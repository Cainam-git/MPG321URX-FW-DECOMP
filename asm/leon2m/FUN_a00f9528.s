# leon2m FUN_a00f9528 0xa00f9528-0xa00f9880 (856 bytes)
a00f9528:  9d e3 bf 98  save  %sp, -104, %sp
a00f952c:  80 8e 60 ff  btst  0xff, %i1
a00f9530:  12 80 00 0c  bne  0xa00f9560
a00f9534:  25 2a 00 ad  sethi  %hi(0xa802b400), %l2
a00f9538:  c2 0c a3 c8  ldub  [ %l2 + 0x3c8 ], %g1	! 0xa802b7c8
a00f953c:  80 a0 60 01  cmp  %g1, 1
a00f9540:  22 80 00 54  be,a   0xa00f9690
a00f9544:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f9548:  04 80 00 1d  ble  0xa00f95bc
a00f954c:  80 a0 60 02  cmp  %g1, 2
a00f9550:  12 80 00 ca  bne  0xa00f9878
a00f9554:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f9558:  10 80 00 80  b  0xa00f9758
a00f955c:  90 10 00 18  mov  %i0, %o0
a00f9560:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00f9564:  90 10 00 10  mov  %l0, %o0
a00f9568:  92 10 20 32  mov  0x32, %o1
a00f956c:  7f ff e1 5a  call  0xa00f1ad4
a00f9570:  94 10 20 00  clr  %o2
a00f9574:  98 10 20 10  mov  0x10, %o4
a00f9578:  13 2a 00 ad  sethi  %hi(0xa802b400), %o1
a00f957c:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00f9580:  d8 22 63 d4  st  %o4, [ %o1 + 0x3d4 ]
a00f9584:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f9588:  d8 22 23 d0  st  %o4, [ %o0 + 0x3d0 ]
a00f958c:  d8 23 63 cc  st  %o4, [ %o5 + 0x3cc ]
a00f9590:  90 10 00 10  mov  %l0, %o0
a00f9594:  92 10 20 30  mov  0x30, %o1
a00f9598:  7f ff e1 4f  call  0xa00f1ad4
a00f959c:  94 10 20 00  clr  %o2
a00f95a0:  90 10 00 10  mov  %l0, %o0
a00f95a4:  92 10 20 30  mov  0x30, %o1
a00f95a8:  7f ff e1 4b  call  0xa00f1ad4
a00f95ac:  94 10 20 85  mov  0x85, %o2
a00f95b0:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f95b4:  10 80 00 b1  b  0xa00f9878
a00f95b8:  c0 28 63 c8  clrb  [ %g1 + 0x3c8 ]	! 0xa802b7c8
a00f95bc:  80 a0 60 00  cmp  %g1, 0
a00f95c0:  12 80 00 ae  bne  0xa00f9878
a00f95c4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f95c8:  90 10 00 18  mov  %i0, %o0
a00f95cc:  7f ff e1 31  call  0xa00f1a90
a00f95d0:  92 10 20 30  mov  0x30, %o1
a00f95d4:  80 8a 20 80  btst  0x80, %o0
a00f95d8:  12 80 00 a8  bne  0xa00f9878
a00f95dc:  b2 10 20 00  clr  %i1
a00f95e0:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00f95e4:  94 0e 60 ff  and  %i1, 0xff, %o2
a00f95e8:  90 10 00 18  mov  %i0, %o0
a00f95ec:  7f ff e1 3a  call  0xa00f1ad4
a00f95f0:  92 10 20 31  mov  0x31, %o1
a00f95f4:  92 10 20 35  mov  0x35, %o1
a00f95f8:  7f ff e1 26  call  0xa00f1a90
a00f95fc:  90 10 00 18  mov  %i0, %o0
a00f9600:  9e 0a 20 ff  and  %o0, 0xff, %o7
a00f9604:  a1 2b e0 08  sll  %o7, 8, %l0
a00f9608:  92 10 20 34  mov  0x34, %o1
a00f960c:  7f ff e1 21  call  0xa00f1a90
a00f9610:  90 10 00 18  mov  %i0, %o0
a00f9614:  94 0a 20 ff  and  %o0, 0xff, %o2
a00f9618:  96 14 00 0a  or  %l0, %o2, %o3
a00f961c:  a1 2a e0 08  sll  %o3, 8, %l0
a00f9620:  92 10 20 33  mov  0x33, %o1
a00f9624:  7f ff e1 1b  call  0xa00f1a90
a00f9628:  90 10 00 18  mov  %i0, %o0
a00f962c:  92 0a 20 ff  and  %o0, 0xff, %o1
a00f9630:  9b 2e 60 10  sll  %i1, 0x10, %o5
a00f9634:  98 14 00 09  or  %l0, %o1, %o4
a00f9638:  96 06 60 01  add  %i1, 1, %o3
a00f963c:  91 33 60 0b  srl  %o5, 0xb, %o0
a00f9640:  b3 2a e0 10  sll  %o3, 0x10, %i1
a00f9644:  e0 04 63 d4  ld  [ %l1 + 0x3d4 ], %l0
a00f9648:  82 5a 00 0c  smul  %o0, %o4, %g1
a00f964c:  95 36 60 10  srl  %i1, 0x10, %o2
a00f9650:  9e 00 40 10  add  %g1, %l0, %o7
a00f9654:  de 24 63 d4  st  %o7, [ %l1 + 0x3d4 ]
a00f9658:  80 a2 a0 07  cmp  %o2, 7
a00f965c:  08 bf ff e2  bleu  0xa00f95e4
a00f9660:  b2 10 00 0b  mov  %o3, %i1
a00f9664:  90 10 00 18  mov  %i0, %o0
a00f9668:  92 10 20 30  mov  0x30, %o1
a00f966c:  7f ff e1 1a  call  0xa00f1ad4
a00f9670:  94 10 20 00  clr  %o2
a00f9674:  90 10 00 18  mov  %i0, %o0
a00f9678:  92 10 20 30  mov  0x30, %o1
a00f967c:  7f ff e1 16  call  0xa00f1ad4
a00f9680:  94 10 20 8d  mov  0x8d, %o2
a00f9684:  82 10 20 01  mov  1, %g1
a00f9688:  10 80 00 7c  b  0xa00f9878
a00f968c:  c2 2c a3 c8  stb  %g1, [ %l2 + 0x3c8 ]
a00f9690:  90 10 00 18  mov  %i0, %o0
a00f9694:  7f ff e0 ff  call  0xa00f1a90
a00f9698:  92 10 20 30  mov  0x30, %o1
a00f969c:  80 8a 20 80  btst  0x80, %o0
a00f96a0:  12 80 00 76  bne  0xa00f9878
a00f96a4:  b2 10 20 00  clr  %i1
a00f96a8:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00f96ac:  94 0e 60 ff  and  %i1, 0xff, %o2
a00f96b0:  90 10 00 18  mov  %i0, %o0
a00f96b4:  7f ff e1 08  call  0xa00f1ad4
a00f96b8:  92 10 20 31  mov  0x31, %o1
a00f96bc:  92 10 20 35  mov  0x35, %o1
a00f96c0:  7f ff e0 f4  call  0xa00f1a90
a00f96c4:  90 10 00 18  mov  %i0, %o0
a00f96c8:  98 0a 20 ff  and  %o0, 0xff, %o4
a00f96cc:  a1 2b 20 08  sll  %o4, 8, %l0
a00f96d0:  92 10 20 34  mov  0x34, %o1
a00f96d4:  7f ff e0 ef  call  0xa00f1a90
a00f96d8:  90 10 00 18  mov  %i0, %o0
a00f96dc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f96e0:  82 14 00 08  or  %l0, %o0, %g1
a00f96e4:  a1 28 60 08  sll  %g1, 8, %l0
a00f96e8:  92 10 20 33  mov  0x33, %o1
a00f96ec:  7f ff e0 e9  call  0xa00f1a90
a00f96f0:  90 10 00 18  mov  %i0, %o0
a00f96f4:  9e 0a 20 ff  and  %o0, 0xff, %o7
a00f96f8:  90 06 60 01  add  %i1, 1, %o0
a00f96fc:  95 2e 60 10  sll  %i1, 0x10, %o2
a00f9700:  a0 14 00 0f  or  %l0, %o7, %l0
a00f9704:  97 32 a0 0b  srl  %o2, 0xb, %o3
a00f9708:  99 2a 20 10  sll  %o0, 0x10, %o4
a00f970c:  da 04 63 d0  ld  [ %l1 + 0x3d0 ], %o5
a00f9710:  b3 33 20 10  srl  %o4, 0x10, %i1
a00f9714:  92 5a c0 10  smul  %o3, %l0, %o1
a00f9718:  82 02 40 0d  add  %o1, %o5, %g1
a00f971c:  80 a6 60 07  cmp  %i1, 7
a00f9720:  c2 24 63 d0  st  %g1, [ %l1 + 0x3d0 ]
a00f9724:  08 bf ff e2  bleu  0xa00f96ac
a00f9728:  b2 10 00 08  mov  %o0, %i1
a00f972c:  90 10 00 18  mov  %i0, %o0
a00f9730:  92 10 20 30  mov  0x30, %o1
a00f9734:  7f ff e0 e8  call  0xa00f1ad4
a00f9738:  94 10 20 00  clr  %o2
a00f973c:  90 10 00 18  mov  %i0, %o0
a00f9740:  92 10 20 30  mov  0x30, %o1
a00f9744:  7f ff e0 e4  call  0xa00f1ad4
a00f9748:  94 10 20 95  mov  0x95, %o2
a00f974c:  82 10 20 02  mov  2, %g1
a00f9750:  10 80 00 4a  b  0xa00f9878
a00f9754:  c2 2c a3 c8  stb  %g1, [ %l2 + 0x3c8 ]
a00f9758:  7f ff e0 ce  call  0xa00f1a90
a00f975c:  92 10 20 30  mov  0x30, %o1
a00f9760:  80 8a 20 80  btst  0x80, %o0
a00f9764:  12 80 00 45  bne  0xa00f9878
a00f9768:  b2 10 20 00  clr  %i1
a00f976c:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00f9770:  94 0e 60 ff  and  %i1, 0xff, %o2
a00f9774:  90 10 00 18  mov  %i0, %o0
a00f9778:  7f ff e0 d7  call  0xa00f1ad4
a00f977c:  92 10 20 31  mov  0x31, %o1
a00f9780:  92 10 20 35  mov  0x35, %o1
a00f9784:  7f ff e0 c3  call  0xa00f1a90
a00f9788:  90 10 00 18  mov  %i0, %o0
a00f978c:  94 0a 20 ff  and  %o0, 0xff, %o2
a00f9790:  a1 2a a0 08  sll  %o2, 8, %l0
a00f9794:  92 10 20 34  mov  0x34, %o1
a00f9798:  7f ff e0 be  call  0xa00f1a90
a00f979c:  90 10 00 18  mov  %i0, %o0
a00f97a0:  96 0a 20 ff  and  %o0, 0xff, %o3
a00f97a4:  92 14 00 0b  or  %l0, %o3, %o1
a00f97a8:  a1 2a 60 08  sll  %o1, 8, %l0
a00f97ac:  92 10 20 33  mov  0x33, %o1
a00f97b0:  7f ff e0 b8  call  0xa00f1a90
a00f97b4:  90 10 00 18  mov  %i0, %o0
a00f97b8:  99 2e 60 10  sll  %i1, 0x10, %o4
a00f97bc:  92 06 60 01  add  %i1, 1, %o1
a00f97c0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f97c4:  9f 33 20 0b  srl  %o4, 0xb, %o7
a00f97c8:  82 14 00 08  or  %l0, %o0, %g1
a00f97cc:  97 2a 60 10  sll  %o1, 0x10, %o3
a00f97d0:  da 04 63 cc  ld  [ %l1 + 0x3cc ], %o5
a00f97d4:  b3 32 e0 10  srl  %o3, 0x10, %i1
a00f97d8:  94 5b c0 01  smul  %o7, %g1, %o2
a00f97dc:  98 02 80 0d  add  %o2, %o5, %o4
a00f97e0:  80 a6 60 07  cmp  %i1, 7
a00f97e4:  d8 24 63 cc  st  %o4, [ %l1 + 0x3cc ]
a00f97e8:  08 bf ff e2  bleu  0xa00f9770
a00f97ec:  b2 10 00 09  mov  %o1, %i1
a00f97f0:  1b 34 6d c5  sethi  %hi(0xd1b71400), %o5
a00f97f4:  82 13 63 59  or  %o5, 0x359, %g1	! 0xd1b71759
a00f97f8:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00f97fc:  80 53 00 01  umul  %o4, %g1, %g0
a00f9800:  9f 40 00 00  rd  %y, %o7
a00f9804:  33 2a 00 ad  sethi  %hi(0xa802b400), %i1
a00f9808:  e0 02 23 d4  ld  [ %o0 + 0x3d4 ], %l0
a00f980c:  d2 06 63 d0  ld  [ %i1 + 0x3d0 ], %o1
a00f9810:  99 33 e0 0c  srl  %o7, 0xc, %o4
a00f9814:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f9818:  80 52 40 01  umul  %o1, %g1, %g0
a00f981c:  97 40 00 00  rd  %y, %o3
a00f9820:  80 54 00 01  umul  %l0, %g1, %g0
a00f9824:  95 40 00 00  rd  %y, %o2
a00f9828:  d8 23 63 c4  st  %o4, [ %o5 + 0x3c4 ]
a00f982c:  9e 10 20 10  mov  0x10, %o7
a00f9830:  93 32 a0 0c  srl  %o2, 0xc, %o1
a00f9834:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f9838:  a1 32 e0 0c  srl  %o3, 0xc, %l0
a00f983c:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f9840:  d2 23 63 bc  st  %o1, [ %o5 + 0x3bc ]
a00f9844:  de 22 23 d4  st  %o7, [ %o0 + 0x3d4 ]
a00f9848:  e0 20 63 c0  st  %l0, [ %g1 + 0x3c0 ]
a00f984c:  de 24 63 cc  st  %o7, [ %l1 + 0x3cc ]
a00f9850:  de 26 63 d0  st  %o7, [ %i1 + 0x3d0 ]
a00f9854:  90 10 00 18  mov  %i0, %o0
a00f9858:  92 10 20 30  mov  0x30, %o1
a00f985c:  7f ff e0 9e  call  0xa00f1ad4
a00f9860:  94 10 20 00  clr  %o2
a00f9864:  90 10 00 18  mov  %i0, %o0
a00f9868:  92 10 20 30  mov  0x30, %o1
a00f986c:  7f ff e0 9a  call  0xa00f1ad4
a00f9870:  94 10 20 85  mov  0x85, %o2
a00f9874:  c0 2c a3 c8  clrb  [ %l2 + 0x3c8 ]
a00f9878:  81 c7 e0 08  ret
a00f987c:  81 e8 00 00  restore
