# fn_40008e88: 0x40008e88-0x40008e9a (firmware file offset 0x38e88-0x38e9a), 8 instructions
# Address stored in the words at: 0x4000cf30
# Calls: fn_40008de4
# Other literal values: 0x3ffe5edc

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40008e88, @function
fn_40008e88:
	entry	a1, 32                  # 40008e88
	l32r	a3, lit_3ffe2234        # 40008e8b  = 0x3ffe5edc
	movi.n	a2, 1                   # 40008e8e
	s32i.n	a2, a3, 0               # 40008e90
	movi.n	a10, 0                  # 40008e92
	movi.n	a11, 0                  # 40008e94
	call8	fn_40008de4             # 40008e96
	retw.n                          # 40008e99
	.size	fn_40008e88, . - fn_40008e88
