load('../tf_snn/output/cifar10_cnn.mat');
conv1_nz = conv1(conv1(:) > 0);
[N,X] = hist(conv1_nz, 100);
set(gca, 'YScale' ,'log');

conv1_sort = sort(conv1_nz);
conv1_len = length(conv1_sort);
conv1_pscale = conv1_sort(floor(conv1_len * 0.999));

clf;hold on;
N(N < 1) = 1;
bar(X, log(N) / log(10));
logyts = get(gca, 'YTick');
expyts = exp(logyts*log(10));
set(gca, 'YTickLabel', expyts)
plot([conv1_pscale, conv1_pscale], [0, logyts(end)], '--r', 'LineWidth',2)
text(double(conv1_pscale)+0.1, double(logyts(end))-0.1, '99.9%', 'Color', 'Red')
xlabel('激活值')
ylabel('个数')