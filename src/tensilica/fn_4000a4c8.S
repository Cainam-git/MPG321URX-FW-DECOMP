# fn_4000a4c8: 0x4000a4c8-0x4000a513 (firmware file offset 0x3a4c8-0x3a513), 28 instructions
# Called from: fn_4000a514
# Addresses loaded: ro_3ffe1a30, data_3ffe2a80, fn_4000ab5c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a4c8, @function
fn_4000a4c8:
	entry	a1, 32                  # 4000a4c8
	bltz	a2, .L4000a500          # 4000a4cb
	movi.n	a5, 21                  # 4000a4ce
	blt	a5, a2, .L4000a500      # 4000a4d0
	l32r	a8, lit_3ffe234c        # 4000a4d3  = ro_3ffe1a30
	add.n	a8, a2, a8              # 4000a4d6
	l8ui	a8, a8, 0               # 4000a4d8
	l32r	a7, lit_3ffe2350        # 4000a4db  = data_3ffe2a80
	bgeui	a8, 7, .L4000a500       # 4000a4de
	slli	a8, a2, 3               # 4000a4e1
	sub	a7, a7, a8              # 4000a4e4
	l32r	a8, lit_3ffe2354        # 4000a4e7  = fn_4000ab5c
	l32i	a6, a7, 168             # 4000a4ea
	bnez.n	a3, .L4000a504          # 4000a4ed
	s32i	a8, a7, 168             # 4000a4ef
	s32i	a2, a7, 172             # 4000a4f2
	sub	a9, a6, a8              # 4000a4f5
	movi.n	a2, 0                   # 4000a4f8
	movnez	a2, a6, a9              # 4000a4fa
	retw.n                          # 4000a4fd
	.balign	4, 0                    # 1 zero byte up to the 4-byte boundary 0x4000a500
.L4000a500:
	movi.n	a2, 0                   # 4000a500
	retw.n                          # 4000a502
.L4000a504:
	s32i	a3, a7, 168             # 4000a504
	s32i	a4, a7, 172             # 4000a507
	sub	a10, a6, a8             # 4000a50a
	movi.n	a2, 0                   # 4000a50d
	movnez	a2, a6, a10             # 4000a50f
	retw.n                          # 4000a512
	.size	fn_4000a4c8, . - fn_4000a4c8
