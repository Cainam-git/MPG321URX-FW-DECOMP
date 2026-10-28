# fn_40001858: 0x40001858-0x4000187f (firmware file offset 0x31858-0x3187f), 15 instructions
# Address stored in the words at: 0x4000d2fc
# Addresses loaded: data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001858, @function
fn_40001858:
	entry	a1, 48                  # 40001858
	s32i.n	a2, a1, 0               # 4000185b
	s32i.n	a3, a1, 4               # 4000185d
	l32i.n	a6, a1, 4               # 4000185f
	movi	a5, 254                 # 40001861
	bltu	a5, a6, .L40001875      # 40001864
	l32r	a8, lit_3ffe1a98        # 40001867  = data_3ffe2390
	l32i.n	a7, a1, 4               # 4000186a
	extui	a7, a7, 0, 8            # 4000186c
	s32i	a7, a8, 64              # 4000186f
	j	.L4000187e              # 40001872
.L40001875:
	l32r	a9, lit_3ffe1a98        # 40001875  = data_3ffe2390
	movi	a8, 255                 # 40001878
	s32i	a8, a9, 64              # 4000187b
.L4000187e:
	retw.n                          # 4000187e
	.size	fn_40001858, . - fn_40001858
