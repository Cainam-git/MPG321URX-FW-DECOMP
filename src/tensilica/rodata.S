# Read-only data: 0x4000acf8-0x4000c767 (firmware file offset 0x3acf8-0x3c767)
# The reset code copies this region to RAM 0x3ffe0000-0x3ffe1a6f (section_table); the code uses the
# RAM addresses. Each label ro_XXXXXXXX is the RAM address of the byte that follows it.
# Text is written as .ascii/.asciz, tables of code addresses as .word with labels, other
# data as .word in hex.

rodata_start:

# used by: fn_40000fb4
ro_3ffe0000 = . - rodata_start + RODATA_RAM
	.asciz	"Configured seg size is over than tensilica seg buf size!!\n" # 4000acf8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40000fb4
ro_3ffe003c = . - rodata_start + RODATA_RAM
	.asciz	"Leon2M conf LED_col = %d, LED_row = %d\n" # 4000ad34

# used by: fn_40000fb4
ro_3ffe0064 = . - rodata_start + RODATA_RAM
	.asciz	"Tensilica LED_CH_NUM = %d\n" # 4000ad5c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40000fb4
ro_3ffe0080 = . - rodata_start + RODATA_RAM
	.asciz	"LDC_LoadPanel Error!!\n" # 4000ad78
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40000fb4
ro_3ffe0098 = . - rodata_start + RODATA_RAM
	.asciz	"PanelInfo\r\n"         # 4000ad90

# used by: fn_40000fb4
ro_3ffe00a4 = . - rodata_start + RODATA_RAM
	.asciz	"Resolution: %d x %d\r\n" # 4000ad9c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40000fb4
ro_3ffe00bc = . - rodata_start + RODATA_RAM
	.asciz	"DriverDuty: Max %04x Min %04x\r\n" # 4000adb4

# used by: fn_40000fb4
ro_3ffe00dc = . - rodata_start + RODATA_RAM
	.asciz	"LEDRowCol: %02d x %02d : %02d\r\n" # 4000add4

# used by: fn_40000fb4
ro_3ffe00fc = . - rodata_start + RODATA_RAM
	.asciz	"DriverType: Type %02x Num %02x Seq %02x\r\n" # 4000adf4
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_4000165c
ro_3ffe0128 = . - rodata_start + RODATA_RAM
	.asciz	"Current Stress Staus = %d (Peaking OFF)\n" # 4000ae20
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_4000165c
ro_3ffe0154 = . - rodata_start + RODATA_RAM
	.asciz	"Current Stress Staus = %d (Peaking ON)\n" # 4000ae4c

# used by: fn_400016a4
ro_3ffe017c = . - rodata_start + RODATA_RAM
	.asciz	"MAILBOX_DPLL INIT DONE!!\n" # 4000ae74
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_400016a4
ro_3ffe0198 = . - rodata_start + RODATA_RAM
	.asciz	"MAILBOX_DPLL NOT INIT!!\n" # 4000ae90
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_400016d4
ro_3ffe01b4 = . - rodata_start + RODATA_RAM
	.asciz	"Segment Merge Mode: Maximum \n" # 4000aeac
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_400016d4
ro_3ffe01d4 = . - rodata_start + RODATA_RAM
	.asciz	"Segment Merge Mode: Average \n" # 4000aecc
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_400016d4
ro_3ffe01f4 = . - rodata_start + RODATA_RAM
	.asciz	"Segment Merge Mode: Average exclude black  \n" # 4000aeec
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_400016d4
ro_3ffe0224 = . - rodata_start + RODATA_RAM
	.asciz	"Segment Merge Mode: Blend \n" # 4000af1c

# used by: fn_40001894
ro_3ffe0240 = . - rodata_start + RODATA_RAM
	.asciz	"Selected entry is out of range of table!\n" # 4000af38
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe026c = . - rodata_start + RODATA_RAM
	.asciz	"Input Duty:\n"         # 4000af64
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe027c = . - rodata_start + RODATA_RAM
	.asciz	"\n "                   # 4000af74
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe0280 = . - rodata_start + RODATA_RAM
	.asciz	"\t%04X "               # 4000af78
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe0288 = . - rodata_start + RODATA_RAM
	.word	0x0000000a              # 4000af80

# used by: fn_40003190
ro_3ffe028c = . - rodata_start + RODATA_RAM
	.asciz	"LDC_GainTable_ANV1: \n" # 4000af84
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe02a4 = . - rodata_start + RODATA_RAM
	.asciz	"\t%04d, \t%04d \n"     # 4000af9c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe02b4 = . - rodata_start + RODATA_RAM
	.asciz	"\t%04d, \t%04d \n\n"   # 4000afac

# used by: fn_40003190
ro_3ffe02c4 = . - rodata_start + RODATA_RAM
	.asciz	"LDC_GainTable_ANV2: \n" # 4000afbc
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe02dc = . - rodata_start + RODATA_RAM
	.asciz	"LDC_GainTable_ANV3: \n" # 4000afd4
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe02f4 = . - rodata_start + RODATA_RAM
	.asciz	"LED_Mode = \t%04X\n"   # 4000afec
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe0308 = . - rodata_start + RODATA_RAM
	.asciz	"LDC_Mode = \t%04X\n"   # 4000b000
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe031c = . - rodata_start + RODATA_RAM
	.asciz	"usUserPDIM = \t%04X\n" # 4000b014

