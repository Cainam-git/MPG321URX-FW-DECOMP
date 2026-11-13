# leon2m FUN_a012e550 0xa012e550-0xa012e6c0 (368 bytes)
a012e550:  9d e3 bf 98  save  %sp, -104, %sp
a012e554:  b1 2e 20 10  sll  %i0, 0x10, %i0
a012e558:  b1 36 20 10  srl  %i0, 0x10, %i0
a012e55c:  80 8e 25 08  btst  0x508, %i0
a012e560:  9e 10 20 00  clr  %o7
a012e564:  12 80 00 2d  bne  0xa012e618
a012e568:  94 10 20 00  clr  %o2
a012e56c:  94 10 3f ff  mov  -1, %o2
a012e570:  91 2e 60 10  sll  %i1, 0x10, %o0
a012e574:  83 32 20 10  srl  %o0, 0x10, %g1
a012e578:  9a 10 00 0a  mov  %o2, %o5
a012e57c:  80 88 60 92  btst  0x92, %g1
a012e580:  12 80 00 14  bne  0xa012e5d0
a012e584:  90 10 20 00  clr  %o0
a012e588:  90 10 3f ff  mov  -1, %o0
a012e58c:  92 0b 60 ff  and  %o5, 0xff, %o1
a012e590:  96 1a 60 ff  xor  %o1, 0xff, %o3
a012e594:  80 a0 00 0b  cmp  %g0, %o3
a012e598:  96 0a 20 ff  and  %o0, 0xff, %o3
a012e59c:  98 40 20 00  addx  %g0, 0, %o4
a012e5a0:  94 1a e0 ff  xor  %o3, 0xff, %o2
a012e5a4:  80 a0 00 0a  cmp  %g0, %o2
a012e5a8:  9a 40 20 00  addx  %g0, 0, %o5
a012e5ac:  80 8b 00 0d  btst  %o4, %o5
a012e5b0:  32 80 00 02  bne,a   0xa012e5b8
a012e5b4:  9e 10 20 01  mov  1, %o7
a012e5b8:  b0 0b e0 ff  and  %o7, 0xff, %i0
a012e5bc:  80 a6 20 01  cmp  %i0, 1
a012e5c0:  12 80 00 3e  bne  0xa012e6b8
a012e5c4:  9b 2a 60 03  sll  %o1, 3, %o5
a012e5c8:  10 80 00 25  b  0xa012e65c
a012e5cc:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a012e5d0:  80 a0 60 01  cmp  %g1, 1
a012e5d4:  02 bf ff ee  be  0xa012e58c
a012e5d8:  94 10 20 00  clr  %o2
a012e5dc:  b2 10 00 01  mov  %g1, %i1
a012e5e0:  96 10 20 00  clr  %o3
a012e5e4:  92 10 20 92  mov  0x92, %o1
a012e5e8:  b1 3a 40 0b  sra  %o1, %o3, %i0
a012e5ec:  94 02 a0 01  inc  %o2
a012e5f0:  96 0a a0 ff  and  %o2, 0xff, %o3
a012e5f4:  80 8e 20 01  btst  1, %i0
a012e5f8:  02 80 00 03  be  0xa012e604
a012e5fc:  99 3e 40 0b  sra  %i1, %o3, %o4
a012e600:  90 02 20 01  inc  %o0
a012e604:  80 a3 20 01  cmp  %o4, 1
a012e608:  12 bf ff f9  bne  0xa012e5ec
a012e60c:  b1 3a 40 0b  sra  %o1, %o3, %i0
a012e610:  10 bf ff e0  b  0xa012e590
a012e614:  92 0b 60 ff  and  %o5, 0xff, %o1
a012e618:  80 a6 20 01  cmp  %i0, 1
a012e61c:  02 bf ff d5  be  0xa012e570
a012e620:  96 10 20 00  clr  %o3
a012e624:  98 10 20 00  clr  %o4
a012e628:  92 10 25 08  mov  0x508, %o1
a012e62c:  83 3a 40 0c  sra  %o1, %o4, %g1
a012e630:  96 02 e0 01  inc  %o3
a012e634:  98 0a e0 ff  and  %o3, 0xff, %o4
a012e638:  80 88 60 01  btst  1, %g1
a012e63c:  02 80 00 03  be  0xa012e648
a012e640:  9b 3e 00 0c  sra  %i0, %o4, %o5
a012e644:  94 02 a0 01  inc  %o2
a012e648:  80 a3 60 01  cmp  %o5, 1
a012e64c:  12 bf ff f9  bne  0xa012e630
a012e650:  83 3a 40 0c  sra  %o1, %o4, %g1
a012e654:  10 bf ff c8  b  0xa012e574
a012e658:  91 2e 60 10  sll  %i1, 0x10, %o0
a012e65c:  98 12 21 a0  or  %o0, 0x1a0, %o4
a012e660:  94 02 c0 0b  add  %o3, %o3, %o2
a012e664:  b2 03 40 09  add  %o5, %o1, %i1
a012e668:  82 02 80 0b  add  %o2, %o3, %g1
a012e66c:  d2 03 20 34  ld  [ %o4 + 0x34 ], %o1
a012e670:  de 0b 20 37  ldub  [ %o4 + 0x37 ], %o7
a012e674:  97 32 60 08  srl  %o1, 8, %o3
a012e678:  9a 06 40 01  add  %i1, %g1, %o5
a012e67c:  80 a3 e0 01  cmp  %o7, 1
a012e680:  08 80 00 03  bleu  0xa012e68c
a012e684:  92 10 21 20  mov  0x120, %o1
a012e688:  92 10 22 40  mov  0x240, %o1
a012e68c:  98 0a 63 60  and  %o1, 0x360, %o4
a012e690:  82 03 20 10  add  %o4, 0x10, %g1
a012e694:  b2 02 c0 01  add  %o3, %g1, %i1
a012e698:  92 06 40 0d  add  %i1, %o5, %o1
a012e69c:  97 2a 60 10  sll  %o1, 0x10, %o3
a012e6a0:  9e 12 21 a0  or  %o0, 0x1a0, %o7
a012e6a4:  93 32 e0 10  srl  %o3, 0x10, %o1
a012e6a8:  d0 0b e0 34  ldub  [ %o7 + 0x34 ], %o0
a012e6ac:  96 10 00 1a  mov  %i2, %o3
a012e6b0:  40 00 47 2c  call  0xa0140360
a012e6b4:  94 10 20 03  mov  3, %o2
a012e6b8:  81 c7 e0 08  ret
a012e6bc:  81 e8 00 00  restore
