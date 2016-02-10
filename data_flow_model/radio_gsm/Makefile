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
		$(SUBMOD)/COMP_DATA.strl \
		$(SUBMOD)/FIT_RANGE_MOD.strl \
		$(SUBMOD)/FIT_RANGE_SNK.strl \
		$(SUBMOD)/FIT_RANGE_SRC.strl \
		$(SUBMOD)/SWITCH.strl \
		$(SUBMOD)/WAIT_SIG1.strl \
		$(SUBMOD)/TIMER.strl 

PROPERTY_STRL=	Safety.strl \
		Safety_Liveness.strl \
		Correctness.strl \
		CONVERTOR1.strl

OBJ_GSMALL_STRL=GSM_ALL$(OBJ) \
		GSM_ALL_data$(OBJ) \
		$(SUBMOD)/COMP_DATA_data$(OBJ) \
		$(SUBMOD)/FIT_RANGE_data$(OBJ) \
		$(INCLUDE)/datatype_data$(OBJ) \
		$(INTFACE)/intergsm$(OBJ)

OBJ_PERF_DNLINK_STRL=PERF_DNLINK$(OBJ) \
		GSM_ALL_data$(OBJ) \
		$(SUBMOD)/COMP_DATA_data$(OBJ) \
		$(SUBMOD)/FIT_RANGE_data$(OBJ) \
		$(INCLUDE)/datatype_data$(OBJ) \
		$(INTFACE)/intergsm$(OBJ)

OBJ_PERF_UPLINK_STRL=PERF_UPLINK$(OBJ) \
		GSM_ALL_data$(OBJ) \
		$(SUBMOD)/COMP_DATA_data$(OBJ) \
		$(SUBMOD)/FIT_RANGE_data$(OBJ) \
		$(INCLUDE)/datatype_data$(OBJ) \
		$(INTFACE)/intergsm$(OBJ)

OBJ_PERF_ALL_STRL=PERF_ALL$(OBJ) \
		GSM_ALL_data$(OBJ) \
		$(SUBMOD)/COMP_DATA_data$(OBJ) \
		$(SUBMOD)/FIT_RANGE_data$(OBJ) \
		$(INCLUDE)/datatype_data$(OBJ) \
		$(INTFACE)/intergsm$(OBJ)

OBJ_DNLINK_STRL=GSM_DNLINK$(OBJ) \
		GSM_ALL_data$(OBJ) \
		$(SUBMOD)/COMP_DATA_data$(OBJ) \
		$(SUBMOD)/FIT_RANGE_data$(OBJ) \
		$(INCLUDE)/datatype_data$(OBJ) \
		$(INTFACE)/intergsm$(OBJ)

OBJ_UPLINK_STRL=GSM_UPLINK.o \
		GSM_ALL_data$(OBJ) \
		$(SUBMOD)/COMP_DATA_data.o \
		$(SUBMOD)/FIT_RANGE_data.o \
		$(INCLUDE)/datatype_data$(OBJ) \
		$(INTFACE)/intergsm$(OBJ)

OBJ_GSMALL_CC=	$(CXX)/StrlBuffer$(OBJ) \
		$(CXX)/StrlConnect$(OBJ) \
		$(CXX)/StrlSigProc$(OBJ) \
		$(CXX)/StrlComplex$(OBJ)

PERFG=		$(CXX)/StrlPerfGraph$(OBJ) \
		$(CXX)/StrlCycleCount$(OBJ)

SCDIRS =	$(SUBMOD) $(SRC) $(I_MOD) $(SNK)

###########################################
# optimization mode
###########################################

#########################
# This optimization is to group *.strl into one file
# in order to use ic level linking
# Don't compile both *link_compil and perf_*link_compil due to "-DPERFMON" on FileSource
# FileSink
#########################
all : gsmclean gsm gsmall dnlink_compil uplink_compil 
#xeve
#gsmclean
#perf_dnlink_compil perf_uplink_compil
#gsmall perf_dnlink_compil perf_uplink_compil dnlink_compil uplink_compil
#perf_dnlink_opt perf_uplink_opt

xeve: verif_dn verif_up

verif_up:
	rm -f Verif_Gsm_Uplink.*.*.blif
	$(ESTEREL) -blif -B Verif_Gsm_Uplink Verif_Gsm_Uplink.strl \
	$(STRL_FILES) $(PROPERTY_STRL)
	$(REMLATCH) Verif_Gsm_Uplink.blif
	$(AREAOPT) Verif_Gsm_Uplink.opt
#	$(XEVE) Verif_Gsm_Uplink.opt.opt.blif

verif_dn: 
	rm -f Verif_Gsm_Dnlink.*.*.blif
	$(ESTEREL) -blif -B Verif_Gsm_Dnlink Verif_Gsm_Dnlink.strl \
	$(STRL_FILES) $(PROPERTY_STRL)
	$(REMLATCH) Verif_Gsm_Dnlink.blif
	$(AREAOPT) Verif_Gsm_Dnlink.opt
