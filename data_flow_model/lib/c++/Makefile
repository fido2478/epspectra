BASE_DIR := ..
include ../../Makefile.include

OBJS := $(patsubst %.cc, %.o, $(wildcard *.cc))
#OBJ4CC := $(wildcard *.cc)
#HEADER := $(wildcard *.h) $(CCINC)

I386_OBJS := $(patsubst %.s,%.o,$(wildcard *.s))

ifdef MMX
  MACHDEP_OBJS = $(I386_OBJS)
endif

all : world

gsm : $(OBJS) $(MACHDEP_OBJS) $(MOCOBJS)
	$(CC) $(CFLAGS) -shared -o libspectra.so $(OBJS) $(MACHDEP_OBJS) $(MOCOBJS)

world : $(OBJS) $(MACHDEP_OBJS) $(MOCOBJS)
	$(CC) $(CFLAGS) -shared -o libspectra.so $(OBJS) $(MACHDEP_OBJS) $(MOCOBJS)

c4strl : $(OBJ4CC)

%.o: %.cc %.h
	$(G++) $(CFLAGS) $(CCINC)  -c -o $@ $<

$(I386_OBJS): %.o: %.s
	$(AS) -f elf -o $@ $<

allclean :
	$(RM) $(OBJ4CC)

gsmclean: clean

clean: 
	$(RM) $(SETOFREMOVE) *.so *.a 
