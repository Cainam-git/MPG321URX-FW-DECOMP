# fn_40005c8c: 0x40005c8c-0x40005c9a (firmware file offset 0x35c8c-0x35c9a), 6 instructions
# Address stored in the words at: 0x4000b444
# Other literal values: 0xe0091084

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005c8c, @function
fn_40005c8c:
	entry	a1, 32                  # 40005c8c
	l32r	a3, lit_3ffe1bf4        # 40005c8f  = 0xe0091084
	movi.n	a2, 1                   # 40005c92
	memw                            # 40005c94
	s32i.n	a2, a3, 0               # 40005c97
	retw.n                          # 40005c99
	.size	fn_40005c8c, . - fn_40005c8c