#	$(XEVE) Verif_Gsm_Dnlink.opt.opt.blif

opt : gsmclean gsm perf_dnlink_opt perf_uplink_opt 
#perf_all_opt
#perf_all_opt
#perf_dnlink_opt perf_uplink_opt
#DN_IC_LEVEL GSM_DNLINK.EXE gsm MAIN gsm_dnlink.opt

perf_dnlink_opt: PERF_DN_IC_LEVEL PERF_DNLINK.EXE perf_dnlink.opt

perf_uplink_opt: PERF_UP_IC_LEVEL PERF_UPLINK.EXE perf_uplink.opt

perf_all_opt: PERF_ALL_IC_LEVEL PERF_ALL.EXE perf_all.opt

#########################
# application without opt
#########################
#make clean;make;make allxes/upxes/dnxes
allxes:perf_dn_xes
#gsm_all_xes

perf_dn_xes: PERF_DNLINK.simul PERF_DNLINK.EXE
	$(XES) -cc $(C++) -o PERF_DNLINK $(OBJ_PERF_DNLINK_STRL) $(SPECTRA_LIBS) $(GSMOBJ) $(CFLAGS)
	$(XES) PERF_DNLINK$(EXE)

gsm_all_xes: GSM_ALL.simul GSM_ALL.EXE
	$(XES) -cc $(C++) -o GSM_ALL  $(OBJ_GSMALL_STRL) $(SPECTRA_LIBS) $(GSMOBJ) $(CFLAGS)
	$(XES) GSM_ALL$(EXE)

upxes	: GSM_UPLINK.cyc GSM_UPLINK.EXE gsm
	$(XES) -cc $(C++) -o GSM_UPLINK $(OBJ_UPLINK_STRL) $(SPECTRA_LIBS) $(GSMOBJ) $(STRLINC) $(CFLAGS)
	$(XES) GSM_UPLINK$(EXE)

gsmall : GSM_ALL.cyc GSM_ALL.EXE gsm_all

gsm_all:
	$(CC) -c -o main.o main.c $(STRLINC) $(CFLAGS)
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main.o $(GSMINC) $(OBJ_GSMALL_STRL) $(SPECTRA_LIBS) $(GSMLIB) $(VOICE_LIBS)

uplink_compil : GSM_UPLINK.cyc GSM_UPLINK.EXE gsm_uplink

uplink_compil_opt : GSM_UP_IC_LEVEL GSM_UPLINK.EXE gsm_uplink.opt

gsm_uplink :
	$(CC) -c -o main_uplink.o main_uplink.c $(STRLINC) $(CFLAGS)
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main_uplink.o $(GSMINC) $(OBJ_UPLINK_STRL) $(SPECTRA_LIBS) $(GSMLIB) $(VOICE_LIBS) 

gsm_uplink.opt :
	$(CC) -c -o main_uplink.o main_uplink.c $(STRLINC) $(CFLAGS)
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main_uplink.o $(GSMINC) $(OBJ_UPLINK_STRL) $(SPECTRA_LIBS) $(GSMLIB) $(VOICE_LIBS) 

perf_dnlink_compil : PERF_DNLINK.cyc PERF_DNLINK.EXE perf_dnlink

perf_uplink_compil : PERF_UPLINK.cyc PERF_UPLINK.EXE perf_uplink

perf_all_compil : PERF_ALL.cyc PERF_ALL.EXE perf_all

perf_dnlink :
	$(CC) -c -o main_perf_dnlink.o main_perf_dnlink.c $(STRLINC) $(CFLAGS)
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main_perf_dnlink.o $(OBJ_PERF_DNLINK_STRL) $(SPECTRA_LIBS) $(GSMINC) $(GSMLIB) $(VOICE_LIBS)
# $(OBJ_GSMALL_CC)  $(PERFG)

perf_uplink :
	$(CC) -c -o main_perf_uplink.o main_perf_uplink.c $(STRLINC) $(CFLAGS)
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main_perf_uplink.o $(OBJ_PERF_UPLINK_STRL) $(SPECTRA_LIBS) $(GSMINC) $(GSMLIB) $(VOICE_LIBS)

perf_all :
	$(CC) -c -o main_perf_all.o main_perf_all.c $(STRLINC) $(CFLAGS)
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main_perf_all.o $(OBJ_PERF_ALL_STRL) $(SPECTRA_LIBS) $(GSMINC) $(GSMLIB) $(VOICE_LIBS)

