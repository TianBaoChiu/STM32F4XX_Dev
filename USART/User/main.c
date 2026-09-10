#include "stm32f4xx.h"
#include "bsp_usart.h"

int main(void)
{
    Debug_USART_Config();

    Usart_SendString(
        DEBUG_USART,
        "USART interrupt test ready.\r\n"
    );

    while (1)
    {
    }
}