#ifndef __LITETASKER_H
#define __LITETASKER_H

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "Led.h"
#include "State.h"

typedef struct{
    State state;
    uint32_t time;
}TaskBlock;

#define initTaskBlock(x)  	((x)->state = 0)
#define yield(x) 			(x)->state = __LINE__; return 1 ; case __LINE__ :
#define startTask(x) 		switch ((x)->state) { case 0:
#define endTask(x) 			}

#endif //__LITETASKER_H