# used by: fn_40003190
ro_3ffe0330 = . - rodata_start + RODATA_RAM
	.asciz	"usUserADIM = \t%04X\n" # 4000b028

# used by: fn_40003190
ro_3ffe0344 = . - rodata_start + RODATA_RAM
	.asciz	"ADIM_Max = \t%04X\n"   # 4000b03c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe0358 = . - rodata_start + RODATA_RAM
	.asciz	"ADIM_Min = \t%04X\n"   # 4000b050
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe036c = . - rodata_start + RODATA_RAM
	.asciz	"ADIM_BrighPercent = \t%04X\n" # 4000b064
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe0388 = . - rodata_start + RODATA_RAM
	.asciz	"PercentADIM = \t%04X\n" # 4000b080
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe03a0 = . - rodata_start + RODATA_RAM
	.asciz	"LimitUpperBound = \t%04X\n" # 4000b098
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe03bc = . - rodata_start + RODATA_RAM
	.asciz	"ZonePeakingPercent = \t%04X\n" # 4000b0b4

# used by: fn_40003190
ro_3ffe03d8 = . - rodata_start + RODATA_RAM
	.asciz	"UserGlobalGain = \t%04X\n" # 4000b0d0

# used by: fn_40003190
ro_3ffe03f0 = . - rodata_start + RODATA_RAM
	.asciz	"ApplyGlobalGain = \t%04X\n" # 4000b0e8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe040c = . - rodata_start + RODATA_RAM
	.asciz	"GainFilterMode = \t%04X\n" # 4000b104

# used by: fn_40003190
ro_3ffe0424 = . - rodata_start + RODATA_RAM
	.asciz	"Input Duty:"           # 4000b11c

# used by: fn_40003190
ro_3ffe0430 = . - rodata_start + RODATA_RAM
	.asciz	"\n  %02d. "            # 4000b128
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe043c = . - rodata_start + RODATA_RAM
	.asciz	"Merged Segment:"       # 4000b134

# used by: fn_40003190
ro_3ffe044c = . - rodata_start + RODATA_RAM
	.asciz	"LED ADIM:"             # 4000b144
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe0458 = . - rodata_start + RODATA_RAM
	.asciz	"LED PDIM:"             # 4000b150
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe0464 = . - rodata_start + RODATA_RAM
	.asciz	"Pure Pattern: %d\n"    # 4000b15c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003190
ro_3ffe0478 = . - rodata_start + RODATA_RAM
	.asciz	"ApplyGlobalGain: 0x%04X\n" # 4000b170
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_400035d0
ro_3ffe0494 = . - rodata_start + RODATA_RAM
	.space	32, 0                   # 4000b18c

# used by: fn_40003814
ro_3ffe04b4 = . - rodata_start + RODATA_RAM
	.asciz	"POWER_UP\r\n"          # 4000b1ac
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003814
ro_3ffe04c0 = . - rodata_start + RODATA_RAM
	.asciz	"POWER_DOWN\r\n"        # 4000b1b8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003814
ro_3ffe04d0 = . - rodata_start + RODATA_RAM
	.asciz	"MailBox Cmd: %02X %02X %04X \n" # 4000b1c8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: word at 0x4000d418
ro_3ffe04f0 = . - rodata_start + RODATA_RAM
	.asciz	"mr"                    # 4000b1e8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: word at 0x4000d420
ro_3ffe04f4 = . - rodata_start + RODATA_RAM
	.asciz	"mw"                    # 4000b1ec
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: word at 0x4000d428
ro_3ffe04f8 = . - rodata_start + RODATA_RAM
	.asciz	"md"                    # 4000b1f0
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: word at 0x4000d430
ro_3ffe04fc = . - rodata_start + RODATA_RAM
	.asciz	"cfg"                   # 4000b1f4

# used by: fn_40003904
ro_3ffe0500 = . - rodata_start + RODATA_RAM
	.asciz	"%08X:   "              # 4000b1f8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003904
ro_3ffe050c = . - rodata_start + RODATA_RAM
	.asciz	" %08X"                 # 4000b204
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003904
ro_3ffe0514 = . - rodata_start + RODATA_RAM
	.asciz	" %04X"                 # 4000b20c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003904
ro_3ffe051c = . - rodata_start + RODATA_RAM
	.asciz	" %02X"                 # 4000b214
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003904
ro_3ffe0524 = . - rodata_start + RODATA_RAM
	.word	0x0000000a              # 4000b21c

# used by: fn_40003b98
ro_3ffe0528 = . - rodata_start + RODATA_RAM
	.asciz	"val = 0x%08X\n"        # 4000b220
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003c94
ro_3ffe0538 = . - rodata_start + RODATA_RAM
	.asciz	"\n-----------------------------------------\n" # 4000b230

# used by: fn_40003c94
ro_3ffe0564 = . - rodata_start + RODATA_RAM
	.asciz	"Core %s\n"             # 4000b25c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003c94
ro_3ffe0570 = . - rodata_start + RODATA_RAM
	.asciz	"NVT_Formal_RG20189"    # 4000b268
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003c94
ro_3ffe0584 = . - rodata_start + RODATA_RAM
	.asciz	"NT68500 FW Version: %d.%d.%d (customer id = %d)\n" # 4000b27c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003c94
