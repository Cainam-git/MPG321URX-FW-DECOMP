# leon2m FUN_a00f2b48 0xa00f2b48-0xa00f2b8c (68 bytes)
a00f2b48:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00f2b4c:  80 a3 60 04  cmp  %o5, 4
a00f2b50:  82 40 20 00  addx  %g0, 0, %g1
a00f2b54:  82 20 00 01  neg  %g1
a00f2b58:  90 0b 40 01  and  %o5, %g1, %o0
a00f2b5c:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f2b60:  90 02 00 08  add  %o0, %o0, %o0
a00f2b64:  82 13 62 e4  or  %o5, 0x2e4, %g1
a00f2b68:  da 10 40 08  lduh  [ %g1 + %o0 ], %o5
a00f2b6c:  92 0a 60 ff  and  %o1, 0xff, %o1
a00f2b70:  90 03 40 09  add  %o5, %o1, %o0
a00f2b74:  93 2a 20 02  sll  %o0, 2, %o1
a00f2b78:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00f2b7c:  9a 12 40 01  or  %o1, %g1, %o5
a00f2b80:  d0 03 40 00  ld  [ %o5 ], %o0
a00f2b84:  81 c3 e0 08  retl
a00f2b88:  90 0a 20 ff  and  %o0, 0xff, %o0
