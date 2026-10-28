# fn_40001b08: 0x40001b08-0x40001cb3 (firmware file offset 0x31b08-0x31cb3), 191 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Other literal values: 0xe0080700, 0x00038270, 0xe0091040, 0x00038400
# 1 instruction after an unconditional jump or return: no branch, jump, call or stored address leads to it.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001b08, @function
fn_40001b08:
	entry	a1, 96                  # 40001b08
	s32i.n	a2, a1, 48              # 40001b0b
	s32i.n	a3, a1, 52              # 40001b0d
	movi.n	a8, 0                   # 40001b0f
	s32i.n	a8, a1, 0               # 40001b11
	movi.n	a7, 0                   # 40001b13
	s32i.n	a7, a1, 4               # 40001b15
	l32i.n	a6, a1, 52              # 40001b17
	l32i.n	a5, a1, 4               # 40001b19
	bgeu	a5, a6, .L40001b3a      # 40001b1b
.L40001b1e:
	l32i.n	a13, a1, 0              # 40001b1e
	l32i.n	a12, a1, 4              # 40001b20
	l32i.n	a14, a1, 48             # 40001b22
	addx4	a12, a12, a14           # 40001b24
	l32i.n	a12, a12, 0             # 40001b27
	add.n	a12, a12, a13           # 40001b29
	s32i.n	a12, a1, 0              # 40001b2b
	l32i.n	a11, a1, 4              # 40001b2d
	addi.n	a11, a11, 1             # 40001b2f
	s32i.n	a11, a1, 4              # 40001b31
	l32i.n	a10, a1, 52             # 40001b33
	l32i.n	a9, a1, 4               # 40001b35
	bltu	a9, a10, .L40001b1e     # 40001b37
.L40001b3a:
	l32i.n	a4, a1, 52              # 40001b3a
	l32i.n	a3, a1, 0               # 40001b3c
	quou	a3, a3, a4              # 40001b3e
	s32i.n	a3, a1, 0               # 40001b41
	l32i.n	a2, a1, 0               # 40001b43
	movi.n	a15, 64                 # 40001b45
	bgeu	a15, a2, .L40001b9d     # 40001b47
	l32r	a8, lit_3ffe1b78        # 40001b4a  = 0xe0080700
	s32i.n	a8, a1, 8               # 40001b4d
	movi.n	a7, 0                   # 40001b4f
	s32i.n	a7, a1, 4               # 40001b51
	l32i.n	a6, a1, 4               # 40001b53
	movi.n	a5, 62                  # 40001b55
	bltu	a5, a6, .L40001b85      # 40001b57
.L40001b5a:
	l32i.n	a14, a1, 8              # 40001b5a
	l32i.n	a14, a14, 0             # 40001b5c
	s32i.n	a14, a1, 12             # 40001b5e
	l32i.n	a13, a1, 8              # 40001b60
	addi.n	a13, a13, 4             # 40001b62
	s32i.n	a13, a1, 8              # 40001b64
	l32i.n	a12, a1, 8              # 40001b66
	l32i.n	a12, a12, 0             # 40001b68
	s32i.n	a12, a1, 16             # 40001b6a
	l32i.n	a11, a1, 16             # 40001b6c
	l32i.n	a10, a1, 12             # 40001b6e
	add.n	a10, a10, a11           # 40001b70
	l32r	a9, lit_3ffe1b7c        # 40001b72  = 0x00038270
	bltu	a9, a10, .L40001b85     # 40001b75
	l32i.n	a3, a1, 4               # 40001b78
	addi.n	a3, a3, 1               # 40001b7a
	s32i.n	a3, a1, 4               # 40001b7c
	l32i.n	a2, a1, 4               # 40001b7e
	movi.n	a15, 62                 # 40001b80
	bgeu	a15, a2, .L40001b5a     # 40001b82
