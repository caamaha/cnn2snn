
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
const int _num__array_neurongroup_1__spikespace = 5;
int32_t * _array_neurongroup_1_i;
const int _num__array_neurongroup_1_i = 4;
double * _array_neurongroup_1_v;
const int _num__array_neurongroup_1_v = 4;
int32_t * _array_neurongroup_2__spikespace;
const int _num__array_neurongroup_2__spikespace = 2;
int32_t * _array_neurongroup_2_i;
const int _num__array_neurongroup_2_i = 1;
double * _array_neurongroup_2_v;
const int _num__array_neurongroup_2_v = 1;
int32_t * _array_neurongroup__spikespace;
const int _num__array_neurongroup__spikespace = 2;
int32_t * _array_neurongroup_i;
const int _num__array_neurongroup_i = 1;
double * _array_neurongroup_v;
const int _num__array_neurongroup_v = 1;
int32_t * _array_poissongroup__spikespace;
const int _num__array_poissongroup__spikespace = 5;
int32_t * _array_poissongroup_i;
const int _num__array_poissongroup_i = 4;
double * _array_poissongroup_rates;
const int _num__array_poissongroup_rates = 4;
int32_t * _array_spikemonitor__source_idx;
const int _num__array_spikemonitor__source_idx = 1;
int32_t * _array_spikemonitor_count;
const int _num__array_spikemonitor_count = 1;
int32_t * _array_spikemonitor_N;
const int _num__array_spikemonitor_N = 1;
int32_t * _array_statemonitor__indices;
const int _num__array_statemonitor__indices = 4;
int32_t * _array_statemonitor_N;
const int _num__array_statemonitor_N = 1;
double * _array_statemonitor_v;
const int _num__array_statemonitor_v = (0, 4);
int32_t * _array_synapses_1_N;
const int _num__array_synapses_1_N = 1;
int32_t * _array_synapses_2_N;
const int _num__array_synapses_2_N = 1;
int32_t * _array_synapses_3_N;
const int _num__array_synapses_3_N = 1;
int32_t * _array_synapses_N;
const int _num__array_synapses_N = 1;

//////////////// dynamic arrays 1d /////////
std::vector<int32_t> _dynamic_array_spikemonitor_i;
std::vector<double> _dynamic_array_spikemonitor_t;
std::vector<double> _dynamic_array_statemonitor_t;
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
std::vector<int32_t> _dynamic_array_synapses__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses__synaptic_pre;
std::vector<double> _dynamic_array_synapses_delay;
std::vector<double> _dynamic_array_synapses_lastupdate;
std::vector<int32_t> _dynamic_array_synapses_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_N_outgoing;
std::vector<double> _dynamic_array_synapses_w;

//////////////// dynamic arrays 2d /////////
DynamicArray2D<double> _dynamic_array_statemonitor_v;

/////////////// static arrays /////////////
double * _static_array__array_poissongroup_rates;
const int _num__static_array__array_poissongroup_rates = 4;
int32_t * _static_array__array_statemonitor__indices;
const int _num__static_array__array_statemonitor__indices = 4;

//////////////// synapses /////////////////
// synapses
SynapticPathway<double> synapses_pre(
		_dynamic_array_synapses_delay,
		_dynamic_array_synapses__synaptic_pre,
		0, 4);
// synapses_1
SynapticPathway<double> synapses_1_pre(
		_dynamic_array_synapses_1_delay,
		_dynamic_array_synapses_1__synaptic_pre,
		0, 4);
// synapses_2
SynapticPathway<double> synapses_2_pre(
		_dynamic_array_synapses_2_delay,
		_dynamic_array_synapses_2__synaptic_pre,
		0, 1);
// synapses_3
SynapticPathway<double> synapses_3_pre(
		_dynamic_array_synapses_3_delay,
		_dynamic_array_synapses_3__synaptic_pre,
		0, 4);

//////////////// clocks ///////////////////
Clock defaultclock;  // attributes will be set in run.cpp

