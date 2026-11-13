# reg_write32_masked  (fn_40003f38): 0x40003f38-0x40003f70 (firmware file offset 0x33f38-0x33f70), 25 instructions
# Name basis: proven - code
# Called from: reg_write32_masked_wrap, DRV_LDC_SetPanelResolution, ldc_set_zone_count_exponents,
#              ldc_hw_set_reg280_low_bytes, DRV_LDC_UpdateSegmentBoundary, DRV_LDC_SetLDCSegment,
#              DRV_LDC_SetDSRegisters, ldc_hw_set_reg168_fields, ldc_hw_set_reg28c_bits4_6,
#              ldc_hw_set_reg290_high_half, ldc_unit_set_mode_bits, ldc_unit_set_length_and_flag,
#              ldc_unit_set_reg38_bit13
#
# Read-modify-write of a 32-bit word: the bits set in mask take the bits of value, the others keep their state.
# Arguments: a2 = address, a3 = value, a4 = mask.
# Locals: a1+0 = word.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	reg_write32_masked, @function
reg_write32_masked:                     # fn_40003f38
	entry	a1, 64                  # 40003f38
	# value &= mask
	s32i.n	a2, a1, 16              # 40003f3b
	s32i.n	a3, a1, 20              # 40003f3d
	s32i.n	a4, a1, 24              # 40003f3f
	l32i.n	a14, a1, 24             # 40003f41
	l32i.n	a13, a1, 20             # 40003f43
	and	a13, a13, a14           # 40003f45
	s32i.n	a13, a1, 20             # 40003f48
	# word = *(volatile u32 *)address
	l32i.n	a12, a1, 16             # 40003f4a
	memw                            # 40003f4c
	l32i.n	a12, a12, 0             # 40003f4f
	s32i.n	a12, a1, 0              # 40003f51
	# word = value | (word & ~mask)
	movi.n	a12, -1                 # 40003f53
	l32i.n	a11, a1, 24             # 40003f55
	xor	a11, a11, a12           # 40003f57
	l32i.n	a10, a1, 0              # 40003f5a
	and	a10, a10, a11           # 40003f5c
	l32i.n	a9, a1, 20              # 40003f5f
	or	a9, a9, a10             # 40003f61
	s32i.n	a9, a1, 0               # 40003f64
	# *(volatile u32 *)address = word
	l32i.n	a8, a1, 16              # 40003f66
	l32i.n	a7, a1, 0               # 40003f68
	memw                            # 40003f6a
	s32i.n	a7, a8, 0               # 40003f6d
	retw.n                          # 40003f6f
	.size	reg_write32_masked, . - reg_write32_masked
