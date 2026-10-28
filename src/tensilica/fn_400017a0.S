# fn_400017a0: 0x400017a0-0x400017bc (firmware file offset 0x317a0-0x317bc), 12 instructions
# Address stored in the words at: 0x4000d2e4
# Addresses loaded: data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400017a0, @function
fn_400017a0:
	entry	a1, 48                  # 400017a0
	s32i.n	a2, a1, 0               # 400017a3
	s32i.n	a3, a1, 4               # 400017a5
	l32r	a6, lit_3ffe1a98        # 400017a7  = data_3ffe2390
	l32i.n	a6, a6, 12              # 400017aa
	l32i.n	a5, a1, 4               # 400017ac
	bgeu	a5, a6, .L400017bb      # 400017ae
	l32r	a8, lit_3ffe1a98        # 400017b1  = data_3ffe2390
	l32i.n	a7, a1, 4               # 400017b4
	extui	a7, a7, 0, 10           # 400017b6
	s32i.n	a7, a8, 8               # 400017b9
.L400017bb:
	retw.n                          # 400017bb
	.size	fn_400017a0, . - fn_400017a0
