# fn_40000e20: 0x40000e20-0x40000fb3 (firmware file offset 0x30e20-0x30fb3), 156 instructions
# Called from: fn_4000a3cc
# Calls: fn_4000087c, fn_400008c0, fn_40000de8, fn_40005fac, fn_4000679c
# Addresses loaded: data_3ffe2390, fn_400009a0
# Other literal values: 0xe0091010, 0x3ffe2bf0, 0x3ffe3db0, 0x00020000, 0x3ffe3e30, 0x000fff00, 0x00000fff,
#                       0x3ffe3eb0, 0x3ffe3ef0, 0x00000870, 0x00000f00, 0xe00910a0, 0xe00910a4, 0xe00910a8,
#                       0xe00910ac

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40000e20, @function
fn_40000e20:
	entry	a1, 48                  # 40000e20
	movi.n	a11, 0                  # 40000e23
	s32i.n	a11, a1, 0              # 40000e25
	l32r	a10, lit_3ffe1aa8       # 40000e27  = 0xe0091010
	movi.n	a9, 1                   # 40000e2a
	memw                            # 40000e2c
	s32i.n	a9, a10, 0              # 40000e2f
	l32r	a8, lit_3ffe1a80        # 40000e31  = 0x3ffe2bf0
	movi.n	a7, 3                   # 40000e34
	s32i	a7, a8, 0x140           # 40000e36
	l32r	a6, lit_3ffe1a80        # 40000e39  = 0x3ffe2bf0
	movi.n	a5, 0                   # 40000e3c
	s32i	a5, a6, 0x144           # 40000e3e
	movi.n	a4, 0                   # 40000e41
	s32i.n	a4, a1, 0               # 40000e43
	l32i.n	a3, a1, 0               # 40000e45
	movi.n	a2, 31                  # 40000e47
	bltu	a2, a3, .L40000e73      # 40000e49
.L40000e4c:
	l32i.n	a5, a1, 0               # 40000e4c
	l32r	a6, lit_3ffe1aac        # 40000e4e  = 0x3ffe3db0
	addx4	a5, a5, a6              # 40000e51
	l32r	a4, lit_3ffe1ab0        # 40000e54  = 0x00020000
	s32i.n	a4, a5, 0               # 40000e57
	l32i.n	a2, a1, 0               # 40000e59
	l32r	a3, lit_3ffe1ab4        # 40000e5b  = 0x3ffe3e30
	addx4	a2, a2, a3              # 40000e5e
	l32r	a15, lit_3ffe1ab8       # 40000e61  = 0x000fff00
	s32i.n	a15, a2, 0              # 40000e64
	l32i.n	a14, a1, 0              # 40000e66
	addi.n	a14, a14, 1             # 40000e68
	s32i.n	a14, a1, 0              # 40000e6a
	l32i.n	a13, a1, 0              # 40000e6c
	movi.n	a12, 31                 # 40000e6e
	bgeu	a12, a13, .L40000e4c    # 40000e70
