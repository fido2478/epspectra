/* "SAXORT STRL Compiler version 3.0 compiled on Fri Mar 30 11:02:53 MET DST 2001" */

/* automaton kernel code*/
#include <stdlib.h>
#include <stdio.h>
#include "UDP_FLOW_strlcc.h"
#define SIZEOFINT 32
#define B_SET_VECTOR_MASK(i) ((unsigned int)1 << i)
#define B_RES_VECTOR_MASK(i) (~((unsigned int)1 << i))
#define BIT_SET(b_vector, bit_number) b_vector[(bit_number) / SIZEOFINT] |= B_SET_VECTOR_MASK((bit_number) % SIZEOFINT)
#define BIT_RESET(b_vector, bit_number) b_vector[(bit_number) / SIZEOFINT] &= ~B_SET_VECTOR_MASK((bit_number) % SIZEOFINT)
#define BIT_VALUE(b_vector, bit_number) b_vector[(bit_number) / SIZEOFINT] & B_SET_VECTOR_MASK((bit_number) % SIZEOFINT)

#define SET_ON(point) current_point_bit_vector[point / SIZEOFINT] |= B_SET_VECTOR_MASK(point % SIZEOFINT)
#define SET_OFF(point) current_point_bit_vector[point / SIZEOFINT] &= ~B_SET_VECTOR_MASK(point % SIZEOFINT)
#define IS_ON(point) (current_point_bit_vector[point / SIZEOFINT] & B_SET_VECTOR_MASK(point % SIZEOFINT))
#define SET_PAUSE_ON(point) next_point_bit_vector[point / SIZEOFINT] |= B_SET_VECTOR_MASK(point % SIZEOFINT)
#define SET_PAUSE_OFF(point) next_point_bit_vector[point / SIZEOFINT] &= ~B_SET_VECTOR_MASK(point % SIZEOFINT)
#define IS_PAUSE_ON(point) (next_point_bit_vector[point / SIZEOFINT] & B_SET_VECTOR_MASK(point % SIZEOFINT))

#define HALT_POINT_NUM 158
#define HALT_POINT_VECTOR_SIZE ((HALT_POINT_NUM-1)/(int)SIZEOFINT)+1
static unsigned int current_point_bit_vector[HALT_POINT_VECTOR_SIZE];
static unsigned int next_point_bit_vector[HALT_POINT_VECTOR_SIZE];

#define SIGNAL_NUM 90
#define SIGNAL_VECTOR_SIZE ((SIGNAL_NUM-1)/(int)SIZEOFINT)+1
static unsigned int signal_bit_vector[SIGNAL_VECTOR_SIZE];
#define EMIT(signal) signal_bit_vector[signal / SIZEOFINT] |= B_SET_VECTOR_MASK(signal % SIZEOFINT)
#define CLEAR_SIGNAL(signal) signal_bit_vector[signal / SIZEOFINT] &= B_RES_VECTOR_MASK(signal % SIZEOFINT)
#define IS_SIGNAL(signal,pre_level) (signal_bit_vector[signal / SIZEOFINT] & B_SET_VECTOR_MASK(signal % SIZEOFINT))


typedef  int boolean;
typedef  int integer;
#ifndef STRLEN 
#define STRLEN 81 
#endif 
typedef char *string;
#define _integer(x,y) (*x) = (y)
#define _boolean(x,y) (*x) = (y)
#define _float(x,y) (*x) = (y)
#define _double(x,y) (*x) = (y)
#define _string(x,y) strcpy((*x),(y))
#define _eq_integer(x,y) ((x) == (y))
#define _eq_boolean(x,y) ((x) == (y))
#define _eq_float(x,y) ((x) == (y))
#define _eq_double(x,y) ((x) == (y))
#define _eq_string(x,y) (!strcmp((x),(y)))
#define _string_to_text(x) (x)
#define _text_to_string(x,y) (strcpy((*x),(y)))

#define SIG_ID_Exception_GOTO_UNMARK_566 89
#define SIG_ID_Exception_EXIT_FUNC_565 88
static StrlSampleSize ID_Variable_complete_var_564 ;
static StrlSampleRange ID_Variable_temp_range_563 ;
static StrlSampleIndex ID_Variable_temp_index_562 ;
static integer ID_Variable_not_complete_flag_561 ;
static integer ID_Variable_not_source_560 ;
static integer ID_Variable_temp_int_559 ;
static UnsignedInt ID_Variable_temp_unsigned_558 ;
static integer ID_Variable_temp_int_557 ;
static integer ID_Variable_maxOutSize_556 ;
static integer ID_Variable_requestSize_555 ;
static StrlSampleIndex ID_Variable_desiredWP_554 ;
static StrlSampleIndex ID_Variable_pendingWP_553 ;
static StrlSampleRange ID_Variable_inside_input_552 ;
static StrlSampleRange ID_Variable_output_range_551 ;
static StrlSampleRange ID_Variable_input_range_550 ;
#define SIG_ID_Exception_compute_loop_549 87
#define SIG_ID_Signal_R_Name_548 86
static string ID_Signal_R_Name_548  = NULL;
#define SIG_ID_Signal_switch_off_547 85
#define SIG_ID_Signal_switch_on_546 84
#define SIG_ID_Signal_forecast_range_545 83
static StrlSampleRange ID_Signal_forecast_range_545 ;
#define SIG_ID_Signal_My_Sample_Range_544 82
static StrlSampleRange ID_Signal_My_Sample_Range_544 ;
static StrlSampleRange ID_Variable_my_input_543 ;
static StrlSampleRange ID_Variable_org_input_542 ;
static boolean ID_Variable_CONT_FLAG_541 ;
#define SIG_ID_Exception_main_loop_540 81
#define SIG_ID_Exception_GOTO_UNMARK_539 80
#define SIG_ID_Exception_EXIT_FUNC_538 79
static StrlSampleSize ID_Variable_complete_var_537 ;
static StrlSampleRange ID_Variable_temp_range_536 ;
static StrlSampleIndex ID_Variable_temp_index_535 ;
static integer ID_Variable_not_complete_flag_534 ;
static integer ID_Variable_not_source_533 ;
static integer ID_Variable_temp_int_532 ;
static UnsignedInt ID_Variable_temp_unsigned_531 ;
static integer ID_Variable_temp_int_530 ;
static integer ID_Variable_maxOutSize_529 ;
static integer ID_Variable_requestSize_528 ;
static StrlSampleIndex ID_Variable_desiredWP_527 ;
static StrlSampleIndex ID_Variable_pendingWP_526 ;
static StrlSampleRange ID_Variable_inside_input_525 ;
static StrlSampleRange ID_Variable_output_range_524 ;
static StrlSampleRange ID_Variable_input_range_523 ;
#define SIG_ID_Exception_compute_loop_521 78
#define SIG_ID_Exception_main_trap_522 77
#define SIG_ID_Signal_INI_PHASE_520 76
static boolean ID_Signal_INI_PHASE_520 ;
#define SIG_ID_Signal_R_Name_519 75
static string ID_Signal_R_Name_519  = NULL;
#define SIG_ID_Signal_switch_off_518 74
#define SIG_ID_Signal_switch_on_517 73
#define SIG_ID_Signal_forecast_range_516 72
static StrlSampleRange ID_Signal_forecast_range_516 ;
#define SIG_ID_Signal_My_Sample_Range_515 71
static StrlSampleRange ID_Signal_My_Sample_Range_515 ;
static StrlSampleRange ID_Variable_my_input_514 ;
static StrlSampleRange ID_Variable_org_input_513 ;
static string ID_Variable_My_Name_512  = NULL;
static boolean ID_Variable_CONT_FLAG_511 ;
static UnsignedInt ID_Variable_temp_unsigned_510 ;
static integer ID_Variable_temp_int_509 ;
static integer ID_Variable_maxOutSize_508 ;
static integer ID_Variable_requestSize_507 ;
static StrlSampleIndex ID_Variable_desiredWP_506 ;
static StrlSampleIndex ID_Variable_pendingWP_505 ;
static StrlSampleRange ID_Variable_inside_input_504 ;
static StrlSampleRange ID_Variable_output_range_503 ;
static StrlSampleRange ID_Variable_input_range_502 ;
#define SIG_ID_Signal_R_Name_501 70
static string ID_Signal_R_Name_501  = NULL;
#define SIG_ID_Signal_switch_off_500 69
#define SIG_ID_Signal_switch_on_499 68
#define SIG_ID_Signal_forecast_range_498 67
static StrlSampleRange ID_Signal_forecast_range_498 ;
#define SIG_ID_Signal_My_Sample_Range_497 66
static StrlSampleRange ID_Signal_My_Sample_Range_497 ;
static StrlSampleRange ID_Variable_my_input_496 ;
static StrlSampleRange ID_Variable_org_input_495 ;
static integer ID_Variable_n_times_494 ;
static boolean ID_Variable_CONT_FLAG_493 ;
#define SIG_ID_Exception_main_loop_491 65
#define SIG_ID_Exception_GOTO_UNMARK_490 64
#define SIG_ID_Exception_EXIT_FUNC_489 63
static StrlSampleSize ID_Variable_complete_var_488 ;
static StrlSampleRange ID_Variable_temp_range_487 ;
static StrlSampleIndex ID_Variable_temp_index_486 ;
static integer ID_Variable_not_complete_flag_485 ;
static integer ID_Variable_not_source_484 ;
static integer ID_Variable_temp_int_483 ;
static UnsignedInt ID_Variable_temp_unsigned_482 ;
static integer ID_Variable_temp_int_481 ;
static integer ID_Variable_maxOutSize_480 ;
static integer ID_Variable_requestSize_479 ;
static StrlSampleIndex ID_Variable_desiredWP_478 ;
static StrlSampleIndex ID_Variable_pendingWP_477 ;
static StrlSampleRange ID_Variable_inside_input_476 ;
static StrlSampleRange ID_Variable_output_range_475 ;
static StrlSampleRange ID_Variable_input_range_474 ;
#define SIG_ID_Exception_main_trap_473 62
#define SIG_ID_Exception_compute_loop_471 61
#define SIG_ID_Exception_main_trap_472 60
#define SIG_ID_Signal_INI_PHASE_470 59
static boolean ID_Signal_INI_PHASE_470 ;
#define SIG_ID_Signal_R_Name_469 58
static string ID_Signal_R_Name_469  = NULL;
#define SIG_ID_Signal_switch_off_468 57
#define SIG_ID_Signal_switch_on_467 56
#define SIG_ID_Signal_forecast_range_466 55
static StrlSampleRange ID_Signal_forecast_range_466 ;
#define SIG_ID_Signal_My_Sample_Range_465 54
static StrlSampleRange ID_Signal_My_Sample_Range_465 ;
static StrlSampleRange ID_Variable_my_input_464 ;
static StrlSampleRange ID_Variable_org_input_463 ;
static boolean ID_Variable_CONT_FLAG_462 ;
#define SIG_ID_Exception_main_loop_461 53
#define SIG_ID_Exception_GOTO_UNMARK_460 52
#define SIG_ID_Exception_EXIT_FUNC_459 51
static StrlSampleSize ID_Variable_complete_var_458 ;
static StrlSampleRange ID_Variable_temp_range_457 ;
static StrlSampleIndex ID_Variable_temp_index_456 ;
static integer ID_Variable_not_complete_flag_455 ;
static integer ID_Variable_not_source_454 ;
static integer ID_Variable_temp_int_453 ;
static UnsignedInt ID_Variable_temp_unsigned_452 ;
static integer ID_Variable_temp_int_451 ;
static integer ID_Variable_maxOutSize_450 ;
static integer ID_Variable_requestSize_449 ;
static StrlSampleIndex ID_Variable_desiredWP_448 ;
static StrlSampleIndex ID_Variable_pendingWP_447 ;
static StrlSampleRange ID_Variable_inside_input_446 ;
static StrlSampleRange ID_Variable_output_range_445 ;
static StrlSampleRange ID_Variable_input_range_444 ;
#define SIG_ID_Exception_compute_loop_440 50
#define SIG_ID_Exception_main_trap_441 49
#define SIG_ID_Signal_INI_PHASE_439 48
static boolean ID_Signal_INI_PHASE_439 ;
#define SIG_ID_Signal_R_Name_438 47
static string ID_Signal_R_Name_438  = NULL;
#define SIG_ID_Signal_switch_off_437 46
#define SIG_ID_Signal_switch_on_436 45
#define SIG_ID_Signal_forecast_range_435 44
static StrlSampleRange ID_Signal_forecast_range_435 ;
#define SIG_ID_Signal_My_Sample_Range_434 43
static StrlSampleRange ID_Signal_My_Sample_Range_434 ;
static StrlSampleRange ID_Variable_my_input_433 ;
static StrlSampleRange ID_Variable_org_input_432 ;
static string ID_Variable_My_Name_431  = NULL;
static boolean ID_Variable_CONT_FLAG_430 ;
#define SIG_ID_Exception_main_loop_427 42
#define SIG_ID_Exception_GOTO_UNMARK_426 41
#define SIG_ID_Exception_EXIT_FUNC_425 40
static StrlSampleSize ID_Variable_complete_var_424 ;
static StrlSampleRange ID_Variable_temp_range_423 ;
static StrlSampleIndex ID_Variable_temp_index_422 ;
static integer ID_Variable_not_complete_flag_421 ;
static integer ID_Variable_not_source_420 ;
static integer ID_Variable_temp_int_419 ;
static UnsignedInt ID_Variable_temp_unsigned_402 ;
static integer ID_Variable_temp_int_401 ;
static integer ID_Variable_maxOutSize_400 ;
static integer ID_Variable_requestSize_399 ;
static StrlSampleIndex ID_Variable_remainedWP_398 ;
static StrlSampleIndex ID_Variable_pendingWP_397 ;
static StrlSampleRange ID_Variable_output_range_396 ;
static StrlSampleRange ID_Variable_input_range_395 ;
#define SIG_ID_Signal_R_Name_378 39
static string ID_Signal_R_Name_378  = NULL;
#define SIG_ID_Signal_My_Sample_Range_377 38
static StrlSampleRange ID_Signal_My_Sample_Range_377 ;
static StrlSampleRange ID_Variable_my_output_376 ;
static boolean ID_Variable_INITIAL_FLAG_375 ;
#define SIG_ID_Signal_Clock_Wire_M_S2_95 37
#define SIG_ID_Signal_Clock_Wire_M_S1_94 36
#define SIG_ID_Signal_Clock_Wire_M_M1_93 35
#define SIG_ID_Signal_Clock_Wire_S_M_92 34
#define SIG_ID_Signal_Ack_Wire_M_S2_91 33
static StrlSampleRange ID_Signal_Ack_Wire_M_S2_91 ;
#define SIG_ID_Signal_Ack_Wire_M_S1_90 32
static StrlSampleRange ID_Signal_Ack_Wire_M_S1_90 ;
#define SIG_ID_Signal_Ack_Wire_M_M2_89 31
static StrlSampleRange ID_Signal_Ack_Wire_M_M2_89 ;
#define SIG_ID_Signal_Ack_Wire_M_M1_88 30
static StrlSampleRange ID_Signal_Ack_Wire_M_M1_88 ;
#define SIG_ID_Signal_Ack_Wire_S_M_87 29
static StrlSampleRange ID_Signal_Ack_Wire_S_M_87 ;
#define SIG_ID_Signal_Compute_Wire_M_S2_86 28
#define SIG_ID_Signal_Compute_Wire_M_S1_85 27
#define SIG_ID_Signal_Compute_Wire_M_M1_84 26
#define SIG_ID_Signal_Compute_Wire_S_M_83 25
#define SIG_ID_Signal_Mark_Wire_M_S2_82 24
static StrlSampleRange ID_Signal_Mark_Wire_M_S2_82 ;
#define SIG_ID_Signal_Mark_Wire_M_S1_81 23
static StrlSampleRange ID_Signal_Mark_Wire_M_S1_81 ;
#define SIG_ID_Signal_Mark_Wire_M_M2_80 22
static StrlSampleRange ID_Signal_Mark_Wire_M_M2_80 ;
#define SIG_ID_Signal_Mark_Wire_M_M1_79 21
static StrlSampleRange ID_Signal_Mark_Wire_M_M1_79 ;
#define SIG_ID_Signal_Mark_Wire_S_M_78 20
static StrlSampleRange ID_Signal_Mark_Wire_S_M_78 ;
static string ID_Variable_nameofsink_77  = NULL;
static string ID_Variable_nameofscopesink_76  = NULL;
static string ID_Variable_nameofsummer_75  = NULL;
static string ID_Variable_nameofmod_74  = NULL;
static string ID_Variable_nameofcoder_73  = NULL;
static string ID_Variable_nameofsource_72  = NULL;
#ifndef INITIAL_SIZE
extern StrlSampleSize INITIAL_SIZE;
#endif
#ifndef INITIAL_DEBUG4VAR
extern Debug4Var INITIAL_DEBUG4VAR;
#endif
#ifndef INITIAL_UNSIGNEDINT
extern UnsignedInt INITIAL_UNSIGNEDINT;
#endif
#ifndef INITIAL_INDEX
extern StrlSampleIndex INITIAL_INDEX;
#endif
#define S_DEF_TPD 2.600000e+03
#define S_CENTER_FREQ_MULT 4
#define S_ALPHA 6.000000e-01
#define S_K 2
#define S_CONST_NUM 5
#define S_NUM_SYMB 16
#define S_AMPL 80
#define S_OUTPUT_SYMBOL_BITS 4
#define S_IN_RATE 2000
#define S_OUT_RATE 400000
#ifndef INITIAL_UNSIGNEDLL
extern UnsignedLL INITIAL_UNSIGNEDLL;
#endif
#ifndef INITIAL_RANGE
extern StrlSampleRange INITIAL_RANGE;
#endif
#define SIG_ID_Output_debug_sink_58 19
static Debug4Var ID_Output_debug_sink_58 ;
#define SIG_ID_Output_debug_scopesink_57 18
static Debug4Var ID_Output_debug_scopesink_57 ;
#define SIG_ID_Output_debug_summer_56 17
static Debug4Var ID_Output_debug_summer_56 ;
#define SIG_ID_Output_debug_mod_55 16
static Debug4Var ID_Output_debug_mod_55 ;
#define SIG_ID_Output_debug_coder_54 15
static Debug4Var ID_Output_debug_coder_54 ;
#define SIG_ID_Output_debug_source_53 14
static Debug4Var ID_Output_debug_source_53 ;
#define SIG_ID_Output_SINK_COMPUTEDSR_52 13
static StrlSampleRange ID_Output_SINK_COMPUTEDSR_52 ;
#define SIG_ID_Output_SCOPESINK_COMPUTEDSR_51 12
static StrlSampleRange ID_Output_SCOPESINK_COMPUTEDSR_51 ;
#define SIG_ID_Output_SUMMER_COMPUTEDSR_50 11
static StrlSampleRange ID_Output_SUMMER_COMPUTEDSR_50 ;
#define SIG_ID_Output_MOD_COMPUTEDSR_49 10
static StrlSampleRange ID_Output_MOD_COMPUTEDSR_49 ;
#define SIG_ID_Output_CODER_COMPUTEDSR_48 9
static StrlSampleRange ID_Output_CODER_COMPUTEDSR_48 ;
#define SIG_ID_Output_SOURCE_COMPUTEDSR_47 8
static StrlSampleRange ID_Output_SOURCE_COMPUTEDSR_47 ;
#define SIG_ID_InputOutput_Sink_module_46 7
static string ID_InputOutput_Sink_module_46  = NULL;
#define SIG_ID_InputOutput_Scopesink_module_45 6
static string ID_InputOutput_Scopesink_module_45  = NULL;
#define SIG_ID_InputOutput_Summer_module_44 5
static string ID_InputOutput_Summer_module_44  = NULL;
#define SIG_ID_InputOutput_Mod_module_43 4
static string ID_InputOutput_Mod_module_43  = NULL;
#define SIG_ID_InputOutput_Coder_module_42 3
static string ID_InputOutput_Coder_module_42  = NULL;
#define SIG_ID_InputOutput_Source_module_41 2
static string ID_InputOutput_Source_module_41  = NULL;
#define SIG_ID_Input_User_Quit_40 1
#define SIG_ID_Input_on_TimeConstraint_39 0
static integer ID_Input_on_TimeConstraint_39 ;
#ifndef _StrlSampleRange
extern  void _StrlSampleRange(StrlSampleRange*,StrlSampleRange);
#endif
#ifndef _StrlSampleRange
extern  int _eq_StrlSampleRange(StrlSampleRange,StrlSampleRange);
#endif
#ifndef _StrlSampleRange_to_text
extern  char* _StrlSampleRange_to_text(StrlSampleRange);
#endif
#ifndef  _text_to_StrlSampleRange
extern  void _text_to_StrlSampleRange(StrlSampleRange*,char *);
#endif
#ifndef _UnsignedLL
extern  void _UnsignedLL(UnsignedLL*,UnsignedLL);
#endif
#ifndef _UnsignedLL
extern  int _eq_UnsignedLL(UnsignedLL,UnsignedLL);
#endif
#ifndef _UnsignedLL_to_text
extern  char* _UnsignedLL_to_text(UnsignedLL);
#endif
#ifndef  _text_to_UnsignedLL
extern  void _text_to_UnsignedLL(UnsignedLL*,char *);
#endif
#ifndef _UnsignedLong
extern  void _UnsignedLong(UnsignedLong*,UnsignedLong);
#endif
#ifndef _UnsignedLong
extern  int _eq_UnsignedLong(UnsignedLong,UnsignedLong);
#endif
#ifndef _UnsignedLong_to_text
extern  char* _UnsignedLong_to_text(UnsignedLong);
#endif
#ifndef  _text_to_UnsignedLong
extern  void _text_to_UnsignedLong(UnsignedLong*,char *);
#endif
#ifndef _Debug4Var
extern  void _Debug4Var(Debug4Var*,Debug4Var);
#endif
#ifndef _Debug4Var
extern  int _eq_Debug4Var(Debug4Var,Debug4Var);
#endif
#ifndef _Debug4Var_to_text
extern  char* _Debug4Var_to_text(Debug4Var);
#endif
#ifndef  _text_to_Debug4Var
extern  void _text_to_Debug4Var(Debug4Var*,char *);
#endif
#ifndef _StrlSampleIndex
extern  void _StrlSampleIndex(StrlSampleIndex*,StrlSampleIndex);
#endif
#ifndef _StrlSampleIndex
extern  int _eq_StrlSampleIndex(StrlSampleIndex,StrlSampleIndex);
#endif
#ifndef _StrlSampleIndex_to_text
extern  char* _StrlSampleIndex_to_text(StrlSampleIndex);
#endif
#ifndef  _text_to_StrlSampleIndex
extern  void _text_to_StrlSampleIndex(StrlSampleIndex*,char *);
#endif
#ifndef _UnsignedInt
extern  void _UnsignedInt(UnsignedInt*,UnsignedInt);
#endif
#ifndef _UnsignedInt
extern  int _eq_UnsignedInt(UnsignedInt,UnsignedInt);
#endif
#ifndef _UnsignedInt_to_text
extern  char* _UnsignedInt_to_text(UnsignedInt);
#endif
#ifndef  _text_to_UnsignedInt
extern  void _text_to_UnsignedInt(UnsignedInt*,char *);
#endif
#ifndef _StrlSampleSize
extern  void _StrlSampleSize(StrlSampleSize*,StrlSampleSize);
#endif
#ifndef _StrlSampleSize
extern  int _eq_StrlSampleSize(StrlSampleSize,StrlSampleSize);
#endif
#ifndef _StrlSampleSize_to_text
extern  char* _StrlSampleSize_to_text(StrlSampleSize);
#endif
#ifndef  _text_to_StrlSampleSize
extern  void _text_to_StrlSampleSize(StrlSampleSize*,char *);
#endif
#ifndef GET_SOURCE
extern string GET_SOURCE(string, integer);
#endif
#ifndef GET_CODER
extern string GET_CODER(integer);
#endif
#ifndef GET_MOD_F
extern string GET_MOD_F(integer, float, integer, integer, integer, integer, float, integer);
#endif
#ifndef GET_SUMMER
extern string GET_SUMMER();
#endif
#ifndef GET_SINK
extern string GET_SINK(string, integer);
#endif
#ifndef GET_SCOPESINK_F
extern string GET_SCOPESINK_F(float, integer, integer, integer, integer);
#endif
#ifndef GETMARKEDWP
extern StrlSampleIndex GETMARKEDWP(string);
#endif
#ifndef ADD_INDEX_SIZE
extern StrlSampleIndex ADD_INDEX_SIZE(StrlSampleRange);
#endif
#ifndef SUBTRACT_A_B
extern integer SUBTRACT_A_B(StrlSampleIndex, StrlSampleIndex);
#endif
#ifndef GETMAXOUTSIZE
extern integer GETMAXOUTSIZE(string);
#endif
#ifndef GET_OUTPUTSIZE
extern UnsignedInt GET_OUTPUTSIZE(string);
#endif
#ifndef ROUNDOWN_SIZE
extern integer ROUNDOWN_SIZE(integer, UnsignedInt);
#endif
#ifndef SET_SAMPLERANGE
extern StrlSampleRange SET_SAMPLERANGE(StrlSampleIndex, integer);
#endif
#ifndef REAL_FIT_RANGE
extern integer REAL_FIT_RANGE(StrlSampleIndex, integer, StrlSampleRange, string);
#endif
#ifndef error_exit
extern integer error_exit(integer);
#endif
#ifndef DEBUG_RANGE
extern Debug4Var DEBUG_RANGE(string, StrlSampleRange);
#endif
#ifndef DEBUG_INT
extern Debug4Var DEBUG_INT(string, integer);
#endif
#ifndef DEBUG_INDEX
extern Debug4Var DEBUG_INDEX(string, StrlSampleIndex);
#endif
#ifndef CHECK_MYWRITERLL
extern integer CHECK_MYWRITERLL(string);
#endif
#ifndef CHECK_MYMARKEDDATA_SIZE
extern integer CHECK_MYMARKEDDATA_SIZE(string);
#endif
#ifndef GET_NUMBERINPUTS
extern integer GET_NUMBERINPUTS(string);
#endif
#ifndef REALCOMPUTEDATA
extern StrlSampleSize REALCOMPUTEDATA(string, integer);
#endif
#ifndef CMPSAMPLESIZE
extern integer CMPSAMPLESIZE(StrlSampleSize, StrlSampleSize);
#endif
#ifndef GET_MYMARKEDINDEX
extern StrlSampleIndex GET_MYMARKEDINDEX(string);
#endif
#ifndef GET_MYMARKEDSIZE
extern StrlSampleSize GET_MYMARKEDSIZE(string);
#endif
#ifndef GET_MYMARKEDDATA
extern StrlSampleRange GET_MYMARKEDDATA(string);
#endif
#ifndef ADD_SAMPLEINDEX
extern StrlSampleIndex ADD_SAMPLEINDEX(StrlSampleIndex, StrlSampleSize);
#endif
#ifndef GETWP
extern StrlSampleIndex GETWP(string);
#endif
#ifndef CHECKSAMPLESIZE
extern integer CHECKSAMPLESIZE(StrlSampleRange, StrlSampleRange);
#endif
#ifndef UPDATESAMPLE
extern StrlSampleRange UPDATESAMPLE(StrlSampleRange);
#endif
#ifndef DOWNCASTS
extern StrlSampleRange DOWNCASTS(StrlSampleRange, string);
#endif
#ifndef FORECASTS
extern StrlSampleRange FORECASTS(StrlSampleRange, string);
#endif
#ifndef INSIDE_COMP_FIT
extern StrlSampleRange INSIDE_COMP_FIT(StrlSampleRange, StrlSampleRange, string);
#endif
#ifndef CONNECT_MODULES
extern void CONNECT_MODULES(string, string, integer, integer);
#endif
#ifndef INITGUI_MAIN_START
extern void INITGUI_MAIN_START();
#endif
#ifndef INITIAL_SINK
extern void INITIAL_SINK(string);
#endif
#ifndef RUN_GUI_MAIN
extern void RUN_GUI_MAIN();
#endif
#ifndef INIT_PERF_GRAPH
extern void INIT_PERF_GRAPH();
#endif
#ifndef START_PERF_GRAPH
extern void START_PERF_GRAPH();
#endif
#ifndef STOP_PERF_GRAPH
extern void STOP_PERF_GRAPH();
#endif
#ifndef LOCALINCAWAITTICK
extern void LOCALINCAWAITTICK(string);
#endif
#ifndef SET_MARKEDWP
extern void SET_MARKEDWP(string, StrlSampleIndex);
#endif
#ifndef WRITEDATA
extern void WRITEDATA(string, integer);
#endif

