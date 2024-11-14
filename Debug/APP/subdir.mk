################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Bootloader.c \
../APP/main.c 

OBJS += \
./APP/Bootloader.o \
./APP/main.o 

C_DEPS += \
./APP/Bootloader.d \
./APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o APP/%.su APP/%.cyclo: ../APP/%.c APP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"/home/chelly/Desktop/work space/FOTA" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-APP

clean-APP:
	-$(RM) ./APP/Bootloader.cyclo ./APP/Bootloader.d ./APP/Bootloader.o ./APP/Bootloader.su ./APP/main.cyclo ./APP/main.d ./APP/main.o ./APP/main.su

.PHONY: clean-APP

