# fn_40003fa0: 0x40003fa0-0x40003ff6 (firmware file offset 0x33fa0-0x33ff6), 35 instructions
# Called from: fn_40004190

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003fa0, @function
fn_40003fa0:
	entry	a1, 64                  # 40003fa0
	s32i.n	a2, a1, 16              # 40003fa3
	extui	a2, a3, 0, 8            # 40003fa5
	s8i	a2, a1, 20              # 40003fa8
	l32i.n	a14, a1, 16             # 40003fab
	extui	a14, a14, 0, 2          # 40003fad
	slli	a14, a14, 3             # 40003fb0
	s32i.n	a14, a1, 0              # 40003fb3
	movi.n	a14, -4                 # 40003fb5
	l32i.n	a13, a1, 16             # 40003fb7
	and	a13, a13, a14           # 40003fb9
	s32i.n	a13, a1, 4              # 40003fbc
	l32i.n	a12, a1, 4              # 40003fbe
	memw                            # 40003fc0
	l32i.n	a12, a12, 0             # 40003fc3
	s32i.n	a12, a1, 8              # 40003fc5
	movi.n	a10, -1                 # 40003fc7
	movi	a9, 255                 # 40003fc9
	l32i.n	a11, a1, 0              # 40003fcc
	ssl	a11                     # 40003fce
	sll	a9, a9                  # 40003fd1
	xor	a9, a9, a10             # 40003fd4
	l32i.n	a8, a1, 8               # 40003fd7
	and	a8, a8, a9              # 40003fd9
	l8ui	a7, a1, 20              # 40003fdc
	l32i.n	a9, a1, 0               # 40003fdf
	ssl	a9                      # 40003fe1
	sll	a7, a7                  # 40003fe4
	or	a7, a7, a8              # 40003fe7
	s32i.n	a7, a1, 8               # 40003fea
	l32i.n	a6, a1, 4               # 40003fec
	l32i.n	a5, a1, 8               # 40003fee
	memw                            # 40003ff0
	s32i.n	a5, a6, 0               # 40003ff3
	retw.n                          # 40003ff5
	.size	fn_40003fa0, . - fn_40003fa0
