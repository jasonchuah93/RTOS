  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

.global  taskSwitch
.global  SysTick_Handler
.extern taskOneStack
.extern taskTwoStack
.extern mainTcb
.extern readyQueue
.extern runningQueue

.equ TCB_NEXT , 0
.equ TCB_NAME , 4
.equ TCB_SP   , 8

  .section  .text.taskSwitch
  .type  taskSwitch, %function
taskSwitch:
	push   {lr}
	ldr    r0,  =#0xabababab
 	ldr    r1,  =#0x11111111
 	ldr    r2,  =#0x22222222
 	ldr    r3,  =#0x33333333
 	ldr    r4,  =#0x44444444
 	ldr    r5,  =#0x55555555
 	ldr    r6,  =#0x66666666
 	ldr    r7,  =#0x77777777
 	ldr    r8,  =#0x88888888
 	ldr    r9,  =#0x99999999
 	ldr    r10, =#0xaaaaaaaa
 	ldr    r11, =#0xbbbbbbbb
 	ldr    r12, =#0xcccccccc
 	ldr    lr,  =#0xdddddddd
 	b		 .

.align 8
.type  SysTick_Handler, %function
 SysTick_Handler:
push	{r4-r11} 			//Push registers into stack
ldr    r4,  =runningQueue   //mov address of runningQ to r0
ldr    r4,  [r4]		    //deref runningQ, then content mov to r1
str    sp,  [r4,#TCB_SP]
push   {r7,lr}
ldr    r0,  =readyQueue     //load readyQueue into r0
bl	   listRemoveFirst
//ldr	   r5,r0
ldr    r1, = runningQueue   //load runningQueue into r1
str    r0, [r1]
ldr    r0, =readyQueue      //load readyQueue into r0
mov    r1,r4
bl     listAddLast          //branch link function listAddLast
pop    {r7,lr}
ldr	   sp,  [r5,#TCB_SP]
pop    {r4-r11}				//Pop out register r4-r11
bx 		lr





