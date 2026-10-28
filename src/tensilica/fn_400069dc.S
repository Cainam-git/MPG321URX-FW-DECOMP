# fn_400069dc: 0x400069dc-0x400069ed (firmware file offset 0x369dc-0x369ed), 7 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_40003f24
# Other literal values: 0xe0080378, 0x04000000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400069dc, @function
fn_400069dc:
	entry	a1, 48                  # 400069dc
	s32i.n	a2, a1, 0               # 400069df
	s32i.n	a3, a1, 4               # 400069e1
	l32r	a10, lit_3ffe1f20       # 400069e3  = 0xe0080378
	l32r	a11, lit_3ffe1f24       # 400069e6  = 0x04000000
	call8	fn_40003f24             # 400069e9
	retw.n                          # 400069ec
	.size	fn_400069dc, . - fn_400069dc
