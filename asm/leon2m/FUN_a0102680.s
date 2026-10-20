# leon2m FUN_a0102680 0xa0102680-0xa01026e8 (104 bytes)
a0102680:  9d e3 bf 98  save  %sp, -104, %sp
a0102684:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a0102688:  98 13 63 80  or  %o5, 0x380, %o4	! 0xcf014780
a010268c:  f0 03 00 00  ld  [ %o4 ], %i0
a0102690:  9e 16 20 40  or  %i0, 0x40, %o7
a0102694:  33 33 c0 50  sethi  %hi(0xcf014000), %i1
a0102698:  90 16 61 84  or  %i1, 0x184, %o0	! 0xcf014184
a010269c:  13 00 0c 80  sethi  %hi(0x320000), %o1
a01026a0:  de 23 00 00  st  %o7, [ %o4 ]
a01026a4:  7f ff c2 93  call  0xa00f30f0
a01026a8:  a0 16 61 94  or  %i1, 0x194, %l0
a01026ac:  d6 04 00 00  ld  [ %l0 ], %o3
a01026b0:  94 12 e0 80  or  %o3, 0x80, %o2
a01026b4:  13 33 c0 49  sethi  %hi(0xcf012400), %o1
a01026b8:  d4 24 00 00  st  %o2, [ %l0 ]
a01026bc:  9a 12 60 40  or  %o1, 0x40, %o5
a01026c0:  d0 03 40 00  ld  [ %o5 ], %o0
a01026c4:  82 12 20 10  or  %o0, 0x10, %g1
a01026c8:  31 33 c0 4a  sethi  %hi(0xcf012800), %i0
a01026cc:  33 00 0a 6a  sethi  %hi(0x29a800), %i1
a01026d0:  c2 23 40 00  st  %g1, [ %o5 ]
a01026d4:  b0 16 22 44  or  %i0, 0x244, %i0
a01026d8:  b2 16 62 aa  or  %i1, 0x2aa, %i1
a01026dc:  7f ff c2 85  call  0xa00f30f0
a01026e0:  81 e8 00 00  restore
a01026e4:  01 00 00 00  nop
