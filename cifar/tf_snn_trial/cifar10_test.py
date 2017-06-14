# Copyright 2015 The TensorFlow Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==============================================================================

"""Evaluation for CIFAR-10.

Accuracy:
cifar10_train.py achieves 83.0% accuracy after 100K steps (256 epochs
of data) as judged by cifar10_eval.py.

Speed:
On a single Tesla K40, cifar10_train.py processes a single batch of 128 images
in 0.25-0.35 sec (i.e. 350 - 600 images /sec). The model reaches ~86%
accuracy after 100K steps in 8 hours of training time.

Usage:
Please see the tutorial and website for how to download the CIFAR-10
data set, compile the program and train the model.

http://tensorflow.org/tutorials/deep_cnn/
"""
from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

from datetime import datetime
import math
import time

import scipy.misc
import numpy as np
import tensorflow as tf

import cifar10
import cifar10_extract

import scipy.io as sio


FLAGS = tf.app.flags.FLAGS

tf.app.flags.DEFINE_string('eval_dir', 'output/cifar10_eval',
                           """Directory where to write event logs.""")
tf.app.flags.DEFINE_string('eval_data', 'test',
                           """Either 'test' or 'train_eval'.""")
tf.app.flags.DEFINE_string('checkpoint_dir', 'output/cifar10_train',
                           """Directory where to read model checkpoints.""")
tf.app.flags.DEFINE_integer('num_examples', 10000,
                            """Number of examples to run.""")


def eval_once(saver, summary_writer, top_k_op, summary_op):
    """Run Eval once.

    Args:
      saver: Saver.
      summary_writer: Summary writer.
      top_k_op: Top K op.
      summary_op: Summary op.
    """
    with tf.Session() as sess:
        ckpt = tf.train.get_checkpoint_state(FLAGS.checkpoint_dir)
        if ckpt and ckpt.model_checkpoint_path:
            # Restores from checkpoint
            saver.restore(sess, ckpt.model_checkpoint_path)
            # Assuming model_checkpoint_path looks something like:
            #   /my-favorite-path/cifar10_train/model.ckpt-0,
            # extract global_step from it.
            global_step = ckpt.model_checkpoint_path.split(
                '/')[-1].split('-')[-1]
        else:
            print('No checkpoint file found')
            return

        # Start the queue runners.
        coord = tf.train.Coordinator()
        try:
            threads = []
            for qr in tf.get_collection(tf.GraphKeys.QUEUE_RUNNERS):
                threads.extend(qr.create_threads(sess, coord=coord, daemon=True,
                                                 start=True))

            num_iter = int(math.ceil(FLAGS.num_examples / FLAGS.batch_size))
            true_count = 0  # Counts the number of correct predictions.
            total_sample_count = num_iter * FLAGS.batch_size
            step = 0
            while step < num_iter and not coord.should_stop():
                predictions = sess.run([top_k_op])
                true_count += np.sum(predictions)
                step += 1

            # Compute precision @ 1.
            precision = true_count / total_sample_count
            print('%s: precision @ 1 = %.3f' % (datetime.now(), precision))

            summary = tf.Summary()
            summary.ParseFromString(sess.run(summary_op))
            summary.value.add(tag='Precision @ 1', simple_value=precision)
            summary_writer.add_summary(summary, global_step)
        except Exception as e:  # pylint: disable=broad-except
            coord.request_stop(e)

        coord.request_stop()
        coord.join(threads, stop_grace_period_secs=10)


def evaluate():
    """Eval CIFAR-10 for a number of steps."""
    with tf.Graph().as_default() as g:
        # Get images and labels for CIFAR-10.
        #         eval_data = FLAGS.eval_data == 'test'
        #         images, labels = cifar10.inputs(eval_data=eval_data)

        images = tf.placeholder('float', [FLAGS.batch_size, 24, 24, 3])
        labels = tf.placeholder('int32', [FLAGS.batch_size, 10])

        # Build a Graph that computes the logits predictions from the
        # inference model.
        logits = cifar10.inference(images)

#         lp = tf.argmax(logits, 1)

        # count correct prediction
        correct_prediction = tf.equal(
            tf.argmax(logits, 1), tf.argmax(labels, 1))
        accuracy = tf.reduce_mean(tf.cast(correct_prediction, "float"))

        # Calculate predictions.
