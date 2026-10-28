# fn_400075fc: 0x400075fc-0x40007709 (firmware file offset 0x375fc-0x37709), 104 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_40006be8, fn_4000912c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400075fc, @function
fn_400075fc:
	entry	a1, 192                 # 400075fc
	extui	a7, a2, 0, 8            # 400075ff
	s8i	a7, a1, 144             # 40007602
	s32i	a3, a1, 148             # 40007605
	extui	a3, a4, 0, 8            # 40007608
	s8i	a3, a1, 152             # 4000760b
	s32i	a5, a1, 156             # 4000760e
	movi.n	a11, 0                  # 40007611
	s32i.n	a11, a1, 0              # 40007613
	movi.n	a10, 0                  # 40007615
	s32i.n	a10, a1, 4              # 40007617
	l32i	a9, a1, 148             # 40007619
	bnei	a9, 1, .L40007654       # 4000761c
	addi	a13, a1, 16             # 4000761f
	l32i	a14, a1, 156            # 40007622
	l8ui	a14, a14, 0             # 40007625
	slli	a14, a14, 16            # 40007628
	l8ui	a15, a1, 152            # 4000762b
	slli	a15, a15, 8             # 4000762e
	movi.n	a2, 64                  # 40007631
	l8ui	a12, a1, 144            # 40007633
	or	a12, a12, a2            # 40007636
	extui	a12, a12, 0, 8          # 40007639
	add.n	a12, a12, a15           # 4000763c
	add.n	a12, a12, a14           # 4000763e
	s32i.n	a12, a13, 0             # 40007640
	movi.n	a10, 1                  # 40007642
	addi	a11, a1, 16             # 40007644
	movi.n	a12, 1                  # 40007647
	call8	fn_40006be8             # 40007649
	movi.n	a10, 1                  # 4000764c
	call8	fn_4000912c             # 4000764e
	j	.L40007708              # 40007651
.L40007654:
	l32i	a2, a1, 148             # 40007654
	movi	a15, 254                # 40007657
	bgeu	a15, a2, .L40007660     # 4000765a
	j	.L40007708              # 4000765d
.L40007660:
	addi	a8, a1, 16              # 40007660
	l32i	a11, a1, 148            # 40007663
	slli	a11, a11, 8             # 40007666
	l8ui	a10, a1, 144            # 40007669
	add.n	a10, a10, a11           # 4000766c
	l8ui	a9, a1, 152             # 4000766e
	slli	a9, a9, 16              # 40007671
	add.n	a9, a9, a10             # 40007674
	l32i	a7, a1, 156             # 40007676
	l8ui	a7, a7, 0               # 40007679
	slli	a7, a7, 24              # 4000767c
	add.n	a7, a7, a9              # 4000767f
	s32i.n	a7, a8, 0               # 40007681
	l32i	a6, a1, 148             # 40007683
	addi.n	a6, a6, 3               # 40007686
	srli	a6, a6, 2               # 40007688
	s32i.n	a6, a1, 0               # 4000768b
	movi.n	a5, 1                   # 4000768d
	s32i.n	a5, a1, 4               # 4000768f
	l32i.n	a4, a1, 0               # 40007691
	l32i.n	a3, a1, 4               # 40007693
	bgeu	a3, a4, .L400076f3      # 40007695
.L40007698:
	l32i.n	a2, a1, 4               # 40007698
	addi	a3, a1, 16              # 4000769a
	addx4	a2, a2, a3              # 4000769d
	l32i.n	a3, a1, 4               # 400076a0
	l32i	a4, a1, 156             # 400076a2
	addx4	a3, a3, a4              # 400076a5
	l8ui	a3, a3, 0               # 400076a8
	slli	a3, a3, 24              # 400076ab
	l32i.n	a4, a1, 4               # 400076ae
	l32i	a5, a1, 156             # 400076b0
	addx4	a4, a4, a5              # 400076b3
	addmi	a4, a4, 0xffffff00      # 400076b6
	l8ui	a4, a4, 255             # 400076b9
	slli	a4, a4, 16              # 400076bc
	l32i.n	a5, a1, 4               # 400076bf
	l32i	a6, a1, 156             # 400076c1
	addx4	a5, a5, a6              # 400076c4
	addmi	a5, a5, 0xffffff00      # 400076c7
	l8ui	a5, a5, 254             # 400076ca
	slli	a5, a5, 8               # 400076cd
	l32i.n	a15, a1, 4              # 400076d0
	l32i	a6, a1, 156             # 400076d2
	addx4	a15, a15, a6            # 400076d5
	addmi	a15, a15, 0xffffff00    # 400076d8
	l8ui	a15, a15, 253           # 400076db
	add.n	a15, a15, a5            # 400076de
	add.n	a15, a15, a4            # 400076e0
	add.n	a15, a15, a3            # 400076e2
	s32i.n	a15, a2, 0              # 400076e4
	l32i.n	a14, a1, 4              # 400076e6
	addi.n	a14, a14, 1             # 400076e8
	s32i.n	a14, a1, 4              # 400076ea
	l32i.n	a13, a1, 0              # 400076ec
	l32i.n	a12, a1, 4              # 400076ee
	bltu	a12, a13, .L40007698    # 400076f0
.L400076f3:
	l32i.n	a4, a1, 0               # 400076f3
	addi.n	a4, a4, 1               # 400076f5
	s32i.n	a4, a1, 0               # 400076f7
	l32i.n	a10, a1, 0              # 400076f9
	addi	a11, a1, 16             # 400076fb
	movi.n	a12, 1                  # 400076fe
	call8	fn_40006be8             # 40007700
	movi.n	a10, 2                  # 40007703
	call8	fn_4000912c             # 40007705
.L40007708:
	retw.n                          # 40007708
	.size	fn_400075fc, . - fn_400075fc
