# leon2s FUN_a00b0e54 0xa00b0e54-0xa00b1028 (468 bytes)
a00b0e54:  9d e3 bf 88  save  %sp, -120, %sp
a00b0e58:  13 28 02 d3  sethi  %hi(0xa00b4c00), %o1
a00b0e5c:  92 12 62 0c  or  %o1, 0x20c, %o1	! 0xa00b4e0c
a00b0e60:  94 10 20 08  mov  8, %o2
a00b0e64:  40 00 01 dd  call  0xa00b15d8
a00b0e68:  90 07 bf f0  add  %fp, -16, %o0
a00b0e6c:  13 28 02 d3  sethi  %hi(0xa00b4c00), %o1
a00b0e70:  92 12 62 14  or  %o1, 0x214, %o1	! 0xa00b4e14
a00b0e74:  90 07 bf e8  add  %fp, -24, %o0
a00b0e78:  40 00 01 d8  call  0xa00b15d8
a00b0e7c:  94 10 20 08  mov  8, %o2
a00b0e80:  a6 10 20 00  clr  %l3
a00b0e84:  a4 10 20 00  clr  %l2
a00b0e88:  29 2a 01 e1  sethi  %hi(0xa8078400), %l4
a00b0e8c:  82 15 23 68  or  %l4, 0x368, %g1	! 0xa8078768
a00b0e90:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00b0e94:  da 08 40 11  ldub  [ %g1 + %l1 ], %o5
a00b0e98:  82 07 bf f8  add  %fp, -8, %g1
a00b0e9c:  a0 00 40 0d  add  %g1, %o5, %l0
a00b0ea0:  82 0c e0 ff  and  %l3, 0xff, %g1
a00b0ea4:  80 a3 40 01  cmp  %o5, %g1
a00b0ea8:  12 80 00 0f  bne  0xa00b0ee4
a00b0eac:  98 04 a0 04  add  %l2, 4, %o4
a00b0eb0:  7f ff 4c 05  call  0xa0083ec4
a00b0eb4:  d8 2c 3f f8  stb  %o4, [ %l0 + -8 ]
a00b0eb8:  80 8a 20 ff  btst  0xff, %o0
a00b0ebc:  02 80 00 06  be  0xa00b0ed4
a00b0ec0:  80 a4 60 03  cmp  %l1, 3
a00b0ec4:  28 80 00 07  bleu,a   0xa00b0ee0
a00b0ec8:  82 10 20 06  mov  6, %g1
a00b0ecc:  10 80 00 05  b  0xa00b0ee0
a00b0ed0:  82 10 20 04  mov  4, %g1
a00b0ed4:  38 80 00 03  bgu,a   0xa00b0ee0
a00b0ed8:  82 10 20 06  mov  6, %g1
a00b0edc:  82 10 20 04  mov  4, %g1
a00b0ee0:  c2 2c 3f f0  stb  %g1, [ %l0 + -16 ]
a00b0ee4:  a4 04 a0 01  inc  %l2
a00b0ee8:  82 0c a0 ff  and  %l2, 0xff, %g1
a00b0eec:  80 a0 60 04  cmp  %g1, 4
a00b0ef0:  28 bf ff e7  bleu,a   0xa00b0e8c
a00b0ef4:  29 2a 01 e1  sethi  %hi(0xa8078400), %l4
a00b0ef8:  a6 04 e0 01  inc  %l3
a00b0efc:  82 0c e0 ff  and  %l3, 0xff, %g1
a00b0f00:  80 a0 60 07  cmp  %g1, 7
a00b0f04:  28 bf ff e1  bleu,a   0xa00b0e88
a00b0f08:  a4 10 20 00  clr  %l2
a00b0f0c:  c2 0f bf e9  ldub  [ %fp + -23 ], %g1
a00b0f10:  da 0f bf e8  ldub  [ %fp + -24 ], %o5
a00b0f14:  83 28 60 04  sll  %g1, 4, %g1
a00b0f18:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00b0f1c:  82 10 40 0d  or  %g1, %o5, %g1
a00b0f20:  9a 12 a3 c0  or  %o2, 0x3c0, %o5
a00b0f24:  c2 23 40 00  st  %g1, [ %o5 ]
a00b0f28:  c2 0f bf eb  ldub  [ %fp + -21 ], %g1
a00b0f2c:  da 0f bf ea  ldub  [ %fp + -22 ], %o5
a00b0f30:  83 28 60 04  sll  %g1, 4, %g1
a00b0f34:  82 10 40 0d  or  %g1, %o5, %g1
a00b0f38:  9a 12 a3 c4  or  %o2, 0x3c4, %o5
a00b0f3c:  c2 23 40 00  st  %g1, [ %o5 ]
a00b0f40:  c2 0f bf ed  ldub  [ %fp + -19 ], %g1
a00b0f44:  da 0f bf ec  ldub  [ %fp + -20 ], %o5
a00b0f48:  83 28 60 04  sll  %g1, 4, %g1
a00b0f4c:  82 10 40 0d  or  %g1, %o5, %g1
a00b0f50:  9a 12 a3 c8  or  %o2, 0x3c8, %o5
a00b0f54:  c2 23 40 00  st  %g1, [ %o5 ]
a00b0f58:  c2 0f bf ef  ldub  [ %fp + -17 ], %g1
a00b0f5c:  da 0f bf ee  ldub  [ %fp + -18 ], %o5
a00b0f60:  83 28 60 04  sll  %g1, 4, %g1
a00b0f64:  82 10 40 0d  or  %g1, %o5, %g1
a00b0f68:  9a 12 a3 cc  or  %o2, 0x3cc, %o5
a00b0f6c:  c2 23 40 00  st  %g1, [ %o5 ]
a00b0f70:  c2 0f bf f1  ldub  [ %fp + -15 ], %g1
a00b0f74:  da 0f bf f0  ldub  [ %fp + -16 ], %o5
a00b0f78:  83 28 60 04  sll  %g1, 4, %g1
a00b0f7c:  82 10 40 0d  or  %g1, %o5, %g1
a00b0f80:  9a 12 a3 d0  or  %o2, 0x3d0, %o5
a00b0f84:  c2 23 40 00  st  %g1, [ %o5 ]
a00b0f88:  c2 0f bf f3  ldub  [ %fp + -13 ], %g1
a00b0f8c:  da 0f bf f2  ldub  [ %fp + -14 ], %o5
a00b0f90:  83 28 60 04  sll  %g1, 4, %g1
a00b0f94:  82 10 40 0d  or  %g1, %o5, %g1
a00b0f98:  9a 12 a3 d4  or  %o2, 0x3d4, %o5
a00b0f9c:  c2 23 40 00  st  %g1, [ %o5 ]
a00b0fa0:  c2 0f bf f5  ldub  [ %fp + -11 ], %g1
a00b0fa4:  da 0f bf f4  ldub  [ %fp + -12 ], %o5
a00b0fa8:  83 28 60 04  sll  %g1, 4, %g1
a00b0fac:  82 10 40 0d  or  %g1, %o5, %g1
a00b0fb0:  9a 12 a3 d8  or  %o2, 0x3d8, %o5
a00b0fb4:  c2 23 40 00  st  %g1, [ %o5 ]
a00b0fb8:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00b0fbc:  d8 0f bf f6  ldub  [ %fp + -10 ], %o4
a00b0fc0:  83 28 60 04  sll  %g1, 4, %g1
a00b0fc4:  92 15 23 68  or  %l4, 0x368, %o1
a00b0fc8:  82 10 40 0c  or  %g1, %o4, %g1
a00b0fcc:  d6 0a 60 02  ldub  [ %o1 + 2 ], %o3
a00b0fd0:  da 0a 60 03  ldub  [ %o1 + 3 ], %o5
a00b0fd4:  98 12 a3 dc  or  %o2, 0x3dc, %o4
a00b0fd8:  c2 23 00 00  st  %g1, [ %o4 ]
a00b0fdc:  9b 2b 60 04  sll  %o5, 4, %o5
a00b0fe0:  d8 0a 60 01  ldub  [ %o1 + 1 ], %o4
a00b0fe4:  9a 13 40 0b  or  %o5, %o3, %o5
a00b0fe8:  82 12 a3 e0  or  %o2, 0x3e0, %g1
a00b0fec:  da 20 40 00  st  %o5, [ %g1 ]
a00b0ff0:  d6 0d 23 68  ldub  [ %l4 + 0x368 ], %o3
a00b0ff4:  9a 12 a3 e4  or  %o2, 0x3e4, %o5
a00b0ff8:  82 10 20 13  mov  0x13, %g1
a00b0ffc:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1000:  99 2b 20 04  sll  %o4, 4, %o4
a00b1004:  da 0a 60 04  ldub  [ %o1 + 4 ], %o5
a00b1008:  82 12 a3 e8  or  %o2, 0x3e8, %g1
a00b100c:  98 13 00 0b  or  %o4, %o3, %o4
a00b1010:  d8 20 40 00  st  %o4, [ %g1 ]
a00b1014:  94 12 a3 ec  or  %o2, 0x3ec, %o2
a00b1018:  9a 13 60 70  or  %o5, 0x70, %o5
a00b101c:  da 22 80 00  st  %o5, [ %o2 ]
a00b1020:  81 c7 e0 08  ret
a00b1024:  81 e8 00 00  restore