// Profiling information for each code object
double neurongroup_1_resetter_codeobject_profiling_info = 0.0;
double neurongroup_1_thresholder_codeobject_profiling_info = 0.0;
double neurongroup_2_resetter_codeobject_profiling_info = 0.0;
double neurongroup_2_thresholder_codeobject_profiling_info = 0.0;
double neurongroup_resetter_codeobject_profiling_info = 0.0;
double neurongroup_thresholder_codeobject_profiling_info = 0.0;
double poissongroup_thresholder_codeobject_profiling_info = 0.0;
double spikemonitor_codeobject_profiling_info = 0.0;
double statemonitor_codeobject_profiling_info = 0.0;
double synapses_1_pre_codeobject_profiling_info = 0.0;
double synapses_1_pre_initialise_queue_profiling_info = 0.0;
double synapses_1_pre_push_spikes_profiling_info = 0.0;
double synapses_1_synapses_create_generator_codeobject_profiling_info = 0.0;
double synapses_2_pre_codeobject_profiling_info = 0.0;
double synapses_2_pre_initialise_queue_profiling_info = 0.0;
double synapses_2_pre_push_spikes_profiling_info = 0.0;
double synapses_2_synapses_create_generator_codeobject_profiling_info = 0.0;
double synapses_3_pre_codeobject_profiling_info = 0.0;
double synapses_3_pre_initialise_queue_profiling_info = 0.0;
double synapses_3_pre_push_spikes_profiling_info = 0.0;
double synapses_3_synapses_create_generator_codeobject_profiling_info = 0.0;
double synapses_pre_codeobject_profiling_info = 0.0;
double synapses_pre_initialise_queue_profiling_info = 0.0;
double synapses_pre_push_spikes_profiling_info = 0.0;
double synapses_synapses_create_generator_codeobject_profiling_info = 0.0;

}

