# fn_4000a10c: 0x4000a10c-0x4000a11d (firmware file offset 0x3a10c-0x3a11d), 8 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_4000a890

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a10c, @function
fn_4000a10c:
	entry	a1, 48                  # 4000a10c
	movi.n	a10, 0                  # 4000a10f
	movi.n	a11, -1                 # 4000a111
	movi.n	a12, 2                  # 4000a113
	movi.n	a13, 0                  # 4000a115
	call8	fn_4000a890             # 4000a117
	s32i.n	a10, a1, 0              # 4000a11a
	retw.n                          # 4000a11c
	.size	fn_4000a10c, . - fn_4000a10c
