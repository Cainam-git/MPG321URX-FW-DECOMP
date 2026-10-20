# leon2s FUN_a00d9524 0xa00d9524-0xa00d95e4 (192 bytes)
a00d9524:  9d e3 bf 80  save  %sp, -128, %sp
a00d9528:  a0 07 bf e0  add  %fp, -32, %l0
a00d952c:  94 10 20 13  mov  0x13, %o2
a00d9530:  92 10 00 18  mov  %i0, %o1
a00d9534:  40 3b a0 29  call  0xa0fc15d8
a00d9538:  90 10 00 10  mov  %l0, %o0
a00d953c:  d8 07 bf e0  ld  [ %fp + -32 ], %o4
a00d9540:  03 3c 00 00  sethi  %hi(0xf0000000), %g1
a00d9544:  82 2b 00 01  andn  %o4, %g1, %g1
a00d9548:  1b 04 00 00  sethi  %hi(0x10000000), %o5
a00d954c:  82 10 40 0d  or  %g1, %o5, %g1
a00d9550:  1b 03 c0 00  sethi  %hi(0xf000000), %o5
a00d9554:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d9558:  03 03 c0 00  sethi  %hi(0xf000000), %g1
a00d955c:  97 33 20 18  srl  %o4, 0x18, %o3
a00d9560:  94 2b 00 01  andn  %o4, %g1, %o2
a00d9564:  96 0a e0 0f  and  %o3, 0xf, %o3
a00d9568:  99 33 20 1c  srl  %o4, 0x1c, %o4
a00d956c:  80 a2 c0 0c  cmp  %o3, %o4
a00d9570:  2a 80 00 04  bcs,a   0xa00d9580
a00d9574:  da 0e 00 00  ldub  [ %i0 ], %o5
a00d9578:  10 80 00 0b  b  0xa00d95a4
a00d957c:  da 27 bf e0  st  %o5, [ %fp + -32 ]
a00d9580:  82 0b 60 ff  and  %o5, 0xff, %g1
a00d9584:  83 30 60 04  srl  %g1, 4, %g1
a00d9588:  9a 0b 60 0f  and  %o5, 0xf, %o5
a00d958c:  82 20 40 0d  sub  %g1, %o5, %g1
a00d9590:  82 00 7f ff  add  %g1, -1, %g1
a00d9594:  82 08 60 0f  and  %g1, 0xf, %g1
a00d9598:  83 28 60 18  sll  %g1, 0x18, %g1
a00d959c:  94 12 80 01  or  %o2, %g1, %o2
a00d95a0:  d4 27 bf e0  st  %o2, [ %fp + -32 ]
a00d95a4:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a00d95a8:  03 00 0f c0  sethi  %hi(0x3f0000), %g1
a00d95ac:  82 2b 40 01  andn  %o5, %g1, %g1
a00d95b0:  1b 00 00 20  sethi  %hi(0x8000), %o5
a00d95b4:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d95b8:  03 00 00 10  sethi  %hi(0x4000), %g1
a00d95bc:  82 2b 40 01  andn  %o5, %g1, %g1
a00d95c0:  82 08 70 ff  and  %g1, -3841, %g1
a00d95c4:  c2 27 bf f0  st  %g1, [ %fp + -16 ]
a00d95c8:  90 10 00 10  mov  %l0, %o0
a00d95cc:  92 10 20 01  mov  1, %o1
a00d95d0:  7f ff f5 21  call  0xa00d6a54
a00d95d4:  94 10 20 01  mov  1, %o2
a00d95d8:  01 00 00 00  nop
a00d95dc:  81 c7 e0 08  ret
a00d95e0:  81 e8 00 00  restore
