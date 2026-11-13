# DRV_LDC_SetDSRegisters  (fn_400066d4): 0x400066d4-0x40006709 (firmware file offset 0x366d4-0x36709), 20 instructions
# Name basis: proven - original name printed 'DRV_LDC_SetDSRegisters'
# Called from: ldc_set_ds_divider
# Original name: the routine prints "DRV_LDC_SetDSRegisters". Writes panel width / DS divider (segment grid
# record +48) to bits 16..31 of register 0xE0080040 and the DS divider itself to bits 0..7 of 0xE0080370.
# Arguments: none.
# Locals: a1+0 ds_width (grid.width / grid.ds_divider).
# Returns: nothing.
# Calls: dbg_printf, reg_write32_masked
# Text loaded: "DRV_LDC_SetDSRegisters\r\n"
# Other literal values: 0x3ffe4450, 0xe0080040, 0xffff0000, 0xe0080370

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	DRV_LDC_SetDSRegisters, @function
DRV_LDC_SetDSRegisters:                 # fn_400066d4
	entry	a1, 48                  # 400066d4
	# printf("DRV_LDC_SetDSRegisters\r\n");
	l32r	a10, lit_3ffe1ee4       # 400066d7  = ro_3ffe0b10 "DRV_LDC_SetDSRegisters\r\n"
	call8	dbg_printf              # 400066da
	# ds_width = grid.width / grid.ds_divider;   /* 0x3ffe4450 +16 / +48 */
	l32r	a13, lit_3ffe1a84       # 400066dd  = 0x3ffe4450
	l32i.n	a13, a13, 48            # 400066e0
	l32r	a12, lit_3ffe1a84       # 400066e2  = 0x3ffe4450
	l32i.n	a12, a12, 16            # 400066e5
	quou	a12, a12, a13           # 400066e7
	s32i.n	a12, a1, 0              # 400066ea
	# reg_write32_masked(0xE0080040, ds_width << 16, 0xFFFF0000);
	l32r	a10, lit_3ffe1ee8       # 400066ec  = 0xe0080040
	l32i.n	a11, a1, 0              # 400066ef
	slli	a11, a11, 16            # 400066f1
	l32r	a12, lit_3ffe1eec       # 400066f4  = 0xffff0000
	call8	reg_write32_masked      # 400066f7
	# reg_write32_masked(0xE0080370, grid.ds_divider, 0xFF);
	l32r	a10, lit_3ffe1be4       # 400066fa  = 0xe0080370
	l32r	a11, lit_3ffe1a84       # 400066fd  = 0x3ffe4450
	l32i.n	a11, a11, 48            # 40006700
	movi	a12, 255                # 40006702
	call8	reg_write32_masked      # 40006705
	retw.n                          # 40006708
	.size	DRV_LDC_SetDSRegisters, . - DRV_LDC_SetDSRegisters