#         top_k_op = tf.nn.in_top_k(logits, labels, 1)

        # Restore the moving average version of the learned variables for eval.
        variable_averages = tf.train.ExponentialMovingAverage(
            cifar10.MOVING_AVERAGE_DECAY)
        variables_to_restore = variable_averages.variables_to_restore()
        saver = tf.train.Saver(variables_to_restore)

#         eval_once(saver, summary_writer, top_k_op, summary_op)
        
        # get cifar-10 dataset
        cifar10_data_set = cifar10_extract.Cifar10DataSet('../dataset/')
        test_images, test_labels = cifar10_data_set.test_data()

        # crop
        test_images = test_images[:, 4:28, 4:28, :] - 0.5
        
        with tf.Session() as sess:
            ckpt = tf.train.get_checkpoint_state(FLAGS.checkpoint_dir)
            if ckpt and ckpt.model_checkpoint_path:
                # Restores from checkpoint
                saver.restore(sess, ckpt.model_checkpoint_path)
            else:
                print('No checkpoint file found')
                return

            avg = 0
            for i in xrange(100):
                batch_xs = test_images[
                    i * FLAGS.batch_size:(i + 1) * FLAGS.batch_size]
                batch_ys = test_labels[
                    i * FLAGS.batch_size:(i + 1) * FLAGS.batch_size]
                avg += sess.run(accuracy, feed_dict={images:
                                                     batch_xs, labels: batch_ys})
            avg /= (100)
            print("test accuracy %g" % avg)
            
            # Get conv1 output
            conv1 = tf.get_default_graph().get_tensor_by_name('conv1/conv1:0')
            cnn_conv1 = sess.run(conv1, feed_dict={images: test_images[0:100], labels: test_labels[0:100]})
            cnn_conv1 = cnn_conv1.reshape((100, 24*24*64))
            
            # Get pool1 output
            pool1 = tf.get_default_graph().get_tensor_by_name('pool1:0')
            cnn_pool1 = sess.run(pool1, feed_dict={images: test_images[0:100], labels: test_labels[0:100]})
            cnn_pool1 = cnn_pool1.reshape((100, 12*12*64))
            
            sio.savemat('output/cifar10_cnn.mat', {'conv1': cnn_conv1,
                                                   'pool1': cnn_pool1})
            

            # Save weights for brian2
            with tf.variable_scope('conv1', reuse=True):
                w_conv1 = tf.get_variable("weights")
                b_conv1 = tf.get_variable("biases")

            with tf.variable_scope('conv2', reuse=True):
                w_conv2 = tf.get_variable("weights")
                b_conv2 = tf.get_variable("biases")

            with tf.variable_scope('local3', reuse=True):
                w_local3 = tf.get_variable("weights")
                b_local3 = tf.get_variable("biases")

            with tf.variable_scope('local4', reuse=True):
                w_local4 = tf.get_variable("weights")
                b_local4 = tf.get_variable("biases")

            with tf.variable_scope('softmax_linear', reuse=True):
                w_local5 = tf.get_variable("weights")
                b_local5 = tf.get_variable("biases")

            if not tf.gfile.Exists('output/weights'):
                tf.gfile.MakeDirs('output/weights')
            save_w_conv1 = sess.run(w_conv1)
            save_b_conv1 = sess.run(b_conv1)
            save_w_conv2 = sess.run(w_conv2)
            save_b_conv2 = sess.run(b_conv2)
            save_w_local3 = sess.run(w_local3)
            save_b_local3 = sess.run(b_local3)
            save_w_local4 = sess.run(w_local4)
            save_b_local4 = sess.run(b_local4)
            save_w_local5 = sess.run(w_local5)
            save_b_local5 = sess.run(b_local5)
            sio.savemat('output/weights/cifar10_weights.mat', {'conv1_w': save_w_conv1,
                                                               'conv1_b': save_b_conv1,
                                                               'conv2_w': save_w_conv2,
                                                               'conv2_b': save_b_conv2,
                                                               'ip1_w': save_w_local3,
                                                               'ip1_b': save_b_local3,
                                                               'ip2_w': save_w_local4,
                                                               'ip2_b': save_b_local4,
                                                               'ip3_w': save_w_local5,
                                                               'ip3_b': save_b_local5})


def main(argv=None):  # pylint: disable=unused-argument
    FLAGS.batch_size = 100
    evaluate()


if __name__ == '__main__':
    tf.app.run()
