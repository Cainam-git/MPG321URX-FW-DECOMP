# leon2m FUN_a008a568 0xa008a568-0xa008a778 (528 bytes)
a008a568:  9d e3 bf 80  save  %sp, -128, %sp
a008a56c:  90 06 3f ff  add  %i0, -1, %o0
a008a570:  82 0a 20 ff  and  %o0, 0xff, %g1
a008a574:  80 a0 60 0b  cmp  %g1, 0xb
a008a578:  08 80 00 5a  bleu  0xa008a6e0
a008a57c:  92 06 3f f1  add  %i0, -15, %o1
a008a580:  94 0a 60 ff  and  %o1, 0xff, %o2
a008a584:  80 a2 a0 01  cmp  %o2, 1
a008a588:  18 80 00 2c  bgu  0xa008a638
a008a58c:  9e 0e 20 ff  and  %i0, 0xff, %o7
a008a590:  92 0e 20 ff  and  %i0, 0xff, %o1
a008a594:  94 02 40 09  add  %o1, %o1, %o2
a008a598:  11 00 04 00  sethi  %hi(0x100000), %o0
a008a59c:  b0 02 80 09  add  %o2, %o1, %i0
a008a5a0:  82 12 22 42  or  %o0, 0x242, %g1
a008a5a4:  9e 06 00 01  add  %i0, %g1, %o7
a008a5a8:  d8 08 40 18  ldub  [ %g1 + %i0 ], %o4
a008a5ac:  9b 2e 60 10  sll  %i1, 0x10, %o5
a008a5b0:  17 00 04 01  sethi  %hi(0x100400), %o3
a008a5b4:  e0 0b e0 02  ldub  [ %o7 + 2 ], %l0
a008a5b8:  b2 03 00 10  add  %o4, %l0, %i1
a008a5bc:  92 12 e0 78  or  %o3, 0x78, %o1
a008a5c0:  95 33 60 10  srl  %o5, 0x10, %o2
a008a5c4:  f0 0b e0 01  ldub  [ %o7 + 1 ], %i0
a008a5c8:  40 03 34 8b  call  0xa01577f4
a008a5cc:  90 07 bf e7  add  %fp, -25, %o0
a008a5d0:  98 10 20 00  clr  %o4
a008a5d4:  9a 10 20 00  clr  %o5
a008a5d8:  10 80 00 08  b  0xa008a5f8
a008a5dc:  96 07 bf e7  add  %fp, -25, %o3
a008a5e0:  c2 2b 40 0b  stb  %g1, [ %o5 + %o3 ]
a008a5e4:  98 03 20 01  inc  %o4
a008a5e8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008a5ec:  80 a3 60 00  cmp  %o5, 0
a008a5f0:  12 80 00 0d  bne  0xa008a624
a008a5f4:  92 0e 60 ff  and  %i1, 0xff, %o1
a008a5f8:  de 0b 40 0b  ldub  [ %o5 + %o3 ], %o7
a008a5fc:  80 a3 e0 20  cmp  %o7, 0x20
a008a600:  12 bf ff f8  bne  0xa008a5e0
a008a604:  82 03 ff d1  add  %o7, -47, %g1
a008a608:  c0 2b 40 0b  clrb  [ %o5 + %o3 ]
a008a60c:  98 03 20 01  inc  %o4
a008a610:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008a614:  80 a3 60 00  cmp  %o5, 0
a008a618:  22 bf ff f9  be,a   0xa008a5fc
a008a61c:  de 0b 40 0b  ldub  [ %o5 + %o3 ], %o7
a008a620:  92 0e 60 ff  and  %i1, 0xff, %o1
a008a624:  94 0e 20 ff  and  %i0, 0xff, %o2
a008a628:  90 10 20 00  clr  %o0
a008a62c:  96 10 20 01  mov  1, %o3
a008a630:  10 80 00 4d  b  0xa008a764
a008a634:  98 07 bf e7  add  %fp, -25, %o4
a008a638:  92 03 c0 0f  add  %o7, %o7, %o1
a008a63c:  15 00 04 00  sethi  %hi(0x100000), %o2
a008a640:  a0 02 40 0f  add  %o1, %o7, %l0
a008a644:  82 12 a2 42  or  %o2, 0x242, %g1
a008a648:  98 04 00 01  add  %l0, %g1, %o4
a008a64c:  d0 08 40 10  ldub  [ %g1 + %l0 ], %o0
a008a650:  f0 0b 20 02  ldub  [ %o4 + 2 ], %i0
a008a654:  9b 2e 60 10  sll  %i1, 0x10, %o5
a008a658:  17 00 04 01  sethi  %hi(0x100400), %o3
a008a65c:  b2 02 00 18  add  %o0, %i0, %i1
a008a660:  a0 07 bf e8  add  %fp, -24, %l0
a008a664:  f0 0b 20 01  ldub  [ %o4 + 1 ], %i0
a008a668:  92 12 e0 80  or  %o3, 0x80, %o1
a008a66c:  95 33 60 10  srl  %o5, 0x10, %o2
a008a670:  40 03 34 61  call  0xa01577f4
a008a674:  90 10 00 10  mov  %l0, %o0
a008a678:  98 10 20 00  clr  %o4
a008a67c:  96 07 bf f8  add  %fp, -8, %o3
a008a680:  10 80 00 08  b  0xa008a6a0
a008a684:  82 10 20 00  clr  %g1
a008a688:  c2 2b 7f f0  stb  %g1, [ %o5 + -16 ]
a008a68c:  98 03 20 01  inc  %o4
a008a690:  82 0b 20 ff  and  %o4, 0xff, %g1
a008a694:  80 a0 60 02  cmp  %g1, 2
a008a698:  18 80 00 0d  bgu  0xa008a6cc
a008a69c:  92 0e 60 ff  and  %i1, 0xff, %o1
a008a6a0:  9a 02 c0 01  add  %o3, %g1, %o5
a008a6a4:  d0 0b 7f f0  ldub  [ %o5 + -16 ], %o0
a008a6a8:  80 a2 20 20  cmp  %o0, 0x20
a008a6ac:  12 bf ff f7  bne  0xa008a688
a008a6b0:  82 02 3f d1  add  %o0, -47, %g1
a008a6b4:  98 03 20 01  inc  %o4
a008a6b8:  82 0b 20 ff  and  %o4, 0xff, %g1
a008a6bc:  80 a0 60 02  cmp  %g1, 2
a008a6c0:  08 bf ff f8  bleu  0xa008a6a0
a008a6c4:  c0 2b 7f f0  clrb  [ %o5 + -16 ]
a008a6c8:  92 0e 60 ff  and  %i1, 0xff, %o1
a008a6cc:  94 0e 20 ff  and  %i0, 0xff, %o2
a008a6d0:  98 10 00 10  mov  %l0, %o4
a008a6d4:  90 10 20 00  clr  %o0
a008a6d8:  10 80 00 23  b  0xa008a764
a008a6dc:  96 10 20 03  mov  3, %o3
a008a6e0:  82 0e 20 ff  and  %i0, 0xff, %g1
a008a6e4:  b0 00 40 01  add  %g1, %g1, %i0
a008a6e8:  21 00 04 00  sethi  %hi(0x100000), %l0
a008a6ec:  9a 06 00 01  add  %i0, %g1, %o5
a008a6f0:  9e 14 22 42  or  %l0, 0x242, %o7
a008a6f4:  96 03 40 0f  add  %o5, %o7, %o3
a008a6f8:  d8 0b c0 0d  ldub  [ %o7 + %o5 ], %o4
a008a6fc:  95 2e 60 10  sll  %i1, 0x10, %o2
a008a700:  a0 07 bf f0  add  %fp, -16, %l0
a008a704:  13 00 04 01  sethi  %hi(0x100400), %o1
a008a708:  b2 03 20 01  add  %o4, 1, %i1
a008a70c:  f0 0a e0 01  ldub  [ %o3 + 1 ], %i0
a008a710:  92 12 60 80  or  %o1, 0x80, %o1
a008a714:  95 32 a0 10  srl  %o2, 0x10, %o2
a008a718:  40 03 34 37  call  0xa01577f4
a008a71c:  90 10 00 10  mov  %l0, %o0
a008a720:  98 10 20 00  clr  %o4
a008a724:  82 10 20 00  clr  %g1
a008a728:  10 80 00 08  b  0xa008a748
a008a72c:  96 07 bf f8  add  %fp, -8, %o3
a008a730:  c2 2b 7f f8  stb  %g1, [ %o5 + -8 ]
a008a734:  98 03 20 01  inc  %o4
a008a738:  82 0b 20 ff  and  %o4, 0xff, %g1
a008a73c:  80 a0 60 02  cmp  %g1, 2
a008a740:  18 bf ff e3  bgu  0xa008a6cc
a008a744:  92 0e 60 ff  and  %i1, 0xff, %o1
a008a748:  9a 02 c0 01  add  %o3, %g1, %o5
a008a74c:  d0 0b 7f f8  ldub  [ %o5 + -8 ], %o0
a008a750:  80 a2 20 20  cmp  %o0, 0x20
a008a754:  12 bf ff f7  bne  0xa008a730
a008a758:  82 02 3f d1  add  %o0, -47, %g1
a008a75c:  10 bf ff f6  b  0xa008a734
a008a760:  c0 2b 7f f8  clrb  [ %o5 + -8 ]
a008a764:  40 02 f0 e4  call  0xa0146af4
a008a768:  9a 10 20 00  clr  %o5
a008a76c:  01 00 00 00  nop
a008a770:  81 c7 e0 08  ret
a008a774:  81 e8 00 00  restore
