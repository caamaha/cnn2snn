sample_count = 1;

load('../brian2/output/snn_counts.mat');
snn_conv1 = uint8(conv1(1:sample_count, :));
snn_pool1 = uint8(pool1(1:sample_count, :));

snn_conv1 = reshape(snn_conv1, 64, 24, []);
snn_pool1 = reshape(snn_pool1, 64, 12, []);

map_conv1 = squeeze(snn_conv1(1, :, :));

map_pool1 = squeeze(snn_pool1(1, :, :));


figure(1)
imshow(map_conv1)

figure(2)
imshow(map_pool1)