# ldc_set_zone_count_exponents  (fn_400063dc): 0x400063dc-0x4000640e (firmware file offset 0x363dc-0x3640e), 20 instructions
# Name basis: derived - used as 1<<n zone counts by ldc_hw_set_zone_area_factors; command 0x2B = zone counts
#   as powers of two (MAP)
# Called from: ldc_cmd_set_zone_counts, ldc_hw_init
# Stores the two zone-count exponents (zone counts as powers of two) in the segment grid record and writes them
# to bits 16..23 and 24..31 of register 0xE0080000. ldc_hw_init passes 5 and 6; command 0x2B (ldc_cmd_set_zone_counts)
# passes the values from the main processor.
# Arguments: a2 count_x_log2, a3 count_y_log2.
# Locals: a1+0 count_x_log2, a1+4 count_y_log2.
# Returns: nothing.
# Calls: reg_write32_masked
# Other literal values: 0x3ffe4450, 0xe0080000, 0x00ff0000, 0xff000000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_set_zone_count_exponents, @function
ldc_set_zone_count_exponents:           # fn_400063dc
	entry	a1, 48                  # 400063dc
	s32i.n	a2, a1, 0               # 400063df
	s32i.n	a3, a1, 4               # 400063e1
	# grid.count_x_log2 = count_x_log2;   /* 0x3ffe4450 +24 */
	l32r	a14, lit_3ffe1a84       # 400063e3  = 0x3ffe4450
	l32i.n	a13, a1, 0              # 400063e6
	s32i.n	a13, a14, 24            # 400063e8
	# grid.count_y_log2 = count_y_log2;   /* +28 */
	l32r	a13, lit_3ffe1a84       # 400063ea  = 0x3ffe4450
	l32i.n	a12, a1, 4              # 400063ed
	s32i.n	a12, a13, 28            # 400063ef
	# reg_write32_masked(0xE0080000, count_x_log2 << 16, 0xFF0000);
	l32r	a10, lit_3ffe1b74       # 400063f1  = 0xe0080000
	l32i.n	a11, a1, 0              # 400063f4
	slli	a11, a11, 16            # 400063f6
	l32r	a12, lit_3ffe1ea4       # 400063f9  = 0x00ff0000
	call8	reg_write32_masked      # 400063fc
	# reg_write32_masked(0xE0080000, count_y_log2 << 24, 0xFF000000);
	l32r	a10, lit_3ffe1b74       # 400063ff  = 0xe0080000
	l32i.n	a11, a1, 4              # 40006402
	slli	a11, a11, 24            # 40006404
	l32r	a12, lit_3ffe1ea8       # 40006407  = 0xff000000
	call8	reg_write32_masked      # 4000640a
	retw.n                          # 4000640d
	.size	ldc_set_zone_count_exponents, . - ldc_set_zone_count_exponents
