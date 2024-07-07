#
# Auto-Generated file. Do not edit!
#

# Add inputs and outputs from these tool invocations to the build variables
ASM_SRCS += \
../system/serial.S \
../system/start.S \
../system/wakeup.S

C_SRCS += \
../system/init.c \
../system/UserGpio.c

STARTO += ./system/start.o

OBJS += \
./system/init.o \
./system/serial.o \
./system/UserGpio.o \
./system/wakeup.o

ASM_DEPS += \
./system/serial.d \
./system/start.d \
./system/wakeup.d

C_DEPS += \
./system/init.d \
./system/UserGpio.d

# Each subdirectory must supply rules for building sources it contributes
system/%.o: ../system/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: LoongArch32 ELF C Compiler'
	D:/LoongIDE/la32-tool/bin/loongarch32-newlib-elf-gcc.exe -mabi=ilp32s -march=loongarch32 -G0 -DLS1C102 -DBSP_USE_RTC -std=gnu99 -ffunction-sections -fdata-sections -msoft-float -fsched-pressure  -O2 -g -Wall -c -fmessage-length=0 -pipe -I"../" -I"../include" -I"../drivers/include" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/%.o: ../system/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: LoongArch32 ELF C Compiler'
	D:/LoongIDE/la32-tool/bin/loongarch32-newlib-elf-gcc.exe -mabi=ilp32s -march=loongarch32 -G0 -DLS1C102 -DBSP_USE_RTC -std=gnu99 -ffunction-sections -fdata-sections -msoft-float -fsched-pressure  -O2 -fno-builtin -g -Wall -c -fmessage-length=0 -pipe -I"../" -I"../include" -I"../include" -I"../drivers/include" -I"../drivers/private/ls1c102" -I"../drivers/public" -I"../system" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

