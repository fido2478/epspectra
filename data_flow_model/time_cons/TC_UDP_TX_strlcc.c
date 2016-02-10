/* "SAXORT STRL Compiler version 3.0 compiled on Fri Mar 30 11:02:53 MET DST 2001" */

/* automaton kernel code*/
#include <stdlib.h>
#include <stdio.h>
#include "TC_UDP_TX_strlcc.h"
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

#define HALT_POINT_NUM 166
#define HALT_POINT_VECTOR_SIZE ((HALT_POINT_NUM-1)/(int)SIZEOFINT)+1
static unsigned int current_point_bit_vector[HALT_POINT_VECTOR_SIZE];
static unsigned int next_point_bit_vector[HALT_POINT_VECTOR_SIZE];

#define SIGNAL_NUM 97
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

#define SIG_ID_Exception_trap_time_128 96
#define SIG_ID_Exception_GOTO_UNMARK_623 95
#define SIG_ID_Exception_EXIT_FUNC_622 94
static StrlSampleSize ID_Variable_complete_var_621 ;
static StrlSampleRange ID_Variable_temp_range_620 ;
static StrlSampleIndex ID_Variable_temp_index_619 ;
static integer ID_Variable_not_complete_flag_618 ;
static integer ID_Variable_not_source_617 ;
static integer ID_Variable_temp_int_616 ;
static UnsignedInt ID_Variable_temp_unsigned_615 ;
static integer ID_Variable_temp_int_614 ;
static integer ID_Variable_maxOutSize_613 ;
static integer ID_Variable_sameindex_612 ;
static integer ID_Variable_requestSize_611 ;
static StrlSampleIndex ID_Variable_desiredWP_610 ;
static StrlSampleIndex ID_Variable_evaluatedWP_609 ;
static StrlSampleIndex ID_Variable_pendingWP_608 ;
static StrlSampleRange ID_Variable_inside_input_607 ;
static StrlSampleRange ID_Variable_output_range_606 ;
static StrlSampleRange ID_Variable_input_range_605 ;
#define SIG_ID_Exception_compute_loop_604 93
#define SIG_ID_Signal_R_Name_603 92
static string ID_Signal_R_Name_603  = NULL;
#define SIG_ID_Signal_switch_off_602 91
#define SIG_ID_Signal_switch_on_601 90
#define SIG_ID_Signal_forecast_range_600 89
static StrlSampleRange ID_Signal_forecast_range_600 ;
#define SIG_ID_Signal_My_Sample_Range_599 88
static StrlSampleRange ID_Signal_My_Sample_Range_599 ;
static StrlSampleRange ID_Variable_my_input_598 ;
static StrlSampleRange ID_Variable_org_input_597 ;
static boolean ID_Variable_CONT_FLAG_596 ;
#define SIG_ID_Exception_main_loop_595 87
#define SIG_ID_Exception_GOTO_UNMARK_594 86
#define SIG_ID_Exception_EXIT_FUNC_593 85
static StrlSampleSize ID_Variable_complete_var_592 ;
static StrlSampleRange ID_Variable_temp_range_591 ;
static StrlSampleIndex ID_Variable_temp_index_590 ;
static integer ID_Variable_not_complete_flag_589 ;
static integer ID_Variable_not_source_588 ;
static integer ID_Variable_temp_int_587 ;
static UnsignedInt ID_Variable_temp_unsigned_586 ;
static integer ID_Variable_temp_int_585 ;
static integer ID_Variable_maxOutSize_584 ;
static integer ID_Variable_sameindex_583 ;
static integer ID_Variable_requestSize_582 ;
static StrlSampleIndex ID_Variable_desiredWP_581 ;
static StrlSampleIndex ID_Variable_evaluatedWP_580 ;
static StrlSampleIndex ID_Variable_pendingWP_579 ;
static StrlSampleRange ID_Variable_inside_input_578 ;
static StrlSampleRange ID_Variable_output_range_577 ;
static StrlSampleRange ID_Variable_input_range_576 ;
#define SIG_ID_Exception_compute_loop_574 84
#define SIG_ID_Exception_main_trap_575 83
#define SIG_ID_Signal_INI_PHASE_573 82
static boolean ID_Signal_INI_PHASE_573 ;
#define SIG_ID_Signal_R_Name_572 81
static string ID_Signal_R_Name_572  = NULL;
#define SIG_ID_Signal_switch_off_571 80
#define SIG_ID_Signal_switch_on_570 79
#define SIG_ID_Signal_forecast_range_569 78
static StrlSampleRange ID_Signal_forecast_range_569 ;
#define SIG_ID_Signal_My_Sample_Range_568 77
static StrlSampleRange ID_Signal_My_Sample_Range_568 ;
static StrlSampleRange ID_Variable_my_input_567 ;
static StrlSampleRange ID_Variable_org_input_566 ;
static string ID_Variable_My_Name_565  = NULL;
static boolean ID_Variable_CONT_FLAG_564 ;
static UnsignedInt ID_Variable_temp_unsigned_563 ;
static integer ID_Variable_temp_int_562 ;
static integer ID_Variable_maxOutSize_561 ;
static integer ID_Variable_sameindex_560 ;
static integer ID_Variable_requestSize_559 ;
static StrlSampleIndex ID_Variable_desiredWP_558 ;
static StrlSampleIndex ID_Variable_evaluatedWP_557 ;
static StrlSampleIndex ID_Variable_pendingWP_556 ;
static StrlSampleRange ID_Variable_inside_input_555 ;
static StrlSampleRange ID_Variable_output_range_554 ;
static StrlSampleRange ID_Variable_input_range_553 ;
#define SIG_ID_Signal_R_Name_552 76
static string ID_Signal_R_Name_552  = NULL;
#define SIG_ID_Signal_switch_off_551 75
#define SIG_ID_Signal_switch_on_550 74
#define SIG_ID_Signal_forecast_range_549 73
static StrlSampleRange ID_Signal_forecast_range_549 ;
#define SIG_ID_Signal_My_Sample_Range_548 72
static StrlSampleRange ID_Signal_My_Sample_Range_548 ;
static StrlSampleRange ID_Variable_my_input_547 ;
static StrlSampleRange ID_Variable_org_input_546 ;
static integer ID_Variable_n_times_545 ;
static boolean ID_Variable_CONT_FLAG_544 ;
#define SIG_ID_Exception_main_loop_542 71
#define SIG_ID_Exception_GOTO_UNMARK_541 70
#define SIG_ID_Exception_EXIT_FUNC_540 69
static StrlSampleSize ID_Variable_complete_var_539 ;
static StrlSampleRange ID_Variable_temp_range_538 ;
static StrlSampleIndex ID_Variable_temp_index_537 ;
static integer ID_Variable_not_complete_flag_536 ;
static integer ID_Variable_not_source_535 ;
static integer ID_Variable_temp_int_534 ;
static UnsignedInt ID_Variable_temp_unsigned_533 ;
static integer ID_Variable_temp_int_532 ;
static integer ID_Variable_maxOutSize_531 ;
static integer ID_Variable_sameindex_530 ;
static integer ID_Variable_requestSize_529 ;
static StrlSampleIndex ID_Variable_desiredWP_528 ;
static StrlSampleIndex ID_Variable_evaluatedWP_527 ;
static StrlSampleIndex ID_Variable_pendingWP_526 ;
static StrlSampleRange ID_Variable_inside_input_525 ;
static StrlSampleRange ID_Variable_output_range_524 ;
static StrlSampleRange ID_Variable_input_range_523 ;
#define SIG_ID_Exception_main_trap_522 68
#define SIG_ID_Exception_compute_loop_520 67
#define SIG_ID_Exception_main_trap_521 66
#define SIG_ID_Signal_INI_PHASE_519 65
static boolean ID_Signal_INI_PHASE_519 ;
#define SIG_ID_Signal_R_Name_518 64
static string ID_Signal_R_Name_518  = NULL;
#define SIG_ID_Signal_switch_off_517 63
#define SIG_ID_Signal_switch_on_516 62
#define SIG_ID_Signal_forecast_range_515 61
static StrlSampleRange ID_Signal_forecast_range_515 ;
#define SIG_ID_Signal_My_Sample_Range_514 60
static StrlSampleRange ID_Signal_My_Sample_Range_514 ;
static StrlSampleRange ID_Variable_my_input_513 ;
static StrlSampleRange ID_Variable_org_input_512 ;
static boolean ID_Variable_CONT_FLAG_511 ;
#define SIG_ID_Exception_main_loop_510 59
#define SIG_ID_Exception_GOTO_UNMARK_509 58
#define SIG_ID_Exception_EXIT_FUNC_508 57
static StrlSampleSize ID_Variable_complete_var_507 ;
static StrlSampleRange ID_Variable_temp_range_506 ;
static StrlSampleIndex ID_Variable_temp_index_505 ;
static integer ID_Variable_not_complete_flag_504 ;
static integer ID_Variable_not_source_503 ;
static integer ID_Variable_temp_int_502 ;
static UnsignedInt ID_Variable_temp_unsigned_501 ;
static integer ID_Variable_temp_int_500 ;
static integer ID_Variable_maxOutSize_499 ;
static integer ID_Variable_sameindex_498 ;
static integer ID_Variable_requestSize_497 ;
static StrlSampleIndex ID_Variable_desiredWP_496 ;
static StrlSampleIndex ID_Variable_evaluatedWP_495 ;
static StrlSampleIndex ID_Variable_pendingWP_494 ;
static StrlSampleRange ID_Variable_inside_input_493 ;
static StrlSampleRange ID_Variable_output_range_492 ;
static StrlSampleRange ID_Variable_input_range_491 ;
#define SIG_ID_Exception_compute_loop_486 56
#define SIG_ID_Exception_main_trap_487 55
#define SIG_ID_Signal_INI_PHASE_485 54
static boolean ID_Signal_INI_PHASE_485 ;
#define SIG_ID_Signal_R_Name_484 53
static string ID_Signal_R_Name_484  = NULL;
#define SIG_ID_Signal_switch_off_483 52
#define SIG_ID_Signal_switch_on_482 51
#define SIG_ID_Signal_forecast_range_481 50
static StrlSampleRange ID_Signal_forecast_range_481 ;
#define SIG_ID_Signal_My_Sample_Range_480 49
static StrlSampleRange ID_Signal_My_Sample_Range_480 ;
static StrlSampleRange ID_Variable_my_input_479 ;
static StrlSampleRange ID_Variable_org_input_478 ;
static string ID_Variable_My_Name_477  = NULL;
static boolean ID_Variable_CONT_FLAG_476 ;
#define SIG_ID_Exception_main_loop_473 48
#define SIG_ID_Exception_GOTO_UNMARK_472 47
#define SIG_ID_Exception_EXIT_FUNC_471 46
static StrlSampleSize ID_Variable_complete_var_470 ;
static StrlSampleRange ID_Variable_temp_range_469 ;
static StrlSampleIndex ID_Variable_temp_index_468 ;
static integer ID_Variable_not_complete_flag_467 ;
static integer ID_Variable_not_source_466 ;
static integer ID_Variable_temp_int_465 ;
static UnsignedInt ID_Variable_temp_unsigned_448 ;
static integer ID_Variable_temp_int_447 ;
static integer ID_Variable_maxOutSize_446 ;
static integer ID_Variable_requestSize_445 ;
static StrlSampleIndex ID_Variable_remainedWP_444 ;
static StrlSampleIndex ID_Variable_pendingWP_443 ;
static StrlSampleRange ID_Variable_output_range_442 ;
static StrlSampleRange ID_Variable_input_range_441 ;
#define SIG_ID_Signal_R_Name_422 45
static string ID_Signal_R_Name_422  = NULL;
#define SIG_ID_Signal_My_Sample_Range_421 44
static StrlSampleRange ID_Signal_My_Sample_Range_421 ;
static StrlSampleRange ID_Variable_my_output_420 ;
static boolean ID_Variable_INITIAL_FLAG_419 ;
#define SIG_ID_Signal_ack_MD_122 43
#define SIG_ID_Signal_Clock_Wire_M_S2_121 42
#define SIG_ID_Signal_Clock_Wire_M_S1_120 41
#define SIG_ID_Signal_Clock_Wire_M_M1_119 40
#define SIG_ID_Signal_Clock_Wire_S_M_118 39
#define SIG_ID_Signal_Ack_Wire_M_S2_117 38
static StrlSampleRange ID_Signal_Ack_Wire_M_S2_117 ;
#define SIG_ID_Signal_Ack_Wire_M_S1_116 37
static StrlSampleRange ID_Signal_Ack_Wire_M_S1_116 ;
#define SIG_ID_Signal_Ack_Wire_M_M2_115 36
static StrlSampleRange ID_Signal_Ack_Wire_M_M2_115 ;
#define SIG_ID_Signal_Ack_Wire_M_M1_114 35
static StrlSampleRange ID_Signal_Ack_Wire_M_M1_114 ;
#define SIG_ID_Signal_Ack_Wire_S_M_113 34
static StrlSampleRange ID_Signal_Ack_Wire_S_M_113 ;
#define SIG_ID_Signal_Compute_Wire_M_S2_112 33
#define SIG_ID_Signal_Compute_Wire_M_S1_111 32
#define SIG_ID_Signal_Compute_Wire_M_M1_110 31
#define SIG_ID_Signal_Compute_Wire_S_M_109 30
#define SIG_ID_Signal_Mark_Wire_M_S2_108 29
static StrlSampleRange ID_Signal_Mark_Wire_M_S2_108 ;
#define SIG_ID_Signal_Mark_Wire_M_S1_107 28
static StrlSampleRange ID_Signal_Mark_Wire_M_S1_107 ;
#define SIG_ID_Signal_Mark_Wire_M_M2_106 27
static StrlSampleRange ID_Signal_Mark_Wire_M_M2_106 ;
#define SIG_ID_Signal_Mark_Wire_M_M1_105 26
static StrlSampleRange ID_Signal_Mark_Wire_M_M1_105 ;
#define SIG_ID_Signal_Mark_Wire_S_M_104 25
static StrlSampleRange ID_Signal_Mark_Wire_S_M_104 ;
#define SIG_ID_Signal_Missed_Deadline_103 24
static UnsignedLL ID_Signal_Missed_Deadline_103 ;
#define SIG_ID_Signal_Trigger_102 23
#define SIG_ID_Signal_end_alarm_101 22
#define SIG_ID_Signal_start_alarm_100 21
static integer ID_Variable_tmp_99 ;
static double ID_Variable_dtsec_98 ;
static float ID_Variable_diff_97 ;
static float ID_Variable_outfq_96 ;
static float ID_Variable_infq_95 ;
static UnsignedLL ID_Variable_skip_sample_94 ;
static UnsignedLL ID_Variable_this_time_93 ;
static UnsignedLL ID_Variable_prev_time_92 ;
static UnsignedLong ID_Variable_this_outsample_91 ;
static UnsignedLong ID_Variable_prev_outsample_90 ;
static StrlSampleRange ID_Variable_outsample_89 ;
static StrlSampleRange ID_Variable_insample_88 ;
static string ID_Variable_nameofsink_87  = NULL;
static string ID_Variable_nameofscopesink_86  = NULL;
static string ID_Variable_nameofsummer_85  = NULL;
static string ID_Variable_nameofmod_84  = NULL;
static string ID_Variable_nameofcoder_83  = NULL;
static string ID_Variable_nameofsource_82  = NULL;
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
#define SIG_ID_Output_debug_sink_59 20
static Debug4Var ID_Output_debug_sink_59 ;
#define SIG_ID_Output_debug_scopesink_58 19
static Debug4Var ID_Output_debug_scopesink_58 ;
#define SIG_ID_Output_debug_summer_57 18
static Debug4Var ID_Output_debug_summer_57 ;
#define SIG_ID_Output_debug_mod_56 17
static Debug4Var ID_Output_debug_mod_56 ;
#define SIG_ID_Output_debug_coder_55 16
static Debug4Var ID_Output_debug_coder_55 ;
#define SIG_ID_Output_debug_source_54 15
static Debug4Var ID_Output_debug_source_54 ;
#define SIG_ID_Output_SINK_COMPUTEDSR_53 14
static StrlSampleRange ID_Output_SINK_COMPUTEDSR_53 ;
#define SIG_ID_Output_SCOPESINK_COMPUTEDSR_52 13
static StrlSampleRange ID_Output_SCOPESINK_COMPUTEDSR_52 ;
#define SIG_ID_Output_SUMMER_COMPUTEDSR_51 12
static StrlSampleRange ID_Output_SUMMER_COMPUTEDSR_51 ;
#define SIG_ID_Output_MOD_COMPUTEDSR_50 11
static StrlSampleRange ID_Output_MOD_COMPUTEDSR_50 ;
#define SIG_ID_Output_CODER_COMPUTEDSR_49 10
static StrlSampleRange ID_Output_CODER_COMPUTEDSR_49 ;
#define SIG_ID_Output_SOURCE_COMPUTEDSR_48 9
static StrlSampleRange ID_Output_SOURCE_COMPUTEDSR_48 ;
#define SIG_ID_InputOutput_Sink_module_47 8
static string ID_InputOutput_Sink_module_47  = NULL;
#define SIG_ID_InputOutput_Scopesink_module_46 7
static string ID_InputOutput_Scopesink_module_46  = NULL;
#define SIG_ID_InputOutput_Summer_module_45 6
static string ID_InputOutput_Summer_module_45  = NULL;
#define SIG_ID_InputOutput_Mod_module_44 5
static string ID_InputOutput_Mod_module_44  = NULL;
#define SIG_ID_InputOutput_Coder_module_43 4
static string ID_InputOutput_Coder_module_43  = NULL;
#define SIG_ID_InputOutput_Source_module_42 3
static string ID_InputOutput_Source_module_42  = NULL;
#define SIG_ID_Input_User_Quit_41 2
#define SIG_ID_Input_on_TimeConstraint_40 1
static integer ID_Input_on_TimeConstraint_40 ;
#define SIG_ID_Input_inputdt_39 0
static double ID_Input_inputdt_39 ;
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
#ifndef NEWGETWP
extern UnsignedLong NEWGETWP(string);
#endif
#ifndef GET_FREQUENCY
extern float GET_FREQUENCY(string);
#endif
#ifndef GET_TIMESTAMP
extern UnsignedLL GET_TIMESTAMP();
#endif
#ifndef ELAPSE_TIME
extern integer ELAPSE_TIME(UnsignedLL, double);
#endif
#ifndef ALAMEACHSEC
extern integer ALAMEACHSEC(float);
#endif
#ifndef EVAL_TS_TM
extern UnsignedLL EVAL_TS_TM(float, float, double, UnsignedLong, UnsignedLong);
#endif
#ifndef EVAL_TS
extern UnsignedLL EVAL_TS(float, StrlSampleRange, UnsignedLL, UnsignedLL);
#endif
#ifndef CMPSMPINDEX
extern integer CMPSMPINDEX(float, StrlSampleRange, StrlSampleRange);
#endif
#ifndef CMPULL
extern integer CMPULL(UnsignedLL, UnsignedLL);
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
#ifndef SKIP_SAMPLEDATA
extern StrlSampleIndex SKIP_SAMPLEDATA(UnsignedLL, StrlSampleIndex);
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
#ifndef GETINDEX
extern StrlSampleIndex GETINDEX(StrlSampleRange);
#endif
#ifndef INSIDE_COMP_FIT
extern StrlSampleRange INSIDE_COMP_FIT(StrlSampleRange, StrlSampleRange, string);
#endif
#ifndef CONNECT_MODULES
extern void CONNECT_MODULES(string, string, integer, integer);
#endif
#ifndef INITIAL_SINK
extern void INITIAL_SINK(string);
#endif
#ifndef INITGUI_MAIN_START
extern void INITGUI_MAIN_START();
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
#ifndef SKIPPING_DATA
extern void SKIPPING_DATA(UnsignedLL);
#endif
#ifndef SET_MARKEDWP
extern void SET_MARKEDWP(string, StrlSampleIndex);
#endif
#ifndef WRITEDATA
extern void WRITEDATA(string, integer);
#endif

