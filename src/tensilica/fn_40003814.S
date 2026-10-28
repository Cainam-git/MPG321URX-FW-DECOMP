# fn_40003814: 0x40003814-0x400038e6 (firmware file offset 0x33814-0x338e6), 80 instructions
# Called from: fn_4000a3cc
# Calls: fn_400099bc
# Indirect calls (callx): 1
# Text loaded: "POWER_UP\r\n", "POWER_DOWN\r\n", "MailBox Cmd: %02X %02X %04X \n"
# Addresses loaded: data_3ffe2590
# Other literal values: 0xe0091034, 0xe0091030, 0xaa550001, 0x55aa0002, 0xe0091020, 0xe0091024, 0x3ffe3f60

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003814, @function
fn_40003814:
	entry	a1, 48                  # 40003814
	l32r	a3, lit_3ffe1cbc        # 40003817  = 0xe0091034
	memw                            # 4000381a
	l32i.n	a3, a3, 0               # 4000381d
	l32r	a2, lit_3ffe1cc0        # 4000381f  = 0xe0091030
	memw                            # 40003822
	l32i.n	a2, a2, 0               # 40003825
	beq	a2, a3, .L40003875      # 40003827
	l32r	a5, lit_3ffe1cc4        # 4000382a  = 0xaa550001
	l32r	a4, lit_3ffe1cc0        # 4000382d  = 0xe0091030
	memw                            # 40003830
	l32i.n	a4, a4, 0               # 40003833
	bne	a4, a5, .L4000383e      # 40003835
	l32r	a10, lit_3ffe1cc8       # 40003838  = ro_3ffe04b4 "POWER_UP\r\n"
	call8	fn_400099bc             # 4000383b
.L4000383e:
	l32r	a6, lit_3ffe1ccc        # 4000383e  = 0x55aa0002
	l32r	a5, lit_3ffe1cc0        # 40003841  = 0xe0091030
	memw                            # 40003844
	l32i.n	a5, a5, 0               # 40003847
	bne	a5, a6, .L40003865      # 40003849
	l32r	a10, lit_3ffe1cd0       # 4000384c  = ro_3ffe04c0 "POWER_DOWN\r\n"
	call8	fn_400099bc             # 4000384f
	l32r	a7, lit_3ffe1cbc        # 40003852  = 0xe0091034
	l32r	a6, lit_3ffe1cc0        # 40003855  = 0xe0091030
	memw                            # 40003858
	l32i.n	a6, a6, 0               # 4000385b
	memw                            # 4000385d
	s32i.n	a6, a7, 0               # 40003860
.L40003862:
	j	.L40003862              # 40003862
.L40003865:
	l32r	a8, lit_3ffe1cbc        # 40003865  = 0xe0091034
	l32r	a7, lit_3ffe1cc0        # 40003868  = 0xe0091030
	memw                            # 4000386b
	l32i.n	a7, a7, 0               # 4000386e
	memw                            # 40003870
	s32i.n	a7, a8, 0               # 40003873
.L40003875:
	l32r	a10, lit_3ffe1cd4       # 40003875  = 0xe0091020
	memw                            # 40003878
	l32i.n	a10, a10, 0             # 4000387b
	extui	a10, a10, 24, 8         # 4000387d
	s32i.n	a10, a1, 0              # 40003880
	movi.n	a9, 0                   # 40003882
	l32i.n	a8, a1, 0               # 40003884
	beq	a8, a9, .L400038e5      # 40003886
	l32r	a15, lit_3ffe1cd4       # 40003889  = 0xe0091020
	memw                            # 4000388c
	l32i.n	a15, a15, 0             # 4000388f
	extui	a15, a15, 0, 16         # 40003891
	s32i.n	a15, a1, 4              # 40003894
	l32r	a14, lit_3ffe1cd4       # 40003896  = 0xe0091020
	memw                            # 40003899
	l32i.n	a14, a14, 0             # 4000389c
	extui	a14, a14, 16, 16        # 4000389e
	extui	a14, a14, 0, 8          # 400038a1
	s32i.n	a14, a1, 8              # 400038a4
	l32r	a14, lit_3ffe1cd8       # 400038a6  = 0xe0091024
	l32r	a13, lit_3ffe1cd4       # 400038a9  = 0xe0091020
	memw                            # 400038ac
	l32i.n	a13, a13, 0             # 400038af
	memw                            # 400038b1
	s32i.n	a13, a14, 0             # 400038b4
	l32r	a12, lit_3ffe1cd4       # 400038b6  = 0xe0091020
	movi.n	a11, 0                  # 400038b9
	memw                            # 400038bb
	s32i.n	a11, a12, 0             # 400038be
	l32r	a10, lit_3ffe1cdc       # 400038c0  = ro_3ffe04d0 "MailBox Cmd: %02X %02X %04X \n"
	l32i.n	a11, a1, 0              # 400038c3
	l32i.n	a12, a1, 8              # 400038c5
	l32i.n	a13, a1, 4              # 400038c7
	call8	fn_400099bc             # 400038c9
	l32i.n	a8, a1, 0               # 400038cc
	l32r	a9, lit_3ffe1cb8        # 400038ce  = 0x3ffe3f60
	addx4	a8, a8, a9              # 400038d1
	l32i.n	a8, a8, 0               # 400038d4
	l32i.n	a10, a1, 8              # 400038d6
	l32i.n	a11, a1, 4              # 400038d8
	l32r	a9, lit_3ffe1cb4        # 400038da  = data_3ffe2590
	addx8	a8, a8, a9              # 400038dd
	l32i.n	a8, a8, 4               # 400038e0
	callx8	a8                      # 400038e2
.L400038e5:
	retw.n                          # 400038e5
	.size	fn_40003814, . - fn_40003814
