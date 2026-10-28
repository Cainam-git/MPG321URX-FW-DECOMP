# fn_4000ab6c: 0x4000ab6c-0x4000ab70 (firmware file offset 0x3ab6c-0x3ab70), 2 instructions
# Called from: fn_400090c8

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000ab6c, @function
fn_4000ab6c:
	entry	a1, 16                  # 4000ab6c
	retw.n                          # 4000ab6f
	.size	fn_4000ab6c, . - fn_4000ab6c
