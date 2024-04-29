################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Common/Queue/Queue.c 

OBJS += \
./Core/Common/Queue/Queue.o 

C_DEPS += \
./Core/Common/Queue/Queue.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Common/Queue/%.o Core/Common/Queue/%.su Core/Common/Queue/%.cyclo: ../Core/Common/Queue/%.c Core/Common/Queue/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Common-2f-Queue

clean-Core-2f-Common-2f-Queue:
	-$(RM) ./Core/Common/Queue/Queue.cyclo ./Core/Common/Queue/Queue.d ./Core/Common/Queue/Queue.o ./Core/Common/Queue/Queue.su

.PHONY: clean-Core-2f-Common-2f-Queue

