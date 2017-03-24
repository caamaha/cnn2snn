addpath ../caffe/matlab
 
caffe.set_mode_cpu();

% load pretrained model
model = './caffe/lenet_deploy.prototxt';
weights = './caffe/lenet_iter_10000.caffemodel';

% create net and load weights
net = caffe.Net(model, weights, 'test'); 

% save network weights
conv1_weights = net.params('conv1', 1).get_data();
conv2_weights = net.params('conv2', 1).get_data();
ip1_weights = net.params('ip1', 1).get_data();
ip2_weights = net.params('ip2', 1).get_data();

save('brian2/weights/pretrained_lenet.mat', 'conv1_weights', 'conv2_weights', 'ip1_weights', 'ip2_weights');
