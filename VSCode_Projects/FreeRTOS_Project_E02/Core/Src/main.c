/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "FreeRTOS.h"
#include "portmacro.h"
#include "projdefs.h"
#include "stm32f4xx_hal.h"
#include "task.h"
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
UART_HandleTypeDef huart1;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
static void task1_handler(void *argument);
static void task2_handler(void *argument);
static void task3_handler(void *argument);

static void MX_USART1_UART_Init(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  MX_USART1_UART_Init();

  printf("UART is Ready\r\n");

  BaseType_t result;

  result = xTaskCreate(
      task1_handler,                  // Task function
      "led_green",                // Task 名稱
      128,                    // Stack depth：128 words
      (void *)"LED Toggle From led_green",                   // 傳給 Task 的參數
      tskIDLE_PRIORITY + 2,   // Priority
      NULL                    // 不需要 Task Handle
  );

  configASSERT(result == pdPASS);

  result = xTaskCreate(
      task2_handler,                  // Task function
      "led_blue",                // Task 名稱
      128,                    // Stack depth：128 words
      (void *)"LED Toggle From led_blue",                   // 傳給 Task 的參數
      tskIDLE_PRIORITY + 2,   // Priority
      NULL                    // 不需要 Task Handle
  );

  configASSERT(result == pdPASS);

  result = xTaskCreate(
      task3_handler,                  // Task function
      "led_red",                // Task 名稱
      128,                    // Stack depth：128 words
      (void *)"LED Toggle From led_red",                   // 傳給 Task 的參數
      tskIDLE_PRIORITY + 2,   // Priority
      NULL                    // 不需要 Task Handle
  );

  configASSERT(result == pdPASS);

   vTaskStartScheduler();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /* USER CODE BEGIN MX_GPIO_Init_2 */
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOF_CLK_ENABLE();                       // ① 開 GPIOF 的 clock

  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8,
                    GPIO_PIN_SET);                    // ② 先輸出 1：共陽 LED，1 = 滅

  GPIO_InitStruct.Pin   = GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8;
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;        // ③ 推挽輸出
  GPIO_InitStruct.Pull  = GPIO_NOPULL;                // 輸出腳不需要上拉或下拉
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;        // LED 用低速就夠了
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);             // ④ 套用設定
  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
static void task1_handler(void *argument)
{
    for (;;)
    {
        /* 1. 翻轉 green 的腳位 */
        HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_7);
        /* 2. printf 一行（可以直接印 argument 傳進來的字串） */
        printf("%s tick=%lu\r\n", (const char *)argument, (unsigned long)xTaskGetTickCount());
        /* 3. HAL_Delay 等 green 的時間 */
        //HAL_Delay(1000);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
static void task2_handler(void *argument)
{

    for (;;)
    {
        /* 1. 翻轉 blue 的腳位 */
        HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_8);
        /* 2. printf 一行（可以直接印 argument 傳進來的字串） */
        printf("%s tick=%lu\r\n", (const char *)argument, (unsigned long)xTaskGetTickCount());
        /* 3. HAL_Delay 等 orangre 的時間 */
        // HAL_Delay(800);
        vTaskDelay(pdMS_TO_TICKS(800));
    }
}
static void task3_handler(void *argument)
{
    TickType_t beforeDelay = 0;          // 放在 for (;;) 前面
    for (;;)
    {
        /* 1. 翻轉 red 的腳位 */
        HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_6);
        /* 2. printf 一行（可以直接印 argument 傳進來的字串） */
        printf("%s tick=%lu before_delay=%lu\r\n", (const char *)argument,
           (unsigned long)xTaskGetTickCount(), (unsigned long)beforeDelay);
        /* 3. HAL_Delay 等 red 的時間 */
        // HAL_Delay(400);
        beforeDelay = xTaskGetTickCount();
        vTaskDelay(pdMS_TO_TICKS(400));
    }
}
static void MX_USART1_UART_Init(void)
{
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;  // 8 個資料位元
    huart1.Init.StopBits = UART_STOPBITS_1;      // 1 個停止位元
    huart1.Init.Parity = UART_PARITY_NONE;       // 不使用同位檢查
    huart1.Init.Mode = UART_MODE_TX_RX;          // 啟用傳送與接收
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE; // 不使用 RTS/CTS 流量控制
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&huart1) != HAL_OK)
    {
        Error_Handler();
    }
}

int __io_putchar(int ch)
{
    uint8_t data = (uint8_t)ch;

    if (HAL_UART_Transmit(&huart1, &data, 1, 100) != HAL_OK)
    {
        Error_Handler();
    }

    return ch;
}

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6)
  {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
