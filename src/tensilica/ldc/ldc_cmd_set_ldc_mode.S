# ldc_cmd_set_ldc_mode  (fn_40001428): 0x40001428-0x400014bc (firmware file offset 0x31428-0x314bc), 56 instructions
# Name basis: proven - field +0x144 printed as 'LDC_Mode'; sender ldc_send_ldc_mode
# Address stored in the words at: 0x4000d294
# Calls: DRV_LDC_Intensity_Gain_Update, ldc_hw_apply_gain_filter_mode, lib_fill_halfwords,
#        ldc_post_brightness_status
# Addresses loaded: ldc_gain_table_anv1, ldc_dimming_settings, ldc_gain_table_flat
# Other literal values: 0x3ffe2bf0, 0x3ffe3eb0, 0x3ffe3ef0
#
# Command 0x20 (sent by ldc_send_ldc_mode): stores the value as LDC_Mode (panel +0x144). Mode 3 passes table
# ldc_gain_table_anv1 with 5 to DRV_LDC_Intensity_Gain_Update and sets GainFilterMode 4; modes 1
# and 2 pass ldc_gain_table_flat with 2 and set GainFilterMode 0; mode 4 passes ldc_gain_table_anv1 with 5 and sets
# GainFilterMode 0; other modes change neither. Then applies GainFilterMode, fills LED PDIM with usUserPDIM and
# LED ADIM with PercentADIM, and posts the brightness status.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_ldc_mode, @function
ldc_cmd_set_ldc_mode:                   # fn_40001428
	entry	a1, 48                  # 40001428
	s32i.n	a2, a1, 0               # 4000142b
	s32i.n	a3, a1, 4               # 4000142d
	# panel.ldc_mode = value
	l32r	a7, lit_3ffe1a80        # 4000142f  = 0x3ffe2bf0
	l32i.n	a6, a1, 4               # 40001432
	s32i	a6, a7, 0x144           # 40001434
	# if (panel.ldc_mode == 3) { DRV_LDC_Intensity_Gain_Update(ldc_gain_table_anv1, 5); cfg.gain_filter_mode = 4; }
	l32r	a5, lit_3ffe1a80        # 40001437  = 0x3ffe2bf0
	l32i	a5, a5, 0x144           # 4000143a
	bnei	a5, 3, .L40001452       # 4000143d
	l32r	a10, lit_3ffe1b20       # 40001440  = ldc_gain_table_anv1
	movi.n	a11, 5                  # 40001443
	call8	DRV_LDC_Intensity_Gain_Update # 40001445
	l32r	a8, lit_3ffe1a98        # 40001448  = ldc_dimming_settings
	movi.n	a7, 4                   # 4000144b
	s32i.n	a7, a8, 4               # 4000144d
	j	.L4000148e              # 4000144f
.L40001452:
	# else if (panel.ldc_mode == 1 || panel.ldc_mode == 2)
	l32r	a9, lit_3ffe1a80        # 40001452  = 0x3ffe2bf0
	l32i	a9, a9, 0x144           # 40001455
	beqi	a9, 1, .L40001464       # 40001458
	l32r	a10, lit_3ffe1a80       # 4000145b  = 0x3ffe2bf0
	l32i	a10, a10, 0x144         # 4000145e
	bnei	a10, 2, .L40001476      # 40001461
.L40001464:
	#     { DRV_LDC_Intensity_Gain_Update(ldc_gain_table_flat, 2); cfg.gain_filter_mode = 0; }
	l32r	a10, lit_3ffe1b24       # 40001464  = ldc_gain_table_flat
	movi.n	a11, 2                  # 40001467
	call8	DRV_LDC_Intensity_Gain_Update # 40001469
	l32r	a12, lit_3ffe1a98       # 4000146c  = ldc_dimming_settings
	movi.n	a11, 0                  # 4000146f
	s32i.n	a11, a12, 4             # 40001471
	j	.L4000148e              # 40001473
.L40001476:
	# else if (panel.ldc_mode == 4) { DRV_LDC_Intensity_Gain_Update(ldc_gain_table_anv1, 5); cfg.gain_filter_mode = 0; }
	l32r	a13, lit_3ffe1a80       # 40001476  = 0x3ffe2bf0
	l32i	a13, a13, 0x144         # 40001479
	bnei	a13, 4, .L4000148e      # 4000147c
	l32r	a10, lit_3ffe1b20       # 4000147f  = ldc_gain_table_anv1
	movi.n	a11, 5                  # 40001482
	call8	DRV_LDC_Intensity_Gain_Update # 40001484
	l32r	a15, lit_3ffe1a98       # 40001487  = ldc_dimming_settings
	movi.n	a14, 0                  # 4000148a
	s32i.n	a14, a15, 4             # 4000148c
.L4000148e:
	# ldc_hw_apply_gain_filter_mode(cfg.gain_filter_mode)
	l32r	a10, lit_3ffe1a98       # 4000148e  = ldc_dimming_settings
	l32i.n	a10, a10, 4             # 40001491
	call8	ldc_hw_apply_gain_filter_mode # 40001493
	# lib_fill_halfwords(cfg.user_pdim, led_pdim, cfg.channel_count)
	l32r	a10, lit_3ffe1a98       # 40001496  = ldc_dimming_settings
	l32i.n	a10, a10, 16            # 40001499
	l32r	a11, lit_3ffe1ac0       # 4000149b  = 0x3ffe3eb0
	l32r	a12, lit_3ffe1a98       # 4000149e  = ldc_dimming_settings
	l32i.n	a12, a12, 0             # 400014a1
	call8	lib_fill_halfwords      # 400014a3
	# lib_fill_halfwords(cfg.percent_adim, led_adim, cfg.channel_count)
	l32r	a10, lit_3ffe1a98       # 400014a6  = ldc_dimming_settings
	l32i.n	a10, a10, 20            # 400014a9
	l32r	a11, lit_3ffe1ac4       # 400014ab  = 0x3ffe3ef0
	l32r	a12, lit_3ffe1a98       # 400014ae  = ldc_dimming_settings
	l32i.n	a12, a12, 0             # 400014b1
	call8	lib_fill_halfwords      # 400014b3
	# ldc_post_brightness_status(1)
	movi.n	a10, 1                  # 400014b6
	call8	ldc_post_brightness_status # 400014b8
	retw.n                          # 400014bb
	.size	ldc_cmd_set_ldc_mode, . - ldc_cmd_set_ldc_mode
