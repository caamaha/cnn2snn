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
                            j = out_ind.ind3(h, w, k)
                            pre_ind.append(i)
                            post_ind.append(j)
                            weights.append(kernel_weights[kh, kw, kd, k])

def create_conv_padding_connections(in_ind, out_ind, output_size, kernel_num, kernel_size, pad_left, kernel_weights, pre_ind, post_ind, weights):
    for h in range(output_size):    # output height
        for w in range(output_size):    # output width
            for k in range(kernel_num):     # kernel numbers
                for kd in range(in_ind.sz0):    # kernel depth
                    for kh in range(kernel_size):   # kernel height
                        for kw in range(kernel_size):   # kernel width
                            i = in_ind.pad_ind3(kh + h - pad_left, kw + w - pad_left, kd)
                            if i < 0:
                                j = out_ind.ind3(h, w, k)
                                pre_ind.append(0)
                                post_ind.append(j)
                                weights.append(kernel_weights[kh, kw, kd, k])
                            
def create_convb_connections(out_ind, output_size, kernel_num, kernel_bias, pre_ind, post_ind, weights):
    for h in range(output_size):
        for w in range(output_size):
            for k in range(kernel_num):
                pre_ind.append(k)
                post_ind.append(out_ind.ind3(h, w, k))
                weights.append(kernel_bias[k])

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
                    
def create_ipb_connections(ip_n, ip_bias, pre_ind, post_ind, weights):
    for i in range(ip_n):
        pre_ind.append(0)
        post_ind.append(i)
        weights.append(ip_bias[i])

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
eqs_input           = '''rates     : Hz
                         dv/dt = 1 : second'''
input_thresh        = 'v > 1/rates'
input_reset         = 'v -= 1/rates'

eqs_conv1           = 'v : 1'
eqs_pool1           = 'v : 1'
eqs_conv2           = 'v : 1'
eqs_pool2           = 'v : 1'
eqs_ip1             = 'v : 1'
eqs_ip2             = 'v : 1'
eqs_ip3             = 'v : 1'

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

ip2_thresh          = 'v >= 1'
ip2_reset           = 'v = 0'

ip3_thresh          = 'v >= 1'
ip3_reset           = 'v = 0'

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
pool2_output_size   = (conv2_output_size - pool2_kernel_size + pool2_pad_left + pool2_pad_right) / pool2_kernel_stride + 1     # should be 6
pool2_output_n      = pool2_output_size * pool2_output_size * pool2_kernel_num
pool2_ind           = dim3_ind(pool2_output_size, pool2_output_size, pool2_kernel_num)
pool2_input_size    = pool2_output_size * pool2_kernel_size
pool2_input_n       = pool2_input_size * pool2_input_size * pool2_kernel_num
pool2_input_ind     = dim3_ind(pool2_input_size, pool2_input_size, pool2_kernel_num)

ip1_output_n        = 384
ip1_ind             = dim3_ind(1, 1, ip1_output_n)

ip2_output_n        = 192
ip2_ind             = dim3_ind(1, 1, ip2_output_n)

ip3_output_n        = 10
ip3_ind             = dim3_ind(1, 1, ip3_output_n)

#------------------------------------------------------------------------------ 
# load synapses weights from pretrained model
#------------------------------------------------------------------------------
pretrained = sio.loadmat('../tf_snn_trial/output/weights/cifar10_weights.mat')

# convert input range from [-0.5, 0.5] to [0.0, 1.0]
for i in range(np.size(pretrained['conv1_b'], 1)):
    sum_w = np.sum(pretrained['conv1_w'][:, :, :, i])
    pretrained['conv1_b'][0, i] = -0.5 * sum_w

