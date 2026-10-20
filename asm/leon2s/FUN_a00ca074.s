# leon2s FUN_a00ca074 0xa00ca074-0xa00ca130 (188 bytes)
a00ca074:  19 33 c0 63  sethi  %hi(0xcf018c00), %o4
a00ca078:  9a 13 22 0c  or  %o4, 0x20c, %o5	! 0xcf018e0c
a00ca07c:  c2 03 40 00  ld  [ %o5 ], %g1
a00ca080:  80 a0 60 00  cmp  %g1, 0
a00ca084:  92 0a 60 ff  and  %o1, 0xff, %o1
a00ca088:  12 80 00 24  bne  0xa00ca118
a00ca08c:  96 13 22 04  or  %o4, 0x204, %o3
a00ca090:  82 0a 20 ff  and  %o0, 0xff, %g1
a00ca094:  d2 22 c0 00  st  %o1, [ %o3 ]
a00ca098:  80 a0 60 aa  cmp  %g1, 0xaa
a00ca09c:  12 80 00 0b  bne  0xa00ca0c8
a00ca0a0:  9a 13 22 14  or  %o4, 0x214, %o5
a00ca0a4:  c2 03 40 00  ld  [ %o5 ], %g1
a00ca0a8:  82 10 60 01  or  %g1, 1, %g1
a00ca0ac:  c2 23 40 00  st  %g1, [ %o5 ]
a00ca0b0:  c2 03 40 00  ld  [ %o5 ], %g1
a00ca0b4:  80 88 60 01  btst  1, %g1
a00ca0b8:  12 bf ff fe  bne  0xa00ca0b0
a00ca0bc:  01 00 00 00  nop
a00ca0c0:  10 80 00 09  b  0xa00ca0e4
a00ca0c4:  19 33 c0 63  sethi  %hi(0xcf018c00), %o4
a00ca0c8:  c2 03 40 00  ld  [ %o5 ], %g1
a00ca0cc:  82 10 60 04  or  %g1, 4, %g1
a00ca0d0:  c2 23 40 00  st  %g1, [ %o5 ]
a00ca0d4:  c2 03 40 00  ld  [ %o5 ], %g1
a00ca0d8:  80 88 60 04  btst  4, %g1
a00ca0dc:  12 bf ff fe  bne  0xa00ca0d4
a00ca0e0:  19 33 c0 63  sethi  %hi(0xcf018c00), %o4
a00ca0e4:  9a 13 22 10  or  %o4, 0x210, %o5	! 0xcf018e10
a00ca0e8:  82 10 20 1f  mov  0x1f, %g1
a00ca0ec:  c2 23 40 00  st  %g1, [ %o5 ]
a00ca0f0:  9a 13 22 14  or  %o4, 0x214, %o5
a00ca0f4:  c2 03 40 00  ld  [ %o5 ], %g1
a00ca0f8:  82 10 60 80  or  %g1, 0x80, %g1
a00ca0fc:  c2 23 40 00  st  %g1, [ %o5 ]
a00ca100:  c2 03 40 00  ld  [ %o5 ], %g1
a00ca104:  80 88 60 80  btst  0x80, %g1
a00ca108:  12 bf ff fe  bne  0xa00ca100
a00ca10c:  82 10 20 3f  mov  0x3f, %g1
a00ca110:  10 80 00 05  b  0xa00ca124
a00ca114:  9a 13 22 0c  or  %o4, 0x20c, %o5
a00ca118:  d2 22 c0 00  st  %o1, [ %o3 ]
a00ca11c:  c2 03 40 00  ld  [ %o5 ], %g1
a00ca120:  82 00 7f ff  add  %g1, -1, %g1
a00ca124:  c2 23 40 00  st  %g1, [ %o5 ]
a00ca128:  81 c3 e0 08  retl
a00ca12c:  01 00 00 00  nop
