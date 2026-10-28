# fn_40005ba8: 0x40005ba8-0x40005c23 (firmware file offset 0x35ba8-0x35c23), 51 instructions
# Called from: fn_4000a3cc
# Calls: fn_400099bc
# Text loaded: "\n---------------------------------------------",
#              "\n    Welcome to User's Command Line Debug",
#              "\n---------------------------------------------\n"
# Other literal values: 0x3ffe4240, 0x3ffe4270

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005ba8, @function
fn_40005ba8:
	entry	a1, 48                  # 40005ba8
	l32r	a13, lit_3ffe1d70       # 40005bab  = 0x3ffe4240
	movi.n	a12, 0                  # 40005bae
	s8i	a12, a13, 25            # 40005bb0
	l32r	a11, lit_3ffe1d70       # 40005bb3  = 0x3ffe4240
	movi.n	a10, 0                  # 40005bb6
	s32i.n	a10, a11, 28            # 40005bb8
	l32r	a9, lit_3ffe1d70        # 40005bba  = 0x3ffe4240
	movi.n	a8, 0                   # 40005bbd
	s8i	a8, a9, 32              # 40005bbf
	l32r	a7, lit_3ffe1d70        # 40005bc2  = 0x3ffe4240
	movi.n	a6, 0                   # 40005bc5
	s8i	a6, a7, 24              # 40005bc7
	l32r	a5, lit_3ffe1d70        # 40005bca  = 0x3ffe4240
	movi.n	a4, 0                   # 40005bcd
	s32i.n	a4, a5, 0               # 40005bcf
	movi.n	a3, 0                   # 40005bd1
	s32i.n	a3, a1, 0               # 40005bd3
	l32i.n	a2, a1, 0               # 40005bd5
	bgei	a2, 4, .L40005c10       # 40005bd7
.L40005bda:
	movi.n	a2, 0                   # 40005bda
	s32i.n	a2, a1, 4               # 40005bdc
	l32i.n	a15, a1, 4              # 40005bde
	movi.n	a14, 31                 # 40005be0
	blt	a14, a15, .L40005c05    # 40005be2
.L40005be5:
	l32r	a8, lit_3ffe1d74        # 40005be5  = 0x3ffe4270
	l32i.n	a9, a1, 0               # 40005be8
	slli	a9, a9, 5               # 40005bea
	l32i.n	a7, a1, 4               # 40005bed
	add.n	a7, a7, a9              # 40005bef
	add.n	a7, a7, a8              # 40005bf1
	movi.n	a6, 0                   # 40005bf3
	s8i	a6, a7, 0               # 40005bf5
	l32i.n	a5, a1, 4               # 40005bf8
	addi.n	a5, a5, 1               # 40005bfa
	s32i.n	a5, a1, 4               # 40005bfc
	l32i.n	a4, a1, 4               # 40005bfe
	movi.n	a3, 31                  # 40005c00
	bge	a3, a4, .L40005be5      # 40005c02
.L40005c05:
	l32i.n	a11, a1, 0              # 40005c05
	addi.n	a11, a11, 1             # 40005c07
	s32i.n	a11, a1, 0              # 40005c09
	l32i.n	a10, a1, 0              # 40005c0b
	blti	a10, 4, .L40005bda      # 40005c0d
.L40005c10:
	l32r	a10, lit_3ffe1e04       # 40005c10  = ro_3ffe0924 "\n---------------------------------------------"
	call8	fn_400099bc             # 40005c13
	l32r	a10, lit_3ffe1e08       # 40005c16  = ro_3ffe0954 "\n    Welcome to User's Command Line Debug"
	call8	fn_400099bc             # 40005c19
	l32r	a10, lit_3ffe1e0c       # 40005c1c  = ro_3ffe0980 "\n---------------------------------------------\n"
	call8	fn_400099bc             # 40005c1f
	retw.n                          # 40005c22
	.size	fn_40005ba8, . - fn_40005ba8
