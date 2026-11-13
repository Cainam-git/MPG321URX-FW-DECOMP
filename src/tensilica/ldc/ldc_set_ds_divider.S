# ldc_set_ds_divider  (fn_4000670c): 0x4000670c-0x40006722 (firmware file offset 0x3670c-0x36722), 9 instructions
# Name basis: derived - stores the value read by DRV_LDC_SetDSRegisters and calls it
# Called from: ldc_cmd_load_panel_and_start, ldc_cmd_set_ds_divider, ldc_hw_init
# Stores the low byte of the value as DS divider (segment grid record +48) and writes the DS registers
# (DRV_LDC_SetDSRegisters). ldc_hw_init passes 32; command 0x46 (ldc_cmd_set_ds_divider) passes the low byte of its value.
# Arguments: a2 divider.
# Locals: a1+0 divider.
# Returns: nothing.
# Calls: DRV_LDC_SetDSRegisters
# Other literal values: 0x3ffe4450

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_set_ds_divider, @function
ldc_set_ds_divider:                     # fn_4000670c
	entry	a1, 48                  # 4000670c
	# grid.ds_divider = (u8)divider;   /* 0x3ffe4450 +48 */
	s32i.n	a2, a1, 0               # 4000670f
	l32r	a5, lit_3ffe1a84        # 40006711  = 0x3ffe4450
	l32i.n	a4, a1, 0               # 40006714
	sext	a4, a4, 7               # 40006716
	extui	a4, a4, 0, 8            # 40006719
	s32i.n	a4, a5, 48              # 4000671c
	# DRV_LDC_SetDSRegisters();
	call8	DRV_LDC_SetDSRegisters  # 4000671e
	retw.n                          # 40006721
	.size	ldc_set_ds_divider, . - ldc_set_ds_divider
