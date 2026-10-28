# fn_4000161c: 0x4000161c-0x4000162b (firmware file offset 0x3161c-0x3162b), 7 instructions
# Address stored in the words at: 0x4000d324
# Addresses loaded: data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000161c, @function
fn_4000161c:
	entry	a1, 48                  # 4000161c
	s32i.n	a2, a1, 0               # 4000161f
	s32i.n	a3, a1, 4               # 40001621
	l32r	a6, lit_3ffe1a98        # 40001623  = data_3ffe2390
	l32i.n	a5, a1, 4               # 40001626
	s32i.n	a5, a6, 44              # 40001628
	retw.n                          # 4000162a
	.size	fn_4000161c, . - fn_4000161c
