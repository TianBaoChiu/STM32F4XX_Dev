#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_key.h"


void Delay(uint32_t count)
{
	for(; count!=0; count --);
}


int main(void)	
{
	
	LED_GPIO_Config();
	LED_KEY_Config();
	
	GPIO_SetBits(GPIOF, GPIO_Pin_6);
	GPIO_SetBits(GPIOF, GPIO_Pin_7);
	GPIO_SetBits(GPIOF, GPIO_Pin_8);
	
	while(1)
	{
		
		if(Key_Scan(GPIOA, GPIO_Pin_0) == KEY_PRESSED)
		{
			/*GPIO_ResetBits(GPIOF, GPIO_Pin_6);
			GPIO_SetBits(GPIOF, GPIO_Pin_7);
			GPIO_SetBits(GPIOF, GPIO_Pin_8);
			Delay(0xffffff);
			
			GPIO_ResetBits(GPIOF, GPIO_Pin_7);
			GPIO_SetBits(GPIOF, GPIO_Pin_6);
			GPIO_SetBits(GPIOF, GPIO_Pin_8);
			Delay(0xffffff);
			
			GPIO_ResetBits(GPIOF, GPIO_Pin_8);
			GPIO_SetBits(GPIOF, GPIO_Pin_6);
			GPIO_SetBits(GPIOF, GPIO_Pin_7);
			Delay(0xffffff);*/
			
			GPIO_ToggleBits(GPIOF, GPIO_Pin_6);
		}
		/*else
		{
			GPIO_SetBits(GPIOF, GPIO_Pin_6);
			GPIO_SetBits(GPIOF, GPIO_Pin_7);
			GPIO_SetBits(GPIOF, GPIO_Pin_8);
		}*/
	}
	
	
	return 0;
}