extern void UDP_FLOW_O_debug_sink(Debug4Var);
extern void UDP_FLOW_O_debug_scopesink(Debug4Var);
extern void UDP_FLOW_O_debug_summer(Debug4Var);
extern void UDP_FLOW_O_debug_mod(Debug4Var);
extern void UDP_FLOW_O_debug_coder(Debug4Var);
extern void UDP_FLOW_O_debug_source(Debug4Var);
extern void UDP_FLOW_O_SINK_COMPUTEDSR(StrlSampleRange);
extern void UDP_FLOW_O_SCOPESINK_COMPUTEDSR(StrlSampleRange);
extern void UDP_FLOW_O_SUMMER_COMPUTEDSR(StrlSampleRange);
extern void UDP_FLOW_O_MOD_COMPUTEDSR(StrlSampleRange);
extern void UDP_FLOW_O_CODER_COMPUTEDSR(StrlSampleRange);
extern void UDP_FLOW_O_SOURCE_COMPUTEDSR(StrlSampleRange);
void UDP_FLOW_I_Sink_module(string value) {EMIT(SIG_ID_InputOutput_Sink_module_46);_string(&ID_InputOutput_Sink_module_46,value);}
extern void UDP_FLOW_O_Sink_module(string);
void UDP_FLOW_I_Scopesink_module(string value) {EMIT(SIG_ID_InputOutput_Scopesink_module_45);_string(&ID_InputOutput_Scopesink_module_45,value);}
extern void UDP_FLOW_O_Scopesink_module(string);
void UDP_FLOW_I_Summer_module(string value) {EMIT(SIG_ID_InputOutput_Summer_module_44);_string(&ID_InputOutput_Summer_module_44,value);}
extern void UDP_FLOW_O_Summer_module(string);
void UDP_FLOW_I_Mod_module(string value) {EMIT(SIG_ID_InputOutput_Mod_module_43);_string(&ID_InputOutput_Mod_module_43,value);}
extern void UDP_FLOW_O_Mod_module(string);
void UDP_FLOW_I_Coder_module(string value) {EMIT(SIG_ID_InputOutput_Coder_module_42);_string(&ID_InputOutput_Coder_module_42,value);}
extern void UDP_FLOW_O_Coder_module(string);
void UDP_FLOW_I_Source_module(string value) {EMIT(SIG_ID_InputOutput_Source_module_41);_string(&ID_InputOutput_Source_module_41,value);}
extern void UDP_FLOW_O_Source_module(string);
void UDP_FLOW_I_User_Quit() {EMIT(SIG_ID_Input_User_Quit_40);}
void UDP_FLOW_I_on_TimeConstraint(integer value) {EMIT(SIG_ID_Input_on_TimeConstraint_39);_integer(&ID_Input_on_TimeConstraint_39,value);}

static void Point_0() {
	_StrlSampleRange(&ID_Signal_Mark_Wire_S_M_78,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_78);
	_StrlSampleRange(&ID_Signal_Mark_Wire_M_M1_79,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79);
	_StrlSampleRange(&ID_Signal_Mark_Wire_M_M2_80,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M2_80);
	_StrlSampleRange(&ID_Signal_Mark_Wire_M_S1_81,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_81);
	_StrlSampleRange(&ID_Signal_Mark_Wire_M_S2_82,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S2_82);
	CLEAR_SIGNAL(SIG_ID_Signal_Compute_Wire_S_M_83);
	CLEAR_SIGNAL(SIG_ID_Signal_Compute_Wire_M_M1_84);
	CLEAR_SIGNAL(SIG_ID_Signal_Compute_Wire_M_S1_85);
	CLEAR_SIGNAL(SIG_ID_Signal_Compute_Wire_M_S2_86);
	_StrlSampleRange(&ID_Signal_Ack_Wire_S_M_87,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Ack_Wire_S_M_87);
	_StrlSampleRange(&ID_Signal_Ack_Wire_M_M1_88,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_88);
	_StrlSampleRange(&ID_Signal_Ack_Wire_M_M2_89,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89);
	_StrlSampleRange(&ID_Signal_Ack_Wire_M_S1_90,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90);
	_StrlSampleRange(&ID_Signal_Ack_Wire_M_S2_91,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_91);
	CLEAR_SIGNAL(SIG_ID_Signal_Clock_Wire_S_M_92);
	CLEAR_SIGNAL(SIG_ID_Signal_Clock_Wire_M_M1_93);
	CLEAR_SIGNAL(SIG_ID_Signal_Clock_Wire_M_S1_94);
	CLEAR_SIGNAL(SIG_ID_Signal_Clock_Wire_M_S2_95);
	_string(&ID_Variable_nameofsource_72,GET_SOURCE("tmp.gz", 1));
	_string(&ID_Variable_nameofcoder_73,GET_CODER(4));
	_string(&ID_Variable_nameofmod_74,GET_MOD_F(200, 6.500000e+04, 80, 16, 5, 2, 6.000000e-01, 4));
	_string(&ID_Variable_nameofsummer_75,GET_SUMMER());
	_string(&ID_Variable_nameofscopesink_76,GET_SCOPESINK_F((2.600000e+03 / 2.000000e+00), -128, 128, 500, 1));
	_string(&ID_Variable_nameofsink_77,GET_SINK("138.96.251.3", 5001));
	CONNECT_MODULES(ID_Variable_nameofscopesink_76, ID_Variable_nameofmod_74, 400000, 8);
	CONNECT_MODULES(ID_Variable_nameofsink_77, ID_Variable_nameofsummer_75, 400000, 8);
	CONNECT_MODULES(ID_Variable_nameofsummer_75, ID_Variable_nameofmod_74, 400000, 8);
	CONNECT_MODULES(ID_Variable_nameofmod_74, ID_Variable_nameofcoder_73, 2000, 8);
	CONNECT_MODULES(ID_Variable_nameofcoder_73, ID_Variable_nameofsource_72, 1000, 8);
	_string(&ID_InputOutput_Source_module_41,ID_Variable_nameofsource_72);
	UDP_FLOW_O_Source_module(ID_InputOutput_Source_module_41); EMIT(SIG_ID_InputOutput_Source_module_41);
	_string(&ID_InputOutput_Coder_module_42,ID_Variable_nameofcoder_73);
	UDP_FLOW_O_Coder_module(ID_InputOutput_Coder_module_42); EMIT(SIG_ID_InputOutput_Coder_module_42);
	_string(&ID_InputOutput_Mod_module_43,ID_Variable_nameofmod_74);
	UDP_FLOW_O_Mod_module(ID_InputOutput_Mod_module_43); EMIT(SIG_ID_InputOutput_Mod_module_43);
	_string(&ID_InputOutput_Summer_module_44,ID_Variable_nameofsummer_75);
	UDP_FLOW_O_Summer_module(ID_InputOutput_Summer_module_44); EMIT(SIG_ID_InputOutput_Summer_module_44);
	_string(&ID_InputOutput_Scopesink_module_45,ID_Variable_nameofscopesink_76);
	UDP_FLOW_O_Scopesink_module(ID_InputOutput_Scopesink_module_45); EMIT(SIG_ID_InputOutput_Scopesink_module_45);
	_string(&ID_InputOutput_Sink_module_46,ID_Variable_nameofsink_77);
	UDP_FLOW_O_Sink_module(ID_InputOutput_Sink_module_46); EMIT(SIG_ID_InputOutput_Sink_module_46);
	INITIAL_SINK(ID_InputOutput_Sink_module_46);
	INITIAL_SINK(ID_InputOutput_Scopesink_module_45);
	INIT_PERF_GRAPH();
	INITGUI_MAIN_START();
	RUN_GUI_MAIN();
	_boolean(&ID_Variable_CONT_FLAG_541,0);
	_StrlSampleRange(&ID_Variable_org_input_542,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_my_input_543,INITIAL_RANGE);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_544,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_544);
	_StrlSampleRange(&ID_Signal_forecast_range_545,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_forecast_range_545);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_on_546);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_off_547);
	CLEAR_SIGNAL(SIG_ID_Signal_R_Name_548);
	_boolean(&ID_Variable_CONT_FLAG_493,0);
	_integer(&ID_Variable_n_times_494,0);
	_StrlSampleRange(&ID_Variable_org_input_495,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_my_input_496,INITIAL_RANGE);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_497,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_497);
	_StrlSampleRange(&ID_Signal_forecast_range_498,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_forecast_range_498);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_on_499);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_off_500);
	CLEAR_SIGNAL(SIG_ID_Signal_R_Name_501);
	_boolean(&ID_Variable_CONT_FLAG_430,0);
	_string(&ID_Variable_My_Name_431,"name");
	_StrlSampleRange(&ID_Variable_org_input_432,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_my_input_433,INITIAL_RANGE);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_434,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_434);
	_StrlSampleRange(&ID_Signal_forecast_range_435,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_forecast_range_435);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_on_436);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_off_437);
	CLEAR_SIGNAL(SIG_ID_Signal_R_Name_438);
	CLEAR_SIGNAL(SIG_ID_Signal_INI_PHASE_439);
	_boolean(&ID_Signal_INI_PHASE_439,1);
	EMIT(SIG_ID_Signal_INI_PHASE_439);
	current_point_bit_vector[0] |= 0x2000000; current_point_bit_vector[1] |= 0x10; current_point_bit_vector[4] |= 0x1000; /* On:  #25 #36 #140*/
	next_point_bit_vector[0] |= 0x200002; next_point_bit_vector[1] |= 0x41; /* PauseOn:  #1 #21 #32 #38*/
	if (IS_SIGNAL(SIG_ID_Signal_INI_PHASE_439,0)) {
		next_point_bit_vector[0] |= 0x80; /* PauseOn:  #7*/
	} else {
		CLEAR_SIGNAL(SIG_ID_Exception_main_trap_441);
		next_point_bit_vector[4] |= 0x1; /* PauseOn:  #128*/
		if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_78,0)) {
			next_point_bit_vector[3] |= 0x20000000; /* PauseOn:  #125*/
		} else {
			current_point_bit_vector[4] |= 0x1; /* On:  #128*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_88,0)) {
			next_point_bit_vector[0] |= 0x100; /* PauseOn:  #8*/
		} else {
			current_point_bit_vector[4] |= 0x1; /* On:  #128*/
		}
		if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_78,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_88,0))) {
			EMIT(SIG_ID_Exception_main_trap_441);
			current_point_bit_vector[3] |= 0x40000000; /* On:  #126*/
			current_point_bit_vector[4] &= ~0x1; /* Off:  #128*/
		} else {
			current_point_bit_vector[4] |= 0x1; /* On:  #128*/
		}
	}
	START_PERF_GRAPH();
	_StrlSampleRange(&ID_Signal_Ack_Wire_S_M_87,INITIAL_RANGE);
	EMIT(SIG_ID_Signal_Ack_Wire_S_M_87);
	_boolean(&ID_Variable_INITIAL_FLAG_375,1);
	_StrlSampleRange(&ID_Variable_my_output_376,INITIAL_RANGE);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_377,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_377);
	CLEAR_SIGNAL(SIG_ID_Signal_R_Name_378);
	_boolean(&ID_Variable_CONT_FLAG_462,0);
	_StrlSampleRange(&ID_Variable_org_input_463,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_my_input_464,INITIAL_RANGE);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_465,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_465);
	_StrlSampleRange(&ID_Signal_forecast_range_466,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_forecast_range_466);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_on_467);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_off_468);
	CLEAR_SIGNAL(SIG_ID_Signal_R_Name_469);
	CLEAR_SIGNAL(SIG_ID_Signal_INI_PHASE_470);
	_boolean(&ID_Signal_INI_PHASE_470,1);
	EMIT(SIG_ID_Signal_INI_PHASE_470);
	current_point_bit_vector[3] |= 0x80000; current_point_bit_vector[4] |= 0x100000; /* On:  #115 #148*/
	if (IS_SIGNAL(SIG_ID_Signal_INI_PHASE_470,0)) {
		next_point_bit_vector[0] |= 0x1000; /* PauseOn:  #12*/
	} else {
		CLEAR_SIGNAL(SIG_ID_Exception_main_trap_472);
		next_point_bit_vector[2] |= 0x20000; /* PauseOn:  #81*/
		if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0))) {
			next_point_bit_vector[0] |= 0x20000; /* PauseOn:  #17*/
		} else {
			current_point_bit_vector[2] |= 0x20000; /* On:  #81*/
		}
		if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0))) {
			next_point_bit_vector[2] |= 0x4000; /* PauseOn:  #78*/
		} else {
			current_point_bit_vector[2] |= 0x20000; /* On:  #81*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0)) {
			next_point_bit_vector[1] |= 0x80; next_point_bit_vector[2] |= 0x600; /* PauseOn:  #39 #73 #74*/
		} else {
			current_point_bit_vector[2] |= 0x20000; /* On:  #81*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) {
			next_point_bit_vector[0] |= 0x2000; next_point_bit_vector[2] |= 0x3000; /* PauseOn:  #13 #76 #77*/
		} else {
			current_point_bit_vector[2] |= 0x20000; /* On:  #81*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0)) {
			next_point_bit_vector[0] |= 0x8000; next_point_bit_vector[1] |= 0xc00; /* PauseOn:  #15 #42 #43*/
		} else {
			current_point_bit_vector[2] |= 0x20000; /* On:  #81*/
		}
		if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0))) {
			next_point_bit_vector[1] |= 0x1000; /* PauseOn:  #44*/
		} else {
			current_point_bit_vector[2] |= 0x20000; /* On:  #81*/
		}
		if (((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0))) {
			EMIT(SIG_ID_Exception_main_trap_472);
			current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
			current_point_bit_vector[2] &= ~0x20000; /* Off:  #81*/
		} else {
			current_point_bit_vector[2] |= 0x20000; /* On:  #81*/
		}
	}
	_boolean(&ID_Variable_CONT_FLAG_511,0);
	_string(&ID_Variable_My_Name_512,"name");
	_StrlSampleRange(&ID_Variable_org_input_513,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_my_input_514,INITIAL_RANGE);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_515,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_515);
	_StrlSampleRange(&ID_Signal_forecast_range_516,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_forecast_range_516);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_on_517);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_off_518);
	CLEAR_SIGNAL(SIG_ID_Signal_R_Name_519);
	CLEAR_SIGNAL(SIG_ID_Signal_INI_PHASE_520);
	_boolean(&ID_Signal_INI_PHASE_520,1);
	EMIT(SIG_ID_Signal_INI_PHASE_520);
	current_point_bit_vector[1] |= 0x80000000; /* On:  #63*/
	if (IS_SIGNAL(SIG_ID_Signal_INI_PHASE_520,0)) {
		next_point_bit_vector[0] |= 0x8000000; /* PauseOn:  #27*/
	} else {
		CLEAR_SIGNAL(SIG_ID_Exception_main_trap_522);
		next_point_bit_vector[1] |= 0x40000; /* PauseOn:  #50*/
		if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_81,0)) {
			next_point_bit_vector[1] |= 0x8000; /* PauseOn:  #47*/
		} else {
			current_point_bit_vector[1] |= 0x40000; /* On:  #50*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_91,0)) {
			next_point_bit_vector[0] |= 0x10000000; /* PauseOn:  #28*/
		} else {
			current_point_bit_vector[1] |= 0x40000; /* On:  #50*/
		}
		if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_81,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_91,0))) {
			EMIT(SIG_ID_Exception_main_trap_522);
			current_point_bit_vector[1] |= 0x10000; /* On:  #48*/
			current_point_bit_vector[1] &= ~0x40000; /* Off:  #50*/
		} else {
			current_point_bit_vector[1] |= 0x40000; /* On:  #50*/
		}
	}
}