ro_3ffe05b8 = . - rodata_start + RODATA_RAM
	.asciz	"Built time: %s %s\n"   # 4000b2b0
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003c94
ro_3ffe05cc = . - rodata_start + RODATA_RAM
	.asciz	"Nov 10 2025"           # 4000b2c4

# used by: fn_40003c94
ro_3ffe05d8 = . - rodata_start + RODATA_RAM
	.asciz	"09:47:58"              # 4000b2d0
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003c94
ro_3ffe05e4 = . - rodata_start + RODATA_RAM
	.asciz	"--------------------------------------------\n" # 4000b2dc
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40003cd0
ro_3ffe0614 = . - rodata_start + RODATA_RAM
	.asciz	"Please enter the command: " # 4000b30c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40004dfc
ro_3ffe0630 = . - rodata_start + RODATA_RAM
	.asciz	"mem"                   # 4000b328
	.space	28, 0                   # 4000b32c
	.word	fn_4000498c             # 4000b348
	.asciz	"wmem"                  # 4000b34c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary
	.space	24, 0                   # 4000b354
	.word	fn_40004bcc             # 4000b36c
	.asciz	"mdw"                   # 4000b370
	.space	28, 0                   # 4000b374
	.word	fn_40004b08             # 4000b390
	.asciz	"mww"                   # 4000b394
	.space	28, 0                   # 4000b398
	.word	fn_40004bcc             # 4000b3b4
	.asciz	"gpio"                  # 4000b3b8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary
	.space	24, 0                   # 4000b3c0
	.word	fn_40005cac             # 4000b3d8
	.asciz	"help"                  # 4000b3dc
	.balign	4, 0                    # zero bytes up to the 4-byte boundary
	.space	24, 0                   # 4000b3e4
	.word	fn_40005c3c             # 4000b3fc
	.asciz	"rsa"                   # 4000b400
	.space	28, 0                   # 4000b404
	.word	fn_40005c78             # 4000b420
	.asciz	"msg1"                  # 4000b424
	.balign	4, 0                    # zero bytes up to the 4-byte boundary
	.space	24, 0                   # 4000b42c
	.word	fn_40005c8c             # 4000b444
	.asciz	"msg0"                  # 4000b448
	.balign	4, 0                    # zero bytes up to the 4-byte boundary
	.space	24, 0                   # 4000b450
	.word	fn_40005c9c             # 4000b468
	.space	44, 0                   # 4000b46c

# used by: fn_400058dc
ro_3ffe07a0 = . - rodata_start + RODATA_RAM
	.asciz	"*CB00000"              # 4000b498
	.balign	4, 0                    # zero bytes up to the 4-byte boundary
	.space	4, 0                    # 4000b4a4

# used by: fn_400058dc
ro_3ffe07b0 = . - rodata_start + RODATA_RAM
	.asciz	"{#UTIL#}"              # 4000b4a8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary
	.space	4, 0                    # 4000b4b4

# used by: word at 0x4000d438
ro_3ffe07c0 = . - rodata_start + RODATA_RAM
	.asciz	"mem [addr] [count] : display memory data ( 8 bits format)" # 4000b4b8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: word at 0x4000d43c
ro_3ffe07fc = . - rodata_start + RODATA_RAM
	.asciz	"wmem [addr] [data]: write data to memory" # 4000b4f4
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: word at 0x4000d440
ro_3ffe0828 = . - rodata_start + RODATA_RAM
	.asciz	"mdw [addr] [count] : display memory data (32 bits format)" # 4000b520
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: word at 0x4000d444
ro_3ffe0864 = . - rodata_start + RODATA_RAM
	.asciz	"proc [p1] [p2] [p3]: function test" # 4000b55c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: word at 0x4000d448
ro_3ffe0888 = . - rodata_start + RODATA_RAM
	.asciz	"gpio [port]: GPIO test" # 4000b580
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_4000498c, fn_40004b08
ro_3ffe08a0 = . - rodata_start + RODATA_RAM
	.asciz	" : "                   # 4000b598

# used by: fn_4000498c
ro_3ffe08a4 = . - rodata_start + RODATA_RAM
	.asciz	"            "          # 4000b59c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_4000498c, fn_40004b08
ro_3ffe08b4 = . - rodata_start + RODATA_RAM
	.word	0x00000020              # 4000b5ac

# used by: fn_4000498c
ro_3ffe08b8 = . - rodata_start + RODATA_RAM
	.asciz	"| "                    # 4000b5b0
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_4000498c
ro_3ffe08bc = . - rodata_start + RODATA_RAM
	.byte	0x2e, 0x00              # 4000b5b4

# used by: fn_4000498c, fn_40004b08, fn_40004bcc, fn_400058dc
ro_3ffe08be = . - rodata_start + RODATA_RAM
	.byte	0x0a, 0x00              # 4000b5b6

# used by: fn_40004b08
ro_3ffe08c0 = . - rodata_start + RODATA_RAM
	.asciz	"         "             # 4000b5b8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40004bcc
ro_3ffe08cc = . - rodata_start + RODATA_RAM
	.asciz	"\n ["                  # 4000b5c4

# used by: fn_40004bcc
ro_3ffe08d0 = . - rodata_start + RODATA_RAM
	.asciz	"] : "                  # 4000b5c8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40004bcc
