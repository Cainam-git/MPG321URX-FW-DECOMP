# fn_40009bc8: 0x40009bc8-0x40009ca5 (firmware file offset 0x39bc8-0x39ca5), 93 instructions
# Called from: fn_40009ca8
# Other literal values: 0xe00a000c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40009bc8, @function
fn_40009bc8:
	entry	a1, 64                  # 40009bc8
	s32i.n	a2, a1, 16              # 40009bcb
	movi.n	a7, 0                   # 40009bcd
	s32i.n	a7, a1, 0               # 40009bcf
	l32i.n	a6, a1, 16              # 40009bd1
	l32i.n	a6, a6, 4               # 40009bd3
	s32i.n	a6, a1, 4               # 40009bd5
	movi.n	a5, 0                   # 40009bd7
	l32i.n	a4, a1, 4               # 40009bd9
	beq	a4, a5, .L40009bf0      # 40009bdb
	l32i.n	a8, a1, 4               # 40009bde
	beqi	a8, 1, .L40009bf7       # 40009be0
	l32i.n	a9, a1, 4               # 40009be3
	beqi	a9, 2, .L40009c03       # 40009be5
	l32i.n	a10, a1, 4              # 40009be8
	beqi	a10, 3, .L40009c0f      # 40009bea
	j	.L40009c0f              # 40009bed
.L40009bf0:
	l32i.n	a11, a1, 0              # 40009bf0
	s32i.n	a11, a1, 0              # 40009bf2
	j	.L40009c1b              # 40009bf4
.L40009bf7:
	movi.n	a13, 1                  # 40009bf7
	l32i.n	a12, a1, 0              # 40009bf9
	or	a12, a12, a13           # 40009bfb
	s32i.n	a12, a1, 0              # 40009bfe
	j	.L40009c1b              # 40009c00
.L40009c03:
	movi.n	a15, 2                  # 40009c03
	l32i.n	a14, a1, 0              # 40009c05
	or	a14, a14, a15           # 40009c07
	s32i.n	a14, a1, 0              # 40009c0a
	j	.L40009c1b              # 40009c0c
.L40009c0f:
	movi.n	a3, 3                   # 40009c0f
	l32i.n	a2, a1, 0               # 40009c11
	or	a2, a2, a3              # 40009c13
	s32i.n	a2, a1, 0               # 40009c16
	j	.L40009c1b              # 40009c18
.L40009c1b:
	l32i.n	a5, a1, 16              # 40009c1b
	l32i.n	a5, a5, 8               # 40009c1d
	s32i.n	a5, a1, 8               # 40009c1f
	l32i.n	a4, a1, 8               # 40009c21
	beqi	a4, 1, .L40009c3f       # 40009c23
	l32i.n	a6, a1, 8               # 40009c26
	beqi	a6, 2, .L40009c4b       # 40009c28
	l32i.n	a7, a1, 8               # 40009c2b
	beqi	a7, 3, .L40009c57       # 40009c2d
	l32i.n	a8, a1, 8               # 40009c30
	beqi	a8, 4, .L40009c63       # 40009c32
	movi.n	a10, 0                  # 40009c35
	l32i.n	a9, a1, 8               # 40009c37
	beq	a9, a10, .L40009c6f     # 40009c39
	j	.L40009c6f              # 40009c3c
.L40009c3f:
	movi.n	a12, 8                  # 40009c3f
	l32i.n	a11, a1, 0              # 40009c41
	or	a11, a11, a12           # 40009c43
	s32i.n	a11, a1, 0              # 40009c46
	j	.L40009c72              # 40009c48
.L40009c4b:
	movi.n	a14, 24                 # 40009c4b
	l32i.n	a13, a1, 0              # 40009c4d
	or	a13, a13, a14           # 40009c4f
	s32i.n	a13, a1, 0              # 40009c52
	j	.L40009c72              # 40009c54
.L40009c57:
	movi.n	a2, 40                  # 40009c57
	l32i.n	a15, a1, 0              # 40009c59
	or	a15, a15, a2            # 40009c5b
	s32i.n	a15, a1, 0              # 40009c5e
	j	.L40009c72              # 40009c60
.L40009c63:
	movi.n	a4, 56                  # 40009c63
	l32i.n	a3, a1, 0               # 40009c65
	or	a3, a3, a4              # 40009c67
	s32i.n	a3, a1, 0               # 40009c6a
	j	.L40009c72              # 40009c6c
.L40009c6f:
	j	.L40009c72              # 40009c6f
.L40009c72:
	l32i.n	a6, a1, 16              # 40009c72
	l32i.n	a6, a6, 12              # 40009c74
	s32i.n	a6, a1, 12              # 40009c76
	l32i.n	a5, a1, 12              # 40009c78
	beqi	a5, 1, .L40009c87       # 40009c7a
	movi.n	a8, 0                   # 40009c7d
	l32i.n	a7, a1, 12              # 40009c7f
	beq	a7, a8, .L40009c8e      # 40009c81
	j	.L40009c8e              # 40009c84
.L40009c87:
	l32i.n	a9, a1, 0               # 40009c87
	s32i.n	a9, a1, 0               # 40009c89
	j	.L40009c9a              # 40009c8b
.L40009c8e:
	movi.n	a11, 4                  # 40009c8e
	l32i.n	a10, a1, 0              # 40009c90
	or	a10, a10, a11           # 40009c92
	s32i.n	a10, a1, 0              # 40009c95
	j	.L40009c9a              # 40009c97
.L40009c9a:
	l32r	a13, lit_3ffe22fc       # 40009c9a  = 0xe00a000c
	l32i.n	a12, a1, 0              # 40009c9d
	memw                            # 40009c9f
	s32i.n	a12, a13, 0             # 40009ca2
	retw.n                          # 40009ca4
	.size	fn_40009bc8, . - fn_40009bc8
