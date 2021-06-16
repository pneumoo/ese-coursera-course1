#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make all PLATFORM=[PLATFORM] COURSE=COURSE1 VERBOSE=VERBOSE
#
# Build Targets:
#      all .c files 
#
# Platform Overrides:
#      	PLATFORM - is default as 'HOST', but can be 'MSP432'
#	COURSE - is default as 'COURSE1'. No other options.
#	VERBOSE - is default off, but can be turned on by setting as "VERBOSE"
#
#------------------------------------------------------------------------------
include sources.mk

ifndef PLATFORM
PLATFORM=HOST
endif



# Architectures Specific Flags
ifeq ($(PLATFORM),MSP432) # add 'PLATFORM=MSP432" to make command
	LINKER_FILE = ./msp432p401r.lds
	CPU = cortex-m4
	ARCH = thumb
	ARMVER = armv7e-m
	ABI = hard
	FPU = fpv4-sp-d16
	SPECS = nosys.specs
endif



# Compiler Flags and Defines
TARGET = final_assessment
GEN_FLAGS = -Wall \
		-Werror \
		-g \
		-O0 \
		-std=c99


ifeq ($(PLATFORM),HOST)
	CC = gcc
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = $(GEN_FLAGS)
	CPPFLAGS = -D$(PLATFORM) $(INCLUDES)
endif


ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map \
                       -T $(LINKER_FILE) 
	CFLAGS = $(GEN_FLAGS) \
			-mcpu=$(CPU) \
			-m$(ARCH) \
			-march=$(ARMVER) \
			-mfloat-abi=$(ABI) \
			-mfpu=$(FPU) \
			--specs=$(SPECS) 

	CPPFLAGS = -D$(PLATFORM) $(INCLUDES)

endif


ifndef COURSE #add 'COURSE=COURSE1' to make command
CPPFLAGS += -DCOURSE1
endif


ifdef VERBOSE #add 'VERBOSE=VERBOSE' to make command
CPPFLAGS += -DVERBOSE
endif


PPROCS = $(SOURCES:.c=.i)	# Pre-process file list
DEPS = $(SOURCES.c=.d)		# Dependency file list
ASMS = $(SOURCES:.c=.asm)	# Assembly file list
OBJS = $(SOURCES:.c=.o)		# Object file list

# Generate preprocessed files  ('-E' -> Stop after preprocessing stage)
%.i : %.c
	$(CC) -E $(CFLAGS) $(CPPFLAGS) -o $@ $^

# Generate dependency files
%.d : %.c
	$(CC) -M $(CFLAGS) $(CPPFLAGS) -o $@ $^

# Generate assembly files  ('-S' -> stop after compilation proper, do not assemble)
%.asm : %.c
	$(CC) -S $(CFLAGS) $(CPPFLAGS) -o $@ $^ 

# Generate object files ('-c' -> compile and assemble, but do not link)
%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $^




# PHONYS - 
.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
	size $@

.PHONY: clean
clean:
	rm -f ./src/*.i ./src/*.d ./src/*.asm ./src/*.o *.out *.map  


