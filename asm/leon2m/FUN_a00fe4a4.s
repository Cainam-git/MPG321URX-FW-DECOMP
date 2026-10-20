# leon2m FUN_a00fe4a4 0xa00fe4a4-0xa00fe6c8 (548 bytes)
a00fe4a4:  9d e3 bf 98  save  %sp, -104, %sp
a00fe4a8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00fe4ac:  80 a6 60 61  cmp  %i1, 0x61
a00fe4b0:  02 80 00 35  be  0xa00fe584
a00fe4b4:  96 10 00 18  mov  %i0, %o3
a00fe4b8:  80 a6 60 61  cmp  %i1, 0x61
a00fe4bc:  04 80 00 13  ble  0xa00fe508
a00fe4c0:  80 a6 60 51  cmp  %i1, 0x51
a00fe4c4:  80 a6 60 71  cmp  %i1, 0x71
a00fe4c8:  02 80 00 42  be  0xa00fe5d0
a00fe4cc:  80 a6 60 81  cmp  %i1, 0x81
a00fe4d0:  02 80 00 64  be  0xa00fe660
a00fe4d4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00fe4d8:  90 10 00 18  mov  %i0, %o0
a00fe4dc:  92 10 20 5c  mov  0x5c, %o1
a00fe4e0:  94 10 20 01  mov  1, %o2
a00fe4e4:  7f ff cd 9e  call  0xa00f1b5c
a00fe4e8:  96 10 20 00  clr  %o3
a00fe4ec:  90 10 00 18  mov  %i0, %o0
a00fe4f0:  7f ff ce 47  call  0xa00f1e0c
a00fe4f4:  92 10 20 40  mov  0x40, %o1
a00fe4f8:  98 12 20 01  or  %o0, 1, %o4
a00fe4fc:  b4 0b 20 fd  and  %o4, 0xfd, %i2
a00fe500:  7f ff ce 54  call  0xa00f1e50
a00fe504:  93 e8 20 40  restore  %g0, 0x40, %o1
a00fe508:  12 bf ff f4  bne  0xa00fe4d8
a00fe50c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00fe510:  35 33 c0 b7  sethi  %hi(0xcf02dc00), %i2
a00fe514:  9e 16 a0 04  or  %i2, 4, %o7	! 0xcf02dc04
a00fe518:  f2 03 c0 00  ld  [ %o7 ], %i1
a00fe51c:  b0 0e 7f ec  and  %i1, -20, %i0
a00fe520:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00fe524:  f0 23 c0 00  st  %i0, [ %o7 ]
a00fe528:  98 13 63 50  or  %o5, 0x350, %o4
a00fe52c:  d4 03 00 00  ld  [ %o4 ], %o2
a00fe530:  92 0a bf f8  and  %o2, -8, %o1
a00fe534:  90 12 60 02  or  %o1, 2, %o0
a00fe538:  82 0a 20 ff  and  %o0, 0xff, %g1
a00fe53c:  b0 0a e0 ff  and  %o3, 0xff, %i0
a00fe540:  c2 23 00 00  st  %g1, [ %o4 ]
a00fe544:  90 10 00 18  mov  %i0, %o0
a00fe548:  92 10 20 04  mov  4, %o1
a00fe54c:  7f ff cd 62  call  0xa00f1ad4
a00fe550:  94 10 20 8a  mov  0x8a, %o2
a00fe554:  90 10 00 18  mov  %i0, %o0
a00fe558:  92 10 20 5c  mov  0x5c, %o1
a00fe55c:  94 10 20 01  mov  1, %o2
a00fe560:  7f ff cd 7f  call  0xa00f1b5c
a00fe564:  96 10 20 00  clr  %o3
a00fe568:  90 10 00 18  mov  %i0, %o0
a00fe56c:  7f ff ce 28  call  0xa00f1e0c
a00fe570:  92 10 20 40  mov  0x40, %o1
a00fe574:  98 12 20 01  or  %o0, 1, %o4
a00fe578:  b4 0b 20 fd  and  %o4, 0xfd, %i2
a00fe57c:  7f ff ce 35  call  0xa00f1e50
a00fe580:  93 e8 20 40  restore  %g0, 0x40, %o1
a00fe584:  35 33 c0 b7  sethi  %hi(0xcf02dc00), %i2
a00fe588:  9e 16 a0 04  or  %i2, 4, %o7	! 0xcf02dc04
a00fe58c:  f2 03 c0 00  ld  [ %o7 ], %i1
a00fe590:  b0 0e 7f ec  and  %i1, -20, %i0
a00fe594:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00fe598:  f0 23 c0 00  st  %i0, [ %o7 ]
a00fe59c:  98 13 63 50  or  %o5, 0x350, %o4
a00fe5a0:  d4 03 00 00  ld  [ %o4 ], %o2
a00fe5a4:  92 0a bf f8  and  %o2, -8, %o1
a00fe5a8:  90 12 60 05  or  %o1, 5, %o0
a00fe5ac:  82 0a 20 ff  and  %o0, 0xff, %g1
a00fe5b0:  b0 0a e0 ff  and  %o3, 0xff, %i0
a00fe5b4:  c2 23 00 00  st  %g1, [ %o4 ]
a00fe5b8:  90 10 00 18  mov  %i0, %o0
a00fe5bc:  92 10 20 04  mov  4, %o1
a00fe5c0:  7f ff cd 45  call  0xa00f1ad4
a00fe5c4:  94 10 20 8e  mov  0x8e, %o2
a00fe5c8:  10 bf ff e4  b  0xa00fe558
a00fe5cc:  90 10 00 18  mov  %i0, %o0
a00fe5d0:  1f 33 c0 b7  sethi  %hi(0xcf02dc00), %o7
a00fe5d4:  b0 13 e0 04  or  %o7, 4, %i0	! 0xcf02dc04
a00fe5d8:  f4 06 00 00  ld  [ %i0 ], %i2
a00fe5dc:  b2 16 a0 13  or  %i2, 0x13, %i1
a00fe5e0:  f2 26 00 00  st  %i1, [ %i0 ]
a00fe5e4:  92 13 e0 18  or  %o7, 0x18, %o1
a00fe5e8:  da 02 40 00  ld  [ %o1 ], %o5
a00fe5ec:  94 13 60 01  or  %o5, 1, %o2
a00fe5f0:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00fe5f4:  d4 22 40 00  st  %o2, [ %o1 ]
a00fe5f8:  98 12 22 74  or  %o0, 0x274, %o4
a00fe5fc:  c2 03 00 00  ld  [ %o4 ], %g1
a00fe600:  b0 0a e0 ff  and  %o3, 0xff, %i0
a00fe604:  96 08 7f fe  and  %g1, -2, %o3
a00fe608:  d6 23 00 00  st  %o3, [ %o4 ]
a00fe60c:  90 10 00 18  mov  %i0, %o0
a00fe610:  92 10 20 04  mov  4, %o1
a00fe614:  7f ff cd 30  call  0xa00f1ad4
a00fe618:  94 10 20 83  mov  0x83, %o2
a00fe61c:  90 10 00 18  mov  %i0, %o0
a00fe620:  92 10 20 03  mov  3, %o1
a00fe624:  94 10 20 01  mov  1, %o2
a00fe628:  7f ff cd 4d  call  0xa00f1b5c
a00fe62c:  96 10 20 00  clr  %o3
a00fe630:  90 10 00 18  mov  %i0, %o0
a00fe634:  92 10 20 5c  mov  0x5c, %o1
a00fe638:  94 10 20 01  mov  1, %o2
a00fe63c:  7f ff cd 48  call  0xa00f1b5c
a00fe640:  96 10 20 00  clr  %o3
a00fe644:  90 10 00 18  mov  %i0, %o0
a00fe648:  7f ff cd f1  call  0xa00f1e0c
a00fe64c:  92 10 20 40  mov  0x40, %o1
a00fe650:  98 12 20 01  or  %o0, 1, %o4
a00fe654:  b4 0b 20 fd  and  %o4, 0xfd, %i2
a00fe658:  7f ff cd fe  call  0xa00f1e50
a00fe65c:  93 e8 20 40  restore  %g0, 0x40, %o1
a00fe660:  1f 33 c0 b7  sethi  %hi(0xcf02dc00), %o7
a00fe664:  b0 13 e0 04  or  %o7, 4, %i0	! 0xcf02dc04
a00fe668:  f4 06 00 00  ld  [ %i0 ], %i2
a00fe66c:  b2 16 a0 13  or  %i2, 0x13, %i1
a00fe670:  f2 26 00 00  st  %i1, [ %i0 ]
a00fe674:  92 13 e0 18  or  %o7, 0x18, %o1
a00fe678:  da 02 40 00  ld  [ %o1 ], %o5
a00fe67c:  94 13 60 01  or  %o5, 1, %o2
a00fe680:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00fe684:  d4 22 40 00  st  %o2, [ %o1 ]
a00fe688:  98 12 22 74  or  %o0, 0x274, %o4
a00fe68c:  c2 03 00 00  ld  [ %o4 ], %g1
a00fe690:  b0 0a e0 ff  and  %o3, 0xff, %i0
a00fe694:  96 10 60 01  or  %g1, 1, %o3
a00fe698:  d6 23 00 00  st  %o3, [ %o4 ]
a00fe69c:  90 10 00 18  mov  %i0, %o0
a00fe6a0:  92 10 20 04  mov  4, %o1
a00fe6a4:  7f ff cd 0c  call  0xa00f1ad4
a00fe6a8:  94 10 20 83  mov  0x83, %o2
a00fe6ac:  90 10 00 18  mov  %i0, %o0
a00fe6b0:  92 10 20 03  mov  3, %o1
a00fe6b4:  94 10 20 01  mov  1, %o2
a00fe6b8:  7f ff cd 29  call  0xa00f1b5c
a00fe6bc:  96 10 20 01  mov  1, %o3
a00fe6c0:  10 bf ff dd  b  0xa00fe634
a00fe6c4:  90 10 00 18  mov  %i0, %o0
