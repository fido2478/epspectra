/*
 * x86 Performance-Monitoring Counters driver for Linux
 *
 * Copyright (C) 1999  Mikael Pettersson
 */
#ifndef __I386_PERFCTR_H
#define __I386_PERFCTR_H

#include <linux/ioctl.h>

/*
 * Kernel interface to the Performance-Monitoring Counters driver
 */

struct perfctr_control {
	unsigned int evntsel[2];
};

typedef union {
	unsigned long long u64;
	unsigned int u32[2];
} perfctr_uint64_t;

struct perfctr_counters {
	perfctr_uint64_t tsc_start, tsc, pmc[2];
};

struct perfctr_state {
	struct perfctr_control control;
	struct perfctr_counters counters, *user;
};

#ifdef __KERNEL__

#define INIT_PERFCTR { {{0,0}}, {{0}, {0}, {{0},{0}}}, 0 },

/* Forward declaration, a strange C thing */
struct task_struct;

extern void perfctr_init_thread(struct task_struct*);
extern void perfctr_suspend_thread(struct task_struct*);
extern void perfctr_resume_thread(struct task_struct*);
extern void perfctr_flush_thread(struct task_struct*);
extern void perfctr_exit_thread(struct task_struct*);

#endif

/*
 * ioctl() interface
 */

struct perfctr_info {
	unsigned char major_version;
	unsigned char minor_version;
	unsigned char events_format;
#define PERFCTR_EVENTS_INTEL_P5		0
#define PERFCTR_EVENTS_INTEL_P5MMX	1
#define PERFCTR_EVENTS_INTEL_P6		2
#define PERFCTR_EVENTS_INTEL_PII	3
#define PERFCTR_EVENTS_CYRIX_MII	4
#define PERFCTR_EVENTS_WINCHIP_C6	5
#define PERFCTR_EVENTS_WINCHIP_2	6
	unsigned char have_rdpmc;	/* user-mode rdpmc available? */
	unsigned char have_rdtsc;	/* user-mode rdtsc available? */
};

struct perfctr_enable {
	struct perfctr_control control;
	struct perfctr_counters *user;
};

#define PERFCTR_IOCTL_BASE	'P'
#define PERFCTR_INFO		_IOR(PERFCTR_IOCTL_BASE,0,struct perfctr_info)
#define PERFCTR_ENABLE		_IOW(PERFCTR_IOCTL_BASE,1,struct perfctr_enable)
#define PERFCTR_READ		_IOR(PERFCTR_IOCTL_BASE,2,struct perfctr_state)
#define PERFCTR_GLOBAL_ENABLE	_IOW(PERFCTR_IOCTL_BASE,3,struct perfctr_enable)
#define PERFCTR_GLOBAL_READ	_IOR(PERFCTR_IOCTL_BASE,4,struct perfctr_state)

#endif	/* __I386_PERFCTR_H */
