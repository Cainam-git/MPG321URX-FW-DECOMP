# leon2m FUN_a0094b6c 0xa0094b6c-0xa0094df0 (644 bytes)
a0094b6c:  9d e3 bf 98  save  %sp, -104, %sp
a0094b70:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a0094b74:  b4 16 62 90  or  %i1, 0x290, %i2	! 0xa802d290
a0094b78:  c2 0e a1 a3  ldub  [ %i2 + 0x1a3 ], %g1
a0094b7c:  80 a0 60 00  cmp  %g1, 0
a0094b80:  02 80 00 07  be  0xa0094b9c
a0094b84:  80 a0 60 01  cmp  %g1, 1
a0094b88:  02 80 00 1f  be  0xa0094c04
a0094b8c:  80 a0 60 02  cmp  %g1, 2
a0094b90:  12 80 00 96  bne  0xa0094de8
a0094b94:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a0094b98:  30 80 00 33  b,a   0xa0094c64
a0094b9c:  e0 0e a1 a5  ldub  [ %i2 + 0x1a5 ], %l0
a0094ba0:  40 02 cd f7  call  0xa014837c
a0094ba4:  90 10 20 00  clr  %o0
a0094ba8:  a3 2a 20 10  sll  %o0, 0x10, %l1
a0094bac:  9f 34 60 10  srl  %l1, 0x10, %o7
a0094bb0:  1b 0e 38 e3  sethi  %hi(0x38e38c00), %o5
a0094bb4:  94 03 ff 40  add  %o7, -192, %o2
a0094bb8:  98 13 62 39  or  %o5, 0x239, %o4
a0094bbc:  80 5a 80 0c  smul  %o2, %o4, %g0
a0094bc0:  97 40 00 00  rd  %y, %o3
a0094bc4:  93 3a e0 04  sra  %o3, 4, %o1
a0094bc8:  91 3a a0 1f  sra  %o2, 0x1f, %o0
a0094bcc:  82 22 40 08  sub  %o1, %o0, %g1
a0094bd0:  80 a4 00 01  cmp  %l0, %g1
a0094bd4:  02 80 00 85  be  0xa0094de8
a0094bd8:  90 10 20 00  clr  %o0
a0094bdc:  92 10 20 00  clr  %o1
a0094be0:  40 00 47 ee  call  0xa00a6b98
a0094be4:  94 10 20 01  mov  1, %o2
a0094be8:  f0 0e a1 a5  ldub  [ %i2 + 0x1a5 ], %i0
a0094bec:  a4 06 20 01  add  %i0, 1, %l2
a0094bf0:  e4 2e a1 a5  stb  %l2, [ %i2 + 0x1a5 ]
a0094bf4:  b0 10 20 00  clr  %i0
a0094bf8:  b2 10 20 00  clr  %i1
a0094bfc:  40 00 47 e7  call  0xa00a6b98
a0094c00:  95 e8 20 00  restore  %g0, 0, %o2
a0094c04:  e0 0e a1 a7  ldub  [ %i2 + 0x1a7 ], %l0
a0094c08:  40 02 cd dd  call  0xa014837c
a0094c0c:  90 10 20 00  clr  %o0
a0094c10:  9f 2a 20 10  sll  %o0, 0x10, %o7
a0094c14:  9b 33 e0 10  srl  %o7, 0x10, %o5
a0094c18:  19 0e 38 e3  sethi  %hi(0x38e38c00), %o4
a0094c1c:  90 03 7e e0  add  %o5, -288, %o0
a0094c20:  96 13 22 39  or  %o4, 0x239, %o3
a0094c24:  80 5a 00 0b  smul  %o0, %o3, %g0
a0094c28:  95 40 00 00  rd  %y, %o2
a0094c2c:  83 3a a0 04  sra  %o2, 4, %g1
a0094c30:  93 3a 20 1f  sra  %o0, 0x1f, %o1
a0094c34:  b2 20 40 09  sub  %g1, %o1, %i1
a0094c38:  80 a4 00 19  cmp  %l0, %i1
a0094c3c:  02 80 00 6b  be  0xa0094de8
a0094c40:  90 10 20 01  mov  1, %o0
a0094c44:  92 10 20 00  clr  %o1
a0094c48:  40 00 47 d4  call  0xa00a6b98
a0094c4c:  94 10 20 01  mov  1, %o2
a0094c50:  e4 0e a1 a7  ldub  [ %i2 + 0x1a7 ], %l2
a0094c54:  a2 04 a0 01  add  %l2, 1, %l1
a0094c58:  e2 2e a1 a7  stb  %l1, [ %i2 + 0x1a7 ]
a0094c5c:  10 bf ff e7  b  0xa0094bf8
a0094c60:  b0 10 20 01  mov  1, %i0
a0094c64:  67 ff e2 4c  call  0x4008d594
a0094c68:  d0 16 20 34  lduh  [ %i0 + 0x34 ], %o0
a0094c6c:  a1 2a 20 10  sll  %o0, 0x10, %l0
a0094c70:  b5 34 20 10  srl  %l0, 0x10, %i2
a0094c74:  80 a6 a0 64  cmp  %i2, 0x64
a0094c78:  a2 10 00 18  mov  %i0, %l1
a0094c7c:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a0094c80:  18 80 00 54  bgu  0xa0094dd0
a0094c84:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a0094c88:  40 02 ca a7  call  0xa0147724
a0094c8c:  a0 14 a3 f4  or  %l2, 0x3f4, %l0
a0094c90:  d6 0c 20 08  ldub  [ %l0 + 8 ], %o3
a0094c94:  95 32 e0 04  srl  %o3, 4, %o2
a0094c98:  80 a2 a0 04  cmp  %o2, 4
a0094c9c:  02 80 00 06  be  0xa0094cb4
a0094ca0:  d0 34 60 34  sth  %o0, [ %l1 + 0x34 ]
a0094ca4:  90 10 20 42  mov  0x42, %o0
a0094ca8:  40 02 ca 9f  call  0xa0147724
a0094cac:  d0 2c 20 08  stb  %o0, [ %l0 + 8 ]
a0094cb0:  d0 36 a0 3a  sth  %o0, [ %i2 + 0x3a ]
a0094cb4:  67 ff e2 38  call  0x4008d594
a0094cb8:  d0 16 a0 3a  lduh  [ %i2 + 0x3a ], %o0
a0094cbc:  9b 2a 20 10  sll  %o0, 0x10, %o5
a0094cc0:  99 33 60 10  srl  %o5, 0x10, %o4
a0094cc4:  80 a3 27 d0  cmp  %o4, 0x7d0
a0094cc8:  18 80 00 39  bgu  0xa0094dac
a0094ccc:  01 00 00 00  nop
a0094cd0:  67 ff e2 31  call  0x4008d594
a0094cd4:  d0 16 a0 3a  lduh  [ %i2 + 0x3a ], %o0
a0094cd8:  95 2a 20 10  sll  %o0, 0x10, %o2
a0094cdc:  03 00 00 04  sethi  %hi(0x1000), %g1
a0094ce0:  a1 32 a0 10  srl  %o2, 0x10, %l0
a0094ce4:  b4 10 63 88  or  %g1, 0x388, %i2
a0094ce8:  80 a4 00 1a  cmp  %l0, %i2
a0094cec:  18 80 00 25  bgu  0xa0094d80
a0094cf0:  01 00 00 00  nop
a0094cf4:  b0 14 a3 f4  or  %l2, 0x3f4, %i0
a0094cf8:  c2 0e 20 08  ldub  [ %i0 + 8 ], %g1
a0094cfc:  b4 16 62 90  or  %i1, 0x290, %i2
a0094d00:  a0 08 60 0f  and  %g1, 0xf, %l0
a0094d04:  d2 16 a1 ac  lduh  [ %i2 + 0x1ac ], %o1
a0094d08:  a2 02 40 10  add  %o1, %l0, %l1
a0094d0c:  40 02 cd 9c  call  0xa014837c
a0094d10:  90 10 20 00  clr  %o0
a0094d14:  9f 2a 20 10  sll  %o0, 0x10, %o7
a0094d18:  9b 33 e0 10  srl  %o7, 0x10, %o5
a0094d1c:  a4 03 7f 88  add  %o5, -120, %l2
a0094d20:  80 a4 40 12  cmp  %l1, %l2
a0094d24:  34 80 00 0c  bg,a   0xa0094d54
a0094d28:  e4 16 a1 ac  lduh  [ %i2 + 0x1ac ], %l2
a0094d2c:  d6 0e 20 08  ldub  [ %i0 + 8 ], %o3
a0094d30:  94 0a e0 0f  and  %o3, 0xf, %o2
a0094d34:  f0 16 a1 ac  lduh  [ %i2 + 0x1ac ], %i0
a0094d38:  82 02 80 18  add  %o2, %i0, %g1
a0094d3c:  c2 36 a1 ac  sth  %g1, [ %i2 + 0x1ac ]
a0094d40:  b4 16 62 90  or  %i1, 0x290, %i2
a0094d44:  f2 16 a1 ae  lduh  [ %i2 + 0x1ae ], %i1
a0094d48:  f0 16 a1 ac  lduh  [ %i2 + 0x1ac ], %i0
a0094d4c:  40 02 c6 00  call  0xa014654c
a0094d50:  95 e8 20 01  restore  %g0, 1, %o2
a0094d54:  40 02 cd 8a  call  0xa014837c
a0094d58:  90 10 20 00  clr  %o0
a0094d5c:  a3 2a 20 10  sll  %o0, 0x10, %l1
a0094d60:  99 34 60 10  srl  %l1, 0x10, %o4
a0094d64:  90 03 3f a0  add  %o4, -96, %o0
a0094d68:  80 a4 80 08  cmp  %l2, %o0
a0094d6c:  36 bf ff f6  bge,a   0xa0094d44
a0094d70:  b4 16 62 90  or  %i1, 0x290, %i2
a0094d74:  da 16 a1 ac  lduh  [ %i2 + 0x1ac ], %o5
a0094d78:  10 bf ff f1  b  0xa0094d3c
a0094d7c:  82 03 60 02  add  %o5, 2, %g1
a0094d80:  67 ff e2 05  call  0x4008d594
a0094d84:  d0 16 20 34  lduh  [ %i0 + 0x34 ], %o0
a0094d88:  97 2a 20 10  sll  %o0, 0x10, %o3
a0094d8c:  b1 32 e0 10  srl  %o3, 0x10, %i0
a0094d90:  80 a6 20 63  cmp  %i0, 0x63
a0094d94:  18 bf ff d9  bgu  0xa0094cf8
a0094d98:  b0 14 a3 f4  or  %l2, 0x3f4, %i0
a0094d9c:  90 14 a3 f4  or  %l2, 0x3f4, %o0
a0094da0:  98 10 20 4a  mov  0x4a, %o4
a0094da4:  10 bf ff d5  b  0xa0094cf8
a0094da8:  d8 2a 20 08  stb  %o4, [ %o0 + 8 ]
a0094dac:  67 ff e1 fa  call  0x4008d594
a0094db0:  d0 14 60 34  lduh  [ %l1 + 0x34 ], %o0
a0094db4:  a3 2a 20 10  sll  %o0, 0x10, %l1
a0094db8:  9f 34 60 10  srl  %l1, 0x10, %o7
a0094dbc:  80 a3 e0 63  cmp  %o7, 0x63
a0094dc0:  18 bf ff c4  bgu  0xa0094cd0
a0094dc4:  92 10 20 46  mov  0x46, %o1
a0094dc8:  10 bf ff c2  b  0xa0094cd0
a0094dcc:  d2 2c 20 08  stb  %o1, [ %l0 + 8 ]
a0094dd0:  92 14 a3 f4  or  %l2, 0x3f4, %o1
a0094dd4:  82 10 20 42  mov  0x42, %g1
a0094dd8:  40 02 ca 53  call  0xa0147724
a0094ddc:  c2 2a 60 08  stb  %g1, [ %o1 + 8 ]
a0094de0:  10 bf ff aa  b  0xa0094c88
a0094de4:  d0 36 a0 3a  sth  %o0, [ %i2 + 0x3a ]
a0094de8:  81 c7 e0 08  ret
a0094dec:  81 e8 00 00  restore
