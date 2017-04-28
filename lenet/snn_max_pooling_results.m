addpath mnistHelper/

load('brian2/output/max_pooing_it_counts.mat');

labels = loadMNISTLabels('mnist/t10k-labels-idx1-ubyte')';
% labels(labels == 0)  = 10; % Remap 0 to 10 caffe version
labels = labels + 1;  % tf version

[~, pred] = max(it_counts', [], 1);

acc = mean(labels(1:10) == pred(1:10));
fprintf('Accuracy: %0.3f%%\n', acc * 100);