# fn_40008c60: 0x40008c60-0x40008cdf (firmware file offset 0x38c60-0x38cdf), 50 instructions
# Called from: fn_40008e9c, fn_40008f58
# Other literal values: 0xe00a106c, 0xe00a1070, 0xe00a1068

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40008c60, @function
fn_40008c60:
	entry	a1, 64                  # 40008c60
	s32i.n	a2, a1, 16              # 40008c63
	l32i.n	a4, a1, 16              # 40008c65
	bgeui	a4, 8, .L40008c84       # 40008c67
	movi.n	a6, 1                   # 40008c6a
	l32i.n	a7, a1, 16              # 40008c6c
	ssl	a7                      # 40008c6e
	sll	a6, a6                  # 40008c71
	l32r	a5, lit_3ffe221c        # 40008c74  = 0xe00a106c
	memw                            # 40008c77
	l32i.n	a5, a5, 0               # 40008c7a
	or	a5, a5, a6              # 40008c7c
	s32i.n	a5, a1, 0               # 40008c7f
	j	.L40008ca0              # 40008c81
.L40008c84:
	movi.n	a10, -1                 # 40008c84
	movi.n	a9, 1                   # 40008c86
	l32i.n	a11, a1, 16             # 40008c88
	ssl	a11                     # 40008c8a
	sll	a9, a9                  # 40008c8d
	xor	a9, a9, a10             # 40008c90
	l32r	a8, lit_3ffe221c        # 40008c93  = 0xe00a106c
	memw                            # 40008c96
	l32i.n	a8, a8, 0               # 40008c99
	and	a8, a8, a9              # 40008c9b
	s32i.n	a8, a1, 0               # 40008c9e
.L40008ca0:
	l32r	a7, lit_3ffe221c        # 40008ca0  = 0xe00a106c
	memw                            # 40008ca3
	l32i.n	a6, a1, 0               # 40008ca6
	s32i.n	a6, a7, 0               # 40008ca8
	l32r	a4, lit_3ffe2220        # 40008caa  = 0xe00a1070
	movi.n	a3, 1                   # 40008cad
	l32i.n	a5, a1, 16              # 40008caf
	ssl	a5                      # 40008cb1
	sll	a3, a3                  # 40008cb4
	memw                            # 40008cb7
	s32i.n	a3, a4, 0               # 40008cba
	l32r	a13, lit_3ffe2224       # 40008cbc  = 0xe00a1068
	movi.n	a15, -1                 # 40008cbf
	movi.n	a14, 1                  # 40008cc1
	l32i.n	a2, a1, 16              # 40008cc3
	ssl	a2                      # 40008cc5
	sll	a14, a14                # 40008cc8
	xor	a14, a14, a15           # 40008ccb
	l32r	a12, lit_3ffe2224       # 40008cce  = 0xe00a1068
	memw                            # 40008cd1
	l32i.n	a12, a12, 0             # 40008cd4
	and	a12, a12, a14           # 40008cd6
	memw                            # 40008cd9
	s32i.n	a12, a13, 0             # 40008cdc
	retw.n                          # 40008cde
	.size	fn_40008c60, . - fn_40008c60
