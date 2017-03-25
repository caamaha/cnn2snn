from brian2 import *
from brian2 import numpy as np
from matplotlib.pyplot import *

set_device('cpp_standalone')
prefs.codegen.target = 'weave'

start_scope()

eqs_conv1 = '''
v : 1
'''

conv1_thresh = 1
conv1_reset  = 0

input_group = PoissonGroup(4, 0 * Hz)

pool_group = NeuronGroup(1, eqs_conv1, threshold = 'v>=1', reset = 'v=0', method = 'euler')
inter_group  = NeuronGroup(4, eqs_conv1, threshold = 'v>=1', reset = 'v=0', method = 'euler', events={'under': 'v < 0'})
inter_group.run_on_event('under', 'v=0')
out_group  = NeuronGroup(1, eqs_conv1, threshold = 'v>=1', reset = 'v=0', method = 'euler')



synapses_input_inter = Synapses(input_group, inter_group, model='w:1', on_pre = 'v_post += w', method = 'linear', delay=1*ms)
synapses_input_inter.connect(condition = 'i == j')
synapses_input_inter.w = 0.1;

synapses_inter_pool = Synapses(inter_group, pool_group, model='w:1', on_pre = 'v_post += w', method = 'linear', delay=1*ms)
synapses_inter_pool.connect()
synapses_inter_pool.w = 0.5;

synapses_pool_inter = Synapses(pool_group, inter_group, model='w:1', on_pre = 'v_post += w', method = 'linear', delay=1*ms)
synapses_pool_inter.connect()
synapses_pool_inter.w = -0.5;


synapses_inter_out = Synapses(inter_group, out_group, model='w:1', on_pre = 'v_post += w', method = 'linear', delay=1*ms)
synapses_inter_out.connect()
synapses_inter_out.w = 0.1;

spike_mon = SpikeMonitor(out_group)
M = StateMonitor(inter_group, 'v', record=True)

input_group.rates = np.array([1, 500, 0, 0]) * Hz
run(1000 * ms)
# input_group.rates = 0 * Hz
# run(1000 * ms)

print spike_mon.count

plot(M.t/ms, M.v[0], '.')

show()