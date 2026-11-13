# leon2s FUN_a00a78b4 0xa00a78b4-0xa00a78fc (72 bytes)
a00a78b4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a78b8:  9a 02 00 08  add  %o0, %o0, %o5
a00a78bc:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a78c0:  80 a2 20 04  cmp  %o0, 4
a00a78c4:  93 32 60 10  srl  %o1, 0x10, %o1
a00a78c8:  18 80 00 0b  bgu  0xa00a78f4
a00a78cc:  90 10 20 00  clr  %o0
a00a78d0:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a78d4:  82 10 61 7a  or  %g1, 0x17a, %g1	! 0xa00b4d7a
a00a78d8:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a78dc:  82 00 40 09  add  %g1, %o1, %g1
a00a78e0:  83 28 60 02  sll  %g1, 2, %g1
a00a78e4:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a78e8:  82 10 40 0d  or  %g1, %o5, %g1
a00a78ec:  c2 00 40 00  ld  [ %g1 ], %g1
a00a78f0:  90 08 60 ff  and  %g1, 0xff, %o0
a00a78f4:  81 c3 e0 08  retl
a00a78f8:  01 00 00 00  nop
