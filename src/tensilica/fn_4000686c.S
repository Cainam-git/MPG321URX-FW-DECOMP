# fn_4000686c: 0x4000686c-0x40006883 (firmware file offset 0x3686c-0x36883), 9 instructions
# Called from: fn_40001748
# Calls: fn_40003f38
# Other literal values: 0xe0080290, 0xffff0000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000686c, @function
fn_4000686c:
	entry	a1, 48                  # 4000686c
	s32i.n	a2, a1, 0               # 4000686f
	l32r	a10, lit_3ffe1f0c       # 40006871  = 0xe0080290
	l32i.n	a11, a1, 0              # 40006874
	extui	a11, a11, 0, 16         # 40006876
	slli	a11, a11, 16            # 40006879
	l32r	a12, lit_3ffe1eec       # 4000687c  = 0xffff0000
	call8	fn_40003f38             # 4000687f
	retw.n                          # 40006882
	.size	fn_4000686c, . - fn_4000686c
