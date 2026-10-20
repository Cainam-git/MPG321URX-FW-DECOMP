# leon2s TRAINING_NORESPONSE 0xa0087824-0xa0087d50 (1324 bytes)
a0087824:  9d e3 bf 38  save  %sp, -200, %sp
a0087828:  80 8e 20 ff  btst  0xff, %i0
a008782c:  c0 27 bf f0  clr  [ %fp + -16 ]
a0087830:  aa 10 20 02  mov  2, %l5
a0087834:  ac 10 20 00  clr  %l6
a0087838:  02 80 00 06  be  0xa0087850
a008783c:  ae 10 20 00  clr  %l7
a0087840:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0087844:  ec 08 61 c0  ldub  [ %g1 + 0x1c0 ], %l6	! 0xa80761c0
a0087848:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a008784c:  ee 08 61 bf  ldub  [ %g1 + 0x1bf ], %l7	! 0xa80761bf
a0087850:  82 10 20 04  mov  4, %g1
a0087854:  c2 2f bf f1  stb  %g1, [ %fp + -15 ]
a0087858:  82 10 20 1e  mov  0x1e, %g1
a008785c:  a0 10 00 16  mov  %l6, %l0
a0087860:  9a 0d a0 ff  and  %l6, 0xff, %o5
a0087864:  a2 0d e0 ff  and  %l7, 0xff, %l1
a0087868:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a008786c:  80 a3 40 11  cmp  %o5, %l1
a0087870:  18 80 00 3d  bgu  0xa0087964
a0087874:  c2 0f bf f1  ldub  [ %fp + -15 ], %g1
a0087878:  c2 0e 40 00  ldub  [ %i1 ], %g1
a008787c:  83 38 40 0d  sra  %g1, %o5, %g1
a0087880:  80 88 60 01  btst  1, %g1
a0087884:  22 80 00 36  be,a   0xa008795c
a0087888:  a0 04 20 01  inc  %l0
a008788c:  80 a3 60 00  cmp  %o5, 0
a0087890:  12 80 00 0e  bne  0xa00878c8
a0087894:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a0087898:  7f ff fc d0  call  0xa0086bd8
a008789c:  01 00 00 00  nop
a00878a0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00878a4:  80 a2 20 02  cmp  %o0, 2
a00878a8:  12 80 00 08  bne  0xa00878c8
a00878ac:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a00878b0:  40 00 96 73  call  0xa00ad27c
a00878b4:  90 10 20 00  clr  %o0
a00878b8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00878bc:  80 a2 20 01  cmp  %o0, 1
a00878c0:  12 80 01 21  bne  0xa0087d44
a00878c4:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a00878c8:  9a 13 61 00  or  %o5, 0x100, %o5	! 0xcf018d00
a00878cc:  c2 03 40 00  ld  [ %o5 ], %g1
a00878d0:  82 08 7f fc  and  %g1, -4, %g1
a00878d4:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00878d8:  c2 23 40 00  st  %g1, [ %o5 ]
a00878dc:  80 a6 20 00  cmp  %i0, 0
a00878e0:  02 80 00 19  be  0xa0087944
a00878e4:  90 10 00 18  mov  %i0, %o0
a00878e8:  7f ff ff 81  call  0xa00876ec
a00878ec:  90 10 00 18  mov  %i0, %o0
a00878f0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00878f4:  80 a2 20 08  cmp  %o0, 8
a00878f8:  02 80 00 0d  be  0xa008792c
a00878fc:  80 a2 20 06  cmp  %o0, 6
a0087900:  12 80 00 06  bne  0xa0087918
a0087904:  80 a2 20 0a  cmp  %o0, 0xa
a0087908:  90 10 00 18  mov  %i0, %o0
a008790c:  92 10 20 66  mov  0x66, %o1
a0087910:  10 80 00 0a  b  0xa0087938
a0087914:  94 10 20 00  clr  %o2
a0087918:  12 80 00 06  bne  0xa0087930
a008791c:  90 10 00 18  mov  %i0, %o0
a0087920:  92 10 20 66  mov  0x66, %o1
a0087924:  10 80 00 05  b  0xa0087938
a0087928:  94 10 20 40  mov  0x40, %o2
a008792c:  90 10 00 18  mov  %i0, %o0
a0087930:  92 10 20 66  mov  0x66, %o1
a0087934:  94 10 20 20  mov  0x20, %o2
a0087938:  40 00 7f f1  call  0xa00a78fc
a008793c:  01 00 00 00  nop
a0087940:  90 10 00 18  mov  %i0, %o0
a0087944:  7f ff fc c1  call  0xa0086c48
a0087948:  92 07 bf f0  add  %fp, -16, %o1
a008794c:  90 10 00 18  mov  %i0, %o0
a0087950:  7f ff fb 1a  call  0xa00865b8
a0087954:  92 10 20 01  mov  1, %o1
a0087958:  a0 04 20 01  inc  %l0
a008795c:  10 bf ff c4  b  0xa008786c
a0087960:  9a 0c 20 ff  and  %l0, 0xff, %o5
a0087964:  c2 2f bf 9f  stb  %g1, [ %fp + -97 ]
a0087968:  e4 0f bf f0  ldub  [ %fp + -16 ], %l2
a008796c:  a6 0d a0 ff  and  %l6, 0xff, %l3
a0087970:  a8 0d e0 ff  and  %l7, 0xff, %l4
a0087974:  a0 10 00 16  mov  %l6, %l0
a0087978:  80 a4 c0 14  cmp  %l3, %l4
a008797c:  b0 10 00 13  mov  %l3, %i0
a0087980:  18 80 00 16  bgu  0xa00879d8
a0087984:  a2 0c a0 ff  and  %l2, 0xff, %l1
a0087988:  c2 0e 40 00  ldub  [ %i1 ], %g1
a008798c:  83 38 40 18  sra  %g1, %i0, %g1
a0087990:  94 10 00 18  mov  %i0, %o2
a0087994:  90 10 00 18  mov  %i0, %o0
a0087998:  92 10 00 11  mov  %l1, %o1
a008799c:  80 88 60 01  btst  1, %g1
a00879a0:  02 80 00 0b  be  0xa00879cc
a00879a4:  a0 04 20 01  inc  %l0
a00879a8:  7f ff ff 63  call  0xa0087734
a00879ac:  01 00 00 00  nop
a00879b0:  90 10 00 18  mov  %i0, %o0
a00879b4:  7f ff ff 78  call  0xa0087794
a00879b8:  d2 0f bf 9f  ldub  [ %fp + -97 ], %o1
a00879bc:  90 10 00 18  mov  %i0, %o0
a00879c0:  94 10 00 11  mov  %l1, %o2
a00879c4:  7f ff fd 0c  call  0xa0086df4
a00879c8:  d2 0f bf 9f  ldub  [ %fp + -97 ], %o1
a00879cc:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00879d0:  10 bf ff ec  b  0xa0087980
a00879d4:  80 a6 00 14  cmp  %i0, %l4
a00879d8:  a8 07 bf a0  add  %fp, -96, %l4
a00879dc:  90 10 00 13  mov  %l3, %o0
a00879e0:  92 07 bf 9f  add  %fp, -97, %o1
a00879e4:  94 10 00 14  mov  %l4, %o2
a00879e8:  7f ff fd ca  call  0xa0087110
a00879ec:  96 10 00 19  mov  %i1, %o3
a00879f0:  82 0a 20 ff  and  %o0, 0xff, %g1
a00879f4:  80 a0 60 04  cmp  %g1, 4
a00879f8:  12 80 00 31  bne  0xa0087abc
a00879fc:  a2 10 00 08  mov  %o0, %l1
a0087a00:  94 10 00 14  mov  %l4, %o2
a0087a04:  90 10 00 13  mov  %l3, %o0
a0087a08:  92 07 bf 9f  add  %fp, -97, %o1
a0087a0c:  7f ff fe 8c  call  0xa008743c
a0087a10:  96 10 00 19  mov  %i1, %o3
a0087a14:  82 0a 20 ff  and  %o0, 0xff, %g1
a0087a18:  80 a0 60 05  cmp  %g1, 5
a0087a1c:  02 80 00 60  be  0xa0087b9c
a0087a20:  a2 10 00 08  mov  %o0, %l1
a0087a24:  80 8c 20 ff  btst  0xff, %l0
a0087a28:  32 80 00 67  bne,a   0xa0087bc4
a0087a2c:  aa 05 7f ff  add  %l5, -1, %l5
a0087a30:  80 a0 60 09  cmp  %g1, 9
a0087a34:  12 80 00 09  bne  0xa0087a58
a0087a38:  82 0c 60 ff  and  %l1, 0xff, %g1
a0087a3c:  da 0f bf 9f  ldub  [ %fp + -97 ], %o5
a0087a40:  c2 0f bf f3  ldub  [ %fp + -13 ], %g1
a0087a44:  80 a3 40 01  cmp  %o5, %g1
a0087a48:  18 80 00 1b  bgu  0xa0087ab4
a0087a4c:  83 33 60 01  srl  %o5, 1, %g1
a0087a50:  a2 10 20 08  mov  8, %l1
a0087a54:  82 0c 60 ff  and  %l1, 0xff, %g1
a0087a58:  80 a0 60 08  cmp  %g1, 8
a0087a5c:  12 80 00 51  bne  0xa0087ba0
a0087a60:  82 0c 60 ff  and  %l1, 0xff, %g1
a0087a64:  9a 0c a0 ff  and  %l2, 0xff, %o5
a0087a68:  c2 0f bf f2  ldub  [ %fp + -14 ], %g1
a0087a6c:  80 a3 40 01  cmp  %o5, %g1
a0087a70:  08 80 00 4a  bleu  0xa0087b98
a0087a74:  80 a3 60 14  cmp  %o5, 0x14
a0087a78:  22 80 00 0e  be,a   0xa0087ab0
a0087a7c:  a4 10 20 0a  mov  0xa, %l2
a0087a80:  14 80 00 07  bg  0xa0087a9c
a0087a84:  80 a3 60 1e  cmp  %o5, 0x1e
a0087a88:  80 a3 60 0a  cmp  %o5, 0xa
a0087a8c:  02 80 00 08  be  0xa0087aac
a0087a90:  c2 0f bf f1  ldub  [ %fp + -15 ], %g1
a0087a94:  10 80 00 4c  b  0xa0087bc4
a0087a98:  c2 2f bf 9f  stb  %g1, [ %fp + -97 ]
a0087a9c:  22 80 00 05  be,a   0xa0087ab0
a0087aa0:  a4 10 20 14  mov  0x14, %l2
a0087aa4:  10 80 00 04  b  0xa0087ab4
a0087aa8:  c2 0f bf f1  ldub  [ %fp + -15 ], %g1
a0087aac:  a4 10 20 06  mov  6, %l2
a0087ab0:  c2 0f bf f1  ldub  [ %fp + -15 ], %g1
a0087ab4:  10 80 00 44  b  0xa0087bc4
a0087ab8:  c2 2f bf 9f  stb  %g1, [ %fp + -97 ]
a0087abc:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0087ac0:  7f ff ae 81  call  0xa00734c4
a0087ac4:  90 12 21 a8  or  %o0, 0x1a8, %o0	! 0xa00689a8
a0087ac8:  80 8c 20 ff  btst  0xff, %l0
a0087acc:  02 80 00 04  be  0xa0087adc
a0087ad0:  9a 0c a0 ff  and  %l2, 0xff, %o5
a0087ad4:  10 80 00 3c  b  0xa0087bc4
a0087ad8:  aa 05 7f ff  add  %l5, -1, %l5
a0087adc:  c2 0f bf f2  ldub  [ %fp + -14 ], %g1
a0087ae0:  80 a3 40 01  cmp  %o5, %g1
a0087ae4:  08 80 00 10  bleu  0xa0087b24
a0087ae8:  80 a3 60 14  cmp  %o5, 0x14
a0087aec:  22 80 00 36  be,a   0xa0087bc4
a0087af0:  a4 10 20 0a  mov  0xa, %l2
a0087af4:  14 80 00 06  bg  0xa0087b0c
a0087af8:  80 a3 60 1e  cmp  %o5, 0x1e
a0087afc:  80 a3 60 0a  cmp  %o5, 0xa
a0087b00:  02 80 00 07  be  0xa0087b1c
a0087b04:  80 8d 60 ff  btst  0xff, %l5
a0087b08:  30 80 00 30  b,a   0xa0087bc8
a0087b0c:  22 80 00 2e  be,a   0xa0087bc4
a0087b10:  a4 10 20 14  mov  0x14, %l2
a0087b14:  10 80 00 2d  b  0xa0087bc8
a0087b18:  80 8d 60 ff  btst  0xff, %l5
a0087b1c:  10 80 00 2a  b  0xa0087bc4
a0087b20:  a4 10 20 06  mov  6, %l2
a0087b24:  7f ff fd 54  call  0xa0087074
a0087b28:  90 10 20 00  clr  %o0
a0087b2c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0087b30:  80 a2 20 01  cmp  %o0, 1
a0087b34:  32 80 00 1a  bne,a   0xa0087b9c
a0087b38:  a2 10 20 01  mov  1, %l1
a0087b3c:  f0 0f bf 9f  ldub  [ %fp + -97 ], %i0
a0087b40:  c2 0f bf f3  ldub  [ %fp + -13 ], %g1
a0087b44:  80 a6 00 01  cmp  %i0, %g1
a0087b48:  28 80 00 15  bleu,a   0xa0087b9c
a0087b4c:  a2 10 20 01  mov  1, %l1
a0087b50:  a1 36 20 01  srl  %i0, 1, %l0
a0087b54:  90 10 00 10  mov  %l0, %o0
a0087b58:  7f ff fd 53  call  0xa00870a4
a0087b5c:  92 10 00 14  mov  %l4, %o1
a0087b60:  90 0a 20 ff  and  %o0, 0xff, %o0
a0087b64:  80 a2 20 04  cmp  %o0, 4
a0087b68:  02 80 00 09  be  0xa0087b8c
a0087b6c:  92 10 00 14  mov  %l4, %o1
a0087b70:  a1 36 20 02  srl  %i0, 2, %l0
a0087b74:  7f ff fd 4c  call  0xa00870a4
a0087b78:  90 10 00 10  mov  %l0, %o0
a0087b7c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0087b80:  80 a2 20 04  cmp  %o0, 4
a0087b84:  32 80 00 06  bne,a   0xa0087b9c
a0087b88:  a2 10 20 01  mov  1, %l1
a0087b8c:  e0 2f bf 9f  stb  %l0, [ %fp + -97 ]
a0087b90:  10 80 00 0d  b  0xa0087bc4
a0087b94:  e4 0f bf f0  ldub  [ %fp + -16 ], %l2
a0087b98:  a2 10 20 01  mov  1, %l1
a0087b9c:  82 0c 60 ff  and  %l1, 0xff, %g1
a0087ba0:  80 a0 60 02  cmp  %g1, 2
a0087ba4:  02 80 00 52  be  0xa0087cec
a0087ba8:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0087bac:  80 a0 60 01  cmp  %g1, 1
a0087bb0:  02 80 00 4d  be  0xa0087ce4
a0087bb4:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0087bb8:  80 a0 60 05  cmp  %g1, 5
a0087bbc:  22 80 00 05  be,a   0xa0087bd0
a0087bc0:  a2 10 20 00  clr  %l1
a0087bc4:  80 8d 60 ff  btst  0xff, %l5
a0087bc8:  32 bf ff 6a  bne,a   0xa0087970
a0087bcc:  a6 0d a0 ff  and  %l6, 0xff, %l3
a0087bd0:  a4 0d e0 ff  and  %l7, 0xff, %l2
a0087bd4:  80 a4 c0 12  cmp  %l3, %l2
a0087bd8:  a0 10 00 16  mov  %l6, %l0
a0087bdc:  b0 10 00 13  mov  %l3, %i0
a0087be0:  18 80 00 26  bgu  0xa0087c78
a0087be4:  92 10 20 07  mov  7, %o1
a0087be8:  7f ff fa 3b  call  0xa00864d4
a0087bec:  90 10 00 18  mov  %i0, %o0
a0087bf0:  80 8a 20 ff  btst  0xff, %o0
a0087bf4:  12 80 00 06  bne  0xa0087c0c
a0087bf8:  80 8c 60 ff  btst  0xff, %l1
a0087bfc:  80 a6 20 00  cmp  %i0, 0
a0087c00:  32 80 00 1b  bne,a   0xa0087c6c
a0087c04:  a0 04 20 01  inc  %l0
a0087c08:  30 80 00 50  b,a   0xa0087d48
a0087c0c:  32 80 00 18  bne,a   0xa0087c6c
a0087c10:  a0 04 20 01  inc  %l0
a0087c14:  80 a6 20 00  cmp  %i0, 0
a0087c18:  12 80 00 12  bne  0xa0087c60
a0087c1c:  01 00 00 00  nop
a0087c20:  7f ff fa a1  call  0xa00866a4
a0087c24:  01 00 00 00  nop
a0087c28:  90 0a 20 ff  and  %o0, 0xff, %o0
a0087c2c:  80 a2 20 01  cmp  %o0, 1
a0087c30:  12 80 00 0c  bne  0xa0087c60
a0087c34:  01 00 00 00  nop
a0087c38:  7f ff fb e8  call  0xa0086bd8
a0087c3c:  01 00 00 00  nop
a0087c40:  90 0a 20 ff  and  %o0, 0xff, %o0
a0087c44:  80 a2 20 01  cmp  %o0, 1
a0087c48:  12 80 00 06  bne  0xa0087c60
a0087c4c:  01 00 00 00  nop
a0087c50:  7f c4 fa 13  call  0x9f1c649c
a0087c54:  01 00 00 00  nop
a0087c58:  7f c4 fa 25  call  0x9f1c64ec
a0087c5c:  01 00 00 00  nop
a0087c60:  7f ff fa 6f  call  0xa008661c
a0087c64:  90 0c 20 ff  and  %l0, 0xff, %o0
a0087c68:  a0 04 20 01  inc  %l0
a0087c6c:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0087c70:  10 bf ff dc  b  0xa0087be0
a0087c74:  80 a6 00 12  cmp  %i0, %l2
a0087c78:  80 8c 60 ff  btst  0xff, %l1
a0087c7c:  12 80 00 21  bne  0xa0087d00
a0087c80:  a2 0d e0 ff  and  %l7, 0xff, %l1
a0087c84:  b0 10 00 13  mov  %l3, %i0
a0087c88:  a0 10 00 16  mov  %l6, %l0
a0087c8c:  80 a6 00 11  cmp  %i0, %l1
a0087c90:  38 80 00 2e  bgu,a   0xa0087d48
a0087c94:  b0 10 20 01  mov  1, %i0
a0087c98:  7f ff f7 1f  call  0xa0085914
a0087c9c:  90 10 00 18  mov  %i0, %o0
a0087ca0:  90 10 00 18  mov  %i0, %o0
a0087ca4:  40 00 8b 23  call  0xa00aa930
a0087ca8:  92 10 20 04  mov  4, %o1
a0087cac:  c2 0e 40 00  ldub  [ %i1 ], %g1
a0087cb0:  83 38 40 18  sra  %g1, %i0, %g1
a0087cb4:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0087cb8:  90 12 21 e0  or  %o0, 0x1e0, %o0	! 0xa00689e0
a0087cbc:  80 88 60 01  btst  1, %g1
a0087cc0:  12 80 00 05  bne  0xa0087cd4
a0087cc4:  92 10 00 18  mov  %i0, %o1
a0087cc8:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0087ccc:  92 10 00 18  mov  %i0, %o1
a0087cd0:  90 12 22 08  or  %o0, 0x208, %o0
a0087cd4:  7f ff ac dc  call  0xa0073044
a0087cd8:  a0 04 20 01  inc  %l0
a0087cdc:  10 bf ff ec  b  0xa0087c8c
a0087ce0:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0087ce4:  10 80 00 03  b  0xa0087cf0
a0087ce8:  90 12 21 d0  or  %o0, 0x1d0, %o0
a0087cec:  90 12 21 b8  or  %o0, 0x1b8, %o0
a0087cf0:  7f ff ad f5  call  0xa00734c4
a0087cf4:  a4 0d e0 ff  and  %l7, 0xff, %l2
a0087cf8:  10 bf ff b8  b  0xa0087bd8
a0087cfc:  80 a4 c0 12  cmp  %l3, %l2
a0087d00:  b2 10 00 13  mov  %l3, %i1
a0087d04:  a0 10 00 16  mov  %l6, %l0
a0087d08:  80 a6 40 11  cmp  %i1, %l1
a0087d0c:  18 80 00 0f  bgu  0xa0087d48
a0087d10:  b0 10 20 00  clr  %i0
a0087d14:  7f ff f7 00  call  0xa0085914
a0087d18:  90 10 00 19  mov  %i1, %o0
a0087d1c:  90 10 00 19  mov  %i1, %o0
a0087d20:  40 00 8b 04  call  0xa00aa930
a0087d24:  92 10 20 07  mov  7, %o1
a0087d28:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0087d2c:  92 10 00 19  mov  %i1, %o1
a0087d30:  90 12 22 28  or  %o0, 0x228, %o0
a0087d34:  7f ff ac c4  call  0xa0073044
a0087d38:  a0 04 20 01  inc  %l0
a0087d3c:  10 bf ff f3  b  0xa0087d08
a0087d40:  b2 0c 20 ff  and  %l0, 0xff, %i1
a0087d44:  b0 10 20 00  clr  %i0
a0087d48:  81 c7 e0 08  ret
a0087d4c:  81 e8 00 00  restore
