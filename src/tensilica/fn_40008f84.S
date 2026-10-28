# fn_40008f84: 0x40008f84-0x40008fd6 (firmware file offset 0x38f84-0x38fd6), 33 instructions
# Address stored in the words at: 0x4000cf58
# Calls: fn_4000ac08, fn_4000a548, fn_4000abe4, fn_4000abdc
# Indirect calls (callx): 1
# Other literal values: 0x3ffe5598

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40008f84, @function
fn_40008f84:
	entry	a1, 48                  # 40008f84
.L40008f87:
	movi.n	a10, 0                  # 40008f87
	call8	fn_4000ac08             # 40008f89
	s32i.n	a10, a1, 0              # 40008f8c
	movi.n	a3, 0                   # 40008f8e
	l32r	a2, lit_3ffe2258        # 40008f90  = 0x3ffe5598
	l8ui	a2, a2, 0               # 40008f93
	beq	a2, a3, .L40008fa1      # 40008f96
	movi.n	a10, 64                 # 40008f99
	call8	fn_4000a548             # 40008f9b
	j	.L40008faf              # 40008f9e
.L40008fa1:
	movi.n	a10, 0                  # 40008fa1
	l32i.n	a12, a1, 0              # 40008fa3
	l32r	a11, lit_3ffe2258       # 40008fa5  = 0x3ffe5598
	l32i.n	a11, a11, 4             # 40008fa8
	add.n	a11, a11, a12           # 40008faa
	call8	fn_4000abe4             # 40008fac
.L40008faf:
	movi.n	a13, 0                  # 40008faf
	l32r	a12, lit_3ffe2258       # 40008fb1  = 0x3ffe5598
	l32i.n	a12, a12, 8             # 40008fb4
	beq	a12, a13, .L40008fc1    # 40008fb6
	l32r	a8, lit_3ffe2258        # 40008fb9  = 0x3ffe5598
	l32i.n	a8, a8, 8               # 40008fbc
	callx8	a8                      # 40008fbe
.L40008fc1:
	call8	fn_4000abdc             # 40008fc1
	l32i.n	a11, a1, 0              # 40008fc4
	sub	a10, a10, a11           # 40008fc6
	s32i.n	a10, a1, 4              # 40008fc9
	l32i.n	a10, a1, 4              # 40008fcb
	l32r	a9, lit_3ffe2258        # 40008fcd  = 0x3ffe5598
	l32i.n	a9, a9, 4               # 40008fd0
	bltu	a9, a10, .L40008f87     # 40008fd2
	retw.n                          # 40008fd5
	.size	fn_40008f84, . - fn_40008f84
