
#include "objects.h"
#include "synapses_classes.h"
#include "brianlib/clocks.h"
#include "brianlib/dynamic_array.h"
#include "brianlib/stdint_compat.h"
#include "network.h"
#include "randomkit.h"
#include<vector>
#include<iostream>
#include<fstream>

namespace brian {

std::vector< rk_state* > _mersenne_twister_states;

//////////////// networks /////////////////
Network magicnetwork;

//////////////// arrays ///////////////////
double * _array_defaultclock_dt;
const int _num__array_defaultclock_dt = 1;
double * _array_defaultclock_t;
const int _num__array_defaultclock_t = 1;
uint64_t * _array_defaultclock_timestep;
const int _num__array_defaultclock_timestep = 1;
int32_t * _array_neurongroup_1__spikespace;
const int _num__array_neurongroup_1__spikespace = 2881;
int32_t * _array_neurongroup_1__underspace;
const int _num__array_neurongroup_1__underspace = 2881;
int32_t * _array_neurongroup_1_i;
const int _num__array_neurongroup_1_i = 2880;
double * _array_neurongroup_1_v;
const int _num__array_neurongroup_1_v = 2880;
int32_t * _array_neurongroup_2__spikespace;
const int _num__array_neurongroup_2__spikespace = 3201;
int32_t * _array_neurongroup_2__underspace;
const int _num__array_neurongroup_2__underspace = 3201;
int32_t * _array_neurongroup_2_i;
const int _num__array_neurongroup_2_i = 3200;
double * _array_neurongroup_2_v;
const int _num__array_neurongroup_2_v = 3200;
int32_t * _array_neurongroup_3__spikespace;
const int _num__array_neurongroup_3__spikespace = 801;
int32_t * _array_neurongroup_3__underspace;
const int _num__array_neurongroup_3__underspace = 801;
int32_t * _array_neurongroup_3_i;
const int _num__array_neurongroup_3_i = 800;
double * _array_neurongroup_3_v;
const int _num__array_neurongroup_3_v = 800;
int32_t * _array_neurongroup_4__spikespace;
const int _num__array_neurongroup_4__spikespace = 501;
int32_t * _array_neurongroup_4_i;
const int _num__array_neurongroup_4_i = 500;
double * _array_neurongroup_4_v;
const int _num__array_neurongroup_4_v = 500;
int32_t * _array_neurongroup_5__spikespace;
const int _num__array_neurongroup_5__spikespace = 11;
int32_t * _array_neurongroup_5_i;
const int _num__array_neurongroup_5_i = 10;
double * _array_neurongroup_5_v;
const int _num__array_neurongroup_5_v = 10;
int32_t * _array_neurongroup_6__spikespace;
const int _num__array_neurongroup_6__spikespace = 11;
int32_t * _array_neurongroup_6_i;
const int _num__array_neurongroup_6_i = 10;
double * _array_neurongroup_6_v;
const int _num__array_neurongroup_6_v = 10;
int32_t * _array_neurongroup__spikespace;
const int _num__array_neurongroup__spikespace = 11521;
int32_t * _array_neurongroup__underspace;
const int _num__array_neurongroup__underspace = 11521;
int32_t * _array_neurongroup_i;
const int _num__array_neurongroup_i = 11520;
double * _array_neurongroup_v;
const int _num__array_neurongroup_v = 11520;
int32_t * _array_poissongroup__spikespace;
const int _num__array_poissongroup__spikespace = 785;
int32_t * _array_poissongroup_i;
const int _num__array_poissongroup_i = 784;
double * _array_poissongroup_rates;
const int _num__array_poissongroup_rates = 784;
int32_t * _array_spikemonitor__source_idx;
const int _num__array_spikemonitor__source_idx = 10;
int32_t * _array_spikemonitor_count;
const int _num__array_spikemonitor_count = 10;
int32_t * _array_spikemonitor_N;
const int _num__array_spikemonitor_N = 1;
int32_t * _array_synapses_1_N;
const int _num__array_synapses_1_N = 1;
int32_t * _array_synapses_1_sources;
const int _num__array_synapses_1_sources = 11520;
int32_t * _array_synapses_1_targets;
const int _num__array_synapses_1_targets = 11520;
int32_t * _array_synapses_2_N;
const int _num__array_synapses_2_N = 1;
int32_t * _array_synapses_2_sources;
const int _num__array_synapses_2_sources = 1600000;
int32_t * _array_synapses_2_targets;
const int _num__array_synapses_2_targets = 1600000;
int32_t * _array_synapses_3_N;
const int _num__array_synapses_3_N = 1;
int32_t * _array_synapses_3_sources;
const int _num__array_synapses_3_sources = 3200;
int32_t * _array_synapses_3_targets;
const int _num__array_synapses_3_targets = 3200;
int32_t * _array_synapses_4_N;
const int _num__array_synapses_4_N = 1;
int32_t * _array_synapses_4_sources;
const int _num__array_synapses_4_sources = 400000;
int32_t * _array_synapses_4_targets;
const int _num__array_synapses_4_targets = 400000;
int32_t * _array_synapses_5_N;
const int _num__array_synapses_5_N = 1;
int32_t * _array_synapses_5_sources;
const int _num__array_synapses_5_sources = 5000;
int32_t * _array_synapses_5_targets;
const int _num__array_synapses_5_targets = 5000;
int32_t * _array_synapses_6_N;
const int _num__array_synapses_6_N = 1;
int32_t * _array_synapses_6_sources;
const int _num__array_synapses_6_sources = 100;
int32_t * _array_synapses_6_targets;
const int _num__array_synapses_6_targets = 100;
int32_t * _array_synapses_N;
const int _num__array_synapses_N = 1;
int32_t * _array_synapses_sources;
const int _num__array_synapses_sources = 288000;
int32_t * _array_synapses_targets;
const int _num__array_synapses_targets = 288000;

//////////////// dynamic arrays 1d /////////
std::vector<int32_t> _dynamic_array_spikemonitor_i;
std::vector<double> _dynamic_array_spikemonitor_t;
std::vector<int32_t> _dynamic_array_synapses_1__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_1__synaptic_pre;
std::vector<double> _dynamic_array_synapses_1_delay;
std::vector<double> _dynamic_array_synapses_1_lastupdate;
std::vector<int32_t> _dynamic_array_synapses_1_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_1_N_outgoing;
std::vector<double> _dynamic_array_synapses_1_w;
std::vector<int32_t> _dynamic_array_synapses_2__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_2__synaptic_pre;
std::vector<double> _dynamic_array_synapses_2_delay;
std::vector<double> _dynamic_array_synapses_2_lastupdate;
std::vector<int32_t> _dynamic_array_synapses_2_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_2_N_outgoing;
std::vector<double> _dynamic_array_synapses_2_w;
std::vector<int32_t> _dynamic_array_synapses_3__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_3__synaptic_pre;
std::vector<double> _dynamic_array_synapses_3_delay;
std::vector<double> _dynamic_array_synapses_3_lastupdate;
std::vector<int32_t> _dynamic_array_synapses_3_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_3_N_outgoing;
std::vector<double> _dynamic_array_synapses_3_w;
std::vector<int32_t> _dynamic_array_synapses_4__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_4__synaptic_pre;
std::vector<double> _dynamic_array_synapses_4_delay;
std::vector<double> _dynamic_array_synapses_4_lastupdate;
std::vector<int32_t> _dynamic_array_synapses_4_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_4_N_outgoing;
std::vector<double> _dynamic_array_synapses_4_w;
std::vector<int32_t> _dynamic_array_synapses_5__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_5__synaptic_pre;
std::vector<double> _dynamic_array_synapses_5_delay;
std::vector<double> _dynamic_array_synapses_5_lastupdate;
std::vector<int32_t> _dynamic_array_synapses_5_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_5_N_outgoing;
std::vector<double> _dynamic_array_synapses_5_w;
std::vector<int32_t> _dynamic_array_synapses_6__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_6__synaptic_pre;
std::vector<double> _dynamic_array_synapses_6_delay;
std::vector<double> _dynamic_array_synapses_6_lastupdate;
std::vector<int32_t> _dynamic_array_synapses_6_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_6_N_outgoing;
std::vector<double> _dynamic_array_synapses_6_w;
std::vector<int32_t> _dynamic_array_synapses__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses__synaptic_pre;
std::vector<double> _dynamic_array_synapses_delay;
std::vector<double> _dynamic_array_synapses_lastupdate;
std::vector<int32_t> _dynamic_array_synapses_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_N_outgoing;
std::vector<double> _dynamic_array_synapses_w;

//////////////// dynamic arrays 2d /////////

/////////////// static arrays /////////////
double * _static_array__array_poissongroup_rates;
const int _num__static_array__array_poissongroup_rates = 784;
int32_t * _static_array__array_synapses_1_sources;
const int _num__static_array__array_synapses_1_sources = 11520;
int32_t * _static_array__array_synapses_1_targets;
const int _num__static_array__array_synapses_1_targets = 11520;
int32_t * _static_array__array_synapses_2_sources;
const int _num__static_array__array_synapses_2_sources = 1600000;
int32_t * _static_array__array_synapses_2_targets;
const int _num__static_array__array_synapses_2_targets = 1600000;
int32_t * _static_array__array_synapses_3_sources;
const int _num__static_array__array_synapses_3_sources = 3200;
int32_t * _static_array__array_synapses_3_targets;
const int _num__static_array__array_synapses_3_targets = 3200;
int32_t * _static_array__array_synapses_4_sources;
const int _num__static_array__array_synapses_4_sources = 400000;
int32_t * _static_array__array_synapses_4_targets;
const int _num__static_array__array_synapses_4_targets = 400000;
int32_t * _static_array__array_synapses_5_sources;
const int _num__static_array__array_synapses_5_sources = 5000;
int32_t * _static_array__array_synapses_5_targets;
const int _num__static_array__array_synapses_5_targets = 5000;
int32_t * _static_array__array_synapses_6_sources;
const int _num__static_array__array_synapses_6_sources = 100;
int32_t * _static_array__array_synapses_6_targets;
const int _num__static_array__array_synapses_6_targets = 100;
int32_t * _static_array__array_synapses_sources;
const int _num__static_array__array_synapses_sources = 288000;
int32_t * _static_array__array_synapses_targets;
const int _num__static_array__array_synapses_targets = 288000;
double * _static_array__dynamic_array_synapses_1_w;
const int _num__static_array__dynamic_array_synapses_1_w = 11520;
float * _static_array__dynamic_array_synapses_2_w;
const int _num__static_array__dynamic_array_synapses_2_w = 1600000;
double * _static_array__dynamic_array_synapses_3_w;
const int _num__static_array__dynamic_array_synapses_3_w = 3200;
float * _static_array__dynamic_array_synapses_4_w;
const int _num__static_array__dynamic_array_synapses_4_w = 400000;
float * _static_array__dynamic_array_synapses_5_w;
const int _num__static_array__dynamic_array_synapses_5_w = 5000;
float * _static_array__dynamic_array_synapses_6_w;
const int _num__static_array__dynamic_array_synapses_6_w = 100;
float * _static_array__dynamic_array_synapses_w;
const int _num__static_array__dynamic_array_synapses_w = 288000;

//////////////// synapses /////////////////
// synapses
SynapticPathway<double> synapses_pre(
		_dynamic_array_synapses_delay,
		_dynamic_array_synapses__synaptic_pre,
		0, 784);
// synapses_1
SynapticPathway<double> synapses_1_pre(
		_dynamic_array_synapses_1_delay,
		_dynamic_array_synapses_1__synaptic_pre,
		0, 11520);
// synapses_2
SynapticPathway<double> synapses_2_pre(
		_dynamic_array_synapses_2_delay,
		_dynamic_array_synapses_2__synaptic_pre,
		0, 2880);
// synapses_3
SynapticPathway<double> synapses_3_pre(
		_dynamic_array_synapses_3_delay,
		_dynamic_array_synapses_3__synaptic_pre,
		0, 3200);
// synapses_4
SynapticPathway<double> synapses_4_pre(
		_dynamic_array_synapses_4_delay,
		_dynamic_array_synapses_4__synaptic_pre,
		0, 800);
// synapses_5
SynapticPathway<double> synapses_5_pre(
		_dynamic_array_synapses_5_delay,
		_dynamic_array_synapses_5__synaptic_pre,
		0, 500);
// synapses_6
SynapticPathway<double> synapses_6_pre(
		_dynamic_array_synapses_6_delay,
		_dynamic_array_synapses_6__synaptic_pre,
		0, 10);

//////////////// clocks ///////////////////
Clock defaultclock;  // attributes will be set in run.cpp

// Profiling information for each code object
double neurongroup_1_resetter_1_codeobject_profiling_info = 0.0;
double neurongroup_1_resetter_codeobject_profiling_info = 0.0;
double neurongroup_1_thresholder_1_codeobject_profiling_info = 0.0;
double neurongroup_1_thresholder_codeobject_profiling_info = 0.0;
double neurongroup_2_resetter_1_codeobject_profiling_info = 0.0;
double neurongroup_2_resetter_codeobject_profiling_info = 0.0;
double neurongroup_2_thresholder_1_codeobject_profiling_info = 0.0;
double neurongroup_2_thresholder_codeobject_profiling_info = 0.0;
double neurongroup_3_resetter_1_codeobject_profiling_info = 0.0;
double neurongroup_3_resetter_codeobject_profiling_info = 0.0;
double neurongroup_3_thresholder_1_codeobject_profiling_info = 0.0;
double neurongroup_3_thresholder_codeobject_profiling_info = 0.0;
double neurongroup_4_resetter_codeobject_profiling_info = 0.0;
double neurongroup_4_thresholder_codeobject_profiling_info = 0.0;
double neurongroup_5_resetter_codeobject_profiling_info = 0.0;
double neurongroup_5_thresholder_codeobject_profiling_info = 0.0;
double neurongroup_6_resetter_codeobject_profiling_info = 0.0;
double neurongroup_6_thresholder_codeobject_profiling_info = 0.0;
double neurongroup_resetter_1_codeobject_profiling_info = 0.0;
double neurongroup_resetter_codeobject_profiling_info = 0.0;
double neurongroup_thresholder_1_codeobject_profiling_info = 0.0;
double neurongroup_thresholder_codeobject_profiling_info = 0.0;
double poissongroup_thresholder_codeobject_profiling_info = 0.0;
double spikemonitor_codeobject_profiling_info = 0.0;
double synapses_1_pre_codeobject_profiling_info = 0.0;
double synapses_1_pre_initialise_queue_profiling_info = 0.0;
double synapses_1_pre_push_spikes_profiling_info = 0.0;
double synapses_1_synapses_create_array_codeobject_profiling_info = 0.0;
double synapses_2_pre_codeobject_profiling_info = 0.0;
double synapses_2_pre_initialise_queue_profiling_info = 0.0;
double synapses_2_pre_push_spikes_profiling_info = 0.0;
double synapses_2_synapses_create_array_codeobject_profiling_info = 0.0;
double synapses_3_pre_codeobject_profiling_info = 0.0;
double synapses_3_pre_initialise_queue_profiling_info = 0.0;
double synapses_3_pre_push_spikes_profiling_info = 0.0;
double synapses_3_synapses_create_array_codeobject_profiling_info = 0.0;
double synapses_4_pre_codeobject_profiling_info = 0.0;
double synapses_4_pre_initialise_queue_profiling_info = 0.0;
double synapses_4_pre_push_spikes_profiling_info = 0.0;
double synapses_4_synapses_create_array_codeobject_profiling_info = 0.0;
double synapses_5_pre_codeobject_profiling_info = 0.0;
double synapses_5_pre_initialise_queue_profiling_info = 0.0;
double synapses_5_pre_push_spikes_profiling_info = 0.0;
double synapses_5_synapses_create_array_codeobject_profiling_info = 0.0;
double synapses_6_pre_codeobject_profiling_info = 0.0;
double synapses_6_pre_initialise_queue_profiling_info = 0.0;
double synapses_6_pre_push_spikes_profiling_info = 0.0;
double synapses_6_synapses_create_array_codeobject_profiling_info = 0.0;
double synapses_pre_codeobject_profiling_info = 0.0;
double synapses_pre_initialise_queue_profiling_info = 0.0;
double synapses_pre_push_spikes_profiling_info = 0.0;
double synapses_synapses_create_array_codeobject_profiling_info = 0.0;

}

