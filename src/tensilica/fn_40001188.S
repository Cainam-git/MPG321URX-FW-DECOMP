# fn_40001188: 0x40001188-0x400011e2 (firmware file offset 0x31188-0x311e2), 39 instructions
# Called from: fn_4000153c, fn_400017c0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001188, @function
fn_40001188:
	entry	a1, 64                  # 40001188
	s32i.n	a2, a1, 16              # 4000118b
	s32i.n	a3, a1, 20              # 4000118d
	s32i.n	a4, a1, 24              # 4000118f
	s32i.n	a5, a1, 28              # 40001191
	l32i.n	a10, a1, 24             # 40001193
	s32i.n	a10, a1, 0              # 40001195
	l32i.n	a9, a1, 24              # 40001197
	l32i.n	a8, a1, 16              # 40001199
	bgeu	a8, a9, .L400011b9      # 4000119b
	movi	a13, 0x3ff              # 4000119e
	l32i.n	a15, a1, 20             # 400011a1
	l32i.n	a14, a1, 16             # 400011a3
	sub	a14, a14, a15           # 400011a5
	l32i.n	a12, a1, 28             # 400011a8
	mull	a12, a12, a14           # 400011aa
	quou	a12, a12, a13           # 400011ad
	l32i.n	a11, a1, 20             # 400011b0
	add.n	a11, a11, a12           # 400011b2
	s32i.n	a11, a1, 0              # 400011b4
	j	.L400011df              # 400011b6
.L400011b9:
	l32i.n	a3, a1, 24              # 400011b9
	l32i.n	a2, a1, 20              # 400011bb
	bgeu	a2, a3, .L400011db      # 400011bd
	movi	a6, 0x3ff               # 400011c0
	l32i.n	a8, a1, 20              # 400011c3
	l32i.n	a7, a1, 24              # 400011c5
	sub	a7, a7, a8              # 400011c7
	l32i.n	a5, a1, 28              # 400011ca
	mull	a5, a5, a7              # 400011cc
	quou	a5, a5, a6              # 400011cf
	l32i.n	a4, a1, 20              # 400011d2
	add.n	a4, a4, a5              # 400011d4
	s32i.n	a4, a1, 0               # 400011d6
	j	.L400011df              # 400011d8
.L400011db:
	l32i.n	a9, a1, 20              # 400011db
	s32i.n	a9, a1, 0               # 400011dd
.L400011df:
	l32i.n	a2, a1, 0               # 400011df
	retw.n                          # 400011e1
	.size	fn_40001188, . - fn_40001188
