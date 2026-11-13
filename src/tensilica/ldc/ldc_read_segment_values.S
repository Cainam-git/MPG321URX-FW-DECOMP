# ldc_read_segment_values  (fn_40006804): 0x40006804-0x40006850 (firmware file offset 0x36804-0x36850), 33 instructions
# Name basis: derived - called by the interrupt 7 handler; (segment count + 1) / 2 words
# Called from: ldc_irq_handler
# Copies (segment count + 1) / 2 words from the dimming block at 0xE0083000 into the segment value array at
# 0x3ffe4490 (two 16-bit values per word). Called by the interrupt 7 handler ldc_irq_handler.
# Arguments: none.
# Locals: a1+0 i, a1+4 src (0xE0083000), a1+8 dst (0x3ffe4490).
# Returns: nothing.
# Addresses loaded: ldc_segment_count
# Other literal values: 0xe0083000, 0x3ffe4490

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_read_segment_values, @function
ldc_read_segment_values:                # fn_40006804
	entry	a1, 48                  # 40006804
	# src = 0xE0083000; dst = segment_values;
	movi.n	a7, 0                   # 40006807
	s32i.n	a7, a1, 0               # 40006809
	l32r	a6, lit_3ffe1f04        # 4000680b  = 0xe0083000
	s32i.n	a6, a1, 4               # 4000680e
	l32r	a5, lit_3ffe1b88        # 40006810  = 0x3ffe4490
	s32i.n	a5, a1, 8               # 40006813
	# for (i = 0; i < (segment_count + 1) / 2; i++)   /* segment_count = ldc_segment_count */
	movi.n	a4, 0                   # 40006815
	s32i.n	a4, a1, 0               # 40006817
	l32r	a3, lit_3ffe1a88        # 40006819  = ldc_segment_count
	l32i.n	a3, a3, 0               # 4000681c
	addi.n	a3, a3, 1               # 4000681e
	srli	a3, a3, 1               # 40006820
	l32i.n	a2, a1, 0               # 40006823
	bgeu	a2, a3, .L4000684f      # 40006825
.L40006828:
	#     ((u32 *)dst)[i] = ((volatile u32 *)src)[i];
	l32i.n	a12, a1, 0              # 40006828
	l32i.n	a13, a1, 8              # 4000682a
	addx4	a12, a12, a13           # 4000682c
	l32i.n	a11, a1, 0              # 4000682f
	l32i.n	a13, a1, 4              # 40006831
	addx4	a11, a11, a13           # 40006833
	l32i.n	a11, a11, 0             # 40006836
	s32i.n	a11, a12, 0             # 40006838
	#     /* i++, loop while i < (segment_count + 1) / 2 */
	l32i.n	a10, a1, 0              # 4000683a
	addi.n	a10, a10, 1             # 4000683c
	s32i.n	a10, a1, 0              # 4000683e
	l32r	a9, lit_3ffe1a88        # 40006840  = ldc_segment_count
	l32i.n	a9, a9, 0               # 40006843
	addi.n	a9, a9, 1               # 40006845
	srli	a9, a9, 1               # 40006847
	l32i.n	a8, a1, 0               # 4000684a
	bltu	a8, a9, .L40006828      # 4000684c
.L4000684f:
	retw.n                          # 4000684f
	.size	ldc_read_segment_values, . - ldc_read_segment_values
