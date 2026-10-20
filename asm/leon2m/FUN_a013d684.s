# leon2m FUN_a013d684 0xa013d684-0xa013d918 (660 bytes)
a013d684:  9d e3 bf 98  save  %sp, -104, %sp
a013d688:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013d68c:  80 a6 20 00  cmp  %i0, 0
a013d690:  12 80 00 07  bne  0xa013d6ac
a013d694:  92 10 3f d0  mov  -48, %o1
a013d698:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a013d69c:  da 08 63 d3  ldub  [ %g1 + 0x3d3 ], %o5	! 0xa802e3d3
a013d6a0:  80 a3 60 00  cmp  %o5, 0
a013d6a4:  32 80 00 65  bne,a   0xa013d838
a013d6a8:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a013d6ac:  b5 2e 20 04  sll  %i0, 4, %i2
a013d6b0:  90 26 80 18  sub  %i2, %i0, %o0
a013d6b4:  99 2a 20 03  sll  %o0, 3, %o4
a013d6b8:  35 2a 00 b7  sethi  %hi(0xa802dc00), %i2
a013d6bc:  90 16 a3 30  or  %i2, 0x330, %o0	! 0xa802df30
a013d6c0:  96 03 00 08  add  %o4, %o0, %o3
a013d6c4:  da 12 e0 4c  lduh  [ %o3 + 0x4c ], %o5
a013d6c8:  95 2b 60 04  sll  %o5, 4, %o2
a013d6cc:  82 22 80 0d  sub  %o2, %o5, %g1
a013d6d0:  33 14 7a e1  sethi  %hi(0x51eb8400), %i1
a013d6d4:  a3 28 60 03  sll  %g1, 3, %l1
a013d6d8:  98 16 61 1f  or  %i1, 0x11f, %o4
a013d6dc:  80 54 40 0c  umul  %l1, %o4, %g0
a013d6e0:  a1 40 00 00  rd  %y, %l0
a013d6e4:  9f 34 20 05  srl  %l0, 5, %o7
a013d6e8:  de 32 e0 48  sth  %o7, [ %o3 + 0x48 ]
a013d6ec:  80 a6 20 01  cmp  %i0, 1
a013d6f0:  02 80 00 49  be  0xa013d814
a013d6f4:  d4 12 e0 4c  lduh  [ %o3 + 0x4c ], %o2
a013d6f8:  80 a6 20 00  cmp  %i0, 0
a013d6fc:  32 80 00 02  bne,a   0xa013d704
a013d700:  92 10 3f e0  mov  -32, %o1
a013d704:  9f 2a a0 10  sll  %o2, 0x10, %o7
a013d708:  91 33 e0 10  srl  %o7, 0x10, %o0
a013d70c:  d8 12 e0 48  lduh  [ %o3 + 0x48 ], %o4
a013d710:  82 0a 60 ff  and  %o1, 0xff, %g1
a013d714:  9a 23 00 08  sub  %o4, %o0, %o5
a013d718:  80 a3 40 01  cmp  %o5, %g1
a013d71c:  16 80 00 05  bge  0xa013d730
a013d720:  c2 12 e0 48  lduh  [ %o3 + 0x48 ], %g1
a013d724:  a0 0a 60 ff  and  %o1, 0xff, %l0
a013d728:  82 02 80 10  add  %o2, %l0, %g1
a013d72c:  c2 32 e0 48  sth  %g1, [ %o3 + 0x48 ]
a013d730:  80 88 60 07  btst  7, %g1
a013d734:  02 80 00 06  be  0xa013d74c
a013d738:  83 28 60 10  sll  %g1, 0x10, %g1
a013d73c:  a3 30 60 13  srl  %g1, 0x13, %l1
a013d740:  93 2c 60 03  sll  %l1, 3, %o1
a013d744:  94 02 60 08  add  %o1, 8, %o2
a013d748:  d4 32 e0 48  sth  %o2, [ %o3 + 0x48 ]
a013d74c:  91 2e 20 04  sll  %i0, 4, %o0
a013d750:  98 22 00 18  sub  %o0, %i0, %o4
a013d754:  9a 16 a3 30  or  %i2, 0x330, %o5
a013d758:  83 2b 20 03  sll  %o4, 3, %g1
a013d75c:  f2 03 40 01  ld  [ %o5 + %g1 ], %i1
a013d760:  97 36 60 0c  srl  %i1, 0xc, %o3
a013d764:  9a 0a e0 0f  and  %o3, 0xf, %o5
a013d768:  80 a3 60 01  cmp  %o5, 1
a013d76c:  02 80 00 46  be  0xa013d884
a013d770:  90 10 20 00  clr  %o0
a013d774:  80 a3 60 01  cmp  %o5, 1
a013d778:  04 80 00 06  ble  0xa013d790
a013d77c:  80 a3 60 02  cmp  %o5, 2
a013d780:  02 80 00 4e  be  0xa013d8b8
a013d784:  80 a3 60 03  cmp  %o5, 3
a013d788:  22 80 00 02  be,a   0xa013d790
a013d78c:  90 10 20 03  mov  3, %o0
a013d790:  97 2e 20 04  sll  %i0, 4, %o3
a013d794:  92 22 c0 18  sub  %o3, %i0, %o1
a013d798:  a1 2a 60 03  sll  %o1, 3, %l0
a013d79c:  a2 16 a3 30  or  %i2, 0x330, %l1
a013d7a0:  b2 04 00 11  add  %l0, %l1, %i1
a013d7a4:  d4 16 60 5c  lduh  [ %i1 + 0x5c ], %o2
a013d7a8:  90 0a 20 03  and  %o0, 3, %o0
a013d7ac:  d6 16 60 54  lduh  [ %i1 + 0x54 ], %o3
a013d7b0:  7f ff 2e 66  call  0xa0109148
a013d7b4:  d2 16 60 5a  lduh  [ %i1 + 0x5a ], %o1
a013d7b8:  d4 04 40 10  ld  [ %l1 + %l0 ], %o2
a013d7bc:  9f 32 a0 0c  srl  %o2, 0xc, %o7
a013d7c0:  82 0b e0 0f  and  %o7, 0xf, %g1
a013d7c4:  80 a0 60 01  cmp  %g1, 1
a013d7c8:  02 80 00 31  be  0xa013d88c
a013d7cc:  98 10 20 00  clr  %o4
a013d7d0:  80 a0 60 01  cmp  %g1, 1
a013d7d4:  04 80 00 06  ble  0xa013d7ec
a013d7d8:  80 a0 60 02  cmp  %g1, 2
a013d7dc:  02 80 00 39  be  0xa013d8c0
a013d7e0:  80 a0 60 03  cmp  %g1, 3
a013d7e4:  02 80 00 42  be  0xa013d8ec
a013d7e8:  9f 2e 20 04  sll  %i0, 4, %o7
a013d7ec:  9f 2e 20 04  sll  %i0, 4, %o7
a013d7f0:  90 23 c0 18  sub  %o7, %i0, %o0
a013d7f4:  9a 16 a3 30  or  %i2, 0x330, %o5
a013d7f8:  b1 2a 20 03  sll  %o0, 3, %i0
a013d7fc:  82 06 00 0d  add  %i0, %o5, %g1
a013d800:  b0 0b 20 03  and  %o4, 3, %i0
a013d804:  f4 10 60 52  lduh  [ %g1 + 0x52 ], %i2
a013d808:  f2 10 60 4a  lduh  [ %g1 + 0x4a ], %i1
a013d80c:  7f ff 2e 9b  call  0xa0109278
a013d810:  81 e8 00 00  restore
a013d814:  92 02 20 78  add  %o0, 0x78, %o1
a013d818:  f2 12 60 48  lduh  [ %o1 + 0x48 ], %i1
a013d81c:  a2 5e 60 66  smul  %i1, 0x66, %l1
a013d820:  80 54 40 0c  umul  %l1, %o4, %g0
a013d824:  a1 40 00 00  rd  %y, %l0
a013d828:  9f 34 20 05  srl  %l0, 5, %o7
a013d82c:  de 32 60 48  sth  %o7, [ %o1 + 0x48 ]
a013d830:  10 bf ff b5  b  0xa013d704
a013d834:  92 10 3f e0  mov  -32, %o1
a013d838:  d0 0a a1 a7  ldub  [ %o2 + 0x1a7 ], %o0
a013d83c:  80 a2 20 00  cmp  %o0, 0
a013d840:  12 bf ff 9c  bne  0xa013d6b0
a013d844:  b5 2e 20 04  sll  %i0, 4, %i2
a013d848:  35 2a 00 b7  sethi  %hi(0xa802dc00), %i2
a013d84c:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a013d850:  d8 12 e3 9a  lduh  [ %o3 + 0x39a ], %o4	! 0xa802e39a
a013d854:  92 16 a3 30  or  %i2, 0x330, %o1
a013d858:  d8 32 60 48  sth  %o4, [ %o1 + 0x48 ]
a013d85c:  91 2e 20 04  sll  %i0, 4, %o0
a013d860:  98 22 00 18  sub  %o0, %i0, %o4
a013d864:  9a 16 a3 30  or  %i2, 0x330, %o5
a013d868:  83 2b 20 03  sll  %o4, 3, %g1
a013d86c:  f2 03 40 01  ld  [ %o5 + %g1 ], %i1
a013d870:  97 36 60 0c  srl  %i1, 0xc, %o3
a013d874:  9a 0a e0 0f  and  %o3, 0xf, %o5
a013d878:  80 a3 60 01  cmp  %o5, 1
a013d87c:  12 bf ff bf  bne  0xa013d778
a013d880:  90 10 20 00  clr  %o0
a013d884:  10 bf ff c3  b  0xa013d790
a013d888:  90 10 20 01  mov  1, %o0
a013d88c:  9f 2e 20 04  sll  %i0, 4, %o7
a013d890:  90 23 c0 18  sub  %o7, %i0, %o0
a013d894:  9a 16 a3 30  or  %i2, 0x330, %o5
a013d898:  b1 2a 20 03  sll  %o0, 3, %i0
a013d89c:  82 06 00 0d  add  %i0, %o5, %g1
a013d8a0:  98 10 20 01  mov  1, %o4
a013d8a4:  b0 0b 20 03  and  %o4, 3, %i0
a013d8a8:  f4 10 60 52  lduh  [ %g1 + 0x52 ], %i2
a013d8ac:  f2 10 60 4a  lduh  [ %g1 + 0x4a ], %i1
a013d8b0:  7f ff 2e 72  call  0xa0109278
a013d8b4:  81 e8 00 00  restore
a013d8b8:  10 bf ff b6  b  0xa013d790
a013d8bc:  90 10 20 02  mov  2, %o0
a013d8c0:  9f 2e 20 04  sll  %i0, 4, %o7
a013d8c4:  90 23 c0 18  sub  %o7, %i0, %o0
a013d8c8:  9a 16 a3 30  or  %i2, 0x330, %o5
a013d8cc:  b1 2a 20 03  sll  %o0, 3, %i0
a013d8d0:  82 06 00 0d  add  %i0, %o5, %g1
a013d8d4:  98 10 20 02  mov  2, %o4
a013d8d8:  b0 0b 20 03  and  %o4, 3, %i0
a013d8dc:  f4 10 60 52  lduh  [ %g1 + 0x52 ], %i2
a013d8e0:  f2 10 60 4a  lduh  [ %g1 + 0x4a ], %i1
a013d8e4:  7f ff 2e 65  call  0xa0109278
a013d8e8:  81 e8 00 00  restore
a013d8ec:  90 23 c0 18  sub  %o7, %i0, %o0
a013d8f0:  9a 16 a3 30  or  %i2, 0x330, %o5
a013d8f4:  b1 2a 20 03  sll  %o0, 3, %i0
a013d8f8:  82 06 00 0d  add  %i0, %o5, %g1
a013d8fc:  98 10 20 03  mov  3, %o4
a013d900:  b0 0b 20 03  and  %o4, 3, %i0
a013d904:  f4 10 60 52  lduh  [ %g1 + 0x52 ], %i2
a013d908:  f2 10 60 4a  lduh  [ %g1 + 0x4a ], %i1
a013d90c:  7f ff 2e 5b  call  0xa0109278
a013d910:  81 e8 00 00  restore
a013d914:  01 00 00 00  nop
