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

Mini_Opt:Opt

Opt :
	$(ESTEREL_V603) -blif -sub -B SOURCE SOURCE.strl\
	../submodule/MARK_DATA_SRC.strl \
	../submodule/COMPUTE_DATA_SRC.strl 
	$(AREAOPT_V603) SOURCE_d
	$(BLIFSC_V603) -ctbl SOURCE.ctbl -sblif SOURCE_s.blif \
	SOURCE_d.opt.blif > SOURCE.sc
	$(RM) *.blif *.ctbl

Indiv_Opt:
	$(ESTEREL_V603) -sub -sc SOURCE.strl
#	sclink -nocopy SOURCE.sc \
#	../submodule/MARK_DATA_SRC.sc \
#	../submodule/COMPUTE_DATA_SRC.sc > SOURCE_SC.sc

world : $(OBJ4STRL) 

c4strl : $(OBJ4STRL)  

$(OBJ4STRL) : $(C4STRL) $(HEADER)
	$(CC) $(STRLFLAGS) $(STRLINC) -c -o $@ $< 

allclean : clean

clean4strl :
	$(RM) $(OBJ4STRL) 

clean :
	$(RM) $(OBJ4STRL) *.sc *.ssc *.blif *.ctbl *.log

