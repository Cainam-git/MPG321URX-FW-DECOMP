# leon2m FUN_a00c762c 0xa00c762c-0xa00c7818 (492 bytes)
a00c762c:  9d e3 bf 98  save  %sp, -104, %sp
a00c7630:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c7634:  80 a4 20 02  cmp  %l0, 2
a00c7638:  02 80 00 56  be  0xa00c7790
a00c763c:  80 a4 20 03  cmp  %l0, 3
a00c7640:  02 80 00 57  be  0xa00c779c
a00c7644:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c7648:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c764c:  94 08 60 ff  and  %g1, 0xff, %o2
a00c7650:  9a 02 bf d0  add  %o2, -48, %o5
a00c7654:  82 0b 60 ff  and  %o5, 0xff, %g1
a00c7658:  80 a0 60 ff  cmp  %g1, 0xff
a00c765c:  02 80 00 6d  be  0xa00c7810
a00c7660:  b0 10 20 ff  mov  0xff, %i0
a00c7664:  80 a0 60 05  cmp  %g1, 5
a00c7668:  18 80 00 6a  bgu  0xa00c7810
a00c766c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c7670:  40 00 32 85  call  0xa00d4084
a00c7674:  da 2a e2 d9  stb  %o5, [ %o3 + 0x2d9 ]	! 0xa802d2d9
a00c7678:  40 00 34 c8  call  0xa00d4998
a00c767c:  01 00 00 00  nop
a00c7680:  7f ff c4 93  call  0xa00b88cc
a00c7684:  01 00 00 00  nop
a00c7688:  80 a4 20 02  cmp  %l0, 2
a00c768c:  02 80 00 24  be  0xa00c771c
a00c7690:  80 a4 20 03  cmp  %l0, 3
a00c7694:  02 80 00 45  be  0xa00c77a8
a00c7698:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c769c:  94 12 e0 78  or  %o3, 0x78, %o2	! 0xa802d078
a00c76a0:  b0 10 20 30  mov  0x30, %i0
a00c76a4:  98 10 20 35  mov  0x35, %o4
a00c76a8:  92 10 20 36  mov  0x36, %o1
a00c76ac:  82 10 20 2b  mov  0x2b, %g1
a00c76b0:  90 10 20 0d  mov  0xd, %o0
a00c76b4:  d8 2a e0 78  stb  %o4, [ %o3 + 0x78 ]
a00c76b8:  d2 2a a0 01  stb  %o1, [ %o2 + 1 ]
a00c76bc:  f0 2a a0 03  stb  %i0, [ %o2 + 3 ]
a00c76c0:  c2 2a a0 04  stb  %g1, [ %o2 + 4 ]
a00c76c4:  d0 2a a0 05  stb  %o0, [ %o2 + 5 ]
a00c76c8:  80 a4 20 02  cmp  %l0, 2
a00c76cc:  02 80 00 21  be  0xa00c7750
a00c76d0:  f0 2a a0 02  stb  %i0, [ %o2 + 2 ]
a00c76d4:  80 a4 20 03  cmp  %l0, 3
a00c76d8:  02 80 00 41  be  0xa00c77dc
a00c76dc:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c76e0:  92 12 e0 d0  or  %o3, 0xd0, %o1	! 0xa802d0d0
a00c76e4:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c76e8:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]	! 0xa802b09c
a00c76ec:  c0 2a e0 d0  clrb  [ %o3 + 0xd0 ]
a00c76f0:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c76f4:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c76f8:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c76fc:  80 a4 20 02  cmp  %l0, 2
a00c7700:  02 80 00 1d  be  0xa00c7774
a00c7704:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c7708:  80 a4 20 03  cmp  %l0, 3
a00c770c:  12 80 00 1d  bne  0xa00c7780
a00c7710:  90 10 00 10  mov  %l0, %o0
a00c7714:  10 80 00 3c  b  0xa00c7804
a00c7718:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c771c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c7720:  98 12 21 28  or  %o0, 0x128, %o4	! 0xa802d128
a00c7724:  9e 10 20 30  mov  0x30, %o7
a00c7728:  82 10 20 35  mov  0x35, %g1
a00c772c:  b0 10 20 0d  mov  0xd, %i0
a00c7730:  a0 10 20 36  mov  0x36, %l0
a00c7734:  9a 10 20 2b  mov  0x2b, %o5
a00c7738:  c2 2a 21 28  stb  %g1, [ %o0 + 0x128 ]
a00c773c:  f0 2b 20 05  stb  %i0, [ %o4 + 5 ]
a00c7740:  e0 2b 20 01  stb  %l0, [ %o4 + 1 ]
a00c7744:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00c7748:  da 2b 20 04  stb  %o5, [ %o4 + 4 ]
a00c774c:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00c7750:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c7754:  94 13 e0 40  or  %o7, 0x40, %o2	! 0xa802d040
a00c7758:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c775c:  c0 2b 60 9a  clrb  [ %o5 + 0x9a ]	! 0xa802b09a
a00c7760:  c0 2b e0 40  clrb  [ %o7 + 0x40 ]
a00c7764:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c7768:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c776c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c7770:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c7774:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c7778:  94 13 21 28  or  %o4, 0x128, %o2	! 0xa802d128
a00c777c:  90 10 20 02  mov  2, %o0
a00c7780:  40 02 04 1a  call  0xa01487e8
a00c7784:  92 10 20 06  mov  6, %o1
a00c7788:  10 80 00 22  b  0xa00c7810
a00c778c:  b0 10 20 00  clr  %i0
a00c7790:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c7794:  10 bf ff ae  b  0xa00c764c
a00c7798:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c779c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c77a0:  10 bf ff ab  b  0xa00c764c
a00c77a4:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c77a8:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c77ac:  92 13 61 08  or  %o5, 0x108, %o1	! 0xa802d108
a00c77b0:  94 10 20 30  mov  0x30, %o2
a00c77b4:  a0 10 20 35  mov  0x35, %l0
a00c77b8:  9e 10 20 0d  mov  0xd, %o7
a00c77bc:  98 10 20 36  mov  0x36, %o4
a00c77c0:  96 10 20 2b  mov  0x2b, %o3
a00c77c4:  e0 2b 61 08  stb  %l0, [ %o5 + 0x108 ]
a00c77c8:  de 2a 60 05  stb  %o7, [ %o1 + 5 ]
a00c77cc:  d8 2a 60 01  stb  %o4, [ %o1 + 1 ]
a00c77d0:  d4 2a 60 03  stb  %o2, [ %o1 + 3 ]
a00c77d4:  d6 2a 60 04  stb  %o3, [ %o1 + 4 ]
a00c77d8:  d4 2a 60 02  stb  %o2, [ %o1 + 2 ]
a00c77dc:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c77e0:  a0 16 20 98  or  %i0, 0x98, %l0	! 0xa802d098
a00c77e4:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00c77e8:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]	! 0xa802b098
a00c77ec:  c0 2e 20 98  clrb  [ %i0 + 0x98 ]
a00c77f0:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00c77f4:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a00c77f8:  c0 2c 20 07  clrb  [ %l0 + 7 ]
a00c77fc:  c0 2c 20 0a  clrb  [ %l0 + 0xa ]
a00c7800:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c7804:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c7808:  10 bf ff de  b  0xa00c7780
a00c780c:  90 10 20 03  mov  3, %o0
a00c7810:  81 c7 e0 08  ret
a00c7814:  81 e8 00 00  restore