static void Point_1() {
	if (IS_SIGNAL(SIG_ID_Input_User_Quit_40,0)) {
		current_point_bit_vector[0] &= ~0xffffff84; current_point_bit_vector[1] &= ~0x8da4ffff; current_point_bit_vector[2] &= ~0x64027f03; current_point_bit_vector[3] &= ~0x20b8000c; current_point_bit_vector[4] &= ~0x3b071a9; /* Off:  #2 #7 #8 #9 #10 #11 #12 #13 #14 #15 #16 #17 #18 #19 #20 #21 #22 #23 #24 #25 #26 #27 #28 #29 #30 #31 #32 #33 #34 #35 #36 #37 #38 #39 #40 #41 #42 #43 #44 #45 #46 #47 #50 #53 #55 #56 #58 #59 #63 #64 #65 #72 #73 #74 #75 #76 #77 #78 #81 #90 #93 #94 #98 #99 #115 #116 #117 #119 #125 #128 #131 #133 #135 #136 #140 #141 #142 #148 #149 #151 #152 #153*/
	} else {
		next_point_bit_vector[0] |= 0x2; /* PauseOn:  #1*/
	}
}

static void Point_2() {
	_StrlSampleRange(&ID_Signal_Mark_Wire_S_M_78,ID_Variable_output_range_396);
	EMIT(SIG_ID_Signal_Mark_Wire_S_M_78);
	_integer(&ID_Variable_temp_int_419,0);
	_integer(&ID_Variable_not_source_420,0);
	_integer(&ID_Variable_not_complete_flag_421,0);
	_StrlSampleIndex(&ID_Variable_temp_index_422,INITIAL_INDEX);
	_StrlSampleRange(&ID_Variable_temp_range_423,INITIAL_RANGE);
	_StrlSampleSize(&ID_Variable_complete_var_424,INITIAL_SIZE);
	CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_425);
	CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_426);
	if (_eq_integer(CHECK_MYWRITERLL(ID_InputOutput_Source_module_41),0)) {
		current_point_bit_vector[0] |= 0x20; /* On:  #5*/
	} else {
		if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_InputOutput_Source_module_41),0)) {
			current_point_bit_vector[0] |= 0x10; /* On:  #4*/
		} else {
			if ((GET_NUMBERINPUTS(ID_InputOutput_Source_module_41) > 0)) {
				_integer(&ID_Variable_not_source_420,1);
			}
			_StrlSampleSize(&ID_Variable_complete_var_424,REALCOMPUTEDATA(ID_InputOutput_Source_module_41, ID_Variable_not_source_420));
			if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_InputOutput_Source_module_41), ID_Variable_complete_var_424) > 0)) {
				_integer(&ID_Variable_not_complete_flag_421,(ID_Variable_not_complete_flag_421 - 1));
				current_point_bit_vector[0] |= 0x8; /* On:  #3*/
			} else {
				current_point_bit_vector[0] |= 0x8; /* On:  #3*/
			}
		}
	}
}

static void Point_3() {
	if ((ID_Variable_not_complete_flag_421 < 0)) {
		_StrlSampleIndex(&ID_Variable_temp_index_422,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_InputOutput_Source_module_41), ID_Variable_complete_var_424));
		SET_MARKEDWP(ID_InputOutput_Source_module_41, ID_Variable_temp_index_422);
	}
	WRITEDATA(ID_InputOutput_Source_module_41, ID_Variable_not_source_420);
	_StrlSampleIndex(&ID_Variable_temp_index_422,GETWP(ID_InputOutput_Source_module_41));
	_StrlSampleRange(&ID_Output_SOURCE_COMPUTEDSR_47,GET_MYMARKEDDATA(ID_InputOutput_Source_module_41));
	UDP_FLOW_O_SOURCE_COMPUTEDSR(ID_Output_SOURCE_COMPUTEDSR_47); EMIT(SIG_ID_Output_SOURCE_COMPUTEDSR_47);
	current_point_bit_vector[0] |= 0x40; /* On:  #6*/
}

static void Point_4() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_425);
	current_point_bit_vector[0] |= 0x40; /* On:  #6*/
	current_point_bit_vector[0] &= ~0x8; /* Off:  #3*/
}

static void Point_5() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_425);
	current_point_bit_vector[0] |= 0x40; /* On:  #6*/
	current_point_bit_vector[0] &= ~0x8; /* Off:  #3*/
}

static void Point_6() {
	CLEAR_SIGNAL(SIG_ID_Exception_main_loop_427);
	current_point_bit_vector[4] |= 0x400000; /* On:  #150*/
}

static void Point_7() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_78,0)) {
		EMIT(SIG_ID_Signal_switch_on_436);
		_StrlSampleRange(&ID_Variable_org_input_432,ID_Signal_Mark_Wire_S_M_78);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_434,ID_Variable_org_input_432);
		EMIT(SIG_ID_Signal_My_Sample_Range_434);
		current_point_bit_vector[3] |= 0x80000000; /* On:  #127*/
	} else {
		next_point_bit_vector[0] |= 0x80; /* PauseOn:  #7*/
	}
}

static void Point_8() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_78,0)) {
		EMIT(SIG_ID_Exception_main_trap_441);
		current_point_bit_vector[3] |= 0x40000000; /* On:  #126*/
		current_point_bit_vector[4] &= ~0x1; /* Off:  #128*/
	} else {
		next_point_bit_vector[0] |= 0x100; /* PauseOn:  #8*/
	}
}

static void Point_9() {
	_StrlSampleRange(&ID_Signal_Mark_Wire_M_M1_79,ID_Variable_output_range_445);
	EMIT(SIG_ID_Signal_Mark_Wire_M_M1_79);
	_StrlSampleRange(&ID_Signal_forecast_range_435,ID_Variable_inside_input_446);
	EMIT(SIG_ID_Signal_forecast_range_435);
	_StrlSampleRange(&ID_Variable_my_input_433,ID_Signal_forecast_range_435);
	EMIT(SIG_ID_Signal_switch_off_437);
	current_point_bit_vector[4] |= 0x2000000; /* On:  #153*/
}

static void Point_10() {
	CLEAR_SIGNAL(SIG_ID_Exception_main_loop_461);
	current_point_bit_vector[4] |= 0x40; /* On:  #134*/
}

static void Point_11() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_off_437,0)) {
		current_point_bit_vector[4] |= 0x80000; /* On:  #147*/
		current_point_bit_vector[4] &= ~0x2000; /* Off:  #141*/
	} else {
		next_point_bit_vector[0] |= 0x800; /* PauseOn:  #11*/
	}
}

static void Point_12() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0)) {
		EMIT(SIG_ID_Signal_switch_on_467);
		_StrlSampleRange(&ID_Variable_org_input_463,ID_Signal_Mark_Wire_M_M1_79);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_465,ID_Variable_org_input_463);
		EMIT(SIG_ID_Signal_My_Sample_Range_465);
		current_point_bit_vector[2] |= 0x10000; /* On:  #80*/
	} else {
		next_point_bit_vector[0] |= 0x1000; /* PauseOn:  #12*/
	}
}

static void Point_13() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0)) {
		next_point_bit_vector[2] |= 0x800; /* PauseOn:  #75*/
	} else {
		next_point_bit_vector[0] |= 0x2000; /* PauseOn:  #13*/
	}
}

static void Point_14() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0)) {
		EMIT(SIG_ID_Exception_main_trap_472);
		current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
		current_point_bit_vector[2] &= ~0x20000; /* Off:  #81*/
	} else {
		next_point_bit_vector[0] |= 0x4000; /* PauseOn:  #14*/
	}
}

static void Point_15() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0)) {
		next_point_bit_vector[1] |= 0x200; /* PauseOn:  #41*/
	} else {
		next_point_bit_vector[0] |= 0x8000; /* PauseOn:  #15*/
	}
}

static void Point_16() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0)) {
		EMIT(SIG_ID_Exception_main_trap_472);
		current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
		current_point_bit_vector[2] &= ~0x20000; /* Off:  #81*/
	} else {
		next_point_bit_vector[0] |= 0x10000; /* PauseOn:  #16*/
	}
}

static void Point_17() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0)) {
		EMIT(SIG_ID_Exception_main_trap_472);
		current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
		current_point_bit_vector[2] &= ~0x20000; /* Off:  #81*/
	} else {
		next_point_bit_vector[0] |= 0x20000; /* PauseOn:  #17*/
	}
}

static void Point_18() {
	_StrlSampleRange(&ID_Signal_Mark_Wire_M_S1_81,ID_Variable_output_range_475);
	EMIT(SIG_ID_Signal_Mark_Wire_M_S1_81);
	_StrlSampleRange(&ID_Signal_forecast_range_466,ID_Variable_inside_input_476);
	EMIT(SIG_ID_Signal_forecast_range_466);
	_StrlSampleRange(&ID_Variable_my_input_464,ID_Signal_forecast_range_466);
	EMIT(SIG_ID_Signal_switch_off_468);
	current_point_bit_vector[4] |= 0x4000; /* On:  #142*/
}

static void Point_19() {
	CLEAR_SIGNAL(SIG_ID_Exception_main_loop_491);
	current_point_bit_vector[3] |= 0x2; /* On:  #97*/
}

static void Point_20() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_off_468,0)) {
		current_point_bit_vector[3] |= 0x10000000; /* On:  #124*/
		current_point_bit_vector[3] &= ~0x100000; /* Off:  #116*/
	} else {
		next_point_bit_vector[0] |= 0x100000; /* PauseOn:  #20*/
	}
}

static void Point_21() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_81,0)) {
		EMIT(SIG_ID_Signal_switch_on_499);
		_StrlSampleRange(&ID_Variable_org_input_495,ID_Signal_Mark_Wire_M_S1_81);
		if (ID_Variable_CONT_FLAG_493) {
			_StrlSampleRange(&ID_Signal_My_Sample_Range_497,ID_Variable_my_input_496);
			EMIT(SIG_ID_Signal_My_Sample_Range_497);
		} else {
			_StrlSampleRange(&ID_Signal_My_Sample_Range_497,ID_Variable_org_input_495);
			EMIT(SIG_ID_Signal_My_Sample_Range_497);
		}
		_StrlSampleRange(&ID_Variable_input_range_502,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_503,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_inside_input_504,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_505,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_506,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_507,0);
		_integer(&ID_Variable_maxOutSize_508,0);
		_integer(&ID_Variable_temp_int_509,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_510,INITIAL_UNSIGNEDINT);
		current_point_bit_vector[0] |= 0x400000; /* On:  #22*/
	} else {
		next_point_bit_vector[0] |= 0x200000; /* PauseOn:  #21*/
	}
}

static void Point_22() {
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_497,0)) {
		_StrlSampleRange(&ID_Variable_input_range_502,ID_Signal_My_Sample_Range_497);
		_StrlSampleRange(&ID_Variable_output_range_503,DOWNCASTS(ID_Variable_input_range_502, ID_InputOutput_Scopesink_module_45));
		_StrlSampleIndex(&ID_Variable_pendingWP_505,GETMARKEDWP(ID_InputOutput_Scopesink_module_45));
		_StrlSampleIndex(&ID_Variable_desiredWP_506,ADD_INDEX_SIZE(ID_Variable_output_range_503));
		_integer(&ID_Variable_requestSize_507,SUBTRACT_A_B(ID_Variable_desiredWP_506, ID_Variable_pendingWP_505));
		_integer(&ID_Variable_maxOutSize_508,GETMAXOUTSIZE(ID_InputOutput_Scopesink_module_45));
		if ((ID_Variable_requestSize_507 > ID_Variable_maxOutSize_508)) {
			_integer(&ID_Variable_requestSize_507,ID_Variable_maxOutSize_508);
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_510,GET_OUTPUTSIZE(ID_InputOutput_Scopesink_module_45));
		_integer(&ID_Variable_requestSize_507,ROUNDOWN_SIZE(ID_Variable_requestSize_507, ID_Variable_temp_unsigned_510));
		_StrlSampleRange(&ID_Variable_output_range_503,SET_SAMPLERANGE(ID_Variable_pendingWP_505, ID_Variable_requestSize_507));
		_StrlSampleRange(&ID_Variable_inside_input_504,FORECASTS(ID_Variable_output_range_503, ID_InputOutput_Scopesink_module_45));
		_integer(&ID_Variable_temp_int_509,REAL_FIT_RANGE(ID_Variable_pendingWP_505, ID_Variable_requestSize_507, ID_Variable_inside_input_504, ID_InputOutput_Scopesink_module_45));
		LOCALINCAWAITTICK(ID_InputOutput_Scopesink_module_45);
		next_point_bit_vector[0] |= 0x800000; /* PauseOn:  #23*/
	} else {
		next_point_bit_vector[0] |= 0x400000; /* PauseOn:  #22*/
	}
}

static void Point_23() {
	_StrlSampleRange(&ID_Signal_forecast_range_498,ID_Variable_inside_input_504);
	EMIT(SIG_ID_Signal_forecast_range_498);
	_StrlSampleRange(&ID_Variable_my_input_496,ID_Signal_forecast_range_498);
	EMIT(SIG_ID_Signal_switch_off_500);
	if (ID_Variable_CONT_FLAG_493) {
		current_point_bit_vector[3] |= 0x400000; /* On:  #118*/
	} else {
		current_point_bit_vector[3] |= 0x200000; /* On:  #117*/
	}
}

static void Point_24() {
	_StrlSampleRange(&ID_Signal_Ack_Wire_M_S1_90,ID_Variable_my_input_496);
	EMIT(SIG_ID_Signal_Ack_Wire_M_S1_90);
	next_point_bit_vector[0] |= 0x200000; /* PauseOn:  #21*/
}

static void Point_25() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_499,0)) {
		current_point_bit_vector[1] |= 0x4000; /* On:  #46*/
		next_point_bit_vector[0] |= 0x4000000; /* PauseOn:  #26*/
	} else {
		next_point_bit_vector[0] |= 0x2000000; /* PauseOn:  #25*/
	}
}

static void Point_26() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_off_500,0)) {
		current_point_bit_vector[1] &= ~0x4000; /* Off:  #46*/
		if (IS_SIGNAL(SIG_ID_Signal_switch_on_499,0)) {
			EMIT(SIG_ID_Signal_Clock_Wire_M_S1_94);
			next_point_bit_vector[0] |= 0x4000000; next_point_bit_vector[1] |= 0x4000; /* PauseOn:  #26 #46*/
		} else {
			next_point_bit_vector[0] |= 0x2000000; /* PauseOn:  #25*/
		}
	} else {
		next_point_bit_vector[0] |= 0x4000000; /* PauseOn:  #26*/
	}
}

static void Point_27() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_81,0)) {
		EMIT(SIG_ID_Signal_switch_on_517);
		_StrlSampleRange(&ID_Variable_org_input_513,ID_Signal_Mark_Wire_M_S1_81);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_515,ID_Variable_org_input_513);
		EMIT(SIG_ID_Signal_My_Sample_Range_515);
		current_point_bit_vector[1] |= 0x20000; /* On:  #49*/
	} else {
		next_point_bit_vector[0] |= 0x8000000; /* PauseOn:  #27*/
	}
}

static void Point_28() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_81,0)) {
		EMIT(SIG_ID_Exception_main_trap_522);
		current_point_bit_vector[1] |= 0x10000; /* On:  #48*/
		current_point_bit_vector[1] &= ~0x40000; /* Off:  #50*/
	} else {
		next_point_bit_vector[0] |= 0x10000000; /* PauseOn:  #28*/
	}
}

static void Point_29() {
	_StrlSampleRange(&ID_Signal_Mark_Wire_M_S2_82,ID_Variable_output_range_524);
	EMIT(SIG_ID_Signal_Mark_Wire_M_S2_82);
	_StrlSampleRange(&ID_Signal_forecast_range_516,ID_Variable_inside_input_525);
	EMIT(SIG_ID_Signal_forecast_range_516);
	_StrlSampleRange(&ID_Variable_my_input_514,ID_Signal_forecast_range_516);
	EMIT(SIG_ID_Signal_switch_off_518);
	current_point_bit_vector[3] |= 0x800000; /* On:  #119*/
}

static void Point_30() {
	CLEAR_SIGNAL(SIG_ID_Exception_main_loop_540);
	current_point_bit_vector[1] |= 0x2000000; /* On:  #57*/
}

static void Point_31() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_off_518,0)) {
		current_point_bit_vector[2] |= 0x80; /* On:  #71*/
		current_point_bit_vector[2] &= ~0x1; /* Off:  #64*/
	} else {
		next_point_bit_vector[0] |= 0x80000000; /* PauseOn:  #31*/
	}
}

static void Point_32() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S2_82,0)) {
		EMIT(SIG_ID_Signal_switch_on_546);
		_StrlSampleRange(&ID_Variable_org_input_542,ID_Signal_Mark_Wire_M_S2_82);
		CLEAR_SIGNAL(SIG_ID_Exception_compute_loop_549);
		if (ID_Variable_CONT_FLAG_541) {
			_StrlSampleRange(&ID_Signal_My_Sample_Range_544,ID_Variable_my_input_543);
			EMIT(SIG_ID_Signal_My_Sample_Range_544);
		} else {
			_StrlSampleRange(&ID_Signal_My_Sample_Range_544,ID_Variable_org_input_542);
			EMIT(SIG_ID_Signal_My_Sample_Range_544);
		}
		_StrlSampleRange(&ID_Variable_input_range_550,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_551,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_inside_input_552,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_553,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_554,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_555,0);
		_integer(&ID_Variable_maxOutSize_556,0);
		_integer(&ID_Variable_temp_int_557,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_558,INITIAL_UNSIGNEDINT);
		current_point_bit_vector[1] |= 0x2; /* On:  #33*/
	} else {
		next_point_bit_vector[1] |= 0x1; /* PauseOn:  #32*/
	}
}

