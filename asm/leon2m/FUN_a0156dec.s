# leon2m FUN_a0156dec 0xa0156dec-0xa0156f34 (328 bytes)
a0156dec:  c2 02 00 00  ld  [ %o0 ], %g1
a0156df0:  80 a0 60 01  cmp  %g1, 1
a0156df4:  d6 02 20 0c  ld  [ %o0 + 0xc ], %o3
a0156df8:  d8 02 20 04  ld  [ %o0 + 4 ], %o4
a0156dfc:  18 80 00 06  bgu  0xa0156e14
a0156e00:  94 10 20 00  clr  %o2
a0156e04:  03 00 04 00  sethi  %hi(0x100000), %g1
a0156e08:  96 12 c0 01  or  %o3, %g1, %o3
a0156e0c:  10 80 00 42  b  0xa0156f14
a0156e10:  94 10 20 ff  mov  0xff, %o2
a0156e14:  80 a0 60 04  cmp  %g1, 4
a0156e18:  12 80 00 05  bne  0xa0156e2c
a0156e1c:  80 a0 60 02  cmp  %g1, 2
a0156e20:  94 10 20 ff  mov  0xff, %o2
a0156e24:  10 80 00 3c  b  0xa0156f14
a0156e28:  96 10 20 00  clr  %o3
a0156e2c:  22 80 00 3a  be,a   0xa0156f14
a0156e30:  96 10 20 00  clr  %o3
a0156e34:  80 a2 e0 00  cmp  %o3, 0
a0156e38:  02 80 00 38  be  0xa0156f18
a0156e3c:  9a 0a a0 ff  and  %o2, 0xff, %o5
a0156e40:  d0 02 20 08  ld  [ %o0 + 8 ], %o0
a0156e44:  80 a2 3f 82  cmp  %o0, -126
a0156e48:  16 80 00 14  bge  0xa0156e98
a0156e4c:  80 a2 20 7f  cmp  %o0, 0x7f
a0156e50:  82 10 3f 82  mov  -126, %g1
a0156e54:  90 20 40 08  sub  %g1, %o0, %o0
a0156e58:  80 a2 20 19  cmp  %o0, 0x19
a0156e5c:  04 80 00 1d  ble  0xa0156ed0
a0156e60:  82 10 20 01  mov  1, %g1
a0156e64:  96 10 20 00  clr  %o3
a0156e68:  82 0a e0 7f  and  %o3, 0x7f, %g1
a0156e6c:  80 a0 60 40  cmp  %g1, 0x40
a0156e70:  02 80 00 20  be  0xa0156ef0
a0156e74:  80 8a e0 80  btst  0x80, %o3
a0156e78:  96 02 e0 3f  add  %o3, 0x3f, %o3
a0156e7c:  03 0f ff ff  sethi  %hi(0x3ffffc00), %g1
a0156e80:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0x3fffffff
a0156e84:  80 a2 c0 01  cmp  %o3, %g1
a0156e88:  38 80 00 02  bgu,a   0xa0156e90
a0156e8c:  94 10 20 01  mov  1, %o2
a0156e90:  10 80 00 21  b  0xa0156f14
a0156e94:  97 32 e0 07  srl  %o3, 7, %o3
a0156e98:  14 bf ff e3  bg  0xa0156e24
a0156e9c:  94 10 20 ff  mov  0xff, %o2
a0156ea0:  82 0a e0 7f  and  %o3, 0x7f, %g1
a0156ea4:  80 a0 60 40  cmp  %g1, 0x40
a0156ea8:  02 80 00 16  be  0xa0156f00
a0156eac:  94 02 20 7f  add  %o0, 0x7f, %o2
a0156eb0:  96 02 e0 3f  add  %o3, 0x3f, %o3
a0156eb4:  80 a2 e0 00  cmp  %o3, 0
a0156eb8:  36 80 00 17  bge,a   0xa0156f14
a0156ebc:  97 32 e0 07  srl  %o3, 7, %o3
a0156ec0:  97 32 e0 01  srl  %o3, 1, %o3
a0156ec4:  94 02 a0 01  inc  %o2
a0156ec8:  10 80 00 13  b  0xa0156f14
a0156ecc:  97 32 e0 07  srl  %o3, 7, %o3
a0156ed0:  83 28 40 08  sll  %g1, %o0, %g1
a0156ed4:  82 00 7f ff  add  %g1, -1, %g1
a0156ed8:  82 08 40 0b  and  %g1, %o3, %g1
a0156edc:  80 a0 00 01  cmp  %g0, %g1
a0156ee0:  9b 32 c0 08  srl  %o3, %o0, %o5
a0156ee4:  82 40 20 00  addx  %g0, 0, %g1
a0156ee8:  10 bf ff e0  b  0xa0156e68
a0156eec:  96 13 40 01  or  %o5, %g1, %o3
a0156ef0:  32 bf ff e3  bne,a   0xa0156e7c
a0156ef4:  96 02 e0 40  add  %o3, 0x40, %o3
a0156ef8:  10 bf ff e2  b  0xa0156e80
a0156efc:  03 0f ff ff  sethi  %hi(0x3ffffc00), %g1
a0156f00:  80 8a e0 80  btst  0x80, %o3
a0156f04:  32 bf ff ec  bne,a   0xa0156eb4
a0156f08:  96 02 e0 40  add  %o3, 0x40, %o3
a0156f0c:  10 bf ff eb  b  0xa0156eb8
a0156f10:  80 a2 e0 00  cmp  %o3, 0
a0156f14:  9a 0a a0 ff  and  %o2, 0xff, %o5
a0156f18:  03 3f e0 00  sethi  %hi(0xff800000), %g1
a0156f1c:  82 2a c0 01  andn  %o3, %g1, %g1
a0156f20:  9b 2b 60 17  sll  %o5, 0x17, %o5
a0156f24:  82 10 40 0d  or  %g1, %o5, %g1
a0156f28:  99 2b 20 1f  sll  %o4, 0x1f, %o4
a0156f2c:  81 c3 e0 08  retl
a0156f30:  90 10 40 0c  or  %g1, %o4, %o0
