# leon2s FUN_a00a78fc 0xa00a78fc-0xa00a7940 (68 bytes)
a00a78fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a7900:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a7904:  9a 02 00 08  add  %o0, %o0, %o5
a00a7908:  93 32 60 10  srl  %o1, 0x10, %o1
a00a790c:  80 a2 20 04  cmp  %o0, 4
a00a7910:  18 80 00 0a  bgu  0xa00a7938
a00a7914:  94 0a a0 ff  and  %o2, 0xff, %o2
a00a7918:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a791c:  82 10 61 7a  or  %g1, 0x17a, %g1	! 0xa00b4d7a
a00a7920:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a7924:  82 00 40 09  add  %g1, %o1, %g1
a00a7928:  83 28 60 02  sll  %g1, 2, %g1
a00a792c:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a7930:  82 10 40 0d  or  %g1, %o5, %g1
a00a7934:  d4 20 40 00  st  %o2, [ %g1 ]
a00a7938:  81 c3 e0 08  retl
a00a793c:  01 00 00 00  nop
