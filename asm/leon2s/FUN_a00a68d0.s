# leon2s FUN_a00a68d0 0xa00a68d0-0xa00a6938 (104 bytes)
a00a68d0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a68d4:  9a 02 00 08  add  %o0, %o0, %o5
a00a68d8:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a68dc:  80 a2 20 01  cmp  %o0, 1
a00a68e0:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a00a68e4:  93 32 60 10  srl  %o1, 0x10, %o1
a00a68e8:  18 80 00 12  bgu  0xa00a6930
a00a68ec:  90 10 20 00  clr  %o0
a00a68f0:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a68f4:  82 10 61 9c  or  %g1, 0x19c, %g1	! 0xa00b4d9c
a00a68f8:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a68fc:  82 00 40 09  add  %g1, %o1, %g1
a00a6900:  9a 00 60 01  add  %g1, 1, %o5
a00a6904:  83 28 60 02  sll  %g1, 2, %g1
a00a6908:  9b 2b 60 02  sll  %o5, 2, %o5
a00a690c:  82 10 40 0c  or  %g1, %o4, %g1
a00a6910:  9a 13 40 0c  or  %o5, %o4, %o5
a00a6914:  d8 00 40 00  ld  [ %g1 ], %o4
a00a6918:  c2 03 40 00  ld  [ %o5 ], %g1
a00a691c:  83 28 60 08  sll  %g1, 8, %g1
a00a6920:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a6924:  82 10 40 0c  or  %g1, %o4, %g1
a00a6928:  83 28 60 10  sll  %g1, 0x10, %g1
a00a692c:  91 30 60 10  srl  %g1, 0x10, %o0
a00a6930:  81 c3 e0 08  retl
a00a6934:  01 00 00 00  nop
