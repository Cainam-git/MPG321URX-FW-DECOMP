# ldc_cmd_set_segment_merge_mode  (fn_400016d4): 0x400016d4-0x40001732 (firmware file offset 0x316d4-0x31732), 34 instructions
# Name basis: proven - prints 'Segment Merge Mode: ...'; stores the merge routine at panel +0x148
# Address stored in the words at: 0x4000d33c
# Calls: dbg_printf
# Text loaded: "Segment Merge Mode: Maximum \n", "Segment Merge Mode: Average \n",
#              "Segment Merge Mode: Average exclude black  \n", "Segment Merge Mode: Blend \n"
# Addresses loaded: ldc_merge_segments_maximum, ldc_merge_segments_average,
#                   ldc_merge_segments_average_no_black, ldc_merge_segments_blend
# Other literal values: 0x3ffe2bf0
#
# Command 0x41: selects how segments are merged into LED channels by storing the merge routine in panel +0x148
# (called through it by the per-frame pass ldc_run_frame_pass) and prints the mode: 0 = Maximum
# (ldc_merge_segments_maximum), 1 = Average (ldc_merge_segments_average), 2 = Average exclude black
# (ldc_merge_segments_average_no_black), any other value = Blend (ldc_merge_segments_blend).
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15), the merge mode
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_segment_merge_mode, @function
ldc_cmd_set_segment_merge_mode:         # fn_400016d4
	entry	a1, 48                  # 400016d4
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 400016d7
	s32i.n	a3, a1, 4               # 400016d9
	# if (value == 0)
	movi.n	a6, 0                   # 400016db
	l32i.n	a5, a1, 4               # 400016dd
	bne	a5, a6, .L400016f4      # 400016df
	# panel.merge_fn = ldc_merge_segments_maximum
	l32r	a7, lit_3ffe1a80        # 400016e2  = 0x3ffe2bf0
	l32r	a6, lit_3ffe1ae0        # 400016e5  = ldc_merge_segments_maximum
	s32i	a6, a7, 0x148           # 400016e8
	# printf("Segment Merge Mode: Maximum \n")
	l32r	a10, lit_3ffe1b40       # 400016eb  = ro_3ffe01b4 "Segment Merge Mode: Maximum \n"
	call8	dbg_printf              # 400016ee
	j	.L40001731              # 400016f1
.L400016f4:
	# else if (value == 1)
	l32i.n	a8, a1, 4               # 400016f4
	bnei	a8, 1, .L4000170b       # 400016f6
	# panel.merge_fn = ldc_merge_segments_average; printf("Segment Merge Mode: Average \n")
	l32r	a10, lit_3ffe1a80       # 400016f9  = 0x3ffe2bf0
	l32r	a9, lit_3ffe1b44        # 400016fc  = ldc_merge_segments_average
	s32i	a9, a10, 0x148          # 400016ff
	l32r	a10, lit_3ffe1b48       # 40001702  = ro_3ffe01d4 "Segment Merge Mode: Average \n"
	call8	dbg_printf              # 40001705
	j	.L40001731              # 40001708
.L4000170b:
	# else if (value == 2)
	l32i.n	a11, a1, 4              # 4000170b
	bnei	a11, 2, .L40001722      # 4000170d
	# panel.merge_fn = ldc_merge_segments_average_no_black;
	# printf("Segment Merge Mode: Average exclude black  \n")
	l32r	a13, lit_3ffe1a80       # 40001710  = 0x3ffe2bf0
	l32r	a12, lit_3ffe1b4c       # 40001713  = ldc_merge_segments_average_no_black
	s32i	a12, a13, 0x148         # 40001716
	l32r	a10, lit_3ffe1b50       # 40001719  = ro_3ffe01f4 "Segment Merge Mode: Average exclude black  \n"
	call8	dbg_printf              # 4000171c
	j	.L40001731              # 4000171f
.L40001722:
	# else { panel.merge_fn = ldc_merge_segments_blend; printf("Segment Merge Mode: Blend \n"); }
	l32r	a15, lit_3ffe1a80       # 40001722  = 0x3ffe2bf0
	l32r	a14, lit_3ffe1b54       # 40001725  = ldc_merge_segments_blend
	s32i	a14, a15, 0x148         # 40001728
	l32r	a10, lit_3ffe1b58       # 4000172b  = ro_3ffe0224 "Segment Merge Mode: Blend \n"
	call8	dbg_printf              # 4000172e
.L40001731:
	retw.n                          # 40001731
	.size	ldc_cmd_set_segment_merge_mode, . - ldc_cmd_set_segment_merge_mode
