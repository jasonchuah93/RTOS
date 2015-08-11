#include "Task.h"
#include "LinkedList.h"

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

LinkedList readyQueue;

Tcb mainTcb;
Tcb taskOneTcb;
Tcb taskTwoTcb;
Tcb *runningTcb;

CpuContext Context;
CpuContext *cc = (CpuContext *)(((uint32_t)(&taskOneStack[1024])) - sizeof(CpuContext));
CpuContext *cc2 = (CpuContext *)(((uint32_t)(&taskOneStack[1024])) - sizeof(CpuContext));

void taskOne(void){
	int counter = 0x00000000;
	while(1){
		counter++;
	}
}

void taskTwo(void){
	int counter = 0xffffffff;
	while(1){
		counter--;
	}
}

void initTcb(){
	mainTcb.name = "main thread";
	mainTcb.sp = 0;
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

	taskTwoTcb.name = "thread _2";
	taskTwoTcb.sp = (uint32_t)cc2;

	cc2->r4	= 0xFFFFFFF9;
	cc2->r5	= 0xcccccccc;
	cc2->r6	= 0x22222222;
	cc2->r7	= 0x11111111;
	cc2->r8	= 0xabababab;
	cc2->r9	= 0xbbbbbbbb;
	cc2->r10= 0xaaaaaaaa;
	cc2->r11= 0x99999999;
	cc2->r0	= 0x88888888;
	cc2->r1	= 0x77777777;
	cc2->r2	= 0x66666666;
	cc2->r12= 0x55555555;
	cc2->lr	= 0x44444444;
	cc2->pc	= (uint32_t)taskTwo;
	cc2->xpsr = 0x01000000;

	runningTcb = &mainTcb;
	createLinkedList(&taskOneTcb);
}
