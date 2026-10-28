# fn_40001ac8: 0x40001ac8-0x40001b06 (firmware file offset 0x31ac8-0x31b06), 25 instructions
# Address stored in the words at: 0x4000d3f4
# Calls: fn_4000679c
# Addresses loaded: data_3ffe2390
# Other literal values: 0x3ffe2bf0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001ac8, @function
fn_40001ac8:
	entry	a1, 48                  # 40001ac8
	s32i.n	a2, a1, 0               # 40001acb
	s32i.n	a3, a1, 4               # 40001acd
	l32r	a7, lit_3ffe1a80        # 40001acf  = 0x3ffe2bf0
	movi.n	a10, 1                  # 40001ad2
	l32i.n	a9, a1, 4               # 40001ad4
	addi.n	a9, a9, -1              # 40001ad6
	movi.n	a8, 1                   # 40001ad8
	movi.n	a6, 0                   # 40001ada
	moveqz	a6, a8, a9              # 40001adc
	s32i	a6, a7, 0x154           # 40001adf
	movi.n	a6, 0                   # 40001ae2
	l32r	a5, lit_3ffe1a80        # 40001ae4  = 0x3ffe2bf0
	l32i	a5, a5, 0x154           # 40001ae7
	beq	a5, a6, .L40001afd      # 40001aea
	movi.n	a11, -5                 # 40001aed
	l32r	a10, lit_3ffe1a98       # 40001aef  = data_3ffe2390
	l32i.n	a10, a10, 4             # 40001af2
	and	a10, a10, a11           # 40001af4
	call8	fn_4000679c             # 40001af7
	j	.L40001b05              # 40001afa
.L40001afd:
	l32r	a10, lit_3ffe1a98       # 40001afd  = data_3ffe2390
	l32i.n	a10, a10, 4             # 40001b00
	call8	fn_4000679c             # 40001b02
.L40001b05:
	retw.n                          # 40001b05
	.size	fn_40001ac8, . - fn_40001ac8
