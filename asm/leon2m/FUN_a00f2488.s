# leon2m FUN_a00f2488 0xa00f2488-0xa00f25f8 (368 bytes)
a00f2488:  9d e3 bf 98  save  %sp, -104, %sp
a00f248c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f2490:  9e 10 00 1a  mov  %i2, %o7
a00f2494:  80 a6 20 08  cmp  %i0, 8
a00f2498:  02 80 00 2c  be  0xa00f2548
a00f249c:  9a 10 00 1a  mov  %i2, %o5
a00f24a0:  80 a6 20 05  cmp  %i0, 5
a00f24a4:  38 80 00 14  bgu,a   0xa00f24f4
a00f24a8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00f24ac:  37 00 06 68  sethi  %hi(0x19a000), %i3
a00f24b0:  ba 06 00 18  add  %i0, %i0, %i5
a00f24b4:  b8 16 e2 ec  or  %i3, 0x2ec, %i4
a00f24b8:  f4 17 00 1d  lduh  [ %i4 + %i5 ], %i2
a00f24bc:  82 0e 60 ff  and  %i1, 0xff, %g1
a00f24c0:  b2 06 80 01  add  %i2, %g1, %i1
a00f24c4:  b6 06 60 01  add  %i1, 1, %i3
a00f24c8:  b1 2e 60 02  sll  %i1, 2, %i0
a00f24cc:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a00f24d0:  ba 16 00 1a  or  %i0, %i2, %i5
a00f24d4:  b8 0b e0 ff  and  %o7, 0xff, %i4
a00f24d8:  83 2e e0 02  sll  %i3, 2, %g1
a00f24dc:  b3 2b e0 10  sll  %o7, 0x10, %i1
a00f24e0:  f8 27 40 00  st  %i4, [ %i5 ]
a00f24e4:  b6 10 40 1a  or  %g1, %i2, %i3
a00f24e8:  b1 36 60 18  srl  %i1, 0x18, %i0
a00f24ec:  f0 26 c0 00  st  %i0, [ %i3 ]
a00f24f0:  30 80 00 40  b,a   0xa00f25f0
a00f24f4:  80 a6 60 a0  cmp  %i1, 0xa0
a00f24f8:  02 80 00 38  be  0xa00f25d8
a00f24fc:  80 a6 60 be  cmp  %i1, 0xbe
a00f2500:  02 80 00 2b  be  0xa00f25ac
a00f2504:  39 00 06 68  sethi  %hi(0x19a000), %i4
a00f2508:  ba 06 00 18  add  %i0, %i0, %i5
a00f250c:  82 17 22 ec  or  %i4, 0x2ec, %g1
a00f2510:  f4 10 40 1d  lduh  [ %g1 + %i5 ], %i2
a00f2514:  b0 06 80 19  add  %i2, %i1, %i0
a00f2518:  b8 06 20 01  add  %i0, 1, %i4
a00f251c:  b7 2e 20 02  sll  %i0, 2, %i3
a00f2520:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a00f2524:  ba 16 c0 1a  or  %i3, %i2, %i5
a00f2528:  82 0b e0 ff  and  %o7, 0xff, %g1
a00f252c:  b3 2f 20 02  sll  %i4, 2, %i1
a00f2530:  b1 2b e0 10  sll  %o7, 0x10, %i0
a00f2534:  c2 27 40 00  st  %g1, [ %i5 ]
a00f2538:  b8 16 40 1a  or  %i1, %i2, %i4
a00f253c:  b7 36 20 18  srl  %i0, 0x18, %i3
a00f2540:  f6 27 00 00  st  %i3, [ %i4 ]
a00f2544:  30 80 00 2b  b,a   0xa00f25f0
a00f2548:  bb 2e a0 10  sll  %i2, 0x10, %i5
a00f254c:  b6 0e a0 ff  and  %i2, 0xff, %i3
a00f2550:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f2554:  b5 37 60 18  srl  %i5, 0x18, %i2
a00f2558:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00f255c:  9e 10 62 ec  or  %g1, 0x2ec, %o7
a00f2560:  b0 10 20 00  clr  %i0
a00f2564:  ba 10 20 00  clr  %i5
a00f2568:  39 33 c0 00  sethi  %hi(0xcf000000), %i4
a00f256c:  82 07 40 1d  add  %i5, %i5, %g1
a00f2570:  fa 13 c0 01  lduh  [ %o7 + %g1 ], %i5
a00f2574:  ba 07 40 19  add  %i5, %i1, %i5
a00f2578:  82 07 60 01  add  %i5, 1, %g1
a00f257c:  bb 2f 60 02  sll  %i5, 2, %i5
a00f2580:  ba 17 40 1c  or  %i5, %i4, %i5
a00f2584:  f6 27 40 00  st  %i3, [ %i5 ]
a00f2588:  83 28 60 02  sll  %g1, 2, %g1
a00f258c:  b0 06 20 01  inc  %i0
a00f2590:  82 10 40 1c  or  %g1, %i4, %g1
a00f2594:  ba 0e 20 ff  and  %i0, 0xff, %i5
a00f2598:  f4 20 40 00  st  %i2, [ %g1 ]
a00f259c:  80 a7 60 07  cmp  %i5, 7
a00f25a0:  08 bf ff f4  bleu  0xa00f2570
a00f25a4:  82 07 40 1d  add  %i5, %i5, %g1
a00f25a8:  30 80 00 12  b,a   0xa00f25f0
a00f25ac:  b8 06 00 18  add  %i0, %i0, %i4
a00f25b0:  31 00 06 68  sethi  %hi(0x19a000), %i0
a00f25b4:  b6 16 22 ec  or  %i0, 0x2ec, %i3	! 0x19a2ec
a00f25b8:  fa 16 c0 1c  lduh  [ %i3 + %i4 ], %i5
a00f25bc:  ba 07 60 5d  add  %i5, 0x5d, %i5
a00f25c0:  bb 2f 60 02  sll  %i5, 2, %i5
a00f25c4:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00f25c8:  b2 17 40 01  or  %i5, %g1, %i1
a00f25cc:  b4 0b 60 ff  and  %o5, 0xff, %i2
a00f25d0:  f4 26 40 00  st  %i2, [ %i1 ]
a00f25d4:  30 80 00 07  b,a   0xa00f25f0
a00f25d8:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f25dc:  b2 06 00 18  add  %i0, %i0, %i1
a00f25e0:  b4 10 62 ec  or  %g1, 0x2ec, %i2
a00f25e4:  f0 16 80 19  lduh  [ %i2 + %i1 ], %i0
a00f25e8:  10 bf ff f6  b  0xa00f25c0
a00f25ec:  ba 06 20 60  add  %i0, 0x60, %i5
a00f25f0:  81 c7 e0 08  ret
a00f25f4:  81 e8 00 00  restore