void _init_arrays()
{
	using namespace brian;

    // Arrays initialized to 0
	_array_statemonitor__indices = new int32_t[4];
	
	for(int i=0; i<4; i++) _array_statemonitor__indices[i] = 0;
	_array_spikemonitor__source_idx = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_spikemonitor__source_idx[i] = 0;
	_array_poissongroup__spikespace = new int32_t[5];
	
	for(int i=0; i<5; i++) _array_poissongroup__spikespace[i] = 0;
	_array_neurongroup__spikespace = new int32_t[2];
	
	for(int i=0; i<2; i++) _array_neurongroup__spikespace[i] = 0;
	_array_neurongroup_1__spikespace = new int32_t[5];
	
	for(int i=0; i<5; i++) _array_neurongroup_1__spikespace[i] = 0;
	_array_neurongroup_2__spikespace = new int32_t[2];
	
	for(int i=0; i<2; i++) _array_neurongroup_2__spikespace[i] = 0;
	_array_spikemonitor_count = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_spikemonitor_count[i] = 0;
	_dynamic_array_synapses_delay.resize(1);
	
	for(int i=0; i<1; i++) _dynamic_array_synapses_delay[i] = 0;
	_dynamic_array_synapses_1_delay.resize(1);
	
	for(int i=0; i<1; i++) _dynamic_array_synapses_1_delay[i] = 0;
	_dynamic_array_synapses_2_delay.resize(1);
	
	for(int i=0; i<1; i++) _dynamic_array_synapses_2_delay[i] = 0;
	_dynamic_array_synapses_3_delay.resize(1);
	
	for(int i=0; i<1; i++) _dynamic_array_synapses_3_delay[i] = 0;
	_array_defaultclock_dt = new double[1];
	
	for(int i=0; i<1; i++) _array_defaultclock_dt[i] = 0;
	_array_poissongroup_i = new int32_t[4];
	
	for(int i=0; i<4; i++) _array_poissongroup_i[i] = 0;
	_array_neurongroup_i = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_neurongroup_i[i] = 0;
	_array_neurongroup_1_i = new int32_t[4];
	
	for(int i=0; i<4; i++) _array_neurongroup_1_i[i] = 0;
	_array_neurongroup_2_i = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_neurongroup_2_i[i] = 0;
	_array_synapses_N = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_synapses_N[i] = 0;
	_array_synapses_1_N = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_synapses_1_N[i] = 0;
	_array_synapses_2_N = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_synapses_2_N[i] = 0;
	_array_synapses_3_N = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_synapses_3_N[i] = 0;
	_array_spikemonitor_N = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_spikemonitor_N[i] = 0;
	_array_statemonitor_N = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_statemonitor_N[i] = 0;
	_array_poissongroup_rates = new double[4];
	
	for(int i=0; i<4; i++) _array_poissongroup_rates[i] = 0;
	_array_defaultclock_t = new double[1];
	
	for(int i=0; i<1; i++) _array_defaultclock_t[i] = 0;
	_array_defaultclock_timestep = new uint64_t[1];
	
	for(int i=0; i<1; i++) _array_defaultclock_timestep[i] = 0;
	_array_neurongroup_v = new double[1];
	
	for(int i=0; i<1; i++) _array_neurongroup_v[i] = 0;
	_array_neurongroup_1_v = new double[4];
	
	for(int i=0; i<4; i++) _array_neurongroup_1_v[i] = 0;
	_array_neurongroup_2_v = new double[1];
	
	for(int i=0; i<1; i++) _array_neurongroup_2_v[i] = 0;

	// Arrays initialized to an "arange"
	_array_spikemonitor__source_idx = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_spikemonitor__source_idx[i] = 0 + i;
	_array_neurongroup_i = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_neurongroup_i[i] = 0 + i;
	_array_poissongroup_i = new int32_t[4];
	
	for(int i=0; i<4; i++) _array_poissongroup_i[i] = 0 + i;
	_array_neurongroup_2_i = new int32_t[1];
	
	for(int i=0; i<1; i++) _array_neurongroup_2_i[i] = 0 + i;
	_array_neurongroup_1_i = new int32_t[4];
	
	for(int i=0; i<4; i++) _array_neurongroup_1_i[i] = 0 + i;

	// static arrays
	_static_array__array_poissongroup_rates = new double[4];
	_static_array__array_statemonitor__indices = new int32_t[4];

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
		f_static_array__array_poissongroup_rates.read(reinterpret_cast<char*>(_static_array__array_poissongroup_rates), 4*sizeof(double));
	} else
	{
		std::cout << "Error opening static array _static_array__array_poissongroup_rates." << endl;
	}
	ifstream f_static_array__array_statemonitor__indices;
	f_static_array__array_statemonitor__indices.open("static_arrays/_static_array__array_statemonitor__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor__indices.is_open())
	{
		f_static_array__array_statemonitor__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor__indices), 4*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor__indices." << endl;
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
		outfile__array_neurongroup_1__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_1__spikespace), 5*sizeof(_array_neurongroup_1__spikespace[0]));
		outfile__array_neurongroup_1__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_1_i;
	outfile__array_neurongroup_1_i.open("results/_array_neurongroup_1_i_6263110221643836299", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_i.is_open())
	{
		outfile__array_neurongroup_1_i.write(reinterpret_cast<char*>(_array_neurongroup_1_i), 4*sizeof(_array_neurongroup_1_i[0]));
		outfile__array_neurongroup_1_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_i." << endl;
	}
	ofstream outfile__array_neurongroup_1_v;
	outfile__array_neurongroup_1_v.open("results/_array_neurongroup_1_v_6263110221643836308", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_v.is_open())
	{
		outfile__array_neurongroup_1_v.write(reinterpret_cast<char*>(_array_neurongroup_1_v), 4*sizeof(_array_neurongroup_1_v[0]));
		outfile__array_neurongroup_1_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_v." << endl;
	}
	ofstream outfile__array_neurongroup_2__spikespace;
	outfile__array_neurongroup_2__spikespace.open("results/_array_neurongroup_2__spikespace_-7436586474334848428", ios::binary | ios::out);
	if(outfile__array_neurongroup_2__spikespace.is_open())
	{
		outfile__array_neurongroup_2__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_2__spikespace), 2*sizeof(_array_neurongroup_2__spikespace[0]));
		outfile__array_neurongroup_2__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_2__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_2_i;
	outfile__array_neurongroup_2_i.open("results/_array_neurongroup_2_i_6263111221515835924", ios::binary | ios::out);
	if(outfile__array_neurongroup_2_i.is_open())
	{
		outfile__array_neurongroup_2_i.write(reinterpret_cast<char*>(_array_neurongroup_2_i), 1*sizeof(_array_neurongroup_2_i[0]));
		outfile__array_neurongroup_2_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_2_i." << endl;
	}
	ofstream outfile__array_neurongroup_2_v;
	outfile__array_neurongroup_2_v.open("results/_array_neurongroup_2_v_6263111221515835915", ios::binary | ios::out);
	if(outfile__array_neurongroup_2_v.is_open())
	{
		outfile__array_neurongroup_2_v.write(reinterpret_cast<char*>(_array_neurongroup_2_v), 1*sizeof(_array_neurongroup_2_v[0]));
		outfile__array_neurongroup_2_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_2_v." << endl;
	}
	ofstream outfile__array_neurongroup__spikespace;
	outfile__array_neurongroup__spikespace.open("results/_array_neurongroup__spikespace_6291509255835556833", ios::binary | ios::out);
	if(outfile__array_neurongroup__spikespace.is_open())
	{
		outfile__array_neurongroup__spikespace.write(reinterpret_cast<char*>(_array_neurongroup__spikespace), 2*sizeof(_array_neurongroup__spikespace[0]));
		outfile__array_neurongroup__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_i;
	outfile__array_neurongroup_i.open("results/_array_neurongroup_i_-2688036259655650195", ios::binary | ios::out);
	if(outfile__array_neurongroup_i.is_open())
	{
		outfile__array_neurongroup_i.write(reinterpret_cast<char*>(_array_neurongroup_i), 1*sizeof(_array_neurongroup_i[0]));
		outfile__array_neurongroup_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_i." << endl;
	}
	ofstream outfile__array_neurongroup_v;
	outfile__array_neurongroup_v.open("results/_array_neurongroup_v_-2688036259655650190", ios::binary | ios::out);
	if(outfile__array_neurongroup_v.is_open())
	{
		outfile__array_neurongroup_v.write(reinterpret_cast<char*>(_array_neurongroup_v), 1*sizeof(_array_neurongroup_v[0]));
		outfile__array_neurongroup_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_v." << endl;
	}
	ofstream outfile__array_poissongroup__spikespace;
	outfile__array_poissongroup__spikespace.open("results/_array_poissongroup__spikespace_-4364673061333452130", ios::binary | ios::out);
	if(outfile__array_poissongroup__spikespace.is_open())
	{
		outfile__array_poissongroup__spikespace.write(reinterpret_cast<char*>(_array_poissongroup__spikespace), 5*sizeof(_array_poissongroup__spikespace[0]));
		outfile__array_poissongroup__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_poissongroup__spikespace." << endl;
	}
	ofstream outfile__array_poissongroup_i;
	outfile__array_poissongroup_i.open("results/_array_poissongroup_i_2968481286923345034", ios::binary | ios::out);
	if(outfile__array_poissongroup_i.is_open())
	{
		outfile__array_poissongroup_i.write(reinterpret_cast<char*>(_array_poissongroup_i), 4*sizeof(_array_poissongroup_i[0]));
		outfile__array_poissongroup_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_poissongroup_i." << endl;
	}
	ofstream outfile__array_poissongroup_rates;
	outfile__array_poissongroup_rates.open("results/_array_poissongroup_rates_6241245451607672350", ios::binary | ios::out);
	if(outfile__array_poissongroup_rates.is_open())
	{
		outfile__array_poissongroup_rates.write(reinterpret_cast<char*>(_array_poissongroup_rates), 4*sizeof(_array_poissongroup_rates[0]));
		outfile__array_poissongroup_rates.close();
	} else
	{
		std::cout << "Error writing output file for _array_poissongroup_rates." << endl;
	}
	ofstream outfile__array_spikemonitor__source_idx;
	outfile__array_spikemonitor__source_idx.open("results/_array_spikemonitor__source_idx_-4045852888739339153", ios::binary | ios::out);
	if(outfile__array_spikemonitor__source_idx.is_open())
	{
		outfile__array_spikemonitor__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor__source_idx), 1*sizeof(_array_spikemonitor__source_idx[0]));
		outfile__array_spikemonitor__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_count;
	outfile__array_spikemonitor_count.open("results/_array_spikemonitor_count_-3651895352503201284", ios::binary | ios::out);
	if(outfile__array_spikemonitor_count.is_open())
	{
		outfile__array_spikemonitor_count.write(reinterpret_cast<char*>(_array_spikemonitor_count), 1*sizeof(_array_spikemonitor_count[0]));
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
	ofstream outfile__array_statemonitor__indices;
	outfile__array_statemonitor__indices.open("results/_array_statemonitor__indices_6163485638831984707", ios::binary | ios::out);
	if(outfile__array_statemonitor__indices.is_open())
	{
		outfile__array_statemonitor__indices.write(reinterpret_cast<char*>(_array_statemonitor__indices), 4*sizeof(_array_statemonitor__indices[0]));
		outfile__array_statemonitor__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor__indices." << endl;
	}
	ofstream outfile__array_statemonitor_N;
	outfile__array_statemonitor_N.open("results/_array_statemonitor_N_1126150466128921572", ios::binary | ios::out);
	if(outfile__array_statemonitor_N.is_open())
	{
		outfile__array_statemonitor_N.write(reinterpret_cast<char*>(_array_statemonitor_N), 1*sizeof(_array_statemonitor_N[0]));
		outfile__array_statemonitor_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_N." << endl;
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
	ofstream outfile__dynamic_array_statemonitor_t;
	outfile__dynamic_array_statemonitor_t.open("results/_dynamic_array_statemonitor_t_6620044162385838772", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_t.is_open())
	{
        if (! _dynamic_array_statemonitor_t.empty() )
        {
			outfile__dynamic_array_statemonitor_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_t[0]), _dynamic_array_statemonitor_t.size()*sizeof(_dynamic_array_statemonitor_t[0]));
		    outfile__dynamic_array_statemonitor_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_t." << endl;
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

	ofstream outfile__dynamic_array_statemonitor_v;
	outfile__dynamic_array_statemonitor_v.open("results/_dynamic_array_statemonitor_v_6620044162385838774", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_v.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_v.n; n++)
        {
            if (! _dynamic_array_statemonitor_v(n).empty())
            {
                outfile__dynamic_array_statemonitor_v.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_v(n, 0)), _dynamic_array_statemonitor_v.m*sizeof(_dynamic_array_statemonitor_v(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_v.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_v." << endl;
	}

	// Write profiling info to disk
	ofstream outfile_profiling_info;
	outfile_profiling_info.open("results/profiling_info.txt", ios::out);
	if(outfile_profiling_info.is_open())
	{
	outfile_profiling_info << "neurongroup_1_resetter_codeobject\t" << neurongroup_1_resetter_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_1_thresholder_codeobject\t" << neurongroup_1_thresholder_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_2_resetter_codeobject\t" << neurongroup_2_resetter_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_2_thresholder_codeobject\t" << neurongroup_2_thresholder_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_resetter_codeobject\t" << neurongroup_resetter_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "neurongroup_thresholder_codeobject\t" << neurongroup_thresholder_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "poissongroup_thresholder_codeobject\t" << poissongroup_thresholder_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "spikemonitor_codeobject\t" << spikemonitor_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "statemonitor_codeobject\t" << statemonitor_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_1_pre_codeobject\t" << synapses_1_pre_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_1_pre_initialise_queue\t" << synapses_1_pre_initialise_queue_profiling_info << std::endl;
	outfile_profiling_info << "synapses_1_pre_push_spikes\t" << synapses_1_pre_push_spikes_profiling_info << std::endl;
	outfile_profiling_info << "synapses_1_synapses_create_generator_codeobject\t" << synapses_1_synapses_create_generator_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_2_pre_codeobject\t" << synapses_2_pre_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_2_pre_initialise_queue\t" << synapses_2_pre_initialise_queue_profiling_info << std::endl;
	outfile_profiling_info << "synapses_2_pre_push_spikes\t" << synapses_2_pre_push_spikes_profiling_info << std::endl;
	outfile_profiling_info << "synapses_2_synapses_create_generator_codeobject\t" << synapses_2_synapses_create_generator_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_3_pre_codeobject\t" << synapses_3_pre_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_3_pre_initialise_queue\t" << synapses_3_pre_initialise_queue_profiling_info << std::endl;
	outfile_profiling_info << "synapses_3_pre_push_spikes\t" << synapses_3_pre_push_spikes_profiling_info << std::endl;
	outfile_profiling_info << "synapses_3_synapses_create_generator_codeobject\t" << synapses_3_synapses_create_generator_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_pre_codeobject\t" << synapses_pre_codeobject_profiling_info << std::endl;
	outfile_profiling_info << "synapses_pre_initialise_queue\t" << synapses_pre_initialise_queue_profiling_info << std::endl;
	outfile_profiling_info << "synapses_pre_push_spikes\t" << synapses_pre_push_spikes_profiling_info << std::endl;
	outfile_profiling_info << "synapses_synapses_create_generator_codeobject\t" << synapses_synapses_create_generator_codeobject_profiling_info << std::endl;
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
	if(_static_array__array_statemonitor__indices!=0)
	{
		delete [] _static_array__array_statemonitor__indices;
		_static_array__array_statemonitor__indices = 0;
	}
}

