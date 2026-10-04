################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/FreeRTOS/FreeRTOS-Kernel/event_groups.c \
../ThirdParty/FreeRTOS/FreeRTOS-Kernel/list.c \
../ThirdParty/FreeRTOS/FreeRTOS-Kernel/queue.c \
../ThirdParty/FreeRTOS/FreeRTOS-Kernel/stream_buffer.c \
../ThirdParty/FreeRTOS/FreeRTOS-Kernel/tasks.c \
../ThirdParty/FreeRTOS/FreeRTOS-Kernel/timers.c 

OBJS += \
./ThirdParty/FreeRTOS/FreeRTOS-Kernel/event_groups.o \
./ThirdParty/FreeRTOS/FreeRTOS-Kernel/list.o \
./ThirdParty/FreeRTOS/FreeRTOS-Kernel/queue.o \
./ThirdParty/FreeRTOS/FreeRTOS-Kernel/stream_buffer.o \
./ThirdParty/FreeRTOS/FreeRTOS-Kernel/tasks.o \
./ThirdParty/FreeRTOS/FreeRTOS-Kernel/timers.o 

C_DEPS += \
./ThirdParty/FreeRTOS/FreeRTOS-Kernel/event_groups.d \
./ThirdParty/FreeRTOS/FreeRTOS-Kernel/list.d \
./ThirdParty/FreeRTOS/FreeRTOS-Kernel/queue.d \
./ThirdParty/FreeRTOS/FreeRTOS-Kernel/stream_buffer.d \
./ThirdParty/FreeRTOS/FreeRTOS-Kernel/tasks.d \
./ThirdParty/FreeRTOS/FreeRTOS-Kernel/timers.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/FreeRTOS/FreeRTOS-Kernel/%.o ThirdParty/FreeRTOS/FreeRTOS-Kernel/%.su ThirdParty/FreeRTOS/FreeRTOS-Kernel/%.cyclo: ../ThirdParty/FreeRTOS/FreeRTOS-Kernel/%.c ThirdParty/FreeRTOS/FreeRTOS-Kernel/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/Workspace/Learning/STM32/STM32F4XX_Dev/RTOS_workspace/FreeRTOS_Projects/ThirdParty/FreeRTOS/FreeRTOS-Kernel/include" -I"D:/Workspace/Learning/STM32/STM32F4XX_Dev/RTOS_workspace/FreeRTOS_Projects/ThirdParty/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-FreeRTOS-2f-FreeRTOS-2d-Kernel

clean-ThirdParty-2f-FreeRTOS-2f-FreeRTOS-2d-Kernel:
	-$(RM) ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/event_groups.cyclo ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/event_groups.d ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/event_groups.o ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/event_groups.su ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/list.cyclo ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/list.d ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/list.o ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/list.su ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/queue.cyclo ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/queue.d ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/queue.o ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/queue.su ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/stream_buffer.cyclo ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/stream_buffer.d ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/stream_buffer.o ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/stream_buffer.su ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/tasks.cyclo ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/tasks.d ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/tasks.o ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/tasks.su ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/timers.cyclo ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/timers.d ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/timers.o ./ThirdParty/FreeRTOS/FreeRTOS-Kernel/timers.su

.PHONY: clean-ThirdParty-2f-FreeRTOS-2f-FreeRTOS-2d-Kernel

