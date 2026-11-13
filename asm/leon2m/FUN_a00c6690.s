# leon2m FUN_a00c6690 0xa00c6690-0xa00c68d8 (584 bytes)
a00c6690:  9d e3 bf 98  save  %sp, -104, %sp
a00c6694:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c6698:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c669c:  80 a4 20 02  cmp  %l0, 2
a00c66a0:  02 80 00 08  be  0xa00c66c0
a00c66a4:  82 10 60 40  or  %g1, 0x40, %g1
a00c66a8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c66ac:  80 a4 20 03  cmp  %l0, 3
a00c66b0:  02 80 00 04  be  0xa00c66c0
a00c66b4:  82 12 20 98  or  %o0, 0x98, %g1
a00c66b8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c66bc:  82 12 60 d0  or  %o1, 0xd0, %g1	! 0xa802d0d0
a00c66c0:  de 08 60 07  ldub  [ %g1 + 7 ], %o7
a00c66c4:  94 03 ff d0  add  %o7, -48, %o2
a00c66c8:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00c66cc:  80 a3 60 01  cmp  %o5, 1
a00c66d0:  d6 08 60 09  ldub  [ %g1 + 9 ], %o3
a00c66d4:  d8 08 60 08  ldub  [ %g1 + 8 ], %o4
a00c66d8:  18 80 00 07  bgu  0xa00c66f4
a00c66dc:  9a 10 20 ff  mov  0xff, %o5
a00c66e0:  98 03 3f d0  add  %o4, -48, %o4
a00c66e4:  b0 0b 20 ff  and  %o4, 0xff, %i0
a00c66e8:  80 a6 20 09  cmp  %i0, 9
a00c66ec:  28 80 00 33  bleu,a   0xa00c67b8
a00c66f0:  96 02 ff d0  add  %o3, -48, %o3
a00c66f4:  80 a3 60 ff  cmp  %o5, 0xff
a00c66f8:  02 80 00 76  be  0xa00c68d0
a00c66fc:  b0 10 20 ff  mov  0xff, %i0
a00c6700:  80 a3 60 64  cmp  %o5, 0x64
a00c6704:  18 80 00 73  bgu  0xa00c68d0
a00c6708:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c670c:  40 00 45 b5  call  0xa00d7de0
a00c6710:  da 2a e2 9a  stb  %o5, [ %o3 + 0x29a ]	! 0xa802d29a
a00c6714:  40 00 38 a1  call  0xa00d4998
a00c6718:  01 00 00 00  nop
a00c671c:  7f ff c8 6c  call  0xa00b88cc
a00c6720:  01 00 00 00  nop
a00c6724:  80 a4 20 02  cmp  %l0, 2
a00c6728:  02 80 00 33  be  0xa00c67f4
a00c672c:  80 a4 20 03  cmp  %l0, 3
a00c6730:  02 80 00 4e  be  0xa00c6868
a00c6734:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c6738:  94 12 e0 78  or  %o3, 0x78, %o2	! 0xa802d078
a00c673c:  9e 10 20 30  mov  0x30, %o7
a00c6740:  82 10 20 35  mov  0x35, %g1
a00c6744:  90 10 20 36  mov  0x36, %o0
a00c6748:  b0 10 20 2b  mov  0x2b, %i0
a00c674c:  9a 10 20 0d  mov  0xd, %o5
a00c6750:  c2 2a e0 78  stb  %g1, [ %o3 + 0x78 ]
a00c6754:  d0 2a a0 01  stb  %o0, [ %o2 + 1 ]
a00c6758:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00c675c:  f0 2a a0 04  stb  %i0, [ %o2 + 4 ]
a00c6760:  da 2a a0 05  stb  %o5, [ %o2 + 5 ]
a00c6764:  80 a4 20 02  cmp  %l0, 2
a00c6768:  02 80 00 30  be  0xa00c6828
a00c676c:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00c6770:  80 a4 20 03  cmp  %l0, 3
a00c6774:  02 80 00 4a  be  0xa00c689c
a00c6778:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c677c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c6780:  b0 12 20 d0  or  %o0, 0xd0, %i0	! 0xa802d0d0
a00c6784:  c0 2a e0 9c  clrb  [ %o3 + 0x9c ]
a00c6788:  c0 2a 20 d0  clrb  [ %o0 + 0xd0 ]
a00c678c:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00c6790:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00c6794:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00c6798:  80 a4 20 02  cmp  %l0, 2
a00c679c:  02 80 00 2c  be  0xa00c684c
a00c67a0:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00c67a4:  80 a4 20 03  cmp  %l0, 3
a00c67a8:  12 80 00 2c  bne  0xa00c6858
a00c67ac:  90 10 00 10  mov  %l0, %o0
a00c67b0:  10 80 00 45  b  0xa00c68c4
a00c67b4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c67b8:  82 0a e0 ff  and  %o3, 0xff, %g1
a00c67bc:  80 a0 60 09  cmp  %g1, 9
a00c67c0:  18 bf ff ce  bgu  0xa00c66f8
a00c67c4:  80 a3 60 ff  cmp  %o5, 0xff
a00c67c8:  90 0b 20 ff  and  %o4, 0xff, %o0
a00c67cc:  83 2a 20 02  sll  %o0, 2, %g1
a00c67d0:  9e 00 40 08  add  %g1, %o0, %o7
a00c67d4:  b0 0a a0 ff  and  %o2, 0xff, %i0
a00c67d8:  9a 03 c0 0f  add  %o7, %o7, %o5
a00c67dc:  92 5e 20 64  smul  %i0, 0x64, %o1
a00c67e0:  90 02 40 0d  add  %o1, %o5, %o0
a00c67e4:  98 0a e0 ff  and  %o3, 0xff, %o4
a00c67e8:  94 02 00 0c  add  %o0, %o4, %o2
a00c67ec:  10 bf ff c2  b  0xa00c66f4
a00c67f0:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00c67f4:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c67f8:  a0 13 e1 28  or  %o7, 0x128, %l0	! 0xa802d128
a00c67fc:  94 10 20 30  mov  0x30, %o2
a00c6800:  b0 10 20 35  mov  0x35, %i0
a00c6804:  9a 10 20 0d  mov  0xd, %o5
a00c6808:  92 10 20 36  mov  0x36, %o1
a00c680c:  98 10 20 2b  mov  0x2b, %o4
a00c6810:  f0 2b e1 28  stb  %i0, [ %o7 + 0x128 ]
a00c6814:  da 2c 20 05  stb  %o5, [ %l0 + 5 ]
a00c6818:  d2 2c 20 01  stb  %o1, [ %l0 + 1 ]
a00c681c:  d4 2c 20 03  stb  %o2, [ %l0 + 3 ]
a00c6820:  d8 2c 20 04  stb  %o4, [ %l0 + 4 ]
a00c6824:  d4 2c 20 02  stb  %o2, [ %l0 + 2 ]
a00c6828:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c682c:  a0 12 a0 40  or  %o2, 0x40, %l0	! 0xa802d040
a00c6830:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00c6834:  c0 2b 20 9a  clrb  [ %o4 + 0x9a ]	! 0xa802b09a
a00c6838:  c0 2a a0 40  clrb  [ %o2 + 0x40 ]
a00c683c:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00c6840:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a00c6844:  c0 2c 20 07  clrb  [ %l0 + 7 ]
a00c6848:  c0 2c 20 0a  clrb  [ %l0 + 0xa ]
a00c684c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c6850:  94 10 61 28  or  %g1, 0x128, %o2	! 0xa802d128
a00c6854:  90 10 20 02  mov  2, %o0
a00c6858:  40 02 07 e4  call  0xa01487e8
a00c685c:  92 10 20 06  mov  6, %o1
a00c6860:  10 80 00 1c  b  0xa00c68d0
a00c6864:  b0 10 20 00  clr  %i0
a00c6868:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c686c:  90 13 21 08  or  %o4, 0x108, %o0	! 0xa802d108
a00c6870:  a0 10 20 30  mov  0x30, %l0
a00c6874:  92 10 20 35  mov  0x35, %o1
a00c6878:  94 10 20 0d  mov  0xd, %o2
a00c687c:  96 10 20 36  mov  0x36, %o3
a00c6880:  82 10 20 2b  mov  0x2b, %g1
a00c6884:  d2 2b 21 08  stb  %o1, [ %o4 + 0x108 ]
a00c6888:  d4 2a 20 05  stb  %o2, [ %o0 + 5 ]
a00c688c:  d6 2a 20 01  stb  %o3, [ %o0 + 1 ]
a00c6890:  e0 2a 20 03  stb  %l0, [ %o0 + 3 ]
a00c6894:  c2 2a 20 04  stb  %g1, [ %o0 + 4 ]
a00c6898:  e0 2a 20 02  stb  %l0, [ %o0 + 2 ]
a00c689c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c68a0:  92 13 e0 98  or  %o7, 0x98, %o1	! 0xa802d098
a00c68a4:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c68a8:  c0 2b 60 98  clrb  [ %o5 + 0x98 ]	! 0xa802b098
a00c68ac:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]
a00c68b0:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c68b4:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c68b8:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c68bc:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c68c0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c68c4:  94 14 21 08  or  %l0, 0x108, %o2	! 0xa802d108
a00c68c8:  10 bf ff e4  b  0xa00c6858
a00c68cc:  90 10 20 03  mov  3, %o0
a00c68d0:  81 c7 e0 08  ret
a00c68d4:  81 e8 00 00  restore
