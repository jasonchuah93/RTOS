#include "stdio.h"
#include "LedSM.h"
#include "Message.h"
#include "Button.h"

void ledInitData(LedData *data){
  data->state = LED_OFF;
  data->time = 0;
}

void ledSM(LedData *data){
	switch(data->state){
	case LED_OFF:
		if(msg == CHANGE_MODE){
			data->state = LED_BLINKING_ON;
			msg = DO_NOTHING;
		}
	break;
	case LED_BLINKING_ON:
		if(msg == CHANGE_MODE){
			data->state = LED_ON;
			msg = DO_NOTHING;
		}else{
			if(getCurrentTime()==1){
				data->state = LED_BLINKING_OFF;
			}
		}
	break;
	case LED_BLINKING_OFF:
		if(msg == CHANGE_MODE){
			data->state = LED_ON;
			msg = DO_NOTHING;
		}else{
			if(getCurrentTime()==1){
				data->state = LED_BLINKING_ON;
			}
		}
	break;
	case LED_ON:
		if(msg == CHANGE_MODE){
			data->state = LED_OFF;
			msg = DO_NOTHING;
		}
	break;
 
	default:
		printf("Error: unknown state encounter in ledSM : %d\n",data->state);
	break;
	}
}


