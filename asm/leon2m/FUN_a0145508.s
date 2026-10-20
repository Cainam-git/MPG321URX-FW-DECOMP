# leon2m FUN_a0145508 0xa0145508-0xa0145644 (316 bytes)
a0145508:  9d e3 bf 98  save  %sp, -104, %sp
a014550c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0145510:  80 a6 20 00  cmp  %i0, 0
a0145514:  02 80 00 06  be  0xa014552c
a0145518:  80 a6 20 01  cmp  %i0, 1
a014551c:  12 80 00 48  bne  0xa014563c
a0145520:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0145524:  10 80 00 04  b  0xa0145534
a0145528:  1b 2a 00 b7  sethi  %hi(0xa802dc00), %o5
a014552c:  40 00 3b e8  call  0xa01544cc
a0145530:  81 e8 00 00  restore
a0145534:  a4 10 62 24  or  %g1, 0x224, %l2
a0145538:  a2 13 63 30  or  %o5, 0x330, %l1
a014553c:  a0 10 20 00  clr  %l0
a0145540:  10 80 00 07  b  0xa014555c
a0145544:  b0 10 20 00  clr  %i0
a0145548:  a0 04 20 01  inc  %l0
a014554c:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0145550:  80 a6 20 03  cmp  %i0, 3
a0145554:  18 80 00 3a  bgu  0xa014563c
a0145558:  01 00 00 00  nop
a014555c:  7f ff de 44  call  0xa013ce6c
a0145560:  90 10 00 18  mov  %i0, %o0
a0145564:  90 0a 20 ff  and  %o0, 0xff, %o0
a0145568:  80 a2 20 0c  cmp  %o0, 0xc
a014556c:  32 bf ff f8  bne,a   0xa014554c
a0145570:  a0 04 20 01  inc  %l0
a0145574:  80 a6 20 01  cmp  %i0, 1
a0145578:  02 80 00 0b  be  0xa01455a4
a014557c:  82 10 20 01  mov  1, %g1
a0145580:  80 a6 20 01  cmp  %i0, 1
a0145584:  04 80 00 29  ble  0xa0145628
a0145588:  80 a6 20 02  cmp  %i0, 2
a014558c:  02 80 00 06  be  0xa01455a4
a0145590:  82 10 20 02  mov  2, %g1
a0145594:  80 a6 20 03  cmp  %i0, 3
a0145598:  02 80 00 03  be  0xa01455a4
a014559c:  82 10 20 03  mov  3, %g1
a01455a0:  82 10 3f ff  mov  -1, %g1
a01455a4:  9a 08 60 ff  and  %g1, 0xff, %o5
a01455a8:  80 a3 60 03  cmp  %o5, 3
a01455ac:  18 80 00 1b  bgu  0xa0145618
a01455b0:  13 00 06 9b  sethi  %hi(0x1a6c00), %o1
a01455b4:  95 2b 60 04  sll  %o5, 4, %o2
a01455b8:  92 22 80 0d  sub  %o2, %o5, %o1
a01455bc:  83 2a 60 03  sll  %o1, 3, %g1
a01455c0:  d0 04 40 01  ld  [ %l1 + %g1 ], %o0
a01455c4:  9b 32 20 0c  srl  %o0, 0xc, %o5
a01455c8:  9e 0b 60 0f  and  %o5, 0xf, %o7
a01455cc:  98 5b e0 2a  smul  %o7, 0x2a, %o4
a01455d0:  96 03 00 12  add  %o4, %l2, %o3
a01455d4:  d4 0a e0 09  ldub  [ %o3 + 9 ], %o2
a01455d8:  80 a2 a0 05  cmp  %o2, 5
a01455dc:  22 bf ff dc  be,a   0xa014554c
a01455e0:  a0 04 20 01  inc  %l0
a01455e4:  93 2e 20 04  sll  %i0, 4, %o1
a01455e8:  82 22 40 18  sub  %o1, %i0, %g1
a01455ec:  91 28 60 03  sll  %g1, 3, %o0
a01455f0:  b0 02 00 11  add  %o0, %l1, %i0
a01455f4:  d8 16 20 28  lduh  [ %i0 + 0x28 ], %o4
a01455f8:  d6 16 20 2a  lduh  [ %i0 + 0x2a ], %o3
a01455fc:  de 16 20 2c  lduh  [ %i0 + 0x2c ], %o7
a0145600:  9a 10 20 20  mov  0x20, %o5
a0145604:  da 2e 20 26  stb  %o5, [ %i0 + 0x26 ]
a0145608:  d8 36 20 0e  sth  %o4, [ %i0 + 0xe ]
a014560c:  d6 36 20 1e  sth  %o3, [ %i0 + 0x1e ]
a0145610:  10 bf ff ce  b  0xa0145548
a0145614:  de 36 20 20  sth  %o7, [ %i0 + 0x20 ]
a0145618:  7f fe 66 d6  call  0xa00df170
a014561c:  90 12 61 d8  or  %o1, 0x1d8, %o0
a0145620:  10 bf ff e5  b  0xa01455b4
a0145624:  9a 10 20 00  clr  %o5
a0145628:  80 a6 20 00  cmp  %i0, 0
a014562c:  02 bf ff de  be  0xa01455a4
a0145630:  82 10 20 00  clr  %g1
a0145634:  10 bf ff dc  b  0xa01455a4
a0145638:  82 10 3f ff  mov  -1, %g1
a014563c:  81 c7 e0 08  ret
a0145640:  81 e8 00 00  restore
