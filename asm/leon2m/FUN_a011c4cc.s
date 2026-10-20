# leon2m FUN_a011c4cc 0xa011c4cc-0xa011c6c8 (508 bytes)
a011c4cc:  9d e3 bf 98  save  %sp, -104, %sp
a011c4d0:  b8 0e a0 ff  and  %i2, 0xff, %i4
a011c4d4:  80 a7 20 00  cmp  %i4, 0
a011c4d8:  12 80 00 3e  bne  0xa011c5d0
a011c4dc:  35 33 c0 30  sethi  %hi(0xcf00c000), %i2
a011c4e0:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011c4e4:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a011c4e8:  98 10 63 cc  or  %g1, 0x3cc, %o4	! 0xcf00bfcc
a011c4ec:  b4 17 63 8c  or  %i5, 0x38c, %i2
a011c4f0:  b6 17 63 80  or  %i5, 0x380, %i3
a011c4f4:  9e 17 63 84  or  %i5, 0x384, %o7
a011c4f8:  9a 17 63 88  or  %i5, 0x388, %o5
a011c4fc:  ba 07 00 1c  add  %i4, %i4, %i5
a011c500:  39 2a 00 9e  sethi  %hi(0xa8027800), %i4
a011c504:  82 17 22 a8  or  %i4, 0x2a8, %g1	! 0xa8027aa8
a011c508:  f8 10 40 1d  lduh  [ %g1 + %i5 ], %i4
a011c50c:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a011c510:  b9 2f 20 02  sll  %i4, 2, %i4
a011c514:  b8 17 00 01  or  %i4, %g1, %i4
a011c518:  fa 07 00 00  ld  [ %i4 ], %i5
a011c51c:  82 0f 60 7f  and  %i5, 0x7f, %g1
a011c520:  c2 27 00 00  st  %g1, [ %i4 ]
a011c524:  fa 06 60 04  ld  [ %i1 + 4 ], %i5
a011c528:  b8 0f 60 f0  and  %i5, 0xf0, %i4
a011c52c:  f8 26 c0 00  st  %i4, [ %i3 ]
a011c530:  f8 16 40 00  lduh  [ %i1 ], %i4
a011c534:  82 10 20 9f  mov  0x9f, %g1
a011c538:  01 00 00 00  nop
a011c53c:  82 80 7f ff  addcc  %g1, -1, %g1
a011c540:  1c bf ff fe  bpos  0xa011c538
a011c544:  01 00 00 00  nop
a011c548:  f6 06 60 08  ld  [ %i1 + 8 ], %i3
a011c54c:  f6 23 c0 00  st  %i3, [ %o7 ]
a011c550:  c2 06 60 08  ld  [ %i1 + 8 ], %g1
a011c554:  bb 30 60 08  srl  %g1, 8, %i5
a011c558:  fa 23 40 00  st  %i5, [ %o5 ]
a011c55c:  f6 16 60 08  lduh  [ %i1 + 8 ], %i3
a011c560:  f6 23 00 00  st  %i3, [ %o4 ]
a011c564:  82 10 20 9f  mov  0x9f, %g1
a011c568:  01 00 00 00  nop
a011c56c:  82 80 7f ff  addcc  %g1, -1, %g1
a011c570:  1c bf ff fe  bpos  0xa011c568
a011c574:  80 a6 20 00  cmp  %i0, 0
a011c578:  12 80 00 1d  bne  0xa011c5ec
a011c57c:  9f 2f 20 10  sll  %i4, 0x10, %o7
a011c580:  b7 2f 20 10  sll  %i4, 0x10, %i3
a011c584:  b9 36 e0 10  srl  %i3, 0x10, %i4
a011c588:  80 a6 00 1c  cmp  %i0, %i4
a011c58c:  1a 80 00 4d  bcc  0xa011c6c0
a011c590:  b8 10 20 00  clr  %i4
a011c594:  f2 06 60 0c  ld  [ %i1 + 0xc ], %i1
a011c598:  83 2f 20 10  sll  %i4, 0x10, %g1
a011c59c:  bb 30 60 10  srl  %g1, 0x10, %i5
a011c5a0:  f0 0e 40 1d  ldub  [ %i1 + %i5 ], %i0
a011c5a4:  f0 26 80 00  st  %i0, [ %i2 ]
a011c5a8:  82 10 20 9f  mov  0x9f, %g1
a011c5ac:  01 00 00 00  nop
a011c5b0:  82 80 7f ff  addcc  %g1, -1, %g1
a011c5b4:  1c bf ff fe  bpos  0xa011c5ac
a011c5b8:  b0 07 20 01  add  %i4, 1, %i0
a011c5bc:  b9 2e 20 10  sll  %i0, 0x10, %i4
a011c5c0:  80 a6 c0 1c  cmp  %i3, %i4
a011c5c4:  18 bf ff f5  bgu  0xa011c598
a011c5c8:  b8 10 00 18  mov  %i0, %i4
a011c5cc:  30 80 00 3d  b,a   0xa011c6c0
a011c5d0:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011c5d4:  98 16 a3 cc  or  %i2, 0x3cc, %o4
a011c5d8:  b4 17 63 a0  or  %i5, 0x3a0, %i2
a011c5dc:  b6 17 63 94  or  %i5, 0x394, %i3
a011c5e0:  9e 17 63 98  or  %i5, 0x398, %o7
a011c5e4:  10 bf ff c6  b  0xa011c4fc
a011c5e8:  9a 17 63 9c  or  %i5, 0x39c, %o5
a011c5ec:  80 a3 e0 00  cmp  %o7, 0
a011c5f0:  02 80 00 34  be  0xa011c6c0
a011c5f4:  b0 10 20 00  clr  %i0
a011c5f8:  f2 06 60 0c  ld  [ %i1 + 0xc ], %i1
a011c5fc:  b7 2e 20 10  sll  %i0, 0x10, %i3
a011c600:  bb 36 e0 10  srl  %i3, 0x10, %i5
a011c604:  f6 0e 40 1d  ldub  [ %i1 + %i5 ], %i3
a011c608:  80 a0 00 1b  cmp  %g0, %i3
a011c60c:  b8 60 3f ff  subx  %g0, -1, %i4
a011c610:  82 1e e0 ff  xor  %i3, 0xff, %g1
a011c614:  80 a0 00 01  cmp  %g0, %g1
a011c618:  ba 60 3f ff  subx  %g0, -1, %i5
a011c61c:  80 97 00 1d  orcc  %i4, %i5, %g0
a011c620:  02 80 00 20  be  0xa011c6a0
a011c624:  ba 06 20 01  add  %i0, 1, %i5
a011c628:  b9 2f 60 10  sll  %i5, 0x10, %i4
a011c62c:  b1 37 20 10  srl  %i4, 0x10, %i0
a011c630:  f8 0e 40 18  ldub  [ %i1 + %i0 ], %i4
a011c634:  b0 10 00 1d  mov  %i5, %i0
a011c638:  f6 26 80 00  st  %i3, [ %i2 ]
a011c63c:  82 10 20 9f  mov  0x9f, %g1
a011c640:  01 00 00 00  nop
a011c644:  82 80 7f ff  addcc  %g1, -1, %g1
a011c648:  1c bf ff fe  bpos  0xa011c640
a011c64c:  01 00 00 00  nop
a011c650:  b8 07 3f ff  add  %i4, -1, %i4
a011c654:  80 8f 20 ff  btst  0xff, %i4
a011c658:  12 bf ff f8  bne  0xa011c638
a011c65c:  01 00 00 00  nop
a011c660:  b6 06 20 01  add  %i0, 1, %i3
a011c664:  83 2e e0 10  sll  %i3, 0x10, %g1
a011c668:  80 a3 c0 01  cmp  %o7, %g1
a011c66c:  08 80 00 15  bleu  0xa011c6c0
a011c670:  b0 10 00 1b  mov  %i3, %i0
a011c674:  b7 2e 20 10  sll  %i0, 0x10, %i3
a011c678:  bb 36 e0 10  srl  %i3, 0x10, %i5
a011c67c:  f6 0e 40 1d  ldub  [ %i1 + %i5 ], %i3
a011c680:  80 a0 00 1b  cmp  %g0, %i3
a011c684:  b8 60 3f ff  subx  %g0, -1, %i4
a011c688:  82 1e e0 ff  xor  %i3, 0xff, %g1
a011c68c:  80 a0 00 01  cmp  %g0, %g1
a011c690:  ba 60 3f ff  subx  %g0, -1, %i5
a011c694:  80 97 00 1d  orcc  %i4, %i5, %g0
a011c698:  12 bf ff e4  bne  0xa011c628
a011c69c:  ba 06 20 01  add  %i0, 1, %i5
a011c6a0:  f6 26 80 00  st  %i3, [ %i2 ]
a011c6a4:  82 10 20 9f  mov  0x9f, %g1
a011c6a8:  01 00 00 00  nop
a011c6ac:  82 80 7f ff  addcc  %g1, -1, %g1
a011c6b0:  1c bf ff fe  bpos  0xa011c6a8
a011c6b4:  b6 06 20 01  add  %i0, 1, %i3
a011c6b8:  10 bf ff ec  b  0xa011c668
a011c6bc:  83 2e e0 10  sll  %i3, 0x10, %g1
a011c6c0:  81 c7 e0 08  ret
a011c6c4:  81 e8 00 00  restore
