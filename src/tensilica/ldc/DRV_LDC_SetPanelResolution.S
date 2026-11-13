# DRV_LDC_SetPanelResolution  (fn_40006374): 0x40006374-0x400063d8 (firmware file offset 0x36374-0x363d8), 38 instructions
# Name basis: proven - original name printed 'DRV_LDC_SetPanelResolution,%u,%u'
# Called from: ldc_cmd_load_panel_and_start, ldc_hw_init
# Original name: the routine prints "DRV_LDC_SetPanelResolution,%u,%u". Stores the panel width and height in the
# segment grid record, writes them to register 0xE0080004 (width bits 0..15, height bits 16..31, a byte at a
# time) and recomputes the zone area factors (ldc_hw_set_zone_area_factors).
# Arguments: a2 width, a3 height (ldc_hw_init passes 3840 x 2160; ldc_cmd_load_panel_and_start, command 0x21, the panel size).
# Locals: a1+0 width, a1+4 height.
# Returns: nothing.
# Note: reg_write32_masked(addr, value, mask) does *addr = (*addr & ~mask) | (value & mask).
# Calls: dbg_printf, reg_write32_masked, ldc_hw_set_zone_area_factors
# Text loaded: "DRV_LDC_SetPanelResolution,%u,%u\r\n"
# Other literal values: 0x3ffe4450, 0xe0080004, 0x0000ff00, 0x00ff0000, 0xff000000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	DRV_LDC_SetPanelResolution, @function
DRV_LDC_SetPanelResolution:             # fn_40006374
	entry	a1, 48                  # 40006374
	s32i.n	a2, a1, 0               # 40006377
	s32i.n	a3, a1, 4               # 40006379
	# printf("DRV_LDC_SetPanelResolution,%u,%u\r\n", width, height);
	l32r	a10, lit_3ffe1e9c       # 4000637b  = ro_3ffe0ab4 "DRV_LDC_SetPanelResolution,%u,%u\r\n"
	l32i.n	a11, a1, 0              # 4000637e
	l32i.n	a12, a1, 4              # 40006380
	call8	dbg_printf              # 40006382
	# grid.width = width;   /* 0x3ffe4450 +16 */
	l32r	a14, lit_3ffe1a84       # 40006385  = 0x3ffe4450
	l32i.n	a13, a1, 0              # 40006388
	s32i.n	a13, a14, 16            # 4000638a
	# grid.height = height;   /* +20 */
	l32r	a13, lit_3ffe1a84       # 4000638c  = 0x3ffe4450
	l32i.n	a12, a1, 4              # 4000638f
	s32i.n	a12, a13, 20            # 40006391
	# reg_write32_masked(0xE0080004, width & 0xFF, 0xFF);
	l32r	a10, lit_3ffe1ea0       # 40006393  = 0xe0080004
	l32i.n	a11, a1, 0              # 40006396
	extui	a11, a11, 0, 8          # 40006398
	movi	a12, 255                # 4000639b
	call8	reg_write32_masked      # 4000639e
	# reg_write32_masked(0xE0080004, width & 0xFFFFFF00, 0xFF00);
	l32r	a10, lit_3ffe1ea0       # 400063a1  = 0xe0080004
	movi	a12, 0xffffff00         # 400063a4
	l32i.n	a11, a1, 0              # 400063a7
	and	a11, a11, a12           # 400063a9
	l32r	a12, lit_3ffe1d3c       # 400063ac  = 0x0000ff00
	call8	reg_write32_masked      # 400063af
	# reg_write32_masked(0xE0080004, (height & 0xFF) << 16, 0xFF0000);
	l32r	a10, lit_3ffe1ea0       # 400063b2  = 0xe0080004
	l32i.n	a11, a1, 4              # 400063b5
	extui	a11, a11, 0, 8          # 400063b7
	slli	a11, a11, 16            # 400063ba
	l32r	a12, lit_3ffe1ea4       # 400063bd  = 0x00ff0000
	call8	reg_write32_masked      # 400063c0
	# reg_write32_masked(0xE0080004, (height >> 8) << 24, 0xFF000000);
	l32r	a10, lit_3ffe1ea0       # 400063c3  = 0xe0080004
	l32i.n	a11, a1, 4              # 400063c6
	srli	a11, a11, 8             # 400063c8
	slli	a11, a11, 24            # 400063cb
	l32r	a12, lit_3ffe1ea8       # 400063ce  = 0xff000000
	call8	reg_write32_masked      # 400063d1
	# ldc_hw_set_zone_area_factors();
	call8	ldc_hw_set_zone_area_factors # 400063d4
	retw.n                          # 400063d7
	.size	DRV_LDC_SetPanelResolution, . - DRV_LDC_SetPanelResolution
