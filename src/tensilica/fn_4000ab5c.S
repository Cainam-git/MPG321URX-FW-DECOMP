# fn_4000ab5c: 0x4000ab5c-0x4000ab63 (firmware file offset 0x3ab5c-0x3ab63), 3 instructions
# Address stored in the words at: 0x4000d04c, 0x4000d778, 0x4000d780, 0x4000d788, 0x4000d790, 0x4000d798,
#                                 0x4000d7a0, 0x4000d7a8, 0x4000d7b0, 0x4000d7b8, 0x4000d7c0, 0x4000d7c8,
#                                 0x4000d7d0, 0x4000d7d8, 0x4000d7e0, 0x4000d7e8, 0x4000d7f0, 0x4000d7f8,
#                                 0x4000d800, 0x4000d808, 0x4000d810, 0x4000d818, 0x4000d820

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000ab5c, @function
fn_4000ab5c:
	entry	a1, 16                  # 4000ab5c
	break	1, 15                   # 4000ab5f
	retw.n                          # 4000ab62
	.size	fn_4000ab5c, . - fn_4000ab5c
