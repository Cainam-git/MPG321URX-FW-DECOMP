# leon2m FUN_a01215e8 0xa01215e8-0xa01216f8 (272 bytes)
a01215e8:  9d e3 bf 98  save  %sp, -104, %sp
a01215ec:  a0 0e 20 ff  and  %i0, 0xff, %l0
a01215f0:  94 10 20 01  mov  1, %o2
a01215f4:  96 10 20 00  clr  %o3
a01215f8:  90 10 00 10  mov  %l0, %o0
a01215fc:  7f ff 41 58  call  0xa00f1b5c
a0121600:  92 10 20 56  mov  0x56, %o1
a0121604:  92 10 20 04  mov  4, %o1
a0121608:  7f ff 41 22  call  0xa00f1a90
a012160c:  90 10 00 10  mov  %l0, %o0
a0121610:  82 0a 20 03  and  %o0, 3, %g1
a0121614:  92 10 20 00  clr  %o1
a0121618:  80 a0 60 03  cmp  %g1, 3
a012161c:  02 80 00 0a  be  0xa0121644
a0121620:  90 10 00 10  mov  %l0, %o0
a0121624:  7f ff 41 1b  call  0xa00f1a90
a0121628:  01 00 00 00  nop
a012162c:  80 8a 20 40  btst  0x40, %o0
a0121630:  94 10 20 40  mov  0x40, %o2
a0121634:  96 10 20 00  clr  %o3
a0121638:  92 10 20 00  clr  %o1
a012163c:  12 80 00 29  bne  0xa01216e0
a0121640:  90 10 00 10  mov  %l0, %o0
a0121644:  92 10 20 04  mov  4, %o1
a0121648:  7f ff 41 12  call  0xa00f1a90
a012164c:  90 10 00 10  mov  %l0, %o0
a0121650:  94 0a 20 03  and  %o0, 3, %o2
a0121654:  92 10 20 03  mov  3, %o1
a0121658:  80 a2 a0 03  cmp  %o2, 3
a012165c:  02 80 00 14  be  0xa01216ac
a0121660:  90 10 00 10  mov  %l0, %o0
a0121664:  92 10 20 03  mov  3, %o1
a0121668:  7f ff 41 0a  call  0xa00f1a90
a012166c:  90 10 00 10  mov  %l0, %o0
a0121670:  80 8a 20 20  btst  0x20, %o0
a0121674:  92 10 20 11  mov  0x11, %o1
a0121678:  90 10 00 10  mov  %l0, %o0
a012167c:  02 80 00 15  be  0xa01216d0
a0121680:  82 10 20 00  clr  %g1
a0121684:  b0 10 00 10  mov  %l0, %i0
a0121688:  b2 10 20 00  clr  %i1
a012168c:  b4 10 20 04  mov  4, %i2
a0121690:  80 a0 60 00  cmp  %g1, 0
a0121694:  02 80 00 04  be  0xa01216a4
a0121698:  b6 10 20 01  mov  1, %i3
a012169c:  7f ff 41 30  call  0xa00f1b5c
a01216a0:  81 e8 00 00  restore
a01216a4:  7f ff 41 2e  call  0xa00f1b5c
a01216a8:  97 e8 20 00  restore  %g0, 0, %o3
a01216ac:  7f ff 40 f9  call  0xa00f1a90
a01216b0:  01 00 00 00  nop
a01216b4:  90 0a 20 01  and  %o0, 1, %o0
a01216b8:  7f ff 3f f6  call  0xa00f1690
a01216bc:  92 10 20 8f  mov  0x8f, %o1
a01216c0:  90 0a 20 04  and  %o0, 4, %o0
a01216c4:  80 a0 00 08  cmp  %g0, %o0
a01216c8:  10 bf ff ef  b  0xa0121684
a01216cc:  82 40 20 00  addx  %g0, 0, %g1
a01216d0:  7f ff 42 33  call  0xa00f1f9c
a01216d4:  01 00 00 00  nop
a01216d8:  10 bf ff fb  b  0xa01216c4
a01216dc:  90 0a 20 04  and  %o0, 4, %o0
a01216e0:  7f ff 41 1f  call  0xa00f1b5c
a01216e4:  01 00 00 00  nop
a01216e8:  67 fd ae ae  call  0x4008d1a0
a01216ec:  90 10 20 78  mov  0x78, %o0	! 0x78
a01216f0:  10 bf ff d6  b  0xa0121648
a01216f4:  92 10 20 04  mov  4, %o1
