#include "bsp_dma.h"


/* 定义aSRC_Const_Buffer数组作为DMA传输数据源
const关键字将aSRC_Const_Buffer数组变量定义为常量类型(放在Flash中) */
const uint32_t aSRC_Const_Buffer[BUFFER_SIZE]= {
                        0x01020304,0x05060708,0x090A0B0C,0x0D0E0F10,
                        0x11121314,0x15161718,0x191A1B1C,0x1D1E1F20,
                        0x21222324,0x25262728,0x292A2B2C,0x2D2E2F30,
                        0x31323334,0x35363738,0x393A3B3C,0x3D3E3F40,
                        0x41424344,0x45464748,0x494A4B4C,0x4D4E4F50,
                        0x51525354,0x55565758,0x595A5B5C,0x5D5E5F60,
                        0x61626364,0x65666768,0x696A6B6C,0x6D6E6F70,
                        0x71727374,0x75767778,0x797A7B7C,0x7D7E7F80
};


/* 定义DMA传输目标存储器(放在SRAM中) */
uint32_t aDST_Buffer[BUFFER_SIZE];

uint8_t SendBuff[SENDBUFF_SIZE];

void USART_DMA_Config(void)
{
    DMA_InitTypeDef DMA_InitStructure;

    /*开启DMA时钟*/
    RCC_AHB1PeriphClockCmd(DEBUG_USART_DMA_CLK, ENABLE);

    /* 复位初始化DMA数据流 */
    DMA_DeInit(DEBUG_USART_DMA_STREAM);

    /* 确保DMA数据流复位完成 */
    while (DMA_GetCmdStatus(DEBUG_USART_DMA_STREAM) != DISABLE)  {
    }

    /*usart1 tx对应dma2，通道4，数据流7*/
    DMA_InitStructure.DMA_Channel = DEBUG_USART_DMA_CHANNEL;
    /*设置DMA源：串口数据寄存器地址*/
    DMA_InitStructure.DMA_PeripheralBaseAddr = DEBUG_USART_DR_BASE;
    /*内存地址(要传输的变量的指针)*/
    DMA_InitStructure.DMA_Memory0BaseAddr = (u32)SendBuff;
    /*方向：从内存到外设*/
    DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
    /*传输大小DMA_BufferSize=SENDBUFF_SIZE*/
    DMA_InitStructure.DMA_BufferSize = SENDBUFF_SIZE;
    /*外设地址不增*/
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    /*内存地址自增*/
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    /*外设数据单位*/
    DMA_InitStructure.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Byte;
    /*内存数据单位 8bit*/
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    /*DMA模式：不断循环*/
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    /*优先级：中*/
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
    /*禁用FIFO*/
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
    /*存储器突发传输 16个节拍*/
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    /*外设突发传输 1个节拍*/
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
    /*配置DMA2的数据流7*/
    DMA_Init(DEBUG_USART_DMA_STREAM, &DMA_InitStructure);

    /*使能DMA*/
    DMA_Cmd(DEBUG_USART_DMA_STREAM, ENABLE);

    /* 等待DMA数据流有效*/
    while (DMA_GetCmdStatus(DEBUG_USART_DMA_STREAM) != ENABLE) {
    }
}


uint8_t Buffercmp(const uint32_t* pBuffer,
                uint32_t* pBuffer1, uint16_t BufferLength)
{
    /* 数据长度递减 */
    while (BufferLength--) {
        /* 判断两个数据源是否对应相等 */
        if (*pBuffer != *pBuffer1) {
            /* 对应数据源不相等马上退出函数，并返回0 */
            return 0;
        }
        /* 递增两个数据源的地址指针 */
        pBuffer++;
        pBuffer1++;
    }
    /* 完成判断并且对应数据相对 */
    return 1;
}
