#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make 
#
# Build Targets:
#      
#
# Platform Overrides:
#      
#
#------------------------------------------------------------------------------
SOURCES = main.c misc.c
INCLDUES = misc.h
LINKER_FILE = /msp432p4014.lds
PLATFORM = HOST

CC = gcc

LDFLAGS = -Wl,-Map=$(TARGET).map 

CFLAGS = -Wall \
		-Werror \
		-g \
		-O0 \
		-std=c99

CPPFLAGS = -I.$(INCLUDES)



TARGET = main

OBJS = $(SOURCES:.c=.o)		# Object file list

# Generate object files ('-c' -> compile and assemble, but do not link)
%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $^



.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
	size $@

.PHONY: clean
clean:
	rm -f *.i *.d *.asm *.o *.out *.map  






