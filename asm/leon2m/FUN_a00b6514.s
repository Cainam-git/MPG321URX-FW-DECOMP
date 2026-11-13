# leon2m FUN_a00b6514 0xa00b6514-0xa00b65e4 (208 bytes)
a00b6514:  9d e3 bf 80  save  %sp, -128, %sp
a00b6518:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00b651c:  d0 0b 60 33  ldub  [ %o5 + 0x33 ], %o0	! 0xa802d433
a00b6520:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b6524:  82 02 00 08  add  %o0, %o0, %g1
a00b6528:  b2 00 60 09  add  %g1, 9, %i1
a00b652c:  80 a6 20 01  cmp  %i0, 1
a00b6530:  02 80 00 29  be  0xa00b65d4
a00b6534:  b4 10 20 2a  mov  0x2a, %i2
a00b6538:  80 a6 20 02  cmp  %i0, 2
a00b653c:  02 80 00 28  be  0xa00b65dc
a00b6540:  80 a6 20 03  cmp  %i0, 3
a00b6544:  22 80 00 02  be,a   0xa00b654c
a00b6548:  b4 10 20 2e  mov  0x2e, %i2
a00b654c:  90 10 20 00  clr  %o0
a00b6550:  92 10 20 00  clr  %o1
a00b6554:  40 02 41 bb  call  0xa0146c40
a00b6558:  94 10 20 00  clr  %o2
a00b655c:  90 10 20 00  clr  %o0
a00b6560:  92 10 20 00  clr  %o1
a00b6564:  94 10 20 00  clr  %o2
a00b6568:  96 10 20 00  clr  %o3
a00b656c:  98 10 20 00  clr  %o4
a00b6570:  9a 10 20 0c  mov  0xc, %o5
a00b6574:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00b6578:  c0 23 a0 60  clr  [ %sp + 0x60 ]
a00b657c:  c0 23 a0 64  clr  [ %sp + 0x64 ]
a00b6580:  c0 23 a0 68  clr  [ %sp + 0x68 ]
a00b6584:  40 02 40 3e  call  0xa014667c
a00b6588:  c0 23 a0 6c  clr  [ %sp + 0x6c ]
a00b658c:  9e 0e 60 ff  and  %i1, 0xff, %o7
a00b6590:  82 0e a0 ff  and  %i2, 0xff, %g1
a00b6594:  99 2b e0 03  sll  %o7, 3, %o4
a00b6598:  96 03 00 0f  add  %o4, %o7, %o3
a00b659c:  b0 00 40 01  add  %g1, %g1, %i0
a00b65a0:  92 06 00 01  add  %i0, %g1, %o1
a00b65a4:  95 2a e0 02  sll  %o3, 2, %o2
a00b65a8:  93 2a 60 03  sll  %o1, 3, %o1
a00b65ac:  98 02 a0 51  add  %o2, 0x51, %o4
a00b65b0:  90 10 20 00  clr  %o0
a00b65b4:  94 02 a0 1a  add  %o2, 0x1a, %o2
a00b65b8:  96 02 60 17  add  %o1, 0x17, %o3
a00b65bc:  40 02 40 ad  call  0xa0146870
a00b65c0:  9a 10 20 00  clr  %o5
a00b65c4:  b0 10 20 00  clr  %i0
a00b65c8:  b2 10 20 01  mov  1, %i1
a00b65cc:  40 02 41 9d  call  0xa0146c40
a00b65d0:  95 e8 20 00  restore  %g0, 0, %o2
a00b65d4:  10 bf ff de  b  0xa00b654c
a00b65d8:  b4 10 20 2b  mov  0x2b, %i2
a00b65dc:  10 bf ff dc  b  0xa00b654c
a00b65e0:  b4 10 20 2d  mov  0x2d, %i2
