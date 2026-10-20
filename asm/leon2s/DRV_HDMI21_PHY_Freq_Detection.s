# leon2s DRV_HDMI21_PHY_Freq_Detection 0xa009a580-0xa009a698 (280 bytes)
a009a580:  9d e3 bf 98  save  %sp, -104, %sp
a009a584:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009a588:  80 a6 20 00  cmp  %i0, 0
a009a58c:  02 80 00 05  be  0xa009a5a0
a009a590:  a0 10 20 02  mov  2, %l0
a009a594:  80 a6 20 01  cmp  %i0, 1
a009a598:  12 80 00 3e  bne  0xa009a690
a009a59c:  a0 10 20 03  mov  3, %l0
a009a5a0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009a5a4:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009a5a8:  80 88 68 00  btst  0x800, %g1
a009a5ac:  02 80 00 08  be  0xa009a5cc
a009a5b0:  a8 0c 20 ff  and  %l0, 0xff, %l4
a009a5b4:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009a5b8:  13 28 02 d0  sethi  %hi(0xa00b4000), %o1
a009a5bc:  90 12 22 98  or  %o0, 0x298, %o0
a009a5c0:  7f ff 62 a1  call  0xa0073044
a009a5c4:  92 12 63 90  or  %o1, 0x390, %o1
a009a5c8:  a8 0c 20 ff  and  %l0, 0xff, %l4
a009a5cc:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009a5d0:  92 12 63 54  or  %o1, 0x354, %o1	! 0x2f54
a009a5d4:  90 10 00 14  mov  %l4, %o0
a009a5d8:  94 10 3f 00  mov  -256, %o2
a009a5dc:  40 00 33 ab  call  0xa00a7488
a009a5e0:  96 10 20 5f  mov  0x5f, %o3
a009a5e4:  aa 10 20 00  clr  %l5
a009a5e8:  a6 0d 60 ff  and  %l5, 0xff, %l3
a009a5ec:  25 00 00 0b  sethi  %hi(0x2c00), %l2
a009a5f0:  15 3f c0 3f  sethi  %hi(0xff00fc00), %o2
a009a5f4:  94 12 a3 ff  or  %o2, 0x3ff, %o2	! 0xff00ffff
a009a5f8:  90 10 00 14  mov  %l4, %o0
a009a5fc:  92 14 a3 50  or  %l2, 0x350, %o1
a009a600:  40 00 33 a2  call  0xa00a7488
a009a604:  97 2c e0 10  sll  %l3, 0x10, %o3
a009a608:  94 10 00 14  mov  %l4, %o2
a009a60c:  96 14 a3 50  or  %l2, 0x350, %o3
a009a610:  92 10 20 18  mov  0x18, %o1
a009a614:  40 00 33 84  call  0xa00a7424
a009a618:  90 10 20 01  mov  1, %o0
a009a61c:  40 00 5b fc  call  0xa00b160c
a009a620:  90 10 20 14  mov  0x14, %o0
a009a624:  92 14 a3 54  or  %l2, 0x354, %o1
a009a628:  90 10 00 14  mov  %l4, %o0
a009a62c:  40 00 33 3a  call  0xa00a7314
a009a630:  23 00 07 ff  sethi  %hi(0x1ffc00), %l1
a009a634:  a2 14 63 00  or  %l1, 0x300, %l1	! 0x1fff00
a009a638:  a1 2e 20 02  sll  %i0, 2, %l0
a009a63c:  a0 04 00 13  add  %l0, %l3, %l0
a009a640:  90 0a 00 11  and  %o0, %l1, %o0
a009a644:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009a648:  82 10 60 5a  or  %g1, 0x5a, %g1	! 0xa807905a
a009a64c:  91 32 20 08  srl  %o0, 8, %o0
a009a650:  a0 04 00 10  add  %l0, %l0, %l0
a009a654:  d0 30 40 10  sth  %o0, [ %g1 + %l0 ]
a009a658:  92 14 a3 54  or  %l2, 0x354, %o1
a009a65c:  40 00 33 2e  call  0xa00a7314
a009a660:  90 10 00 14  mov  %l4, %o0
a009a664:  94 0a 00 11  and  %o0, %l1, %o2
a009a668:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009a66c:  90 12 22 b0  or  %o0, 0x2b0, %o0	! 0xa006a2b0
a009a670:  92 10 00 13  mov  %l3, %o1
a009a674:  7f ff 62 74  call  0xa0073044
a009a678:  95 32 a0 08  srl  %o2, 8, %o2
a009a67c:  aa 05 60 01  inc  %l5
a009a680:  82 0d 60 ff  and  %l5, 0xff, %g1
a009a684:  80 a0 60 03  cmp  %g1, 3
a009a688:  08 bf ff d9  bleu  0xa009a5ec
a009a68c:  a6 0d 60 ff  and  %l5, 0xff, %l3
a009a690:  81 c7 e0 08  ret
a009a694:  81 e8 00 00  restore
