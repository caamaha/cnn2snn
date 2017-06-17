load('../tf_snn/output/cifar10_cnn.mat');
conv1_nz = conv1(conv1(:) > 0);
conv1_sort = sort(conv1_nz);
conv1_len = length(conv1_sort);
conv1_pscale = conv1_sort(floor(conv1_len * 0.999));


conv2_nz = conv2(conv2(:) > 0);
conv2_sort = sort(conv2_nz);
conv2_len = length(conv2_sort);
conv2_pscale = conv2_sort(floor(conv2_len * 0.999));


ip1_nz = ip1(ip1(:) > 0);
ip1_sort = sort(ip1_nz);
ip1_len = length(ip1_sort);
ip1_pscale = ip1_sort(floor(ip1_len * 0.999));

ip2_nz = ip2(ip2(:) > 0);
ip2_sort = sort(ip2_nz);
ip2_len = length(ip2_sort);
ip2_pscale = ip2_sort(floor(ip2_len * 0.999));

ip3_nz = ip3(ip3(:) > 0);
ip3_sort = sort(ip3_nz);
ip3_len = length(ip3_sort);
ip3_pscale = ip3_sort(floor(ip3_len * 0.999));