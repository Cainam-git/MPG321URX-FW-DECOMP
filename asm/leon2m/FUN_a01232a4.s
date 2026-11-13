# leon2m FUN_a01232a4 0xa01232a4-0xa0123304 (96 bytes)
a01232a4:  96 0a 20 ff  and  %o0, 0xff, %o3
a01232a8:  80 a2 e0 02  cmp  %o3, 2
a01232ac:  98 40 20 00  addx  %g0, 0, %o4
a01232b0:  82 20 00 0c  neg  %o4, %g1
a01232b4:  90 0a c0 01  and  %o3, %g1, %o0
a01232b8:  1b 00 06 8c  sethi  %hi(0x1a3000), %o5
a01232bc:  96 02 00 08  add  %o0, %o0, %o3
a01232c0:  98 13 60 70  or  %o5, 0x70, %o4
a01232c4:  da 13 00 0b  lduh  [ %o4 + %o3 ], %o5
a01232c8:  82 03 60 45  add  %o5, 0x45, %g1
a01232cc:  90 03 60 44  add  %o5, 0x44, %o0
a01232d0:  99 28 60 02  sll  %g1, 2, %o4
a01232d4:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a01232d8:  83 2a 20 02  sll  %o0, 2, %g1
a01232dc:  9a 10 40 0b  or  %g1, %o3, %o5
a01232e0:  98 13 00 0b  or  %o4, %o3, %o4
a01232e4:  d6 03 00 00  ld  [ %o4 ], %o3
a01232e8:  d0 03 40 00  ld  [ %o5 ], %o0
a01232ec:  99 2a 20 08  sll  %o0, 8, %o4
a01232f0:  82 0a e0 ff  and  %o3, 0xff, %g1
a01232f4:  96 13 00 01  or  %o4, %g1, %o3
a01232f8:  91 2a e0 10  sll  %o3, 0x10, %o0
a01232fc:  81 c3 e0 08  retl
a0123300:  91 32 20 10  srl  %o0, 0x10, %o0
