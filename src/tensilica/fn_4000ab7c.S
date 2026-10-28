# fn_4000ab7c: 0x4000ab7c-0x4000ab83 (firmware file offset 0x3ab7c-0x3ab83), 3 instructions
# Called from: fn_40008e9c, fn_40008f58, fn_40009ca8
# Special registers: intclear

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000ab7c, @function
fn_4000ab7c:
	entry	a1, 16                  # 4000ab7c
	wsr.intclear	a2              # 4000ab7f
	retw.n                          # 4000ab82
	.size	fn_4000ab7c, . - fn_4000ab7c
