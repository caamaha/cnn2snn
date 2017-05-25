import tensorflow as tf
import extract_cifar10
import time
from sys import path
import scipy.io as sio

# Parameters
isTrain = True
batch_size = 64

def weight_variable(shape):
	initial = tf.truncated_normal(shape, stddev=0.1)
	return tf.Variable(initial)

def bias_variable(shape):
	initial = tf.constant(0.1, shape=shape)
	return tf.Variable(initial)

def conv2d(x, W):
	return tf.nn.conv2d(x, W, strides=[1, 1, 1, 1], padding='SAME')

x = tf.placeholder('float',[None,32,32,3])
y_ = tf.placeholder('float',[None,10])

# conv1
W_conv1 = weight_variable([5, 5, 3, 64])
b_conv1 = bias_variable([64])
conv1 = tf.nn.relu(conv2d(x,W_conv1) + b_conv1)
# pool1
pool1 = tf.nn.max_pool(conv1, ksize=[1, 3, 3, 1], strides=[1, 2, 2, 1],padding='SAME', name='pool1')
# norm1
norm1 = tf.nn.lrn(pool1, 4, bias=1.0, alpha=0.001 / 9.0, beta=0.75,name='norm1')

# conv2
W_conv2 = weight_variable([5,5,64,64])
b_conv2 = bias_variable([64])
conv2 = tf.nn.relu(conv2d(norm1,W_conv2) + b_conv2)
# norm2
norm2 = tf.nn.lrn(conv2, 4, bias=1.0, alpha=0.001 / 9.0, beta=0.75,name='norm2')
# pool2
pool2 = tf.nn.max_pool(norm2, ksize=[1, 3, 3, 1],strides=[1, 2, 2, 1], padding='SAME', name='pool2')

# fc1
W_fc1 = weight_variable([8*8*64,384])
b_fc1 = bias_variable([384])
pool2_flat = tf.reshape(pool2,[-1,8*8*64])
fc1 = tf.nn.relu(tf.matmul(pool2_flat,W_fc1) + b_fc1)
    
# fc2
W_fc2 = weight_variable([384,192])
b_fc2 = bias_variable([192])
fc2 = tf.nn.relu(tf.matmul(fc1,W_fc2) + b_fc2)

# Dropout
keep_prob = tf.placeholder("float")
fc1_drop = tf.nn.dropout(fc2,keep_prob)
    
# softmax
W_out = weight_variable([192,10])
b_out = bias_variable([10])
y_conv = tf.maximum(tf.nn.softmax(tf.matmul(fc1_drop, W_out) + b_out),1e-30)

# cost function
cross_entropy = -tf.reduce_sum(y_*tf.log(y_conv))
# Adam optimizer
train_step = tf.train.AdamOptimizer(1e-4).minimize(cross_entropy)
    
# count correct prediction
correct_prediction = tf.equal(tf.argmax(y_conv,1), tf.argmax(y_,1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction, "float"))

# save model
saver = tf.train.Saver()

# get cifar-10 dataset
cifar10_data_set = extract_cifar10.Cifar10DataSet('dataset/')
test_images,test_labels = cifar10_data_set.test_data()

# define session
with tf.Session() as sess:
	sess.run(tf.initialize_all_variables())
	if isTrain:
		start_time = time.time()
		for i in xrange(50000):
			batch_xs, batch_ys = cifar10_data_set.next_train_batch(batch_size)
			if i%1000 == 0:
				train_accuracy = accuracy.eval(feed_dict={x:batch_xs, y_: batch_ys, keep_prob: 1.0})
				print "step %d, training accuracy %g"%(i, train_accuracy)
				end_time = time.time()
				print 'time: ',(end_time - start_time)
				start_time = end_time

			if (i+1)%10000 == 0:
				avg = 0
				for j in xrange(20):
					avg+=accuracy.eval(feed_dict={x: test_images[j*50:j*50+50], y_: test_labels[j*50:j*50+50], keep_prob: 1.0})
				avg/=20
				print "test accuracy %g"%avg

			train_step.run(feed_dict={x: batch_xs, y_: batch_ys, keep_prob: 0.5})

		if not tf.gfile.Exists('output/model'):
			tf.gfile.MakeDirs('output/model')
		save_path = saver.save(sess, "output/model/model.ckpt")
		print "Model saved in file: ", save_path

		if not tf.gfile.Exists('output/weights'):
			tf.gfile.MakeDirs('output/weights')
		conv1_weights = sess.run(W_conv1)
		conv2_weights = sess.run(W_conv2)
		ip1_weights = sess.run(W_fc1)
		ip2_weights = sess.run(W_fc2)
		sio.savemat('output/weights/lenet_avg_pooling.mat', {'conv1_weights':conv1_weights, 
                                                            'conv2_weights':conv2_weights, 
                                                            'ip1_weights':ip1_weights, 
                                                            'ip2_weights':ip2_weights})

	else:
		saver.restore(sess, "output/model/model.ckpt")

	avg = 0
	for i in xrange(200):
		avg+=accuracy.eval(feed_dict={x: test_images[i*50:i*50+50], y_: test_labels[i*50:i*50+50], keep_prob: 1.0})
	avg/=200
	print "test accuracy %g"%avg	