extern void TC_UDP_TX_O_debug_sink(Debug4Var);
extern void TC_UDP_TX_O_debug_scopesink(Debug4Var);
extern void TC_UDP_TX_O_debug_summer(Debug4Var);
extern void TC_UDP_TX_O_debug_mod(Debug4Var);
extern void TC_UDP_TX_O_debug_coder(Debug4Var);
extern void TC_UDP_TX_O_debug_source(Debug4Var);
extern void TC_UDP_TX_O_SINK_COMPUTEDSR(StrlSampleRange);
extern void TC_UDP_TX_O_SCOPESINK_COMPUTEDSR(StrlSampleRange);
extern void TC_UDP_TX_O_SUMMER_COMPUTEDSR(StrlSampleRange);
extern void TC_UDP_TX_O_MOD_COMPUTEDSR(StrlSampleRange);
extern void TC_UDP_TX_O_CODER_COMPUTEDSR(StrlSampleRange);
extern void TC_UDP_TX_O_SOURCE_COMPUTEDSR(StrlSampleRange);
void TC_UDP_TX_I_Sink_module(string value) {EMIT(SIG_ID_InputOutput_Sink_module_47);_string(&ID_InputOutput_Sink_module_47,value);}
extern void TC_UDP_TX_O_Sink_module(string);
void TC_UDP_TX_I_Scopesink_module(string value) {EMIT(SIG_ID_InputOutput_Scopesink_module_46);_string(&ID_InputOutput_Scopesink_module_46,value);}
extern void TC_UDP_TX_O_Scopesink_module(string);
void TC_UDP_TX_I_Summer_module(string value) {EMIT(SIG_ID_InputOutput_Summer_module_45);_string(&ID_InputOutput_Summer_module_45,value);}
extern void TC_UDP_TX_O_Summer_module(string);
void TC_UDP_TX_I_Mod_module(string value) {EMIT(SIG_ID_InputOutput_Mod_module_44);_string(&ID_InputOutput_Mod_module_44,value);}
extern void TC_UDP_TX_O_Mod_module(string);
void TC_UDP_TX_I_Coder_module(string value) {EMIT(SIG_ID_InputOutput_Coder_module_43);_string(&ID_InputOutput_Coder_module_43,value);}
extern void TC_UDP_TX_O_Coder_module(string);
void TC_UDP_TX_I_Source_module(string value) {EMIT(SIG_ID_InputOutput_Source_module_42);_string(&ID_InputOutput_Source_module_42,value);}
extern void TC_UDP_TX_O_Source_module(string);
void TC_UDP_TX_I_User_Quit() {EMIT(SIG_ID_Input_User_Quit_41);}
void TC_UDP_TX_I_on_TimeConstraint(integer value) {EMIT(SIG_ID_Input_on_TimeConstraint_40);_integer(&ID_Input_on_TimeConstraint_40,value);}
void TC_UDP_TX_I_inputdt(double value) {EMIT(SIG_ID_Input_inputdt_39);_double(&ID_Input_inputdt_39,value);}

static void Point_0() {
	CLEAR_SIGNAL(SIG_ID_Signal_start_alarm_100);
	CLEAR_SIGNAL(SIG_ID_Signal_end_alarm_101);
	CLEAR_SIGNAL(SIG_ID_Signal_Trigger_102);
	_UnsignedLL(&ID_Signal_Missed_Deadline_103,INITIAL_UNSIGNEDLL);
	CLEAR_SIGNAL(SIG_ID_Signal_Missed_Deadline_103);
	_StrlSampleRange(&ID_Signal_Mark_Wire_S_M_104,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_104);
	_StrlSampleRange(&ID_Signal_Mark_Wire_M_M1_105,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105);
	_StrlSampleRange(&ID_Signal_Mark_Wire_M_M2_106,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M2_106);
	_StrlSampleRange(&ID_Signal_Mark_Wire_M_S1_107,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_107);
	_StrlSampleRange(&ID_Signal_Mark_Wire_M_S2_108,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S2_108);
	CLEAR_SIGNAL(SIG_ID_Signal_Compute_Wire_S_M_109);
	CLEAR_SIGNAL(SIG_ID_Signal_Compute_Wire_M_M1_110);
	CLEAR_SIGNAL(SIG_ID_Signal_Compute_Wire_M_S1_111);
	CLEAR_SIGNAL(SIG_ID_Signal_Compute_Wire_M_S2_112);
	_StrlSampleRange(&ID_Signal_Ack_Wire_S_M_113,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Ack_Wire_S_M_113);
	_StrlSampleRange(&ID_Signal_Ack_Wire_M_M1_114,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_114);
	_StrlSampleRange(&ID_Signal_Ack_Wire_M_M2_115,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115);
	_StrlSampleRange(&ID_Signal_Ack_Wire_M_S1_116,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116);
	_StrlSampleRange(&ID_Signal_Ack_Wire_M_S2_117,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_117);
	CLEAR_SIGNAL(SIG_ID_Signal_Clock_Wire_S_M_118);
	CLEAR_SIGNAL(SIG_ID_Signal_Clock_Wire_M_M1_119);
	CLEAR_SIGNAL(SIG_ID_Signal_Clock_Wire_M_S1_120);
	CLEAR_SIGNAL(SIG_ID_Signal_Clock_Wire_M_S2_121);
	CLEAR_SIGNAL(SIG_ID_Signal_ack_MD_122);
	_string(&ID_Variable_nameofsource_82,GET_SOURCE("tmp.gz", 1));
	_string(&ID_Variable_nameofcoder_83,GET_CODER(4));
	_string(&ID_Variable_nameofmod_84,GET_MOD_F(200, 6.500000e+04, 80, 16, 5, 2, 6.000000e-01, 4));
	_string(&ID_Variable_nameofsummer_85,GET_SUMMER());
	_string(&ID_Variable_nameofscopesink_86,GET_SCOPESINK_F((2.600000e+03 / 2.000000e+00), -128, 128, 500, 1));
	_string(&ID_Variable_nameofsink_87,GET_SINK("138.96.251.3", 5001));
	CONNECT_MODULES(ID_Variable_nameofscopesink_86, ID_Variable_nameofmod_84, 400000, 8);
	CONNECT_MODULES(ID_Variable_nameofsink_87, ID_Variable_nameofsummer_85, 400000, 8);
	CONNECT_MODULES(ID_Variable_nameofsummer_85, ID_Variable_nameofmod_84, 400000, 8);
	CONNECT_MODULES(ID_Variable_nameofmod_84, ID_Variable_nameofcoder_83, 2000, 8);
	CONNECT_MODULES(ID_Variable_nameofcoder_83, ID_Variable_nameofsource_82, 1000, 8);
	_string(&ID_InputOutput_Source_module_42,ID_Variable_nameofsource_82);
	TC_UDP_TX_O_Source_module(ID_InputOutput_Source_module_42); EMIT(SIG_ID_InputOutput_Source_module_42);
	_string(&ID_InputOutput_Coder_module_43,ID_Variable_nameofcoder_83);
	TC_UDP_TX_O_Coder_module(ID_InputOutput_Coder_module_43); EMIT(SIG_ID_InputOutput_Coder_module_43);
	_string(&ID_InputOutput_Mod_module_44,ID_Variable_nameofmod_84);
	TC_UDP_TX_O_Mod_module(ID_InputOutput_Mod_module_44); EMIT(SIG_ID_InputOutput_Mod_module_44);
	_string(&ID_InputOutput_Summer_module_45,ID_Variable_nameofsummer_85);
	TC_UDP_TX_O_Summer_module(ID_InputOutput_Summer_module_45); EMIT(SIG_ID_InputOutput_Summer_module_45);
	_string(&ID_InputOutput_Scopesink_module_46,ID_Variable_nameofscopesink_86);
	TC_UDP_TX_O_Scopesink_module(ID_InputOutput_Scopesink_module_46); EMIT(SIG_ID_InputOutput_Scopesink_module_46);
	_string(&ID_InputOutput_Sink_module_47,ID_Variable_nameofsink_87);
	TC_UDP_TX_O_Sink_module(ID_InputOutput_Sink_module_47); EMIT(SIG_ID_InputOutput_Sink_module_47);
	INITIAL_SINK(ID_InputOutput_Sink_module_47);
	INITIAL_SINK(ID_InputOutput_Scopesink_module_46);
	_float(&ID_Variable_infq_95,GET_FREQUENCY(ID_Variable_nameofsource_82));
	_float(&ID_Variable_outfq_96,GET_FREQUENCY(ID_Variable_nameofsink_87));
	_float(&ID_Variable_diff_97,(ID_Variable_outfq_96 / ID_Variable_infq_95));
	_double(&ID_Variable_dtsec_98,ID_Input_inputdt_39);
	INIT_PERF_GRAPH();
	INITGUI_MAIN_START();
	RUN_GUI_MAIN();
	_boolean(&ID_Variable_CONT_FLAG_596,0);
	_StrlSampleRange(&ID_Variable_org_input_597,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_my_input_598,INITIAL_RANGE);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_599,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_599);
	_StrlSampleRange(&ID_Signal_forecast_range_600,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_forecast_range_600);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_on_601);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_off_602);
	CLEAR_SIGNAL(SIG_ID_Signal_R_Name_603);
	_boolean(&ID_Variable_CONT_FLAG_544,0);
	_integer(&ID_Variable_n_times_545,0);
	_StrlSampleRange(&ID_Variable_org_input_546,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_my_input_547,INITIAL_RANGE);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_548,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_548);
	_StrlSampleRange(&ID_Signal_forecast_range_549,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_forecast_range_549);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_on_550);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_off_551);
	CLEAR_SIGNAL(SIG_ID_Signal_R_Name_552);
	_boolean(&ID_Variable_CONT_FLAG_476,0);
	_string(&ID_Variable_My_Name_477,"name");
	_StrlSampleRange(&ID_Variable_org_input_478,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_my_input_479,INITIAL_RANGE);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_480,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_480);
	_StrlSampleRange(&ID_Signal_forecast_range_481,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_forecast_range_481);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_on_482);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_off_483);
	CLEAR_SIGNAL(SIG_ID_Signal_R_Name_484);
	CLEAR_SIGNAL(SIG_ID_Signal_INI_PHASE_485);
	_boolean(&ID_Signal_INI_PHASE_485,1);
	EMIT(SIG_ID_Signal_INI_PHASE_485);
	current_point_bit_vector[0] |= 0x2000000; current_point_bit_vector[1] |= 0x4000010; current_point_bit_vector[4] |= 0x100000; /* On:  #25 #36 #58 #148*/
	next_point_bit_vector[0] |= 0x200002; next_point_bit_vector[1] |= 0xc1; /* PauseOn:  #1 #21 #32 #38 #39*/
	if (IS_SIGNAL(SIG_ID_Signal_INI_PHASE_485,0)) {
		next_point_bit_vector[0] |= 0x80; /* PauseOn:  #7*/
	} else {
		CLEAR_SIGNAL(SIG_ID_Exception_main_trap_487);
		next_point_bit_vector[4] |= 0x100; /* PauseOn:  #136*/
		if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_104,0)) {
			next_point_bit_vector[4] |= 0x20; /* PauseOn:  #133*/
		} else {
			current_point_bit_vector[4] |= 0x100; /* On:  #136*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_114,0)) {
			next_point_bit_vector[0] |= 0x100; /* PauseOn:  #8*/
		} else {
			current_point_bit_vector[4] |= 0x100; /* On:  #136*/
		}
		if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_104,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_114,0))) {
			EMIT(SIG_ID_Exception_main_trap_487);
			current_point_bit_vector[4] |= 0x40; /* On:  #134*/
			current_point_bit_vector[4] &= ~0x100; /* Off:  #136*/
		} else {
			current_point_bit_vector[4] |= 0x100; /* On:  #136*/
		}
	}
	START_PERF_GRAPH();
	_StrlSampleRange(&ID_Signal_Ack_Wire_S_M_113,INITIAL_RANGE);
	EMIT(SIG_ID_Signal_Ack_Wire_S_M_113);
	_boolean(&ID_Variable_INITIAL_FLAG_419,1);
	_StrlSampleRange(&ID_Variable_my_output_420,INITIAL_RANGE);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_421,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_421);
	CLEAR_SIGNAL(SIG_ID_Signal_R_Name_422);
	_boolean(&ID_Variable_CONT_FLAG_511,0);
	_StrlSampleRange(&ID_Variable_org_input_512,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_my_input_513,INITIAL_RANGE);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_514,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_514);
	_StrlSampleRange(&ID_Signal_forecast_range_515,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_forecast_range_515);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_on_516);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_off_517);
	CLEAR_SIGNAL(SIG_ID_Signal_R_Name_518);
	CLEAR_SIGNAL(SIG_ID_Signal_INI_PHASE_519);
	_boolean(&ID_Signal_INI_PHASE_519,1);
	EMIT(SIG_ID_Signal_INI_PHASE_519);
	current_point_bit_vector[3] |= 0x8000000; current_point_bit_vector[4] |= 0x10000000; /* On:  #123 #156*/
	if (IS_SIGNAL(SIG_ID_Signal_INI_PHASE_519,0)) {
		next_point_bit_vector[0] |= 0x1000; /* PauseOn:  #12*/
	} else {
		CLEAR_SIGNAL(SIG_ID_Exception_main_trap_521);
		next_point_bit_vector[2] |= 0x2000000; /* PauseOn:  #89*/
		if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0))) {
			next_point_bit_vector[0] |= 0x20000; /* PauseOn:  #17*/
		} else {
			current_point_bit_vector[2] |= 0x2000000; /* On:  #89*/
		}
		if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0))) {
			next_point_bit_vector[2] |= 0x400000; /* PauseOn:  #86*/
		} else {
			current_point_bit_vector[2] |= 0x2000000; /* On:  #89*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0)) {
			next_point_bit_vector[1] |= 0x100; next_point_bit_vector[2] |= 0x60000; /* PauseOn:  #40 #81 #82*/
		} else {
			current_point_bit_vector[2] |= 0x2000000; /* On:  #89*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) {
			next_point_bit_vector[0] |= 0x2000; next_point_bit_vector[2] |= 0x300000; /* PauseOn:  #13 #84 #85*/
		} else {
			current_point_bit_vector[2] |= 0x2000000; /* On:  #89*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0)) {
			next_point_bit_vector[0] |= 0x8000; next_point_bit_vector[1] |= 0x1800; /* PauseOn:  #15 #43 #44*/
		} else {
			current_point_bit_vector[2] |= 0x2000000; /* On:  #89*/
		}
		if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0))) {
			next_point_bit_vector[1] |= 0x2000; /* PauseOn:  #45*/
		} else {
			current_point_bit_vector[2] |= 0x2000000; /* On:  #89*/
		}
		if (((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0))) {
			EMIT(SIG_ID_Exception_main_trap_521);
			current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
			current_point_bit_vector[2] &= ~0x2000000; /* Off:  #89*/
		} else {
			current_point_bit_vector[2] |= 0x2000000; /* On:  #89*/
		}
	}
	_boolean(&ID_Variable_CONT_FLAG_564,0);
	_string(&ID_Variable_My_Name_565,"name");
	_StrlSampleRange(&ID_Variable_org_input_566,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_my_input_567,INITIAL_RANGE);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_568,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_568);
	_StrlSampleRange(&ID_Signal_forecast_range_569,INITIAL_RANGE);
	CLEAR_SIGNAL(SIG_ID_Signal_forecast_range_569);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_on_570);
	CLEAR_SIGNAL(SIG_ID_Signal_switch_off_571);
	CLEAR_SIGNAL(SIG_ID_Signal_R_Name_572);
	CLEAR_SIGNAL(SIG_ID_Signal_INI_PHASE_573);
	_boolean(&ID_Signal_INI_PHASE_573,1);
	EMIT(SIG_ID_Signal_INI_PHASE_573);
	current_point_bit_vector[2] |= 0x80; /* On:  #71*/
	if (IS_SIGNAL(SIG_ID_Signal_INI_PHASE_573,0)) {
		next_point_bit_vector[0] |= 0x8000000; /* PauseOn:  #27*/
	} else {
		CLEAR_SIGNAL(SIG_ID_Exception_main_trap_575);
		next_point_bit_vector[1] |= 0x80000; /* PauseOn:  #51*/
		if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_107,0)) {
			next_point_bit_vector[1] |= 0x10000; /* PauseOn:  #48*/
		} else {
			current_point_bit_vector[1] |= 0x80000; /* On:  #51*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_117,0)) {
			next_point_bit_vector[0] |= 0x10000000; /* PauseOn:  #28*/
		} else {
			current_point_bit_vector[1] |= 0x80000; /* On:  #51*/
		}
		if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_107,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_117,0))) {
			EMIT(SIG_ID_Exception_main_trap_575);
			current_point_bit_vector[1] |= 0x20000; /* On:  #49*/
			current_point_bit_vector[1] &= ~0x80000; /* Off:  #51*/
		} else {
			current_point_bit_vector[1] |= 0x80000; /* On:  #51*/
		}
	}
}

static void Point_1() {
	if (IS_SIGNAL(SIG_ID_Input_User_Quit_41,0)) {
		current_point_bit_vector[0] &= ~0xffffff84; current_point_bit_vector[1] &= ~0xf749ffff; current_point_bit_vector[2] &= ~0x27f038e; current_point_bit_vector[3] &= ~0xb8000c64; current_point_bit_vector[4] &= ~0xb071a920; current_point_bit_vector[5] &= ~0x3; /* Off:  #2 #7 #8 #9 #10 #11 #12 #13 #14 #15 #16 #17 #18 #19 #20 #21 #22 #23 #24 #25 #26 #27 #28 #29 #30 #31 #32 #33 #34 #35 #36 #37 #38 #39 #40 #41 #42 #43 #44 #45 #46 #47 #48 #51 #54 #56 #57 #58 #60 #61 #62 #63 #65 #66 #67 #71 #72 #73 #80 #81 #82 #83 #84 #85 #86 #89 #98 #101 #102 #106 #107 #123 #124 #125 #127 #133 #136 #139 #141 #143 #144 #148 #149 #150 #156 #157 #159 #160 #161*/
	} else {
		next_point_bit_vector[0] |= 0x2; /* PauseOn:  #1*/
	}
}

static void Point_2() {
	_StrlSampleRange(&ID_Signal_Mark_Wire_S_M_104,ID_Variable_output_range_442);
	EMIT(SIG_ID_Signal_Mark_Wire_S_M_104);
	EMIT(SIG_ID_Signal_ack_MD_122);
	_integer(&ID_Variable_temp_int_465,0);
	_integer(&ID_Variable_not_source_466,0);
	_integer(&ID_Variable_not_complete_flag_467,0);
	_StrlSampleIndex(&ID_Variable_temp_index_468,INITIAL_INDEX);
	_StrlSampleRange(&ID_Variable_temp_range_469,INITIAL_RANGE);
	_StrlSampleSize(&ID_Variable_complete_var_470,INITIAL_SIZE);
	CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_471);
	CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_472);
	if (_eq_integer(CHECK_MYWRITERLL(ID_InputOutput_Source_module_42),0)) {
		current_point_bit_vector[0] |= 0x20; /* On:  #5*/
	} else {
		if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_InputOutput_Source_module_42),0)) {
			current_point_bit_vector[0] |= 0x10; /* On:  #4*/
		} else {
			if ((GET_NUMBERINPUTS(ID_InputOutput_Source_module_42) > 0)) {
				_integer(&ID_Variable_not_source_466,1);
			}
			_StrlSampleSize(&ID_Variable_complete_var_470,REALCOMPUTEDATA(ID_InputOutput_Source_module_42, ID_Variable_not_source_466));
			if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_InputOutput_Source_module_42), ID_Variable_complete_var_470) > 0)) {
				_integer(&ID_Variable_not_complete_flag_467,(ID_Variable_not_complete_flag_467 - 1));
				current_point_bit_vector[0] |= 0x8; /* On:  #3*/
			} else {
				current_point_bit_vector[0] |= 0x8; /* On:  #3*/
			}
		}
	}
}

static void Point_3() {
	if ((ID_Variable_not_complete_flag_467 < 0)) {
		_StrlSampleIndex(&ID_Variable_temp_index_468,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_InputOutput_Source_module_42), ID_Variable_complete_var_470));
		SET_MARKEDWP(ID_InputOutput_Source_module_42, ID_Variable_temp_index_468);
	}
	WRITEDATA(ID_InputOutput_Source_module_42, ID_Variable_not_source_466);
	_StrlSampleIndex(&ID_Variable_temp_index_468,GETWP(ID_InputOutput_Source_module_42));
	_StrlSampleRange(&ID_Output_SOURCE_COMPUTEDSR_48,GET_MYMARKEDDATA(ID_InputOutput_Source_module_42));
	TC_UDP_TX_O_SOURCE_COMPUTEDSR(ID_Output_SOURCE_COMPUTEDSR_48); EMIT(SIG_ID_Output_SOURCE_COMPUTEDSR_48);
	current_point_bit_vector[0] |= 0x40; /* On:  #6*/
}

