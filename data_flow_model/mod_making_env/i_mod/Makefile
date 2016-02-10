################################################################
# This is Makefile to compile C file for esterel.
################################################################

include ../makefile.include

OBJ4STRL := $(patsubst %_data.c, %_data.o, $(wildcard *_data.c))
C4STRL := $(wildcard *_data.c)
HEADER := $(wildcard *.h)

all   : world

world : $(OBJ4STRL) 

c4strl : $(OBJ4STRL)  

$(OBJ4STRL) : $(C4STRL) $(HEADER)
	$(CC) $(STRLFLAGS) -c -o $@ $< 

allclean : clean

clean4strl :
	$(RM) $(OBJ4STRL) 

clean :
	$(RM) $(OBJ4STRL)

