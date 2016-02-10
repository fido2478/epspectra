################################################################
# This is Makefile to compile C file for esterel.
################################################################
SPECTRA_BASE := ..
include ../Makefile.include

OBJ4STRL := $(patsubst %_data.c, %_data.o, $(wildcard *_data.c))
C4STRL := $(wildcard *_data.c)
HEADER := $(wildcard *.h)

all   : world

TopLevel:Opt

Mini_Opt:
	$(ESTEREL_V603) -sub -sc P_MOD.strl

Opt   :
	$(ESTEREL_V603) -blif -sub -B P_MOD P_MOD.strl\
	../submodule/MARK_DATA.strl \
	../submodule/COMPUTE_DATA.strl 
	$(AREAOPT_V603) P_MOD_d
	$(BLIFSC_V603) -ctbl P_MOD.ctbl -sblif P_MOD_s.blif \
	P_MOD_d.opt.blif > P_MOD.sc
	$(RM) P_MOD.ctbl P_MOD_*.blif

Indiv_Opt:
	$(ESTEREL_V603) -sub -sc P_MOD.strl
#	sclink -nocopy P_MOD.sc \
#	../submodule/MARK_DATA.sc \
#	../submodule/COMPUTE_DATA.sc > P_MOD_SC.sc

world : $(OBJ4STRL) 

c4strl : $(OBJ4STRL)  

$(OBJ4STRL) : $(C4STRL) $(HEADER)
	$(CC) $(STRLFLAGS)  $(STRLINC) -c -o $@ $< 

allclean : clean

clean4strl :
	$(RM) $(OBJ4STRL) 

clean :
	$(RM) $(OBJ4STRL) *.ssc *.sc *.ctbl *.blif *.log 

