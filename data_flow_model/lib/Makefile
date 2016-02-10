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

ifneq (,)
This makefile requires GNU Make.
endif

include ../Makefile.include
ROOT = $(SPECTRA_BASE)/lib
ALLDIRS= c++/nasm c++/gsm c++ vrgui fftw include strl/submod strl/src strl/snk strl/i_mod interface 
SUBDIRS= c++ include strl/submod strl/src strl/snk strl/i_mod interface
GSMDIRS= c++/nasm c++/gsm c++ c++/p_mod include strl/submod strl/src strl/snk strl/i_mod interface
all: 
	for i in $(SUBDIRS) ; do cd $$i ; $(MAKE) $@ ; cd $(ROOT) ; done

gsm:
	for i in $(GSMDIRS) ; do cd $$i ; $(MAKE) $@ ; cd $(ROOT) ; done

world:
	for i in $(ALLDIRS) ; do cd $$i ; $(MAKE) $@ ; cd $(ROOT) ; done

gsmclean:
	for i in $(GSMDIRS) ; do cd $$i ; $(MAKE) $@ ; cd $(ROOT) ; done

clean: 
	for i in $(SUBDIRS) ; do cd $$i ; $(MAKE) $@ ; cd $(ROOT) ; done

allclean:
	for i in $(ALLDIRS) ; do cd $$i ; $(MAKE) $@ ; cd $(ROOT) ; done
