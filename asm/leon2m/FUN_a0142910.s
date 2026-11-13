# leon2m FUN_a0142910 0xa0142910-0xa0142e80 (1392 bytes)
a0142910:  9d e3 bf 98  save  %sp, -104, %sp
a0142914:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0142918:  ba 10 61 16  or  %g1, 0x116, %i5	! 0xa802e116
a014291c:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a0142920:  aa 13 62 24  or  %o5, 0x224, %l5	! 0xa802e224
a0142924:  a8 10 20 00  clr  %l4
a0142928:  a6 10 20 00  clr  %l3
a014292c:  ae 10 00 1d  mov  %i5, %l7
a0142930:  a2 5c e0 2a  smul  %l3, 0x2a, %l1
a0142934:  a0 04 40 15  add  %l1, %l5, %l0
a0142938:  c2 0c 20 02  ldub  [ %l0 + 2 ], %g1
a014293c:  80 a0 60 01  cmp  %g1, 1
a0142940:  02 80 00 32  be  0xa0142a08
a0142944:  ac 10 20 02  mov  2, %l6
a0142948:  7f ff fe 08  call  0xa0142168
a014294c:  d0 0c 20 0a  ldub  [ %l0 + 0xa ], %o0
a0142950:  a4 0a 20 ff  and  %o0, 0xff, %l2
a0142954:  80 a4 a0 ff  cmp  %l2, 0xff
a0142958:  02 80 00 49  be  0xa0142a7c
a014295c:  80 a4 a0 06  cmp  %l2, 6
a0142960:  02 80 00 9d  be  0xa0142bd4
a0142964:  9e 10 20 05  mov  5, %o7
a0142968:  83 2c a0 03  sll  %l2, 3, %g1
a014296c:  9a 00 40 12  add  %g1, %l2, %o5
a0142970:  82 03 40 0d  add  %o5, %o5, %g1
a0142974:  de 15 c0 01  lduh  [ %l7 + %g1 ], %o7
a0142978:  93 2b e0 10  sll  %o7, 0x10, %o1
a014297c:  91 32 60 1c  srl  %o1, 0x1c, %o0
a0142980:  80 a2 20 05  cmp  %o0, 5
a0142984:  02 80 00 57  be  0xa0142ae0
a0142988:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a014298c:  9e 05 3f fa  add  %l4, -6, %o7
a0142990:  a2 0b e0 ff  and  %o7, 0xff, %l1
a0142994:  80 a4 60 01  cmp  %l1, 1
a0142998:  38 80 00 21  bgu,a   0xa0142a1c
a014299c:  90 10 00 13  mov  %l3, %o0
a01429a0:  d4 14 00 00  lduh  [ %l0 ], %o2
a01429a4:  80 8a a8 00  btst  0x800, %o2
a01429a8:  22 80 00 1d  be,a   0xa0142a1c
a01429ac:  90 10 00 13  mov  %l3, %o0
a01429b0:  c2 0c 20 03  ldub  [ %l0 + 3 ], %g1
a01429b4:  80 a0 60 05  cmp  %g1, 5
a01429b8:  32 80 00 02  bne,a   0xa01429c0
a01429bc:  82 10 20 01  mov  1, %g1
a01429c0:  c2 2c 20 09  stb  %g1, [ %l0 + 9 ]
a01429c4:  c2 0c 20 02  ldub  [ %l0 + 2 ], %g1
a01429c8:  80 a0 60 03  cmp  %g1, 3
a01429cc:  22 80 00 1c  be,a   0xa0142a3c
a01429d0:  e4 0c 20 03  ldub  [ %l0 + 3 ], %l2
a01429d4:  80 a0 60 03  cmp  %g1, 3
a01429d8:  14 80 00 2c  bg  0xa0142a88
a01429dc:  80 a0 60 04  cmp  %g1, 4
a01429e0:  80 a0 60 02  cmp  %g1, 2
a01429e4:  32 80 01 21  bne,a   0xa0142e68
a01429e8:  a8 05 20 01  inc  %l4
a01429ec:  10 80 00 b7  b  0xa0142cc8
a01429f0:  90 10 00 13  mov  %l3, %o0
a01429f4:  a0 04 40 15  add  %l1, %l5, %l0
a01429f8:  c2 0c 20 02  ldub  [ %l0 + 2 ], %g1
a01429fc:  80 a0 60 01  cmp  %g1, 1
a0142a00:  12 bf ff d2  bne  0xa0142948
a0142a04:  01 00 00 00  nop
a0142a08:  c2 2c 20 09  stb  %g1, [ %l0 + 9 ]
a0142a0c:  7f ff 7c ba  call  0xa0121cf4
a0142a10:  90 10 00 13  mov  %l3, %o0
a0142a14:  10 80 01 15  b  0xa0142e68
a0142a18:  a8 05 20 01  inc  %l4
a0142a1c:  d2 0c 20 1f  ldub  [ %l0 + 0x1f ], %o1
a0142a20:  7f ff 7a 61  call  0xa01213a4
a0142a24:  d4 0c 20 09  ldub  [ %l0 + 9 ], %o2
a0142a28:  c2 0c 20 02  ldub  [ %l0 + 2 ], %g1
a0142a2c:  80 a0 60 03  cmp  %g1, 3
a0142a30:  12 bf ff ea  bne  0xa01429d8
a0142a34:  d0 2c 20 09  stb  %o0, [ %l0 + 9 ]
a0142a38:  e4 0c 20 03  ldub  [ %l0 + 3 ], %l2
a0142a3c:  80 a4 a0 05  cmp  %l2, 5
a0142a40:  22 80 00 79  be,a   0xa0142c24
a0142a44:  d2 14 00 00  lduh  [ %l0 ], %o1
a0142a48:  ec 2c 20 02  stb  %l6, [ %l0 + 2 ]
a0142a4c:  c0 34 20 04  clrh  [ %l0 + 4 ]
a0142a50:  c0 34 20 16  clrh  [ %l0 + 0x16 ]
a0142a54:  c0 34 20 18  clrh  [ %l0 + 0x18 ]
a0142a58:  c0 34 20 1a  clrh  [ %l0 + 0x1a ]
a0142a5c:  c0 34 20 1c  clrh  [ %l0 + 0x1c ]
a0142a60:  c0 34 20 1e  clrh  [ %l0 + 0x1e ]
a0142a64:  c0 34 20 20  clrh  [ %l0 + 0x20 ]
a0142a68:  c0 2c 20 22  clrb  [ %l0 + 0x22 ]
a0142a6c:  c0 2c 20 23  clrb  [ %l0 + 0x23 ]
a0142a70:  c0 2c 20 24  clrb  [ %l0 + 0x24 ]
a0142a74:  10 80 00 fc  b  0xa0142e64
a0142a78:  c0 34 20 26  clrh  [ %l0 + 0x26 ]
a0142a7c:  90 10 20 01  mov  1, %o0
a0142a80:  10 80 00 f9  b  0xa0142e64
a0142a84:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a0142a88:  32 80 00 f8  bne,a   0xa0142e68
a0142a8c:  a8 05 20 01  inc  %l4
a0142a90:  e2 0c 20 03  ldub  [ %l0 + 3 ], %l1
a0142a94:  80 a4 60 05  cmp  %l1, 5
a0142a98:  02 80 00 b8  be  0xa0142d78
a0142a9c:  15 00 00 04  sethi  %hi(0x1000), %o2
a0142aa0:  de 14 00 00  lduh  [ %l0 ], %o7
a0142aa4:  a6 13 c0 0a  or  %o7, %o2, %l3
a0142aa8:  e6 34 00 00  sth  %l3, [ %l0 ]
a0142aac:  c0 34 20 04  clrh  [ %l0 + 4 ]
a0142ab0:  c0 34 20 16  clrh  [ %l0 + 0x16 ]
a0142ab4:  c0 34 20 18  clrh  [ %l0 + 0x18 ]
a0142ab8:  c0 34 20 1a  clrh  [ %l0 + 0x1a ]
a0142abc:  c0 34 20 1c  clrh  [ %l0 + 0x1c ]
a0142ac0:  c0 34 20 1e  clrh  [ %l0 + 0x1e ]
a0142ac4:  c0 34 20 20  clrh  [ %l0 + 0x20 ]
a0142ac8:  c0 2c 20 22  clrb  [ %l0 + 0x22 ]
a0142acc:  c0 2c 20 23  clrb  [ %l0 + 0x23 ]
a0142ad0:  c0 2c 20 24  clrb  [ %l0 + 0x24 ]
a0142ad4:  c0 34 20 26  clrh  [ %l0 + 0x26 ]
a0142ad8:  10 80 00 e3  b  0xa0142e64
a0142adc:  ec 2c 20 02  stb  %l6, [ %l0 + 2 ]
a0142ae0:  94 00 40 17  add  %g1, %l7, %o2
a0142ae4:  c2 12 a0 06  lduh  [ %o2 + 6 ], %g1
a0142ae8:  da 12 a0 08  lduh  [ %o2 + 8 ], %o5
a0142aec:  d8 12 a0 0a  lduh  [ %o2 + 0xa ], %o4
a0142af0:  d6 12 a0 0c  lduh  [ %o2 + 0xc ], %o3
a0142af4:  d6 34 20 18  sth  %o3, [ %l0 + 0x18 ]
a0142af8:  c2 34 20 1a  sth  %g1, [ %l0 + 0x1a ]
a0142afc:  da 34 20 1c  sth  %o5, [ %l0 + 0x1c ]
a0142b00:  d8 34 20 16  sth  %o4, [ %l0 + 0x16 ]
a0142b04:  97 32 60 1a  srl  %o1, 0x1a, %o3
a0142b08:  d8 14 40 15  lduh  [ %l1 + %l5 ], %o4
a0142b0c:  82 0a e0 01  and  %o3, 1, %g1
a0142b10:  1b 3f ff e0  sethi  %hi(0xffff8000), %o5
a0142b14:  96 2b 00 0d  andn  %o4, %o5, %o3
a0142b18:  83 28 60 0f  sll  %g1, 0xf, %g1
a0142b1c:  9a 12 c0 01  or  %o3, %g1, %o5
a0142b20:  99 32 60 19  srl  %o1, 0x19, %o4
a0142b24:  17 00 00 10  sethi  %hi(0x4000), %o3
a0142b28:  98 0b 20 01  and  %o4, 1, %o4
a0142b2c:  82 2b 40 0b  andn  %o5, %o3, %g1
a0142b30:  99 2b 20 0e  sll  %o4, 0xe, %o4
a0142b34:  96 10 40 0c  or  %g1, %o4, %o3
a0142b38:  9b 32 60 18  srl  %o1, 0x18, %o5
a0142b3c:  03 00 00 08  sethi  %hi(0x2000), %g1
a0142b40:  9a 0b 60 01  and  %o5, 1, %o5
a0142b44:  98 2a c0 01  andn  %o3, %g1, %o4
a0142b48:  9b 2b 60 0d  sll  %o5, 0xd, %o5
a0142b4c:  96 13 00 0d  or  %o4, %o5, %o3
a0142b50:  d6 34 40 15  sth  %o3, [ %l1 + %l5 ]
a0142b54:  c2 0a a0 04  ldub  [ %o2 + 4 ], %g1
a0142b58:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a0142b5c:  c2 2c 20 28  stb  %g1, [ %l0 + 0x28 ]
a0142b60:  d6 14 40 15  lduh  [ %l1 + %l5 ], %o3
a0142b64:  99 32 60 0a  srl  %o1, 0xa, %o4
a0142b68:  9a 0b 28 00  and  %o4, 0x800, %o5
a0142b6c:  91 32 60 0a  srl  %o1, 0xa, %o0
a0142b70:  82 0a f3 ff  and  %o3, -3073, %g1
a0142b74:  96 10 40 0d  or  %g1, %o5, %o3
a0142b78:  98 0a 24 00  and  %o0, 0x400, %o4
a0142b7c:  90 12 c0 0c  or  %o3, %o4, %o0
a0142b80:  9b 32 60 0a  srl  %o1, 0xa, %o5
a0142b84:  98 0b 62 00  and  %o5, 0x200, %o4
a0142b88:  97 32 60 0a  srl  %o1, 0xa, %o3
a0142b8c:  82 0a 3c ff  and  %o0, -769, %g1
a0142b90:  90 10 40 0c  or  %g1, %o4, %o0
a0142b94:  9a 0a e1 00  and  %o3, 0x100, %o5
a0142b98:  96 12 00 0d  or  %o0, %o5, %o3
a0142b9c:  99 32 60 0b  srl  %o1, 0xb, %o4
a0142ba0:  92 0b 20 40  and  %o4, 0x40, %o1
a0142ba4:  82 0a ff 3f  and  %o3, -193, %g1
a0142ba8:  90 0b e0 01  and  %o7, 1, %o0
a0142bac:  9e 10 40 09  or  %g1, %o1, %o7
a0142bb0:  d8 12 a0 02  lduh  [ %o2 + 2 ], %o4
a0142bb4:  9b 2a 20 07  sll  %o0, 7, %o5
a0142bb8:  94 13 c0 0d  or  %o7, %o5, %o2
a0142bbc:  97 33 20 0f  srl  %o4, 0xf, %o3
a0142bc0:  93 2a e0 05  sll  %o3, 5, %o1
a0142bc4:  90 0a bf df  and  %o2, -33, %o0
a0142bc8:  82 12 00 09  or  %o0, %o1, %g1
a0142bcc:  10 bf ff 70  b  0xa014298c
a0142bd0:  c2 34 40 15  sth  %g1, [ %l1 + %l5 ]
a0142bd4:  de 2c 20 03  stb  %o7, [ %l0 + 3 ]
a0142bd8:  7f fe d9 c7  call  0xa00f92f4
a0142bdc:  d0 0c 20 0b  ldub  [ %l0 + 0xb ], %o0
a0142be0:  d0 34 20 1a  sth  %o0, [ %l0 + 0x1a ]
a0142be4:  7f fe d9 cc  call  0xa00f9314
a0142be8:  d0 0c 20 0b  ldub  [ %l0 + 0xb ], %o0
a0142bec:  d0 34 20 1c  sth  %o0, [ %l0 + 0x1c ]
a0142bf0:  7f fe d9 d1  call  0xa00f9334
a0142bf4:  d0 0c 20 0b  ldub  [ %l0 + 0xb ], %o0
a0142bf8:  d0 34 20 16  sth  %o0, [ %l0 + 0x16 ]
a0142bfc:  7f fe d9 d6  call  0xa00f9354
a0142c00:  d0 0c 20 0b  ldub  [ %l0 + 0xb ], %o0
a0142c04:  d0 34 20 18  sth  %o0, [ %l0 + 0x18 ]
a0142c08:  d8 14 40 15  lduh  [ %l1 + %l5 ], %o4
a0142c0c:  17 3f ff e0  sethi  %hi(0xffff8000), %o3
a0142c10:  94 2b 00 0b  andn  %o4, %o3, %o2
a0142c14:  13 00 00 10  sethi  %hi(0x4000), %o1
a0142c18:  82 2a 80 09  andn  %o2, %o1, %g1
a0142c1c:  10 bf ff 5c  b  0xa014298c
a0142c20:  c2 34 40 15  sth  %g1, [ %l1 + %l5 ]
a0142c24:  80 8a 68 00  btst  0x800, %o1
a0142c28:  12 80 00 61  bne  0xa0142dac
a0142c2c:  01 00 00 00  nop
a0142c30:  da 0c 20 09  ldub  [ %l0 + 9 ], %o5
a0142c34:  d8 0c 20 08  ldub  [ %l0 + 8 ], %o4
a0142c38:  96 0b 60 ff  and  %o5, 0xff, %o3
a0142c3c:  80 a3 00 0b  cmp  %o4, %o3
a0142c40:  02 80 00 05  be  0xa0142c54
a0142c44:  80 a3 20 01  cmp  %o4, 1
a0142c48:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a0142c4c:  10 80 00 86  b  0xa0142e64
a0142c50:  ec 2c 20 02  stb  %l6, [ %l0 + 2 ]
a0142c54:  02 bf ff fd  be  0xa0142c48
a0142c58:  80 a3 20 01  cmp  %o4, 1
a0142c5c:  06 80 00 82  bl  0xa0142e64
a0142c60:  80 a3 20 05  cmp  %o4, 5
a0142c64:  34 80 00 81  bg,a   0xa0142e68
a0142c68:  a8 05 20 01  inc  %l4
a0142c6c:  67 fd 2a 4a  call  0x4008d594
a0142c70:  d0 14 20 06  lduh  [ %l0 + 6 ], %o0
a0142c74:  9b 2a 20 10  sll  %o0, 0x10, %o5
a0142c78:  99 33 60 10  srl  %o5, 0x10, %o4
a0142c7c:  80 a3 20 64  cmp  %o4, 0x64
a0142c80:  28 80 00 7a  bleu,a   0xa0142e68
a0142c84:  a8 05 20 01  inc  %l4
a0142c88:  90 10 00 10  mov  %l0, %o0
a0142c8c:  7f ff fe f4  call  0xa014285c
a0142c90:  92 10 00 13  mov  %l3, %o1
a0142c94:  82 10 20 04  mov  4, %g1
a0142c98:  c2 2c 20 02  stb  %g1, [ %l0 + 2 ]
a0142c9c:  7f fe 6a 5e  call  0xa00dd614
a0142ca0:  90 10 20 02  mov  2, %o0
a0142ca4:  80 8a 20 ff  btst  0xff, %o0
a0142ca8:  22 80 00 70  be,a   0xa0142e68
a0142cac:  a8 05 20 01  inc  %l4
a0142cb0:  21 00 06 9b  sethi  %hi(0x1a6c00), %l0
a0142cb4:  90 14 21 40  or  %l0, 0x140, %o0	! 0x1a6d40
a0142cb8:  7f fe 71 2e  call  0xa00df170
a0142cbc:  92 10 00 13  mov  %l3, %o1
a0142cc0:  10 80 00 6a  b  0xa0142e68
a0142cc4:  a8 05 20 01  inc  %l4
a0142cc8:  7f fe d8 a4  call  0xa00f8f58
a0142ccc:  92 10 20 00  clr  %o1
a0142cd0:  99 2c a0 03  sll  %l2, 3, %o4
a0142cd4:  96 03 00 12  add  %o4, %l2, %o3
a0142cd8:  90 02 c0 0b  add  %o3, %o3, %o0
a0142cdc:  92 02 00 1d  add  %o0, %i5, %o1
a0142ce0:  e4 12 60 02  lduh  [ %o1 + 2 ], %l2
a0142ce4:  90 10 00 13  mov  %l3, %o0
a0142ce8:  80 8c a0 20  btst  0x20, %l2
a0142cec:  12 80 00 04  bne  0xa0142cfc
a0142cf0:  92 10 20 b0  mov  0xb0, %o1
a0142cf4:  90 10 00 13  mov  %l3, %o0
a0142cf8:  92 10 20 04  mov  4, %o1
a0142cfc:  7f ff 76 cc  call  0xa012082c
a0142d00:  01 00 00 00  nop
a0142d04:  da 0c 20 09  ldub  [ %l0 + 9 ], %o5
a0142d08:  80 a3 60 01  cmp  %o5, 1
a0142d0c:  22 80 00 57  be,a   0xa0142e68
a0142d10:  a8 05 20 01  inc  %l4
a0142d14:  c2 0c 20 03  ldub  [ %l0 + 3 ], %g1
a0142d18:  80 a0 60 05  cmp  %g1, 5
a0142d1c:  32 80 00 53  bne,a   0xa0142e68
a0142d20:  a8 05 20 01  inc  %l4
a0142d24:  67 fd 2a 19  call  0x4008d588
a0142d28:  01 00 00 00  nop
a0142d2c:  67 fd 2a 17  call  0x4008d588
a0142d30:  d0 34 20 06  sth  %o0, [ %l0 + 6 ]
a0142d34:  d0 34 20 12  sth  %o0, [ %l0 + 0x12 ]
a0142d38:  e2 0c 20 09  ldub  [ %l0 + 9 ], %l1
a0142d3c:  9e 10 20 03  mov  3, %o7
a0142d40:  de 2c 20 02  stb  %o7, [ %l0 + 2 ]
a0142d44:  e2 2c 20 08  stb  %l1, [ %l0 + 8 ]
a0142d48:  7f fe 6a 33  call  0xa00dd614
a0142d4c:  90 10 20 02  mov  2, %o0
a0142d50:  80 8a 20 ff  btst  0xff, %o0
a0142d54:  22 80 00 45  be,a   0xa0142e68
a0142d58:  a8 05 20 01  inc  %l4
a0142d5c:  15 00 06 9b  sethi  %hi(0x1a6c00), %o2
a0142d60:  90 12 a1 60  or  %o2, 0x160, %o0	! 0x1a6d60
a0142d64:  92 10 00 13  mov  %l3, %o1
a0142d68:  7f fe 71 02  call  0xa00df170
a0142d6c:  d4 14 20 06  lduh  [ %l0 + 6 ], %o2
a0142d70:  10 80 00 3e  b  0xa0142e68
a0142d74:  a8 05 20 01  inc  %l4
a0142d78:  e4 14 00 00  lduh  [ %l0 ], %l2
a0142d7c:  80 8c a8 00  btst  0x800, %l2
a0142d80:  12 80 00 15  bne  0xa0142dd4
a0142d84:  01 00 00 00  nop
a0142d88:  c2 0c 20 09  ldub  [ %l0 + 9 ], %g1
a0142d8c:  80 a0 60 01  cmp  %g1, 1
a0142d90:  22 80 00 1b  be,a   0xa0142dfc
a0142d94:  c2 2c 20 08  stb  %g1, [ %l0 + 8 ]
a0142d98:  90 10 00 10  mov  %l0, %o0
a0142d9c:  7f ff fe b0  call  0xa014285c
a0142da0:  92 10 00 13  mov  %l3, %o1
a0142da4:  10 80 00 31  b  0xa0142e68
a0142da8:  a8 05 20 01  inc  %l4
a0142dac:  7f fe ea 9d  call  0xa00fd820
a0142db0:  90 10 00 13  mov  %l3, %o0
a0142db4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0142db8:  80 a2 20 b1  cmp  %o0, 0xb1
a0142dbc:  02 bf ff 9d  be  0xa0142c30
a0142dc0:  80 a4 e0 03  cmp  %l3, 3
a0142dc4:  28 bf ff 22  bleu,a   0xa0142a4c
a0142dc8:  ec 2c 20 02  stb  %l6, [ %l0 + 2 ]
a0142dcc:  10 bf ff 9a  b  0xa0142c34
a0142dd0:  da 0c 20 09  ldub  [ %l0 + 9 ], %o5
a0142dd4:  7f fe ea 93  call  0xa00fd820
a0142dd8:  90 10 00 13  mov  %l3, %o0
a0142ddc:  92 0a 20 ff  and  %o0, 0xff, %o1
a0142de0:  80 a2 60 b1  cmp  %o1, 0xb1
a0142de4:  02 bf ff e9  be  0xa0142d88
a0142de8:  80 a4 e0 03  cmp  %l3, 3
a0142dec:  38 bf ff e8  bgu,a   0xa0142d8c
a0142df0:  c2 0c 20 09  ldub  [ %l0 + 9 ], %g1
a0142df4:  10 bf ff 16  b  0xa0142a4c
a0142df8:  ec 2c 20 02  stb  %l6, [ %l0 + 2 ]
a0142dfc:  67 fd 29 e3  call  0x4008d588
a0142e00:  ec 2c 20 02  stb  %l6, [ %l0 + 2 ]
a0142e04:  d6 14 00 00  lduh  [ %l0 ], %o3
a0142e08:  d0 34 20 06  sth  %o0, [ %l0 + 6 ]
a0142e0c:  19 00 00 04  sethi  %hi(0x1000), %o4
a0142e10:  90 12 c0 0c  or  %o3, %o4, %o0
a0142e14:  d0 34 00 00  sth  %o0, [ %l0 ]
a0142e18:  c0 34 20 04  clrh  [ %l0 + 4 ]
a0142e1c:  c0 34 20 16  clrh  [ %l0 + 0x16 ]
a0142e20:  c0 34 20 18  clrh  [ %l0 + 0x18 ]
a0142e24:  c0 34 20 1a  clrh  [ %l0 + 0x1a ]
a0142e28:  c0 34 20 1c  clrh  [ %l0 + 0x1c ]
a0142e2c:  c0 34 20 1e  clrh  [ %l0 + 0x1e ]
a0142e30:  c0 34 20 20  clrh  [ %l0 + 0x20 ]
a0142e34:  c0 2c 20 22  clrb  [ %l0 + 0x22 ]
a0142e38:  c0 2c 20 23  clrb  [ %l0 + 0x23 ]
a0142e3c:  c0 2c 20 24  clrb  [ %l0 + 0x24 ]
a0142e40:  c0 34 20 26  clrh  [ %l0 + 0x26 ]
a0142e44:  7f fe 69 f4  call  0xa00dd614
a0142e48:  90 10 20 02  mov  2, %o0
a0142e4c:  80 8a 20 ff  btst  0xff, %o0
a0142e50:  22 80 00 06  be,a   0xa0142e68
a0142e54:  a8 05 20 01  inc  %l4
a0142e58:  1b 00 06 9b  sethi  %hi(0x1a6c00), %o5
a0142e5c:  10 bf ff 97  b  0xa0142cb8
a0142e60:  90 13 61 88  or  %o5, 0x188, %o0	! 0x1a6d88
a0142e64:  a8 05 20 01  inc  %l4
a0142e68:  a6 0d 20 ff  and  %l4, 0xff, %l3
a0142e6c:  80 a4 e0 03  cmp  %l3, 3
a0142e70:  08 bf fe e1  bleu  0xa01429f4
a0142e74:  a2 5c e0 2a  smul  %l3, 0x2a, %l1
a0142e78:  81 c7 e0 08  ret
a0142e7c:  81 e8 00 00  restore
