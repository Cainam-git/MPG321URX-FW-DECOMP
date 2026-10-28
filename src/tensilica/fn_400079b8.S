# fn_400079b8: 0x400079b8-0x40007ab7 (firmware file offset 0x379b8-0x37ab7), 102 instructions
# Called from: fn_400013a0, fn_400077d4
# Calls: fn_40007998, fn_400074b4, fn_40007878, fn_40007760, fn_40007914, fn_400077a4, fn_400078e8,
#        fn_40007820, fn_40007348, fn_4000713c, fn_400077fc, fn_400099bc
# Text loaded: "LED_AS3824_Init Done!! \n"
# Other literal values: 0x00000fff, 0x3ffe54a0, 0x3ffe5500, 0x3ffe54c0, 0x3ffe5548, 0x3ffe2c24

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400079b8, @function
fn_400079b8:
	entry	a1, 48                  # 400079b8
	movi.n	a3, 0                   # 400079bb
	s32i.n	a3, a1, 0               # 400079bd
	movi.n	a2, 0                   # 400079bf
	s32i.n	a2, a1, 4               # 400079c1
	call8	fn_40007998             # 400079c3
	movi.n	a10, 3                  # 400079c6
	movi	a11, 143                # 400079c8
	call8	fn_400074b4             # 400079cb
	movi	a10, 128                # 400079ce
	call8	fn_40007878             # 400079d1
	movi	a10, 0x200              # 400079d4
	call8	fn_40007760             # 400079d7
	movi.n	a10, 14                 # 400079da
	movi	a11, 255                # 400079dc
	call8	fn_400074b4             # 400079df
	movi.n	a10, 15                 # 400079e2
	movi	a11, 255                # 400079e4
	call8	fn_400074b4             # 400079e7
	movi.n	a10, 18                 # 400079ea
	movi.n	a11, 5                  # 400079ec
	call8	fn_400074b4             # 400079ee
	movi.n	a10, 0                  # 400079f1
	call8	fn_40007914             # 400079f3
	l32r	a10, lit_3ffe1abc       # 400079f6  = 0x00000fff
	call8	fn_400077a4             # 400079f9
	movi.n	a10, 0                  # 400079fc
	call8	fn_400078e8             # 400079fe
	movi.n	a10, 6                  # 40007a01
	call8	fn_40007820             # 40007a03
	l32r	a8, lit_3ffe20ac        # 40007a06  = 0x3ffe54a0
	movi.n	a7, 16                  # 40007a09
	s32i.n	a7, a8, 12              # 40007a0b
	movi.n	a6, 0                   # 40007a0d
	s32i.n	a6, a1, 4               # 40007a0f
	l32i.n	a5, a1, 4               # 40007a11
	movi.n	a4, 0                   # 40007a13
	bgeu	a4, a5, .L40007a1b      # 40007a15
	j	.L40007aa3              # 40007a18
.L40007a1b:
	l32r	a15, lit_3ffe20ac       # 40007a1b  = 0x3ffe54a0
	l32i.n	a14, a1, 4              # 40007a1e
	addi.n	a14, a14, 1             # 40007a20
	s32i.n	a14, a15, 0             # 40007a22
	l32r	a13, lit_3ffe20ac       # 40007a24  = 0x3ffe54a0
	movi.n	a12, 1                  # 40007a27
	s32i	a12, a13, 232           # 40007a29
	movi.n	a11, 0                  # 40007a2c
	s32i.n	a11, a1, 0              # 40007a2e
	l32i.n	a10, a1, 0              # 40007a30
	movi.n	a9, 15                  # 40007a32
	bltu	a9, a10, .L40007a71     # 40007a34
.L40007a37:
	l32i.n	a11, a1, 0              # 40007a37
	l32r	a12, lit_3ffe20e8       # 40007a39  = 0x3ffe5500
	addx4	a11, a11, a12           # 40007a3c
	l32r	a10, lit_3ffe1abc       # 40007a3f  = 0x00000fff
	s32i.n	a10, a11, 0             # 40007a42
	l32i.n	a8, a1, 0               # 40007a44
	l32r	a9, lit_3ffe20ec        # 40007a46  = 0x3ffe54c0
	addx4	a8, a8, a9              # 40007a49
	movi.n	a7, 0                   # 40007a4c
	s32i.n	a7, a8, 0               # 40007a4e
	l32i.n	a5, a1, 0               # 40007a50
	l32r	a6, lit_3ffe205c        # 40007a52  = 0x3ffe5548
	addx4	a5, a5, a6              # 40007a55
	l32i.n	a4, a1, 0               # 40007a58
	l32r	a6, lit_3ffe1b08        # 40007a5a  = 0x3ffe2c24
	addx4	a4, a4, a6              # 40007a5d
	l32i.n	a4, a4, 0               # 40007a60
	s32i.n	a4, a5, 0               # 40007a62
	l32i.n	a3, a1, 0               # 40007a64
	addi.n	a3, a3, 1               # 40007a66
	s32i.n	a3, a1, 0               # 40007a68
	l32i.n	a2, a1, 0               # 40007a6a
	movi.n	a15, 15                 # 40007a6c
	bgeu	a15, a2, .L40007a37     # 40007a6e
.L40007a71:
	l32r	a10, lit_3ffe20ac       # 40007a71  = 0x3ffe54a0
	l32i.n	a10, a10, 0             # 40007a74
	l32r	a11, lit_3ffe20ec       # 40007a76  = 0x3ffe54c0
	l32r	a12, lit_3ffe20ac       # 40007a79  = 0x3ffe54a0
	l32i	a12, a12, 232           # 40007a7c
	call8	fn_40007348             # 40007a7f
	l32r	a10, lit_3ffe20ac       # 40007a82  = 0x3ffe54a0
	l32i.n	a10, a10, 0             # 40007a85
	l32r	a11, lit_3ffe20e8       # 40007a87  = 0x3ffe5500
	l32r	a12, lit_3ffe20ac       # 40007a8a  = 0x3ffe54a0
	l32i	a12, a12, 232           # 40007a8d
	call8	fn_4000713c             # 40007a90
	l32i.n	a13, a1, 4              # 40007a93
	addi.n	a13, a13, 1             # 40007a95
	s32i.n	a13, a1, 4              # 40007a97
	l32i.n	a12, a1, 4              # 40007a99
	movi.n	a11, 0                  # 40007a9b
	bltu	a11, a12, .L40007aa3    # 40007a9d
	j	.L40007a1b              # 40007aa0
.L40007aa3:
	movi.n	a10, 0                  # 40007aa3
	call8	fn_400077fc             # 40007aa5
	l32r	a15, lit_3ffe20ac       # 40007aa8  = 0x3ffe54a0
	movi.n	a14, 1                  # 40007aab
	s32i	a14, a15, 236           # 40007aad
	l32r	a10, lit_3ffe20f0       # 40007ab0  = ro_3ffe0d48 "LED_AS3824_Init Done!! \n"
	call8	fn_400099bc             # 40007ab3
	retw.n                          # 40007ab6
	.size	fn_400079b8, . - fn_400079b8
