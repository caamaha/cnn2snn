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
    for h in range(output_size):
        for w in range(output_size):
            for k in range(kernel_num):
                for kh in range(kernel_size):
                    for kw in range(kernel_size):
                        i = in_ind.ind2 (   kh + h, kw + w)
                        j = out_ind.ind3(k,      h,      w)
                        pre_ind.append(i)
                        post_ind.append(j)
                        conv_w.append(kernel_weights[kw, kh, k])
    
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
eqs_conv1 = 'v : 1'
eqs_pool1 = 'v : 1'
eqs_conv2 = 'v : 1'
eqs_pool2 = 'v : 1'
eqs_ip1   = 'v : 1'
eqs_ip2   = 'v : 1'

conv1_thresh = 'v >= 10'
conv1_reset  = 'v = 0'

pool1_thresh = 'v >= 1'
pool1_reset  = 'v = 0'

input_size   = 28
input_n      = input_size * input_size
input_ind    = dim3_ind(input_size, input_size)

conv1_kernel_size   = 5
conv1_kernel_num    = 20
conv1_kernel_stride = 1
conv1_output_size   = (input_size - conv1_kernel_size + 0) / conv1_kernel_stride + 1    # should be 24 
conv1_output_n      = conv1_output_size * conv1_output_size
conv1_ind           = dim3_ind(conv1_output_size, conv1_output_size)

pool1_kernel_size   = 2
pool1_kernel_num    = conv1_kernel_num
pool1_kernel_stride = 2
pool1_output_size   = conv1_output_size / 2     # should be 12
pool1_output_n      = pool1_output_size * pool1_output_size
pool1_ind           = dim3_ind(pool1_output_size, pool1_output_size)


#------------------------------------------------------------------------------ 
# load synapses weights from pretrained model
#------------------------------------------------------------------------------
pretrained_lenet = sio.loadmat('weights/pretrained_lenet.mat')
conv1_weights = pretrained_lenet['conv1_weights']
conv2_weights = pretrained_lenet['conv2_weights']
ip1_weights   = pretrained_lenet['ip1_weights']
ip2_weights   = pretrained_lenet['ip2_weights']


#------------------------------------------------------------------------------ 
# create network population and synapses
#------------------------------------------------------------------------------

# input group
input_group = PoissonGroup(input_n, 0 * Hz)

# conv1 group
conv1_group  = NeuronGroup(conv1_output_n * conv1_kernel_num, eqs_conv1, threshold = conv1_thresh, reset = conv1_reset, method = 'euler')
synapses_input_conv1 = Synapses(input_group, conv1_group, model='w:1', on_pre = 'v += w', method = 'linear')
pre_ind  = []
post_ind = []
conv1_w  = []
create_conv_connections(input_ind, conv1_ind, conv1_output_size, conv1_kernel_num, conv1_kernel_size, conv1_weights, pre_ind, post_ind, conv1_w)
# for h in range(conv1_output_size):
#     for w in range(conv1_output_size):
#         for k in range(conv1_kernel_num):
#             for kh in range(conv1_kernel_size):
#                 for kw in range(conv1_kernel_size):
#                     i = input_ind.ind2 (   kh + h, kw + w)
#                     j = conv1_ind.ind3(k,      h,      w)
#                     pre_ind.append(i)
#                     post_ind.append(j)
#                     conv1_w.append(conv1_weights[kw, kh, k])



synapses_input_conv1.connect(i = pre_ind, j = post_ind)
synapses_input_conv1.w = conv1_w;

# pool1 group
pool1_group = NeuronGroup(pool1_output_n * pool1_kernel_num, eqs_pool1, threshold = pool1_thresh, reset = pool1_reset, method = 'euler')
synapses_conv1_pool1 = Synapses(conv1_group, pool1_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
pool1_w  = []
create_pool_connections(conv1_ind, pool1_ind, pool1_output_size, pool1_kernel_num, pool1_kernel_size, pool1_kernel_stride, pre_ind, post_ind, pool1_w)
synapses_conv1_pool1.connect(i = pre_ind, j = post_ind)
synapses_conv1_pool1.w = pool1_w;


#------------------------------------------------------------------------------ 
# create monitors
#------------------------------------------------------------------------------
conv1_mon = SpikeMonitor(conv1_group)
pool1_mon = SpikeMonitor(pool1_group)
# print synapses_input_conv1.w[input_ind.ind2(0, 0), conv1_ind.ind3(16, 0, 0) ]



#------------------------------------------------------------------------------ 
# run the simulation and set inputs
#------------------------------------------------------------------------------
ion()

input_group.rates = testing['x'][0, :, :].reshape(input_n) * Hz
run(1000 * ms)

#------------------------------------------------------------------------------ 
# plot results
#------------------------------------------------------------------------------   

# plot(M.t/ms, M.v[0], label='v')
# imshow(testing['x'][0, :, :], cmap ='gray')


# ttt = testing['x'][0, :, :].reshape(input_n)
# print input_group.rates[input_ind.ind2(0, 0)]
# print input_group.rates[input_ind.ind2(1, 0)]

print conv1_mon.count[conv1_ind.ind3(0, 6, 10)]
print conv1_mon.count[conv1_ind.ind3(0, 5, 10)]
print pool1_mon.count[pool1_ind.ind3(0, 3, 5)]
print pool1_mon.count[pool1_ind.ind3(0, 2, 5)]

ioff()
show()