static void Point_33() {
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_544,0)) {
		_StrlSampleRange(&ID_Variable_input_range_550,ID_Signal_My_Sample_Range_544);
		_StrlSampleRange(&ID_Variable_output_range_551,DOWNCASTS(ID_Variable_input_range_550, ID_InputOutput_Sink_module_46));
		_StrlSampleIndex(&ID_Variable_pendingWP_553,GETMARKEDWP(ID_InputOutput_Sink_module_46));
		_StrlSampleIndex(&ID_Variable_desiredWP_554,ADD_INDEX_SIZE(ID_Variable_output_range_551));
		_integer(&ID_Variable_requestSize_555,SUBTRACT_A_B(ID_Variable_desiredWP_554, ID_Variable_pendingWP_553));
		_integer(&ID_Variable_maxOutSize_556,GETMAXOUTSIZE(ID_InputOutput_Sink_module_46));
		if ((ID_Variable_requestSize_555 > ID_Variable_maxOutSize_556)) {
			_integer(&ID_Variable_requestSize_555,ID_Variable_maxOutSize_556);
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_558,GET_OUTPUTSIZE(ID_InputOutput_Sink_module_46));
		_integer(&ID_Variable_requestSize_555,ROUNDOWN_SIZE(ID_Variable_requestSize_555, ID_Variable_temp_unsigned_558));
		_StrlSampleRange(&ID_Variable_output_range_551,SET_SAMPLERANGE(ID_Variable_pendingWP_553, ID_Variable_requestSize_555));
		_StrlSampleRange(&ID_Variable_inside_input_552,FORECASTS(ID_Variable_output_range_551, ID_InputOutput_Sink_module_46));
		_integer(&ID_Variable_temp_int_557,REAL_FIT_RANGE(ID_Variable_pendingWP_553, ID_Variable_requestSize_555, ID_Variable_inside_input_552, ID_InputOutput_Sink_module_46));
		LOCALINCAWAITTICK(ID_InputOutput_Sink_module_46);
		next_point_bit_vector[1] |= 0x4; /* PauseOn:  #34*/
	} else {
		next_point_bit_vector[1] |= 0x2; /* PauseOn:  #33*/
	}
}

static void Point_34() {
	_StrlSampleRange(&ID_Signal_forecast_range_545,ID_Variable_inside_input_552);
	EMIT(SIG_ID_Signal_forecast_range_545);
	_StrlSampleRange(&ID_Variable_my_input_543,ID_Signal_forecast_range_545);
	EMIT(SIG_ID_Signal_switch_off_547);
	if (ID_Variable_CONT_FLAG_541) {
		current_point_bit_vector[2] |= 0x4; /* On:  #66*/
	} else {
		current_point_bit_vector[2] |= 0x2; /* On:  #65*/
	}
}

static void Point_35() {
	if ((CHECKSAMPLESIZE(ID_Variable_org_input_542, ID_Variable_my_input_543) >= 0)) {
		_StrlSampleRange(&ID_Variable_my_input_543,UPDATESAMPLE(ID_Variable_my_input_543));
		_boolean(&ID_Variable_CONT_FLAG_541,1);
		if (ID_Variable_CONT_FLAG_541) {
			_StrlSampleRange(&ID_Signal_My_Sample_Range_544,ID_Variable_my_input_543);
			EMIT(SIG_ID_Signal_My_Sample_Range_544);
		} else {
			_StrlSampleRange(&ID_Signal_My_Sample_Range_544,ID_Variable_org_input_542);
			EMIT(SIG_ID_Signal_My_Sample_Range_544);
		}
		_StrlSampleRange(&ID_Variable_input_range_550,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_551,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_inside_input_552,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_553,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_554,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_555,0);
		_integer(&ID_Variable_maxOutSize_556,0);
		_integer(&ID_Variable_temp_int_557,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_558,INITIAL_UNSIGNEDINT);
		if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_544,0)) {
			_StrlSampleRange(&ID_Variable_input_range_550,ID_Signal_My_Sample_Range_544);
			_StrlSampleRange(&ID_Variable_output_range_551,DOWNCASTS(ID_Variable_input_range_550, ID_InputOutput_Sink_module_46));
			_StrlSampleIndex(&ID_Variable_pendingWP_553,GETMARKEDWP(ID_InputOutput_Sink_module_46));
			_StrlSampleIndex(&ID_Variable_desiredWP_554,ADD_INDEX_SIZE(ID_Variable_output_range_551));
			_integer(&ID_Variable_requestSize_555,SUBTRACT_A_B(ID_Variable_desiredWP_554, ID_Variable_pendingWP_553));
			_integer(&ID_Variable_maxOutSize_556,GETMAXOUTSIZE(ID_InputOutput_Sink_module_46));
			if ((ID_Variable_requestSize_555 > ID_Variable_maxOutSize_556)) {
				_integer(&ID_Variable_requestSize_555,ID_Variable_maxOutSize_556);
			}
			_UnsignedInt(&ID_Variable_temp_unsigned_558,GET_OUTPUTSIZE(ID_InputOutput_Sink_module_46));
			_integer(&ID_Variable_requestSize_555,ROUNDOWN_SIZE(ID_Variable_requestSize_555, ID_Variable_temp_unsigned_558));
			_StrlSampleRange(&ID_Variable_output_range_551,SET_SAMPLERANGE(ID_Variable_pendingWP_553, ID_Variable_requestSize_555));
			_StrlSampleRange(&ID_Variable_inside_input_552,FORECASTS(ID_Variable_output_range_551, ID_InputOutput_Sink_module_46));
			_integer(&ID_Variable_temp_int_557,REAL_FIT_RANGE(ID_Variable_pendingWP_553, ID_Variable_requestSize_555, ID_Variable_inside_input_552, ID_InputOutput_Sink_module_46));
			LOCALINCAWAITTICK(ID_InputOutput_Sink_module_46);
			next_point_bit_vector[1] |= 0x4; /* PauseOn:  #34*/
		} else {
			next_point_bit_vector[1] |= 0x2; /* PauseOn:  #33*/
		}
	} else {
		_boolean(&ID_Variable_CONT_FLAG_541,0);
		EMIT(SIG_ID_Exception_compute_loop_549);
		_StrlSampleRange(&ID_Signal_Ack_Wire_M_S2_91,ID_Variable_my_input_543);
		EMIT(SIG_ID_Signal_Ack_Wire_M_S2_91);
		next_point_bit_vector[1] |= 0x1; /* PauseOn:  #32*/
		next_point_bit_vector[1] &= ~0xe; next_point_bit_vector[2] &= ~0x2; /* PauseOff:  #33 #34 #35 #65*/
	}
}

static void Point_36() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_546,0)) {
		current_point_bit_vector[1] |= 0x1000000; /* On:  #56*/
		next_point_bit_vector[1] |= 0x20; /* PauseOn:  #37*/
	} else {
		next_point_bit_vector[1] |= 0x10; /* PauseOn:  #36*/
	}
}

static void Point_37() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_off_547,0)) {
		current_point_bit_vector[1] &= ~0x1000000; /* Off:  #56*/
		if (IS_SIGNAL(SIG_ID_Signal_switch_on_546,0)) {
			EMIT(SIG_ID_Signal_Clock_Wire_M_S2_95);
			next_point_bit_vector[1] |= 0x1000020; /* PauseOn:  #37 #56*/
		} else {
			next_point_bit_vector[1] |= 0x10; /* PauseOn:  #36*/
		}
	} else {
		next_point_bit_vector[1] |= 0x20; /* PauseOn:  #37*/
	}
}

static void Point_38() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) {
		STOP_PERF_GRAPH();
		RUN_GUI_MAIN();
		START_PERF_GRAPH();
		next_point_bit_vector[1] |= 0x40; /* PauseOn:  #38*/
	} else {
		next_point_bit_vector[1] |= 0x40; /* PauseOn:  #38*/
	}
}

static void Point_39() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) {
		next_point_bit_vector[2] |= 0x100; /* PauseOn:  #72*/
	} else {
		next_point_bit_vector[1] |= 0x80; /* PauseOn:  #39*/
	}
}

static void Point_40() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) {
		EMIT(SIG_ID_Exception_main_trap_472);
		current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
		current_point_bit_vector[2] &= ~0x20000; /* Off:  #81*/
	} else {
		next_point_bit_vector[1] |= 0x100; /* PauseOn:  #40*/
	}
}

static void Point_41() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) {
		EMIT(SIG_ID_Exception_main_trap_472);
		current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
		current_point_bit_vector[2] &= ~0x20000; /* Off:  #81*/
	} else {
		next_point_bit_vector[1] |= 0x200; /* PauseOn:  #41*/
	}
}

static void Point_42() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) {
		next_point_bit_vector[0] |= 0x10000; /* PauseOn:  #16*/
	} else {
		next_point_bit_vector[1] |= 0x400; /* PauseOn:  #42*/
	}
}

static void Point_43() {
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0))) {
		EMIT(SIG_ID_Exception_main_trap_472);
		current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
		current_point_bit_vector[2] &= ~0x20000; /* Off:  #81*/
		next_point_bit_vector[1] |= 0x800; /* PauseOn:  #43*/
	} else {
		next_point_bit_vector[1] |= 0x800; /* PauseOn:  #43*/
	}
}

static void Point_44() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) {
		EMIT(SIG_ID_Exception_main_trap_472);
		current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
		current_point_bit_vector[2] &= ~0x20000; /* Off:  #81*/
	} else {
		next_point_bit_vector[1] |= 0x1000; /* PauseOn:  #44*/
	}
}

static void Point_45() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) {
		EMIT(SIG_ID_Exception_main_trap_473);
		current_point_bit_vector[2] |= 0x8000000; /* On:  #91*/
		current_point_bit_vector[2] &= ~0x40000000; /* Off:  #94*/
	} else {
		next_point_bit_vector[1] |= 0x2000; /* PauseOn:  #45*/
	}
}

static void Point_46() {
	EMIT(SIG_ID_Signal_Clock_Wire_M_S1_94);
	next_point_bit_vector[1] |= 0x4000; /* PauseOn:  #46*/
}

static void Point_47() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_91,0)) {
		EMIT(SIG_ID_Exception_main_trap_522);
		current_point_bit_vector[1] |= 0x10000; /* On:  #48*/
		current_point_bit_vector[1] &= ~0x40000; /* Off:  #50*/
	} else {
		next_point_bit_vector[1] |= 0x8000; /* PauseOn:  #47*/
	}
}

static void Point_48() {
	EMIT(SIG_ID_Signal_switch_on_517);
	_StrlSampleRange(&ID_Variable_org_input_513,ID_Signal_Mark_Wire_M_S1_81);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_515,ID_Variable_org_input_513);
	EMIT(SIG_ID_Signal_My_Sample_Range_515);
	current_point_bit_vector[1] |= 0x20000; /* On:  #49*/
	next_point_bit_vector[0] &= ~0x10000000; next_point_bit_vector[1] &= ~0x48000; /* PauseOff:  #28 #47 #50*/
}

static void Point_49() {
	CLEAR_SIGNAL(SIG_ID_Exception_compute_loop_521);
	if (ID_Variable_CONT_FLAG_511) {
		next_point_bit_vector[1] |= 0x200000; /* PauseOn:  #53*/
	} else {
		current_point_bit_vector[1] |= 0x400000; /* On:  #54*/
	}
}

static void Point_50() {
	if (next_point_bit_vector[0]&0x10000000) return;
	 if (next_point_bit_vector[1]&0x48000) return;
	 /* isPauseOn:  #28 #47 #50*/
	next_point_bit_vector[1] |= 0x40000; /* PauseOn:  #50*/
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_91,0)) {
		next_point_bit_vector[0] |= 0x10000000; /* PauseOn:  #28*/
	} else {
		current_point_bit_vector[1] |= 0x80000; /* On:  #51*/
	}
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_81,0)) {
		next_point_bit_vector[1] |= 0x8000; /* PauseOn:  #47*/
	} else {
		current_point_bit_vector[1] |= 0x80000; /* On:  #51*/
	}
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_81,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_91,0))) {
		current_point_bit_vector[1] |= 0x100000; /* On:  #52*/
	} else {
		current_point_bit_vector[1] |= 0x80000; /* On:  #51*/
	}
}

static void Point_51() {
	if (next_point_bit_vector[0]&0x10000000) return;
	 if (next_point_bit_vector[1]&0x8000) return;
	 /* isPauseOn:  #28 #47*/
}

static void Point_52() {
	EMIT(SIG_ID_Exception_main_trap_522);
	current_point_bit_vector[1] &= ~0x80000; /* Off:  #51*/
}

static void Point_53() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_91,0)) {
		_StrlSampleRange(&ID_Signal_My_Sample_Range_515,ID_Variable_my_input_514);
		EMIT(SIG_ID_Signal_My_Sample_Range_515);
		current_point_bit_vector[1] |= 0x400000; /* On:  #54*/
	} else {
		next_point_bit_vector[1] |= 0x200000; /* PauseOn:  #53*/
	}
}

static void Point_54() {
	_StrlSampleRange(&ID_Variable_input_range_523,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_output_range_524,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_inside_input_525,INITIAL_RANGE);
	_StrlSampleIndex(&ID_Variable_pendingWP_526,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_desiredWP_527,INITIAL_INDEX);
	_integer(&ID_Variable_requestSize_528,0);
	_integer(&ID_Variable_maxOutSize_529,0);
	_integer(&ID_Variable_temp_int_530,0);
	_UnsignedInt(&ID_Variable_temp_unsigned_531,INITIAL_UNSIGNEDINT);
	current_point_bit_vector[1] |= 0x800000; /* On:  #55*/
}

static void Point_55() {
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_515,0)) {
		_StrlSampleRange(&ID_Variable_input_range_523,ID_Signal_My_Sample_Range_515);
		_StrlSampleRange(&ID_Variable_output_range_524,DOWNCASTS(ID_Variable_input_range_523, ID_InputOutput_Summer_module_44));
		_StrlSampleIndex(&ID_Variable_pendingWP_526,GETMARKEDWP(ID_InputOutput_Summer_module_44));
		_StrlSampleIndex(&ID_Variable_desiredWP_527,ADD_INDEX_SIZE(ID_Variable_output_range_524));
		_integer(&ID_Variable_requestSize_528,SUBTRACT_A_B(ID_Variable_desiredWP_527, ID_Variable_pendingWP_526));
		_integer(&ID_Variable_maxOutSize_529,GETMAXOUTSIZE(ID_InputOutput_Summer_module_44));
		if ((ID_Variable_requestSize_528 > ID_Variable_maxOutSize_529)) {
			_integer(&ID_Variable_requestSize_528,ID_Variable_maxOutSize_529);
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_531,GET_OUTPUTSIZE(ID_InputOutput_Summer_module_44));
		_integer(&ID_Variable_requestSize_528,ROUNDOWN_SIZE(ID_Variable_requestSize_528, ID_Variable_temp_unsigned_531));
		_StrlSampleRange(&ID_Variable_output_range_524,SET_SAMPLERANGE(ID_Variable_pendingWP_526, ID_Variable_requestSize_528));
		_StrlSampleRange(&ID_Variable_inside_input_525,FORECASTS(ID_Variable_output_range_524, ID_InputOutput_Summer_module_44));
		_integer(&ID_Variable_temp_int_530,REAL_FIT_RANGE(ID_Variable_pendingWP_526, ID_Variable_requestSize_528, ID_Variable_inside_input_525, ID_InputOutput_Summer_module_44));
		LOCALINCAWAITTICK(ID_InputOutput_Summer_module_44);
		next_point_bit_vector[0] |= 0x20000000; /* PauseOn:  #29*/
	} else {
		next_point_bit_vector[1] |= 0x800000; /* PauseOn:  #55*/
	}
}

static void Point_56() {
	EMIT(SIG_ID_Signal_Clock_Wire_M_S2_95);
	next_point_bit_vector[1] |= 0x1000000; /* PauseOn:  #56*/
}

static void Point_57() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_M_S2_95,0)) {
		next_point_bit_vector[1] |= 0x2000000; /* PauseOn:  #57*/
	} else {
		next_point_bit_vector[1] |= 0xc000000; /* PauseOn:  #58 #59*/
	}
}

static void Point_58() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_M_S2_95,0)) {
		next_point_bit_vector[1] |= current_point_bit_vector[1] & 0x8000000; current_point_bit_vector[1] &= ~0x8000000; /* Suspend:  #59*/
		next_point_bit_vector[1] |= 0x4000000; /* PauseOn:  #58*/
	} else {
		next_point_bit_vector[1] |= 0x4000000; /* PauseOn:  #58*/
	}
}

static void Point_59() {
	EMIT(SIG_ID_Exception_main_loop_540);
	EMIT(SIG_ID_Signal_Compute_Wire_M_S2_86);
	next_point_bit_vector[1] &= ~0xc000000; /* PauseOff:  #58 #59*/
	if ((CHECKSAMPLESIZE(ID_Variable_org_input_513, ID_Variable_my_input_514) >= 0)) {
		current_point_bit_vector[1] |= 0x40000000; /* On:  #62*/
	} else {
		_boolean(&ID_Variable_CONT_FLAG_511,0);
		EMIT(SIG_ID_Exception_compute_loop_521);
		_StrlSampleRange(&ID_Signal_Ack_Wire_M_M2_89,ID_Variable_my_input_514);
		EMIT(SIG_ID_Signal_Ack_Wire_M_M2_89);
		next_point_bit_vector[0] &= ~0x60000000; next_point_bit_vector[1] &= ~0xca00000; next_point_bit_vector[3] &= ~0x800000; /* PauseOff:  #29 #30 #53 #55 #58 #59 #119*/
		if (IS_SIGNAL(SIG_ID_Signal_INI_PHASE_520,0)) {
			next_point_bit_vector[0] |= 0x8000000; /* PauseOn:  #27*/
		} else {
			CLEAR_SIGNAL(SIG_ID_Exception_main_trap_522);
			next_point_bit_vector[1] |= 0x40000; /* PauseOn:  #50*/
			if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_91,0)) {
				next_point_bit_vector[0] |= 0x10000000; /* PauseOn:  #28*/
			} else {
				current_point_bit_vector[1] |= 0x10000000; /* On:  #60*/
			}
			if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_81,0)) {
				next_point_bit_vector[1] |= 0x8000; /* PauseOn:  #47*/
			} else {
				current_point_bit_vector[1] |= 0x10000000; /* On:  #60*/
			}
			if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_81,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_91,0))) {
				current_point_bit_vector[1] |= 0x20000000; /* On:  #61*/
			} else {
				current_point_bit_vector[1] |= 0x10000000; /* On:  #60*/
			}
		}
	}
}

static void Point_60() {
	if (next_point_bit_vector[0]&0x10000000) return;
	 if (next_point_bit_vector[1]&0x8000) return;
	 /* isPauseOn:  #28 #47*/
}

static void Point_61() {
	EMIT(SIG_ID_Exception_main_trap_522);
	EMIT(SIG_ID_Signal_switch_on_517);
	_StrlSampleRange(&ID_Variable_org_input_513,ID_Signal_Mark_Wire_M_S1_81);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_515,ID_Variable_org_input_513);
	EMIT(SIG_ID_Signal_My_Sample_Range_515);
	CLEAR_SIGNAL(SIG_ID_Exception_compute_loop_521);
	current_point_bit_vector[1] &= ~0x10000000; /* Off:  #60*/
	next_point_bit_vector[0] &= ~0x10000000; next_point_bit_vector[1] &= ~0x48000; /* PauseOff:  #28 #47 #50*/
	if (ID_Variable_CONT_FLAG_511) {
		next_point_bit_vector[1] |= 0x200000; /* PauseOn:  #53*/
	} else {
		_StrlSampleRange(&ID_Variable_input_range_523,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_524,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_inside_input_525,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_526,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_527,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_528,0);
		_integer(&ID_Variable_maxOutSize_529,0);
		_integer(&ID_Variable_temp_int_530,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_531,INITIAL_UNSIGNEDINT);
		if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_515,0)) {
			_StrlSampleRange(&ID_Variable_input_range_523,ID_Signal_My_Sample_Range_515);
			_StrlSampleRange(&ID_Variable_output_range_524,DOWNCASTS(ID_Variable_input_range_523, ID_InputOutput_Summer_module_44));
			_StrlSampleIndex(&ID_Variable_pendingWP_526,GETMARKEDWP(ID_InputOutput_Summer_module_44));
			_StrlSampleIndex(&ID_Variable_desiredWP_527,ADD_INDEX_SIZE(ID_Variable_output_range_524));
			_integer(&ID_Variable_requestSize_528,SUBTRACT_A_B(ID_Variable_desiredWP_527, ID_Variable_pendingWP_526));
			_integer(&ID_Variable_maxOutSize_529,GETMAXOUTSIZE(ID_InputOutput_Summer_module_44));
			if ((ID_Variable_requestSize_528 > ID_Variable_maxOutSize_529)) {
				_integer(&ID_Variable_requestSize_528,ID_Variable_maxOutSize_529);
			}
			_UnsignedInt(&ID_Variable_temp_unsigned_531,GET_OUTPUTSIZE(ID_InputOutput_Summer_module_44));
			_integer(&ID_Variable_requestSize_528,ROUNDOWN_SIZE(ID_Variable_requestSize_528, ID_Variable_temp_unsigned_531));
			_StrlSampleRange(&ID_Variable_output_range_524,SET_SAMPLERANGE(ID_Variable_pendingWP_526, ID_Variable_requestSize_528));
			_StrlSampleRange(&ID_Variable_inside_input_525,FORECASTS(ID_Variable_output_range_524, ID_InputOutput_Summer_module_44));
			_integer(&ID_Variable_temp_int_530,REAL_FIT_RANGE(ID_Variable_pendingWP_526, ID_Variable_requestSize_528, ID_Variable_inside_input_525, ID_InputOutput_Summer_module_44));
			LOCALINCAWAITTICK(ID_InputOutput_Summer_module_44);
			next_point_bit_vector[0] |= 0x20000000; /* PauseOn:  #29*/
		} else {
			next_point_bit_vector[1] |= 0x800000; /* PauseOn:  #55*/
		}
	}
}

