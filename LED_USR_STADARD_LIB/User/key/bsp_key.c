#include "bsp_key.h"

void LED_KEY_Config(void)
{
    //1. RCC Clock(AHB1)
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    //2. GPIO Type Structure
    GPIO_InitTypeDef GPIO_InitStruct;
	
	
		//3. GPIO Structure Config
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
		//GPIO_InitStruct.GPIO_Speed = GPIO_Low_Speed;
		//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
		//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    
    //4. GPIO Init
		GPIO_Init(GPIOA, &GPIO_InitStruct);

}

uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == Bit_SET)
	{
		uint32_t count = 0xffffff;
		for(; count!=0; count --);
		return KEY_PRESSED;
	}
	
	return KEY_FREE;
	
}