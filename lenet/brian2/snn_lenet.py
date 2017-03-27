#coding=utf-8

import time
import os.path
import scipy
import scipy.io as sio
import cPickle as pickle
from struct import unpack
import sys
from matplotlib.pyplot import *
from dim3_ind import *
from brian2 import *

start_scope()

# specify the location of the MNIST data
MNIST_data_path = '../mnist/'

#------------------------------------------------------------------------------ 
# functions
#------------------------------------------------------------------------------     

def get_labeled_data(picklename, bTrain = True):
    """Read input-vector (image) and target class (label, 0-9) and return
       it as list of tuples.
    """
    if os.path.isfile('%s.pickle' % picklename):
        data = pickle.load(open('%s.pickle' % picklename))
    else:
        # Open the images with gzip in read binary mode
        if bTrain:
            images = open(MNIST_data_path + 'train-images-idx3-ubyte','rb')
            labels = open(MNIST_data_path + 'train-labels-idx1-ubyte','rb')
        else:
            images = open(MNIST_data_path + 't10k-images-idx3-ubyte','rb')
            labels = open(MNIST_data_path + 't10k-labels-idx1-ubyte','rb')

        # Get metadata for images
        images.read(4)  # skip the magic_number
        number_of_images = unpack('>I', images.read(4))[0]
        rows = unpack('>I', images.read(4))[0]
        cols = unpack('>I', images.read(4))[0]
        # Get metadata for labels
        labels.read(4)  # skip the magic_number
        N = unpack('>I', labels.read(4))[0]
    
        if number_of_images != N:
            raise Exception('number of labels did not match the number of images')
        # Get the data
        x = np.zeros((N, rows, cols), dtype=np.uint8)  # Initialize numpy array
        y = np.zeros((N, 1), dtype=np.uint8)  # Initialize numpy array
        for i in xrange(N):
            x[i] = [[unpack('>B', images.read(1))[0] for unused_col in xrange(cols)]  for unused_row in xrange(rows) ]
            y[i] = unpack('>B', labels.read(1))[0]
            
        data = {'x': x, 'y': y, 'rows': rows, 'cols': cols}
        pickle.dump(data, open("%s.pickle" % picklename, "wb"))
    return data

def create_conv_connections(in_ind, out_ind, output_size, kernel_num, kernel_size, kernel_weights, pre_ind, post_ind, conv_w):
    for h in range(output_size):    # output height
        for w in range(output_size):    # output width
            for k in range(kernel_num):     # kernel numbers
                for kd in range(in_ind.sz2):    # kernel depth
                    for kh in range(kernel_size):   # kernel height
                        for kw in range(kernel_size):   # kernel width
                            i = in_ind.ind3 (kd, kh + h, kw + w)
                            j = out_ind.ind3(k,       h,      w)
                            pre_ind.append(i)
                            post_ind.append(j)
                            conv_w.append(kernel_weights[kw, kh, kd, k])
    
def create_pool_connections(in_ind, out_ind, output_size, kernel_num, kernel_size, kernel_stride, pre_ind, post_ind, pool_w):
    for h in range(output_size):
        for w in range(output_size):
            for k in range(kernel_num):
                for kh in range(kernel_size):
                    for kw in range(kernel_size):
                        i = in_ind.ind3 (k, kh + kernel_size*h, kw + kernel_size*w)
                        j = out_ind.ind3(k,                  h,                  w)
                        pre_ind.append(i)
                        post_ind.append(j)
                        pool_w.append(0.25)

def create_ip_connections(in_ind, output_n, ip_weights, pre_ind, post_ind, ip_w):
    for n in range(output_n):
        for d in range(in_ind.sz2):
            for h in range(in_ind.sz1):
                for w in range(in_ind.sz0):
                    i = in_ind.ind3(d, h, w)
                    pre_ind.append(i)
                    post_ind.append(n)
                    ip_w.append(ip_weights[i, n])

#------------------------------------------------------------------------------ 
# load MNIST
#------------------------------------------------------------------------------
# start = time.time()
# training = get_labeled_data('cache/training')
# end = time.time()
# print 'time needed to load training set:', end - start
 
start = time.time()
testing = get_labeled_data('cache/testing', bTrain = False)
end = time.time()
print 'time needed to load test set:', end - start

#------------------------------------------------------------------------------ 
# set parameters and equations
#------------------------------------------------------------------------------
eqs_conv1           = 'v : 1'
eqs_pool1           = 'v : 1'
eqs_conv2           = 'v : 1'
eqs_pool2           = 'v : 1'
eqs_ip1             = 'v : 1'
eqs_ip2             = 'v : 1'
eqs_it              = 'v : 1'

