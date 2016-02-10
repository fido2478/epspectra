##############################################################
# For the application without Time-Constraint functionality
# based on Data-Flow Model,
# This Makefile gives three kinds of compilation mode :
# 1.type "make" which corresponds to generating C codes with non-opt,
# 2.type "make iclevel_opt" which generates iclevel-optimized C codes, and
# 3.type "make modulo_opt" which generates modulo-optimized C codes.
################################################################

include ../Makefile.include

STRL_FILES = 	TC_SOURCE.strl \
		P_MOD.strl \
		P_MOD1to2.strl \
		SINK.strl \
		COMP_DATA.strl \
		TC_FIT_RANGE_MOD.strl \
		TC_FIT_RANGE_SNK.strl \
		TC_FIT_RANGE_SRC.strl \
		SWITCH.strl \
		WAIT_SIG1.strl \
		WAIT_SIG2.strl \
		TIMER.strl 

#######################
# generate C code without optimization
#######################
all : clean
	$(ESTEREL) -B TC_UDP_TX TC_UDP_TX.strl $(STRL_FILES)


xes : all
	$(CC) -o TC_UDP_TX.o TC_UDP_TX.c
	$(CC) -o TC_UDP_TX_data.o TC_UDP_TX_data.c
	$(XES) -o TC_UDP_TX TC_UDP_TX.o TC_UDP_TX_data.o
#######################
# optimization mode
#######################

##################
# SAXO-RT
##################
saxo : clean
	$(SAXORT) 

##################
# ic linking level
##################
iclevel_opt : clean
	$(ESTEREL) -blif -B TC_UDP_TX TC_UDP_TX.strl $(STRL_FILES)
	$(REMLATCH) TC_UDP_TX.blif
	$(AREAOPT) TC_UDP_TX.opt
	$(BLIFSC) -ctbl TC_UDP_TX.ctbl TC_UDP_TX.opt.opt.blif > \
	TC_UDP_TX.icopt.sc
	$(ESTEREL) TC_UDP_TX.icopt.sc

##################
#global modulo opt
##################
glmodulo_opt : clean src_module i_module snk_module
	$(ESTEREL) -sc TC_UDP_TX.strl
	$(SCLINK) -nocopy TC_UDP_TX.sc SOURCE.sc \
	P_MOD.sc P_MOD1to2.sc SINK.sc SCOPESINK.sc > TC_UDP_TX.gl.sc
	$(ESTEREL) -blif TC_UDP_TX.gl.sc
	$(REMLATCH) TC_UDP_TX.gl.blif
	$(AREAOPT) TC_UDP_TX.gl.opt
	$(BLIFSC) -ctbl TC_UDP_TX.gl.ctbl TC_UDP_TX.gl.opt.opt.blif >
	TC_UDP_TX.glmodopt.sc
	$(ESTEREL) TC_UDP_TX.glmodopt.sc

###################
##sc linking level
###################
modulo_opt : clean src_module i_module snk_module
	$(ESTEREL) -sc TC_UDP_TX.strl
	$(SCLINK) -nocopy TC_UDP_TX.sc SOURCE.sc \
	P_MOD.sc P_MOD1to2.sc SINK.sc SCOPESINK.sc > TC_UDP_TX.modopt.sc
	$(ESTEREL) TC_UDP_TX.modopt.sc

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
