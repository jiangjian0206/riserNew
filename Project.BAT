SET PATH=C:\Keil_v5\ARM\ARMCC\Bin;C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\Windows\System32;C:\Windows\system32;D:\Program Files\nodejs;D:\Program Files\nodejs\node_global
SET CPU_TYPE=STM32F103ZE
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=Project
SET CPU_CLOCK=0x00B71B00
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_it.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\w5500.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\led.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\main.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\usart.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\newriser.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\adc.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\misc.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_adc.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_bkp.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_can.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_cec.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_crc.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_dac.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_dbgmcu.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_dma.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_exti.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_flash.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_fsmc.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_gpio.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_i2c.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_iwdg.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_pwr.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_rcc.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_rtc.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_sdio.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_spi.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_tim.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_usart.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\stm32f10x_wwdg.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\core_cm3.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\system_stm32f10x.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via ".\user\output\startup_stm32f10x_hd._ia"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\delaypoint.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\taskpoint.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\user\output\key.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via ".\USER\Output\Project.lnp"
"C:\Keil_v5\ARM\ARMCC\Bin\fromelf.exe" ".\USER\Output\Project.axf" --i32combined --output ".\USER\Output\Project.hex"
