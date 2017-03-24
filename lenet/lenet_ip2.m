addpath ../caffe/matlab
addpath mnistHelper/

% record ip2 features
train_ip2_val = [];
test_ip2_val = [];

% load mnist dataset
train_images = loadMNISTImages('mnist/train-images-idx3-ubyte');
test_images  = loadMNISTImages('mnist/t10k-images-idx3-ubyte');

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

save('ip2_val.mat', 'train_ip2_val', 'test_ip2_val');