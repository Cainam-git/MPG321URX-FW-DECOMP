# leon2s FUN_a00a6fc0 0xa00a6fc0-0xa00a7058 (152 bytes)
a00a6fc0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a6fc4:  80 a2 20 02  cmp  %o0, 2
a00a6fc8:  18 80 00 22  bgu  0xa00a7050
a00a6fcc:  01 00 00 00  nop
a00a6fd0:  12 80 00 15  bne  0xa00a7024
a00a6fd4:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a6fd8:  9b 2a 60 10  sll  %o1, 0x10, %o5
a00a6fdc:  90 10 61 90  or  %g1, 0x190, %o0
a00a6fe0:  93 33 60 10  srl  %o5, 0x10, %o1
a00a6fe4:  94 0a a0 ff  and  %o2, 0xff, %o2
a00a6fe8:  98 10 20 00  clr  %o4
a00a6fec:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00a6ff0:  82 0b 20 ff  and  %o4, 0xff, %g1
a00a6ff4:  82 00 40 01  add  %g1, %g1, %g1
a00a6ff8:  c2 12 00 01  lduh  [ %o0 + %g1 ], %g1
a00a6ffc:  82 00 40 09  add  %g1, %o1, %g1
a00a7000:  83 28 60 02  sll  %g1, 2, %g1
a00a7004:  98 03 20 01  inc  %o4
a00a7008:  82 10 40 0b  or  %g1, %o3, %g1
a00a700c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00a7010:  d4 20 40 00  st  %o2, [ %g1 ]
a00a7014:  80 a3 60 01  cmp  %o5, 1
a00a7018:  08 bf ff f7  bleu  0xa00a6ff4
a00a701c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00a7020:  30 80 00 0c  b,a   0xa00a7050
a00a7024:  98 02 00 08  add  %o0, %o0, %o4
a00a7028:  9b 2a 60 10  sll  %o1, 0x10, %o5
a00a702c:  82 10 61 90  or  %g1, 0x190, %g1
a00a7030:  9b 33 60 10  srl  %o5, 0x10, %o5
a00a7034:  c2 10 40 0c  lduh  [ %g1 + %o4 ], %g1
a00a7038:  82 00 40 0d  add  %g1, %o5, %g1
a00a703c:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a7040:  83 28 60 02  sll  %g1, 2, %g1
a00a7044:  82 10 40 0d  or  %g1, %o5, %g1
a00a7048:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00a704c:  da 20 40 00  st  %o5, [ %g1 ]
a00a7050:  81 c3 e0 08  retl
a00a7054:  01 00 00 00  nop