static void Point_4() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_471);
	current_point_bit_vector[0] |= 0x40; /* On:  #6*/
	current_point_bit_vector[0] &= ~0x8; /* Off:  #3*/
}

static void Point_5() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_471);
	current_point_bit_vector[0] |= 0x40; /* On:  #6*/
	current_point_bit_vector[0] &= ~0x8; /* Off:  #3*/
}

static void Point_6() {
	CLEAR_SIGNAL(SIG_ID_Exception_main_loop_473);
	current_point_bit_vector[4] |= 0x40000000; /* On:  #158*/
}

static void Point_7() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_104,0)) {
		EMIT(SIG_ID_Signal_switch_on_482);
		_StrlSampleRange(&ID_Variable_org_input_478,ID_Signal_Mark_Wire_S_M_104);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_480,ID_Variable_org_input_478);
		EMIT(SIG_ID_Signal_My_Sample_Range_480);
		current_point_bit_vector[4] |= 0x80; /* On:  #135*/
	} else {
		next_point_bit_vector[0] |= 0x80; /* PauseOn:  #7*/
	}
}

static void Point_8() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_104,0)) {
		EMIT(SIG_ID_Exception_main_trap_487);
		current_point_bit_vector[4] |= 0x40; /* On:  #134*/
		current_point_bit_vector[4] &= ~0x100; /* Off:  #136*/
	} else {
		next_point_bit_vector[0] |= 0x100; /* PauseOn:  #8*/
	}
}

static void Point_9() {
	_StrlSampleRange(&ID_Signal_Mark_Wire_M_M1_105,ID_Variable_output_range_492);
	EMIT(SIG_ID_Signal_Mark_Wire_M_M1_105);
	_StrlSampleRange(&ID_Signal_forecast_range_481,ID_Variable_inside_input_493);
	EMIT(SIG_ID_Signal_forecast_range_481);
	_StrlSampleRange(&ID_Variable_my_input_479,ID_Signal_forecast_range_481);
	EMIT(SIG_ID_Signal_switch_off_483);
	current_point_bit_vector[5] |= 0x2; /* On:  #161*/
}

static void Point_10() {
	CLEAR_SIGNAL(SIG_ID_Exception_main_loop_510);
	current_point_bit_vector[4] |= 0x4000; /* On:  #142*/
}

static void Point_11() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_off_483,0)) {
		current_point_bit_vector[4] |= 0x8000000; /* On:  #155*/
		current_point_bit_vector[4] &= ~0x200000; /* Off:  #149*/
	} else {
		next_point_bit_vector[0] |= 0x800; /* PauseOn:  #11*/
	}
}

static void Point_12() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0)) {
		EMIT(SIG_ID_Signal_switch_on_516);
		_StrlSampleRange(&ID_Variable_org_input_512,ID_Signal_Mark_Wire_M_M1_105);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_514,ID_Variable_org_input_512);
		EMIT(SIG_ID_Signal_My_Sample_Range_514);
		current_point_bit_vector[2] |= 0x1000000; /* On:  #88*/
	} else {
		next_point_bit_vector[0] |= 0x1000; /* PauseOn:  #12*/
	}
}

static void Point_13() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0)) {
		next_point_bit_vector[2] |= 0x80000; /* PauseOn:  #83*/
	} else {
		next_point_bit_vector[0] |= 0x2000; /* PauseOn:  #13*/
	}
}

static void Point_14() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0)) {
		EMIT(SIG_ID_Exception_main_trap_521);
		current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
		current_point_bit_vector[2] &= ~0x2000000; /* Off:  #89*/
	} else {
		next_point_bit_vector[0] |= 0x4000; /* PauseOn:  #14*/
	}
}

static void Point_15() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0)) {
		next_point_bit_vector[1] |= 0x400; /* PauseOn:  #42*/
	} else {
		next_point_bit_vector[0] |= 0x8000; /* PauseOn:  #15*/
	}
}

static void Point_16() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0)) {
		EMIT(SIG_ID_Exception_main_trap_521);
		current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
		current_point_bit_vector[2] &= ~0x2000000; /* Off:  #89*/
	} else {
		next_point_bit_vector[0] |= 0x10000; /* PauseOn:  #16*/
	}
}

static void Point_17() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0)) {
		EMIT(SIG_ID_Exception_main_trap_521);
		current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
		current_point_bit_vector[2] &= ~0x2000000; /* Off:  #89*/
	} else {
		next_point_bit_vector[0] |= 0x20000; /* PauseOn:  #17*/
	}
}

static void Point_18() {
	_StrlSampleRange(&ID_Signal_Mark_Wire_M_S1_107,ID_Variable_output_range_524);
	EMIT(SIG_ID_Signal_Mark_Wire_M_S1_107);
	_StrlSampleRange(&ID_Signal_forecast_range_515,ID_Variable_inside_input_525);
	EMIT(SIG_ID_Signal_forecast_range_515);
	_StrlSampleRange(&ID_Variable_my_input_513,ID_Signal_forecast_range_515);
	EMIT(SIG_ID_Signal_switch_off_517);
	current_point_bit_vector[4] |= 0x400000; /* On:  #150*/
}

static void Point_19() {
	CLEAR_SIGNAL(SIG_ID_Exception_main_loop_542);
	current_point_bit_vector[3] |= 0x200; /* On:  #105*/
}

static void Point_20() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_off_517,0)) {
		current_point_bit_vector[4] |= 0x10; /* On:  #132*/
		current_point_bit_vector[3] &= ~0x10000000; /* Off:  #124*/
	} else {
		next_point_bit_vector[0] |= 0x100000; /* PauseOn:  #20*/
	}
}

static void Point_21() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_107,0)) {
		EMIT(SIG_ID_Signal_switch_on_550);
		_StrlSampleRange(&ID_Variable_org_input_546,ID_Signal_Mark_Wire_M_S1_107);
		if (ID_Variable_CONT_FLAG_544) {
			_StrlSampleRange(&ID_Signal_My_Sample_Range_548,ID_Variable_my_input_547);
			EMIT(SIG_ID_Signal_My_Sample_Range_548);
		} else {
			_StrlSampleRange(&ID_Signal_My_Sample_Range_548,ID_Variable_org_input_546);
			EMIT(SIG_ID_Signal_My_Sample_Range_548);
		}
		_StrlSampleRange(&ID_Variable_input_range_553,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_554,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_inside_input_555,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_556,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_evaluatedWP_557,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_558,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_559,0);
		_integer(&ID_Variable_sameindex_560,0);
		_integer(&ID_Variable_maxOutSize_561,0);
		_integer(&ID_Variable_temp_int_562,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_563,INITIAL_UNSIGNEDINT);
		current_point_bit_vector[0] |= 0x400000; /* On:  #22*/
	} else {
		next_point_bit_vector[0] |= 0x200000; /* PauseOn:  #21*/
	}
}

static void Point_22() {
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_548,0)) {
		_StrlSampleRange(&ID_Variable_input_range_553,ID_Signal_My_Sample_Range_548);
		_StrlSampleRange(&ID_Variable_output_range_554,DOWNCASTS(ID_Variable_input_range_553, ID_InputOutput_Scopesink_module_46));
		_StrlSampleIndex(&ID_Variable_pendingWP_556,GETMARKEDWP(ID_InputOutput_Scopesink_module_46));
		_StrlSampleIndex(&ID_Variable_evaluatedWP_557,GETINDEX(ID_Variable_output_range_554));
		_StrlSampleIndex(&ID_Variable_desiredWP_558,ADD_INDEX_SIZE(ID_Variable_output_range_554));
		_integer(&ID_Variable_sameindex_560,SUBTRACT_A_B(ID_Variable_evaluatedWP_557, ID_Variable_pendingWP_556));
		_integer(&ID_Variable_maxOutSize_561,GETMAXOUTSIZE(ID_InputOutput_Scopesink_module_46));
		if ((ID_Variable_sameindex_560 < 0)) {
			_integer(&ID_Variable_temp_int_562,error_exit(1));
		} else {
			if ((ID_Variable_sameindex_560 > 0)) {
				_integer(&ID_Variable_requestSize_559,SUBTRACT_A_B(ID_Variable_desiredWP_558, ID_Variable_evaluatedWP_557));
				_StrlSampleIndex(&ID_Variable_pendingWP_556,ID_Variable_evaluatedWP_557);
			} else {
				_integer(&ID_Variable_requestSize_559,SUBTRACT_A_B(ID_Variable_desiredWP_558, ID_Variable_pendingWP_556));
			}
		}
		if ((ID_Variable_requestSize_559 > ID_Variable_maxOutSize_561)) {
			_integer(&ID_Variable_requestSize_559,ID_Variable_maxOutSize_561);
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_563,GET_OUTPUTSIZE(ID_InputOutput_Scopesink_module_46));
		_integer(&ID_Variable_requestSize_559,ROUNDOWN_SIZE(ID_Variable_requestSize_559, ID_Variable_temp_unsigned_563));
		_StrlSampleRange(&ID_Variable_output_range_554,SET_SAMPLERANGE(ID_Variable_pendingWP_556, ID_Variable_requestSize_559));
		_StrlSampleRange(&ID_Variable_inside_input_555,FORECASTS(ID_Variable_output_range_554, ID_InputOutput_Scopesink_module_46));
		_integer(&ID_Variable_temp_int_562,REAL_FIT_RANGE(ID_Variable_pendingWP_556, ID_Variable_requestSize_559, ID_Variable_inside_input_555, ID_InputOutput_Scopesink_module_46));
		LOCALINCAWAITTICK(ID_InputOutput_Scopesink_module_46);
		next_point_bit_vector[0] |= 0x800000; /* PauseOn:  #23*/
	} else {
		next_point_bit_vector[0] |= 0x400000; /* PauseOn:  #22*/
	}
}

static void Point_23() {
	_StrlSampleRange(&ID_Signal_forecast_range_549,ID_Variable_inside_input_555);
	EMIT(SIG_ID_Signal_forecast_range_549);
	_StrlSampleRange(&ID_Variable_my_input_547,ID_Signal_forecast_range_549);
	EMIT(SIG_ID_Signal_switch_off_551);
	if (ID_Variable_CONT_FLAG_544) {
		current_point_bit_vector[3] |= 0x40000000; /* On:  #126*/
	} else {
		current_point_bit_vector[3] |= 0x20000000; /* On:  #125*/
	}
}

static void Point_24() {
	_StrlSampleRange(&ID_Signal_Ack_Wire_M_S1_116,ID_Variable_my_input_547);
	EMIT(SIG_ID_Signal_Ack_Wire_M_S1_116);
	next_point_bit_vector[0] |= 0x200000; /* PauseOn:  #21*/
}

static void Point_25() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_550,0)) {
		current_point_bit_vector[1] |= 0x8000; /* On:  #47*/
		next_point_bit_vector[0] |= 0x4000000; /* PauseOn:  #26*/
	} else {
		next_point_bit_vector[0] |= 0x2000000; /* PauseOn:  #25*/
	}
}

static void Point_26() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_off_551,0)) {
		current_point_bit_vector[1] &= ~0x8000; /* Off:  #47*/
		if (IS_SIGNAL(SIG_ID_Signal_switch_on_550,0)) {
			EMIT(SIG_ID_Signal_Clock_Wire_M_S1_120);
			next_point_bit_vector[0] |= 0x4000000; next_point_bit_vector[1] |= 0x8000; /* PauseOn:  #26 #47*/
		} else {
			next_point_bit_vector[0] |= 0x2000000; /* PauseOn:  #25*/
		}
	} else {
		next_point_bit_vector[0] |= 0x4000000; /* PauseOn:  #26*/
	}
}

static void Point_27() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_107,0)) {
		EMIT(SIG_ID_Signal_switch_on_570);
		_StrlSampleRange(&ID_Variable_org_input_566,ID_Signal_Mark_Wire_M_S1_107);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_568,ID_Variable_org_input_566);
		EMIT(SIG_ID_Signal_My_Sample_Range_568);
		current_point_bit_vector[1] |= 0x40000; /* On:  #50*/
	} else {
		next_point_bit_vector[0] |= 0x8000000; /* PauseOn:  #27*/
	}
}

static void Point_28() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_107,0)) {
		EMIT(SIG_ID_Exception_main_trap_575);
		current_point_bit_vector[1] |= 0x20000; /* On:  #49*/
		current_point_bit_vector[1] &= ~0x80000; /* Off:  #51*/
	} else {
		next_point_bit_vector[0] |= 0x10000000; /* PauseOn:  #28*/
	}
}

static void Point_29() {
	_StrlSampleRange(&ID_Signal_Mark_Wire_M_S2_108,ID_Variable_output_range_577);
	EMIT(SIG_ID_Signal_Mark_Wire_M_S2_108);
	_StrlSampleRange(&ID_Signal_forecast_range_569,ID_Variable_inside_input_578);
	EMIT(SIG_ID_Signal_forecast_range_569);
	_StrlSampleRange(&ID_Variable_my_input_567,ID_Signal_forecast_range_569);
	EMIT(SIG_ID_Signal_switch_off_571);
	current_point_bit_vector[3] |= 0x80000000; /* On:  #127*/
}

static void Point_30() {
	CLEAR_SIGNAL(SIG_ID_Exception_main_loop_595);
	current_point_bit_vector[1] |= 0x8000000; /* On:  #59*/
}

static void Point_31() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_off_571,0)) {
		current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
		current_point_bit_vector[2] &= ~0x100; /* Off:  #72*/
	} else {
		next_point_bit_vector[0] |= 0x80000000; /* PauseOn:  #31*/
	}
}

static void Point_32() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S2_108,0)) {
		EMIT(SIG_ID_Signal_switch_on_601);
		_StrlSampleRange(&ID_Variable_org_input_597,ID_Signal_Mark_Wire_M_S2_108);
		CLEAR_SIGNAL(SIG_ID_Exception_compute_loop_604);
		if (ID_Variable_CONT_FLAG_596) {
			_StrlSampleRange(&ID_Signal_My_Sample_Range_599,ID_Variable_my_input_598);
			EMIT(SIG_ID_Signal_My_Sample_Range_599);
		} else {
			_StrlSampleRange(&ID_Signal_My_Sample_Range_599,ID_Variable_org_input_597);
			EMIT(SIG_ID_Signal_My_Sample_Range_599);
		}
		_StrlSampleRange(&ID_Variable_input_range_605,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_606,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_inside_input_607,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_608,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_evaluatedWP_609,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_610,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_611,0);
		_integer(&ID_Variable_sameindex_612,0);
		_integer(&ID_Variable_maxOutSize_613,0);
		_integer(&ID_Variable_temp_int_614,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_615,INITIAL_UNSIGNEDINT);
		current_point_bit_vector[1] |= 0x2; /* On:  #33*/
	} else {
		next_point_bit_vector[1] |= 0x1; /* PauseOn:  #32*/
	}
}

static void Point_33() {
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_599,0)) {
		_StrlSampleRange(&ID_Variable_input_range_605,ID_Signal_My_Sample_Range_599);
		_StrlSampleRange(&ID_Variable_output_range_606,DOWNCASTS(ID_Variable_input_range_605, ID_InputOutput_Sink_module_47));
		_StrlSampleIndex(&ID_Variable_pendingWP_608,GETMARKEDWP(ID_InputOutput_Sink_module_47));
		_StrlSampleIndex(&ID_Variable_evaluatedWP_609,GETINDEX(ID_Variable_output_range_606));
		_StrlSampleIndex(&ID_Variable_desiredWP_610,ADD_INDEX_SIZE(ID_Variable_output_range_606));
		_integer(&ID_Variable_sameindex_612,SUBTRACT_A_B(ID_Variable_evaluatedWP_609, ID_Variable_pendingWP_608));
		_integer(&ID_Variable_maxOutSize_613,GETMAXOUTSIZE(ID_InputOutput_Sink_module_47));
		if ((ID_Variable_sameindex_612 < 0)) {
			_integer(&ID_Variable_temp_int_614,error_exit(1));
		} else {
			if ((ID_Variable_sameindex_612 > 0)) {
				_integer(&ID_Variable_requestSize_611,SUBTRACT_A_B(ID_Variable_desiredWP_610, ID_Variable_evaluatedWP_609));
				_StrlSampleIndex(&ID_Variable_pendingWP_608,ID_Variable_evaluatedWP_609);
			} else {
				_integer(&ID_Variable_requestSize_611,SUBTRACT_A_B(ID_Variable_desiredWP_610, ID_Variable_pendingWP_608));
			}
		}
		if ((ID_Variable_requestSize_611 > ID_Variable_maxOutSize_613)) {
			_integer(&ID_Variable_requestSize_611,ID_Variable_maxOutSize_613);
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_615,GET_OUTPUTSIZE(ID_InputOutput_Sink_module_47));
		_integer(&ID_Variable_requestSize_611,ROUNDOWN_SIZE(ID_Variable_requestSize_611, ID_Variable_temp_unsigned_615));
		_StrlSampleRange(&ID_Variable_output_range_606,SET_SAMPLERANGE(ID_Variable_pendingWP_608, ID_Variable_requestSize_611));
		_StrlSampleRange(&ID_Variable_inside_input_607,FORECASTS(ID_Variable_output_range_606, ID_InputOutput_Sink_module_47));
		_integer(&ID_Variable_temp_int_614,REAL_FIT_RANGE(ID_Variable_pendingWP_608, ID_Variable_requestSize_611, ID_Variable_inside_input_607, ID_InputOutput_Sink_module_47));
		LOCALINCAWAITTICK(ID_InputOutput_Sink_module_47);
		next_point_bit_vector[1] |= 0x4; /* PauseOn:  #34*/
	} else {
		next_point_bit_vector[1] |= 0x2; /* PauseOn:  #33*/
	}
}

static void Point_34() {
	_StrlSampleRange(&ID_Signal_forecast_range_600,ID_Variable_inside_input_607);
	EMIT(SIG_ID_Signal_forecast_range_600);
	_StrlSampleRange(&ID_Variable_my_input_598,ID_Signal_forecast_range_600);
	EMIT(SIG_ID_Signal_switch_off_602);
	if (ID_Variable_CONT_FLAG_596) {
		current_point_bit_vector[2] |= 0x400; /* On:  #74*/
	} else {
		current_point_bit_vector[2] |= 0x200; /* On:  #73*/
	}
}

