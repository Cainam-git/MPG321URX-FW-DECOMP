# DRV_LDC_SetLDCSegment  (fn_4000660c): 0x4000660c-0x400066d2 (firmware file offset 0x3660c-0x366d2), 72 instructions
# Name basis: proven - original name printed 'DRV_LDC_SetLDCSegment'
# Called from: ldc_cmd_load_panel_and_start, ldc_cmd_set_segment_grid, ldc_hw_init
# Original name: the routine prints "DRV_LDC_SetLDCSegment". Sets the segment grid: clamps the column count to
# 1..64 and the row count to 1..32, stores both and their product (segment count, ldc_segment_count), writes them
# to bits 0..7 / 8..15 of register 0xE0080000, clears bits 16..23 and writes the column count to bits 24..31 of
# 0xE0080280, writes the segment boundaries (DRV_LDC_UpdateSegmentBoundary) and waits. Bit 0 of 0xE008000C is cleared while it
# works and the register is restored to its earlier value at the end.
# Arguments: a2 columns (byte), a3 rows (byte). ldc_hw_init passes 32 x 16.
# Locals: a1+0 saved (old value of 0xE008000C), a1+16 columns, a1+20 rows.
# Returns: nothing.
# Calls: dbg_printf, reg_write32_masked, DRV_LDC_UpdateSegmentBoundary, timer_wait_ticks
# Text loaded: "DRV_LDC_SetLDCSegment\r\n"
# Addresses loaded: ldc_segment_count
# Other literal values: 0xe008000c, 0x3ffe4450, 0xe0080000, 0x0000ff00, 0xe0080280, 0x00ff0000, 0xff000000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	DRV_LDC_SetLDCSegment, @function
DRV_LDC_SetLDCSegment:                  # fn_4000660c
	entry	a1, 64                  # 4000660c
	# columns = (u8)a2; rows = (u8)a3;
	extui	a4, a2, 0, 8            # 4000660f
	s8i	a4, a1, 16              # 40006612
	extui	a2, a3, 0, 8            # 40006615
	s8i	a2, a1, 20              # 40006618
	# printf("DRV_LDC_SetLDCSegment\r\n");
	l32r	a10, lit_3ffe1ee0       # 4000661b  = ro_3ffe0af8 "DRV_LDC_SetLDCSegment\r\n"
	call8	dbg_printf              # 4000661e
	# saved = reg[0x00C];   /* reg[x] = 32-bit register at 0xE0080000 + x */
	l32r	a8, lit_3ffe1e74        # 40006621  = 0xe008000c
	memw                            # 40006624
	l32i.n	a8, a8, 0               # 40006627
	s32i.n	a8, a1, 0               # 40006629
	# reg[0x00C] &= ~1;
	l32r	a8, lit_3ffe1e74        # 4000662b  = 0xe008000c
	movi.n	a9, -2                  # 4000662e
	l32r	a7, lit_3ffe1e74        # 40006630  = 0xe008000c
	memw                            # 40006633
	l32i.n	a7, a7, 0               # 40006636
	and	a7, a7, a9              # 40006638
	memw                            # 4000663b
	s32i.n	a7, a8, 0               # 4000663e
	# columns = max(min(columns, 64), 1);
	movi.n	a7, 64                  # 40006640
	l8ui	a6, a1, 16              # 40006642
	minu	a6, a6, a7              # 40006645
	s8i	a6, a1, 16              # 40006648
	movi.n	a6, 1                   # 4000664b
	l8ui	a5, a1, 16              # 4000664d
	maxu	a5, a5, a6              # 40006650
	s8i	a5, a1, 16              # 40006653
	# rows = max(min(rows, 32), 1);
	movi.n	a5, 32                  # 40006656
	l8ui	a4, a1, 20              # 40006658
	minu	a4, a4, a5              # 4000665b
	s8i	a4, a1, 20              # 4000665e
	movi.n	a4, 1                   # 40006661
	l8ui	a3, a1, 20              # 40006663
	maxu	a3, a3, a4              # 40006666
	s8i	a3, a1, 20              # 40006669
	# grid.columns = columns;   /* 0x3ffe4450 +0 */
	l32r	a3, lit_3ffe1a84        # 4000666c  = 0x3ffe4450
	l8ui	a2, a1, 16              # 4000666f
	s32i.n	a2, a3, 0               # 40006672
	# grid.rows = rows;   /* +4 */
	l32r	a2, lit_3ffe1a84        # 40006674  = 0x3ffe4450
	l8ui	a15, a1, 20             # 40006677
	s32i.n	a15, a2, 4              # 4000667a
	# segment_count = columns * rows;   /* ldc_segment_count */
	l32r	a13, lit_3ffe1a88       # 4000667c  = ldc_segment_count
	l8ui	a14, a1, 20             # 4000667f
	l8ui	a12, a1, 16             # 40006682
	mull	a12, a12, a14           # 40006685
	s32i.n	a12, a13, 0             # 40006688
	# reg_write32_masked(0xE0080000, columns, 0xFF);
	l32r	a10, lit_3ffe1b74       # 4000668a  = 0xe0080000
	l8ui	a11, a1, 16             # 4000668d
	movi	a12, 255                # 40006690
	call8	reg_write32_masked      # 40006693
	# reg_write32_masked(0xE0080000, rows << 8, 0xFF00);
	l32r	a10, lit_3ffe1b74       # 40006696  = 0xe0080000
	l8ui	a11, a1, 20             # 40006699
	slli	a11, a11, 8             # 4000669c
	l32r	a12, lit_3ffe1d3c       # 4000669f  = 0x0000ff00
	call8	reg_write32_masked      # 400066a2
	# reg_write32_masked(0xE0080280, 0, 0xFF0000);
	l32r	a10, lit_3ffe1eac       # 400066a5  = 0xe0080280
	movi.n	a11, 0                  # 400066a8
	l32r	a12, lit_3ffe1ea4       # 400066aa  = 0x00ff0000
	call8	reg_write32_masked      # 400066ad
	# reg_write32_masked(0xE0080280, columns << 24, 0xFF000000);
	l32r	a10, lit_3ffe1eac       # 400066b0  = 0xe0080280
	l8ui	a11, a1, 16             # 400066b3
	slli	a11, a11, 24            # 400066b6
	l32r	a12, lit_3ffe1ea8       # 400066b9  = 0xff000000
	call8	reg_write32_masked      # 400066bc
	# DRV_LDC_UpdateSegmentBoundary();
	call8	DRV_LDC_UpdateSegmentBoundary # 400066bf
	# timer_wait_ticks(50);   /* waits until the counter at 0x3ffe5598 +24 has moved on by 50 */
	movi.n	a10, 50                 # 400066c2
	call8	timer_wait_ticks        # 400066c4
	# reg[0x00C] = saved;
	l32r	a13, lit_3ffe1e74       # 400066c7  = 0xe008000c
	l32i.n	a12, a1, 0              # 400066ca
	memw                            # 400066cc
	s32i.n	a12, a13, 0             # 400066cf
	retw.n                          # 400066d1
	.size	DRV_LDC_SetLDCSegment, . - DRV_LDC_SetLDCSegment
