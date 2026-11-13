# ldc_select_led_driver  (fn_40000de8): 0x40000de8-0x40000e1c (firmware file offset 0x30de8-0x30e1c), 19 instructions
# Name basis: derived - argument is panel +24, printed as 'DriverType: Type'; pointer +0x13C called by
#   ldc_follow_mode_and_run_led_driver
# Called from: ldc_init_panel_defaults, ldc_cmd_load_panel_and_start
# Calls: ldc_units_setup_driver_type2
# Addresses loaded: ldc_as3824_update, ldc_led_driver_type2_update, ldc_led_driver_type0_update
# Other literal values: 0x3ffe2bf0
#
# Stores the LED driver routine for a driver type in panel +0x13C (called through it by ldc_follow_mode_and_run_led_driver):
# type 1 -> ldc_as3824_update, type 2 -> ldc_led_driver_type2_update (and runs ldc_units_setup_driver_type2 once), any other type -> ldc_led_driver_type0_update.
# a2 = driver_type (panel +24, printed as "DriverType: Type")
# Locals: a1+0 = driver_type.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_select_led_driver, @function
ldc_select_led_driver:                  # fn_40000de8
	entry	a1, 48                  # 40000de8
	s32i.n	a2, a1, 0               # 40000deb
	# if (driver_type == 1) panel.led_driver_fn = ldc_as3824_update
	l32i.n	a4, a1, 0               # 40000ded
	bnei	a4, 1, .L40000dfe       # 40000def
	l32r	a6, lit_3ffe1a80        # 40000df2  = 0x3ffe2bf0
	l32r	a5, lit_3ffe1a9c        # 40000df5  = ldc_as3824_update
	s32i	a5, a6, 0x13c           # 40000df8
	j	.L40000e1b              # 40000dfb
.L40000dfe:
	# else if (driver_type == 2) { panel.led_driver_fn = ldc_led_driver_type2_update; ldc_units_setup_driver_type2(); }
	l32i.n	a7, a1, 0               # 40000dfe
	bnei	a7, 2, .L40000e12       # 40000e00
	l32r	a9, lit_3ffe1a80        # 40000e03  = 0x3ffe2bf0
	l32r	a8, lit_3ffe1aa0        # 40000e06  = ldc_led_driver_type2_update
	s32i	a8, a9, 0x13c           # 40000e09
	call8	ldc_units_setup_driver_type2 # 40000e0c
	j	.L40000e1b              # 40000e0f
.L40000e12:
	# else panel.led_driver_fn = ldc_led_driver_type0_update
	l32r	a11, lit_3ffe1a80       # 40000e12  = 0x3ffe2bf0
	l32r	a10, lit_3ffe1aa4       # 40000e15  = ldc_led_driver_type0_update
	s32i	a10, a11, 0x13c         # 40000e18
.L40000e1b:
	retw.n                          # 40000e1b
	.size	ldc_select_led_driver, . - ldc_select_led_driver
