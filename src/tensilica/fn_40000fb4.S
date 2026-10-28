# fn_40000fb4: 0x40000fb4-0x40001186 (firmware file offset 0x30fb4-0x31186), 179 instructions
# Called from: fn_40001344
# Calls: fn_400099bc
# Text loaded: "Configured seg size is over than tensilica seg buf size!!\n",
#              "Leon2M conf LED_col = %d, LED_row = %d\n", "Tensilica LED_CH_NUM = %d\n",
#              "LDC_LoadPanel Error!!\n", "PanelInfo\r\n", "Resolution: %d x %d\r\n",
#              "DriverDuty: Max %04x Min %04x\r\n", "LEDRowCol: %02d x %02d : %02d\r\n",
#              "DriverType: Type %02x Num %02x Seq %02x\r\n"
# Addresses loaded: data_3ffe2390
# Other literal values: 0x3ffe2bf0, 0xe00910a0, 0xe00910a4, 0xe00910a8, 0xe00910ac, 0x3ffe2c24, 0xe00910c0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40000fb4, @function
fn_40000fb4:
	entry	a1, 48                  # 40000fb4
	l32r	a14, lit_3ffe1a80       # 40000fb7  = 0x3ffe2bf0
	l32r	a13, lit_3ffe1ad0       # 40000fba  = 0xe00910a0
	memw                            # 40000fbd
	l32i.n	a13, a13, 0             # 40000fc0
	extui	a13, a13, 0, 16         # 40000fc2
	s32i.n	a13, a14, 4             # 40000fc5
	l32r	a13, lit_3ffe1a80       # 40000fc7  = 0x3ffe2bf0
	l32r	a12, lit_3ffe1ad0       # 40000fca  = 0xe00910a0
	memw                            # 40000fcd
	l32i.n	a12, a12, 0             # 40000fd0
	extui	a12, a12, 16, 16        # 40000fd2
	s32i.n	a12, a13, 0             # 40000fd5
	l32r	a12, lit_3ffe1a80       # 40000fd7  = 0x3ffe2bf0
	l32r	a11, lit_3ffe1ad4       # 40000fda  = 0xe00910a4
	memw                            # 40000fdd
	l32i.n	a11, a11, 0             # 40000fe0
	extui	a11, a11, 0, 16         # 40000fe2
	s32i.n	a11, a12, 8             # 40000fe5
	l32r	a11, lit_3ffe1a80       # 40000fe7  = 0x3ffe2bf0
	l32r	a10, lit_3ffe1ad4       # 40000fea  = 0xe00910a4
	memw                            # 40000fed
	l32i.n	a10, a10, 0             # 40000ff0
	extui	a10, a10, 16, 16        # 40000ff2
	s32i.n	a10, a11, 12            # 40000ff5
	l32r	a10, lit_3ffe1a80       # 40000ff7  = 0x3ffe2bf0
	l32r	a9, lit_3ffe1ad8        # 40000ffa  = 0xe00910a8
	memw                            # 40000ffd
	l32i.n	a9, a9, 0               # 40001000
	extui	a9, a9, 0, 8            # 40001002
	s32i.n	a9, a10, 16             # 40001005
	l32r	a9, lit_3ffe1a80        # 40001007  = 0x3ffe2bf0
	l32r	a8, lit_3ffe1ad8        # 4000100a  = 0xe00910a8
	memw                            # 4000100d
	l32i.n	a8, a8, 0               # 40001010
	srli	a8, a8, 8               # 40001012
	s32i.n	a8, a9, 20              # 40001015
	l32r	a8, lit_3ffe1a80        # 40001017  = 0x3ffe2bf0
	l32r	a7, lit_3ffe1adc        # 4000101a  = 0xe00910ac
	memw                            # 4000101d
	l32i.n	a7, a7, 0               # 40001020
	extui	a7, a7, 0, 8            # 40001022
	s32i.n	a7, a8, 24              # 40001025
	l32r	a7, lit_3ffe1a80        # 40001027  = 0x3ffe2bf0
	l32r	a6, lit_3ffe1adc        # 4000102a  = 0xe00910ac
	memw                            # 4000102d
	l32i.n	a6, a6, 0               # 40001030
	srli	a6, a6, 8               # 40001032
	extui	a6, a6, 0, 8            # 40001035
	s32i.n	a6, a7, 28              # 40001038
	l32r	a6, lit_3ffe1a80        # 4000103a  = 0x3ffe2bf0
	l32r	a5, lit_3ffe1adc        # 4000103d  = 0xe00910ac
	memw                            # 40001040
	l32i.n	a5, a5, 0               # 40001043
	extui	a5, a5, 16, 16          # 40001045
	extui	a5, a5, 0, 8            # 40001048
	s32i.n	a5, a6, 32              # 4000104b
	l32r	a4, lit_3ffe1a80        # 4000104d  = 0x3ffe2bf0
	l32i.n	a4, a4, 20              # 40001050
	l32r	a3, lit_3ffe1a80        # 40001052  = 0x3ffe2bf0
	l32i.n	a3, a3, 16              # 40001055
	mull	a3, a3, a4              # 40001057
	movi.n	a2, 32                  # 4000105a
	bgeu	a2, a3, .L40001086      # 4000105c
