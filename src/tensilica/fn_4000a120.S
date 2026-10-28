# fn_4000a120: 0x4000a120-0x4000a1f2 (firmware file offset 0x3a120-0x3a1f2), 93 instructions
# Called from: fn_40003904, fn_40003a70, fn_40003b68, fn_40003b98

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a120, @function
fn_4000a120:
	entry	a1, 64                  # 4000a120
	s32i.n	a2, a1, 16              # 4000a123
	s32i.n	a3, a1, 20              # 4000a125
	s32i.n	a4, a1, 24              # 4000a127
	l32i.n	a9, a1, 24              # 4000a129
	movi.n	a8, 0                   # 4000a12b
	s8i	a8, a9, 0               # 4000a12d
	movi.n	a8, 0                   # 4000a130
	l32i.n	a7, a1, 20              # 4000a132
	beq	a7, a8, .L4000a148      # 4000a134
	movi.n	a11, 0                  # 4000a137
	l32i.n	a10, a1, 16             # 4000a139
	beq	a10, a11, .L4000a148    # 4000a13b
	movi.n	a12, 0                  # 4000a13e
	l32i.n	a11, a1, 16             # 4000a140
	l8ui	a11, a11, 0             # 4000a142
	bne	a11, a12, .L4000a14f    # 4000a145
.L4000a148:
	movi.n	a12, 0                  # 4000a148
	s32i.n	a12, a1, 4              # 4000a14a
	j	.L4000a1ef              # 4000a14c
.L4000a14f:
	movi.n	a15, 0                  # 4000a14f
	s32i.n	a15, a1, 0              # 4000a151
	l32i.n	a14, a1, 20             # 4000a153
	l32i.n	a13, a1, 0              # 4000a155
	bgeu	a13, a14, .L4000a173    # 4000a157
.L4000a15a:
	l32i.n	a3, a1, 0               # 4000a15a
	l32i.n	a2, a1, 16              # 4000a15c
	add.n	a2, a2, a3              # 4000a15e
	l8ui	a2, a2, 0               # 4000a160
	bnei	a2, 32, .L4000a173      # 4000a163
	l32i.n	a5, a1, 0               # 4000a166
	addi.n	a5, a5, 1               # 4000a168
	s32i.n	a5, a1, 0               # 4000a16a
	l32i.n	a4, a1, 20              # 4000a16c
	l32i.n	a3, a1, 0               # 4000a16e
	bltu	a3, a4, .L4000a15a      # 4000a170
.L4000a173:
	l32i.n	a7, a1, 20              # 4000a173
	l32i.n	a6, a1, 0               # 4000a175
	bltu	a6, a7, .L4000a181      # 4000a177
	movi.n	a8, 0                   # 4000a17a
	s32i.n	a8, a1, 4               # 4000a17c
	j	.L4000a1ef              # 4000a17e
.L4000a181:
	l32i.n	a14, a1, 0              # 4000a181
	l32i.n	a13, a1, 16             # 4000a183
	add.n	a13, a13, a14           # 4000a185
	s32i.n	a13, a1, 16             # 4000a187
	l32i.n	a13, a1, 0              # 4000a189
	l32i.n	a12, a1, 20             # 4000a18b
	sub	a12, a12, a13           # 4000a18d
	s32i.n	a12, a1, 20             # 4000a190
	movi.n	a11, 0                  # 4000a192
	s32i.n	a11, a1, 0              # 4000a194
	l32i.n	a10, a1, 20             # 4000a196
	l32i.n	a9, a1, 0               # 4000a198
	bgeu	a9, a10, .L4000a1dc     # 4000a19a
.L4000a19d:
	l32i.n	a15, a1, 0              # 4000a19d
	l32i.n	a14, a1, 16             # 4000a19f
	add.n	a14, a14, a15           # 4000a1a1
	l8ui	a14, a14, 0             # 4000a1a3
	beqi	a14, 32, .L4000a1cc     # 4000a1a6
	movi.n	a2, 0                   # 4000a1a9
	l32i.n	a3, a1, 0               # 4000a1ab
	l32i.n	a15, a1, 16             # 4000a1ad
	add.n	a15, a15, a3            # 4000a1af
	l8ui	a15, a15, 0             # 4000a1b1
	beq	a15, a2, .L4000a1cc     # 4000a1b4
	l32i.n	a4, a1, 0               # 4000a1b7
	l32i.n	a3, a1, 24              # 4000a1b9
	add.n	a3, a3, a4              # 4000a1bb
	l32i.n	a4, a1, 0               # 4000a1bd
	l32i.n	a2, a1, 16              # 4000a1bf
	add.n	a2, a2, a4              # 4000a1c1
	l8ui	a2, a2, 0               # 4000a1c3
	s8i	a2, a3, 0               # 4000a1c6
	j	.L4000a1cf              # 4000a1c9
.L4000a1cc:
	j	.L4000a1dc              # 4000a1cc
.L4000a1cf:
	l32i.n	a6, a1, 0               # 4000a1cf
	addi.n	a6, a6, 1               # 4000a1d1
	s32i.n	a6, a1, 0               # 4000a1d3
	l32i.n	a5, a1, 20              # 4000a1d5
	l32i.n	a4, a1, 0               # 4000a1d7
	bltu	a4, a5, .L4000a19d      # 4000a1d9
.L4000a1dc:
	l32i.n	a10, a1, 0              # 4000a1dc
	l32i.n	a9, a1, 24              # 4000a1de
	add.n	a9, a9, a10             # 4000a1e0
	movi.n	a8, 0                   # 4000a1e2
	s8i	a8, a9, 0               # 4000a1e4
	l32i.n	a8, a1, 0               # 4000a1e7
	l32i.n	a7, a1, 16              # 4000a1e9
	add.n	a7, a7, a8              # 4000a1eb
	s32i.n	a7, a1, 4               # 4000a1ed
.L4000a1ef:
	l32i.n	a2, a1, 4               # 4000a1ef
	retw.n                          # 4000a1f1
	.size	fn_4000a120, . - fn_4000a120
