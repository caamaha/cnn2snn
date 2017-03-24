addpath ../caffe/matlab
addpath mnistHelper/

% load mnist dataset
images = loadMNISTImages('mnist/t10k-images-idx3-ubyte');
labels = loadMNISTLabels('mnist/t10k-labels-idx1-ubyte');
 
%imshow(images(:,:,1));
%disp(labels(1));

caffe.set_mode_cpu();

% load pretrained model
model = './caffe/lenet_deploy.prototxt';
weights = './caffe/lenet_iter_10000.caffemodel';

% create net and load weights
net = caffe.Net(model, weights, 'test'); 

test_num = 2;

test_input = zeros(28, 28);
test_input(1, 1) = 1;
test_input(1, 2) = 1;

net_inputs = images(:, :, 1:test_num);
%net_inputs = test_input;
net_inputs = {reshape(net_inputs, [28, 28, 1, test_num])};
net.reshape_as_input(net_inputs);
net.set_input_data(net_inputs);

net.forward_prefilled();
prob = net.blobs('prob').get_data();

% show the predicted result
[~, pred] = max(prob, [], 1);
disp(pred-1);
% show the label
disp(labels(1:test_num)');

% save network weights
conv1_weights = net.params('conv1', 1).get_data();
conv2_weights = net.params('conv2', 1).get_data();
ip1_weights = net.params('ip1', 1).get_data();
ip2_weights = net.params('ip2', 1).get_data();

save('brian2/weights/pretrained_lenet.mat', 'conv1_weights', 'conv2_weights', 'ip1_weights', 'ip2_weights');
