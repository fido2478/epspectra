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
	$(ESTEREL_V603) -sc -sub P_MOD.strl
	$(ESTEREL_V603) -sc -sub P_MOD1to2.strl

G_Blif :
	$(ESTEREL_V603) -Lblif:-soft -B P_MOD \
	P_MOD.strl $(SUBMOD)/FIT_RANGE_MOD.strl $(SUBMOD)/COMP_DATA.strl \
	$(SUBMOD)/GET_MY_MARKED_DATA.strl $(SUBMOD)/TIMER.strl \
	$(SUBMOD)/SWITCH.strl $(SUBMOD)/WAIT_SIG1.strl
	$(AREAOPT) P_MOD
#
	$(ESTEREL_V603) -Lblif:-soft -B P_MOD1to2 \
	P_MOD1to2.strl $(SUBMOD)/FIT_RANGE_MOD.strl $(SUBMOD)/COMP_DATA.strl \
	$(SUBMOD)/GET_MY_MARKED_DATA.strl $(SUBMOD)/TIMER.strl \
	$(SUBMOD)/SWITCH.strl $(SUBMOD)/WAIT_SIG1.strl \
	$(SUBMOD)/WAIT_SIG2.strl 
	$(AREAOPT) P_MOD1to2

Sub_Opt :
	$(ESTEREL_V603) -causal -sub -B P_MOD \
	P_MOD.strl $(SUBMOD)/FIT_RANGE_MOD.strl $(SUBMOD)/COMP_DATA.strl \
	$(SUBMOD)/GET_MY_MARKED_DATA.strl $(SUBMOD)/TIMER.strl \
	$(SUBMOD)/SWITCH.strl $(SUBMOD)/WAIT_SIG1.strl
	$(AREAOPT) P_MOD_d
	$(BLIFSC_V603) -ctbl P_MOD.ctbl -sblif P_MOD_s.blif \
	P_MOD_d.opt.blif > P_MOD.sc
#
	$(ESTEREL_V603) -causal -sub -B P_MOD1to2 \
	P_MOD1to2.strl $(SUBMOD)/FIT_RANGE_MOD.strl $(SUBMOD)/COMP_DATA.strl \
	$(SUBMOD)/GET_MY_MARKED_DATA.strl $(SUBMOD)/TIMER.strl \
	$(SUBMOD)/SWITCH.strl $(SUBMOD)/WAIT_SIG1.strl \
	$(SUBMOD)/WAIT_SIG2.strl 
	$(AREAOPT) P_MOD1to2_d
	$(BLIFSC_V603) -ctbl P_MOD1to2.ctbl -sblif P_MOD1to2_s.blif \
	P_MOD1to2_d.opt.blif > P_MOD1to2.sc

Ind_Opt :
	$(ESTEREL_V603) -sc -sub P_MOD.strl \
	$(SUBMOD)/FIT_RANGE_MOD.strl \
	$(SUBMOD)/COMP_DATA.strl $(SUBMOD)/TIMER.strl $(SUBMOD)/SWITCH.strl \
	$(SUBMOD)/WAIT_SIG1.strl

gsmclean: clean

clean :
	$(RM) $(SETOFREMOVE)

