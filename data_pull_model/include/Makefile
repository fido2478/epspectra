################################################################
# This is Makefile to compile C file for esterel.
################################################################
SPECTRA_BASE := ..
include ../Makefile.include

OBJ4STRL := $(patsubst %_data.c, %_data.o, $(wildcard *_data.c))
C4STRL := $(wildcard *_data.c)
HEADER := $(wildcard *.h)
#STRLFLAGS := -DSTRLEN=80

all   : world

Opt : world

world : $(OBJ4STRL) 

c4strl : $(OBJ4STRL)  

%_data.o: %_data.c %.h
	$(CC) $(CFLAGS) $(STRLINC) -c -o $@ $<

#$(OBJ4STRL) : $(C4STRL) $(HEADER)
#	$(CC) $(STRLFLAGS) -c -o $@ $< 

allclean : clean

clean4strl :
	$(RM) $(OBJ4STRL) 

clean :
	$(RM) $(OBJ4STRL)

