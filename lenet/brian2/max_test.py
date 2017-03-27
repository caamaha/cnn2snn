from brian2 import *
from brian2 import numpy as np
from matplotlib.pyplot import *

start_scope()

eqs_conv1 = '''
v : 1
'''

input_group = PoissonGroup(1, 0 * Hz)


out_group  = NeuronGroup(1, eqs_conv1, threshold = 'v>=1', reset = 'v=0', method = 'euler')


synapses_input_inter = Synapses(input_group, out_group, model='w:1', on_pre = 'v_post = clip(v_post+w, 0, 1)', method = 'linear', delay=1*ms)
synapses_input_inter.connect()
synapses_input_inter.w = -0.1;



input_group.rates = 100 * Hz

run(100 * ms)
