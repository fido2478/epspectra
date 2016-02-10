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
OBJS := $(patsubst %.cc, %.o, $(wildcard *.cc))
MOCOBJS := moc_VrGUI_int.o
MOCDEBUG_OBJS := moc_VrGUI_int.debug.o

include ../../Makefile.include
INC := -I$(QTDIR)/include $(CCINC)
MOC=moc

I386_OBJS := $(patsubst %.s,%.o,$(wildcard *.s))

ifdef MMX
  MACHDEP_OBJS = $(I386_OBJS)
endif

world:all
all: $(OBJS) $(MACHDEP_OBJS) $(MOCOBJS)

debug:  $(DEBUG_OBJS) $(MACHDEP_OBJS) $(MOCDEBUG_OBJS) 

moc_%.o: %.h
	$(MOC) -o $@.cc $<
	$(G++) -c $(CFLAGS) $(CCINC) -o $@ $@.cc
	$(RM) $@.cc

moc_%.debug.o: %.h
	$(MOC) -o $@.cc $<
	$(CC) -c $(DEBUG_CFLAGS) $(CCINC) -o $@ $@.cc
	$(RM) $@.cc

%.o: %.cc
	$(CC) -c $(CFLAGS) $(CCINC) -o $@ $<

%.debug.o: %.cc %.h
	$(CC) $(DEBUG_CFLAGS) $(CCINC) -c -o $@ $< 

allclean : clean

clean : 
	$(RM) *.o
