################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
BSP/src/%.o: ../BSP/src/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/Code Composer Studio/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"E:/Code Composer Studio/Project/TRY" -I"E:/Code Composer Studio/Project/TRY/Board" -I"E:/Code Composer Studio/Project/TRY/BSP" -I"E:/Code Composer Studio/Project/TRY/BSP/inc" -I"E:/Code Composer Studio/Project/TRY/Debug" -I"E:/Code Composer Studio/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"E:/Code Composer Studio/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"BSP/src/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


