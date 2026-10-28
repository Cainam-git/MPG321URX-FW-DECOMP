# fn_40001780: 0x40001780-0x4000179c (firmware file offset 0x31780-0x3179c), 12 instructions
# Address stored in the words at: 0x4000d2dc
# Addresses loaded: data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001780, @function
fn_40001780:
	entry	a1, 48                  # 40001780
	s32i.n	a2, a1, 0               # 40001783
	s32i.n	a3, a1, 4               # 40001785
	l32i.n	a6, a1, 4               # 40001787
	l32r	a5, lit_3ffe1a98        # 40001789  = data_3ffe2390
	l32i.n	a5, a5, 8               # 4000178c
	bgeu	a5, a6, .L4000179b      # 4000178e
	l32r	a8, lit_3ffe1a98        # 40001791  = data_3ffe2390
	l32i.n	a7, a1, 4               # 40001794
	extui	a7, a7, 0, 10           # 40001796
	s32i.n	a7, a8, 12              # 40001799
.L4000179b:
	retw.n                          # 4000179b
	.size	fn_40001780, . - fn_40001780
