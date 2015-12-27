#include "unity.h"
#include "Register.h"
#include "HostRcc.h"
#include "Rcc.h"

void notResetAndClockGpioA(){
  RCC_reg->RCC_AHB1ENR |= 1;
	RCC_reg->RCC_AHB1RSTR &= ~1;
}

void setUp(void){
  RCC_reg->RCC_AHB1ENR = 0;
	RCC_reg->RCC_AHB1RSTR = 0xFFFFFFFF;
}

void tearDown(void){}

void test_module_generator_needs_to_be_implemented(void){
  RCC_reg->RCC_AHB1ENR = 0;
	RCC_reg->RCC_AHB1RSTR = 0xFFFFFFFF;
  
	RCC_reg->RCC_AHB1ENR |= 1;
	RCC_reg->RCC_AHB1RSTR &= ~1;
  
  TEST_ASSERT_EQUAL(1,RCC_reg->RCC_AHB1ENR &1);
  TEST_ASSERT_EQUAL(0,RCC_reg->RCC_AHB1RSTR &1);
}
