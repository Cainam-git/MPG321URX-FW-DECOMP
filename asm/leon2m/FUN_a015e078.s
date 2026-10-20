# leon2m FUN_a015e078 0xa015e078-0xa015e134 (188 bytes)
a015e078:  82 12 00 09  or  %o0, %o1, %g1
a015e07c:  80 88 60 03  btst  3, %g1
a015e080:  32 80 00 08  bne,a   0xa015e0a0
a015e084:  d8 4a 00 00  ldsb  [ %o0 ], %o4
a015e088:  d8 02 00 00  ld  [ %o0 ], %o4
a015e08c:  c2 02 40 00  ld  [ %o1 ], %g1
a015e090:  80 a3 00 01  cmp  %o4, %g1
a015e094:  02 80 00 15  be  0xa015e0e8
a015e098:  03 3f bf bf  sethi  %hi(0xfefefc00), %g1
a015e09c:  d8 4a 00 00  ldsb  [ %o0 ], %o4
a015e0a0:  80 a3 20 00  cmp  %o4, 0
a015e0a4:  02 80 00 0c  be  0xa015e0d4
a015e0a8:  da 0a 00 00  ldub  [ %o0 ], %o5
a015e0ac:  c2 4a 40 00  ldsb  [ %o1 ], %g1
a015e0b0:  80 a3 00 01  cmp  %o4, %g1
a015e0b4:  12 80 00 09  bne  0xa015e0d8
a015e0b8:  c2 0a 40 00  ldub  [ %o1 ], %g1
a015e0bc:  90 02 20 01  inc  %o0
a015e0c0:  d8 4a 00 00  ldsb  [ %o0 ], %o4
a015e0c4:  92 02 60 01  inc  %o1
a015e0c8:  80 a3 20 00  cmp  %o4, 0
a015e0cc:  12 bf ff f8  bne  0xa015e0ac
a015e0d0:  da 0a 00 00  ldub  [ %o0 ], %o5
a015e0d4:  c2 0a 40 00  ldub  [ %o1 ], %g1
a015e0d8:  9a 0b 60 ff  and  %o5, 0xff, %o5
a015e0dc:  82 08 60 ff  and  %g1, 0xff, %g1
a015e0e0:  10 80 00 13  b  0xa015e12c
a015e0e4:  90 23 40 01  sub  %o5, %g1, %o0
a015e0e8:  1b 20 20 20  sethi  %hi(0x80808000), %o5
a015e0ec:  96 10 62 ff  or  %g1, 0x2ff, %o3
a015e0f0:  9a 13 60 80  or  %o5, 0x80, %o5
a015e0f4:  82 03 00 0b  add  %o4, %o3, %g1
a015e0f8:  82 28 40 0c  andn  %g1, %o4, %g1
a015e0fc:  90 02 20 04  add  %o0, 4, %o0
a015e100:  80 88 40 0d  btst  %g1, %o5
a015e104:  12 80 00 09  bne  0xa015e128
a015e108:  92 02 60 04  add  %o1, 4, %o1
a015e10c:  d8 02 00 00  ld  [ %o0 ], %o4
a015e110:  c2 02 40 00  ld  [ %o1 ], %g1
a015e114:  80 a3 00 01  cmp  %o4, %g1
a015e118:  02 bf ff f8  be  0xa015e0f8
a015e11c:  82 03 00 0b  add  %o4, %o3, %g1
a015e120:  10 bf ff e0  b  0xa015e0a0
a015e124:  d8 4a 00 00  ldsb  [ %o0 ], %o4
a015e128:  90 10 20 00  clr  %o0
a015e12c:  81 c3 e0 08  retl
a015e130:  01 00 00 00  nop
