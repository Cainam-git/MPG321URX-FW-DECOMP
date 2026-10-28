# fn_40005574: 0x40005574-0x4000574b (firmware file offset 0x35574-0x3574b), 177 instructions
# Called from: fn_400058dc
# Calls: fn_4000496c, fn_40005518, fn_400054a4, fn_400099bc, fn_4000497c
# Other literal values: 0x3ffe4240, 0x0000ffff, 0x3ffe4411, 0x3ffe4410, 0x3ffe4419, 0x3ffe441a, 0x3ffe441b,
#                       0x3ffe441c, 0x3ffe441d, 0x3ffe441e, 0x3ffe441f, 0x3ffe4420, 0x3ffe4412, 0x3ffe4413,
#                       0x3ffe4414, 0x3ffe4415, 0x3ffe4416, 0x3ffe4424, 0x3ffe4425, 0x3ffe4426, 0x3ffe4427,
#                       0x3ffe4417, 0x3ffe4418

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005574, @function
fn_40005574:
	entry	a1, 64                  # 40005574
	movi.n	a5, 0                   # 40005577
	s32i.n	a5, a1, 0               # 40005579
	l32r	a4, lit_3ffe1d70        # 4000557b  = 0x3ffe4240
	l32i.n	a4, a4, 4               # 4000557e
	s32i.n	a4, a1, 4               # 40005580
	l32r	a3, lit_3ffe1b70        # 40005582  = 0x0000ffff
	l32i.n	a2, a1, 4               # 40005585
	beq	a2, a3, .L400055b2      # 40005587
	l32i.n	a6, a1, 4               # 4000558a
	beqi	a6, 1, .L400055b9       # 4000558c
	l32i.n	a7, a1, 4               # 4000558f
	bnei	a7, 2, .L40005597       # 40005591
	j	.L40005637              # 40005594
.L40005597:
	l32i.n	a8, a1, 4               # 40005597
	bnei	a8, 3, .L4000559f       # 40005599
	j	.L400056ae              # 4000559c
.L4000559f:
	l32i.n	a9, a1, 4               # 4000559f
	bnei	a9, 4, .L400055a7       # 400055a1
	j	.L400056b1              # 400055a4
.L400055a7:
	l32i.n	a10, a1, 4              # 400055a7
	bnei	a10, 5, .L400055af      # 400055a9
	j	.L400056b4              # 400055ac
.L400055af:
	j	.L40005745              # 400055af
.L400055b2:
	movi.n	a11, 1                  # 400055b2
	s32i.n	a11, a1, 0              # 400055b4
	j	.L40005748              # 400055b6
.L400055b9:
	movi.n	a14, -4                 # 400055b9
	l32r	a13, lit_3ffe1d70       # 400055bb  = 0x3ffe4240
	l32i.n	a13, a13, 8             # 400055be
	and	a13, a13, a14           # 400055c0
	l32r	a12, lit_3ffe1d70       # 400055c3  = 0x3ffe4240
	l32i.n	a12, a12, 20            # 400055c6
	add.n	a12, a12, a13           # 400055c8
	s32i.n	a12, a1, 8              # 400055ca
	l32i.n	a10, a1, 8              # 400055cc
	call8	fn_4000496c             # 400055ce
	s32i.n	a10, a1, 12             # 400055d1
	l32i.n	a10, a1, 12             # 400055d3
	movi.n	a11, 0                  # 400055d5
	call8	fn_40005518             # 400055d7
	s8i	a10, a1, 16             # 400055da
	l32r	a10, lit_3ffe1d9c       # 400055dd  = 0x3ffe4411
	l32i.n	a11, a1, 12             # 400055e0
	call8	fn_400054a4             # 400055e2
	l32r	a3, lit_3ffe1da0        # 400055e5  = 0x3ffe4410
	movi.n	a2, 35                  # 400055e8
	s8i	a2, a3, 0               # 400055ea
	l32r	a15, lit_3ffe1da4       # 400055ed  = 0x3ffe4419
	l8ui	a14, a1, 16             # 400055f0
	s8i	a14, a15, 0             # 400055f3
	l32r	a13, lit_3ffe1da8       # 400055f6  = 0x3ffe441a
	movi.n	a12, 32                 # 400055f9
	s8i	a12, a13, 0             # 400055fb
	l32r	a11, lit_3ffe1dac       # 400055fe  = 0x3ffe441b
	movi.n	a10, 79                 # 40005601
	s8i	a10, a11, 0             # 40005603
	l32r	a9, lit_3ffe1db0        # 40005606  = 0x3ffe441c
	movi.n	a8, 75                  # 40005609
	s8i	a8, a9, 0               # 4000560b
	l32r	a7, lit_3ffe1db4        # 4000560e  = 0x3ffe441d
	movi.n	a6, 33                  # 40005611
	s8i	a6, a7, 0               # 40005613
	l32r	a5, lit_3ffe1db8        # 40005616  = 0x3ffe441e
	movi.n	a4, 35                  # 40005619
	s8i	a4, a5, 0               # 4000561b
	l32r	a3, lit_3ffe1dbc        # 4000561e  = 0x3ffe441f
	movi.n	a2, 10                  # 40005621
	s8i	a2, a3, 0               # 40005623
	l32r	a15, lit_3ffe1dc0       # 40005626  = 0x3ffe4420
	movi.n	a14, 0                  # 40005629
	s8i	a14, a15, 0             # 4000562b
	l32r	a10, lit_3ffe1da0       # 4000562e  = 0x3ffe4410
	call8	fn_400099bc             # 40005631
	j	.L40005748              # 40005634
