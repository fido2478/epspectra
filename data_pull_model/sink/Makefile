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
	$(ESTEREL_V603) -sub -sc SINK.strl

Opt : 
	$(ESTEREL_V603) -blif -sub -B SINK SINK.strl \
	../submodule/GET_SAMPLE_RANGE.strl \
	../submodule/MARK_DATA.strl \
	../submodule/COMPUTE_DATA.strl 
	$(AREAOPT_V603) SINK_d
	$(BLIFSC_V603) -ctbl SINK.ctbl -sblif SINK_s.blif \
	SINK_d.opt.blif > SINK.sc
	$(RM) SINK.ctbl SINK_*.blif

Indiv_Opt:
	$(ESTEREL_V6) -sub -sc SINK.strl
#	sclink -nocopy SINK.sc \
#	../submodule/GET_SAMPLE_RANGE.sc \
#	../submodule/MARK_DATA.sc \
#	../submodule/COMPUTE_DATA.sc > SINK_SC


world : $(OBJ4STRL) 

c4strl : $(OBJ4STRL)  

$(OBJ4STRL) : $(C4STRL) $(HEADER)
	$(CC) $(STRLFLAGS) $(STRLINC) -c -o $@ $< 

allclean : clean

clean4strl :
	$(RM) $(OBJ4STRL) 

clean :
	$(RM) $(OBJ4STRL) *.ssc *.sc *.ctbl *.blif *.log 

