# ldc_cmd_set_user_pdim  (fn_400014c0): 0x400014c0-0x4000150e (firmware file offset 0x314c0-0x3150e), 31 instructions
# Name basis: proven - field printed as 'usUserPDIM'; table printed as 'LED PDIM'
# Address stored in the words at: 0x4000d2c4
# Calls: lib_fill_halfwords, ldc_post_brightness_status
# Addresses loaded: ldc_dimming_settings
# Other literal values: 0x00000fff, 0x3ffe3eb0, 0xe0091028
#
# Command 0x30 (sent by ldc_send_user_pdim): stores the value as usUserPDIM, at most 0xFFF, fills LED PDIM of
# every channel with it, posts the brightness status and writes PercentADIM << 16 + usUserPDIM to mailbox
# word 0xE0091028 (portal 2 +0x28).
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_user_pdim, @function
ldc_cmd_set_user_pdim:                  # fn_400014c0
	entry	a1, 48                  # 400014c0
	s32i.n	a2, a1, 0               # 400014c3
	s32i.n	a3, a1, 4               # 400014c5
	# cfg.user_pdim = value   (usUserPDIM, cfg +16)
	l32r	a8, lit_3ffe1a98        # 400014c7  = ldc_dimming_settings
	l32i.n	a7, a1, 4               # 400014ca
	s32i.n	a7, a8, 16              # 400014cc
	# if (cfg.user_pdim > 0xFFF) cfg.user_pdim = 0xFFF
	l32r	a6, lit_3ffe1a98        # 400014ce  = ldc_dimming_settings
	l32i.n	a6, a6, 16              # 400014d1
	l32r	a5, lit_3ffe1abc        # 400014d3  = 0x00000fff
	bgeu	a5, a6, .L400014e1      # 400014d6
	l32r	a9, lit_3ffe1a98        # 400014d9  = ldc_dimming_settings
	l32r	a8, lit_3ffe1abc        # 400014dc  = 0x00000fff
	s32i.n	a8, a9, 16              # 400014df
.L400014e1:
	# lib_fill_halfwords(cfg.user_pdim, led_pdim, cfg.channel_count)
	l32r	a10, lit_3ffe1a98       # 400014e1  = ldc_dimming_settings
	l32i.n	a10, a10, 16            # 400014e4
	l32r	a11, lit_3ffe1ac0       # 400014e6  = 0x3ffe3eb0
	l32r	a12, lit_3ffe1a98       # 400014e9  = ldc_dimming_settings
	l32i.n	a12, a12, 0             # 400014ec
	call8	lib_fill_halfwords      # 400014ee
	# ldc_post_brightness_status(1)
	movi.n	a10, 1                  # 400014f1
	call8	ldc_post_brightness_status # 400014f3
	# mailbox[0x28] = (cfg.percent_adim << 16) + cfg.user_pdim   (0xE0091028)
	l32r	a12, lit_3ffe1b28       # 400014f6  = 0xe0091028
	l32r	a13, lit_3ffe1a98       # 400014f9  = ldc_dimming_settings
	l32i.n	a13, a13, 20            # 400014fc
	slli	a13, a13, 16            # 400014fe
	l32r	a11, lit_3ffe1a98       # 40001501  = ldc_dimming_settings
	l32i.n	a11, a11, 16            # 40001504
	add.n	a11, a11, a13           # 40001506
	memw                            # 40001508
	s32i.n	a11, a12, 0             # 4000150b
	retw.n                          # 4000150d
	.size	ldc_cmd_set_user_pdim, . - ldc_cmd_set_user_pdim
