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

  .section  .text.taskSwitch
  .type  taskSwitch, %function
taskSwitch:
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
 	push	{r0}
 	b		 .

.align 8
.type  SysTick_Handler, %function
 SysTick_Handler:
// Your Code Starts here :
// Push the rest of the register

push	{r4-r11}

ldr    r0,  =runningTcb //mov address of runningQ to r0
ldr    r1,  [r0]		   //deref runningQ, then content mov to r1
ldr    r2,  [r1,#4]

str	   sp,  [r1,#4]

ldr    r0,  =readyQueue //mov address of taskOne to r0
ldr	   r1,  [r0]
ldr    lr,  [r1,#4]
ldr	   r0,  [lr,#32]
ldr	   r1,  [lr,#36]
ldr	   r2,  [lr,#32]
ldr	   r3,  [lr,#44]
ldr	   r4,  [lr,#0]
ldr	   r5,  [lr,#4]
ldr	   r6,  [lr,#8]
ldr	   r7,  [lr,#12]
ldr	   r8,  [lr,#16]
ldr	   r9,  [lr,#20]
ldr	   r10,  [lr,#24]
ldr	   r11,  [lr,#28]
ldr	   r12,  [lr,#48]

ldr    pc,  [lr,#56]
bx 		lr





