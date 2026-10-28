# fn_40002de0: 0x40002de0-0x40002e74 (firmware file offset 0x32de0-0x32e74), 62 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Addresses loaded: data_3ffe2760
# Other literal values: 0x3ffe4490, 0x3ffe2d70

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40002de0, @function
fn_40002de0:
	entry	a1, 64                  # 40002de0
	s32i.n	a2, a1, 16              # 40002de3
	s32i.n	a3, a1, 20              # 40002de5
	s32i.n	a4, a1, 24              # 40002de7
	movi.n	a10, 0                  # 40002de9
	s32i.n	a10, a1, 0              # 40002deb
	l32i.n	a9, a1, 24              # 40002ded
	s32i.n	a9, a1, 4               # 40002def
	movi.n	a8, 0                   # 40002df1
	l32i.n	a7, a1, 4               # 40002df3
	beq	a7, a8, .L40002e00      # 40002df5
	l32i.n	a11, a1, 4              # 40002df8
	beqi	a11, 1, .L40002e36      # 40002dfa
	j	.L40002e00              # 40002dfd
.L40002e00:
	movi.n	a14, 0                  # 40002e00
	s32i.n	a14, a1, 0              # 40002e02
	l32r	a13, lit_3ffe1a88       # 40002e04  = data_3ffe2760
	l32i.n	a13, a13, 0             # 40002e07
	l32i.n	a12, a1, 0              # 40002e09
	bgeu	a12, a13, .L40002e33    # 40002e0b
.L40002e0e:
	l32i.n	a5, a1, 0               # 40002e0e
	l32i.n	a6, a1, 20              # 40002e10
	addx2	a5, a5, a6              # 40002e12
	l32i.n	a4, a1, 0               # 40002e15
	l32r	a6, lit_3ffe1b88        # 40002e17  = 0x3ffe4490
	addx2	a4, a4, a6              # 40002e1a
	l16ui	a4, a4, 0               # 40002e1d
	s16i	a4, a5, 0               # 40002e20
	l32i.n	a3, a1, 0               # 40002e23
	addi.n	a3, a3, 1               # 40002e25
	s32i.n	a3, a1, 0               # 40002e27
	l32r	a2, lit_3ffe1a88        # 40002e29  = data_3ffe2760
	l32i.n	a2, a2, 0               # 40002e2c
	l32i.n	a15, a1, 0              # 40002e2e
	bltu	a15, a2, .L40002e0e     # 40002e30
.L40002e33:
	j	.L40002e73              # 40002e33
.L40002e36:
	movi.n	a9, 0                   # 40002e36
	s32i.n	a9, a1, 0               # 40002e38
	l32r	a8, lit_3ffe1a88        # 40002e3a  = data_3ffe2760
	l32i.n	a8, a8, 0               # 40002e3d
	l32i.n	a7, a1, 0               # 40002e3f
	bgeu	a7, a8, .L40002e70      # 40002e41
.L40002e44:
	l32i.n	a13, a1, 0              # 40002e44
	l32r	a14, lit_3ffe1a8c       # 40002e46  = 0x3ffe2d70
	addx2	a13, a13, a14           # 40002e49
	l16ui	a13, a13, 0             # 40002e4c
	l32i.n	a14, a1, 0              # 40002e4f
	l32i.n	a15, a1, 20             # 40002e51
	addx2	a14, a14, a15           # 40002e53
	l32i.n	a15, a1, 16             # 40002e56
	addx4	a13, a13, a15           # 40002e58
	l32i.n	a13, a13, 0             # 40002e5b
	s16i	a13, a14, 0             # 40002e5d
	l32i.n	a12, a1, 0              # 40002e60
	addi.n	a12, a12, 1             # 40002e62
	s32i.n	a12, a1, 0              # 40002e64
	l32r	a11, lit_3ffe1a88       # 40002e66  = data_3ffe2760
	l32i.n	a11, a11, 0             # 40002e69
	l32i.n	a10, a1, 0              # 40002e6b
	bltu	a10, a11, .L40002e44    # 40002e6d
.L40002e70:
	j	.L40002e73              # 40002e70
.L40002e73:
	retw.n                          # 40002e73
	.size	fn_40002de0, . - fn_40002de0
