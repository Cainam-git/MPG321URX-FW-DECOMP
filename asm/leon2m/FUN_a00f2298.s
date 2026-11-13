# leon2m FUN_a00f2298 0xa00f2298-0xa00f232c (148 bytes)
a00f2298:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f229c:  80 a2 20 08  cmp  %o0, 8
a00f22a0:  02 80 00 0f  be  0xa00f22dc
a00f22a4:  80 a2 20 07  cmp  %o0, 7
a00f22a8:  18 80 00 1f  bgu  0xa00f2324
a00f22ac:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f22b0:  98 02 00 08  add  %o0, %o0, %o4
a00f22b4:  96 10 62 ec  or  %g1, 0x2ec, %o3
a00f22b8:  da 12 c0 0c  lduh  [ %o3 + %o4 ], %o5
a00f22bc:  90 0a 60 ff  and  %o1, 0xff, %o0
a00f22c0:  82 03 40 08  add  %o5, %o0, %g1
a00f22c4:  93 28 60 02  sll  %g1, 2, %o1
a00f22c8:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00f22cc:  90 12 40 0b  or  %o1, %o3, %o0
a00f22d0:  98 0a a0 ff  and  %o2, 0xff, %o4
a00f22d4:  d8 22 00 00  st  %o4, [ %o0 ]
a00f22d8:  30 80 00 13  b,a   0xa00f2324
a00f22dc:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f22e0:  92 0a 60 ff  and  %o1, 0xff, %o1
a00f22e4:  94 0a a0 ff  and  %o2, 0xff, %o2
a00f22e8:  90 10 62 ec  or  %g1, 0x2ec, %o0
a00f22ec:  96 10 20 00  clr  %o3
a00f22f0:  9a 10 20 00  clr  %o5
a00f22f4:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a00f22f8:  9a 03 40 0d  add  %o5, %o5, %o5
a00f22fc:  c2 12 00 0d  lduh  [ %o0 + %o5 ], %g1
a00f2300:  82 00 40 09  add  %g1, %o1, %g1
a00f2304:  9b 28 60 02  sll  %g1, 2, %o5
a00f2308:  82 13 40 0c  or  %o5, %o4, %g1
a00f230c:  96 02 e0 01  inc  %o3
a00f2310:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00f2314:  d4 20 40 00  st  %o2, [ %g1 ]
a00f2318:  80 a3 60 07  cmp  %o5, 7
a00f231c:  08 bf ff f8  bleu  0xa00f22fc
a00f2320:  9a 03 40 0d  add  %o5, %o5, %o5
a00f2324:  81 c3 e0 08  retl
a00f2328:  01 00 00 00  nop