static void Point_35() {
	if ((CHECKSAMPLESIZE(ID_Variable_org_input_597, ID_Variable_my_input_598) >= 0)) {
		_StrlSampleRange(&ID_Variable_my_input_598,UPDATESAMPLE(ID_Variable_my_input_598));
		_boolean(&ID_Variable_CONT_FLAG_596,1);
		if (ID_Variable_CONT_FLAG_596) {
			_StrlSampleRange(&ID_Signal_My_Sample_Range_599,ID_Variable_my_input_598);
			EMIT(SIG_ID_Signal_My_Sample_Range_599);
		} else {
			_StrlSampleRange(&ID_Signal_My_Sample_Range_599,ID_Variable_org_input_597);
			EMIT(SIG_ID_Signal_My_Sample_Range_599);
		}
		_StrlSampleRange(&ID_Variable_input_range_605,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_606,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_inside_input_607,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_608,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_evaluatedWP_609,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_610,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_611,0);
		_integer(&ID_Variable_sameindex_612,0);
		_integer(&ID_Variable_maxOutSize_613,0);
		_integer(&ID_Variable_temp_int_614,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_615,INITIAL_UNSIGNEDINT);
		if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_599,0)) {
			_StrlSampleRange(&ID_Variable_input_range_605,ID_Signal_My_Sample_Range_599);
			_StrlSampleRange(&ID_Variable_output_range_606,DOWNCASTS(ID_Variable_input_range_605, ID_InputOutput_Sink_module_47));
			_StrlSampleIndex(&ID_Variable_pendingWP_608,GETMARKEDWP(ID_InputOutput_Sink_module_47));
			_StrlSampleIndex(&ID_Variable_evaluatedWP_609,GETINDEX(ID_Variable_output_range_606));
			_StrlSampleIndex(&ID_Variable_desiredWP_610,ADD_INDEX_SIZE(ID_Variable_output_range_606));
			_integer(&ID_Variable_sameindex_612,SUBTRACT_A_B(ID_Variable_evaluatedWP_609, ID_Variable_pendingWP_608));
			_integer(&ID_Variable_maxOutSize_613,GETMAXOUTSIZE(ID_InputOutput_Sink_module_47));
			if ((ID_Variable_sameindex_612 < 0)) {
				_integer(&ID_Variable_temp_int_614,error_exit(1));
			} else {
				if ((ID_Variable_sameindex_612 > 0)) {
					_integer(&ID_Variable_requestSize_611,SUBTRACT_A_B(ID_Variable_desiredWP_610, ID_Variable_evaluatedWP_609));
					_StrlSampleIndex(&ID_Variable_pendingWP_608,ID_Variable_evaluatedWP_609);
				} else {
					_integer(&ID_Variable_requestSize_611,SUBTRACT_A_B(ID_Variable_desiredWP_610, ID_Variable_pendingWP_608));
				}
			}
			if ((ID_Variable_requestSize_611 > ID_Variable_maxOutSize_613)) {
				_integer(&ID_Variable_requestSize_611,ID_Variable_maxOutSize_613);
			}
			_UnsignedInt(&ID_Variable_temp_unsigned_615,GET_OUTPUTSIZE(ID_InputOutput_Sink_module_47));
			_integer(&ID_Variable_requestSize_611,ROUNDOWN_SIZE(ID_Variable_requestSize_611, ID_Variable_temp_unsigned_615));
			_StrlSampleRange(&ID_Variable_output_range_606,SET_SAMPLERANGE(ID_Variable_pendingWP_608, ID_Variable_requestSize_611));
			_StrlSampleRange(&ID_Variable_inside_input_607,FORECASTS(ID_Variable_output_range_606, ID_InputOutput_Sink_module_47));
			_integer(&ID_Variable_temp_int_614,REAL_FIT_RANGE(ID_Variable_pendingWP_608, ID_Variable_requestSize_611, ID_Variable_inside_input_607, ID_InputOutput_Sink_module_47));
			LOCALINCAWAITTICK(ID_InputOutput_Sink_module_47);
			next_point_bit_vector[1] |= 0x4; /* PauseOn:  #34*/
		} else {
			next_point_bit_vector[1] |= 0x2; /* PauseOn:  #33*/
		}
	} else {
		_boolean(&ID_Variable_CONT_FLAG_596,0);
		EMIT(SIG_ID_Exception_compute_loop_604);
		_StrlSampleRange(&ID_Signal_Ack_Wire_M_S2_117,ID_Variable_my_input_598);
		EMIT(SIG_ID_Signal_Ack_Wire_M_S2_117);
		next_point_bit_vector[1] |= 0x1; /* PauseOn:  #32*/
		next_point_bit_vector[1] &= ~0xe; next_point_bit_vector[2] &= ~0x200; /* PauseOff:  #33 #34 #35 #73*/
	}
}

static void Point_36() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_601,0)) {
		current_point_bit_vector[1] |= 0x2000000; /* On:  #57*/
		next_point_bit_vector[1] |= 0x20; /* PauseOn:  #37*/
	} else {
		next_point_bit_vector[1] |= 0x10; /* PauseOn:  #36*/
	}
}

static void Point_37() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_off_602,0)) {
		current_point_bit_vector[1] &= ~0x2000000; /* Off:  #57*/
		if (IS_SIGNAL(SIG_ID_Signal_switch_on_601,0)) {
			EMIT(SIG_ID_Signal_Clock_Wire_M_S2_121);
			next_point_bit_vector[1] |= 0x2000020; /* PauseOn:  #37 #57*/
		} else {
			next_point_bit_vector[1] |= 0x10; /* PauseOn:  #36*/
		}
	} else {
		next_point_bit_vector[1] |= 0x20; /* PauseOn:  #37*/
	}
}

static void Point_38() {
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_104,0)) {
		EMIT(SIG_ID_Signal_start_alarm_100);
		_UnsignedLong(&ID_Variable_prev_outsample_90,NEWGETWP(ID_Variable_nameofsink_87));
		current_point_bit_vector[1] |= 0x40000000; /* On:  #62*/
	} else {
		next_point_bit_vector[1] |= 0x40; /* PauseOn:  #38*/
	}
}

static void Point_39() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) {
		STOP_PERF_GRAPH();
		RUN_GUI_MAIN();
		START_PERF_GRAPH();
		next_point_bit_vector[1] |= 0x80; /* PauseOn:  #39*/
	} else {
		next_point_bit_vector[1] |= 0x80; /* PauseOn:  #39*/
	}
}

static void Point_40() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) {
		next_point_bit_vector[2] |= 0x10000; /* PauseOn:  #80*/
	} else {
		next_point_bit_vector[1] |= 0x100; /* PauseOn:  #40*/
	}
}

static void Point_41() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) {
		EMIT(SIG_ID_Exception_main_trap_521);
		current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
		current_point_bit_vector[2] &= ~0x2000000; /* Off:  #89*/
	} else {
		next_point_bit_vector[1] |= 0x200; /* PauseOn:  #41*/
	}
}

static void Point_42() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) {
		EMIT(SIG_ID_Exception_main_trap_521);
		current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
		current_point_bit_vector[2] &= ~0x2000000; /* Off:  #89*/
	} else {
		next_point_bit_vector[1] |= 0x400; /* PauseOn:  #42*/
	}
}

static void Point_43() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) {
		next_point_bit_vector[0] |= 0x10000; /* PauseOn:  #16*/
	} else {
		next_point_bit_vector[1] |= 0x800; /* PauseOn:  #43*/
	}
}

static void Point_44() {
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0))) {
		EMIT(SIG_ID_Exception_main_trap_521);
		current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
		current_point_bit_vector[2] &= ~0x2000000; /* Off:  #89*/
		next_point_bit_vector[1] |= 0x1000; /* PauseOn:  #44*/
	} else {
		next_point_bit_vector[1] |= 0x1000; /* PauseOn:  #44*/
	}
}

static void Point_45() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) {
		EMIT(SIG_ID_Exception_main_trap_521);
		current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
		current_point_bit_vector[2] &= ~0x2000000; /* Off:  #89*/
	} else {
		next_point_bit_vector[1] |= 0x2000; /* PauseOn:  #45*/
	}
}

static void Point_46() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) {
		EMIT(SIG_ID_Exception_main_trap_522);
		current_point_bit_vector[3] |= 0x8; /* On:  #99*/
		current_point_bit_vector[3] &= ~0x40; /* Off:  #102*/
	} else {
		next_point_bit_vector[1] |= 0x4000; /* PauseOn:  #46*/
	}
}

static void Point_47() {
	EMIT(SIG_ID_Signal_Clock_Wire_M_S1_120);
	next_point_bit_vector[1] |= 0x8000; /* PauseOn:  #47*/
}

static void Point_48() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_117,0)) {
		EMIT(SIG_ID_Exception_main_trap_575);
		current_point_bit_vector[1] |= 0x20000; /* On:  #49*/
		current_point_bit_vector[1] &= ~0x80000; /* Off:  #51*/
	} else {
		next_point_bit_vector[1] |= 0x10000; /* PauseOn:  #48*/
	}
}

static void Point_49() {
	EMIT(SIG_ID_Signal_switch_on_570);
	_StrlSampleRange(&ID_Variable_org_input_566,ID_Signal_Mark_Wire_M_S1_107);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_568,ID_Variable_org_input_566);
	EMIT(SIG_ID_Signal_My_Sample_Range_568);
	current_point_bit_vector[1] |= 0x40000; /* On:  #50*/
	next_point_bit_vector[0] &= ~0x10000000; next_point_bit_vector[1] &= ~0x90000; /* PauseOff:  #28 #48 #51*/
}

static void Point_50() {
	CLEAR_SIGNAL(SIG_ID_Exception_compute_loop_574);
	if (ID_Variable_CONT_FLAG_564) {
		next_point_bit_vector[1] |= 0x400000; /* PauseOn:  #54*/
	} else {
		current_point_bit_vector[1] |= 0x800000; /* On:  #55*/
	}
}

static void Point_51() {
	if (next_point_bit_vector[0]&0x10000000) return;
	 if (next_point_bit_vector[1]&0x90000) return;
	 /* isPauseOn:  #28 #48 #51*/
	next_point_bit_vector[1] |= 0x80000; /* PauseOn:  #51*/
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_117,0)) {
		next_point_bit_vector[0] |= 0x10000000; /* PauseOn:  #28*/
	} else {
		current_point_bit_vector[1] |= 0x100000; /* On:  #52*/
	}
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_107,0)) {
		next_point_bit_vector[1] |= 0x10000; /* PauseOn:  #48*/
	} else {
		current_point_bit_vector[1] |= 0x100000; /* On:  #52*/
	}
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_107,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_117,0))) {
		current_point_bit_vector[1] |= 0x200000; /* On:  #53*/
	} else {
		current_point_bit_vector[1] |= 0x100000; /* On:  #52*/
	}
}

static void Point_52() {
	if (next_point_bit_vector[0]&0x10000000) return;
	 if (next_point_bit_vector[1]&0x10000) return;
	 /* isPauseOn:  #28 #48*/
}

static void Point_53() {
	EMIT(SIG_ID_Exception_main_trap_575);
	current_point_bit_vector[1] &= ~0x100000; /* Off:  #52*/
}

static void Point_54() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_117,0)) {
		_StrlSampleRange(&ID_Signal_My_Sample_Range_568,ID_Variable_my_input_567);
		EMIT(SIG_ID_Signal_My_Sample_Range_568);
		current_point_bit_vector[1] |= 0x800000; /* On:  #55*/
	} else {
		next_point_bit_vector[1] |= 0x400000; /* PauseOn:  #54*/
	}
}

static void Point_55() {
	_StrlSampleRange(&ID_Variable_input_range_576,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_output_range_577,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_inside_input_578,INITIAL_RANGE);
	_StrlSampleIndex(&ID_Variable_pendingWP_579,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_evaluatedWP_580,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_desiredWP_581,INITIAL_INDEX);
	_integer(&ID_Variable_requestSize_582,0);
	_integer(&ID_Variable_sameindex_583,0);
	_integer(&ID_Variable_maxOutSize_584,0);
	_integer(&ID_Variable_temp_int_585,0);
	_UnsignedInt(&ID_Variable_temp_unsigned_586,INITIAL_UNSIGNEDINT);
	current_point_bit_vector[1] |= 0x1000000; /* On:  #56*/
}

static void Point_56() {
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_568,0)) {
		_StrlSampleRange(&ID_Variable_input_range_576,ID_Signal_My_Sample_Range_568);
		_StrlSampleRange(&ID_Variable_output_range_577,DOWNCASTS(ID_Variable_input_range_576, ID_InputOutput_Summer_module_45));
		_StrlSampleIndex(&ID_Variable_pendingWP_579,GETMARKEDWP(ID_InputOutput_Summer_module_45));
		_StrlSampleIndex(&ID_Variable_evaluatedWP_580,GETINDEX(ID_Variable_output_range_577));
		_StrlSampleIndex(&ID_Variable_desiredWP_581,ADD_INDEX_SIZE(ID_Variable_output_range_577));
		_integer(&ID_Variable_sameindex_583,SUBTRACT_A_B(ID_Variable_evaluatedWP_580, ID_Variable_pendingWP_579));
		_integer(&ID_Variable_maxOutSize_584,GETMAXOUTSIZE(ID_InputOutput_Summer_module_45));
		if ((ID_Variable_sameindex_583 < 0)) {
			_integer(&ID_Variable_temp_int_585,error_exit(1));
		} else {
			if ((ID_Variable_sameindex_583 > 0)) {
				_integer(&ID_Variable_requestSize_582,SUBTRACT_A_B(ID_Variable_desiredWP_581, ID_Variable_evaluatedWP_580));
				_StrlSampleIndex(&ID_Variable_pendingWP_579,ID_Variable_evaluatedWP_580);
			} else {
				_integer(&ID_Variable_requestSize_582,SUBTRACT_A_B(ID_Variable_desiredWP_581, ID_Variable_pendingWP_579));
			}
		}
		if ((ID_Variable_requestSize_582 > ID_Variable_maxOutSize_584)) {
			_integer(&ID_Variable_requestSize_582,ID_Variable_maxOutSize_584);
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_586,GET_OUTPUTSIZE(ID_InputOutput_Summer_module_45));
		_integer(&ID_Variable_requestSize_582,ROUNDOWN_SIZE(ID_Variable_requestSize_582, ID_Variable_temp_unsigned_586));
		_StrlSampleRange(&ID_Variable_output_range_577,SET_SAMPLERANGE(ID_Variable_pendingWP_579, ID_Variable_requestSize_582));
		_StrlSampleRange(&ID_Variable_inside_input_578,FORECASTS(ID_Variable_output_range_577, ID_InputOutput_Summer_module_45));
		_integer(&ID_Variable_temp_int_585,REAL_FIT_RANGE(ID_Variable_pendingWP_579, ID_Variable_requestSize_582, ID_Variable_inside_input_578, ID_InputOutput_Summer_module_45));
		LOCALINCAWAITTICK(ID_InputOutput_Summer_module_45);
		next_point_bit_vector[0] |= 0x20000000; /* PauseOn:  #29*/
	} else {
		next_point_bit_vector[1] |= 0x1000000; /* PauseOn:  #56*/
	}
}

static void Point_57() {
	EMIT(SIG_ID_Signal_Clock_Wire_M_S2_121);
	next_point_bit_vector[1] |= 0x2000000; /* PauseOn:  #57*/
}

static void Point_58() {
	if (IS_SIGNAL(SIG_ID_Signal_start_alarm_100,0)) {
		_UnsignedLL(&ID_Variable_this_time_93,GET_TIMESTAMP());
		CLEAR_SIGNAL(SIG_ID_Exception_trap_time_128);
		current_point_bit_vector[1] &= ~0x20000000; /* Off:  #61*/
		next_point_bit_vector[1] |= 0x4000000; /* PauseOn:  #58*/
		if ((ELAPSE_TIME(ID_Variable_this_time_93, ID_Variable_dtsec_98) > 0)) {
			EMIT(SIG_ID_Signal_end_alarm_101);
			EMIT(SIG_ID_Exception_trap_time_128);
			next_point_bit_vector[1] &= ~0x20000000; /* PauseOff:  #61*/
		} else {
			next_point_bit_vector[1] |= 0x20000000; /* PauseOn:  #61*/
		}
	} else {
		next_point_bit_vector[1] |= 0x4000000; /* PauseOn:  #58*/
	}
}

static void Point_59() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_M_S2_121,0)) {
		next_point_bit_vector[1] |= 0x8000000; /* PauseOn:  #59*/
	} else {
		next_point_bit_vector[1] |= 0x10000000; next_point_bit_vector[2] |= 0x8; /* PauseOn:  #60 #67*/
	}
}

static void Point_60() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_M_S2_121,0)) {
		next_point_bit_vector[2] |= current_point_bit_vector[2] & 0x8; current_point_bit_vector[2] &= ~0x8; /* Suspend:  #67*/
		next_point_bit_vector[1] |= 0x10000000; /* PauseOn:  #60*/
	} else {
		next_point_bit_vector[1] |= 0x10000000; /* PauseOn:  #60*/
	}
}

static void Point_61() {
	if ((ELAPSE_TIME(ID_Variable_this_time_93, ID_Variable_dtsec_98) > 0)) {
		EMIT(SIG_ID_Signal_end_alarm_101);
		EMIT(SIG_ID_Exception_trap_time_128);
	} else {
		next_point_bit_vector[1] |= 0x20000000; /* PauseOn:  #61*/
	}
}

static void Point_62() {
	if (IS_SIGNAL(SIG_ID_Signal_end_alarm_101,0)) {
		_UnsignedLong(&ID_Variable_this_outsample_91,NEWGETWP(ID_Variable_nameofsink_87));
		_UnsignedLL(&ID_Variable_skip_sample_94,EVAL_TS_TM(ID_Variable_infq_95, ID_Variable_outfq_96, ID_Variable_dtsec_98, ID_Variable_this_outsample_91, ID_Variable_prev_outsample_90));
		current_point_bit_vector[1] |= 0x80000000; current_point_bit_vector[2] |= 0x1; /* On:  #63 #64*/
	} else {
		next_point_bit_vector[1] |= 0x40000000; /* PauseOn:  #62*/
	}
}

static void Point_63() {
	if (IS_SIGNAL(SIG_ID_Signal_ack_MD_122,0)) {
		current_point_bit_vector[2] &= ~0x7; /* Off:  #64 #65 #66*/
		next_point_bit_vector[1] |= 0x40; /* PauseOn:  #38*/
	} else {
		next_point_bit_vector[1] |= 0x80000000; /* PauseOn:  #63*/
	}
}

static void Point_64() {
	if ((CMPULL(ID_Variable_skip_sample_94, INITIAL_UNSIGNEDLL) > 0)) {
		current_point_bit_vector[2] |= 0x4; /* On:  #66*/
	} else {
		current_point_bit_vector[2] |= 0x2; /* On:  #65*/
	}
}

static void Point_65() {
	_UnsignedLL(&ID_Signal_Missed_Deadline_103,INITIAL_UNSIGNEDLL);
	EMIT(SIG_ID_Signal_Missed_Deadline_103);
	next_point_bit_vector[2] |= 0x2; /* PauseOn:  #65*/
}

static void Point_66() {
	_UnsignedLL(&ID_Signal_Missed_Deadline_103,ID_Variable_skip_sample_94);
	EMIT(SIG_ID_Signal_Missed_Deadline_103);
	next_point_bit_vector[2] |= 0x4; /* PauseOn:  #66*/
}

static void Point_67() {
	EMIT(SIG_ID_Exception_main_loop_595);
	EMIT(SIG_ID_Signal_Compute_Wire_M_S2_112);
	next_point_bit_vector[1] &= ~0x10000000; next_point_bit_vector[2] &= ~0x8; /* PauseOff:  #60 #67*/
	if ((CHECKSAMPLESIZE(ID_Variable_org_input_566, ID_Variable_my_input_567) >= 0)) {
		current_point_bit_vector[2] |= 0x40; /* On:  #70*/
	} else {
		_boolean(&ID_Variable_CONT_FLAG_564,0);
		EMIT(SIG_ID_Exception_compute_loop_574);
		_StrlSampleRange(&ID_Signal_Ack_Wire_M_M2_115,ID_Variable_my_input_567);
		EMIT(SIG_ID_Signal_Ack_Wire_M_M2_115);
		next_point_bit_vector[0] &= ~0x60000000; next_point_bit_vector[1] &= ~0x11400000; next_point_bit_vector[2] &= ~0x8; next_point_bit_vector[3] &= ~0x80000000; /* PauseOff:  #29 #30 #54 #56 #60 #67 #127*/
		if (IS_SIGNAL(SIG_ID_Signal_INI_PHASE_573,0)) {
			next_point_bit_vector[0] |= 0x8000000; /* PauseOn:  #27*/
		} else {
			CLEAR_SIGNAL(SIG_ID_Exception_main_trap_575);
			next_point_bit_vector[1] |= 0x80000; /* PauseOn:  #51*/
			if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_117,0)) {
				next_point_bit_vector[0] |= 0x10000000; /* PauseOn:  #28*/
			} else {
				current_point_bit_vector[2] |= 0x10; /* On:  #68*/
			}
			if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_107,0)) {
				next_point_bit_vector[1] |= 0x10000; /* PauseOn:  #48*/
			} else {
				current_point_bit_vector[2] |= 0x10; /* On:  #68*/
			}
			if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_S1_107,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S2_117,0))) {
				current_point_bit_vector[2] |= 0x20; /* On:  #69*/
			} else {
				current_point_bit_vector[2] |= 0x10; /* On:  #68*/
			}
		}
	}
}

static void Point_68() {
	if (next_point_bit_vector[0]&0x10000000) return;
	 if (next_point_bit_vector[1]&0x10000) return;
	 /* isPauseOn:  #28 #48*/
}

