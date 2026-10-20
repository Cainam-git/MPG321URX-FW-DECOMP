# leon2s FUN_a00a7fd8 0xa00a7fd8-0xa00a8054 (124 bytes)
a00a7fd8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a7fdc:  82 02 00 08  add  %o0, %o0, %g1
a00a7fe0:  82 00 40 08  add  %g1, %o0, %g1
a00a7fe4:  82 00 40 01  add  %g1, %g1, %g1
a00a7fe8:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a7fec:  95 2a a0 10  sll  %o2, 0x10, %o2
a00a7ff0:  82 00 40 09  add  %g1, %o1, %g1
a00a7ff4:  80 a2 20 01  cmp  %o0, 1
a00a7ff8:  95 32 a0 10  srl  %o2, 0x10, %o2
a00a7ffc:  96 00 40 01  add  %g1, %g1, %o3
a00a8000:  98 10 20 01  mov  1, %o4
a00a8004:  9a 10 20 01  mov  1, %o5
a00a8008:  18 80 00 03  bgu  0xa00a8014
a00a800c:  90 10 20 00  clr  %o0
a00a8010:  98 10 20 00  clr  %o4
a00a8014:  80 a2 60 05  cmp  %o1, 5
a00a8018:  28 80 00 02  bleu,a   0xa00a8020
a00a801c:  9a 10 20 00  clr  %o5
a00a8020:  80 93 00 0d  orcc  %o4, %o5, %g0
a00a8024:  12 80 00 0a  bne  0xa00a804c
a00a8028:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a802c:  82 10 61 44  or  %g1, 0x144, %g1	! 0xa00b4d44
a00a8030:  c2 10 40 0b  lduh  [ %g1 + %o3 ], %g1
a00a8034:  82 00 40 0a  add  %g1, %o2, %g1
a00a8038:  83 28 60 02  sll  %g1, 2, %g1
a00a803c:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a8040:  82 10 40 0d  or  %g1, %o5, %g1
a00a8044:  c2 00 40 00  ld  [ %g1 ], %g1
a00a8048:  90 08 60 ff  and  %g1, 0xff, %o0
a00a804c:  81 c3 e0 08  retl
a00a8050:  01 00 00 00  nop
