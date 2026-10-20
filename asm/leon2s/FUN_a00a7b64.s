# leon2s FUN_a00a7b64 0xa00a7b64-0xa00a7bf8 (148 bytes)
a00a7b64:  82 10 00 09  mov  %o1, %g1
a00a7b68:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a7b6c:  83 28 60 10  sll  %g1, 0x10, %g1
a00a7b70:  96 02 00 08  add  %o0, %o0, %o3
a00a7b74:  94 0a a0 ff  and  %o2, 0xff, %o2
a00a7b78:  80 a2 20 04  cmp  %o0, 4
a00a7b7c:  18 80 00 1d  bgu  0xa00a7bf0
a00a7b80:  99 30 60 10  srl  %g1, 0x10, %o4
a00a7b84:  83 2a 60 10  sll  %o1, 0x10, %g1
a00a7b88:  80 a2 20 00  cmp  %o0, 0
a00a7b8c:  02 80 00 11  be  0xa00a7bd0
a00a7b90:  93 30 60 10  srl  %g1, 0x10, %o1
a00a7b94:  82 02 3f ff  add  %o0, -1, %g1
a00a7b98:  80 a2 60 5f  cmp  %o1, 0x5f
a00a7b9c:  18 80 00 0d  bgu  0xa00a7bd0
a00a7ba0:  91 28 60 06  sll  %g1, 6, %o0
a00a7ba4:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7ba8:  82 10 61 70  or  %g1, 0x170, %g1	! 0xa00b4d70
a00a7bac:  da 10 40 0b  lduh  [ %g1 + %o3 ], %o5
a00a7bb0:  9a 03 60 60  add  %o5, 0x60, %o5
a00a7bb4:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00a7bb8:  9b 2b 60 02  sll  %o5, 2, %o5
a00a7bbc:  9a 13 40 01  or  %o5, %g1, %o5
a00a7bc0:  c2 03 40 00  ld  [ %o5 ], %g1
a00a7bc4:  82 08 60 3f  and  %g1, 0x3f, %g1
a00a7bc8:  82 10 40 08  or  %g1, %o0, %g1
a00a7bcc:  c2 23 40 00  st  %g1, [ %o5 ]
a00a7bd0:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7bd4:  82 10 61 70  or  %g1, 0x170, %g1	! 0xa00b4d70
a00a7bd8:  c2 10 40 0b  lduh  [ %g1 + %o3 ], %g1
a00a7bdc:  82 00 40 0c  add  %g1, %o4, %g1
a00a7be0:  83 28 60 02  sll  %g1, 2, %g1
a00a7be4:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a7be8:  82 10 40 0d  or  %g1, %o5, %g1
a00a7bec:  d4 20 40 00  st  %o2, [ %g1 ]
a00a7bf0:  81 c3 e0 08  retl
a00a7bf4:  01 00 00 00  nop
