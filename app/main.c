#include "stm32f4xx_hal_gpio.h"
#include "main.h"
#include "Task.h"
#include "Button.h"
#include "ButtonSM.h"
#include "Led.h"
#include "LedSM.h"
#include "Timer.h"
#include "liteTasker.h"

void testFunc(void);
void taskSwitch(void);

int main(void)
{

	TaskBlock LED1_tb;

	initTaskBlock(&LED1_tb);
	initButton();
	initLED(LED1);
	initLED(LED2);

	initSysTick();
	initTcb();
	yield_LED1(&LED1_tb);
	taskSwitch();

	while(1){}
}

void initSysTick(){
	if(SysTick_Config(SystemCoreClock / 1000)){
		while(1);
	}
}

