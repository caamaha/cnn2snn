addpath ../caffe/matlab
addpath mnistHelper/

% load mnist dataset
images = loadMNISTImages('mnist/t10k-images-idx3-ubyte');
labels = loadMNISTLabels('mnist/t10k-labels-idx1-ubyte');
labels(labels == 0)  = 10; % Remap 0 to 10
 
caffe_pred = [];

caffe.set_mode_cpu();

% load pretrained model
model = './caffe/lenet_deploy.prototxt';
weights = './caffe/lenet_iter_10000.caffemodel';

% create net and load weights
net = caffe.Net(model, weights, 'test'); 


for k = 1:size(images, 3) / 100
    fprintf(1, '%d / %d\n', k, size(images, 3) / 100);
    net_inputs = images(:, :, (k-1)*100+1:k*100);
    %net_inputs = test_input;
    net_inputs = {reshape(net_inputs, [28, 28, 1, 100])};
    net.reshape_as_input(net_inputs);
    net.set_input_data(net_inputs);

    net.forward_prefilled();
    prob = net.blobs('prob').get_data();

    % show the predicted result
    [~, pred] = max(prob, [], 1);
    caffe_pred = [caffe_pred; (pred-1)'];
end

caffe_pred(caffe_pred == 0)  = 10; % Remap 0 to 10

acc = mean(labels(:) == caffe_pred(:));
fprintf('Accuracy: %0.3f%%\n', acc * 100);
