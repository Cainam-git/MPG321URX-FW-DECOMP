# fn_40004b08: 0x40004b08-0x40004bc9 (firmware file offset 0x34b08-0x34bc9), 82 instructions
# Address stored in the words at: 0x4000b390
# Calls: fn_4000a010, fn_400099bc, fn_4000496c
# Text loaded: " : ", "         "
# Addresses loaded: ro_3ffe08b4, ro_3ffe08be

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40004b08, @function
fn_40004b08:
	entry	a1, 80                  # 40004b08
	s32i.n	a2, a1, 32              # 40004b0b
	s32i.n	a3, a1, 36              # 40004b0d
	s32i.n	a4, a1, 40              # 40004b0f
	movi.n	a8, 0                   # 40004b11
	l32i.n	a7, a1, 32              # 40004b13
	bne	a7, a8, .L40004b1b      # 40004b15
	j	.L40004bc8              # 40004b18
.L40004b1b:
	movi.n	a10, -4                 # 40004b1b
	l32i.n	a9, a1, 32              # 40004b1d
	and	a9, a9, a10             # 40004b1f
	s32i.n	a9, a1, 32              # 40004b22
	movi.n	a9, 0                   # 40004b24
	l32i.n	a8, a1, 36              # 40004b26
	bne	a8, a9, .L40004b2f      # 40004b28
	movi.n	a10, 32                 # 40004b2b
	s32i.n	a10, a1, 36             # 40004b2d
.L40004b2f:
	l32i.n	a6, a1, 32              # 40004b2f
	s32i.n	a6, a1, 0               # 40004b31
	l32i.n	a5, a1, 36              # 40004b33
	l32i.n	a6, a1, 0               # 40004b35
	addx4	a5, a5, a6              # 40004b37
	s32i.n	a5, a1, 4               # 40004b3a
	movi.n	a4, -32                 # 40004b3c
	l32i.n	a3, a1, 0               # 40004b3e
	and	a3, a3, a4              # 40004b40
	s32i.n	a3, a1, 8               # 40004b43
	movi.n	a3, -32                 # 40004b45
	l32i.n	a2, a1, 4               # 40004b47
	addi	a2, a2, 31              # 40004b49
	and	a2, a2, a3              # 40004b4c
	s32i.n	a2, a1, 12              # 40004b4f
	l32i.n	a15, a1, 8              # 40004b51
	s32i.n	a15, a1, 16             # 40004b53
	l32i.n	a14, a1, 8              # 40004b55
	s32i.n	a14, a1, 20             # 40004b57
	l32i.n	a13, a1, 12             # 40004b59
	l32i.n	a12, a1, 20             # 40004b5b
	bgeu	a12, a13, .L40004bc2    # 40004b5d
.L40004b60:
	l32i.n	a10, a1, 20             # 40004b60
	call8	fn_4000a010             # 40004b62
	l32r	a10, lit_3ffe1d40       # 40004b65  = ro_3ffe08a0 " : "
	call8	fn_400099bc             # 40004b68
	movi.n	a8, 0                   # 40004b6b
	s32i.n	a8, a1, 24              # 40004b6d
	l32i.n	a7, a1, 24              # 40004b6f
	bgei	a7, 4, .L40004bae       # 40004b71
.L40004b74:
	l32i.n	a10, a1, 0              # 40004b74
	l32i.n	a9, a1, 16              # 40004b76
	bltu	a9, a10, .L40004b82     # 40004b78
	l32i.n	a12, a1, 4              # 40004b7b
	l32i.n	a11, a1, 16             # 40004b7d
	bltu	a11, a12, .L40004b8b    # 40004b7f
.L40004b82:
	l32r	a10, lit_3ffe1d58       # 40004b82  = ro_3ffe08c0 "         "
	call8	fn_400099bc             # 40004b85
	j	.L40004b9d              # 40004b88
.L40004b8b:
	l32i.n	a10, a1, 16             # 40004b8b
	call8	fn_4000496c             # 40004b8d
	s32i.n	a10, a1, 28             # 40004b90
	l32i.n	a10, a1, 28             # 40004b92
	call8	fn_4000a010             # 40004b94
	l32r	a10, lit_3ffe1d48       # 40004b97  = ro_3ffe08b4
	call8	fn_400099bc             # 40004b9a
.L40004b9d:
	l32i.n	a15, a1, 16             # 40004b9d
	addi.n	a15, a15, 4             # 40004b9f
	s32i.n	a15, a1, 16             # 40004ba1
	l32i.n	a14, a1, 24             # 40004ba3
	addi.n	a14, a14, 1             # 40004ba5
	s32i.n	a14, a1, 24             # 40004ba7
	l32i.n	a13, a1, 24             # 40004ba9
	blti	a13, 4, .L40004b74      # 40004bab
.L40004bae:
	l32r	a10, lit_3ffe1d54       # 40004bae  = ro_3ffe08be
	call8	fn_400099bc             # 40004bb1
	l32i.n	a4, a1, 20              # 40004bb4
	addi	a4, a4, 16              # 40004bb6
	s32i.n	a4, a1, 20              # 40004bb9
	l32i.n	a3, a1, 12              # 40004bbb
	l32i.n	a2, a1, 20              # 40004bbd
	bltu	a2, a3, .L40004b60      # 40004bbf
.L40004bc2:
	l32r	a10, lit_3ffe1d54       # 40004bc2  = ro_3ffe08be
	call8	fn_400099bc             # 40004bc5
.L40004bc8:
	retw.n                          # 40004bc8
	.size	fn_40004b08, . - fn_40004b08
