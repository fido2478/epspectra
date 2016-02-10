#############################
#############################
# FIXED PART - DO NOT TOUCH #
#############################
#############################

#############################
# made on 28 Aout 2000      #
# Esterel code optimized    #
#############################
SPECTRA_BASE = .
include Makefile.include

TYPEDIR = include
SOURCEDIR =source
P_MODDIR =p_mod
SINKDIR =sink
FUNCDIR = submodule
MAINDIR = main
CCDIR = cc
CXXDIR =c++
FFTW = fftw
VRGUI = vrgui

INC= -I. -I$(TYPEDIR) -I$(PROCESSDIR) -I$(SOURCEDIR)  -I$(P_MODDIR) -I$(SINKDIR) -I$(ENVDIR) -I$(FUNCDIR) -I$(CCDIR) -I$(VRCLSSDIR) -L$(QTDIR)/lib -lqt -lm /usr/X11R6/lib/libX11.a /usr/X11R6/lib/libXext.a

STRL= PERF_STRL1.strl \
	$(SOURCEDIR)$(PATHSEP)SOURCE1.strl \
	$(P_MODDIR)$(PATHSEP)P_MOD1.strl \
	$(SINKDIR)$(PATHSEP)SINK1.strl \
	$(FUNCDIR)$(PATHSEP)MARK_DATA1.strl \
	$(FUNCDIR)$(PATHSEP)MARK_DATA_SRC1.strl \
	$(FUNCDIR)$(PATHSEP)COMPUTE_DATA1.strl \
	$(FUNCDIR)$(PATHSEP)COMPUTE_DATA_SRC1.strl 

OBJECTS= PERF_STRL1$(OBJ) \
	PERF_STRL_data$(OBJ) \
	$(TYPEDIR)$(PATHSEP)datatype_data$(OBJ)	\
	$(SOURCEDIR)$(PATHSEP)SOURCE_data$(OBJ) \
	$(P_MODDIR)$(PATHSEP)P_MOD_data$(OBJ) \
	$(SINKDIR)$(PATHSEP)SINK_data$(OBJ) \
	$(FUNCDIR)$(PATHSEP)MARK_DATA_data$(OBJ) \
	$(FUNCDIR)$(PATHSEP)COMPUTE_DATA_data$(OBJ) \
	$(CCDIR)$(PATHSEP)interface$(OBJ) 

VROBJECTS = $(CXXDIR)/StrlBuffer$(OBJ) \
	$(CXXDIR)/StrlConnect$(OBJ) \
	$(CXXDIR)/StrlSigProc$(OBJ) \
	$(CXXDIR)/StrlMMX$(OBJ) \
	$(CXXDIR)/VrAdd_MMX$(OBJ) \
	$(CXXDIR)/VrAdd4_MMX$(OBJ) \
	$(CXXDIR)/StrlComplex$(OBJ) \
	$(CXXDIR)/StrlCycleCount$(OBJ) \
	$(CXXDIR)/StrlPerfGraph$(OBJ) \
	$(VRGUI)/VrGUI_int.o \
	$(VRGUI)/VrGUIimp.o \
	$(VRGUI)/moc_VrGUI_int.o

STRLDIRS = $(VRGUI) $(FFTW) $(TYPEDIR) $(SOURCEDIR) $(P_MODDIR) $(SUMMERDIR) $(SINKDIR)  $(FUNCDIR) $(CCDIR) $(CXXDIR) $(MAINDIR)

SCDIRS = $(FUNCDIR) $(SOURCEDIR) $(P_MODDIR) $(SINKDIR)
##########################################################################
##########################################################################
app4FT :
	cp $(STRL) /home/hkim/app4FT/DPM/
####################################
# Here is for V6
####################################

## xes simul ##
xes : clean simul c2o world
###############
	$(XES) -cc $(C++) -o PERF_STRL1 $(CFLAGS) $(CCINC) $(QLIBS) $(OBJECTS) $(VROBJECTS) $(QTDIR)/lib/libqt.so $(QTDIR)/lib/libqt.so.1 $(QTDIR)/lib/libqt.so.1.44
	$(XES) PERF_STRL1$(EXE)

simul :
	$(ESTEREL) -v -simul -B PERF_STRL1 $(STRL)

## appl of dpm ##
appl : clean strl2c c2o world appdpm
#####################

## opt of dpm ##
opt : clean iclevel_opt c2o world appdpm.opt
################

## FT compiler ##
FTapp : clean FTc2o world FTdpm.opt
#################

FTc2o :
	$(CC) $(STRLFLAGS) -c -o PERF_STRL1.o PERF_STRL1_strlcc.c $(STRLINC) $(CFLAGS)
	$(CC) $(STRLFLAGS) -c -o PERF_STRL_data.o PERF_STRL_data.c $(STRLINC) $(CFLAGS)

FTdpm.opt :
	$(LINKER) $(LINKER_FLAGS) $(DEFINES) main/main_perf.o main/lib4main.o $(OBJECTS) $(VROBJECTS) $(INC) -lcurses -ltermcap

strl12c :
	$(ESTEREL) -v -B PERF_STRL1 $(STRL)

c2o :
	$(CC) $(STRLFLAGS) -c -o PERF_STRL1.o PERF_STRL1.c $(STRLINC) $(CFLAGS)
	$(CC) $(STRLFLAGS) -c -o PERF_STRL_data.o PERF_STRL_data.c $(STRLINC) $(CFLAGS)

appdpm :
	$(LINKER) $(LINKER_FLAGS) $(DEFINES) main/main_perf.o main/lib4main.o $(OBJECTS) $(VROBJECTS) $(INC) -lcurses -ltermcap

iclevel_opt :
	$(ESTEREL) -blif -B PERF_STRL1 $(STRL)
	$(REMLATCH) PERF_STRL1.blif
	$(AREAOPT) PERF_STRL1.opt
	$(BLIFSC) -ctbl PERF_STRL1.ctbl PERF_STRL1.opt.opt.blif > \
	PERF_STRL1.icopt.sc
	$(ESTEREL) PERF_STRL1.icopt.sc -B PERF_STRL1
	$(COPY) PERF_STRL1.c  PERF_STRL1.icopt.c

appdpm.opt :
	$(LINKER) $(LINKER_FLAGS) $(DEFINES) main/main_perf.o main/lib4main.o $(OBJECTS) $(VROBJECTS) $(INC) -lcurses -ltermcap 

######################################

c4strl : $(OBJ4STRL) 
	for i in ${STRLDIRS} ; do cd $$i ; $(MAKE) $@; cd ..; done 

world : 
	for i in ${STRLDIRS} ; do cd $$i ; $(MAKE) $@; cd ..; done

clean4strl : self-clean
	for i in ${STRLDIRS} ; do cd $$i ; $(MAKE) $@; cd ..; done 

allclean : self-clean
	for i in ${STRLDIRS} ; do cd $$i ; $(MAKE) $@; cd ..; done

clean : self-clean
	for i in ${STRLDIRS} ; do cd $$i ; $(MAKE) $@; cd ..; done

self-clean:
	$(RM)  PERF_STRL1.c PERF_STRL1$(EXE) $(OBJECTS) core simul *.sc *.ssc *.ctbl *.log *.o
