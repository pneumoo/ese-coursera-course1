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
# Simple makefile for the cortex-M0+ build system
#
# Use: make [TARGET] [OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated files
#
# Overrides:
#      CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      ARCH - ARM Architecture (arm, thumb)
#      SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#
#------------------------------------------------------------------------------
SOURCES = main.c misc.c
INCLDUES = misc.h

# Architecture Specific Flags
CPU = cortex-m0plus
ARCH = thumb
SPECS = nosys.specs

# Platform Specific Flags
LINKER_FILE = msp432p401r.lds

# Compile Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
TARGET = demo
LDFLAGS = -Wl,-Map=main.map -T $(LINKER_FILE)
CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall
CPPFLAGS = -I.$(INCLUDES)

OBJS = $(SOURCES:.c=.o)

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map

