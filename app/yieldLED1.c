#include "yieldLED1.h"
#include "Timer.h"

void yield_LED1(TaskBlock *tb){
	startTask(tb);
	while(1){
		turnOnLED(PORTG,LED1);
		while(halfSecHasNotExpire()){
			yield(tb);
			turnOffLED(PORTG,LED2);
		}
		turnOffLED(PORTG,LED1);
		while(halfSecHasNotExpire()){
			yield(tb);
			turnOnLED(PORTG,LED2);
		}
	}
	endTask(tb);
}
