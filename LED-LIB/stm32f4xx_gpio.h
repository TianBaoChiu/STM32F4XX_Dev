#ifndef _STM32F4XX_H
#define _STM32F4XX_H

#include "stm32f4xx.h"


#define GPIO_PIN_0               ((uint16_t)(1 << 0))
#define GPIO_PIN_1               ((uint16_t)(1 << 1))
#define GPIO_PIN_2               ((uint16_t)(1 << 2))
#define GPIO_PIN_3               ((uint16_t)(1 << 3))
#define GPIO_PIN_4               ((uint16_t)(1 << 4))
#define GPIO_PIN_5               ((uint16_t)(1 << 5))
#define GPIO_PIN_6               ((uint16_t)(1 << 6))
#define GPIO_PIN_7               ((uint16_t)(1 << 7))
#define GPIO_PIN_8               ((uint16_t)(1 << 8))
#define GPIO_PIN_9               ((uint16_t)(1 << 9))
#define GPIO_PIN_10              ((uint16_t)(1 << 10))
#define GPIO_PIN_11              ((uint16_t)(1 << 11))
#define GPIO_PIN_12              ((uint16_t)(1 << 12))
#define GPIO_PIN_13              ((uint16_t)(1 << 13))
#define GPIO_PIN_14              ((uint16_t)(1 << 14))
#define GPIO_PIN_15              ((uint16_t)(1 << 15))
#define GPIO_PIN_ALL             ((uint16_t)(0xFFFF))


void GPIO_SetBits(GPIO_TypeDef * GPIO, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef * GPIO, uint16_t GPIO_Pin);


typedef enum
{
    GPIO_INPUT       = 0x00,
    GPIO_OUTPUT      = 0x01,
    GPIO_ALT_MODE    = 0x02,
    GPIO_ANALOG_MODE = 0x03
}GPIOMode_TypeDef;

typedef enum
{
    GPIO_NPU_NPD      = 0x00,
    GPIO_PULL_UP      = 0x01,
    GPIO_PULL_DOWN    = 0x02,
    GPIO_RESERVED     = 0x03
}GPIOPuPd_TypeDef;


typedef enum
{
    GPIO_PUSH_PULL     = 0x00,
    GPIO_OPEN_DRAIN    = 0x01
}GPIOOType_TypeDef;

typedef enum
{
    GPIO_SPEED_LOW          = 0x00,
    GPIO_SPEED_MIDIUM       = 0x01,
    GPIO_SPEED_HIGH         = 0x02,
    GPIO_SPEED_VERY_HIGH    = 0x03
}GPIOOspeed_TypeDef;



typedef struct
{
    uint16_t            GPIO_PinNum;
    GPIOMode_TypeDef    GPIO_Mode;
    GPIOPuPd_TypeDef    GPIO_PuPd;
    GPIOOType_TypeDef   GPIO_OType;
    GPIOOspeed_TypeDef  GPIO_Ospeed;
}GPIO_InitTypeDef;

#endif