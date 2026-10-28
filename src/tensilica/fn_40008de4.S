# fn_40008de4: 0x40008de4-0x40008e87 (firmware file offset 0x38de4-0x38e87), 67 instructions
# Called from: fn_40008e88, fn_40008ef0
# Other literal values: 0xe00a1008, 0xe00a1020, 0xe00a1024, 0xe00a1070

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40008de4, @function
fn_40008de4:
	entry	a1, 64                  # 40008de4
	s32i.n	a2, a1, 16              # 40008de7
	s32i.n	a3, a1, 20              # 40008de9
	movi.n	a7, 0                   # 40008deb
	s32i.n	a7, a1, 0               # 40008ded
	l32i.n	a6, a1, 16              # 40008def
	movi.n	a5, 1                   # 40008df1
	bltu	a5, a6, .L40008e03      # 40008df3
	l32i.n	a8, a1, 16              # 40008df6
	l32r	a9, lit_3ffe2228        # 40008df8  = 0xe00a1008
	addx4	a8, a8, a9              # 40008dfb
	s32i.n	a8, a1, 0               # 40008dfe
	j	.L40008e53              # 40008e00
.L40008e03:
	l32i.n	a9, a1, 16              # 40008e03
	addi	a9, a9, -3              # 40008e05
	bgeui	a9, 4, .L40008e1a       # 40008e08
	l32i.n	a10, a1, 16             # 40008e0b
	addi.n	a10, a10, -1            # 40008e0d
	l32r	a11, lit_3ffe2228       # 40008e0f  = 0xe00a1008
	addx4	a10, a10, a11           # 40008e12
	s32i.n	a10, a1, 0              # 40008e15
	j	.L40008e53              # 40008e17
.L40008e1a:
	movi.n	a12, 9                  # 40008e1a
	l32i.n	a11, a1, 16             # 40008e1c
	bne	a11, a12, .L40008e3f    # 40008e1e
	l32i.n	a13, a1, 20             # 40008e21
	movi.n	a12, 15                 # 40008e23
	bltu	a12, a13, .L40008e30    # 40008e25
	l32r	a14, lit_3ffe222c       # 40008e28  = 0xe00a1020
	s32i.n	a14, a1, 0              # 40008e2b
	j	.L40008e3c              # 40008e2d
.L40008e30:
	l32r	a2, lit_3ffe2230        # 40008e30  = 0xe00a1024
	s32i.n	a2, a1, 0               # 40008e33
	l32i.n	a15, a1, 20             # 40008e35
	addi	a15, a15, -16           # 40008e37
	s32i.n	a15, a1, 20             # 40008e3a
.L40008e3c:
	j	.L40008e53              # 40008e3c
.L40008e3f:
	l32i.n	a4, a1, 16              # 40008e3f
	movi.n	a3, 9                   # 40008e41
	bgeu	a3, a4, .L40008e53      # 40008e43
	l32i.n	a5, a1, 16              # 40008e46
	addi	a5, a5, -9              # 40008e48
	l32r	a6, lit_3ffe2230        # 40008e4b  = 0xe00a1024
	addx4	a5, a5, a6              # 40008e4e
	s32i.n	a5, a1, 0               # 40008e51
.L40008e53:
	movi.n	a7, 0                   # 40008e53
	l32i.n	a6, a1, 0               # 40008e55
	beq	a6, a7, .L40008e74      # 40008e57
	l32i.n	a11, a1, 0              # 40008e5a
	movi.n	a10, 1                  # 40008e5c
	l32i.n	a12, a1, 20             # 40008e5e
	ssl	a12                     # 40008e60
	sll	a10, a10                # 40008e63
	memw                            # 40008e66
	s32i.n	a10, a11, 48            # 40008e69
	l32i.n	a9, a1, 0               # 40008e6b
	movi.n	a8, 0                   # 40008e6d
	memw                            # 40008e6f
	s32i.n	a8, a9, 48              # 40008e72
.L40008e74:
	l32r	a14, lit_3ffe2220       # 40008e74  = 0xe00a1070
	movi.n	a13, 1                  # 40008e77
	l32i.n	a15, a1, 16             # 40008e79
	ssl	a15                     # 40008e7b
	sll	a13, a13                # 40008e7e
	memw                            # 40008e81
	s32i.n	a13, a14, 0             # 40008e84
	retw.n                          # 40008e86
	.size	fn_40008de4, . - fn_40008de4
