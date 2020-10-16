################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include LCD_APIs/subdir.mk
-include GSM_A6_Driver/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Core/Mobile_Specific_Tasks/subdir.mk
-include 4x4_Keypad_APIs/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
FreeRTOS_LED_Keypad_1602LCD_I2c_USART.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
FreeRTOS_LED_Keypad_1602LCD_I2c_USART.list \

OBJCOPY_BIN += \
FreeRTOS_LED_Keypad_1602LCD_I2c_USART.bin \


# All Target
all: FreeRTOS_LED_Keypad_1602LCD_I2c_USART.elf secondary-outputs

# Tool invocations
FreeRTOS_LED_Keypad_1602LCD_I2c_USART.elf: $(OBJS) $(USER_OBJS) D:\PENDRIVE\EMBEDDED_SYSTEM\STM32_PROJECTS\FreeRTOS_Project\FreeRTOS_HAL_Based\FreeRTOS_LED_Keypad_1602LCD_I2c_USART\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "FreeRTOS_LED_Keypad_1602LCD_I2c_USART.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\PENDRIVE\EMBEDDED_SYSTEM\STM32_PROJECTS\FreeRTOS_Project\FreeRTOS_HAL_Based\FreeRTOS_LED_Keypad_1602LCD_I2c_USART\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="FreeRTOS_LED_Keypad_1602LCD_I2c_USART.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

FreeRTOS_LED_Keypad_1602LCD_I2c_USART.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "FreeRTOS_LED_Keypad_1602LCD_I2c_USART.list"
	@echo 'Finished building: $@'
	@echo ' '

FreeRTOS_LED_Keypad_1602LCD_I2c_USART.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "FreeRTOS_LED_Keypad_1602LCD_I2c_USART.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