.L4000105f:
	l32r	a10, lit_3ffe1ae4       # 4000105f  = ro_3ffe0000 "Configured seg size is over than tensilica seg buf size!!\n"
	call8	fn_400099bc             # 40001062
	l32r	a10, lit_3ffe1ae8       # 40001065  = ro_3ffe003c "Leon2M conf LED_col = %d, LED_row = %d\n"
	l32r	a11, lit_3ffe1a80       # 40001068  = 0x3ffe2bf0
	l32i.n	a11, a11, 20            # 4000106b
	l32r	a12, lit_3ffe1a80       # 4000106d  = 0x3ffe2bf0
	l32i.n	a12, a12, 16            # 40001070
	call8	fn_400099bc             # 40001072
	l32r	a10, lit_3ffe1aec       # 40001075  = ro_3ffe0064 "Tensilica LED_CH_NUM = %d\n"
	movi.n	a11, 32                 # 40001078
	call8	fn_400099bc             # 4000107a
	l32r	a10, lit_3ffe1af0       # 4000107d  = ro_3ffe0080 "LDC_LoadPanel Error!!\n"
	call8	fn_400099bc             # 40001080
	j	.L4000105f              # 40001083
.L40001086:
	l32r	a13, lit_3ffe1a98       # 40001086  = data_3ffe2390
	l32r	a14, lit_3ffe1a80       # 40001089  = 0x3ffe2bf0
	l32i.n	a14, a14, 20            # 4000108c
	l32r	a12, lit_3ffe1a80       # 4000108e  = 0x3ffe2bf0
	l32i.n	a12, a12, 16            # 40001091
	mull	a12, a12, a14           # 40001093
	s32i.n	a12, a13, 0             # 40001096
	l32r	a10, lit_3ffe1af4       # 40001098  = ro_3ffe0098 "PanelInfo\r\n"
	call8	fn_400099bc             # 4000109b
	l32r	a10, lit_3ffe1af8       # 4000109e  = ro_3ffe00a4 "Resolution: %d x %d\r\n"
	l32r	a11, lit_3ffe1a80       # 400010a1  = 0x3ffe2bf0
	l32i.n	a11, a11, 0             # 400010a4
	l32r	a12, lit_3ffe1a80       # 400010a6  = 0x3ffe2bf0
	l32i.n	a12, a12, 4             # 400010a9
	call8	fn_400099bc             # 400010ab
	l32r	a10, lit_3ffe1afc       # 400010ae  = ro_3ffe00bc "DriverDuty: Max %04x Min %04x\r\n"
	l32r	a11, lit_3ffe1a80       # 400010b1  = 0x3ffe2bf0
	l32i.n	a11, a11, 8             # 400010b4
	l32r	a12, lit_3ffe1a80       # 400010b6  = 0x3ffe2bf0
	l32i.n	a12, a12, 12            # 400010b9
	call8	fn_400099bc             # 400010bb
	l32r	a10, lit_3ffe1b00       # 400010be  = ro_3ffe00dc "LEDRowCol: %02d x %02d : %02d\r\n"
	l32r	a11, lit_3ffe1a80       # 400010c1  = 0x3ffe2bf0
	l32i.n	a11, a11, 16            # 400010c4
	l32r	a12, lit_3ffe1a80       # 400010c6  = 0x3ffe2bf0
	l32i.n	a12, a12, 20            # 400010c9
	l32r	a13, lit_3ffe1a98       # 400010cb  = data_3ffe2390
	l32i.n	a13, a13, 0             # 400010ce
	call8	fn_400099bc             # 400010d0
	l32r	a10, lit_3ffe1b04       # 400010d3  = ro_3ffe00fc "DriverType: Type %02x Num %02x Seq %02x\r\n"
	l32r	a11, lit_3ffe1a80       # 400010d6  = 0x3ffe2bf0
	l32i.n	a11, a11, 24            # 400010d9
	l32r	a12, lit_3ffe1a80       # 400010db  = 0x3ffe2bf0
	l32i.n	a12, a12, 28            # 400010de
	l32r	a13, lit_3ffe1a80       # 400010e0  = 0x3ffe2bf0
	l32i.n	a13, a13, 32            # 400010e3
	call8	fn_400099bc             # 400010e5
	movi.n	a14, 0                  # 400010e8
	s32i.n	a14, a1, 0              # 400010ea
	l32i.n	a13, a1, 0              # 400010ec
	movi.n	a12, 31                 # 400010ee
	bgeu	a12, a13, .L400010f6    # 400010f0
	j	.L40001185              # 400010f3
