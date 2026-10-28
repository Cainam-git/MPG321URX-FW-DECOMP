# fn_4000496c: 0x4000496c-0x4000497a (firmware file offset 0x3496c-0x3497a), 7 instructions
# Called from: fn_4000498c, fn_40004b08, fn_40005050, fn_40005574

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000496c, @function
fn_4000496c:
	entry	a1, 64                  # 4000496c
	s32i.n	a2, a1, 16              # 4000496f
	l32i.n	a4, a1, 16              # 40004971
	l32i.n	a4, a4, 0               # 40004973
	s32i.n	a4, a1, 0               # 40004975
	l32i.n	a2, a1, 0               # 40004977
	retw.n                          # 40004979
	.size	fn_4000496c, . - fn_4000496c
