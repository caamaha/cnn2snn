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
import matplotlib.pyplot as plt

import cifar10_extract

start_scope()

# specify the location of the MNIST data
MNIST_data_path = '../mnist/'

#------------------------------------------------------------------------------ 
# functions
#------------------------------------------------------------------------------     

def create_conv_connections(in_ind, out_ind, output_size, kernel_num, kernel_size, pad_left, kernel_weights, pre_ind, post_ind, weights):
    for h in range(output_size):    # output height
        for w in range(output_size):    # output width
            for k in range(kernel_num):     # kernel numbers
                for kd in range(in_ind.sz0):    # kernel depth
                    for kh in range(kernel_size):   # kernel height
                        for kw in range(kernel_size):   # kernel width
                            i = in_ind.pad_ind3(kh + h - pad_left, kw + w - pad_left, kd)
                            if i < 0:
                                continue
                            j = out_ind.ind3(h, w, k )
                            pre_ind.append(i)
                            post_ind.append(j)
                            weights.append(kernel_weights[kh, kw, kd, k])
                            
def create_convb_connections(out_ind, output_size, kernel_num, kernel_bias, pre_ind, post_ind, weights):
    for h in range(output_size):
        for w in range(output_size):
            for k in range(kernel_num):
                pre_ind.append(k)
                post_ind.append(out_ind.ind3(h, w, k))
                if kernel_bias[k] > 0:
                    weights.append(1)
                else:
                    weights.append(-1)

def create_max_pooling_input_connections(in_ind, out_ind, kernel_size, kernel_stride, pad_left, pre_ind, post_ind, weights):
    for h in range(out_ind.sz2 / kernel_size):
        for w in range(out_ind.sz1 / kernel_size):
            for k in range(out_ind.sz0):
                for kh in range(kernel_size):
                    for kw in range(kernel_size):
                        i = in_ind.pad_ind3(kh + kernel_stride*h - pad_left, kw + kernel_stride*w - pad_left, k)
                        if i < 0:
                            continue
                        j = out_ind.ind3(kh + kernel_size*h, kw + kernel_size*w, k)
                        pre_ind.append(i)
                        post_ind.append(j)
                        weights.append(1)
    
def create_max_pooling_inter_connections(inter_ind, output_size, kernel_num, kernel_size, pre_ind, post_ind, weights):
    for h in range(output_size):
        for w in range(output_size):
            for k in range(kernel_num):
                for kh1 in range(kernel_size):
                    for kw1 in range(kernel_size):
                        for kh2 in range(kernel_size):
                            for kw2 in range(kernel_size):
                                if (kh2 == kh1) and (kw2 == kw1):
                                    continue
                                i = inter_ind.ind3(kh1 + kernel_size*h, kw1 + kernel_size*w, k)
                                j = inter_ind.ind3(kh2 + kernel_size*h, kw2 + kernel_size*w, k)
                                pre_ind.append(i)
                                post_ind.append(j)
                                weights.append(-1)

def create_max_pooling_out_connections(in_ind, out_ind, output_size, kernel_num, kernel_size, pre_ind, post_ind, weights):
    for h in range(output_size):
        for w in range(output_size):
            for k in range(kernel_num):
                for kh in range(kernel_size):
                    for kw in range(kernel_size):
                        i = in_ind.ind3(kh + kernel_size*h, kw + kernel_size*w, k)
                        j = out_ind.ind3(h, w, k)
                        pre_ind.append(i)
                        post_ind.append(j)
                        weights.append(1)

def create_ip_connections(in_ind, output_n, ip_weights, pre_ind, post_ind, weights):
    for n in range(output_n):
        for h in range(in_ind.sz2):
            for w in range(in_ind.sz1):
                for d in range(in_ind.sz0):
                    i = in_ind.ind3(h, w, d)
                    pre_ind.append(i)
                    post_ind.append(n)
                    weights.append(ip_weights[i, n])

#------------------------------------------------------------------------------ 
# load CIFAR10
#------------------------------------------------------------------------------
cifar10_data_set = cifar10_extract.Cifar10DataSet('../dataset/')
test_images, test_labels = cifar10_data_set.test_data()

# crop
test_images = test_images[:, 4:28, 4:28, :] * 255


