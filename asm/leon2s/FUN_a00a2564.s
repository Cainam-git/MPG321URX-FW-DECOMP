# leon2s FUN_a00a2564 0xa00a2564-0xa00a268c (296 bytes)  [FUN_a00a2684 = unreachable ret/restore tail, merged]
a00a2564:  9d e3 bf 98  save  %sp, -104, %sp
a00a2568:  7f ff ac a6  call  0xa008d800
a00a256c:  01 00 00 00  nop
a00a2570:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a2574:  80 a2 20 82  cmp  %o0, 0x82
a00a2578:  08 80 00 42  bleu  0xa00a2680
a00a257c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a2580:  80 8e 20 01  btst  1, %i0
a00a2584:  02 80 00 0d  be  0xa00a25b8
a00a2588:  80 8e 20 02  btst  2, %i0
a00a258c:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a00a2590:  a0 14 23 00  or  %l0, 0x300, %l0	! 0xa807db00
a00a2594:  d2 04 20 24  ld  [ %l0 + 0x24 ], %o1
a00a2598:  92 02 60 c0  add  %o1, 0xc0, %o1
a00a259c:  40 00 13 8e  call  0xa00a73d4
a00a25a0:  90 10 20 0c  mov  0xc, %o0
a00a25a4:  d2 04 20 58  ld  [ %l0 + 0x58 ], %o1
a00a25a8:  92 02 60 c0  add  %o1, 0xc0, %o1
a00a25ac:  40 00 13 8a  call  0xa00a73d4
a00a25b0:  90 10 20 0c  mov  0xc, %o0
a00a25b4:  80 8e 20 02  btst  2, %i0
a00a25b8:  02 80 00 0d  be  0xa00a25ec
a00a25bc:  80 8e 20 04  btst  4, %i0
a00a25c0:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a00a25c4:  a0 14 23 00  or  %l0, 0x300, %l0	! 0xa807db00
a00a25c8:  d2 04 20 24  ld  [ %l0 + 0x24 ], %o1
a00a25cc:  92 02 60 c0  add  %o1, 0xc0, %o1
a00a25d0:  40 00 13 81  call  0xa00a73d4
a00a25d4:  90 10 20 0d  mov  0xd, %o0
a00a25d8:  d2 04 20 58  ld  [ %l0 + 0x58 ], %o1
a00a25dc:  92 02 60 c0  add  %o1, 0xc0, %o1
a00a25e0:  40 00 13 7d  call  0xa00a73d4
a00a25e4:  90 10 20 0d  mov  0xd, %o0
a00a25e8:  80 8e 20 04  btst  4, %i0
a00a25ec:  02 80 00 0d  be  0xa00a2620
a00a25f0:  80 8e 20 08  btst  8, %i0
a00a25f4:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a00a25f8:  a0 14 23 00  or  %l0, 0x300, %l0	! 0xa807db00
a00a25fc:  d2 04 20 24  ld  [ %l0 + 0x24 ], %o1
a00a2600:  92 02 60 c0  add  %o1, 0xc0, %o1
a00a2604:  40 00 13 74  call  0xa00a73d4
a00a2608:  90 10 20 0e  mov  0xe, %o0
a00a260c:  d2 04 20 58  ld  [ %l0 + 0x58 ], %o1
a00a2610:  92 02 60 c0  add  %o1, 0xc0, %o1
a00a2614:  40 00 13 70  call  0xa00a73d4
a00a2618:  90 10 20 0e  mov  0xe, %o0
a00a261c:  80 8e 20 08  btst  8, %i0
a00a2620:  02 80 00 0d  be  0xa00a2654
a00a2624:  80 8e 20 10  btst  0x10, %i0
a00a2628:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a00a262c:  a0 14 23 00  or  %l0, 0x300, %l0	! 0xa807db00
a00a2630:  d2 04 20 24  ld  [ %l0 + 0x24 ], %o1
a00a2634:  92 02 60 c0  add  %o1, 0xc0, %o1
a00a2638:  40 00 13 67  call  0xa00a73d4
a00a263c:  90 10 20 0f  mov  0xf, %o0
a00a2640:  d2 04 20 58  ld  [ %l0 + 0x58 ], %o1
a00a2644:  92 02 60 c0  add  %o1, 0xc0, %o1
a00a2648:  40 00 13 63  call  0xa00a73d4
a00a264c:  90 10 20 0f  mov  0xf, %o0
a00a2650:  80 8e 20 10  btst  0x10, %i0
a00a2654:  02 80 00 0b  be  0xa00a2680
a00a2658:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a00a265c:  a0 14 23 00  or  %l0, 0x300, %l0	! 0xa807db00
a00a2660:  d2 04 20 24  ld  [ %l0 + 0x24 ], %o1
a00a2664:  92 02 60 c0  add  %o1, 0xc0, %o1
a00a2668:  40 00 13 5b  call  0xa00a73d4
a00a266c:  90 10 20 0b  mov  0xb, %o0
a00a2670:  f2 04 20 58  ld  [ %l0 + 0x58 ], %i1
a00a2674:  b2 06 60 c0  add  %i1, 0xc0, %i1
a00a2678:  40 00 13 57  call  0xa00a73d4
a00a267c:  91 e8 20 0b  restore  %g0, 0xb, %o0
a00a2680:  01 00 00 00  nop
a00a2684:  81 c7 e0 08  ret
a00a2688:  81 e8 00 00  restore