ro_3ffe08d8 = . - rodata_start + RODATA_RAM
	.asciz	"Address Fail\n"        # 4000b5d0
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40004dfc, fn_40004fc0
ro_3ffe08e8 = . - rodata_start + RODATA_RAM
	.asciz	"\n\r"                  # 4000b5e0
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40004fc0
ro_3ffe08ec = . - rodata_start + RODATA_RAM
	.asciz	" OK.\n\r"              # 4000b5e4
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40004fc0
ro_3ffe08f4 = . - rodata_start + RODATA_RAM
	.asciz	"\n\rCommand Not Found!\n\r" # 4000b5ec
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40004fc0
ro_3ffe090c = . - rodata_start + RODATA_RAM
	.asciz	"TDBG >>"               # 4000b604

# used by: fn_400058dc
ro_3ffe0914 = . - rodata_start + RODATA_RAM
	.word	0x00082008              # 4000b60c

# used by: fn_400058dc
ro_3ffe0918 = . - rodata_start + RODATA_RAM
	.asciz	"\n\rDBG >>"            # 4000b610
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40005ba8
ro_3ffe0924 = . - rodata_start + RODATA_RAM
	.asciz	"\n---------------------------------------------" # 4000b61c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40005ba8
ro_3ffe0954 = . - rodata_start + RODATA_RAM
	.asciz	"\n    Welcome to User's Command Line Debug" # 4000b64c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40005ba8
ro_3ffe0980 = . - rodata_start + RODATA_RAM
	.asciz	"\n---------------------------------------------\n" # 4000b678

# used by: fn_40005c24
ro_3ffe09b0 = . - rodata_start + RODATA_RAM
	.asciz	"NT68500 Tensilica S/W : " # 4000b6a8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40005c24
ro_3ffe09cc = . - rodata_start + RODATA_RAM
	.asciz	"#\n"                   # 4000b6c4
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40005c3c
ro_3ffe09d0 = . - rodata_start + RODATA_RAM
	.asciz	"\n%s"                  # 4000b6c8

# used by: fn_40005cac
ro_3ffe09d4 = . - rodata_start + RODATA_RAM
	.asciz	"GPIOtest done!!"       # 4000b6cc

# used by: fn_40005de8
ro_3ffe09e4 = . - rodata_start + RODATA_RAM
	.asciz	"*** UART TX Test Start ***\n" # 4000b6dc

# used by: fn_40005de8
ro_3ffe0a00 = . - rodata_start + RODATA_RAM
	.asciz	"*** UART TX Test End ***\n\n" # 4000b6f8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40005de8
ro_3ffe0a1c = . - rodata_start + RODATA_RAM
	.asciz	"*** UART RX Test Start ***\n" # 4000b714

# used by: fn_40005de8
ro_3ffe0a38 = . - rodata_start + RODATA_RAM
	.asciz	"Please input a character ('q' to exit):\n" # 4000b730
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40005de8
ro_3ffe0a64 = . - rodata_start + RODATA_RAM
	.asciz	"User input: \\n\n"     # 4000b75c

# used by: fn_40005de8
ro_3ffe0a74 = . - rodata_start + RODATA_RAM
	.asciz	"User input: %c\n"      # 4000b76c

# used by: fn_40005de8
ro_3ffe0a84 = . - rodata_start + RODATA_RAM
	.asciz	"*** UART RX Test End ***\n\n" # 4000b77c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40005de8
ro_3ffe0aa0 = . - rodata_start + RODATA_RAM
	.asciz	"UART test done!\n"     # 4000b798
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40006374
ro_3ffe0ab4 = . - rodata_start + RODATA_RAM
	.asciz	"DRV_LDC_SetPanelResolution,%u,%u\r\n" # 4000b7ac
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40006434
ro_3ffe0ad8 = . - rodata_start + RODATA_RAM
	.asciz	"DRV_LDC_UpdateSegmentBoundary\r\n" # 4000b7d0

# used by: fn_4000660c
ro_3ffe0af8 = . - rodata_start + RODATA_RAM
	.asciz	"DRV_LDC_SetLDCSegment\r\n" # 4000b7f0

# used by: fn_400066d4
ro_3ffe0b10 = . - rodata_start + RODATA_RAM
	.asciz	"DRV_LDC_SetDSRegisters\r\n" # 4000b808
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40006904
ro_3ffe0b2c = . - rodata_start + RODATA_RAM
	.asciz	"DRV_LDC_Intensity_Gain_Update\n" # 4000b824
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40006afc
ro_3ffe0b4c = . - rodata_start + RODATA_RAM
	.asciz	"LDC test function\r\n" # 4000b844

# used by: fn_40006afc
ro_3ffe0b60 = . - rodata_start + RODATA_RAM
	.asciz	"i = %d, %lX, %lX, %lX, %lX, %lX, %lX, %lX, %lX, %lX\r\n" # 4000b858
	.balign	4, 0                    # zero bytes up to the 4-byte boundary
	.space	8, 0                    # 4000b890

# used by: fn_4000713c
ro_3ffe0ba0 = . - rodata_start + RODATA_RAM
	.space	48, 0                   # 4000b898

# used by: fn_40007348
ro_3ffe0bd0 = . - rodata_start + RODATA_RAM
	.space	32, 0                   # 4000b8c8

# used by: fn_40007530
ro_3ffe0bf0 = . - rodata_start + RODATA_RAM
	.word	0x00000000, 0x00000000  # 4000b8e8

