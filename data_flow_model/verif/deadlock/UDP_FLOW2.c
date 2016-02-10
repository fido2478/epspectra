/* sscc : C CODE OF SORTED EQUATIONS UDP_FLOW - SIMULATION MODE */

/* AUXILIARY DECLARATIONS */

#ifndef STRLEN
#define STRLEN 81
#endif
#define _COND(A,B,C) ((A)?(B):(C))
#ifdef TRACE_ACTION
#include <stdio.h>
#endif
#ifndef NULL
#define NULL ((char*)0)
#endif

#ifndef __EXEC_STATUS_H_LOADED
#define __EXEC_STATUS_H_LOADED

typedef struct {
unsigned int start:1;
unsigned int kill:1;
unsigned int active:1;
unsigned int suspended:1;
unsigned int prev_active:1;
unsigned int prev_suspended:1;
unsigned int exec_index;
unsigned int task_exec_index;
void (*pStart)();
void (*pRet)();
} __ExecStatus;

#endif
#define __ResetExecStatus(status) {\
   status.prev_active = status.active; \
   status.prev_suspended = status.suspended; \
   status.start = status.kill = status.active = status.suspended = 0; }
#define __DSZ(V) (--(V)<=0)
#define BASIC_TYPES_DEFINED
typedef int boolean;
typedef int integer;
typedef char* string;
#define CSIMUL_H_LOADED
typedef struct {char text[STRLEN];} symbolic;
extern void _boolean(boolean*, boolean);
extern boolean _eq_boolean(boolean, boolean);
extern boolean _ne_boolean(boolean, boolean);
extern boolean _cond_boolean(boolean ,boolean ,boolean);
extern char* _boolean_to_text(boolean);
extern int _check_boolean(char*);
extern void _text_to_boolean(boolean*, char*);
extern void _integer(integer*, integer);
extern boolean _eq_integer(integer, integer);
extern boolean _ne_integer(integer, integer);
extern integer _cond_integer(boolean ,integer ,integer);
extern char* _integer_to_text(integer);
extern int _check_integer(char*);
extern void _text_to_integer(integer*, char*);
extern void _string(string, string);
extern boolean _eq_string(string, string);
extern boolean _ne_string(string, string);
extern string _cond_string(boolean ,string ,string);
extern char* _string_to_text(string);
extern int _check_string(char*);
extern void _text_to_string(string, char*);
extern void _float(float*, float);
extern boolean _eq_float(float, float);
extern boolean _ne_float(float, float);
extern float _cond_float(boolean ,float ,float);
extern char* _float_to_text(float);
extern int _check_float(char*);
extern void _text_to_float(float*, char*);
extern void _double(double*, double);
extern boolean _eq_double(double, double);
extern boolean _ne_double(double, double);
extern double _cond_double(boolean ,double ,double);
extern char* _double_to_text(double);
extern int _check_double(char*);
extern void _text_to_double(double*, char*);
extern void _symbolic(symbolic*, symbolic);
extern boolean _eq_symbolic(symbolic, symbolic);
extern boolean _ne_symbolic(symbolic, symbolic);
extern symbolic _cond_symbolic(boolean ,symbolic ,symbolic);
extern char* _symbolic_to_text(symbolic);
extern int _check_symbolic(char*);
extern void _text_to_symbolic(symbolic*, char*);
extern char* __PredefinedTypeToText(int, char*);
#define _true 1
#define _false 0
#define __UDP_FLOW_GENERIC_TEST(TEST) return TEST;
typedef void (*__UDP_FLOW_APF)();
static __UDP_FLOW_APF *__UDP_FLOW_PActionArray;
static int **__UDP_FLOW_PCheckArray;
struct __SourcePoint {
int linkback;
int line;
int column;
int instance_index;
};
struct __InstanceEntry {
char *module_name;
int father_index;
char *dir_name;
char *file_name;
struct __SourcePoint source_point;
struct __SourcePoint end_point;
struct __SourcePoint instance_point;
};
struct __TaskEntry {
char *name;
int   nb_args_ref;
int   nb_args_val;
int  *type_codes_array;
struct __SourcePoint source_point;
};
struct __SignalEntry {
char *name;
int code;
int variable_index;
int present;
struct __SourcePoint source_point;
int number_of_emit_source_points;
struct __SourcePoint* emit_source_point_array;
int number_of_present_source_points;
struct __SourcePoint* present_source_point_array;
int number_of_access_source_points;
struct __SourcePoint* access_source_point_array;
};
struct __InputEntry {
char *name;
int hash;
char *type_name;
int is_a_sensor;
int type_code;
int multiple;
int signal_index;
int (*p_check_input)(char*);
void (*p_input_function)();
int present;
struct __SourcePoint source_point;
};
struct __ReturnEntry {
char *name;
int hash;
char *type_name;
int type_code;
int signal_index;
int exec_index;
int (*p_check_input)(char*);
void (*p_input_function)();
int present;
struct __SourcePoint source_point;
};
struct __ImplicationEntry {
int master;
int slave;
struct __SourcePoint source_point;
};
struct __ExclusionEntry {
int *exclusion_list;
struct __SourcePoint source_point;
};
struct __VariableEntry {
char *full_name;
char *short_name;
char *type_name;
int type_code;
int comment_kind;
int is_initialized;
char *p_variable;
char *source_name;
int written;
unsigned char written_in_transition;
unsigned char read_in_transition;
struct __SourcePoint source_point;
};
struct __ExecEntry {
int task_index;
int *var_indexes_array;
char **p_values_array;
struct __SourcePoint source_point;
};
struct __HaltEntry {
struct __SourcePoint source_point;
};
struct __NetEntry {
int known;
int value;
int number_of_source_points;
struct __SourcePoint* source_point_array;
};
struct __ModuleEntry {
char *version_id;
char *name;
int number_of_instances;
int number_of_tasks;
int number_of_signals;
int number_of_inputs;
int number_of_returns;
int number_of_sensors;
int number_of_outputs;
int number_of_locals;
int number_of_exceptions;
int number_of_implications;
int number_of_exclusions;
int number_of_variables;
int number_of_execs;
int number_of_halts;
int number_of_nets;
int number_of_states;
int state;
unsigned short *halt_list;
unsigned short *awaited_list;
unsigned short *emitted_list;
unsigned short *started_list;
unsigned short *killed_list;
unsigned short *suspended_list;
unsigned short *active_list;
int run_time_error_code;
int error_info;
void (*init)();
int (*run)();
int (*reset)();
char *(*show_variable)(int);
void (*set_variable)(int, char*, char*);
int (*check_value)(int, char*);
int (*execute_action)();
struct __InstanceEntry* instance_table;
struct __TaskEntry* task_table;
struct __SignalEntry* signal_table;
struct __InputEntry* input_table;
struct __ReturnEntry* return_table;
struct __ImplicationEntry* implication_table;
struct __ExclusionEntry* exclusion_table;
struct __VariableEntry* variable_table;
struct __ExecEntry* exec_table;
struct __HaltEntry* halt_table;
struct __NetEntry* net_table;
};

                       
/* EXTERN DECLARATIONS */

