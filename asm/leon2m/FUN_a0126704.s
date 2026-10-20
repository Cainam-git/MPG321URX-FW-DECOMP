# leon2m FUN_a0126704 0xa0126704-0xa0126878 (372 bytes)
a0126704:  9d e3 bf 90  save  %sp, -112, %sp
a0126708:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a012670c:  a2 15 60 90  or  %l5, 0x90, %l1	! 0xa802d890
a0126710:  f0 2c 60 01  stb  %i0, [ %l1 + 1 ]
a0126714:  7f ff f8 6d  call  0xa01248c8
a0126718:  c0 2d 60 90  clrb  [ %l5 + 0x90 ]
a012671c:  80 8a 20 ff  btst  0xff, %o0
a0126720:  02 80 00 54  be  0xa0126870
a0126724:  15 00 06 91  sethi  %hi(0x1a4400), %o2
a0126728:  92 0e 20 ff  and  %i0, 0xff, %o1
a012672c:  7f fe e2 91  call  0xa00df170
a0126730:  90 12 a0 a0  or  %o2, 0xa0, %o0
a0126734:  82 10 20 01  mov  1, %g1
a0126738:  a4 10 20 02  mov  2, %l2
a012673c:  c2 23 a0 60  st  %g1, [ %sp + 0x60 ]
a0126740:  9a 10 00 11  mov  %l1, %o5
a0126744:  92 10 20 02  mov  2, %o1
a0126748:  94 10 20 b2  mov  0xb2, %o2
a012674c:  96 10 20 05  mov  5, %o3
a0126750:  98 10 20 00  clr  %o4
a0126754:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0126758:  40 00 84 d2  call  0xa0147aa0
a012675c:  90 10 20 60  mov  0x60, %o0
a0126760:  67 fd 9a 90  call  0x4008d1a0
a0126764:  90 10 20 32  mov  0x32, %o0
a0126768:  2d 2a 00 b6  sethi  %hi(0xa802d800), %l6
a012676c:  96 10 20 05  mov  5, %o3
a0126770:  98 10 20 00  clr  %o4
a0126774:  9a 15 a0 88  or  %l6, 0x88, %o5
a0126778:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a012677c:  92 10 20 02  mov  2, %o1
a0126780:  94 10 20 b2  mov  0xb2, %o2
a0126784:  40 00 84 d9  call  0xa0147ae8
a0126788:  90 10 20 60  mov  0x60, %o0
a012678c:  a0 15 a0 88  or  %l6, 0x88, %l0
a0126790:  11 00 06 91  sethi  %hi(0x1a4400), %o0
a0126794:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a0126798:  d2 0d a0 88  ldub  [ %l6 + 0x88 ], %o1
a012679c:  7f fe e2 75  call  0xa00df170
a01267a0:  90 12 20 d0  or  %o0, 0xd0, %o0
a01267a4:  a4 10 00 11  mov  %l1, %l2
a01267a8:  90 10 20 32  mov  0x32, %o0
a01267ac:  67 fd 9a 7d  call  0x4008d1a0
a01267b0:  a2 10 00 10  mov  %l0, %l1
a01267b4:  a8 10 00 15  mov  %l5, %l4
a01267b8:  a6 10 00 16  mov  %l6, %l3
a01267bc:  10 80 00 1f  b  0xa0126838
a01267c0:  a0 10 20 02  mov  2, %l0
a01267c4:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a01267c8:  80 a2 e0 09  cmp  %o3, 9
a01267cc:  18 80 00 29  bgu  0xa0126870
a01267d0:  d2 0d 20 90  ldub  [ %l4 + 0x90 ], %o1
a01267d4:  7f fe e2 67  call  0xa00df170
a01267d8:  d6 0c e0 88  ldub  [ %l3 + 0x88 ], %o3
a01267dc:  98 10 20 01  mov  1, %o4
a01267e0:  d8 23 a0 60  st  %o4, [ %sp + 0x60 ]
a01267e4:  92 10 20 02  mov  2, %o1
a01267e8:  94 10 20 b2  mov  0xb2, %o2
a01267ec:  96 10 20 05  mov  5, %o3
a01267f0:  98 10 20 00  clr  %o4
a01267f4:  9a 10 00 12  mov  %l2, %o5
a01267f8:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a01267fc:  40 00 84 a9  call  0xa0147aa0
a0126800:  90 10 20 60  mov  0x60, %o0
a0126804:  67 fd 9a 67  call  0x4008d1a0
a0126808:  90 10 20 32  mov  0x32, %o0
a012680c:  92 10 20 02  mov  2, %o1
a0126810:  96 10 20 05  mov  5, %o3
a0126814:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a0126818:  90 10 20 60  mov  0x60, %o0
a012681c:  94 10 20 b2  mov  0xb2, %o2
a0126820:  98 10 20 00  clr  %o4
a0126824:  40 00 84 b1  call  0xa0147ae8
a0126828:  9a 10 00 11  mov  %l1, %o5
a012682c:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0126830:  92 02 e0 01  add  %o3, 1, %o1
a0126834:  d2 2e 21 fd  stb  %o1, [ %i0 + 0x1fd ]
a0126838:  31 00 06 91  sethi  %hi(0x1a4400), %i0
a012683c:  da 0c a0 01  ldub  [ %l2 + 1 ], %o5
a0126840:  de 0c 60 01  ldub  [ %l1 + 1 ], %o7
a0126844:  90 16 21 00  or  %i0, 0x100, %o0
a0126848:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a012684c:  94 10 00 0d  mov  %o5, %o2
a0126850:  80 a3 40 0f  cmp  %o5, %o7
a0126854:  12 bf ff dc  bne  0xa01267c4
a0126858:  98 10 00 0f  mov  %o7, %o4
a012685c:  d2 0d 60 90  ldub  [ %l5 + 0x90 ], %o1
a0126860:  c2 0d a0 88  ldub  [ %l6 + 0x88 ], %g1
a0126864:  80 a2 40 01  cmp  %o1, %g1
a0126868:  12 bf ff d8  bne  0xa01267c8
a012686c:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0126870:  81 c7 e0 08  ret
a0126874:  81 e8 00 00  restore
