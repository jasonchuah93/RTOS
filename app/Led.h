#ifndef Led_H
#define Led_H

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

#define LED1 (GPIO_PIN_13) // PG13 GREEN
#define LED2 (GPIO_PIN_14) // PG14 RED
#define LED3 (GPIO_PIN_13) // LD5  GREEN
#define LED4 (GPIO_PIN_5) // LD6   RED

#define PORTG (GPIOG)
#define PORTB (GPIOB)
#define PORTC (GPIOC)

#define turnOnLED(port,x) HAL_GPIO_WritePin(port, x, GPIO_PIN_SET);
#define turnOffLED(port,x) HAL_GPIO_WritePin(port, x, GPIO_PIN_RESET);

void initLED(int pin);
void initRearLED1();
void initRearLED2();

#endif // Led_H
