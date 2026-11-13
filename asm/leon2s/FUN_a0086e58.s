# leon2s FUN_a0086e58 0xa0086e58-0xa0086fb0 (344 bytes)
a0086e58:  9d e3 bf 88  save  %sp, -120, %sp
a0086e5c:  c2 0e 40 00  ldub  [ %i1 ], %g1
a0086e60:  9a 10 20 00  clr  %o5
a0086e64:  98 10 20 00  clr  %o4
a0086e68:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0086e6c:  82 10 7f 80  or  %g1, -128, %g1
a0086e70:  ac 07 bf f0  add  %fp, -16, %l6
a0086e74:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0086e78:  92 10 20 90  mov  0x90, %o1
a0086e7c:  94 10 22 00  mov  0x200, %o2
a0086e80:  96 10 20 07  mov  7, %o3
a0086e84:  98 10 00 16  mov  %l6, %o4
a0086e88:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0086e8c:  7f ff fd 5d  call  0xa0086400
a0086e90:  90 10 00 18  mov  %i0, %o0
a0086e94:  e0 0f bf f7  ldub  [ %fp + -9 ], %l0
a0086e98:  de 0f bf f6  ldub  [ %fp + -10 ], %o7
a0086e9c:  94 0c 20 0c  and  %l0, 0xc, %o2
a0086ea0:  98 0b e0 0c  and  %o7, 0xc, %o4
a0086ea4:  96 0b e0 30  and  %o7, 0x30, %o3
a0086ea8:  92 0c 20 30  and  %l0, 0x30, %o1
a0086eac:  9b 34 20 06  srl  %l0, 6, %o5
a0086eb0:  b7 3a a0 02  sra  %o2, 2, %i3
a0086eb4:  af 3b 20 02  sra  %o4, 2, %l7
a0086eb8:  bb 3a e0 04  sra  %o3, 4, %i5
a0086ebc:  b9 33 e0 06  srl  %o7, 6, %i4
a0086ec0:  b5 3a 60 04  sra  %o1, 4, %i2
a0086ec4:  da 27 bf ec  st  %o5, [ %fp + -20 ]
a0086ec8:  80 8a 20 ff  btst  0xff, %o0
a0086ecc:  15 00 00 08  sethi  %hi(0x2000), %o2
a0086ed0:  da 0f bf f0  ldub  [ %fp + -16 ], %o5
a0086ed4:  e2 0f bf f1  ldub  [ %fp + -15 ], %l1
a0086ed8:  e4 0f bf f2  ldub  [ %fp + -14 ], %l2
a0086edc:  e6 0f bf f3  ldub  [ %fp + -13 ], %l3
a0086ee0:  e8 0f bf f4  ldub  [ %fp + -12 ], %l4
a0086ee4:  ea 0f bf f5  ldub  [ %fp + -11 ], %l5
a0086ee8:  9e 0b e0 03  and  %o7, 3, %o7
a0086eec:  a0 0c 20 03  and  %l0, 3, %l0
a0086ef0:  94 12 a0 03  or  %o2, 3, %o2
a0086ef4:  92 10 20 90  mov  0x90, %o1
a0086ef8:  96 10 20 00  clr  %o3
a0086efc:  98 10 00 16  mov  %l6, %o4
a0086f00:  12 80 00 05  bne  0xa0086f14
a0086f04:  90 10 20 00  clr  %o0
a0086f08:  c2 0e 40 00  ldub  [ %i1 ], %g1
a0086f0c:  82 08 60 7f  and  %g1, 0x7f, %g1
a0086f10:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0086f14:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a0086f18:  da 2e 60 01  stb  %o5, [ %i1 + 1 ]
a0086f1c:  e2 2e 60 02  stb  %l1, [ %i1 + 2 ]
a0086f20:  e4 2e 60 04  stb  %l2, [ %i1 + 4 ]
a0086f24:  e6 2e 60 05  stb  %l3, [ %i1 + 5 ]
a0086f28:  e8 2e 60 06  stb  %l4, [ %i1 + 6 ]
a0086f2c:  ea 2e 60 07  stb  %l5, [ %i1 + 7 ]
a0086f30:  de 2e 60 08  stb  %o7, [ %i1 + 8 ]
a0086f34:  ee 2e 60 0c  stb  %l7, [ %i1 + 0xc ]
a0086f38:  fa 2e 60 09  stb  %i5, [ %i1 + 9 ]
a0086f3c:  f8 2e 60 0d  stb  %i4, [ %i1 + 0xd ]
a0086f40:  e0 2e 60 0a  stb  %l0, [ %i1 + 0xa ]
a0086f44:  f6 2e 60 0e  stb  %i3, [ %i1 + 0xe ]
a0086f48:  f4 2e 60 0b  stb  %i2, [ %i1 + 0xb ]
a0086f4c:  80 a6 20 00  cmp  %i0, 0
a0086f50:  12 80 00 04  bne  0xa0086f60
a0086f54:  c2 2e 60 0f  stb  %g1, [ %i1 + 0xf ]
a0086f58:  7f ff fd 2a  call  0xa0086400
a0086f5c:  01 00 00 00  nop
a0086f60:  7f ff fd d1  call  0xa00866a4
a0086f64:  01 00 00 00  nop
a0086f68:  15 00 00 08  sethi  %hi(0x2000), %o2
a0086f6c:  80 8a 20 ff  btst  0xff, %o0
a0086f70:  94 12 a0 03  or  %o2, 3, %o2
a0086f74:  98 10 00 16  mov  %l6, %o4
a0086f78:  92 10 20 80  mov  0x80, %o1
a0086f7c:  96 10 20 00  clr  %o3
a0086f80:  02 80 00 07  be  0xa0086f9c
a0086f84:  90 10 00 18  mov  %i0, %o0
a0086f88:  80 a6 20 00  cmp  %i0, 0
a0086f8c:  12 80 00 04  bne  0xa0086f9c
a0086f90:  c2 0f bf f0  ldub  [ %fp + -16 ], %g1
a0086f94:  10 80 00 04  b  0xa0086fa4
a0086f98:  c2 2e 60 03  stb  %g1, [ %i1 + 3 ]
a0086f9c:  7f ff fd 0e  call  0xa00863d4
a0086fa0:  c0 2e 60 03  clrb  [ %i1 + 3 ]
a0086fa4:  01 00 00 00  nop
a0086fa8:  81 c7 e0 08  ret
a0086fac:  81 e8 00 00  restore
