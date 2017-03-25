
#ifndef _BRIAN_OBJECTS_H
#define _BRIAN_OBJECTS_H

#include "synapses_classes.h"
#include "brianlib/clocks.h"
#include "brianlib/dynamic_array.h"
#include "brianlib/stdint_compat.h"
#include "network.h"
#include "randomkit.h"
#include<vector>


namespace brian {

// In OpenMP we need one state per thread
extern std::vector< rk_state* > _mersenne_twister_states;

//////////////// clocks ///////////////////
extern Clock defaultclock;

//////////////// networks /////////////////
extern Network magicnetwork;
extern Network magicnetwork;

//////////////// dynamic arrays ///////////
extern std::vector<int32_t> _dynamic_array_spikemonitor_i;
extern std::vector<double> _dynamic_array_spikemonitor_t;
extern std::vector<int32_t> _dynamic_array_synapses_1__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_1__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_1_delay;
extern std::vector<double> _dynamic_array_synapses_1_lastupdate;
extern std::vector<int32_t> _dynamic_array_synapses_1_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_1_N_outgoing;
extern std::vector<double> _dynamic_array_synapses_1_w;
extern std::vector<int32_t> _dynamic_array_synapses_2__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_2__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_2_delay;
extern std::vector<double> _dynamic_array_synapses_2_lastupdate;
extern std::vector<int32_t> _dynamic_array_synapses_2_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_2_N_outgoing;
extern std::vector<double> _dynamic_array_synapses_2_w;
extern std::vector<int32_t> _dynamic_array_synapses_3__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_3__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_3_delay;
extern std::vector<double> _dynamic_array_synapses_3_lastupdate;
extern std::vector<int32_t> _dynamic_array_synapses_3_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_3_N_outgoing;
extern std::vector<double> _dynamic_array_synapses_3_w;
extern std::vector<int32_t> _dynamic_array_synapses_4__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_4__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_4_delay;
extern std::vector<double> _dynamic_array_synapses_4_lastupdate;
extern std::vector<int32_t> _dynamic_array_synapses_4_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_4_N_outgoing;
extern std::vector<double> _dynamic_array_synapses_4_w;
extern std::vector<int32_t> _dynamic_array_synapses_5__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_5__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_5_delay;
extern std::vector<double> _dynamic_array_synapses_5_lastupdate;
extern std::vector<int32_t> _dynamic_array_synapses_5_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_5_N_outgoing;
extern std::vector<double> _dynamic_array_synapses_5_w;
extern std::vector<int32_t> _dynamic_array_synapses_6__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_6__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_6_delay;
extern std::vector<double> _dynamic_array_synapses_6_lastupdate;
extern std::vector<int32_t> _dynamic_array_synapses_6_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_6_N_outgoing;
extern std::vector<double> _dynamic_array_synapses_6_w;
extern std::vector<int32_t> _dynamic_array_synapses__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_delay;
extern std::vector<double> _dynamic_array_synapses_lastupdate;
extern std::vector<int32_t> _dynamic_array_synapses_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_N_outgoing;
extern std::vector<double> _dynamic_array_synapses_w;

//////////////// arrays ///////////////////
extern double *_array_defaultclock_dt;
extern const int _num__array_defaultclock_dt;
extern double *_array_defaultclock_t;
extern const int _num__array_defaultclock_t;
extern uint64_t *_array_defaultclock_timestep;
extern const int _num__array_defaultclock_timestep;
extern int32_t *_array_neurongroup_1__spikespace;
extern const int _num__array_neurongroup_1__spikespace;
extern int32_t *_array_neurongroup_1__underspace;
extern const int _num__array_neurongroup_1__underspace;
extern int32_t *_array_neurongroup_1_i;
extern const int _num__array_neurongroup_1_i;
extern double *_array_neurongroup_1_v;
extern const int _num__array_neurongroup_1_v;
extern int32_t *_array_neurongroup_2__spikespace;
extern const int _num__array_neurongroup_2__spikespace;
extern int32_t *_array_neurongroup_2__underspace;
extern const int _num__array_neurongroup_2__underspace;
extern int32_t *_array_neurongroup_2_i;
extern const int _num__array_neurongroup_2_i;
extern double *_array_neurongroup_2_v;
extern const int _num__array_neurongroup_2_v;
extern int32_t *_array_neurongroup_3__spikespace;
extern const int _num__array_neurongroup_3__spikespace;
extern int32_t *_array_neurongroup_3__underspace;
extern const int _num__array_neurongroup_3__underspace;
extern int32_t *_array_neurongroup_3_i;
extern const int _num__array_neurongroup_3_i;
extern double *_array_neurongroup_3_v;
extern const int _num__array_neurongroup_3_v;
extern int32_t *_array_neurongroup_4__spikespace;
extern const int _num__array_neurongroup_4__spikespace;
extern int32_t *_array_neurongroup_4_i;
extern const int _num__array_neurongroup_4_i;
extern double *_array_neurongroup_4_v;
extern const int _num__array_neurongroup_4_v;
extern int32_t *_array_neurongroup_5__spikespace;
extern const int _num__array_neurongroup_5__spikespace;
extern int32_t *_array_neurongroup_5_i;
extern const int _num__array_neurongroup_5_i;
extern double *_array_neurongroup_5_v;
extern const int _num__array_neurongroup_5_v;
extern int32_t *_array_neurongroup_6__spikespace;
extern const int _num__array_neurongroup_6__spikespace;
extern int32_t *_array_neurongroup_6_i;
extern const int _num__array_neurongroup_6_i;
extern double *_array_neurongroup_6_v;
extern const int _num__array_neurongroup_6_v;
extern int32_t *_array_neurongroup__spikespace;
extern const int _num__array_neurongroup__spikespace;
extern int32_t *_array_neurongroup__underspace;
extern const int _num__array_neurongroup__underspace;
extern int32_t *_array_neurongroup_i;
extern const int _num__array_neurongroup_i;
extern double *_array_neurongroup_v;
extern const int _num__array_neurongroup_v;
extern int32_t *_array_poissongroup__spikespace;
extern const int _num__array_poissongroup__spikespace;
extern int32_t *_array_poissongroup_i;
extern const int _num__array_poissongroup_i;
extern double *_array_poissongroup_rates;
extern const int _num__array_poissongroup_rates;
extern int32_t *_array_spikemonitor__source_idx;
extern const int _num__array_spikemonitor__source_idx;
extern int32_t *_array_spikemonitor_count;
extern const int _num__array_spikemonitor_count;
extern int32_t *_array_spikemonitor_N;
extern const int _num__array_spikemonitor_N;
extern int32_t *_array_synapses_1_N;
extern const int _num__array_synapses_1_N;
extern int32_t *_array_synapses_1_sources;
extern const int _num__array_synapses_1_sources;
extern int32_t *_array_synapses_1_targets;
extern const int _num__array_synapses_1_targets;
extern int32_t *_array_synapses_2_N;
extern const int _num__array_synapses_2_N;
extern int32_t *_array_synapses_2_sources;
extern const int _num__array_synapses_2_sources;
extern int32_t *_array_synapses_2_targets;
extern const int _num__array_synapses_2_targets;
extern int32_t *_array_synapses_3_N;
extern const int _num__array_synapses_3_N;
extern int32_t *_array_synapses_3_sources;
extern const int _num__array_synapses_3_sources;
extern int32_t *_array_synapses_3_targets;
extern const int _num__array_synapses_3_targets;
extern int32_t *_array_synapses_4_N;
extern const int _num__array_synapses_4_N;
extern int32_t *_array_synapses_4_sources;
extern const int _num__array_synapses_4_sources;
extern int32_t *_array_synapses_4_targets;
extern const int _num__array_synapses_4_targets;
extern int32_t *_array_synapses_5_N;
extern const int _num__array_synapses_5_N;
extern int32_t *_array_synapses_5_sources;
extern const int _num__array_synapses_5_sources;
extern int32_t *_array_synapses_5_targets;
extern const int _num__array_synapses_5_targets;
extern int32_t *_array_synapses_6_N;
extern const int _num__array_synapses_6_N;
extern int32_t *_array_synapses_6_sources;
extern const int _num__array_synapses_6_sources;
extern int32_t *_array_synapses_6_targets;
extern const int _num__array_synapses_6_targets;
extern int32_t *_array_synapses_N;
extern const int _num__array_synapses_N;
extern int32_t *_array_synapses_sources;
extern const int _num__array_synapses_sources;
extern int32_t *_array_synapses_targets;
extern const int _num__array_synapses_targets;

//////////////// dynamic arrays 2d /////////

/////////////// static arrays /////////////
extern double *_static_array__array_poissongroup_rates;
extern const int _num__static_array__array_poissongroup_rates;
extern int32_t *_static_array__array_synapses_1_sources;
extern const int _num__static_array__array_synapses_1_sources;
extern int32_t *_static_array__array_synapses_1_targets;
extern const int _num__static_array__array_synapses_1_targets;
extern int32_t *_static_array__array_synapses_2_sources;
extern const int _num__static_array__array_synapses_2_sources;
extern int32_t *_static_array__array_synapses_2_targets;
extern const int _num__static_array__array_synapses_2_targets;
extern int32_t *_static_array__array_synapses_3_sources;
extern const int _num__static_array__array_synapses_3_sources;
extern int32_t *_static_array__array_synapses_3_targets;
extern const int _num__static_array__array_synapses_3_targets;
extern int32_t *_static_array__array_synapses_4_sources;
extern const int _num__static_array__array_synapses_4_sources;
extern int32_t *_static_array__array_synapses_4_targets;
extern const int _num__static_array__array_synapses_4_targets;
extern int32_t *_static_array__array_synapses_5_sources;
extern const int _num__static_array__array_synapses_5_sources;
extern int32_t *_static_array__array_synapses_5_targets;
extern const int _num__static_array__array_synapses_5_targets;
extern int32_t *_static_array__array_synapses_6_sources;
extern const int _num__static_array__array_synapses_6_sources;
extern int32_t *_static_array__array_synapses_6_targets;
extern const int _num__static_array__array_synapses_6_targets;
extern int32_t *_static_array__array_synapses_sources;
extern const int _num__static_array__array_synapses_sources;
extern int32_t *_static_array__array_synapses_targets;
extern const int _num__static_array__array_synapses_targets;
extern double *_static_array__dynamic_array_synapses_1_w;
extern const int _num__static_array__dynamic_array_synapses_1_w;
extern float *_static_array__dynamic_array_synapses_2_w;
extern const int _num__static_array__dynamic_array_synapses_2_w;
extern double *_static_array__dynamic_array_synapses_3_w;
extern const int _num__static_array__dynamic_array_synapses_3_w;
extern float *_static_array__dynamic_array_synapses_4_w;
extern const int _num__static_array__dynamic_array_synapses_4_w;
extern float *_static_array__dynamic_array_synapses_5_w;
extern const int _num__static_array__dynamic_array_synapses_5_w;
extern float *_static_array__dynamic_array_synapses_6_w;
extern const int _num__static_array__dynamic_array_synapses_6_w;
extern float *_static_array__dynamic_array_synapses_w;
extern const int _num__static_array__dynamic_array_synapses_w;

//////////////// synapses /////////////////
// synapses
extern SynapticPathway<double> synapses_pre;
// synapses_1
extern SynapticPathway<double> synapses_1_pre;
// synapses_2
extern SynapticPathway<double> synapses_2_pre;
// synapses_3
extern SynapticPathway<double> synapses_3_pre;
// synapses_4
extern SynapticPathway<double> synapses_4_pre;
// synapses_5
extern SynapticPathway<double> synapses_5_pre;
// synapses_6
extern SynapticPathway<double> synapses_6_pre;

// Profiling information for each code object
extern double neurongroup_1_resetter_1_codeobject_profiling_info;
extern double neurongroup_1_resetter_codeobject_profiling_info;
extern double neurongroup_1_thresholder_1_codeobject_profiling_info;
extern double neurongroup_1_thresholder_codeobject_profiling_info;
extern double neurongroup_2_resetter_1_codeobject_profiling_info;
extern double neurongroup_2_resetter_codeobject_profiling_info;
extern double neurongroup_2_thresholder_1_codeobject_profiling_info;
extern double neurongroup_2_thresholder_codeobject_profiling_info;
extern double neurongroup_3_resetter_1_codeobject_profiling_info;
extern double neurongroup_3_resetter_codeobject_profiling_info;
extern double neurongroup_3_thresholder_1_codeobject_profiling_info;
extern double neurongroup_3_thresholder_codeobject_profiling_info;
extern double neurongroup_4_resetter_codeobject_profiling_info;
extern double neurongroup_4_thresholder_codeobject_profiling_info;
extern double neurongroup_5_resetter_codeobject_profiling_info;
extern double neurongroup_5_thresholder_codeobject_profiling_info;
extern double neurongroup_6_resetter_codeobject_profiling_info;
extern double neurongroup_6_thresholder_codeobject_profiling_info;
extern double neurongroup_resetter_1_codeobject_profiling_info;
extern double neurongroup_resetter_codeobject_profiling_info;
extern double neurongroup_thresholder_1_codeobject_profiling_info;
extern double neurongroup_thresholder_codeobject_profiling_info;
extern double poissongroup_thresholder_codeobject_profiling_info;
extern double spikemonitor_codeobject_profiling_info;
extern double synapses_1_pre_codeobject_profiling_info;
extern double synapses_1_pre_initialise_queue_profiling_info;
extern double synapses_1_pre_push_spikes_profiling_info;
extern double synapses_1_synapses_create_array_codeobject_profiling_info;
extern double synapses_2_pre_codeobject_profiling_info;
extern double synapses_2_pre_initialise_queue_profiling_info;
extern double synapses_2_pre_push_spikes_profiling_info;
extern double synapses_2_synapses_create_array_codeobject_profiling_info;
extern double synapses_3_pre_codeobject_profiling_info;
extern double synapses_3_pre_initialise_queue_profiling_info;
extern double synapses_3_pre_push_spikes_profiling_info;
extern double synapses_3_synapses_create_array_codeobject_profiling_info;
extern double synapses_4_pre_codeobject_profiling_info;
extern double synapses_4_pre_initialise_queue_profiling_info;
extern double synapses_4_pre_push_spikes_profiling_info;
extern double synapses_4_synapses_create_array_codeobject_profiling_info;
extern double synapses_5_pre_codeobject_profiling_info;
extern double synapses_5_pre_initialise_queue_profiling_info;
extern double synapses_5_pre_push_spikes_profiling_info;
extern double synapses_5_synapses_create_array_codeobject_profiling_info;
extern double synapses_6_pre_codeobject_profiling_info;
extern double synapses_6_pre_initialise_queue_profiling_info;
extern double synapses_6_pre_push_spikes_profiling_info;
extern double synapses_6_synapses_create_array_codeobject_profiling_info;
extern double synapses_pre_codeobject_profiling_info;
extern double synapses_pre_initialise_queue_profiling_info;
extern double synapses_pre_push_spikes_profiling_info;
extern double synapses_synapses_create_array_codeobject_profiling_info;

}

void _init_arrays();
void _load_arrays();
void _write_arrays();
void _dealloc_arrays();

#endif


