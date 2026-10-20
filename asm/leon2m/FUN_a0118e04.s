# leon2m FUN_a0118e04 0xa0118e04-0xa011909c (664 bytes)
a0118e04:  9d e3 bf 58  save  %sp, -168, %sp
a0118e08:  d6 06 00 00  ld  [ %i0 ], %o3
a0118e0c:  21 2a 00 9e  sethi  %hi(0xa8027800), %l0
a0118e10:  d6 24 22 98  st  %o3, [ %l0 + 0x298 ]	! 0xa8027a98
a0118e14:  d2 06 20 04  ld  [ %i0 + 4 ], %o1
a0118e18:  a2 14 22 98  or  %l0, 0x298, %l1
a0118e1c:  d2 24 60 04  st  %o1, [ %l1 + 4 ]
a0118e20:  d0 06 20 08  ld  [ %i0 + 8 ], %o0
a0118e24:  d0 24 60 08  st  %o0, [ %l1 + 8 ]
a0118e28:  da 06 20 0c  ld  [ %i0 + 0xc ], %o5
a0118e2c:  da 24 60 0c  st  %o5, [ %l1 + 0xc ]
a0118e30:  90 10 20 08  mov  8, %o0
a0118e34:  92 10 20 1a  mov  0x1a, %o1
a0118e38:  7f ff 67 55  call  0xa00f2b8c
a0118e3c:  94 10 20 00  clr  %o2
a0118e40:  94 10 20 00  clr  %o2
a0118e44:  90 10 20 08  mov  8, %o0
a0118e48:  7f ff 67 51  call  0xa00f2b8c
a0118e4c:  92 10 20 1b  mov  0x1b, %o1
a0118e50:  92 10 20 10  mov  0x10, %o1
a0118e54:  7f ff 67 3d  call  0xa00f2b48
a0118e58:  90 10 20 08  mov  8, %o0
a0118e5c:  94 12 20 01  or  %o0, 1, %o2
a0118e60:  94 0a a0 ff  and  %o2, 0xff, %o2
a0118e64:  90 10 20 08  mov  8, %o0
a0118e68:  7f ff 67 49  call  0xa00f2b8c
a0118e6c:  92 10 20 10  mov  0x10, %o1
a0118e70:  c2 04 22 98  ld  [ %l0 + 0x298 ], %g1
a0118e74:  80 a0 60 00  cmp  %g1, 0
a0118e78:  16 80 00 87  bge  0xa0119094
a0118e7c:  b0 10 00 10  mov  %l0, %i0
a0118e80:  19 00 06 8b  sethi  %hi(0x1a2c00), %o4
a0118e84:  92 13 23 2f  or  %o4, 0x32f, %o1	! 0x1a2f2f
a0118e88:  94 10 20 1e  mov  0x1e, %o2
a0118e8c:  40 00 8e a1  call  0xa013c910
a0118e90:  90 07 bf d8  add  %fp, -40, %o0
a0118e94:  90 10 20 00  clr  %o0
a0118e98:  7f ff 64 41  call  0xa00f1f9c
a0118e9c:  92 10 20 29  mov  0x29, %o1
a0118ea0:  80 8a 20 04  btst  4, %o0
a0118ea4:  02 80 00 38  be  0xa0118f84
a0118ea8:  98 10 20 20  mov  0x20, %o4
a0118eac:  e0 04 60 08  ld  [ %l1 + 8 ], %l0
a0118eb0:  80 a4 20 00  cmp  %l0, 0
a0118eb4:  12 80 00 39  bne  0xa0118f98
a0118eb8:  15 00 2d c6  sethi  %hi(0xb71800), %o2
a0118ebc:  23 33 c0 4b  sethi  %hi(0xcf012c00), %l1
a0118ec0:  9e 14 63 d8  or  %l1, 0x3d8, %o7	! 0xcf012fd8
a0118ec4:  96 10 20 00  clr  %o3
a0118ec8:  98 10 20 00  clr  %o4
a0118ecc:  90 07 bf f8  add  %fp, -8, %o0
a0118ed0:  92 14 63 d0  or  %l1, 0x3d0, %o1
a0118ed4:  94 14 63 d4  or  %l1, 0x3d4, %o2
a0118ed8:  9a 03 00 0c  add  %o4, %o4, %o5
a0118edc:  a0 03 40 08  add  %o5, %o0, %l0
a0118ee0:  a3 2b 20 04  sll  %o4, 4, %l1
a0118ee4:  e2 22 40 00  st  %l1, [ %o1 ]
a0118ee8:  c2 0c 3f e0  ldub  [ %l0 + -32 ], %g1
a0118eec:  96 02 e0 01  inc  %o3
a0118ef0:  c2 22 80 00  st  %g1, [ %o2 ]
a0118ef4:  e4 0c 3f e1  ldub  [ %l0 + -31 ], %l2
a0118ef8:  98 0a e0 ff  and  %o3, 0xff, %o4
a0118efc:  e4 23 c0 00  st  %l2, [ %o7 ]
a0118f00:  80 a3 20 0e  cmp  %o4, 0xe
a0118f04:  08 bf ff f6  bleu  0xa0118edc
a0118f08:  9a 03 00 0c  add  %o4, %o4, %o5
a0118f0c:  13 00 06 8b  sethi  %hi(0x1a2c00), %o1
a0118f10:  92 12 63 4d  or  %o1, 0x34d, %o1	! 0x1a2f4d
a0118f14:  90 07 bf b8  add  %fp, -72, %o0
a0118f18:  40 00 8e 7e  call  0xa013c910
a0118f1c:  94 10 20 20  mov  0x20, %o2
a0118f20:  a0 16 22 98  or  %i0, 0x298, %l0
a0118f24:  f0 04 20 08  ld  [ %l0 + 8 ], %i0
a0118f28:  80 a6 20 00  cmp  %i0, 0
a0118f2c:  12 80 00 48  bne  0xa011904c
a0118f30:  1f 33 c0 4b  sethi  %hi(0xcf012c00), %o7
a0118f34:  21 33 c0 4b  sethi  %hi(0xcf012c00), %l0
a0118f38:  9e 14 23 e8  or  %l0, 0x3e8, %o7	! 0xcf012fe8
a0118f3c:  96 10 20 00  clr  %o3
a0118f40:  90 07 bf f8  add  %fp, -8, %o0
a0118f44:  9a 10 20 00  clr  %o5
a0118f48:  92 14 23 e0  or  %l0, 0x3e0, %o1
a0118f4c:  94 14 23 e4  or  %l0, 0x3e4, %o2
a0118f50:  a2 03 40 0d  add  %o5, %o5, %l1
a0118f54:  da 22 40 00  st  %o5, [ %o1 ]
a0118f58:  a4 04 40 08  add  %l1, %o0, %l2
a0118f5c:  da 0c bf c0  ldub  [ %l2 + -64 ], %o5
a0118f60:  da 22 80 00  st  %o5, [ %o2 ]
a0118f64:  96 02 e0 01  inc  %o3
a0118f68:  d8 0c bf c1  ldub  [ %l2 + -63 ], %o4
a0118f6c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0118f70:  d8 23 c0 00  st  %o4, [ %o7 ]
a0118f74:  80 a3 60 0f  cmp  %o5, 0xf
a0118f78:  08 bf ff f7  bleu  0xa0118f54
a0118f7c:  a2 03 40 0d  add  %o5, %o5, %l1
a0118f80:  30 80 00 45  b,a   0xa0119094
a0118f84:  e0 04 60 08  ld  [ %l1 + 8 ], %l0
a0118f88:  80 a4 20 00  cmp  %l0, 0
a0118f8c:  02 bf ff cc  be  0xa0118ebc
a0118f90:  98 10 21 00  mov  0x100, %o4
a0118f94:  15 00 2d c6  sethi  %hi(0xb71800), %o2
a0118f98:  9e 0b 21 20  and  %o4, 0x120, %o7
a0118f9c:  90 12 a3 00  or  %o2, 0x300, %o0
a0118fa0:  25 33 c0 4b  sethi  %hi(0xcf012c00), %l2
a0118fa4:  97 3a 20 1f  sra  %o0, 0x1f, %o3
a0118fa8:  81 82 e0 00  mov  %o3, %y
a0118fac:  01 00 00 00  nop
a0118fb0:  01 00 00 00  nop
a0118fb4:  01 00 00 00  nop
a0118fb8:  94 7a 00 0f  sdiv  %o0, %o7, %o2
a0118fbc:  9e 14 a3 d8  or  %l2, 0x3d8, %o7
a0118fc0:  96 10 20 00  clr  %o3
a0118fc4:  98 10 20 00  clr  %o4
a0118fc8:  90 14 a3 d0  or  %l2, 0x3d0, %o0
a0118fcc:  92 14 a3 d4  or  %l2, 0x3d4, %o1
a0118fd0:  82 03 00 0c  add  %o4, %o4, %g1
a0118fd4:  e2 14 00 01  lduh  [ %l0 + %g1 ], %l1
a0118fd8:  a5 3a a0 1f  sra  %o2, 0x1f, %l2
a0118fdc:  81 84 a0 00  mov  %l2, %y
a0118fe0:  01 00 00 00  nop
a0118fe4:  01 00 00 00  nop
a0118fe8:  01 00 00 00  nop
a0118fec:  9a 7a 80 11  sdiv  %o2, %l1, %o5
a0118ff0:  a5 2b 20 04  sll  %o4, 4, %l2
a0118ff4:  a3 2b 60 10  sll  %o5, 0x10, %l1
a0118ff8:  e4 22 00 00  st  %l2, [ %o0 ]
a0118ffc:  99 34 60 18  srl  %l1, 0x18, %o4
a0119000:  d8 22 40 00  st  %o4, [ %o1 ]
a0119004:  96 02 e0 01  inc  %o3
a0119008:  82 0b 60 ff  and  %o5, 0xff, %g1
a011900c:  98 0a e0 ff  and  %o3, 0xff, %o4
a0119010:  c2 23 c0 00  st  %g1, [ %o7 ]
a0119014:  80 a3 20 0e  cmp  %o4, 0xe
a0119018:  08 bf ff ef  bleu  0xa0118fd4
a011901c:  82 03 00 0c  add  %o4, %o4, %g1
a0119020:  13 00 06 8b  sethi  %hi(0x1a2c00), %o1
a0119024:  92 12 63 4d  or  %o1, 0x34d, %o1	! 0x1a2f4d
a0119028:  90 07 bf b8  add  %fp, -72, %o0
a011902c:  40 00 8e 39  call  0xa013c910
a0119030:  94 10 20 20  mov  0x20, %o2
a0119034:  a0 16 22 98  or  %i0, 0x298, %l0
a0119038:  f0 04 20 08  ld  [ %l0 + 8 ], %i0
a011903c:  80 a6 20 00  cmp  %i0, 0
a0119040:  22 bf ff be  be,a   0xa0118f38
a0119044:  21 33 c0 4b  sethi  %hi(0xcf012c00), %l0
a0119048:  1f 33 c0 4b  sethi  %hi(0xcf012c00), %o7
a011904c:  e0 04 20 0c  ld  [ %l0 + 0xc ], %l0
a0119050:  90 13 e3 e8  or  %o7, 0x3e8, %o0
a0119054:  96 10 20 00  clr  %o3
a0119058:  98 10 20 00  clr  %o4
a011905c:  92 13 e3 e0  or  %o7, 0x3e0, %o1
a0119060:  94 13 e3 e4  or  %o7, 0x3e4, %o2
a0119064:  d8 22 40 00  st  %o4, [ %o1 ]
a0119068:  a4 03 00 0c  add  %o4, %o4, %l2
a011906c:  d8 0c 00 12  ldub  [ %l0 + %l2 ], %o4
a0119070:  d8 22 80 00  st  %o4, [ %o2 ]
a0119074:  82 04 80 10  add  %l2, %l0, %g1
a0119078:  96 02 e0 01  inc  %o3
a011907c:  f0 08 60 01  ldub  [ %g1 + 1 ], %i0
a0119080:  98 0a e0 ff  and  %o3, 0xff, %o4
a0119084:  f0 22 00 00  st  %i0, [ %o0 ]
a0119088:  80 a3 20 0f  cmp  %o4, 0xf
a011908c:  08 bf ff f6  bleu  0xa0119064
a0119090:  01 00 00 00  nop
a0119094:  81 c7 e0 08  ret
a0119098:  81 e8 00 00  restore
