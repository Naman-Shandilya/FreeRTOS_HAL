################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../4x4_Keypad_APIs/4x4_Keypad_APIs.c 

OBJS += \
./4x4_Keypad_APIs/4x4_Keypad_APIs.o 

C_DEPS += \
./4x4_Keypad_APIs/4x4_Keypad_APIs.d 


# Each subdirectory must supply rules for building sources it contributes
4x4_Keypad_APIs/4x4_Keypad_APIs.o: ../4x4_Keypad_APIs/4x4_Keypad_APIs.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"4x4_Keypad_APIs/4x4_Keypad_APIs.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

