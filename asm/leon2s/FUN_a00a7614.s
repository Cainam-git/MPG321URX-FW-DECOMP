# leon2s FUN_a00a7614 0xa00a7614-0xa00a7718 (260 bytes)
a00a7614:  9d e3 bf 98  save  %sp, -104, %sp
a00a7618:  03 33 c0 f4  sethi  %hi(0xcf03d000), %g1
a00a761c:  90 10 60 14  or  %g1, 0x14, %o0	! 0xcf03d014
a00a7620:  9a 10 60 18  or  %g1, 0x18, %o5
a00a7624:  96 10 60 1c  or  %g1, 0x1c, %o3
a00a7628:  94 10 60 20  or  %g1, 0x20, %o2
a00a762c:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00a7630:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a00a7634:  de 02 00 00  ld  [ %o0 ], %o7
a00a7638:  82 0e 40 01  and  %i1, %g1, %g1
a00a763c:  f6 03 40 00  ld  [ %o5 ], %i3
a00a7640:  83 38 60 08  sra  %g1, 8, %g1
a00a7644:  ba 10 20 01  mov  1, %i5
a00a7648:  f8 02 c0 00  ld  [ %o3 ], %i4
a00a764c:  bb 2f 40 01  sll  %i5, %g1, %i5
a00a7650:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a7654:  c2 02 80 00  ld  [ %o2 ], %g1
a00a7658:  98 10 00 1b  mov  %i3, %o4
a00a765c:  92 10 00 1c  mov  %i4, %o1
a00a7660:  80 a6 20 01  cmp  %i0, 1
a00a7664:  18 80 00 2b  bgu  0xa00a7710
a00a7668:  a0 10 00 01  mov  %g1, %l0
a00a766c:  83 37 60 08  srl  %i5, 8, %g1
a00a7670:  b6 0f 60 ff  and  %i5, 0xff, %i3
a00a7674:  80 a6 20 00  cmp  %i0, 0
a00a7678:  02 80 00 08  be  0xa00a7698
a00a767c:  82 08 60 01  and  %g1, 1, %g1
a00a7680:  83 37 60 08  srl  %i5, 8, %g1
a00a7684:  80 a6 20 01  cmp  %i0, 1
a00a7688:  02 80 00 08  be  0xa00a76a8
a00a768c:  82 08 60 01  and  %g1, 1, %g1
a00a7690:  10 80 00 09  b  0xa00a76b4
a00a7694:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7698:  f6 22 00 00  st  %i3, [ %o0 ]
a00a769c:  c2 23 40 00  st  %g1, [ %o5 ]
a00a76a0:  10 80 00 05  b  0xa00a76b4
a00a76a4:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a76a8:  f6 22 c0 00  st  %i3, [ %o3 ]
a00a76ac:  c2 22 80 00  st  %g1, [ %o2 ]
a00a76b0:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a76b4:  ba 06 00 18  add  %i0, %i0, %i5
a00a76b8:  82 10 61 84  or  %g1, 0x184, %g1
a00a76bc:  c2 10 40 1d  lduh  [ %g1 + %i5 ], %g1
a00a76c0:  ba 0e 60 ff  and  %i1, 0xff, %i5
a00a76c4:  82 00 40 1d  add  %g1, %i5, %g1
a00a76c8:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a76cc:  83 28 60 02  sll  %g1, 2, %g1
a00a76d0:  82 10 40 1d  or  %g1, %i5, %g1
a00a76d4:  b8 0e a0 ff  and  %i2, 0xff, %i4
a00a76d8:  f8 20 40 00  st  %i4, [ %g1 ]
a00a76dc:  3b 33 c0 f4  sethi  %hi(0xcf03d000), %i5
a00a76e0:  82 17 60 14  or  %i5, 0x14, %g1	! 0xcf03d014
a00a76e4:  b8 0b e0 ff  and  %o7, 0xff, %i4
a00a76e8:  f8 20 40 00  st  %i4, [ %g1 ]
a00a76ec:  82 17 60 18  or  %i5, 0x18, %g1
a00a76f0:  b8 0b 20 ff  and  %o4, 0xff, %i4
a00a76f4:  f8 20 40 00  st  %i4, [ %g1 ]
a00a76f8:  82 17 60 1c  or  %i5, 0x1c, %g1
a00a76fc:  b8 0a 60 ff  and  %o1, 0xff, %i4
a00a7700:  f8 20 40 00  st  %i4, [ %g1 ]
a00a7704:  ba 17 60 20  or  %i5, 0x20, %i5
a00a7708:  82 0c 20 ff  and  %l0, 0xff, %g1
a00a770c:  c2 27 40 00  st  %g1, [ %i5 ]
a00a7710:  81 c7 e0 08  ret
a00a7714:  81 e8 00 00  restore
