# leon2m FUN_a0093d30 0xa0093d30-0xa0093f90 (608 bytes)
a0093d30:  9d e3 bf 98  save  %sp, -104, %sp
a0093d34:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a0093d38:  67 ff e6 17  call  0x4008d594
a0093d3c:  d0 14 a0 34  lduh  [ %l2 + 0x34 ], %o0	! 0xa802d034
a0093d40:  83 2a 20 10  sll  %o0, 0x10, %g1
a0093d44:  91 30 60 10  srl  %g1, 0x10, %o0
a0093d48:  80 a2 20 64  cmp  %o0, 0x64
a0093d4c:  a6 10 00 12  mov  %l2, %l3
a0093d50:  29 2a 00 b3  sethi  %hi(0xa802cc00), %l4
a0093d54:  18 80 00 28  bgu  0xa0093df4
a0093d58:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a0093d5c:  40 02 ce 72  call  0xa0147724
a0093d60:  a0 15 23 f4  or  %l4, 0x3f4, %l0
a0093d64:  d6 0c 20 08  ldub  [ %l0 + 8 ], %o3
a0093d68:  95 32 e0 04  srl  %o3, 4, %o2
a0093d6c:  80 a2 a0 01  cmp  %o2, 1
a0093d70:  02 80 00 06  be  0xa0093d88
a0093d74:  d0 34 e0 34  sth  %o0, [ %l3 + 0x34 ]
a0093d78:  98 10 20 18  mov  0x18, %o4
a0093d7c:  40 02 ce 6a  call  0xa0147724
a0093d80:  d8 2c 20 08  stb  %o4, [ %l0 + 8 ]
a0093d84:  d0 34 60 3a  sth  %o0, [ %l1 + 0x3a ]
a0093d88:  67 ff e6 03  call  0x4008d594
a0093d8c:  d0 14 60 3a  lduh  [ %l1 + 0x3a ], %o0
a0093d90:  91 2a 20 10  sll  %o0, 0x10, %o0
a0093d94:  9f 32 20 10  srl  %o0, 0x10, %o7
a0093d98:  80 a3 e7 d0  cmp  %o7, 0x7d0
a0093d9c:  18 80 00 3a  bgu  0xa0093e84
a0093da0:  01 00 00 00  nop
a0093da4:  67 ff e5 fc  call  0x4008d594
a0093da8:  d0 14 60 3a  lduh  [ %l1 + 0x3a ], %o0
a0093dac:  95 2a 20 10  sll  %o0, 0x10, %o2
a0093db0:  13 00 00 04  sethi  %hi(0x1000), %o1
a0093db4:  a3 32 a0 10  srl  %o2, 0x10, %l1
a0093db8:  a0 12 63 88  or  %o1, 0x388, %l0
a0093dbc:  80 a4 40 10  cmp  %l1, %l0
a0093dc0:  18 80 00 26  bgu  0xa0093e58
a0093dc4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0093dc8:  a2 12 22 90  or  %o0, 0x290, %l1	! 0xa802d290
a0093dcc:  c2 0c 60 31  ldub  [ %l1 + 0x31 ], %g1
a0093dd0:  80 a0 60 00  cmp  %g1, 0
a0093dd4:  02 80 00 0e  be  0xa0093e0c
a0093dd8:  80 a0 60 01  cmp  %g1, 1
a0093ddc:  02 80 00 33  be  0xa0093ea8
a0093de0:  80 a0 60 02  cmp  %g1, 2
a0093de4:  12 80 00 63  bne  0xa0093f70
a0093de8:  a4 15 23 f4  or  %l4, 0x3f4, %l2
a0093dec:  10 80 00 4f  b  0xa0093f28
a0093df0:  e6 0c a0 08  ldub  [ %l2 + 8 ], %l3
a0093df4:  9a 15 23 f4  or  %l4, 0x3f4, %o5
a0093df8:  92 10 20 18  mov  0x18, %o1
a0093dfc:  40 02 ce 4a  call  0xa0147724
a0093e00:  d2 2b 60 08  stb  %o1, [ %o5 + 8 ]
a0093e04:  10 bf ff d6  b  0xa0093d5c
a0093e08:  d0 34 60 3a  sth  %o0, [ %l1 + 0x3a ]
a0093e0c:  a4 15 23 f4  or  %l4, 0x3f4, %l2
a0093e10:  d4 0c a0 08  ldub  [ %l2 + 8 ], %o2
a0093e14:  92 0a a0 0f  and  %o2, 0xf, %o1
a0093e18:  e0 14 60 54  lduh  [ %l1 + 0x54 ], %l0
a0093e1c:  a6 04 00 09  add  %l0, %o1, %l3
a0093e20:  40 02 d1 57  call  0xa014837c
a0093e24:  90 10 20 00  clr  %o0
a0093e28:  9b 2a 20 10  sll  %o0, 0x10, %o5
a0093e2c:  83 33 60 10  srl  %o5, 0x10, %g1
a0093e30:  a8 00 79 40  add  %g1, -1728, %l4
a0093e34:  80 a4 c0 14  cmp  %l3, %l4
a0093e38:  34 80 00 30  bg,a   0xa0093ef8
a0093e3c:  e0 14 60 54  lduh  [ %l1 + 0x54 ], %l0
a0093e40:  c2 0c a0 08  ldub  [ %l2 + 8 ], %g1
a0093e44:  da 14 60 54  lduh  [ %l1 + 0x54 ], %o5
a0093e48:  a4 08 60 0f  and  %g1, 0xf, %l2
a0093e4c:  82 04 80 0d  add  %l2, %o5, %g1
a0093e50:  10 80 00 48  b  0xa0093f70
a0093e54:  c2 34 60 54  sth  %g1, [ %l1 + 0x54 ]
a0093e58:  67 ff e5 cf  call  0x4008d594
a0093e5c:  d0 14 a0 34  lduh  [ %l2 + 0x34 ], %o0
a0093e60:  97 2a 20 10  sll  %o0, 0x10, %o3
a0093e64:  a5 32 e0 10  srl  %o3, 0x10, %l2
a0093e68:  80 a4 a0 63  cmp  %l2, 0x63
a0093e6c:  18 bf ff d7  bgu  0xa0093dc8
a0093e70:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0093e74:  98 15 23 f4  or  %l4, 0x3f4, %o4
a0093e78:  9e 10 20 18  mov  0x18, %o7
a0093e7c:  10 bf ff d3  b  0xa0093dc8
a0093e80:  de 2b 20 08  stb  %o7, [ %o4 + 8 ]
a0093e84:  67 ff e5 c4  call  0x4008d594
a0093e88:  d0 14 e0 34  lduh  [ %l3 + 0x34 ], %o0
a0093e8c:  83 2a 20 10  sll  %o0, 0x10, %g1
a0093e90:  a7 30 60 10  srl  %g1, 0x10, %l3
a0093e94:  80 a4 e0 63  cmp  %l3, 0x63
a0093e98:  18 bf ff c3  bgu  0xa0093da4
a0093e9c:  9a 10 20 18  mov  0x18, %o5
a0093ea0:  10 bf ff c1  b  0xa0093da4
a0093ea4:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a0093ea8:  a4 15 23 f4  or  %l4, 0x3f4, %l2
a0093eac:  da 0c a0 08  ldub  [ %l2 + 8 ], %o5
a0093eb0:  82 0b 60 0f  and  %o5, 0xf, %g1
a0093eb4:  e6 14 60 54  lduh  [ %l1 + 0x54 ], %l3
a0093eb8:  a8 04 c0 01  add  %l3, %g1, %l4
a0093ebc:  40 02 d1 30  call  0xa014837c
a0093ec0:  90 10 20 00  clr  %o0
a0093ec4:  91 2a 20 10  sll  %o0, 0x10, %o0
a0093ec8:  9f 32 20 10  srl  %o0, 0x10, %o7
a0093ecc:  98 03 fa c0  add  %o7, -1344, %o4
a0093ed0:  80 a5 00 0c  cmp  %l4, %o4
a0093ed4:  24 bf ff dc  ble,a   0xa0093e44
a0093ed8:  c2 0c a0 08  ldub  [ %l2 + 8 ], %g1
a0093edc:  e0 14 60 54  lduh  [ %l1 + 0x54 ], %l0
a0093ee0:  40 02 d1 27  call  0xa014837c
a0093ee4:  90 10 20 00  clr  %o0
a0093ee8:  95 2a 20 10  sll  %o0, 0x10, %o2
a0093eec:  93 32 a0 10  srl  %o2, 0x10, %o1
a0093ef0:  10 80 00 07  b  0xa0093f0c
a0093ef4:  90 02 7a c0  add  %o1, -1344, %o0
a0093ef8:  40 02 d1 21  call  0xa014837c
a0093efc:  90 10 20 00  clr  %o0
a0093f00:  97 2a 20 10  sll  %o0, 0x10, %o3
a0093f04:  a5 32 e0 10  srl  %o3, 0x10, %l2
a0093f08:  90 04 b9 40  add  %l2, -1728, %o0
a0093f0c:  80 a4 00 08  cmp  %l0, %o0
a0093f10:  16 80 00 18  bge  0xa0093f70
a0093f14:  01 00 00 00  nop
a0093f18:  d6 14 60 54  lduh  [ %l1 + 0x54 ], %o3
a0093f1c:  82 02 e0 02  add  %o3, 2, %g1
a0093f20:  10 80 00 14  b  0xa0093f70
a0093f24:  c2 34 60 54  sth  %g1, [ %l1 + 0x54 ]
a0093f28:  90 0c e0 0f  and  %l3, 0xf, %o0
a0093f2c:  de 14 60 54  lduh  [ %l1 + 0x54 ], %o7
a0093f30:  a0 03 c0 08  add  %o7, %o0, %l0
a0093f34:  40 02 d1 12  call  0xa014837c
a0093f38:  90 10 20 00  clr  %o0
a0093f3c:  a9 2a 20 10  sll  %o0, 0x10, %l4
a0093f40:  99 35 20 10  srl  %l4, 0x10, %o4
a0093f44:  96 03 3c 40  add  %o4, -960, %o3
a0093f48:  80 a4 00 0b  cmp  %l0, %o3
a0093f4c:  24 bf ff be  ble,a   0xa0093e44
a0093f50:  c2 0c a0 08  ldub  [ %l2 + 8 ], %g1
a0093f54:  e0 14 60 54  lduh  [ %l1 + 0x54 ], %l0
a0093f58:  40 02 d1 09  call  0xa014837c
a0093f5c:  90 10 20 00  clr  %o0
a0093f60:  95 2a 20 10  sll  %o0, 0x10, %o2
a0093f64:  93 32 a0 10  srl  %o2, 0x10, %o1
a0093f68:  10 bf ff e9  b  0xa0093f0c
a0093f6c:  90 02 7c 40  add  %o1, -960, %o0
a0093f70:  40 01 0e c0  call  0xa00d7a70
a0093f74:  90 10 20 00  clr  %o0
a0093f78:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a0093f7c:  d8 0c 60 8e  ldub  [ %l1 + 0x8e ], %o4	! 0xa802b08e
a0093f80:  a0 13 20 02  or  %o4, 2, %l0
a0093f84:  e0 2c 60 8e  stb  %l0, [ %l1 + 0x8e ]
a0093f88:  81 c7 e0 08  ret
a0093f8c:  81 e8 00 00  restore
