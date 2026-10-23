# leon2m FUN_a010c4a0 0xa010c4a0-0xa010c54c (172 bytes)
a010c4a0:  90 0a 20 ff  and  %o0, 0xff, %o0
a010c4a4:  80 a2 20 01  cmp  %o0, 1
a010c4a8:  08 80 00 1a  bleu  0xa010c510
a010c4ac:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010c4b0:  93 2a 60 02  sll  %o1, 2, %o1
a010c4b4:  96 10 62 c4  or  %g1, 0x2c4, %o3
a010c4b8:  98 10 20 00  clr  %o4
a010c4bc:  83 2b 20 02  sll  %o4, 2, %g1
a010c4c0:  da 02 c0 01  ld  [ %o3 + %g1 ], %o5
a010c4c4:  98 03 20 01  inc  %o4
a010c4c8:  d4 23 40 09  st  %o2, [ %o5 + %o1 ]
a010c4cc:  80 a3 20 01  cmp  %o4, 1
a010c4d0:  08 bf ff fc  bleu  0xa010c4c0
a010c4d4:  83 2b 20 02  sll  %o4, 2, %g1
a010c4d8:  80 a2 20 01  cmp  %o0, 1
a010c4dc:  08 80 00 16  bleu  0xa010c534
a010c4e0:  97 2a 20 02  sll  %o0, 2, %o3
a010c4e4:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010c4e8:  96 12 22 bc  or  %o0, 0x2bc, %o3	! 0x19aebc
a010c4ec:  98 10 20 00  clr  %o4
a010c4f0:  83 2b 20 02  sll  %o4, 2, %g1
a010c4f4:  da 02 c0 01  ld  [ %o3 + %g1 ], %o5
a010c4f8:  98 03 20 01  inc  %o4
a010c4fc:  d4 23 40 09  st  %o2, [ %o5 + %o1 ]
a010c500:  80 a3 20 01  cmp  %o4, 1
a010c504:  08 bf ff fc  bleu  0xa010c4f4
a010c508:  83 2b 20 02  sll  %o4, 2, %g1
a010c50c:  30 80 00 0e  b,a   0xa010c544
a010c510:  97 2a 20 02  sll  %o0, 2, %o3
a010c514:  9a 10 62 c4  or  %g1, 0x2c4, %o5
a010c518:  d8 03 40 0b  ld  [ %o5 + %o3 ], %o4
a010c51c:  93 2a 60 02  sll  %o1, 2, %o1
a010c520:  d4 23 00 09  st  %o2, [ %o4 + %o1 ]
a010c524:  80 a2 20 01  cmp  %o0, 1
a010c528:  38 bf ff f0  bgu,a   0xa010c4e8
a010c52c:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010c530:  97 2a 20 02  sll  %o0, 2, %o3
a010c534:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010c538:  90 13 62 bc  or  %o5, 0x2bc, %o0	! 0x19aebc
a010c53c:  d8 02 00 0b  ld  [ %o0 + %o3 ], %o4
a010c540:  d4 23 00 09  st  %o2, [ %o4 + %o1 ]
a010c544:  81 c3 e0 08  retl
a010c548:  01 00 00 00  nop
