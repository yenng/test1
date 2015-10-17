#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "GPIO.h"
#include "Rcc.h"

void delay(uint32_t delayCount){
	while(delayCount != 0)
		delayCount--;
}

int main(void)
{
	int reading;
	configurePin(GPIO_MODE_OUTPUT, PIN_14,PORTG);
	configurePin(GPIO_MODE_OUTPUT, PIN_13,PORTG);
	configurePin(GPIO_MODE_OUTPUT, PIN_13,PORTB);
	configurePin(GPIO_MODE_OUTPUT, PIN_5,PORTC);
	configurePin(GPIO_MODE_INPUT, PIN_0,PORTA);
	PORTA->PUPDR = 0x64000000;

	while(1){
		if(PORTA->IBR & 0x00000001){
			writeOne(PIN_14,PORTG);
			writeZero(PIN_13,PORTG);
			writeOne(PIN_13,PORTB);
			writeOne(PIN_5,PORTC);
			delay(0x9999);
			writeZero(PIN_14,PORTG);
			writeOne(PIN_13,PORTG);
			writeZero(PIN_13,PORTB);
			writeZero(PIN_5,PORTC);
			delay(0x9999);
		}
		else{
			writeOne(PIN_14,PORTG);
			writeOne(PIN_13,PORTG);
			writeOne(PIN_13,PORTB);
			writeZero(PIN_5,PORTC);
		}
	}

}
