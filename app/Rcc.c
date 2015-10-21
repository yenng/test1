#include "Rcc.h"
#include "GPIO.h"

void gpioUnresetEnableClock(GPIO* port){
	int valToShift = ((int)port - (0x40020000))/(0x400);

	RCC_reg->RCC_AHB1RSTR &= ~(1 << (valToShift));
	RCC_reg->RCC_AHB1ENR |= (0x00100000 | ~(0 << (valToShift)));
}
