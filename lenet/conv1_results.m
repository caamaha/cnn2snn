load('brian2/output/conv1_counts.mat');
load('tensorflow/output/conv1_out.mat');

sample_count = 10;

snn_conv1 = conv1_counts(1:10, :);
cnn_conv1 = double(reshape(conv1_out, sample_count, []) * 255);

p = lsqcurvefit(@(p, x) p(1)*x.^2 + p(2)*x, [0, 1], cnn_conv1(:), snn_conv1(:));
p = [p, 0];

clf; hold on;
plot(cnn_conv1, snn_conv1, 'ro');
plot(0:0.01:max(cnn_conv1(:)), polyval(p, 0:0.01:max(cnn_conv1(:))));
xlabel('cnn_conv1 * 255')
ylabel('snn_conv1 counts in 1000ms');