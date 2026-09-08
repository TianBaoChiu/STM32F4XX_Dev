#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_systick.h"

void Delay(uint32_t count)
{
	for(; count!=0; count --);
}


int main(void)	
{
	
	LED_GPIO_Config();
	Systick_Init();
	
	GPIO_SetBits(GPIOF, GPIO_Pin_6);
	GPIO_SetBits(GPIOF, GPIO_Pin_7);
	GPIO_SetBits(GPIOF, GPIO_Pin_8);
	
	while(1)
	{
		GPIO_ResetBits(GPIOF, GPIO_Pin_6);
		Delay_ms(500);
		GPIO_SetBits(GPIOF, GPIO_Pin_6);
		Delay_ms(500);
	}
	
	
	return 0;
}