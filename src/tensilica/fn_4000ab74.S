# fn_4000ab74: 0x4000ab74-0x4000ab78 (firmware file offset 0x3ab74-0x3ab78), 2 instructions
# Called from: fn_40009104

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000ab74, @function
fn_4000ab74:
	entry	a1, 16                  # 4000ab74
	retw.n                          # 4000ab77
	.size	fn_4000ab74, . - fn_4000ab74
