# leon2m FUN_a00f19a4 0xa00f19a4-0xa00f19dc (56 bytes)
a00f19a4:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f19a8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f19ac:  91 2a 20 02  sll  %o0, 2, %o0
a00f19b0:  82 13 62 d8  or  %o5, 0x2d8, %g1
a00f19b4:  93 2a 60 10  sll  %o1, 0x10, %o1
a00f19b8:  da 00 40 08  ld  [ %g1 + %o0 ], %o5
a00f19bc:  93 32 60 10  srl  %o1, 0x10, %o1
a00f19c0:  90 03 40 09  add  %o5, %o1, %o0
a00f19c4:  93 2a 20 02  sll  %o0, 2, %o1
a00f19c8:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00f19cc:  9a 12 40 01  or  %o1, %g1, %o5
a00f19d0:  d0 03 40 00  ld  [ %o5 ], %o0
a00f19d4:  81 c3 e0 08  retl
a00f19d8:  90 0a 20 ff  and  %o0, 0xff, %o0
