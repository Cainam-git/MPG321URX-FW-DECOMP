# reg_read8  (fn_40003f74): 0x40003f74-0x40003f9e (firmware file offset 0x33f74-0x33f9e), 17 instructions
# Name basis: proven - code
# Called from: reg_read8_wrap
#
# Returns the byte at an address by reading the aligned 32-bit word that holds it (address & ~3) and shifting
# right by 8 * (address & 3).
# Arguments: a2 = address.
# Locals: a1+0 = word, a1+4 = byte.
# Returns: the byte (0..255).

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	reg_read8, @function
reg_read8:                              # fn_40003f74
	entry	a1, 64                  # 40003f74
	s32i.n	a2, a1, 16              # 40003f77
	# word = *(volatile u32 *)(address & ~3)
	movi.n	a7, -4                  # 40003f79
	l32i.n	a6, a1, 16              # 40003f7b
	and	a6, a6, a7              # 40003f7d
	memw                            # 40003f80
	l32i.n	a6, a6, 0               # 40003f83
	s32i.n	a6, a1, 0               # 40003f85
	# byte = word >> ((address & 3) * 8); return byte
	l32i.n	a5, a1, 16              # 40003f87
	extui	a5, a5, 0, 2            # 40003f89
	l32i.n	a4, a1, 0               # 40003f8c
	slli	a5, a5, 3               # 40003f8e
	ssr	a5                      # 40003f91
	srl	a4, a4                  # 40003f94
	s8i	a4, a1, 4               # 40003f97
	l8ui	a2, a1, 4               # 40003f9a
	retw.n                          # 40003f9d
	.size	reg_read8, . - reg_read8
