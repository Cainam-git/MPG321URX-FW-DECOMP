# leon2m FUN_a01227f0 0xa01227f0-0xa0122cd8 (1224 bytes)
a01227f0:  9d e3 bf 98  save  %sp, -104, %sp
a01227f4:  23 2a 00 b5  sethi  %hi(0xa802d400), %l1
a01227f8:  c2 04 62 a4  ld  [ %l1 + 0x2a4 ], %g1	! 0xa802d6a4
a01227fc:  da 08 60 07  ldub  [ %g1 + 7 ], %o5
a0122800:  80 a3 60 0a  cmp  %o5, 0xa
a0122804:  02 80 00 07  be  0xa0122820
a0122808:  a0 10 20 04  mov  4, %l0
a012280c:  9a 1b 60 08  xor  %o5, 8, %o5
a0122810:  80 a0 00 0d  cmp  %g0, %o5
a0122814:  92 60 20 00  subx  %g0, 0, %o1
a0122818:  90 0a 60 02  and  %o1, 2, %o0
a012281c:  a0 02 20 03  add  %o0, 3, %l0
a0122820:  92 10 20 00  clr  %o1
a0122824:  7f ff 8c 9c  call  0xa0105a94
a0122828:  90 10 20 01  mov  1, %o0
a012282c:  93 2a 20 10  sll  %o0, 0x10, %o1
a0122830:  96 0c 20 ff  and  %l0, 0xff, %o3
a0122834:  95 32 60 10  srl  %o1, 0x10, %o2
a0122838:  82 5a c0 0a  smul  %o3, %o2, %g1
a012283c:  9b 28 60 02  sll  %g1, 2, %o5
a0122840:  90 03 40 01  add  %o5, %g1, %o0
a0122844:  1f 00 06 8c  sethi  %hi(0x1a3000), %o7
a0122848:  93 32 20 02  srl  %o0, 2, %o1
a012284c:  90 13 e0 30  or  %o7, 0x30, %o0
a0122850:  7f fe f2 48  call  0xa00df170
a0122854:  01 00 00 00  nop
a0122858:  13 33 c0 3a  sethi  %hi(0xcf00e800), %o1
a012285c:  a0 12 63 58  or  %o1, 0x358, %l0	! 0xcf00eb58
a0122860:  98 10 20 07  mov  7, %o4
a0122864:  d8 24 00 00  st  %o4, [ %l0 ]
a0122868:  94 12 63 44  or  %o1, 0x344, %o2
a012286c:  a0 10 20 01  mov  1, %l0
a0122870:  e0 22 80 00  st  %l0, [ %o2 ]
a0122874:  7f ff fd b9  call  0xa0121f58
a0122878:  01 00 00 00  nop
a012287c:  15 33 c0 72  sethi  %hi(0xcf01c800), %o2
a0122880:  92 12 a3 b8  or  %o2, 0x3b8, %o1	! 0xcf01cbb8
a0122884:  96 10 20 ff  mov  0xff, %o3
a0122888:  d6 22 40 00  st  %o3, [ %o1 ]
a012288c:  9a 12 a3 bc  or  %o2, 0x3bc, %o5
a0122890:  c0 23 40 00  clr  [ %o5 ]
a0122894:  82 10 20 fd  mov  0xfd, %g1
a0122898:  90 12 a1 9c  or  %o2, 0x19c, %o0
a012289c:  c2 22 00 00  st  %g1, [ %o0 ]
a01228a0:  98 12 a0 30  or  %o2, 0x30, %o4
a01228a4:  9e 10 20 04  mov  4, %o7
a01228a8:  de 23 00 00  st  %o7, [ %o4 ]
a01228ac:  96 12 a0 04  or  %o2, 4, %o3
a01228b0:  c0 22 c0 00  clr  [ %o3 ]
a01228b4:  e0 22 40 00  st  %l0, [ %o1 ]
a01228b8:  9a 10 20 00  clr  %o5
a01228bc:  82 10 20 00  clr  %g1
a01228c0:  98 10 20 80  mov  0x80, %o4
a01228c4:  9f 3b 00 01  sra  %o4, %g1, %o7
a01228c8:  a0 0b e0 ff  and  %o7, 0xff, %l0
a01228cc:  9a 03 60 01  inc  %o5
a01228d0:  e0 22 40 00  st  %l0, [ %o1 ]
a01228d4:  82 0b 60 ff  and  %o5, 0xff, %g1
a01228d8:  c0 22 80 00  clr  [ %o2 ]
a01228dc:  80 a0 60 07  cmp  %g1, 7
a01228e0:  28 bf ff fa  bleu,a   0xa01228c8
a01228e4:  9f 3b 00 01  sra  %o4, %g1, %o7
a01228e8:  d8 04 62 a4  ld  [ %l1 + 0x2a4 ], %o4
a01228ec:  c2 0b 20 07  ldub  [ %o4 + 7 ], %g1
a01228f0:  80 a0 60 0a  cmp  %g1, 0xa
a01228f4:  02 80 00 06  be  0xa012290c
a01228f8:  9a 10 20 02  mov  2, %o5
a01228fc:  80 a0 60 08  cmp  %g1, 8
a0122900:  02 80 00 03  be  0xa012290c
a0122904:  9a 10 20 01  mov  1, %o5
a0122908:  9a 10 20 03  mov  3, %o5
a012290c:  19 33 c0 3a  sethi  %hi(0xcf00e800), %o4
a0122910:  96 13 23 40  or  %o4, 0x340, %o3	! 0xcf00eb40
a0122914:  da 22 c0 00  st  %o5, [ %o3 ]
a0122918:  17 33 c0 3a  sethi  %hi(0xcf00e800), %o3
a012291c:  9e 12 e3 44  or  %o3, 0x344, %o7	! 0xcf00eb44
a0122920:  c0 23 c0 00  clr  [ %o7 ]
a0122924:  92 12 e3 48  or  %o3, 0x348, %o1
a0122928:  a0 10 20 04  mov  4, %l0
a012292c:  e0 22 40 00  st  %l0, [ %o1 ]
a0122930:  94 12 e3 4c  or  %o3, 0x34c, %o2
a0122934:  c0 22 80 00  clr  [ %o2 ]
a0122938:  82 12 e3 50  or  %o3, 0x350, %g1
a012293c:  c0 20 40 00  clr  [ %g1 ]
a0122940:  da 04 62 a4  ld  [ %l1 + 0x2a4 ], %o5
a0122944:  d0 0b 60 06  ldub  [ %o5 + 6 ], %o0
a0122948:  82 02 3f fb  add  %o0, -5, %g1
a012294c:  80 a0 60 05  cmp  %g1, 5
a0122950:  38 80 00 08  bgu,a   0xa0122970
a0122954:  9e 12 e3 54  or  %o3, 0x354, %o7
a0122958:  15 00 03 07  sethi  %hi(0xc1c00), %o2
a012295c:  83 28 60 02  sll  %g1, 2, %g1
a0122960:  9a 12 a3 40  or  %o2, 0x340, %o5
a0122964:  d0 03 40 01  ld  [ %o5 + %g1 ], %o0
a0122968:  81 c2 00 00  jmp  %o0
a012296c:  01 00 00 00  nop
a0122970:  96 10 20 07  mov  7, %o3	! 0x7
a0122974:  d6 23 c0 00  st  %o3, [ %o7 ]
a0122978:  1b 33 c0 3a  sethi  %hi(0xcf00e800), %o5
a012297c:  a0 13 63 58  or  %o5, 0x358, %l0	! 0xcf00eb58
a0122980:  9e 10 20 07  mov  7, %o7
a0122984:  de 24 00 00  st  %o7, [ %l0 ]
a0122988:  94 13 63 60  or  %o5, 0x360, %o2
a012298c:  d2 02 80 00  ld  [ %o2 ], %o1
a0122990:  82 0a 60 fc  and  %o1, 0xfc, %g1
a0122994:  c2 22 80 00  st  %g1, [ %o2 ]
a0122998:  90 13 63 5c  or  %o5, 0x35c, %o0
a012299c:  c0 22 00 00  clr  [ %o0 ]
a01229a0:  67 fd aa 00  call  0x4008d1a0
a01229a4:  90 10 20 0a  mov  0xa, %o0
a01229a8:  d8 04 62 a4  ld  [ %l1 + 0x2a4 ], %o4
a01229ac:  c2 0b 20 06  ldub  [ %o4 + 6 ], %g1
a01229b0:  80 a0 60 05  cmp  %g1, 5
a01229b4:  26 80 00 09  bl,a   0xa01229d8
a01229b8:  23 33 c0 73  sethi  %hi(0xcf01cc00), %l1
a01229bc:  80 a0 60 07  cmp  %g1, 7
a01229c0:  04 80 00 ab  ble  0xa0122c6c
a01229c4:  19 33 c0 73  sethi  %hi(0xcf01cc00), %o4
a01229c8:  80 a0 60 0a  cmp  %g1, 0xa
a01229cc:  04 80 00 bb  ble  0xa0122cb8
a01229d0:  94 10 20 ff  mov  0xff, %o2
a01229d4:  23 33 c0 73  sethi  %hi(0xcf01cc00), %l1
a01229d8:  9e 10 20 ff  mov  0xff, %o7
a01229dc:  9a 14 61 10  or  %l1, 0x110, %o5
a01229e0:  de 23 40 00  st  %o7, [ %o5 ]
a01229e4:  90 14 61 9c  or  %l1, 0x19c, %o0
a01229e8:  de 22 00 00  st  %o7, [ %o0 ]
a01229ec:  96 14 62 28  or  %l1, 0x228, %o3
a01229f0:  de 22 c0 00  st  %o7, [ %o3 ]
a01229f4:  a0 14 62 b4  or  %l1, 0x2b4, %l0
a01229f8:  de 24 00 00  st  %o7, [ %l0 ]
a01229fc:  17 33 c0 73  sethi  %hi(0xcf01cc00), %o3
a0122a00:  1f 2a 00 9e  sethi  %hi(0xa8027800), %o7
a0122a04:  c2 0b e3 0c  ldub  [ %o7 + 0x30c ], %g1	! 0xa8027b0c
a0122a08:  a0 12 e1 30  or  %o3, 0x130, %l0
a0122a0c:  c2 24 00 00  st  %g1, [ %l0 ]
a0122a10:  92 12 e1 34  or  %o3, 0x134, %o1
a0122a14:  c2 22 40 00  st  %g1, [ %o1 ]
a0122a18:  98 12 e1 38  or  %o3, 0x138, %o4
a0122a1c:  c2 23 00 00  st  %g1, [ %o4 ]
a0122a20:  9a 12 e1 3c  or  %o3, 0x13c, %o5
a0122a24:  c2 23 40 00  st  %g1, [ %o5 ]
a0122a28:  94 12 e1 40  or  %o3, 0x140, %o2
a0122a2c:  c2 22 80 00  st  %g1, [ %o2 ]
a0122a30:  90 12 e1 44  or  %o3, 0x144, %o0
a0122a34:  c2 22 00 00  st  %g1, [ %o0 ]
a0122a38:  a2 12 e1 48  or  %o3, 0x148, %l1
a0122a3c:  c2 24 40 00  st  %g1, [ %l1 ]
a0122a40:  9e 12 e1 4c  or  %o3, 0x14c, %o7
a0122a44:  c2 23 c0 00  st  %g1, [ %o7 ]
a0122a48:  a0 12 e1 bc  or  %o3, 0x1bc, %l0
a0122a4c:  c2 24 00 00  st  %g1, [ %l0 ]
a0122a50:  92 12 e1 c0  or  %o3, 0x1c0, %o1
a0122a54:  c2 22 40 00  st  %g1, [ %o1 ]
a0122a58:  98 12 e1 c4  or  %o3, 0x1c4, %o4
a0122a5c:  c2 23 00 00  st  %g1, [ %o4 ]
a0122a60:  9a 12 e1 c8  or  %o3, 0x1c8, %o5
a0122a64:  c2 23 40 00  st  %g1, [ %o5 ]
a0122a68:  94 12 e1 cc  or  %o3, 0x1cc, %o2
a0122a6c:  c2 22 80 00  st  %g1, [ %o2 ]
a0122a70:  90 12 e1 d0  or  %o3, 0x1d0, %o0
a0122a74:  c2 22 00 00  st  %g1, [ %o0 ]
a0122a78:  a2 12 e1 d4  or  %o3, 0x1d4, %l1
a0122a7c:  c2 24 40 00  st  %g1, [ %l1 ]
a0122a80:  9e 12 e1 d8  or  %o3, 0x1d8, %o7
a0122a84:  c2 23 c0 00  st  %g1, [ %o7 ]
a0122a88:  a0 12 e2 48  or  %o3, 0x248, %l0
a0122a8c:  c2 24 00 00  st  %g1, [ %l0 ]
a0122a90:  92 12 e2 4c  or  %o3, 0x24c, %o1
a0122a94:  c2 22 40 00  st  %g1, [ %o1 ]
a0122a98:  98 12 e2 50  or  %o3, 0x250, %o4
a0122a9c:  c2 23 00 00  st  %g1, [ %o4 ]
a0122aa0:  9a 12 e2 54  or  %o3, 0x254, %o5
a0122aa4:  c2 23 40 00  st  %g1, [ %o5 ]
a0122aa8:  94 12 e2 58  or  %o3, 0x258, %o2
a0122aac:  c2 22 80 00  st  %g1, [ %o2 ]
a0122ab0:  90 12 e2 5c  or  %o3, 0x25c, %o0
a0122ab4:  c2 22 00 00  st  %g1, [ %o0 ]
a0122ab8:  a2 12 e2 60  or  %o3, 0x260, %l1
a0122abc:  c2 24 40 00  st  %g1, [ %l1 ]
a0122ac0:  9e 12 e2 64  or  %o3, 0x264, %o7
a0122ac4:  c2 23 c0 00  st  %g1, [ %o7 ]
a0122ac8:  a0 12 e2 d4  or  %o3, 0x2d4, %l0
a0122acc:  c2 24 00 00  st  %g1, [ %l0 ]
a0122ad0:  92 12 e2 d8  or  %o3, 0x2d8, %o1
a0122ad4:  c2 22 40 00  st  %g1, [ %o1 ]
a0122ad8:  98 12 e2 dc  or  %o3, 0x2dc, %o4
a0122adc:  c2 23 00 00  st  %g1, [ %o4 ]
a0122ae0:  9a 12 e2 e0  or  %o3, 0x2e0, %o5
a0122ae4:  c2 23 40 00  st  %g1, [ %o5 ]
a0122ae8:  94 12 e2 e4  or  %o3, 0x2e4, %o2
a0122aec:  c2 22 80 00  st  %g1, [ %o2 ]
a0122af0:  11 2a 00 b2  sethi  %hi(0xa802c800), %o0
a0122af4:  d4 0a 21 ec  ldub  [ %o0 + 0x1ec ], %o2	! 0xa802c9ec
a0122af8:  a2 12 e2 e8  or  %o3, 0x2e8, %l1
a0122afc:  c2 24 40 00  st  %g1, [ %l1 ]
a0122b00:  9e 12 e2 ec  or  %o3, 0x2ec, %o7
a0122b04:  92 12 e2 f0  or  %o3, 0x2f0, %o1
a0122b08:  a1 2a a0 04  sll  %o2, 4, %l0
a0122b0c:  c2 23 c0 00  st  %g1, [ %o7 ]
a0122b10:  98 04 00 0a  add  %l0, %o2, %o4
a0122b14:  c2 22 40 00  st  %g1, [ %o1 ]
a0122b18:  80 a2 a0 00  cmp  %o2, 0
a0122b1c:  12 80 00 17  bne  0xa0122b78
a0122b20:  92 03 3f ef  add  %o4, -17, %o1
a0122b24:  82 12 e1 0c  or  %o3, 0x10c, %g1
a0122b28:  c0 20 40 00  clr  [ %g1 ]
a0122b2c:  80 a2 a0 00  cmp  %o2, 0
a0122b30:  12 80 00 22  bne  0xa0122bb8
a0122b34:  1f 33 c0 73  sethi  %hi(0xcf01cc00), %o7
a0122b38:  23 33 c0 73  sethi  %hi(0xcf01cc00), %l1
a0122b3c:  96 14 61 98  or  %l1, 0x198, %o3	! 0xcf01cd98
a0122b40:  c0 22 c0 00  clr  [ %o3 ]
a0122b44:  80 a2 a0 00  cmp  %o2, 0
a0122b48:  12 80 00 2c  bne  0xa0122bf8
a0122b4c:  03 33 c0 73  sethi  %hi(0xcf01cc00), %g1
a0122b50:  21 33 c0 73  sethi  %hi(0xcf01cc00), %l0
a0122b54:  90 14 22 24  or  %l0, 0x224, %o0	! 0xcf01ce24
a0122b58:  c0 22 00 00  clr  [ %o0 ]
a0122b5c:  80 a2 a0 00  cmp  %o2, 0
a0122b60:  12 80 00 36  bne  0xa0122c38
a0122b64:  03 33 c0 73  sethi  %hi(0xcf01cc00), %g1
a0122b68:  13 33 c0 73  sethi  %hi(0xcf01cc00), %o1
a0122b6c:  94 12 62 b0  or  %o1, 0x2b0, %o2	! 0xcf01ceb0
a0122b70:  c0 22 80 00  clr  [ %o2 ]
a0122b74:  30 80 00 57  b,a   0xa0122cd0
a0122b78:  9e 12 e1 0c  or  %o3, 0x10c, %o7
a0122b7c:  82 10 20 ff  mov  0xff, %g1
a0122b80:  c2 23 c0 00  st  %g1, [ %o7 ]
a0122b84:  90 0a 60 ff  and  %o1, 0xff, %o0
a0122b88:  a0 12 e0 fc  or  %o3, 0xfc, %l0
a0122b8c:  d0 24 00 00  st  %o0, [ %l0 ]
a0122b90:  98 12 e1 00  or  %o3, 0x100, %o4
a0122b94:  d0 23 00 00  st  %o0, [ %o4 ]
a0122b98:  9a 12 e1 04  or  %o3, 0x104, %o5
a0122b9c:  d0 23 40 00  st  %o0, [ %o5 ]
a0122ba0:  a2 12 e1 08  or  %o3, 0x108, %l1
a0122ba4:  d0 24 40 00  st  %o0, [ %l1 ]
a0122ba8:  80 a2 a0 00  cmp  %o2, 0
a0122bac:  02 bf ff e4  be  0xa0122b3c
a0122bb0:  23 33 c0 73  sethi  %hi(0xcf01cc00), %l1
a0122bb4:  1f 33 c0 73  sethi  %hi(0xcf01cc00), %o7
a0122bb8:  96 13 e1 98  or  %o7, 0x198, %o3	! 0xcf01cd98
a0122bbc:  a2 10 20 ff  mov  0xff, %l1
a0122bc0:  e2 22 c0 00  st  %l1, [ %o3 ]
a0122bc4:  a0 0a 60 ff  and  %o1, 0xff, %l0
a0122bc8:  82 13 e1 88  or  %o7, 0x188, %g1
a0122bcc:  e0 20 40 00  st  %l0, [ %g1 ]
a0122bd0:  98 13 e1 8c  or  %o7, 0x18c, %o4
a0122bd4:  e0 23 00 00  st  %l0, [ %o4 ]
a0122bd8:  9a 13 e1 90  or  %o7, 0x190, %o5
a0122bdc:  e0 23 40 00  st  %l0, [ %o5 ]
a0122be0:  90 13 e1 94  or  %o7, 0x194, %o0
a0122be4:  e0 22 00 00  st  %l0, [ %o0 ]
a0122be8:  80 a2 a0 00  cmp  %o2, 0
a0122bec:  02 bf ff da  be  0xa0122b54
a0122bf0:  21 33 c0 73  sethi  %hi(0xcf01cc00), %l0
a0122bf4:  03 33 c0 73  sethi  %hi(0xcf01cc00), %g1
a0122bf8:  90 10 62 24  or  %g1, 0x224, %o0	! 0xcf01ce24
a0122bfc:  a0 10 20 ff  mov  0xff, %l0
a0122c00:  e0 22 00 00  st  %l0, [ %o0 ]
a0122c04:  96 0a 60 ff  and  %o1, 0xff, %o3
a0122c08:  a2 10 62 14  or  %g1, 0x214, %l1
a0122c0c:  d6 24 40 00  st  %o3, [ %l1 ]
a0122c10:  98 10 62 18  or  %g1, 0x218, %o4
a0122c14:  d6 23 00 00  st  %o3, [ %o4 ]
a0122c18:  9a 10 62 1c  or  %g1, 0x21c, %o5
a0122c1c:  d6 23 40 00  st  %o3, [ %o5 ]
a0122c20:  9e 10 62 20  or  %g1, 0x220, %o7
a0122c24:  d6 23 c0 00  st  %o3, [ %o7 ]
a0122c28:  80 a2 a0 00  cmp  %o2, 0
a0122c2c:  22 bf ff d0  be,a   0xa0122b6c
a0122c30:  13 33 c0 73  sethi  %hi(0xcf01cc00), %o1
a0122c34:  03 33 c0 73  sethi  %hi(0xcf01cc00), %g1
a0122c38:  90 10 62 b0  or  %g1, 0x2b0, %o0	! 0xcf01ceb0
a0122c3c:  a0 10 20 ff  mov  0xff, %l0
a0122c40:  e0 22 00 00  st  %l0, [ %o0 ]
a0122c44:  96 0a 60 ff  and  %o1, 0xff, %o3
a0122c48:  a2 10 62 a0  or  %g1, 0x2a0, %l1
a0122c4c:  d6 24 40 00  st  %o3, [ %l1 ]
a0122c50:  98 10 62 a4  or  %g1, 0x2a4, %o4
a0122c54:  d6 23 00 00  st  %o3, [ %o4 ]
a0122c58:  9a 10 62 a8  or  %g1, 0x2a8, %o5
a0122c5c:  d6 23 40 00  st  %o3, [ %o5 ]
a0122c60:  9e 10 62 ac  or  %g1, 0x2ac, %o7
a0122c64:  d6 23 c0 00  st  %o3, [ %o7 ]
a0122c68:  30 80 00 1a  b,a   0xa0122cd0
a0122c6c:  96 13 21 10  or  %o4, 0x110, %o3
a0122c70:  90 10 20 ff  mov  0xff, %o0
a0122c74:  d0 22 c0 00  st  %o0, [ %o3 ]
a0122c78:  a2 13 21 9c  or  %o4, 0x19c, %l1
a0122c7c:  c0 24 40 00  clr  [ %l1 ]
a0122c80:  92 13 22 28  or  %o4, 0x228, %o1
a0122c84:  c0 22 40 00  clr  [ %o1 ]
a0122c88:  98 13 22 b4  or  %o4, 0x2b4, %o4
a0122c8c:  c0 23 00 00  clr  [ %o4 ]
a0122c90:  10 bf ff 5c  b  0xa0122a00
a0122c94:  17 33 c0 73  sethi  %hi(0xcf01cc00), %o3
a0122c98:  9a 10 20 01  mov  1, %o5
a0122c9c:  21 33 c0 3a  sethi  %hi(0xcf00e800), %l0
a0122ca0:  92 14 23 54  or  %l0, 0x354, %o1	! 0xcf00eb54
a0122ca4:  da 22 40 00  st  %o5, [ %o1 ]
a0122ca8:  10 bf ff 35  b  0xa012297c
a0122cac:  1b 33 c0 3a  sethi  %hi(0xcf00e800), %o5
a0122cb0:  10 bf ff fb  b  0xa0122c9c
a0122cb4:  9a 10 20 05  mov  5, %o5
a0122cb8:  82 13 21 10  or  %o4, 0x110, %g1
a0122cbc:  d4 20 40 00  st  %o2, [ %g1 ]
a0122cc0:  9a 13 21 9c  or  %o4, 0x19c, %o5
a0122cc4:  d4 23 40 00  st  %o2, [ %o5 ]
a0122cc8:  10 bf ff ef  b  0xa0122c84
a0122ccc:  92 13 22 28  or  %o4, 0x228, %o1
a0122cd0:  81 c7 e0 08  ret
a0122cd4:  81 e8 00 00  restore
