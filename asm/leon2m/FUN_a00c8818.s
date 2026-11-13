# leon2m FUN_a00c8818 0xa00c8818-0xa00c8a44 (556 bytes)
a00c8818:  9d e3 bf 98  save  %sp, -104, %sp
a00c881c:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00c8820:  80 a4 60 02  cmp  %l1, 2
a00c8824:  02 80 00 63  be  0xa00c89b0
a00c8828:  80 a4 60 03  cmp  %l1, 3
a00c882c:  02 80 00 67  be  0xa00c89c8
a00c8830:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c8834:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c8838:  96 08 60 ff  and  %g1, 0xff, %o3
a00c883c:  94 02 ff d0  add  %o3, -48, %o2
a00c8840:  90 0a a0 ff  and  %o2, 0xff, %o0
a00c8844:  80 a2 20 03  cmp  %o0, 3
a00c8848:  18 80 00 7d  bgu  0xa00c8a3c
a00c884c:  b0 10 20 ff  mov  0xff, %i0
a00c8850:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c8854:  a0 13 22 90  or  %o4, 0x290, %l0	! 0xa802d290
a00c8858:  da 0c 20 1f  ldub  [ %l0 + 0x1f ], %o5
a00c885c:  80 a3 60 00  cmp  %o5, 0
a00c8860:  02 80 00 77  be  0xa00c8a3c
a00c8864:  01 00 00 00  nop
a00c8868:  40 01 ef 4d  call  0xa014459c
a00c886c:  01 00 00 00  nop
a00c8870:  d0 2c 20 20  stb  %o0, [ %l0 + 0x20 ]
a00c8874:  40 00 34 31  call  0xa00d5938
a00c8878:  90 10 20 01  mov  1, %o0
a00c887c:  40 01 71 b2  call  0xa0124f44
a00c8880:  01 00 00 00  nop
a00c8884:  f0 04 20 a8  ld  [ %l0 + 0xa8 ], %i0
a00c8888:  1f 00 00 10  sethi  %hi(0x4000), %o7
a00c888c:  80 8e 00 0f  btst  %i0, %o7
a00c8890:  12 80 00 4b  bne  0xa00c89bc
a00c8894:  01 00 00 00  nop
a00c8898:  40 01 71 a3  call  0xa0124f24
a00c889c:  01 00 00 00  nop
a00c88a0:  7f ff c0 0b  call  0xa00b88cc
a00c88a4:  01 00 00 00  nop
a00c88a8:  80 a4 60 02  cmp  %l1, 2
a00c88ac:  02 80 00 24  be  0xa00c893c
a00c88b0:  80 a4 60 03  cmp  %l1, 3
a00c88b4:  02 80 00 48  be  0xa00c89d4
a00c88b8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c88bc:  94 13 e0 78  or  %o7, 0x78, %o2	! 0xa802d078
a00c88c0:  90 10 20 30  mov  0x30, %o0
a00c88c4:  9a 10 20 35  mov  0x35, %o5
a00c88c8:  98 10 20 36  mov  0x36, %o4
a00c88cc:  96 10 20 2b  mov  0x2b, %o3
a00c88d0:  92 10 20 0d  mov  0xd, %o1
a00c88d4:  da 2b e0 78  stb  %o5, [ %o7 + 0x78 ]
a00c88d8:  d8 2a a0 01  stb  %o4, [ %o2 + 1 ]
a00c88dc:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00c88e0:  d6 2a a0 04  stb  %o3, [ %o2 + 4 ]
a00c88e4:  d2 2a a0 05  stb  %o1, [ %o2 + 5 ]
a00c88e8:  80 a4 60 02  cmp  %l1, 2
a00c88ec:  02 80 00 21  be  0xa00c8970
a00c88f0:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00c88f4:  80 a4 60 03  cmp  %l1, 3
a00c88f8:  02 80 00 44  be  0xa00c8a08
a00c88fc:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c8900:  92 12 e0 d0  or  %o3, 0xd0, %o1	! 0xa802d0d0
a00c8904:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00c8908:  c0 2b 20 9c  clrb  [ %o4 + 0x9c ]	! 0xa802b09c
a00c890c:  c0 2a e0 d0  clrb  [ %o3 + 0xd0 ]
a00c8910:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c8914:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c8918:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c891c:  80 a4 60 02  cmp  %l1, 2
a00c8920:  02 80 00 1d  be  0xa00c8994
a00c8924:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c8928:  80 a4 60 03  cmp  %l1, 3
a00c892c:  12 80 00 1d  bne  0xa00c89a0
a00c8930:  90 10 00 11  mov  %l1, %o0
a00c8934:  10 80 00 3f  b  0xa00c8a30
a00c8938:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c893c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c8940:  a0 12 a1 28  or  %o2, 0x128, %l0	! 0xa802d128
a00c8944:  a2 10 20 30  mov  0x30, %l1
a00c8948:  96 10 20 35  mov  0x35, %o3
a00c894c:  92 10 20 0d  mov  0xd, %o1
a00c8950:  90 10 20 36  mov  0x36, %o0
a00c8954:  82 10 20 2b  mov  0x2b, %g1
a00c8958:  d6 2a a1 28  stb  %o3, [ %o2 + 0x128 ]
a00c895c:  d2 2c 20 05  stb  %o1, [ %l0 + 5 ]
a00c8960:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00c8964:  e2 2c 20 03  stb  %l1, [ %l0 + 3 ]
a00c8968:  c2 2c 20 04  stb  %g1, [ %l0 + 4 ]
a00c896c:  e2 2c 20 02  stb  %l1, [ %l0 + 2 ]
a00c8970:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c8974:  94 16 20 40  or  %i0, 0x40, %o2	! 0xa802d040
a00c8978:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00c897c:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00c8980:  c0 2e 20 40  clrb  [ %i0 + 0x40 ]
a00c8984:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c8988:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c898c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c8990:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c8994:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c8998:  94 13 e1 28  or  %o7, 0x128, %o2	! 0xa802d128
a00c899c:  90 10 20 02  mov  2, %o0
a00c89a0:  40 01 ff 92  call  0xa01487e8
a00c89a4:  92 10 20 06  mov  6, %o1
a00c89a8:  10 80 00 25  b  0xa00c8a3c
a00c89ac:  b0 10 20 00  clr  %i0
a00c89b0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c89b4:  10 bf ff a1  b  0xa00c8838
a00c89b8:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c89bc:  40 00 34 c7  call  0xa00d5cd8
a00c89c0:  01 00 00 00  nop
a00c89c4:  30 bf ff b5  b,a   0xa00c8898
a00c89c8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c89cc:  10 bf ff 9b  b  0xa00c8838
a00c89d0:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c89d4:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c89d8:  98 14 61 08  or  %l1, 0x108, %o4	! 0xa802d108
a00c89dc:  9e 10 20 30  mov  0x30, %o7
a00c89e0:  82 10 20 35  mov  0x35, %g1
a00c89e4:  a0 10 20 0d  mov  0xd, %l0
a00c89e8:  b0 10 20 36  mov  0x36, %i0
a00c89ec:  9a 10 20 2b  mov  0x2b, %o5
a00c89f0:  c2 2c 61 08  stb  %g1, [ %l1 + 0x108 ]
a00c89f4:  e0 2b 20 05  stb  %l0, [ %o4 + 5 ]
a00c89f8:  f0 2b 20 01  stb  %i0, [ %o4 + 1 ]
a00c89fc:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00c8a00:  da 2b 20 04  stb  %o5, [ %o4 + 4 ]
a00c8a04:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00c8a08:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c8a0c:  a2 12 20 98  or  %o0, 0x98, %l1	! 0xa802d098
a00c8a10:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c8a14:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c8a18:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00c8a1c:  c0 2c 60 19  clrb  [ %l1 + 0x19 ]
a00c8a20:  c0 2c 60 01  clrb  [ %l1 + 1 ]
a00c8a24:  c0 2c 60 07  clrb  [ %l1 + 7 ]
a00c8a28:  c0 2c 60 0a  clrb  [ %l1 + 0xa ]
a00c8a2c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c8a30:  94 13 61 08  or  %o5, 0x108, %o2	! 0xa802d108
a00c8a34:  10 bf ff db  b  0xa00c89a0
a00c8a38:  90 10 20 03  mov  3, %o0
a00c8a3c:  81 c7 e0 08  ret
a00c8a40:  81 e8 00 00  restore