#------------------------------------------------------------------------------ 
# set parameters and equations
#------------------------------------------------------------------------------
eqs_conv1           = 'v : 1'
eqs_pool1           = 'v : 1'
eqs_conv2           = 'v : 1'
eqs_pool2           = 'v : 1'
eqs_ip1             = 'v : 1'
eqs_ip2             = 'v : 1'

conv1_thresh        = 'v >= 1'
conv1_reset         = 'v = 0'

pool1_thresh        = 'v >= 1'
pool1_reset         = 'v = 0'

conv2_thresh        = 'v >= 1'
conv2_reset         = 'v = 0'

pool2_thresh        = 'v >= 2'
pool2_reset         = 'v = 0'

ip1_thresh          = 'v >= 2'
ip1_reset           = 'v = 0'

ip2_thresh          = 'v >= 1'
ip2_reset           = 'v = 0'

input_size          = 24
input_n             = input_size * input_size * 3
input_ind           = dim3_ind(input_size, input_size, 3)

conv1_kernel_size   = 5
conv1_kernel_num    = 64
conv1_kernel_stride = 1
conv1_pad_left      = 2 # pad left and top
conv1_pad_right     = 2 # pad right and bottom
conv1_output_size   = (input_size - conv1_kernel_size + conv1_pad_left + conv1_pad_right) / conv1_kernel_stride + 1    # should be 24
conv1_output_n      = conv1_output_size * conv1_output_size * conv1_kernel_num
conv1_ind           = dim3_ind(conv1_output_size, conv1_output_size, conv1_kernel_num)

pool1_kernel_size   = 3
pool1_kernel_num    = conv1_kernel_num
pool1_kernel_stride = 2
pool1_pad_left      = 0 # pad left and top
pool1_pad_right     = 1 # pad right and bottom
pool1_output_size   = (conv1_output_size - pool1_kernel_size + pool1_pad_left + pool1_pad_right) / pool1_kernel_stride + 1     # should be 12
pool1_output_n      = pool1_output_size * pool1_output_size * pool1_kernel_num
pool1_ind           = dim3_ind(pool1_output_size, pool1_output_size, pool1_kernel_num)
pool1_input_size    = pool1_output_size * pool1_kernel_size
pool1_input_n       = pool1_input_size * pool1_input_size * pool1_kernel_num
pool1_input_ind     = dim3_ind(pool1_input_size, pool1_input_size, pool1_kernel_num)

conv2_kernel_size   = 5
conv2_kernel_num    = 64
conv2_kernel_stride = 1
conv2_pad_left      = 2 # pad left and top
conv2_pad_right     = 2 # pad right and bottom
conv2_output_size   = (pool1_output_size - conv2_kernel_size + conv2_pad_left + conv2_pad_right) / conv2_kernel_stride + 1    # should be 12
conv2_output_n      = conv2_output_size * conv2_output_size * conv2_kernel_num
conv2_ind           = dim3_ind(conv2_output_size, conv2_output_size, conv2_kernel_num)

pool2_kernel_size   = 3
pool2_kernel_num    = conv2_kernel_num
pool2_kernel_stride = 2
pool2_pad_left      = 0 # pad left and top
pool2_pad_right     = 1 # pad right and bottom
pool2_output_size   = conv2_output_size / 2     # should be 6
pool2_output_n      = pool2_output_size * pool2_output_size * pool2_kernel_num
pool2_ind           = dim3_ind(pool2_output_size, pool2_output_size, pool2_kernel_num)

ip1_output_n        = 384
ip1_ind             = dim3_ind(1, 1, ip1_output_n)

ip2_output_n        = 192
ip2_ind             = dim3_ind(1, 1, ip2_output_n)

ip3_output_n        = 10
ip3_ind             = dim3_ind(1, 1, ip3_output_n)

#------------------------------------------------------------------------------ 
# load synapses weights from pretrained model
#------------------------------------------------------------------------------
pretrained = sio.loadmat('../tf_snn/output/weights/cifar10_weights.mat')
conv1_w    = pretrained['conv1_w']
conv1_b    = pretrained['conv1_b'][0, :]
conv2_w    = pretrained['conv2_w']
conv2_b    = pretrained['conv2_b'][0, :]
ip1_w      = pretrained['ip1_w']
ip1_b      = pretrained['ip1_b'][0, :]
ip2_w      = pretrained['ip2_w']
ip2_b      = pretrained['ip2_b'][0, :]
ip3_w      = pretrained['ip3_w']
ip3_b      = pretrained['ip3_b'][0, :]

