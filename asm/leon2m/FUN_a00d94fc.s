# leon2m FUN_a00d94fc 0xa00d94fc-0xa00d972c (300 bytes)
a00d94fc:  9d e3 bf 98  save  %sp, -104, %sp
a00d9500:  40 01 ca 1c  call  0xa014bd70
a00d9504:  90 10 20 00  clr  %o0
a00d9508:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d950c:  80 a2 20 01  cmp  %o0, 1
a00d9510:  02 80 00 85  be  0xa00d9724
a00d9514:  01 00 00 00  nop
a00d9518:  40 01 a8 f1  call  0xa01438dc
a00d951c:  90 10 20 00  clr  %o0	! 0x0
a00d9520:  82 0a 20 ff  and  %o0, 0xff, %g1
a00d9524:  80 a0 60 01  cmp  %g1, 1
a00d9528:  02 80 00 10  be  0xa00d9568
a00d952c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00d9530:  9a 12 e2 90  or  %o3, 0x290, %o5	! 0xa802d290
a00d9534:  d2 03 61 1c  ld  [ %o5 + 0x11c ], %o1
a00d9538:  80 8a 60 10  btst  0x10, %o1
a00d953c:  02 80 00 7a  be  0xa00d9724
a00d9540:  01 00 00 00  nop
a00d9544:  c2 0b 60 11  ldub  [ %o5 + 0x11 ], %g1
a00d9548:  80 a0 60 07  cmp  %g1, 7
a00d954c:  18 80 00 15  bgu  0xa00d95a0
a00d9550:  1f 00 01 ce  sethi  %hi(0x73800), %o7
a00d9554:  95 28 60 02  sll  %g1, 2, %o2
a00d9558:  9a 13 e2 fc  or  %o7, 0x2fc, %o5
a00d955c:  d8 03 40 0a  ld  [ %o5 + %o2 ], %o4
a00d9560:  81 c3 00 00  jmp  %o4
a00d9564:  01 00 00 00  nop
a00d9568:  40 01 c9 40  call  0xa014ba68
a00d956c:  01 00 00 00  nop
a00d9570:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d9574:  80 a2 20 02  cmp  %o0, 2
a00d9578:  02 80 00 6b  be  0xa00d9724
a00d957c:  01 00 00 00  nop
a00d9580:  04 80 00 25  ble  0xa00d9614
a00d9584:  80 a2 20 01  cmp  %o0, 1
a00d9588:  80 a2 20 03  cmp  %o0, 3
a00d958c:  02 80 00 66  be  0xa00d9724
a00d9590:  80 a2 20 04  cmp  %o0, 4
a00d9594:  12 bf ff e7  bne  0xa00d9530
a00d9598:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00d959c:  30 80 00 62  b,a   0xa00d9724
a00d95a0:  40 01 b0 e0  call  0xa0145920
a00d95a4:  90 10 20 09  mov  9, %o0
a00d95a8:  b0 10 00 08  mov  %o0, %i0
a00d95ac:  40 01 b0 dd  call  0xa0145920
a00d95b0:  90 10 20 0a  mov  0xa, %o0
a00d95b4:  b2 10 00 08  mov  %o0, %i1
a00d95b8:  90 10 20 0b  mov  0xb, %o0
a00d95bc:  40 01 b0 d9  call  0xa0145920
a00d95c0:  01 00 00 00  nop
a00d95c4:  40 01 f4 9f  call  0xa0156840
a00d95c8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d95cc:  19 00 06 62  sethi  %hi(0x198800), %o4
a00d95d0:  40 01 f2 e2  call  0xa0156158
a00d95d4:  d4 1b 22 68  ldd  [ %o4 + 0x268 ], %o2	! 0x198a68
a00d95d8:  40 01 ee e2  call  0xa0155160
a00d95dc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d95e0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00d95e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d95e8:  b4 06 60 01  add  %i1, 1, %i2
a00d95ec:  9a 06 20 01  add  %i0, 1, %o5
a00d95f0:  96 02 20 01  add  %o0, 1, %o3
a00d95f4:  95 2e a0 10  sll  %i2, 0x10, %o2
a00d95f8:  9f 2b 60 10  sll  %o5, 0x10, %o7
a00d95fc:  83 2a e0 10  sll  %o3, 0x10, %g1
a00d9600:  b1 33 e0 10  srl  %o7, 0x10, %i0
a00d9604:  b3 32 a0 10  srl  %o2, 0x10, %i1
a00d9608:  b5 30 60 10  srl  %g1, 0x10, %i2
a00d960c:  40 01 b2 6d  call  0xa0145fc0
a00d9610:  81 e8 00 00  restore
a00d9614:  12 bf ff c7  bne  0xa00d9530
a00d9618:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00d961c:  30 80 00 42  b,a   0xa00d9724
a00d9620:  40 01 b0 c0  call  0xa0145920
a00d9624:  90 10 20 15  mov  0x15, %o0
a00d9628:  b0 10 00 08  mov  %o0, %i0
a00d962c:  40 01 b0 bd  call  0xa0145920
a00d9630:  90 10 20 16  mov  0x16, %o0
a00d9634:  b2 10 00 08  mov  %o0, %i1
a00d9638:  10 bf ff e1  b  0xa00d95bc
a00d963c:  90 10 20 17  mov  0x17, %o0
a00d9640:  40 01 b0 b8  call  0xa0145920
a00d9644:  90 10 20 0f  mov  0xf, %o0
a00d9648:  b0 10 00 08  mov  %o0, %i0
a00d964c:  40 01 b0 b5  call  0xa0145920
a00d9650:  90 10 20 10  mov  0x10, %o0
a00d9654:  b2 10 00 08  mov  %o0, %i1
a00d9658:  10 bf ff d9  b  0xa00d95bc
a00d965c:  90 10 20 11  mov  0x11, %o0
a00d9660:  40 01 b0 b0  call  0xa0145920
a00d9664:  90 10 20 0c  mov  0xc, %o0
a00d9668:  b0 10 00 08  mov  %o0, %i0
a00d966c:  40 01 b0 ad  call  0xa0145920
a00d9670:  90 10 20 0d  mov  0xd, %o0
a00d9674:  b2 10 00 08  mov  %o0, %i1
a00d9678:  10 bf ff d1  b  0xa00d95bc
a00d967c:  90 10 20 0e  mov  0xe, %o0
a00d9680:  98 12 e2 90  or  %o3, 0x290, %o4
a00d9684:  f0 0b 20 14  ldub  [ %o4 + 0x14 ], %i0
a00d9688:  d2 0b 20 12  ldub  [ %o4 + 0x12 ], %o1
a00d968c:  d0 0b 20 13  ldub  [ %o4 + 0x13 ], %o0
a00d9690:  96 5e 20 c8  smul  %i0, 0xc8, %o3
a00d9694:  9a 5a 60 c8  smul  %o1, 0xc8, %o5
a00d9698:  33 14 7a e1  sethi  %hi(0x51eb8400), %i1
a00d969c:  82 16 61 1f  or  %i1, 0x11f, %g1	! 0x51eb851f
a00d96a0:  b4 5a 20 c8  smul  %o0, 0xc8, %i2
a00d96a4:  9e 02 e0 32  add  %o3, 0x32, %o7
a00d96a8:  94 03 60 32  add  %o5, 0x32, %o2
a00d96ac:  98 06 a0 32  add  %i2, 0x32, %o4
a00d96b0:  80 53 c0 01  umul  %o7, %g1, %g0
a00d96b4:  b1 40 00 00  rd  %y, %i0
a00d96b8:  80 52 80 01  umul  %o2, %g1, %g0
a00d96bc:  93 40 00 00  rd  %y, %o1
a00d96c0:  80 53 00 01  umul  %o4, %g1, %g0
a00d96c4:  91 40 00 00  rd  %y, %o0
a00d96c8:  b3 32 60 05  srl  %o1, 5, %i1
a00d96cc:  97 36 20 05  srl  %i0, 5, %o3
a00d96d0:  b5 32 20 05  srl  %o0, 5, %i2
a00d96d4:  b0 06 60 37  add  %i1, 0x37, %i0
a00d96d8:  b2 06 a0 37  add  %i2, 0x37, %i1
a00d96dc:  10 bf ff ba  b  0xa00d95c4
a00d96e0:  90 02 e0 37  add  %o3, 0x37, %o0
a00d96e4:  40 01 b0 8f  call  0xa0145920
a00d96e8:  90 10 20 06  mov  6, %o0
a00d96ec:  b0 10 00 08  mov  %o0, %i0
a00d96f0:  40 01 b0 8c  call  0xa0145920
a00d96f4:  90 10 20 07  mov  7, %o0
a00d96f8:  b2 10 00 08  mov  %o0, %i1
a00d96fc:  10 bf ff b0  b  0xa00d95bc
a00d9700:  90 10 20 08  mov  8, %o0
a00d9704:  40 01 b0 87  call  0xa0145920
a00d9708:  90 10 20 12  mov  0x12, %o0
a00d970c:  b0 10 00 08  mov  %o0, %i0
a00d9710:  40 01 b0 84  call  0xa0145920
a00d9714:  90 10 20 13  mov  0x13, %o0
a00d9718:  b2 10 00 08  mov  %o0, %i1
a00d971c:  10 bf ff a8  b  0xa00d95bc
a00d9720:  90 10 20 14  mov  0x14, %o0
a00d9724:  81 c7 e0 08  ret
a00d9728:  81 e8 00 00  restore
