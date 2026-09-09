#include "stm32f4xx.h"
#include "bsp_usart.h"

int main(void)
{
    volatile uint32_t delay;

    Debug_USART_Config();
	
		while (1)
		{
				Usart_SendString(DEBUG_USART, "Hello USART1234!\r\n");

				for (delay = 0; delay < 10000000U; delay++)
				{
						__NOP();
				}
		}
}