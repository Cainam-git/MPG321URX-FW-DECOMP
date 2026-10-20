# leon2m FUN_a01238e8 0xa01238e8-0xa0123c4c (868 bytes)  [FUN_a0123c44 = unreachable ret/restore tail, merged]
a01238e8:  9d e3 bf 98  save  %sp, -104, %sp
a01238ec:  31 2a 00 b6  sethi  %hi(0xa802d800), %i0
a01238f0:  fa 0e 20 7e  ldub  [ %i0 + 0x7e ], %i5	! 0xa802d87e
a01238f4:  33 00 00 3c  sethi  %hi(0xf000), %i1
a01238f8:  b8 07 40 1d  add  %i5, %i5, %i4
a01238fc:  82 16 61 90  or  %i1, 0x190, %g1
a0123900:  b4 07 00 01  add  %i4, %g1, %i2
a0123904:  b7 2e a0 02  sll  %i2, 2, %i3
a0123908:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a012390c:  ba 16 c0 1a  or  %i3, %i2, %i5
a0123910:  c2 07 40 00  ld  [ %i5 ], %g1
a0123914:  80 a0 60 96  cmp  %g1, 0x96
a0123918:  12 80 00 ca  bne  0xa0123c40
a012391c:  b6 16 61 91  or  %i1, 0x191, %i3
a0123920:  82 07 00 1b  add  %i4, %i3, %g1
a0123924:  b9 28 60 02  sll  %g1, 2, %i4
a0123928:  82 17 00 1a  or  %i4, %i2, %g1
a012392c:  ba 10 20 47  mov  0x47, %i5
a0123930:  fa 20 40 00  st  %i5, [ %g1 ]
a0123934:  f8 0e 20 7e  ldub  [ %i0 + 0x7e ], %i4
a0123938:  b8 07 00 1c  add  %i4, %i4, %i4
a012393c:  b6 07 00 1b  add  %i4, %i3, %i3
a0123940:  b1 2e e0 02  sll  %i3, 2, %i0
a0123944:  ba 10 00 19  mov  %i1, %i5
a0123948:  b6 16 00 1a  or  %i0, %i2, %i3
a012394c:  f2 06 c0 00  ld  [ %i3 ], %i1
a0123950:  80 a6 60 47  cmp  %i1, 0x47
a0123954:  02 bf ff fe  be  0xa012394c
a0123958:  82 17 61 90  or  %i5, 0x190, %g1
a012395c:  ba 07 00 01  add  %i4, %g1, %i5
a0123960:  b7 2f 60 02  sll  %i5, 2, %i3
a0123964:  b0 16 c0 1a  or  %i3, %i2, %i0
a0123968:  f4 06 00 00  ld  [ %i0 ], %i2
a012396c:  80 a6 a0 9b  cmp  %i2, 0x9b
a0123970:  02 80 00 b4  be  0xa0123c40
a0123974:  35 33 c0 f1  sethi  %hi(0xcf03c400), %i2
a0123978:  b8 16 a2 60  or  %i2, 0x260, %i4	! 0xcf03c660
a012397c:  b2 10 20 52  mov  0x52, %i1
a0123980:  f2 27 00 00  st  %i1, [ %i4 ]
a0123984:  ba 10 00 1c  mov  %i4, %i5
a0123988:  f0 07 40 00  ld  [ %i5 ], %i0
a012398c:  80 a6 20 52  cmp  %i0, 0x52
a0123990:  02 bf ff fe  be  0xa0123988
a0123994:  37 00 00 3c  sethi  %hi(0xf000), %i3
a0123998:  1f 2a 00 b6  sethi  %hi(0xa802d800), %o7
a012399c:  b2 16 e1 9a  or  %i3, 0x19a, %i1
a01239a0:  b6 10 20 00  clr  %i3
a01239a4:  b8 10 20 00  clr  %i4
a01239a8:  b0 13 e0 50  or  %o7, 0x50, %i0
a01239ac:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a01239b0:  82 07 00 19  add  %i4, %i1, %g1
a01239b4:  bb 28 60 02  sll  %g1, 2, %i5
a01239b8:  82 17 40 1a  or  %i5, %i2, %g1
a01239bc:  fa 00 40 00  ld  [ %g1 ], %i5
a01239c0:  fa 2f 00 18  stb  %i5, [ %i4 + %i0 ]
a01239c4:  b6 06 e0 01  inc  %i3
a01239c8:  b8 0e e0 ff  and  %i3, 0xff, %i4
a01239cc:  80 a7 20 05  cmp  %i4, 5
a01239d0:  08 bf ff f9  bleu  0xa01239b4
a01239d4:  82 07 00 19  add  %i4, %i1, %g1
a01239d8:  35 33 c0 f1  sethi  %hi(0xcf03c400), %i2
a01239dc:  b8 16 a2 60  or  %i2, 0x260, %i4	! 0xcf03c660
a01239e0:  b2 10 20 53  mov  0x53, %i1
a01239e4:  f2 27 00 00  st  %i1, [ %i4 ]
a01239e8:  ba 10 00 1c  mov  %i4, %i5
a01239ec:  f0 07 40 00  ld  [ %i5 ], %i0
a01239f0:  80 a6 20 53  cmp  %i0, 0x53
a01239f4:  02 bf ff fe  be  0xa01239ec
a01239f8:  b8 10 20 00  clr  %i4
a01239fc:  37 00 00 3c  sethi  %hi(0xf000), %i3
a0123a00:  3b 2a 00 b6  sethi  %hi(0xa802d800), %i5
a0123a04:  b0 16 e1 9a  or  %i3, 0x19a, %i0
a0123a08:  b2 17 60 56  or  %i5, 0x56, %i1
a0123a0c:  b6 10 20 00  clr  %i3
a0123a10:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a0123a14:  82 07 00 18  add  %i4, %i0, %g1
a0123a18:  bb 28 60 02  sll  %g1, 2, %i5
a0123a1c:  82 17 40 1a  or  %i5, %i2, %g1
a0123a20:  fa 00 40 00  ld  [ %g1 ], %i5
a0123a24:  fa 2f 00 19  stb  %i5, [ %i4 + %i1 ]
a0123a28:  b6 06 e0 01  inc  %i3
a0123a2c:  b8 0e e0 ff  and  %i3, 0xff, %i4
a0123a30:  80 a7 20 05  cmp  %i4, 5
a0123a34:  08 bf ff f9  bleu  0xa0123a18
a0123a38:  82 07 00 18  add  %i4, %i0, %g1
a0123a3c:  35 33 c0 f1  sethi  %hi(0xcf03c400), %i2
a0123a40:  b8 16 a2 60  or  %i2, 0x260, %i4	! 0xcf03c660
a0123a44:  b2 10 20 54  mov  0x54, %i1
a0123a48:  f2 27 00 00  st  %i1, [ %i4 ]
a0123a4c:  ba 10 00 1c  mov  %i4, %i5
a0123a50:  f0 07 40 00  ld  [ %i5 ], %i0
a0123a54:  80 a6 20 54  cmp  %i0, 0x54
a0123a58:  02 bf ff fe  be  0xa0123a50
a0123a5c:  b8 10 20 00  clr  %i4
a0123a60:  37 00 00 3c  sethi  %hi(0xf000), %i3
a0123a64:  3b 2a 00 b6  sethi  %hi(0xa802d800), %i5
a0123a68:  b0 16 e1 9a  or  %i3, 0x19a, %i0
a0123a6c:  b2 17 60 5c  or  %i5, 0x5c, %i1
a0123a70:  b6 10 20 00  clr  %i3
a0123a74:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a0123a78:  82 07 00 18  add  %i4, %i0, %g1
a0123a7c:  bb 28 60 02  sll  %g1, 2, %i5
a0123a80:  82 17 40 1a  or  %i5, %i2, %g1
a0123a84:  fa 00 40 00  ld  [ %g1 ], %i5
a0123a88:  fa 2f 00 19  stb  %i5, [ %i4 + %i1 ]
a0123a8c:  b6 06 e0 01  inc  %i3
a0123a90:  b8 0e e0 ff  and  %i3, 0xff, %i4
a0123a94:  80 a7 20 05  cmp  %i4, 5
a0123a98:  08 bf ff f9  bleu  0xa0123a7c
a0123a9c:  82 07 00 18  add  %i4, %i0, %g1
a0123aa0:  35 33 c0 f1  sethi  %hi(0xcf03c400), %i2
a0123aa4:  b8 16 a2 60  or  %i2, 0x260, %i4	! 0xcf03c660
a0123aa8:  b2 10 20 55  mov  0x55, %i1
a0123aac:  f2 27 00 00  st  %i1, [ %i4 ]
a0123ab0:  ba 10 00 1c  mov  %i4, %i5
a0123ab4:  f0 07 40 00  ld  [ %i5 ], %i0
a0123ab8:  80 a6 20 55  cmp  %i0, 0x55
a0123abc:  02 bf ff fe  be  0xa0123ab4
a0123ac0:  b8 10 20 00  clr  %i4
a0123ac4:  37 00 00 3c  sethi  %hi(0xf000), %i3
a0123ac8:  3b 2a 00 b6  sethi  %hi(0xa802d800), %i5
a0123acc:  b0 16 e1 9a  or  %i3, 0x19a, %i0
a0123ad0:  b2 17 60 62  or  %i5, 0x62, %i1
a0123ad4:  b6 10 20 00  clr  %i3
a0123ad8:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a0123adc:  82 07 00 18  add  %i4, %i0, %g1
a0123ae0:  bb 28 60 02  sll  %g1, 2, %i5
a0123ae4:  82 17 40 1a  or  %i5, %i2, %g1
a0123ae8:  fa 00 40 00  ld  [ %g1 ], %i5
a0123aec:  fa 2f 00 19  stb  %i5, [ %i4 + %i1 ]
a0123af0:  b6 06 e0 01  inc  %i3
a0123af4:  b8 0e e0 ff  and  %i3, 0xff, %i4
a0123af8:  80 a7 20 05  cmp  %i4, 5
a0123afc:  08 bf ff f9  bleu  0xa0123ae0
a0123b00:  82 07 00 18  add  %i4, %i0, %g1
a0123b04:  35 33 c0 f1  sethi  %hi(0xcf03c400), %i2
a0123b08:  b8 16 a2 60  or  %i2, 0x260, %i4	! 0xcf03c660
a0123b0c:  b2 10 20 56  mov  0x56, %i1
a0123b10:  f2 27 00 00  st  %i1, [ %i4 ]
a0123b14:  ba 10 00 1c  mov  %i4, %i5
a0123b18:  f0 07 40 00  ld  [ %i5 ], %i0
a0123b1c:  80 a6 20 56  cmp  %i0, 0x56
a0123b20:  02 bf ff fe  be  0xa0123b18
a0123b24:  b8 10 20 00  clr  %i4
a0123b28:  37 00 00 3c  sethi  %hi(0xf000), %i3
a0123b2c:  3b 2a 00 b6  sethi  %hi(0xa802d800), %i5
a0123b30:  b0 16 e1 9a  or  %i3, 0x19a, %i0
a0123b34:  b2 17 60 68  or  %i5, 0x68, %i1
a0123b38:  b6 10 20 00  clr  %i3
a0123b3c:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a0123b40:  82 07 00 18  add  %i4, %i0, %g1
a0123b44:  bb 28 60 02  sll  %g1, 2, %i5
a0123b48:  82 17 40 1a  or  %i5, %i2, %g1
a0123b4c:  fa 00 40 00  ld  [ %g1 ], %i5
a0123b50:  fa 2f 00 19  stb  %i5, [ %i4 + %i1 ]
a0123b54:  b6 06 e0 01  inc  %i3
a0123b58:  b8 0e e0 ff  and  %i3, 0xff, %i4
a0123b5c:  80 a7 20 05  cmp  %i4, 5
a0123b60:  08 bf ff f9  bleu  0xa0123b44
a0123b64:  82 07 00 18  add  %i4, %i0, %g1
a0123b68:  35 33 c0 f1  sethi  %hi(0xcf03c400), %i2
a0123b6c:  b8 16 a2 60  or  %i2, 0x260, %i4	! 0xcf03c660
a0123b70:  b2 10 20 57  mov  0x57, %i1
a0123b74:  f2 27 00 00  st  %i1, [ %i4 ]
a0123b78:  ba 10 00 1c  mov  %i4, %i5
a0123b7c:  f0 07 40 00  ld  [ %i5 ], %i0
a0123b80:  80 a6 20 57  cmp  %i0, 0x57
a0123b84:  02 bf ff fe  be  0xa0123b7c
a0123b88:  b8 10 20 00  clr  %i4
a0123b8c:  37 00 00 3c  sethi  %hi(0xf000), %i3
a0123b90:  3b 2a 00 b6  sethi  %hi(0xa802d800), %i5
a0123b94:  b0 16 e1 9a  or  %i3, 0x19a, %i0
a0123b98:  b2 17 60 6e  or  %i5, 0x6e, %i1
a0123b9c:  b6 10 20 00  clr  %i3
a0123ba0:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a0123ba4:  82 07 00 18  add  %i4, %i0, %g1
a0123ba8:  bb 28 60 02  sll  %g1, 2, %i5
a0123bac:  82 17 40 1a  or  %i5, %i2, %g1
a0123bb0:  fa 00 40 00  ld  [ %g1 ], %i5
a0123bb4:  fa 2f 00 19  stb  %i5, [ %i4 + %i1 ]
a0123bb8:  b6 06 e0 01  inc  %i3
a0123bbc:  b8 0e e0 ff  and  %i3, 0xff, %i4
a0123bc0:  80 a7 20 05  cmp  %i4, 5
a0123bc4:  08 bf ff f9  bleu  0xa0123ba8
a0123bc8:  82 07 00 18  add  %i4, %i0, %g1
a0123bcc:  35 33 c0 f1  sethi  %hi(0xcf03c400), %i2
a0123bd0:  b8 16 a2 60  or  %i2, 0x260, %i4	! 0xcf03c660
a0123bd4:  b2 10 20 58  mov  0x58, %i1
a0123bd8:  f2 27 00 00  st  %i1, [ %i4 ]
a0123bdc:  ba 10 00 1c  mov  %i4, %i5
a0123be0:  f0 07 40 00  ld  [ %i5 ], %i0
a0123be4:  80 a6 20 58  cmp  %i0, 0x58
a0123be8:  02 bf ff fe  be  0xa0123be0
a0123bec:  b8 10 20 00  clr  %i4
a0123bf0:  37 00 00 3c  sethi  %hi(0xf000), %i3
a0123bf4:  3b 2a 00 b6  sethi  %hi(0xa802d800), %i5
a0123bf8:  b0 16 e1 9a  or  %i3, 0x19a, %i0
a0123bfc:  b2 17 60 74  or  %i5, 0x74, %i1
a0123c00:  b6 10 20 00  clr  %i3
a0123c04:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a0123c08:  82 07 00 18  add  %i4, %i0, %g1
a0123c0c:  bb 28 60 02  sll  %g1, 2, %i5
a0123c10:  82 17 40 1a  or  %i5, %i2, %g1
a0123c14:  fa 00 40 00  ld  [ %g1 ], %i5
a0123c18:  fa 2f 00 19  stb  %i5, [ %i4 + %i1 ]
a0123c1c:  b6 06 e0 01  inc  %i3
a0123c20:  b8 0e e0 ff  and  %i3, 0xff, %i4
a0123c24:  80 a7 20 05  cmp  %i4, 5
a0123c28:  08 bf ff f9  bleu  0xa0123c0c
a0123c2c:  82 07 00 18  add  %i4, %i0, %g1
a0123c30:  39 00 06 8c  sethi  %hi(0x1a3000), %i4
a0123c34:  b2 13 e0 50  or  %o7, 0x50, %i1
a0123c38:  7f fe ed 4e  call  0xa00df170
a0123c3c:  91 ef 20 a0  restore  %i4, 0xa0, %o0
a0123c40:  01 00 00 00  nop
a0123c44:  81 c7 e0 08  ret
a0123c48:  81 e8 00 00  restore