static void Point_69() {
	EMIT(SIG_ID_Exception_main_trap_575);
	EMIT(SIG_ID_Signal_switch_on_570);
	_StrlSampleRange(&ID_Variable_org_input_566,ID_Signal_Mark_Wire_M_S1_107);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_568,ID_Variable_org_input_566);
	EMIT(SIG_ID_Signal_My_Sample_Range_568);
	CLEAR_SIGNAL(SIG_ID_Exception_compute_loop_574);
	current_point_bit_vector[2] &= ~0x10; /* Off:  #68*/
	next_point_bit_vector[0] &= ~0x10000000; next_point_bit_vector[1] &= ~0x90000; /* PauseOff:  #28 #48 #51*/
	if (ID_Variable_CONT_FLAG_564) {
		next_point_bit_vector[1] |= 0x400000; /* PauseOn:  #54*/
	} else {
		_StrlSampleRange(&ID_Variable_input_range_576,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_577,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_inside_input_578,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_579,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_evaluatedWP_580,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_581,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_582,0);
		_integer(&ID_Variable_sameindex_583,0);
		_integer(&ID_Variable_maxOutSize_584,0);
		_integer(&ID_Variable_temp_int_585,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_586,INITIAL_UNSIGNEDINT);
		if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_568,0)) {
			_StrlSampleRange(&ID_Variable_input_range_576,ID_Signal_My_Sample_Range_568);
			_StrlSampleRange(&ID_Variable_output_range_577,DOWNCASTS(ID_Variable_input_range_576, ID_InputOutput_Summer_module_45));
			_StrlSampleIndex(&ID_Variable_pendingWP_579,GETMARKEDWP(ID_InputOutput_Summer_module_45));
			_StrlSampleIndex(&ID_Variable_evaluatedWP_580,GETINDEX(ID_Variable_output_range_577));
			_StrlSampleIndex(&ID_Variable_desiredWP_581,ADD_INDEX_SIZE(ID_Variable_output_range_577));
			_integer(&ID_Variable_sameindex_583,SUBTRACT_A_B(ID_Variable_evaluatedWP_580, ID_Variable_pendingWP_579));
			_integer(&ID_Variable_maxOutSize_584,GETMAXOUTSIZE(ID_InputOutput_Summer_module_45));
			if ((ID_Variable_sameindex_583 < 0)) {
				_integer(&ID_Variable_temp_int_585,error_exit(1));
			} else {
				if ((ID_Variable_sameindex_583 > 0)) {
					_integer(&ID_Variable_requestSize_582,SUBTRACT_A_B(ID_Variable_desiredWP_581, ID_Variable_evaluatedWP_580));
					_StrlSampleIndex(&ID_Variable_pendingWP_579,ID_Variable_evaluatedWP_580);
				} else {
					_integer(&ID_Variable_requestSize_582,SUBTRACT_A_B(ID_Variable_desiredWP_581, ID_Variable_pendingWP_579));
				}
			}
			if ((ID_Variable_requestSize_582 > ID_Variable_maxOutSize_584)) {
				_integer(&ID_Variable_requestSize_582,ID_Variable_maxOutSize_584);
			}
			_UnsignedInt(&ID_Variable_temp_unsigned_586,GET_OUTPUTSIZE(ID_InputOutput_Summer_module_45));
			_integer(&ID_Variable_requestSize_582,ROUNDOWN_SIZE(ID_Variable_requestSize_582, ID_Variable_temp_unsigned_586));
			_StrlSampleRange(&ID_Variable_output_range_577,SET_SAMPLERANGE(ID_Variable_pendingWP_579, ID_Variable_requestSize_582));
			_StrlSampleRange(&ID_Variable_inside_input_578,FORECASTS(ID_Variable_output_range_577, ID_InputOutput_Summer_module_45));
			_integer(&ID_Variable_temp_int_585,REAL_FIT_RANGE(ID_Variable_pendingWP_579, ID_Variable_requestSize_582, ID_Variable_inside_input_578, ID_InputOutput_Summer_module_45));
			LOCALINCAWAITTICK(ID_InputOutput_Summer_module_45);
			next_point_bit_vector[0] |= 0x20000000; /* PauseOn:  #29*/
		} else {
			next_point_bit_vector[1] |= 0x1000000; /* PauseOn:  #56*/
		}
	}
}

static void Point_70() {
	_StrlSampleRange(&ID_Variable_my_input_567,UPDATESAMPLE(ID_Variable_my_input_567));
	_boolean(&ID_Variable_CONT_FLAG_564,1);
	if (ID_Variable_CONT_FLAG_564) {
		next_point_bit_vector[1] |= 0x400000; /* PauseOn:  #54*/
	} else {
		_StrlSampleRange(&ID_Variable_input_range_576,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_577,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_inside_input_578,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_579,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_evaluatedWP_580,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_581,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_582,0);
		_integer(&ID_Variable_sameindex_583,0);
		_integer(&ID_Variable_maxOutSize_584,0);
		_integer(&ID_Variable_temp_int_585,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_586,INITIAL_UNSIGNEDINT);
		if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_568,0)) {
			_StrlSampleRange(&ID_Variable_input_range_576,ID_Signal_My_Sample_Range_568);
			_StrlSampleRange(&ID_Variable_output_range_577,DOWNCASTS(ID_Variable_input_range_576, ID_InputOutput_Summer_module_45));
			_StrlSampleIndex(&ID_Variable_pendingWP_579,GETMARKEDWP(ID_InputOutput_Summer_module_45));
			_StrlSampleIndex(&ID_Variable_evaluatedWP_580,GETINDEX(ID_Variable_output_range_577));
			_StrlSampleIndex(&ID_Variable_desiredWP_581,ADD_INDEX_SIZE(ID_Variable_output_range_577));
			_integer(&ID_Variable_sameindex_583,SUBTRACT_A_B(ID_Variable_evaluatedWP_580, ID_Variable_pendingWP_579));
			_integer(&ID_Variable_maxOutSize_584,GETMAXOUTSIZE(ID_InputOutput_Summer_module_45));
			if ((ID_Variable_sameindex_583 < 0)) {
				_integer(&ID_Variable_temp_int_585,error_exit(1));
			} else {
				if ((ID_Variable_sameindex_583 > 0)) {
					_integer(&ID_Variable_requestSize_582,SUBTRACT_A_B(ID_Variable_desiredWP_581, ID_Variable_evaluatedWP_580));
					_StrlSampleIndex(&ID_Variable_pendingWP_579,ID_Variable_evaluatedWP_580);
				} else {
					_integer(&ID_Variable_requestSize_582,SUBTRACT_A_B(ID_Variable_desiredWP_581, ID_Variable_pendingWP_579));
				}
			}
			if ((ID_Variable_requestSize_582 > ID_Variable_maxOutSize_584)) {
				_integer(&ID_Variable_requestSize_582,ID_Variable_maxOutSize_584);
			}
			_UnsignedInt(&ID_Variable_temp_unsigned_586,GET_OUTPUTSIZE(ID_InputOutput_Summer_module_45));
			_integer(&ID_Variable_requestSize_582,ROUNDOWN_SIZE(ID_Variable_requestSize_582, ID_Variable_temp_unsigned_586));
			_StrlSampleRange(&ID_Variable_output_range_577,SET_SAMPLERANGE(ID_Variable_pendingWP_579, ID_Variable_requestSize_582));
			_StrlSampleRange(&ID_Variable_inside_input_578,FORECASTS(ID_Variable_output_range_577, ID_InputOutput_Summer_module_45));
			_integer(&ID_Variable_temp_int_585,REAL_FIT_RANGE(ID_Variable_pendingWP_579, ID_Variable_requestSize_582, ID_Variable_inside_input_578, ID_InputOutput_Summer_module_45));
			LOCALINCAWAITTICK(ID_InputOutput_Summer_module_45);
			next_point_bit_vector[0] |= 0x20000000; /* PauseOn:  #29*/
		} else {
			next_point_bit_vector[1] |= 0x1000000; /* PauseOn:  #56*/
		}
	}
}

static void Point_71() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_570,0)) {
		current_point_bit_vector[2] |= 0x100; /* On:  #72*/
		next_point_bit_vector[0] |= 0x80000000; /* PauseOn:  #31*/
	} else {
		next_point_bit_vector[2] |= 0x80; /* PauseOn:  #71*/
	}
}

static void Point_72() {
	EMIT(SIG_ID_Signal_Clock_Wire_M_S1_120);
	next_point_bit_vector[2] |= 0x100; /* PauseOn:  #72*/
}

static void Point_73() {
	if (IS_SIGNAL(SIG_ID_Signal_Compute_Wire_M_S2_112,0)) {
		current_point_bit_vector[2] |= 0x400; /* On:  #74*/
	} else {
		next_point_bit_vector[2] |= 0x200; /* PauseOn:  #73*/
	}
}

static void Point_74() {
	_integer(&ID_Variable_temp_int_616,0);
	_integer(&ID_Variable_not_source_617,0);
	_integer(&ID_Variable_not_complete_flag_618,0);
	_StrlSampleIndex(&ID_Variable_temp_index_619,INITIAL_INDEX);
	_StrlSampleRange(&ID_Variable_temp_range_620,INITIAL_RANGE);
	_StrlSampleSize(&ID_Variable_complete_var_621,INITIAL_SIZE);
	CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_622);
	CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_623);
	if (_eq_integer(CHECK_MYWRITERLL(ID_InputOutput_Sink_module_47),0)) {
		current_point_bit_vector[2] |= 0x2000; /* On:  #77*/
	} else {
		if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_InputOutput_Sink_module_47),0)) {
			current_point_bit_vector[2] |= 0x1000; /* On:  #76*/
		} else {
			if ((GET_NUMBERINPUTS(ID_InputOutput_Sink_module_47) > 0)) {
				_integer(&ID_Variable_not_source_617,1);
			}
			_StrlSampleSize(&ID_Variable_complete_var_621,REALCOMPUTEDATA(ID_InputOutput_Sink_module_47, ID_Variable_not_source_617));
			if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_InputOutput_Sink_module_47), ID_Variable_complete_var_621) > 0)) {
				_integer(&ID_Variable_not_complete_flag_618,(ID_Variable_not_complete_flag_618 - 1));
				current_point_bit_vector[2] |= 0x800; /* On:  #75*/
			} else {
				current_point_bit_vector[2] |= 0x800; /* On:  #75*/
			}
		}
	}
}

static void Point_75() {
	if ((ID_Variable_not_complete_flag_618 < 0)) {
		_StrlSampleIndex(&ID_Variable_temp_index_619,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_InputOutput_Sink_module_47), ID_Variable_complete_var_621));
		SET_MARKEDWP(ID_InputOutput_Sink_module_47, ID_Variable_temp_index_619);
	}
	WRITEDATA(ID_InputOutput_Sink_module_47, ID_Variable_not_source_617);
	_StrlSampleIndex(&ID_Variable_temp_index_619,GETWP(ID_InputOutput_Sink_module_47));
	_StrlSampleRange(&ID_Output_SINK_COMPUTEDSR_53,GET_MYMARKEDDATA(ID_InputOutput_Sink_module_47));
	TC_UDP_TX_O_SINK_COMPUTEDSR(ID_Output_SINK_COMPUTEDSR_53); EMIT(SIG_ID_Output_SINK_COMPUTEDSR_53);
	current_point_bit_vector[2] |= 0x4000; /* On:  #78*/
}

static void Point_76() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_622);
	current_point_bit_vector[2] |= 0x4000; /* On:  #78*/
	current_point_bit_vector[2] &= ~0x800; /* Off:  #75*/
}

static void Point_77() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_622);
	current_point_bit_vector[2] |= 0x4000; /* On:  #78*/
	current_point_bit_vector[2] &= ~0x800; /* Off:  #75*/
}

static void Point_78() {
	LOCALINCAWAITTICK(ID_InputOutput_Sink_module_47);
	next_point_bit_vector[1] |= 0x8; /* PauseOn:  #35*/
}

static void Point_79() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_570,0)) {
		EMIT(SIG_ID_Signal_Clock_Wire_M_S1_120);
		next_point_bit_vector[0] |= 0x80000000; next_point_bit_vector[2] |= 0x100; /* PauseOn:  #31 #72*/
	} else {
		next_point_bit_vector[2] |= 0x80; /* PauseOn:  #71*/
	}
}

static void Point_80() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0)) {
		EMIT(SIG_ID_Exception_main_trap_521);
		current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
		current_point_bit_vector[2] &= ~0x2000000; /* Off:  #89*/
	} else {
		next_point_bit_vector[2] |= 0x10000; /* PauseOn:  #80*/
	}
}

static void Point_81() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0)) {
		next_point_bit_vector[1] |= 0x200; /* PauseOn:  #41*/
	} else {
		next_point_bit_vector[2] |= 0x20000; /* PauseOn:  #81*/
	}
}

static void Point_82() {
	if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0))) {
		EMIT(SIG_ID_Exception_main_trap_521);
		current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
		current_point_bit_vector[2] &= ~0x2000000; /* Off:  #89*/
		next_point_bit_vector[2] |= 0x40000; /* PauseOn:  #82*/
	} else {
		next_point_bit_vector[2] |= 0x40000; /* PauseOn:  #82*/
	}
}

static void Point_83() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0)) {
		EMIT(SIG_ID_Exception_main_trap_521);
		current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
		current_point_bit_vector[2] &= ~0x2000000; /* Off:  #89*/
	} else {
		next_point_bit_vector[2] |= 0x80000; /* PauseOn:  #83*/
	}
}

static void Point_84() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0)) {
		next_point_bit_vector[0] |= 0x4000; /* PauseOn:  #14*/
	} else {
		next_point_bit_vector[2] |= 0x100000; /* PauseOn:  #84*/
	}
}

static void Point_85() {
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0))) {
		EMIT(SIG_ID_Exception_main_trap_521);
		current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
		current_point_bit_vector[2] &= ~0x2000000; /* Off:  #89*/
		next_point_bit_vector[2] |= 0x200000; /* PauseOn:  #85*/
	} else {
		next_point_bit_vector[2] |= 0x200000; /* PauseOn:  #85*/
	}
}

static void Point_86() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0)) {
		EMIT(SIG_ID_Exception_main_trap_521);
		current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
		current_point_bit_vector[2] &= ~0x2000000; /* Off:  #89*/
	} else {
		next_point_bit_vector[2] |= 0x400000; /* PauseOn:  #86*/
	}
}

static void Point_87() {
	EMIT(SIG_ID_Signal_switch_on_516);
	_StrlSampleRange(&ID_Variable_org_input_512,ID_Signal_Mark_Wire_M_M1_105);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_514,ID_Variable_org_input_512);
	EMIT(SIG_ID_Signal_My_Sample_Range_514);
	current_point_bit_vector[2] |= 0x1000000; /* On:  #88*/
	next_point_bit_vector[0] &= ~0x3e000; next_point_bit_vector[1] &= ~0x3f00; next_point_bit_vector[2] &= ~0x27f0000; /* PauseOff:  #13 #14 #15 #16 #17 #40 #41 #42 #43 #44 #45 #80 #81 #82 #83 #84 #85 #86 #89*/
}

static void Point_88() {
	CLEAR_SIGNAL(SIG_ID_Exception_compute_loop_520);
	if (ID_Variable_CONT_FLAG_511) {
		CLEAR_SIGNAL(SIG_ID_Exception_main_trap_522);
		next_point_bit_vector[3] |= 0x40; /* PauseOn:  #102*/
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) {
			next_point_bit_vector[3] |= 0x4; /* PauseOn:  #98*/
		} else {
			current_point_bit_vector[3] |= 0x40; /* On:  #102*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0)) {
			next_point_bit_vector[1] |= 0x4000; /* PauseOn:  #46*/
		} else {
			current_point_bit_vector[3] |= 0x40; /* On:  #102*/
		}
		if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0))) {
			EMIT(SIG_ID_Exception_main_trap_522);
			current_point_bit_vector[3] |= 0x8; /* On:  #99*/
			current_point_bit_vector[3] &= ~0x40; /* Off:  #102*/
		} else {
			current_point_bit_vector[3] |= 0x40; /* On:  #102*/
		}
	} else {
		current_point_bit_vector[3] |= 0x10; /* On:  #100*/
	}
}

static void Point_89() {
	if (next_point_bit_vector[0]&0x3e000) return;
	 if (next_point_bit_vector[1]&0x3f00) return;
	 if (next_point_bit_vector[2]&0x27f0000) return;
	 /* isPauseOn:  #13 #14 #15 #16 #17 #40 #41 #42 #43 #44 #45 #80 #81 #82 #83 #84 #85 #86 #89*/
	current_point_bit_vector[2] |= 0xd8000000; /* On:  #91 #92 #94 #95*/
	next_point_bit_vector[2] |= 0x2000000; /* PauseOn:  #89*/
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) {
		next_point_bit_vector[0] |= 0x2000; next_point_bit_vector[2] |= 0x300000; /* PauseOn:  #13 #84 #85*/
	} else {
		current_point_bit_vector[2] |= 0x4000000; /* On:  #90*/
	}
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0)) {
		next_point_bit_vector[1] |= 0x100; next_point_bit_vector[2] |= 0x60000; /* PauseOn:  #40 #81 #82*/
	} else {
		current_point_bit_vector[2] |= 0x4000000; /* On:  #90*/
	}
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0)) {
		next_point_bit_vector[0] |= 0x8000; next_point_bit_vector[1] |= 0x1800; /* PauseOn:  #15 #43 #44*/
	} else {
		current_point_bit_vector[2] |= 0x4000000; /* On:  #90*/
	}
}

static void Point_90() {
	if (next_point_bit_vector[0]&0x1e000) return;
	 if (next_point_bit_vector[1]&0x1f00) return;
	 if (next_point_bit_vector[2]&0x3f0000) return;
	 /* isPauseOn:  #13 #14 #15 #16 #40 #41 #42 #43 #44 #80 #81 #82 #83 #84 #85*/
	current_point_bit_vector[2] |= 0x20000000; /* On:  #93*/
}

static void Point_91() {
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0))) {
		next_point_bit_vector[2] |= 0x400000; /* PauseOn:  #86*/
	} else {
		current_point_bit_vector[2] |= 0x20000000; /* On:  #93*/
	}
}

static void Point_92() {
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0))) {
		next_point_bit_vector[1] |= 0x2000; /* PauseOn:  #45*/
	} else {
		current_point_bit_vector[2] |= 0x20000000; /* On:  #93*/
	}
}

static void Point_93() {
	if (next_point_bit_vector[0]&0x1e000) return;
	 if (next_point_bit_vector[1]&0x3f00) return;
	 if (next_point_bit_vector[2]&0x7f0000) return;
	 /* isPauseOn:  #13 #14 #15 #16 #40 #41 #42 #43 #44 #45 #80 #81 #82 #83 #84 #85 #86*/
	current_point_bit_vector[3] |= 0x1; /* On:  #96*/
}

static void Point_94() {
	if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0))) {
		next_point_bit_vector[0] |= 0x20000; /* PauseOn:  #17*/
	} else {
		current_point_bit_vector[3] |= 0x1; /* On:  #96*/
	}
}

static void Point_95() {
	if (((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0))) {
		current_point_bit_vector[3] |= 0x2; /* On:  #97*/
	} else {
		current_point_bit_vector[3] |= 0x1; /* On:  #96*/
	}
}

static void Point_96() {
	if (next_point_bit_vector[0]&0x3e000) return;
	 if (next_point_bit_vector[1]&0x3f00) return;
	 if (next_point_bit_vector[2]&0x7f0000) return;
	 /* isPauseOn:  #13 #14 #15 #16 #17 #40 #41 #42 #43 #44 #45 #80 #81 #82 #83 #84 #85 #86*/
}

static void Point_97() {
	EMIT(SIG_ID_Exception_main_trap_521);
	current_point_bit_vector[3] &= ~0x1; /* Off:  #96*/
}

static void Point_98() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0)) {
		EMIT(SIG_ID_Exception_main_trap_522);
		current_point_bit_vector[3] |= 0x8; /* On:  #99*/
		current_point_bit_vector[3] &= ~0x40; /* Off:  #102*/
	} else {
		next_point_bit_vector[3] |= 0x4; /* PauseOn:  #98*/
	}
}

static void Point_99() {
	_StrlSampleRange(&ID_Signal_My_Sample_Range_514,ID_Variable_my_input_513);
	EMIT(SIG_ID_Signal_My_Sample_Range_514);
	current_point_bit_vector[3] |= 0x10; /* On:  #100*/
	next_point_bit_vector[1] &= ~0x4000; next_point_bit_vector[3] &= ~0x44; /* PauseOff:  #46 #98 #102*/
}

static void Point_100() {
	_StrlSampleRange(&ID_Variable_input_range_523,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_output_range_524,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_inside_input_525,INITIAL_RANGE);
	_StrlSampleIndex(&ID_Variable_pendingWP_526,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_evaluatedWP_527,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_desiredWP_528,INITIAL_INDEX);
	_integer(&ID_Variable_requestSize_529,0);
	_integer(&ID_Variable_sameindex_530,0);
	_integer(&ID_Variable_maxOutSize_531,0);
	_integer(&ID_Variable_temp_int_532,0);
	_UnsignedInt(&ID_Variable_temp_unsigned_533,INITIAL_UNSIGNEDINT);
	current_point_bit_vector[3] |= 0x20; /* On:  #101*/
}

