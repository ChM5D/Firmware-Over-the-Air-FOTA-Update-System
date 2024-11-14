################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f401ccux.s 

C_SRCS += \
../Startup/System_Init.c 

OBJS += \
./Startup/System_Init.o \
./Startup/startup_stm32f401ccux.o 

S_DEPS += \
./Startup/startup_stm32f401ccux.d 

C_DEPS += \
./Startup/System_Init.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o Startup/%.su Startup/%.cyclo: ../Startup/%.c Startup/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"/home/chelly/Desktop/work space/FOTA" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/System_Init.cyclo ./Startup/System_Init.d ./Startup/System_Init.o ./Startup/System_Init.su ./Startup/startup_stm32f401ccux.d ./Startup/startup_stm32f401ccux.o

.PHONY: clean-Startup

