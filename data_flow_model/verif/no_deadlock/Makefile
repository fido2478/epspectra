all:  clean xes

xes : UDP_FLOW.o
	xes UDP_FLOW.o

UDP_FLOW.o : UDP_FLOW.c
	cc -c -o UDP_FLOW.o UDP_FLOW.c
UDP_FLOW.c :
	esterelv6_03-3 -causal -simul -B UDP_FLOW UDP_FLOW.strl SOURCE.strl P_MOD.strl P_MOD1.strl P_MOD1to2.strl SINK.strl SCOPESINK.strl MARK_DATA.strl COMPUTE_DATA4SRC.strl COMPUTE_DATA4SINK.strl COMPUTE_DATA4SINK1.strl COMPUTE_DATA.strl COMPUTE_DATA1.strl COMPUTE_DATA2.strl SWITCH.strl TIMER.strl WAIT_SIG.strl WAIT_SIG2.strl

clean :
	rm -f UDP_FLOW.o UDP_FLOW.c
