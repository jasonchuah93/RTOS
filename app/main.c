#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "LEDSM.h"
#include "Task.h"
#include "main.h"

void testFunc();
void schedular();

int taskSwitch(int value){
	return value *3;
}

void initSysTick(){
	if(SysTick_Config(SystemCoreClock / 100)){
		while(1);
	}
}

int main(void)
{
	initSysTick();
	initTcb();
	while(1)
		{

		}
}
