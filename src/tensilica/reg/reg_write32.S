# reg_write32  (fn_40003f24): 0x40003f24-0x40003f35 (firmware file offset 0x33f24-0x33f35), 8 instructions
# Name basis: proven - code
# Called from: reg_write32_wrap, DRV_LDC_Intensity_Gain_Update, ldc_hw_write_global_gain_0x400,
#              ldc_hw_write_global_gain, ldc_units_copy_words_and_start, ldc_unit_set_mode_bits,
#              ldc_units_init
#
# Writes a 32-bit word to an address (a volatile write).
# Arguments: a2 = address, a3 = value.
# Locals: a1+0 = address, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	reg_write32, @function
reg_write32:                            # fn_40003f24
	entry	a1, 48                  # 40003f24
	# *(volatile u32 *)address = value
	s32i.n	a2, a1, 0               # 40003f27
	s32i.n	a3, a1, 4               # 40003f29
	l32i.n	a6, a1, 0               # 40003f2b
	l32i.n	a5, a1, 4               # 40003f2d
	memw                            # 40003f2f
	s32i.n	a5, a6, 0               # 40003f32
	retw.n                          # 40003f34
	.size	reg_write32, . - reg_write32
