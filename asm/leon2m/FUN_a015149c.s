# leon2m FUN_a015149c 0xa015149c-0xa0151674 (472 bytes)
a015149c:  9d e3 bf 98  save  %sp, -104, %sp
a01514a0:  7f ff 4b 57  call  0xa01241fc
a01514a4:  01 00 00 00  nop
a01514a8:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a01514ac:  a0 12 e3 d0  or  %o3, 0x3d0, %l0	! 0xa802e3d0
a01514b0:  d4 0c 20 04  ldub  [ %l0 + 4 ], %o2
a01514b4:  92 0a a0 0f  and  %o2, 0xf, %o1
a01514b8:  7f ff c3 d8  call  0xa0142418
a01514bc:  90 10 20 00  clr  %o0
a01514c0:  d0 04 20 04  ld  [ %l0 + 4 ], %o0
a01514c4:  93 32 20 14  srl  %o0, 0x14, %o1
a01514c8:  92 0a 60 0f  and  %o1, 0xf, %o1
a01514cc:  7f ff c3 d3  call  0xa0142418
a01514d0:  90 10 20 01  mov  1, %o0
a01514d4:  c2 04 20 04  ld  [ %l0 + 4 ], %g1
a01514d8:  83 30 60 1c  srl  %g1, 0x1c, %g1
a01514dc:  80 a0 60 02  cmp  %g1, 2
a01514e0:  22 80 00 37  be,a   0xa01515bc
a01514e4:  90 10 20 00  clr  %o0
a01514e8:  04 80 00 1f  ble  0xa0151564
a01514ec:  80 a0 60 01  cmp  %g1, 1
a01514f0:  80 a0 60 03  cmp  %g1, 3
a01514f4:  02 80 00 4c  be  0xa0151624
a01514f8:  90 10 20 00  clr  %o0
a01514fc:  7f fe e1 75  call  0xa0109ad0
a0151500:  92 10 20 00  clr  %o1
a0151504:  90 10 20 00  clr  %o0
a0151508:  7f fe e1 83  call  0xa0109b14
a015150c:  92 10 20 00  clr  %o1
a0151510:  90 10 20 01  mov  1, %o0
a0151514:  7f fe e1 6f  call  0xa0109ad0
a0151518:  92 10 20 00  clr  %o1
a015151c:  90 10 20 01  mov  1, %o0
a0151520:  7f fe e1 7d  call  0xa0109b14
a0151524:  92 10 20 00  clr  %o1
a0151528:  90 10 20 02  mov  2, %o0
a015152c:  7f fe e1 69  call  0xa0109ad0
a0151530:  92 10 20 00  clr  %o1
a0151534:  90 10 20 02  mov  2, %o0
a0151538:  7f fe e1 77  call  0xa0109b14
a015153c:  92 10 20 00  clr  %o1
a0151540:  90 10 20 03  mov  3, %o0
a0151544:  92 10 20 00  clr  %o1
a0151548:  7f fe e1 62  call  0xa0109ad0
a015154c:  01 00 00 00  nop
a0151550:  90 10 20 03  mov  3, %o0	! 0x3
a0151554:  7f fe e1 70  call  0xa0109b14
a0151558:  92 10 20 00  clr  %o1
a015155c:  7f ff f4 9d  call  0xa014e7d0
a0151560:  81 e8 00 00  restore
a0151564:  12 bf ff e6  bne  0xa01514fc
a0151568:  90 10 20 00  clr  %o0
a015156c:  7f fe e1 59  call  0xa0109ad0
a0151570:  92 10 20 01  mov  1, %o1
a0151574:  90 10 20 00  clr  %o0
a0151578:  7f fe e1 67  call  0xa0109b14
a015157c:  92 10 20 00  clr  %o1
a0151580:  90 10 20 01  mov  1, %o0
a0151584:  7f fe e1 53  call  0xa0109ad0
a0151588:  92 10 20 01  mov  1, %o1
a015158c:  90 10 20 01  mov  1, %o0
a0151590:  7f fe e1 61  call  0xa0109b14
a0151594:  92 10 20 00  clr  %o1
a0151598:  90 10 20 02  mov  2, %o0
a015159c:  7f fe e1 4d  call  0xa0109ad0
a01515a0:  92 10 20 01  mov  1, %o1
a01515a4:  90 10 20 02  mov  2, %o0
a01515a8:  7f fe e1 5b  call  0xa0109b14
a01515ac:  92 10 20 00  clr  %o1
a01515b0:  90 10 20 03  mov  3, %o0
a01515b4:  10 bf ff e5  b  0xa0151548
a01515b8:  92 10 20 01  mov  1, %o1
a01515bc:  7f fe e1 45  call  0xa0109ad0
a01515c0:  92 10 20 00  clr  %o1
a01515c4:  90 10 20 00  clr  %o0
a01515c8:  7f fe e1 53  call  0xa0109b14
a01515cc:  92 10 20 01  mov  1, %o1
a01515d0:  90 10 20 01  mov  1, %o0
a01515d4:  7f fe e1 3f  call  0xa0109ad0
a01515d8:  92 10 20 00  clr  %o1
a01515dc:  90 10 20 01  mov  1, %o0
a01515e0:  7f fe e1 4d  call  0xa0109b14
a01515e4:  92 10 20 01  mov  1, %o1
a01515e8:  90 10 20 02  mov  2, %o0
a01515ec:  7f fe e1 39  call  0xa0109ad0
a01515f0:  92 10 20 00  clr  %o1
a01515f4:  90 10 20 02  mov  2, %o0
a01515f8:  7f fe e1 47  call  0xa0109b14
a01515fc:  92 10 20 01  mov  1, %o1
a0151600:  90 10 20 03  mov  3, %o0
a0151604:  92 10 20 00  clr  %o1
a0151608:  7f fe e1 32  call  0xa0109ad0
a015160c:  01 00 00 00  nop
a0151610:  90 10 20 03  mov  3, %o0	! 0x3
a0151614:  7f fe e1 40  call  0xa0109b14
a0151618:  92 10 20 01  mov  1, %o1
a015161c:  7f ff f4 6d  call  0xa014e7d0
a0151620:  81 e8 00 00  restore
a0151624:  7f fe e1 2b  call  0xa0109ad0
a0151628:  92 10 20 01  mov  1, %o1
a015162c:  90 10 20 00  clr  %o0
a0151630:  7f fe e1 39  call  0xa0109b14
a0151634:  92 10 20 01  mov  1, %o1
a0151638:  90 10 20 01  mov  1, %o0
a015163c:  7f fe e1 25  call  0xa0109ad0
a0151640:  92 10 20 01  mov  1, %o1
a0151644:  90 10 20 01  mov  1, %o0
a0151648:  7f fe e1 33  call  0xa0109b14
a015164c:  92 10 20 01  mov  1, %o1
a0151650:  90 10 20 02  mov  2, %o0
a0151654:  7f fe e1 1f  call  0xa0109ad0
a0151658:  92 10 20 01  mov  1, %o1
a015165c:  90 10 20 02  mov  2, %o0
a0151660:  7f fe e1 2d  call  0xa0109b14
a0151664:  92 10 20 01  mov  1, %o1
a0151668:  90 10 20 03  mov  3, %o0
a015166c:  10 bf ff e7  b  0xa0151608
a0151670:  92 10 20 01  mov  1, %o1
