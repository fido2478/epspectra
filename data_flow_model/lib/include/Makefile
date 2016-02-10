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


################################################################
# This is Makefile to compile C file for esterel.
################################################################
include ../../Makefile.include

OBJ4STRL := $(patsubst %_data.c, %_data.o, $(wildcard *_data.c))
C4STRL := $(wildcard *_data.c)
HEADER := $(wildcard *.h)

all   : world

gsm   : world

world : $(OBJ4STRL) 

%_data.o: %_data.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

allclean : clean

gsmclean: clean

clean :
	$(RM) $(OBJ4STRL)

