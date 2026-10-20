# leon2s FUN_a00a0588 0xa00a0588-0xa00a0798 (528 bytes)
a00a0588:  9d e3 bf 98  save  %sp, -104, %sp
a00a058c:  9a 10 00 18  mov  %i0, %o5
a00a0590:  80 a6 60 3f  cmp  %i1, 0x3f
a00a0594:  9e 10 20 00  clr  %o7
a00a0598:  18 80 00 7e  bgu  0xa00a0790
a00a059c:  b0 10 20 00  clr  %i0
a00a05a0:  03 28 02 d2  sethi  %hi(0xa00b4800), %g1
a00a05a4:  82 10 62 00  or  %g1, 0x200, %g1	! 0xa00b4a00
a00a05a8:  b5 2e 60 03  sll  %i1, 3, %i2
a00a05ac:  ba 06 80 01  add  %i2, %g1, %i5
a00a05b0:  f4 06 80 01  ld  [ %i2 + %g1 ], %i2
a00a05b4:  f8 0f 60 05  ldub  [ %i5 + 5 ], %i4
a00a05b8:  f6 0f 60 04  ldub  [ %i5 + 4 ], %i3
a00a05bc:  c2 0f 60 06  ldub  [ %i5 + 6 ], %g1
a00a05c0:  b7 2e e0 03  sll  %i3, 3, %i3
a00a05c4:  b9 2f 20 03  sll  %i4, 3, %i4
a00a05c8:  b8 07 00 01  add  %i4, %g1, %i4
a00a05cc:  80 a6 a0 07  cmp  %i2, 7
a00a05d0:  18 80 00 6f  bgu  0xa00a078c
a00a05d4:  b6 06 c0 01  add  %i3, %g1, %i3
a00a05d8:  3b 28 02 81  sethi  %hi(0xa00a0400), %i5
a00a05dc:  83 2e a0 02  sll  %i2, 2, %g1
a00a05e0:  ba 17 61 68  or  %i5, 0x168, %i5
a00a05e4:  c2 07 40 01  ld  [ %i5 + %g1 ], %g1
a00a05e8:  3b 2a 01 f6  sethi  %hi(0xa807d800), %i5
a00a05ec:  81 c0 40 00  jmp  %g1
a00a05f0:  b4 0b 60 ff  and  %o5, 0xff, %i2
a00a05f4:  82 1e 60 04  xor  %i1, 4, %g1
a00a05f8:  80 a0 00 01  cmp  %g0, %g1
a00a05fc:  ba 60 3f ff  subx  %g0, -1, %i5
a00a0600:  82 1e 60 16  xor  %i1, 0x16, %g1
a00a0604:  80 a0 00 01  cmp  %g0, %g1
a00a0608:  82 60 3f ff  subx  %g0, -1, %g1
a00a060c:  80 97 40 01  orcc  %i5, %g1, %g0
a00a0610:  b4 0b 60 ff  and  %o5, 0xff, %i2
a00a0614:  02 80 00 0a  be  0xa00a063c
a00a0618:  3b 2a 01 f6  sethi  %hi(0xa807d800), %i5
a00a061c:  82 5e a0 34  smul  %i2, 0x34, %g1
a00a0620:  ba 17 63 00  or  %i5, 0x300, %i5
a00a0624:  fa 07 40 01  ld  [ %i5 + %g1 ], %i5
a00a0628:  82 10 20 01  mov  1, %g1
a00a062c:  83 28 40 1b  sll  %g1, %i3, %g1
a00a0630:  fa 07 60 70  ld  [ %i5 + 0x70 ], %i5
a00a0634:  10 80 00 54  b  0xa00a0784
a00a0638:  80 88 40 1d  btst  %g1, %i5
a00a063c:  ba 17 63 00  or  %i5, 0x300, %i5
a00a0640:  82 5e a0 34  smul  %i2, 0x34, %g1
a00a0644:  f4 07 40 01  ld  [ %i5 + %g1 ], %i2
a00a0648:  b2 10 20 01  mov  1, %i1
a00a064c:  bb 2e 40 1c  sll  %i1, %i4, %i5
a00a0650:  c2 06 a0 74  ld  [ %i2 + 0x74 ], %g1
a00a0654:  82 08 40 1d  and  %g1, %i5, %g1
a00a0658:  80 88 7f 00  btst  -256, %g1
a00a065c:  02 80 00 4d  be  0xa00a0790
a00a0660:  b0 0b e0 ff  and  %o7, 0xff, %i0
a00a0664:  bb 2e 40 1b  sll  %i1, %i3, %i5
a00a0668:  c2 06 a0 70  ld  [ %i2 + 0x70 ], %g1
a00a066c:  10 80 00 46  b  0xa00a0784
a00a0670:  80 88 40 1d  btst  %g1, %i5
a00a0674:  ba 17 63 00  or  %i5, 0x300, %i5
a00a0678:  82 5e a0 34  smul  %i2, 0x34, %g1
a00a067c:  f4 07 40 01  ld  [ %i5 + %g1 ], %i2
a00a0680:  b2 10 20 01  mov  1, %i1
a00a0684:  bb 2e 40 1c  sll  %i1, %i4, %i5
a00a0688:  c2 06 a0 78  ld  [ %i2 + 0x78 ], %g1
a00a068c:  82 08 40 1d  and  %g1, %i5, %g1
a00a0690:  3b 3f c0 00  sethi  %hi(0xff000000), %i5
a00a0694:  80 a8 40 1d  andncc  %g1, %i5, %g0
a00a0698:  02 80 00 3e  be  0xa00a0790
a00a069c:  b0 0b e0 ff  and  %o7, 0xff, %i0
a00a06a0:  bb 2e 40 1b  sll  %i1, %i3, %i5
a00a06a4:  c2 06 a0 74  ld  [ %i2 + 0x74 ], %g1
a00a06a8:  10 80 00 37  b  0xa00a0784
a00a06ac:  80 88 40 1d  btst  %g1, %i5
a00a06b0:  82 5e a0 34  smul  %i2, 0x34, %g1
a00a06b4:  ba 17 63 00  or  %i5, 0x300, %i5
a00a06b8:  fa 07 40 01  ld  [ %i5 + %g1 ], %i5
a00a06bc:  82 10 20 01  mov  1, %g1
a00a06c0:  b7 28 40 1b  sll  %g1, %i3, %i3
a00a06c4:  c2 07 60 7c  ld  [ %i5 + 0x7c ], %g1
a00a06c8:  82 08 40 1b  and  %g1, %i3, %g1
a00a06cc:  80 88 7f 00  btst  -256, %g1
a00a06d0:  02 80 00 30  be  0xa00a0790
a00a06d4:  b0 0b e0 ff  and  %o7, 0xff, %i0
a00a06d8:  c2 07 60 78  ld  [ %i5 + 0x78 ], %g1
a00a06dc:  10 80 00 2a  b  0xa00a0784
a00a06e0:  80 88 40 1b  btst  %g1, %i3
a00a06e4:  82 5e a0 34  smul  %i2, 0x34, %g1
a00a06e8:  ba 17 63 00  or  %i5, 0x300, %i5
a00a06ec:  fa 07 40 01  ld  [ %i5 + %g1 ], %i5
a00a06f0:  82 10 20 01  mov  1, %g1
a00a06f4:  b7 28 40 1b  sll  %g1, %i3, %i3
a00a06f8:  c2 07 60 7c  ld  [ %i5 + 0x7c ], %g1
a00a06fc:  82 08 40 1b  and  %g1, %i3, %g1
a00a0700:  80 88 7f 00  btst  -256, %g1
a00a0704:  02 80 00 23  be  0xa00a0790
a00a0708:  b0 0b e0 ff  and  %o7, 0xff, %i0
a00a070c:  c2 07 60 7c  ld  [ %i5 + 0x7c ], %g1
a00a0710:  10 80 00 1d  b  0xa00a0784
a00a0714:  80 88 40 1b  btst  %g1, %i3
a00a0718:  82 5e a0 34  smul  %i2, 0x34, %g1
a00a071c:  ba 17 63 00  or  %i5, 0x300, %i5
a00a0720:  fa 07 40 01  ld  [ %i5 + %g1 ], %i5
a00a0724:  82 10 20 01  mov  1, %g1
a00a0728:  b7 28 40 1b  sll  %g1, %i3, %i3
a00a072c:  c2 07 60 7c  ld  [ %i5 + 0x7c ], %g1
a00a0730:  82 08 40 1b  and  %g1, %i3, %g1
a00a0734:  80 88 7f 00  btst  -256, %g1
a00a0738:  02 80 00 16  be  0xa00a0790
a00a073c:  b0 0b e0 ff  and  %o7, 0xff, %i0
a00a0740:  c2 07 60 80  ld  [ %i5 + 0x80 ], %g1
a00a0744:  10 80 00 10  b  0xa00a0784
a00a0748:  80 88 40 1b  btst  %g1, %i3
a00a074c:  ba 17 63 00  or  %i5, 0x300, %i5
a00a0750:  82 5e a0 34  smul  %i2, 0x34, %g1
a00a0754:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a00a0758:  82 10 20 01  mov  1, %g1
a00a075c:  b7 28 40 1b  sll  %g1, %i3, %i3
a00a0760:  fa 07 20 90  ld  [ %i4 + 0x90 ], %i5
a00a0764:  03 3f c0 3f  sethi  %hi(0xff00fc00), %g1
a00a0768:  ba 0f 40 1b  and  %i5, %i3, %i5
a00a076c:  82 10 63 00  or  %g1, 0x300, %g1
a00a0770:  80 8f 40 01  btst  %i5, %g1
a00a0774:  02 80 00 07  be  0xa00a0790
a00a0778:  b0 0b e0 ff  and  %o7, 0xff, %i0
a00a077c:  c2 07 20 90  ld  [ %i4 + 0x90 ], %g1
a00a0780:  80 88 40 1b  btst  %g1, %i3
a00a0784:  32 80 00 02  bne,a   0xa00a078c
a00a0788:  9e 10 20 01  mov  1, %o7
a00a078c:  b0 0b e0 ff  and  %o7, 0xff, %i0
a00a0790:  81 c7 e0 08  ret
a00a0794:  81 e8 00 00  restore
