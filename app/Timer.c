#include "Timer.h"

uint32_t counter = 0;
uint32_t currentTime = 0;

//Calculate the current time being

uint32_t updateCurrentTime(){
	if(counter++ >= 100){
		counter = 0;
			currentTime++;
	}
	return currentTime;
}

uint32_t getCurrentTime(){
	return HAL_GetTick();
}

int delay(uint32_t delayCycle){
	static uint32_t previousTime = 0;
	while((getCurrentTime() - previousTime) < delayCycle);
	previousTime = getCurrentTime();
}


