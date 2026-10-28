# fn_40008300: 0x40008300-0x400086a1 (firmware file offset 0x38300-0x386a1), 337 instructions
# Called from: fn_400086a4
# Calls: fn_400099bc
# Text loaded: "[ERR] gpio_switch_mux: gpio index out of range (%bu)\n"
# Addresses loaded: ro_3ffe1350
# Other literal values: 0x00001638, 0x000015c0, 0x000015dc, 0x000015d8, 0x000015e0, 0x000015d4, 0x000015cc,
#                       0x000015c8

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40008300, @function
fn_40008300:
	entry	a1, 64                  # 40008300
	s32i.n	a2, a1, 16              # 40008303
	l32i.n	a12, a1, 16             # 40008305
	srli	a12, a12, 3             # 40008307
	s8i	a12, a1, 0              # 4000830a
	movi.n	a10, 1                  # 4000830d
	l32i.n	a11, a1, 16             # 4000830f
	extui	a11, a11, 0, 3          # 40008311
	ssl	a11                     # 40008314
	sll	a10, a10                # 40008317
	s8i	a10, a1, 1              # 4000831a
	l32r	a10, lit_3ffe21c4       # 4000831d  = 0x00001638
	movi.n	a11, 1                  # 40008320
	movi	a12, 254                # 40008322
	l32r	a9, lit_3ffe21c4        # 40008325  = 0x00001638
	memw                            # 40008328
	l32i.n	a9, a9, 0               # 4000832b
	and	a9, a9, a12             # 4000832d
	or	a9, a9, a11             # 40008330
	memw                            # 40008333
	s32i.n	a9, a10, 0              # 40008336
	l8ui	a8, a1, 0               # 40008338
	movi	a7, 0x52c               # 4000833b
	sub	a7, a7, a8              # 4000833e
	slli	a7, a7, 2               # 40008341
	l8ui	a8, a1, 1               # 40008344
	l8ui	a9, a1, 0               # 40008347
	movi	a6, 0x52c               # 4000834a
	sub	a6, a6, a9              # 4000834d
	slli	a6, a6, 2               # 40008350
	memw                            # 40008353
	l32i.n	a6, a6, 0               # 40008356
	extui	a6, a6, 0, 8            # 40008358
	or	a6, a6, a8              # 4000835b
	extui	a6, a6, 0, 8            # 4000835e
	memw                            # 40008361
	s32i.n	a6, a7, 0               # 40008364
	l32i.n	a5, a1, 16              # 40008366
	s32i.n	a5, a1, 4               # 40008368
	l32i.n	a4, a1, 4               # 4000836a
	s32i.n	a4, a1, 8               # 4000836c
	bltui	a4, 32, .L40008374      # 4000836e
	j	.L40008695              # 40008371
.L40008374:
	l32r	a14, lit_3ffe21c8       # 40008374  = ro_3ffe1350
	l32i.n	a13, a1, 8              # 40008377
	addx4	a13, a13, a14           # 40008379
	l32i.n	a13, a13, 0             # 4000837c
	jx	a13                     # 4000837e
.L40008381:
	l32r	a2, lit_3ffe21cc        # 40008381  = 0x000015c0
	movi	a3, 251                 # 40008384
	l32r	a15, lit_3ffe21cc       # 40008387  = 0x000015c0
	memw                            # 4000838a
	l32i.n	a15, a15, 0             # 4000838d
	and	a15, a15, a3            # 4000838f
	memw                            # 40008392
	s32i.n	a15, a2, 0              # 40008395
	j	.L400086a0              # 40008397
.L4000839a:
	l32r	a3, lit_3ffe21d0        # 4000839a  = 0x000015dc
	movi	a4, 254                 # 4000839d
	l32r	a2, lit_3ffe21d0        # 400083a0  = 0x000015dc
	memw                            # 400083a3
	l32i.n	a2, a2, 0               # 400083a6
	and	a2, a2, a4              # 400083a8
	memw                            # 400083ab
	s32i.n	a2, a3, 0               # 400083ae
	j	.L400086a0              # 400083b0
.L400083b3:
	l32r	a4, lit_3ffe21d0        # 400083b3  = 0x000015dc
	movi	a5, 253                 # 400083b6
	l32r	a3, lit_3ffe21d0        # 400083b9  = 0x000015dc
	memw                            # 400083bc
	l32i.n	a3, a3, 0               # 400083bf
	and	a3, a3, a5              # 400083c1
	memw                            # 400083c4
	s32i.n	a3, a4, 0               # 400083c7
	j	.L400086a0              # 400083c9
