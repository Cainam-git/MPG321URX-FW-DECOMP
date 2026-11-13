# DRV_LDC_UpdateSegmentBoundary  (fn_40006434): 0x40006434-0x4000660a (firmware file offset 0x36434-0x3660a), 188 instructions
# Name basis: proven - original name printed 'DRV_LDC_UpdateSegmentBoundary'
# Called from: DRV_LDC_SetLDCSegment
# Original name: the routine prints "DRV_LDC_UpdateSegmentBoundary". Divides the panel width into grid.columns
# and the panel height into grid.rows equal parts and writes the boundaries into the dimming block:
# for column i (1..columns) the end x = width * i / columns goes into a 13-bit half of 0xE0080900 + ((i-1)/2)*4
# (i <= 32) or 0xE0080800 + ((i-33)/2)*4 (i > 32), odd i in bits 0..12, even i in bits 16..28, and the pair
# {end x, start x} into 0xE0080980 + (i-1)*4 (i <= 32) or 0xE0080880 + (i-33)*4 (i > 32). For row j (1..rows)
# the end y = height * j / rows goes into a 12-bit half of 0xE0080940 + ((j-1)/2)*4, and the pair
# {end y - 1, start y} into 0xE0080680 + (j-1)*4.
# Arguments: none (uses the segment grid record at 0x3ffe4450: +0 columns, +4 rows, +16 width, +20 height).
# Locals: a1+0 x (end of the current column), a1+4 prev_x, a1+8 i (column, then row number), a1+12 y,
#   a1+16 prev_y, a1+20 / a1+24 mask of the column register half, a1+28 mask of the row register half.
# Returns: nothing.
# Calls: dbg_printf, reg_write32_masked
# Text loaded: "DRV_LDC_UpdateSegmentBoundary\r\n"
# Other literal values: 0x3ffe4450, 0x1fff0000, 0x00001fff, 0xe0080900, 0xe0080800, 0xe0080980, 0x1fff1fff,
#                       0xe0080880, 0x0fff0000, 0x00000fff, 0xe0080940, 0xe0080680, 0x0fff0fff

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	DRV_LDC_UpdateSegmentBoundary, @function
DRV_LDC_UpdateSegmentBoundary:          # fn_40006434
	entry	a1, 64                  # 40006434
	# printf("DRV_LDC_UpdateSegmentBoundary\r\n");
	l32r	a10, lit_3ffe1eb0       # 40006437  = ro_3ffe0ad8 "DRV_LDC_UpdateSegmentBoundary\r\n"
	call8	dbg_printf              # 4000643a
	# x = 0; prev_x = x;
	movi.n	a5, 0                   # 4000643d
	s32i.n	a5, a1, 0               # 4000643f
	l32i.n	a4, a1, 0               # 40006441
	s32i.n	a4, a1, 4               # 40006443
	# for (i = 1; i <= grid.columns; i++) {
	movi.n	a3, 1                   # 40006445
	s32i.n	a3, a1, 8               # 40006447
	l32i.n	a3, a1, 8               # 40006449
	l32r	a2, lit_3ffe1a84        # 4000644b  = 0x3ffe4450
	l32i.n	a2, a2, 0               # 4000644e
	bgeu	a2, a3, .L40006456      # 40006450
	j	.L4000655f              # 40006453
.L40006456:
	#     x = grid.width * i / grid.columns;
	l32r	a9, lit_3ffe1a84        # 40006456  = 0x3ffe4450
	l32i.n	a9, a9, 0               # 40006459
	l32i.n	a10, a1, 8              # 4000645b
	l32r	a8, lit_3ffe1a84        # 4000645d  = 0x3ffe4450
	l32i.n	a8, a8, 16              # 40006460
	mull	a8, a8, a10             # 40006462
	quou	a8, a8, a9              # 40006465
	s32i.n	a8, a1, 0               # 40006468
	#     if (i <= 32) {
	l32i.n	a7, a1, 8               # 4000646a
	movi.n	a6, 32                  # 4000646c
	blt	a6, a7, .L400064b6      # 4000646e
	#         mask = (i & 1) ? 0x1FFF : 0x1FFF0000;
	l32i.n	a10, a1, 8              # 40006471
	bbsi	a10, 0, .L4000647e      # 40006473
	l32r	a11, lit_3ffe1eb4       # 40006476  = 0x1fff0000
	s32i.n	a11, a1, 20             # 40006479
	j	.L40006483              # 4000647b
