# leon2m FUN_a0148540 0xa0148540-0xa01485e0 (160 bytes)
a0148540:  9d e3 bf 98  save  %sp, -104, %sp
a0148544:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0148548:  80 a6 20 01  cmp  %i0, 1
a014854c:  02 80 00 0b  be  0xa0148578
a0148550:  82 10 20 01  mov  1, %g1
a0148554:  80 a6 20 01  cmp  %i0, 1
a0148558:  04 80 00 11  ble  0xa014859c
a014855c:  80 a6 20 02  cmp  %i0, 2
a0148560:  02 80 00 06  be  0xa0148578
a0148564:  82 10 20 02  mov  2, %g1
a0148568:  80 a6 20 03  cmp  %i0, 3
a014856c:  02 80 00 03  be  0xa0148578
a0148570:  82 10 20 03  mov  3, %g1
a0148574:  82 10 3f ff  mov  -1, %g1
a0148578:  9a 08 60 ff  and  %g1, 0xff, %o5
a014857c:  80 a3 60 03  cmp  %o5, 3
a0148580:  08 80 00 0d  bleu  0xa01485b4
a0148584:  9f 2b 60 04  sll  %o5, 4, %o7
a0148588:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a014858c:  7f fe 5a f9  call  0xa00df170
a0148590:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a0148594:  10 80 00 07  b  0xa01485b0
a0148598:  9a 10 20 00  clr  %o5
a014859c:  80 a6 20 00  cmp  %i0, 0
a01485a0:  02 bf ff f6  be  0xa0148578
a01485a4:  82 10 20 00  clr  %g1
a01485a8:  10 bf ff f4  b  0xa0148578
a01485ac:  82 10 3f ff  mov  -1, %g1
a01485b0:  9f 2b 60 04  sll  %o5, 4, %o7
a01485b4:  98 23 c0 0d  sub  %o7, %o5, %o4
a01485b8:  17 2a 00 b7  sethi  %hi(0xa802dc00), %o3
a01485bc:  95 2b 20 03  sll  %o4, 3, %o2
a01485c0:  9a 12 e3 30  or  %o3, 0x330, %o5
a01485c4:  d2 03 40 0a  ld  [ %o5 + %o2 ], %o1
a01485c8:  83 32 60 0c  srl  %o1, 0xc, %g1
a01485cc:  7f ff de b3  call  0xa0140098
a01485d0:  90 08 60 0f  and  %g1, 0xf, %o0
a01485d4:  b0 0a 20 ff  and  %o0, 0xff, %i0
a01485d8:  81 c7 e0 08  ret
a01485dc:  81 e8 00 00  restore
