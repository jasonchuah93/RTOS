#ifndef __yieldLED1_H
#define __yieldLED1_H

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "Led.h"
#include "liteTasker.h"


void yield_LED1(TaskBlock *tb);

#endif //yieldLED1
