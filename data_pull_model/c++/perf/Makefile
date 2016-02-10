#   
#  Copyright 1997 Massachusetts Institute of Technology
# 
#  Permission to use, copy, modify, distribute, and sell this software and
#  its documentation for any purpose is hereby granted without fee, provided
#  that the above copyright notice appear in all copies and that both that
#  copyright notice and this permission notice appear in supporting
#  documentation, and that the name of M.I.T. not be used in advertising or
#  publicity pertaining to distribution of the software without specific,
#  written prior permission.  M.I.T. makes no representations about the
#  suitability of this software for any purpose.  It is provided "as is"
#  without express or implied warranty.
# 

SPECTRA_BASE := ../..
include ../../../Makefile.include

OBJS := $(patsubst %.c,%.o,$(wildcard *.c))
#DEBUG_OBJS := $(patsubst %.c,%.debug.o,$(wildcard *.c))

all: $(OBJS)

world: $(OBJS)

debug: 	all #$(DEBUG_OBJS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $< 

#%.debug.o: %.c %.h
#	$(CC) $(DEBUG_CFLAGS) -c -o $@ $< 

clean: 
	$(RM) *.o