conv1_thresh        = 'v >= 1'
conv1_reset         = 'v = 0'

pool1_thresh        = 'v >= 1'
pool1_reset         = 'v = 0'

conv2_thresh        = 'v >= 1'
conv2_reset         = 'v = 0'

pool2_thresh        = 'v >= 1'
pool2_reset         = 'v = 0'

ip1_thresh          = 'v >= 1'
ip1_reset           = 'v = 0'

ip2_thresh          = 'v >= 2'
ip2_reset           = 'v = 0'

it_thresh           = 'v >= 2'
it_reset            = 'v = 0'

def under(v, w):
    return max(0, v+w)

input_size          = 28
input_n             = input_size * input_size
input_ind           = dim3_ind(1, input_size, input_size)

conv1_kernel_size   = 5
conv1_kernel_num    = 20
conv1_kernel_stride = 1
conv1_output_size   = (input_size - conv1_kernel_size + 0) / conv1_kernel_stride + 1    # should be 24
conv1_output_n      = conv1_output_size * conv1_output_size
conv1_ind           = dim3_ind(conv1_kernel_num, conv1_output_size, conv1_output_size)

pool1_kernel_size   = 2
pool1_kernel_num    = conv1_kernel_num
pool1_kernel_stride = 2
pool1_output_size   = conv1_output_size / 2     # should be 12
pool1_output_n      = pool1_output_size * pool1_output_size
pool1_ind           = dim3_ind(pool1_kernel_num, pool1_output_size, pool1_output_size)

conv2_kernel_size   = 5
conv2_kernel_num    = 50
conv2_kernel_stride = 1
conv2_output_size   = (pool1_output_size - conv2_kernel_size + 0) / conv2_kernel_stride + 1    # should be 8
conv2_output_n      = conv2_output_size * conv2_output_size
conv2_ind           = dim3_ind(conv2_kernel_num, conv2_output_size, conv2_output_size)

pool2_kernel_size   = 2
pool2_kernel_num    = conv2_kernel_num
pool2_kernel_stride = 2
pool2_output_size   = conv2_output_size / 2     # should be 4
pool2_output_n      = pool2_output_size * pool2_output_size
pool2_ind           = dim3_ind(pool2_kernel_num, pool2_output_size, pool2_output_size)

ip1_output_n        = 500
ip1_ind             = dim3_ind(1, 1, ip1_output_n)
ip2_output_n        = 10
ip2_ind             = dim3_ind(1, 1, ip2_output_n)
it_output_n         = 10

#------------------------------------------------------------------------------ 
# load synapses weights from pretrained model
#------------------------------------------------------------------------------
pretrained_lenet = sio.loadmat('weights/lenet_avg_pooling.mat')
conv1_weights    = pretrained_lenet['conv1_weights']
conv2_weights    = pretrained_lenet['conv2_weights']
ip1_weights      = pretrained_lenet['ip1_weights']
ip2_weights      = pretrained_lenet['ip2_weights']
softmax_weights  = pretrained_lenet['softmax_weights']

#------------------------------------------------------------------------------ 
# create network population and synapses
#------------------------------------------------------------------------------

# input group
input_group = PoissonGroup(input_n, 0 * Hz)

# conv1 group
conv1_group  = NeuronGroup(conv1_output_n * conv1_kernel_num, eqs_conv1, threshold = conv1_thresh, reset = conv1_reset, method = 'euler')
synapses_input_conv1 = Synapses(input_group, conv1_group, model='w:1', on_pre = 'v_post += w', method = 'linear')   # on_pre = 'v_post = clip(v_post+w, 0, 1)'
pre_ind  = []
post_ind = []
conv_w  = []
create_conv_connections(input_ind, conv1_ind, conv1_output_size, conv1_kernel_num, conv1_kernel_size, conv1_weights, pre_ind, post_ind, conv_w)
synapses_input_conv1.connect(i = pre_ind, j = post_ind)
synapses_input_conv1.w = conv_w;

