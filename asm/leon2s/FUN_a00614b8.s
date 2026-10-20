# leon2s FUN_a00614b8 0xa00614b8-0xa0061528 (112 bytes)
a00614b8:  9d e3 bf 98  save  %sp, -104, %sp
a00614bc:  9e 10 00 18  mov  %i0, %o7
a00614c0:  80 a6 40 1a  cmp  %i1, %i2
a00614c4:  b0 10 20 01  mov  1, %i0
a00614c8:  0a 80 00 16  bcs  0xa0061520
a00614cc:  b8 10 20 01  mov  1, %i4
a00614d0:  82 10 20 01  mov  1, %g1
a00614d4:  bb 28 40 19  sll  %g1, %i1, %i5
a00614d8:  83 28 40 1a  sll  %g1, %i2, %g1
a00614dc:  82 27 40 01  sub  %i5, %g1, %g1
a00614e0:  ba 10 40 1d  or  %g1, %i5, %i5
a00614e4:  83 2e c0 1a  sll  %i3, %i2, %g1
a00614e8:  80 a6 60 1f  cmp  %i1, 0x1f
a00614ec:  18 80 00 03  bgu  0xa00614f8
a00614f0:  b6 08 40 1d  and  %g1, %i5, %i3
a00614f4:  b0 10 20 00  clr  %i0
a00614f8:  80 a6 a0 1f  cmp  %i2, 0x1f
a00614fc:  28 80 00 02  bleu,a   0xa0061504
a0061500:  b8 10 20 00  clr  %i4
a0061504:  80 96 00 1c  orcc  %i0, %i4, %g0
a0061508:  12 80 00 06  bne  0xa0061520
a006150c:  01 00 00 00  nop
a0061510:  c2 03 c0 00  ld  [ %o7 ], %g1
a0061514:  82 28 40 1d  andn  %g1, %i5, %g1
a0061518:  82 10 40 1b  or  %g1, %i3, %g1
a006151c:  c2 23 c0 00  st  %g1, [ %o7 ]
a0061520:  81 c7 e0 08  ret
a0061524:  81 e8 00 00  restore
