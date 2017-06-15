# -*- coding:utf-8 -*-  

from sys import path
import time
import numpy as np
import tensorflow as tf
import extract_mnist
import scipy.io as sio

# Parameter
batch_size = 64
isTrain = True

#初始化单个卷积核上的参数
def weight_variable(shape):
    initial = tf.truncated_normal(shape, stddev=0.1)
    return tf.Variable(initial)

#输入特征x，用卷积核W进行卷积运算，strides为卷积核移动步长，
#padding表示是否需要补齐边缘像素使输出图像大小不变
def conv2d(x, W):
    return tf.nn.conv2d(x, W, strides=[1, 1, 1, 1], padding='VALID')

#对x进行最大池化操作，ksize进行池化的范围，
def max_pool_2x2(x):
    return tf.nn.max_pool(x, ksize=[1, 2, 2, 1],strides=[1, 2, 2, 1], padding='VALID')

# average pooling
def avg_pool_2x2(x):
    return tf.nn.avg_pool(x, ksize=[1, 2, 2, 1],strides=[1, 2, 2, 1], padding='VALID')

def input_poisson(x_image, level):
    #print x_image
    x_image = (x_image+0.5) * level
    
    w = x_image.shape[0]
    h = x_image.shape[1]
    img = np.random.poisson(x_image, (w, h))
    #img = x_image
    img = img / level
    #print img
    return img

    
#声明输入图片数据，类别
x = tf.placeholder('float',[None,784])
y_ = tf.placeholder('float',[None,10])
#输入图片数据转化
x_image = tf.reshape(x,[-1,28,28,1])

#第一层卷积层，初始化卷积核参数、偏置值，该卷积层5*5大小，一个通道，共有20个不同卷积核
#[filter_height, filter_width, in_channels, out_channels]
W_conv1 = weight_variable([5, 5, 1, 20])
#进行卷积操作，并添加relu激活函数
h_conv1 = tf.nn.relu(conv2d(x_image, W_conv1))
#进行最大池化
h_pool1 = max_pool_2x2(h_conv1)

#同理第二层卷积层
W_conv2 = weight_variable([5,5,20,50])
h_conv2 = tf.nn.relu(conv2d(h_pool1, W_conv2))
h_pool2 = max_pool_2x2(h_conv2)

#全连接层
#权值参数
W_fc1 = weight_variable([4*4*50,500])
#将卷积的产出展开
h_pool2_flat = tf.reshape(h_pool2,[-1,4*4*50])
#神经网络计算，并添加relu激活函数
h_fc1 = tf.nn.relu(tf.matmul(h_pool2_flat, W_fc1))

#输出层，使用softmax进行多分类
W_fc2 = weight_variable([500,10])
h_fc2 = tf.matmul(h_fc1, W_fc2)
y_conv=tf.maximum(tf.nn.softmax(h_fc2),1e-30)

#代价函数
cross_entropy = -tf.reduce_sum(y_*tf.log(y_conv))
#使用Adam优化算法来调整参数
train_step = tf.train.AdamOptimizer(1e-4).minimize(cross_entropy)

#测试正确率
correct_prediction = tf.equal(tf.argmax(y_conv,1), tf.argmax(y_,1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction, "float"))

#保存参数
saver = tf.train.Saver()

#获取mnist数据
mnist_data_set = extract_mnist.MnistDataSet('../mnist/')
te_images,test_labels = mnist_data_set.test_data()
#test_images = input_poisson(te_images, 255.0)
test_images = te_images + 0.5

#定义会话
with tf.Session() as sess:
    #初始化所有变量
    sess.run(tf.global_variables_initializer())
    #进行训练
    if isTrain:
        start_time = time.time()
        for i in xrange(20000):
            #获取训练数据
            xs, batch_ys = mnist_data_set.next_train_batch(batch_size)
            # 给输入数据增加噪声
            batch_xs = input_poisson(xs, 50.0)
#             batch_xs = xs + 0.5
            #每迭代100个 batch，对当前训练数据进行测试，输出当前预测准确率
            if i%100 == 0:
                train_accuracy = accuracy.eval(feed_dict={x:batch_xs, y_: batch_ys})
                print "step %d, training accuracy %g"%(i, train_accuracy)
                #计算间隔时间
                end_time = time.time()
                print 'time: ',(end_time - start_time)
                start_time = end_time
            #训练数据
            train_step.run(feed_dict={x: batch_xs, y_: batch_ys})

        #保存参数
        if not tf.gfile.Exists('output/model'):
            tf.gfile.MakeDirs('output/model')
        save_path = saver.save(sess, "output/model/max_pooling_model.ckpt")
        print "Model saved in file: ", save_path

        #保存网络权值
        if not tf.gfile.Exists('output/weights'):
            tf.gfile.MakeDirs('output/weights')
        conv1_weights = sess.run(W_conv1)
        conv2_weights = sess.run(W_conv2)
        ip1_weights = sess.run(W_fc1)
        ip2_weights = sess.run(W_fc2)
        sio.savemat('output/weights/lenet_max_pooling.mat', {'conv1_weights':conv1_weights, 
                                                             'conv2_weights':conv2_weights, 
                                                             'ip1_weights':ip1_weights, 
                                                             'ip2_weights':ip2_weights})
    else:
        saver.restore(sess, "output/model/max_pooling_model.ckpt")
        
    # 输出整体测试数据的情况
    avg = 0
    for i in xrange(200):
        avg += accuracy.eval(feed_dict={x: test_images[i*50:i*50+50], y_: test_labels[i*50:i*50+50]})
    avg/=200
    print "test accuracy %g"%avg

#     conv1_out = sess.run(h_conv1, feed_dict={x: test_images[0:10,:].reshape((10,784))})
#     conv1_out = conv1_out.reshape((10, 11520))
#     sio.savemat('output/conv1_out.mat', {'conv1_out':conv1_out})
#     
#     print np.shape(conv1_out)

# print conv1_weights[:,:,0,0]
# tmp = conv1_out[0,:,:,0] * 255
# print tmp.astype(int)

