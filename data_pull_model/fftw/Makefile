# $Id: Makefile,v 1.1.1.1 1999/04/06 20:44:28 brettv Exp $

LIBFFT = libfftw.a
HEADERS = fftw.h
INCLUDE = -I.
prefix = /usr/local
LIBDIR = $(prefix)/lib
INCLUDEDIR = $(prefix)/include
RM = rm
CP = cp
MAKE = make

# On systems that have ranlib:
RANLIB = ranlib

# On systems that don't have ranlib
# RANLIB = echo ranlib

# Generic gcc
CC = gcc
CFLAGS = -pedantic -ansi -O6 -fomit-frame-pointer -Wall $(INCLUDE)

# Solaris:
# CC = cc
# CFLAGS = -DSOLARIS -native -fast -xO5 -dalign $(INCLUDE)

# IBM RS/6000:
# CC=cc
# CFLAGS = -O3 -qarch=pwrx -qtune=pwrx $(INCLUDE)

# SGI Onyx
# CC=cc
# CFLAGS=-64 -r10000 -OPT:fold_arith_limit=10000 -O3 $(INCLUDE)

# Filename prefixes:

#NOTW_PREFIX=fftw_notw_
#TWID_PREFIX=fftw_twid_
#NOTWI_PREFIX=fftwi_notw_
#TWIDI_PREFIX=fftwi_twid_

# # Or, on primitive systems with 8.3 filenames:
NOTW_PREFIX=fn_
TWID_PREFIX=ftw_
NOTWI_PREFIX=fni_
TWIDI_PREFIX=ftwi_

NOTW_BLOCKS=$(NOTW_PREFIX)1.o $(NOTW_PREFIX)2.o $(NOTW_PREFIX)3.o     \
	$(NOTW_PREFIX)4.o $(NOTW_PREFIX)5.o $(NOTW_PREFIX)6.o         \
	$(NOTW_PREFIX)7.o $(NOTW_PREFIX)8.o $(NOTW_PREFIX)9.o         \
	$(NOTW_PREFIX)10.o $(NOTW_PREFIX)11.o $(NOTW_PREFIX)12.o      \
	$(NOTW_PREFIX)13.o $(NOTW_PREFIX)14.o $(NOTW_PREFIX)15.o      \
	$(NOTW_PREFIX)16.o $(NOTW_PREFIX)32.o $(NOTW_PREFIX)64.o      

TWID_BLOCKS=$(TWID_PREFIX)2.o $(TWID_PREFIX)3.o $(TWID_PREFIX)4.o     \
	$(TWID_PREFIX)5.o $(TWID_PREFIX)6.o $(TWID_PREFIX)7.o         \
	$(TWID_PREFIX)8.o $(TWID_PREFIX)9.o $(TWID_PREFIX)10.o        \
	$(TWID_PREFIX)16.o $(TWID_PREFIX)32.o $(TWID_PREFIX)64.o

NOTWI_BLOCKS=$(NOTWI_PREFIX)1.o $(NOTWI_PREFIX)2.o $(NOTWI_PREFIX)3.o \
	$(NOTWI_PREFIX)4.o $(NOTWI_PREFIX)5.o $(NOTWI_PREFIX)6.o      \
	$(NOTWI_PREFIX)7.o $(NOTWI_PREFIX)8.o $(NOTWI_PREFIX)9.o      \
	$(NOTWI_PREFIX)10.o $(NOTWI_PREFIX)11.o $(NOTWI_PREFIX)12.o   \
	$(NOTWI_PREFIX)13.o $(NOTWI_PREFIX)14.o $(NOTWI_PREFIX)15.o   \
	$(NOTWI_PREFIX)16.o $(NOTWI_PREFIX)32.o $(NOTWI_PREFIX)64.o

TWIDI_BLOCKS=$(TWIDI_PREFIX)2.o $(TWIDI_PREFIX)3.o                   \
	$(TWIDI_PREFIX)4.o $(TWIDI_PREFIX)5.o $(TWIDI_PREFIX)6.o    \
	$(TWIDI_PREFIX)7.o $(TWIDI_PREFIX)8.o $(TWIDI_PREFIX)9.o    \
	$(TWIDI_PREFIX)10.o $(TWIDI_PREFIX)16.o $(TWIDI_PREFIX)32.o \
        $(TWIDI_PREFIX)64.o

