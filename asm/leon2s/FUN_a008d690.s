# leon2s FUN_a008d690 0xa008d690-0xa008d70c (124 bytes)
a008d690:  9d e3 bf 98  save  %sp, -104, %sp
a008d694:  03 28 02 d0  sethi  %hi(0xa00b4000), %g1
a008d698:  96 10 60 36  or  %g1, 0x36, %o3	! 0xa00b4036
a008d69c:  98 10 20 00  clr  %o4
a008d6a0:  9a 10 20 0c  mov  0xc, %o5
a008d6a4:  82 0b 60 ff  and  %o5, 0xff, %g1
a008d6a8:  83 28 60 02  sll  %g1, 2, %g1
a008d6ac:  82 00 40 0b  add  %g1, %o3, %g1
a008d6b0:  c2 10 60 02  lduh  [ %g1 + 2 ], %g1
a008d6b4:  92 03 00 01  add  %o4, %g1, %o1
a008d6b8:  9a 03 60 01  inc  %o5
a008d6bc:  82 0b 60 ff  and  %o5, 0xff, %g1
a008d6c0:  80 a0 60 10  cmp  %g1, 0x10
a008d6c4:  08 bf ff f9  bleu  0xa008d6a8
a008d6c8:  98 10 00 09  mov  %o1, %o4
a008d6cc:  21 27 c6 c1  sethi  %hi(0x9f1b0400), %l0
a008d6d0:  93 2a 60 10  sll  %o1, 0x10, %o1
a008d6d4:  d0 12 e0 30  lduh  [ %o3 + 0x30 ], %o0
a008d6d8:  93 32 60 10  srl  %o1, 0x10, %o1
a008d6dc:  7f ff ff 01  call  0xa008d2e0
a008d6e0:  94 14 22 00  or  %l0, 0x200, %o2
a008d6e4:  90 14 22 00  or  %l0, 0x200, %o0
a008d6e8:  92 10 20 0c  mov  0xc, %o1
a008d6ec:  7f ff ff 69  call  0xa008d490
a008d6f0:  94 10 20 11  mov  0x11, %o2
a008d6f4:  9a 10 20 01  mov  1, %o5
a008d6f8:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a008d6fc:  da 28 60 00  stb  %o5, [ %g1 ]
a008d700:  7f ff 89 f7  call  0xa006fedc
a008d704:  81 e8 00 00  restore
a008d708:  01 00 00 00  nop
