#ifndef _LedSM_H
#define _LedSM_H

#include <stdint.h>
#include "State.h"
#include "liteTasker.h"
#include "stm32f4xx_hal_gpio.h"

typedef struct {
  State state;
  uint32_t time;
}LedData;

void ledInitData(TaskBlock *tb);
void ledSM(TaskBlock *tb);

#endif // LedSM_H