# used by: fn_4000770c
ro_3ffe0bf8 = . - rodata_start + RODATA_RAM
	.asciz	"AS3824Buf.HdrMode = 0x%02X \n" # 4000b8f0
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40007760
ro_3ffe0c18 = . - rodata_start + RODATA_RAM
	.word	0x00000000, 0x00000000  # 4000b910

# used by: fn_400077a4
ro_3ffe0c20 = . - rodata_start + RODATA_RAM
	.asciz	"LED_AS3824_SetPwmPeriod = 0x%X \n" # 4000b918
	.balign	4, 0                    # zero bytes up to the 4-byte boundary
	.space	4, 0                    # 4000b93c

# used by: fn_400077a4
ro_3ffe0c48 = . - rodata_start + RODATA_RAM
	.word	0x00000000, 0x00000000  # 4000b940

# used by: fn_400077fc
ro_3ffe0c50 = . - rodata_start + RODATA_RAM
	.asciz	"LED AS3824 Current On: 0x%04X\n" # 4000b948
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40007820
ro_3ffe0c70 = . - rodata_start + RODATA_RAM
	.asciz	"LED AS3824 HDR Mode: 0x%04X\n" # 4000b968
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_4000784c
ro_3ffe0c90 = . - rodata_start + RODATA_RAM
	.asciz	"LED AS3824 PWM CTRL: 0x%04X\n" # 4000b988
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40007878
ro_3ffe0cb0 = . - rodata_start + RODATA_RAM
	.asciz	"LED AS3824 CURR CTRL: 0x%04X\n" # 4000b9a8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_400078a0
ro_3ffe0cd0 = . - rodata_start + RODATA_RAM
	.asciz	"LED AS3824 CURR CTRL(DACref): 0x%04X\n" # 4000b9c8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_400078e8
ro_3ffe0cf8 = . - rodata_start + RODATA_RAM
	.asciz	"LED AS3824 Options: 0x%04X\n" # 4000b9f0

# used by: fn_40007914
ro_3ffe0d14 = . - rodata_start + RODATA_RAM
	.asciz	"LED AS3824 Direct PWM: 0x%04X\n" # 4000ba0c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40007998
ro_3ffe0d34 = . - rodata_start + RODATA_RAM
	.asciz	"LED_AS3824_Unlock\n"   # 4000ba2c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_400079b8
ro_3ffe0d48 = . - rodata_start + RODATA_RAM
	.asciz	"LED_AS3824_Init Done!! \n" # 4000ba40
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40007c50
ro_3ffe0d64 = . - rodata_start + RODATA_RAM
	.asciz	"AS3824Buf.DevAddr = 0x%04X\n" # 4000ba5c

# used by: fn_40007c50
ro_3ffe0d80 = . - rodata_start + RODATA_RAM
	.asciz	"AS3824Buf.LockUnlock = 0x%04X\n" # 4000ba78
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40007c50
ro_3ffe0da0 = . - rodata_start + RODATA_RAM
	.asciz	"AS3824Buf.CurrOnOff = 0x%04X\n" # 4000ba98
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40007c50
ro_3ffe0dc0 = . - rodata_start + RODATA_RAM
	.asciz	"AS3824Buf.CurrOnNum = 0x%04X\n" # 4000bab8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40007c50
ro_3ffe0de0 = . - rodata_start + RODATA_RAM
	.asciz	"AS3824Buf.CurrCtrl = 0x%04X\n" # 4000bad8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40007c50
ro_3ffe0e00 = . - rodata_start + RODATA_RAM
	.asciz	"AS3824Buf.PWM_Ctrl = 0x%04X\n" # 4000baf8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40007c50
ro_3ffe0e20 = . - rodata_start + RODATA_RAM
	.asciz	"AS3824Buf.PWM_Period = 0x%04X\n" # 4000bb18
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40007c50
ro_3ffe0e40 = . - rodata_start + RODATA_RAM
	.asciz	"AS3824Buf.DAC = 0x%04X\n" # 4000bb38

# used by: fn_40007c50
ro_3ffe0e58 = . - rodata_start + RODATA_RAM
	.asciz	"AS3824Buf.Options = 0x%04X\n" # 4000bb50

# used by: fn_40007c50
ro_3ffe0e74 = . - rodata_start + RODATA_RAM
	.asciz	"AS3824Buf.HdrMode = 0x%04X\n" # 4000bb6c

# used by: fn_40007c50
ro_3ffe0e90 = . - rodata_start + RODATA_RAM
	.asciz	"AS3824Buf.BDAC[%02d] = 0x%04X\n" # 4000bb88
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40007c50
ro_3ffe0eb0 = . - rodata_start + RODATA_RAM
	.word	0x0000000a              # 4000bba8

# used by: fn_40007c50
ro_3ffe0eb4 = . - rodata_start + RODATA_RAM
	.asciz	"AS3824Buf.PWM_HT[%02d] = 0x%04X\n" # 4000bbac
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40007c50
ro_3ffe0ed8 = . - rodata_start + RODATA_RAM
	.asciz	"LED_Mode = 0x%04X\n"   # 4000bbd0
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40007c50
ro_3ffe0eec = . - rodata_start + RODATA_RAM
	.asciz	"LDC_Mode = 0x%04X\n"   # 4000bbe4
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40007e68
ro_3ffe0f00 = . - rodata_start + RODATA_RAM
	.space	1040, 0                 # 4000bbf8

