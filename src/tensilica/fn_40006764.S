# fn_40006764: 0x40006764-0x4000679a (firmware file offset 0x36764-0x3679a), 22 instructions
# Called from: fn_40001aa8
# Other literal values: 0xe00805a4

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40006764, @function
fn_40006764:
	entry	a1, 64                  # 40006764
	s32i.n	a2, a1, 16              # 40006767
	l32i.n	a4, a1, 16              # 40006769
	bnei	a4, 1, .L40006780       # 4000676b
	movi.n	a6, 4                   # 4000676e
	l32r	a5, lit_3ffe1efc        # 40006770  = 0xe00805a4
	memw                            # 40006773
	l32i.n	a5, a5, 0               # 40006776
	or	a5, a5, a6              # 40006778
	s32i.n	a5, a1, 0               # 4000677b
	j	.L4000678f              # 4000677d
.L40006780:
	movi.n	a7, -5                  # 40006780
	l32r	a6, lit_3ffe1efc        # 40006782  = 0xe00805a4
	memw                            # 40006785
	l32i.n	a6, a6, 0               # 40006788
	and	a6, a6, a7              # 4000678a
	s32i.n	a6, a1, 0               # 4000678d
.L4000678f:
	l32r	a8, lit_3ffe1efc        # 4000678f  = 0xe00805a4
	memw                            # 40006792
	l32i.n	a7, a1, 0               # 40006795
	s32i.n	a7, a8, 0               # 40006797
	retw.n                          # 40006799
	.size	fn_40006764, . - fn_40006764
