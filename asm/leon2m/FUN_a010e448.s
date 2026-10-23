# leon2m FUN_a010e448 0xa010e448-0xa010e624 (476 bytes)
a010e448:  80 8a 60 ff  btst  0xff, %o1
a010e44c:  12 80 00 27  bne  0xa010e4e8
a010e450:  96 0a 20 ff  and  %o0, 0xff, %o3
a010e454:  80 a2 e0 01  cmp  %o3, 1
a010e458:  18 80 00 61  bgu  0xa010e5dc
a010e45c:  82 10 00 08  mov  %o0, %g1
a010e460:  98 08 60 ff  and  %g1, 0xff, %o4
a010e464:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010e468:  93 2b 20 02  sll  %o4, 2, %o1
a010e46c:  94 13 62 c4  or  %o5, 0x2c4, %o2
a010e470:  da 02 80 09  ld  [ %o2 + %o1 ], %o5
a010e474:  d8 03 60 24  ld  [ %o5 + 0x24 ], %o4
a010e478:  03 00 40 00  sethi  %hi(0x1000000), %g1
a010e47c:  80 a2 e0 01  cmp  %o3, 1
a010e480:  08 80 00 62  bleu  0xa010e608
a010e484:  92 2b 00 01  andn  %o4, %g1, %o1
a010e488:  96 10 00 0a  mov  %o2, %o3
a010e48c:  98 10 20 00  clr  %o4
a010e490:  83 2b 20 02  sll  %o4, 2, %g1
a010e494:  d4 02 c0 01  ld  [ %o3 + %g1 ], %o2
a010e498:  98 03 20 01  inc  %o4
a010e49c:  d2 22 a0 24  st  %o1, [ %o2 + 0x24 ]
a010e4a0:  80 a3 20 01  cmp  %o4, 1
a010e4a4:  08 bf ff fc  bleu  0xa010e494
a010e4a8:  83 2b 20 02  sll  %o4, 2, %g1
a010e4ac:  82 0a 20 ff  and  %o0, 0xff, %g1
a010e4b0:  80 a0 60 01  cmp  %g1, 1
a010e4b4:  08 80 00 45  bleu  0xa010e5c8
a010e4b8:  15 00 06 6b  sethi  %hi(0x19ac00), %o2
a010e4bc:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010e4c0:  96 12 22 bc  or  %o0, 0x2bc, %o3	! 0x19aebc
a010e4c4:  98 10 20 00  clr  %o4
a010e4c8:  95 2b 20 02  sll  %o4, 2, %o2
a010e4cc:  da 02 c0 0a  ld  [ %o3 + %o2 ], %o5
a010e4d0:  98 03 20 01  inc  %o4
a010e4d4:  d2 23 60 24  st  %o1, [ %o5 + 0x24 ]
a010e4d8:  80 a3 20 01  cmp  %o4, 1
a010e4dc:  08 bf ff fc  bleu  0xa010e4cc
a010e4e0:  95 2b 20 02  sll  %o4, 2, %o2
a010e4e4:  30 80 00 4e  b,a   0xa010e61c
a010e4e8:  80 a2 e0 01  cmp  %o3, 1
a010e4ec:  18 80 00 24  bgu  0xa010e57c
a010e4f0:  82 10 00 08  mov  %o0, %g1
a010e4f4:  82 08 60 ff  and  %g1, 0xff, %g1
a010e4f8:  19 00 06 6b  sethi  %hi(0x19ac00), %o4
a010e4fc:  94 13 22 c4  or  %o4, 0x2c4, %o2	! 0x19aec4
a010e500:  9b 28 60 02  sll  %g1, 2, %o5
a010e504:  d2 02 80 0d  ld  [ %o2 + %o5 ], %o1
a010e508:  d8 02 60 24  ld  [ %o1 + 0x24 ], %o4
a010e50c:  03 00 40 00  sethi  %hi(0x1000000), %g1
a010e510:  80 a2 e0 01  cmp  %o3, 1
a010e514:  08 80 00 25  bleu  0xa010e5a8
a010e518:  92 13 00 01  or  %o4, %g1, %o1
a010e51c:  96 10 00 0a  mov  %o2, %o3
a010e520:  98 10 20 00  clr  %o4
a010e524:  9b 2b 20 02  sll  %o4, 2, %o5
a010e528:  d4 02 c0 0d  ld  [ %o3 + %o5 ], %o2
a010e52c:  98 03 20 01  inc  %o4
a010e530:  d2 22 a0 24  st  %o1, [ %o2 + 0x24 ]
a010e534:  80 a3 20 01  cmp  %o4, 1
a010e538:  08 bf ff fc  bleu  0xa010e528
a010e53c:  9b 2b 20 02  sll  %o4, 2, %o5
a010e540:  82 0a 20 ff  and  %o0, 0xff, %g1
a010e544:  80 a0 60 01  cmp  %g1, 1
a010e548:  08 80 00 20  bleu  0xa010e5c8
a010e54c:  15 00 06 6b  sethi  %hi(0x19ac00), %o2
a010e550:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010e554:  96 12 22 bc  or  %o0, 0x2bc, %o3	! 0x19aebc
a010e558:  98 10 20 00  clr  %o4
a010e55c:  9b 2b 20 02  sll  %o4, 2, %o5
a010e560:  d4 02 c0 0d  ld  [ %o3 + %o5 ], %o2
a010e564:  98 03 20 01  inc  %o4
a010e568:  d2 22 a0 24  st  %o1, [ %o2 + 0x24 ]
a010e56c:  80 a3 20 01  cmp  %o4, 1
a010e570:  08 bf ff fc  bleu  0xa010e560
a010e574:  9b 2b 20 02  sll  %o4, 2, %o5
a010e578:  30 80 00 29  b,a   0xa010e61c
a010e57c:  82 10 20 00  clr  %g1
a010e580:  82 08 60 ff  and  %g1, 0xff, %g1
a010e584:  19 00 06 6b  sethi  %hi(0x19ac00), %o4
a010e588:  94 13 22 c4  or  %o4, 0x2c4, %o2	! 0x19aec4
a010e58c:  9b 28 60 02  sll  %g1, 2, %o5
a010e590:  d2 02 80 0d  ld  [ %o2 + %o5 ], %o1
a010e594:  d8 02 60 24  ld  [ %o1 + 0x24 ], %o4
a010e598:  03 00 40 00  sethi  %hi(0x1000000), %g1
a010e59c:  80 a2 e0 01  cmp  %o3, 1
a010e5a0:  18 bf ff df  bgu  0xa010e51c
a010e5a4:  92 13 00 01  or  %o4, %g1, %o1
a010e5a8:  83 2a e0 02  sll  %o3, 2, %g1
a010e5ac:  d6 02 80 01  ld  [ %o2 + %g1 ], %o3
a010e5b0:  82 0a 20 ff  and  %o0, 0xff, %g1
a010e5b4:  d2 22 e0 24  st  %o1, [ %o3 + 0x24 ]
a010e5b8:  80 a0 60 01  cmp  %g1, 1
a010e5bc:  18 bf ff e6  bgu  0xa010e554
a010e5c0:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010e5c4:  15 00 06 6b  sethi  %hi(0x19ac00), %o2
a010e5c8:  97 28 60 02  sll  %g1, 2, %o3
a010e5cc:  90 12 a2 bc  or  %o2, 0x2bc, %o0
a010e5d0:  d8 02 00 0b  ld  [ %o0 + %o3 ], %o4
a010e5d4:  d2 23 20 24  st  %o1, [ %o4 + 0x24 ]
a010e5d8:  30 80 00 11  b,a   0xa010e61c
a010e5dc:  82 10 20 00  clr  %g1
a010e5e0:  98 08 60 ff  and  %g1, 0xff, %o4
a010e5e4:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010e5e8:  93 2b 20 02  sll  %o4, 2, %o1
a010e5ec:  94 13 62 c4  or  %o5, 0x2c4, %o2
a010e5f0:  da 02 80 09  ld  [ %o2 + %o1 ], %o5
a010e5f4:  d8 03 60 24  ld  [ %o5 + 0x24 ], %o4
a010e5f8:  03 00 40 00  sethi  %hi(0x1000000), %g1
a010e5fc:  80 a2 e0 01  cmp  %o3, 1
a010e600:  18 bf ff a2  bgu  0xa010e488
a010e604:  92 2b 00 01  andn  %o4, %g1, %o1
a010e608:  99 2a e0 02  sll  %o3, 2, %o4
a010e60c:  d6 02 80 0c  ld  [ %o2 + %o4 ], %o3
a010e610:  d2 22 e0 24  st  %o1, [ %o3 + 0x24 ]
a010e614:  10 bf ff a7  b  0xa010e4b0
a010e618:  82 0a 20 ff  and  %o0, 0xff, %g1
a010e61c:  81 c3 e0 08  retl
a010e620:  01 00 00 00  nop