static void Point_62() {
	_StrlSampleRange(&ID_Variable_my_input_514,UPDATESAMPLE(ID_Variable_my_input_514));
	_boolean(&ID_Variable_CONT_FLAG_511,1);
	if (ID_Variable_CONT_FLAG_511) {
		next_point_bit_vector[1] |= 0x200000; /* PauseOn:  #53*/
	} else {
		_StrlSampleRange(&ID_Variable_input_range_523,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_524,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_inside_input_525,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_526,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_527,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_528,0);
		_integer(&ID_Variable_maxOutSize_529,0);
		_integer(&ID_Variable_temp_int_530,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_531,INITIAL_UNSIGNEDINT);
		if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_515,0)) {
			_StrlSampleRange(&ID_Variable_input_range_523,ID_Signal_My_Sample_Range_515);
			_StrlSampleRange(&ID_Variable_output_range_524,DOWNCASTS(ID_Variable_input_range_523, ID_InputOutput_Summer_module_44));
			_StrlSampleIndex(&ID_Variable_pendingWP_526,GETMARKEDWP(ID_InputOutput_Summer_module_44));
			_StrlSampleIndex(&ID_Variable_desiredWP_527,ADD_INDEX_SIZE(ID_Variable_output_range_524));
			_integer(&ID_Variable_requestSize_528,SUBTRACT_A_B(ID_Variable_desiredWP_527, ID_Variable_pendingWP_526));
			_integer(&ID_Variable_maxOutSize_529,GETMAXOUTSIZE(ID_InputOutput_Summer_module_44));
			if ((ID_Variable_requestSize_528 > ID_Variable_maxOutSize_529)) {
				_integer(&ID_Variable_requestSize_528,ID_Variable_maxOutSize_529);
			}
			_UnsignedInt(&ID_Variable_temp_unsigned_531,GET_OUTPUTSIZE(ID_InputOutput_Summer_module_44));
			_integer(&ID_Variable_requestSize_528,ROUNDOWN_SIZE(ID_Variable_requestSize_528, ID_Variable_temp_unsigned_531));
			_StrlSampleRange(&ID_Variable_output_range_524,SET_SAMPLERANGE(ID_Variable_pendingWP_526, ID_Variable_requestSize_528));
			_StrlSampleRange(&ID_Variable_inside_input_525,FORECASTS(ID_Variable_output_range_524, ID_InputOutput_Summer_module_44));
			_integer(&ID_Variable_temp_int_530,REAL_FIT_RANGE(ID_Variable_pendingWP_526, ID_Variable_requestSize_528, ID_Variable_inside_input_525, ID_InputOutput_Summer_module_44));
			LOCALINCAWAITTICK(ID_InputOutput_Summer_module_44);
			next_point_bit_vector[0] |= 0x20000000; /* PauseOn:  #29*/
		} else {
			next_point_bit_vector[1] |= 0x800000; /* PauseOn:  #55*/
		}
	}
}

static void Point_63() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_517,0)) {
		current_point_bit_vector[2] |= 0x1; /* On:  #64*/
		next_point_bit_vector[0] |= 0x80000000; /* PauseOn:  #31*/
	} else {
		next_point_bit_vector[1] |= 0x80000000; /* PauseOn:  #63*/
	}
}

static void Point_64() {
	EMIT(SIG_ID_Signal_Clock_Wire_M_S1_94);
	next_point_bit_vector[2] |= 0x1; /* PauseOn:  #64*/
}

static void Point_65() {
	if (IS_SIGNAL(SIG_ID_Signal_Compute_Wire_M_S2_86,0)) {
		current_point_bit_vector[2] |= 0x4; /* On:  #66*/
	} else {
		next_point_bit_vector[2] |= 0x2; /* PauseOn:  #65*/
	}
}

static void Point_66() {
	_integer(&ID_Variable_temp_int_559,0);
	_integer(&ID_Variable_not_source_560,0);
	_integer(&ID_Variable_not_complete_flag_561,0);
	_StrlSampleIndex(&ID_Variable_temp_index_562,INITIAL_INDEX);
	_StrlSampleRange(&ID_Variable_temp_range_563,INITIAL_RANGE);
	_StrlSampleSize(&ID_Variable_complete_var_564,INITIAL_SIZE);
	CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_565);
	CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_566);
	if (_eq_integer(CHECK_MYWRITERLL(ID_InputOutput_Sink_module_46),0)) {
		current_point_bit_vector[2] |= 0x20; /* On:  #69*/
	} else {
		if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_InputOutput_Sink_module_46),0)) {
			current_point_bit_vector[2] |= 0x10; /* On:  #68*/
		} else {
			if ((GET_NUMBERINPUTS(ID_InputOutput_Sink_module_46) > 0)) {
				_integer(&ID_Variable_not_source_560,1);
			}
			_StrlSampleSize(&ID_Variable_complete_var_564,REALCOMPUTEDATA(ID_InputOutput_Sink_module_46, ID_Variable_not_source_560));
			if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_InputOutput_Sink_module_46), ID_Variable_complete_var_564) > 0)) {
				_integer(&ID_Variable_not_complete_flag_561,(ID_Variable_not_complete_flag_561 - 1));
				current_point_bit_vector[2] |= 0x8; /* On:  #67*/
			} else {
				current_point_bit_vector[2] |= 0x8; /* On:  #67*/
			}
		}
	}
}

static void Point_67() {
	if ((ID_Variable_not_complete_flag_561 < 0)) {
		_StrlSampleIndex(&ID_Variable_temp_index_562,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_InputOutput_Sink_module_46), ID_Variable_complete_var_564));
		SET_MARKEDWP(ID_InputOutput_Sink_module_46, ID_Variable_temp_index_562);
	}
	WRITEDATA(ID_InputOutput_Sink_module_46, ID_Variable_not_source_560);
	_StrlSampleIndex(&ID_Variable_temp_index_562,GETWP(ID_InputOutput_Sink_module_46));
	_StrlSampleRange(&ID_Output_SINK_COMPUTEDSR_52,GET_MYMARKEDDATA(ID_InputOutput_Sink_module_46));
	UDP_FLOW_O_SINK_COMPUTEDSR(ID_Output_SINK_COMPUTEDSR_52); EMIT(SIG_ID_Output_SINK_COMPUTEDSR_52);
	current_point_bit_vector[2] |= 0x40; /* On:  #70*/
}

static void Point_68() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_565);
	current_point_bit_vector[2] |= 0x40; /* On:  #70*/
	current_point_bit_vector[2] &= ~0x8; /* Off:  #67*/
}

static void Point_69() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_565);
	current_point_bit_vector[2] |= 0x40; /* On:  #70*/
	current_point_bit_vector[2] &= ~0x8; /* Off:  #67*/
}

static void Point_70() {
	LOCALINCAWAITTICK(ID_InputOutput_Sink_module_46);
	next_point_bit_vector[1] |= 0x8; /* PauseOn:  #35*/
}

static void Point_71() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_517,0)) {
		EMIT(SIG_ID_Signal_Clock_Wire_M_S1_94);
		next_point_bit_vector[0] |= 0x80000000; next_point_bit_vector[2] |= 0x1; /* PauseOn:  #31 #64*/
	} else {
		next_point_bit_vector[1] |= 0x80000000; /* PauseOn:  #63*/
	}
}

static void Point_72() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0)) {
		EMIT(SIG_ID_Exception_main_trap_472);
		current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
		current_point_bit_vector[2] &= ~0x20000; /* Off:  #81*/
	} else {
		next_point_bit_vector[2] |= 0x100; /* PauseOn:  #72*/
	}
}

static void Point_73() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0)) {
		next_point_bit_vector[1] |= 0x100; /* PauseOn:  #40*/
	} else {
		next_point_bit_vector[2] |= 0x200; /* PauseOn:  #73*/
	}
}

static void Point_74() {
	if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0))) {
		EMIT(SIG_ID_Exception_main_trap_472);
		current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
		current_point_bit_vector[2] &= ~0x20000; /* Off:  #81*/
		next_point_bit_vector[2] |= 0x400; /* PauseOn:  #74*/
	} else {
		next_point_bit_vector[2] |= 0x400; /* PauseOn:  #74*/
	}
}

static void Point_75() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0)) {
		EMIT(SIG_ID_Exception_main_trap_472);
		current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
		current_point_bit_vector[2] &= ~0x20000; /* Off:  #81*/
	} else {
		next_point_bit_vector[2] |= 0x800; /* PauseOn:  #75*/
	}
}

static void Point_76() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0)) {
		next_point_bit_vector[0] |= 0x4000; /* PauseOn:  #14*/
	} else {
		next_point_bit_vector[2] |= 0x1000; /* PauseOn:  #76*/
	}
}

static void Point_77() {
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0))) {
		EMIT(SIG_ID_Exception_main_trap_472);
		current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
		current_point_bit_vector[2] &= ~0x20000; /* Off:  #81*/
		next_point_bit_vector[2] |= 0x2000; /* PauseOn:  #77*/
	} else {
		next_point_bit_vector[2] |= 0x2000; /* PauseOn:  #77*/
	}
}

static void Point_78() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0)) {
		EMIT(SIG_ID_Exception_main_trap_472);
		current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
		current_point_bit_vector[2] &= ~0x20000; /* Off:  #81*/
	} else {
		next_point_bit_vector[2] |= 0x4000; /* PauseOn:  #78*/
	}
}

static void Point_79() {
	EMIT(SIG_ID_Signal_switch_on_467);
	_StrlSampleRange(&ID_Variable_org_input_463,ID_Signal_Mark_Wire_M_M1_79);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_465,ID_Variable_org_input_463);
	EMIT(SIG_ID_Signal_My_Sample_Range_465);
	current_point_bit_vector[2] |= 0x10000; /* On:  #80*/
	next_point_bit_vector[0] &= ~0x3e000; next_point_bit_vector[1] &= ~0x1f80; next_point_bit_vector[2] &= ~0x27f00; /* PauseOff:  #13 #14 #15 #16 #17 #39 #40 #41 #42 #43 #44 #72 #73 #74 #75 #76 #77 #78 #81*/
}

static void Point_80() {
	CLEAR_SIGNAL(SIG_ID_Exception_compute_loop_471);
	if (ID_Variable_CONT_FLAG_462) {
		CLEAR_SIGNAL(SIG_ID_Exception_main_trap_473);
		next_point_bit_vector[2] |= 0x40000000; /* PauseOn:  #94*/
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) {
			next_point_bit_vector[2] |= 0x4000000; /* PauseOn:  #90*/
		} else {
			current_point_bit_vector[2] |= 0x40000000; /* On:  #94*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0)) {
			next_point_bit_vector[1] |= 0x2000; /* PauseOn:  #45*/
		} else {
			current_point_bit_vector[2] |= 0x40000000; /* On:  #94*/
		}
		if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0))) {
			EMIT(SIG_ID_Exception_main_trap_473);
			current_point_bit_vector[2] |= 0x8000000; /* On:  #91*/
			current_point_bit_vector[2] &= ~0x40000000; /* Off:  #94*/
		} else {
			current_point_bit_vector[2] |= 0x40000000; /* On:  #94*/
		}
	} else {
		current_point_bit_vector[2] |= 0x10000000; /* On:  #92*/
	}
}

static void Point_81() {
	if (next_point_bit_vector[0]&0x3e000) return;
	 if (next_point_bit_vector[1]&0x1f80) return;
	 if (next_point_bit_vector[2]&0x27f00) return;
	 /* isPauseOn:  #13 #14 #15 #16 #17 #39 #40 #41 #42 #43 #44 #72 #73 #74 #75 #76 #77 #78 #81*/
	current_point_bit_vector[2] |= 0xd80000; /* On:  #83 #84 #86 #87*/
	next_point_bit_vector[2] |= 0x20000; /* PauseOn:  #81*/
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) {
		next_point_bit_vector[0] |= 0x2000; next_point_bit_vector[2] |= 0x3000; /* PauseOn:  #13 #76 #77*/
	} else {
		current_point_bit_vector[2] |= 0x40000; /* On:  #82*/
	}
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0)) {
		next_point_bit_vector[1] |= 0x80; next_point_bit_vector[2] |= 0x600; /* PauseOn:  #39 #73 #74*/
	} else {
		current_point_bit_vector[2] |= 0x40000; /* On:  #82*/
	}
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0)) {
		next_point_bit_vector[0] |= 0x8000; next_point_bit_vector[1] |= 0xc00; /* PauseOn:  #15 #42 #43*/
	} else {
		current_point_bit_vector[2] |= 0x40000; /* On:  #82*/
	}
}

static void Point_82() {
	if (next_point_bit_vector[0]&0x1e000) return;
	 if (next_point_bit_vector[1]&0xf80) return;
	 if (next_point_bit_vector[2]&0x3f00) return;
	 /* isPauseOn:  #13 #14 #15 #16 #39 #40 #41 #42 #43 #72 #73 #74 #75 #76 #77*/
	current_point_bit_vector[2] |= 0x200000; /* On:  #85*/
}

static void Point_83() {
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0))) {
		next_point_bit_vector[2] |= 0x4000; /* PauseOn:  #78*/
	} else {
		current_point_bit_vector[2] |= 0x200000; /* On:  #85*/
	}
}

static void Point_84() {
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0))) {
		next_point_bit_vector[1] |= 0x1000; /* PauseOn:  #44*/
	} else {
		current_point_bit_vector[2] |= 0x200000; /* On:  #85*/
	}
}

static void Point_85() {
	if (next_point_bit_vector[0]&0x1e000) return;
	 if (next_point_bit_vector[1]&0x1f80) return;
	 if (next_point_bit_vector[2]&0x7f00) return;
	 /* isPauseOn:  #13 #14 #15 #16 #39 #40 #41 #42 #43 #44 #72 #73 #74 #75 #76 #77 #78*/
	current_point_bit_vector[2] |= 0x1000000; /* On:  #88*/
}

static void Point_86() {
	if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0))) {
		next_point_bit_vector[0] |= 0x20000; /* PauseOn:  #17*/
	} else {
		current_point_bit_vector[2] |= 0x1000000; /* On:  #88*/
	}
}

static void Point_87() {
	if (((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0))) {
		current_point_bit_vector[2] |= 0x2000000; /* On:  #89*/
	} else {
		current_point_bit_vector[2] |= 0x1000000; /* On:  #88*/
	}
}

static void Point_88() {
	if (next_point_bit_vector[0]&0x3e000) return;
	 if (next_point_bit_vector[1]&0x1f80) return;
	 if (next_point_bit_vector[2]&0x7f00) return;
	 /* isPauseOn:  #13 #14 #15 #16 #17 #39 #40 #41 #42 #43 #44 #72 #73 #74 #75 #76 #77 #78*/
}

static void Point_89() {
	EMIT(SIG_ID_Exception_main_trap_472);
	current_point_bit_vector[2] &= ~0x1000000; /* Off:  #88*/
}

static void Point_90() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0)) {
		EMIT(SIG_ID_Exception_main_trap_473);
		current_point_bit_vector[2] |= 0x8000000; /* On:  #91*/
		current_point_bit_vector[2] &= ~0x40000000; /* Off:  #94*/
	} else {
		next_point_bit_vector[2] |= 0x4000000; /* PauseOn:  #90*/
	}
}

static void Point_91() {
	_StrlSampleRange(&ID_Signal_My_Sample_Range_465,ID_Variable_my_input_464);
	EMIT(SIG_ID_Signal_My_Sample_Range_465);
	current_point_bit_vector[2] |= 0x10000000; /* On:  #92*/
	next_point_bit_vector[1] &= ~0x2000; next_point_bit_vector[2] &= ~0x44000000; /* PauseOff:  #45 #90 #94*/
}

static void Point_92() {
	_StrlSampleRange(&ID_Variable_input_range_474,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_output_range_475,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_inside_input_476,INITIAL_RANGE);
	_StrlSampleIndex(&ID_Variable_pendingWP_477,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_desiredWP_478,INITIAL_INDEX);
	_integer(&ID_Variable_requestSize_479,0);
	_integer(&ID_Variable_maxOutSize_480,0);
	_integer(&ID_Variable_temp_int_481,0);
	_UnsignedInt(&ID_Variable_temp_unsigned_482,INITIAL_UNSIGNEDINT);
	current_point_bit_vector[2] |= 0x20000000; /* On:  #93*/
}

static void Point_93() {
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_465,0)) {
		_StrlSampleRange(&ID_Variable_input_range_474,ID_Signal_My_Sample_Range_465);
		_StrlSampleRange(&ID_Variable_output_range_475,DOWNCASTS(ID_Variable_input_range_474, ID_InputOutput_Mod_module_43));
		_StrlSampleIndex(&ID_Variable_pendingWP_477,GETMARKEDWP(ID_InputOutput_Mod_module_43));
		_StrlSampleIndex(&ID_Variable_desiredWP_478,ADD_INDEX_SIZE(ID_Variable_output_range_475));
		_integer(&ID_Variable_requestSize_479,SUBTRACT_A_B(ID_Variable_desiredWP_478, ID_Variable_pendingWP_477));
		_integer(&ID_Variable_maxOutSize_480,GETMAXOUTSIZE(ID_InputOutput_Mod_module_43));
		if ((ID_Variable_requestSize_479 > ID_Variable_maxOutSize_480)) {
			_integer(&ID_Variable_requestSize_479,ID_Variable_maxOutSize_480);
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_482,GET_OUTPUTSIZE(ID_InputOutput_Mod_module_43));
		_integer(&ID_Variable_requestSize_479,ROUNDOWN_SIZE(ID_Variable_requestSize_479, ID_Variable_temp_unsigned_482));
		_StrlSampleRange(&ID_Variable_output_range_475,SET_SAMPLERANGE(ID_Variable_pendingWP_477, ID_Variable_requestSize_479));
		_StrlSampleRange(&ID_Variable_inside_input_476,FORECASTS(ID_Variable_output_range_475, ID_InputOutput_Mod_module_43));
		_integer(&ID_Variable_temp_int_481,REAL_FIT_RANGE(ID_Variable_pendingWP_477, ID_Variable_requestSize_479, ID_Variable_inside_input_476, ID_InputOutput_Mod_module_43));
		LOCALINCAWAITTICK(ID_InputOutput_Mod_module_43);
		next_point_bit_vector[0] |= 0x40000; /* PauseOn:  #18*/
	} else {
		next_point_bit_vector[2] |= 0x20000000; /* PauseOn:  #93*/
	}
}

static void Point_94() {
	if (next_point_bit_vector[1]&0x2000) return;
	 if (next_point_bit_vector[2]&0x44000000) return;
	 /* isPauseOn:  #45 #90 #94*/
	next_point_bit_vector[2] |= 0x40000000; /* PauseOn:  #94*/
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0)) {
		next_point_bit_vector[1] |= 0x2000; /* PauseOn:  #45*/
	} else {
		current_point_bit_vector[2] |= 0x80000000; /* On:  #95*/
	}
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) {
		next_point_bit_vector[2] |= 0x4000000; /* PauseOn:  #90*/
	} else {
		current_point_bit_vector[2] |= 0x80000000; /* On:  #95*/
	}
	if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0))) {
		current_point_bit_vector[3] |= 0x1; /* On:  #96*/
	} else {
		current_point_bit_vector[2] |= 0x80000000; /* On:  #95*/
	}
}

static void Point_95() {
	if (next_point_bit_vector[1]&0x2000) return;
	 if (next_point_bit_vector[2]&0x4000000) return;
	 /* isPauseOn:  #45 #90*/
}

static void Point_96() {
	EMIT(SIG_ID_Exception_main_trap_473);
	current_point_bit_vector[2] &= ~0x80000000; /* Off:  #95*/
}

static void Point_97() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_M_S1_94,0)) {
		next_point_bit_vector[3] |= 0x2; /* PauseOn:  #97*/
	} else {
		next_point_bit_vector[3] |= 0xc; /* PauseOn:  #98 #99*/
	}
}

static void Point_98() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_M_S1_94,0)) {
		next_point_bit_vector[3] |= current_point_bit_vector[3] & 0x8; current_point_bit_vector[3] &= ~0x8; /* Suspend:  #99*/
		next_point_bit_vector[3] |= 0x4; /* PauseOn:  #98*/
	} else {
		next_point_bit_vector[3] |= 0x4; /* PauseOn:  #98*/
	}
}

