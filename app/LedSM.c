#include <stdio.h>
#include "LedSM.h"
#include "Led.h"
#include "Message.h"
#include "Button.h"

void ledInitData(TaskBlock *tb){
	tb->state = LED_OFF;
	tb->time = 0;
}

void ledSM(TaskBlock *tb){
	switch(tb->state){
	case LED_OFF:
		turnOffLED(PORTG,LED1);
		if(msg == CHANGE_MODE){
			tb->state = LED_BLINKING_ON;
			msg = DO_NOTHING;
		}
	break;
	case LED_BLINKING_ON:
		turnOnLED(PORTG,LED1);
		if(msg == CHANGE_MODE){
			tb->state = LED_ON;
			msg = DO_NOTHING;
		}else{
			if(getCurrentTime()==1){
				tb->state = LED_BLINKING_OFF;
			}
		}
	break;
	case LED_BLINKING_OFF:
		turnOffLED(PORTG,LED1);
		if(msg == CHANGE_MODE){
			tb->state = LED_ON;
			msg = DO_NOTHING;
		}else{
			if(getCurrentTime()==1){
				tb->state = LED_BLINKING_ON;
			}
		}
	break;
	case LED_ON:
		turnOnLED(PORTG,LED1);
		if(msg == CHANGE_MODE){
			tb->state = LED_OFF;
			msg = DO_NOTHING;
		}
	break;
 
	default:
		printf("Error: unknown state encounter in ledSM : %d\n",tb->state);
	break;
	}
}