.L40001b85:
	l32i.n	a5, a1, 4               # 40001b85
	movi.n	a4, 62                  # 40001b87
	bgeu	a4, a5, .L40001b93      # 40001b89
	movi.n	a6, 0                   # 40001b8c
	s32i.n	a6, a1, 32              # 40001b8e
	j	.L40001cb0              # 40001b90
.L40001b93:
	movi.n	a7, 1                   # 40001b93
	s32i.n	a7, a1, 32              # 40001b95
	j	.L40001cb0              # 40001b97
	j	.L40001cb0              # 40001b9a
.L40001b9d:
	movi.n	a10, 0                  # 40001b9d
	s32i.n	a10, a1, 4              # 40001b9f
	l32i.n	a9, a1, 52              # 40001ba1
	l32i.n	a8, a1, 4               # 40001ba3
	bgeu	a8, a9, .L40001c07      # 40001ba5
.L40001ba8:
	l32i.n	a12, a1, 4              # 40001ba8
	l32i.n	a13, a1, 48             # 40001baa
	addx4	a12, a12, a13           # 40001bac
	l32i.n	a12, a12, 0             # 40001baf
	l32i.n	a11, a1, 0              # 40001bb1
	bgeu	a11, a12, .L40001bd4    # 40001bb3
	movi.n	a14, 20                 # 40001bb6
	l32i.n	a2, a1, 0               # 40001bb8
	l32i.n	a15, a1, 4              # 40001bba
	l32i.n	a3, a1, 48              # 40001bbc
	addx4	a15, a15, a3            # 40001bbe
	l32i.n	a15, a15, 0             # 40001bc1
	sub	a15, a15, a2            # 40001bc3
	movi.n	a2, 1                   # 40001bc6
	s32i.n	a2, a1, 36              # 40001bc8
	bltu	a14, a15, .L40001bd1    # 40001bca
	movi.n	a4, 0                   # 40001bcd
	s32i.n	a4, a1, 36              # 40001bcf
.L40001bd1:
	j	.L40001bef              # 40001bd1
.L40001bd4:
	movi.n	a5, 20                  # 40001bd4
	l32i.n	a7, a1, 4               # 40001bd6
	l32i.n	a8, a1, 48              # 40001bd8
	addx4	a7, a7, a8              # 40001bda
	l32i.n	a7, a7, 0               # 40001bdd
	l32i.n	a6, a1, 0               # 40001bdf
	sub	a6, a6, a7              # 40001be1
	movi.n	a7, 1                   # 40001be4
	s32i.n	a7, a1, 36              # 40001be6
	bltu	a5, a6, .L40001bef      # 40001be8
	movi.n	a9, 0                   # 40001beb
	s32i.n	a9, a1, 36              # 40001bed
.L40001bef:
	l32i.n	a10, a1, 36             # 40001bef
	beqz.n	a10, .L40001bfa         # 40001bf1
	movi.n	a11, 0                  # 40001bf3
	s32i.n	a11, a1, 32             # 40001bf5
	j	.L40001cb0              # 40001bf7
.L40001bfa:
	l32i.n	a14, a1, 4              # 40001bfa
	addi.n	a14, a14, 1             # 40001bfc
	s32i.n	a14, a1, 4              # 40001bfe
	l32i.n	a13, a1, 52             # 40001c00
	l32i.n	a12, a1, 4              # 40001c02
	bltu	a12, a13, .L40001ba8    # 40001c04
.L40001c07:
	l32r	a6, lit_3ffe1b80        # 40001c07  = 0xe0091040
	memw                            # 40001c0a
	l32i.n	a6, a6, 0               # 40001c0d
	s32i.n	a6, a1, 20              # 40001c0f
	l32i.n	a5, a1, 20              # 40001c11
	s32i.n	a5, a1, 24              # 40001c13
	l32i.n	a4, a1, 24              # 40001c15
	extui	a4, a4, 0, 16           # 40001c17
	s32i.n	a4, a1, 24              # 40001c1a
	l32i.n	a3, a1, 20              # 40001c1c
	extui	a3, a3, 16, 16          # 40001c1e
	s32i.n	a3, a1, 20              # 40001c21
	l32i.n	a2, a1, 24              # 40001c23
	l32i.n	a15, a1, 20             # 40001c25
	bgeu	a15, a2, .L40001c41     # 40001c27
	movi.n	a7, 4                   # 40001c2a
	l32i.n	a9, a1, 20              # 40001c2c
	l32i.n	a8, a1, 24              # 40001c2e
	sub	a8, a8, a9              # 40001c30
	movi.n	a9, 1                   # 40001c33
	s32i.n	a9, a1, 40              # 40001c35
	bltu	a7, a8, .L40001c3e      # 40001c37
	movi.n	a10, 0                  # 40001c3a
	s32i.n	a10, a1, 40             # 40001c3c
