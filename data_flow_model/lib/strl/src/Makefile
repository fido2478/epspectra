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
	$(ESTEREL_V603) -sub -sc SOURCE.strl

G_Blif :
	$(ESTEREL_V603) -Lblif:-soft -B SOURCE \
	SOURCE.strl $(SUBMOD)/FIT_RANGE_SRC.strl $(SUBMOD)/COMP_DATA.strl \
	$(SUBMOD)/GET_MY_MARKED_DATA.strl $(SUBMOD)/TIMER.strl
	$(AREAOPT) SOURCE

Sub_Opt :
	$(ESTEREL_V603) -blif -sub -B SOURCE \
	SOURCE.strl $(SUBMOD)/FIT_RANGE_SRC.strl $(SUBMOD)/COMP_DATA.strl \
	$(SUBMOD)/GET_MY_MARKED_DATA.strl $(SUBMOD)/TIMER.strl
	$(AREAOPT) SOURCE_d
	$(BLIFSC_V603) -ctbl SOURCE.ctbl -sblif SOURCE_s.blif \
	SOURCE_d.opt.blif > SOURCE.sc

SC_LEVEL :
	$(ESTEREL_V603) -sc -sub -B SOURCE.sc SOURCE.strl \
	$(SUBMOD)/FIT_RANGE_SRC.strl \
	$(SUBMOD)/COMP_DATA.strl $(SUBMOD)/TIMER.strl

gsmclean: clean

clean :
	$(RM) $(SETOFREMOVE)

