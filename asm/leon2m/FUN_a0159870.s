# leon2m FUN_a0159870 0xa0159870-0xa0159cf0 (1152 bytes)
a0159870:  9d e3 bf 98  save  %sp, -104, %sp
a0159874:  31 2a 00 aa  sethi  %hi(0xa802a800), %i0
a0159878:  7f ff f7 f8  call  0xa0157858
a015987c:  90 16 22 98  or  %i0, 0x298, %o0	! 0xa802aa98
a0159880:  80 a2 20 01  cmp  %o0, 1
a0159884:  18 80 00 08  bgu  0xa01598a4
a0159888:  13 00 06 a1  sethi  %hi(0x1a8400), %o1
a015988c:  80 a6 60 00  cmp  %i1, 0
a0159890:  02 80 01 16  be  0xa0159ce8
a0159894:  b0 10 20 00  clr  %i0
a0159898:  f4 2e 40 00  stb  %i2, [ %i1 ]
a015989c:  10 80 01 13  b  0xa0159ce8
a01598a0:  b0 10 20 01  mov  1, %i0
a01598a4:  92 12 60 78  or  %o1, 0x78, %o1
a01598a8:  40 00 11 f4  call  0xa015e078
a01598ac:  90 16 22 98  or  %i0, 0x298, %o0
a01598b0:  80 a2 20 00  cmp  %o0, 0
a01598b4:  12 80 00 3e  bne  0xa01599ac
a01598b8:  80 a6 60 00  cmp  %i1, 0
a01598bc:  02 80 01 0b  be  0xa0159ce8
a01598c0:  b0 10 20 00  clr  %i0
a01598c4:  80 a6 a0 7f  cmp  %i2, 0x7f
a01598c8:  24 bf ff f5  ble,a   0xa015989c
a01598cc:  f4 2e 40 00  stb  %i2, [ %i1 ]
a01598d0:  82 06 bf 80  add  %i2, -128, %g1
a01598d4:  80 a0 67 7f  cmp  %g1, 0x77f
a01598d8:  08 80 00 c0  bleu  0xa0159bd8
a01598dc:  03 00 00 3d  sethi  %hi(0xf400), %g1
a01598e0:  9a 06 b8 00  add  %i2, -2048, %o5
a01598e4:  82 10 63 ff  or  %g1, 0x3ff, %g1
a01598e8:  80 a3 40 01  cmp  %o5, %g1
a01598ec:  08 80 00 56  bleu  0xa0159a44
a01598f0:  03 3f ff ca  sethi  %hi(0xffff2800), %g1
a01598f4:  1b 3f ff c0  sethi  %hi(0xffff0000), %o5
a01598f8:  03 00 07 bf  sethi  %hi(0x1efc00), %g1
a01598fc:  9a 06 80 0d  add  %i2, %o5, %o5
a0159900:  82 10 63 ff  or  %g1, 0x3ff, %g1
a0159904:  80 a3 40 01  cmp  %o5, %g1
a0159908:  08 80 00 bd  bleu  0xa0159bfc
a015990c:  1b 3f f8 00  sethi  %hi(0xffe00000), %o5
a0159910:  03 00 f7 ff  sethi  %hi(0x3dffc00), %g1
a0159914:  9a 06 80 0d  add  %i2, %o5, %o5
a0159918:  82 10 63 ff  or  %g1, 0x3ff, %g1
a015991c:  80 a3 40 01  cmp  %o5, %g1
a0159920:  08 80 00 ca  bleu  0xa0159c48
a0159924:  03 00 ff ff  sethi  %hi(0x3fffc00), %g1
a0159928:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0x3ffffff
a015992c:  80 a6 80 01  cmp  %i2, %g1
a0159930:  04 80 00 ee  ble  0xa0159ce8
a0159934:  b0 10 3f ff  mov  -1, %i0
a0159938:  83 36 a0 1e  srl  %i2, 0x1e, %g1
a015993c:  82 08 60 01  and  %g1, 1, %g1
a0159940:  82 10 7f fc  or  %g1, -4, %g1
a0159944:  9b 36 a0 18  srl  %i2, 0x18, %o5
a0159948:  c2 2e 40 00  stb  %g1, [ %i1 ]
a015994c:  9a 0b 60 3f  and  %o5, 0x3f, %o5
a0159950:  b2 06 60 01  inc  %i1
a0159954:  9a 13 7f 80  or  %o5, -128, %o5
a0159958:  83 36 a0 12  srl  %i2, 0x12, %g1
a015995c:  da 2e 40 00  stb  %o5, [ %i1 ]
a0159960:  82 08 60 3f  and  %g1, 0x3f, %g1
a0159964:  b2 06 60 01  inc  %i1
a0159968:  82 10 7f 80  or  %g1, -128, %g1
a015996c:  9b 36 a0 0c  srl  %i2, 0xc, %o5
a0159970:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0159974:  9a 0b 60 3f  and  %o5, 0x3f, %o5
a0159978:  b2 06 60 01  inc  %i1
a015997c:  9a 13 7f 80  or  %o5, -128, %o5
a0159980:  98 0e af c0  and  %i2, 0xfc0, %o4
a0159984:  da 2e 40 00  stb  %o5, [ %i1 ]
a0159988:  99 3b 20 06  sra  %o4, 6, %o4
a015998c:  82 0e a0 3f  and  %i2, 0x3f, %g1
a0159990:  b2 06 60 01  inc  %i1
a0159994:  98 13 3f 80  or  %o4, -128, %o4
a0159998:  82 10 7f 80  or  %g1, -128, %g1
a015999c:  c2 2e 60 01  stb  %g1, [ %i1 + 1 ]
a01599a0:  d8 2e 40 00  stb  %o4, [ %i1 ]
a01599a4:  10 80 00 d1  b  0xa0159ce8
a01599a8:  b0 10 20 06  mov  6, %i0
a01599ac:  13 00 06 a1  sethi  %hi(0x1a8400), %o1
a01599b0:  92 12 60 80  or  %o1, 0x80, %o1	! 0x1a8480
a01599b4:  40 00 11 b1  call  0xa015e078
a01599b8:  90 16 22 98  or  %i0, 0x298, %o0
a01599bc:  80 a2 20 00  cmp  %o0, 0
a01599c0:  12 80 00 36  bne  0xa0159a98
a01599c4:  97 3e a0 08  sra  %i2, 8, %o3
a01599c8:  80 a6 60 00  cmp  %i1, 0
a01599cc:  02 80 00 c7  be  0xa0159ce8
a01599d0:  b0 10 20 00  clr  %i0
a01599d4:  80 8a e0 ff  btst  0xff, %o3
a01599d8:  02 bf ff ae  be  0xa0159890
a01599dc:  80 a6 60 00  cmp  %i1, 0
a01599e0:  82 02 e0 7f  add  %o3, 0x7f, %g1
a01599e4:  82 08 60 ff  and  %g1, 0xff, %g1
a01599e8:  80 a0 60 1f  cmp  %g1, 0x1f
a01599ec:  9a 02 e0 20  add  %o3, 0x20, %o5
a01599f0:  98 60 20 00  subx  %g0, 0, %o4
a01599f4:  9a 0b 60 ff  and  %o5, 0xff, %o5
a01599f8:  80 a3 60 10  cmp  %o5, 0x10
a01599fc:  82 60 20 00  subx  %g0, 0, %g1
a0159a00:  82 10 40 0c  or  %g1, %o4, %g1
a0159a04:  80 88 60 01  btst  1, %g1
a0159a08:  02 80 00 0d  be  0xa0159a3c
a0159a0c:  82 06 bf c0  add  %i2, -64, %g1
a0159a10:  82 08 60 ff  and  %g1, 0xff, %g1
a0159a14:  80 a0 60 3f  cmp  %g1, 0x3f
a0159a18:  9a 06 bf 80  add  %i2, -128, %o5
a0159a1c:  98 60 20 00  subx  %g0, 0, %o4
a0159a20:  9a 0b 60 ff  and  %o5, 0xff, %o5
a0159a24:  80 a3 60 7d  cmp  %o5, 0x7d
a0159a28:  82 60 20 00  subx  %g0, 0, %g1
a0159a2c:  82 10 40 0c  or  %g1, %o4, %g1
a0159a30:  80 88 60 01  btst  1, %g1
a0159a34:  32 80 00 16  bne,a   0xa0159a8c
a0159a38:  f4 2e 60 01  stb  %i2, [ %i1 + 1 ]
a0159a3c:  10 80 00 ab  b  0xa0159ce8
a0159a40:  b0 10 3f ff  mov  -1, %i0
a0159a44:  82 06 80 01  add  %i2, %g1, %g1
a0159a48:  80 a0 67 ff  cmp  %g1, 0x7ff
a0159a4c:  08 80 00 a7  bleu  0xa0159ce8
a0159a50:  b0 10 3f ff  mov  -1, %i0
a0159a54:  83 36 a0 0c  srl  %i2, 0xc, %g1
a0159a58:  82 08 60 0f  and  %g1, 0xf, %g1
a0159a5c:  82 10 7f e0  or  %g1, -32, %g1
a0159a60:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0159a64:  9a 0e af c0  and  %i2, 0xfc0, %o5
a0159a68:  9b 3b 60 06  sra  %o5, 6, %o5
a0159a6c:  82 0e a0 3f  and  %i2, 0x3f, %g1
a0159a70:  b2 06 60 01  inc  %i1
a0159a74:  9a 13 7f 80  or  %o5, -128, %o5
a0159a78:  82 10 7f 80  or  %g1, -128, %g1
a0159a7c:  c2 2e 60 01  stb  %g1, [ %i1 + 1 ]
a0159a80:  da 2e 40 00  stb  %o5, [ %i1 ]
a0159a84:  10 80 00 99  b  0xa0159ce8
a0159a88:  b0 10 20 03  mov  3, %i0
a0159a8c:  d6 2e 40 00  stb  %o3, [ %i1 ]
a0159a90:  10 80 00 96  b  0xa0159ce8
a0159a94:  b0 10 20 02  mov  2, %i0
a0159a98:  13 00 06 a1  sethi  %hi(0x1a8400), %o1
a0159a9c:  92 12 60 88  or  %o1, 0x88, %o1	! 0x1a8488
a0159aa0:  40 00 11 76  call  0xa015e078
a0159aa4:  90 16 22 98  or  %i0, 0x298, %o0
a0159aa8:  80 a2 20 00  cmp  %o0, 0
a0159aac:  12 80 00 20  bne  0xa0159b2c
a0159ab0:  97 3e a0 08  sra  %i2, 8, %o3
a0159ab4:  80 a6 60 00  cmp  %i1, 0
a0159ab8:  98 10 00 1a  mov  %i2, %o4
a0159abc:  02 80 00 8b  be  0xa0159ce8
a0159ac0:  b0 10 20 00  clr  %i0
a0159ac4:  82 0a e0 ff  and  %o3, 0xff, %g1
a0159ac8:  80 a0 60 00  cmp  %g1, 0
a0159acc:  02 bf ff 71  be  0xa0159890
a0159ad0:  80 a6 60 00  cmp  %i1, 0
a0159ad4:  80 a0 60 a0  cmp  %g1, 0xa0
a0159ad8:  18 80 00 03  bgu  0xa0159ae4
a0159adc:  94 10 20 01  mov  1, %o2
a0159ae0:  94 10 20 00  clr  %o2
a0159ae4:  82 18 60 ff  xor  %g1, 0xff, %g1
a0159ae8:  80 a0 00 01  cmp  %g0, %g1
a0159aec:  9a 40 20 00  addx  %g0, 0, %o5
a0159af0:  80 8a 80 0d  btst  %o2, %o5
a0159af4:  02 bf ff d2  be  0xa0159a3c
a0159af8:  82 0b 20 ff  and  %o4, 0xff, %g1
a0159afc:  80 a0 60 a0  cmp  %g1, 0xa0
a0159b00:  18 80 00 03  bgu  0xa0159b0c
a0159b04:  98 10 20 01  mov  1, %o4
a0159b08:  98 10 20 00  clr  %o4
a0159b0c:  82 18 60 ff  xor  %g1, 0xff, %g1
a0159b10:  80 a0 00 01  cmp  %g0, %g1
a0159b14:  9a 40 20 00  addx  %g0, 0, %o5
a0159b18:  80 8b 00 0d  btst  %o4, %o5
a0159b1c:  22 80 00 73  be,a   0xa0159ce8
a0159b20:  b0 10 3f ff  mov  -1, %i0
a0159b24:  10 bf ff da  b  0xa0159a8c
a0159b28:  f4 2e 60 01  stb  %i2, [ %i1 + 1 ]
a0159b2c:  13 00 06 a1  sethi  %hi(0x1a8400), %o1
a0159b30:  90 16 22 98  or  %i0, 0x298, %o0
a0159b34:  40 00 11 51  call  0xa015e078
a0159b38:  92 12 60 90  or  %o1, 0x90, %o1
a0159b3c:  80 a2 20 00  cmp  %o0, 0
a0159b40:  12 bf ff 54  bne  0xa0159890
a0159b44:  80 a6 60 00  cmp  %i1, 0
a0159b48:  99 3e a0 08  sra  %i2, 8, %o4
a0159b4c:  9a 10 20 00  clr  %o5
a0159b50:  02 80 00 66  be  0xa0159ce8
a0159b54:  b0 10 20 01  mov  1, %i0
a0159b58:  80 8b 20 ff  btst  0xff, %o4
a0159b5c:  22 80 00 53  be,a   0xa0159ca8
a0159b60:  c2 06 c0 00  ld  [ %i3 ], %g1
a0159b64:  82 03 3f df  add  %o4, -33, %g1
a0159b68:  82 08 60 ff  and  %g1, 0xff, %g1
a0159b6c:  80 a0 60 5d  cmp  %g1, 0x5d
a0159b70:  18 bf ff b3  bgu  0xa0159a3c
a0159b74:  82 06 bf df  add  %i2, -33, %g1
a0159b78:  82 08 60 ff  and  %g1, 0xff, %g1
a0159b7c:  80 a0 60 5d  cmp  %g1, 0x5d
a0159b80:  18 80 00 5a  bgu  0xa0159ce8
a0159b84:  b0 10 3f ff  mov  -1, %i0
a0159b88:  c2 06 c0 00  ld  [ %i3 ], %g1
a0159b8c:  80 a0 60 00  cmp  %g1, 0
a0159b90:  32 80 00 0f  bne,a   0xa0159bcc
a0159b94:  f4 2e 60 01  stb  %i2, [ %i1 + 1 ]
a0159b98:  82 10 20 01  mov  1, %g1
a0159b9c:  c2 26 c0 00  st  %g1, [ %i3 ]
a0159ba0:  9a 10 20 1b  mov  0x1b, %o5
a0159ba4:  da 2e 40 00  stb  %o5, [ %i1 ]
a0159ba8:  b2 06 60 01  inc  %i1
a0159bac:  82 10 20 24  mov  0x24, %g1
a0159bb0:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0159bb4:  b2 06 60 01  inc  %i1
a0159bb8:  82 10 20 42  mov  0x42, %g1
a0159bbc:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0159bc0:  b2 06 60 01  inc  %i1
a0159bc4:  9a 10 20 03  mov  3, %o5
a0159bc8:  f4 2e 60 01  stb  %i2, [ %i1 + 1 ]
a0159bcc:  d8 2e 40 00  stb  %o4, [ %i1 ]
a0159bd0:  10 80 00 46  b  0xa0159ce8
a0159bd4:  b0 03 60 02  add  %o5, 2, %i0
a0159bd8:  9a 0e a7 c0  and  %i2, 0x7c0, %o5
a0159bdc:  9b 3b 60 06  sra  %o5, 6, %o5
a0159be0:  82 0e a0 3f  and  %i2, 0x3f, %g1
a0159be4:  9a 13 7f c0  or  %o5, -64, %o5
a0159be8:  82 10 7f 80  or  %g1, -128, %g1
a0159bec:  c2 2e 60 01  stb  %g1, [ %i1 + 1 ]
a0159bf0:  da 2e 40 00  stb  %o5, [ %i1 ]
a0159bf4:  10 80 00 3d  b  0xa0159ce8
a0159bf8:  b0 10 20 02  mov  2, %i0
a0159bfc:  83 36 a0 12  srl  %i2, 0x12, %g1
a0159c00:  82 08 60 07  and  %g1, 7, %g1
a0159c04:  82 10 7f f0  or  %g1, -16, %g1
a0159c08:  9b 36 a0 0c  srl  %i2, 0xc, %o5
a0159c0c:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0159c10:  9a 0b 60 3f  and  %o5, 0x3f, %o5
a0159c14:  b2 06 60 01  inc  %i1
a0159c18:  9a 13 7f 80  or  %o5, -128, %o5
a0159c1c:  98 0e af c0  and  %i2, 0xfc0, %o4
a0159c20:  da 2e 40 00  stb  %o5, [ %i1 ]
a0159c24:  99 3b 20 06  sra  %o4, 6, %o4
a0159c28:  82 0e a0 3f  and  %i2, 0x3f, %g1
a0159c2c:  b2 06 60 01  inc  %i1
a0159c30:  98 13 3f 80  or  %o4, -128, %o4
a0159c34:  82 10 7f 80  or  %g1, -128, %g1
a0159c38:  c2 2e 60 01  stb  %g1, [ %i1 + 1 ]
a0159c3c:  d8 2e 40 00  stb  %o4, [ %i1 ]
a0159c40:  10 80 00 2a  b  0xa0159ce8
a0159c44:  b0 10 20 04  mov  4, %i0
a0159c48:  83 36 a0 18  srl  %i2, 0x18, %g1
a0159c4c:  82 08 60 03  and  %g1, 3, %g1
a0159c50:  82 10 7f f8  or  %g1, -8, %g1
a0159c54:  9b 36 a0 12  srl  %i2, 0x12, %o5
a0159c58:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0159c5c:  9a 0b 60 3f  and  %o5, 0x3f, %o5
a0159c60:  b2 06 60 01  inc  %i1
a0159c64:  9a 13 7f 80  or  %o5, -128, %o5
a0159c68:  83 36 a0 0c  srl  %i2, 0xc, %g1
a0159c6c:  da 2e 40 00  stb  %o5, [ %i1 ]
a0159c70:  82 08 60 3f  and  %g1, 0x3f, %g1
a0159c74:  b2 06 60 01  inc  %i1
a0159c78:  82 10 7f 80  or  %g1, -128, %g1
a0159c7c:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0159c80:  9a 0e af c0  and  %i2, 0xfc0, %o5
a0159c84:  9b 3b 60 06  sra  %o5, 6, %o5
a0159c88:  82 0e a0 3f  and  %i2, 0x3f, %g1
a0159c8c:  b2 06 60 01  inc  %i1
a0159c90:  9a 13 7f 80  or  %o5, -128, %o5
a0159c94:  82 10 7f 80  or  %g1, -128, %g1
a0159c98:  c2 2e 60 01  stb  %g1, [ %i1 + 1 ]
a0159c9c:  da 2e 40 00  stb  %o5, [ %i1 ]
a0159ca0:  10 80 00 12  b  0xa0159ce8
a0159ca4:  b0 10 20 05  mov  5, %i0
a0159ca8:  80 a0 60 00  cmp  %g1, 0
a0159cac:  22 80 00 0e  be,a   0xa0159ce4
a0159cb0:  f4 2e 40 00  stb  %i2, [ %i1 ]
a0159cb4:  c0 26 c0 00  clr  [ %i3 ]
a0159cb8:  82 10 20 1b  mov  0x1b, %g1
a0159cbc:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0159cc0:  b2 06 60 01  inc  %i1
a0159cc4:  82 10 20 28  mov  0x28, %g1
a0159cc8:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0159ccc:  b2 06 60 01  inc  %i1
a0159cd0:  82 10 20 42  mov  0x42, %g1
a0159cd4:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0159cd8:  b2 06 60 01  inc  %i1
a0159cdc:  9a 10 20 03  mov  3, %o5
a0159ce0:  f4 2e 40 00  stb  %i2, [ %i1 ]
a0159ce4:  b0 03 60 01  add  %o5, 1, %i0
a0159ce8:  81 c7 e0 08  ret
a0159cec:  81 e8 00 00  restore
