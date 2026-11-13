# leon2s FUN_a0062bac 0xa0062bac-0xa0062f3c (912 bytes)
a0062bac:  9d e3 bf 98  save  %sp, -104, %sp
a0062bb0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0062bb4:  c2 08 62 5b  ldub  [ %g1 + 0x25b ], %g1	! 0xa8078a5b
a0062bb8:  9a 5e 61 f4  smul  %i1, 0x1f4, %o5
a0062bbc:  80 a0 60 01  cmp  %g1, 1
a0062bc0:  81 80 00 00  mov  %g0, %y
a0062bc4:  01 00 00 00  nop
a0062bc8:  01 00 00 00  nop
a0062bcc:  01 00 00 00  nop
a0062bd0:  a8 73 40 18  udiv  %o5, %i0, %l4
a0062bd4:  12 80 00 08  bne  0xa0062bf4
a0062bd8:  a6 10 20 05  mov  5, %l3
a0062bdc:  11 2a 01 d8  sethi  %hi(0xa8076000), %o0
a0062be0:  13 27 c6 c1  sethi  %hi(0x9f1b0400), %o1
a0062be4:  90 12 21 d0  or  %o0, 0x1d0, %o0
a0062be8:  92 12 63 00  or  %o1, 0x300, %o1
a0062bec:  40 01 3a 7b  call  0xa00b15d8
a0062bf0:  94 10 20 9a  mov  0x9a, %o2
a0062bf4:  19 2a 01 d8  sethi  %hi(0xa8076000), %o4
a0062bf8:  82 13 21 d0  or  %o4, 0x1d0, %g1	! 0xa80761d0
a0062bfc:  9a 00 60 16  add  %g1, 0x16, %o5
a0062c00:  a0 10 20 00  clr  %l0
a0062c04:  c2 13 40 00  lduh  [ %o5 ], %g1
a0062c08:  80 a5 00 01  cmp  %l4, %g1
a0062c0c:  0a 80 00 12  bcs  0xa0062c54
a0062c10:  9a 03 60 16  add  %o5, 0x16, %o5
a0062c14:  a0 04 20 01  inc  %l0
a0062c18:  80 a4 20 06  cmp  %l0, 6
a0062c1c:  2a bf ff fb  bcs,a   0xa0062c08
a0062c20:  c2 13 40 00  lduh  [ %o5 ], %g1
a0062c24:  9a 5c e0 16  smul  %l3, 0x16, %o5
a0062c28:  98 13 21 d0  or  %o4, 0x1d0, %o4
a0062c2c:  82 03 40 0c  add  %o5, %o4, %g1
a0062c30:  e2 13 00 0d  lduh  [ %o4 + %o5 ], %l1
a0062c34:  e4 10 60 16  lduh  [ %g1 + 0x16 ], %l2
a0062c38:  da 10 60 02  lduh  [ %g1 + 2 ], %o5
a0062c3c:  80 a4 80 11  cmp  %l2, %l1
a0062c40:  c2 10 60 18  lduh  [ %g1 + 0x18 ], %g1
a0062c44:  02 80 00 1a  be  0xa0062cac
a0062c48:  92 10 00 0d  mov  %o5, %o1
a0062c4c:  10 80 00 04  b  0xa0062c5c
a0062c50:  80 a0 40 0d  cmp  %g1, %o5
a0062c54:  10 bf ff f4  b  0xa0062c24
a0062c58:  a6 10 00 10  mov  %l0, %l3
a0062c5c:  94 25 00 11  sub  %l4, %l1, %o2
a0062c60:  08 80 00 0b  bleu  0xa0062c8c
a0062c64:  9e 24 80 11  sub  %l2, %l1, %o7
a0062c68:  82 20 40 0d  sub  %g1, %o5, %g1
a0062c6c:  82 58 40 0a  smul  %g1, %o2, %g1
a0062c70:  81 80 00 00  mov  %g0, %y
a0062c74:  01 00 00 00  nop
a0062c78:  01 00 00 00  nop
a0062c7c:  01 00 00 00  nop
a0062c80:  82 70 40 0f  udiv  %g1, %o7, %g1
a0062c84:  10 80 00 0a  b  0xa0062cac
a0062c88:  92 00 40 0d  add  %g1, %o5, %o1
a0062c8c:  82 23 40 01  sub  %o5, %g1, %g1
a0062c90:  82 58 40 0a  smul  %g1, %o2, %g1
a0062c94:  81 80 00 00  mov  %g0, %y
a0062c98:  01 00 00 00  nop
a0062c9c:  01 00 00 00  nop
a0062ca0:  01 00 00 00  nop
a0062ca4:  82 70 40 0f  udiv  %g1, %o7, %g1
a0062ca8:  92 23 40 01  sub  %o5, %g1, %o1
a0062cac:  03 28 01 8e  sethi  %hi(0xa0063800), %g1
a0062cb0:  82 10 61 60  or  %g1, 0x160, %g1	! 0xa0063960
a0062cb4:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a0062cb8:  98 04 c0 13  add  %l3, %l3, %o4
a0062cbc:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a0062cc0:  c2 23 61 6c  st  %g1, [ %o5 + 0x16c ]
a0062cc4:  96 12 e2 a0  or  %o3, 0x2a0, %o3
a0062cc8:  82 10 20 09  mov  9, %g1
a0062ccc:  98 03 00 13  add  %o4, %l3, %o4
a0062cd0:  c2 2a e0 58  stb  %g1, [ %o3 + 0x58 ]
a0062cd4:  99 2b 20 02  sll  %o4, 2, %o4
a0062cd8:  94 5a 40 19  smul  %o1, %i1, %o2
a0062cdc:  98 23 00 13  sub  %o4, %l3, %o4
a0062ce0:  81 80 00 00  mov  %g0, %y
a0062ce4:  01 00 00 00  nop
a0062ce8:  01 00 00 00  nop
a0062cec:  01 00 00 00  nop
a0062cf0:  94 72 80 18  udiv  %o2, %i0, %o2
a0062cf4:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0062cf8:  98 03 00 0c  add  %o4, %o4, %o4
a0062cfc:  d4 32 e0 04  sth  %o2, [ %o3 + 4 ]
a0062d00:  82 10 61 d0  or  %g1, 0x1d0, %g1
a0062d04:  d2 32 e0 02  sth  %o1, [ %o3 + 2 ]
a0062d08:  98 03 00 01  add  %o4, %g1, %o4
a0062d0c:  96 02 e0 5a  add  %o3, 0x5a, %o3
a0062d10:  a0 10 20 09  mov  9, %l0
a0062d14:  d2 13 20 04  lduh  [ %o4 + 4 ], %o1
a0062d18:  80 a4 80 11  cmp  %l2, %l1
a0062d1c:  d0 13 20 1a  lduh  [ %o4 + 0x1a ], %o0
a0062d20:  82 10 00 09  mov  %o1, %g1
a0062d24:  94 25 00 11  sub  %l4, %l1, %o2
a0062d28:  02 80 00 15  be  0xa0062d7c
a0062d2c:  9e 24 80 11  sub  %l2, %l1, %o7
a0062d30:  82 22 00 09  sub  %o0, %o1, %g1
a0062d34:  9a 58 40 0a  smul  %g1, %o2, %o5
a0062d38:  82 22 40 08  sub  %o1, %o0, %g1
a0062d3c:  80 a2 00 09  cmp  %o0, %o1
a0062d40:  08 80 00 09  bleu  0xa0062d64
a0062d44:  82 58 40 0a  smul  %g1, %o2, %g1
a0062d48:  81 80 00 00  mov  %g0, %y
a0062d4c:  01 00 00 00  nop
a0062d50:  01 00 00 00  nop
a0062d54:  01 00 00 00  nop
a0062d58:  82 73 40 0f  udiv  %o5, %o7, %g1
a0062d5c:  10 80 00 08  b  0xa0062d7c
a0062d60:  82 00 40 09  add  %g1, %o1, %g1
a0062d64:  81 80 00 00  mov  %g0, %y
a0062d68:  01 00 00 00  nop
a0062d6c:  01 00 00 00  nop
a0062d70:  01 00 00 00  nop
a0062d74:  82 70 40 0f  udiv  %g1, %o7, %g1
a0062d78:  82 22 40 01  sub  %o1, %g1, %g1
a0062d7c:  c2 32 c0 00  sth  %g1, [ %o3 ]
a0062d80:  98 03 20 02  add  %o4, 2, %o4
a0062d84:  a0 84 3f ff  addcc  %l0, -1, %l0
a0062d88:  12 bf ff e3  bne  0xa0062d14
a0062d8c:  96 02 e0 02  add  %o3, 2, %o3
a0062d90:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0062d94:  82 10 62 a0  or  %g1, 0x2a0, %g1	! 0xa8078aa0
a0062d98:  82 00 60 6c  add  %g1, 0x6c, %g1
a0062d9c:  a0 10 20 09  mov  9, %l0
a0062da0:  9a 10 24 00  mov  0x400, %o5
a0062da4:  da 30 40 00  sth  %o5, [ %g1 ]
a0062da8:  a0 04 20 01  inc  %l0
a0062dac:  80 a4 20 13  cmp  %l0, 0x13
a0062db0:  08 bf ff fd  bleu  0xa0062da4
a0062db4:  82 00 60 02  add  %g1, 2, %g1
a0062db8:  15 2a 01 e2  sethi  %hi(0xa8078800), %o2
a0062dbc:  98 12 a2 a0  or  %o2, 0x2a0, %o4	! 0xa8078aa0
a0062dc0:  d6 13 20 02  lduh  [ %o4 + 2 ], %o3
a0062dc4:  03 00 00 04  sethi  %hi(0x1000), %g1
a0062dc8:  82 20 40 0b  sub  %g1, %o3, %g1
a0062dcc:  1b 04 00 00  sethi  %hi(0x10000000), %o5
a0062dd0:  93 3b 60 1f  sra  %o5, 0x1f, %o1
a0062dd4:  81 82 60 00  mov  %o1, %y
a0062dd8:  01 00 00 00  nop
a0062ddc:  01 00 00 00  nop
a0062de0:  01 00 00 00  nop
a0062de4:  9a 7b 40 01  sdiv  %o5, %g1, %o5
a0062de8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0062dec:  da 20 62 60  st  %o5, [ %g1 + 0x260 ]	! 0xa8078a60
a0062df0:  80 a2 e0 00  cmp  %o3, 0
a0062df4:  c2 13 20 04  lduh  [ %o4 + 4 ], %g1
a0062df8:  12 80 00 05  bne  0xa0062e0c
a0062dfc:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0062e00:  83 28 60 10  sll  %g1, 0x10, %g1
a0062e04:  10 80 00 0a  b  0xa0062e2c
a0062e08:  83 30 60 06  srl  %g1, 6, %g1
a0062e0c:  83 28 60 10  sll  %g1, 0x10, %g1
a0062e10:  83 30 60 06  srl  %g1, 6, %g1
a0062e14:  99 38 60 1f  sra  %g1, 0x1f, %o4
a0062e18:  81 83 20 00  mov  %o4, %y
a0062e1c:  01 00 00 00  nop
a0062e20:  01 00 00 00  nop
a0062e24:  01 00 00 00  nop
a0062e28:  82 78 40 0b  sdiv  %g1, %o3, %g1
a0062e2c:  c2 23 62 5c  st  %g1, [ %o5 + 0x25c ]
a0062e30:  82 12 a2 a0  or  %o2, 0x2a0, %g1
a0062e34:  c2 10 60 02  lduh  [ %g1 + 2 ], %g1
a0062e38:  83 30 60 04  srl  %g1, 4, %g1
a0062e3c:  80 a0 60 00  cmp  %g1, 0
a0062e40:  a2 10 20 00  clr  %l1
a0062e44:  12 80 00 07  bne  0xa0062e60
a0062e48:  a0 10 00 01  mov  %g1, %l0
a0062e4c:  7f ff ff 46  call  0xa0062b64
a0062e50:  90 10 20 08  mov  8, %o0
a0062e54:  91 32 20 0b  srl  %o0, 0xb, %o0
a0062e58:  10 80 00 05  b  0xa0062e6c
a0062e5c:  d0 36 80 00  sth  %o0, [ %i2 ]
a0062e60:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0062e64:  c2 00 62 5c  ld  [ %g1 + 0x25c ], %g1	! 0xa8078a5c
a0062e68:  c2 36 80 00  sth  %g1, [ %i2 ]
a0062e6c:  99 2c 20 10  sll  %l0, 0x10, %o4
a0062e70:  83 33 20 10  srl  %o4, 0x10, %g1
a0062e74:  96 00 60 01  add  %g1, 1, %o3
a0062e78:  a0 10 20 01  mov  1, %l0
a0062e7c:  80 a4 00 0b  cmp  %l0, %o3
a0062e80:  18 80 00 08  bgu  0xa0062ea0
a0062e84:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0062e88:  da 00 62 5c  ld  [ %g1 + 0x25c ], %o5	! 0xa8078a5c
a0062e8c:  82 04 00 10  add  %l0, %l0, %g1
a0062e90:  a0 04 20 01  inc  %l0
a0062e94:  80 a4 00 0b  cmp  %l0, %o3
a0062e98:  08 bf ff fd  bleu  0xa0062e8c
a0062e9c:  da 36 80 01  sth  %o5, [ %i2 + %g1 ]
a0062ea0:  83 33 20 10  srl  %o4, 0x10, %g1
a0062ea4:  a0 00 60 01  add  %g1, 1, %l0
a0062ea8:  80 a4 20 ff  cmp  %l0, 0xff
a0062eac:  18 80 00 0f  bgu  0xa0062ee8
a0062eb0:  83 2c 60 10  sll  %l1, 0x10, %g1
a0062eb4:  7f ff ff 2c  call  0xa0062b64
a0062eb8:  91 2c 20 04  sll  %l0, 4, %o0
a0062ebc:  91 32 20 0c  srl  %o0, 0xc, %o0
a0062ec0:  81 80 00 00  mov  %g0, %y
a0062ec4:  01 00 00 00  nop
a0062ec8:  01 00 00 00  nop
a0062ecc:  01 00 00 00  nop
a0062ed0:  90 72 00 10  udiv  %o0, %l0, %o0
a0062ed4:  82 04 00 10  add  %l0, %l0, %g1
a0062ed8:  a2 10 00 10  mov  %l0, %l1
a0062edc:  a0 04 20 01  inc  %l0
a0062ee0:  10 bf ff f2  b  0xa0062ea8
a0062ee4:  d0 36 80 01  sth  %o0, [ %i2 + %g1 ]
a0062ee8:  83 30 60 10  srl  %g1, 0x10, %g1
a0062eec:  a0 00 60 01  add  %g1, 1, %l0
a0062ef0:  80 a4 20 ff  cmp  %l0, 0xff
a0062ef4:  18 80 00 0f  bgu  0xa0062f30
a0062ef8:  82 10 24 00  mov  0x400, %g1
a0062efc:  7f ff ff 1a  call  0xa0062b64
a0062f00:  91 2c 20 04  sll  %l0, 4, %o0
a0062f04:  91 2a 20 04  sll  %o0, 4, %o0
a0062f08:  91 32 20 10  srl  %o0, 0x10, %o0
a0062f0c:  81 80 00 00  mov  %g0, %y
a0062f10:  01 00 00 00  nop
a0062f14:  01 00 00 00  nop
a0062f18:  01 00 00 00  nop
a0062f1c:  90 72 00 10  udiv  %o0, %l0, %o0
a0062f20:  82 04 00 10  add  %l0, %l0, %g1
a0062f24:  a0 04 20 01  inc  %l0
a0062f28:  10 bf ff f2  b  0xa0062ef0
a0062f2c:  d0 36 80 01  sth  %o0, [ %i2 + %g1 ]
a0062f30:  c2 36 a2 00  sth  %g1, [ %i2 + 0x200 ]
a0062f34:  81 c7 e0 08  ret
a0062f38:  81 e8 00 00  restore
