#include "stm32f4xx.h"
#include <arm_acle.h>



static void delay_loop(uint32_t count);

int main(void)
{




	
	
	/*Enable AHB1 Clock for GPIOF Port*/
	RCC->RCC_AHB1ENR |= (0x01 << 5);
	
	/*Clean reg value at bit 12 and 13*/
	GPIOF->MODER &= ~(0x03 << 2*6);
	
		/*Clean reg value at bit 14 and 15*/
	GPIOF->MODER &= ~(0x03 << 2*7);

		/*Clean reg value at bit 16 and 17*/
	GPIOF->MODER &= ~(0x03 << 2*8);
	
	
	/*Set reg value at bit 12 and 13 as Output mode*/
	GPIOF->MODER |= (0x01 << 2*6);
	
		/*Set reg value at bit 14 and 15 as Output mode*/
	GPIOF->MODER |= (0x01 << 2*7); 
	
		/*Set reg value at bit 16 and 17 as Output mode*/
	GPIOF->MODER |= (0x01 << 2*8);
	
	while(1)
	{
		/*Set GPIOF 8 pin output HIGH level(B)*/
		GPIO_SetBits(GPIOF, GPIO_PIN_8);
		/*Set GPIOF 6 pin output HIGH level(R)*/
		GPIO_SetBits(GPIOF, GPIO_PIN_7);
		
		/*Set GPIOF 6 pin output LOW level(R)*/
		GPIO_ResetBits(GPIOF, GPIO_PIN_6);
		
		delay_loop(DELAY_COUINT);
		
		/*Set GPIOF 6 pin output HIGH level(R)*/
		GPIO_SetBits(GPIOF, GPIO_PIN_6);
		
		/*Set GPIOF 8 pin output HIGH level(G)*/
		GPIO_SetBits(GPIOF, GPIO_PIN_8);
		
		/*Set GPIOF 7 pin output LOW level(G)*/
		GPIO_ResetBits(GPIOF, GPIO_PIN_7);
		
		delay_loop(DELAY_COUINT);
		
		/*Set GPIOF 7 pin output HIGH level(G)*/
		GPIO_SetBits(GPIOF, GPIO_PIN_7);
		
		/*Set GPIOF 6 pin output HIGH level(B)*/
		GPIO_SetBits(GPIOF, GPIO_PIN_6);
		
		/*Set GPIOF 8 pin output LOW level(B)*/
		GPIO_ResetBits(GPIOF, GPIO_PIN_8);
		
		delay_loop(DELAY_COUINT);
	}
	
	return 0;
}

void SystemInit(void) 
{
	/*to build this project, must write the SystemInit funtion here(startup doc line 180)*/
}	


static void delay_loop(uint32_t count)
{
	while(count > 0)
	{
		count --;
    __nop();
		
	}
}

	