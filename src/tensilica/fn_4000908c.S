# fn_4000908c: 0x4000908c-0x400090c6 (firmware file offset 0x3908c-0x390c6), 23 instructions
# Called from: fn_40005f2c, fn_40005f50
# Calls: fn_4000a514, fn_4000ab64, fn_4000ab84, fn_4000a524
# Addresses loaded: fn_40008f84
# Other literal values: 0x3ffe5598

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000908c, @function
fn_4000908c:
	entry	a1, 48                  # 4000908c
	extui	a6, a2, 0, 8            # 4000908f
	s8i	a6, a1, 0               # 40009092
	s32i.n	a3, a1, 4               # 40009095
	s32i.n	a4, a1, 8               # 40009097
	l32r	a11, lit_3ffe2258       # 40009099  = 0x3ffe5598
	l8ui	a10, a1, 0              # 4000909c
	s8i	a10, a11, 0             # 4000909f
	l32r	a10, lit_3ffe2258       # 400090a2  = 0x3ffe5598
	l32i.n	a9, a1, 4               # 400090a5
	s32i.n	a9, a10, 4              # 400090a7
	l32r	a9, lit_3ffe2258        # 400090a9  = 0x3ffe5598
	l32i.n	a8, a1, 8               # 400090ac
	s32i.n	a8, a9, 8               # 400090ae
	movi.n	a10, 6                  # 400090b0
	l32r	a11, lit_3ffe2260       # 400090b2  = fn_40008f84
	call8	fn_4000a514             # 400090b5
	call8	fn_4000ab64             # 400090b8
	l32i.n	a10, a1, 4              # 400090bb
	call8	fn_4000ab84             # 400090bd
	movi.n	a10, 64                 # 400090c0
	call8	fn_4000a524             # 400090c2
	retw.n                          # 400090c5
	.size	fn_4000908c, . - fn_4000908c
