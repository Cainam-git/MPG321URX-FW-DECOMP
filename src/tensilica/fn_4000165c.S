# fn_4000165c: 0x4000165c-0x400016a2 (firmware file offset 0x3165c-0x316a2), 28 instructions
# Address stored in the words at: 0x4000d3ec
# Calls: fn_400099bc, fn_400011e4
# Text loaded: "Current Stress Staus = %d (Peaking OFF)\n", "Current Stress Staus = %d (Peaking ON)\n"
# Addresses loaded: data_3ffe2390
# Other literal values: 0x3ffe2bf0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000165c, @function
fn_4000165c:
	entry	a1, 48                  # 4000165c
	s32i.n	a2, a1, 0               # 4000165f
	s32i.n	a3, a1, 4               # 40001661
	movi.n	a6, 0                   # 40001663
	l32i.n	a5, a1, 4               # 40001665
	bne	a5, a6, .L4000168c      # 40001667
	l32r	a11, lit_3ffe1a80       # 4000166a  = 0x3ffe2bf0
	movi.n	a10, 0                  # 4000166d
	s32i	a10, a11, 0x150         # 4000166f
	l32r	a9, lit_3ffe1a98        # 40001672  = data_3ffe2390
	movi.n	a8, 1                   # 40001675
	s32i.n	a8, a9, 60              # 40001677
	l32r	a7, lit_3ffe1a80        # 40001679  = 0x3ffe2bf0
	movi.n	a6, 3                   # 4000167c
	s32i	a6, a7, 0x140           # 4000167e
	l32r	a10, lit_3ffe1b2c       # 40001681  = ro_3ffe0128 "Current Stress Staus = %d (Peaking OFF)\n"
	movi.n	a11, 0                  # 40001684
	call8	fn_400099bc             # 40001686
	j	.L4000169c              # 40001689
.L4000168c:
	l32r	a13, lit_3ffe1a80       # 4000168c  = 0x3ffe2bf0
	movi.n	a12, 6                  # 4000168f
	s32i	a12, a13, 0x140         # 40001691
	l32r	a10, lit_3ffe1b30       # 40001694  = ro_3ffe0154 "Current Stress Staus = %d (Peaking ON)\n"
	movi.n	a11, 1                  # 40001697
	call8	fn_400099bc             # 40001699
.L4000169c:
	movi.n	a10, 1                  # 4000169c
	call8	fn_400011e4             # 4000169e
	retw.n                          # 400016a1
	.size	fn_4000165c, . - fn_4000165c
