# leon2m FUN_a00f6508 0xa00f6508-0xa00f65d8 (208 bytes)
a00f6508:  17 33 c0 3b  sethi  %hi(0xcf00ec00), %o3
a00f650c:  9a 12 e3 30  or  %o3, 0x330, %o5	! 0xcf00ef30
a00f6510:  d8 03 40 00  ld  [ %o5 ], %o4
a00f6514:  94 0b 3f fd  and  %o4, -3, %o2
a00f6518:  d4 23 40 00  st  %o2, [ %o5 ]
a00f651c:  98 12 e3 34  or  %o3, 0x334, %o4
a00f6520:  82 10 20 02  mov  2, %g1
a00f6524:  c2 23 00 00  st  %g1, [ %o4 ]
a00f6528:  94 12 e3 3c  or  %o3, 0x33c, %o2
a00f652c:  98 10 20 00  clr  %o4
a00f6530:  9a 10 20 00  clr  %o5
a00f6534:  96 12 e3 38  or  %o3, 0x338, %o3
a00f6538:  80 a2 20 00  cmp  %o0, 0
a00f653c:  02 80 00 12  be  0xa00f6584
a00f6540:  82 10 20 80  mov  0x80, %g1
a00f6544:  c2 02 00 00  ld  [ %o0 ], %g1
a00f6548:  83 30 40 0d  srl  %g1, %o5, %g1
a00f654c:  80 88 60 01  btst  1, %g1
a00f6550:  22 80 00 07  be,a   0xa00f656c
a00f6554:  98 03 20 01  inc  %o4
a00f6558:  da 22 c0 00  st  %o5, [ %o3 ]
a00f655c:  82 02 00 0d  add  %o0, %o5, %g1
a00f6560:  da 08 60 04  ldub  [ %g1 + 4 ], %o5
a00f6564:  da 22 80 00  st  %o5, [ %o2 ]
a00f6568:  98 03 20 01  inc  %o4
a00f656c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f6570:  80 a3 60 17  cmp  %o5, 0x17
a00f6574:  28 bf ff f5  bleu,a   0xa00f6548
a00f6578:  c2 02 00 00  ld  [ %o0 ], %g1
a00f657c:  10 80 00 11  b  0xa00f65c0
a00f6580:  19 33 c0 3b  sethi  %hi(0xcf00ec00), %o4
a00f6584:  da 22 c0 00  st  %o5, [ %o3 ]
a00f6588:  98 03 20 01  inc  %o4
a00f658c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f6590:  c2 22 80 00  st  %g1, [ %o2 ]
a00f6594:  80 a3 60 17  cmp  %o5, 0x17
a00f6598:  38 80 00 0a  bgu,a   0xa00f65c0
a00f659c:  19 33 c0 3b  sethi  %hi(0xcf00ec00), %o4
a00f65a0:  da 22 c0 00  st  %o5, [ %o3 ]
a00f65a4:  98 03 20 01  inc  %o4
a00f65a8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f65ac:  c2 22 80 00  st  %g1, [ %o2 ]
a00f65b0:  80 a3 60 17  cmp  %o5, 0x17
a00f65b4:  08 bf ff f4  bleu  0xa00f6584
a00f65b8:  01 00 00 00  nop
a00f65bc:  19 33 c0 3b  sethi  %hi(0xcf00ec00), %o4
a00f65c0:  90 13 23 30  or  %o4, 0x330, %o0	! 0xcf00ef30
a00f65c4:  d4 02 00 00  ld  [ %o0 ], %o2
a00f65c8:  96 12 a0 02  or  %o2, 2, %o3
a00f65cc:  d6 22 00 00  st  %o3, [ %o0 ]
a00f65d0:  81 c3 e0 08  retl
a00f65d4:  01 00 00 00  nop
