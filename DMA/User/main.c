#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_dma.h"



int main(void)	
{
	
	 /* 定义存放比较结果变量 */
    uint8_t TransferStatus;

	LED_GPIO_Config();

	GPIO_ResetBits(GPIOF, GPIO_Pin_6);
	GPIO_ResetBits(GPIOF, GPIO_Pin_7);
	GPIO_ResetBits(GPIOF, GPIO_Pin_8);

	Delay(0xFFFFFF);

	
	GPIO_SetBits(GPIOF, GPIO_Pin_6);
	GPIO_SetBits(GPIOF, GPIO_Pin_7);
	GPIO_SetBits(GPIOF, GPIO_Pin_8);

		
	DMA_Config();

	/* 等待DMA传输完成 */
    while (DMA_GetFlagStatus(DMA_STREAM,DMA_FLAG_TCIF)==DISABLE) {

    }

	/* 比较源数据与传输后数据 */
    TransferStatus=Buffercmp(aSRC_Const_Buffer, aDST_Buffer, BUFFER_SIZE);
	


	 /* 判断源数据与传输后数据比较结果*/
    if (TransferStatus==0) 
		{
        /* 源数据与传输后数据不相等时RGB彩色灯显示红色 */
        GPIO_ResetBits(GPIOF, GPIO_Pin_6);
    } 
		else 
		{
        /* 源数据与传输后数据相等时RGB彩色灯显示蓝色 */
        GPIO_ResetBits(GPIOF, GPIO_Pin_8);
    }


	
	while(1)
	{

	};
	
	
	return 0;
}