extern int __CheckVariables(int*);
extern void __ResetInput();
extern void __ResetExecs();
extern void __ResetVariables();
extern void __ResetVariableStatus();
extern void __AppendToList(unsigned short*, unsigned short);
extern void __ListCopy(unsigned short*, unsigned short**);
extern void __WriteVariable(int);
extern void __ResetVariable(int);
extern void __ResetModuleEntry();
extern void __ResetModuleEntryBeforeReaction();
extern void __ResetModuleEntryAfterReaction();
#ifndef _NO_EXTERN_DEFINITIONS
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static boolean __UDP_FLOW_V0;
static boolean __UDP_FLOW_V1;
static boolean __UDP_FLOW_V2;

static unsigned short __UDP_FLOW_HaltList[44];
static unsigned short __UDP_FLOW_AwaitedList[26];
static unsigned short __UDP_FLOW_EmittedList[26];
static unsigned short __UDP_FLOW_StartedList[1];
static unsigned short __UDP_FLOW_KilledList[1];
static unsigned short __UDP_FLOW_SuspendedList[1];
static unsigned short __UDP_FLOW_ActiveList[1];
static unsigned short __UDP_FLOW_AllAwaitedList[26]={1,0};


/* INPUT FUNCTIONS */

void UDP_FLOW_I_User_Quit () {
__UDP_FLOW_V0 = _true;
}
void UDP_FLOW_IS_User_Quit () {
__UDP_FLOW_V0 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int UDP_FLOW_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __UDP_FLOW_A1 () {
__UDP_FLOW_GENERIC_TEST(__UDP_FLOW_V0);
}
static int __UDP_FLOW_Check1 [] = {1,0,0};

/* OUTPUT ACTIONS */

/* ASSIGNMENTS */

static void __UDP_FLOW_A2 () {
__UDP_FLOW_V0 = _false;
}
static int __UDP_FLOW_Check2 [] = {1,0,1,0};
static void __UDP_FLOW_A3 () {
__UDP_FLOW_V1 = _true;
}
static int __UDP_FLOW_Check3 [] = {1,0,1,1};
static void __UDP_FLOW_A4 () {
__UDP_FLOW_V1 = _false;
}
static int __UDP_FLOW_Check4 [] = {1,0,1,1};
static void __UDP_FLOW_A5 () {
__UDP_FLOW_V2 = _true;
}
static int __UDP_FLOW_Check5 [] = {1,0,1,2};
static void __UDP_FLOW_A6 () {
__UDP_FLOW_V2 = _false;
}
static int __UDP_FLOW_Check6 [] = {1,0,1,2};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __UDP_FLOW_A7 () {
__UDP_FLOW_GENERIC_TEST(__UDP_FLOW_V1);
}
static int __UDP_FLOW_Check7 [] = {1,1,1,0};
static int __UDP_FLOW_A8 () {
__UDP_FLOW_GENERIC_TEST(__UDP_FLOW_V2);
}
static int __UDP_FLOW_Check8 [] = {1,1,2,0};

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

/* ACTION SEQUENCES */


static int *__UDP_FLOW_CheckArray[] = {
0,
__UDP_FLOW_Check1,
__UDP_FLOW_Check2,
__UDP_FLOW_Check3,
__UDP_FLOW_Check4,
__UDP_FLOW_Check5,
__UDP_FLOW_Check6,
__UDP_FLOW_Check7,
__UDP_FLOW_Check8
};
static int **__UDP_FLOW_PCheckArray =  __UDP_FLOW_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void UDP_FLOW_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __UDP_FLOW_show_variable (int __V) {
extern struct __VariableEntry __UDP_FLOW_VariableTable[];
struct __VariableEntry* p_var = &__UDP_FLOW_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __UDP_FLOW_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __UDP_FLOW_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __UDP_FLOW_InstanceTable [] = {
{"UDP_FLOW",0,"","UDP_FLOW.strl",{1,6,1,0},{1,64,1,0},{0,0,0,0}},
{"source1",0,"","SOURCE.strl",{1,6,1,1},{1,26,1,1},{1,30,7,0}},
{"MARK_DATA",1,"","MARK_DATA_VER2.strl",{1,5,1,2},{1,14,1,2},{1,18,7,1}},
{"COMPUTE_DATA",1,"","COMPUTE_DATA_VER2.strl",{1,5,1,3},{1,13,1,3},{1,21,7,1}},
{"TIMER",1,"","TIMER.strl",{1,8,1,4},{1,19,1,4},{1,22,7,1}},
{"module1",0,"","P_MOD.strl",{1,5,1,5},{1,49,1,5},{1,36,7,0}},
{"WAIT_SIG",5,"","WAIT_SIG.strl",{1,1,1,6},{1,24,1,6},{1,29,6,5}},
{"MARK_DATA",5,"","MARK_DATA_VER2.strl",{1,5,1,7},{1,14,1,7},{1,32,3,5}},
{"COMPUTE_DATA",5,"","COMPUTE_DATA_VER2.strl",{1,5,1,8},{1,13,1,8},{1,37,3,5}},
{"TIMER",5,"","TIMER.strl",{1,8,1,9},{1,19,1,9},{1,38,3,5}},
{"SWITCH",5,"","SWITCH_VER2.strl",{1,6,1,10},{1,18,1,10},{1,43,7,5}},
{"module2",0,"","P_MOD.strl",{1,5,1,11},{1,49,1,11},{1,46,7,0}},
{"WAIT_SIG",11,"","WAIT_SIG.strl",{1,1,1,12},{1,24,1,12},{1,29,6,11}},
{"MARK_DATA",11,"","MARK_DATA_VER2.strl",{1,5,1,13},{1,14,1,13},{1,32,3,11}},
{"COMPUTE_DATA",11,"","COMPUTE_DATA_VER2.strl",{1,5,1,14},{1,13,1,14},{1,37,3,11}},
{"TIMER",11,"","TIMER.strl",{1,8,1,15},{1,19,1,15},{1,38,3,11}},
{"SWITCH",11,"","SWITCH_VER2.strl",{1,6,1,16},{1,18,1,16},{1,43,7,11}},
{"sink1",0,"","SINK.strl",{1,5,1,17},{1,34,1,17},{1,56,7,0}},
{"MARK_DATA",17,"","MARK_DATA_VER2.strl",{1,5,1,18},{1,14,1,18},{1,21,3,17}},
{"COMPUTE_DATA",17,"","COMPUTE_DATA_VER2.strl",{1,5,1,19},{1,13,1,19},{1,25,3,17}},
{"SWITCH",17,"","SWITCH_VER2.strl",{1,6,1,20},{1,18,1,20},{1,29,7,17}},
};

struct __SignalEntry __UDP_FLOW_SignalTable [] = {
{"User_Quit",33,0,0,{1,12,7,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Trigger",40,0,0,{1,17,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Mark_Wire_S_M",40,0,0,{1,18,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Mark_Wire_M_M1",40,0,0,{1,18,23,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Mark_Wire_M_S1",40,0,0,{1,19,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Compute_Wire_S_M",40,0,0,{1,20,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Compute_Wire_M_M1",40,0,0,{1,20,26,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Compute_Wire_M_S1",40,0,0,{1,21,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Ack_Wire_S_M",40,0,0,{1,22,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Ack_Wire_M_M1",40,0,0,{1,22,22,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Ack_Wire_M_S1",40,0,0,{1,23,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Clock_Wire_S_M",40,0,0,{1,24,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Clock_Wire_M_M1",40,0,0,{1,24,24,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Clock_Wire_M_S1",40,0,0,{1,25,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"main_loop",48,0,0,{1,12,6,4},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"switch_on",40,0,0,{1,21,8,5},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"switch_off",40,0,0,{1,21,19,5},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"main_trap",48,0,0,{1,5,6,6},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"main_loop",48,0,0,{1,12,6,9},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"switch_on",40,0,0,{1,21,8,11},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"switch_off",40,0,0,{1,21,19,11},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"main_trap",48,0,0,{1,5,6,12},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"main_loop",48,0,0,{1,12,6,15},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"switch_on",40,0,0,{1,16,8,17},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"switch_off",40,0,0,{1,16,19,17},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __UDP_FLOW_InputTable [] = {
{"User_Quit",20,0,0,-1,0,0,0,UDP_FLOW_IS_User_Quit,0,{1,12,7,0}}};

struct __VariableEntry __UDP_FLOW_VariableTable [] = {
{"__UDP_FLOW_V0","V0","boolean",-2,2,0,(char*)&__UDP_FLOW_V0,"User_Quit",0,0,0,{1,12,7,0}},
{"__UDP_FLOW_V1","V1","boolean",-2,0,0,(char*)&__UDP_FLOW_V1,"INI_FLAG",0,0,0,{1,20,5,5}},
{"__UDP_FLOW_V2","V2","boolean",-2,0,0,(char*)&__UDP_FLOW_V2,"INI_FLAG",0,0,0,{1,20,5,11}}
};

struct __HaltEntry __UDP_FLOW_HaltTable [] = {
{{1,64,1,0}},
{{1,17,4,1}},
{{1,11,1,2}},
{{1,12,1,2}},
{{1,13,1,2}},
{{1,11,1,3}},
{{1,12,1,3}},
{{1,16,7,4}},
{{1,27,6,5}},
{{1,36,3,5}},
{{1,8,3,6}},
{{1,13,3,6}},
{{1,21,7,6}},
{{1,11,1,7}},
{{1,12,1,7}},
{{1,13,1,7}},
{{1,11,1,8}},
{{1,12,1,8}},
{{1,16,7,9}},
{{1,13,4,10}},
{{1,15,7,10}},
{{1,27,6,11}},
{{1,36,3,11}},
{{1,8,3,12}},
{{1,13,3,12}},
{{1,21,7,12}},
{{1,11,1,13}},
{{1,12,1,13}},
{{1,13,1,13}},
{{1,11,1,14}},
{{1,12,1,14}},
{{1,16,7,15}},
{{1,13,4,16}},
{{1,15,7,16}},
{{1,19,3,17}},
{{1,24,3,17}},
{{1,11,1,18}},
{{1,12,1,18}},
{{1,13,1,18}},
{{1,11,1,19}},
{{1,12,1,19}},
{{1,13,4,20}},
{{1,15,7,20}}
};


static void __UDP_FLOW__reset_input () {
__UDP_FLOW_V0 = _false;
}


/* MODULE DATA FOR SIMULATION */

int UDP_FLOW();
int UDP_FLOW_reset();

static struct __ModuleEntry __UDP_FLOW_ModuleData = {
"Simulation interface release 5","UDP_FLOW",
21,0,25,1,0,0,0,19,5,0,0,3,0,43,0,0,0,
__UDP_FLOW_HaltList,
__UDP_FLOW_AwaitedList,
__UDP_FLOW_EmittedList,
__UDP_FLOW_StartedList,
__UDP_FLOW_KilledList,
__UDP_FLOW_SuspendedList,
__UDP_FLOW_ActiveList,
0,0,
UDP_FLOW_initialize,UDP_FLOW,UDP_FLOW_reset,
__UDP_FLOW_show_variable,__UDP_FLOW_set_variable,__UDP_FLOW_check_value,0,
__UDP_FLOW_InstanceTable,
0,
__UDP_FLOW_SignalTable,__UDP_FLOW_InputTable,0,
0,0,
__UDP_FLOW_VariableTable,
0,
__UDP_FLOW_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __UDP_FLOW_R[43] = {_true,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int UDP_FLOW () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[64];

__UDP_FLOW_ModuleData.awaited_list = __UDP_FLOW_AwaitedList;
__ResetModuleEntryBeforeReaction();
if (__UDP_FLOW_R[0]) {
__CheckVariables(__UDP_FLOW_CheckArray[5]);__UDP_FLOW_A5();
#ifdef TRACE_ACTION
fprintf(stderr, "__UDP_FLOW_A5\n");
#endif
}
if (__UDP_FLOW_R[0]) {
__CheckVariables(__UDP_FLOW_CheckArray[3]);__UDP_FLOW_A3();
#ifdef TRACE_ACTION
fprintf(stderr, "__UDP_FLOW_A3\n");
#endif
}
E[0] = __UDP_FLOW_R[12]||__UDP_FLOW_R[11]||__UDP_FLOW_R[10];
E[1] = __UDP_FLOW_R[18]||__UDP_FLOW_R[17]||__UDP_FLOW_R[16]||__UDP_FLOW_R[15]||__UDP_FLOW_R[14]||__UDP_FLOW_R[13]||__UDP_FLOW_R[9]||__UDP_FLOW_R[8]||E[0];
E[2] = __UDP_FLOW_R[19]||__UDP_FLOW_R[20];
E[3] = E[2]||E[1];
E[4] = __UDP_FLOW_R[25]||__UDP_FLOW_R[24]||__UDP_FLOW_R[23];
E[5] = __UDP_FLOW_R[31]||__UDP_FLOW_R[30]||__UDP_FLOW_R[29]||__UDP_FLOW_R[28]||__UDP_FLOW_R[27]||__UDP_FLOW_R[26]||__UDP_FLOW_R[22]||__UDP_FLOW_R[21]||E[4];
E[6] = __UDP_FLOW_R[32]||__UDP_FLOW_R[33];
E[7] = E[6]||E[5];
E[8] = __UDP_FLOW_R[40]||__UDP_FLOW_R[39]||__UDP_FLOW_R[38]||__UDP_FLOW_R[37]||__UDP_FLOW_R[36]||__UDP_FLOW_R[35]||__UDP_FLOW_R[34];
E[9] = __UDP_FLOW_R[41]||__UDP_FLOW_R[42];
E[10] = E[9]||E[8];
E[11] = __UDP_FLOW_R[1]||__UDP_FLOW_R[3]||__UDP_FLOW_R[2]||__UDP_FLOW_R[7]||__UDP_FLOW_R[6]||__UDP_FLOW_R[5]||__UDP_FLOW_R[4];
E[12] = E[11]||E[10]||E[7]||E[3];
E[13] = !(__UDP_FLOW_R[0])&&E[12];
E[14] = !((__CheckVariables(__UDP_FLOW_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__UDP_FLOW_A1()))&&E[13];
E[15] = E[14]&&__UDP_FLOW_R[28];
E[16] = E[14]&&__UDP_FLOW_R[34];
E[17] = E[16]&&E[15];
E[18] = E[14]&&__UDP_FLOW_R[41];
E[19] = E[14]&&__UDP_FLOW_R[38];
E[20] = E[14]&&__UDP_FLOW_R[42];
__UDP_FLOW_R[42] = (E[20]&&!(E[19])&&__UDP_FLOW_R[42])||(E[18]&&E[17]);
E[21] = E[14]&&__UDP_FLOW_R[31];
E[22] = E[14]&&__UDP_FLOW_R[30];
E[23] = (E[22]&&!(__UDP_FLOW_R[42]))||(E[21]&&!(__UDP_FLOW_R[42]));
E[24] = E[23]||__UDP_FLOW_R[0];
E[25] = E[24]&&(__CheckVariables(__UDP_FLOW_CheckArray[8]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__UDP_FLOW_A8());
E[25] = E[25]&&E[24];
if (E[25]) {
__CheckVariables(__UDP_FLOW_CheckArray[6]);__UDP_FLOW_A6();
#ifdef TRACE_ACTION
fprintf(stderr, "__UDP_FLOW_A6\n");
#endif
}
E[26] = E[14]&&__UDP_FLOW_R[32];
E[27] = E[14]&&__UDP_FLOW_R[33];
__UDP_FLOW_R[33] = (E[27]&&!(E[15])&&__UDP_FLOW_R[33])||(E[26]&&E[24]);
E[28] = E[14]&&__UDP_FLOW_R[18];
E[29] = E[14]&&__UDP_FLOW_R[17];
E[30] = (E[29]&&!(__UDP_FLOW_R[33]))||(E[28]&&!(__UDP_FLOW_R[33]));
E[31] = E[30]||__UDP_FLOW_R[0];
E[32] = E[31]&&(__CheckVariables(__UDP_FLOW_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__UDP_FLOW_A7());
E[32] = E[32]&&E[31];
if (E[32]) {
__CheckVariables(__UDP_FLOW_CheckArray[4]);__UDP_FLOW_A4();
#ifdef TRACE_ACTION
fprintf(stderr, "__UDP_FLOW_A4\n");
#endif
}
E[13] = (__CheckVariables(__UDP_FLOW_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__UDP_FLOW_A1())&&E[13];
E[13] = E[13];
E[33] = E[14]&&E[11];
E[34] = E[33]&&!(E[31]);
E[35] = E[34]&&__UDP_FLOW_R[4];
E[36] = E[14]&&__UDP_FLOW_R[8];
E[37] = E[14]&&__UDP_FLOW_R[12];
E[38] = (E[0]&&!(__UDP_FLOW_R[12]))||E[37];
E[39] = E[14]&&__UDP_FLOW_R[11];
E[40] = E[39]&&E[35];
E[41] = E[0]&&!(__UDP_FLOW_R[11]);
E[39] = E[39]&&!(E[35])&&__UDP_FLOW_R[11];
E[42] = E[39]||E[41];
E[43] = E[14]&&__UDP_FLOW_R[10];
E[44] = E[43]&&E[23];
E[45] = E[0]&&!(__UDP_FLOW_R[10]);
E[43] = E[43]&&!(E[23])&&__UDP_FLOW_R[10];
E[46] = E[43]||E[45];
E[37] = (E[41]&&E[45]&&E[38]&&E[37]&&E[0])||(!(E[32])&&E[31]);
E[45] = E[35]&&E[37];
E[41] = (!(E[35])&&E[37])||E[45];
E[47] = E[37]&&E[23];
E[48] = (E[37]&&!(E[23]))||E[47];
E[49] = E[35]&&E[23];
E[50] = E[49]&&E[37];
E[49] = !(E[49])&&E[37];
E[51] = (E[36]&&E[35])||((E[46]||E[44])&&(E[44]||E[40])&&(E[40]||E[42])&&E[38]&&E[0])||((E[49]||E[50])&&E[50]&&E[48]&&E[41]&&E[37]);
E[41] = ((E[43]||E[39])&&E[46]&&E[42]&&E[38]&&E[0])||((E[47]||E[45]||E[37])&&E[49]&&E[48]&&E[41]&&E[37]);
E[48] = E[14]&&__UDP_FLOW_R[19];
E[49] = E[14]&&__UDP_FLOW_R[15];
E[0] = E[14]&&__UDP_FLOW_R[20];
__UDP_FLOW_R[20] = (E[0]&&!(E[49])&&__UDP_FLOW_R[20])||(E[48]&&E[31]);
E[38] = E[34]&&__UDP_FLOW_R[7];
E[42] = E[34]&&__UDP_FLOW_R[6];
E[46] = (E[42]&&!(__UDP_FLOW_R[20]))||(E[38]&&!(__UDP_FLOW_R[20]));
E[52] = E[14]&&__UDP_FLOW_R[9];
__UDP_FLOW_R[9] = (!(E[46])&&E[49])||(E[52]&&!(E[46])&&__UDP_FLOW_R[9]);
E[52] = (E[46]&&E[49])||(E[52]&&E[46]);
__UDP_FLOW_R[8] = (E[36]&&!(E[35])&&__UDP_FLOW_R[8])||E[32];
__UDP_FLOW_R[19] = (E[0]&&E[49])||(E[48]&&!(E[31])&&__UDP_FLOW_R[19])||__UDP_FLOW_R[0];
__UDP_FLOW_R[18] = (E[29]&&__UDP_FLOW_R[33])||(E[28]&&__UDP_FLOW_R[33]&&__UDP_FLOW_R[18]);
E[28] = E[14]&&__UDP_FLOW_R[13];
__UDP_FLOW_R[15] = E[14]&&__UDP_FLOW_R[14];
__UDP_FLOW_R[17] = E[14]&&__UDP_FLOW_R[16];
E[41] = ((E[3]&&!(E[2]))||__UDP_FLOW_R[19]||__UDP_FLOW_R[20])&&((E[3]&&!(E[1]))||__UDP_FLOW_R[17]||__UDP_FLOW_R[15]||E[28]||__UDP_FLOW_R[18]||__UDP_FLOW_R[8]||E[52]||__UDP_FLOW_R[9]||E[41]||E[51])&&(__UDP_FLOW_R[17]||__UDP_FLOW_R[15]||E[28]||__UDP_FLOW_R[18]||__UDP_FLOW_R[19]||__UDP_FLOW_R[8]||E[52]||__UDP_FLOW_R[9]||__UDP_FLOW_R[20]||E[41]||E[51]);
E[1] = E[14]&&__UDP_FLOW_R[21];
E[2] = E[14]&&__UDP_FLOW_R[25];
E[29] = (E[4]&&!(__UDP_FLOW_R[25]))||E[2];
E[48] = E[14]&&__UDP_FLOW_R[40];
E[0] = E[14]&&__UDP_FLOW_R[23];
E[36] = E[0]&&E[48];
E[53] = E[4]&&!(__UDP_FLOW_R[23]);
E[0] = E[0]&&!(E[48])&&__UDP_FLOW_R[23];
E[54] = E[0]||E[53];
E[55] = E[14]&&__UDP_FLOW_R[24];
E[56] = E[55]&&E[49];
E[57] = E[4]&&!(__UDP_FLOW_R[24]);
E[55] = E[55]&&!(E[49])&&__UDP_FLOW_R[24];
E[58] = E[55]||E[57];
E[2] = (E[57]&&E[53]&&E[29]&&E[2]&&E[4])||(!(E[25])&&E[24]);
E[53] = E[2]&&E[49];
E[57] = (E[2]&&!(E[49]))||E[53];
E[59] = E[48]&&E[2];
E[60] = (!(E[48])&&E[2])||E[59];
E[61] = E[48]&&E[49];
E[62] = E[61]&&E[2];
E[61] = !(E[61])&&E[2];
E[63] = (E[1]&&E[49])||((E[56]||E[36])&&(E[56]||E[58])&&(E[36]||E[54])&&E[29]&&E[4])||((E[61]||E[62])&&E[62]&&E[60]&&E[57]&&E[2]);
E[57] = ((E[55]||E[0])&&E[58]&&E[54]&&E[29]&&E[4])||((E[59]||E[53]||E[2])&&E[61]&&E[60]&&E[57]&&E[2]);
E[60] = E[14]&&__UDP_FLOW_R[22];
__UDP_FLOW_R[22] = (!(E[30])&&E[15])||(E[60]&&!(E[30])&&__UDP_FLOW_R[22]);
E[30] = (E[30]&&E[15])||(E[60]&&E[30]);
__UDP_FLOW_R[21] = (E[1]&&!(E[49])&&__UDP_FLOW_R[21])||E[25];
__UDP_FLOW_R[32] = (E[27]&&E[15])||(E[26]&&!(E[24])&&__UDP_FLOW_R[32])||__UDP_FLOW_R[0];
__UDP_FLOW_R[31] = (E[22]&&__UDP_FLOW_R[42])||(E[21]&&__UDP_FLOW_R[42]&&__UDP_FLOW_R[31]);
E[21] = E[14]&&__UDP_FLOW_R[26];
__UDP_FLOW_R[28] = E[14]&&__UDP_FLOW_R[27];
__UDP_FLOW_R[30] = E[14]&&__UDP_FLOW_R[29];
E[57] = ((E[7]&&!(E[6]))||__UDP_FLOW_R[32]||__UDP_FLOW_R[33])&&((E[7]&&!(E[5]))||__UDP_FLOW_R[30]||__UDP_FLOW_R[28]||E[21]||__UDP_FLOW_R[31]||__UDP_FLOW_R[21]||E[30]||__UDP_FLOW_R[22]||E[57]||E[63])&&(__UDP_FLOW_R[30]||__UDP_FLOW_R[28]||E[21]||__UDP_FLOW_R[31]||__UDP_FLOW_R[32]||__UDP_FLOW_R[21]||E[30]||__UDP_FLOW_R[22]||E[57]||E[63]||__UDP_FLOW_R[33]);
__UDP_FLOW_R[7] = (E[42]&&__UDP_FLOW_R[20])||(E[38]&&__UDP_FLOW_R[20]&&__UDP_FLOW_R[7]);
__UDP_FLOW_R[1] = (!(E[31])&&__UDP_FLOW_R[0])||(E[34]&&__UDP_FLOW_R[1])||E[46];
__UDP_FLOW_R[4] = E[34]&&__UDP_FLOW_R[3];
__UDP_FLOW_R[6] = E[34]&&__UDP_FLOW_R[5];
E[31] = (E[31]&&__UDP_FLOW_R[0])||(E[33]&&E[31]);
__UDP_FLOW_R[3] = E[34]&&__UDP_FLOW_R[2];
E[34] = E[14]&&__UDP_FLOW_R[35];
__UDP_FLOW_R[35] = (E[34]&&!(E[23])&&__UDP_FLOW_R[35])||E[19];
E[23] = E[34]&&E[23];
__UDP_FLOW_R[41] = (E[20]&&E[19])||(E[18]&&!(E[17])&&__UDP_FLOW_R[41])||__UDP_FLOW_R[0];
__UDP_FLOW_R[34] = (E[16]&&!(E[15])&&__UDP_FLOW_R[34])||E[48]||__UDP_FLOW_R[0];
E[48] = E[14]&&__UDP_FLOW_R[36];
__UDP_FLOW_R[38] = E[14]&&__UDP_FLOW_R[37];
__UDP_FLOW_R[40] = E[14]&&__UDP_FLOW_R[39];
E[8] = ((E[10]&&!(E[9]))||__UDP_FLOW_R[41]||__UDP_FLOW_R[42])&&((E[10]&&!(E[8]))||__UDP_FLOW_R[40]||__UDP_FLOW_R[38]||E[48]||__UDP_FLOW_R[34]||E[23]||__UDP_FLOW_R[35]||E[17])&&(__UDP_FLOW_R[40]||__UDP_FLOW_R[38]||E[48]||__UDP_FLOW_R[34]||__UDP_FLOW_R[41]||E[23]||__UDP_FLOW_R[35]||__UDP_FLOW_R[42]||E[17]);
E[41] = (__UDP_FLOW_R[0]||E[12])&&((E[12]&&!(E[10]))||E[8])&&((E[12]&&!(E[11]))||__UDP_FLOW_R[3]||E[31]||__UDP_FLOW_R[6]||__UDP_FLOW_R[4]||__UDP_FLOW_R[1]||__UDP_FLOW_R[7]||E[35])&&((E[12]&&!(E[7]))||E[57])&&((E[12]&&!(E[3]))||E[41])&&(E[8]||__UDP_FLOW_R[3]||E[31]||__UDP_FLOW_R[6]||__UDP_FLOW_R[4]||__UDP_FLOW_R[1]||__UDP_FLOW_R[7]||E[57]||E[41]||E[35]);
__UDP_FLOW_R[10] = (E[43]&&!(E[40]))||(!(E[50])&&E[45]);
__UDP_FLOW_R[11] = (!(E[44])&&E[39])||(!(E[50])&&E[47]);
__UDP_FLOW_R[12] = !(E[50])&&E[37];
__UDP_FLOW_R[23] = (!(E[56])&&E[0])||(!(E[62])&&E[53]);
__UDP_FLOW_R[24] = (!(E[62])&&E[59])||(E[55]&&!(E[36]));
__UDP_FLOW_R[25] = !(E[62])&&E[2];
__UDP_FLOW_R[0] = !(_true);
if (__UDP_FLOW_R[1]) { __AppendToList(__UDP_FLOW_HaltList,1); }
__UDP_FLOW_R[2] = E[31];
if (__UDP_FLOW_R[2]) { __AppendToList(__UDP_FLOW_HaltList,2); }
if (__UDP_FLOW_R[3]) { __AppendToList(__UDP_FLOW_HaltList,3); }
if (__UDP_FLOW_R[4]) { __AppendToList(__UDP_FLOW_HaltList,4); }
__UDP_FLOW_R[5] = E[35];
if (__UDP_FLOW_R[5]) { __AppendToList(__UDP_FLOW_HaltList,5); }
if (__UDP_FLOW_R[6]) { __AppendToList(__UDP_FLOW_HaltList,6); }
if (__UDP_FLOW_R[7]) { __AppendToList(__UDP_FLOW_HaltList,7); }
if (__UDP_FLOW_R[8]) { __AppendToList(__UDP_FLOW_HaltList,8); }
if (__UDP_FLOW_R[9]) { __AppendToList(__UDP_FLOW_HaltList,9); }
if (__UDP_FLOW_R[10]) { __AppendToList(__UDP_FLOW_HaltList,10); }
if (__UDP_FLOW_R[11]) { __AppendToList(__UDP_FLOW_HaltList,11); }
if (__UDP_FLOW_R[12]) { __AppendToList(__UDP_FLOW_HaltList,12); }
__UDP_FLOW_R[13] = E[51];
if (__UDP_FLOW_R[13]) { __AppendToList(__UDP_FLOW_HaltList,13); }
__UDP_FLOW_R[14] = E[28];
if (__UDP_FLOW_R[14]) { __AppendToList(__UDP_FLOW_HaltList,14); }
if (__UDP_FLOW_R[15]) { __AppendToList(__UDP_FLOW_HaltList,15); }
__UDP_FLOW_R[16] = E[52];
if (__UDP_FLOW_R[16]) { __AppendToList(__UDP_FLOW_HaltList,16); }
if (__UDP_FLOW_R[17]) { __AppendToList(__UDP_FLOW_HaltList,17); }
if (__UDP_FLOW_R[18]) { __AppendToList(__UDP_FLOW_HaltList,18); }
if (__UDP_FLOW_R[19]) { __AppendToList(__UDP_FLOW_HaltList,19); }
if (__UDP_FLOW_R[20]) { __AppendToList(__UDP_FLOW_HaltList,20); }
if (__UDP_FLOW_R[21]) { __AppendToList(__UDP_FLOW_HaltList,21); }
if (__UDP_FLOW_R[22]) { __AppendToList(__UDP_FLOW_HaltList,22); }
if (__UDP_FLOW_R[23]) { __AppendToList(__UDP_FLOW_HaltList,23); }
if (__UDP_FLOW_R[24]) { __AppendToList(__UDP_FLOW_HaltList,24); }
if (__UDP_FLOW_R[25]) { __AppendToList(__UDP_FLOW_HaltList,25); }
__UDP_FLOW_R[26] = E[63];
if (__UDP_FLOW_R[26]) { __AppendToList(__UDP_FLOW_HaltList,26); }
__UDP_FLOW_R[27] = E[21];
if (__UDP_FLOW_R[27]) { __AppendToList(__UDP_FLOW_HaltList,27); }
if (__UDP_FLOW_R[28]) { __AppendToList(__UDP_FLOW_HaltList,28); }
__UDP_FLOW_R[29] = E[30];
if (__UDP_FLOW_R[29]) { __AppendToList(__UDP_FLOW_HaltList,29); }
if (__UDP_FLOW_R[30]) { __AppendToList(__UDP_FLOW_HaltList,30); }
if (__UDP_FLOW_R[31]) { __AppendToList(__UDP_FLOW_HaltList,31); }
if (__UDP_FLOW_R[32]) { __AppendToList(__UDP_FLOW_HaltList,32); }
if (__UDP_FLOW_R[33]) { __AppendToList(__UDP_FLOW_HaltList,33); }
if (__UDP_FLOW_R[34]) { __AppendToList(__UDP_FLOW_HaltList,34); }
if (__UDP_FLOW_R[35]) { __AppendToList(__UDP_FLOW_HaltList,35); }
__UDP_FLOW_R[36] = E[17];
if (__UDP_FLOW_R[36]) { __AppendToList(__UDP_FLOW_HaltList,36); }
__UDP_FLOW_R[37] = E[48];
if (__UDP_FLOW_R[37]) { __AppendToList(__UDP_FLOW_HaltList,37); }
if (__UDP_FLOW_R[38]) { __AppendToList(__UDP_FLOW_HaltList,38); }
__UDP_FLOW_R[39] = E[23];
if (__UDP_FLOW_R[39]) { __AppendToList(__UDP_FLOW_HaltList,39); }
if (__UDP_FLOW_R[40]) { __AppendToList(__UDP_FLOW_HaltList,40); }
if (__UDP_FLOW_R[41]) { __AppendToList(__UDP_FLOW_HaltList,41); }
if (__UDP_FLOW_R[42]) { __AppendToList(__UDP_FLOW_HaltList,42); }
if (!E[41]) { __AppendToList(__UDP_FLOW_HaltList,0); }
__ResetModuleEntryAfterReaction();
__UDP_FLOW_ModuleData.awaited_list = __UDP_FLOW_AllAwaitedList;
__UDP_FLOW__reset_input();
return E[41];
}

/* AUTOMATON RESET */

int UDP_FLOW_reset () {
__UDP_FLOW_ModuleData.awaited_list = __UDP_FLOW_AwaitedList;
__ResetModuleEntry();
__UDP_FLOW_ModuleData.awaited_list = __UDP_FLOW_AllAwaitedList;
__UDP_FLOW_ModuleData.state = 0;
__UDP_FLOW_R[0] = _true;
__UDP_FLOW_R[1] = _false;
__UDP_FLOW_R[2] = _false;
__UDP_FLOW_R[3] = _false;
__UDP_FLOW_R[4] = _false;
__UDP_FLOW_R[5] = _false;
__UDP_FLOW_R[6] = _false;
__UDP_FLOW_R[7] = _false;
__UDP_FLOW_R[8] = _false;
__UDP_FLOW_R[9] = _false;
__UDP_FLOW_R[10] = _false;
__UDP_FLOW_R[11] = _false;
__UDP_FLOW_R[12] = _false;
__UDP_FLOW_R[13] = _false;
__UDP_FLOW_R[14] = _false;
__UDP_FLOW_R[15] = _false;
__UDP_FLOW_R[16] = _false;
__UDP_FLOW_R[17] = _false;
__UDP_FLOW_R[18] = _false;
__UDP_FLOW_R[19] = _false;
__UDP_FLOW_R[20] = _false;
__UDP_FLOW_R[21] = _false;
__UDP_FLOW_R[22] = _false;
__UDP_FLOW_R[23] = _false;
__UDP_FLOW_R[24] = _false;
__UDP_FLOW_R[25] = _false;
__UDP_FLOW_R[26] = _false;
__UDP_FLOW_R[27] = _false;
__UDP_FLOW_R[28] = _false;
__UDP_FLOW_R[29] = _false;
__UDP_FLOW_R[30] = _false;
__UDP_FLOW_R[31] = _false;
__UDP_FLOW_R[32] = _false;
__UDP_FLOW_R[33] = _false;
__UDP_FLOW_R[34] = _false;
__UDP_FLOW_R[35] = _false;
__UDP_FLOW_R[36] = _false;
__UDP_FLOW_R[37] = _false;
__UDP_FLOW_R[38] = _false;
__UDP_FLOW_R[39] = _false;
__UDP_FLOW_R[40] = _false;
__UDP_FLOW_R[41] = _false;
__UDP_FLOW_R[42] = _false;
__UDP_FLOW__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__UDP_FLOW_ModuleData
};
