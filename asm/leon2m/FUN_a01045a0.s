# leon2m FUN_a01045a0 0xa01045a0-0xa0104a34 (1172 bytes)
a01045a0:  9d e3 bf 98  save  %sp, -104, %sp
a01045a4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01045a8:  92 10 20 71  mov  0x71, %o1
a01045ac:  7f ff b8 13  call  0xa00f25f8
a01045b0:  90 10 00 18  mov  %i0, %o0
a01045b4:  37 2a 00 b5  sethi  %hi(0xa802d400), %i3
a01045b8:  da 06 e2 a4  ld  [ %i3 + 0x2a4 ], %o5	! 0xa802d6a4
a01045bc:  d8 13 60 08  lduh  [ %o5 + 8 ], %o4
a01045c0:  d2 13 60 0a  lduh  [ %o5 + 0xa ], %o1
a01045c4:  a6 10 00 08  mov  %o0, %l3
a01045c8:  90 5a 40 0c  smul  %o1, %o4, %o0
a01045cc:  af 32 20 03  srl  %o0, 3, %l7
a01045d0:  67 fe 22 f4  call  0x4008d1a0
a01045d4:  90 10 20 64  mov  0x64, %o0
a01045d8:  b5 2e a0 10  sll  %i2, 0x10, %i2
a01045dc:  03 00 0f ff  sethi  %hi(0x3ffc00), %g1
a01045e0:  b8 10 63 ff  or  %g1, 0x3ff, %i4	! 0x3fffff
a01045e4:  a4 10 20 00  clr  %l2
a01045e8:  a8 10 20 00  clr  %l4
a01045ec:  aa 10 20 00  clr  %l5
a01045f0:  ac 10 20 00  clr  %l6
a01045f4:  bb 36 a0 10  srl  %i2, 0x10, %i5
a01045f8:  94 10 20 06  mov  6, %o2
a01045fc:  90 10 00 18  mov  %i0, %o0
a0104600:  7f ff b7 26  call  0xa00f2298
a0104604:  92 10 20 88  mov  0x88, %o1
a0104608:  90 10 20 01  mov  1, %o0
a010460c:  40 00 75 70  call  0xa0121bcc
a0104610:  92 10 00 1d  mov  %i5, %o1
a0104614:  92 10 20 82  mov  0x82, %o1
a0104618:  7f ff b8 3c  call  0xa00f2708
a010461c:  90 10 00 18  mov  %i0, %o0
a0104620:  a8 02 00 14  add  %o0, %l4, %l4
a0104624:  40 00 73 0d  call  0xa0121258
a0104628:  90 10 00 18  mov  %i0, %o0
a010462c:  80 8a 20 ff  btst  0xff, %o0
a0104630:  02 80 00 2e  be  0xa01046e8
a0104634:  90 10 00 18  mov  %i0, %o0
a0104638:  92 10 20 89  mov  0x89, %o1
a010463c:  7f ff b8 e6  call  0xa00f29d4
a0104640:  90 10 00 18  mov  %i0, %o0
a0104644:  a0 10 00 08  mov  %o0, %l0
a0104648:  90 10 20 01  mov  1, %o0
a010464c:  40 00 75 60  call  0xa0121bcc
a0104650:  92 10 00 1d  mov  %i5, %o1
a0104654:  90 10 00 18  mov  %i0, %o0
a0104658:  7f ff b8 df  call  0xa00f29d4
a010465c:  92 10 20 89  mov  0x89, %o1
a0104660:  9a 10 00 08  mov  %o0, %o5
a0104664:  10 80 00 14  b  0xa01046b4
a0104668:  a2 10 20 00  clr  %l1
a010466c:  80 a0 60 0f  cmp  %g1, 0xf
a0104670:  34 80 00 02  bg,a   0xa0104678
a0104674:  96 10 20 00  clr  %o3
a0104678:  80 a3 20 03  cmp  %o4, 3
a010467c:  94 60 20 00  subx  %g0, 0, %o2
a0104680:  80 8a 80 0b  btst  %o2, %o3
a0104684:  02 80 00 15  be  0xa01046d8
a0104688:  96 04 00 0d  add  %l0, %o5, %o3
a010468c:  7f ff b8 d2  call  0xa00f29d4
a0104690:  01 00 00 00  nop
a0104694:  a0 10 00 08  mov  %o0, %l0
a0104698:  90 10 20 01  mov  1, %o0
a010469c:  40 00 75 4c  call  0xa0121bcc
a01046a0:  93 36 a0 10  srl  %i2, 0x10, %o1
a01046a4:  90 10 00 18  mov  %i0, %o0
a01046a8:  7f ff b8 cb  call  0xa00f29d4
a01046ac:  92 10 20 89  mov  0x89, %o1
a01046b0:  9a 10 00 08  mov  %o0, %o5
a01046b4:  98 0c 60 ff  and  %l1, 0xff, %o4
a01046b8:  82 24 00 0d  sub  %l0, %o5, %g1
a01046bc:  92 10 20 89  mov  0x89, %o1
a01046c0:  90 10 00 18  mov  %i0, %o0
a01046c4:  80 a0 7f f1  cmp  %g1, -15
a01046c8:  96 10 20 01  mov  1, %o3
a01046cc:  16 bf ff e8  bge  0xa010466c
a01046d0:  a2 04 60 01  inc  %l1
a01046d4:  96 04 00 0d  add  %l0, %o5, %o3
a01046d8:  80 a7 00 17  cmp  %i4, %l7
a01046dc:  9a 40 20 00  addx  %g0, 0, %o5
a01046e0:  10 80 00 06  b  0xa01046f8
a01046e4:  91 32 e0 01  srl  %o3, 1, %o0
a01046e8:  7f ff b8 bb  call  0xa00f29d4
a01046ec:  92 10 20 89  mov  0x89, %o1
a01046f0:  80 a7 00 17  cmp  %i4, %l7
a01046f4:  9a 40 20 00  addx  %g0, 0, %o5
a01046f8:  80 a2 00 17  cmp  %o0, %l7
a01046fc:  9e 40 20 00  addx  %g0, 0, %o7
a0104700:  80 8b 40 0f  btst  %o5, %o7
a0104704:  22 80 00 05  be,a   0xa0104718
a0104708:  aa 05 40 08  add  %l5, %o0, %l5
a010470c:  21 00 10 00  sethi  %hi(0x400000), %l0
a0104710:  90 02 00 10  add  %o0, %l0, %o0
a0104714:  aa 05 40 08  add  %l5, %o0, %l5
a0104718:  90 10 00 18  mov  %i0, %o0
a010471c:  92 10 20 88  mov  0x88, %o1
a0104720:  7f ff b6 de  call  0xa00f2298
a0104724:  94 10 20 02  mov  2, %o2
a0104728:  90 10 00 18  mov  %i0, %o0
a010472c:  92 10 20 89  mov  0x89, %o1
a0104730:  7f ff b8 a9  call  0xa00f29d4
a0104734:  a4 04 a0 01  inc  %l2
a0104738:  a2 0c a0 ff  and  %l2, 0xff, %l1
a010473c:  80 a4 60 03  cmp  %l1, 3
a0104740:  08 bf ff ae  bleu  0xa01045f8
a0104744:  ac 05 80 08  add  %l6, %o0, %l6
a0104748:  b5 2d 20 10  sll  %l4, 0x10, %i2
a010474c:  af 36 a0 10  srl  %i2, 0x10, %l7
a0104750:  a4 05 e0 02  add  %l7, 2, %l2
a0104754:  a9 3c a0 02  sra  %l2, 2, %l4
a0104758:  a5 2d 20 10  sll  %l4, 0x10, %l2
a010475c:  a3 34 a0 10  srl  %l2, 0x10, %l1
a0104760:  80 a4 60 00  cmp  %l1, 0
a0104764:  02 80 00 a8  be  0xa0104a04
a0104768:  ae 10 00 14  mov  %l4, %l7
a010476c:  80 a5 60 00  cmp  %l5, 0
a0104770:  02 80 00 aa  be  0xa0104a18
a0104774:  97 2c e0 10  sll  %l3, 0x10, %o3
a0104778:  97 32 e0 10  srl  %o3, 0x10, %o3
a010477c:  a8 05 80 16  add  %l6, %l6, %l4
a0104780:  81 80 00 00  mov  %g0, %y
a0104784:  01 00 00 00  nop
a0104788:  01 00 00 00  nop
a010478c:  01 00 00 00  nop
a0104790:  a6 75 00 0b  udiv  %l4, %o3, %l3
a0104794:  b4 5c c0 0b  smul  %l3, %o3, %i2
a0104798:  a0 25 00 1a  sub  %l4, %i2, %l0
a010479c:  9b 2c 20 10  sll  %l0, 0x10, %o5
a01047a0:  99 33 60 10  srl  %o5, 0x10, %o4
a01047a4:  95 2b 20 02  sll  %o4, 2, %o2
a01047a8:  90 02 80 0c  add  %o2, %o4, %o0
a01047ac:  93 2a e0 03  sll  %o3, 3, %o1
a01047b0:  82 02 00 08  add  %o0, %o0, %g1
a01047b4:  94 05 40 15  add  %l5, %l5, %o2
a01047b8:  9e 02 40 0b  add  %o1, %o3, %o7
a01047bc:  3b 33 33 33  sethi  %hi(0xcccccc00), %i5
a01047c0:  b8 23 c0 01  sub  %o7, %g1, %i4
a01047c4:  aa 17 60 cd  or  %i5, 0xcd, %l5
a01047c8:  80 57 00 15  umul  %i4, %l5, %g0
a01047cc:  ad 40 00 00  rd  %y, %l6
a01047d0:  81 80 00 00  mov  %g0, %y
a01047d4:  01 00 00 00  nop
a01047d8:  01 00 00 00  nop
a01047dc:  01 00 00 00  nop
a01047e0:  aa 72 80 11  udiv  %o2, %l1, %l5
a01047e4:  a7 2d a0 0d  sll  %l6, 0xd, %l3
a01047e8:  b5 2d 60 10  sll  %l5, 0x10, %i2
a01047ec:  a1 3c e0 10  sra  %l3, 0x10, %l0
a01047f0:  a9 36 a0 10  srl  %i2, 0x10, %l4
a01047f4:  9a 5c 00 14  smul  %l0, %l4, %o5
a01047f8:  98 5d 40 11  smul  %l5, %l1, %o4
a01047fc:  83 3b 60 1f  sra  %o5, 0x1f, %g1
a0104800:  81 80 60 00  mov  %g1, %y
a0104804:  01 00 00 00  nop
a0104808:  01 00 00 00  nop
a010480c:  01 00 00 00  nop
a0104810:  92 7b 40 0b  sdiv  %o5, %o3, %o1
a0104814:  ac 22 80 0c  sub  %o2, %o4, %l6
a0104818:  90 05 80 09  add  %l6, %o1, %o0
a010481c:  03 0a aa aa  sethi  %hi(0x2aaaa800), %g1
a0104820:  97 2c 60 03  sll  %l1, 3, %o3
a0104824:  a0 10 62 ab  or  %g1, 0x2ab, %l0
a0104828:  b9 2a 20 10  sll  %o0, 0x10, %i4
a010482c:  ba 02 c0 11  add  %o3, %l1, %i5
a0104830:  80 5f 40 10  smul  %i5, %l0, %g0
a0104834:  a7 40 00 00  rd  %y, %l3
a0104838:  91 3f 20 10  sra  %i4, 0x10, %o0
a010483c:  a8 10 00 12  mov  %l2, %l4
a0104840:  80 a2 00 13  cmp  %o0, %l3
a0104844:  a4 10 00 16  mov  %l6, %l2
a0104848:  94 10 00 15  mov  %l5, %o2
a010484c:  14 80 00 27  bg  0xa01048e8
a0104850:  82 10 00 13  mov  %l3, %g1
a0104854:  aa 22 c0 11  sub  %o3, %l1, %l5
a0104858:  b9 3d 60 1f  sra  %l5, 0x1f, %i4
a010485c:  80 5d 40 10  smul  %l5, %l0, %g0
a0104860:  ad 40 00 00  rd  %y, %l6
a0104864:  82 25 80 1c  sub  %l6, %i4, %g1
a0104868:  80 a2 00 01  cmp  %o0, %g1
a010486c:  14 80 00 20  bg  0xa01048ec
a0104870:  ba 20 40 12  sub  %g1, %l2, %i5
a0104874:  83 2c 60 02  sll  %l1, 2, %g1
a0104878:  ba 00 40 11  add  %g1, %l1, %i5
a010487c:  80 5f 40 10  smul  %i5, %l0, %g0
a0104880:  83 40 00 00  rd  %y, %g1
a0104884:  80 a2 00 01  cmp  %o0, %g1
a0104888:  34 80 00 19  bg,a   0xa01048ec
a010488c:  ba 20 40 12  sub  %g1, %l2, %i5
a0104890:  97 34 60 01  srl  %l1, 1, %o3
a0104894:  80 a2 00 0b  cmp  %o0, %o3
a0104898:  14 80 00 14  bg  0xa01048e8
a010489c:  82 10 00 0b  mov  %o3, %g1
a01048a0:  19 2a aa aa  sethi  %hi(0xaaaaa800), %o4
a01048a4:  92 13 22 ab  or  %o4, 0x2ab, %o1	! 0xaaaaaaab
a01048a8:  80 54 40 09  umul  %l1, %o1, %g0
a01048ac:  9f 40 00 00  rd  %y, %o7
a01048b0:  99 33 e0 02  srl  %o7, 2, %o4
a01048b4:  a3 2b 20 10  sll  %o4, 0x10, %l1
a01048b8:  9b 34 60 10  srl  %l1, 0x10, %o5
a01048bc:  80 a2 00 0d  cmp  %o0, %o5
a01048c0:  14 80 00 0a  bg  0xa01048e8
a01048c4:  82 10 00 0c  mov  %o4, %g1
a01048c8:  a0 20 00 0d  neg  %o5, %l0
a01048cc:  80 a2 00 10  cmp  %o0, %l0
a01048d0:  14 80 00 06  bg  0xa01048e8
a01048d4:  82 20 00 0c  neg  %o4, %g1
a01048d8:  82 20 00 0b  neg  %o3, %g1
a01048dc:  80 a2 00 01  cmp  %o0, %g1
a01048e0:  24 80 00 02  ble,a   0xa01048e8
a01048e4:  82 10 00 0c  mov  %o4, %g1
a01048e8:  ba 20 40 12  sub  %g1, %l2, %i5
a01048ec:  ab 2f 60 10  sll  %i5, 0x10, %l5
a01048f0:  e0 1e 40 00  ldd  [ %i1 ], %l0
a01048f4:  97 3d 60 10  sra  %l5, 0x10, %o3
a01048f8:  b9 3d 60 1f  sra  %l5, 0x1f, %i4
a01048fc:  92 54 40 0b  umul  %l1, %o3, %o1
a0104900:  91 40 00 00  rd  %y, %o0
a0104904:  95 2a a0 10  sll  %o2, 0x10, %o2
a0104908:  ac 5c 40 1c  smul  %l1, %i4, %l6
a010490c:  9b 32 a0 10  srl  %o2, 0x10, %o5
a0104910:  a6 05 80 08  add  %l6, %o0, %l3
a0104914:  b4 5a c0 10  smul  %o3, %l0, %i2
a0104918:  96 10 00 0d  mov  %o5, %o3
a010491c:  90 04 c0 1a  add  %l3, %i2, %o0
a0104920:  40 01 42 3a  call  0xa0155208
a0104924:  94 10 20 00  clr  %o2
a0104928:  a7 35 20 10  srl  %l4, 0x10, %l3
a010492c:  94 10 20 00  clr  %o2
a0104930:  40 01 42 36  call  0xa0155208
a0104934:  96 10 00 13  mov  %l3, %o3
a0104938:  a5 3a 60 1f  sra  %o1, 0x1f, %l2
a010493c:  92 84 40 09  addcc  %l1, %o1, %o1
a0104940:  90 44 00 12  addx  %l0, %l2, %o0
a0104944:  80 8c e0 01  btst  1, %l3
a0104948:  22 80 00 39  be,a   0xa0104a2c
a010494c:  d0 3e 40 00  std  %o0, [ %i1 ]
a0104950:  94 10 20 00  clr  %o2
a0104954:  40 01 42 2d  call  0xa0155208
a0104958:  96 10 00 13  mov  %l3, %o3
a010495c:  a2 04 ff ff  add  %l3, -1, %l1
a0104960:  9a 10 00 11  mov  %l1, %o5
a0104964:  99 3c 60 1f  sra  %l1, 0x1f, %o4
a0104968:  a2 52 40 11  umul  %o1, %l1, %l1
a010496c:  a1 40 00 00  rd  %y, %l0
a0104970:  a4 5a 40 0c  smul  %o1, %o4, %l2
a0104974:  9e 5b 40 08  smul  %o5, %o0, %o7
a0104978:  82 04 80 10  add  %l2, %l0, %g1
a010497c:  a8 05 ff ff  add  %l7, -1, %l4
a0104980:  a0 00 40 0f  add  %g1, %o7, %l0
a0104984:  af 2d 20 10  sll  %l4, 0x10, %l7
a0104988:  e0 3e 40 00  std  %l0, [ %i1 ]
a010498c:  95 35 e0 10  srl  %l7, 0x10, %o2
a0104990:  90 10 00 18  mov  %i0, %o0
a0104994:  7f ff b6 bd  call  0xa00f2488
a0104998:  92 10 20 5e  mov  0x5e, %o1
a010499c:  d2 06 60 04  ld  [ %i1 + 4 ], %o1
a01049a0:  7f ff f7 52  call  0xa01026e8
a01049a4:  90 10 20 00  clr  %o0
a01049a8:  90 10 00 18  mov  %i0, %o0
a01049ac:  92 10 20 54  mov  0x54, %o1
a01049b0:  7f ff b6 3a  call  0xa00f2298
a01049b4:  94 10 20 02  mov  2, %o2
a01049b8:  11 2a 00 b2  sethi  %hi(0xa802c800), %o0
a01049bc:  d4 0a 21 84  ldub  [ %o0 + 0x184 ], %o2	! 0xa802c984
a01049c0:  90 10 00 18  mov  %i0, %o0
a01049c4:  7f ff b6 35  call  0xa00f2298
a01049c8:  92 10 20 86  mov  0x86, %o1
a01049cc:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a01049d0:  d4 0c 21 82  ldub  [ %l0 + 0x182 ], %o2	! 0xa802c982
a01049d4:  90 10 00 18  mov  %i0, %o0
a01049d8:  7f ff b6 30  call  0xa00f2298
a01049dc:  92 10 20 50  mov  0x50, %o1
a01049e0:  d2 06 e2 a4  ld  [ %i3 + 0x2a4 ], %o1
a01049e4:  d4 12 60 0a  lduh  [ %o1 + 0xa ], %o2
a01049e8:  90 10 00 18  mov  %i0, %o0
a01049ec:  92 10 20 64  mov  0x64, %o1
a01049f0:  7f ff b6 a6  call  0xa00f2488
a01049f4:  33 2a 00 b2  sethi  %hi(0xa802c800), %i1
a01049f8:  f4 0e 61 83  ldub  [ %i1 + 0x183 ], %i2	! 0xa802c983
a01049fc:  7f ff b6 27  call  0xa00f2298
a0104a00:  93 e8 20 88  restore  %g0, 0x88, %o1
a0104a04:  67 fe 21 e7  call  0x4008d1a0
a0104a08:  90 10 20 01  mov  1, %o0
a0104a0c:  67 fe 21 e5  call  0x4008d1a0
a0104a10:  90 10 20 01  mov  1, %o0
a0104a14:  30 bf ff fc  b,a   0xa0104a04
a0104a18:  67 fe 21 e2  call  0x4008d1a0
a0104a1c:  90 10 20 01  mov  1, %o0
a0104a20:  67 fe 21 e0  call  0x4008d1a0
a0104a24:  90 10 20 01  mov  1, %o0
a0104a28:  30 bf ff fc  b,a   0xa0104a18
a0104a2c:  10 bf ff d9  b  0xa0104990
a0104a30:  94 10 00 13  mov  %l3, %o2
