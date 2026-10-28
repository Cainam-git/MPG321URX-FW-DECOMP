# fn_400030c8: 0x400030c8-0x4000313f (firmware file offset 0x330c8-0x3313f), 46 instructions
# Called from: fn_400035d0
# Calls: fn_40002228, fn_40002418, fn_4000233c, fn_400024e4, fn_40002ca0, fn_40002a00, fn_4000082c
# Addresses loaded: data_3ffe2390
# Other literal values: 0x3ffe3ef0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400030c8, @function
fn_400030c8:
	entry	a1, 0x140               # 400030c8
	s32i	a2, a1, 0x110           # 400030cb
	l32r	a12, lit_3ffe1a98       # 400030ce  = data_3ffe2390
	l32i.n	a12, a12, 20            # 400030d1
	s32i.n	a12, a1, 0              # 400030d3
	movi.n	a11, 0                  # 400030d5
	s32i.n	a11, a1, 4              # 400030d7
	l32i	a10, a1, 0x110          # 400030d9
	addi	a11, a1, 16             # 400030dc
	l32i.n	a12, a1, 0              # 400030df
	call8	fn_40002228             # 400030e1
	addi	a10, a1, 16             # 400030e4
	l32r	a11, lit_3ffe1a98       # 400030e7  = data_3ffe2390
	l32i.n	a11, a11, 12            # 400030ea
	l32r	a12, lit_3ffe1a98       # 400030ec  = data_3ffe2390
	l32i.n	a12, a12, 8             # 400030ef
	call8	fn_40002418             # 400030f1
	addi	a10, a1, 16             # 400030f4
	l32i.n	a11, a1, 0              # 400030f7
	l32r	a12, lit_3ffe1a98       # 400030f9  = data_3ffe2390
	l32i.n	a12, a12, 8             # 400030fc
	call8	fn_4000233c             # 400030fe
	l32i	a10, a1, 0x110          # 40003101
	addi	a11, a1, 16             # 40003104
	l32r	a12, lit_3ffe1a98       # 40003107  = data_3ffe2390
	l32i.n	a12, a12, 20            # 4000310a
	movi.n	a13, 1                  # 4000310c
	call8	fn_400024e4             # 4000310e
	s32i.n	a10, a1, 4              # 40003111
	addi	a10, a1, 16             # 40003113
	call8	fn_40002ca0             # 40003116
	movi.n	a15, 0                  # 40003119
	l32i.n	a14, a1, 4              # 4000311b
	movi.n	a13, 1                  # 4000311d
	movi.n	a12, 0                  # 4000311f
	moveqz	a12, a13, a14           # 40003121
	addi	a10, a1, 16             # 40003124
	addi	a11, a1, 127            # 40003127
	addi	a11, a11, 17            # 4000312a
	call8	fn_40002a00             # 4000312d
	addi	a10, a1, 127            # 40003130
	addi	a10, a10, 17            # 40003133
	l32r	a11, lit_3ffe1ac4       # 40003136  = 0x3ffe3ef0
	movi.n	a12, 32                 # 40003139
	call8	fn_4000082c             # 4000313b
	retw.n                          # 4000313e
	.size	fn_400030c8, . - fn_400030c8
