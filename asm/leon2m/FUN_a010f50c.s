# leon2m FUN_a010f50c 0xa010f50c-0xa010f65c (336 bytes)
a010f50c:  98 0a 20 ff  and  %o0, 0xff, %o4
a010f510:  80 a3 20 02  cmp  %o4, 2
a010f514:  08 80 00 03  bleu  0xa010f520
a010f518:  82 10 00 08  mov  %o0, %g1
a010f51c:  82 10 20 00  clr  %g1
a010f520:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010f524:  96 08 60 ff  and  %g1, 0xff, %o3
a010f528:  83 2a e0 02  sll  %o3, 2, %g1
a010f52c:  94 13 62 f0  or  %o5, 0x2f0, %o2
a010f530:  da 02 80 01  ld  [ %o2 + %g1 ], %o5
a010f534:  80 8a 60 ff  btst  0xff, %o1
a010f538:  c2 03 40 00  ld  [ %o5 ], %g1
a010f53c:  12 80 00 16  bne  0xa010f594
a010f540:  80 a3 20 02  cmp  %o4, 2
a010f544:  18 80 00 3a  bgu  0xa010f62c
a010f548:  96 08 7f fe  and  %g1, -2, %o3
a010f54c:  9b 2b 20 02  sll  %o4, 2, %o5
a010f550:  d8 02 80 0d  ld  [ %o2 + %o5 ], %o4
a010f554:  d6 23 00 00  st  %o3, [ %o4 ]
a010f558:  82 0a 20 ff  and  %o0, 0xff, %g1
a010f55c:  80 a0 60 02  cmp  %g1, 2
a010f560:  08 80 00 2e  bleu  0xa010f618
a010f564:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010f568:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010f56c:  94 12 22 e4  or  %o0, 0x2e4, %o2	! 0x19aee4
a010f570:  98 10 20 00  clr  %o4
a010f574:  83 2b 20 02  sll  %o4, 2, %g1
a010f578:  d2 02 80 01  ld  [ %o2 + %g1 ], %o1
a010f57c:  98 03 20 01  inc  %o4
a010f580:  d6 22 40 00  st  %o3, [ %o1 ]
a010f584:  80 a3 20 02  cmp  %o4, 2
a010f588:  08 bf ff fc  bleu  0xa010f578
a010f58c:  83 2b 20 02  sll  %o4, 2, %g1
a010f590:  30 80 00 31  b,a   0xa010f654
a010f594:  18 80 00 14  bgu  0xa010f5e4
a010f598:  96 08 7f ef  and  %g1, -17, %o3
a010f59c:  83 2b 20 02  sll  %o4, 2, %g1
a010f5a0:  d8 02 80 01  ld  [ %o2 + %g1 ], %o4
a010f5a4:  82 0a 20 ff  and  %o0, 0xff, %g1
a010f5a8:  d6 23 00 00  st  %o3, [ %o4 ]
a010f5ac:  80 a0 60 02  cmp  %g1, 2
a010f5b0:  08 80 00 1a  bleu  0xa010f618
a010f5b4:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010f5b8:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010f5bc:  94 12 22 e4  or  %o0, 0x2e4, %o2	! 0x19aee4
a010f5c0:  98 10 20 00  clr  %o4
a010f5c4:  93 2b 20 02  sll  %o4, 2, %o1
a010f5c8:  da 02 80 09  ld  [ %o2 + %o1 ], %o5
a010f5cc:  98 03 20 01  inc  %o4
a010f5d0:  d6 23 40 00  st  %o3, [ %o5 ]
a010f5d4:  80 a3 20 02  cmp  %o4, 2
a010f5d8:  08 bf ff fc  bleu  0xa010f5c8
a010f5dc:  93 2b 20 02  sll  %o4, 2, %o1
a010f5e0:  30 80 00 1d  b,a   0xa010f654
a010f5e4:  98 10 20 00  clr  %o4
a010f5e8:  93 2b 20 02  sll  %o4, 2, %o1
a010f5ec:  da 02 80 09  ld  [ %o2 + %o1 ], %o5
a010f5f0:  98 03 20 01  inc  %o4
a010f5f4:  d6 23 40 00  st  %o3, [ %o5 ]
a010f5f8:  80 a3 20 02  cmp  %o4, 2
a010f5fc:  28 bf ff fc  bleu,a   0xa010f5ec
a010f600:  93 2b 20 02  sll  %o4, 2, %o1
a010f604:  82 0a 20 ff  and  %o0, 0xff, %g1
a010f608:  80 a0 60 02  cmp  %g1, 2
a010f60c:  18 bf ff ec  bgu  0xa010f5bc
a010f610:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010f614:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010f618:  99 28 60 02  sll  %g1, 2, %o4
a010f61c:  90 13 62 e4  or  %o5, 0x2e4, %o0
a010f620:  d4 02 00 0c  ld  [ %o0 + %o4 ], %o2
a010f624:  d6 22 80 00  st  %o3, [ %o2 ]
a010f628:  30 80 00 0b  b,a   0xa010f654
a010f62c:  98 10 20 00  clr  %o4
a010f630:  83 2b 20 02  sll  %o4, 2, %g1
a010f634:  d2 02 80 01  ld  [ %o2 + %g1 ], %o1
a010f638:  98 03 20 01  inc  %o4
a010f63c:  d6 22 40 00  st  %o3, [ %o1 ]
a010f640:  80 a3 20 02  cmp  %o4, 2
a010f644:  28 bf ff fc  bleu,a   0xa010f634
a010f648:  83 2b 20 02  sll  %o4, 2, %g1
a010f64c:  10 bf ff c4  b  0xa010f55c
a010f650:  82 0a 20 ff  and  %o0, 0xff, %g1
a010f654:  81 c3 e0 08  retl
a010f658:  01 00 00 00  nop
