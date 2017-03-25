from brian2 import *
from brian2 import numpy as np

start_scope()

eqs_conv1 = '''
v : 1
'''

conv1_thresh = 1
conv1_reset  = 0

input_group = PoissonGroup(4, 0 * Hz)

max_group  = NeuronGroup(4, eqs_conv1, threshold = 'v>=2', reset = 'v=0', method = 'euler')
out_group  = NeuronGroup(1, eqs_conv1, threshold = 'v>=1', reset = 'v=0', method = 'euler')


synapses_input_max = Synapses(input_group, max_group, model='w:1', on_pre = 'v_post += w', method = 'linear', delay=1*ms)
synapses_input_max.connect(condition = 'i == j')
synapses_input_max.w = 1;

synapses_max_max = Synapses(max_group, max_group, model='w:1', on_pre = 'v_post += w', method = 'linear', delay=1*ms)
synapses_max_max.connect(condition = 'i != j')
synapses_max_max.w = -1;

synapses_max_out = Synapses(max_group, out_group, model='w:1', on_pre = 'v_post += w', method = 'linear', delay=1*ms)
synapses_max_out.connect()
synapses_max_out.w = 1;

spike_mon = SpikeMonitor(out_group)

input_group.rates = np.array([50, 50, 0, 0]) * Hz
run(10000 * ms)
input_group.rates = 0 * Hz
run(1000 * ms)

print spike_mon.count