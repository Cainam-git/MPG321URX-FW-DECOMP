# leon2s FUN_a00cd4fc 0xa00cd4fc-0xa00cd5e4 (232 bytes)
a00cd4fc:  9d e3 bf 80  save  %sp, -128, %sp
a00cd500:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cd504:  82 06 00 18  add  %i0, %i0, %g1
a00cd508:  82 00 40 18  add  %g1, %i0, %g1
a00cd50c:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a00cd510:  a1 28 60 03  sll  %g1, 3, %l0
a00cd514:  a2 14 a3 b0  or  %l2, 0x3b0, %l1
a00cd518:  c2 14 40 10  lduh  [ %l1 + %l0 ], %g1
a00cd51c:  15 00 01 a0  sethi  %hi(0x68000), %o2
a00cd520:  82 08 60 03  and  %g1, 3, %g1
a00cd524:  94 12 a0 29  or  %o2, 0x29, %o2
a00cd528:  96 07 bf e0  add  %fp, -32, %o3
a00cd52c:  92 10 20 90  mov  0x90, %o1
a00cd530:  80 a0 60 02  cmp  %g1, 2
a00cd534:  02 80 00 15  be  0xa00cd588
a00cd538:  90 10 20 00  clr  %o0
a00cd53c:  40 3b 23 98  call  0xa0f9639c
a00cd540:  01 00 00 00  nop
a00cd544:  80 8a 20 ff  btst  0xff, %o0
a00cd548:  02 80 00 08  be  0xa00cd568
a00cd54c:  c2 0f bf e0  ldub  [ %fp + -32 ], %g1
a00cd550:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cd554:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cd558:  82 10 40 0d  or  %g1, %o5, %g1
a00cd55c:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cd560:  10 80 00 1e  b  0xa00cd5d8
a00cd564:  c0 2f bf e0  clrb  [ %fp + -32 ]
a00cd568:  80 88 60 01  btst  1, %g1
a00cd56c:  12 80 00 08  bne  0xa00cd58c
a00cd570:  98 06 00 18  add  %i0, %i0, %o4
a00cd574:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cd578:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cd57c:  82 10 40 0d  or  %g1, %o5, %g1
a00cd580:  10 80 00 16  b  0xa00cd5d8
a00cd584:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cd588:  98 06 00 18  add  %i0, %i0, %o4
a00cd58c:  98 03 00 18  add  %o4, %i0, %o4
a00cd590:  99 2b 20 03  sll  %o4, 3, %o4
a00cd594:  96 14 a3 b0  or  %l2, 0x3b0, %o3
a00cd598:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cd59c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cd5a0:  82 2b 40 01  andn  %o5, %g1, %g1
a00cd5a4:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cd5a8:  82 10 40 0d  or  %g1, %o5, %g1
a00cd5ac:  92 10 20 21  mov  0x21, %o1
a00cd5b0:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cd5b4:  40 3b a8 c0  call  0xa0fb78b4
a00cd5b8:  90 10 00 18  mov  %i0, %o0
a00cd5bc:  80 8a 20 80  btst  0x80, %o0
a00cd5c0:  92 10 20 21  mov  0x21, %o1
a00cd5c4:  94 10 20 80  mov  0x80, %o2
a00cd5c8:  02 80 00 04  be  0xa00cd5d8
a00cd5cc:  90 10 00 18  mov  %i0, %o0
a00cd5d0:  40 3b a8 cb  call  0xa0fb78fc
a00cd5d4:  01 00 00 00  nop
a00cd5d8:  01 00 00 00  nop
a00cd5dc:  81 c7 e0 08  ret
a00cd5e0:  81 e8 00 00  restore
