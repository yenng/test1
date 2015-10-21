#ifndef __GPIO_H__
#define	__GPIO_H__
#include "stm32f4xx_hal_gpio.h"

#define GPIO_OUTPUT			GPIO_MODE_OUTPUT_PP
#define GPIO_INPUT			GPIO_MODE_INPUT
void configurePin(int direction, int pinNum, GPIO_TypeDef *port);
void writeOne(int pinNum, GPIO_InitTypeDef *port);
void writeZero(int pinNum, GPIO_InitTypeDef *port);

#endif //__GPIO_H__