.L40000e73:
	l32r	a10, lit_3ffe1abc       # 40000e73  = 0x00000fff
	l32r	a11, lit_3ffe1ac0       # 40000e76  = 0x3ffe3eb0
	movi.n	a12, 32                 # 40000e79
	call8	fn_4000087c             # 40000e7b
	movi	a10, 0x200              # 40000e7e
	l32r	a11, lit_3ffe1ac4       # 40000e81  = 0x3ffe3ef0
	movi.n	a12, 32                 # 40000e84
	call8	fn_4000087c             # 40000e86
	l32r	a3, lit_3ffe1a80        # 40000e89  = 0x3ffe2bf0
	l32r	a2, lit_3ffe1ac8        # 40000e8c  = 0x00000870
	s32i.n	a2, a3, 4               # 40000e8f
	l32r	a15, lit_3ffe1a80       # 40000e91  = 0x3ffe2bf0
	l32r	a14, lit_3ffe1acc       # 40000e94  = 0x00000f00
	s32i.n	a14, a15, 0             # 40000e97
	l32r	a13, lit_3ffe1a80       # 40000e99  = 0x3ffe2bf0
	l32r	a12, lit_3ffe1abc       # 40000e9c  = 0x00000fff
	s32i.n	a12, a13, 8             # 40000e9f
	l32r	a11, lit_3ffe1a80       # 40000ea1  = 0x3ffe2bf0
	movi.n	a10, 0                  # 40000ea4
	s32i.n	a10, a11, 12            # 40000ea6
	l32r	a9, lit_3ffe1a80        # 40000ea8  = 0x3ffe2bf0
	movi.n	a8, 4                   # 40000eab
	s32i.n	a8, a9, 16              # 40000ead
	l32r	a7, lit_3ffe1a80        # 40000eaf  = 0x3ffe2bf0
	movi.n	a6, 8                   # 40000eb2
	s32i.n	a6, a7, 20              # 40000eb4
	l32r	a5, lit_3ffe1a80        # 40000eb6  = 0x3ffe2bf0
	movi.n	a4, 1                   # 40000eb9
	s32i.n	a4, a5, 24              # 40000ebb
	l32r	a3, lit_3ffe1a80        # 40000ebd  = 0x3ffe2bf0
	movi.n	a2, 1                   # 40000ec0
	s32i.n	a2, a3, 28              # 40000ec2
	l32r	a15, lit_3ffe1a80       # 40000ec4  = 0x3ffe2bf0
	movi.n	a14, 0                  # 40000ec7
	s32i.n	a14, a15, 32            # 40000ec9
	l32r	a14, lit_3ffe1ad0       # 40000ecb  = 0xe00910a0
	l32r	a13, lit_3ffe1a80       # 40000ece  = 0x3ffe2bf0
	l32i.n	a13, a13, 4             # 40000ed1
	memw                            # 40000ed3
	s32i.n	a13, a14, 0             # 40000ed6
	l32r	a11, lit_3ffe1ad0       # 40000ed8  = 0xe00910a0
	l32r	a12, lit_3ffe1a80       # 40000edb  = 0x3ffe2bf0
	l32i.n	a12, a12, 0             # 40000ede
	slli	a12, a12, 16            # 40000ee0
	l32r	a10, lit_3ffe1ad0       # 40000ee3  = 0xe00910a0
	memw                            # 40000ee6
	l32i.n	a10, a10, 0             # 40000ee9
	or	a10, a10, a12           # 40000eeb
	memw                            # 40000eee
	s32i.n	a10, a11, 0             # 40000ef1
	l32r	a10, lit_3ffe1ad4       # 40000ef3  = 0xe00910a4
	l32r	a9, lit_3ffe1a80        # 40000ef6  = 0x3ffe2bf0
	l32i.n	a9, a9, 8               # 40000ef9
	memw                            # 40000efb
	s32i.n	a9, a10, 0              # 40000efe
	l32r	a7, lit_3ffe1ad4        # 40000f00  = 0xe00910a4
	l32r	a8, lit_3ffe1a80        # 40000f03  = 0x3ffe2bf0
	l32i.n	a8, a8, 12              # 40000f06
	slli	a8, a8, 16              # 40000f08
	l32r	a6, lit_3ffe1ad4        # 40000f0b  = 0xe00910a4
	memw                            # 40000f0e
	l32i.n	a6, a6, 0               # 40000f11
	or	a6, a6, a8              # 40000f13
	memw                            # 40000f16
	s32i.n	a6, a7, 0               # 40000f19
	l32r	a6, lit_3ffe1ad8        # 40000f1b  = 0xe00910a8
	l32r	a5, lit_3ffe1a80        # 40000f1e  = 0x3ffe2bf0
	l32i.n	a5, a5, 16              # 40000f21
	memw                            # 40000f23
	s32i.n	a5, a6, 0               # 40000f26
	l32r	a3, lit_3ffe1ad8        # 40000f28  = 0xe00910a8
	l32r	a4, lit_3ffe1a80        # 40000f2b  = 0x3ffe2bf0
	l32i.n	a4, a4, 20              # 40000f2e
	slli	a4, a4, 8               # 40000f30
	l32r	a2, lit_3ffe1ad8        # 40000f33  = 0xe00910a8
	memw                            # 40000f36
	l32i.n	a2, a2, 0               # 40000f39
	or	a2, a2, a4              # 40000f3b
	memw                            # 40000f3e
	s32i.n	a2, a3, 0               # 40000f41
	l32r	a2, lit_3ffe1adc        # 40000f43  = 0xe00910ac
	l32r	a15, lit_3ffe1a80       # 40000f46  = 0x3ffe2bf0
	l32i.n	a15, a15, 24            # 40000f49
	memw                            # 40000f4b
	s32i.n	a15, a2, 0              # 40000f4e
	l32r	a13, lit_3ffe1adc       # 40000f50  = 0xe00910ac
	l32r	a14, lit_3ffe1a80       # 40000f53  = 0x3ffe2bf0
	l32i.n	a14, a14, 28            # 40000f56
	slli	a14, a14, 8             # 40000f58
	l32r	a12, lit_3ffe1adc       # 40000f5b  = 0xe00910ac
	memw                            # 40000f5e
	l32i.n	a12, a12, 0             # 40000f61
	or	a12, a12, a14           # 40000f63
	memw                            # 40000f66
	s32i.n	a12, a13, 0             # 40000f69
	l32r	a10, lit_3ffe1adc       # 40000f6b  = 0xe00910ac
	l32r	a11, lit_3ffe1a80       # 40000f6e  = 0x3ffe2bf0
	l32i.n	a11, a11, 32            # 40000f71
	slli	a11, a11, 16            # 40000f73
	l32r	a9, lit_3ffe1adc        # 40000f76  = 0xe00910ac
	memw                            # 40000f79
	l32i.n	a9, a9, 0               # 40000f7c
	or	a9, a9, a11             # 40000f7e
	memw                            # 40000f81
	s32i.n	a9, a10, 0              # 40000f84
	l32r	a8, lit_3ffe1a98        # 40000f86  = data_3ffe2390
	movi.n	a7, 32                  # 40000f89
	s32i.n	a7, a8, 0               # 40000f8b
	call8	fn_400008c0             # 40000f8d
	l32r	a12, lit_3ffe1a80       # 40000f90  = 0x3ffe2bf0
	l32r	a11, lit_3ffe1ae0       # 40000f93  = fn_400009a0
	s32i	a11, a12, 0x148         # 40000f96
	l32r	a10, lit_3ffe1a80       # 40000f99  = 0x3ffe2bf0
	l32i.n	a10, a10, 24            # 40000f9c
	call8	fn_40000de8             # 40000f9e
	l32r	a10, lit_3ffe1a80       # 40000fa1  = 0x3ffe2bf0
	l32i	a10, a10, 0x144         # 40000fa4
	call8	fn_40005fac             # 40000fa7
	l32r	a10, lit_3ffe1a98       # 40000faa  = data_3ffe2390
	l32i.n	a10, a10, 4             # 40000fad
	call8	fn_4000679c             # 40000faf
	retw.n                          # 40000fb2
	.size	fn_40000e20, . - fn_40000e20
