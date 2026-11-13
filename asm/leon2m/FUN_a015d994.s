# leon2m FUN_a015d994 0xa015d994-0xa015d9e4 (80 bytes)
a015d994:  9d e3 bf 98  save  %sp, -104, %sp
a015d998:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a015d99c:  80 a6 20 17  cmp  %i0, 0x17
a015d9a0:  14 80 00 0b  bg  0xa015d9cc
a015d9a4:  d0 18 62 30  ldd  [ %g1 + 0x230 ], %o0
a015d9a8:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015d9ac:  9b 2e 20 03  sll  %i0, 3, %o5
a015d9b0:  82 10 61 78  or  %g1, 0x178, %g1
a015d9b4:  98 00 40 0d  add  %g1, %o5, %o4
a015d9b8:  10 80 00 08  b  0xa015d9d8
a015d9bc:  d0 1b 00 00  ldd  [ %o4 ], %o0
a015d9c0:  7f ff e1 e6  call  0xa0156158
a015d9c4:  d4 18 60 d0  ldd  [ %g1 + 0xd0 ], %o2
a015d9c8:  b0 06 3f ff  add  %i0, -1, %i0
a015d9cc:  80 a6 20 00  cmp  %i0, 0
a015d9d0:  14 bf ff fc  bg  0xa015d9c0
a015d9d4:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015d9d8:  b0 10 00 08  mov  %o0, %i0
a015d9dc:  81 c7 e0 08  ret
a015d9e0:  93 e8 00 09  restore  %g0, %o1, %o1
