# fn_400066d4: 0x400066d4-0x40006709 (firmware file offset 0x366d4-0x36709), 20 instructions
# Called from: fn_4000670c
# Calls: fn_400099bc, fn_40003f38
# Text loaded: "DRV_LDC_SetDSRegisters\r\n"
# Other literal values: 0x3ffe4450, 0xe0080040, 0xffff0000, 0xe0080370

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400066d4, @function
fn_400066d4:
	entry	a1, 48                  # 400066d4
	l32r	a10, lit_3ffe1ee4       # 400066d7  = ro_3ffe0b10 "DRV_LDC_SetDSRegisters\r\n"
	call8	fn_400099bc             # 400066da
	l32r	a13, lit_3ffe1a84       # 400066dd  = 0x3ffe4450
	l32i.n	a13, a13, 48            # 400066e0
	l32r	a12, lit_3ffe1a84       # 400066e2  = 0x3ffe4450
	l32i.n	a12, a12, 16            # 400066e5
	quou	a12, a12, a13           # 400066e7
	s32i.n	a12, a1, 0              # 400066ea
	l32r	a10, lit_3ffe1ee8       # 400066ec  = 0xe0080040
	l32i.n	a11, a1, 0              # 400066ef
	slli	a11, a11, 16            # 400066f1
	l32r	a12, lit_3ffe1eec       # 400066f4  = 0xffff0000
	call8	fn_40003f38             # 400066f7
	l32r	a10, lit_3ffe1be4       # 400066fa  = 0xe0080370
	l32r	a11, lit_3ffe1a84       # 400066fd  = 0x3ffe4450
	l32i.n	a11, a11, 48            # 40006700
	movi	a12, 255                # 40006702
	call8	fn_40003f38             # 40006705
	retw.n                          # 40006708
	.size	fn_400066d4, . - fn_400066d4
