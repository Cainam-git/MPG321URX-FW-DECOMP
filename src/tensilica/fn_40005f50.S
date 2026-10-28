# fn_40005f50: 0x40005f50-0x40005f68 (firmware file offset 0x35f50-0x35f68), 10 instructions
# Called from: fn_40005dd8
# Calls: fn_4000908c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005f50, @function
fn_40005f50:
	entry	a1, 48                  # 40005f50
	extui	a6, a2, 0, 8            # 40005f53
	s8i	a6, a1, 0               # 40005f56
	s32i.n	a3, a1, 4               # 40005f59
	s32i.n	a4, a1, 8               # 40005f5b
	l8ui	a10, a1, 0              # 40005f5d
	l32i.n	a11, a1, 4              # 40005f60
	l32i.n	a12, a1, 8              # 40005f62
	call8	fn_4000908c             # 40005f64
	retw.n                          # 40005f67
	.size	fn_40005f50, . - fn_40005f50
