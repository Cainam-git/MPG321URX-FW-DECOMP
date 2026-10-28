# fn_40008ec4: 0x40008ec4-0x40008eed (firmware file offset 0x38ec4-0x38eed), 16 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Other literal values: 0xe00a1004

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40008ec4, @function
fn_40008ec4:
	entry	a1, 32                  # 40008ec4
	l32r	a4, lit_3ffe223c        # 40008ec7  = 0xe00a1004
	movi.n	a3, 1                   # 40008eca
	memw                            # 40008ecc
	s32i.n	a3, a4, 0               # 40008ecf
	l32r	a2, lit_3ffe223c        # 40008ed1  = 0xe00a1004
	memw                            # 40008ed4
	l32i.n	a2, a2, 0               # 40008ed7
	extui	a2, a2, 0, 1            # 40008ed9
	beqz.n	a2, .L40008eec          # 40008edc
.L40008ede:
	l32r	a5, lit_3ffe223c        # 40008ede  = 0xe00a1004
	memw                            # 40008ee1
	l32i.n	a5, a5, 0               # 40008ee4
	extui	a5, a5, 0, 1            # 40008ee6
	bnez	a5, .L40008ede          # 40008ee9
.L40008eec:
	retw.n                          # 40008eec
	.size	fn_40008ec4, . - fn_40008ec4
