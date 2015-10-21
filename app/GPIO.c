#include "GPIO.h"
#include "stm32f4xx_hal_rcc.h"

void configurePin(int direction, int pinNum, GPIO_TypeDef *port){
	GPIO_InitTypeDef GpioInfo;

	__HAL_RCC_GPIOG_CLK_ENABLE();

	volatile int *ptr = (int*)0x40021800;
	ptr[0] = 0x14000000;
	ptr[1] = 0;
	ptr[2] = 0x28000000;

//	GPIO_InitTypeDef gpio;
//	gpio.Pin=pinNum;
//	gpio.Pull=GPIO_NOPULL;
//	gpio.Mode=direction;
//	gpio.Speed = GPIO_SPEED_MEDIUM;

//	HAL_GPIO_Init(port,&gpio);
}

void writeOne(int pinNum, GPIO_InitTypeDef *port){
	HAL_GPIO_WritePin(port, pinNum, GPIO_PIN_SET);
}

void writeZero(int pinNum, GPIO_InitTypeDef *port){
	HAL_GPIO_WritePin(port, pinNum, GPIO_PIN_RESET);
}
