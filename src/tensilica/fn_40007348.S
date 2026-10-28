# fn_40007348: 0x40007348-0x400074b2 (firmware file offset 0x37348-0x374b2), 148 instructions
# Called from: fn_400079b8, fn_40007ab8
# Calls: fn_4000aa64, fn_40006be8, fn_4000912c
# Addresses loaded: ro_3ffe0bd0
# Other literal values: 0x3ffe5548, 0x00701000, 0x3ffe554c, 0x3ffe5550, 0x3ffe5554, 0x3ffe5558, 0x3ffe555c,
#                       0x3ffe5560, 0x3ffe5564, 0x3ffe5568, 0x3ffe556c, 0x3ffe5570, 0x3ffe5574, 0x3ffe5578,
#                       0x3ffe557c, 0x3ffe5580, 0x3ffe5584

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40007348, @function
fn_40007348:
	entry	a1, 80                  # 40007348
	s32i.n	a2, a1, 32              # 4000734b
	s32i.n	a3, a1, 36              # 4000734d
	s32i.n	a4, a1, 40              # 4000734f
	mov.n	a10, a1                 # 40007351
	l32r	a11, lit_3ffe20a0       # 40007353  = ro_3ffe0bd0
	movi.n	a12, 20                 # 40007356
	call8	fn_4000aa64             # 40007358
	l32r	a14, lit_3ffe205c       # 4000735b  = 0x3ffe5548
	l32i.n	a14, a14, 0             # 4000735e
	mov.n	a12, a1                 # 40007360
	l32r	a13, lit_3ffe20a4       # 40007362  = 0x00701000
	l32i.n	a15, a1, 36             # 40007365
	addx4	a14, a14, a15           # 40007367
	l32i.n	a14, a14, 0             # 4000736a
	extui	a14, a14, 0, 8          # 4000736c
	slli	a14, a14, 24            # 4000736f
	l32i.n	a11, a1, 32             # 40007372
	add.n	a11, a11, a14           # 40007374
	add.n	a11, a11, a13           # 40007376
	s32i.n	a11, a12, 0             # 40007378
	l32r	a10, lit_3ffe2064       # 4000737a  = 0x3ffe554c
	l32i.n	a10, a10, 0             # 4000737d
	l32r	a14, lit_3ffe2068       # 4000737f  = 0x3ffe5550
	l32i.n	a14, a14, 0             # 40007382
	l32r	a13, lit_3ffe206c       # 40007384  = 0x3ffe5554
	l32i.n	a13, a13, 0             # 40007387
	l32r	a12, lit_3ffe2070       # 40007389  = 0x3ffe5558
	l32i.n	a12, a12, 0             # 4000738c
	addi.n	a11, a1, 4              # 4000738e
	l32i.n	a15, a1, 36             # 40007390
	addx4	a12, a12, a15           # 40007392
	l32i.n	a12, a12, 0             # 40007395
	extui	a12, a12, 0, 8          # 40007397
	slli	a12, a12, 24            # 4000739a
	l32i.n	a15, a1, 36             # 4000739d
	addx4	a13, a13, a15           # 4000739f
	l32i.n	a13, a13, 0             # 400073a2
	extui	a13, a13, 0, 8          # 400073a4
	slli	a13, a13, 16            # 400073a7
	l32i.n	a15, a1, 36             # 400073aa
	addx4	a14, a14, a15           # 400073ac
	l32i.n	a14, a14, 0             # 400073af
	extui	a14, a14, 0, 8          # 400073b1
	slli	a14, a14, 8             # 400073b4
	l32i.n	a15, a1, 36             # 400073b7
	addx4	a10, a10, a15           # 400073b9
	l32i.n	a10, a10, 0             # 400073bc
	extui	a10, a10, 0, 8          # 400073be
	add.n	a10, a10, a14           # 400073c1
	add.n	a10, a10, a13           # 400073c3
	add.n	a10, a10, a12           # 400073c5
	s32i.n	a10, a11, 0             # 400073c7
	l32r	a9, lit_3ffe2074        # 400073c9  = 0x3ffe555c
	l32i.n	a9, a9, 0               # 400073cc
	l32r	a13, lit_3ffe2078       # 400073ce  = 0x3ffe5560
	l32i.n	a13, a13, 0             # 400073d1
	l32r	a12, lit_3ffe207c       # 400073d3  = 0x3ffe5564
	l32i.n	a12, a12, 0             # 400073d6
	l32r	a11, lit_3ffe2080       # 400073d8  = 0x3ffe5568
	l32i.n	a11, a11, 0             # 400073db
	addi.n	a10, a1, 8              # 400073dd
	l32i.n	a14, a1, 36             # 400073df
	addx4	a11, a11, a14           # 400073e1
	l32i.n	a11, a11, 0             # 400073e4
	extui	a11, a11, 0, 8          # 400073e6
	slli	a11, a11, 24            # 400073e9
	l32i.n	a14, a1, 36             # 400073ec
	addx4	a12, a12, a14           # 400073ee
	l32i.n	a12, a12, 0             # 400073f1
	extui	a12, a12, 0, 8          # 400073f3
	slli	a12, a12, 16            # 400073f6
	l32i.n	a14, a1, 36             # 400073f9
	addx4	a13, a13, a14           # 400073fb
	l32i.n	a13, a13, 0             # 400073fe
	extui	a13, a13, 0, 8          # 40007400
	slli	a13, a13, 8             # 40007403
	l32i.n	a14, a1, 36             # 40007406
	addx4	a9, a9, a14             # 40007408
	l32i.n	a9, a9, 0               # 4000740b
	extui	a9, a9, 0, 8            # 4000740d
	add.n	a9, a9, a13             # 40007410
	add.n	a9, a9, a12             # 40007412
	add.n	a9, a9, a11             # 40007414
	s32i.n	a9, a10, 0              # 40007416
	l32r	a8, lit_3ffe2084        # 40007418  = 0x3ffe556c
	l32i.n	a8, a8, 0               # 4000741b
	l32r	a12, lit_3ffe2088       # 4000741d  = 0x3ffe5570
	l32i.n	a12, a12, 0             # 40007420
	l32r	a11, lit_3ffe208c       # 40007422  = 0x3ffe5574
	l32i.n	a11, a11, 0             # 40007425
	l32r	a10, lit_3ffe2090       # 40007427  = 0x3ffe5578
	l32i.n	a10, a10, 0             # 4000742a
	addi.n	a9, a1, 12              # 4000742c
	l32i.n	a13, a1, 36             # 4000742e
	addx4	a10, a10, a13           # 40007430
	l32i.n	a10, a10, 0             # 40007433
	extui	a10, a10, 0, 8          # 40007435
	slli	a10, a10, 24            # 40007438
	l32i.n	a13, a1, 36             # 4000743b
	addx4	a11, a11, a13           # 4000743d
	l32i.n	a11, a11, 0             # 40007440
	extui	a11, a11, 0, 8          # 40007442
	slli	a11, a11, 16            # 40007445
	l32i.n	a13, a1, 36             # 40007448
	addx4	a12, a12, a13           # 4000744a
	l32i.n	a12, a12, 0             # 4000744d
	extui	a12, a12, 0, 8          # 4000744f
	slli	a12, a12, 8             # 40007452
	l32i.n	a13, a1, 36             # 40007455
	addx4	a8, a8, a13             # 40007457
	l32i.n	a8, a8, 0               # 4000745a
	extui	a8, a8, 0, 8            # 4000745c
	add.n	a8, a8, a12             # 4000745f
	add.n	a8, a8, a11             # 40007461
	add.n	a8, a8, a10             # 40007463
	s32i.n	a8, a9, 0               # 40007465
	l32r	a7, lit_3ffe2094        # 40007467  = 0x3ffe557c
	l32i.n	a7, a7, 0               # 4000746a
	l32r	a10, lit_3ffe2098       # 4000746c  = 0x3ffe5580
	l32i.n	a10, a10, 0             # 4000746f
	l32r	a9, lit_3ffe209c        # 40007471  = 0x3ffe5584
	l32i.n	a9, a9, 0               # 40007474
	addi	a8, a1, 16              # 40007476
	l32i.n	a11, a1, 36             # 40007479
	addx4	a9, a9, a11             # 4000747b
	l32i.n	a9, a9, 0               # 4000747e
	extui	a9, a9, 0, 8            # 40007480
	slli	a9, a9, 16              # 40007483
	l32i.n	a11, a1, 36             # 40007486
	addx4	a10, a10, a11           # 40007488
	l32i.n	a10, a10, 0             # 4000748b
	extui	a10, a10, 0, 8          # 4000748d
	slli	a10, a10, 8             # 40007490
	l32i.n	a11, a1, 36             # 40007493
	addx4	a7, a7, a11             # 40007495
	l32i.n	a7, a7, 0               # 40007498
	extui	a7, a7, 0, 8            # 4000749a
	add.n	a7, a7, a10             # 4000749d
	add.n	a7, a7, a9              # 4000749f
	s32i.n	a7, a8, 0               # 400074a1
	movi.n	a10, 5                  # 400074a3
	mov.n	a11, a1                 # 400074a5
	movi.n	a12, 1                  # 400074a7
	call8	fn_40006be8             # 400074a9
	movi.n	a10, 2                  # 400074ac
	call8	fn_4000912c             # 400074ae
	retw.n                          # 400074b1
	.size	fn_40007348, . - fn_40007348