perf_dnlink.opt :
	$(CC) -c -o main_perf_dnlink.o main_perf_dnlink.c $(STRLINC) $(CFLAGS)
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main_perf_dnlink.o $(OBJ_PERF_DNLINK_STRL) $(SPECTRA_LIBS) $(GSMINC) $(GSMLIB) $(VOICE_LIBS)

perf_uplink.opt :
	$(CC) -c -o main_perf_uplink.o main_perf_uplink.c $(STRLINC) $(CFLAGS)
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main_perf_uplink.o $(OBJ_PERF_UPLINK_STRL) $(SPECTRA_LIBS) $(GSMINC) $(GSMLIB) $(VOICE_LIBS)

perf_all.opt :
	$(CC) -c -o main_perf_all.o main_perf_all.c $(STRLINC) $(CFLAGS)
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main_perf_all.o $(OBJ_PERF_ALL_STRL) $(SPECTRA_LIBS) $(GSMINC) $(GSMLIB) $(VOICE_LIBS)

########################################################
dnlink_compil : GSM_DNLINK.cyc GSM_DNLINK.EXE gsm_dnlink

dnlink_compil_opt : GSM_DN_IC_LEVEL GSM_DNLINK.EXE gsm_dnlink.opt

gsm_dnlink :
	$(CC) -c -o main_dnlink.o main_dnlink.c $(STRLINC) $(CFLAGS)
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main_dnlink.o $(GSMINC) $(OBJ_DNLINK_STRL) $(SPECTRA_LIBS) $(GSMLIB) $(VOICE_LIBS)

gsm_dnlink.opt :
	$(CC) -c -o main_dnlink.o main_dnlink.c $(STRLINC) $(CFLAGS)
	$(LINKER) $(LINKER_FLAGS) $(CFLAGS) main_dnlink.o $(GSMINC) $(OBJ_DNLINK_STRL) $(SPECTRA_LIBS)


GSM_DN_IC_LEVEL :
	$(ESTEREL_V603) -blif -B GSM_DNLINK GSM_DNLINK.strl $(STRL_FILES)
	$(REMLATCH) GSM_DNLINK.blif
	$(AREAOPT) GSM_DNLINK.opt
	$(BLIFSC_V603) -ctbl GSM_DNLINK.ctbl GSM_DNLINK.opt.opt.blif > GSM_DNLINK.sc
	$(ESTEREL_V603) GSM_DNLINK.sc

PERF_DN_IC_LEVEL :
	$(ESTEREL_V603) -blif -B PERF_DNLINK PERF_DNLINK.strl $(STRL_FILES)
	$(REMLATCH) PERF_DNLINK.blif
	$(AREAOPT) PERF_DNLINK.opt
	$(BLIFSC_V603) -ctbl PERF_DNLINK.ctbl PERF_DNLINK.opt.opt.blif > PERF_DNLINK.sc
	$(ESTEREL_V603) PERF_DNLINK.sc

GSM_UP_IC_LEVEL :
	$(ESTEREL_V603) -blif -B GSM_UPLINK GSM_UPLINK.strl $(STRL_FILES)
	$(REMLATCH) GSM_UPLINK.blif
	$(AREAOPT) GSM_UPLINK.opt
	$(BLIFSC_V603) -ctbl GSM_UPLINK.ctbl GSM_UPLINK.opt.opt.blif > GSM_UPLINK.sc
	$(ESTEREL_V603) GSM_UPLINK.sc

PERF_UP_IC_LEVEL :
	$(ESTEREL_V603) -blif -B PERF_UPLINK PERF_UPLINK.strl $(STRL_FILES)
	$(REMLATCH) PERF_UPLINK.blif
	$(AREAOPT) PERF_UPLINK.opt
	$(BLIFSC_V603) -ctbl PERF_UPLINK.ctbl PERF_UPLINK.opt.opt.blif > PERF_UPLINK.sc
	$(ESTEREL_V603) PERF_UPLINK.sc

PERF_ALL_IC_LEVEL :
	$(ESTEREL_V603) -blif -B PERF_ALL PERF_ALL.strl $(STRL_FILES)
	$(REMLATCH) PERF_ALL.blif
	$(AREAOPT) PERF_ALL.opt
	$(BLIFSC_V603) -ctbl PERF_ALL.ctbl PERF_ALL.opt.opt.blif > PERF_ALL.sc
	$(ESTEREL_V603) PERF_ALL.sc

GSM_ALL.EXE :
	$(C2O) -o GSM_ALL.o GSM_ALL.c $(STRLINC) $(CFLAGS)
	$(C2O) -o GSM_ALL_data.o GSM_ALL_data.c $(STRLINC) $(CFLAGS)

GSM_ALL.cyc : 
	$(ESTEREL_V603) -B GSM_ALL GSM_ALL.strl $(STRL_FILES)

GSM_ALL.simul : 
	$(ESTEREL_V603) $(SIMUL) -B GSM_ALL GSM_ALL.strl $(STRL_FILES)

