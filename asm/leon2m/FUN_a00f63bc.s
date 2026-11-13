# leon2m FUN_a00f63bc 0xa00f63bc-0xa00f6408 (76 bytes)
a00f63bc:  15 33 c0 3b  sethi  %hi(0xcf00ec00), %o2
a00f63c0:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00f63c4:  98 12 a0 84  or  %o2, 0x84, %o4
a00f63c8:  1b 33 c0 3a  sethi  %hi(0xcf00e800), %o5
a00f63cc:  c2 0a e3 b4  ldub  [ %o3 + 0x3b4 ], %g1
a00f63d0:  80 a0 40 08  cmp  %g1, %o0
a00f63d4:  02 80 00 0b  be  0xa00f6400
a00f63d8:  94 13 61 80  or  %o5, 0x180, %o2
a00f63dc:  c2 03 00 00  ld  [ %o4 ], %g1
a00f63e0:  9a 08 60 fc  and  %g1, 0xfc, %o5
a00f63e4:  82 13 40 08  or  %o5, %o0, %g1
a00f63e8:  c2 23 00 00  st  %g1, [ %o4 ]
a00f63ec:  da 02 80 00  ld  [ %o2 ], %o5
a00f63f0:  82 0b 60 fc  and  %o5, 0xfc, %g1
a00f63f4:  98 10 40 08  or  %g1, %o0, %o4
a00f63f8:  d8 22 80 00  st  %o4, [ %o2 ]
a00f63fc:  d0 2a e3 b4  stb  %o0, [ %o3 + 0x3b4 ]
a00f6400:  81 c3 e0 08  retl
a00f6404:  01 00 00 00  nop