# used by: fn_40008300
ro_3ffe1310 = . - rodata_start + RODATA_RAM
	.asciz	"[ERR] gpio_switch_mux: gpio index out of range (%bu)\n" # 4000c008
	.balign	4, 0                    # zero bytes up to the 4-byte boundary
	.space	8, 0                    # 4000c040

# used by: fn_40008300
ro_3ffe1350 = . - rodata_start + RODATA_RAM
	.word	.L40008381              # 4000c048
	.word	.L4000839a              # 4000c04c
	.word	.L400083b3              # 4000c050
	.word	.L400083cc              # 4000c054
	.word	.L400083e5              # 4000c058
	.word	.L400083fe              # 4000c05c
	.word	.L40008417              # 4000c060
	.word	.L40008430              # 4000c064
	.word	.L40008449              # 4000c068
	.word	.L4000845f              # 4000c06c
	.word	.L40008478              # 4000c070
	.word	.L40008491              # 4000c074
	.word	.L400084aa              # 4000c078
	.word	.L400084c3              # 4000c07c
	.word	.L400084dc              # 4000c080
	.word	.L400084f5              # 4000c084
	.word	.L4000850e              # 4000c088
	.word	.L40008524              # 4000c08c
	.word	.L4000853d              # 4000c090
	.word	.L40008556              # 4000c094
	.word	.L4000856f              # 4000c098
	.word	.L40008588              # 4000c09c
	.word	.L400085a1              # 4000c0a0
	.word	.L400085ba              # 4000c0a4
	.word	.L400085d3              # 4000c0a8
	.word	.L400085ec              # 4000c0ac
	.word	.L40008602              # 4000c0b0
	.word	.L4000861b              # 4000c0b4
	.word	.L40008634              # 4000c0b8
	.word	.L4000864d              # 4000c0bc
	.word	.L40008663              # 4000c0c0
	.word	.L4000867c              # 4000c0c4

# used by: fn_400086a4
ro_3ffe13d0 = . - rodata_start + RODATA_RAM
	.asciz	"[ERR] gpio_set_input: gpio index out of range (%bu)\n" # 4000c0c8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary
	.space	8, 0                    # 4000c100

# used by: fn_400086a4
ro_3ffe1410 = . - rodata_start + RODATA_RAM
	.word	.L400086c9              # 4000c108
	.word	.L400086e2              # 4000c10c
	.word	.L400086fb              # 4000c110
	.word	.L40008714              # 4000c114
	.word	.L4000872d              # 4000c118
	.word	.L40008746              # 4000c11c
	.word	.L4000875f              # 4000c120
	.word	.L40008778              # 4000c124
	.word	.L4000878e              # 4000c128
	.word	.L400087a7              # 4000c12c
	.word	.L400087c0              # 4000c130
	.word	.L400087d9              # 4000c134
	.word	.L400087f2              # 4000c138
	.word	.L40008808              # 4000c13c
	.word	.L40008821              # 4000c140
	.word	.L40008837              # 4000c144
	.word	.L40008850              # 4000c148
	.word	.L40008869              # 4000c14c
	.word	.L4000887f              # 4000c150
	.word	.L40008898              # 4000c154
	.word	.L400088b1              # 4000c158
	.word	.L400088ca              # 4000c15c
	.word	.L400088e0              # 4000c160
	.word	.L400088f9              # 4000c164
	.word	.L40008912              # 4000c168
	.word	.L4000892b              # 4000c16c
	.word	.L40008944              # 4000c170
	.word	.L4000895d              # 4000c174
	.word	.L40008976              # 4000c178
	.word	.L4000898f              # 4000c17c
	.word	.L400089a8              # 4000c180
	.word	.L400089c1              # 4000c184

# used by: fn_400089e8, fn_40008af8
ro_3ffe1490 = . - rodata_start + RODATA_RAM
	.asciz	"[ERR] gpio_set_output: gpio index out of range (%bu)\n" # 4000c188
	.balign	4, 0                    # zero bytes up to the 4-byte boundary
	.space	8, 0                    # 4000c1c0

# used by: fn_400089e8
ro_3ffe14d0 = . - rodata_start + RODATA_RAM
	.word	.L40008a08              # 4000c1c8
	.word	.L40008a0e              # 4000c1cc
	.word	.L40008a14              # 4000c1d0
	.word	.L40008a1a              # 4000c1d4
	.word	.L40008a20              # 4000c1d8
	.word	.L40008a26              # 4000c1dc
	.word	.L40008a2c              # 4000c1e0
	.word	.L40008a32              # 4000c1e4
	.word	.L40008a38              # 4000c1e8
	.word	.L40008a3e              # 4000c1ec
	.word	.L40008a44              # 4000c1f0
	.word	.L40008a4a              # 4000c1f4
	.word	.L40008a50              # 4000c1f8
	.word	.L40008a56              # 4000c1fc
	.word	.L40008a5c              # 4000c200
	.word	.L40008a62              # 4000c204
	.word	.L40008a68              # 4000c208
	.word	.L40008a6e              # 4000c20c
	.word	.L40008a74              # 4000c210
	.word	.L40008a7a              # 4000c214
	.word	.L40008a80              # 4000c218
	.word	.L40008a86              # 4000c21c
	.word	.L40008a8c              # 4000c220
	.word	.L40008a92              # 4000c224
	.word	.L40008a98              # 4000c228
	.word	.L40008a9e              # 4000c22c
	.word	.L40008aa4              # 4000c230
	.word	.L40008aaa              # 4000c234
	.word	.L40008ab0              # 4000c238
	.word	.L40008ab6              # 4000c23c
	.word	.L40008abc              # 4000c240
	.word	.L40008ac2              # 4000c244

