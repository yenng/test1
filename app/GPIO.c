#include "GPIO.h"
#include "Rcc.h"
#include <stdint.h>
#include "stm32f4xx_hal_rcc.h"

void configurePin(int direction, int pinNum, GPIO *port){
	gpioUnresetEnableClock(port);

	int *ptr = (int*)0x40023810;
	ptr[0] = 0x00000000;

	int *ptr1 = (int*)0x40023830;
	ptr1[0] = 0x0010007F;

	port->MODER &= ~(3 <<(pinNum * 2));
	port->MODER |= (direction <<(pinNum * 2));

	port->OTYPER &= ~(1<<pinNum);

	port->OSPEED &= ~(3 << (pinNum*2));
	port->OSPEED |= GPIO_MODE_VERY_HIGH_SPEED << (pinNum*2);

	port->PUPDR &= ~(3 << (pinNum*2));
	port->PUPDR |= (PULL_DOWN <<(pinNum * 2));
}

void writeOne(uint16_t pinNum, GPIO *port){
//	port->ODR &= ~( 1 << (pinNum));
//	port->ODR |= 1 << (pinNum);
	port->BSRR |= (uint32_t)(1 << pinNum);
}
void writeZero(uint16_t pinNum, GPIO *port){
//	port->ODR &= ~( 1 << pinNum);
//	port->ODR |= (0 << pinNum);
	port->BSRR |= (uint32_t)(1 << pinNum+16);
}
