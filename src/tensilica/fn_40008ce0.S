# fn_40008ce0: 0x40008ce0-0x40008de0 (firmware file offset 0x38ce0-0x38de0), 105 instructions
# Called from: fn_40008e9c, fn_40008f58
# Other literal values: 0xe00a1008, 0xe00a1020, 0xe00a1024

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40008ce0, @function
fn_40008ce0:
	entry	a1, 64                  # 40008ce0
	s32i.n	a2, a1, 16              # 40008ce3
	s32i.n	a3, a1, 20              # 40008ce5
	s32i.n	a4, a1, 24              # 40008ce7
	movi.n	a9, 0                   # 40008ce9
	s32i.n	a9, a1, 0               # 40008ceb
	l32i.n	a8, a1, 16              # 40008ced
	movi.n	a7, 1                   # 40008cef
	bltu	a7, a8, .L40008d01      # 40008cf1
	l32i.n	a10, a1, 16             # 40008cf4
	l32r	a11, lit_3ffe2228       # 40008cf6  = 0xe00a1008
	addx4	a10, a10, a11           # 40008cf9
	s32i.n	a10, a1, 0              # 40008cfc
	j	.L40008d51              # 40008cfe
.L40008d01:
	l32i.n	a11, a1, 16             # 40008d01
	addi	a11, a11, -3            # 40008d03
	bgeui	a11, 4, .L40008d18      # 40008d06
	l32i.n	a12, a1, 16             # 40008d09
	addi.n	a12, a12, -1            # 40008d0b
	l32r	a13, lit_3ffe2228       # 40008d0d  = 0xe00a1008
	addx4	a12, a12, a13           # 40008d10
	s32i.n	a12, a1, 0              # 40008d13
	j	.L40008d51              # 40008d15
.L40008d18:
	movi.n	a14, 9                  # 40008d18
	l32i.n	a13, a1, 16             # 40008d1a
	bne	a13, a14, .L40008d3d    # 40008d1c
	l32i.n	a15, a1, 20             # 40008d1f
	movi.n	a14, 15                 # 40008d21
	bltu	a14, a15, .L40008d2e    # 40008d23
	l32r	a2, lit_3ffe222c        # 40008d26  = 0xe00a1020
	s32i.n	a2, a1, 0               # 40008d29
	j	.L40008d3a              # 40008d2b
.L40008d2e:
	l32r	a4, lit_3ffe2230        # 40008d2e  = 0xe00a1024
	s32i.n	a4, a1, 0               # 40008d31
	l32i.n	a3, a1, 20              # 40008d33
	addi	a3, a3, -16             # 40008d35
	s32i.n	a3, a1, 20              # 40008d38
.L40008d3a:
	j	.L40008d51              # 40008d3a
.L40008d3d:
	l32i.n	a6, a1, 16              # 40008d3d
	movi.n	a5, 9                   # 40008d3f
	bgeu	a5, a6, .L40008d51      # 40008d41
	l32i.n	a7, a1, 16              # 40008d44
	addi	a7, a7, -9              # 40008d46
	l32r	a8, lit_3ffe2230        # 40008d49  = 0xe00a1024
	addx4	a7, a7, a8              # 40008d4c
	s32i.n	a7, a1, 0               # 40008d4f
.L40008d51:
	movi.n	a9, 0                   # 40008d51
	l32i.n	a8, a1, 0               # 40008d53
	bne	a8, a9, .L40008d5b      # 40008d55
	j	.L40008ddf              # 40008d58
.L40008d5b:
	l32i.n	a14, a1, 0              # 40008d5b
	movi.n	a13, 1                  # 40008d5d
	l32i.n	a15, a1, 20             # 40008d5f
	ssl	a15                     # 40008d61
	sll	a13, a13                # 40008d64
	memw                            # 40008d67
	s32i.n	a13, a14, 48            # 40008d6a
	l32i.n	a12, a1, 0              # 40008d6c
	movi.n	a11, 0                  # 40008d6e
	memw                            # 40008d70
	s32i.n	a11, a12, 48            # 40008d73
	movi.n	a11, 0                  # 40008d75
	l32i.n	a10, a1, 24             # 40008d77
	beq	a10, a11, .L40008d98    # 40008d79
	movi.n	a3, 1                   # 40008d7c
	l32i.n	a4, a1, 20              # 40008d7e
	addi	a4, a4, 16              # 40008d80
	ssl	a4                      # 40008d83
	sll	a3, a3                  # 40008d86
	l32i.n	a2, a1, 0               # 40008d89
	memw                            # 40008d8b
	l32i.n	a2, a2, 0               # 40008d8e
	or	a2, a2, a3              # 40008d90
	s32i.n	a2, a1, 4               # 40008d93
	j	.L40008db6              # 40008d95
.L40008d98:
	movi.n	a7, -1                  # 40008d98
	movi.n	a6, 1                   # 40008d9a
	l32i.n	a8, a1, 20              # 40008d9c
	addi	a8, a8, 16              # 40008d9e
	ssl	a8                      # 40008da1
	sll	a6, a6                  # 40008da4
	xor	a6, a6, a7              # 40008da7
	l32i.n	a5, a1, 0               # 40008daa
	memw                            # 40008dac
	l32i.n	a5, a5, 0               # 40008daf
	and	a5, a5, a6              # 40008db1
	s32i.n	a5, a1, 4               # 40008db4
.L40008db6:
	l32i.n	a15, a1, 0              # 40008db6
	memw                            # 40008db8
	l32i.n	a14, a1, 4              # 40008dbb
	s32i.n	a14, a15, 0             # 40008dbd
	l32i.n	a10, a1, 0              # 40008dbf
	movi.n	a12, -1                 # 40008dc1
	movi.n	a11, 1                  # 40008dc3
	l32i.n	a13, a1, 20             # 40008dc5
	ssl	a13                     # 40008dc7
	sll	a11, a11                # 40008dca
	xor	a11, a11, a12           # 40008dcd
	l32i.n	a9, a1, 0               # 40008dd0
	memw                            # 40008dd2
	l32i.n	a9, a9, 0               # 40008dd5
	and	a9, a9, a11             # 40008dd7
	memw                            # 40008dda
	s32i.n	a9, a10, 0              # 40008ddd
.L40008ddf:
	retw.n                          # 40008ddf
	.size	fn_40008ce0, . - fn_40008ce0
