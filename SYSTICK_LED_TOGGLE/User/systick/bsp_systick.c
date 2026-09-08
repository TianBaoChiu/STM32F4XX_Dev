#include "bsp_systick.h"


volatile uint32_t TimingDelay;


void Systick_Init(void)
{
	
		//1000 is 1000ms
		if(SysTick_Config(SystemCoreClock / 1000)) 
		{
			while(1);
		}
}
	
void Delay_ms(volatile uint32_t nTime)
{
	TimingDelay = nTime;
	while(TimingDelay != 0);
}