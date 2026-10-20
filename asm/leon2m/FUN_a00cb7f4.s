# leon2m FUN_a00cb7f4 0xa00cb7f4-0xa00cb9d4 (480 bytes)
a00cb7f4:  9d e3 bf 98  save  %sp, -104, %sp
a00cb7f8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00cb7fc:  80 a4 20 02  cmp  %l0, 2
a00cb800:  02 80 00 53  be  0xa00cb94c
a00cb804:  80 a4 20 03  cmp  %l0, 3
a00cb808:  02 80 00 54  be  0xa00cb958
a00cb80c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cb810:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00cb814:  9a 08 60 ff  and  %g1, 0xff, %o5
a00cb818:  96 03 7f d0  add  %o5, -48, %o3
a00cb81c:  94 0a e0 ff  and  %o3, 0xff, %o2
a00cb820:  80 a2 a0 02  cmp  %o2, 2
a00cb824:  18 80 00 6a  bgu  0xa00cb9cc
a00cb828:  b0 10 20 ff  mov  0xff, %i0
a00cb82c:  9a 03 7f d1  add  %o5, -47, %o5
a00cb830:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a00cb834:  40 00 3c d7  call  0xa00dab90
a00cb838:  da 2b 20 7d  stb  %o5, [ %o4 + 0x7d ]	! 0xa802d47d
a00cb83c:  7f ff b4 24  call  0xa00b88cc
a00cb840:  01 00 00 00  nop
a00cb844:  80 a4 20 02  cmp  %l0, 2
a00cb848:  02 80 00 24  be  0xa00cb8d8
a00cb84c:  80 a4 20 03  cmp  %l0, 3
a00cb850:  02 80 00 45  be  0xa00cb964
a00cb854:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cb858:  94 12 e0 78  or  %o3, 0x78, %o2	! 0xa802d078
a00cb85c:  90 10 20 30  mov  0x30, %o0
a00cb860:  9a 10 20 35  mov  0x35, %o5
a00cb864:  9e 10 20 36  mov  0x36, %o7
a00cb868:  98 10 20 2b  mov  0x2b, %o4
a00cb86c:  92 10 20 0d  mov  0xd, %o1
a00cb870:  da 2a e0 78  stb  %o5, [ %o3 + 0x78 ]
a00cb874:  de 2a a0 01  stb  %o7, [ %o2 + 1 ]
a00cb878:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00cb87c:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00cb880:  d2 2a a0 05  stb  %o1, [ %o2 + 5 ]
a00cb884:  80 a4 20 02  cmp  %l0, 2
a00cb888:  02 80 00 21  be  0xa00cb90c
a00cb88c:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00cb890:  80 a4 20 03  cmp  %l0, 3
a00cb894:  02 80 00 41  be  0xa00cb998
a00cb898:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cb89c:  9e 13 20 d0  or  %o4, 0xd0, %o7	! 0xa802d0d0
a00cb8a0:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00cb8a4:  c0 2a e0 9c  clrb  [ %o3 + 0x9c ]	! 0xa802b09c
a00cb8a8:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00cb8ac:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00cb8b0:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00cb8b4:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00cb8b8:  80 a4 20 02  cmp  %l0, 2
a00cb8bc:  02 80 00 1d  be  0xa00cb930
a00cb8c0:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00cb8c4:  80 a4 20 03  cmp  %l0, 3
a00cb8c8:  12 80 00 1d  bne  0xa00cb93c
a00cb8cc:  90 10 00 10  mov  %l0, %o0
a00cb8d0:  10 80 00 3c  b  0xa00cb9c0
a00cb8d4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cb8d8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cb8dc:  9e 12 61 28  or  %o1, 0x128, %o7	! 0xa802d128
a00cb8e0:  a0 10 20 30  mov  0x30, %l0
a00cb8e4:  94 10 20 35  mov  0x35, %o2
a00cb8e8:  90 10 20 0d  mov  0xd, %o0
a00cb8ec:  82 10 20 36  mov  0x36, %g1
a00cb8f0:  b0 10 20 2b  mov  0x2b, %i0
a00cb8f4:  d4 2a 61 28  stb  %o2, [ %o1 + 0x128 ]
a00cb8f8:  d0 2b e0 05  stb  %o0, [ %o7 + 5 ]
a00cb8fc:  c2 2b e0 01  stb  %g1, [ %o7 + 1 ]
a00cb900:  e0 2b e0 03  stb  %l0, [ %o7 + 3 ]
a00cb904:  f0 2b e0 04  stb  %i0, [ %o7 + 4 ]
a00cb908:  e0 2b e0 02  stb  %l0, [ %o7 + 2 ]
a00cb90c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00cb910:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00cb914:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00cb918:  c0 2e 20 9a  clrb  [ %i0 + 0x9a ]	! 0xa802b09a
a00cb91c:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00cb920:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00cb924:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00cb928:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00cb92c:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00cb930:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00cb934:  94 13 61 28  or  %o5, 0x128, %o2	! 0xa802d128
a00cb938:  90 10 20 02  mov  2, %o0
a00cb93c:  40 01 f3 ab  call  0xa01487e8
a00cb940:  92 10 20 06  mov  6, %o1
a00cb944:  10 80 00 22  b  0xa00cb9cc
a00cb948:  b0 10 20 00  clr  %i0
a00cb94c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cb950:  10 bf ff b1  b  0xa00cb814
a00cb954:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00cb958:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cb95c:  10 bf ff ae  b  0xa00cb814
a00cb960:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00cb964:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00cb968:  98 16 21 08  or  %i0, 0x108, %o4	! 0xa802d108
a00cb96c:  9e 10 20 30  mov  0x30, %o7
a00cb970:  82 10 20 35  mov  0x35, %g1
a00cb974:  a0 10 20 0d  mov  0xd, %l0
a00cb978:  9a 10 20 36  mov  0x36, %o5
a00cb97c:  96 10 20 2b  mov  0x2b, %o3
a00cb980:  c2 2e 21 08  stb  %g1, [ %i0 + 0x108 ]
a00cb984:  e0 2b 20 05  stb  %l0, [ %o4 + 5 ]
a00cb988:  da 2b 20 01  stb  %o5, [ %o4 + 1 ]
a00cb98c:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00cb990:  d6 2b 20 04  stb  %o3, [ %o4 + 4 ]
a00cb994:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00cb998:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cb99c:  90 12 60 98  or  %o1, 0x98, %o0	! 0xa802d098
a00cb9a0:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00cb9a4:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00cb9a8:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]
a00cb9ac:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00cb9b0:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00cb9b4:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00cb9b8:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00cb9bc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cb9c0:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00cb9c4:  10 bf ff de  b  0xa00cb93c
a00cb9c8:  90 10 20 03  mov  3, %o0
a00cb9cc:  81 c7 e0 08  ret
a00cb9d0:  81 e8 00 00  restore
