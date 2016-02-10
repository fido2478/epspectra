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


include ../Makefile.include

STRL_FILES = 	$(SRC)/SOURCE.strl \
		$(I_MOD)/P_MOD.strl \
		$(I_MOD)/P_MOD1to2.strl \
		$(SNK)/SINK.strl \
		$(SUBMOD)/COMP_DATA.strl \
		$(SUBMOD)/FIT_RANGE_MOD.strl \
		$(SUBMOD)/FIT_RANGE_SNK.strl \
		$(SUBMOD)/FIT_RANGE_SRC.strl \
		$(SUBMOD)/SWITCH.strl \
		$(SUBMOD)/WAIT_SIG1.strl \
		$(SUBMOD)/WAIT_SIG2.strl \
		$(SUBMOD)/TIMER.strl \
		Safety.strl \
		Safety_Liveness.strl \
		Correctness.strl \
		CONVERTOR1.strl \
		CONVERTOR2.strl \
		$(SNK)/SCOPESINK.strl
#		$(SUBMOD)/MONITOR.strl \

OBJ_STRL_FILES=	 UDP_FLOW.o \
		UDP_FLOW_data$(OBJ) \
		$(SUBMOD)/COMP_DATA_data.o \
		$(SUBMOD)/FIT_RANGE_data.o \
		$(INCLUDE)/datatype_data$(OBJ) \
		$(INTFACE)/inter_udp_tx$(OBJ)

OBJ_FILES =	$(CXX)/StrlBuffer$(OBJ) \
		$(CXX)/StrlConnect$(OBJ) \
		$(CXX)/StrlSigProc$(OBJ) \
		$(CXX)/StrlComplex$(OBJ) \
		$(CXX)/StrlMMX$(OBJ) \
		$(CXX)/VrAdd_MMX$(OBJ) \
		$(CXX)/VrAdd4_MMX$(OBJ) \
		$(VRGUI)/VrGUI_int$(OBJ) \
		$(VRGUI)/VrGUIimp$(OBJ) \
		$(VRGUI)/moc_VrGUI_int$(OBJ) \
		$(CXX)/StrlPerfGraph$(OBJ) \
		$(CXX)/StrlCycleCount$(OBJ)

SCDIRS =	$(SUBMOD) $(SRC) $(I_MOD) $(SNK)

###########################################
# optimization mode
###########################################
app4FT :
	cp UDP_FLOW.strl $(STRL_FILES) /home/hkim/app4FT/DFM/nontc/

#########################
# This optimization is to group *.strl into one file
# in order to use ic level linking
#########################
xeve: IC_LEVEL
	$(XEVE) UDP_FLOW.opt.opt.blif

opt :clean IC_LEVEL UDP_FLOW.EXE all MAIN appdfm.opt

#########################
# application without opt
#########################
appl : clean UDP_FLOW.cyc UDP_FLOW.EXE all MAIN appdfm

#########################
# FT compiler
#########################
FTapp : clean FTc2o all MAIN FTappdfm.opt

FTc2o :
	$(C2O) -o UDP_FLOW.o UDP_FLOW_strlcc.c $(STRLINC) $(CFLAGS)
	$(C2O) -o UDP_FLOW_data.o UDP_FLOW_data.c $(CFLAGS)

FTappdfm.opt :
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main.o main_strl.o $(CCINC) $(QLIBS) $(OBJ_STRL_FILES) $(OBJ_FILES)

appdfm :
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main.o main_strl.o $(CCINC) $(QLIBS) $(OBJ_STRL_FILES) $(OBJ_FILES)

appdfm.opt :
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main.o main_strl.o $(CCINC) $(QLIBS) $(OBJ_STRL_FILES) $(OBJ_FILES)


IC_LEVEL :
	$(ESTEREL_V603) -blif -B UDP_FLOW UDP_FLOW.strl $(STRL_FILES)
	$(REMLATCH) UDP_FLOW.blif
	$(AREAOPT) UDP_FLOW.opt
	$(BLIFSC_V603) -ctbl UDP_FLOW.ctbl UDP_FLOW.opt.opt.blif > UDP_FLOW.sc
	$(ESTEREL_V603) UDP_FLOW.sc

UDP_FLOW.EXE :
	$(C2O) -o UDP_FLOW.o UDP_FLOW.c $(STRLINC) $(CFLAGS)
	$(C2O) -o UDP_FLOW_data.o UDP_FLOW_data.c $(CFLAGS)
UDP_FLOW.cyc : 
	$(ESTEREL_V603) -B UDP_FLOW UDP_FLOW.strl $(STRL_FILES)
MAIN : 
	$(CC) -c -o main_strl.o main_strl.c $(STRLINC) $(CFLAGS)
	$(CC) -c -o main.o main.c $(STRLINC) $(CFLAGS)

###########################################
# simulation mode
###########################################

xes: clean UDP_FLOW.o all 
	$(XES) -cc $(C++) -o UDP_FLOW $(OBJ_STRL_FILES) $(OBJ_FILES) $(STRLINC) $(CFLAGS) $(QTDIR)/lib/libqt.so $(QTDIR)/lib/libqt.so.1 $(QTDIR)/lib/libqt.so.1.44
	$(XES) UDP_FLOW$(EXE)
ddd: UDP_FLOW.g all
	$(XES) -cc $(C++) -o UDP_FLOW $(OBJ_STRL_FILES) $(OBJ_FILES)
	$(DDDXES) UDP_FLOW$(EXE)
UDP_FLOW.g : UDP_FLOW
	$(C2O) $(NAMING) UDP_FLOW.c $(STRLINC) $(CFLAGS)
	$(C2O) UDP_FLOW_data.o UDP_FLOW_data.c $(CFLAGS)
UDP_FLOW.o : UDP_FLOW
	$(C2O) $(NAMING) UDP_FLOW.c
	$(C2O) -o UDP_FLOW_data.o UDP_FLOW_data.c $(CFLAGS)
UDP_FLOW : 
	$(ESTEREL) $(SIMUL) $(STRL_NAMING) UDP_FLOW.strl $(STRL_FILES)

#####################################
# library compile
#####################################

all :
	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd epspectra; done

world :
	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd epspectra; done

G_Blif :
	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd epspectra; done

allclean : self-clean
	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd epspectra; done

clean : self-clean
	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd epspectra; done
self-clean:
	rm -f  $(SETOFREMOVE) UDP_FLOW.c appdfm appdfm.opt *.ctbl *.blif *.log *.sc *.ic
