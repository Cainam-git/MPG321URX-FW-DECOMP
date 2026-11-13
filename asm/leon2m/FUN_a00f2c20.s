# leon2m FUN_a00f2c20 0xa00f2c20-0xa00f2ca8 (136 bytes)
a00f2c20:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f2c24:  80 a2 20 01  cmp  %o0, 1
a00f2c28:  08 80 00 14  bleu  0xa00f2c78
a00f2c2c:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f2c30:  92 0a 60 ff  and  %o1, 0xff, %o1
a00f2c34:  94 0a a0 ff  and  %o2, 0xff, %o2
a00f2c38:  90 10 62 e0  or  %g1, 0x2e0, %o0
a00f2c3c:  96 10 20 00  clr  %o3
a00f2c40:  9a 10 20 00  clr  %o5
a00f2c44:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a00f2c48:  9a 03 40 0d  add  %o5, %o5, %o5
a00f2c4c:  c2 12 00 0d  lduh  [ %o0 + %o5 ], %g1
a00f2c50:  82 00 40 09  add  %g1, %o1, %g1
a00f2c54:  9b 28 60 02  sll  %g1, 2, %o5
a00f2c58:  82 13 40 0c  or  %o5, %o4, %g1
a00f2c5c:  96 02 e0 01  inc  %o3
a00f2c60:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00f2c64:  d4 20 40 00  st  %o2, [ %g1 ]
a00f2c68:  80 a3 60 01  cmp  %o5, 1
a00f2c6c:  28 bf ff f8  bleu,a   0xa00f2c4c
a00f2c70:  9a 03 40 0d  add  %o5, %o5, %o5
a00f2c74:  30 80 00 0b  b,a   0xa00f2ca0
a00f2c78:  98 02 00 08  add  %o0, %o0, %o4
a00f2c7c:  96 10 62 e0  or  %g1, 0x2e0, %o3
a00f2c80:  da 12 c0 0c  lduh  [ %o3 + %o4 ], %o5
a00f2c84:  90 0a 60 ff  and  %o1, 0xff, %o0
a00f2c88:  82 03 40 08  add  %o5, %o0, %g1
a00f2c8c:  93 28 60 02  sll  %g1, 2, %o1
a00f2c90:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00f2c94:  90 12 40 0b  or  %o1, %o3, %o0
a00f2c98:  98 0a a0 ff  and  %o2, 0xff, %o4
a00f2c9c:  d8 22 00 00  st  %o4, [ %o0 ]
a00f2ca0:  81 c3 e0 08  retl
a00f2ca4:  01 00 00 00  nop
