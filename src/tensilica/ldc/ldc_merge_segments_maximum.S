# ldc_merge_segments_maximum  (fn_400009a0): 0x400009a0-0x40000a04 (firmware file offset 0x309a0-0x30a04), 43 instructions
# Name basis: proven - stored by ldc_cmd_set_segment_merge_mode with text 'Segment Merge Mode: Maximum'
# Address stored in the words at: 0x4000c7d8
# Addresses loaded: ldc_segment_count
# Other literal values: 0x3ffe2d70
#
# Segment merge mode "Maximum" (selected by ldc_cmd_set_segment_merge_mode, command 0x41, value 0; also the start-up default):
# for every segment, raises the value of its LED channel to the segment's value when that is larger.
# The output is not cleared here.
# a2 = seg_values: 16-bit value of each segment
# a3 = out: one word per LED channel
# Locals: a1+0 = i (segment), a1+4 = ch (channel of segment i).
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_merge_segments_maximum, @function
ldc_merge_segments_maximum:             # fn_400009a0
	entry	a1, 64                  # 400009a0
	s32i.n	a2, a1, 16              # 400009a3
	s32i.n	a3, a1, 20              # 400009a5
	# i = 0; ch = 0
	movi.n	a9, 0                   # 400009a7
	s32i.n	a9, a1, 0               # 400009a9
	movi.n	a8, 0                   # 400009ab
	s32i.n	a8, a1, 4               # 400009ad
	# for (i = 0; i < segment_count; i++)
	movi.n	a7, 0                   # 400009af
	s32i.n	a7, a1, 0               # 400009b1
	l32r	a6, lit_3ffe1a88        # 400009b3  = ldc_segment_count
	l32i.n	a6, a6, 0               # 400009b6
	l32i.n	a5, a1, 0               # 400009b8
	bgeu	a5, a6, .L40000a03      # 400009ba
.L400009bd:
	# ch = channel_of_segment[i]   (16-bit table 0x3FFE2D70)
	l32i.n	a13, a1, 0              # 400009bd
	l32r	a14, lit_3ffe1a8c       # 400009bf  = 0x3ffe2d70
	addx2	a13, a13, a14           # 400009c2
	l16ui	a13, a13, 0             # 400009c5
	s32i.n	a13, a1, 4              # 400009c8
	# if (out[ch] < seg_values[i]) out[ch] = seg_values[i]
	l32i.n	a11, a1, 0              # 400009ca
	l32i.n	a12, a1, 16             # 400009cc
	addx2	a11, a11, a12           # 400009ce
	l16ui	a11, a11, 0             # 400009d1
	l32i.n	a10, a1, 4              # 400009d4
	l32i.n	a12, a1, 20             # 400009d6
	addx4	a10, a10, a12           # 400009d8
	l32i.n	a10, a10, 0             # 400009db
	bgeu	a10, a11, .L400009f3    # 400009dd
	l32i.n	a2, a1, 4               # 400009e0
	l32i.n	a3, a1, 20              # 400009e2
	addx4	a2, a2, a3              # 400009e4
	l32i.n	a15, a1, 0              # 400009e7
	l32i.n	a3, a1, 16              # 400009e9
	addx2	a15, a15, a3            # 400009eb
	l16ui	a15, a15, 0             # 400009ee
	s32i.n	a15, a2, 0              # 400009f1
.L400009f3:
	# i++; loop while i < segment_count
	l32i.n	a6, a1, 0               # 400009f3
	addi.n	a6, a6, 1               # 400009f5
	s32i.n	a6, a1, 0               # 400009f7
	l32r	a5, lit_3ffe1a88        # 400009f9  = ldc_segment_count
	l32i.n	a5, a5, 0               # 400009fc
	l32i.n	a4, a1, 0               # 400009fe
	bltu	a4, a5, .L400009bd      # 40000a00
.L40000a03:
	retw.n                          # 40000a03
	.size	ldc_merge_segments_maximum, . - ldc_merge_segments_maximum
