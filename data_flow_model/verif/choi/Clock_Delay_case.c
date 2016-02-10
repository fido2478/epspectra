/* sscc : C CODE OF SORTED EQUATIONS tis2 - SIMULATION MODE */

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
#define __tis2_GENERIC_TEST(TEST) return TEST;
typedef void (*__tis2_APF)();
static __tis2_APF *__tis2_PActionArray;
static int **__tis2_PCheckArray;
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


static unsigned short __tis2_HaltList[6];
static unsigned short __tis2_AwaitedList[3];
static unsigned short __tis2_EmittedList[3];
static unsigned short __tis2_StartedList[1];
static unsigned short __tis2_KilledList[1];
static unsigned short __tis2_SuspendedList[1];
static unsigned short __tis2_ActiveList[1];
static unsigned short __tis2_AllAwaitedList[3]={0,};


/* INPUT FUNCTIONS */


/* FUNCTIONS RETURNING NUMBER OF EXEC */

int tis2_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

/* OUTPUT ACTIONS */

static void __tis2_A1 () {
#ifdef __OUTPUT
tis2_O_o1();
#endif
__AppendToList(__tis2_EmittedList,0);
}
static int __tis2_Check1 [] = {1,0,0};
static void __tis2_A2 () {
#ifdef __OUTPUT
tis2_O_o2();
#endif
__AppendToList(__tis2_EmittedList,1);
}
static int __tis2_Check2 [] = {1,0,0};

/* ASSIGNMENTS */

/* PROCEDURE CALLS */

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

/* ACTION SEQUENCES */


static int *__tis2_CheckArray[] = {
0,
__tis2_Check1,
__tis2_Check2
};
static int **__tis2_PCheckArray =  __tis2_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void tis2_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __tis2_show_variable (int __V) {
return 0;
}

/* SET VARIABLE FUNCTION */

static void __tis2_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __tis2_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __tis2_InstanceTable [] = {
{"tis2",0,"","Clock_Delay_case.strl",{1,1,1,0},{1,13,1,0},{0,0,0,0}},
};

struct __SignalEntry __tis2_SignalTable [] = {
{"o1",34,0,0,{1,2,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"o2",34,0,0,{1,2,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __HaltEntry __tis2_HaltTable [] = {
{{1,13,1,0}},
{{1,6,3,0}},
{{1,7,1,0}},
{{1,11,3,0}},
{{1,12,1,0}}
};


static void __tis2__reset_input () {
}


/* MODULE DATA FOR SIMULATION */

int tis2();
int tis2_reset();

static struct __ModuleEntry __tis2_ModuleData = {
"Simulation interface release 5","tis2",
1,0,2,0,0,0,2,0,0,0,0,0,0,5,0,0,0,
__tis2_HaltList,
__tis2_AwaitedList,
__tis2_EmittedList,
__tis2_StartedList,
__tis2_KilledList,
__tis2_SuspendedList,
__tis2_ActiveList,
0,0,
tis2_initialize,tis2,tis2_reset,
__tis2_show_variable,__tis2_set_variable,__tis2_check_value,0,
__tis2_InstanceTable,
0,
__tis2_SignalTable,0,0,
0,0,
0,
0,
__tis2_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __tis2_R[5] = {_true,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int tis2 () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[4];

__tis2_ModuleData.awaited_list = __tis2_AwaitedList;
__ResetModuleEntryBeforeReaction();
E[0] = __tis2_R[1]||__tis2_R[2];
__tis2_R[1] = __tis2_R[0]||(E[0]&&!(__tis2_R[0]));
if (__tis2_R[1]) {
__AppendToList(__tis2_EmittedList,0);
}
if (__tis2_R[1]) {
__CheckVariables(__tis2_CheckArray[1]);__tis2_A1();
#ifdef TRACE_ACTION
fprintf(stderr, "__tis2_A1\n");
#endif
}
E[1] = __tis2_R[3]||__tis2_R[4];
__tis2_R[3] = __tis2_R[0]||(E[1]&&!(__tis2_R[0]));
if (__tis2_R[3]) {
__AppendToList(__tis2_EmittedList,1);
}
if (__tis2_R[3]) {
__CheckVariables(__tis2_CheckArray[2]);__tis2_A2();
#ifdef TRACE_ACTION
fprintf(stderr, "__tis2_A2\n");
#endif
}
E[2] = !(_true);
E[3] = E[0]||E[1];
E[1] = (__tis2_R[1]||__tis2_R[3])&&((E[3]&&!(E[0]))||__tis2_R[1])&&((E[3]&&!(E[1]))||__tis2_R[3]);
__tis2_R[0] = !(_true);
if (__tis2_R[1]) { __AppendToList(__tis2_HaltList,1); }
__tis2_R[2] = !(_true);
if (__tis2_R[2]) { __AppendToList(__tis2_HaltList,2); }
if (__tis2_R[3]) { __AppendToList(__tis2_HaltList,3); }
__tis2_R[4] = !(_true);
if (__tis2_R[4]) { __AppendToList(__tis2_HaltList,4); }
if (!E[1]) { __AppendToList(__tis2_HaltList,0); }
__ResetModuleEntryAfterReaction();
__tis2_ModuleData.awaited_list = __tis2_AllAwaitedList;
__tis2__reset_input();
return E[1];
}

/* AUTOMATON RESET */

int tis2_reset () {
__tis2_ModuleData.awaited_list = __tis2_AwaitedList;
__ResetModuleEntry();
__tis2_ModuleData.awaited_list = __tis2_AllAwaitedList;
__tis2_ModuleData.state = 0;
__tis2_R[0] = _true;
__tis2_R[1] = _false;
__tis2_R[2] = _false;
__tis2_R[3] = _false;
__tis2_R[4] = _false;
__tis2__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__tis2_ModuleData
};
