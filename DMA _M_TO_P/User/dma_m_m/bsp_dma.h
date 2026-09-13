#ifndef _BSP_DMA_H
#define _BSP_DMA_H

#include "stm32f4xx.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_rcc.h"
#include "bsp_led.h"

/* 相关宏定义，使用存储器到存储器传输必须使用DMA2 */
#define DMA_STREAM               DMA2_Stream0
#define DMA_CHANNEL              DMA_Channel_0
#define DMA_STREAM_CLOCK         RCC_AHB1Periph_DMA2
#define DMA_FLAG_TCIF            DMA_FLAG_TCIF0

#define BUFFER_SIZE              32
#define TIMEOUT_MAX              10000 /* Maximum timeout value */

//DMA
#define DEBUG_USART_DR_BASE                     (USART1_BASE+0x04)
#define SENDBUFF_SIZE                            5000   //一次发送的数据量
#define DEBUG_USART_DMA_CLK                      RCC_AHB1Periph_DMA2
#define DEBUG_USART_DMA_CHANNEL                  DMA_Channel_4
#define DEBUG_USART_DMA_STREAM                   DMA2_Stream7

extern uint8_t SendBuff[SENDBUFF_SIZE];

void USART_DMA_Config(void);



#endif
