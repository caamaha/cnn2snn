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

def create_conv_synapses(conv_name, kernel_num, group_string):
    group_name = conv_name + 'group'
    exec 'global ' + group_name
    exec group_name + '=' + group_string
    
    

#------------------------------------------------------------------------------ 
# load MNIST
#------------------------------------------------------------------------------
start = time.time()
training = get_labeled_data('cache/training')
end = time.time()
print 'time needed to load training set:', end - start
 
start = time.time()
testing = get_labeled_data('cache/testing', bTrain = False)
end = time.time()
print 'time needed to load test set:', end - start

#------------------------------------------------------------------------------ 
# set parameters and equations
#------------------------------------------------------------------------------
eqs_conv1 = '''
v : 1
'''

conv1_thresh = 'v >= 1'
conv1_reset  = 'v = 0'

input_size   = 28
input_n      = input_size * input_size
input_ind    = dim3_ind(input_size, input_size)

conv1_kernel_size   = 5
conv1_kernel_num    = 20
conv1_kernel_stride = 1
conv1_output_size   = (input_size - conv1_kernel_size + 0) / conv1_kernel_stride + 1
conv1_output_n      = conv1_output_size * conv1_output_size
conv1_ind           = dim3_ind(conv1_output_size, conv1_output_size)


#------------------------------------------------------------------------------ 
# load synapses weights from pretrained model
#------------------------------------------------------------------------------
pretrained_lenet = sio.loadmat('weights/pretrained_lenet.mat')
conv1_weights = pretrained_lenet['conv1_weights'].reshape([20, 5, 5])
conv2_weights = pretrained_lenet['conv2_weights']
ip1_weights   = pretrained_lenet['ip1_weights']
ip2_weights   = pretrained_lenet['ip2_weights']


#------------------------------------------------------------------------------ 
# create network population and synapses
#------------------------------------------------------------------------------
input_group = PoissonGroup(input_n, 0 * Hz)

conv1_group  = NeuronGroup(conv1_output_n * conv1_kernel_num, eqs_conv1, threshold = conv1_thresh, reset = conv1_reset, method = 'euler')

synapses_input_conv1 = Synapses(input_group, conv1_group, model='w:1', on_pre = 'v += w', method = 'linear')
pre_ind  = []
post_ind = []
conv1_w  = []
for h in range(conv1_output_size):
    for w in range(conv1_output_size):
        for k in range(conv1_kernel_num):
            for kh in range(conv1_kernel_size):
                for kw in range(conv1_kernel_size):
                    i = input_ind.ind2 (   kh + h, kw + w)
                    j = conv1_ind.ind3(k,      h,      w)
                    pre_ind.append(i)
                    post_ind.append(j)
                    conv1_w.append(conv1_weights[k, kh, kw])
synapses_input_conv1.connect(i = pre_ind, j = post_ind)
synapses_input_conv1.w = conv1_w;

M = StateMonitor(conv1_group, ('v'), record=[0, 10, 100])



#------------------------------------------------------------------------------ 
# run the simulation and set inputs
#------------------------------------------------------------------------------
ion()

PoissonGroup.rates = training['x'][0, :, :].reshape(input_n) * Hz
run(100 * ms)

#------------------------------------------------------------------------------ 
# plot results
#------------------------------------------------------------------------------   

plot(M.t/ms, M.v[0], label='v')

ioff()
show()