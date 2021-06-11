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
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk



# Compiler Flags and Defines
TARGET = final
PLATFORM = HOST 
GEN_FLAGS = -Wall \
		-g \
		-O0 \
		-std=c99
CC = gcc
LDFLAGS = -Wl,-Map=$(TARGET).map
CFLAGS = $(GEN_FLAGS)
CPPFLAGS = -D$(PLATFORM) $(INCLUDES)






OBJS = $(SOURCES:.c=.o)		# Object file list


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
	rm -f *.i *.d *.asm *.o *.out *.map  


