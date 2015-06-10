#include "stdio.h"
#include "ButtonSM.h"
#include "Message.h"
#include "Button.h"
#include "Timer.h"

void buttonInitData(ButtonData *data){
  data->state = RELEASE;
}

void buttonSM(ButtonData *data){
  switch(data->state){
  case RELEASE:
    if(isButtonPressed() == true ){
		msg = CHANGE_MODE; //Pass the message to LED
		data->state = PRESS;
    }
  break;
  case PRESS:
    if(isButtonPressed() == false ){
		msg = DO_NOTHING;
		data->state = RELEASE;
    }
  break;
  default:
    printf("Error: unknown state encounter in buttonSM : %d\n",data->state);
  break;
  }
}