# used by: fn_40008af8
ro_3ffe1550 = . - rodata_start + RODATA_RAM
	.word	.L40008b18              # 4000c248
	.word	.L40008b1e              # 4000c24c
	.word	.L40008b24              # 4000c250
	.word	.L40008b2a              # 4000c254
	.word	.L40008b30              # 4000c258
	.word	.L40008b36              # 4000c25c
	.word	.L40008b3c              # 4000c260
	.word	.L40008b42              # 4000c264
	.word	.L40008b48              # 4000c268
	.word	.L40008b4e              # 4000c26c
	.word	.L40008b54              # 4000c270
	.word	.L40008b5a              # 4000c274
	.word	.L40008b60              # 4000c278
	.word	.L40008b66              # 4000c27c
	.word	.L40008b6c              # 4000c280
	.word	.L40008b72              # 4000c284
	.word	.L40008b78              # 4000c288
	.word	.L40008b7e              # 4000c28c
	.word	.L40008b84              # 4000c290
	.word	.L40008b8a              # 4000c294
	.word	.L40008b90              # 4000c298
	.word	.L40008b96              # 4000c29c
	.word	.L40008b9c              # 4000c2a0
	.word	.L40008ba2              # 4000c2a4
	.word	.L40008ba8              # 4000c2a8
	.word	.L40008bae              # 4000c2ac
	.word	.L40008bb4              # 4000c2b0
	.word	.L40008bba              # 4000c2b4
	.word	.L40008bc0              # 4000c2b8
	.word	.L40008bc6              # 4000c2bc
	.word	.L40008bcc              # 4000c2c0
	.word	.L40008bd2              # 4000c2c4

# used by: fn_40009218
ro_3ffe15d0 = . - rodata_start + RODATA_RAM
	.word	0x00310030, 0x00330032, 0x00350034, 0x00370036 # 4000c2c8
	.word	0x00390038, 0x00000000, 0x00000000, 0x00000000 # 4000c2d8

# used by: fn_40009218
ro_3ffe15f0 = . - rodata_start + RODATA_RAM
	.asciz	"0123456789abcdef"      # 4000c2e8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary
	.space	12, 0                   # 4000c2fc

# used by: fn_40009218
ro_3ffe1610 = . - rodata_start + RODATA_RAM
	.asciz	"0123456789ABCDEF"      # 4000c308
	.balign	4, 0                    # zero bytes up to the 4-byte boundary
	.space	12, 0                   # 4000c31c

# used by: fn_40009218
ro_3ffe1630 = . - rodata_start + RODATA_RAM
	.word	.L400096dd              # 4000c328
	.word	.L40009906              # 4000c32c
	.word	.L40009906              # 4000c330
	.word	.L40009906              # 4000c334
	.word	.L40009906              # 4000c338
	.word	.L40009906              # 4000c33c
	.word	.L40009906              # 4000c340
	.word	.L40009906              # 4000c344
	.word	.L40009713              # 4000c348
	.word	.L40009906              # 4000c34c
	.word	.L40009906              # 4000c350
	.word	.L40009906              # 4000c354
	.word	.L40009906              # 4000c358
	.word	.L40009906              # 4000c35c
	.word	.L40009906              # 4000c360
	.word	.L40009906              # 4000c364
	.word	.L40009906              # 4000c368
	.word	.L40009906              # 4000c36c
	.word	.L40009906              # 4000c370
	.word	.L4000975c              # 4000c374
	.word	.L40009369              # 4000c378
	.word	.L40009906              # 4000c37c
	.word	.L40009906              # 4000c380
	.word	.L40009906              # 4000c384
	.word	.L40009906              # 4000c388
	.word	.L40009906              # 4000c38c
	.word	.L40009906              # 4000c390
	.word	.L40009906              # 4000c394
	.word	.L400097b7              # 4000c398
	.word	.L40009906              # 4000c39c
	.word	.L40009906              # 4000c3a0
	.word	.L40009906              # 4000c3a4
	.word	.L400095bc              # 4000c3a8
	.word	.L40009906              # 4000c3ac
	.word	.L40009906              # 4000c3b0
	.word	.L400092ef              # 4000c3b4
	.word	.L40009906              # 4000c3b8
	.word	.L40009425              # 4000c3bc
	.word	.L40009906              # 4000c3c0
	.word	.L40009906              # 4000c3c4
	.word	.L400095ec              # 4000c3c8
	.word	0x00000000, 0x00000000, 0x00000000 # 4000c3cc

# used by: fn_40009a90
ro_3ffe16e0 = . - rodata_start + RODATA_RAM
	.asciz	"Hello world!"          # 4000c3d8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40009a90
ro_3ffe16f0 = . - rodata_start + RODATA_RAM
	.asciz	"%s\n"                  # 4000c3e8

# used by: fn_40009a90
ro_3ffe16f4 = . - rodata_start + RODATA_RAM
	.asciz	"printf test\n"         # 4000c3ec
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40009a90
ro_3ffe1704 = . - rodata_start + RODATA_RAM
	.asciz	"%p is null pointer\n"  # 4000c3fc

