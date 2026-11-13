# ldc_write_table_and_global_gain  (fn_40003174): 0x40003174-0x4000318e (firmware file offset 0x33174-0x3318e), 11 instructions
# Name basis: derived - calls ldc_hw_write_result_table and ldc_smooth_and_apply_global_gain
# Called from: ldc_run_frame_pass
# Calls: ldc_hw_write_result_table, ldc_smooth_and_apply_global_gain
# Addresses loaded: ldc_segment_count, ldc_dimming_settings
#
# Step of the processing pass (ldc_run_frame_pass, LDC_Mode 1 or 2): passes the given 16-bit table with segment_count
# (ldc_segment_count) entries to ldc_hw_write_result_table, then runs ldc_smooth_and_apply_global_gain with
# UserGlobalGain (settings +32) and smoothing 0. The pass calls it with the Input Duty array (0x3FFE4490).
# Arguments: a2 = table (16-bit values).
# Locals: a1+0 = table.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_write_table_and_global_gain, @function
ldc_write_table_and_global_gain:        # fn_40003174
	entry	a1, 48                  # 40003174
	# ldc_hw_write_result_table(table, segment_count)
	s32i.n	a2, a1, 0               # 40003177
	l32i.n	a10, a1, 0              # 40003179
	l32r	a11, lit_3ffe1a88       # 4000317b  = ldc_segment_count
	l32i.n	a11, a11, 0             # 4000317e
	call8	ldc_hw_write_result_table # 40003180
	# ldc_smooth_and_apply_global_gain(settings.UserGlobalGain, 0)
	l32r	a10, lit_3ffe1a98       # 40003183  = ldc_dimming_settings
	l32i.n	a10, a10, 32            # 40003186
	movi.n	a11, 0                  # 40003188
	call8	ldc_smooth_and_apply_global_gain # 4000318a
	retw.n                          # 4000318d
	.size	ldc_write_table_and_global_gain, . - ldc_write_table_and_global_gain
