# fn_4000a514: 0x4000a514-0x4000a523 (firmware file offset 0x3a514-0x3a523), 7 instructions
# Called from: fn_40008e9c, fn_40008f58, fn_4000908c, fn_400090c8, fn_40009104, fn_40009ca8
# Calls: fn_4000a4c8

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a514, @function
fn_4000a514:
	entry	a1, 32                  # 4000a514
	mov.n	a11, a3                 # 4000a517
	mov.n	a10, a2                 # 4000a519
	mov.n	a12, a2                 # 4000a51b
	call8	fn_4000a4c8             # 4000a51d
	mov.n	a2, a10                 # 4000a520
	retw.n                          # 4000a522
	.size	fn_4000a514, . - fn_4000a514
