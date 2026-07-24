#include "stm32f4xx.h"



void GPIO_SetBits(GPIO_DefType * GPIO, uint16_t GPIO_Pin)
{
    GPIO->BSRRL = GPIO_Pin;
}


void GPIO_ResetBits(GPIO_DefType * GPIO, uint16_t GPIO_Pin)
{
    GPIO->BSRRH = GPIO_Pin;
}