.L40005637:
	l32r	a10, lit_3ffe1d70       # 40005637  = 0x3ffe4240
	l32i.n	a10, a10, 8             # 4000563a
	l32r	a11, lit_3ffe1d70       # 4000563c  = 0x3ffe4240
	l32i.n	a11, a11, 12            # 4000563f
	call8	fn_40005518             # 40005641
	l32r	a11, lit_3ffe1d70       # 40005644  = 0x3ffe4240
	l8ui	a11, a11, 16            # 40005647
	beq	a11, a10, .L40005650    # 4000564a
	j	.L40005748              # 4000564d
.L40005650:
	movi.n	a14, -4                 # 40005650
	l32r	a13, lit_3ffe1d70       # 40005652  = 0x3ffe4240
	l32i.n	a13, a13, 8             # 40005655
	and	a13, a13, a14           # 40005657
	l32r	a12, lit_3ffe1d70       # 4000565a  = 0x3ffe4240
	l32i.n	a12, a12, 20            # 4000565d
	add.n	a12, a12, a13           # 4000565f
	s32i.n	a12, a1, 8              # 40005661
	l32i.n	a10, a1, 8              # 40005663
	l32r	a11, lit_3ffe1d70       # 40005665  = 0x3ffe4240
	l32i.n	a11, a11, 12            # 40005668
	call8	fn_4000497c             # 4000566a
	l32r	a13, lit_3ffe1da0       # 4000566d  = 0x3ffe4410
	movi.n	a12, 35                 # 40005670
	s8i	a12, a13, 0             # 40005672
	l32r	a11, lit_3ffe1d9c       # 40005675  = 0x3ffe4411
	movi.n	a10, 79                 # 40005678
	s8i	a10, a11, 0             # 4000567a
	l32r	a9, lit_3ffe1dc4        # 4000567d  = 0x3ffe4412
	movi.n	a8, 75                  # 40005680
	s8i	a8, a9, 0               # 40005682
	l32r	a7, lit_3ffe1dc8        # 40005685  = 0x3ffe4413
	movi.n	a6, 33                  # 40005688
	s8i	a6, a7, 0               # 4000568a
	l32r	a5, lit_3ffe1dcc        # 4000568d  = 0x3ffe4414
	movi.n	a4, 35                  # 40005690
	s8i	a4, a5, 0               # 40005692
	l32r	a3, lit_3ffe1dd0        # 40005695  = 0x3ffe4415
	movi.n	a2, 10                  # 40005698
	s8i	a2, a3, 0               # 4000569a
	l32r	a15, lit_3ffe1dd4       # 4000569d  = 0x3ffe4416
	movi.n	a14, 0                  # 400056a0
	s8i	a14, a15, 0             # 400056a2
	l32r	a10, lit_3ffe1da0       # 400056a5  = 0x3ffe4410
	call8	fn_400099bc             # 400056a8
	j	.L40005748              # 400056ab