static void Point_101() {
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_514,0)) {
		_StrlSampleRange(&ID_Variable_input_range_523,ID_Signal_My_Sample_Range_514);
		_StrlSampleRange(&ID_Variable_output_range_524,DOWNCASTS(ID_Variable_input_range_523, ID_InputOutput_Mod_module_44));
		_StrlSampleIndex(&ID_Variable_pendingWP_526,GETMARKEDWP(ID_InputOutput_Mod_module_44));
		_StrlSampleIndex(&ID_Variable_evaluatedWP_527,GETINDEX(ID_Variable_output_range_524));
		_StrlSampleIndex(&ID_Variable_desiredWP_528,ADD_INDEX_SIZE(ID_Variable_output_range_524));
		_integer(&ID_Variable_sameindex_530,SUBTRACT_A_B(ID_Variable_evaluatedWP_527, ID_Variable_pendingWP_526));
		_integer(&ID_Variable_maxOutSize_531,GETMAXOUTSIZE(ID_InputOutput_Mod_module_44));
		if ((ID_Variable_sameindex_530 < 0)) {
			_integer(&ID_Variable_temp_int_532,error_exit(1));
		} else {
			if ((ID_Variable_sameindex_530 > 0)) {
				_integer(&ID_Variable_requestSize_529,SUBTRACT_A_B(ID_Variable_desiredWP_528, ID_Variable_evaluatedWP_527));
				_StrlSampleIndex(&ID_Variable_pendingWP_526,ID_Variable_evaluatedWP_527);
			} else {
				_integer(&ID_Variable_requestSize_529,SUBTRACT_A_B(ID_Variable_desiredWP_528, ID_Variable_pendingWP_526));
			}
		}
		if ((ID_Variable_requestSize_529 > ID_Variable_maxOutSize_531)) {
			_integer(&ID_Variable_requestSize_529,ID_Variable_maxOutSize_531);
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_533,GET_OUTPUTSIZE(ID_InputOutput_Mod_module_44));
		_integer(&ID_Variable_requestSize_529,ROUNDOWN_SIZE(ID_Variable_requestSize_529, ID_Variable_temp_unsigned_533));
		_StrlSampleRange(&ID_Variable_output_range_524,SET_SAMPLERANGE(ID_Variable_pendingWP_526, ID_Variable_requestSize_529));
		_StrlSampleRange(&ID_Variable_inside_input_525,FORECASTS(ID_Variable_output_range_524, ID_InputOutput_Mod_module_44));
		_integer(&ID_Variable_temp_int_532,REAL_FIT_RANGE(ID_Variable_pendingWP_526, ID_Variable_requestSize_529, ID_Variable_inside_input_525, ID_InputOutput_Mod_module_44));
		LOCALINCAWAITTICK(ID_InputOutput_Mod_module_44);
		next_point_bit_vector[0] |= 0x40000; /* PauseOn:  #18*/
	} else {
		next_point_bit_vector[3] |= 0x20; /* PauseOn:  #101*/
	}
}

static void Point_102() {
	if (next_point_bit_vector[1]&0x4000) return;
	 if (next_point_bit_vector[3]&0x44) return;
	 /* isPauseOn:  #46 #98 #102*/
	next_point_bit_vector[3] |= 0x40; /* PauseOn:  #102*/
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0)) {
		next_point_bit_vector[1] |= 0x4000; /* PauseOn:  #46*/
	} else {
		current_point_bit_vector[3] |= 0x80; /* On:  #103*/
	}
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) {
		next_point_bit_vector[3] |= 0x4; /* PauseOn:  #98*/
	} else {
		current_point_bit_vector[3] |= 0x80; /* On:  #103*/
	}
	if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0))) {
		current_point_bit_vector[3] |= 0x100; /* On:  #104*/
	} else {
		current_point_bit_vector[3] |= 0x80; /* On:  #103*/
	}
}

static void Point_103() {
	if (next_point_bit_vector[1]&0x4000) return;
	 if (next_point_bit_vector[3]&0x4) return;
	 /* isPauseOn:  #46 #98*/
}

static void Point_104() {
	EMIT(SIG_ID_Exception_main_trap_522);
	current_point_bit_vector[3] &= ~0x80; /* Off:  #103*/
}

static void Point_105() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_M_S1_120,0)) {
		next_point_bit_vector[3] |= 0x200; /* PauseOn:  #105*/
	} else {
		next_point_bit_vector[3] |= 0xc00; /* PauseOn:  #106 #107*/
	}
}

static void Point_106() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_M_S1_120,0)) {
		next_point_bit_vector[3] |= current_point_bit_vector[3] & 0x800; current_point_bit_vector[3] &= ~0x800; /* Suspend:  #107*/
		next_point_bit_vector[3] |= 0x400; /* PauseOn:  #106*/
	} else {
		next_point_bit_vector[3] |= 0x400; /* PauseOn:  #106*/
	}
}

static void Point_107() {
	EMIT(SIG_ID_Exception_main_loop_542);
	EMIT(SIG_ID_Signal_Compute_Wire_M_S1_111);
	next_point_bit_vector[3] &= ~0xc00; /* PauseOff:  #106 #107*/
	if ((CHECKSAMPLESIZE(ID_Variable_org_input_512, ID_Variable_my_input_513) >= 0)) {
		current_point_bit_vector[3] |= 0x800000; /* On:  #119*/
	} else {
		_boolean(&ID_Variable_CONT_FLAG_511,0);
		EMIT(SIG_ID_Exception_compute_loop_520);
		_StrlSampleRange(&ID_Signal_Ack_Wire_M_M1_114,ID_Variable_my_input_513);
		EMIT(SIG_ID_Signal_Ack_Wire_M_M1_114);
		next_point_bit_vector[0] &= ~0xc0000; next_point_bit_vector[1] &= ~0x4000; next_point_bit_vector[3] &= ~0xc64; next_point_bit_vector[4] &= ~0x400000; /* PauseOff:  #18 #19 #46 #98 #101 #102 #106 #107 #150*/
		if (IS_SIGNAL(SIG_ID_Signal_INI_PHASE_519,0)) {
			next_point_bit_vector[0] |= 0x1000; /* PauseOn:  #12*/
		} else {
			CLEAR_SIGNAL(SIG_ID_Exception_main_trap_521);
			current_point_bit_vector[3] |= 0x36000; /* On:  #109 #110 #112 #113*/
			next_point_bit_vector[2] |= 0x2000000; /* PauseOn:  #89*/
			if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) {
				next_point_bit_vector[0] |= 0x2000; next_point_bit_vector[2] |= 0x300000; /* PauseOn:  #13 #84 #85*/
			} else {
				current_point_bit_vector[3] |= 0x1000; /* On:  #108*/
			}
			if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0)) {
				next_point_bit_vector[1] |= 0x100; next_point_bit_vector[2] |= 0x60000; /* PauseOn:  #40 #81 #82*/
			} else {
				current_point_bit_vector[3] |= 0x1000; /* On:  #108*/
			}
			if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0)) {
				next_point_bit_vector[0] |= 0x8000; next_point_bit_vector[1] |= 0x1800; /* PauseOn:  #15 #43 #44*/
			} else {
				current_point_bit_vector[3] |= 0x1000; /* On:  #108*/
			}
		}
	}
}

static void Point_108() {
	if (next_point_bit_vector[0]&0x1e000) return;
	 if (next_point_bit_vector[1]&0x1f00) return;
	 if (next_point_bit_vector[2]&0x3f0000) return;
	 /* isPauseOn:  #13 #14 #15 #16 #40 #41 #42 #43 #44 #80 #81 #82 #83 #84 #85*/
	current_point_bit_vector[3] |= 0x8000; /* On:  #111*/
}

static void Point_109() {
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0))) {
		next_point_bit_vector[2] |= 0x400000; /* PauseOn:  #86*/
	} else {
		current_point_bit_vector[3] |= 0x8000; /* On:  #111*/
	}
}

static void Point_110() {
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0))) {
		next_point_bit_vector[1] |= 0x2000; /* PauseOn:  #45*/
	} else {
		current_point_bit_vector[3] |= 0x8000; /* On:  #111*/
	}
}

static void Point_111() {
	if (next_point_bit_vector[0]&0x1e000) return;
	 if (next_point_bit_vector[1]&0x3f00) return;
	 if (next_point_bit_vector[2]&0x7f0000) return;
	 /* isPauseOn:  #13 #14 #15 #16 #40 #41 #42 #43 #44 #45 #80 #81 #82 #83 #84 #85 #86*/
	current_point_bit_vector[3] |= 0x40000; /* On:  #114*/
}

static void Point_112() {
	if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0))) {
		next_point_bit_vector[0] |= 0x20000; /* PauseOn:  #17*/
	} else {
		current_point_bit_vector[3] |= 0x40000; /* On:  #114*/
	}
}

static void Point_113() {
	if (((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_M_M1_105,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0))) {
		current_point_bit_vector[3] |= 0x80000; /* On:  #115*/
	} else {
		current_point_bit_vector[3] |= 0x40000; /* On:  #114*/
	}
}

static void Point_114() {
	if (next_point_bit_vector[0]&0x3e000) return;
	 if (next_point_bit_vector[1]&0x3f00) return;
	 if (next_point_bit_vector[2]&0x7f0000) return;
	 /* isPauseOn:  #13 #14 #15 #16 #17 #40 #41 #42 #43 #44 #45 #80 #81 #82 #83 #84 #85 #86*/
}

static void Point_115() {
	EMIT(SIG_ID_Exception_main_trap_521);
	EMIT(SIG_ID_Signal_switch_on_516);
	_StrlSampleRange(&ID_Variable_org_input_512,ID_Signal_Mark_Wire_M_M1_105);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_514,ID_Variable_org_input_512);
	EMIT(SIG_ID_Signal_My_Sample_Range_514);
	CLEAR_SIGNAL(SIG_ID_Exception_compute_loop_520);
	current_point_bit_vector[3] &= ~0x40000; /* Off:  #114*/
	next_point_bit_vector[0] &= ~0x3e000; next_point_bit_vector[1] &= ~0x3f00; next_point_bit_vector[2] &= ~0x27f0000; /* PauseOff:  #13 #14 #15 #16 #17 #40 #41 #42 #43 #44 #45 #80 #81 #82 #83 #84 #85 #86 #89*/
	if (ID_Variable_CONT_FLAG_511) {
		CLEAR_SIGNAL(SIG_ID_Exception_main_trap_522);
		next_point_bit_vector[3] |= 0x40; /* PauseOn:  #102*/
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0)) {
			next_point_bit_vector[1] |= 0x4000; /* PauseOn:  #46*/
		} else {
			current_point_bit_vector[3] |= 0x100000; /* On:  #116*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) {
			next_point_bit_vector[3] |= 0x4; /* PauseOn:  #98*/
		} else {
			current_point_bit_vector[3] |= 0x100000; /* On:  #116*/
		}
		if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0))) {
			current_point_bit_vector[3] |= 0x200000; /* On:  #117*/
		} else {
			current_point_bit_vector[3] |= 0x100000; /* On:  #116*/
		}
	} else {
		current_point_bit_vector[3] |= 0x400000; /* On:  #118*/
	}
}

static void Point_116() {
	if (next_point_bit_vector[1]&0x4000) return;
	 if (next_point_bit_vector[3]&0x4) return;
	 /* isPauseOn:  #46 #98*/
}

static void Point_117() {
	EMIT(SIG_ID_Exception_main_trap_522);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_514,ID_Variable_my_input_513);
	EMIT(SIG_ID_Signal_My_Sample_Range_514);
	current_point_bit_vector[3] |= 0x400000; /* On:  #118*/
	current_point_bit_vector[3] &= ~0x100000; /* Off:  #116*/
	next_point_bit_vector[1] &= ~0x4000; next_point_bit_vector[3] &= ~0x44; /* PauseOff:  #46 #98 #102*/
}

static void Point_118() {
	_StrlSampleRange(&ID_Variable_input_range_523,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_output_range_524,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_inside_input_525,INITIAL_RANGE);
	_StrlSampleIndex(&ID_Variable_pendingWP_526,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_evaluatedWP_527,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_desiredWP_528,INITIAL_INDEX);
	_integer(&ID_Variable_requestSize_529,0);
	_integer(&ID_Variable_sameindex_530,0);
	_integer(&ID_Variable_maxOutSize_531,0);
	_integer(&ID_Variable_temp_int_532,0);
	_UnsignedInt(&ID_Variable_temp_unsigned_533,INITIAL_UNSIGNEDINT);
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_514,0)) {
		_StrlSampleRange(&ID_Variable_input_range_523,ID_Signal_My_Sample_Range_514);
		_StrlSampleRange(&ID_Variable_output_range_524,DOWNCASTS(ID_Variable_input_range_523, ID_InputOutput_Mod_module_44));
		_StrlSampleIndex(&ID_Variable_pendingWP_526,GETMARKEDWP(ID_InputOutput_Mod_module_44));
		_StrlSampleIndex(&ID_Variable_evaluatedWP_527,GETINDEX(ID_Variable_output_range_524));
		_StrlSampleIndex(&ID_Variable_desiredWP_528,ADD_INDEX_SIZE(ID_Variable_output_range_524));
		_integer(&ID_Variable_sameindex_530,SUBTRACT_A_B(ID_Variable_evaluatedWP_527, ID_Variable_pendingWP_526));
		_integer(&ID_Variable_maxOutSize_531,GETMAXOUTSIZE(ID_InputOutput_Mod_module_44));
		if ((ID_Variable_sameindex_530 < 0)) {
			_integer(&ID_Variable_temp_int_532,error_exit(1));
		} else {
			if ((ID_Variable_sameindex_530 > 0)) {
				_integer(&ID_Variable_requestSize_529,SUBTRACT_A_B(ID_Variable_desiredWP_528, ID_Variable_evaluatedWP_527));
				_StrlSampleIndex(&ID_Variable_pendingWP_526,ID_Variable_evaluatedWP_527);
			} else {
				_integer(&ID_Variable_requestSize_529,SUBTRACT_A_B(ID_Variable_desiredWP_528, ID_Variable_pendingWP_526));
			}
		}
		if ((ID_Variable_requestSize_529 > ID_Variable_maxOutSize_531)) {
			_integer(&ID_Variable_requestSize_529,ID_Variable_maxOutSize_531);
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_533,GET_OUTPUTSIZE(ID_InputOutput_Mod_module_44));
		_integer(&ID_Variable_requestSize_529,ROUNDOWN_SIZE(ID_Variable_requestSize_529, ID_Variable_temp_unsigned_533));
		_StrlSampleRange(&ID_Variable_output_range_524,SET_SAMPLERANGE(ID_Variable_pendingWP_526, ID_Variable_requestSize_529));
		_StrlSampleRange(&ID_Variable_inside_input_525,FORECASTS(ID_Variable_output_range_524, ID_InputOutput_Mod_module_44));
		_integer(&ID_Variable_temp_int_532,REAL_FIT_RANGE(ID_Variable_pendingWP_526, ID_Variable_requestSize_529, ID_Variable_inside_input_525, ID_InputOutput_Mod_module_44));
		LOCALINCAWAITTICK(ID_InputOutput_Mod_module_44);
		next_point_bit_vector[0] |= 0x40000; /* PauseOn:  #18*/
	} else {
		next_point_bit_vector[3] |= 0x20; /* PauseOn:  #101*/
	}
}

static void Point_119() {
	_StrlSampleRange(&ID_Variable_my_input_513,UPDATESAMPLE(ID_Variable_my_input_513));
	_boolean(&ID_Variable_CONT_FLAG_511,1);
	if (ID_Variable_CONT_FLAG_511) {
		CLEAR_SIGNAL(SIG_ID_Exception_main_trap_522);
		next_point_bit_vector[3] |= 0x40; /* PauseOn:  #102*/
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0)) {
			next_point_bit_vector[1] |= 0x4000; /* PauseOn:  #46*/
		} else {
			current_point_bit_vector[3] |= 0x1000000; /* On:  #120*/
		}
		if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0)) {
			next_point_bit_vector[3] |= 0x4; /* PauseOn:  #98*/
		} else {
			current_point_bit_vector[3] |= 0x1000000; /* On:  #120*/
		}
		if ((IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_S1_116,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M2_115,0))) {
			current_point_bit_vector[3] |= 0x2000000; /* On:  #121*/
		} else {
			current_point_bit_vector[3] |= 0x1000000; /* On:  #120*/
		}
	} else {
		current_point_bit_vector[3] |= 0x4000000; /* On:  #122*/
	}
}

static void Point_120() {
	if (next_point_bit_vector[1]&0x4000) return;
	 if (next_point_bit_vector[3]&0x4) return;
	 /* isPauseOn:  #46 #98*/
}

static void Point_121() {
	EMIT(SIG_ID_Exception_main_trap_522);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_514,ID_Variable_my_input_513);
	EMIT(SIG_ID_Signal_My_Sample_Range_514);
	current_point_bit_vector[3] |= 0x4000000; /* On:  #122*/
	current_point_bit_vector[3] &= ~0x1000000; /* Off:  #120*/
	next_point_bit_vector[1] &= ~0x4000; next_point_bit_vector[3] &= ~0x44; /* PauseOff:  #46 #98 #102*/
}

static void Point_122() {
	_StrlSampleRange(&ID_Variable_input_range_523,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_output_range_524,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_inside_input_525,INITIAL_RANGE);
	_StrlSampleIndex(&ID_Variable_pendingWP_526,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_evaluatedWP_527,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_desiredWP_528,INITIAL_INDEX);
	_integer(&ID_Variable_requestSize_529,0);
	_integer(&ID_Variable_sameindex_530,0);
	_integer(&ID_Variable_maxOutSize_531,0);
	_integer(&ID_Variable_temp_int_532,0);
	_UnsignedInt(&ID_Variable_temp_unsigned_533,INITIAL_UNSIGNEDINT);
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_514,0)) {
		_StrlSampleRange(&ID_Variable_input_range_523,ID_Signal_My_Sample_Range_514);
		_StrlSampleRange(&ID_Variable_output_range_524,DOWNCASTS(ID_Variable_input_range_523, ID_InputOutput_Mod_module_44));
		_StrlSampleIndex(&ID_Variable_pendingWP_526,GETMARKEDWP(ID_InputOutput_Mod_module_44));
		_StrlSampleIndex(&ID_Variable_evaluatedWP_527,GETINDEX(ID_Variable_output_range_524));
		_StrlSampleIndex(&ID_Variable_desiredWP_528,ADD_INDEX_SIZE(ID_Variable_output_range_524));
		_integer(&ID_Variable_sameindex_530,SUBTRACT_A_B(ID_Variable_evaluatedWP_527, ID_Variable_pendingWP_526));
		_integer(&ID_Variable_maxOutSize_531,GETMAXOUTSIZE(ID_InputOutput_Mod_module_44));
		if ((ID_Variable_sameindex_530 < 0)) {
			_integer(&ID_Variable_temp_int_532,error_exit(1));
		} else {
			if ((ID_Variable_sameindex_530 > 0)) {
				_integer(&ID_Variable_requestSize_529,SUBTRACT_A_B(ID_Variable_desiredWP_528, ID_Variable_evaluatedWP_527));
				_StrlSampleIndex(&ID_Variable_pendingWP_526,ID_Variable_evaluatedWP_527);
			} else {
				_integer(&ID_Variable_requestSize_529,SUBTRACT_A_B(ID_Variable_desiredWP_528, ID_Variable_pendingWP_526));
			}
		}
		if ((ID_Variable_requestSize_529 > ID_Variable_maxOutSize_531)) {
			_integer(&ID_Variable_requestSize_529,ID_Variable_maxOutSize_531);
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_533,GET_OUTPUTSIZE(ID_InputOutput_Mod_module_44));
		_integer(&ID_Variable_requestSize_529,ROUNDOWN_SIZE(ID_Variable_requestSize_529, ID_Variable_temp_unsigned_533));
		_StrlSampleRange(&ID_Variable_output_range_524,SET_SAMPLERANGE(ID_Variable_pendingWP_526, ID_Variable_requestSize_529));
		_StrlSampleRange(&ID_Variable_inside_input_525,FORECASTS(ID_Variable_output_range_524, ID_InputOutput_Mod_module_44));
		_integer(&ID_Variable_temp_int_532,REAL_FIT_RANGE(ID_Variable_pendingWP_526, ID_Variable_requestSize_529, ID_Variable_inside_input_525, ID_InputOutput_Mod_module_44));
		LOCALINCAWAITTICK(ID_InputOutput_Mod_module_44);
		next_point_bit_vector[0] |= 0x40000; /* PauseOn:  #18*/
	} else {
		next_point_bit_vector[3] |= 0x20; /* PauseOn:  #101*/
	}
}

