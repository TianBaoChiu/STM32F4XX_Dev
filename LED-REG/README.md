# STM32F4XX Development Practice

本 Repository 用來保存我的 STM32F407 韌體練習與實機驗證紀錄。

目前重點是理解 MCU 底層工作流程，包括：

- RCC peripheral clock
- GPIO register configuration
- Active-low LED control
- CMSIS／STM32 Standard Peripheral Library
- Keil startup 與 build flow
- Register-level programming
- Firmware download 與實機驗證

## Hardware and Toolchain

| 項目 | 使用環境 |
| --- | --- |
| MCU | STM32F407ZG |
| 開發板 | 野火 STM32F407 霸天虎 |
| LED Pins | PF6（Red）、PF7（Green）、PF8（Blue） |
| LED Logic | Active-low |
| IDE | Keil µVision 5.43 |
| Compiler | Arm Compiler 6.24 |
| Language | C |

## Projects

### LED-REG

不使用 HAL 或 STM32 GPIO library，直接操作暫存器完成三色 LED 循環。

實作內容：

- 設定 `RCC_AHB1ENR`，開啟 GPIOF peripheral clock
- 設定 `GPIOF_MODER`，將 PF6、PF7、PF8 設為 output mode
- 操作 `GPIOF_ODR` 控制 RGB LED
- 使用 C structure 建立 GPIO register mapping
- 使用 `volatile` 存取 memory-mapped registers
- 使用 `__nop()` 建立簡單 software delay
- 理解 active-low LED 的 HIGH／LOW 行為

驗證結果：

- Keil build：`0 Errors, 0 Warnings`
- Firmware download：成功
- 實機結果：PF6、PF7、PF8 三色 LED 可循環閃爍

專案入口：

```text
LED-REG/LED-REG.uvprojx
```

### LED_Test_Project

野火 STM32F407 Standard Peripheral Library LED 範例，用來理解 library-based GPIO initialization 與 register-level 寫法的差異。

實作內容：

- 使用 `RCC_AHB1PeriphClockCmd()` 開啟 GPIOF clock
- 使用 `GPIO_InitTypeDef` 設定 GPIO mode、output type、pull-up 與 speed
- 使用 GPIO library function 控制 PF6、PF7、PF8
- 組合 RGB LED 顯示紅、綠、藍、黃、紫、青與白色

驗證結果：

- Keil build：`0 Errors, 0 Warnings`

專案入口：

```text
LED_Test_Project/Project/RVMDK（uv5）/BH-F407.uvprojx
```

## Repository Structure

```text
STM32F4XX_Dev/
├── LED-REG/
│   ├── main.c
│   ├── stm32f4xx.h
│   ├── startup_stm32f40xx.s
│   └── LED-REG.uvprojx
│
└── LED_Test_Project/
    ├── User/
    │   ├── main.c
    │   └── led/
    │       ├── bsp_led.c
    │       └── bsp_led.h
    ├── Libraries/
    │   ├── CMSIS/
    │   └── STM32F4xx_StdPeriph_Driver/
    └── Project/
        └── RVMDK（uv5）/
            └── BH-F407.uvprojx
```

## Build

1. 使用 Keil µVision 開啟對應的 `.uvprojx`。
2. 確認 target device 為 `STM32F407ZGTx`。
3. 執行 `Rebuild all target files`。
4. 確認 build 結果沒有 error 或 warning。
5. 使用下載器將 firmware 寫入開發板。
6. 觀察 PF6、PF7、PF8 LED 行為。

## Notes

- 板載 RGB LED 為 active-low：
```