.L4000647e:
	l32r	a12, lit_3ffe1eb8       # 4000647e  = 0x00001fff
	s32i.n	a12, a1, 20             # 40006481
.L40006483:
	#         reg_write32_masked(0xE0080900 + ((i - 1) >> 1) * 4, (x & 0x1FFF) << ((i & 1) ? 0 : 16), mask);
	movi.n	a14, 0                  # 40006483
	l32i.n	a13, a1, 8              # 40006485
	extui	a13, a13, 0, 1          # 40006487
	movi.n	a11, 1                  # 4000648a
	movi.n	a12, 0                  # 4000648c
	moveqz	a12, a11, a13           # 4000648e
	l32r	a11, lit_3ffe1ebc       # 40006491  = 0xe0080900
	l32i.n	a10, a1, 8              # 40006494
	addi.n	a10, a10, -1            # 40006496
	srai	a10, a10, 1             # 40006498
	slli	a10, a10, 2             # 4000649b
	add.n	a10, a10, a11           # 4000649e
	l32i.n	a11, a1, 0              # 400064a0
	extui	a11, a11, 0, 13         # 400064a2
	slli	a12, a12, 4             # 400064a5
	ssl	a12                     # 400064a8
	sll	a11, a11                # 400064ab
	l32i.n	a12, a1, 20             # 400064ae
	call8	reg_write32_masked      # 400064b0
	j	.L400064f9              # 400064b3
.L400064b6:
	#     } else {
	#         mask = (i & 1) ? 0x1FFF : 0x1FFF0000;
	l32i.n	a15, a1, 8              # 400064b6
	bbsi	a15, 0, .L400064c3      # 400064b8
	l32r	a2, lit_3ffe1eb4        # 400064bb  = 0x1fff0000
	s32i.n	a2, a1, 24              # 400064be
	j	.L400064c8              # 400064c0
.L400064c3:
	l32r	a3, lit_3ffe1eb8        # 400064c3  = 0x00001fff
	s32i.n	a3, a1, 24              # 400064c6
.L400064c8:
	#         reg_write32_masked(0xE0080800 + ((i - 33) >> 1) * 4, (x & 0x1FFF) << ((i & 1) ? 0 : 16), mask);
	#     }
	movi.n	a14, 0                  # 400064c8
	l32i.n	a13, a1, 8              # 400064ca
	extui	a13, a13, 0, 1          # 400064cc
	movi.n	a11, 1                  # 400064cf
	movi.n	a12, 0                  # 400064d1
	moveqz	a12, a11, a13           # 400064d3
	l32r	a11, lit_3ffe1ec0       # 400064d6  = 0xe0080800
	l32i.n	a10, a1, 8              # 400064d9
	addi	a10, a10, -33           # 400064db
	srai	a10, a10, 1             # 400064de
	slli	a10, a10, 2             # 400064e1
	add.n	a10, a10, a11           # 400064e4
	l32i.n	a11, a1, 0              # 400064e6
	extui	a11, a11, 0, 13         # 400064e8
	slli	a12, a12, 4             # 400064eb
	ssl	a12                     # 400064ee
	sll	a11, a11                # 400064f1
	l32i.n	a12, a1, 24             # 400064f4
	call8	reg_write32_masked      # 400064f6
