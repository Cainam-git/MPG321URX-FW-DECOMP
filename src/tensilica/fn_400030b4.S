# fn_400030b4: 0x400030b4-0x400030c4 (firmware file offset 0x330b4-0x330c4), 7 instructions
# Called from: fn_400035d0
# Calls: fn_40001cb4, fn_40002e78

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400030b4, @function
fn_400030b4:
	entry	a1, 48                  # 400030b4
	s32i.n	a2, a1, 0               # 400030b7
	call8	fn_40001cb4             # 400030b9
	l32i.n	a4, a1, 0               # 400030bc
	s32i.n	a10, a4, 0              # 400030be
	call8	fn_40002e78             # 400030c0
	retw.n                          # 400030c3
	.size	fn_400030b4, . - fn_400030b4
