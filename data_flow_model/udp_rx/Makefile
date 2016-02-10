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
		$(SNK)/SINK.strl \
		$(SUBMOD)/MONITOR.strl \
		$(SUBMOD)/INITIALIZE_SINK.strl \
		$(SUBMOD)/COMP_DATA.strl \
		$(SUBMOD)/GET_MY_MARKED_DATA.strl \
		$(SUBMOD)/FIT_RANGE_MOD.strl \
		$(SUBMOD)/FIT_RANGE_SNK.strl \
		$(SUBMOD)/FIT_RANGE_SRC.strl \
		$(SUBMOD)/SWITCH.strl \
		$(SUBMOD)/WAIT_SIG1.strl \
		$(SUBMOD)/WAIT_SIG2.strl \
		$(SUBMOD)/TIMER.strl

OBJ_STRL_FILES=	 UDP_RX.o \
		UDP_RX_data$(OBJ) \
		$(SUBMOD)/INITIALIZE_SINK_data.o \
		$(SUBMOD)/COMP_DATA_data.o \
		$(SUBMOD)/FIT_RANGE_data.o \
		$(SUBMOD)/GET_MY_MARKED_DATA_data.o \
		$(SUBMOD)/GET_SAMPLE_RANGE_data.o \
		$(INCLUDE)/datatype_data$(OBJ)

OBJ_FILES =	$(CXX)/StrlBuffer$(OBJ) \
		$(CXX)/StrlConnect$(OBJ) \
		$(CXX)/StrlSigProc$(OBJ) \
		$(CXX)/StrlComplex$(OBJ) \
		$(CXX)/StrlMMX$(OBJ) \
		$(INTFACE)/interface$(OBJ)

###########################################
# optimization mode
###########################################

opt : SSC UDP_RX.EXE MAIN world
	$(LINKER) $(LINKER_FLAGS) main.o main_strl.o $(OBJ_STRL_FILES) $(OBJ_FILES)
SSC:
	$(ESTEREL) -causal -Lblif:-soft UDP_RX.strl $(STRL_FILES) -B UDP_RX
	$(BLIFOPT) -area UDP_RX.blif
	$(BLIFSSC) -ctbl UDP_RX.ctbl UDP_RX.opt.blif -B UDP_RX
	$(ESTEREL) $(CAUSAL) UDP_RX.ssc

###########################################
# compile for application
###########################################

appl : UDP_RX.cyc UDP_RX.EXE MAIN world
	$(LINKER) $(LINKER_FLAGS) main.o main_strl.o $(OBJ_STRL_FILES) $(OBJ_FILES)
UDP_RX.EXE :
	$(C2O) -o UDP_RX.o UDP_RX.c
	$(C2O) -o UDP_RX_data.o UDP_RX_data.c
UDP_RX.cyc : 
	$(ESTEREL) $(CYCL_EXE) -B UDP_RX UDP_RX.strl $(STRL_FILES)
MAIN : 
	$(CC) -c -o main_strl.o main_strl.c $(INC)
	$(CC) -c -o main.o main.c $(INC)

###########################################
# simulation mode
###########################################

xes: UDP_RX.o world
	$(XES) -cc $(C++) -o UDP_RX $(OBJ_STRL_FILES) $(OBJ_FILES)
	$(XES) UDP_RX$(EXE)
ddd: UDP_RX.o world
	$(XES) -cc $(C++) -o UDP_RX $(OBJ_STRL_FILES) $(OBJ_FILES)
	$(DDDXES) UDP_RX$(EXE)
UDP_RX.o : UDP_RX
	$(C2O) $(NAMING_DES) UDP_RX.c
	$(C2O) -o UDP_RX_data.o UDP_RX_data.c
UDP_RX : 
	$(ESTEREL) $(CYCL_SIMUL) $(STRL_NAMING) UDP_RX.strl $(STRL_FILES)

#####################################
# library compile
#####################################

world :
	for i in ${LIB_DIR} ; do cd $$i ; $(MAKE) $@; cd ; cd epspectra; done

clean-opt : clean
	rm opt *.blif *.ssc *.ctbl
clean-appl : clean
	rm appl
clean : self-clean
	for i in ${LIB_DIR} ; do cd $$i ; $(MAKE) $@; cd ; cd epspectra; done
self-clean:
	rm *.o UDP_RX.c

backup :
	cd ;cd project;
	tar -zcvf data_flow.tgz data_flow_model;
	mv data_flow_tgz BACK_UP
