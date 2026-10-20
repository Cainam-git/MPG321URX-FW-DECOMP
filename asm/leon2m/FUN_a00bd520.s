# leon2m FUN_a00bd520 0xa00bd520-0xa00bd59c (124 bytes)
a00bd520:  9d e3 bf 98  save  %sp, -104, %sp
a00bd524:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00bd528:  c2 0b 60 1b  ldub  [ %o5 + 0x1b ], %g1	! 0xa802d41b
a00bd52c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00bd530:  98 12 20 78  or  %o0, 0x78, %o4	! 0xa802d078
a00bd534:  9a 00 60 26  add  %g1, 0x26, %o5
a00bd538:  96 10 20 30  mov  0x30, %o3
a00bd53c:  80 a0 60 09  cmp  %g1, 9
a00bd540:  d6 2b 20 07  stb  %o3, [ %o4 + 7 ]
a00bd544:  08 80 00 0c  bleu  0xa00bd574
a00bd548:  82 00 60 30  add  %g1, 0x30, %g1
a00bd54c:  92 10 20 31  mov  0x31, %o1
a00bd550:  da 2b 20 09  stb  %o5, [ %o4 + 9 ]
a00bd554:  d2 2b 20 08  stb  %o1, [ %o4 + 8 ]
a00bd558:  7f ff f5 b9  call  0xa00bac3c
a00bd55c:  90 10 20 29  mov  0x29, %o0
a00bd560:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bd564:  7f ff f4 fb  call  0xa00ba950
a00bd568:  90 10 00 18  mov  %i0, %o0
a00bd56c:  7f ff f5 9e  call  0xa00babe4
a00bd570:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd574:  c2 2b 20 09  stb  %g1, [ %o4 + 9 ]
a00bd578:  d6 2b 20 08  stb  %o3, [ %o4 + 8 ]
a00bd57c:  7f ff f5 b0  call  0xa00bac3c
a00bd580:  90 10 20 29  mov  0x29, %o0
a00bd584:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bd588:  7f ff f4 f2  call  0xa00ba950
a00bd58c:  90 10 00 18  mov  %i0, %o0
a00bd590:  7f ff f5 95  call  0xa00babe4
a00bd594:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd598:  01 00 00 00  nop
