# fn_4000ac30: 0x4000ac30-0x4000ac34 (firmware file offset 0x3ac30-0x3ac34), 2 instructions
# Called from: fn_4000a890

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000ac30, @function
fn_4000ac30:
	entry	a1, 16                  # 4000ac30
	retw.n                          # 4000ac33
	.size	fn_4000ac30, . - fn_4000ac30
