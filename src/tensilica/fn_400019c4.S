# fn_400019c4: 0x400019c4-0x400019e1 (firmware file offset 0x319c4-0x319e1), 12 instructions
# Address stored in the words at: 0x4000d3ac
# Calls: fn_400074b4
# Other literal values: 0x3ffe2bf0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400019c4, @function
fn_400019c4:
	entry	a1, 48                  # 400019c4
	s32i.n	a2, a1, 0               # 400019c7
	s32i.n	a3, a1, 4               # 400019c9
	l32r	a5, lit_3ffe1a80        # 400019cb  = 0x3ffe2bf0
	l32i.n	a5, a5, 24              # 400019ce
	bnei	a5, 1, .L400019e0       # 400019d0
	l32i.n	a10, a1, 0              # 400019d3
	extui	a10, a10, 0, 8          # 400019d5
	l32i.n	a11, a1, 4              # 400019d8
	extui	a11, a11, 0, 8          # 400019da
	call8	fn_400074b4             # 400019dd
.L400019e0:
	retw.n                          # 400019e0
	.size	fn_400019c4, . - fn_400019c4
