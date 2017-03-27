PROGRAM = main
SRCS = objects.cpp main.cpp code_objects/synapses_pre_push_spikes.cpp code_objects/synapses_2_pre_initialise_queue.cpp code_objects/synapses_3_pre_initialise_queue.cpp code_objects/neurongroup_resetter_codeobject.cpp code_objects/synapses_pre_codeobject.cpp code_objects/neurongroup_2_resetter_codeobject.cpp code_objects/neurongroup_1_thresholder_codeobject.cpp code_objects/neurongroup_2_thresholder_codeobject.cpp code_objects/synapses_2_pre_codeobject.cpp code_objects/synapses_3_pre_codeobject.cpp code_objects/synapses_1_synapses_create_generator_codeobject.cpp code_objects/synapses_2_pre_push_spikes.cpp code_objects/statemonitor_codeobject.cpp code_objects/synapses_3_pre_push_spikes.cpp code_objects/spikemonitor_codeobject.cpp code_objects/neurongroup_1_resetter_codeobject.cpp code_objects/synapses_2_synapses_create_generator_codeobject.cpp code_objects/neurongroup_thresholder_codeobject.cpp code_objects/synapses_1_pre_push_spikes.cpp code_objects/synapses_synapses_create_generator_codeobject.cpp code_objects/synapses_1_pre_codeobject.cpp code_objects/poissongroup_thresholder_codeobject.cpp code_objects/synapses_3_synapses_create_generator_codeobject.cpp code_objects/synapses_1_pre_initialise_queue.cpp code_objects/synapses_pre_initialise_queue.cpp network.cpp synapses_classes.cpp run.cpp brianlib/randomkit/randomkit.c
H_SRCS = objects.h code_objects/synapses_pre_push_spikes.h code_objects/synapses_2_pre_initialise_queue.h code_objects/synapses_3_pre_initialise_queue.h code_objects/neurongroup_resetter_codeobject.h code_objects/synapses_pre_codeobject.h code_objects/neurongroup_2_resetter_codeobject.h code_objects/neurongroup_1_thresholder_codeobject.h code_objects/neurongroup_2_thresholder_codeobject.h code_objects/synapses_2_pre_codeobject.h code_objects/synapses_3_pre_codeobject.h code_objects/synapses_1_synapses_create_generator_codeobject.h code_objects/synapses_2_pre_push_spikes.h code_objects/statemonitor_codeobject.h code_objects/synapses_3_pre_push_spikes.h code_objects/spikemonitor_codeobject.h code_objects/neurongroup_1_resetter_codeobject.h code_objects/synapses_2_synapses_create_generator_codeobject.h code_objects/neurongroup_thresholder_codeobject.h code_objects/synapses_1_pre_push_spikes.h code_objects/synapses_synapses_create_generator_codeobject.h code_objects/synapses_1_pre_codeobject.h code_objects/poissongroup_thresholder_codeobject.h code_objects/synapses_3_synapses_create_generator_codeobject.h code_objects/synapses_1_pre_initialise_queue.h code_objects/synapses_pre_initialise_queue.h network.h synapses_classes.h run.h brianlib/dynamic_array.h brianlib/common_math.h brianlib/clocks.h
OBJS = ${SRCS:.cpp=.o}
OBJS := ${OBJS:.c=.o}
CC = @g++
DEBUG = -g
OPTIMISATIONS = -Ibrianlib/randomkit -I/home/soe/workspace/sw/anaconda2/include -w -O3 -ffast-math -fno-finite-math-only -march=native
CFLAGS = -c -Wno-write-strings $(OPTIMISATIONS) -I. 
LFLAGS =  -Lbrianlib/randomkit -L/home/soe/workspace/sw/anaconda2/lib
DEPS = make.deps

all: executable

# Adds debug flags
debug: CFLAGS += $(DEBUG)
debug: LFLAGS += $(DEBUG)
debug: executable

.PHONY: all debug executable clean

executable: $(OBJS) $(DEPS)
	$(CC) $(OBJS) -o $(PROGRAM) $(LFLAGS)

clean:
	rm $(OBJS) $(PROGRAM) $(DEPS)

make.deps: $(SRCS) $(H_SRCS)
	$(CC) $(CFLAGS) -MM $(SRCS) > make.deps
	
ifneq ($(wildcard $(DEPS)), )
include $(DEPS)
endif

%.o : %.cpp
	$(CC) $(CFLAGS) $< -o $@