NOTW_SRC=$(NOTW_PREFIX)1.c $(NOTW_PREFIX)2.c $(NOTW_PREFIX)3.c        \
	$(NOTW_PREFIX)4.c $(NOTW_PREFIX)5.c $(NOTW_PREFIX)6.c         \
	$(NOTW_PREFIX)7.c $(NOTW_PREFIX)8.c $(NOTW_PREFIX)9.c         \
	$(NOTW_PREFIX)10.c $(NOTW_PREFIX)11.c $(NOTW_PREFIX)12.c      \
	$(NOTW_PREFIX)13.c $(NOTW_PREFIX)14.c $(NOTW_PREFIX)15.c      \
	$(NOTW_PREFIX)16.c $(NOTW_PREFIX)32.c $(NOTW_PREFIX)64.c

TWID_SRC=$(TWID_PREFIX)2.c $(TWID_PREFIX)3.c $(TWID_PREFIX)4.c        \
	$(TWID_PREFIX)5.c $(TWID_PREFIX)6.c $(TWID_PREFIX)7.c         \
	$(TWID_PREFIX)8.c $(TWID_PREFIX)9.c $(TWID_PREFIX)10.c        \
	$(TWID_PREFIX)16.c $(TWID_PREFIX)32.c $(TWID_PREFIX)64.c

NOTWI_SRC=$(NOTWI_PREFIX)1.c $(NOTWI_PREFIX)2.c $(NOTWI_PREFIX)3.c    \
	$(NOTWI_PREFIX)4.c $(NOTWI_PREFIX)5.c $(NOTWI_PREFIX)6.c      \
	$(NOTWI_PREFIX)7.c $(NOTWI_PREFIX)8.c $(NOTWI_PREFIX)9.c      \
	$(NOTWI_PREFIX)10.c $(NOTWI_PREFIX)11.c $(NOTWI_PREFIX)12.c   \
	$(NOTWI_PREFIX)13.c $(NOTWI_PREFIX)14.c $(NOTWI_PREFIX)15.c   \
	$(NOTWI_PREFIX)16.c $(NOTWI_PREFIX)32.c $(NOTWI_PREFIX)64.c

TWIDI_SRC=$(TWIDI_PREFIX)2.c $(TWIDI_PREFIX)3.c $(TWIDI_PREFIX)4.c  \
	$(TWIDI_PREFIX)5.c $(TWIDI_PREFIX)6.c $(TWIDI_PREFIX)7.c    \
	$(TWIDI_PREFIX)8.c $(TWIDI_PREFIX)9.c $(TWIDI_PREFIX)10.c   \
	$(TWIDI_PREFIX)16.c $(TWIDI_PREFIX)32.c $(TWIDI_PREFIX)64.c

OTHEROBJ = timer.o config.o planner.o twiddle.o executor.o naive.o \
	generic.o fftwnd.o malloc.o wisdom.o common_io.o

BLOCKS = $(NOTW_BLOCKS) $(NOTWI_BLOCKS) $(TWID_BLOCKS) $(TWIDI_BLOCKS) 

ALLOBJ = $(BLOCKS) $(OTHEROBJ)


all:	$(LIBFFT) 

world: $(LIBFFT)

install: $(LIBFFT)
	$(CP) $(LIBFFT) $(LIBDIR)
	$(RANLIB) $(LIBDIR)/$(LIBFFT)
	$(CP) $(HEADERS) $(INCLUDEDIR)

$(LIBFFT): $(ALLOBJ)
	$(RM) -f $(LIBFFT)
	$(AR) rv $(LIBFFT) $(ALLOBJ)
	$(RANLIB) $(LIBFFT)

sources: 
	$(MAKE) -f Makefile.sources $(NOTW_SRC) $(NOTWI_SRC) \
	     $(TWID_SRC) $(TWIDI_SRC) \
	     NOTW_PREFIX=$(NOTW_PREFIX)     \
	     NOTWI_PREFIX=$(NOTWI_PREFIX)   \
	     TWID_PREFIX=$(TWID_PREFIX)     \
	     TWIDI_PREFIX=$(TWIDI_PREFIX)

allclean: clean

realclean: clean
	$(RM) -f $(LIBFFT)  $(NOTW_SRC) $(NOTWI_SRC) $(TWID_SRC) $(TWIDI_SRC)

clean:
	$(RM) -f *.o *~ core a.out test gmon.out mon.out *.zi *.zo *.s genfft

$(ALLOBJ): $(HEADERS) konst.h

