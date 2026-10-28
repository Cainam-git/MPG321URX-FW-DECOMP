# fn_40004dfc: 0x40004dfc-0x40004e9f (firmware file offset 0x34dfc-0x34e9f), 68 instructions
# Called from: fn_40004fc0
# Calls: fn_40004788, fn_400099bc, fn_40004c14
# Indirect calls (callx): 1
# Text loaded: "mem"
# Addresses loaded: ro_3ffe08e8

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40004dfc, @function
fn_40004dfc:
	entry	a1, 80                  # 40004dfc
	s32i.n	a2, a1, 32              # 40004dff
	movi.n	a7, 10                  # 40004e01
	s32i.n	a7, a1, 0               # 40004e03
	movi.n	a6, 0                   # 40004e05
	s32i.n	a6, a1, 4               # 40004e07
	l32i.n	a5, a1, 0               # 40004e09
	l32i.n	a4, a1, 4               # 40004e0b
	blt	a4, a5, .L40004e13      # 40004e0d
	j	.L40004e98              # 40004e10
.L40004e13:
	l32i.n	a10, a1, 4              # 40004e13
	l32i.n	a11, a1, 4              # 40004e15
	addx8	a10, a10, a11           # 40004e17
	l32r	a11, lit_3ffe1d68       # 40004e1a  = ro_3ffe0630 "mem"
	addx4	a10, a10, a11           # 40004e1d
	l32i.n	a11, a1, 32             # 40004e20
	call8	fn_40004788             # 40004e22
	movi.n	a12, 0                  # 40004e25
	bne	a10, a12, .L40004e88    # 40004e27
	l32r	a10, lit_3ffe1d6c       # 40004e2a  = ro_3ffe08e8
	call8	fn_400099bc             # 40004e2d
	movi.n	a14, 0                  # 40004e30
	l32i.n	a13, a1, 4              # 40004e32
	l32i.n	a15, a1, 4              # 40004e34
	addx8	a13, a13, a15           # 40004e36
	l32r	a15, lit_3ffe1d68       # 40004e39  = ro_3ffe0630 "mem"
	addx4	a13, a13, a15           # 40004e3c
	l32i.n	a13, a13, 32            # 40004e3f
	bne	a13, a14, .L40004e4b    # 40004e41
	movi.n	a2, -1                  # 40004e44
	s32i.n	a2, a1, 20              # 40004e46
	j	.L40004e9c              # 40004e48
.L40004e4b:
	l32i.n	a10, a1, 32             # 40004e4b
	addi	a10, a10, 32            # 40004e4d
	call8	fn_40004c14             # 40004e50
	s32i.n	a10, a1, 8              # 40004e53
	l32i.n	a10, a1, 32             # 40004e55
	addi	a10, a10, 64            # 40004e57
	call8	fn_40004c14             # 40004e5a
	s32i.n	a10, a1, 12             # 40004e5d
	l32i.n	a10, a1, 32             # 40004e5f
	addi	a10, a10, 96            # 40004e61
	call8	fn_40004c14             # 40004e64
	s32i.n	a10, a1, 16             # 40004e67
	l32i.n	a10, a1, 8              # 40004e69
	l32i.n	a11, a1, 12             # 40004e6b
	l32i.n	a12, a1, 16             # 40004e6d
	l32i.n	a8, a1, 4               # 40004e6f
	l32i.n	a9, a1, 4               # 40004e71
	addx8	a8, a8, a9              # 40004e73
	l32r	a9, lit_3ffe1d68        # 40004e76  = ro_3ffe0630 "mem"
	addx4	a8, a8, a9              # 40004e79
	l32i.n	a8, a8, 32              # 40004e7c
	callx8	a8                      # 40004e7e
	movi.n	a10, 0                  # 40004e81
	s32i.n	a10, a1, 20             # 40004e83
	j	.L40004e9c              # 40004e85
.L40004e88:
	l32i.n	a13, a1, 4              # 40004e88
	addi.n	a13, a13, 1             # 40004e8a
	s32i.n	a13, a1, 4              # 40004e8c
	l32i.n	a12, a1, 0              # 40004e8e
	l32i.n	a11, a1, 4              # 40004e90
	bge	a11, a12, .L40004e98    # 40004e92
	j	.L40004e13              # 40004e95
.L40004e98:
	movi.n	a14, -1                 # 40004e98
	s32i.n	a14, a1, 20             # 40004e9a
.L40004e9c:
	l32i.n	a2, a1, 20              # 40004e9c
	retw.n                          # 40004e9e
	.size	fn_40004dfc, . - fn_40004dfc
