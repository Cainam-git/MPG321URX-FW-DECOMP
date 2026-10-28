# fn_40006854: 0x40006854-0x4000686b (firmware file offset 0x36854-0x3686b), 9 instructions
# Called from: fn_40001734, fn_400068c0
# Calls: fn_40003f38
# Other literal values: 0xe008028c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40006854, @function
fn_40006854:
	entry	a1, 48                  # 40006854
	s32i.n	a2, a1, 0               # 40006857
	l32r	a10, lit_3ffe1f08       # 40006859  = 0xe008028c
	l32i.n	a11, a1, 0              # 4000685c
	extui	a11, a11, 0, 3          # 4000685e
	slli	a11, a11, 4             # 40006861
	movi	a12, 112                # 40006864
	call8	fn_40003f38             # 40006867
	retw.n                          # 4000686a
	.size	fn_40006854, . - fn_40006854
