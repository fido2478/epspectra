include ../../../Makefile.include

SRC = .
SNK = .
I_MOD =  .
SUBMOD = .

STRL_FILES = 	$(SRC)/SOURCE.strl \
		$(I_MOD)/P_MOD.strl \
		$(I_MOD)/P_MOD1to2.strl \
		$(SNK)/SINK.strl \
		$(SUBMOD)/INITIALIZE_SINK.strl \
		$(SUBMOD)/COMP_DATA.strl \
		$(SUBMOD)/FIT_RANGE_MOD.strl \
		$(SUBMOD)/FIT_RANGE_SNK.strl \
		$(SUBMOD)/FIT_RANGE_SRC.strl \
		$(SUBMOD)/SWITCH.strl \
		$(SUBMOD)/WAIT_SIG1.strl \
		$(SUBMOD)/WAIT_SIG2.strl \
		$(SUBMOD)/TIMER.strl

all: UDP_FLOW.o
	$(XES) UDP_FLOW.o
ddd: UDP_FLOW.g
	$(DDDXES) UDP_FLOW.o
UDP_FLOW.g : UDP_FLOW
	$(C2O) $(DBUG) $(NAMING) UDP_FLOW.c

UDP_FLOW.o : UDP_FLOW
	$(C2O) $(NAMING) UDP_FLOW.c
UDP_FLOW : 
	$(ESTEREL_V603) $(CYCL_SIMUL) $(STRL_NAMING) UDP_FLOW.strl $(STRL_FILES)

clean :
	rm UDP_FLOW.o UDP_FLOW.c
