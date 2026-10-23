# leon2m FUN_a002c2f0 0xa002c2f0-0xa002c318 (40 bytes)
a002c2f0:  91 2a 20 10  sll  %o0, 0x10, %o0
a002c2f4:  83 32 20 10  srl  %o0, 0x10, %g1
a002c2f8:  92 0a 60 ff  and  %o1, 0xff, %o1
a002c2fc:  90 00 40 09  add  %g1, %o1, %o0
a002c300:  91 2a 20 02  sll  %o0, 2, %o0
a002c304:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a002c308:  92 12 00 01  or  %o0, %g1, %o1
a002c30c:  d0 02 40 00  ld  [ %o1 ], %o0
a002c310:  81 c3 e0 08  retl
a002c314:  90 0a 20 ff  and  %o0, 0xff, %o0
