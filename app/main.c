#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "GPIO.h"

void delay(uint32_t delayCount){
	while(delayCount != 0)
		delayCount--;
}

int main(void)
{
	configurePin(GPIO_MODE_OUTPUT_PP, GPIO_PIN_14,GPIOG);
	while(1){
		writeOne(GPIO_PIN_14,GPIOG);
		writeZero(GPIO_PIN_13,GPIOG);
		delay(0x99999);
		writeZero(GPIO_PIN_14,GPIOG);
		writeOne(GPIO_PIN_13,GPIOG);
		delay(0x99999);
	}

}
