# ldc_run_pdim_path  (fn_40003140): 0x40003140-0x40003172 (firmware file offset 0x33140-0x33172), 20 instructions
# Name basis: derived - calls the ldc_pdim_* steps; output 0x3FFE3EB0 printed as 'LED PDIM:'
# Called from: ldc_run_frame_pass
# Calls: ldc_pdim_select_user_or_dark, ldc_pdim_scale_to_4095, ldc_pdim_raise_masked_channels,
#        ldc_pdim_smooth_toward_target, lib_pack_word_pairs
# Other literal values: 0x3ffe3eb0
#
# PDIM step of the processing pass (ldc_run_frame_pass, LDC_Mode 1 or 2): turns the merged channel values into the
# "LED PDIM" values. Selects the user or dark PDIM per channel, scales to 4095, raises masked channels, runs the
# smoothing step with smoothing off (0) and packs the 32 results as 16-bit values into the LED PDIM array at
# 0x3FFE3EB0.
# Arguments: a2 = merged (merged channel values, 32-bit words); a pass record follows on the stack (passed by
# value by ldc_run_frame_pass), not read here.
# Locals: a1+0 = pdim[32], a1+128 = smoothed[32], a1+256 = merged.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_run_pdim_path, @function
ldc_run_pdim_path:                      # fn_40003140
	entry	a1, 0x130               # 40003140
	s32i	a2, a1, 0x100           # 40003143
	# ldc_pdim_select_user_or_dark(merged, pdim)
	l32i	a10, a1, 0x100          # 40003146
	mov.n	a11, a1                 # 40003149
	call8	ldc_pdim_select_user_or_dark # 4000314b
	# ldc_pdim_scale_to_4095(pdim)
	mov.n	a10, a1                 # 4000314e
	call8	ldc_pdim_scale_to_4095  # 40003150
	# ldc_pdim_raise_masked_channels(pdim)
	mov.n	a10, a1                 # 40003153
	call8	ldc_pdim_raise_masked_channels # 40003155
	# ldc_pdim_smooth_toward_target(pdim, smoothed, 0)
	mov.n	a10, a1                 # 40003158
	addi	a11, a1, 127            # 4000315a
	addi.n	a11, a11, 1             # 4000315d
	movi.n	a12, 0                  # 4000315f
	call8	ldc_pdim_smooth_toward_target # 40003161
	# lib_pack_word_pairs(smoothed, led_pdim (0x3FFE3EB0), 32)
	addi	a10, a1, 127            # 40003164
	addi.n	a10, a10, 1             # 40003167
	l32r	a11, lit_3ffe1ac0       # 40003169  = 0x3ffe3eb0
	movi.n	a12, 32                 # 4000316c
	call8	lib_pack_word_pairs     # 4000316e
	retw.n                          # 40003171
	.size	ldc_run_pdim_path, . - ldc_run_pdim_path
