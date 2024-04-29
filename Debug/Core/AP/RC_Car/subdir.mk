################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/AP/RC_Car/Controller.c \
../Core/AP/RC_Car/Listener.c \
../Core/AP/RC_Car/Presenter.c \
../Core/AP/RC_Car/Queue_Car.c \
../Core/AP/RC_Car/defineModel.c 

OBJS += \
./Core/AP/RC_Car/Controller.o \
./Core/AP/RC_Car/Listener.o \
./Core/AP/RC_Car/Presenter.o \
./Core/AP/RC_Car/Queue_Car.o \
./Core/AP/RC_Car/defineModel.o 

C_DEPS += \
./Core/AP/RC_Car/Controller.d \
./Core/AP/RC_Car/Listener.d \
./Core/AP/RC_Car/Presenter.d \
./Core/AP/RC_Car/Queue_Car.d \
./Core/AP/RC_Car/defineModel.d 


# Each subdirectory must supply rules for building sources it contributes
Core/AP/RC_Car/%.o Core/AP/RC_Car/%.su Core/AP/RC_Car/%.cyclo: ../Core/AP/RC_Car/%.c Core/AP/RC_Car/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-AP-2f-RC_Car

clean-Core-2f-AP-2f-RC_Car:
	-$(RM) ./Core/AP/RC_Car/Controller.cyclo ./Core/AP/RC_Car/Controller.d ./Core/AP/RC_Car/Controller.o ./Core/AP/RC_Car/Controller.su ./Core/AP/RC_Car/Listener.cyclo ./Core/AP/RC_Car/Listener.d ./Core/AP/RC_Car/Listener.o ./Core/AP/RC_Car/Listener.su ./Core/AP/RC_Car/Presenter.cyclo ./Core/AP/RC_Car/Presenter.d ./Core/AP/RC_Car/Presenter.o ./Core/AP/RC_Car/Presenter.su ./Core/AP/RC_Car/Queue_Car.cyclo ./Core/AP/RC_Car/Queue_Car.d ./Core/AP/RC_Car/Queue_Car.o ./Core/AP/RC_Car/Queue_Car.su ./Core/AP/RC_Car/defineModel.cyclo ./Core/AP/RC_Car/defineModel.d ./Core/AP/RC_Car/defineModel.o ./Core/AP/RC_Car/defineModel.su

.PHONY: clean-Core-2f-AP-2f-RC_Car

