#include "Task.h"

/* TASK SWITCHING MECHANISM
 *
 * - Push the rest of the register
 * - Let R0 points to mainTCB
 * - Store the current SP into *mainTcb.sp ; through r0
 * - Let R0 points to taskOneTcb
 * - Load *taskOneTcb ; through R0 in to current SP
 * - Return from interrupt using "bx lr"
 *
 * 	assembler
 * 	.equ TCB_SP,	8
 * 	.equ TCB_NAME,	4
 * 	.equ TCB_NEXT,	0
 * 	str r1[r0, #TCB_SP]
 * 	ldr r1[r0, #TCB_SP]
 *
 * 	*LinkedList >> Tcb *runningTcb;
 */

uint8_t taskOneStack[1028];
uint8_t taskTwoStack[1028];

Tcb mainTcb;
Tcb taskOneTcb;
Tcb taskTwoTcb;
Tcb *runningQueue;
Tcb *readyQueue;
Tcb *blockQueue;

CpuContext Context;
CpuContext *cc = (CpuContext *)(((uint32_t)(&taskOneStack[1024])) - sizeof(CpuContext));

void taskOne(void){
	while(1);
}

//Init all the TCB

void initTcb(){
	mainTcb.name = "main thread";
	mainTcb.sp = 0x1234;
	taskOneTcb.name = "thread _1";
	taskOneTcb.sp = (uint32_t)cc;

	cc->r4	= 0x44444444;
	cc->r5	= 0x55555555;
	cc->r6	= 0x66666666;
	cc->r7	= 0x77777777;
	cc->r8	= 0x88888888;
	cc->r9	= 0x99999999;
	cc->r10	= 0xaaaaaaaa;
	cc->r11	= 0xbbbbbbbb;
	cc->r0	= 0xabababab;
	cc->r1	= 0x11111111;
	cc->r2	= 0x22222222;
	cc->r12	= 0xcccccccc;
	cc->lr	= 0xFFFFFFF9;
	cc->pc	= (uint32_t)taskOne;
	cc->xpsr = 0x01000000;

	runningQueue = &mainTcb;
	readyQueue = &taskOneTcb;
}
