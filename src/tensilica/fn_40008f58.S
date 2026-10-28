# fn_40008f58: 0x40008f58-0x40008f81 (firmware file offset 0x38f58-0x38f81), 16 instructions
# Called from: fn_4000a3cc
# Calls: fn_4000a514, fn_4000ab64, fn_4000ab7c, fn_4000a524, fn_40008ce0, fn_40008c60
# Addresses loaded: fn_40008ef0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40008f58, @function
fn_40008f58:
	entry	a1, 32                  # 40008f58
	movi.n	a10, 9                  # 40008f5b
	l32r	a11, lit_3ffe2254       # 40008f5d  = fn_40008ef0
	call8	fn_4000a514             # 40008f60
	call8	fn_4000ab64             # 40008f63
	movi	a10, 0x200              # 40008f66
	call8	fn_4000ab7c             # 40008f69
	movi	a10, 0x200              # 40008f6c
	call8	fn_4000a524             # 40008f6f
	movi.n	a10, 7                  # 40008f72
	movi.n	a11, 0                  # 40008f74
	movi.n	a12, 0                  # 40008f76
	call8	fn_40008ce0             # 40008f78
	movi.n	a10, 7                  # 40008f7b
	call8	fn_40008c60             # 40008f7d
	retw.n                          # 40008f80
	.size	fn_40008f58, . - fn_40008f58
