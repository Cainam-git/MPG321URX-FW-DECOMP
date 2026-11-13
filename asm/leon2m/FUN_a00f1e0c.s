# leon2m FUN_a00f1e0c 0xa00f1e0c-0xa00f1e50 (68 bytes)
a00f1e0c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00f1e10:  80 a3 60 08  cmp  %o5, 8
a00f1e14:  82 40 20 00  addx  %g0, 0, %g1
a00f1e18:  82 20 00 01  neg  %g1
a00f1e1c:  90 0b 40 01  and  %o5, %g1, %o0
a00f1e20:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f1e24:  90 02 00 08  add  %o0, %o0, %o0
a00f1e28:  82 13 63 0c  or  %o5, 0x30c, %g1
a00f1e2c:  da 10 40 08  lduh  [ %g1 + %o0 ], %o5
a00f1e30:  92 0a 60 ff  and  %o1, 0xff, %o1
a00f1e34:  90 03 40 09  add  %o5, %o1, %o0
a00f1e38:  93 2a 20 02  sll  %o0, 2, %o1
a00f1e3c:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00f1e40:  9a 12 40 01  or  %o1, %g1, %o5
a00f1e44:  d0 03 40 00  ld  [ %o5 ], %o0
a00f1e48:  81 c3 e0 08  retl
a00f1e4c:  90 0a 20 ff  and  %o0, 0xff, %o0
