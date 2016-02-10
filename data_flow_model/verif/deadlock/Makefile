err1 : 
	esterelv6_03-3 -causal -simul -B UDP_FLOW1 UDP_FLOW.strl SOURCE.strl P_MOD.strl SINK.strl MARK_DATA_VER1.strl COMPUTE_DATA_VER1.strl SWITCH.strl TIMER.strl WAIT_SIG.strl
	cc -c -o UDP_FLOW1.o UDP_FLOW1.c
	xes UDP_FLOW1.o

err2 :
	esterelv6_03-3 -causal -simul -B UDP_FLOW2 UDP_FLOW.strl SOURCE.strl P_MOD.strl SINK.strl MARK_DATA_VER2.strl COMPUTE_DATA_VER2.strl SWITCH_VER2.strl TIMER.strl WAIT_SIG.strl
	cc -c -o UDP_FLOW2.o UDP_FLOW2.c
	xes UDP_FLOW2.o
clean :
	rm UDP_FLOW1.o UDP_FLOW1.c UDP_FLOW2.o UDP_FLOW2.c
