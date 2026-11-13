# leon2m FUN_a00cb618 0xa00cb618-0xa00cb7f4 (476 bytes)
a00cb618:  9d e3 bf 98  save  %sp, -104, %sp
a00cb61c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00cb620:  80 a4 20 02  cmp  %l0, 2
a00cb624:  02 80 00 52  be  0xa00cb76c
a00cb628:  80 a4 20 03  cmp  %l0, 3
a00cb62c:  02 80 00 53  be  0xa00cb778
a00cb630:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cb634:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00cb638:  94 08 60 ff  and  %g1, 0xff, %o2
a00cb63c:  98 02 bf d0  add  %o2, -48, %o4
a00cb640:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00cb644:  80 a3 60 01  cmp  %o5, 1
a00cb648:  18 80 00 69  bgu  0xa00cb7ec
a00cb64c:  b0 10 20 ff  mov  0xff, %i0
a00cb650:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00cb654:  40 00 3d 5d  call  0xa00dabc8
a00cb658:  d8 2a e0 7a  stb  %o4, [ %o3 + 0x7a ]	! 0xa802d47a
a00cb65c:  7f ff b4 9c  call  0xa00b88cc
a00cb660:  01 00 00 00  nop
a00cb664:  80 a4 20 02  cmp  %l0, 2
a00cb668:  02 80 00 24  be  0xa00cb6f8
a00cb66c:  80 a4 20 03  cmp  %l0, 3
a00cb670:  02 80 00 45  be  0xa00cb784
a00cb674:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00cb678:  94 13 60 78  or  %o5, 0x78, %o2	! 0xa802d078
a00cb67c:  90 10 20 30  mov  0x30, %o0
a00cb680:  96 10 20 35  mov  0x35, %o3
a00cb684:  98 10 20 36  mov  0x36, %o4
a00cb688:  92 10 20 2b  mov  0x2b, %o1
a00cb68c:  82 10 20 0d  mov  0xd, %g1
a00cb690:  d6 2b 60 78  stb  %o3, [ %o5 + 0x78 ]
a00cb694:  d8 2a a0 01  stb  %o4, [ %o2 + 1 ]
a00cb698:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00cb69c:  d2 2a a0 04  stb  %o1, [ %o2 + 4 ]
a00cb6a0:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00cb6a4:  80 a4 20 02  cmp  %l0, 2
a00cb6a8:  02 80 00 21  be  0xa00cb72c
a00cb6ac:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00cb6b0:  80 a4 20 03  cmp  %l0, 3
a00cb6b4:  02 80 00 41  be  0xa00cb7b8
a00cb6b8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cb6bc:  92 13 20 d0  or  %o4, 0xd0, %o1	! 0xa802d0d0
a00cb6c0:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00cb6c4:  c0 2b 60 9c  clrb  [ %o5 + 0x9c ]	! 0xa802b09c
a00cb6c8:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00cb6cc:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00cb6d0:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00cb6d4:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00cb6d8:  80 a4 20 02  cmp  %l0, 2
a00cb6dc:  02 80 00 1d  be  0xa00cb750
a00cb6e0:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00cb6e4:  80 a4 20 03  cmp  %l0, 3
a00cb6e8:  12 80 00 1d  bne  0xa00cb75c
a00cb6ec:  90 10 00 10  mov  %l0, %o0
a00cb6f0:  10 80 00 3c  b  0xa00cb7e0
a00cb6f4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cb6f8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cb6fc:  98 12 21 28  or  %o0, 0x128, %o4	! 0xa802d128
a00cb700:  9e 10 20 30  mov  0x30, %o7
a00cb704:  92 10 20 35  mov  0x35, %o1
a00cb708:  82 10 20 0d  mov  0xd, %g1
a00cb70c:  b0 10 20 36  mov  0x36, %i0
a00cb710:  a0 10 20 2b  mov  0x2b, %l0
a00cb714:  d2 2a 21 28  stb  %o1, [ %o0 + 0x128 ]
a00cb718:  c2 2b 20 05  stb  %g1, [ %o4 + 5 ]
a00cb71c:  f0 2b 20 01  stb  %i0, [ %o4 + 1 ]
a00cb720:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00cb724:  e0 2b 20 04  stb  %l0, [ %o4 + 4 ]
a00cb728:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00cb72c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00cb730:  94 13 e0 40  or  %o7, 0x40, %o2	! 0xa802d040
a00cb734:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00cb738:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00cb73c:  c0 2b e0 40  clrb  [ %o7 + 0x40 ]
a00cb740:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00cb744:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00cb748:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00cb74c:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00cb750:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cb754:  94 12 e1 28  or  %o3, 0x128, %o2	! 0xa802d128
a00cb758:  90 10 20 02  mov  2, %o0
a00cb75c:  40 01 f4 23  call  0xa01487e8
a00cb760:  92 10 20 06  mov  6, %o1
a00cb764:  10 80 00 22  b  0xa00cb7ec
a00cb768:  b0 10 20 00  clr  %i0
a00cb76c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cb770:  10 bf ff b2  b  0xa00cb638
a00cb774:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00cb778:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cb77c:  10 bf ff af  b  0xa00cb638
a00cb780:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00cb784:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00cb788:  98 14 21 08  or  %l0, 0x108, %o4	! 0xa802d108
a00cb78c:  94 10 20 30  mov  0x30, %o2
a00cb790:  b0 10 20 35  mov  0x35, %i0
a00cb794:  9e 10 20 0d  mov  0xd, %o7
a00cb798:  96 10 20 36  mov  0x36, %o3
a00cb79c:  9a 10 20 2b  mov  0x2b, %o5
a00cb7a0:  f0 2c 21 08  stb  %i0, [ %l0 + 0x108 ]
a00cb7a4:  de 2b 20 05  stb  %o7, [ %o4 + 5 ]
a00cb7a8:  d6 2b 20 01  stb  %o3, [ %o4 + 1 ]
a00cb7ac:  d4 2b 20 03  stb  %o2, [ %o4 + 3 ]
a00cb7b0:  da 2b 20 04  stb  %o5, [ %o4 + 4 ]
a00cb7b4:  d4 2b 20 02  stb  %o2, [ %o4 + 2 ]
a00cb7b8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cb7bc:  b0 12 20 98  or  %o0, 0x98, %i0	! 0xa802d098
a00cb7c0:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00cb7c4:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00cb7c8:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00cb7cc:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00cb7d0:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00cb7d4:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00cb7d8:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00cb7dc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cb7e0:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00cb7e4:  10 bf ff de  b  0xa00cb75c
a00cb7e8:  90 10 20 03  mov  3, %o0
a00cb7ec:  81 c7 e0 08  ret
a00cb7f0:  81 e8 00 00  restore
