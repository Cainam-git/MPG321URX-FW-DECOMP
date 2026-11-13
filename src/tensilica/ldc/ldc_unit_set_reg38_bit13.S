# ldc_unit_set_reg38_bit13  (fn_40006e94): 0x40006e94-0x40006eff (firmware file offset 0x36e94-0x36eff), 40 instructions
# Name basis: descriptive - mechanics only; unit = lowest set bit of the mask
# Called from: ldc_units_init, ldc_units_setup_driver_type2
# For the lowest set bit k (0..3) of the unit mask: writes bit 0 of the value to bit 13 of the unit's register
# 0xC0192038 + k * 0x100. Only one unit is handled per call. Callers: ldc_units_init and ldc_units_setup_driver_type2.
# Arguments: a2 unit_mask (bits 0..3), a3 value.
# Locals: a1+0 unit_mask, a1+4 value.
# Returns: nothing.
# Calls: reg_write32_masked
# Other literal values: 0xc0192038, 0x00002000, 0xc0192138, 0xc0192238, 0xc0192338

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_unit_set_reg38_bit13, @function
ldc_unit_set_reg38_bit13:               # fn_40006e94
	entry	a1, 48                  # 40006e94
	s32i.n	a2, a1, 0               # 40006e97
	s32i.n	a3, a1, 4               # 40006e99
	# if (unit_mask & 1) reg_write32_masked(0xC0192038, (value & 1) << 13, 0x2000);
	l32i.n	a5, a1, 0               # 40006e9b
	extui	a5, a5, 0, 1            # 40006e9d
	beqz.n	a5, .L40006eb6          # 40006ea0
	l32r	a10, lit_3ffe1fa4       # 40006ea2  = 0xc0192038
	l32i.n	a11, a1, 4              # 40006ea5
	extui	a11, a11, 0, 1          # 40006ea7
	slli	a11, a11, 13            # 40006eaa
	l32r	a12, lit_3ffe1fa8       # 40006ead  = 0x00002000
	call8	reg_write32_masked      # 40006eb0
	j	.L40006efe              # 40006eb3
.L40006eb6:
	# else if (unit_mask & 2) reg_write32_masked(0xC0192138, (value & 1) << 13, 0x2000);
	l32i.n	a12, a1, 0              # 40006eb6
	bbci	a12, 1, .L40006ecf      # 40006eb8
	l32r	a10, lit_3ffe1fac       # 40006ebb  = 0xc0192138
	l32i.n	a11, a1, 4              # 40006ebe
	extui	a11, a11, 0, 1          # 40006ec0
	slli	a11, a11, 13            # 40006ec3
	l32r	a12, lit_3ffe1fa8       # 40006ec6  = 0x00002000
	call8	reg_write32_masked      # 40006ec9
	j	.L40006efe              # 40006ecc
.L40006ecf:
	# else if (unit_mask & 4) reg_write32_masked(0xC0192238, (value & 1) << 13, 0x2000);
	l32i.n	a12, a1, 0              # 40006ecf
	bbci	a12, 2, .L40006ee8      # 40006ed1
	l32r	a10, lit_3ffe1fb0       # 40006ed4  = 0xc0192238
	l32i.n	a11, a1, 4              # 40006ed7
	extui	a11, a11, 0, 1          # 40006ed9
	slli	a11, a11, 13            # 40006edc
	l32r	a12, lit_3ffe1fa8       # 40006edf  = 0x00002000
	call8	reg_write32_masked      # 40006ee2
	j	.L40006efe              # 40006ee5
.L40006ee8:
	# else if (unit_mask & 8) reg_write32_masked(0xC0192338, (value & 1) << 13, 0x2000);
	l32i.n	a12, a1, 0              # 40006ee8
	bbci	a12, 3, .L40006efe      # 40006eea
	l32r	a10, lit_3ffe1fb4       # 40006eed  = 0xc0192338
	l32i.n	a11, a1, 4              # 40006ef0
	extui	a11, a11, 0, 1          # 40006ef2
	slli	a11, a11, 13            # 40006ef5
	l32r	a12, lit_3ffe1fa8       # 40006ef8  = 0x00002000
	call8	reg_write32_masked      # 40006efb
.L40006efe:
	retw.n                          # 40006efe
	.size	ldc_unit_set_reg38_bit13, . - ldc_unit_set_reg38_bit13
