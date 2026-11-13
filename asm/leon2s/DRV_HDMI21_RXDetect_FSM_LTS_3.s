# leon2s DRV_HDMI21_RXDetect_FSM_LTS_3 0xa009860c-0xa0098b60 (1364 bytes)
a009860c:  9d e3 bf 98  save  %sp, -104, %sp
a0098610:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0098614:  80 a4 20 00  cmp  %l0, 0
a0098618:  02 80 00 04  be  0xa0098628
a009861c:  80 a4 20 01  cmp  %l0, 1
a0098620:  12 80 01 4e  bne  0xa0098b58
a0098624:  01 00 00 00  nop
a0098628:  7f ff d4 76  call  0xa008d800
a009862c:  01 00 00 00  nop
a0098630:  90 0a 20 ff  and  %o0, 0xff, %o0
a0098634:  80 a2 20 82  cmp  %o0, 0x82
a0098638:  18 80 00 05  bgu  0xa009864c
a009863c:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a0098640:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0098644:  82 10 60 d8  or  %g1, 0xd8, %g1	! 0xa80790d8
a0098648:  c0 28 40 10  clrb  [ %g1 + %l0 ]
a009864c:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a0098650:  9a 15 22 80  or  %l4, 0x280, %o5
a0098654:  a2 10 00 10  mov  %l0, %l1
a0098658:  2d 2a 01 f5  sethi  %hi(0xa807d400), %l6
a009865c:  a4 00 40 0d  add  %g1, %o5, %l2
a0098660:  a6 15 a2 48  or  %l6, 0x248, %l3
a0098664:  a1 2c 20 02  sll  %l0, 2, %l0
a0098668:  da 04 c0 10  ld  [ %l3 + %l0 ], %o5
a009866c:  c2 04 a0 30  ld  [ %l2 + 0x30 ], %g1
a0098670:  80 a3 40 01  cmp  %o5, %g1
a0098674:  02 80 00 11  be  0xa00986b8
a0098678:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009867c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0098680:  80 88 68 00  btst  0x800, %g1
a0098684:  22 80 00 08  be,a   0xa00986a4
a0098688:  c2 04 c0 10  ld  [ %l3 + %l0 ], %g1
a009868c:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a0098690:  13 28 02 d0  sethi  %hi(0xa00b4000), %o1
a0098694:  90 12 20 68  or  %o0, 0x68, %o0
a0098698:  7f ff 6a 6b  call  0xa0073044
a009869c:  92 12 62 f8  or  %o1, 0x2f8, %o1
a00986a0:  c2 04 c0 10  ld  [ %l3 + %l0 ], %g1
a00986a4:  c2 24 a0 30  st  %g1, [ %l2 + 0x30 ]
a00986a8:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00986ac:  9a 04 40 11  add  %l1, %l1, %o5
a00986b0:  82 10 60 86  or  %g1, 0x86, %g1
a00986b4:  c0 30 40 0d  clrh  [ %g1 + %o5 ]
a00986b8:  2b 2a 01 f6  sethi  %hi(0xa807d800), %l5
a00986bc:  a4 15 63 00  or  %l5, 0x300, %l2	! 0xa807db00
a00986c0:  a6 5c 60 34  smul  %l1, 0x34, %l3
a00986c4:  a0 04 c0 12  add  %l3, %l2, %l0
a00986c8:  d2 04 20 18  ld  [ %l0 + 0x18 ], %o1
a00986cc:  92 02 60 80  add  %o1, 0x80, %o1
a00986d0:  40 00 3b 41  call  0xa00a73d4
a00986d4:  90 10 20 04  mov  4, %o0
a00986d8:  7f ff ff 0a  call  0xa0098300
a00986dc:  90 10 00 11  mov  %l1, %o0
a00986e0:  80 8a 20 ff  btst  0xff, %o0
a00986e4:  02 80 00 2c  be  0xa0098794
a00986e8:  82 0e 20 ff  and  %i0, 0xff, %g1
a00986ec:  82 58 60 34  smul  %g1, 0x34, %g1
a00986f0:  98 00 40 12  add  %g1, %l2, %o4
a00986f4:  03 3c 3f ff  sethi  %hi(0xf0fffc00), %g1
a00986f8:  92 10 63 ff  or  %g1, 0x3ff, %o1	! 0xf0ffffff
a00986fc:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a0098700:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xfffffff
a0098704:  96 10 20 00  clr  %o3
a0098708:  82 0a e0 ff  and  %o3, 0xff, %g1
a009870c:  80 a0 60 00  cmp  %g1, 0
a0098710:  12 80 00 06  bne  0xa0098728
a0098714:  80 a0 60 01  cmp  %g1, 1
a0098718:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009871c:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a0098720:  10 80 00 07  b  0xa009873c
a0098724:  82 08 40 09  and  %g1, %o1, %g1
a0098728:  12 80 00 08  bne  0xa0098748
a009872c:  80 a0 60 02  cmp  %g1, 2
a0098730:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a0098734:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a0098738:  82 08 40 0a  and  %g1, %o2, %g1
a009873c:  c2 23 60 a0  st  %g1, [ %o5 + 0xa0 ]
a0098740:  10 80 00 0f  b  0xa009877c
a0098744:  96 02 e0 01  inc  %o3
a0098748:  12 80 00 06  bne  0xa0098760
a009874c:  80 a0 60 03  cmp  %g1, 3
a0098750:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a0098754:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a0098758:  10 80 00 07  b  0xa0098774
a009875c:  82 08 7f f0  and  %g1, -16, %g1
a0098760:  32 80 00 07  bne,a   0xa009877c
a0098764:  96 02 e0 01  inc  %o3
a0098768:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009876c:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a0098770:  82 08 7f 0f  and  %g1, -241, %g1
a0098774:  c2 23 60 a4  st  %g1, [ %o5 + 0xa4 ]
a0098778:  96 02 e0 01  inc  %o3
a009877c:  82 0a e0 ff  and  %o3, 0xff, %g1
a0098780:  80 a0 60 03  cmp  %g1, 3
a0098784:  08 bf ff e3  bleu  0xa0098710
a0098788:  80 a0 60 00  cmp  %g1, 0
a009878c:  10 80 00 6b  b  0xa0098938
a0098790:  82 0e 20 ff  and  %i0, 0xff, %g1
a0098794:  d2 04 20 18  ld  [ %l0 + 0x18 ], %o1
a0098798:  92 02 60 80  add  %o1, 0x80, %o1
a009879c:  40 00 3b 1b  call  0xa00a7408
a00987a0:  90 10 20 05  mov  5, %o0
a00987a4:  80 a2 20 00  cmp  %o0, 0
a00987a8:  02 80 00 31  be  0xa009886c
a00987ac:  9a 04 40 11  add  %l1, %l1, %o5
a00987b0:  21 2a 01 e4  sethi  %hi(0xa8079000), %l0
a00987b4:  82 14 20 86  or  %l0, 0x86, %g1	! 0xa8079086
a00987b8:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00987bc:  80 a0 60 00  cmp  %g1, 0
a00987c0:  12 80 00 0b  bne  0xa00987ec
a00987c4:  b0 14 20 86  or  %l0, 0x86, %i0
a00987c8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00987cc:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a00987d0:  80 88 68 00  btst  0x800, %g1
a00987d4:  22 80 00 07  be,a   0xa00987f0
a00987d8:  a0 04 40 11  add  %l1, %l1, %l0
a00987dc:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a00987e0:  7f ff 6b 39  call  0xa00734c4
a00987e4:  90 12 20 90  or  %o0, 0x90, %o0	! 0xa0069c90
a00987e8:  b0 14 20 86  or  %l0, 0x86, %i0
a00987ec:  a0 04 40 11  add  %l1, %l1, %l0
a00987f0:  da 16 00 10  lduh  [ %i0 + %l0 ], %o5
a00987f4:  9a 03 60 01  inc  %o5
a00987f8:  83 2b 60 10  sll  %o5, 0x10, %g1
a00987fc:  83 30 60 10  srl  %g1, 0x10, %g1
a0098800:  80 a0 61 2b  cmp  %g1, 0x12b
a0098804:  08 80 00 d5  bleu  0xa0098b58
a0098808:  da 36 00 10  sth  %o5, [ %i0 + %l0 ]
a009880c:  82 15 63 00  or  %l5, 0x300, %g1
a0098810:  9a 5c 60 34  smul  %l1, 0x34, %o5
a0098814:  9a 03 40 01  add  %o5, %g1, %o5
a0098818:  d2 03 60 18  ld  [ %o5 + 0x18 ], %o1
a009881c:  c0 36 00 10  clrh  [ %i0 + %l0 ]
a0098820:  92 02 60 90  add  %o1, 0x90, %o1
a0098824:  40 00 3a f9  call  0xa00a7408
a0098828:  90 10 20 11  mov  0x11, %o0
a009882c:  80 a2 20 00  cmp  %o0, 0
a0098830:  02 80 00 06  be  0xa0098848
a0098834:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0098838:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a009883c:  7f ff 6b 22  call  0xa00734c4
a0098840:  90 12 20 a8  or  %o0, 0xa8, %o0	! 0xa0069ca8
a0098844:  30 80 00 c5  b,a   0xa0098b58
a0098848:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1
a009884c:  80 88 68 00  btst  0x800, %g1
a0098850:  02 80 00 c2  be  0xa0098b58
a0098854:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a0098858:  d4 16 00 10  lduh  [ %i0 + %l0 ], %o2
a009885c:  92 10 00 11  mov  %l1, %o1
a0098860:  7f ff 69 f9  call  0xa0073044
a0098864:  90 12 20 b8  or  %o0, 0xb8, %o0
a0098868:  30 80 00 bc  b,a   0xa0098b58
a009886c:  9a 15 22 80  or  %l4, 0x280, %o5
a0098870:  82 5c 60 b0  smul  %l1, 0xb0, %g1
a0098874:  82 00 40 0d  add  %g1, %o5, %g1
a0098878:  c0 28 60 14  clrb  [ %g1 + 0x14 ]
a009887c:  7f ff fe a1  call  0xa0098300
a0098880:  90 10 00 11  mov  %l1, %o0
a0098884:  80 8a 20 ff  btst  0xff, %o0
a0098888:  22 80 00 31  be,a   0xa009894c
a009888c:  c2 04 20 18  ld  [ %l0 + 0x18 ], %g1
a0098890:  82 0e 20 ff  and  %i0, 0xff, %g1
a0098894:  82 58 60 34  smul  %g1, 0x34, %g1
a0098898:  98 00 40 12  add  %g1, %l2, %o4
a009889c:  03 3c 3f ff  sethi  %hi(0xf0fffc00), %g1
a00988a0:  92 10 63 ff  or  %g1, 0x3ff, %o1	! 0xf0ffffff
a00988a4:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a00988a8:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xfffffff
a00988ac:  96 10 20 00  clr  %o3
a00988b0:  82 0a e0 ff  and  %o3, 0xff, %g1
a00988b4:  80 a0 60 00  cmp  %g1, 0
a00988b8:  12 80 00 06  bne  0xa00988d0
a00988bc:  80 a0 60 01  cmp  %g1, 1
a00988c0:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a00988c4:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a00988c8:  10 80 00 07  b  0xa00988e4
a00988cc:  82 08 40 09  and  %g1, %o1, %g1
a00988d0:  12 80 00 08  bne  0xa00988f0
a00988d4:  80 a0 60 02  cmp  %g1, 2
a00988d8:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a00988dc:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a00988e0:  82 08 40 0a  and  %g1, %o2, %g1
a00988e4:  c2 23 60 a0  st  %g1, [ %o5 + 0xa0 ]
a00988e8:  10 80 00 0f  b  0xa0098924
a00988ec:  96 02 e0 01  inc  %o3
a00988f0:  12 80 00 06  bne  0xa0098908
a00988f4:  80 a0 60 03  cmp  %g1, 3
a00988f8:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a00988fc:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a0098900:  10 80 00 07  b  0xa009891c
a0098904:  82 08 7f f0  and  %g1, -16, %g1
a0098908:  32 80 00 07  bne,a   0xa0098924
a009890c:  96 02 e0 01  inc  %o3
a0098910:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a0098914:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a0098918:  82 08 7f 0f  and  %g1, -241, %g1
a009891c:  c2 23 60 a4  st  %g1, [ %o5 + 0xa4 ]
a0098920:  96 02 e0 01  inc  %o3
a0098924:  82 0a e0 ff  and  %o3, 0xff, %g1
a0098928:  80 a0 60 03  cmp  %g1, 3
a009892c:  08 bf ff e3  bleu  0xa00988b8
a0098930:  80 a0 60 00  cmp  %g1, 0
a0098934:  82 0e 20 ff  and  %i0, 0xff, %g1
a0098938:  98 15 a2 48  or  %l6, 0x248, %o4
a009893c:  83 28 60 02  sll  %g1, 2, %g1
a0098940:  9a 10 20 07  mov  7, %o5
a0098944:  10 80 00 85  b  0xa0098b58
a0098948:  da 23 00 01  st  %o5, [ %o4 + %g1 ]
a009894c:  c2 00 60 90  ld  [ %g1 + 0x90 ], %g1
a0098950:  83 30 60 18  srl  %g1, 0x18, %g1
a0098954:  80 88 60 0f  btst  0xf, %g1
a0098958:  02 80 00 80  be  0xa0098b58
a009895c:  01 00 00 00  nop
a0098960:  d2 04 80 13  ld  [ %l2 + %l3 ], %o1
a0098964:  92 02 60 08  add  %o1, 8, %o1
a0098968:  40 00 3a 91  call  0xa00a73ac
a009896c:  90 10 20 0b  mov  0xb, %o0
a0098970:  7f ff fe be  call  0xa0098468
a0098974:  90 10 00 11  mov  %l1, %o0
a0098978:  82 0e 20 ff  and  %i0, 0xff, %g1
a009897c:  82 58 60 34  smul  %g1, 0x34, %g1
a0098980:  98 00 40 12  add  %g1, %l2, %o4
a0098984:  03 3c 3f ff  sethi  %hi(0xf0fffc00), %g1
a0098988:  92 10 63 ff  or  %g1, 0x3ff, %o1	! 0xf0ffffff
a009898c:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a0098990:  96 10 63 ff  or  %g1, 0x3ff, %o3	! 0xfffffff
a0098994:  94 10 20 00  clr  %o2
a0098998:  82 0a a0 ff  and  %o2, 0xff, %g1
a009899c:  80 a0 60 00  cmp  %g1, 0
a00989a0:  12 80 00 06  bne  0xa00989b8
a00989a4:  80 a0 60 01  cmp  %g1, 1
a00989a8:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a00989ac:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a00989b0:  10 80 00 07  b  0xa00989cc
a00989b4:  82 08 40 09  and  %g1, %o1, %g1
a00989b8:  12 80 00 08  bne  0xa00989d8
a00989bc:  80 a0 60 02  cmp  %g1, 2
a00989c0:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a00989c4:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a00989c8:  82 08 40 0b  and  %g1, %o3, %g1
a00989cc:  c2 23 60 a0  st  %g1, [ %o5 + 0xa0 ]
a00989d0:  10 80 00 0f  b  0xa0098a0c
a00989d4:  94 02 a0 01  inc  %o2
a00989d8:  12 80 00 06  bne  0xa00989f0
a00989dc:  80 a0 60 03  cmp  %g1, 3
a00989e0:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a00989e4:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a00989e8:  10 80 00 07  b  0xa0098a04
a00989ec:  82 08 7f f0  and  %g1, -16, %g1
a00989f0:  32 80 00 07  bne,a   0xa0098a0c
a00989f4:  94 02 a0 01  inc  %o2
a00989f8:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a00989fc:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a0098a00:  82 08 7f 0f  and  %g1, -241, %g1
a0098a04:  c2 23 60 a4  st  %g1, [ %o5 + 0xa4 ]
a0098a08:  94 02 a0 01  inc  %o2
a0098a0c:  82 0a a0 ff  and  %o2, 0xff, %g1
a0098a10:  80 a0 60 03  cmp  %g1, 3
a0098a14:  08 bf ff e3  bleu  0xa00989a0
a0098a18:  80 a0 60 00  cmp  %g1, 0
a0098a1c:  98 0e 20 ff  and  %i0, 0xff, %o4
a0098a20:  92 15 22 80  or  %l4, 0x280, %o1
a0098a24:  82 5b 20 b0  smul  %o4, 0xb0, %g1
a0098a28:  c2 0a 40 01  ldub  [ %o1 + %g1 ], %g1
a0098a2c:  80 a0 60 00  cmp  %g1, 0
a0098a30:  02 80 00 39  be  0xa0098b14
a0098a34:  94 10 20 00  clr  %o2
a0098a38:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a0098a3c:  90 10 63 00  or  %g1, 0x300, %o0	! 0xa807db00
a0098a40:  03 3c 3f ff  sethi  %hi(0xf0fffc00), %g1
a0098a44:  a2 10 63 ff  or  %g1, 0x3ff, %l1	! 0xf0ffffff
a0098a48:  9a 5b 20 34  smul  %o4, 0x34, %o5
a0098a4c:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a0098a50:  9e 10 00 09  mov  %o1, %o7
a0098a54:  96 03 40 08  add  %o5, %o0, %o3
a0098a58:  a0 10 63 ff  or  %g1, 0x3ff, %l0
a0098a5c:  13 01 40 00  sethi  %hi(0x5000000), %o1
a0098a60:  82 5b 20 34  smul  %o4, 0x34, %g1
a0098a64:  98 0a a0 ff  and  %o2, 0xff, %o4
a0098a68:  80 a3 20 00  cmp  %o4, 0
a0098a6c:  12 80 00 09  bne  0xa0098a90
a0098a70:  82 00 40 08  add  %g1, %o0, %g1
a0098a74:  da 00 60 18  ld  [ %g1 + 0x18 ], %o5
a0098a78:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a0098a7c:  82 08 40 11  and  %g1, %l1, %g1
a0098a80:  82 10 40 09  or  %g1, %o1, %g1
a0098a84:  c2 23 60 a0  st  %g1, [ %o5 + 0xa0 ]
a0098a88:  10 80 00 1c  b  0xa0098af8
a0098a8c:  98 0e 20 ff  and  %i0, 0xff, %o4
a0098a90:  80 a3 20 01  cmp  %o4, 1
a0098a94:  12 80 00 0a  bne  0xa0098abc
a0098a98:  80 a3 20 02  cmp  %o4, 2
a0098a9c:  c2 02 e0 18  ld  [ %o3 + 0x18 ], %g1
a0098aa0:  da 00 60 a0  ld  [ %g1 + 0xa0 ], %o5
a0098aa4:  9a 0b 40 10  and  %o5, %l0, %o5
a0098aa8:  19 18 00 00  sethi  %hi(0x60000000), %o4
a0098aac:  9a 13 40 0c  or  %o5, %o4, %o5
a0098ab0:  da 20 60 a0  st  %o5, [ %g1 + 0xa0 ]
a0098ab4:  10 80 00 11  b  0xa0098af8
a0098ab8:  98 0e 20 ff  and  %i0, 0xff, %o4
a0098abc:  12 80 00 07  bne  0xa0098ad8
a0098ac0:  80 a3 20 03  cmp  %o4, 3
a0098ac4:  da 02 e0 18  ld  [ %o3 + 0x18 ], %o5
a0098ac8:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a0098acc:  82 08 7f f0  and  %g1, -16, %g1
a0098ad0:  10 80 00 08  b  0xa0098af0
a0098ad4:  82 10 60 07  or  %g1, 7, %g1
a0098ad8:  12 80 00 08  bne  0xa0098af8
a0098adc:  98 0e 20 ff  and  %i0, 0xff, %o4
a0098ae0:  da 02 e0 18  ld  [ %o3 + 0x18 ], %o5
a0098ae4:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a0098ae8:  82 08 7f 0f  and  %g1, -241, %g1
a0098aec:  82 10 60 80  or  %g1, 0x80, %g1
a0098af0:  c2 23 60 a4  st  %g1, [ %o5 + 0xa4 ]
a0098af4:  98 0e 20 ff  and  %i0, 0xff, %o4
a0098af8:  82 5b 20 b0  smul  %o4, 0xb0, %g1
a0098afc:  da 0b c0 01  ldub  [ %o7 + %g1 ], %o5
a0098b00:  94 02 a0 01  inc  %o2
a0098b04:  82 0a a0 ff  and  %o2, 0xff, %g1
a0098b08:  80 a0 40 0d  cmp  %g1, %o5
a0098b0c:  0a bf ff d6  bcs  0xa0098a64
a0098b10:  82 5b 20 34  smul  %o4, 0x34, %g1
a0098b14:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0098b18:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a0098b1c:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a0098b20:  9a 5c 20 34  smul  %l0, 0x34, %o5
a0098b24:  9a 03 40 01  add  %o5, %g1, %o5
a0098b28:  d2 03 60 18  ld  [ %o5 + 0x18 ], %o1
a0098b2c:  92 02 60 80  add  %o1, 0x80, %o1
a0098b30:  40 00 3a 1f  call  0xa00a73ac
a0098b34:  90 10 20 05  mov  5, %o0
a0098b38:  98 04 00 10  add  %l0, %l0, %o4
a0098b3c:  82 10 20 04  mov  4, %g1
a0098b40:  9a 15 a2 48  or  %l6, 0x248, %o5
a0098b44:  a1 2c 20 02  sll  %l0, 2, %l0
a0098b48:  c2 23 40 10  st  %g1, [ %o5 + %l0 ]
a0098b4c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0098b50:  82 10 60 8a  or  %g1, 0x8a, %g1	! 0xa807908a
a0098b54:  c0 30 40 0c  clrh  [ %g1 + %o4 ]
a0098b58:  81 c7 e0 08  ret
a0098b5c:  91 e8 20 00  restore  %g0, 0, %o0
