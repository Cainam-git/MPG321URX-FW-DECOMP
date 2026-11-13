# leon2s FUN_a00b2790 0xa00b2790-0xa00b281c (140 bytes)
a00b2790:  9d e3 bf 98  save  %sp, -104, %sp
a00b2794:  9e 10 20 00  clr  %o7
a00b2798:  9a 10 00 19  mov  %i1, %o5
a00b279c:  80 a3 c0 19  cmp  %o7, %i1
a00b27a0:  b2 10 20 00  clr  %i1
a00b27a4:  16 80 00 1c  bge  0xa00b2814
a00b27a8:  01 00 00 00  nop
a00b27ac:  f8 0e 00 19  ldub  [ %i0 + %i1 ], %i4
a00b27b0:  82 07 3f bf  add  %i4, -65, %g1
a00b27b4:  b6 07 3f d0  add  %i4, -48, %i3
a00b27b8:  ba 08 60 ff  and  %g1, 0xff, %i5
a00b27bc:  82 0e e0 ff  and  %i3, 0xff, %g1
a00b27c0:  80 a0 60 09  cmp  %g1, 9
a00b27c4:  18 80 00 04  bgu  0xa00b27d4
a00b27c8:  b4 10 20 00  clr  %i2
a00b27cc:  10 80 00 0b  b  0xa00b27f8
a00b27d0:  b4 10 00 1b  mov  %i3, %i2
a00b27d4:  82 07 3f 9f  add  %i4, -97, %g1
a00b27d8:  80 a7 60 05  cmp  %i5, 5
a00b27dc:  18 80 00 04  bgu  0xa00b27ec
a00b27e0:  82 08 60 ff  and  %g1, 0xff, %g1
a00b27e4:  10 80 00 05  b  0xa00b27f8
a00b27e8:  b4 07 3f c9  add  %i4, -55, %i2
a00b27ec:  80 a0 60 05  cmp  %g1, 5
a00b27f0:  28 80 00 02  bleu,a   0xa00b27f8
a00b27f4:  b4 07 3f a9  add  %i4, -87, %i2
a00b27f8:  83 2e a0 18  sll  %i2, 0x18, %g1
a00b27fc:  bb 2b e0 04  sll  %o7, 4, %i5
a00b2800:  83 38 60 18  sra  %g1, 0x18, %g1
a00b2804:  b2 06 60 01  inc  %i1
a00b2808:  9e 07 40 01  add  %i5, %g1, %o7
a00b280c:  10 bf ff e6  b  0xa00b27a4
a00b2810:  80 a6 40 0d  cmp  %i1, %o5
a00b2814:  81 c7 e0 08  ret
a00b2818:  91 e8 00 0f  restore  %g0, %o7, %o0