static void Point_99() {
	EMIT(SIG_ID_Exception_main_loop_491);
	EMIT(SIG_ID_Signal_Compute_Wire_M_S1_85);
	next_point_bit_vector[3] &= ~0xc; /* PauseOff:  #98 #99*/
	if ((CHECKSAMPLESIZE(ID_Variable_org_input_463, ID_Variable_my_input_464) >= 0)) {
		current_point_bit_vector[3] |= 0x8000; /* On:  #111*/
	} else {
		_boolean(&ID_Variable_CONT_FLAG_462,0);
		EMIT(SIG_ID_Exception_compute_loop_471);
		_StrlSampleRange(&ID_Signal_Ack_Wire_M_M1_88,ID_Variable_my_input_464);
		EMIT(SIG_ID_Signal_Ack_Wire_M_M1_88);
		next_point_bit_vector[0] &= ~0xc0000; next_point_bit_vector[1] &= ~0x2000; next_point_bit_vector[2] &= ~0x64000000; next_point_bit_vector[3] &= ~0xc; next_point_bit_vector[4] &= ~0x4000; /* PauseOff:  #18 #19 #45 #90 #93 #94 #98 #99 #142*/
		if (IS_SIGNAL(SIG_ID_Signal_INI_PHASE_470,0)) {
			next_point_bit_vector[0] |= 0x1000; /* PauseOn:  #12*/
		} else {
			CLEAR_SIGNAL(SIG_ID_Exception_main_trap_472);
			current_point_bit_vector[3] |= 0x360; /* On:  #101 #102 #104 #105*/
			next_point_bit_vector[2] |= 0x20000; /* PauseOn:  #81*/
			if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) {
				next_point_bit_vector[0] |= 0x2000; next_point_bit_vector[2] |= 0x3000; /* PauseOn:  #13 #76 #77*/
			} else {
				current_point_bit_vector[3] |= 0x10; /* On:  #100*/
			}
			if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0)) {
				next_point_bit_vector[1] |= 0x80; next_point_bit_vector[2] |= 0x600; /* PauseOn:  #39 #73 #74*/
			} else {
				current_point_bit_vector[3] |= 0x10; /* On:  #100*/
			}
			if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0)) {
				next_point_bit_vector[0] |= 0x8000; next_point_bit_vector[1] |= 0xc00; /* PauseOn:  #15 #42 #43*/
			} else {
				current_point_bit_vector[3] |= 0x10; /* On:  #100*/
			}
		}
	}
}

static void Point_100() {
	if (next_point_bit_vector[0]&0x1e000) return;
	 if (next_point_bit_vector[1]&0xf80) return;
	 if (next_point_bit_vector[2]&0x3f00) return;
	 /* isPauseOn:  #13 #14 #15 #16 #39 #40 #41 #42 #43 #72 #73 #74 #75 #76 #77*/
	current_point_bit_vector[3] |= 0x80; /* On:  #103*/
}

static void Point_101() {
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0))) {
		next_point_bit_vector[2] |= 0x4000; /* PauseOn:  #78*/
	} else {
		current_point_bit_vector[3] |= 0x80; /* On:  #103*/
	}
}

static void Point_102() {
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0))) {
		next_point_bit_vector[1] |= 0x1000; /* PauseOn:  #44*/
	} else {
		current_point_bit_vector[3] |= 0x80; /* On:  #103*/
	}
}

static void Point_103() {
	if (next_point_bit_vector[0]&0x1e000) return;
	 if (next_point_bit_vector[1]&0x1f80) return;
	 if (next_point_bit_vector[2]&0x7f00) return;
	 /* isPauseOn:  #13 #14 #15 #16 #39 #40 #41 #42 #43 #44 #72 #73 #74 #75 #76 #77 #78*/
	current_point_bit_vector[3] |= 0x400; /* On:  #106*/
}

static void Point_104() {
	if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0))) {
		next_point_bit_vector[0] |= 0x20000; /* PauseOn:  #17*/
	} else {
		current_point_bit_vector[3] |= 0x400; /* On:  #106*/
	}
}

static void Point_105() {
	if (((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_79,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0))) {
		current_point_bit_vector[3] |= 0x800; /* On:  #107*/
	} else {
		current_point_bit_vector[3] |= 0x400; /* On:  #106*/
	}
}

static void Point_106() {
	if (next_point_bit_vector[0]&0x3e000) return;
	 if (next_point_bit_vector[1]&0x1f80) return;
	 if (next_point_bit_vector[2]&0x7f00) return;
	 /* isPauseOn:  #13 #14 #15 #16 #17 #39 #40 #41 #42 #43 #44 #72 #73 #74 #75 #76 #77 #78*/
}

static void Point_107() {
	EMIT(SIG_ID_Exception_main_trap_472);
	EMIT(SIG_ID_Signal_switch_on_467);
	_StrlSampleRange(&ID_Variable_org_input_463,ID_Signal_Mark_Wire_M_M1_79);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_465,ID_Variable_org_input_463);
	EMIT(SIG_ID_Signal_My_Sample_Range_465);
	CLEAR_SIGNAL(SIG_ID_Exception_compute_loop_471);
	current_point_bit_vector[3] &= ~0x400; /* Off:  #106*/
	next_point_bit_vector[0] &= ~0x3e000; next_point_bit_vector[1] &= ~0x1f80; next_point_bit_vector[2] &= ~0x27f00; /* PauseOff:  #13 #14 #15 #16 #17 #39 #40 #41 #42 #43 #44 #72 #73 #74 #75 #76 #77 #78 #81*/
	if (ID_Variable_CONT_FLAG_462) {
		CLEAR_SIGNAL(SIG_ID_Exception_main_trap_473);
		next_point_bit_vector[2] |= 0x40000000; /* PauseOn:  #94*/
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0)) {
			next_point_bit_vector[1] |= 0x2000; /* PauseOn:  #45*/
		} else {
			current_point_bit_vector[3] |= 0x1000; /* On:  #108*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) {
			next_point_bit_vector[2] |= 0x4000000; /* PauseOn:  #90*/
		} else {
			current_point_bit_vector[3] |= 0x1000; /* On:  #108*/
		}
		if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0))) {
			current_point_bit_vector[3] |= 0x2000; /* On:  #109*/
		} else {
			current_point_bit_vector[3] |= 0x1000; /* On:  #108*/
		}
	} else {
		current_point_bit_vector[3] |= 0x4000; /* On:  #110*/
	}
}

static void Point_108() {
	if (next_point_bit_vector[1]&0x2000) return;
	 if (next_point_bit_vector[2]&0x4000000) return;
	 /* isPauseOn:  #45 #90*/
}

static void Point_109() {
	EMIT(SIG_ID_Exception_main_trap_473);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_465,ID_Variable_my_input_464);
	EMIT(SIG_ID_Signal_My_Sample_Range_465);
	current_point_bit_vector[3] |= 0x4000; /* On:  #110*/
	current_point_bit_vector[3] &= ~0x1000; /* Off:  #108*/
	next_point_bit_vector[1] &= ~0x2000; next_point_bit_vector[2] &= ~0x44000000; /* PauseOff:  #45 #90 #94*/
}

static void Point_110() {
	_StrlSampleRange(&ID_Variable_input_range_474,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_output_range_475,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_inside_input_476,INITIAL_RANGE);
	_StrlSampleIndex(&ID_Variable_pendingWP_477,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_desiredWP_478,INITIAL_INDEX);
	_integer(&ID_Variable_requestSize_479,0);
	_integer(&ID_Variable_maxOutSize_480,0);
	_integer(&ID_Variable_temp_int_481,0);
	_UnsignedInt(&ID_Variable_temp_unsigned_482,INITIAL_UNSIGNEDINT);
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_465,0)) {
		_StrlSampleRange(&ID_Variable_input_range_474,ID_Signal_My_Sample_Range_465);
		_StrlSampleRange(&ID_Variable_output_range_475,DOWNCASTS(ID_Variable_input_range_474, ID_InputOutput_Mod_module_43));
		_StrlSampleIndex(&ID_Variable_pendingWP_477,GETMARKEDWP(ID_InputOutput_Mod_module_43));
		_StrlSampleIndex(&ID_Variable_desiredWP_478,ADD_INDEX_SIZE(ID_Variable_output_range_475));
		_integer(&ID_Variable_requestSize_479,SUBTRACT_A_B(ID_Variable_desiredWP_478, ID_Variable_pendingWP_477));
		_integer(&ID_Variable_maxOutSize_480,GETMAXOUTSIZE(ID_InputOutput_Mod_module_43));
		if ((ID_Variable_requestSize_479 > ID_Variable_maxOutSize_480)) {
			_integer(&ID_Variable_requestSize_479,ID_Variable_maxOutSize_480);
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_482,GET_OUTPUTSIZE(ID_InputOutput_Mod_module_43));
		_integer(&ID_Variable_requestSize_479,ROUNDOWN_SIZE(ID_Variable_requestSize_479, ID_Variable_temp_unsigned_482));
		_StrlSampleRange(&ID_Variable_output_range_475,SET_SAMPLERANGE(ID_Variable_pendingWP_477, ID_Variable_requestSize_479));
		_StrlSampleRange(&ID_Variable_inside_input_476,FORECASTS(ID_Variable_output_range_475, ID_InputOutput_Mod_module_43));
		_integer(&ID_Variable_temp_int_481,REAL_FIT_RANGE(ID_Variable_pendingWP_477, ID_Variable_requestSize_479, ID_Variable_inside_input_476, ID_InputOutput_Mod_module_43));
		LOCALINCAWAITTICK(ID_InputOutput_Mod_module_43);
		next_point_bit_vector[0] |= 0x40000; /* PauseOn:  #18*/
	} else {
		next_point_bit_vector[2] |= 0x20000000; /* PauseOn:  #93*/
	}
}

static void Point_111() {
	_StrlSampleRange(&ID_Variable_my_input_464,UPDATESAMPLE(ID_Variable_my_input_464));
	_boolean(&ID_Variable_CONT_FLAG_462,1);
	if (ID_Variable_CONT_FLAG_462) {
		CLEAR_SIGNAL(SIG_ID_Exception_main_trap_473);
		next_point_bit_vector[2] |= 0x40000000; /* PauseOn:  #94*/
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0)) {
			next_point_bit_vector[1] |= 0x2000; /* PauseOn:  #45*/
		} else {
			current_point_bit_vector[3] |= 0x10000; /* On:  #112*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0)) {
			next_point_bit_vector[2] |= 0x4000000; /* PauseOn:  #90*/
		} else {
			current_point_bit_vector[3] |= 0x10000; /* On:  #112*/
		}
		if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_90,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_89,0))) {
			current_point_bit_vector[3] |= 0x20000; /* On:  #113*/
		} else {
			current_point_bit_vector[3] |= 0x10000; /* On:  #112*/
		}
	} else {
		current_point_bit_vector[3] |= 0x40000; /* On:  #114*/
	}
}

static void Point_112() {
	if (next_point_bit_vector[1]&0x2000) return;
	 if (next_point_bit_vector[2]&0x4000000) return;
	 /* isPauseOn:  #45 #90*/
}

static void Point_113() {
	EMIT(SIG_ID_Exception_main_trap_473);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_465,ID_Variable_my_input_464);
	EMIT(SIG_ID_Signal_My_Sample_Range_465);
	current_point_bit_vector[3] |= 0x40000; /* On:  #114*/
	current_point_bit_vector[3] &= ~0x10000; /* Off:  #112*/
	next_point_bit_vector[1] &= ~0x2000; next_point_bit_vector[2] &= ~0x44000000; /* PauseOff:  #45 #90 #94*/
}

static void Point_114() {
	_StrlSampleRange(&ID_Variable_input_range_474,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_output_range_475,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_inside_input_476,INITIAL_RANGE);
	_StrlSampleIndex(&ID_Variable_pendingWP_477,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_desiredWP_478,INITIAL_INDEX);
	_integer(&ID_Variable_requestSize_479,0);
	_integer(&ID_Variable_maxOutSize_480,0);
	_integer(&ID_Variable_temp_int_481,0);
	_UnsignedInt(&ID_Variable_temp_unsigned_482,INITIAL_UNSIGNEDINT);
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_465,0)) {
		_StrlSampleRange(&ID_Variable_input_range_474,ID_Signal_My_Sample_Range_465);
		_StrlSampleRange(&ID_Variable_output_range_475,DOWNCASTS(ID_Variable_input_range_474, ID_InputOutput_Mod_module_43));
		_StrlSampleIndex(&ID_Variable_pendingWP_477,GETMARKEDWP(ID_InputOutput_Mod_module_43));
		_StrlSampleIndex(&ID_Variable_desiredWP_478,ADD_INDEX_SIZE(ID_Variable_output_range_475));
		_integer(&ID_Variable_requestSize_479,SUBTRACT_A_B(ID_Variable_desiredWP_478, ID_Variable_pendingWP_477));
		_integer(&ID_Variable_maxOutSize_480,GETMAXOUTSIZE(ID_InputOutput_Mod_module_43));
		if ((ID_Variable_requestSize_479 > ID_Variable_maxOutSize_480)) {
			_integer(&ID_Variable_requestSize_479,ID_Variable_maxOutSize_480);
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_482,GET_OUTPUTSIZE(ID_InputOutput_Mod_module_43));
		_integer(&ID_Variable_requestSize_479,ROUNDOWN_SIZE(ID_Variable_requestSize_479, ID_Variable_temp_unsigned_482));
		_StrlSampleRange(&ID_Variable_output_range_475,SET_SAMPLERANGE(ID_Variable_pendingWP_477, ID_Variable_requestSize_479));
		_StrlSampleRange(&ID_Variable_inside_input_476,FORECASTS(ID_Variable_output_range_475, ID_InputOutput_Mod_module_43));
		_integer(&ID_Variable_temp_int_481,REAL_FIT_RANGE(ID_Variable_pendingWP_477, ID_Variable_requestSize_479, ID_Variable_inside_input_476, ID_InputOutput_Mod_module_43));
		LOCALINCAWAITTICK(ID_InputOutput_Mod_module_43);
		next_point_bit_vector[0] |= 0x40000; /* PauseOn:  #18*/
	} else {
		next_point_bit_vector[2] |= 0x20000000; /* PauseOn:  #93*/
	}
}

static void Point_115() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_467,0)) {
		current_point_bit_vector[3] |= 0x100000; /* On:  #116*/
		next_point_bit_vector[0] |= 0x100000; /* PauseOn:  #20*/
	} else {
		next_point_bit_vector[3] |= 0x80000; /* PauseOn:  #115*/
	}
}

static void Point_116() {
	EMIT(SIG_ID_Signal_Clock_Wire_M_M1_93);
	next_point_bit_vector[3] |= 0x100000; /* PauseOn:  #116*/
}

static void Point_117() {
	if (IS_SIGNAL(SIG_ID_Signal_Compute_Wire_M_S1_85,0)) {
		current_point_bit_vector[3] |= 0x400000; /* On:  #118*/
	} else {
		next_point_bit_vector[3] |= 0x200000; /* PauseOn:  #117*/
	}
}

static void Point_118() {
	_StrlSampleRange(&ID_Variable_my_input_496,INSIDE_COMP_FIT(ID_Variable_org_input_495, ID_Variable_my_input_496, ID_InputOutput_Scopesink_module_45));
	LOCALINCAWAITTICK(ID_InputOutput_Scopesink_module_45);
	next_point_bit_vector[0] |= 0x1000000; /* PauseOn:  #24*/
}

static void Point_119() {
	if (IS_SIGNAL(SIG_ID_Signal_Compute_Wire_M_S1_85,0)) {
		_integer(&ID_Variable_temp_int_532,0);
		_integer(&ID_Variable_not_source_533,0);
		_integer(&ID_Variable_not_complete_flag_534,0);
		_StrlSampleIndex(&ID_Variable_temp_index_535,INITIAL_INDEX);
		_StrlSampleRange(&ID_Variable_temp_range_536,INITIAL_RANGE);
		_StrlSampleSize(&ID_Variable_complete_var_537,INITIAL_SIZE);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_538);
		CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_539);
		if (_eq_integer(CHECK_MYWRITERLL(ID_InputOutput_Summer_module_44),0)) {
			current_point_bit_vector[3] |= 0x4000000; /* On:  #122*/
		} else {
			if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_InputOutput_Summer_module_44),0)) {
				current_point_bit_vector[3] |= 0x2000000; /* On:  #121*/
			} else {
				if ((GET_NUMBERINPUTS(ID_InputOutput_Summer_module_44) > 0)) {
					_integer(&ID_Variable_not_source_533,1);
				}
				_StrlSampleSize(&ID_Variable_complete_var_537,REALCOMPUTEDATA(ID_InputOutput_Summer_module_44, ID_Variable_not_source_533));
				if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_InputOutput_Summer_module_44), ID_Variable_complete_var_537) > 0)) {
					_integer(&ID_Variable_not_complete_flag_534,(ID_Variable_not_complete_flag_534 - 1));
					current_point_bit_vector[3] |= 0x1000000; /* On:  #120*/
				} else {
					current_point_bit_vector[3] |= 0x1000000; /* On:  #120*/
				}
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x800000; /* PauseOn:  #119*/
	}
}

static void Point_120() {
	if ((ID_Variable_not_complete_flag_534 < 0)) {
		_StrlSampleIndex(&ID_Variable_temp_index_535,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_InputOutput_Summer_module_44), ID_Variable_complete_var_537));
		SET_MARKEDWP(ID_InputOutput_Summer_module_44, ID_Variable_temp_index_535);
	}
	WRITEDATA(ID_InputOutput_Summer_module_44, ID_Variable_not_source_533);
	_StrlSampleIndex(&ID_Variable_temp_index_535,GETWP(ID_InputOutput_Summer_module_44));
	_StrlSampleRange(&ID_Output_SUMMER_COMPUTEDSR_50,GET_MYMARKEDDATA(ID_InputOutput_Summer_module_44));
	UDP_FLOW_O_SUMMER_COMPUTEDSR(ID_Output_SUMMER_COMPUTEDSR_50); EMIT(SIG_ID_Output_SUMMER_COMPUTEDSR_50);
	current_point_bit_vector[3] |= 0x8000000; /* On:  #123*/
}

static void Point_121() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_538);
	current_point_bit_vector[3] |= 0x8000000; /* On:  #123*/
	current_point_bit_vector[3] &= ~0x1000000; /* Off:  #120*/
}

static void Point_122() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_538);
	current_point_bit_vector[3] |= 0x8000000; /* On:  #123*/
	current_point_bit_vector[3] &= ~0x1000000; /* Off:  #120*/
}

static void Point_123() {
	LOCALINCAWAITTICK(ID_InputOutput_Summer_module_44);
	next_point_bit_vector[0] |= 0x40000000; /* PauseOn:  #30*/
}

static void Point_124() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_467,0)) {
		EMIT(SIG_ID_Signal_Clock_Wire_M_M1_93);
		next_point_bit_vector[0] |= 0x100000; next_point_bit_vector[3] |= 0x100000; /* PauseOn:  #20 #116*/
	} else {
		next_point_bit_vector[3] |= 0x80000; /* PauseOn:  #115*/
	}
}

static void Point_125() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_88,0)) {
		EMIT(SIG_ID_Exception_main_trap_441);
		current_point_bit_vector[3] |= 0x40000000; /* On:  #126*/
		current_point_bit_vector[4] &= ~0x1; /* Off:  #128*/
	} else {
		next_point_bit_vector[3] |= 0x20000000; /* PauseOn:  #125*/
	}
}

static void Point_126() {
	EMIT(SIG_ID_Signal_switch_on_436);
	_StrlSampleRange(&ID_Variable_org_input_432,ID_Signal_Mark_Wire_S_M_78);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_434,ID_Variable_org_input_432);
	EMIT(SIG_ID_Signal_My_Sample_Range_434);
	current_point_bit_vector[3] |= 0x80000000; /* On:  #127*/
	next_point_bit_vector[0] &= ~0x100; next_point_bit_vector[3] &= ~0x20000000; next_point_bit_vector[4] &= ~0x1; /* PauseOff:  #8 #125 #128*/
}

static void Point_127() {
	CLEAR_SIGNAL(SIG_ID_Exception_compute_loop_440);
	if (ID_Variable_CONT_FLAG_430) {
		next_point_bit_vector[4] |= 0x8; /* PauseOn:  #131*/
	} else {
		current_point_bit_vector[4] |= 0x10; /* On:  #132*/
	}
}

static void Point_128() {
	if (next_point_bit_vector[0]&0x100) return;
	 if (next_point_bit_vector[3]&0x20000000) return;
	 if (next_point_bit_vector[4]&0x1) return;
	 /* isPauseOn:  #8 #125 #128*/
	next_point_bit_vector[4] |= 0x1; /* PauseOn:  #128*/
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_88,0)) {
		next_point_bit_vector[0] |= 0x100; /* PauseOn:  #8*/
	} else {
		current_point_bit_vector[4] |= 0x2; /* On:  #129*/
	}
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_78,0)) {
		next_point_bit_vector[3] |= 0x20000000; /* PauseOn:  #125*/
	} else {
		current_point_bit_vector[4] |= 0x2; /* On:  #129*/
	}
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_78,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_88,0))) {
		current_point_bit_vector[4] |= 0x4; /* On:  #130*/
	} else {
		current_point_bit_vector[4] |= 0x2; /* On:  #129*/
	}
}

