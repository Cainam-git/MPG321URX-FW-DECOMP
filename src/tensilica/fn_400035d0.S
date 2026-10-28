# fn_400035d0: 0x400035d0-0x40003762 (firmware file offset 0x335d0-0x33762), 151 instructions
# Called from: fn_40003764
# Calls: fn_4000aa64, fn_400030b4, fn_4000082c, fn_400030c8, fn_40003140, fn_40003174, fn_400011e4,
#        fn_40003558, fn_40003190
# Indirect calls (callx): 2
# Addresses loaded: ro_3ffe0494
# Other literal values: 0x3ffe2bf0, 0x3ffe4490, 0x3ffe3ef0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400035d0, @function
fn_400035d0:
	entry	a1, 0x130               # 400035d0
	addi	a10, a1, 32             # 400035d3
	l32r	a11, lit_3ffe1cb0       # 400035d6  = ro_3ffe0494
	movi.n	a12, 32                 # 400035d9
	call8	fn_4000aa64             # 400035db
	l32r	a2, lit_3ffe1a80        # 400035de  = 0x3ffe2bf0
	l32i	a2, a2, 0x154           # 400035e1
	bnei	a2, 1, .L400035ed       # 400035e4
	addi	a10, a1, 32             # 400035e7
	call8	fn_400030b4             # 400035ea
.L400035ed:
	l32r	a3, lit_3ffe1a80        # 400035ed  = 0x3ffe2bf0
	l32i	a3, a3, 0x144           # 400035f0
	bnei	a3, 4, .L40003613       # 400035f3
	l32r	a10, lit_3ffe1b88       # 400035f6  = 0x3ffe4490
	addi	a11, a1, 64             # 400035f9
	l32r	a8, lit_3ffe1a80        # 400035fc  = 0x3ffe2bf0
	l32i	a8, a8, 0x148           # 400035ff
	callx8	a8                      # 40003602
	addi	a10, a1, 64             # 40003605
	l32r	a11, lit_3ffe1ac4       # 40003608  = 0x3ffe3ef0
	movi.n	a12, 32                 # 4000360b
	call8	fn_4000082c             # 4000360d
	j	.L40003720              # 40003610
.L40003613:
	l32r	a9, lit_3ffe1a80        # 40003613  = 0x3ffe2bf0
	l32i	a9, a9, 0x144           # 40003616
	beqi	a9, 1, .L40003628       # 40003619
	l32r	a10, lit_3ffe1a80       # 4000361c  = 0x3ffe2bf0
	l32i	a10, a10, 0x144         # 4000361f
	beqi	a10, 2, .L40003628      # 40003622
	j	.L40003720              # 40003625
.L40003628:
	movi.n	a13, 0                  # 40003628
	s32i	a13, a1, 192            # 4000362a
	l32i	a12, a1, 192            # 4000362d
	movi.n	a11, 31                 # 40003630
	bltu	a11, a12, .L40003652    # 40003632
.L40003635:
	l32i	a4, a1, 192             # 40003635
	addi	a5, a1, 64              # 40003638
	addx4	a4, a4, a5              # 4000363b
	movi.n	a3, 0                   # 4000363e
	s32i.n	a3, a4, 0               # 40003640
	l32i	a2, a1, 192             # 40003642
	addi.n	a2, a2, 1               # 40003645
	s32i	a2, a1, 192             # 40003647
	l32i	a15, a1, 192            # 4000364a
	movi.n	a14, 31                 # 4000364d
	bgeu	a14, a15, .L40003635    # 4000364f
.L40003652:
	l32r	a10, lit_3ffe1b88       # 40003652  = 0x3ffe4490
	addi	a11, a1, 64             # 40003655
	l32r	a8, lit_3ffe1a80        # 40003658  = 0x3ffe2bf0
	l32i	a8, a8, 0x148           # 4000365b
	callx8	a8                      # 4000365e
	addi	a12, a1, 32             # 40003661
	s32i	a12, a1, 196            # 40003664
	mov.n	a11, a1                 # 40003667
	s32i	a11, a1, 200            # 40003669
	movi.n	a10, 0                  # 4000366c
	s32i	a10, a1, 204            # 4000366e
	movi.n	a9, 8                   # 40003671
	s32i	a9, a1, 208             # 40003673
