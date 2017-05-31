sample_count = 1;

load('../brian2/output/snn_counts.mat');
snn_pool1 = pool1(1:sample_count, :);


load('../tf_snn/output/cifar10_cnn.mat');
cnn_pool1 = double(reshape(pool1(1:sample_count, :), sample_count, []));

figure(2)
plot(cnn_pool1, snn_pool1, 'rx')