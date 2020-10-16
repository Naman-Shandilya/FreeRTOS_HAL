################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f446retx.s 

OBJS += \
./Core/Startup/startup_stm32f446retx.o 

S_DEPS += \
./Core/Startup/startup_stm32f446retx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/startup_stm32f446retx.o: ../Core/Startup/startup_stm32f446retx.s
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -I"D:/PENDRIVE/EMBEDDED_SYSTEM/STM32_PROJECTS/FreeRTOS_Project/FreeRTOS_HAL_Based/FreeRTOS_LED_Keypad_1602LCD_I2c_USART/4x4_Keypad_APIs" -I"D:/PENDRIVE/EMBEDDED_SYSTEM/STM32_PROJECTS/FreeRTOS_Project/FreeRTOS_HAL_Based/FreeRTOS_LED_Keypad_1602LCD_I2c_USART/LCD_APIs" -I"D:/PENDRIVE/EMBEDDED_SYSTEM/STM32_PROJECTS/FreeRTOS_Project/FreeRTOS_HAL_Based/FreeRTOS_LED_Keypad_1602LCD_I2c_USART/Core/Inc" -I"D:/PENDRIVE/EMBEDDED_SYSTEM/STM32_PROJECTS/FreeRTOS_Project/FreeRTOS_HAL_Based/FreeRTOS_LED_Keypad_1602LCD_I2c_USART/Core/Mobile_Specific_Tasks" -I"D:/PENDRIVE/EMBEDDED_SYSTEM/STM32_PROJECTS/FreeRTOS_Project/FreeRTOS_HAL_Based/FreeRTOS_LED_Keypad_1602LCD_I2c_USART/GSM_A6_Driver" -I"D:/PENDRIVE/EMBEDDED_SYSTEM/STM32_PROJECTS/FreeRTOS_Project/FreeRTOS_HAL_Based/FreeRTOS_LED_Keypad_1602LCD_I2c_USART/LCD_APIs" -x assembler-with-cpp -MMD -MP -MF"Core/Startup/startup_stm32f446retx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