.L40003676:
	l32i	a15, a1, 204            # 40003676
	l32i	a3, a1, 200             # 40003679
	add.n	a3, a15, a3             # 4000367c
	l32i	a2, a1, 196             # 4000367e
	add.n	a2, a15, a2             # 40003681
	l32i.n	a2, a2, 0               # 40003683
	s32i.n	a2, a3, 0               # 40003685
	addi.n	a15, a15, 4             # 40003687
	s32i	a15, a1, 204            # 40003689
	l32i	a14, a1, 208            # 4000368c
	addi.n	a14, a14, -1            # 4000368f
	s32i	a14, a1, 208            # 40003691
	movi.n	a13, 0                  # 40003694
	blt	a13, a14, .L40003676    # 40003696
	addi	a10, a1, 64             # 40003699
	call8	fn_400030c8             # 4000369c
	addi	a7, a1, 32              # 4000369f
	s32i	a7, a1, 212             # 400036a2
	mov.n	a6, a1                  # 400036a5
	s32i	a6, a1, 216             # 400036a7
	movi.n	a5, 0                   # 400036aa
	s32i	a5, a1, 220             # 400036ac
	movi.n	a4, 8                   # 400036af
	s32i	a4, a1, 224             # 400036b1
.L400036b4:
	l32i	a10, a1, 220            # 400036b4
	l32i	a12, a1, 216            # 400036b7
	add.n	a12, a10, a12           # 400036ba
	l32i	a11, a1, 212            # 400036bc
	add.n	a11, a10, a11           # 400036bf
	l32i.n	a11, a11, 0             # 400036c1
	s32i.n	a11, a12, 0             # 400036c3
	addi.n	a10, a10, 4             # 400036c5
	s32i	a10, a1, 220            # 400036c7
	l32i	a9, a1, 224             # 400036ca
	addi.n	a9, a9, -1              # 400036cd
	s32i	a9, a1, 224             # 400036cf
	movi.n	a8, 0                   # 400036d2
	blt	a8, a9, .L400036b4      # 400036d4
	addi	a10, a1, 64             # 400036d7
	call8	fn_40003140             # 400036da
	addi	a2, a1, 32              # 400036dd
	s32i	a2, a1, 228             # 400036e0
	mov.n	a15, a1                 # 400036e3
	s32i	a15, a1, 232            # 400036e5
	movi.n	a14, 0                  # 400036e8
	s32i	a14, a1, 236            # 400036ea
	movi.n	a13, 8                  # 400036ed
	s32i	a13, a1, 240            # 400036ef
.L400036f2:
	l32i	a5, a1, 236             # 400036f2
	l32i	a7, a1, 232             # 400036f5
	add.n	a7, a5, a7              # 400036f8
	l32i	a6, a1, 228             # 400036fa
	add.n	a6, a5, a6              # 400036fd
	l32i.n	a6, a6, 0               # 400036ff
	s32i.n	a6, a7, 0               # 40003701
	addi.n	a5, a5, 4               # 40003703
	s32i	a5, a1, 236             # 40003705
	l32i	a4, a1, 240             # 40003708
	addi.n	a4, a4, -1              # 4000370b
	s32i	a4, a1, 240             # 4000370d
	movi.n	a3, 0                   # 40003710
	blt	a3, a4, .L400036f2      # 40003712
	l32r	a10, lit_3ffe1b88       # 40003715  = 0x3ffe4490
	call8	fn_40003174             # 40003718
	movi.n	a10, 0                  # 4000371b
	call8	fn_400011e4             # 4000371d
.L40003720:
	call8	fn_40003558             # 40003720
	addi	a11, a1, 32             # 40003723
	s32i	a11, a1, 244            # 40003726
	mov.n	a10, a1                 # 40003729
	s32i	a10, a1, 248            # 4000372b
	movi.n	a9, 0                   # 4000372e
	s32i	a9, a1, 252             # 40003730
	movi.n	a8, 8                   # 40003733
	s32i	a8, a1, 0x100           # 40003735
.L40003738:
	l32i	a14, a1, 252            # 40003738
	l32i	a2, a1, 248             # 4000373b
	add.n	a2, a14, a2             # 4000373e
	l32i	a15, a1, 244            # 40003740
	add.n	a15, a14, a15           # 40003743
	l32i.n	a15, a15, 0             # 40003745
	s32i.n	a15, a2, 0              # 40003747
	addi.n	a14, a14, 4             # 40003749
	s32i	a14, a1, 252            # 4000374b
	l32i	a13, a1, 0x100          # 4000374e
	addi.n	a13, a13, -1            # 40003751
	s32i	a13, a1, 0x100          # 40003753
	movi.n	a12, 0                  # 40003756
	blt	a12, a13, .L40003738    # 40003758
	addi	a10, a1, 64             # 4000375b
	call8	fn_40003190             # 4000375e
	retw.n                          # 40003761
	.size	fn_400035d0, . - fn_400035d0
