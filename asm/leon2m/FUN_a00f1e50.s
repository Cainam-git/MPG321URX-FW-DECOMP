# leon2m FUN_a00f1e50 0xa00f1e50-0xa00f1ed8 (136 bytes)
a00f1e50:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f1e54:  80 a2 20 07  cmp  %o0, 7
a00f1e58:  08 80 00 14  bleu  0xa00f1ea8
a00f1e5c:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f1e60:  92 0a 60 ff  and  %o1, 0xff, %o1
a00f1e64:  94 0a a0 ff  and  %o2, 0xff, %o2
a00f1e68:  90 10 63 0c  or  %g1, 0x30c, %o0
a00f1e6c:  96 10 20 00  clr  %o3
a00f1e70:  9a 10 20 00  clr  %o5
a00f1e74:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a00f1e78:  9a 03 40 0d  add  %o5, %o5, %o5
a00f1e7c:  c2 12 00 0d  lduh  [ %o0 + %o5 ], %g1
a00f1e80:  82 00 40 09  add  %g1, %o1, %g1
a00f1e84:  9b 28 60 02  sll  %g1, 2, %o5
a00f1e88:  82 13 40 0c  or  %o5, %o4, %g1
a00f1e8c:  96 02 e0 01  inc  %o3
a00f1e90:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00f1e94:  d4 20 40 00  st  %o2, [ %g1 ]
a00f1e98:  80 a3 60 07  cmp  %o5, 7
a00f1e9c:  28 bf ff f8  bleu,a   0xa00f1e7c
a00f1ea0:  9a 03 40 0d  add  %o5, %o5, %o5
a00f1ea4:  30 80 00 0b  b,a   0xa00f1ed0
a00f1ea8:  98 02 00 08  add  %o0, %o0, %o4
a00f1eac:  96 10 63 0c  or  %g1, 0x30c, %o3
a00f1eb0:  da 12 c0 0c  lduh  [ %o3 + %o4 ], %o5
a00f1eb4:  90 0a 60 ff  and  %o1, 0xff, %o0
a00f1eb8:  82 03 40 08  add  %o5, %o0, %g1
a00f1ebc:  93 28 60 02  sll  %g1, 2, %o1
a00f1ec0:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00f1ec4:  90 12 40 0b  or  %o1, %o3, %o0
a00f1ec8:  98 0a a0 ff  and  %o2, 0xff, %o4
a00f1ecc:  d8 22 00 00  st  %o4, [ %o0 ]
a00f1ed0:  81 c3 e0 08  retl
a00f1ed4:  01 00 00 00  nop
