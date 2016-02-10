##############################################################
# For the application without Time-Constraint functionality
# based on Data-Flow Model,
# This Makefile gives three kinds of compilation mode :
# 1.type "make" which corresponds to generating C codes with non-opt,
# 2.type "make iclevel_opt" which generates iclevel-optimized C codes, and
# 3.type "make modulo_opt" which generates modulo-optimized C codes.
################################################################

include ../../Makefile.include

STRL_FILES = 	SOURCE.strl \
		P_MOD.strl \
		P_MOD1to2.strl \
		SINK.strl \
		COMP_DATA.strl \
		FIT_RANGE_MOD.strl \
		FIT_RANGE_SNK.strl \
		FIT_RANGE_SRC.strl \
		SWITCH.strl \
		WAIT_SIG1.strl \
		WAIT_SIG2.strl \
		TIMER.strl \
		Safety.strl \
		Safety_Liveness.strl \
		CONVERTOR1.strl \
		CONVERTOR2.strl
#		MONITOR.strl \

CC = cc -c

#######################
# generate C code without optimization
#######################
all : iclevel_opt

xes : 
	$(ESTEREL) -simul -B UDP_FLOW UDP_FLOW.strl $(STRL_FILES)
	$(CC) -o UDP_FLOW.o UDP_FLOW.c
	$(CC) -o UDP_FLOW_data.o UDP_FLOW_data.c
	$(XES) -o UDP_FLOW UDP_FLOW.o UDP_FLOW_data.o
#######################
# optimization mode
#######################

##################
# ic linking level
##################

iclevel_opt : clean
	$(ESTEREL) -blif -B UDP_FLOW UDP_FLOW.strl $(STRL_FILES)
	$(REMLATCH) UDP_FLOW.blif
	$(AREAOPT) UDP_FLOW.opt
#	$(BLIFSC) -ctbl UDP_FLOW.ctbl UDP_FLOW.opt.opt.blif > UDP_FLOW.icopt.sc
#	$(ESTEREL) UDP_FLOW.icopt.sc

##################
#global modulo opt
##################
glmodulo_opt : clean src_module i_module snk_module
	$(ESTEREL) -sc UDP_FLOW.strl
	$(SCLINK) -nocopy UDP_FLOW.sc SOURCE.sc \
	P_MOD.sc P_MOD1to2.sc SINK.sc SCOPESINK.sc > UDP_FLOW.gl.sc
	$(ESTEREL) -blif UDP_FLOW.gl.sc
	$(REMLATCH) UDP_FLOW.gl.blif
	$(AREAOPT) UDP_FLOW.gl.opt
	$(BLIFSC) -ctbl UDP_FLOW.gl.ctbl UDP_FLOW.gl.opt.opt.blif >
	UDP_FLOW.glmodopt.sc
	$(ESTEREL) UDP_FLOW.glmodopt.sc

###################
##sc linking level
###################
modulo_opt : clean src_module i_module snk_module
	$(ESTEREL) -sc UDP_FLOW.strl
	$(SCLINK) -nocopy UDP_FLOW.sc SOURCE.sc \
	P_MOD.sc P_MOD1to2.sc SINK.sc SCOPESINK.sc > UDP_FLOW.modopt.sc
	$(ESTEREL) UDP_FLOW.modopt.sc

src_module :
	$(ESTEREL) -blif -sub -B SOURCE \
	SOURCE.strl FIT_RANGE_SRC.strl COMP_DATA.strl \
	TIMER.strl
	$(AREAOPT) SOURCE_d
	$(BLIFSC) -ctbl SOURCE.ctbl -sblif SOURCE_s.blif \
	SOURCE_d.opt.blif > SOURCE.sc

i_module :
	$(ESTEREL) -blif -sub -B P_MOD \
	P_MOD.strl FIT_RANGE_MOD.strl COMP_DATA.strl \
	TIMER.strl \
	SWITCH.strl WAIT_SIG1.strl
	$(AREAOPT) P_MOD_d
	$(BLIFSC) -ctbl P_MOD.ctbl -sblif P_MOD_s.blif \
	P_MOD_d.opt.blif > P_MOD.sc
#
	$(ESTEREL) -blif -sub -B P_MOD1to2 \
	P_MOD1to2.strl FIT_RANGE_MOD.strl COMP_DATA.strl \
	TIMER.strl \
	SWITCH.strl WAIT_SIG1.strl \
	WAIT_SIG2.strl 
	$(AREAOPT) P_MOD1to2_d
	$(BLIFSC) -ctbl P_MOD1to2.ctbl -sblif P_MOD1to2_s.blif \
	P_MOD1to2_d.opt.blif > P_MOD1to2.sc

snk_module :
	$(ESTEREL) -blif -sub -B SINK \
	SINK.strl FIT_RANGE_SNK.strl COMP_DATA.strl \
	SWITCH.strl
	$(AREAOPT) SINK_d
	$(BLIFSC) -ctbl SINK.ctbl -sblif SINK_s.blif \
	SINK_d.opt.blif > SINK.sc
#
	$(ESTEREL) -blif -sub -B SCOPESINK \
	SCOPESINK.strl FIT_RANGE_SNK.strl SWITCH.strl
	$(AREAOPT) SCOPESINK_d
	$(BLIFSC) -ctbl SCOPESINK.ctbl -sblif SCOPESINK_s.blif \
	SCOPESINK_d.opt.blif > SCOPESINK.sc

############################
clean :
	$(RM) *.ctbl *.sc *.ic *.log
