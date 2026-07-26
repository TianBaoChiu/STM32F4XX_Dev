#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"


#include <arm_acle.h>



static void delay_loop(uint32_t count);

int main(void)
{

	GPIO_InitTypeDef GPIO_Init_Struct;

	/*Enable AHB1 Clock for GPIOF Port*/
	RCC->RCC_AHB1ENR |= (0x01 << 5);


	/*Init PF6、7、8*/
	GPIO_Init_Struct.GPIO_PinNum = GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8;

	GPIO_Init_Struct.GPIO_Mode = GPIO_OUTPUT;

	GPIO_Init_Struct.GPIO_PuPd = GPIO_PULL_UP;

	GPIO_Init_Struct.GPIO_OType = GPIO_PUSH_PULL;

	GPIO_Init_Struct.GPIO_Ospeed = GPIO_SPEED_LOW;
	
	GPIO_Init(GPIOF, &GPIO_Init_Struct);
	
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

	