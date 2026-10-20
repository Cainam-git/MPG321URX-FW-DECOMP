# leon2s FUN_a00ad478 0xa00ad478-0xa00ad5a4 (300 bytes)
a00ad478:  9d e3 bf 98  save  %sp, -104, %sp
a00ad47c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ad480:  80 a0 00 18  cmp  %g0, %i0
a00ad484:  82 40 3f ff  addx  %g0, -1, %g1
a00ad488:  82 08 60 07  and  %g1, 7, %g1
a00ad48c:  b0 00 60 01  add  %g1, 1, %i0
a00ad490:  7f ff ff d4  call  0xa00ad3e0
a00ad494:  90 10 20 00  clr  %o0
a00ad498:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ad49c:  80 a2 20 01  cmp  %o0, 1
a00ad4a0:  02 80 00 08  be  0xa00ad4c0
a00ad4a4:  01 00 00 00  nop
a00ad4a8:  7f ff ff ce  call  0xa00ad3e0
a00ad4ac:  90 10 20 01  mov  1, %o0	! 0x1
a00ad4b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ad4b4:  80 a2 20 01  cmp  %o0, 1
a00ad4b8:  12 80 00 04  bne  0xa00ad4c8
a00ad4bc:  21 33 c0 4c  sethi  %hi(0xcf013000), %l0
a00ad4c0:  7f ff fe cd  call  0xa00acff4
a00ad4c4:  21 33 c0 4c  sethi  %hi(0xcf013000), %l0
a00ad4c8:  96 0e 20 ff  and  %i0, 0xff, %o3
a00ad4cc:  98 14 22 d8  or  %l0, 0x2d8, %o4
a00ad4d0:  82 10 20 30  mov  0x30, %g1
a00ad4d4:  c2 23 00 00  st  %g1, [ %o4 ]
a00ad4d8:  9b 2a e0 03  sll  %o3, 3, %o5
a00ad4dc:  9a 03 40 0b  add  %o5, %o3, %o5
a00ad4e0:  82 14 22 c4  or  %l0, 0x2c4, %g1
a00ad4e4:  da 20 40 00  st  %o5, [ %g1 ]
a00ad4e8:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00ad4ec:  b0 10 60 18  or  %g1, 0x18, %i0	! 0xa807dc18
a00ad4f0:  99 2a e0 04  sll  %o3, 4, %o4
a00ad4f4:  82 14 22 c8  or  %l0, 0x2c8, %g1
a00ad4f8:  98 23 00 0b  sub  %o4, %o3, %o4
a00ad4fc:  d8 20 40 00  st  %o4, [ %g1 ]
a00ad500:  c2 0e 21 1e  ldub  [ %i0 + 0x11e ], %g1
a00ad504:  9a 14 22 cc  or  %l0, 0x2cc, %o5
a00ad508:  a2 10 20 01  mov  1, %l1
a00ad50c:  e2 23 40 00  st  %l1, [ %o5 ]
a00ad510:  80 a0 60 01  cmp  %g1, 1
a00ad514:  32 80 00 07  bne,a   0xa00ad530
a00ad518:  c2 0e 22 4a  ldub  [ %i0 + 0x24a ], %g1
a00ad51c:  7f ff fe ce  call  0xa00ad054
a00ad520:  90 10 20 01  mov  1, %o0
a00ad524:  7f ff fe cf  call  0xa00ad060
a00ad528:  90 10 20 00  clr  %o0
a00ad52c:  c2 0e 22 4a  ldub  [ %i0 + 0x24a ], %g1
a00ad530:  80 a0 60 01  cmp  %g1, 1
a00ad534:  12 80 00 06  bne  0xa00ad54c
a00ad538:  01 00 00 00  nop
a00ad53c:  7f ff fe c6  call  0xa00ad054
a00ad540:  90 10 20 01  mov  1, %o0	! 0x1
a00ad544:  7f ff fe c7  call  0xa00ad060
a00ad548:  90 10 20 01  mov  1, %o0
a00ad54c:  7f ff fe aa  call  0xa00acff4
a00ad550:  01 00 00 00  nop
a00ad554:  c2 0e 21 1e  ldub  [ %i0 + 0x11e ], %g1
a00ad558:  80 a0 60 01  cmp  %g1, 1
a00ad55c:  32 80 00 07  bne,a   0xa00ad578
a00ad560:  c2 0e 22 4a  ldub  [ %i0 + 0x24a ], %g1
a00ad564:  1b 2a 01 e4  sethi  %hi(0xa8079000), %o5
a00ad568:  c2 0b 63 15  ldub  [ %o5 + 0x315 ], %g1	! 0xa8079315
a00ad56c:  82 08 7f fe  and  %g1, -2, %g1
a00ad570:  c2 2b 63 15  stb  %g1, [ %o5 + 0x315 ]
a00ad574:  c2 0e 22 4a  ldub  [ %i0 + 0x24a ], %g1
a00ad578:  80 a0 60 01  cmp  %g1, 1
a00ad57c:  12 80 00 07  bne  0xa00ad598
a00ad580:  82 14 22 c0  or  %l0, 0x2c0, %g1
a00ad584:  1b 2a 01 e4  sethi  %hi(0xa8079000), %o5
a00ad588:  c2 0b 63 15  ldub  [ %o5 + 0x315 ], %g1	! 0xa8079315
a00ad58c:  82 08 7f fd  and  %g1, -3, %g1
a00ad590:  c2 2b 63 15  stb  %g1, [ %o5 + 0x315 ]
a00ad594:  82 14 22 c0  or  %l0, 0x2c0, %g1
a00ad598:  e2 20 40 00  st  %l1, [ %g1 ]
a00ad59c:  81 c7 e0 08  ret
a00ad5a0:  81 e8 00 00  restore