.L400083cc:
	l32r	a5, lit_3ffe21d0        # 400083cc  = 0x000015dc
	movi	a6, 251                 # 400083cf
	l32r	a4, lit_3ffe21d0        # 400083d2  = 0x000015dc
	memw                            # 400083d5
	l32i.n	a4, a4, 0               # 400083d8
	and	a4, a4, a6              # 400083da
	memw                            # 400083dd
	s32i.n	a4, a5, 0               # 400083e0
	j	.L400086a0              # 400083e2
.L400083e5:
	l32r	a6, lit_3ffe21d0        # 400083e5  = 0x000015dc
	movi	a7, 247                 # 400083e8
	l32r	a5, lit_3ffe21d0        # 400083eb  = 0x000015dc
	memw                            # 400083ee
	l32i.n	a5, a5, 0               # 400083f1
	and	a5, a5, a7              # 400083f3
	memw                            # 400083f6
	s32i.n	a5, a6, 0               # 400083f9
	j	.L400086a0              # 400083fb
.L400083fe:
	l32r	a7, lit_3ffe21d0        # 400083fe  = 0x000015dc
	movi	a8, 239                 # 40008401
	l32r	a6, lit_3ffe21d0        # 40008404  = 0x000015dc
	memw                            # 40008407
	l32i.n	a6, a6, 0               # 4000840a
	and	a6, a6, a8              # 4000840c
	memw                            # 4000840f
	s32i.n	a6, a7, 0               # 40008412
	j	.L400086a0              # 40008414
.L40008417:
	l32r	a8, lit_3ffe21d0        # 40008417  = 0x000015dc
	movi	a9, 223                 # 4000841a
	l32r	a7, lit_3ffe21d0        # 4000841d  = 0x000015dc
	memw                            # 40008420
	l32i.n	a7, a7, 0               # 40008423
	and	a7, a7, a9              # 40008425
	memw                            # 40008428
	s32i.n	a7, a8, 0               # 4000842b
	j	.L400086a0              # 4000842d
.L40008430:
	l32r	a9, lit_3ffe21d0        # 40008430  = 0x000015dc
	movi	a10, 191                # 40008433
	l32r	a8, lit_3ffe21d0        # 40008436  = 0x000015dc
	memw                            # 40008439
	l32i.n	a8, a8, 0               # 4000843c
	and	a8, a8, a10             # 4000843e
	memw                            # 40008441
	s32i.n	a8, a9, 0               # 40008444
	j	.L400086a0              # 40008446
.L40008449:
	l32r	a10, lit_3ffe21d0       # 40008449  = 0x000015dc
	l32r	a9, lit_3ffe21d0        # 4000844c  = 0x000015dc
	memw                            # 4000844f
	l32i.n	a9, a9, 0               # 40008452
	extui	a9, a9, 0, 7            # 40008454
	memw                            # 40008457
	s32i.n	a9, a10, 0              # 4000845a
	j	.L400086a0              # 4000845c
.L4000845f:
	l32r	a11, lit_3ffe21d4       # 4000845f  = 0x000015d8
	movi	a12, 254                # 40008462
	l32r	a10, lit_3ffe21d4       # 40008465  = 0x000015d8
	memw                            # 40008468
	l32i.n	a10, a10, 0             # 4000846b
	and	a10, a10, a12           # 4000846d
	memw                            # 40008470
	s32i.n	a10, a11, 0             # 40008473
	j	.L400086a0              # 40008475
.L40008478:
	l32r	a12, lit_3ffe21d4       # 40008478  = 0x000015d8
	movi	a13, 253                # 4000847b
	l32r	a11, lit_3ffe21d4       # 4000847e  = 0x000015d8
	memw                            # 40008481
	l32i.n	a11, a11, 0             # 40008484
	and	a11, a11, a13           # 40008486
	memw                            # 40008489
	s32i.n	a11, a12, 0             # 4000848c
	j	.L400086a0              # 4000848e
.L40008491:
	l32r	a13, lit_3ffe21d4       # 40008491  = 0x000015d8
	movi	a14, 251                # 40008494
	l32r	a12, lit_3ffe21d4       # 40008497  = 0x000015d8
	memw                            # 4000849a
	l32i.n	a12, a12, 0             # 4000849d
	and	a12, a12, a14           # 4000849f
	memw                            # 400084a2
	s32i.n	a12, a13, 0             # 400084a5
	j	.L400086a0              # 400084a7
.L400084aa:
	l32r	a14, lit_3ffe21d4       # 400084aa  = 0x000015d8
	movi	a15, 247                # 400084ad
	l32r	a13, lit_3ffe21d4       # 400084b0  = 0x000015d8
	memw                            # 400084b3
	l32i.n	a13, a13, 0             # 400084b6
	and	a13, a13, a15           # 400084b8
	memw                            # 400084bb
	s32i.n	a13, a14, 0             # 400084be
	j	.L400086a0              # 400084c0
