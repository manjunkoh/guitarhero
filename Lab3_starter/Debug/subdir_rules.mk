################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
ADC_HAL.obj: ../ADC_HAL.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="ADC_HAL.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

ButtonLED_HAL.obj: ../ButtonLED_HAL.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="ButtonLED_HAL.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Howtoplay_16bit.obj: ../Howtoplay_16bit.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="Howtoplay_16bit.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Lab3_starter_main.obj: ../Lab3_starter_main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="Lab3_starter_main.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

MenuOptions_16bit.obj: ../MenuOptions_16bit.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="MenuOptions_16bit.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

ScoreBoard_16bit.obj: ../ScoreBoard_16bit.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="ScoreBoard_16bit.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Timer32_HAL.obj: ../Timer32_HAL.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="Timer32_HAL.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

graphics_HAL.obj: ../graphics_HAL.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="graphics_HAL.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

guitarhero_16bit.obj: ../guitarhero_16bit.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="guitarhero_16bit.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

menuImage_16bit.obj: ../menuImage_16bit.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="menuImage_16bit.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

noteSplash_16bit.obj: ../noteSplash_16bit.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="noteSplash_16bit.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

resultimage_16bit.obj: ../resultimage_16bit.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="resultimage_16bit.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

song.obj: ../song.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="song.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

songlist_16bit.obj: ../songlist_16bit.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="songlist_16bit.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

sound.obj: ../sound.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="sound.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

system_msp432p401r.obj: ../system_msp432p401r.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/ti/grlib/lib/ccs/m4f" --include_path="C:/Users/junni/Desktop/Aerospace/CPE/ECE2534/Labs/lab3-junniboi/Lab3_starter" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_20_00_12/source/third_party/CMSIS/Include" --include_path="C:/ti/ccv8/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="system_msp432p401r.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


