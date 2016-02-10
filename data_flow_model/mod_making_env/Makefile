all: xes

xes : UDP_FLOW.o
	xes UDP_FLOW.o

UDP_FLOW.o : UDP_FLOW.c
	cc -c -o UDP_FLOW.o UDP_FLOW.c
UDP_FLOW.c :
	esterel -causal -simul -B UDP_FLOW UDP_FLOW.strl src/SOURCE.strl i_mod/P_MOD.strl i_mod/P_MOD1to2.strl snk/SINK.strl submod/MARK_DATA.strl submod/COMPUTE_DATA4SINK.strl submod/COMPUTE_DATA.strl submod/COMPUTE_DATA2.strl submod/SWITCH.strl submod/TIMER.strl submod/WAIT_SIG.strl submod/WAIT_SIG2.strl

verif2 :
	esterel -causal -simul -B UDP_FLOW UDP_FLOW.strl SOURCE.strl P_MOD.strl SINK.strl MARK_DATA_VER2.strl COMPUTE_DATA_VER2.strl SWITCH.strl TIMER.strl WAIT_SIG.strl
	cc -c -o UDP_FLOW.o UDP_FLOW.c
	xes UDP_FLOW.o
clean :
	rm UDP_FLOW.o UDP_FLOW.c
