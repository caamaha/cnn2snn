sample_count = 1;

load('../brian2/output/snn_counts.mat');
snn_conv1 = double(conv1(1:sample_count, :));
snn_pool1 = double(pool1(1:sample_count, :));
snn_conv2 = double(conv2(1:sample_count, :));

load('../tf_snn/output/cifar10_cnn.mat');
cnn_conv1 = double(reshape(conv1(1:sample_count, :), sample_count, []));
cnn_pool1 = double(reshape(pool1(1:sample_count, :), sample_count, []));
cnn_conv2 = double(reshape(conv2(1:sample_count, :), sample_count, []));
cnn_pool2 = double(reshape(pool2(1:sample_count, :), sample_count, []));

load('../tf_snn/output/weights/cifar10_weights.mat');

snn_conv1 = reshape(snn_conv1, 64, 24, []);
snn_pool1 = reshape(snn_pool1, 64, 12, []);
snn_conv2 = reshape(snn_conv2, 64, 12, []);

cnn_conv1 = reshape(cnn_conv1, 64, 24, []);
cnn_pool1 = reshape(cnn_pool1, 64, 12, []);
cnn_conv2 = reshape(cnn_conv2, 64, 12, []);

% check conv1
cnn_y = 0;
snn_y = 0;
px = 4;
py = 0;
for h = 1:5
    for w = 1:5
        for d = 1:64
            cnn_y = cnn_y + conv2_w(h, w, d, 1) * cnn_pool1(d, w+px, h+py);
            snn_y = snn_y + conv2_w(h, w, d, 1) * snn_pool1(d, w+px, h+py)/255.0;
            fprintf(1, '%d%d%2d  %4.2f - %4.2f : %4.2f - %4.2f | %4.2f\n', h, w, d, cnn_pool1(d, w+px, h+py), snn_pool1(d, w+px, h+py)/255.0, cnn_y, snn_y, conv2_w(h,w,d,1));
        end
    end
end
cnn_y = cnn_y + conv2_b(1, 1)
snn_y = snn_y + conv2_b(1, 1)
cnn_conv2(1, 3+px, 3+py)
snn_conv2(1, 3+px, 3+py)