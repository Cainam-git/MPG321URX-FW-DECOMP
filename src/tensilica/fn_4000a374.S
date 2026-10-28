# fn_4000a374: 0x4000a374-0x4000a39b (firmware file offset 0x3a374-0x3a39b), 15 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Other literal values: 0x000015ac, 0x000014f8

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a374, @function
fn_4000a374:
	entry	a1, 32                  # 4000a374
	l32r	a4, lit_3ffe2328        # 4000a377  = 0x000015ac
	movi.n	a3, 78                  # 4000a37a
	memw                            # 4000a37c
	s32i.n	a3, a4, 0               # 4000a37f
	l32r	a3, lit_3ffe21f8        # 4000a381  = 0x000014f8
	movi	a4, 128                 # 4000a384
	l32r	a2, lit_3ffe21f8        # 4000a387  = 0x000014f8
	memw                            # 4000a38a
	l32i.n	a2, a2, 0               # 4000a38d
	extui	a2, a2, 0, 7            # 4000a38f
	or	a2, a2, a4              # 4000a392
	memw                            # 4000a395
	s32i.n	a2, a3, 0               # 4000a398
	retw.n                          # 4000a39a
	.size	fn_4000a374, . - fn_4000a374
