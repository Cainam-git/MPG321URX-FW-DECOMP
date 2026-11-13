# leon2s FUN_a00a7dd0 0xa00a7dd0-0xa00a7e14 (68 bytes)
a00a7dd0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a7dd4:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a7dd8:  9a 02 00 08  add  %o0, %o0, %o5
a00a7ddc:  93 32 60 10  srl  %o1, 0x10, %o1
a00a7de0:  80 a2 20 03  cmp  %o0, 3
a00a7de4:  18 80 00 0a  bgu  0xa00a7e0c
a00a7de8:  94 0a a0 ff  and  %o2, 0xff, %o2
a00a7dec:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7df0:  82 10 61 64  or  %g1, 0x164, %g1	! 0xa00b4d64
a00a7df4:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a7df8:  82 00 40 09  add  %g1, %o1, %g1
a00a7dfc:  83 28 60 02  sll  %g1, 2, %g1
a00a7e00:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a7e04:  82 10 40 0d  or  %g1, %o5, %g1
a00a7e08:  d4 20 40 00  st  %o2, [ %g1 ]
a00a7e0c:  81 c3 e0 08  retl
a00a7e10:  01 00 00 00  nop
