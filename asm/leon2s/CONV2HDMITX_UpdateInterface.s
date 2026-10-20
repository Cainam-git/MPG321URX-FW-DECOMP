# leon2s CONV2HDMITX_UpdateInterface 0xa00a94f4-0xa00a9870 (892 bytes)
a00a94f4:  9d e3 bf 78  save  %sp, -136, %sp
a00a94f8:  a4 07 bf e0  add  %fp, -32, %l2
a00a94fc:  90 10 00 12  mov  %l2, %o0
a00a9500:  92 10 20 00  clr  %o1
a00a9504:  40 00 20 2a  call  0xa00b15ac
a00a9508:  94 10 20 13  mov  0x13, %o2
a00a950c:  da 0e 60 01  ldub  [ %i1 + 1 ], %o5
a00a9510:  82 03 60 1f  add  %o5, 0x1f, %g1
a00a9514:  82 08 60 ff  and  %g1, 0xff, %g1
a00a9518:  80 a0 60 01  cmp  %g1, 1
a00a951c:  c0 27 bf d8  clr  [ %fp + -40 ]
a00a9520:  18 80 00 04  bgu  0xa00a9530
a00a9524:  a6 10 20 00  clr  %l3
a00a9528:  da 0e 60 17  ldub  [ %i1 + 0x17 ], %o5
a00a952c:  a6 10 20 01  mov  1, %l3
a00a9530:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00a9534:  80 a3 60 51  cmp  %o5, 0x51
a00a9538:  02 80 00 5c  be  0xa00a96a8
a00a953c:  90 10 20 00  clr  %o0
a00a9540:  14 80 00 09  bg  0xa00a9564
a00a9544:  80 a3 60 71  cmp  %o5, 0x71
a00a9548:  80 a3 60 31  cmp  %o5, 0x31
a00a954c:  02 80 00 13  be  0xa00a9598
a00a9550:  80 a3 60 41  cmp  %o5, 0x41
a00a9554:  02 80 00 13  be  0xa00a95a0
a00a9558:  80 a3 60 51  cmp  %o5, 0x51
a00a955c:  10 80 00 1a  b  0xa00a95c4
a00a9560:  a0 10 20 00  clr  %l0
a00a9564:  02 80 00 13  be  0xa00a95b0
a00a9568:  80 a3 60 71  cmp  %o5, 0x71
a00a956c:  14 80 00 07  bg  0xa00a9588
a00a9570:  80 a3 60 81  cmp  %o5, 0x81
a00a9574:  80 a3 60 61  cmp  %o5, 0x61
a00a9578:  02 80 00 0c  be  0xa00a95a8
a00a957c:  80 a3 60 51  cmp  %o5, 0x51
a00a9580:  10 80 00 10  b  0xa00a95c0
a00a9584:  a0 10 20 00  clr  %l0
a00a9588:  02 80 00 0c  be  0xa00a95b8
a00a958c:  80 a3 60 51  cmp  %o5, 0x51
a00a9590:  10 80 00 0c  b  0xa00a95c0
a00a9594:  a0 10 20 00  clr  %l0
a00a9598:  10 80 00 24  b  0xa00a9628
a00a959c:  a0 10 20 00  clr  %l0
a00a95a0:  10 80 00 22  b  0xa00a9628
a00a95a4:  a0 10 20 01  mov  1, %l0
a00a95a8:  10 80 00 40  b  0xa00a96a8
a00a95ac:  90 10 20 01  mov  1, %o0
a00a95b0:  10 80 00 6c  b  0xa00a9760
a00a95b4:  a2 10 20 00  clr  %l1
a00a95b8:  10 80 00 6a  b  0xa00a9760
a00a95bc:  a2 10 20 01  mov  1, %l1
a00a95c0:  90 10 20 00  clr  %o0
a00a95c4:  02 80 00 39  be  0xa00a96a8
a00a95c8:  a2 10 20 00  clr  %l1
a00a95cc:  80 a3 60 51  cmp  %o5, 0x51
a00a95d0:  14 80 00 09  bg  0xa00a95f4
a00a95d4:  80 a3 60 71  cmp  %o5, 0x71
a00a95d8:  80 a3 60 31  cmp  %o5, 0x31
a00a95dc:  02 80 00 13  be  0xa00a9628
a00a95e0:  80 a3 60 41  cmp  %o5, 0x41
a00a95e4:  22 80 00 12  be,a   0xa00a962c
a00a95e8:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00a95ec:  10 80 00 93  b  0xa00a9838
a00a95f0:  11 28 01 b0  sethi  %hi(0xa006c000), %o0
a00a95f4:  02 80 00 5b  be  0xa00a9760
a00a95f8:  80 a3 60 71  cmp  %o5, 0x71
a00a95fc:  14 80 00 07  bg  0xa00a9618
a00a9600:  80 a3 60 81  cmp  %o5, 0x81
a00a9604:  80 a3 60 61  cmp  %o5, 0x61
a00a9608:  02 80 00 29  be  0xa00a96ac
a00a960c:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00a9610:  10 80 00 8a  b  0xa00a9838
a00a9614:  11 28 01 b0  sethi  %hi(0xa006c000), %o0
a00a9618:  22 80 00 53  be,a   0xa00a9764
a00a961c:  c2 06 40 00  ld  [ %i1 ], %g1
a00a9620:  10 80 00 86  b  0xa00a9838
a00a9624:  11 28 01 b0  sethi  %hi(0xa006c000), %o0
a00a9628:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00a962c:  7f ff 9e 3f  call  0xa0090f28
a00a9630:  90 10 00 10  mov  %l0, %o0
a00a9634:  c2 06 40 00  ld  [ %i1 ], %g1
a00a9638:  90 0a 20 01  and  %o0, 1, %o0
a00a963c:  91 2a 20 05  sll  %o0, 5, %o0
a00a9640:  82 08 7f df  and  %g1, -33, %g1
a00a9644:  82 10 40 08  or  %g1, %o0, %g1
a00a9648:  c2 26 40 00  st  %g1, [ %i1 ]
a00a964c:  7f ff 9e 3e  call  0xa0090f44
a00a9650:  90 10 00 10  mov  %l0, %o0
a00a9654:  d0 2e 60 11  stb  %o0, [ %i1 + 0x11 ]
a00a9658:  7f ff 9e 42  call  0xa0090f60
a00a965c:  90 10 00 10  mov  %l0, %o0
a00a9660:  c2 06 40 00  ld  [ %i1 ], %g1
a00a9664:  90 0a 20 01  and  %o0, 1, %o0
a00a9668:  91 2a 20 07  sll  %o0, 7, %o0
a00a966c:  82 08 7f 7f  and  %g1, -129, %g1
a00a9670:  82 10 40 08  or  %g1, %o0, %g1
a00a9674:  c2 26 40 00  st  %g1, [ %i1 ]
a00a9678:  7f ff 9e 41  call  0xa0090f7c
a00a967c:  90 10 00 10  mov  %l0, %o0
a00a9680:  c2 06 40 00  ld  [ %i1 ], %g1
a00a9684:  90 0a 20 01  and  %o0, 1, %o0
a00a9688:  91 2a 20 06  sll  %o0, 6, %o0
a00a968c:  82 08 7f bf  and  %g1, -65, %g1
a00a9690:  82 10 40 08  or  %g1, %o0, %g1
a00a9694:  c2 26 40 00  st  %g1, [ %i1 ]
a00a9698:  7f ff 9e 40  call  0xa0090f98
a00a969c:  90 10 00 10  mov  %l0, %o0
a00a96a0:  10 80 00 29  b  0xa00a9744
a00a96a4:  91 2a 20 10  sll  %o0, 0x10, %o0
a00a96a8:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00a96ac:  7f ff e4 0d  call  0xa00a26e0
a00a96b0:  90 10 00 10  mov  %l0, %o0
a00a96b4:  c2 06 40 00  ld  [ %i1 ], %g1
a00a96b8:  90 0a 20 01  and  %o0, 1, %o0
a00a96bc:  91 2a 20 05  sll  %o0, 5, %o0
a00a96c0:  82 08 7f df  and  %g1, -33, %g1
a00a96c4:  82 10 40 08  or  %g1, %o0, %g1
a00a96c8:  c2 26 40 00  st  %g1, [ %i1 ]
a00a96cc:  7f ff e4 0c  call  0xa00a26fc
a00a96d0:  90 10 00 10  mov  %l0, %o0
a00a96d4:  d0 2e 60 11  stb  %o0, [ %i1 + 0x11 ]
a00a96d8:  7f ff e4 10  call  0xa00a2718
a00a96dc:  90 10 00 10  mov  %l0, %o0
a00a96e0:  c2 06 40 00  ld  [ %i1 ], %g1
a00a96e4:  90 0a 20 01  and  %o0, 1, %o0
a00a96e8:  91 2a 20 07  sll  %o0, 7, %o0
a00a96ec:  82 08 7f 7f  and  %g1, -129, %g1
a00a96f0:  82 10 40 08  or  %g1, %o0, %g1
a00a96f4:  c2 26 40 00  st  %g1, [ %i1 ]
a00a96f8:  7f ff e4 0f  call  0xa00a2734
a00a96fc:  90 10 00 10  mov  %l0, %o0
a00a9700:  c2 06 40 00  ld  [ %i1 ], %g1
a00a9704:  90 0a 20 01  and  %o0, 1, %o0
a00a9708:  91 2a 20 06  sll  %o0, 6, %o0
a00a970c:  82 08 7f bf  and  %g1, -65, %g1
a00a9710:  82 10 40 08  or  %g1, %o0, %g1
a00a9714:  80 8c e0 ff  btst  0xff, %l3
a00a9718:  12 80 00 0d  bne  0xa00a974c
a00a971c:  c2 26 40 00  st  %g1, [ %i1 ]
a00a9720:  7f ff e4 0c  call  0xa00a2750
a00a9724:  90 10 00 10  mov  %l0, %o0
a00a9728:  91 2a 20 10  sll  %o0, 0x10, %o0
a00a972c:  03 33 33 33  sethi  %hi(0xcccccc00), %g1
a00a9730:  91 32 20 10  srl  %o0, 0x10, %o0
a00a9734:  82 10 60 cd  or  %g1, 0xcd, %g1
a00a9738:  80 52 00 01  umul  %o0, %g1, %g0
a00a973c:  91 40 00 00  rd  %y, %o0
a00a9740:  91 2a 20 0d  sll  %o0, 0xd, %o0
a00a9744:  91 32 20 10  srl  %o0, 0x10, %o0
a00a9748:  d0 26 60 08  st  %o0, [ %i1 + 8 ]
a00a974c:  90 0e 20 ff  and  %i0, 0xff, %o0
a00a9750:  7f ff a3 63  call  0xa00924dc
a00a9754:  92 10 20 00  clr  %o1
a00a9758:  10 80 00 3b  b  0xa00a9844
a00a975c:  82 0e 20 ff  and  %i0, 0xff, %g1
a00a9760:  c2 06 40 00  ld  [ %i1 ], %g1
a00a9764:  a2 0c 60 ff  and  %l1, 0xff, %l1
a00a9768:  82 10 60 20  or  %g1, 0x20, %g1
a00a976c:  c2 26 40 00  st  %g1, [ %i1 ]
a00a9770:  40 00 1b 1d  call  0xa00b03e4
a00a9774:  90 10 00 11  mov  %l1, %o0
a00a9778:  d0 2e 60 11  stb  %o0, [ %i1 + 0x11 ]
a00a977c:  40 00 1b 21  call  0xa00b0400
a00a9780:  90 10 00 11  mov  %l1, %o0
a00a9784:  c2 06 40 00  ld  [ %i1 ], %g1
a00a9788:  90 0a 20 01  and  %o0, 1, %o0
a00a978c:  91 2a 20 07  sll  %o0, 7, %o0
a00a9790:  82 08 7f 7f  and  %g1, -129, %g1
a00a9794:  82 10 40 08  or  %g1, %o0, %g1
a00a9798:  c2 26 40 00  st  %g1, [ %i1 ]
a00a979c:  40 00 1b 20  call  0xa00b041c
a00a97a0:  90 10 00 11  mov  %l1, %o0
a00a97a4:  c2 06 40 00  ld  [ %i1 ], %g1
a00a97a8:  90 0a 20 01  and  %o0, 1, %o0
a00a97ac:  91 2a 20 06  sll  %o0, 6, %o0
a00a97b0:  82 08 7f bf  and  %g1, -65, %g1
a00a97b4:  82 10 40 08  or  %g1, %o0, %g1
a00a97b8:  c2 26 40 00  st  %g1, [ %i1 ]
a00a97bc:  40 00 1b 1f  call  0xa00b0438
a00a97c0:  90 10 00 11  mov  %l1, %o0
a00a97c4:  a0 10 00 08  mov  %o0, %l0
a00a97c8:  40 00 1b 07  call  0xa00b03e4
a00a97cc:  90 10 00 11  mov  %l1, %o0
a00a97d0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a97d4:  a0 5c 00 08  smul  %l0, %o0, %l0
a00a97d8:  a1 34 20 03  srl  %l0, 3, %l0
a00a97dc:  e0 26 60 08  st  %l0, [ %i1 + 8 ]
a00a97e0:  40 00 1a e5  call  0xa00b0374
a00a97e4:  90 10 00 11  mov  %l1, %o0
a00a97e8:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a00a97ec:  40 00 1a e9  call  0xa00b0390
a00a97f0:  90 10 00 11  mov  %l1, %o0
a00a97f4:  d0 2f bf d9  stb  %o0, [ %fp + -39 ]
a00a97f8:  40 00 1a ed  call  0xa00b03ac
a00a97fc:  90 10 00 11  mov  %l1, %o0
a00a9800:  d0 2f bf da  stb  %o0, [ %fp + -38 ]
a00a9804:  40 00 1a f1  call  0xa00b03c8
a00a9808:  90 10 00 11  mov  %l1, %o0
a00a980c:  d0 2f bf db  stb  %o0, [ %fp + -37 ]
a00a9810:  40 00 1b 0a  call  0xa00b0438
a00a9814:  90 10 00 11  mov  %l1, %o0
a00a9818:  92 07 bf d8  add  %fp, -40, %o1
a00a981c:  7f ff fe 01  call  0xa00a9020
a00a9820:  94 10 00 12  mov  %l2, %o2
a00a9824:  92 10 00 12  mov  %l2, %o1
a00a9828:  7f ff a3 64  call  0xa00925b8
a00a982c:  90 0e 20 ff  and  %i0, 0xff, %o0
a00a9830:  10 80 00 05  b  0xa00a9844
a00a9834:  82 0e 20 ff  and  %i0, 0xff, %g1
a00a9838:  7f ff 27 23  call  0xa00734c4
a00a983c:  90 12 23 d8  or  %o0, 0x3d8, %o0
a00a9840:  82 0e 20 ff  and  %i0, 0xff, %g1
a00a9844:  9a 00 40 01  add  %g1, %g1, %o5
a00a9848:  9a 03 40 01  add  %o5, %g1, %o5
a00a984c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a9850:  9b 2b 60 02  sll  %o5, 2, %o5
a00a9854:  82 10 62 90  or  %g1, 0x290, %g1
a00a9858:  9a 03 40 01  add  %o5, %g1, %o5
a00a985c:  c0 2b 60 10  clrb  [ %o5 + 0x10 ]
a00a9860:  c0 2b 60 0d  clrb  [ %o5 + 0xd ]
a00a9864:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00a9868:  81 c7 e0 08  ret
a00a986c:  81 e8 00 00  restore
