# leon2m FUN_a010b450 0xa010b450-0xa010b4fc (172 bytes)
a010b450:  90 0a 20 ff  and  %o0, 0xff, %o0
a010b454:  80 a2 20 02  cmp  %o0, 2
a010b458:  08 80 00 15  bleu  0xa010b4ac
a010b45c:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010b460:  93 2a 60 02  sll  %o1, 2, %o1
a010b464:  96 10 62 f0  or  %g1, 0x2f0, %o3
a010b468:  98 10 20 00  clr  %o4
a010b46c:  83 2b 20 02  sll  %o4, 2, %g1
a010b470:  da 02 c0 01  ld  [ %o3 + %g1 ], %o5
a010b474:  98 03 20 01  inc  %o4
a010b478:  d4 23 40 09  st  %o2, [ %o5 + %o1 ]
a010b47c:  80 a3 20 02  cmp  %o4, 2
a010b480:  28 bf ff fc  bleu,a   0xa010b470
a010b484:  83 2b 20 02  sll  %o4, 2, %g1
a010b488:  80 a2 20 02  cmp  %o0, 2
a010b48c:  38 80 00 11  bgu,a   0xa010b4d0
a010b490:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010b494:  97 2a 20 02  sll  %o0, 2, %o3
a010b498:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010b49c:  90 13 62 e4  or  %o5, 0x2e4, %o0	! 0x19aee4
a010b4a0:  d8 02 00 0b  ld  [ %o0 + %o3 ], %o4
a010b4a4:  d4 23 00 09  st  %o2, [ %o4 + %o1 ]
a010b4a8:  30 80 00 13  b,a   0xa010b4f4
a010b4ac:  97 2a 20 02  sll  %o0, 2, %o3
a010b4b0:  9a 10 62 f0  or  %g1, 0x2f0, %o5
a010b4b4:  d8 03 40 0b  ld  [ %o5 + %o3 ], %o4
a010b4b8:  93 2a 60 02  sll  %o1, 2, %o1
a010b4bc:  d4 23 00 09  st  %o2, [ %o4 + %o1 ]
a010b4c0:  80 a2 20 02  cmp  %o0, 2
a010b4c4:  08 bf ff f5  bleu  0xa010b498
a010b4c8:  97 2a 20 02  sll  %o0, 2, %o3
a010b4cc:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010b4d0:  96 12 22 e4  or  %o0, 0x2e4, %o3	! 0x19aee4
a010b4d4:  98 10 20 00  clr  %o4
a010b4d8:  83 2b 20 02  sll  %o4, 2, %g1
a010b4dc:  da 02 c0 01  ld  [ %o3 + %g1 ], %o5
a010b4e0:  98 03 20 01  inc  %o4
a010b4e4:  d4 23 40 09  st  %o2, [ %o5 + %o1 ]
a010b4e8:  80 a3 20 02  cmp  %o4, 2
a010b4ec:  08 bf ff fc  bleu  0xa010b4dc
a010b4f0:  83 2b 20 02  sll  %o4, 2, %g1
a010b4f4:  81 c3 e0 08  retl
a010b4f8:  01 00 00 00  nop
