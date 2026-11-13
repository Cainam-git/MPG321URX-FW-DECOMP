# leon2m FUN_a01474b0 0xa01474b0-0xa0147560 (176 bytes)
a01474b0:  9d e3 bf 98  save  %sp, -104, %sp
a01474b4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01474b8:  80 a6 20 01  cmp  %i0, 1
a01474bc:  02 80 00 0b  be  0xa01474e8
a01474c0:  82 10 20 01  mov  1, %g1
a01474c4:  80 a6 20 01  cmp  %i0, 1
a01474c8:  04 80 00 1f  ble  0xa0147544
a01474cc:  80 a6 20 02  cmp  %i0, 2
a01474d0:  02 80 00 06  be  0xa01474e8
a01474d4:  82 10 20 02  mov  2, %g1
a01474d8:  80 a6 20 03  cmp  %i0, 3
a01474dc:  02 80 00 03  be  0xa01474e8
a01474e0:  82 10 20 03  mov  3, %g1
a01474e4:  82 10 3f ff  mov  -1, %g1
a01474e8:  9a 08 60 ff  and  %g1, 0xff, %o5
a01474ec:  80 a3 60 03  cmp  %o5, 3
a01474f0:  18 80 00 11  bgu  0xa0147534
a01474f4:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a01474f8:  9f 2b 60 04  sll  %o5, 4, %o7
a01474fc:  96 23 c0 0d  sub  %o7, %o5, %o3
a0147500:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0147504:  83 2a e0 03  sll  %o3, 3, %g1
a0147508:  9a 12 a3 30  or  %o2, 0x330, %o5
a014750c:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a0147510:  99 32 60 04  srl  %o1, 4, %o4
a0147514:  90 0b 20 0f  and  %o4, 0xf, %o0
a0147518:  80 a2 20 04  cmp  %o0, 4
a014751c:  02 80 00 0f  be  0xa0147558
a0147520:  01 00 00 00  nop
a0147524:  7f fe bb a6  call  0xa00f63bc
a0147528:  b0 10 00 19  mov  %i1, %i0
a014752c:  7f fe bf c2  call  0xa00f7434
a0147530:  81 e8 00 00  restore
a0147534:  7f fe 5f 0f  call  0xa00df170
a0147538:  90 12 21 d8  or  %o0, 0x1d8, %o0
a014753c:  10 bf ff ef  b  0xa01474f8
a0147540:  9a 10 20 00  clr  %o5
a0147544:  80 a6 20 00  cmp  %i0, 0
a0147548:  02 bf ff e8  be  0xa01474e8
a014754c:  82 10 20 00  clr  %g1
a0147550:  10 bf ff e6  b  0xa01474e8
a0147554:  82 10 3f ff  mov  -1, %g1
a0147558:  81 c7 e0 08  ret
a014755c:  81 e8 00 00  restore