# used by: fn_40009a90
ro_3ffe1718 = . - rodata_start + RODATA_RAM
	.asciz	"%d = 5\n"              # 4000c410

# used by: fn_40009a90
ro_3ffe1720 = . - rodata_start + RODATA_RAM
	.asciz	"%d = - max int\n"      # 4000c418

# used by: fn_40009a90
ro_3ffe1730 = . - rodata_start + RODATA_RAM
	.asciz	"%ld = - max long\n"    # 4000c428
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40009a90
ro_3ffe1744 = . - rodata_start + RODATA_RAM
	.asciz	"char %c = 'a'\n"       # 4000c43c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40009a90
ro_3ffe1754 = . - rodata_start + RODATA_RAM
	.asciz	"hex %x = ff\n"         # 4000c44c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40009a90
ro_3ffe1764 = . - rodata_start + RODATA_RAM
	.asciz	"hex %02x = 00\n"       # 4000c45c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40009a90
ro_3ffe1774 = . - rodata_start + RODATA_RAM
	.asciz	"int: signed %d = unsigned %u = hex %x\n" # 4000c46c
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40009a90
ro_3ffe179c = . - rodata_start + RODATA_RAM
	.asciz	"long: signed %ld = unsigned %lu = hex %lx\n" # 4000c494
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40009a90
ro_3ffe17c8 = . - rodata_start + RODATA_RAM
	.asciz	"%d %s(s)%"             # 4000c4c0
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40009a90
ro_3ffe17d4 = . - rodata_start + RODATA_RAM
	.asciz	"message"               # 4000c4cc

# used by: fn_40009a90
ro_3ffe17dc = . - rodata_start + RODATA_RAM
	.word	0x0000000a              # 4000c4d4

# used by: fn_40009a90
ro_3ffe17e0 = . - rodata_start + RODATA_RAM
	.asciz	"%d %s(s) with %%\n"    # 4000c4d8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_40009a90
ro_3ffe17f4 = . - rodata_start + RODATA_RAM
	.asciz	"TEST result should be \n" # 4000c4ec

# used by: fn_40009a90
ro_3ffe180c = . - rodata_start + RODATA_RAM
	.ascii	"        * Hello world!\n" # 4000c504
	.ascii	"        * printf test\n" # 4000c51b
	.ascii	"        * 0x00000000 is null pointer\n" # 4000c531
	.ascii	"        * 5 = 5\n"     # 4000c556
	.ascii	"        * -2147483648 = - max int\n" # 4000c566
	.ascii	"    \t* -2147483648 = - max long\n" # 4000c588
	.ascii	"        * char a = 'a'\n" # 4000c5a8
	.ascii	"        * hex ff = ff\n" # 4000c5bf
	.ascii	"        * hex 00 = 00\n" # 4000c5d5
	.ascii	"        * int: signed -3 = unsigned 4294967293 =" # 4000c5eb
	.ascii	" hex fffffffd\n"       # 4000c61b
	.ascii	"    \t* long: signed -5 = unsigned 4294967291 = h" # 4000c629
	.ascii	"ex fffffffb\n"         # 4000c659
	.ascii	"        * 0 message(s)\n" # 4000c665
	.asciz	"        * 0 message(s) with %%\n" # 4000c67c
	.space	12, 0                   # 4000c69c

# used by: fn_4000a010, fn_4000a08c
ro_3ffe19b0 = . - rodata_start + RODATA_RAM
	.ascii	"0123456789ABCDEF"      # 4000c6a8

# used by: fn_4000a3cc
ro_3ffe19c0 = . - rodata_start + RODATA_RAM
	.asciz	"\nGot power down command..\n" # 4000c6b8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_4000a3cc
ro_3ffe19dc = . - rodata_start + RODATA_RAM
	.asciz	"Enter to Idle loop"    # 4000c6d4
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: fn_4000a3cc
ro_3ffe19f0 = . - rodata_start + RODATA_RAM
	.asciz	"SW_IRQ!!\n"            # 4000c6e8
	.balign	4, 0                    # zero bytes up to the 4-byte boundary

# used by: vec_40000340, word at 0x40000338
ro_3ffe19fc = . - rodata_start + RODATA_RAM
	.word	fn_4000abcc             # 4000c6f4
	.word	fn_4000a458             # 4000c6f8
	.word	fn_4000abcc             # 4000c6fc
	.word	fn_4000abcc             # 4000c700
	.word	fn_4000a570             # 4000c704
	.word	fn_40000010             # 4000c708
	.word	0x00000000, 0x00000000, 0x00000000 # 4000c70c

# used by: fn_4000a890
ro_3ffe1a20 = . - rodata_start + RODATA_RAM
	.word	0x00090400, 0x00080303, 0x00000000, 0xff000000 # 4000c718

# used by: fn_4000a4c8
ro_3ffe1a30 = . - rodata_start + RODATA_RAM
	.word	0x01010101, 0x01010101, 0x03030302, 0x01070504 # 4000c728
	.word	0x01010101, 0x00000301, 0x00000000, 0x00000000 # 4000c738
	.word	0x3ffc0000, 0x3ffc0000, 0x3ffe2bf0, 0x3ffe6448 # 4000c748
	.word	0x3ffef000, 0x3ffef000, 0x60000000, 0x60000000 # 4000c758
rodata_end:
