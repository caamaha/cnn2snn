addpath ../caffe/matlab
addpath mnistHelper/

caffe.set_mode_cpu();

% load pretrained model
model = './caffe/lenet_deploy.prototxt';
weights = './caffe/lenet_iter_10000.caffemodel';

% create net and load weights
net = caffe.Net(model, weights, 'test'); 

test_input = zeros(28, 28);
test_input(1, 1) = 1;
test_input(1, 2) = 1;

net_inputs = test_input;
net_inputs = {reshape(net_inputs, [28, 28, 1, 1])};
net.reshape_as_input(net_inputs);
net.set_input_data(net_inputs);

net.forward_prefilled();

ip1_weights = net.params('ip1', 1).get_data();
ip1_weights(33, 1) = 1000;
net.params('ip1', 1).set_data(ip1_weights);

net.forward_prefilled();
pool2_val = net.blobs('pool2').get_data();
ip1_val = net.blobs('ip1').get_data();





% save network weights
conv1_weights = net.params('conv1', 1).get_data();
conv2_weights = net.params('conv2', 1).get_data();
ip1_weights = net.params('ip1', 1).get_data();
ip2_weights = net.params('ip2', 1).get_data();




