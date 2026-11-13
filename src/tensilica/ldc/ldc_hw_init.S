# ldc_hw_init  (fn_400068c0): 0x400068c0-0x40006902 (firmware file offset 0x368c0-0x36902), 26 instructions
# Name basis: derived - called once by the main routine; calls every set-up routine with start values
# Called from: sys_init_and_run_main_loop
# Start-up set-up of the dimming block, called once by the main routine sys_init_and_run_main_loop: presets the segment values,
# loads the default register table and then sets each register group with its start value: register 0x160,
# zone-count exponents 5 and 6, panel size 3840 x 2160, segment grid 32 x 16, DS divider 32, register 0x168
# fields 56 / 20, gain filter mode 4, register 0x28C bits 4..6 = 3, LDC mode 0.
# Arguments: none.
# Locals: none.
# Returns: nothing.
# Calls: ldc_preset_segment_values, ldc_hw_load_default_registers, ldc_hw_write_reg160,
#        ldc_set_zone_count_exponents, DRV_LDC_SetPanelResolution, DRV_LDC_SetLDCSegment, ldc_set_ds_divider,
#        ldc_hw_set_reg168_fields, ldc_hw_apply_gain_filter_mode, ldc_hw_set_reg28c_bits4_6,
#        ldc_hw_apply_ldc_mode
# Other literal values: 0x08802000, 0x00000f00, 0x00000870

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_hw_init, @function
ldc_hw_init:                            # fn_400068c0
	entry	a1, 32                  # 400068c0
	# ldc_preset_segment_values();
	call8	ldc_preset_segment_values # 400068c3
	# ldc_hw_load_default_registers();
	call8	ldc_hw_load_default_registers # 400068c6
	# ldc_hw_write_reg160(0x08802000);
	l32r	a10, lit_3ffe1f10       # 400068c9  = 0x08802000
	call8	ldc_hw_write_reg160     # 400068cc
	# ldc_set_zone_count_exponents(5, 6);
	movi.n	a10, 5                  # 400068cf
	movi.n	a11, 6                  # 400068d1
	call8	ldc_set_zone_count_exponents # 400068d3
	# DRV_LDC_SetPanelResolution(3840, 2160);
	l32r	a10, lit_3ffe1acc       # 400068d6  = 0x00000f00
	l32r	a11, lit_3ffe1ac8       # 400068d9  = 0x00000870
	call8	DRV_LDC_SetPanelResolution # 400068dc
	# DRV_LDC_SetLDCSegment(32, 16);
	movi.n	a10, 32                 # 400068df
	movi.n	a11, 16                 # 400068e1
	call8	DRV_LDC_SetLDCSegment   # 400068e3
	# ldc_set_ds_divider(32);
	movi.n	a10, 32                 # 400068e6
	call8	ldc_set_ds_divider      # 400068e8
	# ldc_hw_set_reg168_fields(56, 20);
	movi.n	a10, 56                 # 400068eb
	movi.n	a11, 20                 # 400068ed
	call8	ldc_hw_set_reg168_fields # 400068ef
	# ldc_hw_apply_gain_filter_mode(4);
	movi.n	a10, 4                  # 400068f2
	call8	ldc_hw_apply_gain_filter_mode # 400068f4
	# ldc_hw_set_reg28c_bits4_6(3);
	movi.n	a10, 3                  # 400068f7
	call8	ldc_hw_set_reg28c_bits4_6 # 400068f9
	# ldc_hw_apply_ldc_mode(0);
	movi.n	a10, 0                  # 400068fc
	call8	ldc_hw_apply_ldc_mode   # 400068fe
	retw.n                          # 40006901
	.size	ldc_hw_init, . - ldc_hw_init