.L400064f9:
	#     if (i <= 32)
	l32i.n	a2, a1, 8               # 400064f9
	movi.n	a15, 32                 # 400064fb
	blt	a15, a2, .L40006525     # 400064fd
	#         reg_write32_masked(0xE0080980 + (i - 1) * 4, (x & 0x1FFF) << 16 | (prev_x & 0x1FFF), 0x1FFF1FFF);
	l32r	a11, lit_3ffe1ec4       # 40006500  = 0xe0080980
	l32i.n	a10, a1, 8              # 40006503
	addi.n	a10, a10, -1            # 40006505
	slli	a10, a10, 2             # 40006507
	add.n	a10, a10, a11           # 4000650a
	l32i.n	a12, a1, 0              # 4000650c
	extui	a12, a12, 0, 13         # 4000650e
	slli	a12, a12, 16            # 40006511
	l32i.n	a11, a1, 4              # 40006514
	extui	a11, a11, 0, 13         # 40006516
	or	a11, a11, a12           # 40006519
	l32r	a12, lit_3ffe1ec8       # 4000651c  = 0x1fff1fff
	call8	reg_write32_masked      # 4000651f
	j	.L40006548              # 40006522
.L40006525:
	#     else
	#         reg_write32_masked(0xE0080880 + (i - 33) * 4, (x & 0x1FFF) << 16 | (prev_x & 0x1FFF), 0x1FFF1FFF);
	l32r	a11, lit_3ffe1ecc       # 40006525  = 0xe0080880
	l32i.n	a10, a1, 8              # 40006528
	addi	a10, a10, -33           # 4000652a
	slli	a10, a10, 2             # 4000652d
	add.n	a10, a10, a11           # 40006530
	l32i.n	a12, a1, 0              # 40006532
	extui	a12, a12, 0, 13         # 40006534
	slli	a12, a12, 16            # 40006537
	l32i.n	a11, a1, 4              # 4000653a
	extui	a11, a11, 0, 13         # 4000653c
	or	a11, a11, a12           # 4000653f
	l32r	a12, lit_3ffe1ec8       # 40006542  = 0x1fff1fff
	call8	reg_write32_masked      # 40006545
.L40006548:
	#     prev_x = x;
	l32i.n	a13, a1, 0              # 40006548
	s32i.n	a13, a1, 4              # 4000654a
	#     /* i++, loop while i <= grid.columns */
	# }
	l32i.n	a12, a1, 8              # 4000654c
	addi.n	a12, a12, 1             # 4000654e
	s32i.n	a12, a1, 8              # 40006550
	l32i.n	a12, a1, 8              # 40006552
	l32r	a11, lit_3ffe1a84       # 40006554  = 0x3ffe4450
	l32i.n	a11, a11, 0             # 40006557
	bltu	a11, a12, .L4000655f    # 40006559
	j	.L40006456              # 4000655c
.L4000655f:
	# y = 0; prev_y = y;
	movi.n	a3, 0                   # 4000655f
	s32i.n	a3, a1, 12              # 40006561
	l32i.n	a2, a1, 12              # 40006563
	s32i.n	a2, a1, 16              # 40006565
	# for (i = 1; i <= grid.rows; i++) {
	movi.n	a15, 1                  # 40006567
	s32i.n	a15, a1, 8              # 40006569
	l32i.n	a15, a1, 8              # 4000656b
	l32r	a14, lit_3ffe1a84       # 4000656d  = 0x3ffe4450
	l32i.n	a14, a14, 4             # 40006570
	bgeu	a14, a15, .L40006578    # 40006572
	j	.L40006609              # 40006575
