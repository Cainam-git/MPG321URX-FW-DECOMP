# leon2m FUN_a008e5b8 0xa008e5b8-0xa008e650 (152 bytes)
a008e5b8:  9d e3 bf 90  save  %sp, -112, %sp
a008e5bc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a008e5c0:  a0 07 bf f0  add  %fp, -16, %l0
a008e5c4:  13 00 04 01  sethi  %hi(0x100400), %o1
a008e5c8:  d4 08 62 85  ldub  [ %g1 + 0x285 ], %o2
a008e5cc:  92 12 61 08  or  %o1, 0x108, %o1
a008e5d0:  40 03 24 89  call  0xa01577f4
a008e5d4:  90 10 00 10  mov  %l0, %o0
a008e5d8:  98 10 20 00  clr  %o4
a008e5dc:  82 10 20 00  clr  %g1
a008e5e0:  10 80 00 08  b  0xa008e600
a008e5e4:  96 07 bf f8  add  %fp, -8, %o3
a008e5e8:  c2 2b 7f f8  stb  %g1, [ %o5 + -8 ]
a008e5ec:  98 03 20 01  inc  %o4
a008e5f0:  82 0b 20 ff  and  %o4, 0xff, %g1
a008e5f4:  80 a0 60 01  cmp  %g1, 1
a008e5f8:  18 80 00 0d  bgu  0xa008e62c
a008e5fc:  92 0e 20 ff  and  %i0, 0xff, %o1
a008e600:  9a 02 c0 01  add  %o3, %g1, %o5
a008e604:  d0 0b 7f f8  ldub  [ %o5 + -8 ], %o0
a008e608:  80 a2 20 20  cmp  %o0, 0x20
a008e60c:  12 bf ff f7  bne  0xa008e5e8
a008e610:  82 02 3f d1  add  %o0, -47, %g1
a008e614:  98 03 20 01  inc  %o4
a008e618:  82 0b 20 ff  and  %o4, 0xff, %g1
a008e61c:  80 a0 60 01  cmp  %g1, 1
a008e620:  08 bf ff f8  bleu  0xa008e600
a008e624:  c0 2b 7f f8  clrb  [ %o5 + -8 ]
a008e628:  92 0e 20 ff  and  %i0, 0xff, %o1
a008e62c:  94 0e 60 ff  and  %i1, 0xff, %o2
a008e630:  98 10 00 10  mov  %l0, %o4
a008e634:  90 10 20 00  clr  %o0
a008e638:  96 10 20 02  mov  2, %o3
a008e63c:  40 02 e1 2e  call  0xa0146af4
a008e640:  9a 10 20 00  clr  %o5
a008e644:  01 00 00 00  nop
a008e648:  81 c7 e0 08  ret
a008e64c:  81 e8 00 00  restore
