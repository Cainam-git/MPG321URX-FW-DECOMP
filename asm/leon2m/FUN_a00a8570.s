# leon2m FUN_a00a8570 0xa00a8570-0xa00a8654 (228 bytes)
a00a8570:  9d e3 bf 98  save  %sp, -104, %sp
a00a8574:  90 10 21 11  mov  0x111, %o0
a00a8578:  40 02 79 76  call  0xa0146b50
a00a857c:  92 10 20 00  clr  %o1
a00a8580:  90 10 20 00  clr  %o0
a00a8584:  40 02 79 7a  call  0xa0146b6c
a00a8588:  92 10 20 00  clr  %o1
a00a858c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00a8590:  b4 10 62 90  or  %g1, 0x290, %i2	! 0xa802d290
a00a8594:  b8 10 20 00  clr  %i4
a00a8598:  ba 10 20 00  clr  %i5
a00a859c:  37 00 06 36  sethi  %hi(0x18d800), %i3
a00a85a0:  b1 2f 60 03  sll  %i5, 3, %i0
a00a85a4:  9e 26 00 1d  sub  %i0, %i5, %o7
a00a85a8:  9b 2b e0 02  sll  %o7, 2, %o5
a00a85ac:  96 03 40 1d  add  %o5, %i5, %o3
a00a85b0:  d8 0e a0 08  ldub  [ %i2 + 8 ], %o4
a00a85b4:  90 02 c0 0c  add  %o3, %o4, %o0
a00a85b8:  93 2a 20 10  sll  %o0, 0x10, %o1
a00a85bc:  93 32 60 10  srl  %o1, 0x10, %o1
a00a85c0:  7f ff ec a1  call  0xa00a3844
a00a85c4:  90 16 e3 28  or  %i3, 0x328, %o0
a00a85c8:  98 10 00 08  mov  %o0, %o4
a00a85cc:  94 07 40 1d  add  %i5, %i5, %o2
a00a85d0:  94 02 a0 06  add  %o2, 6, %o2
a00a85d4:  90 10 20 00  clr  %o0
a00a85d8:  92 10 20 2a  mov  0x2a, %o1
a00a85dc:  96 10 20 01  mov  1, %o3
a00a85e0:  9a 10 20 00  clr  %o5
a00a85e4:  7f ff ea f0  call  0xa00a31a4
a00a85e8:  b8 07 20 01  inc  %i4
a00a85ec:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00a85f0:  80 a7 60 03  cmp  %i5, 3
a00a85f4:  08 bf ff ec  bleu  0xa00a85a4
a00a85f8:  b1 2f 60 03  sll  %i5, 3, %i0
a00a85fc:  da 0e a0 11  ldub  [ %i2 + 0x11 ], %o5
a00a8600:  b2 03 40 0d  add  %o5, %o5, %i1
a00a8604:  80 a3 60 06  cmp  %o5, 6
a00a8608:  08 80 00 04  bleu  0xa00a8618
a00a860c:  82 06 60 06  add  %i1, 6, %g1
a00a8610:  b4 03 40 0d  add  %o5, %o5, %i2
a00a8614:  82 06 bf f8  add  %i2, -8, %g1
a00a8618:  b4 08 60 ff  and  %g1, 0xff, %i2
a00a861c:  90 10 20 00  clr  %o0
a00a8620:  92 10 20 28  mov  0x28, %o1
a00a8624:  94 10 00 1a  mov  %i2, %o2
a00a8628:  96 10 20 01  mov  1, %o3
a00a862c:  98 10 20 0f  mov  0xf, %o4
a00a8630:  40 02 79 3c  call  0xa0146b20
a00a8634:  9a 10 20 00  clr  %o5
a00a8638:  b0 10 20 00  clr  %i0
a00a863c:  b2 10 20 29  mov  0x29, %i1
a00a8640:  b6 10 20 01  mov  1, %i3
a00a8644:  b8 10 20 10  mov  0x10, %i4
a00a8648:  40 02 79 36  call  0xa0146b20
a00a864c:  9b e8 20 00  restore  %g0, 0, %o5
a00a8650:  01 00 00 00  nop
