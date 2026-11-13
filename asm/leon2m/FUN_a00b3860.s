# leon2m FUN_a00b3860 0xa00b3860-0xa00b3ac8 (616 bytes)
a00b3860:  9d e3 bf 78  save  %sp, -136, %sp
a00b3864:  7f ff e4 f7  call  0xa00acc40
a00b3868:  01 00 00 00  nop
a00b386c:  7f ff e5 a2  call  0xa00acef4
a00b3870:  01 00 00 00  nop
a00b3874:  90 10 20 02  mov  2, %o0	! 0x2
a00b3878:  40 02 4c bd  call  0xa0146b6c
a00b387c:  92 10 20 00  clr  %o1
a00b3880:  90 10 21 a6  mov  0x1a6, %o0
a00b3884:  40 02 4c b3  call  0xa0146b50
a00b3888:  92 10 20 00  clr  %o1
a00b388c:  96 10 25 96  mov  0x596, %o3
a00b3890:  98 10 20 00  clr  %o4
a00b3894:  92 10 20 01  mov  1, %o1
a00b3898:  94 10 20 05  mov  5, %o2
a00b389c:  40 02 4c 79  call  0xa0146a80
a00b38a0:  90 10 20 36  mov  0x36, %o0
a00b38a4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00b38a8:  40 02 43 55  call  0xa01445fc
a00b38ac:  d0 0a a2 ae  ldub  [ %o2 + 0x2ae ], %o0	! 0xa802d2ae
a00b38b0:  92 0a 20 ff  and  %o0, 0xff, %o1
a00b38b4:  11 00 06 5a  sethi  %hi(0x196800), %o0
a00b38b8:  7f ff bf e3  call  0xa00a3844
a00b38bc:  90 12 23 24  or  %o0, 0x324, %o0	! 0x196b24
a00b38c0:  98 10 00 08  mov  %o0, %o4
a00b38c4:  94 10 20 01  mov  1, %o2
a00b38c8:  96 10 20 05  mov  5, %o3
a00b38cc:  9a 10 20 00  clr  %o5
a00b38d0:  90 10 20 00  clr  %o0
a00b38d4:  7f ff be 34  call  0xa00a31a4
a00b38d8:  92 10 20 36  mov  0x36, %o1
a00b38dc:  92 10 20 07  mov  7, %o1
a00b38e0:  40 02 47 60  call  0xa0145660
a00b38e4:  90 10 20 00  clr  %o0
a00b38e8:  83 2a 20 10  sll  %o0, 0x10, %g1
a00b38ec:  a1 30 60 10  srl  %g1, 0x10, %l0
a00b38f0:  92 10 20 08  mov  8, %o1
a00b38f4:  40 02 47 5b  call  0xa0145660
a00b38f8:  90 10 20 00  clr  %o0
a00b38fc:  97 2a 20 10  sll  %o0, 0x10, %o3
a00b3900:  a2 07 bf e8  add  %fp, -24, %l1
a00b3904:  13 00 06 60  sethi  %hi(0x198000), %o1
a00b3908:  94 10 00 10  mov  %l0, %o2
a00b390c:  92 12 61 e0  or  %o1, 0x1e0, %o1
a00b3910:  97 32 e0 10  srl  %o3, 0x10, %o3
a00b3914:  40 02 8f b8  call  0xa01577f4
a00b3918:  90 10 00 11  mov  %l1, %o0
a00b391c:  98 10 20 00  clr  %o4
a00b3920:  82 10 20 00  clr  %g1
a00b3924:  a0 07 bf f8  add  %fp, -8, %l0
a00b3928:  9e 04 00 01  add  %l0, %g1, %o7
a00b392c:  da 0b ff f0  ldub  [ %o7 + -16 ], %o5
a00b3930:  80 a3 60 00  cmp  %o5, 0
a00b3934:  02 80 00 08  be  0xa00b3954
a00b3938:  92 03 3f ff  add  %o4, -1, %o1
a00b393c:  98 03 20 01  inc  %o4
a00b3940:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b3944:  80 a0 60 0f  cmp  %g1, 0xf
a00b3948:  08 bf ff f9  bleu  0xa00b392c
a00b394c:  9e 04 00 01  add  %l0, %g1, %o7
a00b3950:  92 03 3f ff  add  %o4, -1, %o1
a00b3954:  d2 2f bf e8  stb  %o1, [ %fp + -24 ]
a00b3958:  90 10 20 0e  mov  0xe, %o0
a00b395c:  92 10 20 01  mov  1, %o1
a00b3960:  94 10 20 08  mov  8, %o2
a00b3964:  96 10 25 96  mov  0x596, %o3
a00b3968:  40 02 4c 46  call  0xa0146a80
a00b396c:  98 10 20 00  clr  %o4
a00b3970:  98 10 00 11  mov  %l1, %o4
a00b3974:  92 10 20 0e  mov  0xe, %o1
a00b3978:  94 10 20 01  mov  1, %o2
a00b397c:  96 10 20 08  mov  8, %o3
a00b3980:  9a 10 20 00  clr  %o5
a00b3984:  7f ff be 08  call  0xa00a31a4
a00b3988:  90 10 20 00  clr  %o0
a00b398c:  40 00 94 6b  call  0xa00d8b38
a00b3990:  01 00 00 00  nop
a00b3994:  99 2a 20 10  sll  %o0, 0x10, %o4
a00b3998:  17 00 06 60  sethi  %hi(0x198000), %o3
a00b399c:  a2 07 bf d8  add  %fp, -40, %l1
a00b39a0:  95 33 20 10  srl  %o4, 0x10, %o2
a00b39a4:  92 12 e1 d8  or  %o3, 0x1d8, %o1
a00b39a8:  40 02 8f 93  call  0xa01577f4
a00b39ac:  90 10 00 11  mov  %l1, %o0
a00b39b0:  98 10 20 00  clr  %o4
a00b39b4:  82 10 20 00  clr  %g1
a00b39b8:  82 04 00 01  add  %l0, %g1, %g1
a00b39bc:  d0 08 7f e0  ldub  [ %g1 + -32 ], %o0
a00b39c0:  80 a2 20 00  cmp  %o0, 0
a00b39c4:  02 80 00 08  be  0xa00b39e4
a00b39c8:  94 03 3f ff  add  %o4, -1, %o2
a00b39cc:  98 03 20 01  inc  %o4
a00b39d0:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b39d4:  80 a0 60 0f  cmp  %g1, 0xf
a00b39d8:  08 bf ff f9  bleu  0xa00b39bc
a00b39dc:  82 04 00 01  add  %l0, %g1, %g1
a00b39e0:  94 03 3f ff  add  %o4, -1, %o2
a00b39e4:  d4 2f bf d8  stb  %o2, [ %fp + -40 ]
a00b39e8:  90 10 20 02  mov  2, %o0
a00b39ec:  40 02 4c 60  call  0xa0146b6c
a00b39f0:  92 10 20 00  clr  %o1
a00b39f4:  90 10 21 b5  mov  0x1b5, %o0
a00b39f8:  40 02 4c 56  call  0xa0146b50
a00b39fc:  92 10 20 00  clr  %o1
a00b3a00:  90 10 20 0e  mov  0xe, %o0
a00b3a04:  92 10 20 02  mov  2, %o1
a00b3a08:  94 10 20 08  mov  8, %o2
a00b3a0c:  96 10 25 96  mov  0x596, %o3
a00b3a10:  40 02 4c 1c  call  0xa0146a80
a00b3a14:  98 10 20 00  clr  %o4
a00b3a18:  98 10 00 11  mov  %l1, %o4
a00b3a1c:  9a 10 20 00  clr  %o5
a00b3a20:  94 10 20 02  mov  2, %o2
a00b3a24:  96 10 20 08  mov  8, %o3
a00b3a28:  90 10 20 00  clr  %o0
a00b3a2c:  7f ff bd de  call  0xa00a31a4
a00b3a30:  92 10 20 0e  mov  0xe, %o1
a00b3a34:  90 10 21 bc  mov  0x1bc, %o0
a00b3a38:  40 02 4c 46  call  0xa0146b50
a00b3a3c:  92 10 20 00  clr  %o1
a00b3a40:  90 10 20 02  mov  2, %o0
a00b3a44:  40 02 4c 4a  call  0xa0146b6c
a00b3a48:  92 10 20 00  clr  %o1
a00b3a4c:  90 10 20 37  mov  0x37, %o0
a00b3a50:  92 10 20 15  mov  0x15, %o1
a00b3a54:  94 10 20 04  mov  4, %o2
a00b3a58:  96 10 2a 96  mov  0xa96, %o3
a00b3a5c:  40 02 4c 09  call  0xa0146a80
a00b3a60:  98 10 20 00  clr  %o4
a00b3a64:  21 00 06 60  sethi  %hi(0x198000), %l0
a00b3a68:  9a 10 20 00  clr  %o5
a00b3a6c:  98 14 21 f0  or  %l0, 0x1f0, %o4
a00b3a70:  90 10 20 00  clr  %o0
a00b3a74:  92 10 20 37  mov  0x37, %o1
a00b3a78:  94 10 20 15  mov  0x15, %o2
a00b3a7c:  7f ff bd ca  call  0xa00a31a4
a00b3a80:  96 10 20 04  mov  4, %o3
a00b3a84:  90 10 20 01  mov  1, %o0
a00b3a88:  92 10 20 04  mov  4, %o1
a00b3a8c:  94 10 20 0b  mov  0xb, %o2
a00b3a90:  96 10 29 96  mov  0x996, %o3
a00b3a94:  40 02 4b fb  call  0xa0146a80
a00b3a98:  98 10 20 00  clr  %o4
a00b3a9c:  23 00 06 60  sethi  %hi(0x198000), %l1
a00b3aa0:  98 14 61 f8  or  %l1, 0x1f8, %o4	! 0x1981f8
a00b3aa4:  90 10 20 00  clr  %o0
a00b3aa8:  92 10 20 01  mov  1, %o1
a00b3aac:  94 10 20 04  mov  4, %o2
a00b3ab0:  96 10 20 0b  mov  0xb, %o3
a00b3ab4:  7f ff bd bc  call  0xa00a31a4
a00b3ab8:  9a 10 20 00  clr  %o5
a00b3abc:  01 00 00 00  nop
a00b3ac0:  81 c7 e0 08  ret
a00b3ac4:  81 e8 00 00  restore
