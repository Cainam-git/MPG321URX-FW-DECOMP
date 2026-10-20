# leon2m FUN_a014e974 0xa014e974-0xa014e9d8 (100 bytes)
a014e974:  9d e3 bf 98  save  %sp, -104, %sp
a014e978:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a014e97c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014e980:  9e 10 60 80  or  %g1, 0x80, %o7
a014e984:  b2 10 20 00  clr  %i1
a014e988:  b8 10 20 00  clr  %i4
a014e98c:  ba 10 20 00  clr  %i5
a014e990:  10 80 00 05  b  0xa014e9a4
a014e994:  b4 10 20 01  mov  1, %i2
a014e998:  80 a7 60 08  cmp  %i5, 8
a014e99c:  38 80 00 0c  bgu,a   0xa014e9cc
a014e9a0:  b1 2e 60 10  sll  %i1, 0x10, %i0
a014e9a4:  c2 0b c0 1d  ldub  [ %o7 + %i5 ], %g1
a014e9a8:  b8 07 20 01  inc  %i4
a014e9ac:  b7 2e 80 1d  sll  %i2, %i5, %i3
a014e9b0:  80 a6 00 01  cmp  %i0, %g1
a014e9b4:  12 bf ff f9  bne  0xa014e998
a014e9b8:  ba 0f 20 ff  and  %i4, 0xff, %i5
a014e9bc:  80 a7 60 08  cmp  %i5, 8
a014e9c0:  08 bf ff f9  bleu  0xa014e9a4
a014e9c4:  b2 16 c0 19  or  %i3, %i1, %i1
a014e9c8:  b1 2e 60 10  sll  %i1, 0x10, %i0
a014e9cc:  b1 36 20 10  srl  %i0, 0x10, %i0
a014e9d0:  81 c7 e0 08  ret
a014e9d4:  81 e8 00 00  restore
