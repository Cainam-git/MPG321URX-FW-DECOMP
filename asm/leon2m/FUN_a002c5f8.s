# leon2m FUN_a002c5f8 0xa002c5f8-0xa002c704 (268 bytes)
a002c5f8:  9d e3 bf 98  save  %sp, -104, %sp
a002c5fc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a002c600:  80 a6 20 01  cmp  %i0, 1
a002c604:  22 80 00 08  be,a   0xa002c624
a002c608:  b6 0e e0 ff  and  %i3, 0xff, %i3
a002c60c:  04 80 00 28  ble  0xa002c6ac
a002c610:  80 a6 20 02  cmp  %i0, 2
a002c614:  12 80 00 3a  bne  0xa002c6fc
a002c618:  b6 0e e0 ff  and  %i3, 0xff, %i3
a002c61c:  10 80 00 14  b  0xa002c66c
a002c620:  80 a6 e0 00  cmp  %i3, 0
a002c624:  80 a6 e0 00  cmp  %i3, 0
a002c628:  02 80 00 35  be  0xa002c6fc
a002c62c:  b0 10 20 00  clr  %i0
a002c630:  13 27 c4 c0  sethi  %hi(0x9f130000), %o1
a002c634:  b2 0e 60 ff  and  %i1, 0xff, %i1
a002c638:  a0 12 61 00  or  %o1, 0x100, %l0
a002c63c:  82 10 20 00  clr  %g1
a002c640:  97 28 60 02  sll  %g1, 2, %o3
a002c644:  98 06 40 0b  add  %i1, %o3, %o4
a002c648:  90 03 00 10  add  %o4, %l0, %o0
a002c64c:  7f ff ff 04  call  0xa002c25c
a002c650:  d2 06 80 0b  ld  [ %i2 + %o3 ], %o1
a002c654:  b0 06 20 01  inc  %i0
a002c658:  82 0e 20 ff  and  %i0, 0xff, %g1
a002c65c:  80 a0 40 1b  cmp  %g1, %i3
a002c660:  0a bf ff f9  bcs  0xa002c644
a002c664:  97 28 60 02  sll  %g1, 2, %o3
a002c668:  30 80 00 25  b,a   0xa002c6fc
a002c66c:  02 80 00 24  be  0xa002c6fc
a002c670:  b0 10 20 00  clr  %i0
a002c674:  b2 0e 60 ff  and  %i1, 0xff, %i1
a002c678:  82 10 20 00  clr  %g1
a002c67c:  21 2d c2 44  sethi  %hi(0xb7091000), %l0
a002c680:  9b 28 60 02  sll  %g1, 2, %o5
a002c684:  9e 06 40 0d  add  %i1, %o5, %o7
a002c688:  90 03 c0 10  add  %o7, %l0, %o0
a002c68c:  7f ff fe f4  call  0xa002c25c
a002c690:  d2 06 80 0d  ld  [ %i2 + %o5 ], %o1
a002c694:  b0 06 20 01  inc  %i0
a002c698:  82 0e 20 ff  and  %i0, 0xff, %g1
a002c69c:  80 a0 40 1b  cmp  %g1, %i3
a002c6a0:  0a bf ff f9  bcs  0xa002c684
a002c6a4:  9b 28 60 02  sll  %g1, 2, %o5
a002c6a8:  30 80 00 15  b,a   0xa002c6fc
a002c6ac:  80 a6 20 00  cmp  %i0, 0
a002c6b0:  12 80 00 13  bne  0xa002c6fc
a002c6b4:  b6 0e e0 ff  and  %i3, 0xff, %i3
a002c6b8:  80 a6 00 1b  cmp  %i0, %i3
a002c6bc:  1a 80 00 10  bcc  0xa002c6fc
a002c6c0:  b0 10 20 00  clr  %i0
a002c6c4:  03 27 c2 80  sethi  %hi(0x9f0a0000), %g1
a002c6c8:  a0 10 61 00  or  %g1, 0x100, %l0	! 0x9f0a0100
a002c6cc:  b2 0e 60 ff  and  %i1, 0xff, %i1
a002c6d0:  82 10 20 00  clr  %g1
a002c6d4:  95 28 60 02  sll  %g1, 2, %o2
a002c6d8:  90 06 40 0a  add  %i1, %o2, %o0
a002c6dc:  90 02 00 10  add  %o0, %l0, %o0
a002c6e0:  7f ff fe df  call  0xa002c25c
a002c6e4:  d2 06 80 0a  ld  [ %i2 + %o2 ], %o1
a002c6e8:  b0 06 20 01  inc  %i0
a002c6ec:  82 0e 20 ff  and  %i0, 0xff, %g1
a002c6f0:  80 a0 40 1b  cmp  %g1, %i3
a002c6f4:  0a bf ff f9  bcs  0xa002c6d8
a002c6f8:  95 28 60 02  sll  %g1, 2, %o2
a002c6fc:  81 c7 e0 08  ret
a002c700:  81 e8 00 00  restore