.L400084c3:
	l32r	a15, lit_3ffe21d4       # 400084c3  = 0x000015d8
	movi	a2, 239                 # 400084c6
	l32r	a14, lit_3ffe21d4       # 400084c9  = 0x000015d8
	memw                            # 400084cc
	l32i.n	a14, a14, 0             # 400084cf
	and	a14, a14, a2            # 400084d1
	memw                            # 400084d4
	s32i.n	a14, a15, 0             # 400084d7
	j	.L400086a0              # 400084d9
.L400084dc:
	l32r	a2, lit_3ffe21d4        # 400084dc  = 0x000015d8
	movi	a3, 223                 # 400084df
	l32r	a15, lit_3ffe21d4       # 400084e2  = 0x000015d8
	memw                            # 400084e5
	l32i.n	a15, a15, 0             # 400084e8
	and	a15, a15, a3            # 400084ea
	memw                            # 400084ed
	s32i.n	a15, a2, 0              # 400084f0
	j	.L400086a0              # 400084f2
.L400084f5:
	l32r	a3, lit_3ffe21d4        # 400084f5  = 0x000015d8
	movi	a4, 191                 # 400084f8
	l32r	a2, lit_3ffe21d4        # 400084fb  = 0x000015d8
	memw                            # 400084fe
	l32i.n	a2, a2, 0               # 40008501
	and	a2, a2, a4              # 40008503
	memw                            # 40008506
	s32i.n	a2, a3, 0               # 40008509
	j	.L400086a0              # 4000850b
.L4000850e:
	l32r	a4, lit_3ffe21d4        # 4000850e  = 0x000015d8
	l32r	a3, lit_3ffe21d4        # 40008511  = 0x000015d8
	memw                            # 40008514
	l32i.n	a3, a3, 0               # 40008517
	extui	a3, a3, 0, 7            # 40008519
	memw                            # 4000851c
	s32i.n	a3, a4, 0               # 4000851f
	j	.L400086a0              # 40008521
.L40008524:
	l32r	a5, lit_3ffe21d8        # 40008524  = 0x000015e0
	movi	a6, 253                 # 40008527
	l32r	a4, lit_3ffe21d8        # 4000852a  = 0x000015e0
	memw                            # 4000852d
	l32i.n	a4, a4, 0               # 40008530
	and	a4, a4, a6              # 40008532
	memw                            # 40008535
	s32i.n	a4, a5, 0               # 40008538
	j	.L400086a0              # 4000853a
.L4000853d:
	l32r	a6, lit_3ffe21d8        # 4000853d  = 0x000015e0
	movi	a7, 251                 # 40008540
	l32r	a5, lit_3ffe21d8        # 40008543  = 0x000015e0
	memw                            # 40008546
	l32i.n	a5, a5, 0               # 40008549
	and	a5, a5, a7              # 4000854b
	memw                            # 4000854e
	s32i.n	a5, a6, 0               # 40008551
	j	.L400086a0              # 40008553
.L40008556:
	l32r	a7, lit_3ffe21d8        # 40008556  = 0x000015e0
	movi	a8, 247                 # 40008559
	l32r	a6, lit_3ffe21d8        # 4000855c  = 0x000015e0
	memw                            # 4000855f
	l32i.n	a6, a6, 0               # 40008562
	and	a6, a6, a8              # 40008564
	memw                            # 40008567
	s32i.n	a6, a7, 0               # 4000856a
	j	.L400086a0              # 4000856c
.L4000856f:
	l32r	a8, lit_3ffe21d8        # 4000856f  = 0x000015e0
	movi	a9, 239                 # 40008572
	l32r	a7, lit_3ffe21d8        # 40008575  = 0x000015e0
	memw                            # 40008578
	l32i.n	a7, a7, 0               # 4000857b
	and	a7, a7, a9              # 4000857d
	memw                            # 40008580
	s32i.n	a7, a8, 0               # 40008583
	j	.L400086a0              # 40008585
.L40008588:
	l32r	a9, lit_3ffe21d8        # 40008588  = 0x000015e0
	movi	a10, 223                # 4000858b
	l32r	a8, lit_3ffe21d8        # 4000858e  = 0x000015e0
	memw                            # 40008591
	l32i.n	a8, a8, 0               # 40008594
	and	a8, a8, a10             # 40008596
	memw                            # 40008599
	s32i.n	a8, a9, 0               # 4000859c
	j	.L400086a0              # 4000859e
.L400085a1:
	l32r	a10, lit_3ffe21dc       # 400085a1  = 0x000015d4
	movi	a11, 254                # 400085a4
	l32r	a9, lit_3ffe21dc        # 400085a7  = 0x000015d4
	memw                            # 400085aa
	l32i.n	a9, a9, 0               # 400085ad
	and	a9, a9, a11             # 400085af
	memw                            # 400085b2
	s32i.n	a9, a10, 0              # 400085b5
	j	.L400086a0              # 400085b7
