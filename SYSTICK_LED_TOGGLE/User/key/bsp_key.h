#ifndef _BSP_KEY_H
#define _BSP_KEY_H

#include "stm32f4xx.h"

#define KEY_PRESSED 1
#define KEY_FREE		0

void LED_KEY_Config(void);
uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif