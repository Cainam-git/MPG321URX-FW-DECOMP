# leon2m FUN_a00b7530 0xa00b7530-0xa00b7674 (324 bytes)
a00b7530:  9d e3 bf 90  save  %sp, -112, %sp
a00b7534:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00b7538:  92 14 62 90  or  %l1, 0x290, %o1	! 0xa802d290
a00b753c:  da 0a 60 0f  ldub  [ %o1 + 0xf ], %o5
a00b7540:  91 2b 60 02  sll  %o5, 2, %o0
a00b7544:  82 02 00 0d  add  %o0, %o5, %g1
a00b7548:  95 28 60 02  sll  %g1, 2, %o2
a00b754c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b7550:  90 10 20 2c  mov  0x2c, %o0
a00b7554:  92 10 20 06  mov  6, %o1
a00b7558:  94 0a a0 fc  and  %o2, 0xfc, %o2
a00b755c:  96 10 20 06  mov  6, %o3
a00b7560:  7f ff d0 24  call  0xa00ab5f0
a00b7564:  98 10 00 18  mov  %i0, %o4
a00b7568:  a0 10 27 42  mov  0x742, %l0
a00b756c:  90 10 20 01  mov  1, %o0
a00b7570:  80 a6 20 00  cmp  %i0, 0
a00b7574:  12 80 00 05  bne  0xa00b7588
a00b7578:  92 10 20 03  mov  3, %o1
a00b757c:  a0 10 27 92  mov  0x792, %l0
a00b7580:  90 10 20 01  mov  1, %o0
a00b7584:  92 10 20 02  mov  2, %o1
a00b7588:  7f ff c7 b8  call  0xa00a9468
a00b758c:  b0 0c 27 d2  and  %l0, 0x7d2, %i0
a00b7590:  90 10 20 28  mov  0x28, %o0
a00b7594:  92 10 20 06  mov  6, %o1
a00b7598:  94 10 20 03  mov  3, %o2
a00b759c:  96 10 00 18  mov  %i0, %o3
a00b75a0:  40 02 3d 38  call  0xa0146a80
a00b75a4:  98 10 20 00  clr  %o4
a00b75a8:  90 10 20 2b  mov  0x2b, %o0
a00b75ac:  92 10 20 06  mov  6, %o1
a00b75b0:  94 10 20 01  mov  1, %o2
a00b75b4:  96 10 00 18  mov  %i0, %o3
a00b75b8:  40 02 3d 32  call  0xa0146a80
a00b75bc:  98 10 20 00  clr  %o4
a00b75c0:  9a 10 20 00  clr  %o5
a00b75c4:  90 10 20 00  clr  %o0
a00b75c8:  92 10 20 2b  mov  0x2b, %o1
a00b75cc:  94 10 20 06  mov  6, %o2
a00b75d0:  96 10 20 01  mov  1, %o3
a00b75d4:  40 02 3d 53  call  0xa0146b20
a00b75d8:  98 10 20 3f  mov  0x3f, %o4
a00b75dc:  96 10 00 18  mov  %i0, %o3
a00b75e0:  90 10 20 32  mov  0x32, %o0
a00b75e4:  92 10 20 06  mov  6, %o1
a00b75e8:  94 10 20 01  mov  1, %o2
a00b75ec:  40 02 3d 25  call  0xa0146a80
a00b75f0:  98 10 20 00  clr  %o4
a00b75f4:  9a 10 20 00  clr  %o5
a00b75f8:  96 10 20 01  mov  1, %o3
a00b75fc:  98 10 20 40  mov  0x40, %o4
a00b7600:  94 10 20 06  mov  6, %o2
a00b7604:  90 10 20 00  clr  %o0
a00b7608:  40 02 3d 46  call  0xa0146b20
a00b760c:  92 10 20 32  mov  0x32, %o1
a00b7610:  90 10 20 e6  mov  0xe6, %o0
a00b7614:  40 02 3d 4f  call  0xa0146b50
a00b7618:  92 10 20 00  clr  %o1
a00b761c:  19 00 06 60  sethi  %hi(0x198000), %o4
a00b7620:  9e 14 62 90  or  %l1, 0x290, %o7
a00b7624:  a0 07 bf f0  add  %fp, -16, %l0
a00b7628:  92 13 21 d0  or  %o4, 0x1d0, %o1
a00b762c:  d4 0b e0 0f  ldub  [ %o7 + 0xf ], %o2
a00b7630:  40 02 80 71  call  0xa01577f4
a00b7634:  90 10 00 10  mov  %l0, %o0
a00b7638:  96 10 20 03  mov  3, %o3
a00b763c:  d6 2f bf f0  stb  %o3, [ %fp + -16 ]
a00b7640:  90 10 20 02  mov  2, %o0
a00b7644:  40 02 3d 4a  call  0xa0146b6c
a00b7648:  92 10 20 00  clr  %o1
a00b764c:  98 10 00 10  mov  %l0, %o4
a00b7650:  90 10 20 00  clr  %o0
a00b7654:  92 10 20 28  mov  0x28, %o1
a00b7658:  94 10 20 06  mov  6, %o2
a00b765c:  96 10 20 02  mov  2, %o3
a00b7660:  7f ff ae d1  call  0xa00a31a4
a00b7664:  9a 10 20 00  clr  %o5
a00b7668:  01 00 00 00  nop
a00b766c:  81 c7 e0 08  ret
a00b7670:  81 e8 00 00  restore