.L400085ba:
	l32r	a11, lit_3ffe21dc       # 400085ba  = 0x000015d4
	movi	a12, 253                # 400085bd
	l32r	a10, lit_3ffe21dc       # 400085c0  = 0x000015d4
	memw                            # 400085c3
	l32i.n	a10, a10, 0             # 400085c6
	and	a10, a10, a12           # 400085c8
	memw                            # 400085cb
	s32i.n	a10, a11, 0             # 400085ce
	j	.L400086a0              # 400085d0
.L400085d3:
	l32r	a12, lit_3ffe21dc       # 400085d3  = 0x000015d4
	movi	a13, 251                # 400085d6
	l32r	a11, lit_3ffe21dc       # 400085d9  = 0x000015d4
	memw                            # 400085dc
	l32i.n	a11, a11, 0             # 400085df
	and	a11, a11, a13           # 400085e1
	memw                            # 400085e4
	s32i.n	a11, a12, 0             # 400085e7
	j	.L400086a0              # 400085e9
.L400085ec:
	l32r	a13, lit_3ffe21dc       # 400085ec  = 0x000015d4
	l32r	a12, lit_3ffe21dc       # 400085ef  = 0x000015d4
	memw                            # 400085f2
	l32i.n	a12, a12, 0             # 400085f5
	extui	a12, a12, 0, 7          # 400085f7
	memw                            # 400085fa
	s32i.n	a12, a13, 0             # 400085fd
	j	.L400086a0              # 400085ff
.L40008602:
	l32r	a14, lit_3ffe21e0       # 40008602  = 0x000015cc
	movi	a15, 239                # 40008605
	l32r	a13, lit_3ffe21e0       # 40008608  = 0x000015cc
	memw                            # 4000860b
	l32i.n	a13, a13, 0             # 4000860e
	and	a13, a13, a15           # 40008610
	memw                            # 40008613
	s32i.n	a13, a14, 0             # 40008616
	j	.L400086a0              # 40008618
.L4000861b:
	l32r	a15, lit_3ffe21e0       # 4000861b  = 0x000015cc
	movi	a2, 223                 # 4000861e
	l32r	a14, lit_3ffe21e0       # 40008621  = 0x000015cc
	memw                            # 40008624
	l32i.n	a14, a14, 0             # 40008627
	and	a14, a14, a2            # 40008629
	memw                            # 4000862c
	s32i.n	a14, a15, 0             # 4000862f
	j	.L400086a0              # 40008631
.L40008634:
	l32r	a2, lit_3ffe21e0        # 40008634  = 0x000015cc
	movi	a3, 191                 # 40008637
	l32r	a15, lit_3ffe21e0       # 4000863a  = 0x000015cc
	memw                            # 4000863d
	l32i.n	a15, a15, 0             # 40008640
	and	a15, a15, a3            # 40008642
	memw                            # 40008645
	s32i.n	a15, a2, 0              # 40008648
	j	.L400086a0              # 4000864a
.L4000864d:
	l32r	a3, lit_3ffe21e0        # 4000864d  = 0x000015cc
	l32r	a2, lit_3ffe21e0        # 40008650  = 0x000015cc
	memw                            # 40008653
	l32i.n	a2, a2, 0               # 40008656
	extui	a2, a2, 0, 7            # 40008658
	memw                            # 4000865b
	s32i.n	a2, a3, 0               # 4000865e
	j	.L400086a0              # 40008660
.L40008663:
	l32r	a4, lit_3ffe21e4        # 40008663  = 0x000015c8
	movi	a5, 254                 # 40008666
	l32r	a3, lit_3ffe21e4        # 40008669  = 0x000015c8
	memw                            # 4000866c
	l32i.n	a3, a3, 0               # 4000866f
	and	a3, a3, a5              # 40008671
	memw                            # 40008674
	s32i.n	a3, a4, 0               # 40008677
	j	.L400086a0              # 40008679
.L4000867c:
	l32r	a5, lit_3ffe21e4        # 4000867c  = 0x000015c8
	movi	a6, 253                 # 4000867f
	l32r	a4, lit_3ffe21e4        # 40008682  = 0x000015c8
	memw                            # 40008685
	l32i.n	a4, a4, 0               # 40008688
	and	a4, a4, a6              # 4000868a
	memw                            # 4000868d
	s32i.n	a4, a5, 0               # 40008690
	j	.L400086a0              # 40008692
.L40008695:
	l32r	a10, lit_3ffe21e8       # 40008695  = ro_3ffe1310 "[ERR] gpio_switch_mux: gpio index out of range (%bu)\n"
	l32i.n	a11, a1, 16             # 40008698
	call8	fn_400099bc             # 4000869a
	j	.L400086a0              # 4000869d
.L400086a0:
	retw.n                          # 400086a0
	.size	fn_40008300, . - fn_40008300
