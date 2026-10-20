# leon2m FUN_a00ab3d8 0xa00ab3d8-0xa00ab4bc (228 bytes)
a00ab3d8:  9d e3 bf 98  save  %sp, -104, %sp
a00ab3dc:  90 10 21 11  mov  0x111, %o0
a00ab3e0:  40 02 6d dc  call  0xa0146b50
a00ab3e4:  92 10 20 00  clr  %o1
a00ab3e8:  90 10 20 00  clr  %o0
a00ab3ec:  40 02 6d e0  call  0xa0146b6c
a00ab3f0:  92 10 20 00  clr  %o1
a00ab3f4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ab3f8:  b4 10 62 90  or  %g1, 0x290, %i2	! 0xa802d290
a00ab3fc:  b8 10 20 00  clr  %i4
a00ab400:  ba 10 20 00  clr  %i5
a00ab404:  37 00 06 38  sethi  %hi(0x18e000), %i3
a00ab408:  b1 2f 60 03  sll  %i5, 3, %i0
a00ab40c:  9e 26 00 1d  sub  %i0, %i5, %o7
a00ab410:  9b 2b e0 02  sll  %o7, 2, %o5
a00ab414:  96 03 40 1d  add  %o5, %i5, %o3
a00ab418:  d8 0e a0 08  ldub  [ %i2 + 8 ], %o4
a00ab41c:  90 02 c0 0c  add  %o3, %o4, %o0
a00ab420:  93 2a 20 10  sll  %o0, 0x10, %o1
a00ab424:  93 32 60 10  srl  %o1, 0x10, %o1
a00ab428:  7f ff e1 07  call  0xa00a3844
a00ab42c:  90 16 e0 8c  or  %i3, 0x8c, %o0
a00ab430:  98 10 00 08  mov  %o0, %o4
a00ab434:  94 07 40 1d  add  %i5, %i5, %o2
a00ab438:  94 02 a0 06  add  %o2, 6, %o2
a00ab43c:  90 10 20 00  clr  %o0
a00ab440:  92 10 20 2a  mov  0x2a, %o1
a00ab444:  96 10 20 01  mov  1, %o3
a00ab448:  9a 10 20 00  clr  %o5
a00ab44c:  7f ff df 56  call  0xa00a31a4
a00ab450:  b8 07 20 01  inc  %i4
a00ab454:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00ab458:  80 a7 60 02  cmp  %i5, 2
a00ab45c:  08 bf ff ec  bleu  0xa00ab40c
a00ab460:  b1 2f 60 03  sll  %i5, 3, %i0
a00ab464:  da 0e a0 19  ldub  [ %i2 + 0x19 ], %o5
a00ab468:  b2 03 40 0d  add  %o5, %o5, %i1
a00ab46c:  80 a3 60 06  cmp  %o5, 6
a00ab470:  08 80 00 04  bleu  0xa00ab480
a00ab474:  82 06 60 06  add  %i1, 6, %g1
a00ab478:  b4 03 40 0d  add  %o5, %o5, %i2
a00ab47c:  82 06 bf f8  add  %i2, -8, %g1
a00ab480:  b4 08 60 ff  and  %g1, 0xff, %i2
a00ab484:  90 10 20 00  clr  %o0
a00ab488:  92 10 20 28  mov  0x28, %o1
a00ab48c:  94 10 00 1a  mov  %i2, %o2
a00ab490:  96 10 20 01  mov  1, %o3
a00ab494:  98 10 20 0f  mov  0xf, %o4
a00ab498:  40 02 6d a2  call  0xa0146b20
a00ab49c:  9a 10 20 00  clr  %o5
a00ab4a0:  b0 10 20 00  clr  %i0
a00ab4a4:  b2 10 20 29  mov  0x29, %i1
a00ab4a8:  b6 10 20 01  mov  1, %i3
a00ab4ac:  b8 10 20 10  mov  0x10, %i4
a00ab4b0:  40 02 6d 9c  call  0xa0146b20
a00ab4b4:  9b e8 20 00  restore  %g0, 0, %o5
a00ab4b8:  01 00 00 00  nop
