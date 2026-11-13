# leon2m FUN_a011b4f0 0xa011b4f0-0xa011b648 (344 bytes)
a011b4f0:  92 0a 60 ff  and  %o1, 0xff, %o1
a011b4f4:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a011b4f8:  82 12 e2 a8  or  %o3, 0x2a8, %g1	! 0xa8027aa8
a011b4fc:  94 02 40 09  add  %o1, %o1, %o2
a011b500:  da 10 40 0a  lduh  [ %g1 + %o2 ], %o5
a011b504:  97 2b 60 02  sll  %o5, 2, %o3
a011b508:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011b50c:  9a 12 c0 0c  or  %o3, %o4, %o5
a011b510:  d4 03 40 00  ld  [ %o5 ], %o2
a011b514:  82 0a a0 7f  and  %o2, 0x7f, %g1
a011b518:  c2 23 40 00  st  %g1, [ %o5 ]
a011b51c:  80 a2 60 00  cmp  %o1, 0
a011b520:  12 80 00 37  bne  0xa011b5fc
a011b524:  d4 12 00 00  lduh  [ %o0 ], %o2
a011b528:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011b52c:  9a 10 20 d0  mov  0xd0, %o5
a011b530:  82 13 23 80  or  %o4, 0x380, %g1
a011b534:  da 20 40 00  st  %o5, [ %g1 ]
a011b538:  82 10 20 9f  mov  0x9f, %g1
a011b53c:  01 00 00 00  nop
a011b540:  82 80 7f ff  addcc  %g1, -1, %g1
a011b544:  1c bf ff fe  bpos  0xa011b53c
a011b548:  80 a2 60 00  cmp  %o1, 0
a011b54c:  da 12 20 02  lduh  [ %o0 + 2 ], %o5
a011b550:  97 2b 60 10  sll  %o5, 0x10, %o3
a011b554:  12 80 00 2e  bne  0xa011b60c
a011b558:  9b 32 e0 10  srl  %o3, 0x10, %o5
a011b55c:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011b560:  82 13 23 84  or  %o4, 0x384, %g1	! 0xcf011784
a011b564:  9a 0b 60 ff  and  %o5, 0xff, %o5
a011b568:  da 20 40 00  st  %o5, [ %g1 ]
a011b56c:  83 32 e0 18  srl  %o3, 0x18, %g1
a011b570:  98 13 23 88  or  %o4, 0x388, %o4
a011b574:  c2 23 00 00  st  %g1, [ %o4 ]
a011b578:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a011b57c:  96 10 63 cc  or  %g1, 0x3cc, %o3	! 0xcf00bfcc
a011b580:  c0 22 c0 00  clr  [ %o3 ]
a011b584:  82 10 20 9f  mov  0x9f, %g1
a011b588:  01 00 00 00  nop
a011b58c:  82 80 7f ff  addcc  %g1, -1, %g1
a011b590:  1c bf ff fe  bpos  0xa011b588
a011b594:  99 2a a0 10  sll  %o2, 0x10, %o4
a011b598:  80 a3 20 00  cmp  %o4, 0
a011b59c:  02 80 00 29  be  0xa011b640
a011b5a0:  9a 10 20 00  clr  %o5
a011b5a4:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011b5a8:  d0 02 20 04  ld  [ %o0 + 4 ], %o0
a011b5ac:  94 10 63 a0  or  %g1, 0x3a0, %o2
a011b5b0:  96 10 63 8c  or  %g1, 0x38c, %o3
a011b5b4:  83 2b 60 10  sll  %o5, 0x10, %g1
a011b5b8:  83 30 60 10  srl  %g1, 0x10, %g1
a011b5bc:  80 a2 60 00  cmp  %o1, 0
a011b5c0:  12 80 00 1c  bne  0xa011b630
a011b5c4:  c2 0a 00 01  ldub  [ %o0 + %g1 ], %g1
a011b5c8:  82 08 60 ff  and  %g1, 0xff, %g1
a011b5cc:  c2 22 c0 00  st  %g1, [ %o3 ]
a011b5d0:  82 10 20 9f  mov  0x9f, %g1
a011b5d4:  01 00 00 00  nop
a011b5d8:  82 80 7f ff  addcc  %g1, -1, %g1
a011b5dc:  1c bf ff fe  bpos  0xa011b5d4
a011b5e0:  01 00 00 00  nop
a011b5e4:  9a 03 60 01  inc  %o5
a011b5e8:  83 2b 60 10  sll  %o5, 0x10, %g1
a011b5ec:  80 a3 00 01  cmp  %o4, %g1
a011b5f0:  18 bf ff f3  bgu  0xa011b5bc
a011b5f4:  83 30 60 10  srl  %g1, 0x10, %g1
a011b5f8:  30 80 00 12  b,a   0xa011b640
a011b5fc:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011b600:  9a 10 20 d0  mov  0xd0, %o5
a011b604:  10 bf ff cc  b  0xa011b534
a011b608:  82 10 63 94  or  %g1, 0x394, %g1
a011b60c:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011b610:  82 13 23 98  or  %o4, 0x398, %g1	! 0xcf011798
a011b614:  9a 0b 60 ff  and  %o5, 0xff, %o5
a011b618:  da 20 40 00  st  %o5, [ %g1 ]
a011b61c:  83 32 e0 18  srl  %o3, 0x18, %g1
a011b620:  98 13 23 9c  or  %o4, 0x39c, %o4
a011b624:  c2 23 00 00  st  %g1, [ %o4 ]
a011b628:  10 bf ff d5  b  0xa011b57c
a011b62c:  03 33 c0 30  sethi  %hi(0xcf00c000), %g1
a011b630:  82 08 60 ff  and  %g1, 0xff, %g1
a011b634:  c2 22 80 00  st  %g1, [ %o2 ]
a011b638:  10 bf ff e7  b  0xa011b5d4
a011b63c:  82 10 20 9f  mov  0x9f, %g1
a011b640:  81 c3 e0 08  retl
a011b644:  01 00 00 00  nop
