# fn_40001cb4: 0x40001cb4-0x40001dd7 (firmware file offset 0x31cb4-0x31dd7), 118 instructions
# Called from: fn_400030b4
# Addresses loaded: data_3ffe2760, data_3ffe2574
# Other literal values: 0x3ffe4490

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001cb4, @function
fn_40001cb4:
	entry	a1, 48                  # 40001cb4
	movi.n	a7, 0                   # 40001cb7
	s32i.n	a7, a1, 0               # 40001cb9
	movi.n	a6, 0                   # 40001cbb
	s32i.n	a6, a1, 4               # 40001cbd
	movi.n	a5, 0                   # 40001cbf
	s32i.n	a5, a1, 8               # 40001cc1
	movi.n	a4, 0                   # 40001cc3
	s32i.n	a4, a1, 0               # 40001cc5
	l32r	a3, lit_3ffe1a88        # 40001cc7  = data_3ffe2760
	l32i.n	a3, a3, 0               # 40001cca
	l32i.n	a2, a1, 0               # 40001ccc
	bltu	a2, a3, .L40001cd4      # 40001cce
	j	.L40001d90              # 40001cd1
.L40001cd4:
	l32r	a9, lit_3ffe1a88        # 40001cd4  = data_3ffe2760
	l32i.n	a9, a9, 0               # 40001cd7
	l32i.n	a8, a1, 0               # 40001cd9
	addi	a8, a8, 17              # 40001cdb
	remu	a8, a8, a9              # 40001cde
	l32i.n	a9, a1, 0               # 40001ce1
	l32r	a10, lit_3ffe1b88       # 40001ce3  = 0x3ffe4490
	addx2	a9, a9, a10             # 40001ce6
	l16ui	a9, a9, 0               # 40001ce9
	l32r	a10, lit_3ffe1b88       # 40001cec  = 0x3ffe4490
	addx2	a8, a8, a10             # 40001cef
	l16ui	a8, a8, 0               # 40001cf2
	bgeu	a8, a9, .L40001d2c      # 40001cf5
	l32r	a13, lit_3ffe1a88       # 40001cf8  = data_3ffe2760
	l32i.n	a13, a13, 0             # 40001cfb
	l32i.n	a12, a1, 0              # 40001cfd
	addi	a12, a12, 17            # 40001cff
	remu	a12, a12, a13           # 40001d02
	movi.n	a10, 4                  # 40001d05
	l32r	a13, lit_3ffe1b88       # 40001d07  = 0x3ffe4490
	addx2	a12, a12, a13           # 40001d0a
	l16ui	a12, a12, 0             # 40001d0d
	l32i.n	a11, a1, 0              # 40001d10
	l32r	a13, lit_3ffe1b88       # 40001d12  = 0x3ffe4490
	addx2	a11, a11, a13           # 40001d15
	l16ui	a11, a11, 0             # 40001d18
	sub	a11, a11, a12           # 40001d1b
	movi.n	a12, 1                  # 40001d1e
	s32i.n	a12, a1, 12             # 40001d20
	blt	a10, a11, .L40001d29    # 40001d22
	movi.n	a14, 0                  # 40001d25
	s32i.n	a14, a1, 12             # 40001d27
.L40001d29:
	j	.L40001d5d              # 40001d29
.L40001d2c:
	l32r	a3, lit_3ffe1a88        # 40001d2c  = data_3ffe2760
	l32i.n	a3, a3, 0               # 40001d2f
	l32i.n	a2, a1, 0               # 40001d31
	addi	a2, a2, 17              # 40001d33
	remu	a2, a2, a3              # 40001d36
	movi.n	a15, 4                  # 40001d39
	l32i.n	a3, a1, 0               # 40001d3b
	l32r	a4, lit_3ffe1b88        # 40001d3d  = 0x3ffe4490
	addx2	a3, a3, a4              # 40001d40
	l16ui	a3, a3, 0               # 40001d43
	l32r	a4, lit_3ffe1b88        # 40001d46  = 0x3ffe4490
	addx2	a2, a2, a4              # 40001d49
	l16ui	a2, a2, 0               # 40001d4c
	sub	a2, a2, a3              # 40001d4f
	movi.n	a3, 1                   # 40001d52
	s32i.n	a3, a1, 12              # 40001d54
	blt	a15, a2, .L40001d5d     # 40001d56
	movi.n	a4, 0                   # 40001d59
	s32i.n	a4, a1, 12              # 40001d5b
