# fn_40005dd8: 0x40005dd8-0x40005de7 (firmware file offset 0x35dd8-0x35de7), 6 instructions
# Called from: fn_4000a3cc
# Calls: fn_40005f50
# Addresses loaded: fn_40005cf8

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005dd8, @function
fn_40005dd8:
	entry	a1, 32                  # 40005dd8
	movi.n	a10, 0                  # 40005ddb
	movi	a11, 0x454              # 40005ddd
	l32r	a12, lit_3ffe1e3c       # 40005de0  = fn_40005cf8
	call8	fn_40005f50             # 40005de3
	retw.n                          # 40005de6
	.size	fn_40005dd8, . - fn_40005dd8
