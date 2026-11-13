# leon2s FUN_a00a6bb8 0xa00a6bb8-0xa00a6c00 (72 bytes)
a00a6bb8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a6bbc:  9a 02 00 08  add  %o0, %o0, %o5
a00a6bc0:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a6bc4:  80 a2 20 01  cmp  %o0, 1
a00a6bc8:  93 32 60 10  srl  %o1, 0x10, %o1
a00a6bcc:  18 80 00 0b  bgu  0xa00a6bf8
a00a6bd0:  90 10 20 00  clr  %o0
a00a6bd4:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a6bd8:  82 10 61 94  or  %g1, 0x194, %g1	! 0xa00b4d94
a00a6bdc:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a6be0:  82 00 40 09  add  %g1, %o1, %g1
a00a6be4:  83 28 60 02  sll  %g1, 2, %g1
a00a6be8:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a6bec:  82 10 40 0d  or  %g1, %o5, %g1
a00a6bf0:  c2 00 40 00  ld  [ %g1 ], %g1
a00a6bf4:  90 08 60 ff  and  %g1, 0xff, %o0
a00a6bf8:  81 c3 e0 08  retl
a00a6bfc:  01 00 00 00  nop
