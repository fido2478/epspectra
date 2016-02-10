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


SPECTRA_BASE := ..
include ../Makefile.include

STRL_FILES = 	$(SRC)/TC_SOURCE.strl \
		$(I_MOD)/P_MOD.strl \
		$(I_MOD)/P_MOD1to2.strl \
		$(SNK)/SINK.strl \
		$(SUBMOD)/COMP_DATA.strl \
		$(SUBMOD)/TC_FIT_RANGE_MOD.strl \
		$(SUBMOD)/TC_FIT_RANGE_SNK.strl \
		$(SUBMOD)/TC_FIT_RANGE_SRC.strl \
		$(SUBMOD)/SWITCH.strl \
		$(SUBMOD)/WAIT_SIG1.strl \
		$(SUBMOD)/WAIT_SIG2.strl \
		$(SUBMOD)/TIMER.strl \
		$(SNK)/SCOPESINK.strl
#		$(SUBMOD)/MONITOR.strl \


OBJ_STRL_FILES=	 TC_UDP_TX.o \
		TC_UDP_TX_data$(OBJ) \
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
	cp TC_UDP_TX.strl $(STRL_FILES) /home/hkim/app4FT/DFM/tc/
######################
# opt
###################### 
opt :IC_LEVEL TC_UDP_TX.EXE all MAIN tcdfm.opt

######################
# non opt
######################
appl : TC_UDP_TX.cyc TC_UDP_TX.EXE all MAIN tcdfm

tcdfm.opt :
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main.o main_strl.o $(CCINC) $(QLIBS) $(OBJ_STRL_FILES) $(OBJ_FILES)

IC_LEVEL :
	$(ESTEREL_V603) -blif -B TC_UDP_TX TC_UDP_TX.strl $(STRL_FILES)
	$(REMLATCH) TC_UDP_TX.blif
	$(AREAOPT) TC_UDP_TX.opt
	$(BLIFSC_V603) -ctbl TC_UDP_TX.ctbl TC_UDP_TX.opt.opt.blif > TC_UDP_TX.sc
	$(ESTEREL_V603) TC_UDP_TX.sc

tcdfm :
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main.o main_strl.o $(CCINC) $(QLIBS) $(OBJ_STRL_FILES) $(OBJ_FILES) 
TC_UDP_TX.EXE :
	$(C2O) -o TC_UDP_TX.o TC_UDP_TX.c $(STRLINC) $(CFLAGS)
	$(C2O) -o TC_UDP_TX_data.o TC_UDP_TX_data.c $(CFLAGS)
TC_UDP_TX.cyc : 
	$(ESTEREL_V603) -B TC_UDP_TX TC_UDP_TX.strl $(STRL_FILES)
MAIN : 
	$(CC) -c -o main_strl.o main_strl.c $(STRLINC) $(CFLAGS)
	$(CC) -c -o main.o main.c $(STRLINC) $(CFLAGS)

###########################################
# simulation mode
###########################################

xes: TC_UDP_TX.o all 
	$(XES) -cc $(C++)   -o TC_UDP_TX $(CFLAGS) $(CCINC) $(QLIBS) $(OBJ_STRL_FILES) $(OBJ_FILES) $(QTDIR)/lib/libqt.so $(QTDIR)/lib/libqt.so.1 $(QTDIR)/lib/libqt.so.1.44
	$(XES) TC_UDP_TX$(EXE)
ddd: TC_UDP_TX.g all
	$(XES) -cc $(C++) -o TC_UDP_TX $(OBJ_STRL_FILES) $(OBJ_FILES)
	$(DDDXES) TC_UDP_TX$(EXE)
TC_UDP_TX.g : TC_UDP_TX
	$(C2O) $(NAMING) TC_UDP_TX.c $(STRLINC) $(CFLAGS)
	$(C2O) TC_UDP_TX_data.o TC_UDP_TX_data.c $(CFLAGS)
TC_UDP_TX.o : TC_UDP_TX
	$(C2O) $(NAMING) TC_UDP_TX.c $(STRLINC) $(CFLAGS)
	$(C2O) TC_UDP_TX_data.c $(CFLAGS)
TC_UDP_TX : 
	$(ESTEREL_V603) $(SIMUL) $(STRL_NAMING) TC_UDP_TX.strl $(STRL_FILES)

#####################################
# library compile
#####################################

all :
	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd project; done

world :
	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd project; done

allclean : self-clean
	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd project; done

clean : self-clean
	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd project; done
self-clean:
	rm -f  $(SETOFREMOVE) TC_UDP_TX.c appl opt opt3
