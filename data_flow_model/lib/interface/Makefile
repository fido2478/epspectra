#
# Copyright 2000, 2001 INRIA
# Permission to use, copy, modify, distribute, and sell this software and
# its documentation for any purpose is hereby granted without fee, provided
# that the above copyright notice appear in all copies and that both that
# copyright notice and this permission notice appear in supporting
# documentation, and that the name of INRIA not be used in advertising or
# publicity pertaining to distribution of the software without specific,
# written prior permission.
#

################################################################
# This is Makefile to compile C++ file as a role in Interface.
################################################################

include ../../Makefile.include 

OBJS := $(patsubst %.cc,%.o,$(wildcard *.cc))
HEADER := $(wildcard *.h)

all : intergsm.o
 
gsm : intergsm.o

world : all

$(OBJS): %.o : %.cc 
	$(G++) -c $< $(GSMOBJS) $(SPECTRA_LIB)  -o $@ $(CFLAGS) $(CCINC)

allclean : clean

gsmclean:clean

clean :
	$(RM) $(EXECS) $(DEBUG_EXECS) *.o
