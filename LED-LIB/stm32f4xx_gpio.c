#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"



void GPIO_SetBits(GPIO_TypeDef * GPIO, uint16_t GPIO_Pin)
{
    GPIO->BSRRL = GPIO_Pin;
}


void GPIO_ResetBits(GPIO_TypeDef * GPIO, uint16_t GPIO_Pin)
{
    GPIO->BSRRH = GPIO_Pin;
}


void GPIO_Init(GPIO_TypeDef * GPIOx, GPIO_InitTypeDef * GPIO_Init_Def)
{
    uint16_t pin_pos = 0, current_pos = 0, pos = 0;
    
    /*-- GPIO Mode Configuration --*/
    for(pin_pos = 0; pin_pos < 16; pin_pos++)
    {
        /*依序檢查16根Pin腳位*/
        pos = ((uint16_t)0x01) << pin_pos;

        /*檢查當前的初始化結構體內，是否有定義到與當前Pos相同的資訊*/
        current_pos = GPIO_Init_Def->GPIO_PinNum & pos;

        /*有的話就進入初始化流程*/
        if(current_pos)
        {
            /*先清空當前腳位的MODER設置*/
            GPIOx->MODER &= ~(0x03 << 2*pin_pos);

            /*接著設置當前腳位的MODER，設置為Init結構體內的設置*/
            GPIOx->MODER |= ((uint32_t)GPIO_Init_Def->GPIO_Mode << 2*pin_pos);

            /*GPIOx，PUPDR寄存器的GPIO_Pin引脚，PUPDR位清空*/
            GPIOx->PUPDR &= ~(0x03 << 2*pin_pos);

            /*設置PUPDR寄存器*/
            GPIOx->PUPDR |= ((uint32_t)GPIO_Init_Def->GPIO_PuPd << 2*pin_pos);

            /*如果模式是輸出模式跟復用模式，會需要配置速度跟輸出模式*/
            if(GPIO_Init_Def->GPIO_Mode == GPIO_OUTPUT || GPIO_Init_Def->GPIO_Mode == GPIO_ALT_MODE)
            {
                /*清空原先的資訊*/
                GPIOx->OSPEEDR &= ~(0x03 << 2*pin_pos);

                /*設置新的速度*/
                GPIOx->OSPEEDR |= ((uint32_t)GPIO_Init_Def->GPIO_Ospeed << 2*pin_pos);


                /*清空原先的資訊*/
                GPIOx->OTYPER &= ~(0x03 << 2*pin_pos);

                /*設置新的速度*/
                GPIOx->OTYPER |= ((uint32_t)GPIO_Init_Def->GPIO_OType << pin_pos);
            }
        }
    }
}