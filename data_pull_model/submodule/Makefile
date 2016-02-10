################################################################
# This is Makefile to compile C file for esterel.
################################################################
SPECTRA_BASE := ..
include ../Makefile.include

OBJ4STRL := $(patsubst %_data.c, %_data.o, $(wildcard *_data.c))
C4STRL := $(wildcard *_data.c)
HEADER := $(wildcard *.h)

all   : world

Mini_Opt:
## MARK_DATA Optimizing
	$(ESTEREL_V603) -blif -sub MARK_DATA.strl
	$(AREAOPT_V603) MARK_DATA_d
	$(BLIFSC_V603) -ctbl MARK_DATA.ctbl -sblif MARK_DATA_s.blif \
	MARK_DATA_d.opt.blif > MARK_DATA.sc
	$(RM) MARK_DATA.ctbl MARK_DATA_*.blif
## COMPUTE_DATA Optimizing
	$(ESTEREL_V603) -blif -sub -B COMPUTE_DATA COMPUTE_DATA.strl
	$(AREAOPT_V603) COMPUTE_DATA_d
	$(BLIFSC_V603) -ctbl COMPUTE_DATA.ctbl \
	-sblif COMPUTE_DATA_s.blif COMPUTE_DATA_d.opt.blif \
	> COMPUTE_DATA.sc
	$(RM) COMPUTE_DATA.ctbl COMPUTE_DATA_*.blif

TopLevel:Opt

Opt   :

Indiv_Opt:
## MARK_DATA Optimizing
	$(ESTEREL_V603) -blif -sub MARK_DATA.strl
	$(AREAOPT_V603) MARK_DATA_d
	$(BLIFSC_V603) -ctbl MARK_DATA.ctbl -sblif MARK_DATA_s.blif \
	MARK_DATA_d.opt.blif > MARK_DATA.sc
	$(RM) MARK_DATA.ctbl MARK_DATA_*.blif
## COMPUTE_DATA Optimizing
	$(ESTEREL_V603) -blif -sub COMPUTE_DATA.strl
	$(AREAOPT_V603) COMPUTE_DATA_d
	$(BLIFSC_V603) -ctbl COMPUTE_DATA.ctbl \
	-sblif COMPUTE_DATA_s.blif COMPUTE_DATA_d.opt.blif \
	> COMPUTE_DATA.sc
	$(RM) COMPUTE_DATA.ctbl COMPUTE_DATA_*.blif
## MARK_DATA_SRC Optimizing
	$(ESTEREL_V603) -blif -sub MARK_DATA_SRC.strl
	$(AREAOPT_V603) MARK_DATA_SRC_d
	$(BLIFSC_V603) -ctbl MARK_DATA_SRC.ctbl -sblif MARK_DATA_SRC_s.blif \
	MARK_DATA_SRC_d.opt.blif > MARK_DATA_SRC.sc
	$(RM) MARK_DATA_SRC.ctbl MARK_DATA_SRC_*.blif
## COMPUTE_DATA_SRC Optimizing
	$(ESTEREL_V603) -blif -sub COMPUTE_DATA_SRC.strl
	$(AREAOPT_V603) COMPUTE_DATA_SRC_d
	$(BLIFSC_V603) -ctbl COMPUTE_DATA_SRC.ctbl \
	-sblif COMPUTE_DATA_SRC_s.blif COMPUTE_DATA_SRC_d.opt.blif \
	> COMPUTE_DATA_SRC.sc
	$(RM) COMPUTE_DATA_SRC.ctbl COMPUTE_DATA_SRC_*.blif

world : MARK_DATA_data.o COMPUTE_DATA_data.o 

c4strl : MARK_DATA_data.o COMPUTE_DATA_data.o 

MARK_DATA_data.o : MARK_DATA_data.c MARK_DATA.h
	$(CC) $(STRLFLAGS) $(STRLINC) -c -o $@ $<

COMPUTE_DATA_data.o : COMPUTE_DATA_data.c COMPUTE_DATA.h
	$(CC) $(STRLFLAGS) $(STRLINC) -c -o $@ $<

allclean : clean

clean4strl :
	$(RM) $(OBJ4STRL) *.ssc *.sc *.blif *.ctbl *.log 

clean :
	$(RM) $(OBJ4STRL) *.ssc *.sc *.blif *.ctbl *.log 