static void Point_129() {
	if (next_point_bit_vector[0]&0x100) return;
	 if (next_point_bit_vector[3]&0x20000000) return;
	 /* isPauseOn:  #8 #125*/
}

static void Point_130() {
	EMIT(SIG_ID_Exception_main_trap_441);
	current_point_bit_vector[4] &= ~0x2; /* Off:  #129*/
}

static void Point_131() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_88,0)) {
		_StrlSampleRange(&ID_Signal_My_Sample_Range_434,ID_Variable_my_input_433);
		EMIT(SIG_ID_Signal_My_Sample_Range_434);
		current_point_bit_vector[4] |= 0x10; /* On:  #132*/
	} else {
		next_point_bit_vector[4] |= 0x8; /* PauseOn:  #131*/
	}
}

static void Point_132() {
	_StrlSampleRange(&ID_Variable_input_range_444,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_output_range_445,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_inside_input_446,INITIAL_RANGE);
	_StrlSampleIndex(&ID_Variable_pendingWP_447,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_desiredWP_448,INITIAL_INDEX);
	_integer(&ID_Variable_requestSize_449,0);
	_integer(&ID_Variable_maxOutSize_450,0);
	_integer(&ID_Variable_temp_int_451,0);
	_UnsignedInt(&ID_Variable_temp_unsigned_452,INITIAL_UNSIGNEDINT);
	current_point_bit_vector[4] |= 0x20; /* On:  #133*/
}

static void Point_133() {
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_434,0)) {
		_StrlSampleRange(&ID_Variable_input_range_444,ID_Signal_My_Sample_Range_434);
		_StrlSampleRange(&ID_Variable_output_range_445,DOWNCASTS(ID_Variable_input_range_444, ID_InputOutput_Coder_module_42));
		_StrlSampleIndex(&ID_Variable_pendingWP_447,GETMARKEDWP(ID_InputOutput_Coder_module_42));
		_StrlSampleIndex(&ID_Variable_desiredWP_448,ADD_INDEX_SIZE(ID_Variable_output_range_445));
		_integer(&ID_Variable_requestSize_449,SUBTRACT_A_B(ID_Variable_desiredWP_448, ID_Variable_pendingWP_447));
		_integer(&ID_Variable_maxOutSize_450,GETMAXOUTSIZE(ID_InputOutput_Coder_module_42));
		if ((ID_Variable_requestSize_449 > ID_Variable_maxOutSize_450)) {
			_integer(&ID_Variable_requestSize_449,ID_Variable_maxOutSize_450);
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_452,GET_OUTPUTSIZE(ID_InputOutput_Coder_module_42));
		_integer(&ID_Variable_requestSize_449,ROUNDOWN_SIZE(ID_Variable_requestSize_449, ID_Variable_temp_unsigned_452));
		_StrlSampleRange(&ID_Variable_output_range_445,SET_SAMPLERANGE(ID_Variable_pendingWP_447, ID_Variable_requestSize_449));
		_StrlSampleRange(&ID_Variable_inside_input_446,FORECASTS(ID_Variable_output_range_445, ID_InputOutput_Coder_module_42));
		_integer(&ID_Variable_temp_int_451,REAL_FIT_RANGE(ID_Variable_pendingWP_447, ID_Variable_requestSize_449, ID_Variable_inside_input_446, ID_InputOutput_Coder_module_42));
		LOCALINCAWAITTICK(ID_InputOutput_Coder_module_42);
		next_point_bit_vector[0] |= 0x200; /* PauseOn:  #9*/
	} else {
		next_point_bit_vector[4] |= 0x20; /* PauseOn:  #133*/
	}
}

static void Point_134() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_M_M1_93,0)) {
		next_point_bit_vector[4] |= 0x40; /* PauseOn:  #134*/
	} else {
		next_point_bit_vector[4] |= 0x180; /* PauseOn:  #135 #136*/
	}
}

static void Point_135() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_M_M1_93,0)) {
		next_point_bit_vector[4] |= current_point_bit_vector[4] & 0x100; current_point_bit_vector[4] &= ~0x100; /* Suspend:  #136*/
		next_point_bit_vector[4] |= 0x80; /* PauseOn:  #135*/
	} else {
		next_point_bit_vector[4] |= 0x80; /* PauseOn:  #135*/
	}
}

static void Point_136() {
	EMIT(SIG_ID_Exception_main_loop_461);
	EMIT(SIG_ID_Signal_Compute_Wire_M_M1_84);
	next_point_bit_vector[4] &= ~0x180; /* PauseOff:  #135 #136*/
	if ((CHECKSAMPLESIZE(ID_Variable_org_input_432, ID_Variable_my_input_433) >= 0)) {
		current_point_bit_vector[4] |= 0x800; /* On:  #139*/
	} else {
		_boolean(&ID_Variable_CONT_FLAG_430,0);
		EMIT(SIG_ID_Exception_compute_loop_440);
		_StrlSampleRange(&ID_Signal_Ack_Wire_S_M_87,ID_Variable_my_input_433);
		EMIT(SIG_ID_Signal_Ack_Wire_S_M_87);
		next_point_bit_vector[0] &= ~0x600; next_point_bit_vector[4] &= ~0x20001a8; /* PauseOff:  #9 #10 #131 #133 #135 #136 #153*/
		if (IS_SIGNAL(SIG_ID_Signal_INI_PHASE_439,0)) {
			next_point_bit_vector[0] |= 0x80; /* PauseOn:  #7*/
		} else {
			CLEAR_SIGNAL(SIG_ID_Exception_main_trap_441);
			next_point_bit_vector[4] |= 0x1; /* PauseOn:  #128*/
			if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_88,0)) {
				next_point_bit_vector[0] |= 0x100; /* PauseOn:  #8*/
			} else {
				current_point_bit_vector[4] |= 0x200; /* On:  #137*/
			}
			if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_78,0)) {
				next_point_bit_vector[3] |= 0x20000000; /* PauseOn:  #125*/
			} else {
				current_point_bit_vector[4] |= 0x200; /* On:  #137*/
			}
			if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_78,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_88,0))) {
				current_point_bit_vector[4] |= 0x400; /* On:  #138*/
			} else {
				current_point_bit_vector[4] |= 0x200; /* On:  #137*/
			}
		}
	}
}

static void Point_137() {
	if (next_point_bit_vector[0]&0x100) return;
	 if (next_point_bit_vector[3]&0x20000000) return;
	 /* isPauseOn:  #8 #125*/
}

static void Point_138() {
	EMIT(SIG_ID_Exception_main_trap_441);
	EMIT(SIG_ID_Signal_switch_on_436);
	_StrlSampleRange(&ID_Variable_org_input_432,ID_Signal_Mark_Wire_S_M_78);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_434,ID_Variable_org_input_432);
	EMIT(SIG_ID_Signal_My_Sample_Range_434);
	CLEAR_SIGNAL(SIG_ID_Exception_compute_loop_440);
	current_point_bit_vector[4] &= ~0x200; /* Off:  #137*/
	next_point_bit_vector[0] &= ~0x100; next_point_bit_vector[3] &= ~0x20000000; next_point_bit_vector[4] &= ~0x1; /* PauseOff:  #8 #125 #128*/
	if (ID_Variable_CONT_FLAG_430) {
		next_point_bit_vector[4] |= 0x8; /* PauseOn:  #131*/
	} else {
		_StrlSampleRange(&ID_Variable_input_range_444,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_445,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_inside_input_446,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_447,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_448,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_449,0);
		_integer(&ID_Variable_maxOutSize_450,0);
		_integer(&ID_Variable_temp_int_451,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_452,INITIAL_UNSIGNEDINT);
		if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_434,0)) {
			_StrlSampleRange(&ID_Variable_input_range_444,ID_Signal_My_Sample_Range_434);
			_StrlSampleRange(&ID_Variable_output_range_445,DOWNCASTS(ID_Variable_input_range_444, ID_InputOutput_Coder_module_42));
			_StrlSampleIndex(&ID_Variable_pendingWP_447,GETMARKEDWP(ID_InputOutput_Coder_module_42));
			_StrlSampleIndex(&ID_Variable_desiredWP_448,ADD_INDEX_SIZE(ID_Variable_output_range_445));
			_integer(&ID_Variable_requestSize_449,SUBTRACT_A_B(ID_Variable_desiredWP_448, ID_Variable_pendingWP_447));
			_integer(&ID_Variable_maxOutSize_450,GETMAXOUTSIZE(ID_InputOutput_Coder_module_42));
			if ((ID_Variable_requestSize_449 > ID_Variable_maxOutSize_450)) {
				_integer(&ID_Variable_requestSize_449,ID_Variable_maxOutSize_450);
			}
			_UnsignedInt(&ID_Variable_temp_unsigned_452,GET_OUTPUTSIZE(ID_InputOutput_Coder_module_42));
			_integer(&ID_Variable_requestSize_449,ROUNDOWN_SIZE(ID_Variable_requestSize_449, ID_Variable_temp_unsigned_452));
			_StrlSampleRange(&ID_Variable_output_range_445,SET_SAMPLERANGE(ID_Variable_pendingWP_447, ID_Variable_requestSize_449));
			_StrlSampleRange(&ID_Variable_inside_input_446,FORECASTS(ID_Variable_output_range_445, ID_InputOutput_Coder_module_42));
			_integer(&ID_Variable_temp_int_451,REAL_FIT_RANGE(ID_Variable_pendingWP_447, ID_Variable_requestSize_449, ID_Variable_inside_input_446, ID_InputOutput_Coder_module_42));
			LOCALINCAWAITTICK(ID_InputOutput_Coder_module_42);
			next_point_bit_vector[0] |= 0x200; /* PauseOn:  #9*/
		} else {
			next_point_bit_vector[4] |= 0x20; /* PauseOn:  #133*/
		}
	}
}

static void Point_139() {
	_StrlSampleRange(&ID_Variable_my_input_433,UPDATESAMPLE(ID_Variable_my_input_433));
	_boolean(&ID_Variable_CONT_FLAG_430,1);
	if (ID_Variable_CONT_FLAG_430) {
		next_point_bit_vector[4] |= 0x8; /* PauseOn:  #131*/
	} else {
		_StrlSampleRange(&ID_Variable_input_range_444,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_445,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_inside_input_446,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_447,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_448,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_449,0);
		_integer(&ID_Variable_maxOutSize_450,0);
		_integer(&ID_Variable_temp_int_451,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_452,INITIAL_UNSIGNEDINT);
		if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_434,0)) {
			_StrlSampleRange(&ID_Variable_input_range_444,ID_Signal_My_Sample_Range_434);
			_StrlSampleRange(&ID_Variable_output_range_445,DOWNCASTS(ID_Variable_input_range_444, ID_InputOutput_Coder_module_42));
			_StrlSampleIndex(&ID_Variable_pendingWP_447,GETMARKEDWP(ID_InputOutput_Coder_module_42));
			_StrlSampleIndex(&ID_Variable_desiredWP_448,ADD_INDEX_SIZE(ID_Variable_output_range_445));
			_integer(&ID_Variable_requestSize_449,SUBTRACT_A_B(ID_Variable_desiredWP_448, ID_Variable_pendingWP_447));
			_integer(&ID_Variable_maxOutSize_450,GETMAXOUTSIZE(ID_InputOutput_Coder_module_42));
			if ((ID_Variable_requestSize_449 > ID_Variable_maxOutSize_450)) {
				_integer(&ID_Variable_requestSize_449,ID_Variable_maxOutSize_450);
			}
			_UnsignedInt(&ID_Variable_temp_unsigned_452,GET_OUTPUTSIZE(ID_InputOutput_Coder_module_42));
			_integer(&ID_Variable_requestSize_449,ROUNDOWN_SIZE(ID_Variable_requestSize_449, ID_Variable_temp_unsigned_452));
			_StrlSampleRange(&ID_Variable_output_range_445,SET_SAMPLERANGE(ID_Variable_pendingWP_447, ID_Variable_requestSize_449));
			_StrlSampleRange(&ID_Variable_inside_input_446,FORECASTS(ID_Variable_output_range_445, ID_InputOutput_Coder_module_42));
			_integer(&ID_Variable_temp_int_451,REAL_FIT_RANGE(ID_Variable_pendingWP_447, ID_Variable_requestSize_449, ID_Variable_inside_input_446, ID_InputOutput_Coder_module_42));
			LOCALINCAWAITTICK(ID_InputOutput_Coder_module_42);
			next_point_bit_vector[0] |= 0x200; /* PauseOn:  #9*/
		} else {
			next_point_bit_vector[4] |= 0x20; /* PauseOn:  #133*/
		}
	}
}

static void Point_140() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_436,0)) {
		current_point_bit_vector[4] |= 0x2000; /* On:  #141*/
		next_point_bit_vector[0] |= 0x800; /* PauseOn:  #11*/
	} else {
		next_point_bit_vector[4] |= 0x1000; /* PauseOn:  #140*/
	}
}

static void Point_141() {
	EMIT(SIG_ID_Signal_Clock_Wire_S_M_92);
	next_point_bit_vector[4] |= 0x2000; /* PauseOn:  #141*/
}

static void Point_142() {
	if (IS_SIGNAL(SIG_ID_Signal_Compute_Wire_M_M1_84,0)) {
		_integer(&ID_Variable_temp_int_483,0);
		_integer(&ID_Variable_not_source_484,0);
		_integer(&ID_Variable_not_complete_flag_485,0);
		_StrlSampleIndex(&ID_Variable_temp_index_486,INITIAL_INDEX);
		_StrlSampleRange(&ID_Variable_temp_range_487,INITIAL_RANGE);
		_StrlSampleSize(&ID_Variable_complete_var_488,INITIAL_SIZE);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_489);
		CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_490);
		if (_eq_integer(CHECK_MYWRITERLL(ID_InputOutput_Mod_module_43),0)) {
			current_point_bit_vector[4] |= 0x20000; /* On:  #145*/
		} else {
			if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_InputOutput_Mod_module_43),0)) {
				current_point_bit_vector[4] |= 0x10000; /* On:  #144*/
			} else {
				if ((GET_NUMBERINPUTS(ID_InputOutput_Mod_module_43) > 0)) {
					_integer(&ID_Variable_not_source_484,1);
				}
				_StrlSampleSize(&ID_Variable_complete_var_488,REALCOMPUTEDATA(ID_InputOutput_Mod_module_43, ID_Variable_not_source_484));
				if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_InputOutput_Mod_module_43), ID_Variable_complete_var_488) > 0)) {
					_integer(&ID_Variable_not_complete_flag_485,(ID_Variable_not_complete_flag_485 - 1));
					current_point_bit_vector[4] |= 0x8000; /* On:  #143*/
				} else {
					current_point_bit_vector[4] |= 0x8000; /* On:  #143*/
				}
			}
		}
	} else {
		next_point_bit_vector[4] |= 0x4000; /* PauseOn:  #142*/
	}
}

static void Point_143() {
	if ((ID_Variable_not_complete_flag_485 < 0)) {
		_StrlSampleIndex(&ID_Variable_temp_index_486,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_InputOutput_Mod_module_43), ID_Variable_complete_var_488));
		SET_MARKEDWP(ID_InputOutput_Mod_module_43, ID_Variable_temp_index_486);
	}
	WRITEDATA(ID_InputOutput_Mod_module_43, ID_Variable_not_source_484);
	_StrlSampleIndex(&ID_Variable_temp_index_486,GETWP(ID_InputOutput_Mod_module_43));
	_StrlSampleRange(&ID_Output_MOD_COMPUTEDSR_49,GET_MYMARKEDDATA(ID_InputOutput_Mod_module_43));
	UDP_FLOW_O_MOD_COMPUTEDSR(ID_Output_MOD_COMPUTEDSR_49); EMIT(SIG_ID_Output_MOD_COMPUTEDSR_49);
	current_point_bit_vector[4] |= 0x40000; /* On:  #146*/
}

static void Point_144() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_489);
	current_point_bit_vector[4] |= 0x40000; /* On:  #146*/
	current_point_bit_vector[4] &= ~0x8000; /* Off:  #143*/
}

static void Point_145() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_489);
	current_point_bit_vector[4] |= 0x40000; /* On:  #146*/
	current_point_bit_vector[4] &= ~0x8000; /* Off:  #143*/
}

static void Point_146() {
	LOCALINCAWAITTICK(ID_InputOutput_Mod_module_43);
	next_point_bit_vector[0] |= 0x80000; /* PauseOn:  #19*/
}

static void Point_147() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_436,0)) {
		EMIT(SIG_ID_Signal_Clock_Wire_S_M_92);
		next_point_bit_vector[0] |= 0x800; next_point_bit_vector[4] |= 0x2000; /* PauseOn:  #11 #141*/
	} else {
		next_point_bit_vector[4] |= 0x1000; /* PauseOn:  #140*/
	}
}

static void Point_148() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_S_M_87,0)) {
		_StrlSampleRange(&ID_Variable_my_output_376,ID_Signal_Ack_Wire_S_M_87);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_377,ID_Variable_my_output_376);
		EMIT(SIG_ID_Signal_My_Sample_Range_377);
		_StrlSampleRange(&ID_Variable_input_range_395,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_396,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_397,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_remainedWP_398,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_399,0);
		_integer(&ID_Variable_maxOutSize_400,0);
		_integer(&ID_Variable_temp_int_401,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_402,INITIAL_UNSIGNEDINT);
		current_point_bit_vector[4] |= 0x200000; /* On:  #149*/
	} else {
		next_point_bit_vector[4] |= 0x100000; /* PauseOn:  #148*/
	}
}

static void Point_149() {
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_377,0)) {
		_StrlSampleRange(&ID_Variable_input_range_395,ID_Signal_My_Sample_Range_377);
		_StrlSampleIndex(&ID_Variable_pendingWP_397,GETMARKEDWP(ID_InputOutput_Source_module_41));
		_StrlSampleIndex(&ID_Variable_remainedWP_398,ADD_INDEX_SIZE(ID_Variable_input_range_395));
		_integer(&ID_Variable_requestSize_399,SUBTRACT_A_B(ID_Variable_pendingWP_397, ID_Variable_remainedWP_398));
		if ((ID_Variable_requestSize_399 < 0)) {
			_integer(&ID_Variable_temp_int_401,error_exit(0));
		}
		_integer(&ID_Variable_maxOutSize_400,200);
		_integer(&ID_Variable_requestSize_399,(ID_Variable_maxOutSize_400 + ID_Variable_requestSize_399));
		if ((ID_Variable_requestSize_399 > ID_Variable_maxOutSize_400)) {
			_integer(&ID_Variable_requestSize_399,ID_Variable_maxOutSize_400);
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_402,GET_OUTPUTSIZE(ID_InputOutput_Source_module_41));
		_integer(&ID_Variable_requestSize_399,ROUNDOWN_SIZE(ID_Variable_requestSize_399, ID_Variable_temp_unsigned_402));
		_StrlSampleRange(&ID_Variable_output_range_396,SET_SAMPLERANGE(ID_Variable_pendingWP_397, ID_Variable_requestSize_399));
		_integer(&ID_Variable_temp_int_401,REAL_FIT_RANGE(ID_Variable_pendingWP_397, ID_Variable_requestSize_399, INITIAL_RANGE, ID_InputOutput_Source_module_41));
		LOCALINCAWAITTICK(ID_InputOutput_Source_module_41);
		next_point_bit_vector[0] |= 0x4; /* PauseOn:  #2*/
	} else {
		next_point_bit_vector[4] |= 0x200000; /* PauseOn:  #149*/
	}
}

static void Point_150() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_S_M_92,0)) {
		next_point_bit_vector[4] |= 0x400000; /* PauseOn:  #150*/
	} else {
		next_point_bit_vector[4] |= 0x1800000; /* PauseOn:  #151 #152*/
	}
}

static void Point_151() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_S_M_92,0)) {
		next_point_bit_vector[4] |= current_point_bit_vector[4] & 0x1000000; current_point_bit_vector[4] &= ~0x1000000; /* Suspend:  #152*/
		next_point_bit_vector[4] |= 0x800000; /* PauseOn:  #151*/
	} else {
		next_point_bit_vector[4] |= 0x800000; /* PauseOn:  #151*/
	}
}

