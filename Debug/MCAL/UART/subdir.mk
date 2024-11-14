################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/UART/UART_Lcfg.c \
../MCAL/UART/UART_program.c 

OBJS += \
./MCAL/UART/UART_Lcfg.o \
./MCAL/UART/UART_program.o 

C_DEPS += \
./MCAL/UART/UART_Lcfg.d \
./MCAL/UART/UART_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/UART/%.o MCAL/UART/%.su MCAL/UART/%.cyclo: ../MCAL/UART/%.c MCAL/UART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"/home/chelly/Desktop/work space/FOTA" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCAL-2f-UART

clean-MCAL-2f-UART:
	-$(RM) ./MCAL/UART/UART_Lcfg.cyclo ./MCAL/UART/UART_Lcfg.d ./MCAL/UART/UART_Lcfg.o ./MCAL/UART/UART_Lcfg.su ./MCAL/UART/UART_program.cyclo ./MCAL/UART/UART_program.d ./MCAL/UART/UART_program.o ./MCAL/UART/UART_program.su

.PHONY: clean-MCAL-2f-UART

