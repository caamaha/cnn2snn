addpath ../caffe/matlab
addpath mnistHelper/

caffe.set_mode_cpu();

% load pretrained model
model = './caffe/lenet_deploy.prototxt';
weights = './caffe/lenet_iter_10000.caffemodel';

% create net and load weights
net = caffe.Net(model, weights, 'test'); 

% load mnist dataset
images = loadMNISTImages('mnist/t10k-images-idx3-ubyte');
labels = loadMNISTLabels('mnist/t10k-labels-idx1-ubyte');
labels(labels == 0)  = 10; % Remap 0 to 10

net_inputs = images(:, :, 2);
net_inputs = {reshape(net_inputs, [28, 28, 1, 1])};
net.reshape_as_input(net_inputs);
net.set_input_data(net_inputs);

net.forward_prefilled();

ip2_val = net.blobs('ip2').get_data();

softmax_weights = softmaxModel.optTheta;