PERF_DNLINK.EXE :
	$(C2O) -o PERF_DNLINK.o PERF_DNLINK.c $(STRLINC) $(CFLAGS)
	$(C2O) -o GSM_ALL_data.o GSM_ALL_data.c $(STRLINC) $(CFLAGS)

PERF_DNLINK.cyc : 
	$(ESTEREL_V603) -B PERF_DNLINK PERF_DNLINK.strl $(STRL_FILES)

PERF_UPLINK.EXE :
	$(C2O) -o PERF_UPLINK.o PERF_UPLINK.c $(STRLINC) $(CFLAGS)
	$(C2O) -o GSM_ALL_data.o GSM_ALL_data.c $(STRLINC) $(CFLAGS)

PERF_UPLINK.cyc : 
	$(ESTEREL_V603) -B PERF_UPLINK PERF_UPLINK.strl $(STRL_FILES)

PERF_ALL.EXE :
	$(C2O) -o PERF_ALL.o PERF_ALL.c $(STRLINC) $(CFLAGS)
	$(C2O) -o GSM_ALL_data.o GSM_ALL_data.c $(STRLINC) $(CFLAGS)

PERF_ALL.cyc : 
	$(ESTEREL_V603) -B PERF_ALL PERF_ALL.strl $(STRL_FILES)

PERF_DNLINK.simul : 
	$(ESTEREL_V603) $(SIMUL) -B PERF_DNLINK PERF_DNLINK.strl $(STRL_FILES)

GSM_DNLINK.EXE :
	$(C2O) -o GSM_DNLINK.o GSM_DNLINK.c $(STRLINC) $(CFLAGS)
	$(C2O) -o GSM_ALL_data.o GSM_ALL_data.c $(STRLINC) $(CFLAGS)

GSM_DNLINK.cyc : 
	$(ESTEREL_V603) -B GSM_DNLINK GSM_DNLINK.strl $(STRL_FILES)

GSM_UPLINK.EXE :
	$(C2O) -o GSM_UPLINK.o GSM_UPLINK.c $(STRLINC) $(CFLAGS)
	$(C2O) -o GSM_ALL_data.o GSM_ALL_data.c $(STRLINC) $(CFLAGS)

GSM_UPLINK.cyc : 
	$(ESTEREL_V603) -B GSM_UPLINK GSM_UPLINK.strl $(STRL_FILES)

MAIN : 

###########################################
# simulation mode
###########################################

dnxes: clean GSM_DNLINK.o gsm 
	$(XES) -cc $(C++) -o GSM_DNLINK $(OBJ_DNLINK_STRL) $(SPECTRA_LIBS) $(GSMOBJ) $(STRLINC) $(CFLAGS)
	$(XES) GSM_DNLINK$(EXE)
ddd: GSM_DNLINK.g gsm
	$(XES) -cc $(C++) -o GSM_DNLINK $(OBJ_DNLINK_STRL) $(SPECTRA_LIBS)
	$(DDDXES) GSM_DNLINK$(EXE)
GSM_DNLINK.g : GSM_DNLINK
	$(C2O) $(NAMING) GSM_DNLINK.c $(STRLINC) $(CFLAGS)
	$(C2O) GSM_ALL_data.o GSM_ALL_data.c $(CFLAGS)
GSM_DNLINK.o : GSM_DNLINK
	$(C2O) $(NAMING) GSM_DNLINK.c
	$(C2O) -o GSM_ALL_data.o GSM_ALL_data.c $(CFLAGS)
GSM_DNLINK : 
	$(ESTEREL) $(SIMUL) $(STRL_NAMING) GSM_DNLINK.strl $(STRL_FILES)

#####################################
# library compile
#####################################

#all :
#	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd epspectra; done

gsm : 
	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd epspectra; done

world :
	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd epspectra; done

G_Blif :
	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd epspectra; done

allclean : self-clean
	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd epspectra; done

gsmclean : self-clean
	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd epspectra; done

clean : self-clean
	for i in ${LIBDIR} ; do cd $$i ; $(MAKE) $@; cd ; cd epspectra; done
self-clean:
	rm -f  $(SETOFREMOVE) gsm_all GSM_ALL.exe GSM_ALL.c PERF_DNLINK.c PERF_UPLINK.c PERF_ALL.c GSM_DNLINK.c perf_dnlink PERF_DNLINK.exe PERF_UPLINK.exe PERF_ALL.exe gsm_dnlink gsm_dnlink.opt *.ctbl GSM_*.blif PERF_*.blif Verif_*.blif *.log *.sc *.ic GSM_UPLINK.c gsm_uplink gsm_dnlink.opt perf_dnlink.opt perf_uplink.opt perf_all.opt perf_uplink perf_dnlink perf_all dn_out up_out.au core 
