#include <stdlib.h>
#include "objects.h"
#include <ctime>
#include <time.h>

#include "run.h"
#include "brianlib/common_math.h"
#include "randomkit.h"

#include "code_objects/synapses_pre_push_spikes.h"
#include "code_objects/synapses_2_pre_initialise_queue.h"
#include "code_objects/synapses_3_pre_initialise_queue.h"
#include "code_objects/neurongroup_resetter_codeobject.h"
#include "code_objects/synapses_pre_codeobject.h"
#include "code_objects/neurongroup_2_resetter_codeobject.h"
#include "code_objects/neurongroup_1_thresholder_codeobject.h"
#include "code_objects/neurongroup_2_thresholder_codeobject.h"
#include "code_objects/synapses_2_pre_codeobject.h"
#include "code_objects/synapses_3_pre_codeobject.h"
#include "code_objects/synapses_1_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_2_pre_push_spikes.h"
#include "code_objects/statemonitor_codeobject.h"
#include "code_objects/synapses_3_pre_push_spikes.h"
#include "code_objects/spikemonitor_codeobject.h"
#include "code_objects/neurongroup_1_resetter_codeobject.h"
#include "code_objects/synapses_2_synapses_create_generator_codeobject.h"
#include "code_objects/neurongroup_thresholder_codeobject.h"
#include "code_objects/synapses_1_pre_push_spikes.h"
#include "code_objects/synapses_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_1_pre_codeobject.h"
#include "code_objects/poissongroup_thresholder_codeobject.h"
#include "code_objects/synapses_3_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_1_pre_initialise_queue.h"
#include "code_objects/synapses_pre_initialise_queue.h"


#include <iostream>
#include <fstream>




int main(int argc, char **argv)
{

	brian_start();

	{
		using namespace brian;

		
                
        _array_defaultclock_dt[0] = 0.0001;
        _array_defaultclock_dt[0] = 0.0001;
        _array_defaultclock_dt[0] = 0.0001;
        
                        
                        for(int i=0; i<_num__array_poissongroup_rates; i++)
                        {
                            _array_poissongroup_rates[i] = 0.0;
                        }
                        
        _dynamic_array_synapses_delay.resize(1);
        _dynamic_array_synapses_delay.resize(1);
        _dynamic_array_synapses_delay[0] = 0.001;
        _run_synapses_synapses_create_generator_codeobject();
        
                        
                        for(int i=0; i<_dynamic_array_synapses_w.size(); i++)
                        {
                            _dynamic_array_synapses_w[i] = 0.1;
                        }
                        
        _dynamic_array_synapses_1_delay.resize(1);
        _dynamic_array_synapses_1_delay.resize(1);
        _dynamic_array_synapses_1_delay[0] = 0.001;
        _run_synapses_1_synapses_create_generator_codeobject();
        
                        
                        for(int i=0; i<_dynamic_array_synapses_1_w.size(); i++)
                        {
                            _dynamic_array_synapses_1_w[i] = 0.5;
                        }
                        
        _dynamic_array_synapses_2_delay.resize(1);
        _dynamic_array_synapses_2_delay.resize(1);
        _dynamic_array_synapses_2_delay[0] = 0.001;
        _run_synapses_2_synapses_create_generator_codeobject();
        
                        
                        for(int i=0; i<_dynamic_array_synapses_2_w.size(); i++)
                        {
                            _dynamic_array_synapses_2_w[i] = -0.5;
                        }
                        
        _dynamic_array_synapses_3_delay.resize(1);
        _dynamic_array_synapses_3_delay.resize(1);
        _dynamic_array_synapses_3_delay[0] = 0.001;
        _run_synapses_3_synapses_create_generator_codeobject();
        
                        
                        for(int i=0; i<_dynamic_array_synapses_3_w.size(); i++)
                        {
                            _dynamic_array_synapses_3_w[i] = 0.1;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_statemonitor__indices; i++)
                        {
                            _array_statemonitor__indices[i] = _static_array__array_statemonitor__indices[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_poissongroup_rates; i++)
                        {
                            _array_poissongroup_rates[i] = _static_array__array_poissongroup_rates[i];
                        }
                        
        _array_defaultclock_timestep[0] = 0L;
        _array_defaultclock_t[0] = 0.0;
        _run_synapses_1_pre_initialise_queue();
        _run_synapses_2_pre_initialise_queue();
        _run_synapses_3_pre_initialise_queue();
        _run_synapses_pre_initialise_queue();
        magicnetwork.clear();
        magicnetwork.add(&defaultclock, _run_statemonitor_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_1_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_2_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_poissongroup_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_spikemonitor_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_1_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_1_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_2_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_2_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_3_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_3_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_1_resetter_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_2_resetter_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_resetter_codeobject);
        magicnetwork.run(1.0, NULL, 10.0);
        _debugmsg_synapses_pre_codeobject();
        
        _debugmsg_synapses_2_pre_codeobject();
        
        _debugmsg_synapses_3_pre_codeobject();
        
        _debugmsg_spikemonitor_codeobject();
        
        _debugmsg_synapses_1_pre_codeobject();

	}

	brian_end();

	return 0;
}