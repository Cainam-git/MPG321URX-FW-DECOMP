# leon2m FUN_a00f11ac 0xa00f11ac-0xa00f11f4 (72 bytes)
a00f11ac:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00f11b0:  80 a3 60 04  cmp  %o5, 4
a00f11b4:  82 40 20 00  addx  %g0, 0, %g1
a00f11b8:  82 20 00 01  neg  %g1
a00f11bc:  90 0b 40 01  and  %o5, %g1, %o0
a00f11c0:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00f11c4:  90 02 00 08  add  %o0, %o0, %o0
a00f11c8:  82 13 62 7e  or  %o5, 0x27e, %g1
a00f11cc:  93 2a 60 10  sll  %o1, 0x10, %o1
a00f11d0:  da 10 40 08  lduh  [ %g1 + %o0 ], %o5
a00f11d4:  93 32 60 10  srl  %o1, 0x10, %o1
a00f11d8:  90 03 40 09  add  %o5, %o1, %o0
a00f11dc:  93 2a 20 02  sll  %o0, 2, %o1
a00f11e0:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00f11e4:  9a 12 40 01  or  %o1, %g1, %o5
a00f11e8:  d0 03 40 00  ld  [ %o5 ], %o0
a00f11ec:  81 c3 e0 08  retl
a00f11f0:  90 0a 20 ff  and  %o0, 0xff, %o0
