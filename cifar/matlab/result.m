sample_count = 1;

load('../brian2/output/snn_counts.mat');
snn_conv1 = conv1(1:sample_count, :);


load('../tf_snn/output/cifar10_cnn.mat');
cnn_conv1 = double(reshape(conv1(1:sample_count, :), sample_count, []));

% p = lsqcurvefit(@(p, x) p(1)*x.^2 + p(2)*x, [0, 1], cnn_conv1(:), snn_conv1(:));
% p = [p, 0];
% 
% clf; hold on;
% plot(cnn_conv1, snn_conv1, 'ro');
% plot(0:0.01:max(cnn_conv1(:)), polyval(p, 0:0.01:max(cnn_conv1(:))));
% xlabel('cnn_conv1 * 255')
% ylabel('snn_conv1 counts in 1000ms');

figure(2)
plot(cnn_conv1, snn_conv1, 'rx')