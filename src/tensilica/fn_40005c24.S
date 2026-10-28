# fn_40005c24: 0x40005c24-0x40005c3b (firmware file offset 0x35c24-0x35c3b), 9 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_400099bc, fn_4000a010
# Text loaded: "NT68500 Tensilica S/W : "
# Addresses loaded: ro_3ffe09cc

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005c24, @function
fn_40005c24:
	entry	a1, 48                  # 40005c24
	s32i.n	a2, a1, 0               # 40005c27
	l32r	a10, lit_3ffe1e10       # 40005c29  = ro_3ffe09b0 "NT68500 Tensilica S/W : "
	call8	fn_400099bc             # 40005c2c
	l32i.n	a10, a1, 0              # 40005c2f
	call8	fn_4000a010             # 40005c31
	l32r	a10, lit_3ffe1e14       # 40005c34  = ro_3ffe09cc
	call8	fn_400099bc             # 40005c37
	retw.n                          # 40005c3a
	.size	fn_40005c24, . - fn_40005c24
