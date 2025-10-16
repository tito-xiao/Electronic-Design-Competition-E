################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/Code Composer Studio/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"E:/Code Composer Studio/Project/Huidu" -I"E:/Code Composer Studio/Project/Huidu/Board" -I"E:/Code Composer Studio/Project/Huidu/BSP" -I"E:/Code Composer Studio/Project/Huidu/BSP/inc" -I"E:/Code Composer Studio/Project/Huidu/Debug" -I"E:/Code Composer Studio/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"E:/Code Composer Studio/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-544303311: ../gpio_toggle_output.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"E:/Code Composer Studio/ccs/utils/sysconfig_1.24.0/sysconfig_cli.bat" --script "E:/Code Composer Studio/Project/Huidu/gpio_toggle_output.syscfg" -o "." -s "E:/Code Composer Studio/mspm0_sdk_2_05_01_00/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-544303311 ../gpio_toggle_output.syscfg
device.opt: build-544303311
device.cmd.genlibs: build-544303311
ti_msp_dl_config.c: build-544303311
ti_msp_dl_config.h: build-544303311
Event.dot: build-544303311

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/Code Composer Studio/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"E:/Code Composer Studio/Project/Huidu" -I"E:/Code Composer Studio/Project/Huidu/Board" -I"E:/Code Composer Studio/Project/Huidu/BSP" -I"E:/Code Composer Studio/Project/Huidu/BSP/inc" -I"E:/Code Composer Studio/Project/Huidu/Debug" -I"E:/Code Composer Studio/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"E:/Code Composer Studio/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: E:/Code\ Composer\ Studio/mspm0_sdk_2_05_01_00/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/Code Composer Studio/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"E:/Code Composer Studio/Project/Huidu" -I"E:/Code Composer Studio/Project/Huidu/Board" -I"E:/Code Composer Studio/Project/Huidu/BSP" -I"E:/Code Composer Studio/Project/Huidu/BSP/inc" -I"E:/Code Composer Studio/Project/Huidu/Debug" -I"E:/Code Composer Studio/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"E:/Code Composer Studio/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"startup_mspm0g350x_ticlang.d_raw" -MT"startup_mspm0g350x_ticlang.o"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


