# leon2s FUN_a0061a6c 0xa0061a6c-0xa0061adc (112 bytes)
a0061a6c:  9d e3 bf 98  save  %sp, -104, %sp
a0061a70:  9e 10 00 18  mov  %i0, %o7
a0061a74:  80 a6 40 1a  cmp  %i1, %i2
a0061a78:  b0 10 20 01  mov  1, %i0
a0061a7c:  0a 80 00 16  bcs  0xa0061ad4
a0061a80:  b8 10 20 01  mov  1, %i4
a0061a84:  82 10 20 01  mov  1, %g1
a0061a88:  bb 28 40 19  sll  %g1, %i1, %i5
a0061a8c:  83 28 40 1a  sll  %g1, %i2, %g1
a0061a90:  82 27 40 01  sub  %i5, %g1, %g1
a0061a94:  ba 10 40 1d  or  %g1, %i5, %i5
a0061a98:  83 2e c0 1a  sll  %i3, %i2, %g1
a0061a9c:  80 a6 60 1f  cmp  %i1, 0x1f
a0061aa0:  18 80 00 03  bgu  0xa0061aac
a0061aa4:  b6 08 40 1d  and  %g1, %i5, %i3
a0061aa8:  b0 10 20 00  clr  %i0
a0061aac:  80 a6 a0 1f  cmp  %i2, 0x1f
a0061ab0:  28 80 00 02  bleu,a   0xa0061ab8
a0061ab4:  b8 10 20 00  clr  %i4
a0061ab8:  80 96 00 1c  orcc  %i0, %i4, %g0
a0061abc:  12 80 00 06  bne  0xa0061ad4
a0061ac0:  01 00 00 00  nop
a0061ac4:  c2 03 c0 00  ld  [ %o7 ], %g1
a0061ac8:  82 28 40 1d  andn  %g1, %i5, %g1
a0061acc:  82 10 40 1b  or  %g1, %i3, %g1
a0061ad0:  c2 23 c0 00  st  %g1, [ %o7 ]
a0061ad4:  81 c7 e0 08  ret
a0061ad8:  81 e8 00 00  restore
