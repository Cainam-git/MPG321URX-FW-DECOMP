# fn_400090c8: 0x400090c8-0x40009103 (firmware file offset 0x390c8-0x39103), 23 instructions
# Called from: fn_40005f6c, fn_40005f90
# Calls: fn_4000a514, fn_4000ab6c, fn_4000ab94, fn_4000a524
# Addresses loaded: fn_40008fd8
# Other literal values: 0x3ffe5598

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400090c8, @function
fn_400090c8:
	entry	a1, 48                  # 400090c8
	extui	a6, a2, 0, 8            # 400090cb
	s8i	a6, a1, 0               # 400090ce
	s32i.n	a3, a1, 4               # 400090d1
	s32i.n	a4, a1, 8               # 400090d3
	l32r	a11, lit_3ffe2258       # 400090d5  = 0x3ffe5598
	l8ui	a10, a1, 0              # 400090d8
	s8i	a10, a11, 12            # 400090db
	l32r	a10, lit_3ffe2258       # 400090de  = 0x3ffe5598
	l32i.n	a9, a1, 4               # 400090e1
	s32i.n	a9, a10, 16             # 400090e3
	l32r	a9, lit_3ffe2258        # 400090e5  = 0x3ffe5598
	l32i.n	a8, a1, 8               # 400090e8
	s32i.n	a8, a9, 20              # 400090ea
	movi.n	a10, 10                 # 400090ec
	l32r	a11, lit_3ffe2264       # 400090ee  = fn_40008fd8
	call8	fn_4000a514             # 400090f1
	call8	fn_4000ab6c             # 400090f4
	l32i.n	a10, a1, 4              # 400090f7
	call8	fn_4000ab94             # 400090f9
	movi	a10, 0x400              # 400090fc
	call8	fn_4000a524             # 400090ff
	retw.n                          # 40009102
	.size	fn_400090c8, . - fn_400090c8
