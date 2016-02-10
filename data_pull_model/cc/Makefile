################################################################
# This is Makefile to compile C++ file as a role in Interface.
################################################################

SPECTRA_BASE = ..
include ../Makefile.include 
 
OBJ4CC := $(patsubst %.cc, %.o, $(wildcard *.cc))
SOC4CC := $(wildcard *.cc)
HEADER := $(wildcard *.h) $(INC)

all : world
 
world : $(OBJ4CC)

c4strl : $(OBJ4CC)
 
%.o: %.cc %.h
	$(G++) $(CFLAGS) $(CCINC) -c -o $@ $< 

#$(OBJ4CC) : $(SOC4CC) #$(HEADER)
#	$(G++) $(STRLFLAGS) -c $< -o $@ $(INC) $(DEFINES)

allclean : clean

clean4strl :
	$(RM) $(OBJ4CC)  
clean :
	$(RM) $(OBJ4CC)  