# pool1 group
pool1_group = NeuronGroup(pool1_output_n * pool1_kernel_num, eqs_pool1, threshold = pool1_thresh, reset = pool1_reset, method = 'euler')
synapses_conv1_pool1 = Synapses(conv1_group, pool1_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
pool_w   = []
create_pool_connections(conv1_ind, pool1_ind, pool1_output_size, pool1_kernel_num, pool1_kernel_size, pool1_kernel_stride, pre_ind, post_ind, pool_w)
synapses_conv1_pool1.connect(i = pre_ind, j = post_ind)
synapses_conv1_pool1.w = pool_w;

# conv2 group
conv2_group  = NeuronGroup(conv2_output_n * conv2_kernel_num, eqs_conv2, threshold = conv2_thresh, reset = conv2_reset, method = 'euler')
synapses_pool1_conv2 = Synapses(pool1_group, conv2_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
conv_w   = []
create_conv_connections(pool1_ind, conv2_ind, conv2_output_size, conv2_kernel_num, conv2_kernel_size, conv2_weights, pre_ind, post_ind, conv_w)
synapses_pool1_conv2.connect(i = pre_ind, j = post_ind)
synapses_pool1_conv2.w = conv_w;

# pool2 group
pool2_group = NeuronGroup(pool2_output_n * pool2_kernel_num, eqs_pool2, threshold = pool2_thresh, reset = pool2_reset, method = 'euler')
synapses_conv2_pool2 = Synapses(conv2_group, pool2_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
pool_w   = []
create_pool_connections(conv2_ind, pool2_ind, pool2_output_size, pool2_kernel_num, pool2_kernel_size, pool2_kernel_stride, pre_ind, post_ind, pool_w)
synapses_conv2_pool2.connect(i = pre_ind, j = post_ind)
synapses_conv2_pool2.w = pool_w;

# ip1 group
ip1_group = NeuronGroup(ip1_output_n, eqs_ip1, threshold = ip1_thresh, reset = ip1_reset, method = 'euler')
synapses_pool2_ip1 = Synapses(pool2_group, ip1_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
ip_w     = []
create_ip_connections(pool2_ind, ip1_output_n, ip1_weights, pre_ind, post_ind, ip_w)
synapses_pool2_ip1.connect(i = pre_ind, j = post_ind)
synapses_pool2_ip1.w = ip_w;

# ip2 group
ip2_group = NeuronGroup(ip2_output_n, eqs_ip2, threshold = ip2_thresh, reset = ip2_reset, method = 'euler')
synapses_ip1_ip2 = Synapses(ip1_group, ip2_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
ip_w     = []
create_ip_connections(ip1_ind, ip2_output_n, ip2_weights, pre_ind, post_ind, ip_w)
synapses_ip1_ip2.connect(i = pre_ind, j = post_ind)
synapses_ip1_ip2.w = ip_w;

# it group
it_group = NeuronGroup(it_output_n, eqs_it, threshold = it_thresh, reset = it_reset, method = 'euler')
synapses_ip2_it = Synapses(ip2_group, it_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
it_w     = []
create_ip_connections(ip2_ind, it_output_n, softmax_weights, pre_ind, post_ind, it_w)
synapses_ip2_it.connect(i = pre_ind, j = post_ind)
synapses_ip2_it.w = it_w;

# synapses_it_it = Synapses(it_group, it_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
# synapses_it_it.connect(condition='i != j')
# synapses_it_it.w = -1

#------------------------------------------------------------------------------ 
# create monitors
#------------------------------------------------------------------------------
it_mon = SpikeMonitor(it_group)
# ip2_mon = SpikeMonitor(ip2_group)
# print synapses_input_conv1.w[input_ind.ind2(0, 0), conv1_ind.ind3(16, 0, 0) ]

last_it_counts = np.array(it_mon.count)
it_counts_record = np.zeros((np.size(testing['x'], 0), 10))
print np.size(it_counts_record)

#------------------------------------------------------------------------------ 
# run the simulation and set inputs
#------------------------------------------------------------------------------
start = time.time()

defaultclock.dt = 0.5 * ms;

for i in range(np.size(testing['x'], 0)):
    input_group.rates = testing['x'][i, :, :].reshape(input_n) * Hz
    conv1_group.v = 0
    pool1_group.v = 0
    conv2_group.v = 0
    pool2_group.v = 0
    ip1_group.v = 0
    ip2_group.v = 0
    it_group.v = 0
    run(100 * ms)
    curr_it_counts = np.array(it_mon.count) - last_it_counts
    last_it_counts = np.array(it_mon.count)
    it_counts_record[i, :] = curr_it_counts
#     print curr_it_counts
    print '%d / %d' % (i, np.size(testing['x'], 0))

end = time.time()
print 'time needed to run simulation:', end - start

# save classified results
sio.savemat('output/it_counts.mat', {'it_counts':it_counts_record})

#------------------------------------------------------------------------------ 
# plot results
#------------------------------------------------------------------------------   
# print ip2_mon.count


show()