#include "stm32f4xx_hal_gpio.h"
#include "main.h"
#include "Task.h"
#include "Button.h"
#include "ButtonSM.h"
#include "Led.h"
#include "LedSM.h"
#include "Timer.h"

void testFunc(void);
void taskSwitch(void);

int main(void)
{
	LedData Ldata;
	ButtonData Bdata;
	initButton();
	initLED(LED1);
	//buttonInitData(&Bdata);
	//ledInitData(&Ldata);

	initSysTick();
	initTcb();
	taskSwitch();

	while(1)
		{
			//updateCurrentTime();
			//buttonSM(&Bdata);
			//ledSM(&Ldata);
		}
}

void initSysTick(){
	if(SysTick_Config(SystemCoreClock / 1000)){
		while(1);
	}
}
