%close all
%clear

sample = 1;
sample_num = 1;

load('../brian2/output/snn_counts.mat');
snn_conv1 = double(conv1(sample, :));
snn_pool1 = double(pool1(sample, :));
snn_conv2 = double(conv2(sample, :));
snn_pool2 = double(pool2(sample, :));
snn_ip1   = double(ip1(sample, :));
snn_ip2   = double(ip2(sample, :));
snn_ip3   = double(ip3(sample, :));

load('../tf_snn/output/cifar10_cnn.mat');
cnn_conv1 = double(reshape(conv1(sample, :), sample_num, []));
cnn_pool1 = double(reshape(pool1(sample, :), sample_num, []));
cnn_conv2 = double(reshape(conv2(sample, :), sample_num, []));
cnn_pool2 = double(reshape(pool2(sample, :), sample_num, []));
cnn_ip1   = double(reshape(ip1(sample, :), sample_num, []));
cnn_ip2   = double(reshape(ip2(sample, :), sample_num, []));
cnn_ip3   = double(reshape(ip3(sample, :), sample_num, []));

load('../tf_snn/output/weights/cifar10_weights.mat');

conv1_p = polyfit(cnn_conv1(:), snn_conv1(:), 1);
pool1_p = polyfit(cnn_pool1(:), snn_pool1(:), 1);
conv2_p = polyfit(cnn_conv2(:), snn_conv2(:), 1);
pool2_p = polyfit(cnn_pool2(:), snn_pool2(:), 1);

figure(1);clf;
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

subplot(224)
hold on;
plot(cnn_pool2, snn_pool2, 'rx')
plot(cnn_pool2, polyval(pool2_p, cnn_pool2(:)), 'g')

figure(2);clf
subplot(221)
hold on;
plot(cnn_ip1, snn_ip1, 'rx')

subplot(222)
plot(cnn_ip2, snn_ip2, 'rx')

subplot(223)
plot(cnn_ip3, snn_ip3, 'rx')