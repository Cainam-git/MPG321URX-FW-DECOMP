# leon2m FUN_a008e520 0xa008e520-0xa008e5b8 (152 bytes)
a008e520:  9d e3 bf 90  save  %sp, -112, %sp
a008e524:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a008e528:  a0 07 bf f0  add  %fp, -16, %l0
a008e52c:  13 00 04 01  sethi  %hi(0x100400), %o1
a008e530:  d4 10 62 86  lduh  [ %g1 + 0x286 ], %o2
a008e534:  92 12 61 10  or  %o1, 0x110, %o1
a008e538:  40 03 24 af  call  0xa01577f4
a008e53c:  90 10 00 10  mov  %l0, %o0
a008e540:  98 10 20 00  clr  %o4
a008e544:  82 10 20 00  clr  %g1
a008e548:  10 80 00 08  b  0xa008e568
a008e54c:  96 07 bf f8  add  %fp, -8, %o3
a008e550:  c2 2b 7f f8  stb  %g1, [ %o5 + -8 ]
a008e554:  98 03 20 01  inc  %o4
a008e558:  82 0b 20 ff  and  %o4, 0xff, %g1
a008e55c:  80 a0 60 04  cmp  %g1, 4
a008e560:  18 80 00 0d  bgu  0xa008e594
a008e564:  92 0e 20 ff  and  %i0, 0xff, %o1
a008e568:  9a 02 c0 01  add  %o3, %g1, %o5
a008e56c:  d0 0b 7f f8  ldub  [ %o5 + -8 ], %o0
a008e570:  80 a2 20 20  cmp  %o0, 0x20
a008e574:  12 bf ff f7  bne  0xa008e550
a008e578:  82 02 3f d1  add  %o0, -47, %g1
a008e57c:  98 03 20 01  inc  %o4
a008e580:  82 0b 20 ff  and  %o4, 0xff, %g1
a008e584:  80 a0 60 04  cmp  %g1, 4
a008e588:  08 bf ff f8  bleu  0xa008e568
a008e58c:  c0 2b 7f f8  clrb  [ %o5 + -8 ]
a008e590:  92 0e 20 ff  and  %i0, 0xff, %o1
a008e594:  94 0e 60 ff  and  %i1, 0xff, %o2
a008e598:  98 10 00 10  mov  %l0, %o4
a008e59c:  90 10 20 00  clr  %o0
a008e5a0:  96 10 20 05  mov  5, %o3
a008e5a4:  40 02 e1 54  call  0xa0146af4
a008e5a8:  9a 10 20 00  clr  %o5
a008e5ac:  01 00 00 00  nop
a008e5b0:  81 c7 e0 08  ret
a008e5b4:  81 e8 00 00  restore
