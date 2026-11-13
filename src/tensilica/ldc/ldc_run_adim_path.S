# ldc_run_adim_path  (fn_400030c8): 0x400030c8-0x4000313f (firmware file offset 0x330c8-0x3313f), 46 instructions
# Name basis: derived - calls the ldc_adim_* steps; output 0x3FFE3EF0 printed as 'LED ADIM:'
# Called from: ldc_run_frame_pass
# Calls: ldc_adim_map_through_curve, ldc_adim_apply_zone_peaking, ldc_adim_apply_limit_upper_bound,
#        ldc_adim_hold_on_sudden_rise, ldc_adim_raise_masked_channels, ldc_adim_smooth_toward_target,
#        lib_pack_word_pairs
# Addresses loaded: ldc_dimming_settings
# Other literal values: 0x3ffe3ef0
#
# ADIM step of the processing pass (ldc_run_frame_pass, LDC_Mode 1 or 2): turns the merged channel values into the
# "LED ADIM" values. Runs the ADIM chain on a local array of 32 words: map through the curve with PercentADIM,
# zone peaking with ADIM_Max / ADIM_Min, the upper bound limit, the hold on a sudden rise, the raise of masked
# channels, then smooths toward the target (smoothing on only while no hold is active) and packs the 32 results as
# 16-bit values into the LED ADIM array at 0x3FFE3EF0.
# Arguments: a2 = merged (merged channel values, 32-bit words); a pass record follows on the stack (passed by
# value by ldc_run_frame_pass), not read here.
# Locals: a1+0 = percent (settings PercentADIM, +20), a1+4 = hold, a1+16 = adim[32], a1+144 = smoothed[32],
# a1+272 = merged.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_run_adim_path, @function
ldc_run_adim_path:                      # fn_400030c8
	entry	a1, 0x140               # 400030c8
	s32i	a2, a1, 0x110           # 400030cb
	# percent = settings.PercentADIM; hold = 0
	l32r	a12, lit_3ffe1a98       # 400030ce  = ldc_dimming_settings
	l32i.n	a12, a12, 20            # 400030d1
	s32i.n	a12, a1, 0              # 400030d3
	movi.n	a11, 0                  # 400030d5
	s32i.n	a11, a1, 4              # 400030d7
	# ldc_adim_map_through_curve(merged, adim, percent)
	l32i	a10, a1, 0x110          # 400030d9
	addi	a11, a1, 16             # 400030dc
	l32i.n	a12, a1, 0              # 400030df
	call8	ldc_adim_map_through_curve # 400030e1
	# ldc_adim_apply_zone_peaking(adim, settings.ADIM_Max, settings.ADIM_Min)
	addi	a10, a1, 16             # 400030e4
	l32r	a11, lit_3ffe1a98       # 400030e7  = ldc_dimming_settings
	l32i.n	a11, a11, 12            # 400030ea
	l32r	a12, lit_3ffe1a98       # 400030ec  = ldc_dimming_settings
	l32i.n	a12, a12, 8             # 400030ef
	call8	ldc_adim_apply_zone_peaking # 400030f1
	# ldc_adim_apply_limit_upper_bound(adim, percent, settings.ADIM_Min)
	addi	a10, a1, 16             # 400030f4
	l32i.n	a11, a1, 0              # 400030f7
	l32r	a12, lit_3ffe1a98       # 400030f9  = ldc_dimming_settings
	l32i.n	a12, a12, 8             # 400030fc
	call8	ldc_adim_apply_limit_upper_bound # 400030fe
	# hold = ldc_adim_hold_on_sudden_rise(merged, adim, settings.PercentADIM, 1)
	l32i	a10, a1, 0x110          # 40003101
	addi	a11, a1, 16             # 40003104
	l32r	a12, lit_3ffe1a98       # 40003107  = ldc_dimming_settings
	l32i.n	a12, a12, 20            # 4000310a
	movi.n	a13, 1                  # 4000310c
	call8	ldc_adim_hold_on_sudden_rise # 4000310e
	s32i.n	a10, a1, 4              # 40003111
	# ldc_adim_raise_masked_channels(adim)
	addi	a10, a1, 16             # 40003113
	call8	ldc_adim_raise_masked_channels # 40003116
	# ldc_adim_smooth_toward_target(adim, smoothed, hold == 0)
	movi.n	a15, 0                  # 40003119
	l32i.n	a14, a1, 4              # 4000311b
	movi.n	a13, 1                  # 4000311d
	movi.n	a12, 0                  # 4000311f
	moveqz	a12, a13, a14           # 40003121
	addi	a10, a1, 16             # 40003124
	addi	a11, a1, 127            # 40003127
	addi	a11, a11, 17            # 4000312a
	call8	ldc_adim_smooth_toward_target # 4000312d
	# lib_pack_word_pairs(smoothed, led_adim (0x3FFE3EF0), 32)
	addi	a10, a1, 127            # 40003130
	addi	a10, a10, 17            # 40003133
	l32r	a11, lit_3ffe1ac4       # 40003136  = 0x3ffe3ef0
	movi.n	a12, 32                 # 40003139
	call8	lib_pack_word_pairs     # 4000313b
	retw.n                          # 4000313e
	.size	ldc_run_adim_path, . - ldc_run_adim_path
