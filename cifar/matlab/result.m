sample_count = 1;

load('../brian2/output/snn_counts.mat');
snn_conv1 = conv1(1:sample_count, :);
snn_pool1 = pool1(1:sample_count, :);


load('../tf_snn/output/cifar10_cnn.mat');
cnn_conv1 = double(reshape(conv1(1:sample_count, :), sample_count, []));
cnn_pool1 = double(reshape(pool1(1:sample_count, :), sample_count, []));

figure(1)
clf;
subplot(121)
plot(cnn_conv1, snn_conv1, 'rx')
subplot(122)
plot(cnn_pool1, snn_pool1, 'rx')

