# leon2m FUN_a00f2254 0xa00f2254-0xa00f2298 (68 bytes)
a00f2254:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00f2258:  80 a3 60 08  cmp  %o5, 8
a00f225c:  82 40 20 00  addx  %g0, 0, %g1
a00f2260:  82 20 00 01  neg  %g1
a00f2264:  90 0b 40 01  and  %o5, %g1, %o0
a00f2268:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f226c:  90 02 00 08  add  %o0, %o0, %o0
a00f2270:  82 13 62 ec  or  %o5, 0x2ec, %g1
a00f2274:  da 10 40 08  lduh  [ %g1 + %o0 ], %o5
a00f2278:  92 0a 60 ff  and  %o1, 0xff, %o1
a00f227c:  90 03 40 09  add  %o5, %o1, %o0
a00f2280:  93 2a 20 02  sll  %o0, 2, %o1
a00f2284:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00f2288:  9a 12 40 01  or  %o1, %g1, %o5
a00f228c:  d0 03 40 00  ld  [ %o5 ], %o0
a00f2290:  81 c3 e0 08  retl
a00f2294:  90 0a 20 ff  and  %o0, 0xff, %o0
