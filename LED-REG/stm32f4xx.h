#ifndef _STM32FXX_H
#define _STM32FXX_H

#include <stdint.h>




#define RCC_BASE                0x40023800U
#define GPIOF_BASE              0x40021400U



#define RCC_AHB1ENR_OFFSET       0x30

#define RCC_AHB1ENR_REG         (volatile uint32_t *) (RCC_BASE + RCC_AHB1ENR_OFFSET)
	

#define DELAY_COUINT				2000000U


#define __IO                volatile
#define __I                 volatile
#define __O                 volatile const

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

#define GPIOF               ((GPIO_TypeDef *)(GPIOF_BASE))



#endif