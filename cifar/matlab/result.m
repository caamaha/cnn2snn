% close all
% clear

sample_count = 1;

load('../brian2/output/snn_counts.mat');
snn_conv1 = double(conv1(1:sample_count, :));
snn_pool1 = double(pool1(1:sample_count, :));
snn_conv2 = double(conv2(1:sample_count, :));
%snn_pool1 = pool1(1:sample_count, :);


load('../tf_snn/output/cifar10_cnn.mat');
cnn_conv1 = double(reshape(conv1(1:sample_count, :), sample_count, []));
cnn_pool1 = double(reshape(pool1(1:sample_count, :), sample_count, []));
cnn_conv2 = double(reshape(conv2(1:sample_count, :), sample_count, []));
cnn_pool2 = double(reshape(pool2(1:sample_count, :), sample_count, []));

conv1_p = polyfit(cnn_conv1(:), snn_conv1(:), 1);
pool1_p = polyfit(cnn_pool1(:), snn_pool1(:), 1);
conv2_p = polyfit(cnn_conv2(:), snn_conv2(:), 1);

figure(2);clf;
subplot(221)
hold on;
plot(cnn_conv1, snn_conv1, 'rx')
plot(cnn_conv1, polyval(conv1_p, cnn_conv1(:)), 'g')

xlabel('cnn')
ylabel('snn')
subplot(222)
hold on;
plot(cnn_pool1, snn_pool1, 'rx')
plot(cnn_pool1, polyval(pool1_p, cnn_pool1(:)), 'g')

subplot(223)
hold on;
plot(cnn_conv2, snn_conv2, 'rx')
plot(cnn_conv2, polyval(conv2_p, cnn_conv2(:)), 'g')
