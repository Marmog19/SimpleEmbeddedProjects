################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/SysTickDelay.c \
../Core/Inc/UART_lib.c 

OBJS += \
./Core/Inc/SysTickDelay.o \
./Core/Inc/UART_lib.o 

C_DEPS += \
./Core/Inc/SysTickDelay.d \
./Core/Inc/UART_lib.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/%.o Core/Inc/%.su Core/Inc/%.cyclo: ../Core/Inc/%.c Core/Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F446xx -c -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc

clean-Core-2f-Inc:
	-$(RM) ./Core/Inc/SysTickDelay.cyclo ./Core/Inc/SysTickDelay.d ./Core/Inc/SysTickDelay.o ./Core/Inc/SysTickDelay.su ./Core/Inc/UART_lib.cyclo ./Core/Inc/UART_lib.d ./Core/Inc/UART_lib.o ./Core/Inc/UART_lib.su

.PHONY: clean-Core-2f-Inc

