#ifndef Button_H
#define Button_H

#include "stm32f4xx_hal_gpio.h"

#define isButtonPressed() 	HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)
#define isButtonNotPressed() 	!isButtonPressed()

void initButton();

#endif // Button_H
