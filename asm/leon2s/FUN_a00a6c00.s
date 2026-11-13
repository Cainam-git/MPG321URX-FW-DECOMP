# leon2s FUN_a00a6c00 0xa00a6c00-0xa00a6c98 (152 bytes)
a00a6c00:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a6c04:  80 a2 20 02  cmp  %o0, 2
a00a6c08:  18 80 00 22  bgu  0xa00a6c90
a00a6c0c:  01 00 00 00  nop
a00a6c10:  12 80 00 15  bne  0xa00a6c64
a00a6c14:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a6c18:  9b 2a 60 10  sll  %o1, 0x10, %o5
a00a6c1c:  90 10 61 94  or  %g1, 0x194, %o0
a00a6c20:  93 33 60 10  srl  %o5, 0x10, %o1
a00a6c24:  94 0a a0 ff  and  %o2, 0xff, %o2
a00a6c28:  98 10 20 00  clr  %o4
a00a6c2c:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00a6c30:  82 0b 20 ff  and  %o4, 0xff, %g1
a00a6c34:  82 00 40 01  add  %g1, %g1, %g1
a00a6c38:  c2 12 00 01  lduh  [ %o0 + %g1 ], %g1
a00a6c3c:  82 00 40 09  add  %g1, %o1, %g1
a00a6c40:  83 28 60 02  sll  %g1, 2, %g1
a00a6c44:  98 03 20 01  inc  %o4
a00a6c48:  82 10 40 0b  or  %g1, %o3, %g1
a00a6c4c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00a6c50:  d4 20 40 00  st  %o2, [ %g1 ]
a00a6c54:  80 a3 60 01  cmp  %o5, 1
a00a6c58:  08 bf ff f7  bleu  0xa00a6c34
a00a6c5c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00a6c60:  30 80 00 0c  b,a   0xa00a6c90
a00a6c64:  98 02 00 08  add  %o0, %o0, %o4
a00a6c68:  9b 2a 60 10  sll  %o1, 0x10, %o5
a00a6c6c:  82 10 61 94  or  %g1, 0x194, %g1
a00a6c70:  9b 33 60 10  srl  %o5, 0x10, %o5
a00a6c74:  c2 10 40 0c  lduh  [ %g1 + %o4 ], %g1
a00a6c78:  82 00 40 0d  add  %g1, %o5, %g1
a00a6c7c:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a6c80:  83 28 60 02  sll  %g1, 2, %g1
a00a6c84:  82 10 40 0d  or  %g1, %o5, %g1
a00a6c88:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00a6c8c:  da 20 40 00  st  %o5, [ %g1 ]
a00a6c90:  81 c3 e0 08  retl
a00a6c94:  01 00 00 00  nop
