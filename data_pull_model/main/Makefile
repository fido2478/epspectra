SPECTRA_BASE := ..
include ../Makefile.include

all : world

world : 
	$(CC) -c $(INC) -o lib4main.o lib4main.c $(STRLINC) $(CFLAGS)
	$(CC) -c $(INC) -o main_perf.o main_perf.c $(STRLINC) $(CFLAGS)
#	$(CC) -c $(INC) -o main.o main.c  $(STRLINC) $(CFLAGS)

clean :
	$(RM)  *.o a.out
