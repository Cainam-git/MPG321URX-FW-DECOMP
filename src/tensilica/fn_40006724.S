# fn_40006724: 0x40006724-0x4000674c (firmware file offset 0x36724-0x3674c), 17 instructions
# Called from: fn_40001ab8, fn_400068c0
# Calls: fn_40003f38
# Other literal values: 0x3ffe4450, 0xe0080168, 0x00ffffff

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40006724, @function
fn_40006724:
	entry	a1, 48                  # 40006724
	s32i.n	a2, a1, 0               # 40006727
	s32i.n	a3, a1, 4               # 40006729
	l32r	a15, lit_3ffe1a84       # 4000672b  = 0x3ffe4450
	l32i.n	a14, a1, 0              # 4000672e
	s32i.n	a14, a15, 32            # 40006730
	l32r	a14, lit_3ffe1a84       # 40006732  = 0x3ffe4450
	l32i.n	a13, a1, 4              # 40006735
	s32i.n	a13, a14, 36            # 40006737
	l32r	a10, lit_3ffe1ef0       # 40006739  = 0xe0080168
	l32i.n	a12, a1, 0              # 4000673c
	slli	a12, a12, 8             # 4000673e
	l32i.n	a11, a1, 4              # 40006741
	add.n	a11, a11, a12           # 40006743
	l32r	a12, lit_3ffe1ef4       # 40006745  = 0x00ffffff
	call8	fn_40003f38             # 40006748
	retw.n                          # 4000674b
	.size	fn_40006724, . - fn_40006724
