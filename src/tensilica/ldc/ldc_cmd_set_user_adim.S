# ldc_cmd_set_user_adim  (fn_4000153c): 0x4000153c-0x400015d2 (firmware file offset 0x3153c-0x315d2), 59 instructions
# Name basis: proven - fields printed as usUserADIM, ADIM_Max, PercentADIM; senders ldc_send_user_adim_sub0
#   / _sub1
# Called from: ldc_cmd_set_adim_level_and_percent
# Address stored in the words at: 0x4000d2cc
# Calls: ldc_calc_percent_adim, lib_fill_halfwords, ldc_post_brightness_status
# Addresses loaded: ldc_dimming_settings
# Other literal values: 0x3ffe2bf0, 0x3ffe3ef0, 0xe0091028
#
# Command 0x31 (sent by ldc_send_user_adim_sub0 / _sub1), also called by ldc_cmd_set_adim_level_and_percent: stores the value as
# usUserADIM and raises ADIM_Max to it when it is larger. Sub-code 0 computes PercentADIM with
# ldc_calc_percent_adim, any other sub-code uses usUserADIM directly. In LDC_Mode 0 or 3 it fills LED ADIM of
# every channel with PercentADIM and posts the brightness status. Then writes PercentADIM << 16 + usUserPDIM to
# mailbox word 0xE0091028.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_user_adim, @function
ldc_cmd_set_user_adim:                  # fn_4000153c
	entry	a1, 48                  # 4000153c
	s32i.n	a2, a1, 0               # 4000153f
	s32i.n	a3, a1, 4               # 40001541
	# cfg.user_adim = value   (usUserADIM, cfg +24)
	l32r	a8, lit_3ffe1a98        # 40001543  = ldc_dimming_settings
	l32i.n	a7, a1, 4               # 40001546
	s32i.n	a7, a8, 24              # 40001548
	# if (cfg.adim_max < cfg.user_adim) cfg.adim_max = cfg.user_adim   (ADIM_Max, cfg +12)
	l32r	a6, lit_3ffe1a98        # 4000154a  = ldc_dimming_settings
	l32i.n	a6, a6, 24              # 4000154d
	l32r	a5, lit_3ffe1a98        # 4000154f  = ldc_dimming_settings
	l32i.n	a5, a5, 12              # 40001552
	bgeu	a5, a6, .L40001561      # 40001554
	l32r	a9, lit_3ffe1a98        # 40001557  = ldc_dimming_settings
	l32r	a8, lit_3ffe1a98        # 4000155a  = ldc_dimming_settings
	l32i.n	a8, a8, 24              # 4000155d
	s32i.n	a8, a9, 12              # 4000155f
.L40001561:
	# if (sub == 0) cfg.percent_adim = ldc_calc_percent_adim(cfg.adim_max, cfg.adim_min,
	#                                                    cfg.user_adim, cfg.adim_bright_percent)
	movi.n	a10, 0                  # 40001561
	l32i.n	a9, a1, 0               # 40001563
	bne	a9, a10, .L40001587     # 40001565
	l32r	a10, lit_3ffe1a98       # 40001568  = ldc_dimming_settings
	l32i.n	a10, a10, 12            # 4000156b
	l32r	a11, lit_3ffe1a98       # 4000156d  = ldc_dimming_settings
	l32i.n	a11, a11, 8             # 40001570
	l32r	a12, lit_3ffe1a98       # 40001572  = ldc_dimming_settings
	l32i.n	a12, a12, 24            # 40001575
	l32r	a13, lit_3ffe1a98       # 40001577  = ldc_dimming_settings
	l32i.n	a13, a13, 28            # 4000157a
	call8	ldc_calc_percent_adim   # 4000157c
	l32r	a11, lit_3ffe1a98       # 4000157f  = ldc_dimming_settings
	s32i.n	a10, a11, 20            # 40001582
	j	.L40001591              # 40001584
.L40001587:
	# else cfg.percent_adim = cfg.user_adim
	l32r	a13, lit_3ffe1a98       # 40001587  = ldc_dimming_settings
	l32r	a12, lit_3ffe1a98       # 4000158a  = ldc_dimming_settings
	l32i.n	a12, a12, 24            # 4000158d
	s32i.n	a12, a13, 20            # 4000158f
.L40001591:
	# if (panel.ldc_mode == 0 || panel.ldc_mode == 3)
	movi.n	a14, 0                  # 40001591
	l32r	a13, lit_3ffe1a80       # 40001593  = 0x3ffe2bf0
	l32i	a13, a13, 0x144         # 40001596
	beq	a13, a14, .L400015a5    # 40001599
	l32r	a14, lit_3ffe1a80       # 4000159c  = 0x3ffe2bf0
	l32i	a14, a14, 0x144         # 4000159f
	bnei	a14, 3, .L400015ba      # 400015a2
.L400015a5:
	#     { lib_fill_halfwords(cfg.percent_adim, led_adim, cfg.channel_count);
	#       ldc_post_brightness_status(1); }
	l32r	a10, lit_3ffe1a98       # 400015a5  = ldc_dimming_settings
	l32i.n	a10, a10, 20            # 400015a8
	l32r	a11, lit_3ffe1ac4       # 400015aa  = 0x3ffe3ef0
	l32r	a12, lit_3ffe1a98       # 400015ad  = ldc_dimming_settings
	l32i.n	a12, a12, 0             # 400015b0
	call8	lib_fill_halfwords      # 400015b2
	movi.n	a10, 1                  # 400015b5
	call8	ldc_post_brightness_status # 400015b7
.L400015ba:
	# mailbox[0x28] = (cfg.percent_adim << 16) + cfg.user_pdim   (0xE0091028)
	l32r	a12, lit_3ffe1b28       # 400015ba  = 0xe0091028
	l32r	a13, lit_3ffe1a98       # 400015bd  = ldc_dimming_settings
	l32i.n	a13, a13, 20            # 400015c0
	slli	a13, a13, 16            # 400015c2
	l32r	a11, lit_3ffe1a98       # 400015c5  = ldc_dimming_settings
	l32i.n	a11, a11, 16            # 400015c8
	add.n	a11, a11, a13           # 400015ca
	memw                            # 400015cc
	s32i.n	a11, a12, 0             # 400015cf
	retw.n                          # 400015d1
	.size	ldc_cmd_set_user_adim, . - ldc_cmd_set_user_adim
