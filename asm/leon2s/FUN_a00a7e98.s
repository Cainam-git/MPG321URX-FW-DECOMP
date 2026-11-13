# leon2s FUN_a00a7e98 0xa00a7e98-0xa00a7ee0 (72 bytes)
a00a7e98:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a7e9c:  9a 02 00 08  add  %o0, %o0, %o5
a00a7ea0:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a7ea4:  80 a2 20 03  cmp  %o0, 3
a00a7ea8:  93 32 60 10  srl  %o1, 0x10, %o1
a00a7eac:  18 80 00 0b  bgu  0xa00a7ed8
a00a7eb0:  90 10 20 00  clr  %o0
a00a7eb4:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7eb8:  82 10 61 64  or  %g1, 0x164, %g1	! 0xa00b4d64
a00a7ebc:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a7ec0:  82 00 40 09  add  %g1, %o1, %g1
a00a7ec4:  83 28 60 02  sll  %g1, 2, %g1
a00a7ec8:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a7ecc:  82 10 40 0d  or  %g1, %o5, %g1
a00a7ed0:  c2 00 40 00  ld  [ %g1 ], %g1
a00a7ed4:  90 08 60 ff  and  %g1, 0xff, %o0
a00a7ed8:  81 c3 e0 08  retl
a00a7edc:  01 00 00 00  nop
