# leon2s FUN_a00a79c4 0xa00a79c4-0xa00a7a5c (152 bytes)
a00a79c4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a79c8:  9a 02 00 08  add  %o0, %o0, %o5
a00a79cc:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a79d0:  80 a2 20 04  cmp  %o0, 4
a00a79d4:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00a79d8:  93 32 60 10  srl  %o1, 0x10, %o1
a00a79dc:  18 80 00 1e  bgu  0xa00a7a54
a00a79e0:  90 10 20 00  clr  %o0
a00a79e4:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a79e8:  82 10 61 7a  or  %g1, 0x17a, %g1	! 0xa00b4d7a
a00a79ec:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a79f0:  82 00 40 09  add  %g1, %o1, %g1
a00a79f4:  9b 28 60 02  sll  %g1, 2, %o5
a00a79f8:  98 00 60 01  add  %g1, 1, %o4
a00a79fc:  9a 13 40 0b  or  %o5, %o3, %o5
a00a7a00:  99 2b 20 02  sll  %o4, 2, %o4
a00a7a04:  82 00 60 02  add  %g1, 2, %g1
a00a7a08:  da 03 40 00  ld  [ %o5 ], %o5
a00a7a0c:  98 13 00 0b  or  %o4, %o3, %o4
a00a7a10:  83 28 60 02  sll  %g1, 2, %g1
a00a7a14:  82 10 40 0b  or  %g1, %o3, %g1
a00a7a18:  d8 03 00 00  ld  [ %o4 ], %o4
a00a7a1c:  d0 00 40 00  ld  [ %g1 ], %o0
a00a7a20:  96 0b 60 ff  and  %o5, 0xff, %o3
a00a7a24:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a7a28:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00a7a2c:  83 2b 20 08  sll  %o4, 8, %g1
a00a7a30:  80 a2 60 50  cmp  %o1, 0x50
a00a7a34:  12 80 00 04  bne  0xa00a7a44
a00a7a38:  9a 13 40 01  or  %o5, %g1, %o5
a00a7a3c:  10 80 00 06  b  0xa00a7a54
a00a7a40:  90 12 00 0d  or  %o0, %o5, %o0
a00a7a44:  91 2a 20 08  sll  %o0, 8, %o0
a00a7a48:  90 12 00 0c  or  %o0, %o4, %o0
a00a7a4c:  91 2a 20 08  sll  %o0, 8, %o0
a00a7a50:  90 12 00 0b  or  %o0, %o3, %o0
a00a7a54:  81 c3 e0 08  retl
a00a7a58:  01 00 00 00  nop
