#ifndef _LedSM_H
#define _LedSM_H

#include <stdint.h>
#include <State.h>

#include "stm32f4xx_hal_gpio.h"

typedef struct {
  State state;
  uint32_t time;
}LedData;

void ledInitData(LedData *data);
void ledSM(LedData *data);

#endif // LedSM_H
