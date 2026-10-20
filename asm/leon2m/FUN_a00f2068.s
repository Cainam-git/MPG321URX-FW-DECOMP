# leon2m FUN_a00f2068 0xa00f2068-0xa00f21f0 (392 bytes)
a00f2068:  9d e3 bf 98  save  %sp, -104, %sp
a00f206c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f2070:  9e 10 00 19  mov  %i1, %o7
a00f2074:  80 a6 20 07  cmp  %i0, 7
a00f2078:  08 80 00 28  bleu  0xa00f2118
a00f207c:  b2 10 00 1a  mov  %i2, %i1
a00f2080:  b4 0e e0 ff  and  %i3, 0xff, %i2
a00f2084:  37 00 06 68  sethi  %hi(0x19a000), %i3
a00f2088:  80 a6 a0 01  cmp  %i2, 1
a00f208c:  b4 0b e0 ff  and  %o7, 0xff, %i2
a00f2090:  9a 16 e2 fc  or  %i3, 0x2fc, %o5
a00f2094:  b6 10 20 00  clr  %i3
a00f2098:  b8 10 20 00  clr  %i4
a00f209c:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a00f20a0:  02 80 00 37  be  0xa00f217c
a00f20a4:  b0 38 00 19  xnor  %g0, %i1, %i0
a00f20a8:  ba 07 00 1c  add  %i4, %i4, %i5
a00f20ac:  f2 13 40 1d  lduh  [ %o5 + %i5 ], %i1
a00f20b0:  82 06 40 1a  add  %i1, %i2, %g1
a00f20b4:  bb 28 60 02  sll  %g1, 2, %i5
a00f20b8:  ba 17 40 0f  or  %i5, %o7, %i5
a00f20bc:  f8 07 40 00  ld  [ %i5 ], %i4
a00f20c0:  b2 0f 00 18  and  %i4, %i0, %i1
a00f20c4:  b6 06 e0 01  inc  %i3
a00f20c8:  82 0e 60 ff  and  %i1, 0xff, %g1
a00f20cc:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f20d0:  c2 27 40 00  st  %g1, [ %i5 ]
a00f20d4:  80 a7 20 07  cmp  %i4, 7
a00f20d8:  18 80 00 44  bgu  0xa00f21e8
a00f20dc:  ba 07 00 1c  add  %i4, %i4, %i5
a00f20e0:  f2 13 40 1d  lduh  [ %o5 + %i5 ], %i1
a00f20e4:  82 06 40 1a  add  %i1, %i2, %g1
a00f20e8:  bb 28 60 02  sll  %g1, 2, %i5
a00f20ec:  ba 17 40 0f  or  %i5, %o7, %i5
a00f20f0:  f8 07 40 00  ld  [ %i5 ], %i4
a00f20f4:  b2 0f 00 18  and  %i4, %i0, %i1
a00f20f8:  b6 06 e0 01  inc  %i3
a00f20fc:  82 0e 60 ff  and  %i1, 0xff, %g1
a00f2100:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f2104:  c2 27 40 00  st  %g1, [ %i5 ]
a00f2108:  80 a7 20 07  cmp  %i4, 7
a00f210c:  08 bf ff e8  bleu  0xa00f20ac
a00f2110:  ba 07 00 1c  add  %i4, %i4, %i5
a00f2114:  30 80 00 35  b,a   0xa00f21e8
a00f2118:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f211c:  b8 13 62 fc  or  %o5, 0x2fc, %i4	! 0x19a2fc
a00f2120:  b2 06 00 18  add  %i0, %i0, %i1
a00f2124:  c2 17 00 19  lduh  [ %i4 + %i1 ], %g1
a00f2128:  b2 0b e0 ff  and  %o7, 0xff, %i1
a00f212c:  82 00 40 19  add  %g1, %i1, %g1
a00f2130:  b9 28 60 02  sll  %g1, 2, %i4
a00f2134:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00f2138:  82 17 00 1d  or  %i4, %i5, %g1
a00f213c:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f2140:  c2 00 40 00  ld  [ %g1 ], %g1
a00f2144:  80 a7 20 01  cmp  %i4, 1
a00f2148:  02 80 00 03  be  0xa00f2154
a00f214c:  b6 10 40 1a  or  %g1, %i2, %i3
a00f2150:  b6 28 40 1a  andn  %g1, %i2, %i3
a00f2154:  82 13 62 fc  or  %o5, 0x2fc, %g1
a00f2158:  b4 06 00 18  add  %i0, %i0, %i2
a00f215c:  f0 10 40 1a  lduh  [ %g1 + %i2 ], %i0
a00f2160:  b8 06 00 19  add  %i0, %i1, %i4
a00f2164:  83 2f 20 02  sll  %i4, 2, %g1
a00f2168:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00f216c:  b0 10 40 1d  or  %g1, %i5, %i0
a00f2170:  b4 0e e0 ff  and  %i3, 0xff, %i2
a00f2174:  f4 26 00 00  st  %i2, [ %i0 ]
a00f2178:  30 80 00 1c  b,a   0xa00f21e8
a00f217c:  82 07 00 1c  add  %i4, %i4, %g1
a00f2180:  f8 13 40 01  lduh  [ %o5 + %g1 ], %i4
a00f2184:  b0 07 00 1a  add  %i4, %i2, %i0
a00f2188:  bb 2e 20 02  sll  %i0, 2, %i5
a00f218c:  ba 17 40 0f  or  %i5, %o7, %i5
a00f2190:  c2 07 40 00  ld  [ %i5 ], %g1
a00f2194:  b8 10 40 19  or  %g1, %i1, %i4
a00f2198:  b0 0f 20 ff  and  %i4, 0xff, %i0
a00f219c:  b6 06 e0 01  inc  %i3
a00f21a0:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f21a4:  f0 27 40 00  st  %i0, [ %i5 ]
a00f21a8:  80 a7 20 07  cmp  %i4, 7
a00f21ac:  18 80 00 0f  bgu  0xa00f21e8
a00f21b0:  82 07 00 1c  add  %i4, %i4, %g1
a00f21b4:  f8 13 40 01  lduh  [ %o5 + %g1 ], %i4
a00f21b8:  b0 07 00 1a  add  %i4, %i2, %i0
a00f21bc:  bb 2e 20 02  sll  %i0, 2, %i5
a00f21c0:  ba 17 40 0f  or  %i5, %o7, %i5
a00f21c4:  c2 07 40 00  ld  [ %i5 ], %g1
a00f21c8:  b8 10 40 19  or  %g1, %i1, %i4
a00f21cc:  b0 0f 20 ff  and  %i4, 0xff, %i0
a00f21d0:  b6 06 e0 01  inc  %i3
a00f21d4:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f21d8:  f0 27 40 00  st  %i0, [ %i5 ]
a00f21dc:  80 a7 20 07  cmp  %i4, 7
a00f21e0:  08 bf ff e8  bleu  0xa00f2180
a00f21e4:  82 07 00 1c  add  %i4, %i4, %g1
a00f21e8:  81 c7 e0 08  ret
a00f21ec:  81 e8 00 00  restore
