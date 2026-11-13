# leon2m FUN_a010c54c 0xa010c54c-0xa010c61c (208 bytes)
a010c54c:  90 0a 20 ff  and  %o0, 0xff, %o0
a010c550:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010c554:  80 a2 20 01  cmp  %o0, 1
a010c558:  02 80 00 2c  be  0xa010c608
a010c55c:  82 10 63 04  or  %g1, 0x304, %g1
a010c560:  d2 28 60 26  stb  %o1, [ %g1 + 0x26 ]
a010c564:  80 a2 20 01  cmp  %o0, 1
a010c568:  08 80 00 1a  bleu  0xa010c5d0
a010c56c:  92 0a 60 ff  and  %o1, 0xff, %o1
a010c570:  19 00 06 6b  sethi  %hi(0x19ac00), %o4
a010c574:  96 13 22 c4  or  %o4, 0x2c4, %o3	! 0x19aec4
a010c578:  98 10 20 00  clr  %o4
a010c57c:  83 2b 20 02  sll  %o4, 2, %g1
a010c580:  da 02 c0 01  ld  [ %o3 + %g1 ], %o5
a010c584:  98 03 20 01  inc  %o4
a010c588:  d2 23 60 14  st  %o1, [ %o5 + 0x14 ]
a010c58c:  80 a3 20 01  cmp  %o4, 1
a010c590:  08 bf ff fc  bleu  0xa010c580
a010c594:  83 2b 20 02  sll  %o4, 2, %g1
a010c598:  80 a2 20 01  cmp  %o0, 1
a010c59c:  08 80 00 16  bleu  0xa010c5f4
a010c5a0:  99 2a 20 02  sll  %o0, 2, %o4
a010c5a4:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010c5a8:  96 12 22 bc  or  %o0, 0x2bc, %o3	! 0x19aebc
a010c5ac:  98 10 20 00  clr  %o4
a010c5b0:  83 2b 20 02  sll  %o4, 2, %g1
a010c5b4:  da 02 c0 01  ld  [ %o3 + %g1 ], %o5
a010c5b8:  98 03 20 01  inc  %o4
a010c5bc:  d2 23 60 14  st  %o1, [ %o5 + 0x14 ]
a010c5c0:  80 a3 20 01  cmp  %o4, 1
a010c5c4:  08 bf ff fc  bleu  0xa010c5b4
a010c5c8:  83 2b 20 02  sll  %o4, 2, %g1
a010c5cc:  30 80 00 12  b,a   0xa010c614
a010c5d0:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010c5d4:  99 2a 20 02  sll  %o0, 2, %o4
a010c5d8:  9a 10 62 c4  or  %g1, 0x2c4, %o5
a010c5dc:  d6 03 40 0c  ld  [ %o5 + %o4 ], %o3
a010c5e0:  d2 22 e0 14  st  %o1, [ %o3 + 0x14 ]
a010c5e4:  80 a2 20 01  cmp  %o0, 1
a010c5e8:  38 bf ff f0  bgu,a   0xa010c5a8
a010c5ec:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010c5f0:  99 2a 20 02  sll  %o0, 2, %o4
a010c5f4:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010c5f8:  90 13 62 bc  or  %o5, 0x2bc, %o0	! 0x19aebc
a010c5fc:  d6 02 00 0c  ld  [ %o0 + %o4 ], %o3
a010c600:  d2 22 e0 14  st  %o1, [ %o3 + 0x14 ]
a010c604:  30 80 00 04  b,a   0xa010c614
a010c608:  17 2a 00 b6  sethi  %hi(0xa802d800), %o3
a010c60c:  10 bf ff d5  b  0xa010c560
a010c610:  82 12 e0 04  or  %o3, 4, %g1	! 0xa802d804
a010c614:  81 c3 e0 08  retl
a010c618:  01 00 00 00  nop