conv1_wn = 1 / 4.6085
weight_norm = conv1_wn
conv1_w    = pretrained['conv1_w']       * conv1_wn
conv1_b    = pretrained['conv1_b'][0, :] * weight_norm
conv2_wn = 1 / 20.6484 / weight_norm
weight_norm *= conv2_wn
conv2_w    = pretrained['conv2_w']       * conv2_wn
conv2_b    = pretrained['conv2_b'][0, :] * weight_norm
ip1_wn = 1 / 8.7884 / weight_norm
weight_norm *= ip1_wn
ip1_w      = pretrained['ip1_w']         * ip1_wn
ip1_b      = pretrained['ip1_b'][0, :]   * weight_norm
ip2_wn = 1 / 1.5550 / weight_norm
weight_norm *= ip2_wn
ip2_w      = pretrained['ip2_w']         * ip2_wn
ip2_b      = pretrained['ip2_b'][0, :]   * weight_norm
ip3_wn = 1 / 29.8450 / weight_norm
weight_norm *= ip3_wn
ip3_w      = pretrained['ip3_w']         * ip3_wn
ip3_b      = pretrained['ip3_b'][0, :]   * weight_norm

#------------------------------------------------------------------------------ 
# create network population and synapses
#------------------------------------------------------------------------------

# input group
# input_group = PoissonGroup(input_n, 0 * Hz)
input_group  = NeuronGroup(input_n, eqs_input, threshold = input_thresh, reset = input_reset, method = 'euler')
input_pad_group = NeuronGroup(1, eqs_input, threshold = input_thresh, reset = input_reset, method = 'euler')
# conv1 group
conv1_group  = NeuronGroup(conv1_output_n, eqs_conv1, threshold = conv1_thresh, reset = conv1_reset, method = 'euler')
conv1b_group = NeuronGroup(conv1_kernel_num, eqs_input, threshold = input_thresh, reset = input_reset, method = 'euler')
synapses_input_conv1 = Synapses(input_group, conv1_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_conv_connections(input_ind, conv1_ind, conv1_output_size, conv1_kernel_num, conv1_kernel_size, conv1_pad_left, conv1_w, pre_ind, post_ind, weights)
synapses_input_conv1.connect(i = pre_ind, j = post_ind)
synapses_input_conv1.w = weights;

synapses_input_pad_conv1 = Synapses(input_pad_group, conv1_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_conv_padding_connections(input_ind, conv1_ind, conv1_output_size, conv1_kernel_num, conv1_kernel_size, conv1_pad_left, conv1_w, pre_ind, post_ind, weights)
synapses_input_pad_conv1.connect(i = pre_ind, j = post_ind)
synapses_input_pad_conv1.w = weights;

synapses_conv1b_conv1 = Synapses(conv1b_group, conv1_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_convb_connections(conv1_ind, conv1_output_size, conv1_kernel_num, conv1_b, pre_ind, post_ind, weights);
synapses_conv1b_conv1.connect(i = pre_ind, j = post_ind)
synapses_conv1b_conv1.w = weights;


# pool1 input group
pool1_in_group = NeuronGroup(pool1_input_n, eqs_conv1, threshold = conv1_thresh, reset = conv1_reset, method = 'euler')
synapses_conv1_pool1_in = Synapses(conv1_group, pool1_in_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_max_pooling_input_connections(conv1_ind, pool1_input_ind, pool1_kernel_size, pool1_kernel_stride, pool1_pad_left, pre_ind, post_ind, weights)
synapses_conv1_pool1_in.connect(i = pre_ind, j = post_ind)
synapses_conv1_pool1_in.w = weights;

# pool1 intermediate group
synapses_conv1_conv1 = Synapses(pool1_in_group, pool1_in_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_max_pooling_inter_connections(pool1_input_ind, pool1_output_size, pool1_kernel_num, pool1_kernel_size, pre_ind, post_ind, weights)
synapses_conv1_conv1.connect(i = pre_ind, j = post_ind)
synapses_conv1_conv1.w = weights;
 
# pool1 out group
pool1_group = NeuronGroup(pool1_output_n, eqs_pool1, threshold = pool1_thresh, reset = pool1_reset, method = 'euler')
synapses_conv1_pool1 = Synapses(pool1_in_group, pool1_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_max_pooling_out_connections(pool1_input_ind, pool1_ind, pool1_output_size, pool1_kernel_num, pool1_kernel_size, pre_ind, post_ind, weights)
synapses_conv1_pool1.connect(i = pre_ind, j = post_ind)
synapses_conv1_pool1.w = weights;


# conv2 group
conv2_group  = NeuronGroup(conv2_output_n, eqs_conv2, threshold = conv2_thresh, reset = conv2_reset, method = 'euler')
conv2b_group = NeuronGroup(conv2_kernel_num, eqs_input, threshold = input_thresh, reset = input_reset, method = 'euler')
synapses_pool1_conv2 = Synapses(pool1_group, conv2_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_conv_connections(pool1_ind, conv2_ind, conv2_output_size, conv2_kernel_num, conv2_kernel_size, conv2_pad_left, conv2_w, pre_ind, post_ind, weights)
synapses_pool1_conv2.connect(i = pre_ind, j = post_ind)
synapses_pool1_conv2.w = weights;

synapses_conv2b_conv2 = Synapses(conv2b_group, conv2_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_convb_connections(conv2_ind, conv2_output_size, conv2_kernel_num, conv2_b, pre_ind, post_ind, weights);
synapses_conv2b_conv2.connect(i = pre_ind, j = post_ind)
synapses_conv2b_conv2.w = weights;


# pool2 input group
pool2_in_group = NeuronGroup(pool2_input_n, eqs_conv2, threshold = conv2_thresh, reset = conv2_reset, method = 'euler')
synapses_conv2_pool2_in = Synapses(conv2_group, pool2_in_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_max_pooling_input_connections(conv2_ind, pool2_input_ind, pool2_kernel_size, pool2_kernel_stride, pool2_pad_left, pre_ind, post_ind, weights)
synapses_conv2_pool2_in.connect(i = pre_ind, j = post_ind)
synapses_conv2_pool2_in.w = weights;

# pool2 intermediate group
synapses_conv2_conv2 = Synapses(pool2_in_group, pool2_in_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_max_pooling_inter_connections(pool2_input_ind, pool2_output_size, pool2_kernel_num, pool2_kernel_size, pre_ind, post_ind, weights)
synapses_conv2_conv2.connect(i = pre_ind, j = post_ind)
synapses_conv2_conv2.w = weights;

# pool2 out group
pool2_group = NeuronGroup(pool2_output_n, eqs_pool2, threshold = pool2_thresh, reset = pool2_reset, method = 'euler')
synapses_conv2_pool2 = Synapses(pool2_in_group, pool2_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_max_pooling_out_connections(pool2_input_ind, pool2_ind, pool2_output_size, pool2_kernel_num, pool2_kernel_size, pre_ind, post_ind, weights)
synapses_conv2_pool2.connect(i = pre_ind, j = post_ind)
synapses_conv2_pool2.w = weights;


# ip1 group
ip1_group = NeuronGroup(ip1_output_n, eqs_ip1, threshold = ip1_thresh, reset = ip1_reset, method = 'euler')
ip1b_group = NeuronGroup(1, eqs_input, threshold = input_thresh, reset = input_reset, method = 'euler')
synapses_pool2_ip1 = Synapses(pool2_group, ip1_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_ip_connections(pool2_ind, ip1_output_n, ip1_w, pre_ind, post_ind, weights)
synapses_pool2_ip1.connect(i = pre_ind, j = post_ind)
synapses_pool2_ip1.w = weights;

synapses_bias_ip1 = Synapses(ip1b_group, ip1_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_ipb_connections(ip1_output_n, ip1_b, pre_ind, post_ind, weights);
synapses_bias_ip1.connect(i = pre_ind, j = post_ind)
synapses_bias_ip1.w = weights;


# ip2 group
ip2_group = NeuronGroup(ip2_output_n, eqs_ip2, threshold = ip2_thresh, reset = ip2_reset, method = 'euler')
ip2b_group = NeuronGroup(1, eqs_input, threshold = input_thresh, reset = input_reset, method = 'euler')
synapses_ip1_ip2 = Synapses(ip1_group, ip2_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_ip_connections(ip1_ind, ip2_output_n, ip2_w, pre_ind, post_ind, weights)
synapses_ip1_ip2.connect(i = pre_ind, j = post_ind)
synapses_ip1_ip2.w = weights;

synapses_bias_ip2 = Synapses(ip2b_group, ip2_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_ipb_connections(ip2_output_n, ip2_b, pre_ind, post_ind, weights);
synapses_bias_ip2.connect(i = pre_ind, j = post_ind)
synapses_bias_ip2.w = weights;

# ip3 group
ip3_group = NeuronGroup(ip3_output_n, eqs_ip3, threshold = ip3_thresh, reset = ip3_reset, method = 'euler')
ip3b_group = NeuronGroup(1, eqs_input, threshold = input_thresh, reset = input_reset, method = 'euler')
synapses_ip2_ip3 = Synapses(ip2_group, ip3_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_ip_connections(ip2_ind, ip3_output_n, ip3_w, pre_ind, post_ind, weights)
synapses_ip2_ip3.connect(i = pre_ind, j = post_ind)
synapses_ip2_ip3.w = weights;

synapses_bias_ip3 = Synapses(ip3b_group, ip3_group, model='w:1', on_pre = 'v_post += w', method = 'linear')
pre_ind  = []
post_ind = []
weights  = []
create_ipb_connections(ip3_output_n, ip3_b, pre_ind, post_ind, weights);
synapses_bias_ip3.connect(i = pre_ind, j = post_ind)
synapses_bias_ip3.w = weights;


def app_run(test_start = 0, test_end = -1):
    if test_end < test_start:
        test_num = np.size(test_images, 0)
        test_start = 0
        test_end = test_num
        test_range = range(test_num)
    else:
        test_num = test_end - test_start
        test_range = range(test_start, test_end)
    #------------------------------------------------------------------------------ 
    # create monitors
    #------------------------------------------------------------------------------
    
#     conv1_mon = SpikeMonitor(conv1_group)
#     last_conv1_counts = np.array(conv1_mon.count)
#     conv1_record = np.zeros((test_num, np.size(last_conv1_counts)))
#      
#     pool1_mon = SpikeMonitor(pool1_group)
#     last_pool1_counts = np.array(pool1_mon.count)
#     pool1_record = np.zeros((test_num, np.size(last_pool1_counts)))
#        
#     conv2_mon = SpikeMonitor(conv2_group)
#     last_conv2_counts = np.array(conv2_mon.count)
#     conv2_record = np.zeros((test_num, np.size(last_conv2_counts)))
#        
#     pool2_mon = SpikeMonitor(pool2_group)
#     last_pool2_counts = np.array(pool2_mon.count)
#     pool2_record = np.zeros((test_num, np.size(last_pool2_counts)))
#      
#     ip1_mon = SpikeMonitor(ip1_group)
#     last_ip1_counts = np.array(ip1_mon.count)
#     ip1_record = np.zeros((test_num, np.size(last_ip1_counts)))
#      
#     ip2_mon = SpikeMonitor(ip2_group)
#     last_ip2_counts = np.array(ip2_mon.count)
#     ip2_record = np.zeros((test_num, np.size(last_ip2_counts)))
     
    ip3_mon = SpikeMonitor(ip3_group)
    last_ip3_counts = np.array(ip3_mon.count)
    ip3_record = np.zeros((test_num, np.size(last_ip3_counts)))
    
    
    #------------------------------------------------------------------------------ 
    # run the simulation and set inputs
    #------------------------------------------------------------------------------
    start = time.time()
    
    defaultclock.dt = 0.1 * ms;
    
    input_pad_group.rates = 127.5 * Hz
    conv1b_group.rates = 255. * Hz
    conv2b_group.rates = 255. * Hz
    ip1b_group.rates   = 255. * Hz
    ip2b_group.rates   = 255. * Hz
    ip3b_group.rates   = 255. * Hz
    
    sample_counts = 0.0;
    sample_right  = 0.0;
    
    # for i in range(np.size(testing['x'], 0)):
    for i in test_range:
        input_group.rates = test_images[i, :, :, :].reshape(input_n) * Hz
        input_group.v = 0
        conv1_group.v = 0
        pool1_in_group.v = 0
        pool1_group.v = 0
        conv2_group.v = 0
        pool2_in_group.v = 0
        pool2_group.v = 0
        ip1_group.v = 0
        ip2_group.v = 0
        ip3_group.v = 0
        conv1b_group.v = 0
        conv2b_group.v = 0
        ip1b_group.v = 0
        ip2b_group.v = 0
        ip3b_group.v = 0
        run(500 * ms)
        
        
#         curr_conv1_counts = np.array(conv1_mon.count) - last_conv1_counts
#         last_conv1_counts = np.array(conv1_mon.count)
#         conv1_record[i-test_start, :] = curr_conv1_counts
#        
#         curr_pool1_counts = np.array(pool1_mon.count) - last_pool1_counts
#         last_pool1_counts = np.array(pool1_mon.count)
#         pool1_record[i-test_start, :] = curr_pool1_counts
#            
#         curr_conv2_counts = np.array(conv2_mon.count) - last_conv2_counts
#         last_conv2_counts = np.array(conv2_mon.count)
#         conv2_record[i-test_start, :] = curr_conv2_counts
#            
#         curr_pool2_counts = np.array(pool2_mon.count) - last_pool2_counts
#         last_pool2_counts = np.array(pool2_mon.count)
#         pool2_record[i-test_start, :] = curr_pool2_counts
#            
#         curr_ip1_counts = np.array(ip1_mon.count) - last_ip1_counts
#         last_ip1_counts = np.array(ip1_mon.count)
#         ip1_record[i-test_start, :] = curr_ip1_counts
#            
#         curr_ip2_counts = np.array(ip2_mon.count) - last_ip2_counts
#         last_ip2_counts = np.array(ip2_mon.count)
#         ip2_record[i-test_start, :] = curr_ip2_counts
         
        curr_ip3_counts = np.array(ip3_mon.count) - last_ip3_counts
        last_ip3_counts = np.array(ip3_mon.count)
        ip3_record[i-test_start, :] = curr_ip3_counts
        
        pred = np.argmax(curr_ip3_counts)
        label = np.argmax(test_labels[i])
        
        if pred == label:
            sample_right += 1
        sample_counts += 1
    
        print('%d / [%d, %d]:%f %d %d' % (i, test_start, test_end-1, sample_right / sample_counts, sample_right, sample_counts))
        sio.savemat('output/result_%d.mat' % (test_start), 
                                        {
                                            'test_start':test_start,
                                            'test_end':test_end-1,
                                            'sample_right':sample_right,
                                            'sample_counts':sample_counts
                                        })
    
    end = time.time()
    print 'time needed to run simulation:', end - start
    
    
    
    #------------------------------------------------------------------------------ 
    # plot results
    #------------------------------------------------------------------------------   
    
    # save classified results
#     sio.savemat('output/snn_counts_%d_%d.mat' % (test_start, test_end), {'conv1':conv1_record,
#                                           'pool1':pool1_record,
#                                           'conv2':conv2_record,
#                                           'pool2':pool2_record,
#                                           'ip1'  :ip1_record,
#                                           'ip2'  :ip2_record,
#                                           'ip3'  :ip3_record})
    sio.savemat('output/snn_ip3_spikes_%d_%d.mat' % (test_start, test_end), {'snn_t': np.array(ip3_mon.t), 'snn_ip3': np.array(ip3_mon.i)})
    

if __name__ == "__main__":
    if len(sys.argv) == 3:
        app_run(int(sys.argv[1]), int(sys.argv[2]))
    else:
        app_run(0, 100)


