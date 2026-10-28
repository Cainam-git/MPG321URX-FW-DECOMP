# fn_40005f90: 0x40005f90-0x40005fa8 (firmware file offset 0x35f90-0x35fa8), 10 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_400090c8

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005f90, @function
fn_40005f90:
	entry	a1, 48                  # 40005f90
	extui	a6, a2, 0, 8            # 40005f93
	s8i	a6, a1, 0               # 40005f96
	s32i.n	a3, a1, 4               # 40005f99
	s32i.n	a4, a1, 8               # 40005f9b
	l8ui	a10, a1, 0              # 40005f9d
	l32i.n	a11, a1, 4              # 40005fa0
	l32i.n	a12, a1, 8              # 40005fa2
	call8	fn_400090c8             # 40005fa4
	retw.n                          # 40005fa7
	.size	fn_40005f90, . - fn_40005f90
