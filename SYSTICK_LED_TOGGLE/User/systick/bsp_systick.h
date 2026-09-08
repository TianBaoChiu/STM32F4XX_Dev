#ifndef _SYSTICK_H
#define _SYSTICK_H
#include "stm32f4xx.h"

void Systick_Init(void);
void Delay_ms(__IO uint32_t nTime);
	
#endif 