static void Point_152() {
	EMIT(SIG_ID_Exception_main_loop_427);
	EMIT(SIG_ID_Signal_Compute_Wire_S_M_83);
	next_point_bit_vector[4] &= ~0x1800000; /* PauseOff:  #151 #152*/
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_S_M_87,0)) {
		_StrlSampleRange(&ID_Variable_my_output_376,ID_Signal_Ack_Wire_S_M_87);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_377,ID_Variable_my_output_376);
		EMIT(SIG_ID_Signal_My_Sample_Range_377);
		_StrlSampleRange(&ID_Variable_input_range_395,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_396,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_397,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_remainedWP_398,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_399,0);
		_integer(&ID_Variable_maxOutSize_400,0);
		_integer(&ID_Variable_temp_int_401,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_402,INITIAL_UNSIGNEDINT);
		if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_377,0)) {
			_StrlSampleRange(&ID_Variable_input_range_395,ID_Signal_My_Sample_Range_377);
			_StrlSampleIndex(&ID_Variable_pendingWP_397,GETMARKEDWP(ID_InputOutput_Source_module_41));
			_StrlSampleIndex(&ID_Variable_remainedWP_398,ADD_INDEX_SIZE(ID_Variable_input_range_395));
			_integer(&ID_Variable_requestSize_399,SUBTRACT_A_B(ID_Variable_pendingWP_397, ID_Variable_remainedWP_398));
			if ((ID_Variable_requestSize_399 < 0)) {
				_integer(&ID_Variable_temp_int_401,error_exit(0));
			}
			_integer(&ID_Variable_maxOutSize_400,200);
			_integer(&ID_Variable_requestSize_399,(ID_Variable_maxOutSize_400 + ID_Variable_requestSize_399));
			if ((ID_Variable_requestSize_399 > ID_Variable_maxOutSize_400)) {
				_integer(&ID_Variable_requestSize_399,ID_Variable_maxOutSize_400);
			}
			_UnsignedInt(&ID_Variable_temp_unsigned_402,GET_OUTPUTSIZE(ID_InputOutput_Source_module_41));
			_integer(&ID_Variable_requestSize_399,ROUNDOWN_SIZE(ID_Variable_requestSize_399, ID_Variable_temp_unsigned_402));
			_StrlSampleRange(&ID_Variable_output_range_396,SET_SAMPLERANGE(ID_Variable_pendingWP_397, ID_Variable_requestSize_399));
			_integer(&ID_Variable_temp_int_401,REAL_FIT_RANGE(ID_Variable_pendingWP_397, ID_Variable_requestSize_399, INITIAL_RANGE, ID_InputOutput_Source_module_41));
			LOCALINCAWAITTICK(ID_InputOutput_Source_module_41);
			next_point_bit_vector[0] |= 0x4; /* PauseOn:  #2*/
		} else {
			next_point_bit_vector[4] |= 0x200000; /* PauseOn:  #149*/
		}
	} else {
		next_point_bit_vector[4] |= 0x100000; /* PauseOn:  #148*/
	}
}

static void Point_153() {
	if (IS_SIGNAL(SIG_ID_Signal_Compute_Wire_S_M_83,0)) {
		_integer(&ID_Variable_temp_int_453,0);
		_integer(&ID_Variable_not_source_454,0);
		_integer(&ID_Variable_not_complete_flag_455,0);
		_StrlSampleIndex(&ID_Variable_temp_index_456,INITIAL_INDEX);
		_StrlSampleRange(&ID_Variable_temp_range_457,INITIAL_RANGE);
		_StrlSampleSize(&ID_Variable_complete_var_458,INITIAL_SIZE);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_459);
		CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_460);
		if (_eq_integer(CHECK_MYWRITERLL(ID_InputOutput_Coder_module_42),0)) {
			current_point_bit_vector[4] |= 0x10000000; /* On:  #156*/
		} else {
			if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_InputOutput_Coder_module_42),0)) {
				current_point_bit_vector[4] |= 0x8000000; /* On:  #155*/
			} else {
				if ((GET_NUMBERINPUTS(ID_InputOutput_Coder_module_42) > 0)) {
					_integer(&ID_Variable_not_source_454,1);
				}
				_StrlSampleSize(&ID_Variable_complete_var_458,REALCOMPUTEDATA(ID_InputOutput_Coder_module_42, ID_Variable_not_source_454));
				if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_InputOutput_Coder_module_42), ID_Variable_complete_var_458) > 0)) {
					_integer(&ID_Variable_not_complete_flag_455,(ID_Variable_not_complete_flag_455 - 1));
					current_point_bit_vector[4] |= 0x4000000; /* On:  #154*/
				} else {
					current_point_bit_vector[4] |= 0x4000000; /* On:  #154*/
				}
			}
		}
	} else {
		next_point_bit_vector[4] |= 0x2000000; /* PauseOn:  #153*/
	}
}

static void Point_154() {
	if ((ID_Variable_not_complete_flag_455 < 0)) {
		_StrlSampleIndex(&ID_Variable_temp_index_456,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_InputOutput_Coder_module_42), ID_Variable_complete_var_458));
		SET_MARKEDWP(ID_InputOutput_Coder_module_42, ID_Variable_temp_index_456);
	}
	WRITEDATA(ID_InputOutput_Coder_module_42, ID_Variable_not_source_454);
	_StrlSampleIndex(&ID_Variable_temp_index_456,GETWP(ID_InputOutput_Coder_module_42));
	_StrlSampleRange(&ID_Output_CODER_COMPUTEDSR_48,GET_MYMARKEDDATA(ID_InputOutput_Coder_module_42));
	UDP_FLOW_O_CODER_COMPUTEDSR(ID_Output_CODER_COMPUTEDSR_48); EMIT(SIG_ID_Output_CODER_COMPUTEDSR_48);
	current_point_bit_vector[4] |= 0x20000000; /* On:  #157*/
}

static void Point_155() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_459);
	current_point_bit_vector[4] |= 0x20000000; /* On:  #157*/
	current_point_bit_vector[4] &= ~0x4000000; /* Off:  #154*/
}

static void Point_156() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_459);
	current_point_bit_vector[4] |= 0x20000000; /* On:  #157*/
	current_point_bit_vector[4] &= ~0x4000000; /* Off:  #154*/
}

static void Point_157() {
	LOCALINCAWAITTICK(ID_InputOutput_Coder_module_42);
	next_point_bit_vector[0] |= 0x400; /* PauseOn:  #10*/
}


int UDP_FLOW() {
	unsigned int i = 0;
	unsigned int *current_point_ptr;
	unsigned int var;
	char self;
	
	current_point_ptr = current_point_bit_vector;
	if (*current_point_ptr) {
		if ((*current_point_ptr) & 0x1) {
			Point_0();
		}
		if ((*current_point_ptr) & 0x2) {
			Point_1();
		}
		if ((*current_point_ptr) & 0x4) {
			Point_2();
		}
		if ((*current_point_ptr) & 0x8) {
			Point_3();
		}
		if ((*current_point_ptr) & 0x10) {
			Point_4();
		}
		if ((*current_point_ptr) & 0x20) {
			Point_5();
		}
		if ((*current_point_ptr) & 0x40) {
			Point_6();
		}
		if ((*current_point_ptr) & 0x80) {
			Point_7();
		}
		if ((*current_point_ptr) & 0x100) {
			Point_8();
		}
		if ((*current_point_ptr) & 0x200) {
			Point_9();
		}
		if ((*current_point_ptr) & 0x400) {
			Point_10();
		}
		if ((*current_point_ptr) & 0x800) {
			Point_11();
		}
		if ((*current_point_ptr) & 0x1000) {
			Point_12();
		}
		if ((*current_point_ptr) & 0x2000) {
			Point_13();
		}
		if ((*current_point_ptr) & 0x4000) {
			Point_14();
		}
		if ((*current_point_ptr) & 0x8000) {
			Point_15();
		}
		if ((*current_point_ptr) & 0x10000) {
			Point_16();
		}
		if ((*current_point_ptr) & 0x20000) {
			Point_17();
		}
		if ((*current_point_ptr) & 0x40000) {
			Point_18();
		}
		if ((*current_point_ptr) & 0x80000) {
			Point_19();
		}
		if ((*current_point_ptr) & 0x100000) {
			Point_20();
		}
		if ((*current_point_ptr) & 0x200000) {
			Point_21();
		}
		if ((*current_point_ptr) & 0x400000) {
			Point_22();
		}
		if ((*current_point_ptr) & 0x800000) {
			Point_23();
		}
		if ((*current_point_ptr) & 0x1000000) {
			Point_24();
		}
		if ((*current_point_ptr) & 0x2000000) {
			Point_25();
		}
		if ((*current_point_ptr) & 0x4000000) {
			Point_26();
		}
		if ((*current_point_ptr) & 0x8000000) {
			Point_27();
		}
		if ((*current_point_ptr) & 0x10000000) {
			Point_28();
		}
		if ((*current_point_ptr) & 0x20000000) {
			Point_29();
		}
		if ((*current_point_ptr) & 0x40000000) {
			Point_30();
		}
		if ((*current_point_ptr) & 0x80000000) {
			Point_31();
		}
	}
	current_point_ptr++;
	if (*current_point_ptr) {
		if ((*current_point_ptr) & 0x1) {
			Point_32();
		}
		if ((*current_point_ptr) & 0x2) {
			Point_33();
		}
		if ((*current_point_ptr) & 0x4) {
			Point_34();
		}
		if ((*current_point_ptr) & 0x8) {
			Point_35();
		}
		if ((*current_point_ptr) & 0x10) {
			Point_36();
		}
		if ((*current_point_ptr) & 0x20) {
			Point_37();
		}
		if ((*current_point_ptr) & 0x40) {
			Point_38();
		}
		if ((*current_point_ptr) & 0x80) {
			Point_39();
		}
		if ((*current_point_ptr) & 0x100) {
			Point_40();
		}
		if ((*current_point_ptr) & 0x200) {
			Point_41();
		}
		if ((*current_point_ptr) & 0x400) {
			Point_42();
		}
		if ((*current_point_ptr) & 0x800) {
			Point_43();
		}
		if ((*current_point_ptr) & 0x1000) {
			Point_44();
		}
		if ((*current_point_ptr) & 0x2000) {
			Point_45();
		}
		if ((*current_point_ptr) & 0x4000) {
			Point_46();
		}
		if ((*current_point_ptr) & 0x8000) {
			Point_47();
		}
		if ((*current_point_ptr) & 0x10000) {
			Point_48();
		}
		if ((*current_point_ptr) & 0x20000) {
			Point_49();
		}
		if ((*current_point_ptr) & 0x40000) {
			Point_50();
		}
		if ((*current_point_ptr) & 0x80000) {
			Point_51();
		}
		if ((*current_point_ptr) & 0x100000) {
			Point_52();
		}
		if ((*current_point_ptr) & 0x200000) {
			Point_53();
		}
		if ((*current_point_ptr) & 0x400000) {
			Point_54();
		}
		if ((*current_point_ptr) & 0x800000) {
			Point_55();
		}
		if ((*current_point_ptr) & 0x1000000) {
			Point_56();
		}
		if ((*current_point_ptr) & 0x2000000) {
			Point_57();
		}
		if ((*current_point_ptr) & 0x4000000) {
			Point_58();
		}
		if ((*current_point_ptr) & 0x8000000) {
			Point_59();
		}
		if ((*current_point_ptr) & 0x10000000) {
			Point_60();
		}
		if ((*current_point_ptr) & 0x20000000) {
			Point_61();
		}
		if ((*current_point_ptr) & 0x40000000) {
			Point_62();
		}
		if ((*current_point_ptr) & 0x80000000) {
			Point_63();
		}
	}
	current_point_ptr++;
	if (*current_point_ptr) {
		if ((*current_point_ptr) & 0x1) {
			Point_64();
		}
		if ((*current_point_ptr) & 0x2) {
			Point_65();
		}
		if ((*current_point_ptr) & 0x4) {
			Point_66();
		}
		if ((*current_point_ptr) & 0x8) {
			Point_67();
		}
		if ((*current_point_ptr) & 0x10) {
			Point_68();
		}
		if ((*current_point_ptr) & 0x20) {
			Point_69();
		}
		if ((*current_point_ptr) & 0x40) {
			Point_70();
		}
		if ((*current_point_ptr) & 0x80) {
			Point_71();
		}
		if ((*current_point_ptr) & 0x100) {
			Point_72();
		}
		if ((*current_point_ptr) & 0x200) {
			Point_73();
		}
		if ((*current_point_ptr) & 0x400) {
			Point_74();
		}
		if ((*current_point_ptr) & 0x800) {
			Point_75();
		}
		if ((*current_point_ptr) & 0x1000) {
			Point_76();
		}
		if ((*current_point_ptr) & 0x2000) {
			Point_77();
		}
		if ((*current_point_ptr) & 0x4000) {
			Point_78();
		}
		if ((*current_point_ptr) & 0x8000) {
			Point_79();
		}
		if ((*current_point_ptr) & 0x10000) {
			Point_80();
		}
		if ((*current_point_ptr) & 0x20000) {
			Point_81();
		}
		if ((*current_point_ptr) & 0x40000) {
			Point_82();
		}
		if ((*current_point_ptr) & 0x80000) {
			Point_83();
		}
		if ((*current_point_ptr) & 0x100000) {
			Point_84();
		}
		if ((*current_point_ptr) & 0x200000) {
			Point_85();
		}
		if ((*current_point_ptr) & 0x400000) {
			Point_86();
		}
		if ((*current_point_ptr) & 0x800000) {
			Point_87();
		}
		if ((*current_point_ptr) & 0x1000000) {
			Point_88();
		}
		if ((*current_point_ptr) & 0x2000000) {
			Point_89();
		}
		if ((*current_point_ptr) & 0x4000000) {
			Point_90();
		}
		if ((*current_point_ptr) & 0x8000000) {
			Point_91();
		}
		if ((*current_point_ptr) & 0x10000000) {
			Point_92();
		}
		if ((*current_point_ptr) & 0x20000000) {
			Point_93();
		}
		if ((*current_point_ptr) & 0x40000000) {
			Point_94();
		}
		if ((*current_point_ptr) & 0x80000000) {
			Point_95();
		}
	}
	current_point_ptr++;
	if (*current_point_ptr) {
		if ((*current_point_ptr) & 0x1) {
			Point_96();
		}
		if ((*current_point_ptr) & 0x2) {
			Point_97();
		}
		if ((*current_point_ptr) & 0x4) {
			Point_98();
		}
		if ((*current_point_ptr) & 0x8) {
			Point_99();
		}
		if ((*current_point_ptr) & 0x10) {
			Point_100();
		}
		if ((*current_point_ptr) & 0x20) {
			Point_101();
		}
		if ((*current_point_ptr) & 0x40) {
			Point_102();
		}
		if ((*current_point_ptr) & 0x80) {
			Point_103();
		}
		if ((*current_point_ptr) & 0x100) {
			Point_104();
		}
		if ((*current_point_ptr) & 0x200) {
			Point_105();
		}
		if ((*current_point_ptr) & 0x400) {
			Point_106();
		}
		if ((*current_point_ptr) & 0x800) {
			Point_107();
		}
		if ((*current_point_ptr) & 0x1000) {
			Point_108();
		}
		if ((*current_point_ptr) & 0x2000) {
			Point_109();
		}
		if ((*current_point_ptr) & 0x4000) {
			Point_110();
		}
		if ((*current_point_ptr) & 0x8000) {
			Point_111();
		}
		if ((*current_point_ptr) & 0x10000) {
			Point_112();
		}
		if ((*current_point_ptr) & 0x20000) {
			Point_113();
		}
		if ((*current_point_ptr) & 0x40000) {
			Point_114();
		}
		if ((*current_point_ptr) & 0x80000) {
			Point_115();
		}
		if ((*current_point_ptr) & 0x100000) {
			Point_116();
		}
		if ((*current_point_ptr) & 0x200000) {
			Point_117();
		}
		if ((*current_point_ptr) & 0x400000) {
			Point_118();
		}
		if ((*current_point_ptr) & 0x800000) {
			Point_119();
		}
		if ((*current_point_ptr) & 0x1000000) {
			Point_120();
		}
		if ((*current_point_ptr) & 0x2000000) {
			Point_121();
		}
		if ((*current_point_ptr) & 0x4000000) {
			Point_122();
		}
		if ((*current_point_ptr) & 0x8000000) {
			Point_123();
		}
		if ((*current_point_ptr) & 0x10000000) {
			Point_124();
		}
		if ((*current_point_ptr) & 0x20000000) {
			Point_125();
		}
		if ((*current_point_ptr) & 0x40000000) {
			Point_126();
		}
		if ((*current_point_ptr) & 0x80000000) {
			Point_127();
		}
	}
	current_point_ptr++;
	if (*current_point_ptr) {
		if ((*current_point_ptr) & 0x1) {
			Point_128();
		}
		if ((*current_point_ptr) & 0x2) {
			Point_129();
		}
		if ((*current_point_ptr) & 0x4) {
			Point_130();
		}
		if ((*current_point_ptr) & 0x8) {
			Point_131();
		}
		if ((*current_point_ptr) & 0x10) {
			Point_132();
		}
		if ((*current_point_ptr) & 0x20) {
			Point_133();
		}
		if ((*current_point_ptr) & 0x40) {
			Point_134();
		}
		if ((*current_point_ptr) & 0x80) {
			Point_135();
		}
		if ((*current_point_ptr) & 0x100) {
			Point_136();
		}
		if ((*current_point_ptr) & 0x200) {
			Point_137();
		}
		if ((*current_point_ptr) & 0x400) {
			Point_138();
		}
		if ((*current_point_ptr) & 0x800) {
			Point_139();
		}
		if ((*current_point_ptr) & 0x1000) {
			Point_140();
		}
		if ((*current_point_ptr) & 0x2000) {
			Point_141();
		}
		if ((*current_point_ptr) & 0x4000) {
			Point_142();
		}
		if ((*current_point_ptr) & 0x8000) {
			Point_143();
		}
		if ((*current_point_ptr) & 0x10000) {
			Point_144();
		}
		if ((*current_point_ptr) & 0x20000) {
			Point_145();
		}
		if ((*current_point_ptr) & 0x40000) {
			Point_146();
		}
		if ((*current_point_ptr) & 0x80000) {
			Point_147();
		}
		if ((*current_point_ptr) & 0x100000) {
			Point_148();
		}
		if ((*current_point_ptr) & 0x200000) {
			Point_149();
		}
		if ((*current_point_ptr) & 0x400000) {
			Point_150();
		}
		if ((*current_point_ptr) & 0x800000) {
			Point_151();
		}
		if ((*current_point_ptr) & 0x1000000) {
			Point_152();
		}
		if ((*current_point_ptr) & 0x2000000) {
			Point_153();
		}
		if ((*current_point_ptr) & 0x4000000) {
			Point_154();
		}
		if ((*current_point_ptr) & 0x8000000) {
			Point_155();
		}
		if ((*current_point_ptr) & 0x10000000) {
			Point_156();
		}
		if ((*current_point_ptr) & 0x20000000) {
			Point_157();
		}
	}
	current_point_ptr++;
	{
		int i;
		
		for (i = 0 ; i < SIGNAL_VECTOR_SIZE; i++) signal_bit_vector[i] = 0;
		for (i = 0 ; i < HALT_POINT_VECTOR_SIZE; i++) current_point_bit_vector[i] = next_point_bit_vector[i];
		for (i = 0 ; i < HALT_POINT_VECTOR_SIZE; i++) next_point_bit_vector[i] = 0;
	}
	return 1;
}

int UDP_FLOW_reset() {
	int i,j;
	
	if (!ID_Signal_R_Name_548) ID_Signal_R_Name_548 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Signal_R_Name_519) ID_Signal_R_Name_519 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_My_Name_512) ID_Variable_My_Name_512 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Signal_R_Name_501) ID_Signal_R_Name_501 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Signal_R_Name_469) ID_Signal_R_Name_469 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Signal_R_Name_438) ID_Signal_R_Name_438 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_My_Name_431) ID_Variable_My_Name_431 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Signal_R_Name_378) ID_Signal_R_Name_378 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofsink_77) ID_Variable_nameofsink_77 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofscopesink_76) ID_Variable_nameofscopesink_76 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofsummer_75) ID_Variable_nameofsummer_75 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofmod_74) ID_Variable_nameofmod_74 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofcoder_73) ID_Variable_nameofcoder_73 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofsource_72) ID_Variable_nameofsource_72 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_InputOutput_Sink_module_46) ID_InputOutput_Sink_module_46 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_InputOutput_Scopesink_module_45) ID_InputOutput_Scopesink_module_45 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_InputOutput_Summer_module_44) ID_InputOutput_Summer_module_44 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_InputOutput_Mod_module_43) ID_InputOutput_Mod_module_43 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_InputOutput_Coder_module_42) ID_InputOutput_Coder_module_42 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_InputOutput_Source_module_41) ID_InputOutput_Source_module_41 = (string) calloc(STRLEN,sizeof(char));
	for (i = 0 ; i < SIGNAL_VECTOR_SIZE; i++) signal_bit_vector[i] = 0;
	for (i = 0 ; i < HALT_POINT_VECTOR_SIZE; i++) current_point_bit_vector[i] = next_point_bit_vector[i];
	for (i = 0 ; i < HALT_POINT_VECTOR_SIZE; i++) next_point_bit_vector[i] = 0;
	BIT_SET(current_point_bit_vector, 0);
}
