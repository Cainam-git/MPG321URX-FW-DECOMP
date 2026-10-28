# fn_4000497c: 0x4000497c-0x4000498a (firmware file offset 0x3497c-0x3498a), 7 instructions
# Called from: fn_40004bcc, fn_40005050, fn_40005574

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000497c, @function
fn_4000497c:
	entry	a1, 48                  # 4000497c
	s32i.n	a2, a1, 0               # 4000497f
	s32i.n	a3, a1, 4               # 40004981
	l32i.n	a6, a1, 0               # 40004983
	l32i.n	a5, a1, 4               # 40004985
	s32i.n	a5, a6, 0               # 40004987
	retw.n                          # 40004989
	.size	fn_4000497c, . - fn_4000497c