.L40001c3e:
	j	.L40001c55              # 40001c3e
.L40001c41:
	movi.n	a11, 4                  # 40001c41
	l32i.n	a13, a1, 24             # 40001c43
	l32i.n	a12, a1, 20             # 40001c45
	sub	a12, a12, a13           # 40001c47
	movi.n	a13, 1                  # 40001c4a
	s32i.n	a13, a1, 40             # 40001c4c
	bltu	a11, a12, .L40001c55    # 40001c4e
	movi.n	a14, 0                  # 40001c51
	s32i.n	a14, a1, 40             # 40001c53
.L40001c55:
	l32i.n	a15, a1, 40             # 40001c55
	beqz.n	a15, .L40001c60         # 40001c57
	movi.n	a2, 0                   # 40001c59
	s32i.n	a2, a1, 32              # 40001c5b
	j	.L40001cb0              # 40001c5d
.L40001c60:
	l32r	a6, lit_3ffe1b78        # 40001c60  = 0xe0080700
	s32i.n	a6, a1, 28              # 40001c63
	movi.n	a5, 0                   # 40001c65
	s32i.n	a5, a1, 4               # 40001c67
	l32i.n	a4, a1, 4               # 40001c69
	movi.n	a3, 62                  # 40001c6b
	bltu	a3, a4, .L40001c9b      # 40001c6d
.L40001c70:
	l32i.n	a12, a1, 28             # 40001c70
	l32i.n	a12, a12, 0             # 40001c72
	s32i.n	a12, a1, 12             # 40001c74
	l32i.n	a11, a1, 28             # 40001c76
	addi.n	a11, a11, 4             # 40001c78
	s32i.n	a11, a1, 28             # 40001c7a
	l32i.n	a10, a1, 28             # 40001c7c
	l32i.n	a10, a10, 0             # 40001c7e
	s32i.n	a10, a1, 16             # 40001c80
	l32r	a8, lit_3ffe1b84        # 40001c82  = 0x00038400
	l32i.n	a9, a1, 16              # 40001c85
	l32i.n	a7, a1, 12              # 40001c87
	add.n	a7, a7, a9              # 40001c89
	beq	a7, a8, .L40001c9b      # 40001c8b
	l32i.n	a15, a1, 4              # 40001c8e
	addi.n	a15, a15, 1             # 40001c90
	s32i.n	a15, a1, 4              # 40001c92
	l32i.n	a14, a1, 4              # 40001c94
	movi.n	a13, 62                 # 40001c96
	bgeu	a13, a14, .L40001c70    # 40001c98
.L40001c9b:
	l32i.n	a3, a1, 4               # 40001c9b
	movi.n	a2, 62                  # 40001c9d
	bgeu	a2, a3, .L40001ca9      # 40001c9f
	movi.n	a4, 0                   # 40001ca2
	s32i.n	a4, a1, 32              # 40001ca4
	j	.L40001cb0              # 40001ca6
.L40001ca9:
	movi.n	a5, 1                   # 40001ca9
	s32i.n	a5, a1, 32              # 40001cab
	j	.L40001cb0              # 40001cad
.L40001cb0:
	l32i.n	a2, a1, 32              # 40001cb0
	retw.n                          # 40001cb2
	.size	fn_40001b08, . - fn_40001b08