.L400056ae:
	j	.L40005748              # 400056ae
.L400056b1:
	j	.L40005748              # 400056b1
.L400056b4:
	l32r	a13, lit_3ffe1d70       # 400056b4  = 0x3ffe4240
	l32r	a12, lit_3ffe1d70       # 400056b7  = 0x3ffe4240
	l32i.n	a12, a12, 8             # 400056ba
	slli	a12, a12, 16            # 400056bc
	s32i.n	a12, a13, 20            # 400056bf
	l32r	a10, lit_3ffe1dc0       # 400056c1  = 0x3ffe4420
	l32r	a11, lit_3ffe1d70       # 400056c4  = 0x3ffe4240
	l32i.n	a11, a11, 8             # 400056c7
	call8	fn_400054a4             # 400056c9
	l32r	a4, lit_3ffe1da0        # 400056cc  = 0x3ffe4410
	movi.n	a3, 35                  # 400056cf
	s8i	a3, a4, 0               # 400056d1
	l32r	a3, lit_3ffe1d9c        # 400056d4  = 0x3ffe4411
	l32r	a2, lit_3ffe1dd8        # 400056d7  = 0x3ffe4424
	l8ui	a2, a2, 0               # 400056da
	s8i	a2, a3, 0               # 400056dd
	l32r	a2, lit_3ffe1dc4        # 400056e0  = 0x3ffe4412
	l32r	a15, lit_3ffe1ddc       # 400056e3  = 0x3ffe4425
	l8ui	a15, a15, 0             # 400056e6
	s8i	a15, a2, 0              # 400056e9
	l32r	a15, lit_3ffe1dc8       # 400056ec  = 0x3ffe4413
	l32r	a14, lit_3ffe1de0       # 400056ef  = 0x3ffe4426
	l8ui	a14, a14, 0             # 400056f2
	s8i	a14, a15, 0             # 400056f5
	l32r	a14, lit_3ffe1dcc       # 400056f8  = 0x3ffe4414
	l32r	a13, lit_3ffe1de4       # 400056fb  = 0x3ffe4427
	l8ui	a13, a13, 0             # 400056fe
	s8i	a13, a14, 0             # 40005701
	l32r	a12, lit_3ffe1dd0       # 40005704  = 0x3ffe4415
	movi.n	a11, 32                 # 40005707
	s8i	a11, a12, 0             # 40005709
	l32r	a10, lit_3ffe1dd4       # 4000570c  = 0x3ffe4416
	movi.n	a9, 79                  # 4000570f
	s8i	a9, a10, 0              # 40005711
	l32r	a8, lit_3ffe1de8        # 40005714  = 0x3ffe4417
	movi.n	a7, 75                  # 40005717
	s8i	a7, a8, 0               # 40005719
	l32r	a6, lit_3ffe1dec        # 4000571c  = 0x3ffe4418
	movi.n	a5, 33                  # 4000571f
	s8i	a5, a6, 0               # 40005721
	l32r	a4, lit_3ffe1da4        # 40005724  = 0x3ffe4419
	movi.n	a3, 35                  # 40005727
	s8i	a3, a4, 0               # 40005729
	l32r	a2, lit_3ffe1da8        # 4000572c  = 0x3ffe441a
	movi.n	a15, 10                 # 4000572f
	s8i	a15, a2, 0              # 40005731
	l32r	a14, lit_3ffe1dac       # 40005734  = 0x3ffe441b
	movi.n	a13, 0                  # 40005737
	s8i	a13, a14, 0             # 40005739
	l32r	a10, lit_3ffe1da0       # 4000573c  = 0x3ffe4410
	call8	fn_400099bc             # 4000573f
	j	.L40005748              # 40005742
.L40005745:
	j	.L40005748              # 40005745
.L40005748:
	l32i.n	a2, a1, 0               # 40005748
	retw.n                          # 4000574a
	.size	fn_40005574, . - fn_40005574
