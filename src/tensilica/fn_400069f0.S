# fn_400069f0: 0x400069f0-0x40006a04 (firmware file offset 0x369f0-0x36a04), 8 instructions
# Called from: fn_40002bf0
# Calls: fn_40003f24
# Other literal values: 0xe0080378

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400069f0, @function
fn_400069f0:
	entry	a1, 48                  # 400069f0
	s32i.n	a2, a1, 0               # 400069f3
	l32r	a10, lit_3ffe1f20       # 400069f5  = 0xe0080378
	l32i.n	a11, a1, 0              # 400069f8
	extui	a11, a11, 0, 12         # 400069fa
	slli	a11, a11, 16            # 400069fd
	call8	fn_40003f24             # 40006a00
	retw.n                          # 40006a03
	.size	fn_400069f0, . - fn_400069f0
