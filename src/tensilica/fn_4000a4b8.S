# fn_4000a4b8: 0x4000a4b8-0x4000a4c6 (firmware file offset 0x3a4b8-0x3a4c6), 6 instructions
# Called from: fn_4000a458

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a4b8, @function
fn_4000a4b8:
	entry	a1, 48                  # 4000a4b8
	mov.n	a15, a15                # 4000a4bb
	retw.n                          # 4000a4bd
.L4000a4bf:
	movi.n	a2, -1                  # 4000a4bf
	addmi	a1, a1, 0x100           # 4000a4c1
	rfe                             # 4000a4c4
	.size	fn_4000a4b8, . - fn_4000a4b8
