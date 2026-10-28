# fn_4000ab64: 0x4000ab64-0x4000ab68 (firmware file offset 0x3ab64-0x3ab68), 2 instructions
# Called from: fn_40008e9c, fn_40008f58, fn_4000908c, fn_40009ca8

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000ab64, @function
fn_4000ab64:
	entry	a1, 16                  # 4000ab64
	retw.n                          # 4000ab67
	.size	fn_4000ab64, . - fn_4000ab64
