from brian2 import *

start_scope()

eqs_conv1 = '''
dv/dt = (I-v)/tau : 1
I : 1
tau : second
'''

conv1_thresh = 1
conv1_reset  = 0

input_group = PoissonGroup(100, 0 * Hz)

conv1_group  = NeuronGroup(100, eqs_conv1, threshold = conv1_thresh, reset = conv1_reset, method = 'euler')

synapses_input_conv1 = Synapses(input_group, conv1_group, model='w:1', on_pre = 'v_post += w', method = 'linear')

synapses_input_conv1.connect(i = [10, 5], j = [40, 60])

synapses_input_conv1.w = [1, 2];

print synapses_input_conv1.w[5, 60]