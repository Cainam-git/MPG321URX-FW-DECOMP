# leon2s FUN_a00aa538 0xa00aa538-0xa00aa5e8 (176 bytes)
a00aa538:  9d e3 bf 98  save  %sp, -104, %sp
a00aa53c:  80 8e 60 ff  btst  0xff, %i1
a00aa540:  02 80 00 1c  be  0xa00aa5b0
a00aa544:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00aa548:  3b 33 c0 4a  sethi  %hi(0xcf012800), %i5
a00aa54c:  9a 17 62 94  or  %i5, 0x294, %o5	! 0xcf012a94
a00aa550:  9e 17 62 d8  or  %i5, 0x2d8, %o7
a00aa554:  b2 17 62 98  or  %i5, 0x298, %i1
a00aa558:  b4 17 62 dc  or  %i5, 0x2dc, %i2
a00aa55c:  b6 17 62 9c  or  %i5, 0x29c, %i3
a00aa560:  b8 17 62 d0  or  %i5, 0x2d0, %i4
a00aa564:  80 a6 20 00  cmp  %i0, 0
a00aa568:  12 80 00 09  bne  0xa00aa58c
a00aa56c:  ba 17 62 90  or  %i5, 0x290, %i5
a00aa570:  82 10 20 b0  mov  0xb0, %g1
a00aa574:  c2 23 c0 00  st  %g1, [ %o7 ]
a00aa578:  82 10 20 01  mov  1, %g1
a00aa57c:  c2 26 80 00  st  %g1, [ %i2 ]
a00aa580:  c2 07 00 00  ld  [ %i4 ], %g1
a00aa584:  10 80 00 12  b  0xa00aa5cc
a00aa588:  82 10 60 01  or  %g1, 1, %g1
a00aa58c:  82 10 20 0f  mov  0xf, %g1
a00aa590:  c2 23 40 00  st  %g1, [ %o5 ]
a00aa594:  82 10 20 b0  mov  0xb0, %g1
a00aa598:  c2 26 40 00  st  %g1, [ %i1 ]
a00aa59c:  82 10 20 03  mov  3, %g1
a00aa5a0:  c2 26 c0 00  st  %g1, [ %i3 ]
a00aa5a4:  c2 07 40 00  ld  [ %i5 ], %g1
a00aa5a8:  10 80 00 0d  b  0xa00aa5dc
a00aa5ac:  82 10 60 01  or  %g1, 1, %g1
a00aa5b0:  03 33 c0 4a  sethi  %hi(0xcf012800), %g1
a00aa5b4:  b8 10 62 d0  or  %g1, 0x2d0, %i4	! 0xcf012ad0
a00aa5b8:  80 a6 20 00  cmp  %i0, 0
a00aa5bc:  12 80 00 06  bne  0xa00aa5d4
a00aa5c0:  ba 10 62 90  or  %g1, 0x290, %i5
a00aa5c4:  c2 07 00 00  ld  [ %i4 ], %g1
a00aa5c8:  82 08 7f fe  and  %g1, -2, %g1
a00aa5cc:  c2 27 00 00  st  %g1, [ %i4 ]
a00aa5d0:  30 80 00 04  b,a   0xa00aa5e0
a00aa5d4:  c2 07 40 00  ld  [ %i5 ], %g1
a00aa5d8:  82 08 7f fe  and  %g1, -2, %g1
a00aa5dc:  c2 27 40 00  st  %g1, [ %i5 ]
a00aa5e0:  81 c7 e0 08  ret
a00aa5e4:  81 e8 00 00  restore
