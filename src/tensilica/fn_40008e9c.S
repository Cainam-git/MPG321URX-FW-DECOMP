# fn_40008e9c: 0x40008e9c-0x40008ec3 (firmware file offset 0x38e9c-0x38ec3), 16 instructions
# Called from: fn_4000a3cc
# Calls: fn_4000a514, fn_4000ab64, fn_4000ab7c, fn_4000a524, fn_40008ce0, fn_40008c60
# Addresses loaded: fn_40008e88

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40008e9c, @function
fn_40008e9c:
	entry	a1, 32                  # 40008e9c
	movi.n	a10, 0                  # 40008e9f
	l32r	a11, lit_3ffe2238       # 40008ea1  = fn_40008e88
	call8	fn_4000a514             # 40008ea4
	call8	fn_4000ab64             # 40008ea7
	movi.n	a10, 1                  # 40008eaa
	call8	fn_4000ab7c             # 40008eac
	movi.n	a10, 1                  # 40008eaf
	call8	fn_4000a524             # 40008eb1
	movi.n	a10, 0                  # 40008eb4
	movi.n	a11, 0                  # 40008eb6
	movi.n	a12, 0                  # 40008eb8
	call8	fn_40008ce0             # 40008eba
	movi.n	a10, 0                  # 40008ebd
	call8	fn_40008c60             # 40008ebf
	retw.n                          # 40008ec2
	.size	fn_40008e9c, . - fn_40008e9c
