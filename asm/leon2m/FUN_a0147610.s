# leon2m FUN_a0147610 0xa0147610-0xa01476c0 (176 bytes)
a0147610:  9d e3 bf 98  save  %sp, -104, %sp
a0147614:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0147618:  80 a6 20 01  cmp  %i0, 1
a014761c:  02 80 00 0b  be  0xa0147648
a0147620:  82 10 20 01  mov  1, %g1
a0147624:  80 a6 20 01  cmp  %i0, 1
a0147628:  04 80 00 1f  ble  0xa01476a4
a014762c:  80 a6 20 02  cmp  %i0, 2
a0147630:  02 80 00 06  be  0xa0147648
a0147634:  82 10 20 02  mov  2, %g1
a0147638:  80 a6 20 03  cmp  %i0, 3
a014763c:  02 80 00 03  be  0xa0147648
a0147640:  82 10 20 03  mov  3, %g1
a0147644:  82 10 3f ff  mov  -1, %g1
a0147648:  9a 08 60 ff  and  %g1, 0xff, %o5
a014764c:  80 a3 60 03  cmp  %o5, 3
a0147650:  18 80 00 11  bgu  0xa0147694
a0147654:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0147658:  9f 2b 60 04  sll  %o5, 4, %o7
a014765c:  96 23 c0 0d  sub  %o7, %o5, %o3
a0147660:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0147664:  83 2a e0 03  sll  %o3, 3, %g1
a0147668:  9a 12 a3 30  or  %o2, 0x330, %o5
a014766c:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a0147670:  99 32 60 04  srl  %o1, 4, %o4
a0147674:  90 0b 20 0f  and  %o4, 0xf, %o0
a0147678:  80 a2 20 04  cmp  %o0, 4
a014767c:  02 80 00 0f  be  0xa01476b8
a0147680:  01 00 00 00  nop
a0147684:  7f fe bb 4e  call  0xa00f63bc
a0147688:  b0 10 00 19  mov  %i1, %i0
a014768c:  7f fe bb 9f  call  0xa00f6508
a0147690:  81 e8 00 00  restore
a0147694:  7f fe 5e b7  call  0xa00df170
a0147698:  90 12 21 d8  or  %o0, 0x1d8, %o0
a014769c:  10 bf ff ef  b  0xa0147658
a01476a0:  9a 10 20 00  clr  %o5
a01476a4:  80 a6 20 00  cmp  %i0, 0
a01476a8:  02 bf ff e8  be  0xa0147648
a01476ac:  82 10 20 00  clr  %g1
a01476b0:  10 bf ff e6  b  0xa0147648
a01476b4:  82 10 3f ff  mov  -1, %g1
a01476b8:  81 c7 e0 08  ret
a01476bc:  81 e8 00 00  restore
