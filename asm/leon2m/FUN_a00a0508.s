# leon2m FUN_a00a0508 0xa00a0508-0xa00a0780 (632 bytes)
a00a0508:  9d e3 bf 98  save  %sp, -104, %sp
a00a050c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00a0510:  a2 14 22 90  or  %l0, 0x290, %l1	! 0xa802d290
a00a0514:  19 00 00 15  sethi  %hi(0x5400), %o4
a00a0518:  da 14 61 f6  lduh  [ %l1 + 0x1f6 ], %o5
a00a051c:  82 13 21 aa  or  %o4, 0x1aa, %g1
a00a0520:  80 a3 40 01  cmp  %o5, %g1
a00a0524:  02 80 00 12  be  0xa00a056c
a00a0528:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a00a052c:  c2 13 63 f4  lduh  [ %o5 + 0x3f4 ], %g1	! 0xa802cff4
a00a0530:  80 88 64 00  btst  0x400, %g1
a00a0534:  12 80 00 91  bne  0xa00a0778
a00a0538:  98 13 63 f4  or  %o5, 0x3f4, %o4
a00a053c:  d0 0c 61 a9  ldub  [ %l1 + 0x1a9 ], %o0
a00a0540:  80 a2 20 01  cmp  %o0, 1
a00a0544:  22 80 00 3a  be,a   0xa00a062c
a00a0548:  d2 0c 61 8d  ldub  [ %l1 + 0x18d ], %o1
a00a054c:  40 02 72 48  call  0xa013ce6c
a00a0550:  90 10 20 00  clr  %o0
a00a0554:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00a0558:  80 a4 60 0c  cmp  %l1, 0xc
a00a055c:  12 80 00 87  bne  0xa00a0778
a00a0560:  9a 14 22 90  or  %l0, 0x290, %o5
a00a0564:  10 80 00 16  b  0xa00a05bc
a00a0568:  c2 0b 61 8d  ldub  [ %o5 + 0x18d ], %g1
a00a056c:  17 00 3f ff  sethi  %hi(0xfffc00), %o3
a00a0570:  d2 04 61 d4  ld  [ %l1 + 0x1d4 ], %o1
a00a0574:  94 12 e3 00  or  %o3, 0x300, %o2
a00a0578:  90 0a 40 0a  and  %o1, %o2, %o0
a00a057c:  98 13 21 00  or  %o4, 0x100, %o4
a00a0580:  80 a2 00 0c  cmp  %o0, %o4
a00a0584:  12 bf ff f2  bne  0xa00a054c
a00a0588:  01 00 00 00  nop
a00a058c:  40 02 90 04  call  0xa014459c
a00a0590:  90 10 20 00  clr  %o0	! 0x0
a00a0594:  40 00 e3 29  call  0xa00d9238
a00a0598:  d0 2c 60 1e  stb  %o0, [ %l1 + 0x1e ]
a00a059c:  90 10 20 04  mov  4, %o0
a00a05a0:  7f ff 80 c3  call  0xa00808ac
a00a05a4:  92 10 20 00  clr  %o1
a00a05a8:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00a05ac:  e2 0b e0 8e  ldub  [ %o7 + 0x8e ], %l1	! 0xa802b08e
a00a05b0:  a0 14 60 02  or  %l1, 2, %l0
a00a05b4:  10 80 00 71  b  0xa00a0778
a00a05b8:  e0 2b e0 8e  stb  %l0, [ %o7 + 0x8e ]
a00a05bc:  80 a0 60 00  cmp  %g1, 0
a00a05c0:  02 80 00 6e  be  0xa00a0778
a00a05c4:  80 a0 60 01  cmp  %g1, 1
a00a05c8:  22 80 00 39  be,a   0xa00a06ac
a00a05cc:  de 03 61 1c  ld  [ %o5 + 0x11c ], %o7
a00a05d0:  a0 14 22 90  or  %l0, 0x290, %l0
a00a05d4:  da 0c 21 8d  ldub  [ %l0 + 0x18d ], %o5
a00a05d8:  80 a3 60 06  cmp  %o5, 6
a00a05dc:  02 80 00 48  be  0xa00a06fc
a00a05e0:  01 00 00 00  nop
a00a05e4:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a05e8:  80 a0 60 06  cmp  %g1, 6
a00a05ec:  02 80 00 2a  be  0xa00a0694
a00a05f0:  80 a0 60 09  cmp  %g1, 9
a00a05f4:  02 80 00 56  be  0xa00a074c
a00a05f8:  01 00 00 00  nop
a00a05fc:  92 0b 60 ff  and  %o5, 0xff, %o1
a00a0600:  80 a2 60 0a  cmp  %o1, 0xa
a00a0604:  02 80 00 4c  be  0xa00a0734
a00a0608:  01 00 00 00  nop
a00a060c:  40 00 62 1c  call  0xa00b8e7c
a00a0610:  90 10 20 03  mov  3, %o0	! 0x3
a00a0614:  e2 0c 21 8d  ldub  [ %l0 + 0x18d ], %l1
a00a0618:  94 04 60 f9  add  %l1, 0xf9, %o2
a00a061c:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00a0620:  d4 24 23 ec  st  %o2, [ %l0 + 0x3ec ]	! 0xa802afec
a00a0624:  40 00 0f e1  call  0xa00a45a8
a00a0628:  81 e8 00 00  restore
a00a062c:  80 a2 60 02  cmp  %o1, 2
a00a0630:  12 bf ff c7  bne  0xa00a054c
a00a0634:  1b 3f ff e0  sethi  %hi(0xffff8000), %o5
a00a0638:  d6 13 20 04  lduh  [ %o4 + 4 ], %o3
a00a063c:  a0 0a c0 0d  and  %o3, %o5, %l0
a00a0640:  95 2c 20 10  sll  %l0, 0x10, %o2
a00a0644:  9e 10 20 05  mov  5, %o7
a00a0648:  80 a2 a0 00  cmp  %o2, 0
a00a064c:  12 80 00 33  bne  0xa00a0718
a00a0650:  de 2b 20 0a  stb  %o7, [ %o4 + 0xa ]
a00a0654:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00a0658:  40 00 52 8a  call  0xa00b5080
a00a065c:  c0 24 23 ec  clr  [ %l0 + 0x3ec ]	! 0xa802afec
a00a0660:  40 00 42 3a  call  0xa00b0f48
a00a0664:  01 00 00 00  nop
a00a0668:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00a066c:  d4 0a e0 8e  ldub  [ %o3 + 0x8e ], %o2	! 0xa802b08e
a00a0670:  90 12 a0 02  or  %o2, 2, %o0
a00a0674:  92 10 21 16  mov  0x116, %o1
a00a0678:  d2 24 23 ec  st  %o1, [ %l0 + 0x3ec ]
a00a067c:  d0 2a e0 8e  stb  %o0, [ %o3 + 0x8e ]
a00a0680:  67 ff b3 c2  call  0x4008d588
a00a0684:  c0 2c 61 aa  clrb  [ %l1 + 0x1aa ]
a00a0688:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00a068c:  10 80 00 3b  b  0xa00a0778
a00a0690:  d0 33 20 3c  sth  %o0, [ %o4 + 0x3c ]	! 0xa802d03c
a00a0694:  d8 04 21 f4  ld  [ %l0 + 0x1f4 ], %o4
a00a0698:  80 a3 20 00  cmp  %o4, 0
a00a069c:  06 80 00 37  bl  0xa00a0778
a00a06a0:  92 0b 60 ff  and  %o5, 0xff, %o1
a00a06a4:  10 bf ff d8  b  0xa00a0604
a00a06a8:  80 a2 60 0a  cmp  %o1, 0xa
a00a06ac:  80 a3 e0 00  cmp  %o7, 0
a00a06b0:  06 80 00 32  bl  0xa00a0778
a00a06b4:  01 00 00 00  nop
a00a06b8:  c2 03 60 b0  ld  [ %o5 + 0xb0 ], %g1
a00a06bc:  80 a0 60 00  cmp  %g1, 0
a00a06c0:  02 80 00 08  be  0xa00a06e0
a00a06c4:  01 00 00 00  nop
a00a06c8:  40 00 e1 44  call  0xa00d8bd8
a00a06cc:  01 00 00 00  nop
a00a06d0:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00a06d4:  80 a3 60 01  cmp  %o5, 1
a00a06d8:  02 80 00 28  be  0xa00a0778
a00a06dc:  01 00 00 00  nop
a00a06e0:  40 00 dd 9a  call  0xa00d7d48
a00a06e4:  01 00 00 00  nop
a00a06e8:  80 a2 20 00  cmp  %o0, 0
a00a06ec:  12 80 00 23  bne  0xa00a0778
a00a06f0:  a0 14 22 90  or  %l0, 0x290, %l0
a00a06f4:  10 bf ff b9  b  0xa00a05d8
a00a06f8:  da 0c 21 8d  ldub  [ %l0 + 0x18d ], %o5
a00a06fc:  40 00 dd 93  call  0xa00d7d48
a00a0700:  01 00 00 00  nop
a00a0704:  80 a2 20 00  cmp  %o0, 0
a00a0708:  12 80 00 1c  bne  0xa00a0778
a00a070c:  01 00 00 00  nop
a00a0710:  10 bf ff b5  b  0xa00a05e4
a00a0714:  da 0c 21 8d  ldub  [ %l0 + 0x18d ], %o5
a00a0718:  82 12 e4 00  or  %o3, 0x400, %g1
a00a071c:  c2 33 20 04  sth  %g1, [ %o4 + 4 ]
a00a0720:  90 10 20 04  mov  4, %o0
a00a0724:  7f ff 80 62  call  0xa00808ac
a00a0728:  92 10 20 00  clr  %o1
a00a072c:  10 bf ff cb  b  0xa00a0658
a00a0730:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00a0734:  40 00 dd 85  call  0xa00d7d48
a00a0738:  01 00 00 00  nop
a00a073c:  80 a2 20 00  cmp  %o0, 0
a00a0740:  02 bf ff b3  be  0xa00a060c
a00a0744:  01 00 00 00  nop
a00a0748:  30 80 00 0c  b,a   0xa00a0778
a00a074c:  40 00 dd 7f  call  0xa00d7d48
a00a0750:  01 00 00 00  nop
a00a0754:  80 a2 20 00  cmp  %o0, 0
a00a0758:  12 80 00 08  bne  0xa00a0778
a00a075c:  17 00 00 20  sethi  %hi(0x8000), %o3
a00a0760:  d0 04 21 74  ld  [ %l0 + 0x174 ], %o0
a00a0764:  80 8a 00 0b  btst  %o0, %o3
a00a0768:  12 80 00 04  bne  0xa00a0778
a00a076c:  01 00 00 00  nop
a00a0770:  10 bf ff a3  b  0xa00a05fc
a00a0774:  da 0c 21 8d  ldub  [ %l0 + 0x18d ], %o5
a00a0778:  81 c7 e0 08  ret
a00a077c:  81 e8 00 00  restore
