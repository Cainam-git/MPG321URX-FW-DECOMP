# fn_40009f70: 0x40009f70-0x40009fc7 (firmware file offset 0x39f70-0x39fc7), 33 instructions
# Called from: fn_400058dc
# Other literal values: 0x3ffe5cd0, 0x3ffe5cd4

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40009f70, @function
fn_40009f70:
	entry	a1, 64                  # 40009f70
	s32i.n	a2, a1, 16              # 40009f73
	l32r	a5, lit_3ffe230c        # 40009f75  = 0x3ffe5cd0
	l32i	a5, a5, 0x208           # 40009f78
	l32r	a4, lit_3ffe230c        # 40009f7b  = 0x3ffe5cd0
	l32i	a4, a4, 0x204           # 40009f7e
	bne	a4, a5, .L40009f8b      # 40009f81
	movi.n	a6, 0                   # 40009f84
	s32i.n	a6, a1, 0               # 40009f86
	j	.L40009fc4              # 40009f88
.L40009f8b:
	l32i.n	a11, a1, 16             # 40009f8b
	l32r	a10, lit_3ffe230c       # 40009f8d  = 0x3ffe5cd0
	l32i	a10, a10, 0x208         # 40009f90
	l32r	a12, lit_3ffe231c       # 40009f93  = 0x3ffe5cd4
	addx4	a10, a10, a12           # 40009f96
	l32i.n	a10, a10, 0             # 40009f99
	s8i	a10, a11, 0             # 40009f9b
	l32r	a10, lit_3ffe230c       # 40009f9e  = 0x3ffe5cd0
	l32r	a9, lit_3ffe230c        # 40009fa1  = 0x3ffe5cd0
	l32i	a9, a9, 0x208           # 40009fa4
	addi.n	a9, a9, 1               # 40009fa7
	s32i	a9, a10, 0x208          # 40009fa9
	l32r	a8, lit_3ffe230c        # 40009fac  = 0x3ffe5cd0
	l32i	a8, a8, 0x208           # 40009faf
	movi	a7, 127                 # 40009fb2
	bgeu	a7, a8, .L40009fc0      # 40009fb5
	l32r	a13, lit_3ffe230c       # 40009fb8  = 0x3ffe5cd0
	movi.n	a12, 0                  # 40009fbb
	s32i	a12, a13, 0x208         # 40009fbd
.L40009fc0:
	movi.n	a14, 1                  # 40009fc0
	s32i.n	a14, a1, 0              # 40009fc2
.L40009fc4:
	l32i.n	a2, a1, 0               # 40009fc4
	retw.n                          # 40009fc6
	.size	fn_40009f70, . - fn_40009f70
