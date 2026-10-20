# leon2s FUN_a00a6e10 0xa00a6e10-0xa00a6e8c (124 bytes)
a00a6e10:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a6e14:  9a 02 00 08  add  %o0, %o0, %o5
a00a6e18:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a6e1c:  80 a2 20 01  cmp  %o0, 1
a00a6e20:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00a6e24:  93 32 60 10  srl  %o1, 0x10, %o1
a00a6e28:  18 80 00 17  bgu  0xa00a6e84
a00a6e2c:  90 10 20 00  clr  %o0
a00a6e30:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a6e34:  82 10 61 94  or  %g1, 0x194, %g1	! 0xa00b4d94
a00a6e38:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a6e3c:  82 00 40 09  add  %g1, %o1, %g1
a00a6e40:  9b 28 60 02  sll  %g1, 2, %o5
a00a6e44:  98 00 60 01  add  %g1, 1, %o4
a00a6e48:  9a 13 40 0a  or  %o5, %o2, %o5
a00a6e4c:  99 2b 20 02  sll  %o4, 2, %o4
a00a6e50:  82 00 60 02  add  %g1, 2, %g1
a00a6e54:  d6 03 40 00  ld  [ %o5 ], %o3
a00a6e58:  98 13 00 0a  or  %o4, %o2, %o4
a00a6e5c:  83 28 60 02  sll  %g1, 2, %g1
a00a6e60:  da 03 00 00  ld  [ %o4 ], %o5
a00a6e64:  82 10 40 0a  or  %g1, %o2, %g1
a00a6e68:  c2 00 40 00  ld  [ %g1 ], %g1
a00a6e6c:  83 28 60 08  sll  %g1, 8, %g1
a00a6e70:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00a6e74:  82 10 40 0d  or  %g1, %o5, %g1
a00a6e78:  83 28 60 08  sll  %g1, 8, %g1
a00a6e7c:  96 0a e0 ff  and  %o3, 0xff, %o3
a00a6e80:  90 10 40 0b  or  %g1, %o3, %o0
a00a6e84:  81 c3 e0 08  retl
a00a6e88:  01 00 00 00  nop
