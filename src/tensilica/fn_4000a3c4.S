# fn_4000a3c4: 0x4000a3c4-0x4000a3c8 (firmware file offset 0x3a3c4-0x3a3c8), 2 instructions
# Address stored in the words at: 0x4000d024

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a3c4, @function
fn_4000a3c4:
	entry	a1, 32                  # 4000a3c4
	retw.n                          # 4000a3c7
	.size	fn_4000a3c4, . - fn_4000a3c4