.L40001d5d:
	l32i.n	a5, a1, 12              # 40001d5d
	beqz.n	a5, .L40001d67          # 40001d5f
	l32i.n	a6, a1, 4               # 40001d61
	addi.n	a6, a6, 1               # 40001d63
	s32i.n	a6, a1, 4               # 40001d65
.L40001d67:
	movi.n	a8, 0                   # 40001d67
	l32i.n	a7, a1, 0               # 40001d69
	l32r	a9, lit_3ffe1b88        # 40001d6b  = 0x3ffe4490
	addx2	a7, a7, a9              # 40001d6e
	l16ui	a7, a7, 0               # 40001d71
	bne	a7, a8, .L40001d7d      # 40001d74
	l32i.n	a10, a1, 8              # 40001d77
	addi.n	a10, a10, 1             # 40001d79
	s32i.n	a10, a1, 8              # 40001d7b
.L40001d7d:
	l32i.n	a13, a1, 0              # 40001d7d
	addi.n	a13, a13, 1             # 40001d7f
	s32i.n	a13, a1, 0              # 40001d81
	l32r	a12, lit_3ffe1a88       # 40001d83  = data_3ffe2760
	l32i.n	a12, a12, 0             # 40001d86
	l32i.n	a11, a1, 0              # 40001d88
	bgeu	a11, a12, .L40001d90    # 40001d8a
	j	.L40001cd4              # 40001d8d
.L40001d90:
	l32i.n	a15, a1, 4              # 40001d90
	movi.n	a14, 31                 # 40001d92
	bltu	a14, a15, .L40001da1    # 40001d94
	l32r	a3, lit_3ffe1b8c        # 40001d97  = data_3ffe2574
	movi.n	a2, 1                   # 40001d9a
	s32i.n	a2, a3, 0               # 40001d9c
	j	.L40001daf              # 40001d9e
.L40001da1:
	l32i.n	a5, a1, 4               # 40001da1
	movi.n	a4, 40                  # 40001da3
	bgeu	a4, a5, .L40001daf      # 40001da5
	l32r	a7, lit_3ffe1b8c        # 40001da8  = data_3ffe2574
	movi.n	a6, 0                   # 40001dab
	s32i.n	a6, a7, 0               # 40001dad
.L40001daf:
	l32r	a8, lit_3ffe1b8c        # 40001daf  = data_3ffe2574
	l32i.n	a8, a8, 0               # 40001db2
	bnei	a8, 1, .L40001dd1       # 40001db4
	l32i.n	a10, a1, 8              # 40001db7
	movi.n	a9, 0                   # 40001db9
	bgeu	a9, a10, .L40001dd1     # 40001dbb
	l32r	a12, lit_3ffe1a88       # 40001dbe  = data_3ffe2760
	l32i.n	a12, a12, 0             # 40001dc1
	addi.n	a12, a12, -1            # 40001dc3
	l32i.n	a11, a1, 8              # 40001dc5
	bgeu	a11, a12, .L40001dd1    # 40001dc7
	l32r	a14, lit_3ffe1b8c       # 40001dca  = data_3ffe2574
	movi.n	a13, 0                  # 40001dcd
	s32i.n	a13, a14, 0             # 40001dcf
.L40001dd1:
	l32r	a2, lit_3ffe1b8c        # 40001dd1  = data_3ffe2574
	l32i.n	a2, a2, 0               # 40001dd4
	retw.n                          # 40001dd6
	.size	fn_40001cb4, . - fn_40001cb4
