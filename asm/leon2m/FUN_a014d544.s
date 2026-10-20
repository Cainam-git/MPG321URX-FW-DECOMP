# leon2m FUN_a014d544 0xa014d544-0xa014d5f4 (176 bytes)
a014d544:  9d e3 bf 98  save  %sp, -104, %sp
a014d548:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014d54c:  80 a6 20 01  cmp  %i0, 1
a014d550:  02 80 00 0b  be  0xa014d57c
a014d554:  98 10 20 01  mov  1, %o4
a014d558:  80 a6 20 01  cmp  %i0, 1
a014d55c:  04 80 00 11  ble  0xa014d5a0
a014d560:  80 a6 20 02  cmp  %i0, 2
a014d564:  02 80 00 06  be  0xa014d57c
a014d568:  98 10 20 02  mov  2, %o4
a014d56c:  80 a6 20 03  cmp  %i0, 3
a014d570:  02 80 00 03  be  0xa014d57c
a014d574:  98 10 20 03  mov  3, %o4
a014d578:  98 10 3f ff  mov  -1, %o4
a014d57c:  82 0b 20 ff  and  %o4, 0xff, %g1
a014d580:  80 a0 60 03  cmp  %g1, 3
a014d584:  08 80 00 0d  bleu  0xa014d5b8
a014d588:  95 28 60 04  sll  %g1, 4, %o2
a014d58c:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a014d590:  7f fe 46 f8  call  0xa00df170
a014d594:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a014d598:  10 80 00 07  b  0xa014d5b4
a014d59c:  82 10 20 00  clr  %g1
a014d5a0:  80 a6 20 00  cmp  %i0, 0
a014d5a4:  02 bf ff f6  be  0xa014d57c
a014d5a8:  98 10 20 00  clr  %o4
a014d5ac:  10 bf ff f4  b  0xa014d57c
a014d5b0:  98 10 3f ff  mov  -1, %o4
a014d5b4:  95 28 60 04  sll  %g1, 4, %o2
a014d5b8:  9a 22 80 01  sub  %o2, %g1, %o5
a014d5bc:  13 2a 00 b7  sethi  %hi(0xa802dc00), %o1
a014d5c0:  b0 12 63 30  or  %o1, 0x330, %i0	! 0xa802df30
a014d5c4:  91 2b 60 03  sll  %o5, 3, %o0
a014d5c8:  de 06 00 08  ld  [ %i0 + %o0 ], %o7
a014d5cc:  99 33 e0 0c  srl  %o7, 0xc, %o4
a014d5d0:  96 0b 20 0f  and  %o4, 0xf, %o3
a014d5d4:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014d5d8:  9a 5a e0 2a  smul  %o3, 0x2a, %o5
a014d5dc:  82 12 a2 24  or  %o2, 0x224, %g1
a014d5e0:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a014d5e4:  b1 32 60 0b  srl  %o1, 0xb, %i0
a014d5e8:  b0 0e 20 01  and  %i0, 1, %i0
a014d5ec:  81 c7 e0 08  ret
a014d5f0:  81 e8 00 00  restore
