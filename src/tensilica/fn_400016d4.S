# fn_400016d4: 0x400016d4-0x40001732 (firmware file offset 0x316d4-0x31732), 34 instructions
# Address stored in the words at: 0x4000d33c
# Calls: fn_400099bc
# Text loaded: "Segment Merge Mode: Maximum \n", "Segment Merge Mode: Average \n",
#              "Segment Merge Mode: Average exclude black  \n", "Segment Merge Mode: Blend \n"
# Addresses loaded: fn_400009a0, fn_40000a08, fn_40000afc, fn_40000c6c
# Other literal values: 0x3ffe2bf0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400016d4, @function
fn_400016d4:
	entry	a1, 48                  # 400016d4
	s32i.n	a2, a1, 0               # 400016d7
	s32i.n	a3, a1, 4               # 400016d9
	movi.n	a6, 0                   # 400016db
	l32i.n	a5, a1, 4               # 400016dd
	bne	a5, a6, .L400016f4      # 400016df
	l32r	a7, lit_3ffe1a80        # 400016e2  = 0x3ffe2bf0
	l32r	a6, lit_3ffe1ae0        # 400016e5  = fn_400009a0
	s32i	a6, a7, 0x148           # 400016e8
	l32r	a10, lit_3ffe1b40       # 400016eb  = ro_3ffe01b4 "Segment Merge Mode: Maximum \n"
	call8	fn_400099bc             # 400016ee
	j	.L40001731              # 400016f1
.L400016f4:
	l32i.n	a8, a1, 4               # 400016f4
	bnei	a8, 1, .L4000170b       # 400016f6
	l32r	a10, lit_3ffe1a80       # 400016f9  = 0x3ffe2bf0
	l32r	a9, lit_3ffe1b44        # 400016fc  = fn_40000a08
	s32i	a9, a10, 0x148          # 400016ff
	l32r	a10, lit_3ffe1b48       # 40001702  = ro_3ffe01d4 "Segment Merge Mode: Average \n"
	call8	fn_400099bc             # 40001705
	j	.L40001731              # 40001708
.L4000170b:
	l32i.n	a11, a1, 4              # 4000170b
	bnei	a11, 2, .L40001722      # 4000170d
	l32r	a13, lit_3ffe1a80       # 40001710  = 0x3ffe2bf0
	l32r	a12, lit_3ffe1b4c       # 40001713  = fn_40000afc
	s32i	a12, a13, 0x148         # 40001716
	l32r	a10, lit_3ffe1b50       # 40001719  = ro_3ffe01f4 "Segment Merge Mode: Average exclude black  \n"
	call8	fn_400099bc             # 4000171c
	j	.L40001731              # 4000171f
.L40001722:
	l32r	a15, lit_3ffe1a80       # 40001722  = 0x3ffe2bf0
	l32r	a14, lit_3ffe1b54       # 40001725  = fn_40000c6c
	s32i	a14, a15, 0x148         # 40001728
	l32r	a10, lit_3ffe1b58       # 4000172b  = ro_3ffe0224 "Segment Merge Mode: Blend \n"
	call8	fn_400099bc             # 4000172e
.L40001731:
	retw.n                          # 40001731
	.size	fn_400016d4, . - fn_400016d4
