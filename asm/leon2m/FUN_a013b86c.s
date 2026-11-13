# leon2m FUN_a013b86c 0xa013b86c-0xa013b92c (192 bytes)
a013b86c:  9d e3 bf 98  save  %sp, -104, %sp
a013b870:  96 0e 20 ff  and  %i0, 0xff, %o3
a013b874:  80 a2 e0 03  cmp  %o3, 3
a013b878:  b0 10 20 00  clr  %i0
a013b87c:  18 80 00 13  bgu  0xa013b8c8
a013b880:  a2 10 20 00  clr  %l1
a013b884:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a013b888:  94 10 63 30  or  %g1, 0x330, %o2	! 0xa802df30
a013b88c:  98 10 20 00  clr  %o4
a013b890:  83 2b 20 04  sll  %o4, 4, %g1
a013b894:  a0 20 40 0c  sub  %g1, %o4, %l0
a013b898:  9f 2c 20 03  sll  %l0, 3, %o7
a013b89c:  d2 02 80 0f  ld  [ %o2 + %o7 ], %o1
a013b8a0:  91 32 60 0c  srl  %o1, 0xc, %o0
a013b8a4:  9a 0a 20 0f  and  %o0, 0xf, %o5
a013b8a8:  80 a2 c0 0d  cmp  %o3, %o5
a013b8ac:  02 80 00 0c  be  0xa013b8dc
a013b8b0:  80 a3 20 03  cmp  %o4, 3
a013b8b4:  b0 06 20 01  inc  %i0
a013b8b8:  98 0e 20 ff  and  %i0, 0xff, %o4
a013b8bc:  80 a3 20 03  cmp  %o4, 3
a013b8c0:  08 bf ff f5  bleu  0xa013b894
a013b8c4:  83 2b 20 04  sll  %o4, 4, %g1
a013b8c8:  80 8c 60 ff  btst  0xff, %l1
a013b8cc:  22 80 00 15  be,a   0xa013b920
a013b8d0:  b0 10 3f ff  mov  -1, %i0
a013b8d4:  10 80 00 14  b  0xa013b924
a013b8d8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013b8dc:  18 bf ff fc  bgu  0xa013b8cc
a013b8e0:  80 8c 60 ff  btst  0xff, %l1
a013b8e4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a013b8e8:  b0 10 20 00  clr  %i0
a013b8ec:  90 10 20 00  clr  %o0
a013b8f0:  40 00 1f 71  call  0xa01436b4
a013b8f4:  01 00 00 00  nop
a013b8f8:  96 0a 20 ff  and  %o0, 0xff, %o3
a013b8fc:  80 a2 c0 10  cmp  %o3, %l0
a013b900:  22 bf ff f2  be,a   0xa013b8c8
a013b904:  a2 10 20 01  mov  1, %l1
a013b908:  b0 06 20 01  inc  %i0
a013b90c:  90 0e 20 ff  and  %i0, 0xff, %o0
a013b910:  80 a2 20 03  cmp  %o0, 3
a013b914:  08 bf ff f7  bleu  0xa013b8f0
a013b918:  80 8c 60 ff  btst  0xff, %l1
a013b91c:  30 bf ff ec  b,a   0xa013b8cc
a013b920:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013b924:  81 c7 e0 08  ret
a013b928:  81 e8 00 00  restore
