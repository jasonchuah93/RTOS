#include "Led.h"

//Initialize LEDs on PORTG
void initLED(int pin){

	GPIO_InitTypeDef GPioInfo;

	__GPIOG_CLK_ENABLE();

	GPioInfo.Mode = GPIO_MODE_OUTPUT_PP;
	GPioInfo.Pin = pin;
	GPioInfo.Pull = GPIO_NOPULL;
	GPioInfo.Speed = GPIO_SPEED_HIGH;
	GPioInfo.Alternate = GPIO_MODE_AF_PP;

	//Init LED on PG13
	HAL_GPIO_Init(GPIOG, &GPioInfo);

}

//Initializ LEDs on PORTB
void initRearLED1(){

	GPIO_InitTypeDef GPioInfo;

	__GPIOB_CLK_ENABLE();

	GPioInfo.Mode = GPIO_MODE_OUTPUT_PP;
	GPioInfo.Pin = GPIO_PIN_13;
	GPioInfo.Pull = GPIO_NOPULL;
	GPioInfo.Speed = GPIO_SPEED_HIGH;
	GPioInfo.Alternate = GPIO_MODE_AF_PP;

	//Init LED locate on LED5
	HAL_GPIO_Init(GPIOB, &GPioInfo);

}

//Initialize LED on PORTC
void initRearLED2(){

	GPIO_InitTypeDef GPioInfo;

	__GPIOC_CLK_ENABLE();

	GPioInfo.Mode = GPIO_MODE_OUTPUT_PP;
	GPioInfo.Pin = GPIO_PIN_5;
	GPioInfo.Pull = GPIO_NOPULL;
	GPioInfo.Speed = GPIO_SPEED_HIGH;
	GPioInfo.Alternate = GPIO_MODE_AF_PP;

	//Init LED locate LED6
	HAL_GPIO_Init(GPIOC, &GPioInfo);

}
