# leon2m FUN_a00b65e4 0xa00b65e4-0xa00b6994 (944 bytes)
a00b65e4:  9d e3 bf 98  save  %sp, -104, %sp
a00b65e8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b65ec:  80 a6 20 00  cmp  %i0, 0
a00b65f0:  12 80 00 2f  bne  0xa00b66ac
a00b65f4:  80 a6 20 01  cmp  %i0, 1
a00b65f8:  80 8e 60 ff  btst  0xff, %i1
a00b65fc:  12 80 00 62  bne  0xa00b6784
a00b6600:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00b6604:  82 13 e2 90  or  %o7, 0x290, %g1	! 0xa802d290
a00b6608:  d6 08 61 a3  ldub  [ %g1 + 0x1a3 ], %o3
a00b660c:  90 02 c0 01  add  %o3, %g1, %o0
a00b6610:  15 33 33 33  sethi  %hi(0xcccccc00), %o2
a00b6614:  b2 12 a0 cd  or  %o2, 0xcd, %i1	! 0xcccccccd
a00b6618:  d2 0a 21 98  ldub  [ %o0 + 0x198 ], %o1
a00b661c:  80 52 40 19  umul  %o1, %i1, %g0
a00b6620:  b1 40 00 00  rd  %y, %i0
a00b6624:  97 36 20 03  srl  %i0, 3, %o3
a00b6628:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00b662c:  94 03 60 09  add  %o5, 9, %o2
a00b6630:  31 19 99 99  sethi  %hi(0x66666400), %i0
a00b6634:  9a 16 22 67  or  %i0, 0x267, %o5	! 0x66666667
a00b6638:  80 5a 80 0d  smul  %o2, %o5, %g0
a00b663c:  83 40 00 00  rd  %y, %g1
a00b6640:  99 38 60 02  sra  %g1, 2, %o4
a00b6644:  b3 2b 20 02  sll  %o4, 2, %i1
a00b6648:  b0 06 40 0c  add  %i1, %o4, %i0
a00b664c:  9a 06 00 18  add  %i0, %i0, %o5
a00b6650:  83 2a e0 02  sll  %o3, 2, %g1
a00b6654:  98 00 40 0b  add  %g1, %o3, %o4
a00b6658:  94 22 80 0d  sub  %o2, %o5, %o2
a00b665c:  97 2a a0 02  sll  %o2, 2, %o3
a00b6660:  b2 03 00 0c  add  %o4, %o4, %i1
a00b6664:  b0 02 c0 0a  add  %o3, %o2, %i0
a00b6668:  92 22 40 19  sub  %o1, %i1, %o1
a00b666c:  9a 06 00 18  add  %i0, %i0, %o5
a00b6670:  98 03 40 09  add  %o5, %o1, %o4
a00b6674:  d8 2a 21 98  stb  %o4, [ %o0 + 0x198 ]
a00b6678:  82 13 e2 90  or  %o7, 0x290, %g1
a00b667c:  d2 08 61 a3  ldub  [ %g1 + 0x1a3 ], %o1
a00b6680:  9a 02 40 01  add  %o1, %g1, %o5
a00b6684:  d0 0b 61 98  ldub  [ %o5 + 0x198 ], %o0
a00b6688:  80 a2 20 00  cmp  %o0, 0
a00b668c:  12 80 00 ba  bne  0xa00b6974
a00b6690:  01 00 00 00  nop
a00b6694:  d4 0b 61 9c  ldub  [ %o5 + 0x19c ], %o2
a00b6698:  80 a2 a0 00  cmp  %o2, 0
a00b669c:  12 80 00 b6  bne  0xa00b6974
a00b66a0:  82 10 20 01  mov  1, %g1
a00b66a4:  10 80 00 b4  b  0xa00b6974
a00b66a8:  c2 2b 61 9c  stb  %g1, [ %o5 + 0x19c ]
a00b66ac:  02 80 00 42  be  0xa00b67b4
a00b66b0:  80 a6 20 02  cmp  %i0, 2
a00b66b4:  02 80 00 63  be  0xa00b6840
a00b66b8:  80 a6 20 03  cmp  %i0, 3
a00b66bc:  12 80 00 ae  bne  0xa00b6974
a00b66c0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00b66c4:  80 a6 60 00  cmp  %i1, 0
a00b66c8:  12 80 00 9b  bne  0xa00b6934
a00b66cc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00b66d0:  94 12 22 90  or  %o0, 0x290, %o2	! 0xa802d290
a00b66d4:  d2 0a a1 a3  ldub  [ %o2 + 0x1a3 ], %o1
a00b66d8:  1f 33 33 33  sethi  %hi(0xcccccc00), %o7
a00b66dc:  92 02 40 0a  add  %o1, %o2, %o1
a00b66e0:  d4 0a 61 9c  ldub  [ %o1 + 0x19c ], %o2
a00b66e4:  82 13 e0 cd  or  %o7, 0xcd, %g1
a00b66e8:  80 52 80 01  umul  %o2, %g1, %g0
a00b66ec:  97 40 00 00  rd  %y, %o3
a00b66f0:  97 32 e0 03  srl  %o3, 3, %o3
a00b66f4:  9b 2a e0 02  sll  %o3, 2, %o5
a00b66f8:  b0 03 40 0b  add  %o5, %o3, %i0
a00b66fc:  98 06 00 18  add  %i0, %i0, %o4
a00b6700:  9e 22 80 0c  sub  %o2, %o4, %o7
a00b6704:  82 0b e0 ff  and  %o7, 0xff, %g1
a00b6708:  94 00 60 09  add  %g1, 9, %o2
a00b670c:  1b 19 99 99  sethi  %hi(0x66666400), %o5
a00b6710:  b0 13 62 67  or  %o5, 0x267, %i0	! 0x66666667
a00b6714:  80 5a 80 18  smul  %o2, %i0, %g0
a00b6718:  99 40 00 00  rd  %y, %o4
a00b671c:  83 3b 20 02  sra  %o4, 2, %g1
a00b6720:  96 0a e0 ff  and  %o3, 0xff, %o3
a00b6724:  9f 28 60 02  sll  %g1, 2, %o7
a00b6728:  b0 03 c0 01  add  %o7, %g1, %i0
a00b672c:  9b 2a e0 02  sll  %o3, 2, %o5
a00b6730:  98 06 00 18  add  %i0, %i0, %o4
a00b6734:  9e 03 40 0b  add  %o5, %o3, %o7
a00b6738:  82 22 80 0c  sub  %o2, %o4, %g1
a00b673c:  96 03 c0 0f  add  %o7, %o7, %o3
a00b6740:  b0 12 22 90  or  %o0, 0x290, %i0
a00b6744:  9a 02 c0 01  add  %o3, %g1, %o5
a00b6748:  da 2a 61 9c  stb  %o5, [ %o1 + 0x19c ]
a00b674c:  d8 0e 21 a3  ldub  [ %i0 + 0x1a3 ], %o4
a00b6750:  9a 03 00 18  add  %o4, %i0, %o5
a00b6754:  d0 0b 61 98  ldub  [ %o5 + 0x198 ], %o0
a00b6758:  80 a2 20 00  cmp  %o0, 0
a00b675c:  12 80 00 86  bne  0xa00b6974
a00b6760:  01 00 00 00  nop
a00b6764:  d2 0b 61 9c  ldub  [ %o5 + 0x19c ], %o1
a00b6768:  80 a2 60 00  cmp  %o1, 0
a00b676c:  12 80 00 82  bne  0xa00b6974
a00b6770:  80 a6 60 00  cmp  %i1, 0
a00b6774:  02 bf ff cc  be  0xa00b66a4
a00b6778:  82 10 20 09  mov  9, %g1
a00b677c:  10 bf ff ca  b  0xa00b66a4
a00b6780:  82 10 20 01  mov  1, %g1
a00b6784:  92 13 e2 90  or  %o7, 0x290, %o1
a00b6788:  d0 0a 61 a3  ldub  [ %o1 + 0x1a3 ], %o0
a00b678c:  90 02 00 09  add  %o0, %o1, %o0
a00b6790:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a00b6794:  d2 0a 21 98  ldub  [ %o0 + 0x198 ], %o1
a00b6798:  82 13 20 cd  or  %o4, 0xcd, %g1
a00b679c:  80 52 40 01  umul  %o1, %g1, %g0
a00b67a0:  97 40 00 00  rd  %y, %o3
a00b67a4:  97 32 e0 03  srl  %o3, 3, %o3
a00b67a8:  94 0a e0 ff  and  %o3, 0xff, %o2
a00b67ac:  10 bf ff a1  b  0xa00b6630
a00b67b0:  94 02 a0 01  inc  %o2
a00b67b4:  80 8e 60 ff  btst  0xff, %i1
a00b67b8:  02 80 00 43  be  0xa00b68c4
a00b67bc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00b67c0:  94 12 22 90  or  %o0, 0x290, %o2	! 0xa802d290
a00b67c4:  d2 0a a1 a3  ldub  [ %o2 + 0x1a3 ], %o1
a00b67c8:  92 02 40 0a  add  %o1, %o2, %o1
a00b67cc:  1f 33 33 33  sethi  %hi(0xcccccc00), %o7
a00b67d0:  f2 0a 61 98  ldub  [ %o1 + 0x198 ], %i1
a00b67d4:  b0 13 e0 cd  or  %o7, 0xcd, %i0
a00b67d8:  80 56 40 18  umul  %i1, %i0, %g0
a00b67dc:  97 40 00 00  rd  %y, %o3
a00b67e0:  97 32 e0 03  srl  %o3, 3, %o3
a00b67e4:  9b 2a e0 02  sll  %o3, 2, %o5
a00b67e8:  82 03 40 0b  add  %o5, %o3, %g1
a00b67ec:  98 00 40 01  add  %g1, %g1, %o4
a00b67f0:  94 26 40 0c  sub  %i1, %o4, %o2
a00b67f4:  9e 0a a0 ff  and  %o2, 0xff, %o7
a00b67f8:  94 03 e0 01  add  %o7, 1, %o2
a00b67fc:  1b 19 99 99  sethi  %hi(0x66666400), %o5
a00b6800:  b2 13 62 67  or  %o5, 0x267, %i1	! 0x66666667
a00b6804:  80 5a 80 19  smul  %o2, %i1, %g0
a00b6808:  9f 40 00 00  rd  %y, %o7
a00b680c:  83 3b e0 02  sra  %o7, 2, %g1
a00b6810:  b0 0a e0 ff  and  %o3, 0xff, %i0
a00b6814:  99 28 60 02  sll  %g1, 2, %o4
a00b6818:  9b 2e 20 02  sll  %i0, 2, %o5
a00b681c:  b2 03 00 01  add  %o4, %g1, %i1
a00b6820:  9e 03 40 18  add  %o5, %i0, %o7
a00b6824:  96 06 40 19  add  %i1, %i1, %o3
a00b6828:  82 03 c0 0f  add  %o7, %o7, %g1
a00b682c:  b0 22 80 0b  sub  %o2, %o3, %i0
a00b6830:  9a 00 40 18  add  %g1, %i0, %o5
a00b6834:  da 2a 61 98  stb  %o5, [ %o1 + 0x198 ]
a00b6838:  10 bf ff 91  b  0xa00b667c
a00b683c:  82 12 22 90  or  %o0, 0x290, %g1
a00b6840:  80 8e 60 ff  btst  0xff, %i1
a00b6844:  02 80 00 30  be  0xa00b6904
a00b6848:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00b684c:  9e 12 22 90  or  %o0, 0x290, %o7	! 0xa802d290
a00b6850:  d4 0b e1 a3  ldub  [ %o7 + 0x1a3 ], %o2
a00b6854:  92 02 80 0f  add  %o2, %o7, %o1
a00b6858:  03 33 33 33  sethi  %hi(0xcccccc00), %g1
a00b685c:  98 10 60 cd  or  %g1, 0xcd, %o4	! 0xcccccccd
a00b6860:  d4 0a 61 9c  ldub  [ %o1 + 0x19c ], %o2
a00b6864:  80 52 80 0c  umul  %o2, %o4, %g0
a00b6868:  b1 40 00 00  rd  %y, %i0
a00b686c:  99 36 20 03  srl  %i0, 3, %o4
a00b6870:  96 0b 20 ff  and  %o4, 0xff, %o3
a00b6874:  96 02 e0 01  inc  %o3
a00b6878:  1f 0a aa aa  sethi  %hi(0x2aaaa800), %o7
a00b687c:  82 13 e2 ab  or  %o7, 0x2ab, %g1	! 0x2aaaaaab
a00b6880:  80 5a c0 01  smul  %o3, %g1, %g0
a00b6884:  9b 40 00 00  rd  %y, %o5
a00b6888:  b0 03 40 0d  add  %o5, %o5, %i0
a00b688c:  b2 06 00 0d  add  %i0, %o5, %i1
a00b6890:  9e 06 40 19  add  %i1, %i1, %o7
a00b6894:  83 2b 20 02  sll  %o4, 2, %g1
a00b6898:  96 22 c0 0f  sub  %o3, %o7, %o3
a00b689c:  b0 00 40 0c  add  %g1, %o4, %i0
a00b68a0:  99 2a e0 02  sll  %o3, 2, %o4
a00b68a4:  b2 03 00 0b  add  %o4, %o3, %i1
a00b68a8:  9a 06 00 18  add  %i0, %i0, %o5
a00b68ac:  94 22 80 0d  sub  %o2, %o5, %o2
a00b68b0:  9e 06 40 19  add  %i1, %i1, %o7
a00b68b4:  82 03 c0 0a  add  %o7, %o2, %g1
a00b68b8:  c2 2a 61 9c  stb  %g1, [ %o1 + 0x19c ]
a00b68bc:  10 bf ff 70  b  0xa00b667c
a00b68c0:  82 12 22 90  or  %o0, 0x290, %g1
a00b68c4:  98 12 22 90  or  %o0, 0x290, %o4
a00b68c8:  d2 0b 21 a3  ldub  [ %o4 + 0x1a3 ], %o1
a00b68cc:  92 02 40 0c  add  %o1, %o4, %o1
a00b68d0:  33 33 33 33  sethi  %hi(0xcccccc00), %i1
a00b68d4:  94 16 60 cd  or  %i1, 0xcd, %o2	! 0xcccccccd
a00b68d8:  da 0a 61 98  ldub  [ %o1 + 0x198 ], %o5
a00b68dc:  80 53 40 0a  umul  %o5, %o2, %g0
a00b68e0:  97 40 00 00  rd  %y, %o3
a00b68e4:  97 32 e0 03  srl  %o3, 3, %o3
a00b68e8:  9f 2a e0 02  sll  %o3, 2, %o7
a00b68ec:  b0 03 c0 0b  add  %o7, %o3, %i0
a00b68f0:  82 06 00 18  add  %i0, %i0, %g1
a00b68f4:  98 23 40 01  sub  %o5, %g1, %o4
a00b68f8:  b2 0b 20 ff  and  %o4, 0xff, %i1
a00b68fc:  10 bf ff c0  b  0xa00b67fc
a00b6900:  94 06 60 09  add  %i1, 9, %o2
a00b6904:  98 12 22 90  or  %o0, 0x290, %o4
a00b6908:  d2 0b 21 a3  ldub  [ %o4 + 0x1a3 ], %o1
a00b690c:  92 02 40 0c  add  %o1, %o4, %o1
a00b6910:  31 33 33 33  sethi  %hi(0xcccccc00), %i0
a00b6914:  96 16 20 cd  or  %i0, 0xcd, %o3	! 0xcccccccd
a00b6918:  d4 0a 61 9c  ldub  [ %o1 + 0x19c ], %o2
a00b691c:  80 52 80 0b  umul  %o2, %o3, %g0
a00b6920:  9b 40 00 00  rd  %y, %o5
a00b6924:  99 33 60 03  srl  %o5, 3, %o4
a00b6928:  b2 0b 20 ff  and  %o4, 0xff, %i1
a00b692c:  10 bf ff d3  b  0xa00b6878
a00b6930:  96 06 60 05  add  %i1, 5, %o3
a00b6934:  9a 12 22 90  or  %o0, 0x290, %o5
a00b6938:  d2 0b 61 a3  ldub  [ %o5 + 0x1a3 ], %o1
a00b693c:  31 33 33 33  sethi  %hi(0xcccccc00), %i0
a00b6940:  92 02 40 0d  add  %o1, %o5, %o1
a00b6944:  98 16 20 cd  or  %i0, 0xcd, %o4
a00b6948:  da 0a 61 9c  ldub  [ %o1 + 0x19c ], %o5
a00b694c:  80 53 40 0c  umul  %o5, %o4, %g0
a00b6950:  97 40 00 00  rd  %y, %o3
a00b6954:  97 32 e0 03  srl  %o3, 3, %o3
a00b6958:  95 2a e0 02  sll  %o3, 2, %o2
a00b695c:  9e 02 80 0b  add  %o2, %o3, %o7
a00b6960:  82 03 c0 0f  add  %o7, %o7, %g1
a00b6964:  b0 23 40 01  sub  %o5, %g1, %i0
a00b6968:  98 0e 20 ff  and  %i0, 0xff, %o4
a00b696c:  10 bf ff 68  b  0xa00b670c
a00b6970:  94 03 20 01  add  %o4, 1, %o2
a00b6974:  7f ff fe 47  call  0xa00b6290
a00b6978:  90 10 20 00  clr  %o0
a00b697c:  33 2a 00 ac  sethi  %hi(0xa802b000), %i1
a00b6980:  d0 0e 60 8e  ldub  [ %i1 + 0x8e ], %o0	! 0xa802b08e
a00b6984:  94 12 20 02  or  %o0, 2, %o2
a00b6988:  d4 2e 60 8e  stb  %o2, [ %i1 + 0x8e ]
a00b698c:  81 c7 e0 08  ret
a00b6990:  81 e8 00 00  restore
