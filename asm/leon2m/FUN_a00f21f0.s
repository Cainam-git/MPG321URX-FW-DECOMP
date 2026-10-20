# leon2m FUN_a00f21f0 0xa00f21f0-0xa00f2254 (100 bytes)
a00f21f0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f21f4:  80 a2 20 08  cmp  %o0, 8
a00f21f8:  82 40 20 00  addx  %g0, 0, %g1
a00f21fc:  9a 20 00 01  neg  %g1, %o5
a00f2200:  96 0a 00 0d  and  %o0, %o5, %o3
a00f2204:  19 00 06 68  sethi  %hi(0x19a000), %o4
a00f2208:  82 13 22 fc  or  %o4, 0x2fc, %g1	! 0x19a2fc
a00f220c:  9a 02 c0 0b  add  %o3, %o3, %o5
a00f2210:  d6 10 40 0d  lduh  [ %g1 + %o5 ], %o3
a00f2214:  90 0a 60 ff  and  %o1, 0xff, %o0
a00f2218:  98 02 c0 08  add  %o3, %o0, %o4
a00f221c:  92 03 20 01  add  %o4, 1, %o1
a00f2220:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00f2224:  9b 2b 20 02  sll  %o4, 2, %o5
a00f2228:  90 13 40 0b  or  %o5, %o3, %o0
a00f222c:  83 2a 60 02  sll  %o1, 2, %g1
a00f2230:  d2 02 00 00  ld  [ %o0 ], %o1
a00f2234:  98 10 40 0b  or  %g1, %o3, %o4
a00f2238:  da 03 00 00  ld  [ %o4 ], %o5
a00f223c:  97 2b 60 08  sll  %o5, 8, %o3
a00f2240:  82 0a 60 ff  and  %o1, 0xff, %g1
a00f2244:  92 12 c0 01  or  %o3, %g1, %o1
a00f2248:  91 2a 60 10  sll  %o1, 0x10, %o0
a00f224c:  81 c3 e0 08  retl
a00f2250:  91 32 20 10  srl  %o0, 0x10, %o0
