# ldc_cmd_set_adim_bright_percent  (fn_400017c0): 0x400017c0-0x4000182e (firmware file offset 0x317c0-0x3182e), 43 instructions
# Name basis: proven - cfg +28 printed as 'ADIM_BrighPercent'; calls ldc_calc_percent_adim
# Address stored in the words at: 0x4000d2ec
# Calls: ldc_calc_percent_adim, lib_fill_halfwords, ldc_post_brightness_status
# Addresses loaded: ldc_dimming_settings
# Other literal values: 0x3ffe2bf0, 0x3ffe3ef0, 0xe0091028
#
# Command 0x35 (sent by ldc_send_adim_bright_percent): stores the low 10 bits of the value as ADIM_BrighPercent (cfg +28)
# and recomputes PercentADIM (cfg +20) with ldc_calc_percent_adim. In LDC_Mode 0 or 3 it fills LED ADIM of
# every channel with PercentADIM and posts the brightness status. Then writes PercentADIM << 16 + usUserPDIM to
# mailbox word 0xE0091028.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_adim_bright_percent, @function
ldc_cmd_set_adim_bright_percent:        # fn_400017c0
	entry	a1, 48                  # 400017c0
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 400017c3
	s32i.n	a3, a1, 4               # 400017c5
	# cfg.adim_bright_percent = value & 0x3FF
	l32r	a12, lit_3ffe1a98       # 400017c7  = ldc_dimming_settings
	l32i.n	a11, a1, 4              # 400017ca
	extui	a11, a11, 0, 10         # 400017cc
	s32i.n	a11, a12, 28            # 400017cf
	# cfg.percent_adim = ldc_calc_percent_adim(cfg.adim_max, cfg.adim_min, cfg.user_adim,
	#                                          cfg.adim_bright_percent)
	l32r	a10, lit_3ffe1a98       # 400017d1  = ldc_dimming_settings
	l32i.n	a10, a10, 12            # 400017d4
	l32r	a11, lit_3ffe1a98       # 400017d6  = ldc_dimming_settings
	l32i.n	a11, a11, 8             # 400017d9
	l32r	a12, lit_3ffe1a98       # 400017db  = ldc_dimming_settings
	l32i.n	a12, a12, 24            # 400017de
	l32r	a13, lit_3ffe1a98       # 400017e0  = ldc_dimming_settings
	l32i.n	a13, a13, 28            # 400017e3
	call8	ldc_calc_percent_adim   # 400017e5
	l32r	a13, lit_3ffe1a98       # 400017e8  = ldc_dimming_settings
	s32i.n	a10, a13, 20            # 400017eb
	# if (panel.ldc_mode == 0 || panel.ldc_mode == 3)
	movi.n	a13, 0                  # 400017ed
	l32r	a12, lit_3ffe1a80       # 400017ef  = 0x3ffe2bf0
	l32i	a12, a12, 0x144         # 400017f2
	beq	a12, a13, .L40001801    # 400017f5
	l32r	a14, lit_3ffe1a80       # 400017f8  = 0x3ffe2bf0
	l32i	a14, a14, 0x144         # 400017fb
	bnei	a14, 3, .L40001816      # 400017fe
.L40001801:
	# lib_fill_halfwords(cfg.percent_adim, led_adim (0x3FFE3EF0), cfg.channel_count)
	l32r	a10, lit_3ffe1a98       # 40001801  = ldc_dimming_settings
	l32i.n	a10, a10, 20            # 40001804
	l32r	a11, lit_3ffe1ac4       # 40001806  = 0x3ffe3ef0
	l32r	a12, lit_3ffe1a98       # 40001809  = ldc_dimming_settings
	l32i.n	a12, a12, 0             # 4000180c
	call8	lib_fill_halfwords      # 4000180e
	# ldc_post_brightness_status(1)
	movi.n	a10, 1                  # 40001811
	call8	ldc_post_brightness_status # 40001813
.L40001816:
	# mailbox[0x28] = (cfg.percent_adim << 16) + cfg.user_pdim   (0xE0091028)
	l32r	a12, lit_3ffe1b28       # 40001816  = 0xe0091028
	l32r	a13, lit_3ffe1a98       # 40001819  = ldc_dimming_settings
	l32i.n	a13, a13, 20            # 4000181c
	slli	a13, a13, 16            # 4000181e
	l32r	a11, lit_3ffe1a98       # 40001821  = ldc_dimming_settings
	l32i.n	a11, a11, 16            # 40001824
	add.n	a11, a11, a13           # 40001826
	memw                            # 40001828
	s32i.n	a11, a12, 0             # 4000182b
	retw.n                          # 4000182d
	.size	ldc_cmd_set_adim_bright_percent, . - ldc_cmd_set_adim_bright_percent
