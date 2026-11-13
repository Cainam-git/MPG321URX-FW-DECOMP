# leon2s FUN_a00a7cc0 0xa00a7cc0-0xa00a7d04 (68 bytes)
a00a7cc0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a7cc4:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a7cc8:  9a 02 00 08  add  %o0, %o0, %o5
a00a7ccc:  93 32 60 10  srl  %o1, 0x10, %o1
a00a7cd0:  80 a2 20 01  cmp  %o0, 1
a00a7cd4:  18 80 00 0a  bgu  0xa00a7cfc
a00a7cd8:  94 0a a0 ff  and  %o2, 0xff, %o2
a00a7cdc:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7ce0:  82 10 61 6c  or  %g1, 0x16c, %g1	! 0xa00b4d6c
a00a7ce4:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a7ce8:  82 00 40 09  add  %g1, %o1, %g1
a00a7cec:  83 28 60 02  sll  %g1, 2, %g1
a00a7cf0:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a7cf4:  82 10 40 0d  or  %g1, %o5, %g1
a00a7cf8:  d4 20 40 00  st  %o2, [ %g1 ]
a00a7cfc:  81 c3 e0 08  retl
a00a7d00:  01 00 00 00  nop
