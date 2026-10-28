# fn_40005c78: 0x40005c78-0x40005c8b (firmware file offset 0x35c78-0x35c8b), 8 instructions
# Address stored in the words at: 0x4000b420
# Other literal values: 0xb70910fc, 0x68500def

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005c78, @function
fn_40005c78:
	entry	a1, 48                  # 40005c78
	l32r	a4, lit_3ffe1e20        # 40005c7b  = 0xb70910fc
	s32i.n	a4, a1, 0               # 40005c7e
	l32i.n	a3, a1, 0               # 40005c80
	l32r	a2, lit_3ffe1e24        # 40005c82  = 0x68500def
	memw                            # 40005c85
	s32i.n	a2, a3, 0               # 40005c88
	retw.n                          # 40005c8a
	.size	fn_40005c78, . - fn_40005c78
