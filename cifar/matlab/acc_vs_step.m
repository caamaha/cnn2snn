load('l1.mat');
l1 = positive_time;
load('l2.mat');
l2 = positive_time;
load('l3.mat');
l3 = positive_time;
load('l4.mat');
l4 = positive_time;


plot(1:500, l1, 'r', 1:500, l2, 'g', 1:500, l3, 'b', 1:500, l4, 'c');