static void Point_123() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_516,0)) {
		current_point_bit_vector[3] |= 0x10000000; /* On:  #124*/
		next_point_bit_vector[0] |= 0x100000; /* PauseOn:  #20*/
	} else {
		next_point_bit_vector[3] |= 0x8000000; /* PauseOn:  #123*/
	}
}

static void Point_124() {
	EMIT(SIG_ID_Signal_Clock_Wire_M_M1_119);
	next_point_bit_vector[3] |= 0x10000000; /* PauseOn:  #124*/
}

static void Point_125() {
	if (IS_SIGNAL(SIG_ID_Signal_Compute_Wire_M_S1_111,0)) {
		current_point_bit_vector[3] |= 0x40000000; /* On:  #126*/
	} else {
		next_point_bit_vector[3] |= 0x20000000; /* PauseOn:  #125*/
	}
}

static void Point_126() {
	_StrlSampleRange(&ID_Variable_my_input_547,INSIDE_COMP_FIT(ID_Variable_org_input_546, ID_Variable_my_input_547, ID_InputOutput_Scopesink_module_46));
	LOCALINCAWAITTICK(ID_InputOutput_Scopesink_module_46);
	next_point_bit_vector[0] |= 0x1000000; /* PauseOn:  #24*/
}

static void Point_127() {
	if (IS_SIGNAL(SIG_ID_Signal_Compute_Wire_M_S1_111,0)) {
		_integer(&ID_Variable_temp_int_587,0);
		_integer(&ID_Variable_not_source_588,0);
		_integer(&ID_Variable_not_complete_flag_589,0);
		_StrlSampleIndex(&ID_Variable_temp_index_590,INITIAL_INDEX);
		_StrlSampleRange(&ID_Variable_temp_range_591,INITIAL_RANGE);
		_StrlSampleSize(&ID_Variable_complete_var_592,INITIAL_SIZE);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_593);
		CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_594);
		if (_eq_integer(CHECK_MYWRITERLL(ID_InputOutput_Summer_module_45),0)) {
			current_point_bit_vector[4] |= 0x4; /* On:  #130*/
		} else {
			if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_InputOutput_Summer_module_45),0)) {
				current_point_bit_vector[4] |= 0x2; /* On:  #129*/
			} else {
				if ((GET_NUMBERINPUTS(ID_InputOutput_Summer_module_45) > 0)) {
					_integer(&ID_Variable_not_source_588,1);
				}
				_StrlSampleSize(&ID_Variable_complete_var_592,REALCOMPUTEDATA(ID_InputOutput_Summer_module_45, ID_Variable_not_source_588));
				if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_InputOutput_Summer_module_45), ID_Variable_complete_var_592) > 0)) {
					_integer(&ID_Variable_not_complete_flag_589,(ID_Variable_not_complete_flag_589 - 1));
					current_point_bit_vector[4] |= 0x1; /* On:  #128*/
				} else {
					current_point_bit_vector[4] |= 0x1; /* On:  #128*/
				}
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x80000000; /* PauseOn:  #127*/
	}
}

static void Point_128() {
	if ((ID_Variable_not_complete_flag_589 < 0)) {
		_StrlSampleIndex(&ID_Variable_temp_index_590,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_InputOutput_Summer_module_45), ID_Variable_complete_var_592));
		SET_MARKEDWP(ID_InputOutput_Summer_module_45, ID_Variable_temp_index_590);
	}
	WRITEDATA(ID_InputOutput_Summer_module_45, ID_Variable_not_source_588);
	_StrlSampleIndex(&ID_Variable_temp_index_590,GETWP(ID_InputOutput_Summer_module_45));
	_StrlSampleRange(&ID_Output_SUMMER_COMPUTEDSR_51,GET_MYMARKEDDATA(ID_InputOutput_Summer_module_45));
	TC_UDP_TX_O_SUMMER_COMPUTEDSR(ID_Output_SUMMER_COMPUTEDSR_51); EMIT(SIG_ID_Output_SUMMER_COMPUTEDSR_51);
	current_point_bit_vector[4] |= 0x8; /* On:  #131*/
}

static void Point_129() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_593);
	current_point_bit_vector[4] |= 0x8; /* On:  #131*/
	current_point_bit_vector[4] &= ~0x1; /* Off:  #128*/
}

static void Point_130() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_593);
	current_point_bit_vector[4] |= 0x8; /* On:  #131*/
	current_point_bit_vector[4] &= ~0x1; /* Off:  #128*/
}

static void Point_131() {
	LOCALINCAWAITTICK(ID_InputOutput_Summer_module_45);
	next_point_bit_vector[0] |= 0x40000000; /* PauseOn:  #30*/
}

static void Point_132() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_516,0)) {
		EMIT(SIG_ID_Signal_Clock_Wire_M_M1_119);
		next_point_bit_vector[0] |= 0x100000; next_point_bit_vector[3] |= 0x10000000; /* PauseOn:  #20 #124*/
	} else {
		next_point_bit_vector[3] |= 0x8000000; /* PauseOn:  #123*/
	}
}

static void Point_133() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_114,0)) {
		EMIT(SIG_ID_Exception_main_trap_487);
		current_point_bit_vector[4] |= 0x40; /* On:  #134*/
		current_point_bit_vector[4] &= ~0x100; /* Off:  #136*/
	} else {
		next_point_bit_vector[4] |= 0x20; /* PauseOn:  #133*/
	}
}

static void Point_134() {
	EMIT(SIG_ID_Signal_switch_on_482);
	_StrlSampleRange(&ID_Variable_org_input_478,ID_Signal_Mark_Wire_S_M_104);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_480,ID_Variable_org_input_478);
	EMIT(SIG_ID_Signal_My_Sample_Range_480);
	current_point_bit_vector[4] |= 0x80; /* On:  #135*/
	next_point_bit_vector[0] &= ~0x100; next_point_bit_vector[4] &= ~0x120; /* PauseOff:  #8 #133 #136*/
}

static void Point_135() {
	CLEAR_SIGNAL(SIG_ID_Exception_compute_loop_486);
	if (ID_Variable_CONT_FLAG_476) {
		next_point_bit_vector[4] |= 0x800; /* PauseOn:  #139*/
	} else {
		current_point_bit_vector[4] |= 0x1000; /* On:  #140*/
	}
}

static void Point_136() {
	if (next_point_bit_vector[0]&0x100) return;
	 if (next_point_bit_vector[4]&0x120) return;
	 /* isPauseOn:  #8 #133 #136*/
	next_point_bit_vector[4] |= 0x100; /* PauseOn:  #136*/
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_114,0)) {
		next_point_bit_vector[0] |= 0x100; /* PauseOn:  #8*/
	} else {
		current_point_bit_vector[4] |= 0x200; /* On:  #137*/
	}
	if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_104,0)) {
		next_point_bit_vector[4] |= 0x20; /* PauseOn:  #133*/
	} else {
		current_point_bit_vector[4] |= 0x200; /* On:  #137*/
	}
	if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_104,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_114,0))) {
		current_point_bit_vector[4] |= 0x400; /* On:  #138*/
	} else {
		current_point_bit_vector[4] |= 0x200; /* On:  #137*/
	}
}

static void Point_137() {
	if (next_point_bit_vector[0]&0x100) return;
	 if (next_point_bit_vector[4]&0x20) return;
	 /* isPauseOn:  #8 #133*/
}

static void Point_138() {
	EMIT(SIG_ID_Exception_main_trap_487);
	current_point_bit_vector[4] &= ~0x200; /* Off:  #137*/
}

static void Point_139() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_114,0)) {
		_StrlSampleRange(&ID_Signal_My_Sample_Range_480,ID_Variable_my_input_479);
		EMIT(SIG_ID_Signal_My_Sample_Range_480);
		current_point_bit_vector[4] |= 0x1000; /* On:  #140*/
	} else {
		next_point_bit_vector[4] |= 0x800; /* PauseOn:  #139*/
	}
}

static void Point_140() {
	_StrlSampleRange(&ID_Variable_input_range_491,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_output_range_492,INITIAL_RANGE);
	_StrlSampleRange(&ID_Variable_inside_input_493,INITIAL_RANGE);
	_StrlSampleIndex(&ID_Variable_pendingWP_494,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_evaluatedWP_495,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_desiredWP_496,INITIAL_INDEX);
	_integer(&ID_Variable_requestSize_497,0);
	_integer(&ID_Variable_sameindex_498,0);
	_integer(&ID_Variable_maxOutSize_499,0);
	_integer(&ID_Variable_temp_int_500,0);
	_UnsignedInt(&ID_Variable_temp_unsigned_501,INITIAL_UNSIGNEDINT);
	current_point_bit_vector[4] |= 0x2000; /* On:  #141*/
}

static void Point_141() {
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_480,0)) {
		_StrlSampleRange(&ID_Variable_input_range_491,ID_Signal_My_Sample_Range_480);
		_StrlSampleRange(&ID_Variable_output_range_492,DOWNCASTS(ID_Variable_input_range_491, ID_InputOutput_Coder_module_43));
		_StrlSampleIndex(&ID_Variable_pendingWP_494,GETMARKEDWP(ID_InputOutput_Coder_module_43));
		_StrlSampleIndex(&ID_Variable_evaluatedWP_495,GETINDEX(ID_Variable_output_range_492));
		_StrlSampleIndex(&ID_Variable_desiredWP_496,ADD_INDEX_SIZE(ID_Variable_output_range_492));
		_integer(&ID_Variable_sameindex_498,SUBTRACT_A_B(ID_Variable_evaluatedWP_495, ID_Variable_pendingWP_494));
		_integer(&ID_Variable_maxOutSize_499,GETMAXOUTSIZE(ID_InputOutput_Coder_module_43));
		if ((ID_Variable_sameindex_498 < 0)) {
			_integer(&ID_Variable_temp_int_500,error_exit(1));
		} else {
			if ((ID_Variable_sameindex_498 > 0)) {
				_integer(&ID_Variable_requestSize_497,SUBTRACT_A_B(ID_Variable_desiredWP_496, ID_Variable_evaluatedWP_495));
				_StrlSampleIndex(&ID_Variable_pendingWP_494,ID_Variable_evaluatedWP_495);
			} else {
				_integer(&ID_Variable_requestSize_497,SUBTRACT_A_B(ID_Variable_desiredWP_496, ID_Variable_pendingWP_494));
			}
		}
		if ((ID_Variable_requestSize_497 > ID_Variable_maxOutSize_499)) {
			_integer(&ID_Variable_requestSize_497,ID_Variable_maxOutSize_499);
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_501,GET_OUTPUTSIZE(ID_InputOutput_Coder_module_43));
		_integer(&ID_Variable_requestSize_497,ROUNDOWN_SIZE(ID_Variable_requestSize_497, ID_Variable_temp_unsigned_501));
		_StrlSampleRange(&ID_Variable_output_range_492,SET_SAMPLERANGE(ID_Variable_pendingWP_494, ID_Variable_requestSize_497));
		_StrlSampleRange(&ID_Variable_inside_input_493,FORECASTS(ID_Variable_output_range_492, ID_InputOutput_Coder_module_43));
		_integer(&ID_Variable_temp_int_500,REAL_FIT_RANGE(ID_Variable_pendingWP_494, ID_Variable_requestSize_497, ID_Variable_inside_input_493, ID_InputOutput_Coder_module_43));
		LOCALINCAWAITTICK(ID_InputOutput_Coder_module_43);
		next_point_bit_vector[0] |= 0x200; /* PauseOn:  #9*/
	} else {
		next_point_bit_vector[4] |= 0x2000; /* PauseOn:  #141*/
	}
}

static void Point_142() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_M_M1_119,0)) {
		next_point_bit_vector[4] |= 0x4000; /* PauseOn:  #142*/
	} else {
		next_point_bit_vector[4] |= 0x18000; /* PauseOn:  #143 #144*/
	}
}

static void Point_143() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_M_M1_119,0)) {
		next_point_bit_vector[4] |= current_point_bit_vector[4] & 0x10000; current_point_bit_vector[4] &= ~0x10000; /* Suspend:  #144*/
		next_point_bit_vector[4] |= 0x8000; /* PauseOn:  #143*/
	} else {
		next_point_bit_vector[4] |= 0x8000; /* PauseOn:  #143*/
	}
}

static void Point_144() {
	EMIT(SIG_ID_Exception_main_loop_510);
	EMIT(SIG_ID_Signal_Compute_Wire_M_M1_110);
	next_point_bit_vector[4] &= ~0x18000; /* PauseOff:  #143 #144*/
	if ((CHECKSAMPLESIZE(ID_Variable_org_input_478, ID_Variable_my_input_479) >= 0)) {
		current_point_bit_vector[4] |= 0x80000; /* On:  #147*/
	} else {
		_boolean(&ID_Variable_CONT_FLAG_476,0);
		EMIT(SIG_ID_Exception_compute_loop_486);
		_StrlSampleRange(&ID_Signal_Ack_Wire_S_M_113,ID_Variable_my_input_479);
		EMIT(SIG_ID_Signal_Ack_Wire_S_M_113);
		next_point_bit_vector[0] &= ~0x600; next_point_bit_vector[4] &= ~0x1a800; next_point_bit_vector[5] &= ~0x2; /* PauseOff:  #9 #10 #139 #141 #143 #144 #161*/
		if (IS_SIGNAL(SIG_ID_Signal_INI_PHASE_485,0)) {
			next_point_bit_vector[0] |= 0x80; /* PauseOn:  #7*/
		} else {
			CLEAR_SIGNAL(SIG_ID_Exception_main_trap_487);
			next_point_bit_vector[4] |= 0x100; /* PauseOn:  #136*/
			if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_114,0)) {
				next_point_bit_vector[0] |= 0x100; /* PauseOn:  #8*/
			} else {
				current_point_bit_vector[4] |= 0x20000; /* On:  #145*/
			}
			if (IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_104,0)) {
				next_point_bit_vector[4] |= 0x20; /* PauseOn:  #133*/
			} else {
				current_point_bit_vector[4] |= 0x20000; /* On:  #145*/
			}
			if ((IS_SIGNAL(SIG_ID_Signal_Mark_Wire_S_M_104,0) && IS_SIGNAL(SIG_ID_Signal_Ack_Wire_M_M1_114,0))) {
				current_point_bit_vector[4] |= 0x40000; /* On:  #146*/
			} else {
				current_point_bit_vector[4] |= 0x20000; /* On:  #145*/
			}
		}
	}
}

static void Point_145() {
	if (next_point_bit_vector[0]&0x100) return;
	 if (next_point_bit_vector[4]&0x20) return;
	 /* isPauseOn:  #8 #133*/
}

static void Point_146() {
	EMIT(SIG_ID_Exception_main_trap_487);
	EMIT(SIG_ID_Signal_switch_on_482);
	_StrlSampleRange(&ID_Variable_org_input_478,ID_Signal_Mark_Wire_S_M_104);
	_StrlSampleRange(&ID_Signal_My_Sample_Range_480,ID_Variable_org_input_478);
	EMIT(SIG_ID_Signal_My_Sample_Range_480);
	CLEAR_SIGNAL(SIG_ID_Exception_compute_loop_486);
	current_point_bit_vector[4] &= ~0x20000; /* Off:  #145*/
	next_point_bit_vector[0] &= ~0x100; next_point_bit_vector[4] &= ~0x120; /* PauseOff:  #8 #133 #136*/
	if (ID_Variable_CONT_FLAG_476) {
		next_point_bit_vector[4] |= 0x800; /* PauseOn:  #139*/
	} else {
		_StrlSampleRange(&ID_Variable_input_range_491,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_492,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_inside_input_493,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_494,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_evaluatedWP_495,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_496,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_497,0);
		_integer(&ID_Variable_sameindex_498,0);
		_integer(&ID_Variable_maxOutSize_499,0);
		_integer(&ID_Variable_temp_int_500,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_501,INITIAL_UNSIGNEDINT);
		if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_480,0)) {
			_StrlSampleRange(&ID_Variable_input_range_491,ID_Signal_My_Sample_Range_480);
			_StrlSampleRange(&ID_Variable_output_range_492,DOWNCASTS(ID_Variable_input_range_491, ID_InputOutput_Coder_module_43));
			_StrlSampleIndex(&ID_Variable_pendingWP_494,GETMARKEDWP(ID_InputOutput_Coder_module_43));
			_StrlSampleIndex(&ID_Variable_evaluatedWP_495,GETINDEX(ID_Variable_output_range_492));
			_StrlSampleIndex(&ID_Variable_desiredWP_496,ADD_INDEX_SIZE(ID_Variable_output_range_492));
			_integer(&ID_Variable_sameindex_498,SUBTRACT_A_B(ID_Variable_evaluatedWP_495, ID_Variable_pendingWP_494));
			_integer(&ID_Variable_maxOutSize_499,GETMAXOUTSIZE(ID_InputOutput_Coder_module_43));
			if ((ID_Variable_sameindex_498 < 0)) {
				_integer(&ID_Variable_temp_int_500,error_exit(1));
			} else {
				if ((ID_Variable_sameindex_498 > 0)) {
					_integer(&ID_Variable_requestSize_497,SUBTRACT_A_B(ID_Variable_desiredWP_496, ID_Variable_evaluatedWP_495));
					_StrlSampleIndex(&ID_Variable_pendingWP_494,ID_Variable_evaluatedWP_495);
				} else {
					_integer(&ID_Variable_requestSize_497,SUBTRACT_A_B(ID_Variable_desiredWP_496, ID_Variable_pendingWP_494));
				}
			}
			if ((ID_Variable_requestSize_497 > ID_Variable_maxOutSize_499)) {
				_integer(&ID_Variable_requestSize_497,ID_Variable_maxOutSize_499);
			}
			_UnsignedInt(&ID_Variable_temp_unsigned_501,GET_OUTPUTSIZE(ID_InputOutput_Coder_module_43));
			_integer(&ID_Variable_requestSize_497,ROUNDOWN_SIZE(ID_Variable_requestSize_497, ID_Variable_temp_unsigned_501));
			_StrlSampleRange(&ID_Variable_output_range_492,SET_SAMPLERANGE(ID_Variable_pendingWP_494, ID_Variable_requestSize_497));
			_StrlSampleRange(&ID_Variable_inside_input_493,FORECASTS(ID_Variable_output_range_492, ID_InputOutput_Coder_module_43));
			_integer(&ID_Variable_temp_int_500,REAL_FIT_RANGE(ID_Variable_pendingWP_494, ID_Variable_requestSize_497, ID_Variable_inside_input_493, ID_InputOutput_Coder_module_43));
			LOCALINCAWAITTICK(ID_InputOutput_Coder_module_43);
			next_point_bit_vector[0] |= 0x200; /* PauseOn:  #9*/
		} else {
			next_point_bit_vector[4] |= 0x2000; /* PauseOn:  #141*/
		}
	}
}

