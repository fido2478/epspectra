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
# This is Makefile to compile C file for esterel.
################################################################

include ../../../Makefile.include

OBJ4STRL := $(patsubst %_data.c, %_data.o, $(wildcard *_data.c))
C4STRL := $(wildcard *_data.c)
HEADER := $(wildcard *.h)

all   : world

gsm   : world

Not_Dup_Opt:
	$(ESTEREL_V603) -sub -sc -B COMP_DATA COMP_DATA.strl
	$(AREAOPT) COMP_DATA_d
	$(BLIFSC_V603) -ctbl COMP_DATA.ctbl \
	-sblif COMP_DATA_s.blif COMP_DATA_d.opt.blif \
	> COMP_DATA.sc
	$(RM) COMP_DATA.ctbl COMP_DATA*.blif
#
	$(ESTEREL_V603) -blif -sub FIT_RANGE_SRC.strl
	$(AREAOPT) FIT_RANGE_SRC_d
	$(BLIFSC_V603) -ctbl FIT_RANGE_SRC.ctbl -sblif FIT_RANGE_SRC_s.blif \
	FIT_RANGE_SRC_d.opt.blif > FIT_RANGE_SRC.sc
	$(RM) FIT_RANGE_SRC.ctbl FIT_RANGE_SRC*.blif
#
	$(ESTEREL_V603) -blif -sub FIT_RANGE_MOD.strl
	$(AREAOPT) FIT_RANGE_MOD_d
	$(BLIFSC_V603) -ctbl FIT_RANGE_MOD.ctbl -sblif FIT_RANGE_MOD_s.blif \
	FIT_RANGE_MOD_d.opt.blif > FIT_RANGE_MOD.sc
	$(RM) FIT_RANGE_MOD.ctbl FIT_RANGE_MOD*.blif
#
	$(ESTEREL_V603) -blif -sub FIT_RANGE_SNK.strl
	$(AREAOPT) FIT_RANGE_SNK_d
	$(BLIFSC_V603) -ctbl FIT_RANGE_SNK.ctbl -sblif FIT_RANGE_SNK_s.blif \
	FIT_RANGE_SNK_d.opt.blif > FIT_RANGE_SNK.sc
	$(RM) FIT_RANGE_SNK.ctbl FIT_RANGE_SNK*.blif
#
	$(ESTEREL_V603) -sc -sub SWITCH.strl
#
	$(ESTEREL_V603) -sc -sub TIMER.strl
#
	$(ESTEREL_V603) -sc -sub WAIT_SIG1.strl
#
	$(ESTEREL_V603) -sc -sub WAIT_SIG2.strl

Sub_Opt :

SC_LEVEL :

world : $(OBJ4STRL)

%_data.o: %_data.cc %.h
	$(CC) $(STRLINC) -c -o $@ $<

allclean : clean

gsmclean : clean

clean :
	$(RM) $(OBJ4STRL) $(SETOFREMOVE)

