# leon2m FUN_a0149588 0xa0149588-0xa0149978 (1008 bytes)
a0149588:  9d e3 bf 98  save  %sp, -104, %sp
a014958c:  33 2a 00 b7  sethi  %hi(0xa802dc00), %i1
a0149590:  e0 06 63 30  ld  [ %i1 + 0x330 ], %l0	! 0xa802df30
a0149594:  83 34 20 0c  srl  %l0, 0xc, %g1
a0149598:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a014959c:  d0 04 23 d0  ld  [ %l0 + 0x3d0 ], %o0	! 0xa802e3d0
a01495a0:  a2 0e 20 01  and  %i0, 1, %l1
a01495a4:  19 00 20 00  sethi  %hi(0x800000), %o4
a01495a8:  9e 08 60 0f  and  %g1, 0xf, %o7
a01495ac:  94 2a 00 0c  andn  %o0, %o4, %o2
a01495b0:  97 2c 60 17  sll  %l1, 0x17, %o3
a01495b4:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a01495b8:  90 12 80 0b  or  %o2, %o3, %o0
a01495bc:  92 5b e0 2a  smul  %o7, 0x2a, %o1
a01495c0:  a2 13 62 24  or  %o5, 0x224, %l1
a01495c4:  82 02 40 11  add  %o1, %l1, %g1
a01495c8:  d0 24 23 d0  st  %o0, [ %l0 + 0x3d0 ]
a01495cc:  7f ff e2 e7  call  0xa0142168
a01495d0:  d0 08 60 0a  ldub  [ %g1 + 0xa ], %o0
a01495d4:  9e 0a 20 ff  and  %o0, 0xff, %o7
a01495d8:  80 a3 e0 07  cmp  %o7, 7
a01495dc:  9a 40 20 00  addx  %g0, 0, %o5
a01495e0:  b0 20 00 0d  neg  %o5, %i0
a01495e4:  98 0b c0 18  and  %o7, %i0, %o4
a01495e8:  97 2b 20 03  sll  %o4, 3, %o3
a01495ec:  92 02 c0 0c  add  %o3, %o4, %o1
a01495f0:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a01495f4:  b0 12 a1 16  or  %o2, 0x116, %i0	! 0xa802e116
a01495f8:  82 02 40 09  add  %o1, %o1, %g1
a01495fc:  9a 00 40 18  add  %g1, %i0, %o5
a0149600:  7f ff 6e d0  call  0xa0125140
a0149604:  d0 0b 60 10  ldub  [ %o5 + 0x10 ], %o0
a0149608:  7f ff 6e e4  call  0xa0125198
a014960c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149610:  7f ff e3 02  call  0xa0142218
a0149614:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149618:  7f ff e2 eb  call  0xa01421c4
a014961c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149620:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149624:  80 a2 20 71  cmp  %o0, 0x71
a0149628:  02 80 00 c0  be  0xa0149928
a014962c:  94 14 23 d0  or  %l0, 0x3d0, %o2
a0149630:  de 04 23 d0  ld  [ %l0 + 0x3d0 ], %o7
a0149634:  17 00 20 00  sethi  %hi(0x800000), %o3
a0149638:  80 8b c0 0b  btst  %o7, %o3
a014963c:  22 80 00 5c  be,a   0xa01497ac
a0149640:  a0 16 63 30  or  %i1, 0x330, %l0
a0149644:  b2 16 63 30  or  %i1, 0x330, %i1
a0149648:  d4 06 60 78  ld  [ %i1 + 0x78 ], %o2
a014964c:  93 32 a0 0c  srl  %o2, 0xc, %o1
a0149650:  82 0a 60 0f  and  %o1, 0xf, %g1
a0149654:  90 58 60 2a  smul  %g1, 0x2a, %o0
a0149658:  98 02 00 11  add  %o0, %l1, %o4
a014965c:  7f ff e2 c3  call  0xa0142168
a0149660:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a0149664:  96 0a 20 ff  and  %o0, 0xff, %o3
a0149668:  80 a2 e0 07  cmp  %o3, 7
a014966c:  9a 40 20 00  addx  %g0, 0, %o5
a0149670:  9e 20 00 0d  neg  %o5, %o7
a0149674:  94 0a c0 0f  and  %o3, %o7, %o2
a0149678:  93 2a a0 03  sll  %o2, 3, %o1
a014967c:  82 02 40 0a  add  %o1, %o2, %g1
a0149680:  90 00 40 01  add  %g1, %g1, %o0
a0149684:  98 02 00 18  add  %o0, %i0, %o4
a0149688:  7f ff 6e ae  call  0xa0125140
a014968c:  d0 0b 20 10  ldub  [ %o4 + 0x10 ], %o0
a0149690:  7f ff 6e c2  call  0xa0125198
a0149694:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149698:  7f ff e2 e0  call  0xa0142218
a014969c:  90 0a 20 ff  and  %o0, 0xff, %o0
a01496a0:  7f ff e2 c9  call  0xa01421c4
a01496a4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01496a8:  9a 0a 20 ff  and  %o0, 0xff, %o5
a01496ac:  80 a3 60 71  cmp  %o5, 0x71
a01496b0:  02 80 00 94  be  0xa0149900
a01496b4:  9e 14 23 d0  or  %l0, 0x3d0, %o7
a01496b8:  d4 06 60 f0  ld  [ %i1 + 0xf0 ], %o2
a01496bc:  93 32 a0 0c  srl  %o2, 0xc, %o1
a01496c0:  82 0a 60 0f  and  %o1, 0xf, %g1
a01496c4:  90 58 60 2a  smul  %g1, 0x2a, %o0
a01496c8:  98 02 00 11  add  %o0, %l1, %o4
a01496cc:  7f ff e2 a7  call  0xa0142168
a01496d0:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a01496d4:  96 0a 20 ff  and  %o0, 0xff, %o3
a01496d8:  80 a2 e0 07  cmp  %o3, 7
a01496dc:  9a 40 20 00  addx  %g0, 0, %o5
a01496e0:  9e 20 00 0d  neg  %o5, %o7
a01496e4:  94 0a c0 0f  and  %o3, %o7, %o2
a01496e8:  93 2a a0 03  sll  %o2, 3, %o1
a01496ec:  82 02 40 0a  add  %o1, %o2, %g1
a01496f0:  90 00 40 01  add  %g1, %g1, %o0
a01496f4:  98 02 00 18  add  %o0, %i0, %o4
a01496f8:  7f ff 6e 92  call  0xa0125140
a01496fc:  d0 0b 20 10  ldub  [ %o4 + 0x10 ], %o0
a0149700:  7f ff 6e a6  call  0xa0125198
a0149704:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149708:  7f ff e2 c4  call  0xa0142218
a014970c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149710:  7f ff e2 ad  call  0xa01421c4
a0149714:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149718:  9a 0a 20 ff  and  %o0, 0xff, %o5
a014971c:  80 a3 60 71  cmp  %o5, 0x71
a0149720:  02 80 00 8e  be  0xa0149958
a0149724:  9e 14 23 d0  or  %l0, 0x3d0, %o7
a0149728:  c2 06 61 68  ld  [ %i1 + 0x168 ], %g1
a014972c:  99 30 60 0c  srl  %g1, 0xc, %o4
a0149730:  9a 0b 20 0f  and  %o4, 0xf, %o5
a0149734:  b2 5b 60 2a  smul  %o5, 0x2a, %i1
a0149738:  9e 06 40 11  add  %i1, %l1, %o7
a014973c:  d0 0b e0 0a  ldub  [ %o7 + 0xa ], %o0
a0149740:  7f ff e2 8a  call  0xa0142168
a0149744:  01 00 00 00  nop
a0149748:  92 0a 20 ff  and  %o0, 0xff, %o1
a014974c:  80 a2 60 07  cmp  %o1, 7
a0149750:  96 40 20 00  addx  %g0, 0, %o3
a0149754:  94 20 00 0b  neg  %o3, %o2
a0149758:  90 0a 40 0a  and  %o1, %o2, %o0
a014975c:  83 2a 20 03  sll  %o0, 3, %g1
a0149760:  98 00 40 08  add  %g1, %o0, %o4
a0149764:  9a 03 00 0c  add  %o4, %o4, %o5
a0149768:  a2 03 40 18  add  %o5, %i0, %l1
a014976c:  7f ff 6e 75  call  0xa0125140
a0149770:  d0 0c 60 10  ldub  [ %l1 + 0x10 ], %o0
a0149774:  7f ff 6e 89  call  0xa0125198
a0149778:  90 0a 20 ff  and  %o0, 0xff, %o0
a014977c:  7f ff e2 a7  call  0xa0142218
a0149780:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149784:  7f ff e2 90  call  0xa01421c4
a0149788:  90 0a 20 ff  and  %o0, 0xff, %o0
a014978c:  b2 0a 20 ff  and  %o0, 0xff, %i1
a0149790:  80 a6 60 71  cmp  %i1, 0x71
a0149794:  12 80 00 77  bne  0xa0149970
a0149798:  a2 14 23 d0  or  %l0, 0x3d0, %l1
a014979c:  f0 0c 60 21  ldub  [ %l1 + 0x21 ], %i0
a01497a0:  b2 0e 20 03  and  %i0, 3, %i1
a01497a4:  7f ff a4 4c  call  0xa01328d4
a01497a8:  91 e8 20 03  restore  %g0, 3, %o0
a01497ac:  de 04 20 78  ld  [ %l0 + 0x78 ], %o7
a01497b0:  97 33 e0 0c  srl  %o7, 0xc, %o3
a01497b4:  94 0a e0 0f  and  %o3, 0xf, %o2
a01497b8:  90 5a a0 2a  smul  %o2, 0x2a, %o0
a01497bc:  92 02 00 11  add  %o0, %l1, %o1
a01497c0:  7f ff e2 6a  call  0xa0142168
a01497c4:  d0 0a 60 0a  ldub  [ %o1 + 0xa ], %o0
a01497c8:  98 0a 20 ff  and  %o0, 0xff, %o4
a01497cc:  80 a3 20 07  cmp  %o4, 7
a01497d0:  82 40 20 00  addx  %g0, 0, %g1
a01497d4:  9a 20 00 01  neg  %g1, %o5
a01497d8:  b2 0b 00 0d  and  %o4, %o5, %i1
a01497dc:  9f 2e 60 03  sll  %i1, 3, %o7
a01497e0:  96 03 c0 19  add  %o7, %i1, %o3
a01497e4:  94 02 c0 0b  add  %o3, %o3, %o2
a01497e8:  92 02 80 18  add  %o2, %i0, %o1
a01497ec:  7f ff 6e 55  call  0xa0125140
a01497f0:  d0 0a 60 10  ldub  [ %o1 + 0x10 ], %o0
a01497f4:  7f ff 6e 69  call  0xa0125198
a01497f8:  90 0a 20 ff  and  %o0, 0xff, %o0
a01497fc:  7f ff e2 87  call  0xa0142218
a0149800:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149804:  7f ff e2 70  call  0xa01421c4
a0149808:  90 0a 20 ff  and  %o0, 0xff, %o0
a014980c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149810:  80 a2 20 71  cmp  %o0, 0x71
a0149814:  22 80 00 41  be,a   0xa0149918
a0149818:  90 10 20 01  mov  1, %o0
a014981c:  d2 04 20 f0  ld  [ %l0 + 0xf0 ], %o1
a0149820:  83 32 60 0c  srl  %o1, 0xc, %g1
a0149824:  9a 08 60 0f  and  %g1, 0xf, %o5
a0149828:  98 5b 60 2a  smul  %o5, 0x2a, %o4
a014982c:  b2 03 00 11  add  %o4, %l1, %i1
a0149830:  7f ff e2 4e  call  0xa0142168
a0149834:  d0 0e 60 0a  ldub  [ %i1 + 0xa ], %o0
a0149838:  94 0a 20 ff  and  %o0, 0xff, %o2
a014983c:  80 a2 a0 07  cmp  %o2, 7
a0149840:  9e 40 20 00  addx  %g0, 0, %o7
a0149844:  96 20 00 0f  neg  %o7, %o3
a0149848:  90 0a 80 0b  and  %o2, %o3, %o0
a014984c:  93 2a 20 03  sll  %o0, 3, %o1
a0149850:  82 02 40 08  add  %o1, %o0, %g1
a0149854:  9a 00 40 01  add  %g1, %g1, %o5
a0149858:  98 03 40 18  add  %o5, %i0, %o4
a014985c:  7f ff 6e 39  call  0xa0125140
a0149860:  d0 0b 20 10  ldub  [ %o4 + 0x10 ], %o0
a0149864:  7f ff 6e 4d  call  0xa0125198
a0149868:  90 0a 20 ff  and  %o0, 0xff, %o0
a014986c:  7f ff e2 6b  call  0xa0142218
a0149870:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149874:  7f ff e2 54  call  0xa01421c4
a0149878:  90 0a 20 ff  and  %o0, 0xff, %o0
a014987c:  b2 0a 20 ff  and  %o0, 0xff, %i1
a0149880:  80 a6 60 71  cmp  %i1, 0x71
a0149884:  22 80 00 31  be,a   0xa0149948
a0149888:  90 10 20 02  mov  2, %o0
a014988c:  d4 04 21 68  ld  [ %l0 + 0x168 ], %o2
a0149890:  91 32 a0 0c  srl  %o2, 0xc, %o0
a0149894:  a0 0a 20 0f  and  %o0, 0xf, %l0
a0149898:  92 5c 20 2a  smul  %l0, 0x2a, %o1
a014989c:  82 02 40 11  add  %o1, %l1, %g1
a01498a0:  7f ff e2 32  call  0xa0142168
a01498a4:  d0 08 60 0a  ldub  [ %g1 + 0xa ], %o0
a01498a8:  b2 0a 20 ff  and  %o0, 0xff, %i1
a01498ac:  80 a6 60 07  cmp  %i1, 7
a01498b0:  9a 40 20 00  addx  %g0, 0, %o5
a01498b4:  98 20 00 0d  neg  %o5, %o4
a01498b8:  9e 0e 40 0c  and  %i1, %o4, %o7
a01498bc:  97 2b e0 03  sll  %o7, 3, %o3
a01498c0:  94 02 c0 0f  add  %o3, %o7, %o2
a01498c4:  90 02 80 0a  add  %o2, %o2, %o0
a01498c8:  a2 02 00 18  add  %o0, %i0, %l1
a01498cc:  7f ff 6e 1d  call  0xa0125140
a01498d0:  d0 0c 60 10  ldub  [ %l1 + 0x10 ], %o0
a01498d4:  7f ff 6e 31  call  0xa0125198
a01498d8:  90 0a 20 ff  and  %o0, 0xff, %o0
a01498dc:  7f ff e2 4f  call  0xa0142218
a01498e0:  90 0a 20 ff  and  %o0, 0xff, %o0
a01498e4:  7f ff e2 38  call  0xa01421c4
a01498e8:  90 0a 20 ff  and  %o0, 0xff, %o0
a01498ec:  a0 0a 20 ff  and  %o0, 0xff, %l0
a01498f0:  80 a4 20 71  cmp  %l0, 0x71
a01498f4:  12 80 00 1f  bne  0xa0149970
a01498f8:  b0 10 20 03  mov  3, %i0
a01498fc:  30 80 00 11  b,a   0xa0149940
a0149900:  d6 0b e0 1f  ldub  [ %o7 + 0x1f ], %o3
a0149904:  92 0a e0 03  and  %o3, 3, %o1
a0149908:  7f ff a3 f3  call  0xa01328d4
a014990c:  90 10 20 01  mov  1, %o0
a0149910:  10 bf ff 6b  b  0xa01496bc
a0149914:  d4 06 60 f0  ld  [ %i1 + 0xf0 ], %o2
a0149918:  7f ff a3 ef  call  0xa01328d4
a014991c:  92 10 20 00  clr  %o1
a0149920:  10 bf ff c0  b  0xa0149820
a0149924:  d2 04 20 f0  ld  [ %l0 + 0xf0 ], %o1
a0149928:  d2 0a a0 1e  ldub  [ %o2 + 0x1e ], %o1
a014992c:  92 0a 60 03  and  %o1, 3, %o1
a0149930:  7f ff a3 e9  call  0xa01328d4
a0149934:  90 10 20 00  clr  %o0
a0149938:  10 bf ff 3f  b  0xa0149634
a014993c:  de 04 23 d0  ld  [ %l0 + 0x3d0 ], %o7
a0149940:  7f ff a3 e5  call  0xa01328d4
a0149944:  93 e8 20 00  restore  %g0, 0, %o1
a0149948:  7f ff a3 e3  call  0xa01328d4
a014994c:  92 10 20 00  clr  %o1
a0149950:  10 bf ff d0  b  0xa0149890
a0149954:  d4 04 21 68  ld  [ %l0 + 0x168 ], %o2
a0149958:  d6 0b e0 20  ldub  [ %o7 + 0x20 ], %o3
a014995c:  92 0a e0 03  and  %o3, 3, %o1
a0149960:  7f ff a3 dd  call  0xa01328d4
a0149964:  90 10 20 02  mov  2, %o0
a0149968:  10 bf ff 71  b  0xa014972c
a014996c:  c2 06 61 68  ld  [ %i1 + 0x168 ], %g1
a0149970:  81 c7 e0 08  ret
a0149974:  81 e8 00 00  restore
