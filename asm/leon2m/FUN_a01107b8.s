# leon2m FUN_a01107b8 0xa01107b8-0xa0110d64 (1452 bytes)
a01107b8:  9d e3 bf 98  save  %sp, -104, %sp
a01107bc:  a0 0e 20 ff  and  %i0, 0xff, %l0
a01107c0:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a01107c4:  a2 10 63 c4  or  %g1, 0x3c4, %l1	! 0xa802d7c4
a01107c8:  80 a4 20 01  cmp  %l0, 1
a01107cc:  02 80 00 07  be  0xa01107e8
a01107d0:  b8 10 20 01  mov  1, %i4
a01107d4:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a01107d8:  a2 12 23 44  or  %o0, 0x344, %l1	! 0xa802d744
a01107dc:  80 a4 20 02  cmp  %l0, 2
a01107e0:  02 80 01 1f  be  0xa0110c5c
a01107e4:  b8 10 20 00  clr  %i4
a01107e8:  d8 14 60 16  lduh  [ %l1 + 0x16 ], %o4
a01107ec:  80 a3 20 00  cmp  %o4, 0
a01107f0:  02 80 01 5b  be  0xa0110d5c
a01107f4:  9e 10 00 0c  mov  %o4, %o7
a01107f8:  2f 2a 00 b5  sethi  %hi(0xa802d400), %l7
a01107fc:  d4 05 e2 a4  ld  [ %l7 + 0x2a4 ], %o2	! 0xa802d6a4
a0110800:  da 12 a0 08  lduh  [ %o2 + 8 ], %o5
a0110804:  c2 14 60 14  lduh  [ %l1 + 0x14 ], %g1
a0110808:  9b 33 60 01  srl  %o5, 1, %o5
a011080c:  80 a0 40 0d  cmp  %g1, %o5
a0110810:  0a 80 00 fd  bcs  0xa0110c04
a0110814:  ba 10 00 01  mov  %g1, %i5
a0110818:  a6 10 00 0d  mov  %o5, %l3
a011081c:  80 a4 20 01  cmp  %l0, 1
a0110820:  02 80 01 13  be  0xa0110c6c
a0110824:  aa 20 40 0d  sub  %g1, %o5, %l5
a0110828:  80 a4 20 01  cmp  %l0, 1
a011082c:  04 80 01 3b  ble  0xa0110d18
a0110830:  80 a4 20 02  cmp  %l0, 2
a0110834:  02 80 01 01  be  0xa0110c38
a0110838:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a011083c:  a9 2f 60 10  sll  %i5, 0x10, %l4
a0110840:  ec 05 e2 a4  ld  [ %l7 + 0x2a4 ], %l6
a0110844:  83 2b e0 10  sll  %o7, 0x10, %g1
a0110848:  a5 35 20 10  srl  %l4, 0x10, %l2
a011084c:  83 30 60 10  srl  %g1, 0x10, %g1
a0110850:  d8 15 a0 08  lduh  [ %l6 + 8 ], %o4
a0110854:  95 33 20 01  srl  %o4, 1, %o2
a0110858:  96 04 80 01  add  %l2, %g1, %o3
a011085c:  a4 22 80 13  sub  %o2, %l3, %l2
a0110860:  80 a2 c0 0a  cmp  %o3, %o2
a0110864:  14 80 00 04  bg  0xa0110874
a0110868:  a8 20 40 12  sub  %g1, %l2, %l4
a011086c:  a4 10 00 01  mov  %g1, %l2
a0110870:  a8 10 20 00  clr  %l4
a0110874:  da 14 60 0c  lduh  [ %l1 + 0xc ], %o5
a0110878:  95 2b e0 10  sll  %o7, 0x10, %o2
a011087c:  b7 32 a0 10  srl  %o2, 0x10, %i3
a0110880:  90 5b 40 12  smul  %o5, %l2, %o0
a0110884:  92 5b 40 14  smul  %o5, %l4, %o1
a0110888:  81 80 00 00  mov  %g0, %y
a011088c:  01 00 00 00  nop
a0110890:  01 00 00 00  nop
a0110894:  01 00 00 00  nop
a0110898:  94 72 00 1b  udiv  %o0, %i3, %o2
a011089c:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a01108a0:  81 80 00 00  mov  %g0, %y
a01108a4:  01 00 00 00  nop
a01108a8:  01 00 00 00  nop
a01108ac:  01 00 00 00  nop
a01108b0:  ac 72 40 1b  udiv  %o1, %i3, %l6
a01108b4:  90 16 a3 c4  or  %i2, 0x3c4, %o0
a01108b8:  80 a4 20 01  cmp  %l0, 1
a01108bc:  02 80 00 06  be  0xa01108d4
a01108c0:  d8 0c 60 26  ldub  [ %l1 + 0x26 ], %o4
a01108c4:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a01108c8:  80 a4 20 02  cmp  %l0, 2
a01108cc:  02 80 01 0c  be  0xa0110cfc
a01108d0:  90 12 e3 44  or  %o3, 0x344, %o0
a01108d4:  b4 10 20 07  mov  7, %i2
a01108d8:  f4 2a 20 25  stb  %i2, [ %o0 + 0x25 ]
a01108dc:  80 a4 20 02  cmp  %l0, 2
a01108e0:  08 80 00 03  bleu  0xa01108ec
a01108e4:  d8 2a 20 26  stb  %o4, [ %o0 + 0x26 ]
a01108e8:  b0 10 20 00  clr  %i0
a01108ec:  92 0e 20 ff  and  %i0, 0xff, %o1
a01108f0:  83 2a 60 02  sll  %o1, 2, %g1
a01108f4:  37 00 06 6b  sethi  %hi(0x19ac00), %i3
a01108f8:  92 16 e2 d8  or  %i3, 0x2d8, %o1	! 0x19aed8
a01108fc:  f4 02 40 01  ld  [ %o1 + %g1 ], %i2
a0110900:  d6 06 a0 10  ld  [ %i2 + 0x10 ], %o3
a0110904:  1b 3f c0 00  sethi  %hi(0xff000000), %o5
a0110908:  b4 0b 20 ff  and  %o4, 0xff, %i2
a011090c:  b0 13 60 ff  or  %o5, 0xff, %i0
a0110910:  9a 0a c0 18  and  %o3, %i0, %o5
a0110914:  83 2e a0 10  sll  %i2, 0x10, %g1
a0110918:  b0 13 40 01  or  %o5, %g1, %i0
a011091c:  98 10 20 20  mov  0x20, %o4
a0110920:  d8 2a 20 24  stb  %o4, [ %o0 + 0x24 ]
a0110924:  80 a4 20 02  cmp  %l0, 2
a0110928:  08 80 00 e1  bleu  0xa0110cac
a011092c:  96 16 22 01  or  %i0, 0x201, %o3
a0110930:  98 10 20 00  clr  %o4
a0110934:  b1 2b 20 02  sll  %o4, 2, %i0
a0110938:  d0 02 40 18  ld  [ %o1 + %i0 ], %o0
a011093c:  98 03 20 01  inc  %o4
a0110940:  d6 22 20 10  st  %o3, [ %o0 + 0x10 ]
a0110944:  80 a3 20 02  cmp  %o4, 2
a0110948:  28 bf ff fc  bleu,a   0xa0110938
a011094c:  b1 2b 20 02  sll  %o4, 2, %i0
a0110950:  80 a4 20 02  cmp  %l0, 2
a0110954:  08 80 00 dc  bleu  0xa0110cc4
a0110958:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a011095c:  98 10 20 00  clr  %o4
a0110960:  92 16 a2 cc  or  %i2, 0x2cc, %o1
a0110964:  83 2b 20 02  sll  %o4, 2, %g1
a0110968:  d0 02 40 01  ld  [ %o1 + %g1 ], %o0
a011096c:  98 03 20 01  inc  %o4
a0110970:  d6 22 20 10  st  %o3, [ %o0 + 0x10 ]
a0110974:  80 a3 20 02  cmp  %o4, 2
a0110978:  08 bf ff fc  bleu  0xa0110968
a011097c:  83 2b 20 02  sll  %o4, 2, %g1
a0110980:  97 2b e0 10  sll  %o7, 0x10, %o3
a0110984:  9b 32 e0 10  srl  %o3, 0x10, %o5
a0110988:  d6 04 40 00  ld  [ %l1 ], %o3
a011098c:  80 a3 40 12  cmp  %o5, %l2
a0110990:  90 10 00 0b  mov  %o3, %o0
a0110994:  08 80 00 06  bleu  0xa01109ac
a0110998:  b0 10 00 0b  mov  %o3, %i0
a011099c:  f0 0c 60 24  ldub  [ %l1 + 0x24 ], %i0
a01109a0:  93 36 20 03  srl  %i0, 3, %o1
a01109a4:  82 5a 40 0a  smul  %o1, %o2, %g1
a01109a8:  b0 02 c0 01  add  %o3, %g1, %i0
a01109ac:  d8 0c 60 3e  ldub  [ %l1 + 0x3e ], %o4
a01109b0:  80 8b 20 01  btst  1, %o4
a01109b4:  02 80 00 1a  be  0xa0110a1c
a01109b8:  83 2a a0 10  sll  %o2, 0x10, %g1
a01109bc:  9b 2f 60 10  sll  %i5, 0x10, %o5
a01109c0:  83 2b e0 10  sll  %o7, 0x10, %g1
a01109c4:  d8 05 e2 a4  ld  [ %l7 + 0x2a4 ], %o4
a01109c8:  93 33 60 10  srl  %o5, 0x10, %o1
a01109cc:  bb 30 60 10  srl  %g1, 0x10, %i5
a01109d0:  ee 13 20 08  lduh  [ %o4 + 8 ], %l7
a01109d4:  9e 02 40 1d  add  %o1, %i5, %o7
a01109d8:  9b 35 e0 01  srl  %l7, 1, %o5
a01109dc:  80 a3 c0 0d  cmp  %o7, %o5
a01109e0:  04 80 00 bf  ble  0xa0110cdc
a01109e4:  98 23 40 12  sub  %o5, %l2, %o4
a01109e8:  80 a2 40 0d  cmp  %o1, %o5
a01109ec:  3a 80 00 c7  bcc,a   0xa0110d08
a01109f0:  90 23 40 14  sub  %o5, %l4, %o0
a01109f4:  fa 0c 60 24  ldub  [ %l1 + 0x24 ], %i5
a01109f8:  b0 23 40 14  sub  %o5, %l4, %i0
a01109fc:  af 37 60 03  srl  %i5, 3, %l7
a0110a00:  92 5d c0 16  smul  %l7, %l6, %o1
a0110a04:  9e 23 40 12  sub  %o5, %l2, %o7
a0110a08:  aa 26 00 15  sub  %i0, %l5, %l5
a0110a0c:  a6 23 c0 13  sub  %o7, %l3, %l3
a0110a10:  96 02 c0 09  add  %o3, %o1, %o3
a0110a14:  b0 10 00 08  mov  %o0, %i0
a0110a18:  83 2a a0 10  sll  %o2, 0x10, %g1
a0110a1c:  98 10 00 0b  mov  %o3, %o4
a0110a20:  95 30 60 10  srl  %g1, 0x10, %o2
a0110a24:  90 10 00 10  mov  %l0, %o0
a0110a28:  92 10 20 00  clr  %o1
a0110a2c:  7f ff ec 32  call  0xa010baf4
a0110a30:  d6 14 60 0e  lduh  [ %l1 + 0xe ], %o3
a0110a34:  95 2d a0 10  sll  %l6, 0x10, %o2
a0110a38:  90 10 00 10  mov  %l0, %o0
a0110a3c:  92 10 20 01  mov  1, %o1
a0110a40:  95 32 a0 10  srl  %o2, 0x10, %o2
a0110a44:  98 10 00 18  mov  %i0, %o4
a0110a48:  7f ff ec 2b  call  0xa010baf4
a0110a4c:  d6 14 60 0e  lduh  [ %l1 + 0xe ], %o3
a0110a50:  9e 10 00 13  mov  %l3, %o7
a0110a54:  27 2a 00 b5  sethi  %hi(0xa802d400), %l3
a0110a58:  90 14 e3 c4  or  %l3, 0x3c4, %o0	! 0xa802d7c4
a0110a5c:  80 a4 20 01  cmp  %l0, 1
a0110a60:  02 80 00 06  be  0xa0110a78
a0110a64:  d2 14 60 20  lduh  [ %l1 + 0x20 ], %o1
a0110a68:  2d 2a 00 b5  sethi  %hi(0xa802d400), %l6
a0110a6c:  80 a4 20 02  cmp  %l0, 2
a0110a70:  02 80 00 9d  be  0xa0110ce4
a0110a74:  90 15 a3 44  or  %l6, 0x344, %o0
a0110a78:  99 2a 60 10  sll  %o1, 0x10, %o4
a0110a7c:  9b 33 20 10  srl  %o4, 0x10, %o5
a0110a80:  d2 32 20 20  sth  %o1, [ %o0 + 0x20 ]
a0110a84:  bb 2b e0 10  sll  %o7, 0x10, %i5
a0110a88:  ae 16 e2 d8  or  %i3, 0x2d8, %l7
a0110a8c:  b1 2c 20 02  sll  %l0, 2, %i0
a0110a90:  92 17 40 0d  or  %i5, %o5, %o1
a0110a94:  f6 05 c0 18  ld  [ %l7 + %i0 ], %i3
a0110a98:  98 10 00 15  mov  %l5, %o4
a0110a9c:  d2 26 e0 14  st  %o1, [ %i3 + 0x14 ]
a0110aa0:  de 32 20 18  sth  %o7, [ %o0 + 0x18 ]
a0110aa4:  2b 2a 00 b5  sethi  %hi(0xa802d400), %l5
a0110aa8:  92 15 63 c4  or  %l5, 0x3c4, %o1	! 0xa802d7c4
a0110aac:  80 a4 20 01  cmp  %l0, 1
a0110ab0:  02 80 00 06  be  0xa0110ac8
a0110ab4:  d0 14 60 20  lduh  [ %l1 + 0x20 ], %o0
a0110ab8:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a0110abc:  80 a4 20 02  cmp  %l0, 2
a0110ac0:  02 80 00 8c  be  0xa0110cf0
a0110ac4:  92 13 e3 44  or  %o7, 0x344, %o1
a0110ac8:  d4 0a 60 3e  ldub  [ %o1 + 0x3e ], %o2
a0110acc:  80 8a a0 01  btst  1, %o2
a0110ad0:  02 80 00 71  be  0xa0110c94
a0110ad4:  d8 32 60 1a  sth  %o4, [ %o1 + 0x1a ]
a0110ad8:  ab 2b 20 10  sll  %o4, 0x10, %l5
a0110adc:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a0110ae0:  83 35 60 10  srl  %l5, 0x10, %g1
a0110ae4:  ec 0a e3 00  ldub  [ %o3 + 0x300 ], %l6
a0110ae8:  98 20 40 16  sub  %g1, %l6, %o4
a0110aec:  83 2a 20 10  sll  %o0, 0x10, %g1
a0110af0:  95 2b 20 10  sll  %o4, 0x10, %o2
a0110af4:  99 2c 20 02  sll  %l0, 2, %o4
a0110af8:  ad 30 60 10  srl  %g1, 0x10, %l6
a0110afc:  a6 16 a2 cc  or  %i2, 0x2cc, %l3
a0110b00:  9a 12 80 16  or  %o2, %l6, %o5
a0110b04:  de 04 c0 0c  ld  [ %l3 + %o4 ], %o7
a0110b08:  d0 32 60 20  sth  %o0, [ %o1 + 0x20 ]
a0110b0c:  b5 2c a0 10  sll  %l2, 0x10, %i2
a0110b10:  da 23 e0 14  st  %o5, [ %o7 + 0x14 ]
a0110b14:  90 10 00 10  mov  %l0, %o0
a0110b18:  95 36 a0 10  srl  %i2, 0x10, %o2
a0110b1c:  92 10 20 00  clr  %o1
a0110b20:  7f ff ec f1  call  0xa010bee4
a0110b24:  d6 14 60 22  lduh  [ %l1 + 0x22 ], %o3
a0110b28:  a5 2d 20 10  sll  %l4, 0x10, %l2
a0110b2c:  90 10 00 10  mov  %l0, %o0
a0110b30:  95 34 a0 10  srl  %l2, 0x10, %o2
a0110b34:  d6 14 60 22  lduh  [ %l1 + 0x22 ], %o3
a0110b38:  7f ff ec eb  call  0xa010bee4
a0110b3c:  92 10 20 01  mov  1, %o1
a0110b40:  21 2a 00 9e  sethi  %hi(0xa8027800), %l0
a0110b44:  da 0c 22 88  ldub  [ %l0 + 0x288 ], %o5	! 0xa8027a88
a0110b48:  80 a3 60 01  cmp  %o5, 1
a0110b4c:  12 80 00 84  bne  0xa0110d5c
a0110b50:  82 0f 20 ff  and  %i4, 0xff, %g1
a0110b54:  80 a0 60 08  cmp  %g1, 8
a0110b58:  02 80 00 6e  be  0xa0110d10
a0110b5c:  80 a0 60 00  cmp  %g1, 0
a0110b60:  22 80 00 18  be,a   0xa0110bc0
a0110b64:  23 34 00 ec  sethi  %hi(0xd003b000), %l1
a0110b68:  80 a0 60 01  cmp  %g1, 1
a0110b6c:  02 80 00 14  be  0xa0110bbc
a0110b70:  9a 10 20 02  mov  2, %o5
a0110b74:  80 a0 60 02  cmp  %g1, 2
a0110b78:  02 80 00 11  be  0xa0110bbc
a0110b7c:  9a 10 20 04  mov  4, %o5
a0110b80:  80 a0 60 03  cmp  %g1, 3
a0110b84:  02 80 00 0e  be  0xa0110bbc
a0110b88:  9a 10 20 08  mov  8, %o5
a0110b8c:  80 a0 60 04  cmp  %g1, 4
a0110b90:  02 80 00 0b  be  0xa0110bbc
a0110b94:  9a 10 20 10  mov  0x10, %o5
a0110b98:  80 a0 60 05  cmp  %g1, 5
a0110b9c:  02 80 00 08  be  0xa0110bbc
a0110ba0:  9a 10 20 20  mov  0x20, %o5
a0110ba4:  80 a0 60 06  cmp  %g1, 6
a0110ba8:  02 80 00 05  be  0xa0110bbc
a0110bac:  9a 10 20 40  mov  0x40, %o5
a0110bb0:  80 a0 60 07  cmp  %g1, 7
a0110bb4:  12 80 00 04  bne  0xa0110bc4
a0110bb8:  9a 10 21 00  mov  0x100, %o5
a0110bbc:  23 34 00 ec  sethi  %hi(0xd003b000), %l1
a0110bc0:  da 24 40 00  st  %o5, [ %l1 ]
a0110bc4:  67 fd f2 71  call  0x4008d588
a0110bc8:  23 34 00 ec  sethi  %hi(0xd003b000), %l1
a0110bcc:  a0 10 00 08  mov  %o0, %l0
a0110bd0:  f8 04 40 00  ld  [ %l1 ], %i4
a0110bd4:  80 a7 20 00  cmp  %i4, 0
a0110bd8:  02 80 00 61  be  0xa0110d5c
a0110bdc:  01 00 00 00  nop
a0110be0:  67 fd f2 6a  call  0x4008d588
a0110be4:  01 00 00 00  nop
a0110be8:  92 22 00 10  sub  %o0, %l0, %o1
a0110bec:  91 2a 60 10  sll  %o1, 0x10, %o0
a0110bf0:  a9 32 20 10  srl  %o0, 0x10, %l4
a0110bf4:  80 a5 20 63  cmp  %l4, 0x63
a0110bf8:  08 bf ff f6  bleu  0xa0110bd0
a0110bfc:  01 00 00 00  nop
a0110c00:  30 80 00 57  b,a   0xa0110d5c
a0110c04:  96 00 40 0c  add  %g1, %o4, %o3
a0110c08:  a6 10 00 01  mov  %g1, %l3
a0110c0c:  80 a2 c0 0d  cmp  %o3, %o5
a0110c10:  14 bf ff 0b  bg  0xa011083c
a0110c14:  aa 10 20 00  clr  %l5
a0110c18:  80 a4 20 01  cmp  %l0, 1
a0110c1c:  22 80 00 15  be,a   0xa0110c70
a0110c20:  03 34 00 e0  sethi  %hi(0xd0038000), %g1
a0110c24:  04 80 00 49  ble  0xa0110d48
a0110c28:  80 a4 20 02  cmp  %l0, 2
a0110c2c:  32 bf ff 05  bne,a   0xa0110840
a0110c30:  a9 2f 60 10  sll  %i5, 0x10, %l4
a0110c34:  03 34 00 e0  sethi  %hi(0xd0038000), %g1
a0110c38:  82 10 60 04  or  %g1, 4, %g1	! 0xd0038004
a0110c3c:  da 00 40 00  ld  [ %g1 ], %o5
a0110c40:  92 13 64 00  or  %o5, 0x400, %o1
a0110c44:  d2 20 40 00  st  %o1, [ %g1 ]
a0110c48:  d0 00 40 00  ld  [ %g1 ], %o0
a0110c4c:  98 0a 3f f7  and  %o0, -9, %o4
a0110c50:  d8 20 40 00  st  %o4, [ %g1 ]
a0110c54:  10 bf fe fb  b  0xa0110840
a0110c58:  a9 2f 60 10  sll  %i5, 0x10, %l4
a0110c5c:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a0110c60:  a2 12 63 84  or  %o1, 0x384, %l1	! 0xa802d784
a0110c64:  10 bf fe e1  b  0xa01107e8
a0110c68:  b8 10 20 02  mov  2, %i4
a0110c6c:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a0110c70:  82 10 60 04  or  %g1, 4, %g1	! 0xd0030004
a0110c74:  f6 00 40 00  ld  [ %g1 ], %i3
a0110c78:  b4 16 e2 00  or  %i3, 0x200, %i2
a0110c7c:  f4 20 40 00  st  %i2, [ %g1 ]
a0110c80:  ec 00 40 00  ld  [ %g1 ], %l6
a0110c84:  98 0d bf fb  and  %l6, -5, %o4
a0110c88:  d8 20 40 00  st  %o4, [ %g1 ]
a0110c8c:  10 bf fe ed  b  0xa0110840
a0110c90:  a9 2f 60 10  sll  %i5, 0x10, %l4
a0110c94:  bb 2b 20 10  sll  %o4, 0x10, %i5
a0110c98:  2f 2a 00 b5  sethi  %hi(0xa802d400), %l7
a0110c9c:  b1 37 60 10  srl  %i5, 0x10, %i0
a0110ca0:  f6 0d e3 00  ldub  [ %l7 + 0x300 ], %i3
a0110ca4:  10 bf ff 92  b  0xa0110aec
a0110ca8:  98 06 00 1b  add  %i0, %i3, %o4
a0110cac:  9b 2c 20 02  sll  %l0, 2, %o5
a0110cb0:  d8 02 40 0d  ld  [ %o1 + %o5 ], %o4
a0110cb4:  d6 23 20 10  st  %o3, [ %o4 + 0x10 ]
a0110cb8:  80 a4 20 02  cmp  %l0, 2
a0110cbc:  18 bf ff 28  bgu  0xa011095c
a0110cc0:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a0110cc4:  98 16 a2 cc  or  %i2, 0x2cc, %o4	! 0x19aecc
a0110cc8:  b1 2c 20 02  sll  %l0, 2, %i0
a0110ccc:  d2 03 00 18  ld  [ %o4 + %i0 ], %o1
a0110cd0:  d6 22 60 10  st  %o3, [ %o1 + 0x10 ]
a0110cd4:  10 bf ff 2c  b  0xa0110984
a0110cd8:  97 2b e0 10  sll  %o7, 0x10, %o3
a0110cdc:  10 bf ff 4f  b  0xa0110a18
a0110ce0:  a6 23 00 13  sub  %o4, %l3, %l3
a0110ce4:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a0110ce8:  10 bf ff 64  b  0xa0110a78
a0110cec:  90 12 e3 84  or  %o3, 0x384, %o0	! 0xa802d784
a0110cf0:  27 2a 00 b5  sethi  %hi(0xa802d400), %l3
a0110cf4:  10 bf ff 75  b  0xa0110ac8
a0110cf8:  92 14 e3 84  or  %l3, 0x384, %o1	! 0xa802d784
a0110cfc:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a0110d00:  10 bf fe f5  b  0xa01108d4
a0110d04:  90 10 63 84  or  %g1, 0x384, %o0	! 0xa802d784
a0110d08:  10 bf ff 44  b  0xa0110a18
a0110d0c:  aa 22 00 15  sub  %o0, %l5, %l5
a0110d10:  10 bf ff ab  b  0xa0110bbc
a0110d14:  9a 10 21 ff  mov  0x1ff, %o5
a0110d18:  80 a4 20 00  cmp  %l0, 0
a0110d1c:  12 bf fe c8  bne  0xa011083c
a0110d20:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a0110d24:  82 10 60 04  or  %g1, 4, %g1	! 0xd0030004
a0110d28:  e8 00 40 00  ld  [ %g1 ], %l4
a0110d2c:  a4 15 21 00  or  %l4, 0x100, %l2
a0110d30:  e4 20 40 00  st  %l2, [ %g1 ]
a0110d34:  d8 00 40 00  ld  [ %g1 ], %o4
a0110d38:  98 0b 3f fd  and  %o4, -3, %o4
a0110d3c:  d8 20 40 00  st  %o4, [ %g1 ]
a0110d40:  10 bf fe c0  b  0xa0110840
a0110d44:  a9 2f 60 10  sll  %i5, 0x10, %l4
a0110d48:  80 a4 20 00  cmp  %l0, 0
a0110d4c:  02 bf ff f6  be  0xa0110d24
a0110d50:  03 34 00 e0  sethi  %hi(0xd0038000), %g1
a0110d54:  10 bf fe bb  b  0xa0110840
a0110d58:  a9 2f 60 10  sll  %i5, 0x10, %l4
a0110d5c:  81 c7 e0 08  ret
a0110d60:  81 e8 00 00  restore
