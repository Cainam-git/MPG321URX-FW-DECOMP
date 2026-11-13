# leon2m FUN_a01516b0 0xa01516b0-0xa01517f4 (324 bytes)
a01516b0:  9d e3 bf 98  save  %sp, -104, %sp
a01516b4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01516b8:  11 00 06 9d  sethi  %hi(0x1a7400), %o0
a01516bc:  90 12 20 c8  or  %o0, 0xc8, %o0	! 0x1a74c8
a01516c0:  7f fe 36 ac  call  0xa00df170
a01516c4:  92 10 00 18  mov  %i0, %o1
a01516c8:  80 a6 20 02  cmp  %i0, 2
a01516cc:  02 80 00 3d  be  0xa01517c0
a01516d0:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a01516d4:  14 80 00 28  bg  0xa0151774
a01516d8:  80 a6 20 03  cmp  %i0, 3
a01516dc:  80 a6 20 01  cmp  %i0, 1
a01516e0:  02 80 00 3a  be  0xa01517c8
a01516e4:  13 2a 00 b7  sethi  %hi(0xa802dc00), %o1
a01516e8:  1b 2a 00 b7  sethi  %hi(0xa802dc00), %o5
a01516ec:  c2 03 63 30  ld  [ %o5 + 0x330 ], %g1	! 0xa802df30
a01516f0:  99 30 60 0c  srl  %g1, 0xc, %o4
a01516f4:  82 0b 20 0f  and  %o4, 0xf, %g1
a01516f8:  a0 08 60 ff  and  %g1, 0xff, %l0
a01516fc:  80 a4 20 00  cmp  %l0, 0
a0151700:  02 80 00 27  be  0xa015179c
a0151704:  01 00 00 00  nop
a0151708:  7f ff c5 e1  call  0xa0142e8c
a015170c:  90 10 00 10  mov  %l0, %o0
a0151710:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0151714:  80 a4 20 05  cmp  %l0, 5
a0151718:  02 80 00 15  be  0xa015176c
a015171c:  11 2a 00 b7  sethi  %hi(0xa802dc00), %o0
a0151720:  a2 12 23 30  or  %o0, 0x330, %l1	! 0xa802df30
a0151724:  a0 10 20 00  clr  %l0
a0151728:  9a 10 20 00  clr  %o5
a015172c:  95 2b 60 04  sll  %o5, 4, %o2
a0151730:  92 22 80 0d  sub  %o2, %o5, %o1
a0151734:  83 2a 60 03  sll  %o1, 3, %g1
a0151738:  80 a3 40 18  cmp  %o5, %i0
a015173c:  02 80 00 08  be  0xa015175c
a0151740:  a0 04 20 01  inc  %l0
a0151744:  d6 04 40 01  ld  [ %l1 + %g1 ], %o3
a0151748:  99 32 e0 0c  srl  %o3, 0xc, %o4
a015174c:  9b 32 e0 1c  srl  %o3, 0x1c, %o5
a0151750:  80 a3 60 0c  cmp  %o5, 0xc
a0151754:  02 80 00 1f  be  0xa01517d0
a0151758:  90 0b 20 0f  and  %o4, 0xf, %o0
a015175c:  9a 0c 20 ff  and  %l0, 0xff, %o5
a0151760:  80 a3 60 03  cmp  %o5, 3
a0151764:  08 bf ff f3  bleu  0xa0151730
a0151768:  95 2b 60 04  sll  %o5, 4, %o2
a015176c:  7f ff 79 62  call  0xa012fcf4
a0151770:  81 e8 00 00  restore
a0151774:  12 bf ff de  bne  0xa01516ec
a0151778:  1b 2a 00 b7  sethi  %hi(0xa802dc00), %o5
a015177c:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0151780:  c2 02 e0 98  ld  [ %o3 + 0x98 ], %g1	! 0xa802e098
a0151784:  99 30 60 0c  srl  %g1, 0xc, %o4
a0151788:  82 0b 20 0f  and  %o4, 0xf, %g1
a015178c:  a0 08 60 ff  and  %g1, 0xff, %l0
a0151790:  80 a4 20 00  cmp  %l0, 0
a0151794:  12 bf ff dd  bne  0xa0151708
a0151798:  01 00 00 00  nop
a015179c:  7f fe b0 21  call  0xa00fd820
a01517a0:  90 10 20 00  clr  %o0	! 0x0
a01517a4:  9e 0a 20 ff  and  %o0, 0xff, %o7
a01517a8:  80 a3 e0 b1  cmp  %o7, 0xb1
a01517ac:  12 bf ff d7  bne  0xa0151708
a01517b0:  01 00 00 00  nop
a01517b4:  7f ff 79 1b  call  0xa012fc20
a01517b8:  01 00 00 00  nop
a01517bc:  30 bf ff d3  b,a   0xa0151708
a01517c0:  10 bf ff cc  b  0xa01516f0
a01517c4:  c2 02 a0 20  ld  [ %o2 + 0x20 ], %g1
a01517c8:  10 bf ff ca  b  0xa01516f0
a01517cc:  c2 02 63 a8  ld  [ %o1 + 0x3a8 ], %g1
a01517d0:  7f ff c5 af  call  0xa0142e8c
a01517d4:  01 00 00 00  nop
a01517d8:  82 0a 20 ff  and  %o0, 0xff, %g1
a01517dc:  80 a0 60 05  cmp  %g1, 5
a01517e0:  02 bf ff e0  be  0xa0151760
a01517e4:  9a 0c 20 ff  and  %l0, 0xff, %o5
a01517e8:  7f ff 79 43  call  0xa012fcf4
a01517ec:  81 e8 00 00  restore
a01517f0:  01 00 00 00  nop
