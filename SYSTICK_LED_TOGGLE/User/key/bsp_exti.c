#include "bsp_exti.h"

static void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;

    //Config priority to 1
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

    //Interrupt source is KEY1
    NVIC_InitStructure.NVIC_IRQChannel = KEY1_INT_EXTI_IRQ;
    //Config PreemptionPriority to 1
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    //Config SubPriority to 1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    //Enable this IRQ Channel
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    // For key 2 
    NVIC_InitStructure.NVIC_IRQChannel = KEY2_INT_EXTI_IRQ;
    NVIC_Init(&NVIC_InitStructure);
}

void EXTI_Key_Config(void)
{
	
	GPIO_InitTypeDef	GPIO_InitStructure;
	EXTI_InitTypeDef  EXTI_InitStructure;
	
	//Init GPIO where EXTI will use it
	//Enable AHB1 clock
	RCC_AHB1PeriphClockCmd(KEY1_INT_GPIO_CLK | KEY2_INT_GPIO_CLK, ENABLE);
	
	//Enable APB2 clock
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
	//Init Key1 GPIO
	GPIO_InitStructure.GPIO_Pin = KEY1_INT_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStructure);
	
	//Init Key2 GPIO
	GPIO_InitStructure.GPIO_Pin = KEY2_INT_GPIO_PIN;
	GPIO_Init(KEY2_INT_GPIO_PORT, &GPIO_InitStructure);
	
	
	
	//Init EXIT LINE1
	SYSCFG_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE,
                        KEY1_INT_EXTI_PINSOURCE);
	EXTI_InitStructure.EXTI_Line = KEY1_INT_EXTI_LINE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	
	EXTI_Init(&EXTI_InitStructure);
	
	//Init EXTI LINE13
	SYSCFG_EXTILineConfig(KEY2_INT_EXTI_PORTSOURCE,
                        KEY2_INT_EXTI_PINSOURCE);

	EXTI_InitStructure.EXTI_Line = KEY2_INT_EXTI_LINE;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);
	
	EXTI_ClearITPendingBit(KEY1_INT_EXTI_LINE |
                        KEY2_INT_EXTI_LINE);
												
	NVIC_Configuration();
	
}
