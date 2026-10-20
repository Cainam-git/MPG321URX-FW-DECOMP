# leon2s MAX_CED 0xa009967c-0xa0099c18 (1436 bytes)
a009967c:  9d e3 bf 90  save  %sp, -112, %sp
a0099680:  a4 0e 20 ff  and  %i0, 0xff, %l2
a0099684:  98 10 20 00  clr  %o4
a0099688:  9a 10 20 00  clr  %o5
a009968c:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0099690:  80 a4 a0 00  cmp  %l2, 0
a0099694:  a6 10 20 00  clr  %l3
a0099698:  02 80 00 05  be  0xa00996ac
a009969c:  a2 10 20 02  mov  2, %l1
a00996a0:  80 a4 a0 01  cmp  %l2, 1
a00996a4:  12 80 01 5b  bne  0xa0099c10
a00996a8:  a2 10 20 03  mov  3, %l1
a00996ac:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a00996b0:  82 15 22 80  or  %l4, 0x280, %g1	! 0xa807d680
a00996b4:  9a 5c a0 b0  smul  %l2, 0xb0, %o5
a00996b8:  98 03 40 01  add  %o5, %g1, %o4
a00996bc:  c2 0b 20 8f  ldub  [ %o4 + 0x8f ], %g1
a00996c0:  80 a0 60 00  cmp  %g1, 0
a00996c4:  12 80 00 0e  bne  0xa00996fc
a00996c8:  82 15 22 80  or  %l4, 0x280, %g1
a00996cc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00996d0:  da 00 62 34  ld  [ %g1 + 0x234 ], %o5	! 0xa8078634
a00996d4:  03 00 00 08  sethi  %hi(0x2000), %g1
a00996d8:  80 8b 40 01  btst  %o5, %g1
a00996dc:  02 80 00 07  be  0xa00996f8
a00996e0:  82 15 22 80  or  %l4, 0x280, %g1
a00996e4:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a00996e8:  90 12 20 38  or  %o0, 0x38, %o0	! 0xa006a038
a00996ec:  7f ff 66 56  call  0xa0073044
a00996f0:  d2 0b 20 8e  ldub  [ %o4 + 0x8e ], %o1
a00996f4:  82 15 22 80  or  %l4, 0x280, %g1
a00996f8:  9a 5c a0 b0  smul  %l2, 0xb0, %o5
a00996fc:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a0099700:  80 a0 60 00  cmp  %g1, 0
a0099704:  02 80 00 5a  be  0xa009986c
a0099708:  aa 10 20 00  clr  %l5
a009970c:  a0 0d 60 ff  and  %l5, 0xff, %l0
a0099710:  15 00 00 0b  sethi  %hi(0x2c00), %o2
a0099714:  80 a4 20 00  cmp  %l0, 0
a0099718:  02 80 00 0b  be  0xa0099744
a009971c:  94 12 a2 64  or  %o2, 0x264, %o2
a0099720:  15 00 00 0b  sethi  %hi(0x2c00), %o2
a0099724:  80 a4 20 01  cmp  %l0, 1
a0099728:  02 80 00 0d  be  0xa009975c
a009972c:  94 12 a2 64  or  %o2, 0x264, %o2
a0099730:  80 a4 20 02  cmp  %l0, 2
a0099734:  12 80 00 06  bne  0xa009974c
a0099738:  80 a4 20 03  cmp  %l0, 3
a009973c:  15 00 00 0b  sethi  %hi(0x2c00), %o2
a0099740:  94 12 a2 68  or  %o2, 0x268, %o2	! 0x2e68
a0099744:  10 80 00 07  b  0xa0099760
a0099748:  90 10 20 0f  mov  0xf, %o0
a009974c:  12 80 00 0b  bne  0xa0099778
a0099750:  80 8c e0 ff  btst  0xff, %l3
a0099754:  15 00 00 0b  sethi  %hi(0x2c00), %o2
a0099758:  94 12 a2 68  or  %o2, 0x268, %o2	! 0x2e68
a009975c:  90 10 20 1f  mov  0x1f, %o0
a0099760:  40 00 37 42  call  0xa00a7468
a0099764:  92 0c 60 ff  and  %l1, 0xff, %o1
a0099768:  80 a0 00 08  cmp  %g0, %o0
a009976c:  82 40 20 00  addx  %g0, 0, %g1
a0099770:  a6 10 00 01  mov  %g1, %l3
a0099774:  80 8c e0 ff  btst  0xff, %l3
a0099778:  02 80 00 2b  be  0xa0099824
a009977c:  82 04 00 10  add  %l0, %l0, %g1
a0099780:  80 a4 20 00  cmp  %l0, 0
a0099784:  12 80 00 0a  bne  0xa00997ac
a0099788:  80 a4 20 01  cmp  %l0, 1
a009978c:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0099790:  92 12 62 64  or  %o1, 0x264, %o1	! 0x2e64
a0099794:  40 00 36 e0  call  0xa00a7314
a0099798:  90 0c 60 ff  and  %l1, 0xff, %o0
a009979c:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00997a0:  82 2a 00 01  andn  %o0, %g1, %g1
a00997a4:  10 80 00 2a  b  0xa009984c
a00997a8:  c2 37 bf f0  sth  %g1, [ %fp + -16 ]
a00997ac:  12 80 00 0a  bne  0xa00997d4
a00997b0:  80 a4 20 02  cmp  %l0, 2
a00997b4:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a00997b8:  92 12 62 64  or  %o1, 0x264, %o1	! 0x2e64
a00997bc:  40 00 36 d6  call  0xa00a7314
a00997c0:  90 0c 60 ff  and  %l1, 0xff, %o0
a00997c4:  90 02 00 08  add  %o0, %o0, %o0
a00997c8:  91 32 20 11  srl  %o0, 0x11, %o0
a00997cc:  10 80 00 20  b  0xa009984c
a00997d0:  d0 37 bf f2  sth  %o0, [ %fp + -14 ]
a00997d4:  12 80 00 0a  bne  0xa00997fc
a00997d8:  80 a4 20 03  cmp  %l0, 3
a00997dc:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a00997e0:  92 12 62 68  or  %o1, 0x268, %o1	! 0x2e68
a00997e4:  40 00 36 cc  call  0xa00a7314
a00997e8:  90 0c 60 ff  and  %l1, 0xff, %o0
a00997ec:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00997f0:  82 2a 00 01  andn  %o0, %g1, %g1
a00997f4:  10 80 00 16  b  0xa009984c
a00997f8:  c2 37 bf f4  sth  %g1, [ %fp + -12 ]
a00997fc:  12 80 00 15  bne  0xa0099850
a0099800:  82 5c a0 b0  smul  %l2, 0xb0, %g1
a0099804:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0099808:  92 12 62 68  or  %o1, 0x268, %o1	! 0x2e68
a009980c:  40 00 36 c2  call  0xa00a7314
a0099810:  90 0c 60 ff  and  %l1, 0xff, %o0
a0099814:  90 02 00 08  add  %o0, %o0, %o0
a0099818:  91 32 20 11  srl  %o0, 0x11, %o0
a009981c:  10 80 00 0c  b  0xa009984c
a0099820:  d0 37 bf f6  sth  %o0, [ %fp + -10 ]
a0099824:  98 07 80 01  add  %fp, %g1, %o4
a0099828:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009982c:  da 00 62 34  ld  [ %g1 + 0x234 ], %o5	! 0xa8078634
a0099830:  03 00 00 08  sethi  %hi(0x2000), %g1
a0099834:  80 8b 40 01  btst  %o5, %g1
a0099838:  02 80 00 05  be  0xa009984c
a009983c:  c0 33 3f f0  clrh  [ %o4 + -16 ]
a0099840:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a0099844:  7f ff 67 20  call  0xa00734c4
a0099848:  90 12 20 60  or  %o0, 0x60, %o0	! 0xa006a060
a009984c:  82 5c a0 b0  smul  %l2, 0xb0, %g1
a0099850:  9a 15 22 80  or  %l4, 0x280, %o5
a0099854:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a0099858:  aa 05 60 01  inc  %l5
a009985c:  82 0d 60 ff  and  %l5, 0xff, %g1
a0099860:  80 a0 40 0d  cmp  %g1, %o5
a0099864:  2a bf ff ab  bcs,a   0xa0099710
a0099868:  a0 0d 60 ff  and  %l5, 0xff, %l0
a009986c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0099870:  96 0e 20 ff  and  %i0, 0xff, %o3
a0099874:  94 10 62 80  or  %g1, 0x280, %o2
a0099878:  98 5a e0 b0  smul  %o3, 0xb0, %o4
a009987c:  c2 0a 80 0c  ldub  [ %o2 + %o4 ], %g1
a0099880:  80 a0 60 00  cmp  %g1, 0
a0099884:  02 80 00 c2  be  0xa0099b8c
a0099888:  aa 10 20 00  clr  %l5
a009988c:  a0 0d 60 ff  and  %l5, 0xff, %l0
a0099890:  82 04 00 10  add  %l0, %l0, %g1
a0099894:  a6 07 bf f8  add  %fp, -8, %l3
a0099898:  82 00 40 13  add  %g1, %l3, %g1
a009989c:  da 10 7f f8  lduh  [ %g1 + -8 ], %o5
a00998a0:  03 00 00 1f  sethi  %hi(0x7c00), %g1
a00998a4:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0x7fff
a00998a8:  80 a3 40 01  cmp  %o5, %g1
a00998ac:  12 80 00 17  bne  0xa0099908
a00998b0:  2d 2a 01 f5  sethi  %hi(0xa807d400), %l6
a00998b4:  82 03 00 0a  add  %o4, %o2, %g1
a00998b8:  a2 00 40 10  add  %g1, %l0, %l1
a00998bc:  c2 0c 60 92  ldub  [ %l1 + 0x92 ], %g1
a00998c0:  80 a0 60 00  cmp  %g1, 0
a00998c4:  12 80 00 12  bne  0xa009990c
a00998c8:  a4 0e 20 ff  and  %i0, 0xff, %l2
a00998cc:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00998d0:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00998d4:  9a 5a e0 34  smul  %o3, 0x34, %o5
a00998d8:  9a 03 40 01  add  %o5, %g1, %o5
a00998dc:  d2 03 60 0c  ld  [ %o5 + 0xc ], %o1
a00998e0:  92 02 60 60  add  %o1, 0x60, %o1
a00998e4:  40 00 36 b2  call  0xa00a73ac
a00998e8:  90 10 20 01  mov  1, %o0
a00998ec:  82 10 20 01  mov  1, %g1
a00998f0:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a00998f4:  c2 2c 60 92  stb  %g1, [ %l1 + 0x92 ]
a00998f8:  90 12 20 80  or  %o0, 0x80, %o0
a00998fc:  7f ff 65 d2  call  0xa0073044
a0099900:  92 10 00 10  mov  %l0, %o1
a0099904:  2d 2a 01 f5  sethi  %hi(0xa807d400), %l6
a0099908:  a4 0e 20 ff  and  %i0, 0xff, %l2
a009990c:  82 5c a0 b0  smul  %l2, 0xb0, %g1
a0099910:  96 15 a2 80  or  %l6, 0x280, %o3
a0099914:  98 00 40 0b  add  %g1, %o3, %o4
a0099918:  c2 0b 20 8f  ldub  [ %o4 + 0x8f ], %g1
a009991c:  80 a0 60 00  cmp  %g1, 0
a0099920:  12 80 00 92  bne  0xa0099b68
a0099924:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0099928:  83 2c 20 02  sll  %l0, 2, %g1
a009992c:  82 00 40 10  add  %g1, %l0, %g1
a0099930:  9a 5c a0 58  smul  %l2, 0x58, %o5
a0099934:  82 00 40 01  add  %g1, %g1, %g1
a0099938:  82 00 40 0d  add  %g1, %o5, %g1
a009993c:  da 0b 20 8e  ldub  [ %o4 + 0x8e ], %o5
a0099940:  82 00 40 0d  add  %g1, %o5, %g1
a0099944:  9a 04 00 10  add  %l0, %l0, %o5
a0099948:  9a 03 40 13  add  %o5, %l3, %o5
a009994c:  82 00 40 01  add  %g1, %g1, %g1
a0099950:  82 00 40 0b  add  %g1, %o3, %g1
a0099954:  da 13 7f f8  lduh  [ %o5 + -8 ], %o5
a0099958:  da 30 60 3e  sth  %o5, [ %g1 + 0x3e ]
a009995c:  a2 10 20 00  clr  %l1
a0099960:  83 2c 20 02  sll  %l0, 2, %g1
a0099964:  82 00 40 10  add  %g1, %l0, %g1
a0099968:  9a 5c a0 58  smul  %l2, 0x58, %o5
a009996c:  82 00 40 01  add  %g1, %g1, %g1
a0099970:  82 00 40 0d  add  %g1, %o5, %g1
a0099974:  9a 0c 60 ff  and  %l1, 0xff, %o5
a0099978:  82 00 40 0d  add  %g1, %o5, %g1
a009997c:  82 00 40 01  add  %g1, %g1, %g1
a0099980:  9a 15 a2 80  or  %l6, 0x280, %o5
a0099984:  29 2a 01 e1  sethi  %hi(0xa8078400), %l4
a0099988:  9a 00 40 0d  add  %g1, %o5, %o5
a009998c:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a0099990:  27 00 00 08  sethi  %hi(0x2000), %l3
a0099994:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a0099998:  a2 04 60 01  inc  %l1
a009999c:  80 88 40 13  btst  %g1, %l3
a00999a0:  02 80 00 04  be  0xa00999b0
a00999a4:  90 12 20 e8  or  %o0, 0xe8, %o0
a00999a8:  7f ff 65 a7  call  0xa0073044
a00999ac:  d2 13 60 3e  lduh  [ %o5 + 0x3e ], %o1
a00999b0:  82 0c 60 ff  and  %l1, 0xff, %g1
a00999b4:  80 a0 60 09  cmp  %g1, 9
a00999b8:  08 bf ff eb  bleu  0xa0099964
a00999bc:  83 2c 20 02  sll  %l0, 2, %g1
a00999c0:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00999c4:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00999c8:  90 10 62 80  or  %g1, 0x280, %o0
a00999cc:  82 5c 60 b0  smul  %l1, 0xb0, %g1
a00999d0:  82 00 40 08  add  %g1, %o0, %g1
a00999d4:  da 08 60 91  ldub  [ %g1 + 0x91 ], %o5
a00999d8:  80 a3 60 00  cmp  %o5, 0
a00999dc:  d4 08 60 8e  ldub  [ %g1 + 0x8e ], %o2
a00999e0:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00999e4:  02 80 00 3a  be  0xa0099acc
a00999e8:  92 5c 60 58  smul  %l1, 0x58, %o1
a00999ec:  94 0a a0 ff  and  %o2, 0xff, %o2
a00999f0:  03 19 99 99  sethi  %hi(0x66666400), %g1
a00999f4:  96 02 a0 01  add  %o2, 1, %o3
a00999f8:  82 10 62 67  or  %g1, 0x267, %g1
a00999fc:  80 5a c0 01  smul  %o3, %g1, %g0
a0099a00:  83 40 00 00  rd  %y, %g1
a0099a04:  83 38 60 02  sra  %g1, 2, %g1
a0099a08:  99 28 60 02  sll  %g1, 2, %o4
a0099a0c:  9b 2c 20 02  sll  %l0, 2, %o5
a0099a10:  98 03 00 01  add  %o4, %g1, %o4
a0099a14:  9a 03 40 10  add  %o5, %l0, %o5
a0099a18:  9a 03 40 0d  add  %o5, %o5, %o5
a0099a1c:  98 03 00 0c  add  %o4, %o4, %o4
a0099a20:  9a 03 40 09  add  %o5, %o1, %o5
a0099a24:  96 22 c0 0c  sub  %o3, %o4, %o3
a0099a28:  96 03 40 0b  add  %o5, %o3, %o3
a0099a2c:  9a 03 40 0a  add  %o5, %o2, %o5
a0099a30:  9a 03 40 0d  add  %o5, %o5, %o5
a0099a34:  96 02 c0 0b  add  %o3, %o3, %o3
a0099a38:  96 02 c0 08  add  %o3, %o0, %o3
a0099a3c:  9a 03 40 08  add  %o5, %o0, %o5
a0099a40:  d4 13 60 3e  lduh  [ %o5 + 0x3e ], %o2
a0099a44:  c2 12 e0 3e  lduh  [ %o3 + 0x3e ], %g1
a0099a48:  80 a2 80 01  cmp  %o2, %g1
a0099a4c:  1a 80 00 0b  bcc  0xa0099a78
a0099a50:  94 22 80 01  sub  %o2, %g1, %o2
a0099a54:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a0099a58:  80 88 40 13  btst  %g1, %l3
a0099a5c:  02 80 00 04  be  0xa0099a6c
a0099a60:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a0099a64:  7f ff 66 98  call  0xa00734c4
a0099a68:  90 12 20 90  or  %o0, 0x90, %o0	! 0xa006a090
a0099a6c:  7f ff fe bd  call  0xa0099560
a0099a70:  90 10 00 11  mov  %l1, %o0
a0099a74:  30 80 00 67  b,a   0xa0099c10
a0099a78:  80 a2 a0 04  cmp  %o2, 4
a0099a7c:  04 80 00 32  ble  0xa0099b44
a0099a80:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0099a84:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a0099a88:  80 88 40 13  btst  %g1, %l3
a0099a8c:  02 80 00 07  be  0xa0099aa8
a0099a90:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a0099a94:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a0099a98:  90 12 20 c0  or  %o0, 0xc0, %o0	! 0xa006a0c0
a0099a9c:  7f ff 65 6a  call  0xa0073044
a0099aa0:  92 10 00 10  mov  %l0, %o1
a0099aa4:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a0099aa8:  82 5c 60 34  smul  %l1, 0x34, %g1
a0099aac:  9a 13 63 00  or  %o5, 0x300, %o5
a0099ab0:  82 00 40 0d  add  %g1, %o5, %g1
a0099ab4:  d2 00 60 0c  ld  [ %g1 + 0xc ], %o1
a0099ab8:  92 02 60 60  add  %o1, 0x60, %o1
a0099abc:  40 00 36 3c  call  0xa00a73ac
a0099ac0:  90 10 20 01  mov  1, %o0
a0099ac4:  10 80 00 20  b  0xa0099b44
a0099ac8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0099acc:  83 2c 20 02  sll  %l0, 2, %g1
a0099ad0:  82 00 40 10  add  %g1, %l0, %g1
a0099ad4:  82 00 40 01  add  %g1, %g1, %g1
a0099ad8:  82 00 40 09  add  %g1, %o1, %g1
a0099adc:  9a 0a a0 ff  and  %o2, 0xff, %o5
a0099ae0:  82 00 40 0d  add  %g1, %o5, %g1
a0099ae4:  82 00 40 01  add  %g1, %g1, %g1
a0099ae8:  82 00 40 08  add  %g1, %o0, %g1
a0099aec:  e4 10 60 3e  lduh  [ %g1 + 0x3e ], %l2
a0099af0:  80 a4 a0 04  cmp  %l2, 4
a0099af4:  08 80 00 14  bleu  0xa0099b44
a0099af8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0099afc:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a0099b00:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a0099b04:  9a 5c 60 34  smul  %l1, 0x34, %o5
a0099b08:  9a 03 40 01  add  %o5, %g1, %o5
a0099b0c:  d2 03 60 0c  ld  [ %o5 + 0xc ], %o1
a0099b10:  92 02 60 60  add  %o1, 0x60, %o1
a0099b14:  40 00 36 26  call  0xa00a73ac
a0099b18:  90 10 20 01  mov  1, %o0
a0099b1c:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a0099b20:  80 88 40 13  btst  %g1, %l3
a0099b24:  02 80 00 08  be  0xa0099b44
a0099b28:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0099b2c:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a0099b30:  90 12 20 c0  or  %o0, 0xc0, %o0	! 0xa006a0c0
a0099b34:  92 10 00 10  mov  %l0, %o1
a0099b38:  7f ff 65 43  call  0xa0073044
a0099b3c:  94 10 00 12  mov  %l2, %o2
a0099b40:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0099b44:  da 00 62 34  ld  [ %g1 + 0x234 ], %o5	! 0xa8078634
a0099b48:  03 00 00 08  sethi  %hi(0x2000), %g1
a0099b4c:  80 8b 40 01  btst  %o5, %g1
a0099b50:  02 80 00 06  be  0xa0099b68
a0099b54:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0099b58:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a0099b5c:  7f ff 66 5a  call  0xa00734c4
a0099b60:  90 12 22 e8  or  %o0, 0x2e8, %o0	! 0xa0069ee8
a0099b64:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0099b68:  96 0e 20 ff  and  %i0, 0xff, %o3
a0099b6c:  94 10 62 80  or  %g1, 0x280, %o2
a0099b70:  aa 05 60 01  inc  %l5
a0099b74:  98 5a e0 b0  smul  %o3, 0xb0, %o4
a0099b78:  9a 0d 60 ff  and  %l5, 0xff, %o5
a0099b7c:  c2 0a 80 0c  ldub  [ %o2 + %o4 ], %g1
a0099b80:  80 a3 40 01  cmp  %o5, %g1
a0099b84:  0a bf ff 43  bcs  0xa0099890
a0099b88:  a0 0d 60 ff  and  %l5, 0xff, %l0
a0099b8c:  98 0e 20 ff  and  %i0, 0xff, %o4
a0099b90:  15 2a 01 f5  sethi  %hi(0xa807d400), %o2
a0099b94:  82 12 a2 80  or  %o2, 0x280, %g1	! 0xa807d680
a0099b98:  9a 5b 20 b0  smul  %o4, 0xb0, %o5
a0099b9c:  96 03 40 01  add  %o5, %g1, %o3
a0099ba0:  c2 0a e0 8f  ldub  [ %o3 + 0x8f ], %g1
a0099ba4:  80 a0 60 00  cmp  %g1, 0
a0099ba8:  12 80 00 0c  bne  0xa0099bd8
a0099bac:  82 12 a2 80  or  %o2, 0x280, %g1
a0099bb0:  c2 0a e0 8e  ldub  [ %o3 + 0x8e ], %g1
a0099bb4:  82 00 60 01  inc  %g1
a0099bb8:  9a 08 60 ff  and  %g1, 0xff, %o5
a0099bbc:  80 a3 60 0a  cmp  %o5, 0xa
a0099bc0:  12 80 00 05  bne  0xa0099bd4
a0099bc4:  c2 2a e0 8e  stb  %g1, [ %o3 + 0x8e ]
a0099bc8:  82 10 20 01  mov  1, %g1
a0099bcc:  c2 2a e0 91  stb  %g1, [ %o3 + 0x91 ]
a0099bd0:  c0 2a e0 8e  clrb  [ %o3 + 0x8e ]
a0099bd4:  82 12 a2 80  or  %o2, 0x280, %g1
a0099bd8:  98 5b 20 b0  smul  %o4, 0xb0, %o4
a0099bdc:  98 03 00 01  add  %o4, %g1, %o4
a0099be0:  da 0b 20 8f  ldub  [ %o4 + 0x8f ], %o5
a0099be4:  9a 03 60 01  inc  %o5
a0099be8:  d6 0b 20 90  ldub  [ %o4 + 0x90 ], %o3
a0099bec:  95 3b 60 1f  sra  %o5, 0x1f, %o2
a0099bf0:  81 82 a0 00  mov  %o2, %y
a0099bf4:  01 00 00 00  nop
a0099bf8:  01 00 00 00  nop
a0099bfc:  01 00 00 00  nop
a0099c00:  82 7b 40 0b  sdiv  %o5, %o3, %g1
a0099c04:  82 58 40 0b  smul  %g1, %o3, %g1
a0099c08:  9a 23 40 01  sub  %o5, %g1, %o5
a0099c0c:  da 2b 20 8f  stb  %o5, [ %o4 + 0x8f ]
a0099c10:  81 c7 e0 08  ret
a0099c14:  81 e8 00 00  restore