.L40006578:
	#     y = grid.height * i / grid.rows;
	l32r	a6, lit_3ffe1a84        # 40006578  = 0x3ffe4450
	l32i.n	a6, a6, 4               # 4000657b
	l32i.n	a7, a1, 8               # 4000657d
	l32r	a5, lit_3ffe1a84        # 4000657f  = 0x3ffe4450
	l32i.n	a5, a5, 20              # 40006582
	mull	a5, a5, a7              # 40006584
	quou	a5, a5, a6              # 40006587
	s32i.n	a5, a1, 12              # 4000658a
	#     mask = (i & 1) ? 0xFFF : 0x0FFF0000;
	l32i.n	a4, a1, 8               # 4000658c
	bbsi	a4, 0, .L40006599       # 4000658e
	l32r	a7, lit_3ffe1ed0        # 40006591  = 0x0fff0000
	s32i.n	a7, a1, 28              # 40006594
	j	.L4000659e              # 40006596
.L40006599:
	l32r	a8, lit_3ffe1abc        # 40006599  = 0x00000fff
	s32i.n	a8, a1, 28              # 4000659c
.L4000659e:
	#     reg_write32_masked(0xE0080940 + ((i - 1) >> 1) * 4, (y & 0xFFF) << ((i & 1) ? 0 : 16), mask);
	movi.n	a14, 0                  # 4000659e
	l32i.n	a13, a1, 8              # 400065a0
	extui	a13, a13, 0, 1          # 400065a2
	movi.n	a11, 1                  # 400065a5
	movi.n	a12, 0                  # 400065a7
	moveqz	a12, a11, a13           # 400065a9
	l32r	a11, lit_3ffe1ed4       # 400065ac  = 0xe0080940
	l32i.n	a10, a1, 8              # 400065af
	addi.n	a10, a10, -1            # 400065b1
	srai	a10, a10, 1             # 400065b3
	slli	a10, a10, 2             # 400065b6
	add.n	a10, a10, a11           # 400065b9
	l32i.n	a11, a1, 12             # 400065bb
	extui	a11, a11, 0, 12         # 400065bd
	slli	a12, a12, 4             # 400065c0
	ssl	a12                     # 400065c3
	sll	a11, a11                # 400065c6
	l32i.n	a12, a1, 28             # 400065c9
	call8	reg_write32_masked      # 400065cb
	#     reg_write32_masked(0xE0080680 + (i - 1) * 4, ((y - 1) & 0xFFF) << 16 | (prev_y & 0xFFF), 0x0FFF0FFF);
	l32r	a11, lit_3ffe1ed8       # 400065ce  = 0xe0080680
	l32i.n	a10, a1, 8              # 400065d1
	addi.n	a10, a10, -1            # 400065d3
	slli	a10, a10, 2             # 400065d5
	add.n	a10, a10, a11           # 400065d8
	l32i.n	a12, a1, 12             # 400065da
	addi.n	a12, a12, -1            # 400065dc
	extui	a12, a12, 0, 12         # 400065de
	slli	a12, a12, 16            # 400065e1
	l32i.n	a11, a1, 16             # 400065e4
	extui	a11, a11, 0, 12         # 400065e6
	or	a11, a11, a12           # 400065e9
	l32r	a12, lit_3ffe1edc       # 400065ec  = 0x0fff0fff
	call8	reg_write32_masked      # 400065ef
	#     prev_y = y;
	l32i.n	a13, a1, 12             # 400065f2
	s32i.n	a13, a1, 16             # 400065f4
	#     /* i++, loop while i <= grid.rows */
	l32i.n	a12, a1, 8              # 400065f6
	addi.n	a12, a12, 1             # 400065f8
	s32i.n	a12, a1, 8              # 400065fa
	l32i.n	a12, a1, 8              # 400065fc
	l32r	a11, lit_3ffe1a84       # 400065fe  = 0x3ffe4450
	l32i.n	a11, a11, 4             # 40006601
	bltu	a11, a12, .L40006609    # 40006603
	j	.L40006578              # 40006606
.L40006609:
	# }
	retw.n                          # 40006609
	.size	DRV_LDC_UpdateSegmentBoundary, . - DRV_LDC_UpdateSegmentBoundary
