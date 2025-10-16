################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/Software/Electronic/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"C:/Users/xiao/Desktop/电子设计竞赛/代码/412" -I"C:/Users/xiao/Desktop/电子设计竞赛/代码/412/Board" -I"C:/Users/xiao/Desktop/电子设计竞赛/代码/412/BSP" -I"C:/Users/xiao/Desktop/电子设计竞赛/代码/412/BSP/inc" -I"C:/Users/xiao/Desktop/电子设计竞赛/代码/412/Debug" -I"D:/Software/Electronic/ti/ccs2020/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"D:/Software/Electronic/ti/ccs2020/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-158939279: ../empty.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"D:/Software/Electronic/ti/ccs2020/ccs/utils/sysconfig_1.24.0/sysconfig_cli.bat" --script "C:/Users/xiao/Desktop/电子设计竞赛/代码/412/empty.syscfg" -o "." -s "D:/Software/Electronic/ti/ccs2020/mspm0_sdk_2_05_01_00/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-158939279 ../empty.syscfg
device.opt: build-158939279
device.cmd.genlibs: build-158939279
ti_msp_dl_config.c: build-158939279
ti_msp_dl_config.h: build-158939279
Event.dot: build-158939279

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/Software/Electronic/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"C:/Users/xiao/Desktop/电子设计竞赛/代码/412" -I"C:/Users/xiao/Desktop/电子设计竞赛/代码/412/Board" -I"C:/Users/xiao/Desktop/电子设计竞赛/代码/412/BSP" -I"C:/Users/xiao/Desktop/电子设计竞赛/代码/412/BSP/inc" -I"C:/Users/xiao/Desktop/电子设计竞赛/代码/412/Debug" -I"D:/Software/Electronic/ti/ccs2020/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"D:/Software/Electronic/ti/ccs2020/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: D:/Software/Electronic/ti/ccs2020/mspm0_sdk_2_05_01_00/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/Software/Electronic/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"C:/Users/xiao/Desktop/电子设计竞赛/代码/412" -I"C:/Users/xiao/Desktop/电子设计竞赛/代码/412/Board" -I"C:/Users/xiao/Desktop/电子设计竞赛/代码/412/BSP" -I"C:/Users/xiao/Desktop/电子设计竞赛/代码/412/BSP/inc" -I"C:/Users/xiao/Desktop/电子设计竞赛/代码/412/Debug" -I"D:/Software/Electronic/ti/ccs2020/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"D:/Software/Electronic/ti/ccs2020/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


