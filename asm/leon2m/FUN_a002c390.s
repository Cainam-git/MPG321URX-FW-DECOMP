# leon2m FUN_a002c390 0xa002c390-0xa002c3c8 (56 bytes)
a002c390:  9b 2a 20 10  sll  %o0, 0x10, %o5
a002c394:  83 33 60 10  srl  %o5, 0x10, %g1
a002c398:  92 0a 60 ff  and  %o1, 0xff, %o1
a002c39c:  90 00 40 09  add  %g1, %o1, %o0
a002c3a0:  93 2a 20 02  sll  %o0, 2, %o1
a002c3a4:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a002c3a8:  90 12 40 0d  or  %o1, %o5, %o0
a002c3ac:  c2 02 00 00  ld  [ %o0 ], %g1
a002c3b0:  9a 08 60 ff  and  %g1, 0xff, %o5
a002c3b4:  d2 02 20 04  ld  [ %o0 + 4 ], %o1
a002c3b8:  83 2b 60 08  sll  %o5, 8, %g1
a002c3bc:  90 0a 60 ff  and  %o1, 0xff, %o0
a002c3c0:  81 c3 e0 08  retl
a002c3c4:  90 10 40 08  or  %g1, %o0, %o0
