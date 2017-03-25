addpath mnistHelper/

load('brian2/output/it_counts.mat');

labels = loadMNISTLabels('mnist/t10k-labels-idx1-ubyte')';
labels(labels == 0)  = 10; % Remap 0 to 10

[~, pred] = max(it_counts', [], 1);

acc = mean(labels(:) == pred(:));
fprintf('Accuracy: %0.3f%%\n', acc * 100);