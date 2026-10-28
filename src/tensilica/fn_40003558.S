# fn_40003558: 0x40003558-0x400035cd (firmware file offset 0x33558-0x335cd), 44 instructions
# Called from: fn_400035d0
# Calls: fn_40005fac
# Indirect calls (callx): 1
# Other literal values: 0x3ffe2bf0, 0x3ffe3f48, 0x3ffe3f4c, 0x3ffe3f50

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003558, @function
fn_40003558:
	entry	a1, 32                  # 40003558
	l32r	a3, lit_3ffe1a80        # 4000355b  = 0x3ffe2bf0
	l32i	a3, a3, 0x144           # 4000355e
	l32r	a2, lit_3ffe1ca4        # 40003561  = 0x3ffe3f48
	l32i.n	a2, a2, 0               # 40003564
	beq	a2, a3, .L400035a7      # 40003566
	l32r	a14, lit_3ffe1ca4       # 40003569  = 0x3ffe3f48
	l32r	a13, lit_3ffe1a80       # 4000356c  = 0x3ffe2bf0
	l32i	a13, a13, 0x144         # 4000356f
	s32i.n	a13, a14, 0             # 40003572
	l32r	a12, lit_3ffe1ca8       # 40003574  = 0x3ffe3f4c
	movi.n	a11, 0                  # 40003577
	s32i.n	a11, a12, 0             # 40003579
	l32r	a10, lit_3ffe1a80       # 4000357b  = 0x3ffe2bf0
	l32i	a10, a10, 0x144         # 4000357e
	call8	fn_40005fac             # 40003581
	l32r	a14, lit_3ffe1a80       # 40003584  = 0x3ffe2bf0
	l32i	a14, a14, 0x144         # 40003587
	beqi	a14, 1, .L40003596      # 4000358a
	l32r	a15, lit_3ffe1a80       # 4000358d  = 0x3ffe2bf0
	l32i	a15, a15, 0x144         # 40003590
	bnei	a15, 2, .L400035a0      # 40003593
.L40003596:
	l32r	a3, lit_3ffe1cac        # 40003596  = 0x3ffe3f50
	movi.n	a2, 1                   # 40003599
	s32i.n	a2, a3, 0               # 4000359b
	j	.L400035a7              # 4000359d
.L400035a0:
	l32r	a5, lit_3ffe1cac        # 400035a0  = 0x3ffe3f50
	movi.n	a4, 2                   # 400035a3
	s32i.n	a4, a5, 0               # 400035a5
.L400035a7:
	l32r	a7, lit_3ffe1cac        # 400035a7  = 0x3ffe3f50
	l32i.n	a7, a7, 0               # 400035aa
	l32r	a6, lit_3ffe1ca8        # 400035ac  = 0x3ffe3f4c
	l32i.n	a6, a6, 0               # 400035af
	bgeu	a6, a7, .L400035c3      # 400035b1
	l32r	a9, lit_3ffe1ca8        # 400035b4  = 0x3ffe3f4c
	l32r	a8, lit_3ffe1ca8        # 400035b7  = 0x3ffe3f4c
	l32i.n	a8, a8, 0               # 400035ba
	addi.n	a8, a8, 1               # 400035bc
	s32i.n	a8, a9, 0               # 400035be
	j	.L400035cc              # 400035c0
.L400035c3:
	l32r	a8, lit_3ffe1a80        # 400035c3  = 0x3ffe2bf0
	l32i	a8, a8, 0x13c           # 400035c6
	callx8	a8                      # 400035c9
.L400035cc:
	retw.n                          # 400035cc
	.size	fn_40003558, . - fn_40003558
