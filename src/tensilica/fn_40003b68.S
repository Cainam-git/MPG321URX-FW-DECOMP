# fn_40003b68: 0x40003b68-0x40003b95 (firmware file offset 0x33b68-0x33b95), 17 instructions
# Address stored in the words at: 0x4000d42c
# Calls: fn_4000a120, fn_4000a2cc
# Addresses loaded: data_3ffe2700

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003b68, @function
fn_40003b68:
	entry	a1, 128                 # 40003b68
	s32i	a2, a1, 80              # 40003b6b
	s32i	a3, a1, 84              # 40003b6e
	l32i	a10, a1, 80             # 40003b71
	l32i	a11, a1, 84             # 40003b74
	mov.n	a12, a1                 # 40003b77
	call8	fn_4000a120             # 40003b79
	s32i	a10, a1, 80             # 40003b7c
	movi.n	a12, 0                  # 40003b7f
	l32i	a11, a1, 80             # 40003b81
	beq	a11, a12, .L40003b92    # 40003b84
	mov.n	a10, a1                 # 40003b87
	call8	fn_4000a2cc             # 40003b89
	l32r	a13, lit_3ffe1ce0       # 40003b8c  = data_3ffe2700
	s8i	a10, a13, 0             # 40003b8f
.L40003b92:
	movi.n	a2, 0                   # 40003b92
	retw.n                          # 40003b94
	.size	fn_40003b68, . - fn_40003b68
