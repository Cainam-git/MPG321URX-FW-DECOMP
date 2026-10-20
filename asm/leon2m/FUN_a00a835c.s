# leon2m FUN_a00a835c 0xa00a835c-0xa00a8440 (228 bytes)
a00a835c:  9d e3 bf 98  save  %sp, -104, %sp
a00a8360:  90 10 21 11  mov  0x111, %o0
a00a8364:  40 02 79 fb  call  0xa0146b50
a00a8368:  92 10 20 00  clr  %o1
a00a836c:  90 10 20 00  clr  %o0
a00a8370:  40 02 79 ff  call  0xa0146b6c
a00a8374:  92 10 20 00  clr  %o1
a00a8378:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00a837c:  b4 10 62 90  or  %g1, 0x290, %i2	! 0xa802d290
a00a8380:  b8 10 20 00  clr  %i4
a00a8384:  ba 10 20 00  clr  %i5
a00a8388:  37 00 06 24  sethi  %hi(0x189000), %i3
a00a838c:  b1 2f 60 03  sll  %i5, 3, %i0
a00a8390:  9e 26 00 1d  sub  %i0, %i5, %o7
a00a8394:  9b 2b e0 02  sll  %o7, 2, %o5
a00a8398:  96 03 40 1d  add  %o5, %i5, %o3
a00a839c:  d8 0e a0 08  ldub  [ %i2 + 8 ], %o4
a00a83a0:  90 02 c0 0c  add  %o3, %o4, %o0
a00a83a4:  93 2a 20 10  sll  %o0, 0x10, %o1
a00a83a8:  93 32 60 10  srl  %o1, 0x10, %o1
a00a83ac:  7f ff ed 26  call  0xa00a3844
a00a83b0:  90 16 e0 d4  or  %i3, 0xd4, %o0
a00a83b4:  98 10 00 08  mov  %o0, %o4
a00a83b8:  94 07 40 1d  add  %i5, %i5, %o2
a00a83bc:  94 02 a0 06  add  %o2, 6, %o2
a00a83c0:  90 10 20 00  clr  %o0
a00a83c4:  92 10 20 2a  mov  0x2a, %o1
a00a83c8:  96 10 20 01  mov  1, %o3
a00a83cc:  9a 10 20 00  clr  %o5
a00a83d0:  7f ff eb 75  call  0xa00a31a4
a00a83d4:  b8 07 20 01  inc  %i4
a00a83d8:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00a83dc:  80 a7 60 04  cmp  %i5, 4
a00a83e0:  08 bf ff ec  bleu  0xa00a8390
a00a83e4:  b1 2f 60 03  sll  %i5, 3, %i0
a00a83e8:  da 0e a1 5b  ldub  [ %i2 + 0x15b ], %o5
a00a83ec:  b2 03 40 0d  add  %o5, %o5, %i1
a00a83f0:  80 a3 60 06  cmp  %o5, 6
a00a83f4:  08 80 00 04  bleu  0xa00a8404
a00a83f8:  82 06 60 06  add  %i1, 6, %g1
a00a83fc:  b4 03 40 0d  add  %o5, %o5, %i2
a00a8400:  82 06 bf f8  add  %i2, -8, %g1
a00a8404:  b4 08 60 ff  and  %g1, 0xff, %i2
a00a8408:  90 10 20 00  clr  %o0
a00a840c:  92 10 20 28  mov  0x28, %o1
a00a8410:  94 10 00 1a  mov  %i2, %o2
a00a8414:  96 10 20 01  mov  1, %o3
a00a8418:  98 10 20 0f  mov  0xf, %o4
a00a841c:  40 02 79 c1  call  0xa0146b20
a00a8420:  9a 10 20 00  clr  %o5
a00a8424:  b0 10 20 00  clr  %i0
a00a8428:  b2 10 20 29  mov  0x29, %i1
a00a842c:  b6 10 20 01  mov  1, %i3
a00a8430:  b8 10 20 10  mov  0x10, %i4
a00a8434:  40 02 79 bb  call  0xa0146b20
a00a8438:  9b e8 20 00  restore  %g0, 0, %o5
a00a843c:  01 00 00 00  nop
