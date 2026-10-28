# fn_400038e8: 0x400038e8-0x40003903 (firmware file offset 0x338e8-0x33903), 10 instructions
# Called from: fn_40003cd0
# Calls: fn_40009e88
# Addresses loaded: data_3ffe2700

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400038e8, @function
fn_400038e8:
	entry	a1, 48                  # 400038e8
	extui	a2, a2, 0, 8            # 400038eb
	s8i	a2, a1, 0               # 400038ee
	movi.n	a5, 0                   # 400038f1
	l32r	a4, lit_3ffe1ce0        # 400038f3  = data_3ffe2700
	l8ui	a4, a4, 0               # 400038f6
	beq	a4, a5, .L40003902      # 400038f9
	l8ui	a10, a1, 0              # 400038fc
	call8	fn_40009e88             # 400038ff
.L40003902:
	retw.n                          # 40003902
	.size	fn_400038e8, . - fn_400038e8
