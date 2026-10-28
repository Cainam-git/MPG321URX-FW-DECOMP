# fn_40003174: 0x40003174-0x4000318e (firmware file offset 0x33174-0x3318e), 11 instructions
# Called from: fn_400035d0
# Calls: fn_40006a08, fn_40002bf0
# Addresses loaded: data_3ffe2760, data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003174, @function
fn_40003174:
	entry	a1, 48                  # 40003174
	s32i.n	a2, a1, 0               # 40003177
	l32i.n	a10, a1, 0              # 40003179
	l32r	a11, lit_3ffe1a88       # 4000317b  = data_3ffe2760
	l32i.n	a11, a11, 0             # 4000317e
	call8	fn_40006a08             # 40003180
	l32r	a10, lit_3ffe1a98       # 40003183  = data_3ffe2390
	l32i.n	a10, a10, 32            # 40003186
	movi.n	a11, 0                  # 40003188
	call8	fn_40002bf0             # 4000318a
	retw.n                          # 4000318d
	.size	fn_40003174, . - fn_40003174