void _init_arrays()
{
	using namespace brian;

    // Arrays initialized to 0
	_array_spikemonitor__source_idx = new int32_t[10];
	
	for(int i=0; i<10; i++) _array_spikemonitor__source_idx[i] = 0;
	_array_poissongroup__spikespace = new int32_t[785];
	
	for(int i=0; i<785; i++) _array_poissongroup__spikespace[i] = 0;
	_array_neurongroup__spikespace = new int32_t[11521];
	
	for(int i=0; i<11521; i++) _array_neurongroup__spikespace[i] = 0;
	_array_neurongroup_1__spikespace = new int32_t[2881];
	
	for(int i=0; i<2881; i++) _array_neurongroup_1__spikespace[i] = 0;
	_array_neurongroup_2__spikespace = new int32_t[3201];
	
	for(int i=0; i<3201; i++) _array_neurongroup_2__spikespace[i] = 0;
	_array_neurongroup_3__spikespace = new int32_t[801];
	
	for(int i=0; i<801; i++) _array_neurongroup_3__spikespace[i] = 0;
	_array_neurongroup_4__spikespace = new int32_t[501];
	
	for(int i=0; i<501; i++) _array_neurongroup_4__spikespace[i] = 0;
	_array_neurongroup_5__spikespace = new int32_t[11];
	
	for(int i=0; i<11; i++) _array_neurongroup_5__spikespace[i] = 0;
	_array_neurongroup_6__spikespace = new int32_t[11];
	
	for(int i=0; i<11; i++) _array_neurongroup_6__spikespace[i] = 0;
	_array_neurongroup__underspace = new int32_t[11521];
	
	for(int i=0; i<11521; i++) _array_neurongroup__underspace[i] = 0;
	_array_neurongroup_1__underspace = new int32_t[2881];
	
	for(int i=0; i<2881; i++) _array_neurongroup_1__underspace[i] = 0;
	_array_neurongroup_2__underspace = new int32_t[3201];
	
	for(int i=0; i<3201; i++) _array_neurongroup_2__underspace[i] = 0;
	_array_neurongroup_3__underspace = new int32_t[801];
	
	for(int i=0; i<801; i++) _array_neurongroup_3__underspace[i] = 0;
	_array_spikemonitor_count = new int32_t[10];
	
	for(int i=0; i<10; i++) _array_spikemonitor_count[i] = 0;
	_array_defaultclock_dt = new double[1];
	
	for(int i=0; i<1; i++) _array_defaultclock_dt[i] = 0;
	_array_poissongroup_i = new int32_t[784];
	
	for(int i=0; i<784; i++) _array_poissongroup_i[i] = 0;
	_array_neurongroup_i = new int32_t[11520];
	
	for(int i=0; i<11520; i++) _array_neurongroup_i[i] = 0;
	_array_neurongroup_1_i = new int32_t[2880];
	
	for(int i=0; i<2880; i++) _array_neurongroup_1_i[i] = 0;
	_array_neurongroup_2_i = new int32_t[3200];
	
	for(int i=0; i<3200; i++) _array_neurongroup_2_i[i] = 0;
	_array_neurongroup_3_i = new int32_t[800];
	
	for(int i=0; i<800; i++) _array_neurongroup_3_i[i] = 0;
	_array_neurongroup_4_i = new int32_t[500];
	
	for(int i=0; i<500; i++) _array_neurongroup_4_i[i] = 0;
	_array_neurongroup_5_i = new int32_t[10];
	
	for(int i=0; i<10; i++) _array_neurongroup_5_i[i] = 0;
	_array_neurongroup_6_i = new int32_t[10];
	
	for(int i=0; i<10; i++) _array_neurongroup_6_i[i] = 0;
	_array_synapses_N = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_synapses_N[i] = 0;
	_array_synapses_1_N = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_synapses_1_N[i] = 0;
	_array_synapses_2_N = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_synapses_2_N[i] = 0;
	_array_synapses_3_N = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_synapses_3_N[i] = 0;
	_array_synapses_4_N = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_synapses_4_N[i] = 0;
	_array_synapses_5_N = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_synapses_5_N[i] = 0;
	_array_synapses_6_N = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_synapses_6_N[i] = 0;
	_array_spikemonitor_N = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_spikemonitor_N[i] = 0;
	_array_poissongroup_rates = new double[784];
	
	for(int i=0; i<784; i++) _array_poissongroup_rates[i] = 0;
	_array_synapses_sources = new int32_t[288000];
	
	for(int i=0; i<288000; i++) _array_synapses_sources[i] = 0;
	_array_synapses_1_sources = new int32_t[11520];
	
	for(int i=0; i<11520; i++) _array_synapses_1_sources[i] = 0;
	_array_synapses_2_sources = new int32_t[1600000];
	
	for(int i=0; i<1600000; i++) _array_synapses_2_sources[i] = 0;
	_array_synapses_3_sources = new int32_t[3200];
	
	for(int i=0; i<3200; i++) _array_synapses_3_sources[i] = 0;
	_array_synapses_4_sources = new int32_t[400000];
	
	for(int i=0; i<400000; i++) _array_synapses_4_sources[i] = 0;
	_array_synapses_5_sources = new int32_t[5000];
	
	for(int i=0; i<5000; i++) _array_synapses_5_sources[i] = 0;
	_array_synapses_6_sources = new int32_t[100];
	
	for(int i=0; i<100; i++) _array_synapses_6_sources[i] = 0;
	_array_defaultclock_t = new double[1];
	
	for(int i=0; i<1; i++) _array_defaultclock_t[i] = 0;
	_array_synapses_targets = new int32_t[288000];
	
	for(int i=0; i<288000; i++) _array_synapses_targets[i] = 0;
	_array_synapses_1_targets = new int32_t[11520];
	
	for(int i=0; i<11520; i++) _array_synapses_1_targets[i] = 0;
	_array_synapses_2_targets = new int32_t[1600000];
	
	for(int i=0; i<1600000; i++) _array_synapses_2_targets[i] = 0;
	_array_synapses_3_targets = new int32_t[3200];
	
	for(int i=0; i<3200; i++) _array_synapses_3_targets[i] = 0;
	_array_synapses_4_targets = new int32_t[400000];
	
	for(int i=0; i<400000; i++) _array_synapses_4_targets[i] = 0;
	_array_synapses_5_targets = new int32_t[5000];
	
	for(int i=0; i<5000; i++) _array_synapses_5_targets[i] = 0;
	_array_synapses_6_targets = new int32_t[100];
	
	for(int i=0; i<100; i++) _array_synapses_6_targets[i] = 0;
	_array_defaultclock_timestep = new uint64_t[1];
	
	for(int i=0; i<1; i++) _array_defaultclock_timestep[i] = 0;
	_array_neurongroup_v = new double[11520];
	
	for(int i=0; i<11520; i++) _array_neurongroup_v[i] = 0;
	_array_neurongroup_1_v = new double[2880];
	
	for(int i=0; i<2880; i++) _array_neurongroup_1_v[i] = 0;
	_array_neurongroup_2_v = new double[3200];
	
	for(int i=0; i<3200; i++) _array_neurongroup_2_v[i] = 0;
	_array_neurongroup_3_v = new double[800];
	
	for(int i=0; i<800; i++) _array_neurongroup_3_v[i] = 0;
	_array_neurongroup_4_v = new double[500];
	
	for(int i=0; i<500; i++) _array_neurongroup_4_v[i] = 0;
	_array_neurongroup_5_v = new double[10];
	
	for(int i=0; i<10; i++) _array_neurongroup_5_v[i] = 0;
	_array_neurongroup_6_v = new double[10];
	
	for(int i=0; i<10; i++) _array_neurongroup_6_v[i] = 0;

	// Arrays initialized to an "arange"
	_array_spikemonitor__source_idx = new int32_t[10];
	
	for(int i=0; i<10; i++) _array_spikemonitor__source_idx[i] = 0 + i;
	_array_neurongroup_4_i = new int32_t[500];
	
	for(int i=0; i<500; i++) _array_neurongroup_4_i[i] = 0 + i;
	_array_neurongroup_5_i = new int32_t[10];
	
	for(int i=0; i<10; i++) _array_neurongroup_5_i[i] = 0 + i;
	_array_neurongroup_3_i = new int32_t[800];
	
	for(int i=0; i<800; i++) _array_neurongroup_3_i[i] = 0 + i;
	_array_neurongroup_2_i = new int32_t[3200];
	
	for(int i=0; i<3200; i++) _array_neurongroup_2_i[i] = 0 + i;
	_array_neurongroup_1_i = new int32_t[2880];
	
	for(int i=0; i<2880; i++) _array_neurongroup_1_i[i] = 0 + i;
	_array_neurongroup_i = new int32_t[11520];
	
	for(int i=0; i<11520; i++) _array_neurongroup_i[i] = 0 + i;
	_array_neurongroup_6_i = new int32_t[10];
	
	for(int i=0; i<10; i++) _array_neurongroup_6_i[i] = 0 + i;
	_array_poissongroup_i = new int32_t[784];
	
	for(int i=0; i<784; i++) _array_poissongroup_i[i] = 0 + i;

	// static arrays
	_static_array__array_poissongroup_rates = new double[784];
	_static_array__array_synapses_1_sources = new int32_t[11520];
	_static_array__array_synapses_1_targets = new int32_t[11520];
	_static_array__array_synapses_2_sources = new int32_t[1600000];
	_static_array__array_synapses_2_targets = new int32_t[1600000];
	_static_array__array_synapses_3_sources = new int32_t[3200];
	_static_array__array_synapses_3_targets = new int32_t[3200];
	_static_array__array_synapses_4_sources = new int32_t[400000];
	_static_array__array_synapses_4_targets = new int32_t[400000];
	_static_array__array_synapses_5_sources = new int32_t[5000];
	_static_array__array_synapses_5_targets = new int32_t[5000];
	_static_array__array_synapses_6_sources = new int32_t[100];
	_static_array__array_synapses_6_targets = new int32_t[100];
	_static_array__array_synapses_sources = new int32_t[288000];
	_static_array__array_synapses_targets = new int32_t[288000];
	_static_array__dynamic_array_synapses_1_w = new double[11520];
	_static_array__dynamic_array_synapses_2_w = new float[1600000];
	_static_array__dynamic_array_synapses_3_w = new double[3200];
	_static_array__dynamic_array_synapses_4_w = new float[400000];
	_static_array__dynamic_array_synapses_5_w = new float[5000];
	_static_array__dynamic_array_synapses_6_w = new float[100];
	_static_array__dynamic_array_synapses_w = new float[288000];

	// Random number generator states
	for (int i=0; i<1; i++)
	    _mersenne_twister_states.push_back(new rk_state());
}

