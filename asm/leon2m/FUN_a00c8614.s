# leon2m FUN_a00c8614 0xa00c8614-0xa00c8818 (516 bytes)
a00c8614:  9d e3 bf 98  save  %sp, -104, %sp
a00c8618:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c861c:  80 a4 20 02  cmp  %l0, 2
a00c8620:  02 80 00 5c  be  0xa00c8790
a00c8624:  80 a4 20 03  cmp  %l0, 3
a00c8628:  02 80 00 5d  be  0xa00c879c
a00c862c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c8630:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c8634:  96 08 60 ff  and  %g1, 0xff, %o3
a00c8638:  94 02 ff d0  add  %o3, -48, %o2
a00c863c:  90 0a a0 ff  and  %o2, 0xff, %o0
a00c8640:  80 a2 20 03  cmp  %o0, 3
a00c8644:  18 80 00 73  bgu  0xa00c8810
a00c8648:  b0 10 20 ff  mov  0xff, %i0
a00c864c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c8650:  a2 13 22 90  or  %o4, 0x290, %l1	! 0xa802d290
a00c8654:  da 0c 60 1f  ldub  [ %l1 + 0x1f ], %o5
a00c8658:  80 a3 60 00  cmp  %o5, 0
a00c865c:  02 80 00 6d  be  0xa00c8810
a00c8660:  01 00 00 00  nop
a00c8664:  40 01 ef ce  call  0xa014459c
a00c8668:  01 00 00 00  nop
a00c866c:  d0 2c 60 20  stb  %o0, [ %l1 + 0x20 ]
a00c8670:  40 00 34 b2  call  0xa00d5938
a00c8674:  90 10 20 01  mov  1, %o0
a00c8678:  40 00 35 98  call  0xa00d5cd8
a00c867c:  01 00 00 00  nop
a00c8680:  7f ff c0 93  call  0xa00b88cc
a00c8684:  01 00 00 00  nop
a00c8688:  80 a4 20 02  cmp  %l0, 2
a00c868c:  02 80 00 24  be  0xa00c871c
a00c8690:  80 a4 20 03  cmp  %l0, 3
a00c8694:  02 80 00 45  be  0xa00c87a8
a00c8698:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c869c:  94 13 20 78  or  %o4, 0x78, %o2	! 0xa802d078
a00c86a0:  b0 10 20 30  mov  0x30, %i0
a00c86a4:  96 10 20 35  mov  0x35, %o3
a00c86a8:  92 10 20 36  mov  0x36, %o1
a00c86ac:  90 10 20 2b  mov  0x2b, %o0
a00c86b0:  82 10 20 0d  mov  0xd, %g1
a00c86b4:  d6 2b 20 78  stb  %o3, [ %o4 + 0x78 ]
a00c86b8:  d2 2a a0 01  stb  %o1, [ %o2 + 1 ]
a00c86bc:  f0 2a a0 03  stb  %i0, [ %o2 + 3 ]
a00c86c0:  d0 2a a0 04  stb  %o0, [ %o2 + 4 ]
a00c86c4:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00c86c8:  80 a4 20 02  cmp  %l0, 2
a00c86cc:  02 80 00 21  be  0xa00c8750
a00c86d0:  f0 2a a0 02  stb  %i0, [ %o2 + 2 ]
a00c86d4:  80 a4 20 03  cmp  %l0, 3
a00c86d8:  02 80 00 41  be  0xa00c87dc
a00c86dc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c86e0:  90 12 60 d0  or  %o1, 0xd0, %o0	! 0xa802d0d0
a00c86e4:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c86e8:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]	! 0xa802b09c
a00c86ec:  c0 2a 60 d0  clrb  [ %o1 + 0xd0 ]
a00c86f0:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c86f4:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c86f8:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c86fc:  80 a4 20 02  cmp  %l0, 2
a00c8700:  02 80 00 1d  be  0xa00c8774
a00c8704:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c8708:  80 a4 20 03  cmp  %l0, 3
a00c870c:  12 80 00 1d  bne  0xa00c8780
a00c8710:  90 10 00 10  mov  %l0, %o0
a00c8714:  10 80 00 3c  b  0xa00c8804
a00c8718:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c871c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c8720:  9e 12 21 28  or  %o0, 0x128, %o7	! 0xa802d128
a00c8724:  a0 10 20 30  mov  0x30, %l0
a00c8728:  92 10 20 35  mov  0x35, %o1
a00c872c:  82 10 20 0d  mov  0xd, %g1
a00c8730:  b0 10 20 36  mov  0x36, %i0
a00c8734:  a2 10 20 2b  mov  0x2b, %l1
a00c8738:  d2 2a 21 28  stb  %o1, [ %o0 + 0x128 ]
a00c873c:  c2 2b e0 05  stb  %g1, [ %o7 + 5 ]
a00c8740:  f0 2b e0 01  stb  %i0, [ %o7 + 1 ]
a00c8744:  e0 2b e0 03  stb  %l0, [ %o7 + 3 ]
a00c8748:  e2 2b e0 04  stb  %l1, [ %o7 + 4 ]
a00c874c:  e0 2b e0 02  stb  %l0, [ %o7 + 2 ]
a00c8750:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c8754:  94 13 60 40  or  %o5, 0x40, %o2	! 0xa802d040
a00c8758:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00c875c:  c0 2b e0 9a  clrb  [ %o7 + 0x9a ]	! 0xa802b09a
a00c8760:  c0 2b 60 40  clrb  [ %o5 + 0x40 ]
a00c8764:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c8768:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c876c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c8770:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c8774:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c8778:  94 13 21 28  or  %o4, 0x128, %o2	! 0xa802d128
a00c877c:  90 10 20 02  mov  2, %o0
a00c8780:  40 02 00 1a  call  0xa01487e8
a00c8784:  92 10 20 06  mov  6, %o1
a00c8788:  10 80 00 22  b  0xa00c8810
a00c878c:  b0 10 20 00  clr  %i0
a00c8790:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c8794:  10 bf ff a8  b  0xa00c8634
a00c8798:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c879c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c87a0:  10 bf ff a5  b  0xa00c8634
a00c87a4:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c87a8:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c87ac:  98 14 21 08  or  %l0, 0x108, %o4	! 0xa802d108
a00c87b0:  94 10 20 30  mov  0x30, %o2
a00c87b4:  a2 10 20 35  mov  0x35, %l1
a00c87b8:  9e 10 20 0d  mov  0xd, %o7
a00c87bc:  9a 10 20 36  mov  0x36, %o5
a00c87c0:  96 10 20 2b  mov  0x2b, %o3
a00c87c4:  e2 2c 21 08  stb  %l1, [ %l0 + 0x108 ]
a00c87c8:  de 2b 20 05  stb  %o7, [ %o4 + 5 ]
a00c87cc:  da 2b 20 01  stb  %o5, [ %o4 + 1 ]
a00c87d0:  d4 2b 20 03  stb  %o2, [ %o4 + 3 ]
a00c87d4:  d6 2b 20 04  stb  %o3, [ %o4 + 4 ]
a00c87d8:  d4 2b 20 02  stb  %o2, [ %o4 + 2 ]
a00c87dc:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c87e0:  a0 14 60 98  or  %l1, 0x98, %l0	! 0xa802d098
a00c87e4:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00c87e8:  c0 2e 20 98  clrb  [ %i0 + 0x98 ]	! 0xa802b098
a00c87ec:  c0 2c 60 98  clrb  [ %l1 + 0x98 ]
a00c87f0:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00c87f4:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a00c87f8:  c0 2c 20 07  clrb  [ %l0 + 7 ]
a00c87fc:  c0 2c 20 0a  clrb  [ %l0 + 0xa ]
a00c8800:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c8804:  94 12 e1 08  or  %o3, 0x108, %o2	! 0xa802d108
a00c8808:  10 bf ff de  b  0xa00c8780
a00c880c:  90 10 20 03  mov  3, %o0
a00c8810:  81 c7 e0 08  ret
a00c8814:  81 e8 00 00  restore
