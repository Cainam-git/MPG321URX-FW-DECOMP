# leon2m FUN_a00d3650 0xa00d3650-0xa00d3a30 (688 bytes)
a00d3650:  9d e3 bf 70  save  %sp, -144, %sp
a00d3654:  94 10 3f 99  mov  -103, %o2
a00d3658:  98 10 20 00  clr  %o4
a00d365c:  9a 10 20 00  clr  %o5
a00d3660:  96 07 bf f8  add  %fp, -8, %o3
a00d3664:  82 02 c0 0d  add  %o3, %o5, %g1
a00d3668:  98 03 20 01  inc  %o4
a00d366c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d3670:  80 a3 60 27  cmp  %o5, 0x27
a00d3674:  08 bf ff fc  bleu  0xa00d3664
a00d3678:  c0 28 7f d8  clrb  [ %g1 + -40 ]
a00d367c:  d0 0e 60 03  ldub  [ %i1 + 3 ], %o0
a00d3680:  96 0a 20 ff  and  %o0, 0xff, %o3
a00d3684:  a0 1a e0 63  xor  %o3, 0x63, %l0
a00d3688:  80 a0 00 10  cmp  %g0, %l0
a00d368c:  98 60 3f ff  subx  %g0, -1, %o4
a00d3690:  9e 1a e0 31  xor  %o3, 0x31, %o7
a00d3694:  80 a0 00 0f  cmp  %g0, %o7
a00d3698:  9a 60 3f ff  subx  %g0, -1, %o5
a00d369c:  92 10 20 6e  mov  0x6e, %o1
a00d36a0:  80 93 00 0d  orcc  %o4, %o5, %g0
a00d36a4:  d2 2f bf d0  stb  %o1, [ %fp + -48 ]
a00d36a8:  12 80 00 25  bne  0xa00d373c
a00d36ac:  a0 07 bf d0  add  %fp, -48, %l0
a00d36b0:  80 a2 e0 32  cmp  %o3, 0x32
a00d36b4:  02 80 00 22  be  0xa00d373c
a00d36b8:  80 a2 e0 27  cmp  %o3, 0x27
a00d36bc:  02 80 00 20  be  0xa00d373c
a00d36c0:  80 a2 e0 28  cmp  %o3, 0x28
a00d36c4:  02 80 00 1e  be  0xa00d373c
a00d36c8:  80 a2 e0 35  cmp  %o3, 0x35
a00d36cc:  02 80 00 1c  be  0xa00d373c
a00d36d0:  80 a2 e0 36  cmp  %o3, 0x36
a00d36d4:  02 80 00 1a  be  0xa00d373c
a00d36d8:  80 a2 e0 39  cmp  %o3, 0x39
a00d36dc:  02 80 00 18  be  0xa00d373c
a00d36e0:  80 a2 e0 3a  cmp  %o3, 0x3a
a00d36e4:  02 80 00 16  be  0xa00d373c
a00d36e8:  98 1a e0 34  xor  %o3, 0x34, %o4
a00d36ec:  80 a0 00 0c  cmp  %g0, %o4
a00d36f0:  92 60 3f ff  subx  %g0, -1, %o1
a00d36f4:  9a 1a e0 30  xor  %o3, 0x30, %o5
a00d36f8:  80 a0 00 0d  cmp  %g0, %o5
a00d36fc:  82 60 3f ff  subx  %g0, -1, %g1
a00d3700:  80 92 40 01  orcc  %o1, %g1, %g0
a00d3704:  32 80 00 0f  bne,a   0xa00d3740
a00d3708:  82 10 3f 93  mov  -109, %g1
a00d370c:  80 a2 e0 38  cmp  %o3, 0x38
a00d3710:  02 80 00 a1  be  0xa00d3994
a00d3714:  80 a2 e0 3c  cmp  %o3, 0x3c
a00d3718:  02 80 00 0a  be  0xa00d3740
a00d371c:  82 10 3f 93  mov  -109, %g1
a00d3720:  d6 0e 60 06  ldub  [ %i1 + 6 ], %o3
a00d3724:  80 a2 e0 40  cmp  %o3, 0x40
a00d3728:  02 80 00 03  be  0xa00d3734
a00d372c:  82 10 3f c5  mov  -59, %g1
a00d3730:  82 10 3f 95  mov  -107, %g1
a00d3734:  10 80 00 05  b  0xa00d3748
a00d3738:  c2 2f bf d1  stb  %g1, [ %fp + -47 ]
a00d373c:  82 10 3f 86  mov  -122, %g1
a00d3740:  c2 2c 20 01  stb  %g1, [ %l0 + 1 ]
a00d3744:  d6 0e 60 06  ldub  [ %i1 + 6 ], %o3
a00d3748:  d8 0e 60 03  ldub  [ %i1 + 3 ], %o4
a00d374c:  da 0e 60 04  ldub  [ %i1 + 4 ], %o5
a00d3750:  de 0e 60 05  ldub  [ %i1 + 5 ], %o7
a00d3754:  92 03 3f d7  add  %o4, -41, %o1
a00d3758:  82 10 3f d0  mov  -48, %g1
a00d375c:  c2 2c 20 02  stb  %g1, [ %l0 + 2 ]
a00d3760:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00d3764:  da 2c 20 04  stb  %o5, [ %l0 + 4 ]
a00d3768:  de 2c 20 05  stb  %o7, [ %l0 + 5 ]
a00d376c:  80 a2 60 12  cmp  %o1, 0x12
a00d3770:  18 80 00 a3  bgu  0xa00d39fc
a00d3774:  d6 2c 20 06  stb  %o3, [ %l0 + 6 ]
a00d3778:  9e 10 20 01  mov  1, %o7
a00d377c:  97 2b c0 09  sll  %o7, %o1, %o3
a00d3780:  13 00 01 11  sethi  %hi(0x44400), %o1
a00d3784:  90 12 60 01  or  %o1, 1, %o0	! 0x44401
a00d3788:  80 8a c0 08  btst  %o3, %o0
a00d378c:  02 80 00 9d  be  0xa00d3a00
a00d3790:  94 0a a0 fb  and  %o2, 0xfb, %o2
a00d3794:  67 fe e6 83  call  0x4008d1a0
a00d3798:  90 10 20 0a  mov  0xa, %o0
a00d379c:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00d37a0:  d4 0b 60 9f  ldub  [ %o5 + 0x9f ], %o2	! 0xa802b09f
a00d37a4:  80 a2 a0 01  cmp  %o2, 1
a00d37a8:  22 80 00 2d  be,a   0xa00d385c
a00d37ac:  c2 0e 60 03  ldub  [ %i1 + 3 ], %g1
a00d37b0:  de 0b 60 9f  ldub  [ %o5 + 0x9f ], %o7
a00d37b4:  80 a3 e0 02  cmp  %o7, 2
a00d37b8:  22 80 00 4f  be,a   0xa00d38f4
a00d37bc:  d4 0e 60 03  ldub  [ %i1 + 3 ], %o2
a00d37c0:  d2 0b 60 9f  ldub  [ %o5 + 0x9f ], %o1
a00d37c4:  80 a2 60 11  cmp  %o1, 0x11
a00d37c8:  22 80 00 59  be,a   0xa00d392c
a00d37cc:  de 0e 60 03  ldub  [ %i1 + 3 ], %o7
a00d37d0:  d6 0b 60 9f  ldub  [ %o5 + 0x9f ], %o3
a00d37d4:  80 a2 e0 21  cmp  %o3, 0x21
a00d37d8:  22 80 00 04  be,a   0xa00d37e8
a00d37dc:  d2 0e 60 03  ldub  [ %i1 + 3 ], %o1
a00d37e0:  10 80 00 87  b  0xa00d39fc
a00d37e4:  94 10 3f e3  mov  -29, %o2
a00d37e8:  80 a2 60 3b  cmp  %o1, 0x3b
a00d37ec:  12 80 00 84  bne  0xa00d39fc
a00d37f0:  94 10 3f e3  mov  -29, %o2
a00d37f4:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00d37f8:  c2 0b e0 9e  ldub  [ %o7 + 0x9e ], %g1	! 0xa802b09e
a00d37fc:  80 a0 60 06  cmp  %g1, 6
a00d3800:  18 80 00 7f  bgu  0xa00d39fc
a00d3804:  1b 00 01 bc  sethi  %hi(0x6f000), %o5
a00d3808:  99 28 60 02  sll  %g1, 2, %o4
a00d380c:  90 13 61 78  or  %o5, 0x178, %o0
a00d3810:  d4 02 00 0c  ld  [ %o0 + %o4 ], %o2
a00d3814:  81 c2 80 00  jmp  %o2
a00d3818:  01 00 00 00  nop
a00d381c:  90 10 20 1b  mov  0x1b, %o0	! 0x1b
a00d3820:  d4 0e 60 05  ldub  [ %i1 + 5 ], %o2
a00d3824:  7f ff ec 67  call  0xa00ce9c0
a00d3828:  92 07 bf d7  add  %fp, -41, %o1
a00d382c:  10 80 00 74  b  0xa00d39fc
a00d3830:  94 10 3f 99  mov  -103, %o2
a00d3834:  10 bf ff fb  b  0xa00d3820
a00d3838:  90 10 20 0f  mov  0xf, %o0
a00d383c:  10 bf ff f9  b  0xa00d3820
a00d3840:  90 10 20 0b  mov  0xb, %o0
a00d3844:  10 bf ff f7  b  0xa00d3820
a00d3848:  90 10 20 07  mov  7, %o0
a00d384c:  10 bf ff f5  b  0xa00d3820
a00d3850:  90 10 20 13  mov  0x13, %o0
a00d3854:  10 bf ff f3  b  0xa00d3820
a00d3858:  90 10 20 03  mov  3, %o0
a00d385c:  80 a0 60 29  cmp  %g1, 0x29
a00d3860:  12 bf ff d5  bne  0xa00d37b4
a00d3864:  de 0b 60 9f  ldub  [ %o5 + 0x9f ], %o7
a00d3868:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00d386c:  c2 0b 60 9e  ldub  [ %o5 + 0x9e ], %g1	! 0xa802b09e
a00d3870:  80 a0 60 0c  cmp  %g1, 0xc
a00d3874:  18 80 00 62  bgu  0xa00d39fc
a00d3878:  94 10 3f e3  mov  -29, %o2
a00d387c:  13 00 01 bc  sethi  %hi(0x6f000), %o1
a00d3880:  91 28 60 02  sll  %g1, 2, %o0
a00d3884:  96 12 61 44  or  %o1, 0x144, %o3
a00d3888:  d8 02 c0 08  ld  [ %o3 + %o0 ], %o4
a00d388c:  81 c3 00 00  jmp  %o4
a00d3890:  01 00 00 00  nop
a00d3894:  10 bf ff e3  b  0xa00d3820
a00d3898:  90 10 20 18  mov  0x18, %o0	! 0x18
a00d389c:  10 bf ff e1  b  0xa00d3820
a00d38a0:  90 10 20 0c  mov  0xc, %o0
a00d38a4:  10 bf ff df  b  0xa00d3820
a00d38a8:  90 10 20 08  mov  8, %o0
a00d38ac:  10 bf ff dd  b  0xa00d3820
a00d38b0:  90 10 20 04  mov  4, %o0
a00d38b4:  10 bf ff db  b  0xa00d3820
a00d38b8:  90 10 20 22  mov  0x22, %o0
a00d38bc:  10 bf ff d9  b  0xa00d3820
a00d38c0:  90 10 20 1e  mov  0x1e, %o0
a00d38c4:  10 bf ff d7  b  0xa00d3820
a00d38c8:  90 10 20 20  mov  0x20, %o0
a00d38cc:  10 bf ff d5  b  0xa00d3820
a00d38d0:  90 10 20 1c  mov  0x1c, %o0
a00d38d4:  10 bf ff d3  b  0xa00d3820
a00d38d8:  90 10 20 16  mov  0x16, %o0
a00d38dc:  10 bf ff d1  b  0xa00d3820
a00d38e0:  90 10 20 10  mov  0x10, %o0
a00d38e4:  10 bf ff cf  b  0xa00d3820
a00d38e8:  90 10 20 14  mov  0x14, %o0
a00d38ec:  10 bf ff cd  b  0xa00d3820
a00d38f0:  90 10 20 00  clr  %o0
a00d38f4:  80 a2 a0 33  cmp  %o2, 0x33
a00d38f8:  12 bf ff b3  bne  0xa00d37c4
a00d38fc:  d2 0b 60 9f  ldub  [ %o5 + 0x9f ], %o1
a00d3900:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00d3904:  c2 08 60 9e  ldub  [ %g1 + 0x9e ], %g1	! 0xa802b09e
a00d3908:  80 a0 60 0c  cmp  %g1, 0xc
a00d390c:  38 80 00 3c  bgu,a   0xa00d39fc
a00d3910:  94 10 3f e3  mov  -29, %o2
a00d3914:  17 00 01 bc  sethi  %hi(0x6f000), %o3
a00d3918:  91 28 60 02  sll  %g1, 2, %o0
a00d391c:  9a 12 e1 10  or  %o3, 0x110, %o5
a00d3920:  d8 03 40 08  ld  [ %o5 + %o0 ], %o4
a00d3924:  81 c3 00 00  jmp  %o4
a00d3928:  01 00 00 00  nop
a00d392c:  80 a3 e0 37  cmp  %o7, 0x37
a00d3930:  12 bf ff a9  bne  0xa00d37d4
a00d3934:  d6 0b 60 9f  ldub  [ %o5 + 0x9f ], %o3
a00d3938:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00d393c:  c2 0a a0 9e  ldub  [ %o2 + 0x9e ], %g1	! 0xa802b09e
a00d3940:  80 a0 60 06  cmp  %g1, 6
a00d3944:  38 80 00 2e  bgu,a   0xa00d39fc
a00d3948:  94 10 3f e3  mov  -29, %o2
a00d394c:  1b 00 01 bc  sethi  %hi(0x6f000), %o5
a00d3950:  83 28 60 02  sll  %g1, 2, %g1
a00d3954:  90 13 60 f4  or  %o5, 0xf4, %o0
a00d3958:  d8 02 00 01  ld  [ %o0 + %g1 ], %o4
a00d395c:  81 c3 00 00  jmp  %o4
a00d3960:  01 00 00 00  nop
a00d3964:  10 bf ff af  b  0xa00d3820
a00d3968:  90 10 20 1a  mov  0x1a, %o0	! 0x1a
a00d396c:  10 bf ff ad  b  0xa00d3820
a00d3970:  90 10 20 0e  mov  0xe, %o0
a00d3974:  10 bf ff ab  b  0xa00d3820
a00d3978:  90 10 20 0a  mov  0xa, %o0
a00d397c:  10 bf ff a9  b  0xa00d3820
a00d3980:  90 10 20 06  mov  6, %o0
a00d3984:  10 bf ff a7  b  0xa00d3820
a00d3988:  90 10 20 12  mov  0x12, %o0
a00d398c:  10 bf ff a5  b  0xa00d3820
a00d3990:  90 10 20 02  mov  2, %o0
a00d3994:  10 bf ff 6b  b  0xa00d3740
a00d3998:  82 10 3f 93  mov  -109, %g1
a00d399c:  10 bf ff a1  b  0xa00d3820
a00d39a0:  90 10 20 19  mov  0x19, %o0
a00d39a4:  10 bf ff 9f  b  0xa00d3820
a00d39a8:  90 10 20 0d  mov  0xd, %o0
a00d39ac:  10 bf ff 9d  b  0xa00d3820
a00d39b0:  90 10 20 09  mov  9, %o0
a00d39b4:  10 bf ff 9b  b  0xa00d3820
a00d39b8:  90 10 20 05  mov  5, %o0
a00d39bc:  10 bf ff 99  b  0xa00d3820
a00d39c0:  90 10 20 23  mov  0x23, %o0
a00d39c4:  10 bf ff 97  b  0xa00d3820
a00d39c8:  90 10 20 1f  mov  0x1f, %o0
a00d39cc:  10 bf ff 95  b  0xa00d3820
a00d39d0:  90 10 20 21  mov  0x21, %o0
a00d39d4:  10 bf ff 93  b  0xa00d3820
a00d39d8:  90 10 20 1d  mov  0x1d, %o0
a00d39dc:  10 bf ff 91  b  0xa00d3820
a00d39e0:  90 10 20 17  mov  0x17, %o0
a00d39e4:  10 bf ff 8f  b  0xa00d3820
a00d39e8:  90 10 20 11  mov  0x11, %o0
a00d39ec:  10 bf ff 8d  b  0xa00d3820
a00d39f0:  90 10 20 15  mov  0x15, %o0
a00d39f4:  10 bf ff 8b  b  0xa00d3820
a00d39f8:  90 10 20 01  mov  1, %o0
a00d39fc:  94 0a a0 fb  and  %o2, 0xfb, %o2
a00d3a00:  92 10 00 10  mov  %l0, %o1
a00d3a04:  7f ff f6 07  call  0xa00d1220
a00d3a08:  90 10 00 19  mov  %i1, %o0
a00d3a0c:  7f fe d9 55  call  0xa0089f60
a00d3a10:  90 10 20 50  mov  0x50, %o0
a00d3a14:  90 0e 20 ff  and  %i0, 0xff, %o0
a00d3a18:  94 10 00 10  mov  %l0, %o2
a00d3a1c:  40 01 d3 23  call  0xa01486a8
a00d3a20:  92 10 20 19  mov  0x19, %o1
a00d3a24:  01 00 00 00  nop
a00d3a28:  81 c7 e0 08  ret
a00d3a2c:  81 e8 00 00  restore