void _load_arrays()
{
	using namespace brian;

	ifstream f_static_array__array_poissongroup_rates;
	f_static_array__array_poissongroup_rates.open("static_arrays/_static_array__array_poissongroup_rates", ios::in | ios::binary);
	if(f_static_array__array_poissongroup_rates.is_open())
	{
		f_static_array__array_poissongroup_rates.read(reinterpret_cast<char*>(_static_array__array_poissongroup_rates), 784*sizeof(double));
	} else
	{
		std::cout << "Error opening static array _static_array__array_poissongroup_rates." << endl;
	}
	ifstream f_static_array__array_synapses_1_sources;
	f_static_array__array_synapses_1_sources.open("static_arrays/_static_array__array_synapses_1_sources", ios::in | ios::binary);
	if(f_static_array__array_synapses_1_sources.is_open())
	{
		f_static_array__array_synapses_1_sources.read(reinterpret_cast<char*>(_static_array__array_synapses_1_sources), 11520*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_1_sources." << endl;
	}
	ifstream f_static_array__array_synapses_1_targets;
	f_static_array__array_synapses_1_targets.open("static_arrays/_static_array__array_synapses_1_targets", ios::in | ios::binary);
	if(f_static_array__array_synapses_1_targets.is_open())
	{
		f_static_array__array_synapses_1_targets.read(reinterpret_cast<char*>(_static_array__array_synapses_1_targets), 11520*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_1_targets." << endl;
	}
	ifstream f_static_array__array_synapses_2_sources;
	f_static_array__array_synapses_2_sources.open("static_arrays/_static_array__array_synapses_2_sources", ios::in | ios::binary);
	if(f_static_array__array_synapses_2_sources.is_open())
	{
		f_static_array__array_synapses_2_sources.read(reinterpret_cast<char*>(_static_array__array_synapses_2_sources), 1600000*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_2_sources." << endl;
	}
	ifstream f_static_array__array_synapses_2_targets;
	f_static_array__array_synapses_2_targets.open("static_arrays/_static_array__array_synapses_2_targets", ios::in | ios::binary);
	if(f_static_array__array_synapses_2_targets.is_open())
	{
		f_static_array__array_synapses_2_targets.read(reinterpret_cast<char*>(_static_array__array_synapses_2_targets), 1600000*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_2_targets." << endl;
	}
	ifstream f_static_array__array_synapses_3_sources;
	f_static_array__array_synapses_3_sources.open("static_arrays/_static_array__array_synapses_3_sources", ios::in | ios::binary);
	if(f_static_array__array_synapses_3_sources.is_open())
	{
		f_static_array__array_synapses_3_sources.read(reinterpret_cast<char*>(_static_array__array_synapses_3_sources), 3200*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_3_sources." << endl;
	}
	ifstream f_static_array__array_synapses_3_targets;
	f_static_array__array_synapses_3_targets.open("static_arrays/_static_array__array_synapses_3_targets", ios::in | ios::binary);
	if(f_static_array__array_synapses_3_targets.is_open())
	{
		f_static_array__array_synapses_3_targets.read(reinterpret_cast<char*>(_static_array__array_synapses_3_targets), 3200*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_3_targets." << endl;
	}
	ifstream f_static_array__array_synapses_4_sources;
	f_static_array__array_synapses_4_sources.open("static_arrays/_static_array__array_synapses_4_sources", ios::in | ios::binary);
	if(f_static_array__array_synapses_4_sources.is_open())
	{
		f_static_array__array_synapses_4_sources.read(reinterpret_cast<char*>(_static_array__array_synapses_4_sources), 400000*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_4_sources." << endl;
	}
	ifstream f_static_array__array_synapses_4_targets;
	f_static_array__array_synapses_4_targets.open("static_arrays/_static_array__array_synapses_4_targets", ios::in | ios::binary);
	if(f_static_array__array_synapses_4_targets.is_open())
	{
		f_static_array__array_synapses_4_targets.read(reinterpret_cast<char*>(_static_array__array_synapses_4_targets), 400000*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_4_targets." << endl;
	}
	ifstream f_static_array__array_synapses_5_sources;
	f_static_array__array_synapses_5_sources.open("static_arrays/_static_array__array_synapses_5_sources", ios::in | ios::binary);
	if(f_static_array__array_synapses_5_sources.is_open())
	{
		f_static_array__array_synapses_5_sources.read(reinterpret_cast<char*>(_static_array__array_synapses_5_sources), 5000*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_5_sources." << endl;
	}
	ifstream f_static_array__array_synapses_5_targets;
	f_static_array__array_synapses_5_targets.open("static_arrays/_static_array__array_synapses_5_targets", ios::in | ios::binary);
	if(f_static_array__array_synapses_5_targets.is_open())
	{
		f_static_array__array_synapses_5_targets.read(reinterpret_cast<char*>(_static_array__array_synapses_5_targets), 5000*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_5_targets." << endl;
	}
	ifstream f_static_array__array_synapses_6_sources;
	f_static_array__array_synapses_6_sources.open("static_arrays/_static_array__array_synapses_6_sources", ios::in | ios::binary);
	if(f_static_array__array_synapses_6_sources.is_open())
	{
		f_static_array__array_synapses_6_sources.read(reinterpret_cast<char*>(_static_array__array_synapses_6_sources), 100*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_6_sources." << endl;
	}
	ifstream f_static_array__array_synapses_6_targets;
	f_static_array__array_synapses_6_targets.open("static_arrays/_static_array__array_synapses_6_targets", ios::in | ios::binary);
	if(f_static_array__array_synapses_6_targets.is_open())
	{
		f_static_array__array_synapses_6_targets.read(reinterpret_cast<char*>(_static_array__array_synapses_6_targets), 100*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_6_targets." << endl;
	}
	ifstream f_static_array__array_synapses_sources;
	f_static_array__array_synapses_sources.open("static_arrays/_static_array__array_synapses_sources", ios::in | ios::binary);
	if(f_static_array__array_synapses_sources.is_open())
	{
		f_static_array__array_synapses_sources.read(reinterpret_cast<char*>(_static_array__array_synapses_sources), 288000*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_sources." << endl;
	}
	ifstream f_static_array__array_synapses_targets;
	f_static_array__array_synapses_targets.open("static_arrays/_static_array__array_synapses_targets", ios::in | ios::binary);
	if(f_static_array__array_synapses_targets.is_open())
	{
		f_static_array__array_synapses_targets.read(reinterpret_cast<char*>(_static_array__array_synapses_targets), 288000*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_synapses_targets." << endl;
	}
	ifstream f_static_array__dynamic_array_synapses_1_w;
	f_static_array__dynamic_array_synapses_1_w.open("static_arrays/_static_array__dynamic_array_synapses_1_w", ios::in | ios::binary);
	if(f_static_array__dynamic_array_synapses_1_w.is_open())
	{
		f_static_array__dynamic_array_synapses_1_w.read(reinterpret_cast<char*>(_static_array__dynamic_array_synapses_1_w), 11520*sizeof(double));
	} else
	{
		std::cout << "Error opening static array _static_array__dynamic_array_synapses_1_w." << endl;
	}
	ifstream f_static_array__dynamic_array_synapses_2_w;
	f_static_array__dynamic_array_synapses_2_w.open("static_arrays/_static_array__dynamic_array_synapses_2_w", ios::in | ios::binary);
	if(f_static_array__dynamic_array_synapses_2_w.is_open())
	{
		f_static_array__dynamic_array_synapses_2_w.read(reinterpret_cast<char*>(_static_array__dynamic_array_synapses_2_w), 1600000*sizeof(float));
	} else
	{
		std::cout << "Error opening static array _static_array__dynamic_array_synapses_2_w." << endl;
	}
	ifstream f_static_array__dynamic_array_synapses_3_w;
	f_static_array__dynamic_array_synapses_3_w.open("static_arrays/_static_array__dynamic_array_synapses_3_w", ios::in | ios::binary);
	if(f_static_array__dynamic_array_synapses_3_w.is_open())
	{
		f_static_array__dynamic_array_synapses_3_w.read(reinterpret_cast<char*>(_static_array__dynamic_array_synapses_3_w), 3200*sizeof(double));
	} else
	{
		std::cout << "Error opening static array _static_array__dynamic_array_synapses_3_w." << endl;
	}
	ifstream f_static_array__dynamic_array_synapses_4_w;
	f_static_array__dynamic_array_synapses_4_w.open("static_arrays/_static_array__dynamic_array_synapses_4_w", ios::in | ios::binary);
	if(f_static_array__dynamic_array_synapses_4_w.is_open())
	{
		f_static_array__dynamic_array_synapses_4_w.read(reinterpret_cast<char*>(_static_array__dynamic_array_synapses_4_w), 400000*sizeof(float));
	} else
	{
		std::cout << "Error opening static array _static_array__dynamic_array_synapses_4_w." << endl;
	}
	ifstream f_static_array__dynamic_array_synapses_5_w;
	f_static_array__dynamic_array_synapses_5_w.open("static_arrays/_static_array__dynamic_array_synapses_5_w", ios::in | ios::binary);
	if(f_static_array__dynamic_array_synapses_5_w.is_open())
	{
		f_static_array__dynamic_array_synapses_5_w.read(reinterpret_cast<char*>(_static_array__dynamic_array_synapses_5_w), 5000*sizeof(float));
	} else
	{
		std::cout << "Error opening static array _static_array__dynamic_array_synapses_5_w." << endl;
	}
	ifstream f_static_array__dynamic_array_synapses_6_w;
	f_static_array__dynamic_array_synapses_6_w.open("static_arrays/_static_array__dynamic_array_synapses_6_w", ios::in | ios::binary);
	if(f_static_array__dynamic_array_synapses_6_w.is_open())
	{
		f_static_array__dynamic_array_synapses_6_w.read(reinterpret_cast<char*>(_static_array__dynamic_array_synapses_6_w), 100*sizeof(float));
	} else
	{
		std::cout << "Error opening static array _static_array__dynamic_array_synapses_6_w." << endl;
	}
	ifstream f_static_array__dynamic_array_synapses_w;
	f_static_array__dynamic_array_synapses_w.open("static_arrays/_static_array__dynamic_array_synapses_w", ios::in | ios::binary);
	if(f_static_array__dynamic_array_synapses_w.is_open())
	{
		f_static_array__dynamic_array_synapses_w.read(reinterpret_cast<char*>(_static_array__dynamic_array_synapses_w), 288000*sizeof(float));
	} else
	{
		std::cout << "Error opening static array _static_array__dynamic_array_synapses_w." << endl;
	}
}

void _write_arrays()
{
	using namespace brian;

	ofstream outfile__array_defaultclock_dt;
	outfile__array_defaultclock_dt.open("results/_array_defaultclock_dt_-9215759865592636245", ios::binary | ios::out);
	if(outfile__array_defaultclock_dt.is_open())
	{
		outfile__array_defaultclock_dt.write(reinterpret_cast<char*>(_array_defaultclock_dt), 1*sizeof(_array_defaultclock_dt[0]));
		outfile__array_defaultclock_dt.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_dt." << endl;
	}
	ofstream outfile__array_defaultclock_t;
	outfile__array_defaultclock_t.open("results/_array_defaultclock_t_7263079326120112646", ios::binary | ios::out);
	if(outfile__array_defaultclock_t.is_open())
	{
		outfile__array_defaultclock_t.write(reinterpret_cast<char*>(_array_defaultclock_t), 1*sizeof(_array_defaultclock_t[0]));
		outfile__array_defaultclock_t.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_t." << endl;
	}
	ofstream outfile__array_defaultclock_timestep;
	outfile__array_defaultclock_timestep.open("results/_array_defaultclock_timestep_-8300011050550298960", ios::binary | ios::out);
	if(outfile__array_defaultclock_timestep.is_open())
	{
		outfile__array_defaultclock_timestep.write(reinterpret_cast<char*>(_array_defaultclock_timestep), 1*sizeof(_array_defaultclock_timestep[0]));
		outfile__array_defaultclock_timestep.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_timestep." << endl;
	}
	ofstream outfile__array_neurongroup_1__spikespace;
	outfile__array_neurongroup_1__spikespace.open("results/_array_neurongroup_1__spikespace_-4682830371427067093", ios::binary | ios::out);
	if(outfile__array_neurongroup_1__spikespace.is_open())
	{
		outfile__array_neurongroup_1__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_1__spikespace), 2881*sizeof(_array_neurongroup_1__spikespace[0]));
		outfile__array_neurongroup_1__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_1__underspace;
	outfile__array_neurongroup_1__underspace.open("results/_array_neurongroup_1__underspace_-1150388423318807669", ios::binary | ios::out);
	if(outfile__array_neurongroup_1__underspace.is_open())
	{
		outfile__array_neurongroup_1__underspace.write(reinterpret_cast<char*>(_array_neurongroup_1__underspace), 2881*sizeof(_array_neurongroup_1__underspace[0]));
		outfile__array_neurongroup_1__underspace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1__underspace." << endl;
	}
	ofstream outfile__array_neurongroup_1_i;
	outfile__array_neurongroup_1_i.open("results/_array_neurongroup_1_i_6263110221643836299", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_i.is_open())
	{
		outfile__array_neurongroup_1_i.write(reinterpret_cast<char*>(_array_neurongroup_1_i), 2880*sizeof(_array_neurongroup_1_i[0]));
		outfile__array_neurongroup_1_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_i." << endl;
	}
	ofstream outfile__array_neurongroup_1_v;
	outfile__array_neurongroup_1_v.open("results/_array_neurongroup_1_v_6263110221643836308", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_v.is_open())
	{
		outfile__array_neurongroup_1_v.write(reinterpret_cast<char*>(_array_neurongroup_1_v), 2880*sizeof(_array_neurongroup_1_v[0]));
		outfile__array_neurongroup_1_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_v." << endl;
	}
	ofstream outfile__array_neurongroup_2__spikespace;
	outfile__array_neurongroup_2__spikespace.open("results/_array_neurongroup_2__spikespace_-7436586474334848428", ios::binary | ios::out);
	if(outfile__array_neurongroup_2__spikespace.is_open())
	{
		outfile__array_neurongroup_2__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_2__spikespace), 3201*sizeof(_array_neurongroup_2__spikespace[0]));
		outfile__array_neurongroup_2__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_2__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_2__underspace;
	outfile__array_neurongroup_2__underspace.open("results/_array_neurongroup_2__underspace_254401948285269852", ios::binary | ios::out);
	if(outfile__array_neurongroup_2__underspace.is_open())
	{
		outfile__array_neurongroup_2__underspace.write(reinterpret_cast<char*>(_array_neurongroup_2__underspace), 3201*sizeof(_array_neurongroup_2__underspace[0]));
		outfile__array_neurongroup_2__underspace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_2__underspace." << endl;
	}
	ofstream outfile__array_neurongroup_2_i;
	outfile__array_neurongroup_2_i.open("results/_array_neurongroup_2_i_6263111221515835924", ios::binary | ios::out);
	if(outfile__array_neurongroup_2_i.is_open())
	{
		outfile__array_neurongroup_2_i.write(reinterpret_cast<char*>(_array_neurongroup_2_i), 3200*sizeof(_array_neurongroup_2_i[0]));
		outfile__array_neurongroup_2_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_2_i." << endl;
	}
	ofstream outfile__array_neurongroup_2_v;
	outfile__array_neurongroup_2_v.open("results/_array_neurongroup_2_v_6263111221515835915", ios::binary | ios::out);
	if(outfile__array_neurongroup_2_v.is_open())
	{
		outfile__array_neurongroup_2_v.write(reinterpret_cast<char*>(_array_neurongroup_2_v), 3200*sizeof(_array_neurongroup_2_v[0]));
		outfile__array_neurongroup_2_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_2_v." << endl;
	}
	ofstream outfile__array_neurongroup_3__spikespace;
	outfile__array_neurongroup_3__spikespace.open("results/_array_neurongroup_3__spikespace_-337828247222639147", ios::binary | ios::out);
	if(outfile__array_neurongroup_3__spikespace.is_open())
	{
		outfile__array_neurongroup_3__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_3__spikespace), 801*sizeof(_array_neurongroup_3__spikespace[0]));
		outfile__array_neurongroup_3__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_3__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_3__underspace;
	outfile__array_neurongroup_3__underspace.open("results/_array_neurongroup_3__underspace_-5693993814669556859", ios::binary | ios::out);
	if(outfile__array_neurongroup_3__underspace.is_open())
	{
		outfile__array_neurongroup_3__underspace.write(reinterpret_cast<char*>(_array_neurongroup_3__underspace), 801*sizeof(_array_neurongroup_3__underspace[0]));
		outfile__array_neurongroup_3__underspace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_3__underspace." << endl;
	}
	ofstream outfile__array_neurongroup_3_i;
	outfile__array_neurongroup_3_i.open("results/_array_neurongroup_3_i_6263112221643836317", ios::binary | ios::out);
	if(outfile__array_neurongroup_3_i.is_open())
	{
		outfile__array_neurongroup_3_i.write(reinterpret_cast<char*>(_array_neurongroup_3_i), 800*sizeof(_array_neurongroup_3_i[0]));
		outfile__array_neurongroup_3_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_3_i." << endl;
	}
	ofstream outfile__array_neurongroup_3_v;
	outfile__array_neurongroup_3_v.open("results/_array_neurongroup_3_v_6263112221643836290", ios::binary | ios::out);
	if(outfile__array_neurongroup_3_v.is_open())
	{
		outfile__array_neurongroup_3_v.write(reinterpret_cast<char*>(_array_neurongroup_3_v), 800*sizeof(_array_neurongroup_3_v[0]));
		outfile__array_neurongroup_3_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_3_v." << endl;
	}
	ofstream outfile__array_neurongroup_4__spikespace;
	outfile__array_neurongroup_4__spikespace.open("results/_array_neurongroup_4__spikespace_3226332606572092710", ios::binary | ios::out);
	if(outfile__array_neurongroup_4__spikespace.is_open())
	{
		outfile__array_neurongroup_4__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_4__spikespace), 501*sizeof(_array_neurongroup_4__spikespace[0]));
		outfile__array_neurongroup_4__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_4__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_4_i;
	outfile__array_neurongroup_4_i.open("results/_array_neurongroup_4_i_6263113221515835942", ios::binary | ios::out);
	if(outfile__array_neurongroup_4_i.is_open())
	{
		outfile__array_neurongroup_4_i.write(reinterpret_cast<char*>(_array_neurongroup_4_i), 500*sizeof(_array_neurongroup_4_i[0]));
		outfile__array_neurongroup_4_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_4_i." << endl;
	}
	ofstream outfile__array_neurongroup_4_v;
	outfile__array_neurongroup_4_v.open("results/_array_neurongroup_4_v_6263113221515835961", ios::binary | ios::out);
	if(outfile__array_neurongroup_4_v.is_open())
	{
		outfile__array_neurongroup_4_v.write(reinterpret_cast<char*>(_array_neurongroup_4_v), 500*sizeof(_array_neurongroup_4_v[0]));
		outfile__array_neurongroup_4_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_4_v." << endl;
	}
	ofstream outfile__array_neurongroup_5__spikespace;
	outfile__array_neurongroup_5__spikespace.open("results/_array_neurongroup_5__spikespace_-2761740861606240481", ios::binary | ios::out);
	if(outfile__array_neurongroup_5__spikespace.is_open())
	{
		outfile__array_neurongroup_5__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_5__spikespace), 11*sizeof(_array_neurongroup_5__spikespace[0]));
		outfile__array_neurongroup_5__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_5__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_5_i;
	outfile__array_neurongroup_5_i.open("results/_array_neurongroup_5_i_6263114221643836335", ios::binary | ios::out);
	if(outfile__array_neurongroup_5_i.is_open())
	{
		outfile__array_neurongroup_5_i.write(reinterpret_cast<char*>(_array_neurongroup_5_i), 10*sizeof(_array_neurongroup_5_i[0]));
		outfile__array_neurongroup_5_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_5_i." << endl;
	}
	ofstream outfile__array_neurongroup_5_v;
	outfile__array_neurongroup_5_v.open("results/_array_neurongroup_5_v_6263114221643836336", ios::binary | ios::out);
	if(outfile__array_neurongroup_5_v.is_open())
	{
		outfile__array_neurongroup_5_v.write(reinterpret_cast<char*>(_array_neurongroup_5_v), 10*sizeof(_array_neurongroup_5_v[0]));
		outfile__array_neurongroup_5_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_5_v." << endl;
	}
	ofstream outfile__array_neurongroup_6__spikespace;
	outfile__array_neurongroup_6__spikespace.open("results/_array_neurongroup_6__spikespace_-4386026164649702152", ios::binary | ios::out);
	if(outfile__array_neurongroup_6__spikespace.is_open())
	{
		outfile__array_neurongroup_6__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_6__spikespace), 11*sizeof(_array_neurongroup_6__spikespace[0]));
		outfile__array_neurongroup_6__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_6__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_6_i;
	outfile__array_neurongroup_6_i.open("results/_array_neurongroup_6_i_6263115221515835960", ios::binary | ios::out);
	if(outfile__array_neurongroup_6_i.is_open())
	{
		outfile__array_neurongroup_6_i.write(reinterpret_cast<char*>(_array_neurongroup_6_i), 10*sizeof(_array_neurongroup_6_i[0]));
		outfile__array_neurongroup_6_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_6_i." << endl;
	}
	ofstream outfile__array_neurongroup_6_v;
	outfile__array_neurongroup_6_v.open("results/_array_neurongroup_6_v_6263115221515835943", ios::binary | ios::out);
	if(outfile__array_neurongroup_6_v.is_open())
	{
		outfile__array_neurongroup_6_v.write(reinterpret_cast<char*>(_array_neurongroup_6_v), 10*sizeof(_array_neurongroup_6_v[0]));
		outfile__array_neurongroup_6_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_6_v." << endl;
	}
	ofstream outfile__array_neurongroup__spikespace;
	outfile__array_neurongroup__spikespace.open("results/_array_neurongroup__spikespace_6291509255835556833", ios::binary | ios::out);
	if(outfile__array_neurongroup__spikespace.is_open())
	{
		outfile__array_neurongroup__spikespace.write(reinterpret_cast<char*>(_array_neurongroup__spikespace), 11521*sizeof(_array_neurongroup__spikespace[0]));
		outfile__array_neurongroup__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup__underspace;
	outfile__array_neurongroup__underspace.open("results/_array_neurongroup__underspace_-7046950117866497607", ios::binary | ios::out);
	if(outfile__array_neurongroup__underspace.is_open())
	{
		outfile__array_neurongroup__underspace.write(reinterpret_cast<char*>(_array_neurongroup__underspace), 11521*sizeof(_array_neurongroup__underspace[0]));
		outfile__array_neurongroup__underspace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup__underspace." << endl;
	}
	ofstream outfile__array_neurongroup_i;
	outfile__array_neurongroup_i.open("results/_array_neurongroup_i_-2688036259655650195", ios::binary | ios::out);
	if(outfile__array_neurongroup_i.is_open())
	{
		outfile__array_neurongroup_i.write(reinterpret_cast<char*>(_array_neurongroup_i), 11520*sizeof(_array_neurongroup_i[0]));
		outfile__array_neurongroup_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_i." << endl;
	}
	ofstream outfile__array_neurongroup_v;
	outfile__array_neurongroup_v.open("results/_array_neurongroup_v_-2688036259655650190", ios::binary | ios::out);
	if(outfile__array_neurongroup_v.is_open())
	{
		outfile__array_neurongroup_v.write(reinterpret_cast<char*>(_array_neurongroup_v), 11520*sizeof(_array_neurongroup_v[0]));
		outfile__array_neurongroup_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_v." << endl;
	}
	ofstream outfile__array_poissongroup__spikespace;
	outfile__array_poissongroup__spikespace.open("results/_array_poissongroup__spikespace_-4364673061333452130", ios::binary | ios::out);
	if(outfile__array_poissongroup__spikespace.is_open())
	{
		outfile__array_poissongroup__spikespace.write(reinterpret_cast<char*>(_array_poissongroup__spikespace), 785*sizeof(_array_poissongroup__spikespace[0]));
		outfile__array_poissongroup__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_poissongroup__spikespace." << endl;
	}
	ofstream outfile__array_poissongroup_i;
	outfile__array_poissongroup_i.open("results/_array_poissongroup_i_2968481286923345034", ios::binary | ios::out);
	if(outfile__array_poissongroup_i.is_open())
	{
		outfile__array_poissongroup_i.write(reinterpret_cast<char*>(_array_poissongroup_i), 784*sizeof(_array_poissongroup_i[0]));
		outfile__array_poissongroup_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_poissongroup_i." << endl;
	}
	ofstream outfile__array_poissongroup_rates;
	outfile__array_poissongroup_rates.open("results/_array_poissongroup_rates_6241245451607672350", ios::binary | ios::out);
	if(outfile__array_poissongroup_rates.is_open())
	{
		outfile__array_poissongroup_rates.write(reinterpret_cast<char*>(_array_poissongroup_rates), 784*sizeof(_array_poissongroup_rates[0]));
		outfile__array_poissongroup_rates.close();
	} else
	{
		std::cout << "Error writing output file for _array_poissongroup_rates." << endl;
	}
	ofstream outfile__array_spikemonitor__source_idx;
	outfile__array_spikemonitor__source_idx.open("results/_array_spikemonitor__source_idx_-4045852888739339153", ios::binary | ios::out);
	if(outfile__array_spikemonitor__source_idx.is_open())
	{
		outfile__array_spikemonitor__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor__source_idx), 10*sizeof(_array_spikemonitor__source_idx[0]));
		outfile__array_spikemonitor__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_count;
	outfile__array_spikemonitor_count.open("results/_array_spikemonitor_count_-3651895352503201284", ios::binary | ios::out);
	if(outfile__array_spikemonitor_count.is_open())
	{
		outfile__array_spikemonitor_count.write(reinterpret_cast<char*>(_array_spikemonitor_count), 10*sizeof(_array_spikemonitor_count[0]));
		outfile__array_spikemonitor_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_count." << endl;
	}
	ofstream outfile__array_spikemonitor_N;
	outfile__array_spikemonitor_N.open("results/_array_spikemonitor_N_73938390545997659", ios::binary | ios::out);
	if(outfile__array_spikemonitor_N.is_open())
	{
		outfile__array_spikemonitor_N.write(reinterpret_cast<char*>(_array_spikemonitor_N), 1*sizeof(_array_spikemonitor_N[0]));
		outfile__array_spikemonitor_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_N." << endl;
	}
	ofstream outfile__array_synapses_1_N;
	outfile__array_synapses_1_N.open("results/_array_synapses_1_N_-7473518110119523383", ios::binary | ios::out);
	if(outfile__array_synapses_1_N.is_open())
	{
		outfile__array_synapses_1_N.write(reinterpret_cast<char*>(_array_synapses_1_N), 1*sizeof(_array_synapses_1_N[0]));
		outfile__array_synapses_1_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_1_N." << endl;
	}
	ofstream outfile__array_synapses_1_sources;
	outfile__array_synapses_1_sources.open("results/_array_synapses_1_sources_-8800941369442562565", ios::binary | ios::out);
	if(outfile__array_synapses_1_sources.is_open())
	{
		outfile__array_synapses_1_sources.write(reinterpret_cast<char*>(_array_synapses_1_sources), 11520*sizeof(_array_synapses_1_sources[0]));
		outfile__array_synapses_1_sources.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_1_sources." << endl;
	}
	ofstream outfile__array_synapses_1_targets;
	outfile__array_synapses_1_targets.open("results/_array_synapses_1_targets_-5815039991153431049", ios::binary | ios::out);
	if(outfile__array_synapses_1_targets.is_open())
	{
		outfile__array_synapses_1_targets.write(reinterpret_cast<char*>(_array_synapses_1_targets), 11520*sizeof(_array_synapses_1_targets[0]));
		outfile__array_synapses_1_targets.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_1_targets." << endl;
	}
	ofstream outfile__array_synapses_2_N;
	outfile__array_synapses_2_N.open("results/_array_synapses_2_N_-7473517110247523754", ios::binary | ios::out);
	if(outfile__array_synapses_2_N.is_open())
	{
		outfile__array_synapses_2_N.write(reinterpret_cast<char*>(_array_synapses_2_N), 1*sizeof(_array_synapses_2_N[0]));
		outfile__array_synapses_2_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_2_N." << endl;
	}
	ofstream outfile__array_synapses_2_sources;
	outfile__array_synapses_2_sources.open("results/_array_synapses_2_sources_6171244717947166436", ios::binary | ios::out);
	if(outfile__array_synapses_2_sources.is_open())
	{
		outfile__array_synapses_2_sources.write(reinterpret_cast<char*>(_array_synapses_2_sources), 1600000*sizeof(_array_synapses_2_sources[0]));
		outfile__array_synapses_2_sources.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_2_sources." << endl;
	}
	ofstream outfile__array_synapses_2_targets;
	outfile__array_synapses_2_targets.open("results/_array_synapses_2_targets_7007083414236605572", ios::binary | ios::out);
	if(outfile__array_synapses_2_targets.is_open())
	{
		outfile__array_synapses_2_targets.write(reinterpret_cast<char*>(_array_synapses_2_targets), 1600000*sizeof(_array_synapses_2_targets[0]));
		outfile__array_synapses_2_targets.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_2_targets." << endl;
	}
	ofstream outfile__array_synapses_3_N;
	outfile__array_synapses_3_N.open("results/_array_synapses_3_N_-7473516110119523361", ios::binary | ios::out);
	if(outfile__array_synapses_3_N.is_open())
	{
		outfile__array_synapses_3_N.write(reinterpret_cast<char*>(_array_synapses_3_N), 1*sizeof(_array_synapses_3_N[0]));
		outfile__array_synapses_3_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_3_N." << endl;
	}
	ofstream outfile__array_synapses_3_sources;
	outfile__array_synapses_3_sources.open("results/_array_synapses_3_sources_-8647731759271549707", ios::binary | ios::out);
	if(outfile__array_synapses_3_sources.is_open())
	{
		outfile__array_synapses_3_sources.write(reinterpret_cast<char*>(_array_synapses_3_sources), 3200*sizeof(_array_synapses_3_sources[0]));
		outfile__array_synapses_3_sources.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_3_sources." << endl;
	}
	ofstream outfile__array_synapses_3_targets;
	outfile__array_synapses_3_targets.open("results/_array_synapses_3_targets_-9101479339153775255", ios::binary | ios::out);
	if(outfile__array_synapses_3_targets.is_open())
	{
		outfile__array_synapses_3_targets.write(reinterpret_cast<char*>(_array_synapses_3_targets), 3200*sizeof(_array_synapses_3_targets[0]));
		outfile__array_synapses_3_targets.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_3_targets." << endl;
	}
	ofstream outfile__array_synapses_4_N;
	outfile__array_synapses_4_N.open("results/_array_synapses_4_N_-7473515110247523932", ios::binary | ios::out);
	if(outfile__array_synapses_4_N.is_open())
	{
		outfile__array_synapses_4_N.write(reinterpret_cast<char*>(_array_synapses_4_N), 1*sizeof(_array_synapses_4_N[0]));
		outfile__array_synapses_4_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_4_N." << endl;
	}
	ofstream outfile__array_synapses_4_sources;
	outfile__array_synapses_4_sources.open("results/_array_synapses_4_sources_1332494506520317198", ios::binary | ios::out);
	if(outfile__array_synapses_4_sources.is_open())
	{
		outfile__array_synapses_4_sources.write(reinterpret_cast<char*>(_array_synapses_4_sources), 400000*sizeof(_array_synapses_4_sources[0]));
		outfile__array_synapses_4_sources.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_4_sources." << endl;
	}
	ofstream outfile__array_synapses_4_targets;
	outfile__array_synapses_4_targets.open("results/_array_synapses_4_targets_6943628183544854918", ios::binary | ios::out);
	if(outfile__array_synapses_4_targets.is_open())
	{
		outfile__array_synapses_4_targets.write(reinterpret_cast<char*>(_array_synapses_4_targets), 400000*sizeof(_array_synapses_4_targets[0]));
		outfile__array_synapses_4_targets.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_4_targets." << endl;
	}
	ofstream outfile__array_synapses_5_N;
	outfile__array_synapses_5_N.open("results/_array_synapses_5_N_-7473514110119523539", ios::binary | ios::out);
	if(outfile__array_synapses_5_N.is_open())
	{
		outfile__array_synapses_5_N.write(reinterpret_cast<char*>(_array_synapses_5_N), 1*sizeof(_array_synapses_5_N[0]));
		outfile__array_synapses_5_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_5_N." << endl;
	}
	ofstream outfile__array_synapses_5_sources;
	outfile__array_synapses_5_sources.open("results/_array_synapses_5_sources_-2410148184643561825", ios::binary | ios::out);
	if(outfile__array_synapses_5_sources.is_open())
	{
		outfile__array_synapses_5_sources.write(reinterpret_cast<char*>(_array_synapses_5_sources), 5000*sizeof(_array_synapses_5_sources[0]));
		outfile__array_synapses_5_sources.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_5_sources." << endl;
	}
	ofstream outfile__array_synapses_5_targets;
	outfile__array_synapses_5_targets.open("results/_array_synapses_5_targets_-1134252501759464813", ios::binary | ios::out);
	if(outfile__array_synapses_5_targets.is_open())
	{
		outfile__array_synapses_5_targets.write(reinterpret_cast<char*>(_array_synapses_5_targets), 5000*sizeof(_array_synapses_5_targets[0]));
		outfile__array_synapses_5_targets.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_5_targets." << endl;
	}
	ofstream outfile__array_synapses_6_N;
	outfile__array_synapses_6_N.open("results/_array_synapses_6_N_-7473513110247523910", ios::binary | ios::out);
	if(outfile__array_synapses_6_N.is_open())
	{
		outfile__array_synapses_6_N.write(reinterpret_cast<char*>(_array_synapses_6_N), 1*sizeof(_array_synapses_6_N[0]));
		outfile__array_synapses_6_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_6_N." << endl;
	}
	ofstream outfile__array_synapses_6_sources;
	outfile__array_synapses_6_sources.open("results/_array_synapses_6_sources_-3321875686862743112", ios::binary | ios::out);
	if(outfile__array_synapses_6_sources.is_open())
	{
		outfile__array_synapses_6_sources.write(reinterpret_cast<char*>(_array_synapses_6_sources), 100*sizeof(_array_synapses_6_sources[0]));
		outfile__array_synapses_6_sources.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_6_sources." << endl;
	}
	ofstream outfile__array_synapses_6_targets;
	outfile__array_synapses_6_targets.open("results/_array_synapses_6_targets_-2827038647876354496", ios::binary | ios::out);
	if(outfile__array_synapses_6_targets.is_open())
	{
		outfile__array_synapses_6_targets.write(reinterpret_cast<char*>(_array_synapses_6_targets), 100*sizeof(_array_synapses_6_targets[0]));
		outfile__array_synapses_6_targets.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_6_targets." << endl;
	}
	ofstream outfile__array_synapses_N;
	outfile__array_synapses_N.open("results/_array_synapses_N_-7833853409752232273", ios::binary | ios::out);
	if(outfile__array_synapses_N.is_open())
	{
		outfile__array_synapses_N.write(reinterpret_cast<char*>(_array_synapses_N), 1*sizeof(_array_synapses_N[0]));
		outfile__array_synapses_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_N." << endl;
	}
	ofstream outfile__array_synapses_sources;
	outfile__array_synapses_sources.open("results/_array_synapses_sources_6108041809392029201", ios::binary | ios::out);
	if(outfile__array_synapses_sources.is_open())
	{
		outfile__array_synapses_sources.write(reinterpret_cast<char*>(_array_synapses_sources), 288000*sizeof(_array_synapses_sources[0]));
		outfile__array_synapses_sources.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_sources." << endl;
	}
	ofstream outfile__array_synapses_targets;
	outfile__array_synapses_targets.open("results/_array_synapses_targets_7383937492276126237", ios::binary | ios::out);
	if(outfile__array_synapses_targets.is_open())
	{
		outfile__array_synapses_targets.write(reinterpret_cast<char*>(_array_synapses_targets), 288000*sizeof(_array_synapses_targets[0]));
		outfile__array_synapses_targets.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_targets." << endl;
	}

	ofstream outfile__dynamic_array_spikemonitor_i;
	outfile__dynamic_array_spikemonitor_i.open("results/_dynamic_array_spikemonitor_i_3873805716461528078", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_i.is_open())
	{
        if (! _dynamic_array_spikemonitor_i.empty() )
        {
			outfile__dynamic_array_spikemonitor_i.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_i[0]), _dynamic_array_spikemonitor_i.size()*sizeof(_dynamic_array_spikemonitor_i[0]));
		    outfile__dynamic_array_spikemonitor_i.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_i." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_t;
	outfile__dynamic_array_spikemonitor_t.open("results/_dynamic_array_spikemonitor_t_3873805716461528083", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_t.is_open())
	{
        if (! _dynamic_array_spikemonitor_t.empty() )
        {
			outfile__dynamic_array_spikemonitor_t.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_t[0]), _dynamic_array_spikemonitor_t.size()*sizeof(_dynamic_array_spikemonitor_t[0]));
		    outfile__dynamic_array_spikemonitor_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_t." << endl;
	}
	ofstream outfile__dynamic_array_synapses_1__synaptic_post;
	outfile__dynamic_array_synapses_1__synaptic_post.open("results/_dynamic_array_synapses_1__synaptic_post_-4367449856540212009", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_1__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_1__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_1__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_1__synaptic_post[0]), _dynamic_array_synapses_1__synaptic_post.size()*sizeof(_dynamic_array_synapses_1__synaptic_post[0]));
		    outfile__dynamic_array_synapses_1__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_1__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_1__synaptic_pre;
	outfile__dynamic_array_synapses_1__synaptic_pre.open("results/_dynamic_array_synapses_1__synaptic_pre_1368795276670783483", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_1__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_1__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_1__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_1__synaptic_pre[0]), _dynamic_array_synapses_1__synaptic_pre.size()*sizeof(_dynamic_array_synapses_1__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_1__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_1__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_1_delay;
	outfile__dynamic_array_synapses_1_delay.open("results/_dynamic_array_synapses_1_delay_3502988388203646216", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_1_delay.is_open())
	{
        if (! _dynamic_array_synapses_1_delay.empty() )
        {
			outfile__dynamic_array_synapses_1_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_1_delay[0]), _dynamic_array_synapses_1_delay.size()*sizeof(_dynamic_array_synapses_1_delay[0]));
		    outfile__dynamic_array_synapses_1_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_1_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_1_lastupdate;
	outfile__dynamic_array_synapses_1_lastupdate.open("results/_dynamic_array_synapses_1_lastupdate_6875119916677774017", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_1_lastupdate.is_open())
	{
        if (! _dynamic_array_synapses_1_lastupdate.empty() )
        {
			outfile__dynamic_array_synapses_1_lastupdate.write(reinterpret_cast<char*>(&_dynamic_array_synapses_1_lastupdate[0]), _dynamic_array_synapses_1_lastupdate.size()*sizeof(_dynamic_array_synapses_1_lastupdate[0]));
		    outfile__dynamic_array_synapses_1_lastupdate.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_1_lastupdate." << endl;
	}
	ofstream outfile__dynamic_array_synapses_1_N_incoming;
	outfile__dynamic_array_synapses_1_N_incoming.open("results/_dynamic_array_synapses_1_N_incoming_-5364435978754666149", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_1_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_1_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_1_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_1_N_incoming[0]), _dynamic_array_synapses_1_N_incoming.size()*sizeof(_dynamic_array_synapses_1_N_incoming[0]));
		    outfile__dynamic_array_synapses_1_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_1_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_1_N_outgoing;
	outfile__dynamic_array_synapses_1_N_outgoing.open("results/_dynamic_array_synapses_1_N_outgoing_7721560298971024321", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_1_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_1_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_1_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_1_N_outgoing[0]), _dynamic_array_synapses_1_N_outgoing.size()*sizeof(_dynamic_array_synapses_1_N_outgoing[0]));
		    outfile__dynamic_array_synapses_1_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_1_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_1_w;
	outfile__dynamic_array_synapses_1_w.open("results/_dynamic_array_synapses_1_w_-1083981064091387634", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_1_w.is_open())
	{
        if (! _dynamic_array_synapses_1_w.empty() )
        {
			outfile__dynamic_array_synapses_1_w.write(reinterpret_cast<char*>(&_dynamic_array_synapses_1_w[0]), _dynamic_array_synapses_1_w.size()*sizeof(_dynamic_array_synapses_1_w[0]));
		    outfile__dynamic_array_synapses_1_w.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_1_w." << endl;
	}
	ofstream outfile__dynamic_array_synapses_2__synaptic_post;
	outfile__dynamic_array_synapses_2__synaptic_post.open("results/_dynamic_array_synapses_2__synaptic_post_3137150149881540902", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_2__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_2__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_2__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_2__synaptic_post[0]), _dynamic_array_synapses_2__synaptic_post.size()*sizeof(_dynamic_array_synapses_2__synaptic_post[0]));
		    outfile__dynamic_array_synapses_2__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_2__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_2__synaptic_pre;
	outfile__dynamic_array_synapses_2__synaptic_pre.open("results/_dynamic_array_synapses_2__synaptic_pre_405387568754284564", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_2__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_2__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_2__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_2__synaptic_pre[0]), _dynamic_array_synapses_2__synaptic_pre.size()*sizeof(_dynamic_array_synapses_2__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_2__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_2__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_2_delay;
	outfile__dynamic_array_synapses_2_delay.open("results/_dynamic_array_synapses_2_delay_842331536822541471", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_2_delay.is_open())
	{
        if (! _dynamic_array_synapses_2_delay.empty() )
        {
			outfile__dynamic_array_synapses_2_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_2_delay[0]), _dynamic_array_synapses_2_delay.size()*sizeof(_dynamic_array_synapses_2_delay[0]));
		    outfile__dynamic_array_synapses_2_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_2_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_2_lastupdate;
	outfile__dynamic_array_synapses_2_lastupdate.open("results/_dynamic_array_synapses_2_lastupdate_-5705154207782117868", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_2_lastupdate.is_open())
	{
        if (! _dynamic_array_synapses_2_lastupdate.empty() )
        {
			outfile__dynamic_array_synapses_2_lastupdate.write(reinterpret_cast<char*>(&_dynamic_array_synapses_2_lastupdate[0]), _dynamic_array_synapses_2_lastupdate.size()*sizeof(_dynamic_array_synapses_2_lastupdate[0]));
		    outfile__dynamic_array_synapses_2_lastupdate.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_2_lastupdate." << endl;
	}
	ofstream outfile__dynamic_array_synapses_2_N_incoming;
	outfile__dynamic_array_synapses_2_N_incoming.open("results/_dynamic_array_synapses_2_N_incoming_-3275600429616745766", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_2_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_2_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_2_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_2_N_incoming[0]), _dynamic_array_synapses_2_N_incoming.size()*sizeof(_dynamic_array_synapses_2_N_incoming[0]));
		    outfile__dynamic_array_synapses_2_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_2_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_2_N_outgoing;
	outfile__dynamic_array_synapses_2_N_outgoing.open("results/_dynamic_array_synapses_2_N_outgoing_6717848568732218728", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_2_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_2_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_2_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_2_N_outgoing[0]), _dynamic_array_synapses_2_N_outgoing.size()*sizeof(_dynamic_array_synapses_2_N_outgoing[0]));
		    outfile__dynamic_array_synapses_2_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_2_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_2_w;
	outfile__dynamic_array_synapses_2_w.open("results/_dynamic_array_synapses_2_w_-1083984064219388015", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_2_w.is_open())
	{
        if (! _dynamic_array_synapses_2_w.empty() )
        {
			outfile__dynamic_array_synapses_2_w.write(reinterpret_cast<char*>(&_dynamic_array_synapses_2_w[0]), _dynamic_array_synapses_2_w.size()*sizeof(_dynamic_array_synapses_2_w[0]));
		    outfile__dynamic_array_synapses_2_w.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_2_w." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3__synaptic_post;
	outfile__dynamic_array_synapses_3__synaptic_post.open("results/_dynamic_array_synapses_3__synaptic_post_-6807719042071735663", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_3__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_3__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3__synaptic_post[0]), _dynamic_array_synapses_3__synaptic_post.size()*sizeof(_dynamic_array_synapses_3__synaptic_post[0]));
		    outfile__dynamic_array_synapses_3__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3__synaptic_pre;
	outfile__dynamic_array_synapses_3__synaptic_pre.open("results/_dynamic_array_synapses_3__synaptic_pre_-2450464939086801735", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_3__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_3__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3__synaptic_pre[0]), _dynamic_array_synapses_3__synaptic_pre.size()*sizeof(_dynamic_array_synapses_3__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_3__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3_delay;
	outfile__dynamic_array_synapses_3_delay.open("results/_dynamic_array_synapses_3_delay_-2489879914270044434", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3_delay.is_open())
	{
        if (! _dynamic_array_synapses_3_delay.empty() )
        {
			outfile__dynamic_array_synapses_3_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3_delay[0]), _dynamic_array_synapses_3_delay.size()*sizeof(_dynamic_array_synapses_3_delay[0]));
		    outfile__dynamic_array_synapses_3_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3_lastupdate;
	outfile__dynamic_array_synapses_3_lastupdate.open("results/_dynamic_array_synapses_3_lastupdate_5172383737954781683", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3_lastupdate.is_open())
	{
        if (! _dynamic_array_synapses_3_lastupdate.empty() )
        {
			outfile__dynamic_array_synapses_3_lastupdate.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3_lastupdate[0]), _dynamic_array_synapses_3_lastupdate.size()*sizeof(_dynamic_array_synapses_3_lastupdate[0]));
		    outfile__dynamic_array_synapses_3_lastupdate.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3_lastupdate." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3_N_incoming;
	outfile__dynamic_array_synapses_3_N_incoming.open("results/_dynamic_array_synapses_3_N_incoming_-2106702523814753163", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_3_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_3_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3_N_incoming[0]), _dynamic_array_synapses_3_N_incoming.size()*sizeof(_dynamic_array_synapses_3_N_incoming[0]));
		    outfile__dynamic_array_synapses_3_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3_N_outgoing;
	outfile__dynamic_array_synapses_3_N_outgoing.open("results/_dynamic_array_synapses_3_N_outgoing_-3421667455987502645", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_3_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_3_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3_N_outgoing[0]), _dynamic_array_synapses_3_N_outgoing.size()*sizeof(_dynamic_array_synapses_3_N_outgoing[0]));
		    outfile__dynamic_array_synapses_3_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3_w;
	outfile__dynamic_array_synapses_3_w.open("results/_dynamic_array_synapses_3_w_-1083983064091387624", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3_w.is_open())
	{
        if (! _dynamic_array_synapses_3_w.empty() )
        {
			outfile__dynamic_array_synapses_3_w.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3_w[0]), _dynamic_array_synapses_3_w.size()*sizeof(_dynamic_array_synapses_3_w[0]));
		    outfile__dynamic_array_synapses_3_w.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3_w." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4__synaptic_post;
	outfile__dynamic_array_synapses_4__synaptic_post.open("results/_dynamic_array_synapses_4__synaptic_post_-4092947258271513536", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_4__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_4__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4__synaptic_post[0]), _dynamic_array_synapses_4__synaptic_post.size()*sizeof(_dynamic_array_synapses_4__synaptic_post[0]));
		    outfile__dynamic_array_synapses_4__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4__synaptic_pre;
	outfile__dynamic_array_synapses_4__synaptic_pre.open("results/_dynamic_array_synapses_4__synaptic_pre_5068518783656269522", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_4__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_4__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4__synaptic_pre[0]), _dynamic_array_synapses_4__synaptic_pre.size()*sizeof(_dynamic_array_synapses_4__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_4__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4_delay;
	outfile__dynamic_array_synapses_4_delay.open("results/_dynamic_array_synapses_4_delay_-9070136677468453939", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4_delay.is_open())
	{
        if (! _dynamic_array_synapses_4_delay.empty() )
        {
			outfile__dynamic_array_synapses_4_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4_delay[0]), _dynamic_array_synapses_4_delay.size()*sizeof(_dynamic_array_synapses_4_delay[0]));
		    outfile__dynamic_array_synapses_4_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4_lastupdate;
	outfile__dynamic_array_synapses_4_lastupdate.open("results/_dynamic_array_synapses_4_lastupdate_-8962509454501334282", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4_lastupdate.is_open())
	{
        if (! _dynamic_array_synapses_4_lastupdate.empty() )
        {
			outfile__dynamic_array_synapses_4_lastupdate.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4_lastupdate[0]), _dynamic_array_synapses_4_lastupdate.size()*sizeof(_dynamic_array_synapses_4_lastupdate[0]));
		    outfile__dynamic_array_synapses_4_lastupdate.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4_lastupdate." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4_N_incoming;
	outfile__dynamic_array_synapses_4_N_incoming.open("results/_dynamic_array_synapses_4_N_incoming_-3505121638531903940", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_4_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_4_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4_N_incoming[0]), _dynamic_array_synapses_4_N_incoming.size()*sizeof(_dynamic_array_synapses_4_N_incoming[0]));
		    outfile__dynamic_array_synapses_4_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4_N_outgoing;
	outfile__dynamic_array_synapses_4_N_outgoing.open("results/_dynamic_array_synapses_4_N_outgoing_46890498304195442", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_4_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_4_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4_N_outgoing[0]), _dynamic_array_synapses_4_N_outgoing.size()*sizeof(_dynamic_array_synapses_4_N_outgoing[0]));
		    outfile__dynamic_array_synapses_4_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4_w;
	outfile__dynamic_array_synapses_4_w.open("results/_dynamic_array_synapses_4_w_-1083978064219387989", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4_w.is_open())
	{
        if (! _dynamic_array_synapses_4_w.empty() )
        {
			outfile__dynamic_array_synapses_4_w.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4_w[0]), _dynamic_array_synapses_4_w.size()*sizeof(_dynamic_array_synapses_4_w[0]));
		    outfile__dynamic_array_synapses_4_w.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4_w." << endl;
	}
	ofstream outfile__dynamic_array_synapses_5__synaptic_post;
	outfile__dynamic_array_synapses_5__synaptic_post.open("results/_dynamic_array_synapses_5__synaptic_post_9066991549005155803", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_5__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_5__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_5__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_5__synaptic_post[0]), _dynamic_array_synapses_5__synaptic_post.size()*sizeof(_dynamic_array_synapses_5__synaptic_post[0]));
		    outfile__dynamic_array_synapses_5__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_5__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_5__synaptic_pre;
	outfile__dynamic_array_synapses_5__synaptic_pre.open("results/_dynamic_array_synapses_5__synaptic_pre_6928493121890122439", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_5__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_5__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_5__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_5__synaptic_pre[0]), _dynamic_array_synapses_5__synaptic_pre.size()*sizeof(_dynamic_array_synapses_5__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_5__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_5__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_5_delay;
	outfile__dynamic_array_synapses_5_delay.open("results/_dynamic_array_synapses_5_delay_7719061035252566996", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_5_delay.is_open())
	{
        if (! _dynamic_array_synapses_5_delay.empty() )
        {
			outfile__dynamic_array_synapses_5_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_5_delay[0]), _dynamic_array_synapses_5_delay.size()*sizeof(_dynamic_array_synapses_5_delay[0]));
		    outfile__dynamic_array_synapses_5_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_5_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_5_lastupdate;
	outfile__dynamic_array_synapses_5_lastupdate.open("results/_dynamic_array_synapses_5_lastupdate_1287471561635119405", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_5_lastupdate.is_open())
	{
        if (! _dynamic_array_synapses_5_lastupdate.empty() )
        {
			outfile__dynamic_array_synapses_5_lastupdate.write(reinterpret_cast<char*>(&_dynamic_array_synapses_5_lastupdate[0]), _dynamic_array_synapses_5_lastupdate.size()*sizeof(_dynamic_array_synapses_5_lastupdate[0]));
		    outfile__dynamic_array_synapses_5_lastupdate.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_5_lastupdate." << endl;
	}
	ofstream outfile__dynamic_array_synapses_5_N_incoming;
	outfile__dynamic_array_synapses_5_N_incoming.open("results/_dynamic_array_synapses_5_N_incoming_-8542884590583238577", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_5_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_5_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_5_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_5_N_incoming[0]), _dynamic_array_synapses_5_N_incoming.size()*sizeof(_dynamic_array_synapses_5_N_incoming[0]));
		    outfile__dynamic_array_synapses_5_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_5_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_5_N_outgoing;
	outfile__dynamic_array_synapses_5_N_outgoing.open("results/_dynamic_array_synapses_5_N_outgoing_8541650108320020005", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_5_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_5_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_5_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_5_N_outgoing[0]), _dynamic_array_synapses_5_N_outgoing.size()*sizeof(_dynamic_array_synapses_5_N_outgoing[0]));
		    outfile__dynamic_array_synapses_5_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_5_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_5_w;
	outfile__dynamic_array_synapses_5_w.open("results/_dynamic_array_synapses_5_w_-1083977064091387566", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_5_w.is_open())
	{
        if (! _dynamic_array_synapses_5_w.empty() )
        {
			outfile__dynamic_array_synapses_5_w.write(reinterpret_cast<char*>(&_dynamic_array_synapses_5_w[0]), _dynamic_array_synapses_5_w.size()*sizeof(_dynamic_array_synapses_5_w[0]));
		    outfile__dynamic_array_synapses_5_w.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_5_w." << endl;
	}
	ofstream outfile__dynamic_array_synapses_6__synaptic_post;
	outfile__dynamic_array_synapses_6__synaptic_post.open("results/_dynamic_array_synapses_6__synaptic_post_8979672492784261850", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_6__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_6__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_6__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_6__synaptic_post[0]), _dynamic_array_synapses_6__synaptic_post.size()*sizeof(_dynamic_array_synapses_6__synaptic_post[0]));
		    outfile__dynamic_array_synapses_6__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_6__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_6__synaptic_pre;
	outfile__dynamic_array_synapses_6__synaptic_pre.open("results/_dynamic_array_synapses_6__synaptic_pre_2283155644187591344", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_6__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_6__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_6__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_6__synaptic_pre[0]), _dynamic_array_synapses_6__synaptic_pre.size()*sizeof(_dynamic_array_synapses_6__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_6__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_6__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_6_delay;
	outfile__dynamic_array_synapses_6_delay.open("results/_dynamic_array_synapses_6_delay_7870373788113341035", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_6_delay.is_open())
	{
        if (! _dynamic_array_synapses_6_delay.empty() )
        {
			outfile__dynamic_array_synapses_6_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_6_delay[0]), _dynamic_array_synapses_6_delay.size()*sizeof(_dynamic_array_synapses_6_delay[0]));
		    outfile__dynamic_array_synapses_6_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_6_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_6_lastupdate;
	outfile__dynamic_array_synapses_6_lastupdate.open("results/_dynamic_array_synapses_6_lastupdate_-3955554494484559408", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_6_lastupdate.is_open())
	{
        if (! _dynamic_array_synapses_6_lastupdate.empty() )
        {
			outfile__dynamic_array_synapses_6_lastupdate.write(reinterpret_cast<char*>(&_dynamic_array_synapses_6_lastupdate[0]), _dynamic_array_synapses_6_lastupdate.size()*sizeof(_dynamic_array_synapses_6_lastupdate[0]));
		    outfile__dynamic_array_synapses_6_lastupdate.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_6_lastupdate." << endl;
	}
	ofstream outfile__dynamic_array_synapses_6_N_incoming;
	outfile__dynamic_array_synapses_6_N_incoming.open("results/_dynamic_array_synapses_6_N_incoming_-942052844014408290", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_6_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_6_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_6_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_6_N_incoming[0]), _dynamic_array_synapses_6_N_incoming.size()*sizeof(_dynamic_array_synapses_6_N_incoming[0]));
		    outfile__dynamic_array_synapses_6_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_6_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_6_N_outgoing;
	outfile__dynamic_array_synapses_6_N_outgoing.open("results/_dynamic_array_synapses_6_N_outgoing_9083518235633377116", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_6_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_6_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_6_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_6_N_outgoing[0]), _dynamic_array_synapses_6_N_outgoing.size()*sizeof(_dynamic_array_synapses_6_N_outgoing[0]));
		    outfile__dynamic_array_synapses_6_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_6_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_6_w;
	outfile__dynamic_array_synapses_6_w.open("results/_dynamic_array_synapses_6_w_-1083980064219387979", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_6_w.is_open())
	{
        if (! _dynamic_array_synapses_6_w.empty() )
        {
			outfile__dynamic_array_synapses_6_w.write(reinterpret_cast<char*>(&_dynamic_array_synapses_6_w[0]), _dynamic_array_synapses_6_w.size()*sizeof(_dynamic_array_synapses_6_w[0]));
		    outfile__dynamic_array_synapses_6_w.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_6_w." << endl;
	}
	ofstream outfile__dynamic_array_synapses__synaptic_post;
	outfile__dynamic_array_synapses__synaptic_post.open("results/_dynamic_array_synapses__synaptic_post_3840486125387374025", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses__synaptic_post[0]), _dynamic_array_synapses__synaptic_post.size()*sizeof(_dynamic_array_synapses__synaptic_post[0]));
		    outfile__dynamic_array_synapses__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses__synaptic_pre;
	outfile__dynamic_array_synapses__synaptic_pre.open("results/_dynamic_array_synapses__synaptic_pre_5162992210040840425", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses__synaptic_pre[0]), _dynamic_array_synapses__synaptic_pre.size()*sizeof(_dynamic_array_synapses__synaptic_pre[0]));
		    outfile__dynamic_array_synapses__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_delay;
	outfile__dynamic_array_synapses_delay.open("results/_dynamic_array_synapses_delay_-1215025784993018630", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_delay.is_open())
	{
        if (! _dynamic_array_synapses_delay.empty() )
        {
			outfile__dynamic_array_synapses_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_delay[0]), _dynamic_array_synapses_delay.size()*sizeof(_dynamic_array_synapses_delay[0]));
		    outfile__dynamic_array_synapses_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_lastupdate;
	outfile__dynamic_array_synapses_lastupdate.open("results/_dynamic_array_synapses_lastupdate_562699891839928247", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_lastupdate.is_open())
	{
        if (! _dynamic_array_synapses_lastupdate.empty() )
        {
			outfile__dynamic_array_synapses_lastupdate.write(reinterpret_cast<char*>(&_dynamic_array_synapses_lastupdate[0]), _dynamic_array_synapses_lastupdate.size()*sizeof(_dynamic_array_synapses_lastupdate[0]));
		    outfile__dynamic_array_synapses_lastupdate.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_lastupdate." << endl;
	}
	ofstream outfile__dynamic_array_synapses_N_incoming;
	outfile__dynamic_array_synapses_N_incoming.open("results/_dynamic_array_synapses_N_incoming_6651214916728133133", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_N_incoming[0]), _dynamic_array_synapses_N_incoming.size()*sizeof(_dynamic_array_synapses_N_incoming[0]));
		    outfile__dynamic_array_synapses_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_N_outgoing;
	outfile__dynamic_array_synapses_N_outgoing.open("results/_dynamic_array_synapses_N_outgoing_-3277140854151949897", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_N_outgoing[0]), _dynamic_array_synapses_N_outgoing.size()*sizeof(_dynamic_array_synapses_N_outgoing[0]));
		    outfile__dynamic_array_synapses_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_w;
	outfile__dynamic_array_synapses_w.open("results/_dynamic_array_synapses_w_-2614024316621171204", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_w.is_open())
	{
        if (! _dynamic_array_synapses_w.empty() )
        {
			outfile__dynamic_array_synapses_w.write(reinterpret_cast<char*>(&_dynamic_array_synapses_w[0]), _dynamic_array_synapses_w.size()*sizeof(_dynamic_array_synapses_w[0]));
		    outfile__dynamic_array_synapses_w.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_w." << endl;
	}


	// Write profiling info to disk
	ofstream outfile_profiling_info;
	outfile_profiling_info.open("results/profiling_info.txt", ios::out);
	if(outfile_profiling_info.is_open())
	{
	outfile_profiling_info << "neurongroup_1_resetter_1_codeobject\t" << neurongroup_1_resetter_1_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_1_resetter_codeobject\t" << neurongroup_1_resetter_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_1_thresholder_1_codeobject\t" << neurongroup_1_thresholder_1_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_1_thresholder_codeobject\t" << neurongroup_1_thresholder_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_2_resetter_1_codeobject\t" << neurongroup_2_resetter_1_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_2_resetter_codeobject\t" << neurongroup_2_resetter_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_2_thresholder_1_codeobject\t" << neurongroup_2_thresholder_1_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_2_thresholder_codeobject\t" << neurongroup_2_thresholder_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_3_resetter_1_codeobject\t" << neurongroup_3_resetter_1_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_3_resetter_codeobject\t" << neurongroup_3_resetter_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_3_thresholder_1_codeobject\t" << neurongroup_3_thresholder_1_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_3_thresholder_codeobject\t" << neurongroup_3_thresholder_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_4_resetter_codeobject\t" << neurongroup_4_resetter_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_4_thresholder_codeobject\t" << neurongroup_4_thresholder_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_5_resetter_codeobject\t" << neurongroup_5_resetter_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_5_thresholder_codeobject\t" << neurongroup_5_thresholder_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_6_resetter_codeobject\t" << neurongroup_6_resetter_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_6_thresholder_codeobject\t" << neurongroup_6_thresholder_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_resetter_1_codeobject\t" << neurongroup_resetter_1_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_resetter_codeobject\t" << neurongroup_resetter_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_thresholder_1_codeobject\t" << neurongroup_thresholder_1_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_thresholder_codeobject\t" << neurongroup_thresholder_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "poissongroup_thresholder_codeobject\t" << poissongroup_thresholder_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "spikemonitor_codeobject\t" << spikemonitor_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_1_pre_codeobject\t" << synapses_1_pre_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_1_pre_initialise_queue\t" << synapses_1_pre_initialise_queue_profiling_info << std::endl;
	outfile_profiling_info << "synapses_1_pre_push_spikes\t" << synapses_1_pre_push_spikes_profiling_info << std::endl;
	outfile_profiling_info << "synapses_1_synapses_create_array_codeobject\t" << synapses_1_synapses_create_array_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_2_pre_codeobject\t" << synapses_2_pre_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_2_pre_initialise_queue\t" << synapses_2_pre_initialise_queue_profiling_info << std::endl;
	outfile_profiling_info << "synapses_2_pre_push_spikes\t" << synapses_2_pre_push_spikes_profiling_info << std::endl;
	outfile_profiling_info << "synapses_2_synapses_create_array_codeobject\t" << synapses_2_synapses_create_array_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_3_pre_codeobject\t" << synapses_3_pre_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_3_pre_initialise_queue\t" << synapses_3_pre_initialise_queue_profiling_info << std::endl;
	outfile_profiling_info << "synapses_3_pre_push_spikes\t" << synapses_3_pre_push_spikes_profiling_info << std::endl;
	outfile_profiling_info << "synapses_3_synapses_create_array_codeobject\t" << synapses_3_synapses_create_array_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_4_pre_codeobject\t" << synapses_4_pre_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_4_pre_initialise_queue\t" << synapses_4_pre_initialise_queue_profiling_info << std::endl;
	outfile_profiling_info << "synapses_4_pre_push_spikes\t" << synapses_4_pre_push_spikes_profiling_info << std::endl;
	outfile_profiling_info << "synapses_4_synapses_create_array_codeobject\t" << synapses_4_synapses_create_array_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_5_pre_codeobject\t" << synapses_5_pre_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_5_pre_initialise_queue\t" << synapses_5_pre_initialise_queue_profiling_info << std::endl;
	outfile_profiling_info << "synapses_5_pre_push_spikes\t" << synapses_5_pre_push_spikes_profiling_info << std::endl;
	outfile_profiling_info << "synapses_5_synapses_create_array_codeobject\t" << synapses_5_synapses_create_array_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_6_pre_codeobject\t" << synapses_6_pre_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_6_pre_initialise_queue\t" << synapses_6_pre_initialise_queue_profiling_info << std::endl;
	outfile_profiling_info << "synapses_6_pre_push_spikes\t" << synapses_6_pre_push_spikes_profiling_info << std::endl;
	outfile_profiling_info << "synapses_6_synapses_create_array_codeobject\t" << synapses_6_synapses_create_array_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_pre_codeobject\t" << synapses_pre_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_pre_initialise_queue\t" << synapses_pre_initialise_queue_profiling_info << std::endl;
	outfile_profiling_info << "synapses_pre_push_spikes\t" << synapses_pre_push_spikes_profiling_info << std::endl;
	outfile_profiling_info << "synapses_synapses_create_array_codeobject\t" << synapses_synapses_create_array_codeobject_profiling_info << std::endl;
	outfile_profiling_info.close();
	} else
	{
	    std::cout << "Error writing profiling info to file." << std::endl;
	}

	// Write last run info to disk
	ofstream outfile_last_run_info;
	outfile_last_run_info.open("results/last_run_info.txt", ios::out);
	if(outfile_last_run_info.is_open())
	{
		outfile_last_run_info << (Network::_last_run_time) << " " << (Network::_last_run_completed_fraction) << std::endl;
		outfile_last_run_info.close();
	} else
	{
	    std::cout << "Error writing last run info to file." << std::endl;
	}
}

void _dealloc_arrays()
{
	using namespace brian;


	// static arrays
	if(_static_array__array_poissongroup_rates!=0)
	{
		delete [] _static_array__array_poissongroup_rates;
		_static_array__array_poissongroup_rates = 0;
	}
	if(_static_array__array_synapses_1_sources!=0)
	{
		delete [] _static_array__array_synapses_1_sources;
		_static_array__array_synapses_1_sources = 0;
	}
	if(_static_array__array_synapses_1_targets!=0)
	{
		delete [] _static_array__array_synapses_1_targets;
		_static_array__array_synapses_1_targets = 0;
	}
	if(_static_array__array_synapses_2_sources!=0)
	{
		delete [] _static_array__array_synapses_2_sources;
		_static_array__array_synapses_2_sources = 0;
	}
	if(_static_array__array_synapses_2_targets!=0)
	{
		delete [] _static_array__array_synapses_2_targets;
		_static_array__array_synapses_2_targets = 0;
	}
	if(_static_array__array_synapses_3_sources!=0)
	{
		delete [] _static_array__array_synapses_3_sources;
		_static_array__array_synapses_3_sources = 0;
	}
	if(_static_array__array_synapses_3_targets!=0)
	{
		delete [] _static_array__array_synapses_3_targets;
		_static_array__array_synapses_3_targets = 0;
	}
	if(_static_array__array_synapses_4_sources!=0)
	{
		delete [] _static_array__array_synapses_4_sources;
		_static_array__array_synapses_4_sources = 0;
	}
	if(_static_array__array_synapses_4_targets!=0)
	{
		delete [] _static_array__array_synapses_4_targets;
		_static_array__array_synapses_4_targets = 0;
	}
	if(_static_array__array_synapses_5_sources!=0)
	{
		delete [] _static_array__array_synapses_5_sources;
		_static_array__array_synapses_5_sources = 0;
	}
	if(_static_array__array_synapses_5_targets!=0)
	{
		delete [] _static_array__array_synapses_5_targets;
		_static_array__array_synapses_5_targets = 0;
	}
	if(_static_array__array_synapses_6_sources!=0)
	{
		delete [] _static_array__array_synapses_6_sources;
		_static_array__array_synapses_6_sources = 0;
	}
	if(_static_array__array_synapses_6_targets!=0)
	{
		delete [] _static_array__array_synapses_6_targets;
		_static_array__array_synapses_6_targets = 0;
	}
	if(_static_array__array_synapses_sources!=0)
	{
		delete [] _static_array__array_synapses_sources;
		_static_array__array_synapses_sources = 0;
	}
	if(_static_array__array_synapses_targets!=0)
	{
		delete [] _static_array__array_synapses_targets;
		_static_array__array_synapses_targets = 0;
	}
	if(_static_array__dynamic_array_synapses_1_w!=0)
	{
		delete [] _static_array__dynamic_array_synapses_1_w;
		_static_array__dynamic_array_synapses_1_w = 0;
	}
	if(_static_array__dynamic_array_synapses_2_w!=0)
	{
		delete [] _static_array__dynamic_array_synapses_2_w;
		_static_array__dynamic_array_synapses_2_w = 0;
	}
	if(_static_array__dynamic_array_synapses_3_w!=0)
	{
		delete [] _static_array__dynamic_array_synapses_3_w;
		_static_array__dynamic_array_synapses_3_w = 0;
	}
	if(_static_array__dynamic_array_synapses_4_w!=0)
	{
		delete [] _static_array__dynamic_array_synapses_4_w;
		_static_array__dynamic_array_synapses_4_w = 0;
	}
	if(_static_array__dynamic_array_synapses_5_w!=0)
	{
		delete [] _static_array__dynamic_array_synapses_5_w;
		_static_array__dynamic_array_synapses_5_w = 0;
	}
	if(_static_array__dynamic_array_synapses_6_w!=0)
	{
		delete [] _static_array__dynamic_array_synapses_6_w;
		_static_array__dynamic_array_synapses_6_w = 0;
	}
	if(_static_array__dynamic_array_synapses_w!=0)
	{
		delete [] _static_array__dynamic_array_synapses_w;
		_static_array__dynamic_array_synapses_w = 0;
	}
}

