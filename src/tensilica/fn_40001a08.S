# fn_40001a08: 0x40001a08-0x40001a4b (firmware file offset 0x31a08-0x31a4b), 26 instructions
# Address stored in the words at: 0x4000d2bc
# Calls: fn_4000912c, fn_400077fc
# Addresses loaded: data_3ffe2570
# Other literal values: 0x3ffe2bf0, 0x00001388, 0x0000ffff

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001a08, @function
fn_40001a08:
	entry	a1, 48                  # 40001a08
	s32i.n	a2, a1, 0               # 40001a0b
	s32i.n	a3, a1, 4               # 40001a0d
	l32r	a5, lit_3ffe1a80        # 40001a0f  = 0x3ffe2bf0
	l32i.n	a5, a5, 24              # 40001a12
	bnei	a5, 1, .L40001a4a       # 40001a14
	l32i.n	a6, a1, 4               # 40001a17
	extui	a6, a6, 0, 1            # 40001a19
	beqz.n	a6, .L40001a45          # 40001a1c
	l32r	a7, lit_3ffe1b68        # 40001a1e  = data_3ffe2570
	l32i.n	a7, a7, 0               # 40001a21
	bnei	a7, 1, .L40001a36       # 40001a23
	l32r	a10, lit_3ffe1b6c       # 40001a26  = 0x00001388
	call8	fn_4000912c             # 40001a29
	l32r	a9, lit_3ffe1b68        # 40001a2c  = data_3ffe2570
	movi.n	a8, 0                   # 40001a2f
	s32i.n	a8, a9, 0               # 40001a31
	j	.L40001a3c              # 40001a33
.L40001a36:
	movi	a10, 0x7d0              # 40001a36
	call8	fn_4000912c             # 40001a39
.L40001a3c:
	l32r	a10, lit_3ffe1b70       # 40001a3c  = 0x0000ffff
	call8	fn_400077fc             # 40001a3f
	j	.L40001a4a              # 40001a42
.L40001a45:
	movi.n	a10, 0                  # 40001a45
	call8	fn_400077fc             # 40001a47
.L40001a4a:
	retw.n                          # 40001a4a
	.size	fn_40001a08, . - fn_40001a08
