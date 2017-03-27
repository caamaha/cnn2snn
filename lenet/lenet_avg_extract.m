addpath ../caffe/matlab
addpath mnistHelper/

% record ip2 features
train_ip2_val = [];
test_ip2_val = [];

% load mnist dataset
train_images = loadMNISTImages('mnist/train-images-idx3-ubyte');
test_images  = loadMNISTImages('mnist/t10k-images-idx3-ubyte');
train_labels = loadMNISTLabels('mnist/train-labels-idx1-ubyte');
test_labels  = loadMNISTLabels('mnist/t10k-labels-idx1-ubyte');

train_labels(train_labels == 0) = 10; % Remap 0 to 10
test_labels(test_labels == 0)  = 10; % Remap 0 to 10

caffe.set_mode_cpu();

% load pretrained model
model = './caffe/lenet_deploy.prototxt';
weights = './caffe/lenet_iter_10000.caffemodel';

% create net and load weights
net = caffe.Net(model, weights, 'test'); 

for k = 1:size(train_images, 3) / 100
    fprintf(1, '%d / %d\n', k, size(train_images, 3) / 100);
    net_inputs = train_images(:, :, (k-1)*100+1:k*100);
    net_inputs = {reshape(net_inputs, [28, 28, 1, 100])};
    net.reshape_as_input(net_inputs);
    net.set_input_data(net_inputs);
    net.forward_prefilled();
    train_ip2_val = [train_ip2_val, net.blobs('prob').get_data()];
end

for k = 1:size(test_images, 3) / 100
    fprintf(1, '%d / %d\n', k, size(test_images, 3) / 100);
    net_inputs = test_images(:, :, (k-1)*100+1:k*100);
    net_inputs = {reshape(net_inputs, [28, 28, 1, 100])};
    net.reshape_as_input(net_inputs);
    net.set_input_data(net_inputs);
    net.forward_prefilled();
    test_ip2_val = [test_ip2_val, net.blobs('prob').get_data()];
end

% train a softmax classifier

inputData = train_ip2_val;

numClasses = 10;

% Randomly initialise theta
theta = 0.005 * randn(numClasses * inputSize, 1);

[cost, grad] = softmaxCost(theta, numClasses, inputSize, lambda, inputData, train_labels);

options.MaxIter = 100;
softmaxModel = softmaxTrain(inputSize, numClasses, lambda, ...
                            inputData, train_labels, options);
                        
% testing
inputData = test_ip2_val;
[pred] = softmaxPredict(softmaxModel, inputData);
acc = mean(test_labels(:) == pred(:));
fprintf('Accuracy: %0.3f%%\n', acc * 100);

% save network weights
softmax_weights = softmaxModel.optTheta';
conv1_weights = net.params('conv1', 1).get_data();
conv2_weights = net.params('conv2', 1).get_data();
ip1_weights = net.params('ip1', 1).get_data();
ip2_weights = net.params('ip2', 1).get_data();

save('brian2/weights/lenet_avg_pooling.mat', 'conv1_weights', 'conv2_weights', 'ip1_weights', 'ip2_weights', 'softmax_weights');

