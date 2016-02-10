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

Not_Dup_Opt:
	$(ESTEREL_V603) -sub -sc SINK.strl

G_Blif :
	$(ESTEREL_V603) -Lblif:-soft -B SINK \
	SINK.strl $(SUBMOD)/FIT_RANGE_SNK.strl $(SUBMOD)/COMP_DATA.strl \
	$(SUBMOD)/GET_MY_MARKED_DATA.strl \
	$(SUBMOD)/SWITCH.strl
	$(AREAOPT) SINK

Sub_Opt :
	$(ESTEREL_V603) -causal -sub -B SINK \
	SINK.strl $(SUBMOD)/FIT_RANGE_SNK.strl $(SUBMOD)/COMP_DATA.strl \
	$(SUBMOD)/GET_MY_MARKED_DATA.strl \
	$(SUBMOD)/SWITCH.strl
	$(AREAOPT) SINK_d
	$(BLIFSC_V603) -ctbl SINK.ctbl -sblif SINK_s.blif \
	SINK_d.opt.blif > SINK.sc

SC_LEVEL :
	$(ESTEREL_V603) -sc -sub -B SINK.sc SINK.strl \
	$(SUBMOD)/FIT_RANGE_SNK.strl \
	$(SUBMOD)/COMP_DATA.strl $(SUBMOD)/SWITCH.strl

gsmclean:clean

clean :
	$(RM) $(SETOFREMOVE)

