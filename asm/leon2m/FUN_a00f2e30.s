# leon2m FUN_a00f2e30 0xa00f2e30-0xa00f2e74 (68 bytes)
a00f2e30:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00f2e34:  80 a3 60 02  cmp  %o5, 2
a00f2e38:  82 40 20 00  addx  %g0, 0, %g1
a00f2e3c:  82 20 00 01  neg  %g1
a00f2e40:  90 0b 40 01  and  %o5, %g1, %o0
a00f2e44:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f2e48:  90 02 00 08  add  %o0, %o0, %o0
a00f2e4c:  82 13 62 e0  or  %o5, 0x2e0, %g1
a00f2e50:  da 10 40 08  lduh  [ %g1 + %o0 ], %o5
a00f2e54:  92 0a 60 ff  and  %o1, 0xff, %o1
a00f2e58:  90 03 40 09  add  %o5, %o1, %o0
a00f2e5c:  93 2a 20 02  sll  %o0, 2, %o1
a00f2e60:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00f2e64:  9a 12 40 01  or  %o1, %g1, %o5
a00f2e68:  d0 03 40 00  ld  [ %o5 ], %o0
a00f2e6c:  81 c3 e0 08  retl
a00f2e70:  90 0a 20 ff  and  %o0, 0xff, %o0
