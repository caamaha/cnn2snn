% 绘制 准确率 vs 运行时间 图
process_num = 20;
samples_num = 10000;
samples_per_count = samples_num / process_num;

ip3_t = [];
ip3_s = [];

load('test_labels.mat')
[~, test_labels] = max(test_labels');

spikes_time = zeros(500, samples_num);

for i = 0:process_num-1
    file_path = sprintf('../experiments/2/result/snn_ip3_spikes_%d_%d.mat', i*samples_per_count, (i+1)*samples_per_count);
    load(file_path);
    
    for s = 1:samples_per_count
        ip3_time = zeros(500, 10);
        for t = 1:length(snn_t)
            % 记录脉冲发放时刻和脉冲发放个数
            curr_time = snn_t(t) - (s-1) * 0.5;
            if curr_time > 0 && curr_time <= 0.5
                ip3_time(ceil(curr_time*1000), snn_ip3(t)+1) = 1;
            elseif curr_time > 0.5
                break;
            end
        end
        
        % 计算准确率
        for t = 2:500
            ip3_time(t, :) = ip3_time(t, :) + ip3_time(t-1, :);
        end
        [~, ip3_max] = max(ip3_time');
        spikes_time(:, s+i*samples_per_count) = ip3_max;
    end
end

positive_time = zeros(500, 1);
for t = 1:500
    positive_time(t) = mean(spikes_time(t, :) == test_labels(1:samples_num));
end
