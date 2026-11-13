# leon2m FUN_a014459c 0xa014459c-0xa01445fc (96 bytes)
a014459c:  9d e3 bf 98  save  %sp, -104, %sp
a01445a0:  03 00 06 9b  sethi  %hi(0x1a6c00), %g1
a01445a4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01445a8:  b2 10 61 b2  or  %g1, 0x1b2, %i1
a01445ac:  9e 10 3f ff  mov  -1, %o7
a01445b0:  b4 10 20 00  clr  %i2
a01445b4:  10 80 00 05  b  0xa01445c8
a01445b8:  b8 10 20 00  clr  %i4
a01445bc:  80 a7 20 03  cmp  %i4, 3
a01445c0:  38 80 00 0d  bgu,a   0xa01445f4
a01445c4:  b0 0b e0 ff  and  %o7, 0xff, %i0
a01445c8:  b6 07 00 1c  add  %i4, %i4, %i3
a01445cc:  ba 06 c0 19  add  %i3, %i1, %i5
a01445d0:  b4 06 a0 01  inc  %i2
a01445d4:  c2 0f 60 01  ldub  [ %i5 + 1 ], %g1
a01445d8:  80 a0 40 18  cmp  %g1, %i0
a01445dc:  12 bf ff f8  bne  0xa01445bc
a01445e0:  b8 0e a0 ff  and  %i2, 0xff, %i4
a01445e4:  80 a7 20 03  cmp  %i4, 3
a01445e8:  08 bf ff f8  bleu  0xa01445c8
a01445ec:  de 0e 40 1b  ldub  [ %i1 + %i3 ], %o7
a01445f0:  b0 0b e0 ff  and  %o7, 0xff, %i0
a01445f4:  81 c7 e0 08  ret
a01445f8:  81 e8 00 00  restore