static void Point_147() {
	_StrlSampleRange(&ID_Variable_my_input_479,UPDATESAMPLE(ID_Variable_my_input_479));
	_boolean(&ID_Variable_CONT_FLAG_476,1);
	if (ID_Variable_CONT_FLAG_476) {
		next_point_bit_vector[4] |= 0x800; /* PauseOn:  #139*/
	} else {
		_StrlSampleRange(&ID_Variable_input_range_491,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_492,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_inside_input_493,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_494,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_evaluatedWP_495,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_496,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_497,0);
		_integer(&ID_Variable_sameindex_498,0);
		_integer(&ID_Variable_maxOutSize_499,0);
		_integer(&ID_Variable_temp_int_500,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_501,INITIAL_UNSIGNEDINT);
		if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_480,0)) {
			_StrlSampleRange(&ID_Variable_input_range_491,ID_Signal_My_Sample_Range_480);
			_StrlSampleRange(&ID_Variable_output_range_492,DOWNCASTS(ID_Variable_input_range_491, ID_InputOutput_Coder_module_43));
			_StrlSampleIndex(&ID_Variable_pendingWP_494,GETMARKEDWP(ID_InputOutput_Coder_module_43));
			_StrlSampleIndex(&ID_Variable_evaluatedWP_495,GETINDEX(ID_Variable_output_range_492));
			_StrlSampleIndex(&ID_Variable_desiredWP_496,ADD_INDEX_SIZE(ID_Variable_output_range_492));
			_integer(&ID_Variable_sameindex_498,SUBTRACT_A_B(ID_Variable_evaluatedWP_495, ID_Variable_pendingWP_494));
			_integer(&ID_Variable_maxOutSize_499,GETMAXOUTSIZE(ID_InputOutput_Coder_module_43));
			if ((ID_Variable_sameindex_498 < 0)) {
				_integer(&ID_Variable_temp_int_500,error_exit(1));
			} else {
				if ((ID_Variable_sameindex_498 > 0)) {
					_integer(&ID_Variable_requestSize_497,SUBTRACT_A_B(ID_Variable_desiredWP_496, ID_Variable_evaluatedWP_495));
					_StrlSampleIndex(&ID_Variable_pendingWP_494,ID_Variable_evaluatedWP_495);
				} else {
					_integer(&ID_Variable_requestSize_497,SUBTRACT_A_B(ID_Variable_desiredWP_496, ID_Variable_pendingWP_494));
				}
			}
			if ((ID_Variable_requestSize_497 > ID_Variable_maxOutSize_499)) {
				_integer(&ID_Variable_requestSize_497,ID_Variable_maxOutSize_499);
			}
			_UnsignedInt(&ID_Variable_temp_unsigned_501,GET_OUTPUTSIZE(ID_InputOutput_Coder_module_43));
			_integer(&ID_Variable_requestSize_497,ROUNDOWN_SIZE(ID_Variable_requestSize_497, ID_Variable_temp_unsigned_501));
			_StrlSampleRange(&ID_Variable_output_range_492,SET_SAMPLERANGE(ID_Variable_pendingWP_494, ID_Variable_requestSize_497));
			_StrlSampleRange(&ID_Variable_inside_input_493,FORECASTS(ID_Variable_output_range_492, ID_InputOutput_Coder_module_43));
			_integer(&ID_Variable_temp_int_500,REAL_FIT_RANGE(ID_Variable_pendingWP_494, ID_Variable_requestSize_497, ID_Variable_inside_input_493, ID_InputOutput_Coder_module_43));
			LOCALINCAWAITTICK(ID_InputOutput_Coder_module_43);
			next_point_bit_vector[0] |= 0x200; /* PauseOn:  #9*/
		} else {
			next_point_bit_vector[4] |= 0x2000; /* PauseOn:  #141*/
		}
	}
}

static void Point_148() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_482,0)) {
		current_point_bit_vector[4] |= 0x200000; /* On:  #149*/
		next_point_bit_vector[0] |= 0x800; /* PauseOn:  #11*/
	} else {
		next_point_bit_vector[4] |= 0x100000; /* PauseOn:  #148*/
	}
}

static void Point_149() {
	EMIT(SIG_ID_Signal_Clock_Wire_S_M_118);
	next_point_bit_vector[4] |= 0x200000; /* PauseOn:  #149*/
}

static void Point_150() {
	if (IS_SIGNAL(SIG_ID_Signal_Compute_Wire_M_M1_110,0)) {
		_integer(&ID_Variable_temp_int_534,0);
		_integer(&ID_Variable_not_source_535,0);
		_integer(&ID_Variable_not_complete_flag_536,0);
		_StrlSampleIndex(&ID_Variable_temp_index_537,INITIAL_INDEX);
		_StrlSampleRange(&ID_Variable_temp_range_538,INITIAL_RANGE);
		_StrlSampleSize(&ID_Variable_complete_var_539,INITIAL_SIZE);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_540);
		CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_541);
		if (_eq_integer(CHECK_MYWRITERLL(ID_InputOutput_Mod_module_44),0)) {
			current_point_bit_vector[4] |= 0x2000000; /* On:  #153*/
		} else {
			if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_InputOutput_Mod_module_44),0)) {
				current_point_bit_vector[4] |= 0x1000000; /* On:  #152*/
			} else {
				if ((GET_NUMBERINPUTS(ID_InputOutput_Mod_module_44) > 0)) {
					_integer(&ID_Variable_not_source_535,1);
				}
				_StrlSampleSize(&ID_Variable_complete_var_539,REALCOMPUTEDATA(ID_InputOutput_Mod_module_44, ID_Variable_not_source_535));
				if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_InputOutput_Mod_module_44), ID_Variable_complete_var_539) > 0)) {
					_integer(&ID_Variable_not_complete_flag_536,(ID_Variable_not_complete_flag_536 - 1));
					current_point_bit_vector[4] |= 0x800000; /* On:  #151*/
				} else {
					current_point_bit_vector[4] |= 0x800000; /* On:  #151*/
				}
			}
		}
	} else {
		next_point_bit_vector[4] |= 0x400000; /* PauseOn:  #150*/
	}
}

static void Point_151() {
	if ((ID_Variable_not_complete_flag_536 < 0)) {
		_StrlSampleIndex(&ID_Variable_temp_index_537,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_InputOutput_Mod_module_44), ID_Variable_complete_var_539));
		SET_MARKEDWP(ID_InputOutput_Mod_module_44, ID_Variable_temp_index_537);
	}
	WRITEDATA(ID_InputOutput_Mod_module_44, ID_Variable_not_source_535);
	_StrlSampleIndex(&ID_Variable_temp_index_537,GETWP(ID_InputOutput_Mod_module_44));
	_StrlSampleRange(&ID_Output_MOD_COMPUTEDSR_50,GET_MYMARKEDDATA(ID_InputOutput_Mod_module_44));
	TC_UDP_TX_O_MOD_COMPUTEDSR(ID_Output_MOD_COMPUTEDSR_50); EMIT(SIG_ID_Output_MOD_COMPUTEDSR_50);
	current_point_bit_vector[4] |= 0x4000000; /* On:  #154*/
}

static void Point_152() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_540);
	current_point_bit_vector[4] |= 0x4000000; /* On:  #154*/
	current_point_bit_vector[4] &= ~0x800000; /* Off:  #151*/
}

static void Point_153() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_540);
	current_point_bit_vector[4] |= 0x4000000; /* On:  #154*/
	current_point_bit_vector[4] &= ~0x800000; /* Off:  #151*/
}

static void Point_154() {
	LOCALINCAWAITTICK(ID_InputOutput_Mod_module_44);
	next_point_bit_vector[0] |= 0x80000; /* PauseOn:  #19*/
}

static void Point_155() {
	if (IS_SIGNAL(SIG_ID_Signal_switch_on_482,0)) {
		EMIT(SIG_ID_Signal_Clock_Wire_S_M_118);
		next_point_bit_vector[0] |= 0x800; next_point_bit_vector[4] |= 0x200000; /* PauseOn:  #11 #149*/
	} else {
		next_point_bit_vector[4] |= 0x100000; /* PauseOn:  #148*/
	}
}

static void Point_156() {
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_S_M_113,0)) {
		_StrlSampleRange(&ID_Variable_my_output_420,ID_Signal_Ack_Wire_S_M_113);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_421,ID_Variable_my_output_420);
		EMIT(SIG_ID_Signal_My_Sample_Range_421);
		_StrlSampleRange(&ID_Variable_input_range_441,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_442,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_443,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_remainedWP_444,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_445,0);
		_integer(&ID_Variable_maxOutSize_446,0);
		_integer(&ID_Variable_temp_int_447,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_448,INITIAL_UNSIGNEDINT);
		current_point_bit_vector[4] |= 0x20000000; /* On:  #157*/
	} else {
		next_point_bit_vector[4] |= 0x10000000; /* PauseOn:  #156*/
	}
}

static void Point_157() {
	if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_421,0)) {
		_StrlSampleRange(&ID_Variable_input_range_441,ID_Signal_My_Sample_Range_421);
		_StrlSampleIndex(&ID_Variable_pendingWP_443,GETMARKEDWP(ID_InputOutput_Source_module_42));
		_StrlSampleIndex(&ID_Variable_remainedWP_444,ADD_INDEX_SIZE(ID_Variable_input_range_441));
		_integer(&ID_Variable_requestSize_445,SUBTRACT_A_B(ID_Variable_pendingWP_443, ID_Variable_remainedWP_444));
		if ((ID_Variable_requestSize_445 < 0)) {
			_integer(&ID_Variable_temp_int_447,error_exit(0));
		}
		_integer(&ID_Variable_maxOutSize_446,200);
		_integer(&ID_Variable_requestSize_445,(ID_Variable_maxOutSize_446 + ID_Variable_requestSize_445));
		if ((ID_Variable_requestSize_445 > ID_Variable_maxOutSize_446)) {
			_integer(&ID_Variable_requestSize_445,ID_Variable_maxOutSize_446);
		}
		if ((CMPULL(ID_Signal_Missed_Deadline_103, INITIAL_UNSIGNEDLL) > 0)) {
			SKIPPING_DATA(ID_Signal_Missed_Deadline_103);
			_StrlSampleIndex(&ID_Variable_pendingWP_443,SKIP_SAMPLEDATA(ID_Signal_Missed_Deadline_103, ID_Variable_pendingWP_443));
		}
		_UnsignedInt(&ID_Variable_temp_unsigned_448,GET_OUTPUTSIZE(ID_InputOutput_Source_module_42));
		_integer(&ID_Variable_requestSize_445,ROUNDOWN_SIZE(ID_Variable_requestSize_445, ID_Variable_temp_unsigned_448));
		_StrlSampleRange(&ID_Variable_output_range_442,SET_SAMPLERANGE(ID_Variable_pendingWP_443, ID_Variable_requestSize_445));
		_integer(&ID_Variable_temp_int_447,REAL_FIT_RANGE(ID_Variable_pendingWP_443, ID_Variable_requestSize_445, INITIAL_RANGE, ID_InputOutput_Source_module_42));
		LOCALINCAWAITTICK(ID_InputOutput_Source_module_42);
		next_point_bit_vector[0] |= 0x4; /* PauseOn:  #2*/
	} else {
		next_point_bit_vector[4] |= 0x20000000; /* PauseOn:  #157*/
	}
}

static void Point_158() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_S_M_118,0)) {
		next_point_bit_vector[4] |= 0x40000000; /* PauseOn:  #158*/
	} else {
		next_point_bit_vector[4] |= 0x80000000; next_point_bit_vector[5] |= 0x1; /* PauseOn:  #159 #160*/
	}
}

static void Point_159() {
	if (IS_SIGNAL(SIG_ID_Signal_Clock_Wire_S_M_118,0)) {
		next_point_bit_vector[5] |= current_point_bit_vector[5] & 0x1; current_point_bit_vector[5] &= ~0x1; /* Suspend:  #160*/
		next_point_bit_vector[4] |= 0x80000000; /* PauseOn:  #159*/
	} else {
		next_point_bit_vector[4] |= 0x80000000; /* PauseOn:  #159*/
	}
}

static void Point_160() {
	EMIT(SIG_ID_Exception_main_loop_473);
	EMIT(SIG_ID_Signal_Compute_Wire_S_M_109);
	next_point_bit_vector[4] &= ~0x80000000; next_point_bit_vector[5] &= ~0x1; /* PauseOff:  #159 #160*/
	if (IS_SIGNAL(SIG_ID_Signal_Ack_Wire_S_M_113,0)) {
		_StrlSampleRange(&ID_Variable_my_output_420,ID_Signal_Ack_Wire_S_M_113);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_421,ID_Variable_my_output_420);
		EMIT(SIG_ID_Signal_My_Sample_Range_421);
		_StrlSampleRange(&ID_Variable_input_range_441,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_output_range_442,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_443,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_remainedWP_444,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_445,0);
		_integer(&ID_Variable_maxOutSize_446,0);
		_integer(&ID_Variable_temp_int_447,0);
		_UnsignedInt(&ID_Variable_temp_unsigned_448,INITIAL_UNSIGNEDINT);
		if (IS_SIGNAL(SIG_ID_Signal_My_Sample_Range_421,0)) {
			_StrlSampleRange(&ID_Variable_input_range_441,ID_Signal_My_Sample_Range_421);
			_StrlSampleIndex(&ID_Variable_pendingWP_443,GETMARKEDWP(ID_InputOutput_Source_module_42));
			_StrlSampleIndex(&ID_Variable_remainedWP_444,ADD_INDEX_SIZE(ID_Variable_input_range_441));
			_integer(&ID_Variable_requestSize_445,SUBTRACT_A_B(ID_Variable_pendingWP_443, ID_Variable_remainedWP_444));
			if ((ID_Variable_requestSize_445 < 0)) {
				_integer(&ID_Variable_temp_int_447,error_exit(0));
			}
			_integer(&ID_Variable_maxOutSize_446,200);
			_integer(&ID_Variable_requestSize_445,(ID_Variable_maxOutSize_446 + ID_Variable_requestSize_445));
			if ((ID_Variable_requestSize_445 > ID_Variable_maxOutSize_446)) {
				_integer(&ID_Variable_requestSize_445,ID_Variable_maxOutSize_446);
			}
			if ((CMPULL(ID_Signal_Missed_Deadline_103, INITIAL_UNSIGNEDLL) > 0)) {
				SKIPPING_DATA(ID_Signal_Missed_Deadline_103);
				_StrlSampleIndex(&ID_Variable_pendingWP_443,SKIP_SAMPLEDATA(ID_Signal_Missed_Deadline_103, ID_Variable_pendingWP_443));
			}
			_UnsignedInt(&ID_Variable_temp_unsigned_448,GET_OUTPUTSIZE(ID_InputOutput_Source_module_42));
			_integer(&ID_Variable_requestSize_445,ROUNDOWN_SIZE(ID_Variable_requestSize_445, ID_Variable_temp_unsigned_448));
			_StrlSampleRange(&ID_Variable_output_range_442,SET_SAMPLERANGE(ID_Variable_pendingWP_443, ID_Variable_requestSize_445));
			_integer(&ID_Variable_temp_int_447,REAL_FIT_RANGE(ID_Variable_pendingWP_443, ID_Variable_requestSize_445, INITIAL_RANGE, ID_InputOutput_Source_module_42));
			LOCALINCAWAITTICK(ID_InputOutput_Source_module_42);
			next_point_bit_vector[0] |= 0x4; /* PauseOn:  #2*/
		} else {
			next_point_bit_vector[4] |= 0x20000000; /* PauseOn:  #157*/
		}
	} else {
		next_point_bit_vector[4] |= 0x10000000; /* PauseOn:  #156*/
	}
}

static void Point_161() {
	if (IS_SIGNAL(SIG_ID_Signal_Compute_Wire_S_M_109,0)) {
		_integer(&ID_Variable_temp_int_502,0);
		_integer(&ID_Variable_not_source_503,0);
		_integer(&ID_Variable_not_complete_flag_504,0);
		_StrlSampleIndex(&ID_Variable_temp_index_505,INITIAL_INDEX);
		_StrlSampleRange(&ID_Variable_temp_range_506,INITIAL_RANGE);
		_StrlSampleSize(&ID_Variable_complete_var_507,INITIAL_SIZE);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_508);
		CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_509);
		if (_eq_integer(CHECK_MYWRITERLL(ID_InputOutput_Coder_module_43),0)) {
			current_point_bit_vector[5] |= 0x10; /* On:  #164*/
		} else {
			if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_InputOutput_Coder_module_43),0)) {
				current_point_bit_vector[5] |= 0x8; /* On:  #163*/
			} else {
				if ((GET_NUMBERINPUTS(ID_InputOutput_Coder_module_43) > 0)) {
					_integer(&ID_Variable_not_source_503,1);
				}
				_StrlSampleSize(&ID_Variable_complete_var_507,REALCOMPUTEDATA(ID_InputOutput_Coder_module_43, ID_Variable_not_source_503));
				if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_InputOutput_Coder_module_43), ID_Variable_complete_var_507) > 0)) {
					_integer(&ID_Variable_not_complete_flag_504,(ID_Variable_not_complete_flag_504 - 1));
					current_point_bit_vector[5] |= 0x4; /* On:  #162*/
				} else {
					current_point_bit_vector[5] |= 0x4; /* On:  #162*/
				}
			}
		}
	} else {
		next_point_bit_vector[5] |= 0x2; /* PauseOn:  #161*/
	}
}

static void Point_162() {
	if ((ID_Variable_not_complete_flag_504 < 0)) {
		_StrlSampleIndex(&ID_Variable_temp_index_505,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_InputOutput_Coder_module_43), ID_Variable_complete_var_507));
		SET_MARKEDWP(ID_InputOutput_Coder_module_43, ID_Variable_temp_index_505);
	}
	WRITEDATA(ID_InputOutput_Coder_module_43, ID_Variable_not_source_503);
	_StrlSampleIndex(&ID_Variable_temp_index_505,GETWP(ID_InputOutput_Coder_module_43));
	_StrlSampleRange(&ID_Output_CODER_COMPUTEDSR_49,GET_MYMARKEDDATA(ID_InputOutput_Coder_module_43));
	TC_UDP_TX_O_CODER_COMPUTEDSR(ID_Output_CODER_COMPUTEDSR_49); EMIT(SIG_ID_Output_CODER_COMPUTEDSR_49);
	current_point_bit_vector[5] |= 0x20; /* On:  #165*/
}

static void Point_163() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_508);
	current_point_bit_vector[5] |= 0x20; /* On:  #165*/
	current_point_bit_vector[5] &= ~0x4; /* Off:  #162*/
}

static void Point_164() {
	EMIT(SIG_ID_Exception_EXIT_FUNC_508);
	current_point_bit_vector[5] |= 0x20; /* On:  #165*/
	current_point_bit_vector[5] &= ~0x4; /* Off:  #162*/
}

static void Point_165() {
	LOCALINCAWAITTICK(ID_InputOutput_Coder_module_43);
	next_point_bit_vector[0] |= 0x400; /* PauseOn:  #10*/
}


int TC_UDP_TX() {
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
		if ((*current_point_ptr) & 0x40000000) {
			Point_158();
		}
		if ((*current_point_ptr) & 0x80000000) {
			Point_159();
		}
	}
	current_point_ptr++;
	if (*current_point_ptr) {
		if ((*current_point_ptr) & 0x1) {
			Point_160();
		}
		if ((*current_point_ptr) & 0x2) {
			Point_161();
		}
		if ((*current_point_ptr) & 0x4) {
			Point_162();
		}
		if ((*current_point_ptr) & 0x8) {
			Point_163();
		}
		if ((*current_point_ptr) & 0x10) {
			Point_164();
		}
		if ((*current_point_ptr) & 0x20) {
			Point_165();
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

int TC_UDP_TX_reset() {
	int i,j;
	
	if (!ID_Signal_R_Name_603) ID_Signal_R_Name_603 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Signal_R_Name_572) ID_Signal_R_Name_572 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_My_Name_565) ID_Variable_My_Name_565 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Signal_R_Name_552) ID_Signal_R_Name_552 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Signal_R_Name_518) ID_Signal_R_Name_518 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Signal_R_Name_484) ID_Signal_R_Name_484 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_My_Name_477) ID_Variable_My_Name_477 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Signal_R_Name_422) ID_Signal_R_Name_422 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofsink_87) ID_Variable_nameofsink_87 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofscopesink_86) ID_Variable_nameofscopesink_86 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofsummer_85) ID_Variable_nameofsummer_85 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofmod_84) ID_Variable_nameofmod_84 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofcoder_83) ID_Variable_nameofcoder_83 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofsource_82) ID_Variable_nameofsource_82 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_InputOutput_Sink_module_47) ID_InputOutput_Sink_module_47 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_InputOutput_Scopesink_module_46) ID_InputOutput_Scopesink_module_46 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_InputOutput_Summer_module_45) ID_InputOutput_Summer_module_45 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_InputOutput_Mod_module_44) ID_InputOutput_Mod_module_44 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_InputOutput_Coder_module_43) ID_InputOutput_Coder_module_43 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_InputOutput_Source_module_42) ID_InputOutput_Source_module_42 = (string) calloc(STRLEN,sizeof(char));
	for (i = 0 ; i < SIGNAL_VECTOR_SIZE; i++) signal_bit_vector[i] = 0;
	for (i = 0 ; i < HALT_POINT_VECTOR_SIZE; i++) current_point_bit_vector[i] = next_point_bit_vector[i];
	for (i = 0 ; i < HALT_POINT_VECTOR_SIZE; i++) next_point_bit_vector[i] = 0;
	BIT_SET(current_point_bit_vector, 0);
}
