# leon2m FUN_a01405d0 0xa01405d0-0xa0140a0c (1084 bytes)
a01405d0:  9d e3 bf 90  save  %sp, -112, %sp
a01405d4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01405d8:  21 00 06 9a  sethi  %hi(0x1a6800), %l0
a01405dc:  92 14 21 fe  or  %l0, 0x1fe, %o1	! 0x1a69fe
a01405e0:  96 5e 20 26  smul  %i0, 0x26, %o3
a01405e4:  c2 4a 40 0b  ldsb  [ %o1 + %o3 ], %g1
a01405e8:  80 a0 60 00  cmp  %g1, 0
a01405ec:  16 80 01 06  bge  0xa0140a04
a01405f0:  c2 0a 40 0b  ldub  [ %o1 + %o3 ], %g1
a01405f4:  94 08 60 ff  and  %g1, 0xff, %o2
a01405f8:  a5 2a a0 03  sll  %o2, 3, %l2
a01405fc:  a2 04 80 0a  add  %l2, %o2, %l1
a0140600:  2d 00 06 9a  sethi  %hi(0x1a6800), %l6
a0140604:  9f 2c 60 02  sll  %l1, 2, %o7
a0140608:  9a 15 a2 24  or  %l6, 0x224, %o5
a014060c:  90 03 c0 0d  add  %o7, %o5, %o0
a0140610:  d8 0a 20 02  ldub  [ %o0 + 2 ], %o4
a0140614:  80 a3 20 01  cmp  %o4, 1
a0140618:  02 80 00 eb  be  0xa01409c4
a014061c:  a8 02 80 0a  add  %o2, %o2, %l4
a0140620:  ae 05 00 0a  add  %l4, %o2, %l7
a0140624:  29 2a 00 b2  sethi  %hi(0xa802c800), %l4
a0140628:  ab 2d e0 02  sll  %l7, 2, %l5
a014062c:  a6 15 23 dc  or  %l4, 0x3dc, %l3
a0140630:  94 05 40 13  add  %l5, %l3, %o2
a0140634:  de 0a a0 08  ldub  [ %o2 + 8 ], %o7
a0140638:  90 0b e0 ff  and  %o7, 0xff, %o0
a014063c:  80 a2 20 ff  cmp  %o0, 0xff
a0140640:  02 80 00 c9  be  0xa0140964
a0140644:  ae 02 20 03  add  %o0, 3, %l7
a0140648:  da 0a a0 09  ldub  [ %o2 + 9 ], %o5
a014064c:  a3 3d e0 1f  sra  %l7, 0x1f, %l1
a0140650:  81 84 60 00  mov  %l1, %y
a0140654:  01 00 00 00  nop
a0140658:  01 00 00 00  nop
a014065c:  01 00 00 00  nop
a0140660:  98 7d c0 0d  sdiv  %l7, %o5, %o4
a0140664:  aa 02 c0 09  add  %o3, %o1, %l5
a0140668:  82 5b 00 0d  smul  %o4, %o5, %g1
a014066c:  d6 0d 60 04  ldub  [ %l5 + 4 ], %o3
a0140670:  a6 10 20 10  mov  0x10, %l3
a0140674:  98 25 c0 01  sub  %l7, %g1, %o4
a0140678:  a3 3c e0 1f  sra  %l3, 0x1f, %l1
a014067c:  81 84 60 00  mov  %l1, %y
a0140680:  01 00 00 00  nop
a0140684:  01 00 00 00  nop
a0140688:  01 00 00 00  nop
a014068c:  92 7c c0 0b  sdiv  %l3, %o3, %o1
a0140690:  96 0b 20 ff  and  %o4, 0xff, %o3
a0140694:  9b 3a e0 1f  sra  %o3, 0x1f, %o5
a0140698:  81 83 60 00  mov  %o5, %y
a014069c:  01 00 00 00  nop
a01406a0:  01 00 00 00  nop
a01406a4:  01 00 00 00  nop
a01406a8:  a4 7a c0 09  sdiv  %o3, %o1, %l2
a01406ac:  a2 5c 80 09  smul  %l2, %o1, %l1
a01406b0:  82 22 c0 11  sub  %o3, %l1, %g1
a01406b4:  d8 2a a0 08  stb  %o4, [ %o2 + 8 ]
a01406b8:  80 a0 00 01  cmp  %g0, %g1
a01406bc:  9a 60 3f ff  subx  %g0, -1, %o5
a01406c0:  94 10 20 01  mov  1, %o2
a01406c4:  d4 2f bf f0  stb  %o2, [ %fp + -16 ]
a01406c8:  80 a3 60 00  cmp  %o5, 0
a01406cc:  de 2f bf f3  stb  %o7, [ %fp + -13 ]
a01406d0:  02 80 00 05  be  0xa01406e4
a01406d4:  da 2f bf f2  stb  %o5, [ %fp + -14 ]
a01406d8:  80 a2 c0 08  cmp  %o3, %o0
a01406dc:  0a 80 00 b5  bcs  0xa01409b0
a01406e0:  94 02 c0 09  add  %o3, %o1, %o2
a01406e4:  92 10 20 01  mov  1, %o1
a01406e8:  90 07 bf f0  add  %fp, -16, %o0
a01406ec:  d2 2a 20 01  stb  %o1, [ %o0 + 1 ]
a01406f0:  92 14 21 fe  or  %l0, 0x1fe, %o1
a01406f4:  96 5e 20 26  smul  %i0, 0x26, %o3
a01406f8:  d4 0a 40 0b  ldub  [ %o1 + %o3 ], %o2
a01406fc:  99 2a a0 03  sll  %o2, 3, %o4
a0140700:  82 03 00 0a  add  %o4, %o2, %g1
a0140704:  ab 28 60 02  sll  %g1, 2, %l5
a0140708:  ae 15 a2 24  or  %l6, 0x224, %l7
a014070c:  a6 05 40 17  add  %l5, %l7, %l3
a0140710:  e4 0c e0 02  ldub  [ %l3 + 2 ], %l2
a0140714:  80 a4 a0 00  cmp  %l2, 0
a0140718:  12 80 00 80  bne  0xa0140918
a014071c:  82 02 80 0a  add  %o2, %o2, %g1
a0140720:  96 0b e0 ff  and  %o7, 0xff, %o3
a0140724:  80 a2 e0 ff  cmp  %o3, 0xff
a0140728:  02 80 00 b0  be  0xa01409e8
a014072c:  82 10 00 0f  mov  %o7, %g1
a0140730:  92 08 60 ff  and  %g1, 0xff, %o1
a0140734:  80 a2 60 ff  cmp  %o1, 0xff
a0140738:  02 80 00 0e  be  0xa0140770
a014073c:  98 10 3f ff  mov  -1, %o4
a0140740:  9a 14 21 fe  or  %l0, 0x1fe, %o5
a0140744:  90 5e 20 26  smul  %i0, 0x26, %o0
a0140748:  9e 02 80 0a  add  %o2, %o2, %o7
a014074c:  82 02 00 0d  add  %o0, %o5, %g1
a0140750:  98 03 c0 0a  add  %o7, %o2, %o4
a0140754:  d6 08 60 04  ldub  [ %g1 + 4 ], %o3
a0140758:  a7 2b 20 02  sll  %o4, 2, %l3
a014075c:  af 2a e0 08  sll  %o3, 8, %l7
a0140760:  aa 15 23 dc  or  %l4, 0x3dc, %l5
a0140764:  a4 5a 40 17  smul  %o1, %l7, %l2
a0140768:  d4 15 40 13  lduh  [ %l5 + %l3 ], %o2
a014076c:  98 04 80 0a  add  %l2, %o2, %o4
a0140770:  92 14 21 fe  or  %l0, 0x1fe, %o1
a0140774:  96 5e 20 26  smul  %i0, 0x26, %o3
a0140778:  d4 0a 40 0b  ldub  [ %o1 + %o3 ], %o2
a014077c:  ab 2a a0 03  sll  %o2, 3, %l5
a0140780:  a6 05 40 0a  add  %l5, %o2, %l3
a0140784:  a5 2c e0 02  sll  %l3, 2, %l2
a0140788:  9a 15 a2 24  or  %l6, 0x224, %o5
a014078c:  a2 04 80 0d  add  %l2, %o5, %l1
a0140790:  9f 2b 20 10  sll  %o4, 0x10, %o7
a0140794:  d0 0c 60 02  ldub  [ %l1 + 2 ], %o0
a0140798:  80 a2 20 00  cmp  %o0, 0
a014079c:  12 80 00 54  bne  0xa01408ec
a01407a0:  af 33 e0 10  srl  %o7, 0x10, %l7
a01407a4:  9e 02 80 0a  add  %o2, %o2, %o7
a01407a8:  98 03 c0 0a  add  %o7, %o2, %o4
a01407ac:  95 2b 20 02  sll  %o4, 2, %o2
a01407b0:  90 15 23 dc  or  %l4, 0x3dc, %o0
a01407b4:  82 02 80 08  add  %o2, %o0, %g1
a01407b8:  d8 08 60 08  ldub  [ %g1 + 8 ], %o4
a01407bc:  80 a3 20 ff  cmp  %o4, 0xff
a01407c0:  02 80 00 08  be  0xa01407e0
a01407c4:  82 10 3f ff  mov  -1, %g1
a01407c8:  9a 02 c0 09  add  %o3, %o1, %o5
a01407cc:  e4 0b 60 04  ldub  [ %o5 + 4 ], %l2
a01407d0:  a3 2c a0 08  sll  %l2, 8, %l1
a01407d4:  92 5b 00 11  smul  %o4, %l1, %o1
a01407d8:  d6 12 00 0a  lduh  [ %o0 + %o2 ], %o3
a01407dc:  82 02 40 0b  add  %o1, %o3, %g1
a01407e0:  a4 14 21 fe  or  %l0, 0x1fe, %l2
a01407e4:  b0 5e 20 26  smul  %i0, 0x26, %i0
a01407e8:  97 28 60 10  sll  %g1, 0x10, %o3
a01407ec:  a6 06 00 12  add  %i0, %l2, %l3
a01407f0:  e2 0c e0 04  ldub  [ %l3 + 4 ], %l1
a01407f4:  7f ff 91 b7  call  0xa0124ed0
a01407f8:  ab 32 e0 10  srl  %o3, 0x10, %l5
a01407fc:  e0 0f bf f2  ldub  [ %fp + -14 ], %l0
a0140800:  80 a4 20 00  cmp  %l0, 0
a0140804:  02 80 00 19  be  0xa0140868
a0140808:  a0 0c 60 ff  and  %l1, 0xff, %l0
a014080c:  f0 0c 80 18  ldub  [ %l2 + %i0 ], %i0
a0140810:  83 2e 20 03  sll  %i0, 3, %g1
a0140814:  90 00 40 18  add  %g1, %i0, %o0
a0140818:  94 15 a2 24  or  %l6, 0x224, %o2
a014081c:  9b 2a 20 02  sll  %o0, 2, %o5
a0140820:  92 03 40 0a  add  %o5, %o2, %o1
a0140824:  ec 0a 60 03  ldub  [ %o1 + 3 ], %l6
a0140828:  80 a5 a0 00  cmp  %l6, 0
a014082c:  02 80 00 56  be  0xa0140984
a0140830:  92 06 00 18  add  %i0, %i0, %o1
a0140834:  a4 06 00 18  add  %i0, %i0, %l2
a0140838:  9e 04 80 18  add  %l2, %i0, %o7
a014083c:  83 2b e0 02  sll  %o7, 2, %g1
a0140840:  b0 15 23 dc  or  %l4, 0x3dc, %i0
a0140844:  d0 0c e0 01  ldub  [ %l3 + 1 ], %o0
a0140848:  d4 16 00 01  lduh  [ %i0 + %g1 ], %o2
a014084c:  9b 2a 20 0b  sll  %o0, 0xb, %o5
a0140850:  a0 03 40 0a  add  %o5, %o2, %l0
a0140854:  82 0c 30 00  and  %l0, -4096, %g1
a0140858:  a0 0c 60 ff  and  %l1, 0xff, %l0
a014085c:  a9 28 60 10  sll  %g1, 0x10, %l4
a0140860:  7f ff cf 01  call  0xa0134464
a0140864:  91 35 20 10  srl  %l4, 0x10, %o0
a0140868:  e6 0f bf f0  ldub  [ %fp + -16 ], %l3
a014086c:  80 a4 e0 00  cmp  %l3, 0
a0140870:  12 80 00 34  bne  0xa0140940
a0140874:  97 2c 20 08  sll  %l0, 8, %o3
a0140878:  93 2d 60 10  sll  %l5, 0x10, %o1
a014087c:  a3 32 60 10  srl  %o1, 0x10, %l1
a0140880:  90 10 00 11  mov  %l1, %o0
a0140884:  7f ff ce e9  call  0xa0134428
a0140888:  92 10 00 10  mov  %l0, %o1
a014088c:  ea 0f bf f1  ldub  [ %fp + -15 ], %l5
a0140890:  80 a5 60 00  cmp  %l5, 0
a0140894:  12 80 00 05  bne  0xa01408a8
a0140898:  b1 2c 20 08  sll  %l0, 8, %i0
a014089c:  7f ff 91 86  call  0xa0124eb4
a01408a0:  01 00 00 00  nop
a01408a4:  30 80 00 58  b,a   0xa0140a04
a01408a8:  82 06 3f ff  add  %i0, -1, %g1
a01408ac:  91 28 60 10  sll  %g1, 0x10, %o0
a01408b0:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a01408b4:  94 12 a3 d8  or  %o2, 0x3d8, %o2	! 0xa802cbd8
a01408b8:  91 32 20 10  srl  %o0, 0x10, %o0
a01408bc:  7f ff d3 f4  call  0xa013588c
a01408c0:  92 10 20 01  mov  1, %o1
a01408c4:  9b 2d e0 10  sll  %l7, 0x10, %o5
a01408c8:  91 33 60 10  srl  %o5, 0x10, %o0
a01408cc:  7f ff ce d7  call  0xa0134428
a01408d0:  92 10 00 10  mov  %l0, %o1
a01408d4:  90 10 00 11  mov  %l1, %o0
a01408d8:  7f ff ce af  call  0xa0134394
a01408dc:  92 10 00 10  mov  %l0, %o1
a01408e0:  7f ff 91 75  call  0xa0124eb4
a01408e4:  01 00 00 00  nop
a01408e8:  30 80 00 47  b,a   0xa0140a04
a01408ec:  a4 02 80 0a  add  %o2, %o2, %l2
a01408f0:  a2 04 80 0a  add  %l2, %o2, %l1
a01408f4:  9e 02 c0 09  add  %o3, %o1, %o7
a01408f8:  83 2c 60 02  sll  %l1, 2, %g1
a01408fc:  ea 0b e0 01  ldub  [ %o7 + 1 ], %l5
a0140900:  98 15 23 dc  or  %l4, 0x3dc, %o4
a0140904:  e6 13 00 01  lduh  [ %o4 + %g1 ], %l3
a0140908:  91 2d 60 0b  sll  %l5, 0xb, %o0
a014090c:  94 02 00 13  add  %o0, %l3, %o2
a0140910:  10 bf ff b4  b  0xa01407e0
a0140914:  82 0a b8 00  and  %o2, -2048, %g1
a0140918:  98 00 40 0a  add  %g1, %o2, %o4
a014091c:  ae 02 c0 09  add  %o3, %o1, %l7
a0140920:  a7 2b 20 02  sll  %o4, 2, %l3
a0140924:  e4 0d e0 01  ldub  [ %l7 + 1 ], %l2
a0140928:  aa 15 23 dc  or  %l4, 0x3dc, %l5
a014092c:  d4 15 40 13  lduh  [ %l5 + %l3 ], %o2
a0140930:  a3 2c a0 0b  sll  %l2, 0xb, %l1
a0140934:  92 04 40 0a  add  %l1, %o2, %o1
a0140938:  10 bf ff 8e  b  0xa0140770
a014093c:  98 0a 78 00  and  %o1, -2048, %o4
a0140940:  ac 02 ff ff  add  %o3, -1, %l6
a0140944:  99 2d a0 10  sll  %l6, 0x10, %o4
a0140948:  23 2a 00 a9  sethi  %hi(0xa802a400), %l1
a014094c:  91 33 20 10  srl  %o4, 0x10, %o0
a0140950:  94 14 60 78  or  %l1, 0x78, %o2
a0140954:  7f ff d3 ce  call  0xa013588c
a0140958:  92 10 20 01  mov  1, %o1
a014095c:  10 bf ff c8  b  0xa014087c
a0140960:  93 2d 60 10  sll  %l5, 0x10, %o1
a0140964:  c0 2a a0 08  clrb  [ %o2 + 8 ]
a0140968:  9e 10 3f ff  mov  -1, %o7
a014096c:  a2 10 20 01  mov  1, %l1
a0140970:  e2 2f bf f0  stb  %l1, [ %fp + -16 ]
a0140974:  de 2f bf f3  stb  %o7, [ %fp + -13 ]
a0140978:  c0 2f bf f2  clrb  [ %fp + -14 ]
a014097c:  10 bf ff 5d  b  0xa01406f0
a0140980:  c0 2f bf f1  clrb  [ %fp + -15 ]
a0140984:  96 02 40 18  add  %o1, %i0, %o3
a0140988:  a2 15 23 dc  or  %l4, 0x3dc, %l1
a014098c:  9f 2a e0 02  sll  %o3, 2, %o7
a0140990:  ac 03 c0 11  add  %o7, %l1, %l6
a0140994:  e4 0d a0 08  ldub  [ %l6 + 8 ], %l2
a0140998:  99 2c 20 08  sll  %l0, 8, %o4
a014099c:  a8 5c 80 0c  smul  %l2, %o4, %l4
a01409a0:  e6 14 40 0f  lduh  [ %l1 + %o7 ], %l3
a01409a4:  b0 05 00 13  add  %l4, %l3, %i0
a01409a8:  10 bf ff ad  b  0xa014085c
a01409ac:  82 0e 30 00  and  %i0, -4096, %g1
a01409b0:  80 a2 00 0a  cmp  %o0, %o2
a01409b4:  16 bf ff 4d  bge  0xa01406e8
a01409b8:  92 10 20 01  mov  1, %o1
a01409bc:  10 bf ff 4d  b  0xa01406f0
a01409c0:  c0 2f bf f1  clrb  [ %fp + -15 ]
a01409c4:  7f ff 91 43  call  0xa0124ed0
a01409c8:  01 00 00 00  nop
a01409cc:  13 2a 00 a9  sethi  %hi(0xa802a400), %o1
a01409d0:  d0 12 60 7a  lduh  [ %o1 + 0x7a ], %o0	! 0xa802a47a
a01409d4:  7f ff ce 95  call  0xa0134428
a01409d8:  92 10 20 08  mov  8, %o1
a01409dc:  7f ff 91 36  call  0xa0124eb4
a01409e0:  01 00 00 00  nop
a01409e4:  30 80 00 08  b,a   0xa0140a04
a01409e8:  a2 02 80 0a  add  %o2, %o2, %l1
a01409ec:  92 04 40 0a  add  %l1, %o2, %o1
a01409f0:  91 2a 60 02  sll  %o1, 2, %o0
a01409f4:  9a 15 23 dc  or  %l4, 0x3dc, %o5
a01409f8:  9e 02 00 0d  add  %o0, %o5, %o7
a01409fc:  10 bf ff 4d  b  0xa0140730
a0140a00:  c2 0b e0 08  ldub  [ %o7 + 8 ], %g1
a0140a04:  81 c7 e0 08  ret
a0140a08:  81 e8 00 00  restore
