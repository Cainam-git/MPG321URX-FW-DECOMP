# ldc_cmd_load_panel_and_start  (fn_40001344): 0x40001344-0x4000139c (firmware file offset 0x31344-0x3139c), 34 instructions
# Name basis: derived - command table 0x4000D288; sender ldc_send_panel_size_and_start; docs/MAP.md
# Address stored in the words at: 0x4000d29c
# Calls: LDC_LoadPanel, DRV_LDC_SetPanelResolution, DRV_LDC_SetLDCSegment, ldc_set_ds_divider,
#        ldc_select_led_driver, ldc_build_segment_channel_map
# Other literal values: 0x3ffe2bf0, 0x3ffe4450, 0x00000d70, 0x00001400
#
# Command 0x21 (sent by ldc_send_panel_size_and_start). With value 1: loads the panel description
# (LDC_LoadPanel), sets the panel resolution (DRV_LDC_SetPanelResolution) and the current
# segment grid again (DRV_LDC_SetLDCSegment), calls ldc_set_ds_divider with 16 for panel width 3440
# or 5120 and with 32 otherwise, selects the LED driver and rebuilds the segment-to-channel map.
# Other values do nothing.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_load_panel_and_start, @function
ldc_cmd_load_panel_and_start:           # fn_40001344
	entry	a1, 48                  # 40001344
	s32i.n	a2, a1, 0               # 40001347
	s32i.n	a3, a1, 4               # 40001349
	# if (value == 1)
	l32i.n	a5, a1, 4               # 4000134b
	bnei	a5, 1, .L4000139b       # 4000134d
	# LDC_LoadPanel()
	call8	LDC_LoadPanel           # 40001350
	# DRV_LDC_SetPanelResolution(panel.width, panel.height)   ("DRV_LDC_SetPanelResolution")
	l32r	a10, lit_3ffe1a80       # 40001353  = 0x3ffe2bf0
	l32i.n	a10, a10, 0             # 40001356
	l32r	a11, lit_3ffe1a80       # 40001358  = 0x3ffe2bf0
	l32i.n	a11, a11, 4             # 4000135b
	call8	DRV_LDC_SetPanelResolution # 4000135d
	# DRV_LDC_SetLDCSegment(segment_grid.cols, segment_grid.rows)   ("DRV_LDC_SetLDCSegment")
	l32r	a10, lit_3ffe1a84       # 40001360  = 0x3ffe4450
	l32i.n	a10, a10, 0             # 40001363
	l32r	a11, lit_3ffe1a84       # 40001365  = 0x3ffe4450
	l32i.n	a11, a11, 4             # 40001368
	call8	DRV_LDC_SetLDCSegment   # 4000136a
	# if (panel.width == 0xD70 || panel.width == 0x1400) ldc_set_ds_divider(16)
	l32r	a12, lit_3ffe1b18       # 4000136d  = 0x00000d70
	l32r	a11, lit_3ffe1a80       # 40001370  = 0x3ffe2bf0
	l32i.n	a11, a11, 0             # 40001373
	beq	a11, a12, .L40001383    # 40001375
	l32r	a13, lit_3ffe1b1c       # 40001378  = 0x00001400
	l32r	a12, lit_3ffe1a80       # 4000137b  = 0x3ffe2bf0
	l32i.n	a12, a12, 0             # 4000137e
	bne	a12, a13, .L4000138b    # 40001380
.L40001383:
	movi.n	a10, 16                 # 40001383
	call8	ldc_set_ds_divider      # 40001385
	j	.L40001390              # 40001388
.L4000138b:
	# else ldc_set_ds_divider(32)
	movi.n	a10, 32                 # 4000138b
	call8	ldc_set_ds_divider      # 4000138d
.L40001390:
	# ldc_select_led_driver(panel.driver_type)
	l32r	a10, lit_3ffe1a80       # 40001390  = 0x3ffe2bf0
	l32i.n	a10, a10, 24            # 40001393
	call8	ldc_select_led_driver   # 40001395
	# ldc_build_segment_channel_map()
	call8	ldc_build_segment_channel_map # 40001398
.L4000139b:
	retw.n                          # 4000139b
	.size	ldc_cmd_load_panel_and_start, . - ldc_cmd_load_panel_and_start
