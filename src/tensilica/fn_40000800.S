# fn_40000800: 0x40000800-0x40000829 (firmware file offset 0x30800-0x30829), 15 instructions
# Called with call0 from the reset code; it does not start with entry.
# Called from: reset_40000400
# Calls: fn_4000a3cc
# Other literal values: 0x3ffef000, 0x00040020, 0x3ffe2bf0, 0x3ffe6448
# Special registers: ps

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40000800, @function
fn_40000800:
	movi	a0, 0                   # 40000800
	l32r	a1, lit_3ffe1a70        # 40000803  = 0x3ffef000
	l32r	a3, lit_3ffe1a74        # 40000806  = 0x00040020
	nop.n                           # 40000809
	wsr.ps	a3                      # 4000080b
	rsync                           # 4000080e
	l32r	a6, lit_3ffe1a78        # 40000811  = 0x3ffe2bf0
	l32r	a7, lit_3ffe1a7c        # 40000814  = 0x3ffe6448
	bgeu	a6, a7, .L40000821      # 40000817
.L4000081a:
	s32i.n	a0, a6, 0               # 4000081a
	addi.n	a6, a6, 4               # 4000081c
	bltu	a6, a7, .L4000081a      # 4000081e
.L40000821:
	call4	fn_4000a3cc             # 40000821
.L40000824:
	break	1, 15                   # 40000824
	j	.L40000824              # 40000827
	.size	fn_40000800, . - fn_40000800
