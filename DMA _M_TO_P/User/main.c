#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_dma.h"
#include "bsp_usart.h"



int main(void)	
{
	
	uint16_t i;
    /* 初始化USART */
    Debug_USART_Config();

    /* 配置使用DMA模式 */
    USART_DMA_Config();

    /* 配置RGB彩色灯 */
    LED_GPIO_Config();


	GPIO_ResetBits(GPIOF, GPIO_Pin_6);
	GPIO_ResetBits(GPIOF, GPIO_Pin_7);
	GPIO_ResetBits(GPIOF, GPIO_Pin_8);

	Delay(0xFFFFFF);

	
	GPIO_SetBits(GPIOF, GPIO_Pin_6);
	GPIO_SetBits(GPIOF, GPIO_Pin_7);
	GPIO_SetBits(GPIOF, GPIO_Pin_8);

	Delay(0xFFFFFF);

	
    /*填充将要发送的数据*/
    for (i=0; i<SENDBUFF_SIZE; i++) {
        SendBuff[i]  = '1';

    }
		
		 /* USART1 向 DMA发出TX请求 */
    USART_DMACmd(DEBUG_USART, USART_DMAReq_Tx, ENABLE);
		
		 /* 此时CPU是空闲的，可以干其他的事情 */
    //例如同时控制LED
    while (1) {
        GPIO_ResetBits(GPIOF, GPIO_Pin_6);
        Delay(0xFFFFFF);
		GPIO_SetBits(GPIOF, GPIO_Pin_6);
		Delay(0xFFFFFF);
    }
	
	return 0;
}