#------------------------------------------------------------------------------ 
# create network population and synapses
#------------------------------------------------------------------------------

# input group
input_group = PoissonGroup(input_n, 0 * Hz)

# conv1 group
conv1_group  = NeuronGroup(conv1_output_n, eqs_conv1, threshold = conv1_thresh, reset = conv1_reset, method = 'euler')
conv1b_group = PoissonGroup(conv1_kernel_num, 0 * Hz)
synapses_input_conv1 = Synapses(input_group, conv1_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_conv_connections(input_ind, conv1_ind, conv1_output_size, conv1_kernel_num, conv1_kernel_size, conv1_pad_left, conv1_w, pre_ind, post_ind, weights)
synapses_input_conv1.connect(i = pre_ind, j = post_ind)
synapses_input_conv1.w = weights;

synapses_conv1b_conv1 = Synapses(conv1b_group, conv1_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_convb_connections(conv1_ind, conv1_output_size, conv1_kernel_num, conv1_b, pre_ind, post_ind, weights);
synapses_conv1b_conv1.connect(i = pre_ind, j = post_ind)
synapses_conv1b_conv1.w = weights;


# pool1 intermediate group
pool1_in_group = NeuronGroup(pool1_input_n, eqs_conv1, threshold = conv1_thresh, reset = conv1_reset, method = 'euler')
synapses_conv1_pool1_in = Synapses(conv1_group, pool1_in_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights   = []
create_max_pooling_input_connections(pool1_input_ind, pool1_ind, pool1_kernel_size, pool1_kernel_stride, pool1_pad_left, pre_ind, post_ind, weights)
synapses_conv1_pool1_in.connect(i = pre_ind, j = post_ind)
synapses_conv1_pool1_in.w = weights;

synapses_conv1_conv1 = Synapses(pool1_in_group, pool1_in_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights   = []
create_max_pooling_inter_connections(pool1_input_ind, pool1_output_size, pool1_kernel_num, pool1_kernel_size, pre_ind, post_ind, weights)
synapses_conv1_conv1.connect(i = pre_ind, j = post_ind)
synapses_conv1_conv1.w = weights;
 
# pool1 out group
pool1_group = NeuronGroup(pool1_output_n, eqs_pool1, threshold = pool1_thresh, reset = pool1_reset, method = 'euler')
synapses_conv1_pool1 = Synapses(pool1_in_group, pool1_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights   = []
create_max_pooling_out_connections(pool1_input_ind, pool1_ind, pool1_output_size, pool1_kernel_num, pool1_kernel_size, pre_ind, post_ind, weights)
synapses_conv1_pool1.connect(i = pre_ind, j = post_ind)
synapses_conv1_pool1.w = weights;

'''
# conv2 group
conv2_group  = NeuronGroup(conv2_output_n, eqs_conv2, threshold = conv2_thresh, reset = conv2_reset, method = 'euler')
synapses_pool1_conv2 = Synapses(pool1_group, conv2_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
conv_w   = []
create_conv_connections(pool1_ind, conv2_ind, conv2_output_size, conv2_kernel_num, conv2_kernel_size, conv2_w, pre_ind, post_ind, conv_w)
synapses_pool1_conv2.connect(i = pre_ind, j = post_ind)
synapses_pool1_conv2.w = conv_w;

# pool2 intermediate group
synapses_conv2_conv2 = Synapses(conv2_group, conv2_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
pool_w   = []
create_max_pooling_inter_connections(conv2_ind, pool2_output_size, pool2_kernel_num, pool2_kernel_size, pool2_kernel_stride, pre_ind, post_ind, pool_w)
synapses_conv2_conv2.connect(i = pre_ind, j = post_ind)
synapses_conv2_conv2.w = pool_w;

# pool2 out group
pool2_group = NeuronGroup(pool2_output_n, eqs_pool2, threshold = pool2_thresh, reset = pool2_reset, method = 'euler')
synapses_conv2_pool2 = Synapses(conv2_group, pool2_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
pool_w   = []
create_max_pooling_out_connections(conv2_ind, pool2_ind, pool2_output_size, pool2_kernel_num, pool2_kernel_size, pool2_kernel_stride, pre_ind, post_ind, pool_w)
synapses_conv2_pool2.connect(i = pre_ind, j = post_ind)
synapses_conv2_pool2.w = pool_w;

# ip1 group
ip1_group = NeuronGroup(ip1_output_n, eqs_ip1, threshold = ip1_thresh, reset = ip1_reset, method = 'euler')
synapses_pool2_ip1 = Synapses(pool2_group, ip1_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
ip_w     = []
create_ip_connections(pool2_ind, ip1_output_n, ip1_w, pre_ind, post_ind, ip_w)
synapses_pool2_ip1.connect(i = pre_ind, j = post_ind)
synapses_pool2_ip1.w = ip_w;

# ip2 group
ip2_group = NeuronGroup(ip2_output_n, eqs_ip2, threshold = ip2_thresh, reset = ip2_reset, method = 'euler')
synapses_ip1_ip2 = Synapses(ip1_group, ip2_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
ip_w     = []
create_ip_connections(ip1_ind, ip2_output_n, ip2_w, pre_ind, post_ind, ip_w)
synapses_ip1_ip2.connect(i = pre_ind, j = post_ind)
synapses_ip1_ip2.w = ip_w;
'''

#------------------------------------------------------------------------------ 
# create monitors
#------------------------------------------------------------------------------
# ip2_mon = SpikeMonitor(ip2_group)
# last_ip2_counts = np.array(ip2_mon.count)
# ip2_counts_record = np.zeros((np.size(test_images, 0), 10))

conv1_mon = SpikeMonitor(conv1_group)
last_conv1_counts = np.array(conv1_mon.count)
# conv1_counts_record = np.zeros((np.size(testing['x'], 0), 11520))

pool1_mon = SpikeMonitor(pool1_group)
last_pool1_counts = np.array(pool1_mon.count)


# print np.size(it_counts_record)

#------------------------------------------------------------------------------ 
# run the simulation and set inputs
#------------------------------------------------------------------------------
start = time.time()

defaultclock.dt = 0.1 * ms;

conv1b_group.rates = np.abs(conv1_b) * 255 * Hz

# for i in range(np.size(testing['x'], 0)):
for i in range(1):
    input_group.rates = test_images[i, :, :, :].reshape(input_n) * Hz
    conv1_group.v = 0
#     pool1_group.v = 0
#     conv2_group.v = 0
#     pool2_group.v = 0
#     ip1_group.v = 0
#     ip2_group.v = 0
    run(1000 * ms)
    
    
#     curr_ip2_counts = np.array(ip2_mon.count) - last_ip2_counts
#     last_ip2_counts = np.array(ip2_mon.count)
#     ip2_counts_record[i, :] = curr_ip2_counts
    
    curr_conv1_counts = np.array(conv1_mon.count) - last_conv1_counts
    last_conv1_counts = np.array(conv1_mon.count)
#     conv1_counts_record[i, :] = curr_conv1_counts

    curr_pool1_counts = np.array(pool1_mon.count) - last_pool1_counts
    last_pool1_counts = np.array(pool1_mon.count)
    
    print(curr_conv1_counts[conv1_ind.ind3(0, 2, 0)])
    print(curr_conv1_counts[conv1_ind.ind3(0, 3, 0)])
    print(curr_conv1_counts[conv1_ind.ind3(0, 4, 0)])
    print(curr_conv1_counts[conv1_ind.ind3(1, 2, 0)])
    print(curr_conv1_counts[conv1_ind.ind3(1, 3, 0)])
    print(curr_conv1_counts[conv1_ind.ind3(1, 4, 0)])
    print(curr_conv1_counts[conv1_ind.ind3(2, 2, 0)])
    print(curr_conv1_counts[conv1_ind.ind3(2, 3, 0)])
    print(curr_conv1_counts[conv1_ind.ind3(2, 4, 0)])
    
    print(curr_pool1_counts[pool1_ind.ind3(0, 1, 0)])
    
    print '%d / %d' % (i, np.size(test_images, 0))

end = time.time()
print 'time needed to run simulation:', end - start



#------------------------------------------------------------------------------ 
# plot results
#------------------------------------------------------------------------------   
# print ip2_mon.count

# save classified results
# curr_pool1_counts = []
sio.savemat('output/snn_counts.mat', {'conv1':curr_conv1_counts,
                                      'pool1':curr_pool1_counts})

# sio.savemat('output/conv1_counts.mat', {'conv1_counts':conv1_counts_record})
