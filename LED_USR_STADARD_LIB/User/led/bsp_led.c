#include "bsp_led.h"

void LED_GPIO_Config(void)
{
    //1. RCC Clock(AHB1)
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

    //2. GPIO Type Structure
    GPIO_InitTypeDef GPIO_InitStruct;
	
	
		//3. GPIO Structure Config
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
		GPIO_InitStruct.GPIO_Speed = GPIO_Low_Speed;
		GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
		//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    
    //4. GPIO Init
		GPIO_Init(GPIOF, &GPIO_InitStruct);

}

