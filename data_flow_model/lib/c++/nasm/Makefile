# Unix fall-back makefile for the Netwide Assembler. For use if
# `configure' fails to generate a workable Makefile.
#
# The Netwide Assembler is copyright (C) 1996 Simon Tatham and
# Julian Hall. All rights reserved. The software is
# redistributable under the licence given in the file "Licence"
# distributed in the NASM archive.

# You may need to adjust these values.

prefix = /usr/local
#CC = cc
CC = gcc
#CFLAGS =  -g -I.
CFLAGS = -O -I.

# You _shouldn't_ need to adjust anything below this line.

exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin
mandir = ${prefix}/man

INSTALL = install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
PERL = echo comment

.c.o:
	$(CC) -c $(CFLAGS) $*.c

NASM = nasm.o nasmlib.o float.o insnsa.o assemble.o labels.o \
       parser.o outform.o outbin.o outaout.o outcoff.o outelf.o \
       outobj.o outas86.o outrdf.o outdbg.o preproc.o listing.o \
       eval.o

NDISASM = ndisasm.o disasm.o sync.o nasmlib.o insnsd.o

all: nasm

gsm: nasm

world : nasm

nasm: $(NASM)
	$(CC) -o nasm $(NASM)

ndisasm: $(NDISASM)
	$(CC) -o ndisasm $(NDISASM)

assemble.o: assemble.c nasm.h nasmlib.h assemble.h insns.h
disasm.o: disasm.c nasm.h disasm.h sync.h insns.h names.c
eval.o: eval.c eval.h nasm.h nasmlib.h
float.o: float.c nasm.h
insnsa.o: insnsa.c nasm.h insns.h
insnsd.o: insnsd.c nasm.h insns.h
labels.o: labels.c nasm.h nasmlib.h
listing.o: listing.c nasm.h nasmlib.h listing.h
nasm.o: nasm.c nasm.h nasmlib.h preproc.h parser.h assemble.h labels.h \
 outform.h listing.h
nasmlib.o: nasmlib.c nasm.h nasmlib.h
ndisasm.o: ndisasm.c nasm.h nasmlib.h sync.h disasm.h
outaout.o: outaout.c nasm.h nasmlib.h outform.h
outas86.o: outas86.c nasm.h nasmlib.h outform.h
outbin.o: outbin.c nasm.h nasmlib.h outform.h
outcoff.o: outcoff.c nasm.h nasmlib.h outform.h
outdbg.o: outdbg.c nasm.h nasmlib.h outform.h
outelf.o: outelf.c nasm.h nasmlib.h outform.h
outform.o: outform.c outform.h nasm.h
outobj.o: outobj.c nasm.h nasmlib.h outform.h
outrdf.o: outrdf.c nasm.h nasmlib.h outform.h
parser.o: parser.c nasm.h nasmlib.h parser.h float.h names.c
preproc.o: preproc.c nasm.h nasmlib.h macros.c
sync.o: sync.c sync.h

# These two source files are automagically generated from a single
# instruction-table file by a Perl script. They're distributed,
# though, so it isn't necessary to have Perl just to recompile NASM
# from the distribution.

insnsa.c insnsd.c: insns.dat insns.pl
	$(PERL) insns.pl insns.dat

# This source file is generated from the standard macros file
# `standard.mac' by another Perl script. Again, it's part of the
# standard distribution.

macros.c: standard.mac macros.pl
	$(PERL) macros.pl standard.mac

install: nasm ndisasm
	$(INSTALL_PROGRAM) nasm $(bindir)/nasm
	$(INSTALL_PROGRAM) ndisasm $(bindir)/ndisasm
	$(INSTALL_DATA) nasm.1 $(mandir)/man1/nasm.1
	$(INSTALL_DATA) ndisasm.1 $(mandir)/man1/ndisasm.1

allclean: clean

gsmclean: clean

clean:
	rm -f *.o nasm ndisasm

rdf:
	$(MAKE) -C rdoff

rdf_install install_rdf:
	$(MAKE) -C rdoff install
