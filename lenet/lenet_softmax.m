addpath 'softmax'
addpath 'softmax/fminlbfgs'

inputSize  = 10;    % Feature size (ip2 feature length is 10)
numClasses = 10;    % Number of classes (MNIST images fall into 10 classes)
lambda = 1e-4;      % Weight decay parameter

% load mnist dataset
train_labels = loadMNISTLabels('mnist/train-labels-idx1-ubyte');
test_labels  = loadMNISTLabels('mnist/t10k-labels-idx1-ubyte');

train_labels(train_labels == 0) = 10; % Remap 0 to 10
test_labels(test_labels == 0)  = 10; % Remap 0 to 10

% load ip2 feature
load('ip2_val.mat');

inputData = train_ip2_val;

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

% save softmax weights
softmax_weights = softmaxModel.optTheta';
save('brian2/weights/pretrained_lenet_softmax.mat', 'softmax_weights');