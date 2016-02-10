STRL_FILES = 	SOURCE.strl \
		P_MOD.strl \
		SINK.strl \
		INITIALIZE_SINK.strl \
		GET_SAMPLE_RANGE.strl \
		MARK_DATA.strl \
		MARK_DATA_SRC.strl \
		COMPUTE_DATA.strl \
		GET_MY_MARKED_DATA.strl 

all: 
	esterel -causal -B OPT_STRL OPT_STRL.strl $(STRL_FILES)

clean :
	rm OPT_STRL.o OPT_STRL.c
