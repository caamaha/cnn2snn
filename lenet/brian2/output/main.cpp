#include <stdlib.h>
#include "objects.h"
#include <ctime>
#include <time.h>

#include "run.h"
#include "brianlib/common_math.h"
#include "randomkit.h"

#include "code_objects/synapses_pre_push_spikes.h"
#include "code_objects/synapses_2_pre_initialise_queue.h"
#include "code_objects/neurongroup_4_thresholder_codeobject.h"
#include "code_objects/synapses_3_pre_initialise_queue.h"
#include "code_objects/synapses_2_synapses_create_array_codeobject.h"
#include "code_objects/synapses_2_pre_push_spikes.h"
#include "code_objects/synapses_4_pre_codeobject.h"
#include "code_objects/synapses_pre_codeobject.h"
#include "code_objects/neurongroup_2_resetter_codeobject.h"
#include "code_objects/neurongroup_1_thresholder_codeobject.h"
#include "code_objects/neurongroup_2_thresholder_codeobject.h"
#include "code_objects/synapses_2_pre_codeobject.h"
#include "code_objects/synapses_3_synapses_create_array_codeobject.h"
#include "code_objects/neurongroup_5_resetter_codeobject.h"
#include "code_objects/neurongroup_6_resetter_codeobject.h"
#include "code_objects/neurongroup_thresholder_1_codeobject.h"
#include "code_objects/synapses_5_pre_initialise_queue.h"
#include "code_objects/synapses_3_pre_codeobject.h"
#include "code_objects/neurongroup_resetter_codeobject.h"
#include "code_objects/neurongroup_5_thresholder_codeobject.h"
#include "code_objects/synapses_1_pre_codeobject.h"
#include "code_objects/neurongroup_resetter_1_codeobject.h"
#include "code_objects/synapses_5_synapses_create_array_codeobject.h"
#include "code_objects/neurongroup_1_resetter_1_codeobject.h"
#include "code_objects/synapses_3_pre_push_spikes.h"
#include "code_objects/synapses_6_pre_codeobject.h"
#include "code_objects/spikemonitor_codeobject.h"
#include "code_objects/neurongroup_2_thresholder_1_codeobject.h"
#include "code_objects/synapses_4_synapses_create_array_codeobject.h"
#include "code_objects/synapses_5_pre_push_spikes.h"
#include "code_objects/neurongroup_1_resetter_codeobject.h"
#include "code_objects/synapses_1_synapses_create_array_codeobject.h"
#include "code_objects/synapses_1_pre_initialise_queue.h"
#include "code_objects/neurongroup_4_resetter_codeobject.h"
#include "code_objects/neurongroup_thresholder_codeobject.h"
#include "code_objects/neurongroup_1_thresholder_1_codeobject.h"
#include "code_objects/synapses_6_synapses_create_array_codeobject.h"
#include "code_objects/neurongroup_6_thresholder_codeobject.h"
#include "code_objects/synapses_6_pre_initialise_queue.h"
#include "code_objects/synapses_5_pre_codeobject.h"
#include "code_objects/synapses_1_pre_push_spikes.h"
#include "code_objects/neurongroup_3_resetter_1_codeobject.h"
#include "code_objects/synapses_4_pre_push_spikes.h"
#include "code_objects/neurongroup_3_resetter_codeobject.h"
#include "code_objects/synapses_4_pre_initialise_queue.h"
#include "code_objects/synapses_6_pre_push_spikes.h"
#include "code_objects/neurongroup_3_thresholder_codeobject.h"
#include "code_objects/poissongroup_thresholder_codeobject.h"
#include "code_objects/neurongroup_3_thresholder_1_codeobject.h"
#include "code_objects/neurongroup_2_resetter_1_codeobject.h"
#include "code_objects/synapses_synapses_create_array_codeobject.h"
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
                        
        
                        
                        for(int i=0; i<_num__array_synapses_sources; i++)
                        {
                            _array_synapses_sources[i] = _static_array__array_synapses_sources[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_targets; i++)
                        {
                            _array_synapses_targets[i] = _static_array__array_synapses_targets[i];
                        }
                        
        _run_synapses_synapses_create_array_codeobject();
        
                        
                        for(int i=0; i<_dynamic_array_synapses_w.size(); i++)
                        {
                            _dynamic_array_synapses_w[i] = _static_array__dynamic_array_synapses_w[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_1_sources; i++)
                        {
                            _array_synapses_1_sources[i] = _static_array__array_synapses_1_sources[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_1_targets; i++)
                        {
                            _array_synapses_1_targets[i] = _static_array__array_synapses_1_targets[i];
                        }
                        
        _run_synapses_1_synapses_create_array_codeobject();
        
                        
                        for(int i=0; i<_dynamic_array_synapses_1_w.size(); i++)
                        {
                            _dynamic_array_synapses_1_w[i] = _static_array__dynamic_array_synapses_1_w[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_2_sources; i++)
                        {
                            _array_synapses_2_sources[i] = _static_array__array_synapses_2_sources[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_2_targets; i++)
                        {
                            _array_synapses_2_targets[i] = _static_array__array_synapses_2_targets[i];
                        }
                        
        _run_synapses_2_synapses_create_array_codeobject();
        
                        
                        for(int i=0; i<_dynamic_array_synapses_2_w.size(); i++)
                        {
                            _dynamic_array_synapses_2_w[i] = _static_array__dynamic_array_synapses_2_w[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_3_sources; i++)
                        {
                            _array_synapses_3_sources[i] = _static_array__array_synapses_3_sources[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_3_targets; i++)
                        {
                            _array_synapses_3_targets[i] = _static_array__array_synapses_3_targets[i];
                        }
                        
        _run_synapses_3_synapses_create_array_codeobject();
        
                        
                        for(int i=0; i<_dynamic_array_synapses_3_w.size(); i++)
                        {
                            _dynamic_array_synapses_3_w[i] = _static_array__dynamic_array_synapses_3_w[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_4_sources; i++)
                        {
                            _array_synapses_4_sources[i] = _static_array__array_synapses_4_sources[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_4_targets; i++)
                        {
                            _array_synapses_4_targets[i] = _static_array__array_synapses_4_targets[i];
                        }
                        
        _run_synapses_4_synapses_create_array_codeobject();
        
                        
                        for(int i=0; i<_dynamic_array_synapses_4_w.size(); i++)
                        {
                            _dynamic_array_synapses_4_w[i] = _static_array__dynamic_array_synapses_4_w[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_5_sources; i++)
                        {
                            _array_synapses_5_sources[i] = _static_array__array_synapses_5_sources[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_5_targets; i++)
                        {
                            _array_synapses_5_targets[i] = _static_array__array_synapses_5_targets[i];
                        }
                        
        _run_synapses_5_synapses_create_array_codeobject();
        
                        
                        for(int i=0; i<_dynamic_array_synapses_5_w.size(); i++)
                        {
                            _dynamic_array_synapses_5_w[i] = _static_array__dynamic_array_synapses_5_w[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_6_sources; i++)
                        {
                            _array_synapses_6_sources[i] = _static_array__array_synapses_6_sources[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_synapses_6_targets; i++)
                        {
                            _array_synapses_6_targets[i] = _static_array__array_synapses_6_targets[i];
                        }
                        
        _run_synapses_6_synapses_create_array_codeobject();
        
                        
                        for(int i=0; i<_dynamic_array_synapses_6_w.size(); i++)
                        {
                            _dynamic_array_synapses_6_w[i] = _static_array__dynamic_array_synapses_6_w[i];
                        }
                        
        _array_defaultclock_dt[0] = 0.0005;
        
                        
                        for(int i=0; i<_num__array_poissongroup_rates; i++)
                        {
                            _array_poissongroup_rates[i] = _static_array__array_poissongroup_rates[i];
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_v; i++)
                        {
                            _array_neurongroup_v[i] = 0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_1_v; i++)
                        {
                            _array_neurongroup_1_v[i] = 0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_2_v; i++)
                        {
                            _array_neurongroup_2_v[i] = 0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_3_v; i++)
                        {
                            _array_neurongroup_3_v[i] = 0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_4_v; i++)
                        {
                            _array_neurongroup_4_v[i] = 0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_5_v; i++)
                        {
                            _array_neurongroup_5_v[i] = 0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_6_v; i++)
                        {
                            _array_neurongroup_6_v[i] = 0;
                        }
                        
        _array_defaultclock_timestep[0] = 0L;
        _array_defaultclock_t[0] = 0.0;
        _run_synapses_1_pre_initialise_queue();
        _run_synapses_2_pre_initialise_queue();
        _run_synapses_3_pre_initialise_queue();
        _run_synapses_4_pre_initialise_queue();
        _run_synapses_5_pre_initialise_queue();
        _run_synapses_6_pre_initialise_queue();
        _run_synapses_pre_initialise_queue();
        magicnetwork.clear();
        magicnetwork.add(&defaultclock, _run_neurongroup_1_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_2_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_3_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_4_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_5_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_6_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_poissongroup_thresholder_codeobject);
        magicnetwork.add(&defaultclock, _run_spikemonitor_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_1_thresholder_1_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_2_thresholder_1_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_3_thresholder_1_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_thresholder_1_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_1_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_1_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_2_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_2_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_3_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_3_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_4_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_4_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_5_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_5_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_6_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_6_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_synapses_pre_push_spikes);
        magicnetwork.add(&defaultclock, _run_synapses_pre_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_1_resetter_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_2_resetter_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_3_resetter_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_4_resetter_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_5_resetter_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_6_resetter_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_resetter_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_1_resetter_1_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_2_resetter_1_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_3_resetter_1_codeobject);
        magicnetwork.add(&defaultclock, _run_neurongroup_resetter_1_codeobject);
        magicnetwork.run(0.05, NULL, 10.0);
        _debugmsg_synapses_4_pre_codeobject();
        
        _debugmsg_synapses_pre_codeobject();
        
        _debugmsg_synapses_2_pre_codeobject();
        
        _debugmsg_synapses_3_pre_codeobject();
        
        _debugmsg_synapses_1_pre_codeobject();
        
        _debugmsg_synapses_6_pre_codeobject();
        
        _debugmsg_spikemonitor_codeobject();
        
        _debugmsg_synapses_5_pre_codeobject();

	}

	brian_end();

	return 0;
}