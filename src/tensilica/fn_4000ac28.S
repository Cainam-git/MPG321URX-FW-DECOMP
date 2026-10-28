# fn_4000ac28: 0x4000ac28-0x4000ac2c (firmware file offset 0x3ac28-0x3ac2c), 2 instructions
# Called from: fn_4000a890

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000ac28, @function
fn_4000ac28:
	entry	a1, 16                  # 4000ac28
	retw.n                          # 4000ac2b
	.size	fn_4000ac28, . - fn_4000ac28
