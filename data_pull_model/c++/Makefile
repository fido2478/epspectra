SPECTRA_BASE := ..
include ../Makefile.include

OBJS := $(patsubst %.cc, %.o, $(wildcard *.cc))
#SOC4CC := $(wildcard *.cc)
#HEADER := $(wildcard *.h) $(INC)

I386_OBJS := $(patsubst %.s,%.o,$(wildcard *.s))

ifdef MMX
  MACHDEP_OBJS = $(I386_OBJS)
endif

all : world

world : $(OBJS) $(MACHDEP_OBJS) $(MOCOBJS) #$(OBJ4CC)

c4strl : $(OBJ4CC)

%.o: %.cc %.h
	$(G++) $(CFLAGS) $(INC) -c -o $@ $<

$(I386_OBJS): %.o: %.s
	$(AS) -f elf -o $@ $<

clean4strl :
	$(RM) $(OBJ4CC)
clean: 
	$(RM) *.o *.so *.a #$(OBJ4CC)
