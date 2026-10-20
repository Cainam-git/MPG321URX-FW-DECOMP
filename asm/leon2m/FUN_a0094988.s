# leon2m FUN_a0094988 0xa0094988-0xa0094b6c (484 bytes)
a0094988:  9d e3 bf 98  save  %sp, -104, %sp
a009498c:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a0094990:  b4 16 62 90  or  %i1, 0x290, %i2	! 0xa802d290
a0094994:  c2 0e a1 a3  ldub  [ %i2 + 0x1a3 ], %g1
a0094998:  80 a0 60 00  cmp  %g1, 0
a009499c:  12 80 00 10  bne  0xa00949dc
a00949a0:  80 a0 60 01  cmp  %g1, 1
a00949a4:  c2 0e a1 a6  ldub  [ %i2 + 0x1a6 ], %g1
a00949a8:  80 a0 60 1c  cmp  %g1, 0x1c
a00949ac:  02 80 00 6e  be  0xa0094b64
a00949b0:  90 10 20 00  clr  %o0
a00949b4:  92 10 20 00  clr  %o1
a00949b8:  40 00 48 78  call  0xa00a6b98
a00949bc:  94 10 20 01  mov  1, %o2
a00949c0:  d2 0e a1 a6  ldub  [ %i2 + 0x1a6 ], %o1
a00949c4:  90 02 60 01  add  %o1, 1, %o0
a00949c8:  d0 2e a1 a6  stb  %o0, [ %i2 + 0x1a6 ]
a00949cc:  b0 10 20 00  clr  %i0
a00949d0:  b2 10 20 00  clr  %i1
a00949d4:  40 00 48 71  call  0xa00a6b98
a00949d8:  95 e8 20 00  restore  %g0, 0, %o2
a00949dc:  02 80 00 05  be  0xa00949f0
a00949e0:  80 a0 60 02  cmp  %g1, 2
a00949e4:  12 80 00 60  bne  0xa0094b64
a00949e8:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00949ec:  30 80 00 0d  b,a   0xa0094a20
a00949f0:  d4 0e a1 a8  ldub  [ %i2 + 0x1a8 ], %o2
a00949f4:  80 a2 a0 1c  cmp  %o2, 0x1c
a00949f8:  02 80 00 5b  be  0xa0094b64
a00949fc:  90 10 20 01  mov  1, %o0
a0094a00:  92 10 20 00  clr  %o1
a0094a04:  40 00 48 65  call  0xa00a6b98
a0094a08:  94 10 20 01  mov  1, %o2
a0094a0c:  d8 0e a1 a8  ldub  [ %i2 + 0x1a8 ], %o4
a0094a10:  96 03 20 01  add  %o4, 1, %o3
a0094a14:  d6 2e a1 a8  stb  %o3, [ %i2 + 0x1a8 ]
a0094a18:  10 bf ff ee  b  0xa00949d0
a0094a1c:  b0 10 20 01  mov  1, %i0
a0094a20:  67 ff e2 dd  call  0x4008d594
a0094a24:  d0 14 20 34  lduh  [ %l0 + 0x34 ], %o0
a0094a28:  9f 2a 20 10  sll  %o0, 0x10, %o7
a0094a2c:  9b 33 e0 10  srl  %o7, 0x10, %o5
a0094a30:  80 a3 60 64  cmp  %o5, 0x64
a0094a34:  a2 10 00 10  mov  %l0, %l1
a0094a38:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a0094a3c:  18 80 00 2c  bgu  0xa0094aec
a0094a40:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a0094a44:  40 02 cb 38  call  0xa0147724
a0094a48:  b4 14 a3 f4  or  %l2, 0x3f4, %i2
a0094a4c:  d4 0e a0 08  ldub  [ %i2 + 8 ], %o2
a0094a50:  93 32 a0 04  srl  %o2, 4, %o1
a0094a54:  80 a2 60 01  cmp  %o1, 1
a0094a58:  02 80 00 06  be  0xa0094a70
a0094a5c:  d0 34 60 34  sth  %o0, [ %l1 + 0x34 ]
a0094a60:  90 10 20 11  mov  0x11, %o0
a0094a64:  40 02 cb 30  call  0xa0147724
a0094a68:  d0 2e a0 08  stb  %o0, [ %i2 + 8 ]
a0094a6c:  d0 36 20 3a  sth  %o0, [ %i0 + 0x3a ]
a0094a70:  67 ff e2 c9  call  0x4008d594
a0094a74:  d0 16 20 3a  lduh  [ %i0 + 0x3a ], %o0
a0094a78:  99 2a 20 10  sll  %o0, 0x10, %o4
a0094a7c:  97 33 20 10  srl  %o4, 0x10, %o3
a0094a80:  80 a2 e7 d0  cmp  %o3, 0x7d0
a0094a84:  18 80 00 24  bgu  0xa0094b14
a0094a88:  01 00 00 00  nop
a0094a8c:  67 ff e2 c2  call  0x4008d594
a0094a90:  d0 16 20 3a  lduh  [ %i0 + 0x3a ], %o0
a0094a94:  93 2a 20 10  sll  %o0, 0x10, %o1
a0094a98:  03 00 00 04  sethi  %hi(0x1000), %g1
a0094a9c:  b5 32 60 10  srl  %o1, 0x10, %i2
a0094aa0:  b0 10 63 88  or  %g1, 0x388, %i0
a0094aa4:  80 a6 80 18  cmp  %i2, %i0
a0094aa8:  18 80 00 24  bgu  0xa0094b38
a0094aac:  a2 14 a3 f4  or  %l2, 0x3f4, %l1
a0094ab0:  d8 0c 60 08  ldub  [ %l1 + 8 ], %o4
a0094ab4:  9a 0b 20 0f  and  %o4, 0xf, %o5
a0094ab8:  96 16 62 90  or  %i1, 0x290, %o3
a0094abc:  d8 12 e1 ae  lduh  [ %o3 + 0x1ae ], %o4
a0094ac0:  a4 03 00 0d  add  %o4, %o5, %l2
a0094ac4:  80 a4 a7 f2  cmp  %l2, 0x7f2
a0094ac8:  14 80 00 0f  bg  0xa0094b04
a0094acc:  80 a3 28 03  cmp  %o4, 0x803
a0094ad0:  82 03 40 0c  add  %o5, %o4, %g1
a0094ad4:  c2 32 e1 ae  sth  %g1, [ %o3 + 0x1ae ]
a0094ad8:  9a 16 62 90  or  %i1, 0x290, %o5
a0094adc:  f2 13 61 ae  lduh  [ %o5 + 0x1ae ], %i1
a0094ae0:  f0 13 61 ac  lduh  [ %o5 + 0x1ac ], %i0
a0094ae4:  40 02 c6 9a  call  0xa014654c
a0094ae8:  95 e8 20 01  restore  %g0, 1, %o2
a0094aec:  82 10 20 11  mov  0x11, %g1
a0094af0:  b4 14 a3 f4  or  %l2, 0x3f4, %i2
a0094af4:  40 02 cb 0c  call  0xa0147724
a0094af8:  c2 2e a0 08  stb  %g1, [ %i2 + 8 ]
a0094afc:  10 bf ff d2  b  0xa0094a44
a0094b00:  d0 36 20 3a  sth  %o0, [ %i0 + 0x3a ]
a0094b04:  18 bf ff f6  bgu  0xa0094adc
a0094b08:  9a 16 62 90  or  %i1, 0x290, %o5
a0094b0c:  10 bf ff f2  b  0xa0094ad4
a0094b10:  82 03 20 01  add  %o4, 1, %g1
a0094b14:  67 ff e2 a0  call  0x4008d594
a0094b18:  d0 14 60 34  lduh  [ %l1 + 0x34 ], %o0
a0094b1c:  9b 2a 20 10  sll  %o0, 0x10, %o5
a0094b20:  a3 33 60 10  srl  %o5, 0x10, %l1
a0094b24:  80 a4 60 63  cmp  %l1, 0x63
a0094b28:  18 bf ff d9  bgu  0xa0094a8c
a0094b2c:  9e 10 20 15  mov  0x15, %o7
a0094b30:  10 bf ff d7  b  0xa0094a8c
a0094b34:  de 2e a0 08  stb  %o7, [ %i2 + 8 ]
a0094b38:  67 ff e2 97  call  0x4008d594
a0094b3c:  d0 14 20 34  lduh  [ %l0 + 0x34 ], %o0
a0094b40:  95 2a 20 10  sll  %o0, 0x10, %o2
a0094b44:  a1 32 a0 10  srl  %o2, 0x10, %l0
a0094b48:  80 a4 20 63  cmp  %l0, 0x63
a0094b4c:  18 bf ff d9  bgu  0xa0094ab0
a0094b50:  a2 14 a3 f4  or  %l2, 0x3f4, %l1
a0094b54:  90 14 a3 f4  or  %l2, 0x3f4, %o0
a0094b58:  96 10 20 1a  mov  0x1a, %o3
a0094b5c:  10 bf ff d5  b  0xa0094ab0
a0094b60:  d6 2a 20 08  stb  %o3, [ %o0 + 8 ]
a0094b64:  81 c7 e0 08  ret
a0094b68:  81 e8 00 00  restore
