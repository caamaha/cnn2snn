addpath ../caffe/matlab
addpath mnistHelper/

% load mnist dataset
images = loadMNISTImages('mnist/train-images-idx3-ubyte');
labels = loadMNISTLabels('mnist/train-labels-idx1-ubyte');
 
%imshow(images(:,:,1));
%disp(labels(1));

caffe.set_mode_cpu();

% load pretrained model
model = './caffe/lenet_deploy.prototxt';
weights = './caffe/lenet_iter_10000.caffemodel';

% create net and load weights
net = caffe.Net(model, weights, 'test'); 

test_num = 10;

net_inputs = images(:, :, 1:test_num);
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

caffe.reset_all();
