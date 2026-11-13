# leon2m FUN_a010b530 0xa010b530-0xa010b5dc (172 bytes)
a010b530:  90 0a 20 ff  and  %o0, 0xff, %o0
a010b534:  80 a2 20 02  cmp  %o0, 2
a010b538:  08 80 00 15  bleu  0xa010b58c
a010b53c:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010b540:  93 2a 60 02  sll  %o1, 2, %o1
a010b544:  96 10 62 d8  or  %g1, 0x2d8, %o3
a010b548:  98 10 20 00  clr  %o4
a010b54c:  83 2b 20 02  sll  %o4, 2, %g1
a010b550:  da 02 c0 01  ld  [ %o3 + %g1 ], %o5
a010b554:  98 03 20 01  inc  %o4
a010b558:  d4 23 40 09  st  %o2, [ %o5 + %o1 ]
a010b55c:  80 a3 20 02  cmp  %o4, 2
a010b560:  28 bf ff fc  bleu,a   0xa010b550
a010b564:  83 2b 20 02  sll  %o4, 2, %g1
a010b568:  80 a2 20 02  cmp  %o0, 2
a010b56c:  38 80 00 11  bgu,a   0xa010b5b0
a010b570:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010b574:  97 2a 20 02  sll  %o0, 2, %o3
a010b578:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010b57c:  90 13 62 cc  or  %o5, 0x2cc, %o0	! 0x19aecc
a010b580:  d8 02 00 0b  ld  [ %o0 + %o3 ], %o4
a010b584:  d4 23 00 09  st  %o2, [ %o4 + %o1 ]
a010b588:  30 80 00 13  b,a   0xa010b5d4
a010b58c:  97 2a 20 02  sll  %o0, 2, %o3
a010b590:  9a 10 62 d8  or  %g1, 0x2d8, %o5
a010b594:  d8 03 40 0b  ld  [ %o5 + %o3 ], %o4
a010b598:  93 2a 60 02  sll  %o1, 2, %o1
a010b59c:  d4 23 00 09  st  %o2, [ %o4 + %o1 ]
a010b5a0:  80 a2 20 02  cmp  %o0, 2
a010b5a4:  08 bf ff f5  bleu  0xa010b578
a010b5a8:  97 2a 20 02  sll  %o0, 2, %o3
a010b5ac:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010b5b0:  96 12 22 cc  or  %o0, 0x2cc, %o3	! 0x19aecc
a010b5b4:  98 10 20 00  clr  %o4
a010b5b8:  83 2b 20 02  sll  %o4, 2, %g1
a010b5bc:  da 02 c0 01  ld  [ %o3 + %g1 ], %o5
a010b5c0:  98 03 20 01  inc  %o4
a010b5c4:  d4 23 40 09  st  %o2, [ %o5 + %o1 ]
a010b5c8:  80 a3 20 02  cmp  %o4, 2
a010b5cc:  08 bf ff fc  bleu  0xa010b5bc
a010b5d0:  83 2b 20 02  sll  %o4, 2, %g1
a010b5d4:  81 c3 e0 08  retl
a010b5d8:  01 00 00 00  nop
