from brian2 import *
from brian2 import numpy as np
from matplotlib.pyplot import *
import scipy.io as sio

start_scope()

eqs_conv1 = '''
v : 1
'''

conv1_thresh = 1
conv1_reset  = 0

input_group = PoissonGroup(4, 0 * Hz)

pool_group = NeuronGroup(1, eqs_conv1, threshold = 'v>=1', reset = 'v=0', method = 'euler')
inter_group  = NeuronGroup(4, eqs_conv1, threshold = 'v>=1', reset = 'v=0', method = 'euler')
out_group  = NeuronGroup(1, eqs_conv1, threshold = 'v>=1', reset = 'v=0', method = 'euler')



synapses_input_inter = Synapses(input_group, inter_group, model='w:1', on_pre = 'v_post += w', method = 'linear', delay=1*ms)
synapses_input_inter.connect(condition = 'i == j')
synapses_input_inter.w = 0.1;

synapses_inter_pool = Synapses(inter_group, pool_group, model='w:1', on_pre = 'v_post += w', method = 'linear', delay=1*ms)
synapses_inter_pool.connect()
synapses_inter_pool.w = 0.5;

synapses_pool_inter = Synapses(pool_group, inter_group, model='w:1', on_pre = 'v_post = clip(v_post+w, 0, 1)', method = 'linear', delay=1*ms)
synapses_pool_inter.connect()
synapses_pool_inter.w = -0.5;


synapses_inter_out = Synapses(inter_group, out_group, model='w:1', on_pre = 'v_post += w', method = 'linear', delay=1*ms)
synapses_inter_out.connect()
synapses_inter_out.w = 0.1;

spike_mon = SpikeMonitor(inter_group)
M = StateMonitor(inter_group, 'v', record=True)

input_group.rates = np.array([400, 500, 300, 200]) * Hz



run(1000 * ms)
# input_group.rates = 0 * Hz
# run(1000 * ms)

plot(M.t/ms, M.v[0], '.')

print(spike_mon.t)
print(spike_mon.i)
sio.savemat('output/snn_spikes.mat', {'snn_t': np.array(spike_mon.t), 'snn_ip3': np.array(spike_mon.i)})

show()