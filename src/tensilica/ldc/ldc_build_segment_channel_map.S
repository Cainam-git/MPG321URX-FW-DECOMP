# ldc_build_segment_channel_map  (fn_400008c0): 0x400008c0-0x4000099e (firmware file offset 0x308c0-0x3099e), 95 instructions
# Name basis: derived - LED rows/cols (printed LED_row/LED_col) and segment grid from DRV_LDC_SetLDCSegment;
#   tables read by the merge routines
# Called from: ldc_init_panel_defaults, ldc_cmd_load_panel_and_start, ldc_cmd_set_segment_grid
# Calls: lib_pack_word_pairs
# Addresses loaded: ldc_segment_count
# Other literal values: 0x3ffe2bf0, 0x3ffe4450, 0x3ffe2d70, 0x00000800, 0x3ffe3d70
#
# Assigns every segment of the segment grid to one LED channel of the LED grid and counts the segments of
# each channel. Results go to two 16-bit tables: 0x3FFE2D70 (channel of each segment, 2048 entries) and
# 0x3FFE3D70 (number of segments of each channel, 32 entries); the merge routines read both.
# Arguments: none.
# Locals: a1+4 = led_rows (panel +16, printed as LED_row), a1+8 = led_cols (panel +20, printed as LED_col),
#   a1+12 = seg_cols (0x3FFE4450 +0, set by DRV_LDC_SetLDCSegment), a1+16 = seg_rows
#   (0x3FFE4450 +4), a1+20 = i, a1+32 = segs_of_channel[32] (words), a1+160 = channel_of_segment[2048] (words).
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_build_segment_channel_map, @function
ldc_build_segment_channel_map:          # fn_400008c0
	entry	a1, 0x20c0              # 400008c0
	# a7 = &segs_of_channel[0] (a1+32); channel_of_segment follows at a7 + 128
	movi.n	a7, 32                  # 400008c3
	add.n	a7, a1, a7              # 400008c5
	# led_rows = panel.led_rows; led_cols = panel.led_cols
	l32r	a10, lit_3ffe1a80       # 400008c7  = 0x3ffe2bf0
	l32i.n	a10, a10, 16            # 400008ca
	s32i.n	a10, a1, 4              # 400008cc
	l32r	a9, lit_3ffe1a80        # 400008ce  = 0x3ffe2bf0
	l32i.n	a9, a9, 20              # 400008d1
	s32i.n	a9, a1, 8               # 400008d3
	# seg_cols = segment_grid.cols; seg_rows = segment_grid.rows
	l32r	a8, lit_3ffe1a84        # 400008d5  = 0x3ffe4450
	l32i.n	a8, a8, 0               # 400008d8
	s32i.n	a8, a1, 12              # 400008da
	l32r	a6, lit_3ffe1a84        # 400008dc  = 0x3ffe4450
	l32i.n	a6, a6, 4               # 400008df
	s32i.n	a6, a1, 16              # 400008e1
	# for (i = 0; i <= 31; i++)   (i = 0 is stored twice)
	movi.n	a5, 0                   # 400008e3
	s32i.n	a5, a1, 20              # 400008e5
	movi.n	a4, 0                   # 400008e7
	s32i.n	a4, a1, 20              # 400008e9
	l32i.n	a3, a1, 20              # 400008eb
	movi.n	a2, 31                  # 400008ed
	bltu	a2, a3, .L4000090a      # 400008ef
.L400008f2:
	# segs_of_channel[i] = 0
	l32i.n	a15, a1, 20             # 400008f2
	mov.n	a2, a7                  # 400008f4
	addx4	a15, a15, a2            # 400008f6
	movi.n	a14, 0                  # 400008f9
	s32i.n	a14, a15, 0             # 400008fb
	l32i.n	a13, a1, 20             # 400008fd
	addi.n	a13, a13, 1             # 400008ff
	s32i.n	a13, a1, 20             # 40000901
	l32i.n	a12, a1, 20             # 40000903
	movi.n	a11, 31                 # 40000905
	bgeu	a11, a12, .L400008f2    # 40000907