.L400010f6:
	l32i.n	a14, a1, 0              # 400010f6
	l32r	a15, lit_3ffe1b08       # 400010f8  = 0x3ffe2c24
	addx4	a14, a14, a15           # 400010fb
	l32i.n	a13, a1, 0              # 400010fe
	memw                            # 40001100
	l32r	a15, lit_3ffe1b0c       # 40001103  = 0xe00910c0
	add.n	a13, a13, a15           # 40001106
	memw                            # 40001108
	l32i.n	a13, a13, 0             # 4000110b
	extui	a13, a13, 0, 8          # 4000110d
	s32i.n	a13, a14, 0             # 40001110
	l32i.n	a11, a1, 0              # 40001112
	l32r	a12, lit_3ffe1b08       # 40001114  = 0x3ffe2c24
	addx4	a11, a11, a12           # 40001117
	addi.n	a11, a11, 4             # 4000111a
	l32i.n	a10, a1, 0              # 4000111c
	memw                            # 4000111e
	l32r	a12, lit_3ffe1b0c       # 40001121  = 0xe00910c0
	add.n	a10, a10, a12           # 40001124
	memw                            # 40001126
	l32i.n	a10, a10, 0             # 40001129
	srli	a10, a10, 8             # 4000112b
	extui	a10, a10, 0, 8          # 4000112e
	s32i.n	a10, a11, 0             # 40001131
	l32i.n	a8, a1, 0               # 40001133
	l32r	a9, lit_3ffe1b08        # 40001135  = 0x3ffe2c24
	addx4	a8, a8, a9              # 40001138
	addi.n	a8, a8, 8               # 4000113b
	l32i.n	a7, a1, 0               # 4000113d
	memw                            # 4000113f
	l32r	a9, lit_3ffe1b0c        # 40001142  = 0xe00910c0
	add.n	a7, a7, a9              # 40001145
	memw                            # 40001147
	l32i.n	a7, a7, 0               # 4000114a
	extui	a7, a7, 16, 16          # 4000114c
	extui	a7, a7, 0, 8            # 4000114f
	s32i.n	a7, a8, 0               # 40001152
	l32i.n	a5, a1, 0               # 40001154
	l32r	a6, lit_3ffe1b08        # 40001156  = 0x3ffe2c24
	addx4	a5, a5, a6              # 40001159
	addi.n	a5, a5, 12              # 4000115c
	l32i.n	a4, a1, 0               # 4000115e
	memw                            # 40001160
	l32r	a6, lit_3ffe1b0c        # 40001163  = 0xe00910c0
	add.n	a4, a4, a6              # 40001166
	memw                            # 40001168
	l32i.n	a4, a4, 0               # 4000116b
	extui	a4, a4, 24, 8           # 4000116d
	extui	a4, a4, 0, 8            # 40001170
	s32i.n	a4, a5, 0               # 40001173
	l32i.n	a3, a1, 0               # 40001175
	addi.n	a3, a3, 4               # 40001177
	s32i.n	a3, a1, 0               # 40001179
	l32i.n	a2, a1, 0               # 4000117b
	movi.n	a15, 31                 # 4000117d
	bltu	a15, a2, .L40001185     # 4000117f
	j	.L400010f6              # 40001182
.L40001185:
	retw.n                          # 40001185
	.size	fn_40000fb4, . - fn_40000fb4
