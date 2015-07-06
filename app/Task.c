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
CpuContext Context;
CpuContext *cc = &Context; //(CpuContext *)(((uint32_t)(&taskOneStack[1024])) - sizeof(CpuContext));

void taskOne(void){
	while(1);
}

//Init all the TCB

void initTcb(){
	mainTcb.name = "main thread";
	mainTcb.sp = 0;
	taskOneTcb.name = "thread _1";
	taskOneTcb.sp = (uint32_t)&Context;

	Context.r4	= 0x44444444;
	Context.r5	= 0x55555555;
	Context.r6	= 0x66666666;
	Context.r7	= 0x77777777;
	Context.r8	= 0x88888888;
	Context.r9	= 0x99999999;
	Context.r10	= 0xaaaaaaaa;
	Context.r11	= 0xbbbbbbbb;
	Context.r0	= 0xabababab;
	Context.r1	= 0x11111111;
	Context.r2	= 0x22222222;
	Context.r12	= 0xcccccccc;
	Context.lr	= 0xFFFFFFF9;
	Context.pc	= (uint32_t)taskOne;
	Context.xpsr = 0x01000000;

	runningQueue = &mainTcb;
	readyQueue = &taskOneTcb;
}
