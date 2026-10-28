# fn_400037cc: 0x400037cc-0x400037d4 (firmware file offset 0x337cc-0x337d4), 4 instructions
# Address stored in the words at: 0x4000d28c, 0x4000d2f4

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400037cc, @function
fn_400037cc:
	entry	a1, 48                  # 400037cc
	s32i.n	a2, a1, 0               # 400037cf
	s32i.n	a3, a1, 4               # 400037d1
	retw.n                          # 400037d3
	.size	fn_400037cc, . - fn_400037cc