.L4000090a:
	# for (i = 0; i < segment_count; i++)   (segment_count = ldc_segment_count = seg_cols * seg_rows)
	movi.n	a5, 0                   # 4000090a
	s32i.n	a5, a1, 20              # 4000090c
	l32r	a4, lit_3ffe1a88        # 4000090e  = ldc_segment_count
	l32i.n	a4, a4, 0               # 40000911
	l32i.n	a3, a1, 20              # 40000913
	bgeu	a3, a4, .L40000985      # 40000915
.L40000918:
	# channel_of_segment[i] = led_cols * ((led_rows * i / seg_cols) / seg_rows)
	#                         + led_cols * (i % seg_cols) / seg_cols
	l32i.n	a13, a1, 20             # 40000918
	addi	a14, a7, 127            # 4000091a
	addi.n	a14, a14, 1             # 4000091d
	addx4	a13, a13, a14           # 4000091f
	l32i.n	a2, a1, 16              # 40000922
	l32i.n	a3, a1, 12              # 40000924
	l32i.n	a4, a1, 20              # 40000926
	l32i.n	a15, a1, 4              # 40000928
	mull	a15, a15, a4            # 4000092a
	quou	a15, a15, a3            # 4000092d
	quou	a15, a15, a2            # 40000930
	l32i.n	a14, a1, 8              # 40000933
	mull	a14, a14, a15           # 40000935
	l32i.n	a15, a1, 12             # 40000938
	l32i.n	a3, a1, 12              # 4000093a
	l32i.n	a2, a1, 20              # 4000093c
	remu	a2, a2, a3              # 4000093e
	l32i.n	a12, a1, 8              # 40000941
	mull	a12, a12, a2            # 40000943
	quou	a12, a12, a15           # 40000946
	add.n	a12, a12, a14           # 40000949
	s32i.n	a12, a13, 0             # 4000094b
	# segs_of_channel[channel_of_segment[i]]++
	l32i.n	a10, a1, 20             # 4000094d
	addi	a11, a7, 127            # 4000094f
	addi.n	a11, a11, 1             # 40000952
	addx4	a10, a10, a11           # 40000954
	l32i.n	a10, a10, 0             # 40000957
	l32i.n	a11, a1, 20             # 40000959
	addi	a12, a7, 127            # 4000095b
	addi.n	a12, a12, 1             # 4000095e
	addx4	a11, a11, a12           # 40000960
	l32i.n	a11, a11, 0             # 40000963
	mov.n	a12, a7                 # 40000965
	addx4	a11, a11, a12           # 40000967
	mov.n	a12, a7                 # 4000096a
	addx4	a10, a10, a12           # 4000096c
	l32i.n	a10, a10, 0             # 4000096f
	addi.n	a10, a10, 1             # 40000971
	s32i.n	a10, a11, 0             # 40000973
	# i++; loop while i < segment_count
	l32i.n	a9, a1, 20              # 40000975
	addi.n	a9, a9, 1               # 40000977
	s32i.n	a9, a1, 20              # 40000979
	l32r	a8, lit_3ffe1a88        # 4000097b  = ldc_segment_count
	l32i.n	a8, a8, 0               # 4000097e
	l32i.n	a6, a1, 20              # 40000980
	bltu	a6, a8, .L40000918      # 40000982
.L40000985:
	# lib_pack_word_pairs(channel_of_segment, 0x3FFE2D70, 0x800)   (2048 entries to 16 bits)
	addi	a10, a7, 127            # 40000985
	addi.n	a10, a10, 1             # 40000988
	l32r	a11, lit_3ffe1a8c       # 4000098a  = 0x3ffe2d70
	l32r	a12, lit_3ffe1a90       # 4000098d  = 0x00000800
	call8	lib_pack_word_pairs     # 40000990
	# lib_pack_word_pairs(segs_of_channel, 0x3FFE3D70, 32)
	mov.n	a10, a7                 # 40000993
	l32r	a11, lit_3ffe1a94       # 40000995  = 0x3ffe3d70
	movi.n	a12, 32                 # 40000998
	call8	lib_pack_word_pairs     # 4000099a
	retw.n                          # 4000099d
	.size	ldc_build_segment_channel_map, . - ldc_build_segment_channel_map
