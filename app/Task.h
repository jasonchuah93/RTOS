#ifndef __TASK_H
#define __TASK_H

#include <stdint.h>

typedef struct Tcb_t Tcb;
struct Tcb_t {
	Tcb			*next;
	uint32_t	priority;
	char 		*name;
	uint32_t 	sp;
};

typedef struct {
	uint32_t r4;
	uint32_t r5;
	uint32_t r6;
	uint32_t r7;
	uint32_t r8;
	uint32_t r9;
	uint32_t r10;
	uint32_t r11;
	uint32_t r0;
	uint32_t r1;
	uint32_t r2;
	uint32_t r3;
	uint32_t r12;
	uint32_t lr;
	uint32_t pc;
	uint32_t xpsr;
}CpuContext;

extern uint8_t taskOneStack[1028];
extern uint8_t taskTwoStack[1028];

void initTcb(void);
void taskOne(void);
void taskTwo(void);


#endif // __TASK_H
