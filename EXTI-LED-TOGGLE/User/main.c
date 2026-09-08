#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_exti.h"


void Delay(uint32_t count)
{
	for(; count!=0; count --);
}


int main(void)	
{
	
	LED_GPIO_Config();
	
	GPIO_SetBits(GPIOF, GPIO_Pin_6);
	GPIO_SetBits(GPIOF, GPIO_Pin_7);
	GPIO_SetBits(GPIOF, GPIO_Pin_8);
	
	EXTI_Key_Config();
	
	while(1)
	{
	}
	
	
	return 0;
}