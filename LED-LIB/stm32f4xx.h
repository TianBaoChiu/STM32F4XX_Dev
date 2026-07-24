#ifndef _STM32FXX_H
#define _STM32FXX_H

#include <stdint.h>
#include "stm32f4xx_gpio.h"

#define __IO                volatile
#define __I                 volatile
#define __O                 volatile const

#define DELAY_COUINT				2000000U


#define GPIOA_BASE              0x40020000U
#define GPIOB_BASE              0x40020400U
#define GPIOC_BASE              0x40020800U
#define GPIOD_BASE              0x40020C00U
#define GPIOE_BASE              0x40021000U
#define GPIOF_BASE              0x40021400U
#define GPIOG_BASE              0x40021800U
#define GPIOH_BASE              0x40021C00U
#define GPIOI_BASE              0x40022000U
#define GPIOJ_BASE              0x40022400U
#define GPIOK_BASE              0x40022800U



#define RCC_BASE                0x40023800U
	
typedef struct 
{
    __IO uint32_t RCC_CR;                   /*0x00*/
    __IO uint32_t RCC_PLLCFGR;              /*0x04*/
    __IO uint32_t RCC_CFGR;                 /*0x08*/
    __IO uint32_t RCC_CIR;                  /*0x0C*/
    __IO uint32_t RCC_AHB1RSTR;             /*0x10*/
    __IO uint32_t RCC_AHB2RSTR;             /*0x14*/
    __IO uint32_t RCC_AHB3RSTR;             /*0x18*/
    __IO uint32_t RCC_RESERVED0;            /*0x1C*/
    __IO uint32_t RCC_APB1RSTR;             /*0x20*/
    __IO uint32_t RCC_APB2RSTR;             /*0x24*/
    __IO uint32_t RCC_RESERVED1[2];         /*0x28~0x2C*/
    __IO uint32_t RCC_AHB1ENR;              /*0x30*/
    __IO uint32_t RCC_AHB2ENR;
    __IO uint32_t RCC_AHB3ENR;
    __IO uint32_t RCC_APB1ENR;
    __IO uint32_t RCC_APB2ENR;
    __IO uint32_t RCC_AHB1LPENR;
    __IO uint32_t RCC_AHB2LPENR;
    __IO uint32_t RCC_AHB3LPENR;
    __IO uint32_t RCC_APB1LPENR;
    __IO uint32_t RCC_APB2LPENR;
    __IO uint32_t RCC_BDCR;
    __IO uint32_t RCC_CSR;
    __IO uint32_t RCC_SSCGR;
    __IO uint32_t RCC_PLLI2SCFGR;
    __IO uint32_t RCC_PLLSAICFGR;
    __IO uint32_t RCC_DCKCFGR;
}RCC_TypeDef;


#define RCC                ((RCC_TypeDef *)(RCC_BASE))



typedef struct
{
    __IO uint32_t MODER;
    __IO uint32_t OTYPER;
    __IO uint32_t OSPEEDR;
    __IO uint32_t PUPDR;
    __I uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint16_t BSRRL;
    __IO uint16_t BSRRH;
    __IO uint32_t LCKR;
    __IO uint32_t AFRL;
    __IO uint32_t AFRH;

}GPIO_TypeDef;

#define GPIOA               ((GPIO_TypeDef *)(GPIOA_BASE))
#define GPIOB               ((GPIO_TypeDef *)(GPIOB_BASE))
#define GPIOC               ((GPIO_TypeDef *)(GPIOC_BASE))
#define GPIOD               ((GPIO_TypeDef *)(GPIOD_BASE))
#define GPIOE               ((GPIO_TypeDef *)(GPIOE_BASE))
#define GPIOF               ((GPIO_TypeDef *)(GPIOF_BASE))
#define GPIOG               ((GPIO_TypeDef *)(GPIOG_BASE))
#define GPIOH               ((GPIO_TypeDef *)(GPIOH_BASE))
#define GPIOI               ((GPIO_TypeDef *)(GPIOI_BASE))
#define GPIOJ               ((GPIO_TypeDef *)(GPIOJ_BASE))
#define GPIOK               ((GPIO_TypeDef *)(GPIOK_BASE))



#endif