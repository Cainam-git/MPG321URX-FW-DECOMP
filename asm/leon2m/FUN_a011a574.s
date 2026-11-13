# leon2m FUN_a011a574 0xa011a574-0xa011a848 (724 bytes)
a011a574:  9d e3 bf 98  save  %sp, -104, %sp
a011a578:  b4 0e 60 ff  and  %i1, 0xff, %i2
a011a57c:  80 a6 a0 02  cmp  %i2, 2
a011a580:  b8 60 20 00  subx  %g0, 0, %i4
a011a584:  ba 0e 40 1c  and  %i1, %i4, %i5
a011a588:  b6 0f 60 ff  and  %i5, 0xff, %i3
a011a58c:  82 06 c0 1b  add  %i3, %i3, %g1
a011a590:  1f 2a 00 9e  sethi  %hi(0xa8027800), %o7
a011a594:  b6 13 e2 a8  or  %o7, 0x2a8, %i3	! 0xa8027aa8
a011a598:  f8 16 c0 01  lduh  [ %i3 + %g1 ], %i4
a011a59c:  9a 10 00 19  mov  %i1, %o5
a011a5a0:  b2 07 20 ab  add  %i4, 0xab, %i1
a011a5a4:  98 10 00 18  mov  %i0, %o4
a011a5a8:  b1 2e 60 02  sll  %i1, 2, %i0
a011a5ac:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011a5b0:  82 16 00 19  or  %i0, %i1, %g1
a011a5b4:  fa 0b 20 01  ldub  [ %o4 + 1 ], %i5
a011a5b8:  fa 20 40 00  st  %i5, [ %g1 ]
a011a5bc:  f8 0b 00 00  ldub  [ %o4 ], %i4
a011a5c0:  80 8f 20 01  btst  1, %i4
a011a5c4:  02 80 00 39  be  0xa011a6a8
a011a5c8:  b8 06 80 1a  add  %i2, %i2, %i4
a011a5cc:  fa 16 c0 1c  lduh  [ %i3 + %i4 ], %i5
a011a5d0:  b6 07 60 aa  add  %i5, 0xaa, %i3
a011a5d4:  83 2e e0 02  sll  %i3, 2, %g1
a011a5d8:  ba 10 40 19  or  %g1, %i1, %i5
a011a5dc:  f2 07 40 00  ld  [ %i5 ], %i1
a011a5e0:  b0 16 7f 80  or  %i1, -128, %i0
a011a5e4:  82 0e 20 ff  and  %i0, 0xff, %g1
a011a5e8:  c2 27 40 00  st  %g1, [ %i5 ]
a011a5ec:  f2 0b 00 00  ldub  [ %o4 ], %i1
a011a5f0:  80 8e 60 02  btst  2, %i1
a011a5f4:  02 80 00 39  be  0xa011a6d8
a011a5f8:  b8 13 e2 a8  or  %o7, 0x2a8, %i4
a011a5fc:  b0 06 80 1a  add  %i2, %i2, %i0
a011a600:  b8 13 e2 a8  or  %o7, 0x2a8, %i4
a011a604:  f2 17 00 18  lduh  [ %i4 + %i0 ], %i1
a011a608:  ba 06 60 aa  add  %i1, 0xaa, %i5
a011a60c:  83 2f 60 02  sll  %i5, 2, %g1
a011a610:  37 33 c0 00  sethi  %hi(0xcf000000), %i3
a011a614:  ba 10 40 1b  or  %g1, %i3, %i5
a011a618:  f0 07 40 00  ld  [ %i5 ], %i0
a011a61c:  b4 16 20 01  or  %i0, 1, %i2
a011a620:  82 0e a0 ff  and  %i2, 0xff, %g1
a011a624:  c2 27 40 00  st  %g1, [ %i5 ]
a011a628:  f4 0b 00 00  ldub  [ %o4 ], %i2
a011a62c:  39 2a 00 9e  sethi  %hi(0xa8027800), %i4
a011a630:  80 8e a0 04  btst  4, %i2
a011a634:  02 80 00 37  be  0xa011a710
a011a638:  ba 0b 60 ff  and  %o5, 0xff, %i5
a011a63c:  82 07 40 1d  add  %i5, %i5, %g1
a011a640:  b8 17 22 a8  or  %i4, 0x2a8, %i4
a011a644:  f4 17 00 01  lduh  [ %i4 + %g1 ], %i2
a011a648:  b0 06 a0 aa  add  %i2, 0xaa, %i0
a011a64c:  bb 2e 20 02  sll  %i0, 2, %i5
a011a650:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011a654:  ba 17 40 19  or  %i5, %i1, %i5
a011a658:  f6 07 40 00  ld  [ %i5 ], %i3
a011a65c:  82 16 e0 02  or  %i3, 2, %g1
a011a660:  82 08 60 ff  and  %g1, 0xff, %g1
a011a664:  c2 27 40 00  st  %g1, [ %i5 ]
a011a668:  f6 0b 00 00  ldub  [ %o4 ], %i3
a011a66c:  39 2a 00 9e  sethi  %hi(0xa8027800), %i4
a011a670:  80 8e e0 08  btst  8, %i3
a011a674:  02 80 00 36  be  0xa011a74c
a011a678:  ba 0b 60 ff  and  %o5, 0xff, %i5
a011a67c:  b2 07 40 1d  add  %i5, %i5, %i1
a011a680:  b8 17 22 a8  or  %i4, 0x2a8, %i4
a011a684:  f6 17 00 19  lduh  [ %i4 + %i1 ], %i3
a011a688:  82 06 e0 cf  add  %i3, 0xcf, %g1
a011a68c:  bb 28 60 02  sll  %g1, 2, %i5
a011a690:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011a694:  ba 17 40 1a  or  %i5, %i2, %i5
a011a698:  f0 07 40 00  ld  [ %i5 ], %i0
a011a69c:  b2 16 20 04  or  %i0, 4, %i1
a011a6a0:  10 80 00 34  b  0xa011a770
a011a6a4:  82 0e 60 ff  and  %i1, 0xff, %g1
a011a6a8:  fa 16 c0 1c  lduh  [ %i3 + %i4 ], %i5
a011a6ac:  b6 07 60 aa  add  %i5, 0xaa, %i3
a011a6b0:  83 2e e0 02  sll  %i3, 2, %g1
a011a6b4:  ba 10 40 19  or  %g1, %i1, %i5
a011a6b8:  f0 07 40 00  ld  [ %i5 ], %i0
a011a6bc:  82 0e 20 7f  and  %i0, 0x7f, %g1
a011a6c0:  c2 27 40 00  st  %g1, [ %i5 ]
a011a6c4:  f2 0b 00 00  ldub  [ %o4 ], %i1
a011a6c8:  80 8e 60 02  btst  2, %i1
a011a6cc:  12 bf ff cd  bne  0xa011a600
a011a6d0:  b0 06 80 1a  add  %i2, %i2, %i0
a011a6d4:  b8 13 e2 a8  or  %o7, 0x2a8, %i4
a011a6d8:  b0 06 80 1a  add  %i2, %i2, %i0
a011a6dc:  f2 17 00 18  lduh  [ %i4 + %i0 ], %i1
a011a6e0:  ba 06 60 aa  add  %i1, 0xaa, %i5
a011a6e4:  83 2f 60 02  sll  %i5, 2, %g1
a011a6e8:  37 33 c0 00  sethi  %hi(0xcf000000), %i3
a011a6ec:  ba 10 40 1b  or  %g1, %i3, %i5
a011a6f0:  f4 07 40 00  ld  [ %i5 ], %i2
a011a6f4:  82 0e a0 fe  and  %i2, 0xfe, %g1
a011a6f8:  c2 27 40 00  st  %g1, [ %i5 ]
a011a6fc:  f4 0b 00 00  ldub  [ %o4 ], %i2
a011a700:  39 2a 00 9e  sethi  %hi(0xa8027800), %i4
a011a704:  80 8e a0 04  btst  4, %i2
a011a708:  12 bf ff cd  bne  0xa011a63c
a011a70c:  ba 0b 60 ff  and  %o5, 0xff, %i5
a011a710:  82 07 40 1d  add  %i5, %i5, %g1
a011a714:  b8 17 22 a8  or  %i4, 0x2a8, %i4
a011a718:  f4 17 00 01  lduh  [ %i4 + %g1 ], %i2
a011a71c:  b0 06 a0 aa  add  %i2, 0xaa, %i0
a011a720:  bb 2e 20 02  sll  %i0, 2, %i5
a011a724:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011a728:  ba 17 40 19  or  %i5, %i1, %i5
a011a72c:  f6 07 40 00  ld  [ %i5 ], %i3
a011a730:  82 0e e0 fd  and  %i3, 0xfd, %g1
a011a734:  c2 27 40 00  st  %g1, [ %i5 ]
a011a738:  f6 0b 00 00  ldub  [ %o4 ], %i3
a011a73c:  39 2a 00 9e  sethi  %hi(0xa8027800), %i4
a011a740:  80 8e e0 08  btst  8, %i3
a011a744:  12 bf ff ce  bne  0xa011a67c
a011a748:  ba 0b 60 ff  and  %o5, 0xff, %i5
a011a74c:  b2 07 40 1d  add  %i5, %i5, %i1
a011a750:  b8 17 22 a8  or  %i4, 0x2a8, %i4
a011a754:  f6 17 00 19  lduh  [ %i4 + %i1 ], %i3
a011a758:  82 06 e0 cf  add  %i3, 0xcf, %g1
a011a75c:  bb 28 60 02  sll  %g1, 2, %i5
a011a760:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011a764:  ba 17 40 1a  or  %i5, %i2, %i5
a011a768:  f0 07 40 00  ld  [ %i5 ], %i0
a011a76c:  82 0e 20 fb  and  %i0, 0xfb, %g1
a011a770:  c2 27 40 00  st  %g1, [ %i5 ]
a011a774:  ba 0b 60 ff  and  %o5, 0xff, %i5
a011a778:  1f 2a 00 9e  sethi  %hi(0xa8027800), %o7
a011a77c:  9e 13 e2 a8  or  %o7, 0x2a8, %o7	! 0xa8027aa8
a011a780:  b8 07 40 1d  add  %i5, %i5, %i4
a011a784:  f2 13 c0 1c  lduh  [ %o7 + %i4 ], %i1
a011a788:  b0 06 60 aa  add  %i1, 0xaa, %i0
a011a78c:  f6 0b 20 02  ldub  [ %o4 + 2 ], %i3
a011a790:  80 a7 60 02  cmp  %i5, 2
a011a794:  b5 2e 20 02  sll  %i0, 2, %i2
a011a798:  31 33 c0 00  sethi  %hi(0xcf000000), %i0
a011a79c:  82 60 20 00  subx  %g0, 0, %g1
a011a7a0:  b2 0b 60 ff  and  %o5, 0xff, %i1
a011a7a4:  b8 0e e0 30  and  %i3, 0x30, %i4
a011a7a8:  b4 16 80 18  or  %i2, %i0, %i2
a011a7ac:  80 a6 60 02  cmp  %i1, 2
a011a7b0:  b6 07 00 1c  add  %i4, %i4, %i3
a011a7b4:  ba 08 40 0d  and  %g1, %o5, %i5
a011a7b8:  f8 06 80 00  ld  [ %i2 ], %i4
a011a7bc:  82 60 20 00  subx  %g0, 0, %g1
a011a7c0:  ba 0f 60 ff  and  %i5, 0xff, %i5
a011a7c4:  b8 17 00 1b  or  %i4, %i3, %i4
a011a7c8:  80 a6 60 02  cmp  %i1, 2
a011a7cc:  ba 07 40 1d  add  %i5, %i5, %i5
a011a7d0:  b2 0f 20 ff  and  %i4, 0xff, %i1
a011a7d4:  f6 13 c0 1d  lduh  [ %o7 + %i5 ], %i3
a011a7d8:  82 08 40 0d  and  %g1, %o5, %g1
a011a7dc:  f2 26 80 00  st  %i1, [ %i2 ]
a011a7e0:  ba 60 20 00  subx  %g0, 0, %i5
a011a7e4:  b8 06 e0 ad  add  %i3, 0xad, %i4
a011a7e8:  82 08 60 ff  and  %g1, 0xff, %g1
a011a7ec:  b2 0f 40 0d  and  %i5, %o5, %i1
a011a7f0:  82 00 40 01  add  %g1, %g1, %g1
a011a7f4:  b7 2f 20 02  sll  %i4, 2, %i3
a011a7f8:  f4 0b 20 02  ldub  [ %o4 + 2 ], %i2
a011a7fc:  f8 13 c0 01  lduh  [ %o7 + %g1 ], %i4
a011a800:  ba 0e 60 ff  and  %i1, 0xff, %i5
a011a804:  b2 0e a0 07  and  %i2, 7, %i1
a011a808:  82 07 20 ae  add  %i4, 0xae, %g1
a011a80c:  ba 07 40 1d  add  %i5, %i5, %i5
a011a810:  b6 16 c0 18  or  %i3, %i0, %i3
a011a814:  f4 13 c0 1d  lduh  [ %o7 + %i5 ], %i2
a011a818:  b9 28 60 02  sll  %g1, 2, %i4
a011a81c:  f2 26 c0 00  st  %i1, [ %i3 ]
a011a820:  82 06 a0 af  add  %i2, 0xaf, %g1
a011a824:  b6 17 00 18  or  %i4, %i0, %i3
a011a828:  f2 0b 20 03  ldub  [ %o4 + 3 ], %i1
a011a82c:  bb 28 60 02  sll  %g1, 2, %i5
a011a830:  f2 26 c0 00  st  %i1, [ %i3 ]
a011a834:  b4 17 40 18  or  %i5, %i0, %i2
a011a838:  f0 0b 20 04  ldub  [ %o4 + 4 ], %i0
a011a83c:  f0 26 80 00  st  %i0, [ %i2 ]
a011a840:  81 c7 e0 08  ret
a011a844:  81 e8 00 00  restore
