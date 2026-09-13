#ifndef _BSP_DMA_H
#define _BSP_DMA_H

#include "stm32f4xx.h"
#include "stm32f4xx_dma.h"
#include "bsp_led.h"

/* 相关宏定义，使用存储器到存储器传输必须使用DMA2 */
#define DMA_STREAM               DMA2_Stream0
#define DMA_CHANNEL              DMA_Channel_0
#define DMA_STREAM_CLOCK         RCC_AHB1Periph_DMA2
#define DMA_FLAG_TCIF            DMA_FLAG_TCIF0

#define BUFFER_SIZE              32
#define TIMEOUT_MAX              10000 /* Maximum timeout value */

/* 這兩個緩衝區只在 bsp_dma.c 配置儲存空間，其他模組透過 extern 使用。 */
extern const uint32_t aSRC_Const_Buffer[BUFFER_SIZE];
extern uint32_t aDST_Buffer[BUFFER_SIZE];

void DMA_Config(void);

uint8_t Buffercmp(const uint32_t* pBuffer, uint32_t* pBuffer1, uint16_t BufferLength);




#endif
