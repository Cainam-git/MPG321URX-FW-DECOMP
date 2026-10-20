# leon2m FUN_a01118cc 0xa01118cc-0xa01129e4 (44 bytes)
a01118cc:  82 0a 20 ff  and  %o0, 0xff, %g1
a01118d0:  80 a0 60 14  cmp  %g1, 0x14
a01118d4:  18 80 04 42  bgu  0xa01129dc
a01118d8:  11 00 02 c5  sethi  %hi(0xb1400), %o0
a01118dc:  83 28 60 02  sll  %g1, 2, %g1
a01118e0:  9a 12 23 e0  or  %o0, 0x3e0, %o5
a01118e4:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a01118e8:  81 c3 00 00  jmp  %o4
a01118ec:  01 00 00 00  nop
a01118f0:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a01118f4:  96 13 20 40  or  %o4, 0x40, %o3	! 0xcf03c840
a01118f8:  11 00 00 3f  sethi  %hi(0xfc00), %o0
a01118fc:  98 12 23 ff  or  %o0, 0x3ff, %o4	! 0xffff
a0111900:  9a 10 3f ff  mov  -1, %o5
a0111904:  94 10 20 01  mov  1, %o2
a0111908:  c2 02 c0 00  ld  [ %o3 ], %g1
a011190c:  80 a0 60 02  cmp  %g1, 2
a0111910:  32 80 00 02  bne,a   0xa0111918
a0111914:  d4 22 c0 00  st  %o2, [ %o3 ]
a0111918:  d0 02 c0 00  ld  [ %o3 ], %o0
a011191c:  80 a2 20 01  cmp  %o0, 1
a0111920:  02 80 00 07  be  0xa011193c
a0111924:  9a 03 7f ff  add  %o5, -1, %o5
a0111928:  91 2b 60 10  sll  %o5, 0x10, %o0
a011192c:  83 32 20 10  srl  %o0, 0x10, %g1
a0111930:  80 a0 40 0c  cmp  %g1, %o4
a0111934:  12 bf ff f5  bne  0xa0111908
a0111938:  01 00 00 00  nop
a011193c:  19 33 c0 4d  sethi  %hi(0xcf013400), %o4
a0111940:  90 10 20 01  mov  1, %o0
a0111944:  d0 22 c0 00  st  %o0, [ %o3 ]
a0111948:  9a 13 20 28  or  %o4, 0x28, %o5
a011194c:  c2 03 40 00  ld  [ %o5 ], %g1
a0111950:  94 08 7f 7f  and  %g1, -129, %o2
a0111954:  d4 23 40 00  st  %o2, [ %o5 ]
a0111958:  c0 22 c0 00  clr  [ %o3 ]
a011195c:  9a 13 20 30  or  %o4, 0x30, %o5
a0111960:  d0 03 40 00  ld  [ %o5 ], %o0
a0111964:  82 0a 3f 7f  and  %o0, -129, %g1
a0111968:  c2 23 40 00  st  %g1, [ %o5 ]
a011196c:  98 13 20 38  or  %o4, 0x38, %o4
a0111970:  d6 03 00 00  ld  [ %o4 ], %o3
a0111974:  94 0a ff 7f  and  %o3, -129, %o2
a0111978:  92 0a 60 ff  and  %o1, 0xff, %o1
a011197c:  d4 23 00 00  st  %o2, [ %o4 ]
a0111980:  80 a2 60 01  cmp  %o1, 1
a0111984:  02 80 03 65  be  0xa0112718
a0111988:  80 a2 60 02  cmp  %o1, 2
a011198c:  02 80 03 9f  be  0xa0112808
a0111990:  80 a2 60 04  cmp  %o1, 4
a0111994:  12 80 04 12  bne  0xa01129dc
a0111998:  01 00 00 00  nop
a011199c:  d0 03 00 00  ld  [ %o4 ], %o0
a01119a0:  82 12 20 80  or  %o0, 0x80, %g1
a01119a4:  c2 23 00 00  st  %g1, [ %o4 ]
a01119a8:  30 80 04 0d  b,a   0xa01129dc
a01119ac:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a01119b0:  96 13 60 2c  or  %o5, 0x2c, %o3	! 0xcf01342c
a01119b4:  d4 02 c0 00  ld  [ %o3 ], %o2
a01119b8:  98 0a bf fe  and  %o2, -2, %o4
a01119bc:  d8 22 c0 00  st  %o4, [ %o3 ]
a01119c0:  98 13 60 34  or  %o5, 0x34, %o4
a01119c4:  d0 03 00 00  ld  [ %o4 ], %o0
a01119c8:  82 0a 3f fe  and  %o0, -2, %g1
a01119cc:  c2 23 00 00  st  %g1, [ %o4 ]
a01119d0:  9a 13 60 3c  or  %o5, 0x3c, %o5
a01119d4:  d4 03 40 00  ld  [ %o5 ], %o2
a01119d8:  90 0a bf fe  and  %o2, -2, %o0
a01119dc:  92 0a 60 ff  and  %o1, 0xff, %o1
a01119e0:  d0 23 40 00  st  %o0, [ %o5 ]
a01119e4:  80 a2 60 01  cmp  %o1, 1
a01119e8:  02 80 03 48  be  0xa0112708
a01119ec:  80 a2 60 02  cmp  %o1, 2
a01119f0:  02 80 03 82  be  0xa01127f8
a01119f4:  80 a2 60 04  cmp  %o1, 4
a01119f8:  12 80 03 f9  bne  0xa01129dc
a01119fc:  01 00 00 00  nop
a0111a00:  c2 03 40 00  ld  [ %o5 ], %g1
a0111a04:  82 10 60 01  or  %g1, 1, %g1
a0111a08:  c2 23 40 00  st  %g1, [ %o5 ]
a0111a0c:  30 80 03 f4  b,a   0xa01129dc
a0111a10:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a0111a14:  96 13 60 2c  or  %o5, 0x2c, %o3	! 0xcf01342c
a0111a18:  d4 02 c0 00  ld  [ %o3 ], %o2
a0111a1c:  98 0a bf f7  and  %o2, -9, %o4
a0111a20:  d8 22 c0 00  st  %o4, [ %o3 ]
a0111a24:  98 13 60 34  or  %o5, 0x34, %o4
a0111a28:  d0 03 00 00  ld  [ %o4 ], %o0
a0111a2c:  82 0a 3f f7  and  %o0, -9, %g1
a0111a30:  c2 23 00 00  st  %g1, [ %o4 ]
a0111a34:  9a 13 60 3c  or  %o5, 0x3c, %o5
a0111a38:  d4 03 40 00  ld  [ %o5 ], %o2
a0111a3c:  90 0a bf f7  and  %o2, -9, %o0
a0111a40:  92 0a 60 ff  and  %o1, 0xff, %o1
a0111a44:  d0 23 40 00  st  %o0, [ %o5 ]
a0111a48:  80 a2 60 01  cmp  %o1, 1
a0111a4c:  02 80 02 ee  be  0xa0112604
a0111a50:  80 a2 60 02  cmp  %o1, 2
a0111a54:  02 80 01 2e  be  0xa0111f0c
a0111a58:  80 a2 60 04  cmp  %o1, 4
a0111a5c:  12 80 03 e0  bne  0xa01129dc
a0111a60:  01 00 00 00  nop
a0111a64:  c2 03 40 00  ld  [ %o5 ], %g1
a0111a68:  82 10 60 08  or  %g1, 8, %g1
a0111a6c:  c2 23 40 00  st  %g1, [ %o5 ]
a0111a70:  30 80 03 db  b,a   0xa01129dc
a0111a74:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a0111a78:  96 13 60 2c  or  %o5, 0x2c, %o3	! 0xcf01342c
a0111a7c:  d4 02 c0 00  ld  [ %o3 ], %o2
a0111a80:  98 0a bf fd  and  %o2, -3, %o4
a0111a84:  d8 22 c0 00  st  %o4, [ %o3 ]
a0111a88:  98 13 60 34  or  %o5, 0x34, %o4
a0111a8c:  d0 03 00 00  ld  [ %o4 ], %o0
a0111a90:  82 0a 3f fd  and  %o0, -3, %g1
a0111a94:  c2 23 00 00  st  %g1, [ %o4 ]
a0111a98:  9a 13 60 3c  or  %o5, 0x3c, %o5
a0111a9c:  d4 03 40 00  ld  [ %o5 ], %o2
a0111aa0:  90 0a bf fd  and  %o2, -3, %o0
a0111aa4:  92 0a 60 ff  and  %o1, 0xff, %o1
a0111aa8:  d0 23 40 00  st  %o0, [ %o5 ]
a0111aac:  80 a2 60 01  cmp  %o1, 1
a0111ab0:  02 80 02 6f  be  0xa011246c
a0111ab4:  80 a2 60 02  cmp  %o1, 2
a0111ab8:  02 80 01 fa  be  0xa01122a0
a0111abc:  80 a2 60 04  cmp  %o1, 4
a0111ac0:  12 80 03 c7  bne  0xa01129dc
a0111ac4:  01 00 00 00  nop
a0111ac8:  c2 03 40 00  ld  [ %o5 ], %g1
a0111acc:  82 10 60 02  or  %g1, 2, %g1
a0111ad0:  c2 23 40 00  st  %g1, [ %o5 ]
a0111ad4:  30 80 03 c2  b,a   0xa01129dc
a0111ad8:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a0111adc:  96 13 20 40  or  %o4, 0x40, %o3	! 0xcf03c840
a0111ae0:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a0111ae4:  98 10 63 ff  or  %g1, 0x3ff, %o4	! 0xffff
a0111ae8:  9a 10 3f ff  mov  -1, %o5
a0111aec:  94 10 20 01  mov  1, %o2
a0111af0:  d0 02 c0 00  ld  [ %o3 ], %o0
a0111af4:  80 a2 20 02  cmp  %o0, 2
a0111af8:  32 80 00 02  bne,a   0xa0111b00
a0111afc:  d4 22 c0 00  st  %o2, [ %o3 ]
a0111b00:  c2 02 c0 00  ld  [ %o3 ], %g1
a0111b04:  80 a0 60 01  cmp  %g1, 1
a0111b08:  02 80 00 07  be  0xa0111b24
a0111b0c:  9a 03 7f ff  add  %o5, -1, %o5
a0111b10:  83 2b 60 10  sll  %o5, 0x10, %g1
a0111b14:  91 30 60 10  srl  %g1, 0x10, %o0
a0111b18:  80 a2 00 0c  cmp  %o0, %o4
a0111b1c:  12 bf ff f5  bne  0xa0111af0
a0111b20:  01 00 00 00  nop
a0111b24:  19 33 c0 4d  sethi  %hi(0xcf013400), %o4
a0111b28:  82 10 20 01  mov  1, %g1
a0111b2c:  c2 22 c0 00  st  %g1, [ %o3 ]
a0111b30:  9a 13 20 28  or  %o4, 0x28, %o5
a0111b34:  d0 03 40 00  ld  [ %o5 ], %o0
a0111b38:  94 0a 3f bf  and  %o0, -65, %o2
a0111b3c:  d4 23 40 00  st  %o2, [ %o5 ]
a0111b40:  c0 22 c0 00  clr  [ %o3 ]
a0111b44:  9a 13 20 30  or  %o4, 0x30, %o5
a0111b48:  c2 03 40 00  ld  [ %o5 ], %g1
a0111b4c:  90 08 7f bf  and  %g1, -65, %o0
a0111b50:  d0 23 40 00  st  %o0, [ %o5 ]
a0111b54:  98 13 20 38  or  %o4, 0x38, %o4
a0111b58:  d6 03 00 00  ld  [ %o4 ], %o3
a0111b5c:  94 0a ff bf  and  %o3, -65, %o2
a0111b60:  92 0a 60 ff  and  %o1, 0xff, %o1
a0111b64:  d4 23 00 00  st  %o2, [ %o4 ]
a0111b68:  80 a2 60 01  cmp  %o1, 1
a0111b6c:  02 80 02 c6  be  0xa0112684
a0111b70:  80 a2 60 02  cmp  %o1, 2
a0111b74:  02 80 00 bd  be  0xa0111e68
a0111b78:  80 a2 60 04  cmp  %o1, 4
a0111b7c:  12 80 03 98  bne  0xa01129dc
a0111b80:  01 00 00 00  nop
a0111b84:  c2 03 00 00  ld  [ %o4 ], %g1
a0111b88:  82 10 60 40  or  %g1, 0x40, %g1
a0111b8c:  c2 23 00 00  st  %g1, [ %o4 ]
a0111b90:  30 80 03 93  b,a   0xa01129dc
a0111b94:  15 33 c0 4d  sethi  %hi(0xcf013400), %o2
a0111b98:  96 12 a0 2c  or  %o2, 0x2c, %o3	! 0xcf01342c
a0111b9c:  c2 02 c0 00  ld  [ %o3 ], %g1
a0111ba0:  98 08 7f fb  and  %g1, -5, %o4
a0111ba4:  d8 22 c0 00  st  %o4, [ %o3 ]
a0111ba8:  98 12 a0 34  or  %o2, 0x34, %o4
a0111bac:  d0 03 00 00  ld  [ %o4 ], %o0
a0111bb0:  9a 0a 3f fb  and  %o0, -5, %o5
a0111bb4:  82 0a 60 ff  and  %o1, 0xff, %g1
a0111bb8:  da 23 00 00  st  %o5, [ %o4 ]
a0111bbc:  80 a0 60 01  cmp  %g1, 1
a0111bc0:  02 80 02 06  be  0xa01123d8
a0111bc4:  80 a0 60 02  cmp  %g1, 2
a0111bc8:  12 80 03 85  bne  0xa01129dc
a0111bcc:  01 00 00 00  nop
a0111bd0:  d6 03 00 00  ld  [ %o4 ], %o3
a0111bd4:  82 12 e0 04  or  %o3, 4, %g1
a0111bd8:  c2 23 00 00  st  %g1, [ %o4 ]
a0111bdc:  30 80 03 80  b,a   0xa01129dc
a0111be0:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a0111be4:  96 13 20 40  or  %o4, 0x40, %o3	! 0xcf03c840
a0111be8:  11 00 00 3f  sethi  %hi(0xfc00), %o0
a0111bec:  98 12 23 ff  or  %o0, 0x3ff, %o4	! 0xffff
a0111bf0:  9a 10 3f ff  mov  -1, %o5
a0111bf4:  94 10 20 01  mov  1, %o2
a0111bf8:  c2 02 c0 00  ld  [ %o3 ], %g1
a0111bfc:  80 a0 60 02  cmp  %g1, 2
a0111c00:  32 80 00 02  bne,a   0xa0111c08
a0111c04:  d4 22 c0 00  st  %o2, [ %o3 ]
a0111c08:  d0 02 c0 00  ld  [ %o3 ], %o0
a0111c0c:  80 a2 20 01  cmp  %o0, 1
a0111c10:  02 80 00 07  be  0xa0111c2c
a0111c14:  9a 03 7f ff  add  %o5, -1, %o5
a0111c18:  91 2b 60 10  sll  %o5, 0x10, %o0
a0111c1c:  83 32 20 10  srl  %o0, 0x10, %g1
a0111c20:  80 a0 40 0c  cmp  %g1, %o4
a0111c24:  12 bf ff f5  bne  0xa0111bf8
a0111c28:  01 00 00 00  nop
a0111c2c:  19 33 c0 4d  sethi  %hi(0xcf013400), %o4
a0111c30:  90 10 20 01  mov  1, %o0
a0111c34:  d0 22 c0 00  st  %o0, [ %o3 ]
a0111c38:  9a 13 20 28  or  %o4, 0x28, %o5
a0111c3c:  c2 03 40 00  ld  [ %o5 ], %g1
a0111c40:  94 08 7f df  and  %g1, -33, %o2
a0111c44:  d4 23 40 00  st  %o2, [ %o5 ]
a0111c48:  c0 22 c0 00  clr  [ %o3 ]
a0111c4c:  9a 13 20 30  or  %o4, 0x30, %o5
a0111c50:  d0 03 40 00  ld  [ %o5 ], %o0
a0111c54:  82 0a 3f df  and  %o0, -33, %g1
a0111c58:  c2 23 40 00  st  %g1, [ %o5 ]
a0111c5c:  98 13 20 38  or  %o4, 0x38, %o4
a0111c60:  d6 03 00 00  ld  [ %o4 ], %o3
a0111c64:  94 0a ff df  and  %o3, -33, %o2
a0111c68:  92 0a 60 ff  and  %o1, 0xff, %o1
a0111c6c:  d4 23 00 00  st  %o2, [ %o4 ]
a0111c70:  80 a2 60 01  cmp  %o1, 1
a0111c74:  02 80 02 48  be  0xa0112594
a0111c78:  80 a2 60 02  cmp  %o1, 2
a0111c7c:  02 80 01 5a  be  0xa01121e4
a0111c80:  80 a2 60 04  cmp  %o1, 4
a0111c84:  12 80 03 56  bne  0xa01129dc
a0111c88:  01 00 00 00  nop
a0111c8c:  d0 03 00 00  ld  [ %o4 ], %o0
a0111c90:  82 12 20 20  or  %o0, 0x20, %g1
a0111c94:  c2 23 00 00  st  %g1, [ %o4 ]
a0111c98:  30 80 03 51  b,a   0xa01129dc
a0111c9c:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a0111ca0:  96 13 20 40  or  %o4, 0x40, %o3	! 0xcf03c840
a0111ca4:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a0111ca8:  98 10 63 ff  or  %g1, 0x3ff, %o4	! 0xffff
a0111cac:  9a 10 3f ff  mov  -1, %o5
a0111cb0:  94 10 20 01  mov  1, %o2
a0111cb4:  d0 02 c0 00  ld  [ %o3 ], %o0
a0111cb8:  80 a2 20 02  cmp  %o0, 2
a0111cbc:  32 80 00 02  bne,a   0xa0111cc4
a0111cc0:  d4 22 c0 00  st  %o2, [ %o3 ]
a0111cc4:  c2 02 c0 00  ld  [ %o3 ], %g1
a0111cc8:  80 a0 60 01  cmp  %g1, 1
a0111ccc:  02 80 00 07  be  0xa0111ce8
a0111cd0:  9a 03 7f ff  add  %o5, -1, %o5
a0111cd4:  83 2b 60 10  sll  %o5, 0x10, %g1
a0111cd8:  91 30 60 10  srl  %g1, 0x10, %o0
a0111cdc:  80 a2 00 0c  cmp  %o0, %o4
a0111ce0:  12 bf ff f5  bne  0xa0111cb4
a0111ce4:  01 00 00 00  nop
a0111ce8:  19 33 c0 4d  sethi  %hi(0xcf013400), %o4
a0111cec:  9a 10 20 01  mov  1, %o5
a0111cf0:  da 22 c0 00  st  %o5, [ %o3 ]
a0111cf4:  90 13 20 28  or  %o4, 0x28, %o0
a0111cf8:  d4 02 00 00  ld  [ %o0 ], %o2
a0111cfc:  82 0a bf ef  and  %o2, -17, %g1
a0111d00:  c2 22 00 00  st  %g1, [ %o0 ]
a0111d04:  c0 22 c0 00  clr  [ %o3 ]
a0111d08:  98 13 20 30  or  %o4, 0x30, %o4
a0111d0c:  da 03 00 00  ld  [ %o4 ], %o5
a0111d10:  94 0b 7f ef  and  %o5, -17, %o2
a0111d14:  92 0a 60 ff  and  %o1, 0xff, %o1
a0111d18:  d4 23 00 00  st  %o2, [ %o4 ]
a0111d1c:  80 a2 60 01  cmp  %o1, 1
a0111d20:  02 80 01 f7  be  0xa01124fc
a0111d24:  80 a2 60 02  cmp  %o1, 2
a0111d28:  12 80 03 2d  bne  0xa01129dc
a0111d2c:  01 00 00 00  nop
a0111d30:  c2 03 00 00  ld  [ %o4 ], %g1
a0111d34:  82 10 60 10  or  %g1, 0x10, %g1
a0111d38:  c2 23 00 00  st  %g1, [ %o4 ]
a0111d3c:  30 80 03 28  b,a   0xa01129dc
a0111d40:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a0111d44:  9a 13 60 5c  or  %o5, 0x5c, %o5	! 0xcf01345c
a0111d48:  d0 03 40 00  ld  [ %o5 ], %o0
a0111d4c:  96 0a 3f f8  and  %o0, -8, %o3
a0111d50:  92 0a 60 ff  and  %o1, 0xff, %o1
a0111d54:  d6 23 40 00  st  %o3, [ %o5 ]
a0111d58:  80 a2 60 01  cmp  %o1, 1
a0111d5c:  02 bf ff 29  be  0xa0111a00
a0111d60:  80 a2 60 02  cmp  %o1, 2
a0111d64:  02 bf ff 59  be  0xa0111ac8
a0111d68:  80 a2 60 04  cmp  %o1, 4
a0111d6c:  12 80 03 1c  bne  0xa01129dc
a0111d70:  01 00 00 00  nop
a0111d74:  c2 03 40 00  ld  [ %o5 ], %g1
a0111d78:  82 10 60 04  or  %g1, 4, %g1
a0111d7c:  c2 23 40 00  st  %g1, [ %o5 ]
a0111d80:  30 80 03 17  b,a   0xa01129dc
a0111d84:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a0111d88:  96 13 20 40  or  %o4, 0x40, %o3	! 0xcf03c840
a0111d8c:  11 00 00 3f  sethi  %hi(0xfc00), %o0
a0111d90:  98 12 23 ff  or  %o0, 0x3ff, %o4	! 0xffff
a0111d94:  9a 10 3f ff  mov  -1, %o5
a0111d98:  94 10 20 01  mov  1, %o2
a0111d9c:  c2 02 c0 00  ld  [ %o3 ], %g1
a0111da0:  80 a0 60 02  cmp  %g1, 2
a0111da4:  32 80 00 02  bne,a   0xa0111dac
a0111da8:  d4 22 c0 00  st  %o2, [ %o3 ]
a0111dac:  d0 02 c0 00  ld  [ %o3 ], %o0
a0111db0:  80 a2 20 01  cmp  %o0, 1
a0111db4:  02 80 00 07  be  0xa0111dd0
a0111db8:  9a 03 7f ff  add  %o5, -1, %o5
a0111dbc:  91 2b 60 10  sll  %o5, 0x10, %o0
a0111dc0:  83 32 20 10  srl  %o0, 0x10, %g1
a0111dc4:  80 a0 40 0c  cmp  %g1, %o4
a0111dc8:  12 bf ff f5  bne  0xa0111d9c
a0111dcc:  01 00 00 00  nop
a0111dd0:  19 33 c0 4d  sethi  %hi(0xcf013400), %o4
a0111dd4:  90 10 20 01  mov  1, %o0
a0111dd8:  d0 22 c0 00  st  %o0, [ %o3 ]
a0111ddc:  9a 13 20 28  or  %o4, 0x28, %o5
a0111de0:  c2 03 40 00  ld  [ %o5 ], %g1
a0111de4:  94 08 7f fb  and  %g1, -5, %o2
a0111de8:  d4 23 40 00  st  %o2, [ %o5 ]
a0111dec:  c0 22 c0 00  clr  [ %o3 ]
a0111df0:  9a 13 20 30  or  %o4, 0x30, %o5
a0111df4:  d0 03 40 00  ld  [ %o5 ], %o0
a0111df8:  82 0a 3f fb  and  %o0, -5, %g1
a0111dfc:  c2 23 40 00  st  %g1, [ %o5 ]
a0111e00:  98 13 20 38  or  %o4, 0x38, %o4
a0111e04:  d6 03 00 00  ld  [ %o4 ], %o3
a0111e08:  94 0a ff fb  and  %o3, -5, %o2
a0111e0c:  92 0a 60 ff  and  %o1, 0xff, %o1
a0111e10:  d4 23 00 00  st  %o2, [ %o4 ]
a0111e14:  80 a2 60 01  cmp  %o1, 1
a0111e18:  02 80 01 9d  be  0xa011248c
a0111e1c:  80 a2 60 02  cmp  %o1, 2
a0111e20:  02 bf ff d5  be  0xa0111d74
a0111e24:  80 a2 60 04  cmp  %o1, 4
a0111e28:  12 80 02 ed  bne  0xa01129dc
a0111e2c:  01 00 00 00  nop
a0111e30:  30 bf ff 68  b,a   0xa0111bd0
a0111e34:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a0111e38:  9a 13 60 4c  or  %o5, 0x4c, %o5	! 0xcf01344c
a0111e3c:  d4 03 40 00  ld  [ %o5 ], %o2
a0111e40:  90 0a bf 8f  and  %o2, -113, %o0
a0111e44:  92 0a 60 ff  and  %o1, 0xff, %o1
a0111e48:  d0 23 40 00  st  %o0, [ %o5 ]
a0111e4c:  80 a2 60 01  cmp  %o1, 1
a0111e50:  02 80 00 9e  be  0xa01120c8
a0111e54:  80 a2 60 02  cmp  %o1, 2
a0111e58:  02 80 00 e3  be  0xa01121e4
a0111e5c:  80 a2 60 04  cmp  %o1, 4
a0111e60:  12 80 02 df  bne  0xa01129dc
a0111e64:  01 00 00 00  nop
a0111e68:  c2 03 40 00  ld  [ %o5 ], %g1
a0111e6c:  82 10 60 40  or  %g1, 0x40, %g1
a0111e70:  c2 23 40 00  st  %g1, [ %o5 ]
a0111e74:  30 80 02 da  b,a   0xa01129dc
a0111e78:  15 33 c0 f2  sethi  %hi(0xcf03c800), %o2
a0111e7c:  96 12 a0 40  or  %o2, 0x40, %o3	! 0xcf03c840
a0111e80:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a0111e84:  98 10 63 ff  or  %g1, 0x3ff, %o4	! 0xffff
a0111e88:  9a 10 3f ff  mov  -1, %o5
a0111e8c:  94 10 20 01  mov  1, %o2
a0111e90:  d0 02 c0 00  ld  [ %o3 ], %o0
a0111e94:  80 a2 20 02  cmp  %o0, 2
a0111e98:  32 80 00 02  bne,a   0xa0111ea0
a0111e9c:  d4 22 c0 00  st  %o2, [ %o3 ]
a0111ea0:  c2 02 c0 00  ld  [ %o3 ], %g1
a0111ea4:  80 a0 60 01  cmp  %g1, 1
a0111ea8:  02 80 00 07  be  0xa0111ec4
a0111eac:  9a 03 7f ff  add  %o5, -1, %o5
a0111eb0:  83 2b 60 10  sll  %o5, 0x10, %g1
a0111eb4:  91 30 60 10  srl  %g1, 0x10, %o0
a0111eb8:  80 a2 00 0c  cmp  %o0, %o4
a0111ebc:  12 bf ff f5  bne  0xa0111e90
a0111ec0:  01 00 00 00  nop
a0111ec4:  19 33 c0 4d  sethi  %hi(0xcf013400), %o4
a0111ec8:  9a 10 20 01  mov  1, %o5
a0111ecc:  da 22 c0 00  st  %o5, [ %o3 ]
a0111ed0:  94 13 20 28  or  %o4, 0x28, %o2
a0111ed4:  c2 02 80 00  ld  [ %o2 ], %g1
a0111ed8:  90 08 7f f7  and  %g1, -9, %o0
a0111edc:  d0 22 80 00  st  %o0, [ %o2 ]
a0111ee0:  c0 22 c0 00  clr  [ %o3 ]
a0111ee4:  98 13 20 30  or  %o4, 0x30, %o4
a0111ee8:  d6 03 00 00  ld  [ %o4 ], %o3
a0111eec:  9a 0a ff f7  and  %o3, -9, %o5
a0111ef0:  92 0a 60 ff  and  %o1, 0xff, %o1
a0111ef4:  da 23 00 00  st  %o5, [ %o4 ]
a0111ef8:  80 a2 60 01  cmp  %o1, 1
a0111efc:  02 80 01 c6  be  0xa0112614
a0111f00:  80 a2 60 02  cmp  %o1, 2
a0111f04:  12 80 02 b6  bne  0xa01129dc
a0111f08:  01 00 00 00  nop
a0111f0c:  d6 03 00 00  ld  [ %o4 ], %o3
a0111f10:  82 12 e0 08  or  %o3, 8, %g1
a0111f14:  c2 23 00 00  st  %g1, [ %o4 ]
a0111f18:  30 80 02 b1  b,a   0xa01129dc
a0111f1c:  15 33 c0 4d  sethi  %hi(0xcf013400), %o2
a0111f20:  98 12 a0 54  or  %o2, 0x54, %o4	! 0xcf013454
a0111f24:  da 03 00 00  ld  [ %o4 ], %o5
a0111f28:  96 0b 7f 8f  and  %o5, -113, %o3
a0111f2c:  d6 23 00 00  st  %o3, [ %o4 ]
a0111f30:  96 12 a0 58  or  %o2, 0x58, %o3
a0111f34:  c2 02 c0 00  ld  [ %o3 ], %g1
a0111f38:  90 08 7f bd  and  %g1, -67, %o0
a0111f3c:  82 0a 60 ff  and  %o1, 0xff, %g1
a0111f40:  d0 22 c0 00  st  %o0, [ %o3 ]
a0111f44:  80 a0 60 01  cmp  %g1, 1
a0111f48:  02 80 01 8e  be  0xa0112580
a0111f4c:  80 a0 60 02  cmp  %g1, 2
a0111f50:  02 80 02 32  be  0xa0112818
a0111f54:  80 a0 60 04  cmp  %g1, 4
a0111f58:  02 80 02 55  be  0xa01128ac
a0111f5c:  80 a0 60 03  cmp  %g1, 3
a0111f60:  02 80 02 42  be  0xa0112868
a0111f64:  80 a0 60 07  cmp  %g1, 7
a0111f68:  02 80 02 7f  be  0xa0112964
a0111f6c:  80 a0 60 03  cmp  %g1, 3
a0111f70:  02 80 02 44  be  0xa0112880
a0111f74:  19 33 c0 47  sethi  %hi(0xcf011c00), %o4
a0111f78:  9a 13 21 8c  or  %o4, 0x18c, %o5	! 0xcf011d8c
a0111f7c:  c2 03 40 00  ld  [ %o5 ], %g1
a0111f80:  82 08 60 3f  and  %g1, 0x3f, %g1
a0111f84:  c2 23 40 00  st  %g1, [ %o5 ]
a0111f88:  30 80 02 95  b,a   0xa01129dc
a0111f8c:  1b 33 c0 f2  sethi  %hi(0xcf03c800), %o5
a0111f90:  96 13 60 40  or  %o5, 0x40, %o3	! 0xcf03c840
a0111f94:  11 00 00 3f  sethi  %hi(0xfc00), %o0
a0111f98:  98 12 23 ff  or  %o0, 0x3ff, %o4	! 0xffff
a0111f9c:  9a 10 3f ff  mov  -1, %o5
a0111fa0:  94 10 20 01  mov  1, %o2
a0111fa4:  c2 02 c0 00  ld  [ %o3 ], %g1
a0111fa8:  80 a0 60 02  cmp  %g1, 2
a0111fac:  32 80 00 02  bne,a   0xa0111fb4
a0111fb0:  d4 22 c0 00  st  %o2, [ %o3 ]
a0111fb4:  d0 02 c0 00  ld  [ %o3 ], %o0
a0111fb8:  80 a2 20 01  cmp  %o0, 1
a0111fbc:  02 80 00 07  be  0xa0111fd8
a0111fc0:  9a 03 7f ff  add  %o5, -1, %o5
a0111fc4:  91 2b 60 10  sll  %o5, 0x10, %o0
a0111fc8:  83 32 20 10  srl  %o0, 0x10, %g1
a0111fcc:  80 a0 40 0c  cmp  %g1, %o4
a0111fd0:  12 bf ff f5  bne  0xa0111fa4
a0111fd4:  01 00 00 00  nop
a0111fd8:  98 10 20 01  mov  1, %o4	! 0x1
a0111fdc:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a0111fe0:  d8 22 c0 00  st  %o4, [ %o3 ]
a0111fe4:  94 13 60 28  or  %o5, 0x28, %o2
a0111fe8:  d0 02 80 00  ld  [ %o2 ], %o0
a0111fec:  82 0a 3f fe  and  %o0, -2, %g1
a0111ff0:  c2 22 80 00  st  %g1, [ %o2 ]
a0111ff4:  98 0a 60 ff  and  %o1, 0xff, %o4
a0111ff8:  c0 22 c0 00  clr  [ %o3 ]
a0111ffc:  80 a3 20 01  cmp  %o4, 1
a0112000:  12 80 02 77  bne  0xa01129dc
a0112004:  17 33 c0 f2  sethi  %hi(0xcf03c800), %o3
a0112008:  98 12 e0 40  or  %o3, 0x40, %o4	! 0xcf03c840
a011200c:  13 00 00 3f  sethi  %hi(0xfc00), %o1
a0112010:  96 12 63 ff  or  %o1, 0x3ff, %o3	! 0xffff
a0112014:  9a 10 3f ff  mov  -1, %o5
a0112018:  94 10 20 01  mov  1, %o2
a011201c:  c2 03 00 00  ld  [ %o4 ], %g1
a0112020:  80 a0 60 02  cmp  %g1, 2
a0112024:  32 80 00 02  bne,a   0xa011202c
a0112028:  d4 23 00 00  st  %o2, [ %o4 ]
a011202c:  d0 03 00 00  ld  [ %o4 ], %o0
a0112030:  80 a2 20 01  cmp  %o0, 1
a0112034:  02 80 00 07  be  0xa0112050
a0112038:  9a 03 7f ff  add  %o5, -1, %o5
a011203c:  83 2b 60 10  sll  %o5, 0x10, %g1
a0112040:  93 30 60 10  srl  %g1, 0x10, %o1
a0112044:  80 a2 40 0b  cmp  %o1, %o3
a0112048:  12 bf ff f5  bne  0xa011201c
a011204c:  01 00 00 00  nop
a0112050:  96 10 20 01  mov  1, %o3	! 0x1
a0112054:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a0112058:  d6 23 00 00  st  %o3, [ %o4 ]
a011205c:  9a 13 60 28  or  %o5, 0x28, %o5
a0112060:  d4 03 40 00  ld  [ %o5 ], %o2
a0112064:  82 12 a0 01  or  %o2, 1, %g1
a0112068:  c2 23 40 00  st  %g1, [ %o5 ]
a011206c:  c0 23 00 00  clr  [ %o4 ]
a0112070:  30 80 02 5b  b,a   0xa01129dc
a0112074:  11 33 c0 4d  sethi  %hi(0xcf013400), %o0
a0112078:  96 12 20 2c  or  %o0, 0x2c, %o3	! 0xcf01342c
a011207c:  d4 02 c0 00  ld  [ %o3 ], %o2
a0112080:  98 0a bf ef  and  %o2, -17, %o4
a0112084:  d8 22 c0 00  st  %o4, [ %o3 ]
a0112088:  98 12 20 34  or  %o0, 0x34, %o4
a011208c:  c2 03 00 00  ld  [ %o4 ], %g1
a0112090:  9a 08 7f ef  and  %g1, -17, %o5
a0112094:  da 23 00 00  st  %o5, [ %o4 ]
a0112098:  9a 12 20 3c  or  %o0, 0x3c, %o5
a011209c:  d4 03 40 00  ld  [ %o5 ], %o2
a01120a0:  82 0a bf ef  and  %o2, -17, %g1
a01120a4:  92 0a 60 ff  and  %o1, 0xff, %o1
a01120a8:  c2 23 40 00  st  %g1, [ %o5 ]
a01120ac:  80 a2 60 01  cmp  %o1, 1
a01120b0:  02 80 00 f3  be  0xa011247c
a01120b4:  80 a2 60 02  cmp  %o1, 2
a01120b8:  02 bf ff 1e  be  0xa0111d30
a01120bc:  80 a2 60 04  cmp  %o1, 4
a01120c0:  12 80 02 47  bne  0xa01129dc
a01120c4:  01 00 00 00  nop
a01120c8:  c2 03 40 00  ld  [ %o5 ], %g1
a01120cc:  82 10 60 10  or  %g1, 0x10, %g1
a01120d0:  c2 23 40 00  st  %g1, [ %o5 ]
a01120d4:  30 80 02 42  b,a   0xa01129dc
a01120d8:  03 33 c0 4d  sethi  %hi(0xcf013400), %g1
a01120dc:  9a 10 60 44  or  %g1, 0x44, %o5	! 0xcf013444
a01120e0:  d8 03 40 00  ld  [ %o5 ], %o4
a01120e4:  94 0b 3f 8f  and  %o4, -113, %o2
a01120e8:  92 0a 60 ff  and  %o1, 0xff, %o1
a01120ec:  d4 23 40 00  st  %o2, [ %o5 ]
a01120f0:  80 a2 60 01  cmp  %o1, 1
a01120f4:  02 bf ff f5  be  0xa01120c8
a01120f8:  80 a2 60 02  cmp  %o1, 2
a01120fc:  02 80 00 3a  be  0xa01121e4
a0112100:  80 a2 60 04  cmp  %o1, 4
a0112104:  12 80 02 36  bne  0xa01129dc
a0112108:  01 00 00 00  nop
a011210c:  30 bf ff 57  b,a   0xa0111e68
a0112110:  15 33 c0 4d  sethi  %hi(0xcf013400), %o2
a0112114:  98 12 a0 48  or  %o2, 0x48, %o4	! 0xcf013448
a0112118:  c2 03 00 00  ld  [ %o4 ], %g1
a011211c:  96 08 7f dc  and  %g1, -36, %o3
a0112120:  d6 23 00 00  st  %o3, [ %o4 ]
a0112124:  96 12 a0 4c  or  %o2, 0x4c, %o3
a0112128:  da 02 c0 00  ld  [ %o3 ], %o5
a011212c:  90 0b 7f fb  and  %o5, -5, %o0
a0112130:  82 0a 60 ff  and  %o1, 0xff, %g1
a0112134:  d0 22 c0 00  st  %o0, [ %o3 ]
a0112138:  80 a0 60 01  cmp  %g1, 1
a011213c:  02 80 01 0c  be  0xa011256c
a0112140:  80 a0 60 02  cmp  %g1, 2
a0112144:  02 80 01 c4  be  0xa0112854
a0112148:  80 a0 60 03  cmp  %g1, 3
a011214c:  02 80 01 94  be  0xa011279c
a0112150:  80 a0 60 07  cmp  %g1, 7
a0112154:  02 80 01 e5  be  0xa01128e8
a0112158:  80 a0 60 03  cmp  %g1, 3
a011215c:  02 80 01 94  be  0xa01127ac
a0112160:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a0112164:  13 33 c0 47  sethi  %hi(0xcf011c00), %o1
a0112168:  9a 12 61 8c  or  %o1, 0x18c, %o5	! 0xcf011d8c
a011216c:  d8 03 40 00  ld  [ %o5 ], %o4
a0112170:  82 0b 20 f3  and  %o4, 0xf3, %g1
a0112174:  c2 23 40 00  st  %g1, [ %o5 ]
a0112178:  30 80 02 19  b,a   0xa01129dc
a011217c:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a0112180:  9a 13 60 60  or  %o5, 0x60, %o5	! 0xcf013460
a0112184:  d6 03 40 00  ld  [ %o5 ], %o3
a0112188:  94 0a ff da  and  %o3, -38, %o2
a011218c:  92 0a 60 ff  and  %o1, 0xff, %o1
a0112190:  d4 23 40 00  st  %o2, [ %o5 ]
a0112194:  80 a2 60 01  cmp  %o1, 1
a0112198:  02 80 01 57  be  0xa01126f4
a011219c:  80 a2 60 04  cmp  %o1, 4
a01121a0:  02 80 01 a3  be  0xa011282c
a01121a4:  80 a2 60 03  cmp  %o1, 3
a01121a8:  02 80 01 c6  be  0xa01128c0
a01121ac:  80 a2 60 06  cmp  %o1, 6
a01121b0:  02 80 01 c9  be  0xa01128d4
a01121b4:  01 00 00 00  nop
a01121b8:  90 1a 60 03  xor  %o1, 3, %o0
a01121bc:  80 a0 00 08  cmp  %g0, %o0
a01121c0:  96 60 3f ff  subx  %g0, -1, %o3
a01121c4:  9a 1a 60 06  xor  %o1, 6, %o5
a01121c8:  80 a0 00 0d  cmp  %g0, %o5
a01121cc:  92 60 3f ff  subx  %g0, -1, %o1
a01121d0:  80 92 c0 09  orcc  %o3, %o1, %g0
a01121d4:  02 80 00 77  be  0xa01123b0
a01121d8:  13 33 c0 7a  sethi  %hi(0xcf01e800), %o1
a01121dc:  03 33 c0 7a  sethi  %hi(0xcf01e800), %g1
a01121e0:  9a 10 62 40  or  %g1, 0x240, %o5	! 0xcf01ea40
a01121e4:  d8 03 40 00  ld  [ %o5 ], %o4
a01121e8:  82 13 20 20  or  %o4, 0x20, %g1
a01121ec:  c2 23 40 00  st  %g1, [ %o5 ]
a01121f0:  30 80 01 fb  b,a   0xa01129dc
a01121f4:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a01121f8:  96 13 20 40  or  %o4, 0x40, %o3	! 0xcf03c840
a01121fc:  11 00 00 3f  sethi  %hi(0xfc00), %o0
a0112200:  98 12 23 ff  or  %o0, 0x3ff, %o4	! 0xffff
a0112204:  9a 10 3f ff  mov  -1, %o5
a0112208:  94 10 20 01  mov  1, %o2
a011220c:  c2 02 c0 00  ld  [ %o3 ], %g1
a0112210:  80 a0 60 02  cmp  %g1, 2
a0112214:  32 80 00 02  bne,a   0xa011221c
a0112218:  d4 22 c0 00  st  %o2, [ %o3 ]
a011221c:  d0 02 c0 00  ld  [ %o3 ], %o0
a0112220:  80 a2 20 01  cmp  %o0, 1
a0112224:  02 80 00 07  be  0xa0112240
a0112228:  9a 03 7f ff  add  %o5, -1, %o5
a011222c:  91 2b 60 10  sll  %o5, 0x10, %o0
a0112230:  83 32 20 10  srl  %o0, 0x10, %g1
a0112234:  80 a0 40 0c  cmp  %g1, %o4
a0112238:  12 bf ff f5  bne  0xa011220c
a011223c:  01 00 00 00  nop
a0112240:  19 33 c0 4d  sethi  %hi(0xcf013400), %o4
a0112244:  90 10 20 01  mov  1, %o0
a0112248:  d0 22 c0 00  st  %o0, [ %o3 ]
a011224c:  9a 13 20 28  or  %o4, 0x28, %o5
a0112250:  c2 03 40 00  ld  [ %o5 ], %g1
a0112254:  94 08 7f fd  and  %g1, -3, %o2
a0112258:  d4 23 40 00  st  %o2, [ %o5 ]
a011225c:  c0 22 c0 00  clr  [ %o3 ]
a0112260:  9a 13 20 30  or  %o4, 0x30, %o5
a0112264:  d0 03 40 00  ld  [ %o5 ], %o0
a0112268:  82 0a 3f fd  and  %o0, -3, %g1
a011226c:  c2 23 40 00  st  %g1, [ %o5 ]
a0112270:  98 13 20 38  or  %o4, 0x38, %o4
a0112274:  d6 03 00 00  ld  [ %o4 ], %o3
a0112278:  94 0a ff fd  and  %o3, -3, %o2
a011227c:  92 0a 60 ff  and  %o1, 0xff, %o1
a0112280:  d4 23 00 00  st  %o2, [ %o4 ]
a0112284:  80 a2 60 01  cmp  %o1, 1
a0112288:  02 80 00 58  be  0xa01123e8
a011228c:  80 a2 60 02  cmp  %o1, 2
a0112290:  02 bf fe 0e  be  0xa0111ac8
a0112294:  80 a2 60 04  cmp  %o1, 4
a0112298:  12 80 01 d1  bne  0xa01129dc
a011229c:  01 00 00 00  nop
a01122a0:  d6 03 00 00  ld  [ %o4 ], %o3
a01122a4:  82 12 e0 02  or  %o3, 2, %g1
a01122a8:  c2 23 00 00  st  %g1, [ %o4 ]
a01122ac:  30 80 01 cc  b,a   0xa01129dc
a01122b0:  11 33 c0 4d  sethi  %hi(0xcf013400), %o0
a01122b4:  98 12 20 40  or  %o0, 0x40, %o4	! 0xcf013440
a01122b8:  da 03 00 00  ld  [ %o4 ], %o5
a01122bc:  96 0b 7f d8  and  %o5, -40, %o3
a01122c0:  d6 23 00 00  st  %o3, [ %o4 ]
a01122c4:  96 12 20 44  or  %o0, 0x44, %o3
a01122c8:  c2 02 c0 00  ld  [ %o3 ], %g1
a01122cc:  94 08 7f fb  and  %g1, -5, %o2
a01122d0:  92 0a 60 ff  and  %o1, 0xff, %o1
a01122d4:  d4 22 c0 00  st  %o2, [ %o3 ]
a01122d8:  80 a2 60 01  cmp  %o1, 1
a01122dc:  02 80 00 5f  be  0xa0112458
a01122e0:  80 a2 60 02  cmp  %o1, 2
a01122e4:  02 80 01 57  be  0xa0112840
a01122e8:  80 a2 60 04  cmp  %o1, 4
a01122ec:  02 80 01 6b  be  0xa0112898
a01122f0:  80 a2 60 03  cmp  %o1, 3
a01122f4:  02 80 01 97  be  0xa0112950
a01122f8:  80 a2 60 06  cmp  %o1, 6
a01122fc:  02 80 01 a7  be  0xa0112998
a0112300:  80 a2 60 07  cmp  %o1, 7
a0112304:  02 80 01 aa  be  0xa01129ac
a0112308:  82 1a 60 03  xor  %o1, 3, %g1
a011230c:  80 a0 00 01  cmp  %g0, %g1
a0112310:  94 60 3f ff  subx  %g0, -1, %o2
a0112314:  98 1a 60 06  xor  %o1, 6, %o4
a0112318:  80 a0 00 0c  cmp  %g0, %o4
a011231c:  96 60 3f ff  subx  %g0, -1, %o3
a0112320:  80 92 80 0b  orcc  %o2, %o3, %g0
a0112324:  22 80 00 28  be,a   0xa01123c4
a0112328:  17 33 c0 47  sethi  %hi(0xcf011c00), %o3
a011232c:  1b 33 c0 47  sethi  %hi(0xcf011c00), %o5
a0112330:  9a 13 61 8c  or  %o5, 0x18c, %o5	! 0xcf011d8c
a0112334:  d0 03 40 00  ld  [ %o5 ], %o0
a0112338:  82 0a 20 fc  and  %o0, 0xfc, %g1
a011233c:  10 bf fd b3  b  0xa0111a08
a0112340:  82 10 60 01  or  %g1, 1, %g1
a0112344:  15 33 c0 4d  sethi  %hi(0xcf013400), %o2
a0112348:  98 12 a0 50  or  %o2, 0x50, %o4	! 0xcf013450
a011234c:  da 03 00 00  ld  [ %o4 ], %o5
a0112350:  96 0b 7f dc  and  %o5, -36, %o3
a0112354:  d6 23 00 00  st  %o3, [ %o4 ]
a0112358:  96 12 a0 54  or  %o2, 0x54, %o3
a011235c:  c2 02 c0 00  ld  [ %o3 ], %g1
a0112360:  90 08 7f fb  and  %g1, -5, %o0
a0112364:  82 0a 60 ff  and  %o1, 0xff, %g1
a0112368:  d0 22 c0 00  st  %o0, [ %o3 ]
a011236c:  80 a0 60 01  cmp  %g1, 1
a0112370:  02 80 01 06  be  0xa0112788
a0112374:  80 a0 60 02  cmp  %g1, 2
a0112378:  02 80 01 1b  be  0xa01127e4
a011237c:  80 a0 60 03  cmp  %g1, 3
a0112380:  02 80 01 10  be  0xa01127c0
a0112384:  80 a0 60 07  cmp  %g1, 7
a0112388:  02 80 01 65  be  0xa011291c
a011238c:  80 a0 60 03  cmp  %g1, 3
a0112390:  02 80 01 10  be  0xa01127d0
a0112394:  1b 33 c0 47  sethi  %hi(0xcf011c00), %o5
a0112398:  13 33 c0 47  sethi  %hi(0xcf011c00), %o1
a011239c:  9a 12 61 8c  or  %o1, 0x18c, %o5	! 0xcf011d8c
a01123a0:  d8 03 40 00  ld  [ %o5 ], %o4
a01123a4:  82 0b 20 cf  and  %o4, 0xcf, %g1
a01123a8:  c2 23 40 00  st  %g1, [ %o5 ]
a01123ac:  30 80 01 8c  b,a   0xa01129dc
a01123b0:  9a 12 62 40  or  %o1, 0x240, %o5
a01123b4:  d4 03 40 00  ld  [ %o5 ], %o2
a01123b8:  82 0a bf df  and  %o2, -33, %g1
a01123bc:  c2 23 40 00  st  %g1, [ %o5 ]
a01123c0:  30 80 01 87  b,a   0xa01129dc
a01123c4:  9a 12 e1 8c  or  %o3, 0x18c, %o5
a01123c8:  d2 03 40 00  ld  [ %o5 ], %o1
a01123cc:  82 0a 60 fc  and  %o1, 0xfc, %g1
a01123d0:  c2 23 40 00  st  %g1, [ %o5 ]
a01123d4:  30 80 01 82  b,a   0xa01129dc
a01123d8:  d2 02 c0 00  ld  [ %o3 ], %o1
a01123dc:  82 12 60 04  or  %o1, 4, %g1
a01123e0:  c2 22 c0 00  st  %g1, [ %o3 ]
a01123e4:  30 80 01 7e  b,a   0xa01129dc
a01123e8:  17 33 c0 f2  sethi  %hi(0xcf03c800), %o3
a01123ec:  98 12 e0 40  or  %o3, 0x40, %o4	! 0xcf03c840
a01123f0:  13 00 00 3f  sethi  %hi(0xfc00), %o1
a01123f4:  96 12 63 ff  or  %o1, 0x3ff, %o3	! 0xffff
a01123f8:  9a 10 3f ff  mov  -1, %o5
a01123fc:  94 10 20 01  mov  1, %o2
a0112400:  c2 03 00 00  ld  [ %o4 ], %g1
a0112404:  80 a0 60 02  cmp  %g1, 2
a0112408:  32 80 00 02  bne,a   0xa0112410
a011240c:  d4 23 00 00  st  %o2, [ %o4 ]
a0112410:  d0 03 00 00  ld  [ %o4 ], %o0
a0112414:  80 a2 20 01  cmp  %o0, 1
a0112418:  02 80 00 07  be  0xa0112434
a011241c:  9a 03 7f ff  add  %o5, -1, %o5
a0112420:  83 2b 60 10  sll  %o5, 0x10, %g1
a0112424:  93 30 60 10  srl  %g1, 0x10, %o1
a0112428:  80 a2 40 0b  cmp  %o1, %o3
a011242c:  12 bf ff f5  bne  0xa0112400
a0112430:  01 00 00 00  nop
a0112434:  96 10 20 01  mov  1, %o3	! 0x1
a0112438:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a011243c:  d6 23 00 00  st  %o3, [ %o4 ]
a0112440:  9a 13 60 28  or  %o5, 0x28, %o5
a0112444:  d4 03 40 00  ld  [ %o5 ], %o2
a0112448:  82 12 a0 02  or  %o2, 2, %g1
a011244c:  c2 23 40 00  st  %g1, [ %o5 ]
a0112450:  c0 23 00 00  clr  [ %o4 ]
a0112454:  30 80 01 62  b,a   0xa01129dc
a0112458:  d4 03 00 00  ld  [ %o4 ], %o2
a011245c:  82 12 a0 01  or  %o2, 1, %g1
a0112460:  c2 23 00 00  st  %g1, [ %o4 ]
a0112464:  10 bf ff aa  b  0xa011230c
a0112468:  82 1a 60 03  xor  %o1, 3, %g1
a011246c:  d2 02 c0 00  ld  [ %o3 ], %o1
a0112470:  82 12 60 02  or  %o1, 2, %g1
a0112474:  c2 22 c0 00  st  %g1, [ %o3 ]
a0112478:  30 80 01 59  b,a   0xa01129dc
a011247c:  d2 02 c0 00  ld  [ %o3 ], %o1
a0112480:  82 12 60 10  or  %o1, 0x10, %g1
a0112484:  c2 22 c0 00  st  %g1, [ %o3 ]
a0112488:  30 80 01 55  b,a   0xa01129dc
a011248c:  17 33 c0 f2  sethi  %hi(0xcf03c800), %o3
a0112490:  98 12 e0 40  or  %o3, 0x40, %o4	! 0xcf03c840
a0112494:  13 00 00 3f  sethi  %hi(0xfc00), %o1
a0112498:  96 12 63 ff  or  %o1, 0x3ff, %o3	! 0xffff
a011249c:  9a 10 3f ff  mov  -1, %o5
a01124a0:  94 10 20 01  mov  1, %o2
a01124a4:  c2 03 00 00  ld  [ %o4 ], %g1
a01124a8:  80 a0 60 02  cmp  %g1, 2
a01124ac:  32 80 00 02  bne,a   0xa01124b4
a01124b0:  d4 23 00 00  st  %o2, [ %o4 ]
a01124b4:  d0 03 00 00  ld  [ %o4 ], %o0
a01124b8:  80 a2 20 01  cmp  %o0, 1
a01124bc:  02 80 00 07  be  0xa01124d8
a01124c0:  9a 03 7f ff  add  %o5, -1, %o5
a01124c4:  83 2b 60 10  sll  %o5, 0x10, %g1
a01124c8:  93 30 60 10  srl  %g1, 0x10, %o1
a01124cc:  80 a2 40 0b  cmp  %o1, %o3
a01124d0:  12 bf ff f5  bne  0xa01124a4
a01124d4:  01 00 00 00  nop
a01124d8:  96 10 20 01  mov  1, %o3	! 0x1
a01124dc:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a01124e0:  d6 23 00 00  st  %o3, [ %o4 ]
a01124e4:  9a 13 60 28  or  %o5, 0x28, %o5
a01124e8:  d4 03 40 00  ld  [ %o5 ], %o2
a01124ec:  82 12 a0 04  or  %o2, 4, %g1
a01124f0:  c2 23 40 00  st  %g1, [ %o5 ]
a01124f4:  c0 23 00 00  clr  [ %o4 ]
a01124f8:  30 80 01 39  b,a   0xa01129dc
a01124fc:  17 33 c0 f2  sethi  %hi(0xcf03c800), %o3
a0112500:  98 12 e0 40  or  %o3, 0x40, %o4	! 0xcf03c840
a0112504:  13 00 00 3f  sethi  %hi(0xfc00), %o1
a0112508:  96 12 63 ff  or  %o1, 0x3ff, %o3	! 0xffff
a011250c:  9a 10 3f ff  mov  -1, %o5
a0112510:  94 10 20 01  mov  1, %o2
a0112514:  d0 03 00 00  ld  [ %o4 ], %o0
a0112518:  80 a2 20 02  cmp  %o0, 2
a011251c:  32 80 00 02  bne,a   0xa0112524
a0112520:  d4 23 00 00  st  %o2, [ %o4 ]
a0112524:  c2 03 00 00  ld  [ %o4 ], %g1
a0112528:  80 a0 60 01  cmp  %g1, 1
a011252c:  02 80 00 07  be  0xa0112548
a0112530:  9a 03 7f ff  add  %o5, -1, %o5
a0112534:  91 2b 60 10  sll  %o5, 0x10, %o0
a0112538:  93 32 20 10  srl  %o0, 0x10, %o1
a011253c:  80 a2 40 0b  cmp  %o1, %o3
a0112540:  12 bf ff f5  bne  0xa0112514
a0112544:  01 00 00 00  nop
a0112548:  96 10 20 01  mov  1, %o3	! 0x1
a011254c:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a0112550:  d6 23 00 00  st  %o3, [ %o4 ]
a0112554:  9a 13 60 28  or  %o5, 0x28, %o5
a0112558:  d4 03 40 00  ld  [ %o5 ], %o2
a011255c:  82 12 a0 10  or  %o2, 0x10, %g1
a0112560:  c2 23 40 00  st  %g1, [ %o5 ]
a0112564:  c0 23 00 00  clr  [ %o4 ]
a0112568:  30 80 01 1d  b,a   0xa01129dc
a011256c:  d2 03 00 00  ld  [ %o4 ], %o1
a0112570:  82 12 60 01  or  %o1, 1, %g1
a0112574:  c2 23 00 00  st  %g1, [ %o4 ]
a0112578:  10 bf fe fc  b  0xa0112168
a011257c:  13 33 c0 47  sethi  %hi(0xcf011c00), %o1
a0112580:  d2 03 00 00  ld  [ %o4 ], %o1
a0112584:  82 12 60 10  or  %o1, 0x10, %g1
a0112588:  c2 23 00 00  st  %g1, [ %o4 ]
a011258c:  10 bf fe 7b  b  0xa0111f78
a0112590:  19 33 c0 47  sethi  %hi(0xcf011c00), %o4
a0112594:  17 33 c0 f2  sethi  %hi(0xcf03c800), %o3
a0112598:  98 12 e0 40  or  %o3, 0x40, %o4	! 0xcf03c840
a011259c:  13 00 00 3f  sethi  %hi(0xfc00), %o1
a01125a0:  96 12 63 ff  or  %o1, 0x3ff, %o3	! 0xffff
a01125a4:  9a 10 3f ff  mov  -1, %o5
a01125a8:  94 10 20 01  mov  1, %o2
a01125ac:  c2 03 00 00  ld  [ %o4 ], %g1
a01125b0:  80 a0 60 02  cmp  %g1, 2
a01125b4:  32 80 00 02  bne,a   0xa01125bc
a01125b8:  d4 23 00 00  st  %o2, [ %o4 ]
a01125bc:  d0 03 00 00  ld  [ %o4 ], %o0
a01125c0:  80 a2 20 01  cmp  %o0, 1
a01125c4:  02 80 00 07  be  0xa01125e0
a01125c8:  9a 03 7f ff  add  %o5, -1, %o5
a01125cc:  83 2b 60 10  sll  %o5, 0x10, %g1
a01125d0:  93 30 60 10  srl  %g1, 0x10, %o1
a01125d4:  80 a2 40 0b  cmp  %o1, %o3
a01125d8:  12 bf ff f5  bne  0xa01125ac
a01125dc:  01 00 00 00  nop
a01125e0:  96 10 20 01  mov  1, %o3	! 0x1
a01125e4:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a01125e8:  d6 23 00 00  st  %o3, [ %o4 ]
a01125ec:  9a 13 60 28  or  %o5, 0x28, %o5
a01125f0:  d4 03 40 00  ld  [ %o5 ], %o2
a01125f4:  82 12 a0 20  or  %o2, 0x20, %g1
a01125f8:  c2 23 40 00  st  %g1, [ %o5 ]
a01125fc:  c0 23 00 00  clr  [ %o4 ]
a0112600:  30 80 00 f7  b,a   0xa01129dc
a0112604:  d2 02 c0 00  ld  [ %o3 ], %o1
a0112608:  82 12 60 08  or  %o1, 8, %g1
a011260c:  c2 22 c0 00  st  %g1, [ %o3 ]
a0112610:  30 80 00 f3  b,a   0xa01129dc
a0112614:  17 33 c0 f2  sethi  %hi(0xcf03c800), %o3
a0112618:  98 12 e0 40  or  %o3, 0x40, %o4	! 0xcf03c840
a011261c:  13 00 00 3f  sethi  %hi(0xfc00), %o1
a0112620:  96 12 63 ff  or  %o1, 0x3ff, %o3	! 0xffff
a0112624:  9a 10 3f ff  mov  -1, %o5
a0112628:  94 10 20 01  mov  1, %o2
a011262c:  d0 03 00 00  ld  [ %o4 ], %o0
a0112630:  80 a2 20 02  cmp  %o0, 2
a0112634:  32 80 00 02  bne,a   0xa011263c
a0112638:  d4 23 00 00  st  %o2, [ %o4 ]
a011263c:  c2 03 00 00  ld  [ %o4 ], %g1
a0112640:  80 a0 60 01  cmp  %g1, 1
a0112644:  02 80 00 07  be  0xa0112660
a0112648:  9a 03 7f ff  add  %o5, -1, %o5
a011264c:  91 2b 60 10  sll  %o5, 0x10, %o0
a0112650:  93 32 20 10  srl  %o0, 0x10, %o1
a0112654:  80 a2 40 0b  cmp  %o1, %o3
a0112658:  12 bf ff f5  bne  0xa011262c
a011265c:  01 00 00 00  nop
a0112660:  96 10 20 01  mov  1, %o3	! 0x1
a0112664:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a0112668:  d6 23 00 00  st  %o3, [ %o4 ]
a011266c:  9a 13 60 28  or  %o5, 0x28, %o5
a0112670:  d4 03 40 00  ld  [ %o5 ], %o2
a0112674:  82 12 a0 08  or  %o2, 8, %g1
a0112678:  c2 23 40 00  st  %g1, [ %o5 ]
a011267c:  c0 23 00 00  clr  [ %o4 ]
a0112680:  30 80 00 d7  b,a   0xa01129dc
a0112684:  17 33 c0 f2  sethi  %hi(0xcf03c800), %o3
a0112688:  98 12 e0 40  or  %o3, 0x40, %o4	! 0xcf03c840
a011268c:  13 00 00 3f  sethi  %hi(0xfc00), %o1
a0112690:  96 12 63 ff  or  %o1, 0x3ff, %o3	! 0xffff
a0112694:  9a 10 3f ff  mov  -1, %o5
a0112698:  94 10 20 01  mov  1, %o2
a011269c:  d0 03 00 00  ld  [ %o4 ], %o0
a01126a0:  80 a2 20 02  cmp  %o0, 2
a01126a4:  32 80 00 02  bne,a   0xa01126ac
a01126a8:  d4 23 00 00  st  %o2, [ %o4 ]
a01126ac:  c2 03 00 00  ld  [ %o4 ], %g1
a01126b0:  80 a0 60 01  cmp  %g1, 1
a01126b4:  02 80 00 07  be  0xa01126d0
a01126b8:  9a 03 7f ff  add  %o5, -1, %o5
a01126bc:  91 2b 60 10  sll  %o5, 0x10, %o0
a01126c0:  93 32 20 10  srl  %o0, 0x10, %o1
a01126c4:  80 a2 40 0b  cmp  %o1, %o3
a01126c8:  12 bf ff f5  bne  0xa011269c
a01126cc:  01 00 00 00  nop
a01126d0:  96 10 20 01  mov  1, %o3	! 0x1
a01126d4:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a01126d8:  d6 23 00 00  st  %o3, [ %o4 ]
a01126dc:  9a 13 60 28  or  %o5, 0x28, %o5
a01126e0:  d4 03 40 00  ld  [ %o5 ], %o2
a01126e4:  82 12 a0 40  or  %o2, 0x40, %g1
a01126e8:  c2 23 40 00  st  %g1, [ %o5 ]
a01126ec:  c0 23 00 00  clr  [ %o4 ]
a01126f0:  30 80 00 bb  b,a   0xa01129dc
a01126f4:  d0 03 40 00  ld  [ %o5 ], %o0
a01126f8:  82 12 20 01  or  %o0, 1, %g1
a01126fc:  c2 23 40 00  st  %g1, [ %o5 ]
a0112700:  10 bf fe af  b  0xa01121bc
a0112704:  90 1a 60 03  xor  %o1, 3, %o0
a0112708:  d2 02 c0 00  ld  [ %o3 ], %o1
a011270c:  82 12 60 01  or  %o1, 1, %g1
a0112710:  c2 22 c0 00  st  %g1, [ %o3 ]
a0112714:  30 80 00 b2  b,a   0xa01129dc
a0112718:  17 33 c0 f2  sethi  %hi(0xcf03c800), %o3
a011271c:  98 12 e0 40  or  %o3, 0x40, %o4	! 0xcf03c840
a0112720:  13 00 00 3f  sethi  %hi(0xfc00), %o1
a0112724:  96 12 63 ff  or  %o1, 0x3ff, %o3	! 0xffff
a0112728:  9a 10 3f ff  mov  -1, %o5
a011272c:  94 10 20 01  mov  1, %o2
a0112730:  c2 03 00 00  ld  [ %o4 ], %g1
a0112734:  80 a0 60 02  cmp  %g1, 2
a0112738:  32 80 00 02  bne,a   0xa0112740
a011273c:  d4 23 00 00  st  %o2, [ %o4 ]
a0112740:  d0 03 00 00  ld  [ %o4 ], %o0
a0112744:  80 a2 20 01  cmp  %o0, 1
a0112748:  02 80 00 07  be  0xa0112764
a011274c:  9a 03 7f ff  add  %o5, -1, %o5
a0112750:  83 2b 60 10  sll  %o5, 0x10, %g1
a0112754:  93 30 60 10  srl  %g1, 0x10, %o1
a0112758:  80 a2 40 0b  cmp  %o1, %o3
a011275c:  12 bf ff f5  bne  0xa0112730
a0112760:  01 00 00 00  nop
a0112764:  96 10 20 01  mov  1, %o3	! 0x1
a0112768:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a011276c:  d6 23 00 00  st  %o3, [ %o4 ]
a0112770:  9a 13 60 28  or  %o5, 0x28, %o5
a0112774:  d4 03 40 00  ld  [ %o5 ], %o2
a0112778:  82 12 a0 80  or  %o2, 0x80, %g1
a011277c:  c2 23 40 00  st  %g1, [ %o5 ]
a0112780:  c0 23 00 00  clr  [ %o4 ]
a0112784:  30 80 00 96  b,a   0xa01129dc
a0112788:  d2 03 00 00  ld  [ %o4 ], %o1
a011278c:  82 12 60 01  or  %o1, 1, %g1
a0112790:  c2 23 00 00  st  %g1, [ %o4 ]
a0112794:  10 bf ff 02  b  0xa011239c
a0112798:  13 33 c0 47  sethi  %hi(0xcf011c00), %o1
a011279c:  d4 03 00 00  ld  [ %o4 ], %o2
a01127a0:  9a 12 a0 21  or  %o2, 0x21, %o5
a01127a4:  da 23 00 00  st  %o5, [ %o4 ]
a01127a8:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a01127ac:  9a 10 61 8c  or  %g1, 0x18c, %o5	! 0xcf011d8c
a01127b0:  d6 03 40 00  ld  [ %o5 ], %o3
a01127b4:  82 0a e0 f3  and  %o3, 0xf3, %g1
a01127b8:  10 bf fd 71  b  0xa0111d7c
a01127bc:  82 10 60 04  or  %g1, 4, %g1
a01127c0:  d4 03 00 00  ld  [ %o4 ], %o2
a01127c4:  82 12 a0 21  or  %o2, 0x21, %g1
a01127c8:  c2 23 00 00  st  %g1, [ %o4 ]
a01127cc:  1b 33 c0 47  sethi  %hi(0xcf011c00), %o5
a01127d0:  9a 13 61 8c  or  %o5, 0x18c, %o5	! 0xcf011d8c
a01127d4:  d6 03 40 00  ld  [ %o5 ], %o3
a01127d8:  82 0a e0 cf  and  %o3, 0xcf, %g1
a01127dc:  10 bf fe 3d  b  0xa01120d0
a01127e0:  82 10 60 10  or  %g1, 0x10, %g1
a01127e4:  d0 03 00 00  ld  [ %o4 ], %o0
a01127e8:  82 12 20 02  or  %o0, 2, %g1
a01127ec:  c2 23 00 00  st  %g1, [ %o4 ]
a01127f0:  10 bf fe eb  b  0xa011239c
a01127f4:  13 33 c0 47  sethi  %hi(0xcf011c00), %o1
a01127f8:  d6 03 00 00  ld  [ %o4 ], %o3
a01127fc:  82 12 e0 01  or  %o3, 1, %g1
a0112800:  c2 23 00 00  st  %g1, [ %o4 ]
a0112804:  30 80 00 76  b,a   0xa01129dc
a0112808:  d8 03 40 00  ld  [ %o5 ], %o4
a011280c:  82 13 20 80  or  %o4, 0x80, %g1
a0112810:  c2 23 40 00  st  %g1, [ %o5 ]
a0112814:  30 80 00 72  b,a   0xa01129dc
a0112818:  d0 03 00 00  ld  [ %o4 ], %o0
a011281c:  82 12 20 20  or  %o0, 0x20, %g1
a0112820:  c2 23 00 00  st  %g1, [ %o4 ]
a0112824:  10 bf fd d5  b  0xa0111f78
a0112828:  19 33 c0 47  sethi  %hi(0xcf011c00), %o4
a011282c:  c2 03 40 00  ld  [ %o5 ], %g1
a0112830:  82 10 60 04  or  %g1, 4, %g1
a0112834:  c2 23 40 00  st  %g1, [ %o5 ]
a0112838:  10 bf fe 61  b  0xa01121bc
a011283c:  90 1a 60 03  xor  %o1, 3, %o0
a0112840:  c2 03 00 00  ld  [ %o4 ], %g1
a0112844:  82 10 60 02  or  %g1, 2, %g1
a0112848:  c2 23 00 00  st  %g1, [ %o4 ]
a011284c:  10 bf fe b0  b  0xa011230c
a0112850:  82 1a 60 03  xor  %o1, 3, %g1
a0112854:  d0 03 00 00  ld  [ %o4 ], %o0
a0112858:  82 12 20 02  or  %o0, 2, %g1
a011285c:  c2 23 00 00  st  %g1, [ %o4 ]
a0112860:  10 bf fe 42  b  0xa0112168
a0112864:  13 33 c0 47  sethi  %hi(0xcf011c00), %o1
a0112868:  d2 03 00 00  ld  [ %o4 ], %o1
a011286c:  9a 12 60 10  or  %o1, 0x10, %o5
a0112870:  da 23 00 00  st  %o5, [ %o4 ]
a0112874:  d4 02 c0 00  ld  [ %o3 ], %o2
a0112878:  98 12 a0 02  or  %o2, 2, %o4
a011287c:  d8 22 c0 00  st  %o4, [ %o3 ]
a0112880:  11 33 c0 47  sethi  %hi(0xcf011c00), %o0
a0112884:  9a 12 21 8c  or  %o0, 0x18c, %o5	! 0xcf011d8c
a0112888:  d6 03 40 00  ld  [ %o5 ], %o3
a011288c:  82 0a e0 3f  and  %o3, 0x3f, %g1
a0112890:  10 bf fd 78  b  0xa0111e70
a0112894:  82 10 60 40  or  %g1, 0x40, %g1
a0112898:  d0 03 00 00  ld  [ %o4 ], %o0
a011289c:  82 12 20 04  or  %o0, 4, %g1
a01128a0:  c2 23 00 00  st  %g1, [ %o4 ]
a01128a4:  10 bf fe 9a  b  0xa011230c
a01128a8:  82 1a 60 03  xor  %o1, 3, %g1
a01128ac:  c2 03 00 00  ld  [ %o4 ], %g1
a01128b0:  82 10 60 40  or  %g1, 0x40, %g1
a01128b4:  c2 23 00 00  st  %g1, [ %o4 ]
a01128b8:  10 bf fd b0  b  0xa0111f78
a01128bc:  19 33 c0 47  sethi  %hi(0xcf011c00), %o4
a01128c0:  d8 03 40 00  ld  [ %o5 ], %o4
a01128c4:  82 13 20 21  or  %o4, 0x21, %g1
a01128c8:  c2 23 40 00  st  %g1, [ %o5 ]
a01128cc:  10 bf fe 3c  b  0xa01121bc
a01128d0:  90 1a 60 03  xor  %o1, 3, %o0
a01128d4:  d4 03 40 00  ld  [ %o5 ], %o2
a01128d8:  82 12 a0 24  or  %o2, 0x24, %g1
a01128dc:  c2 23 40 00  st  %g1, [ %o5 ]
a01128e0:  10 bf fe 37  b  0xa01121bc
a01128e4:  90 1a 60 03  xor  %o1, 3, %o0
a01128e8:  d4 03 00 00  ld  [ %o4 ], %o2
a01128ec:  9a 12 a0 21  or  %o2, 0x21, %o5
a01128f0:  da 23 00 00  st  %o5, [ %o4 ]
a01128f4:  d0 02 c0 00  ld  [ %o3 ], %o0
a01128f8:  92 12 20 04  or  %o0, 4, %o1
a01128fc:  19 33 c0 47  sethi  %hi(0xcf011c00), %o4
a0112900:  d2 22 c0 00  st  %o1, [ %o3 ]
a0112904:  98 13 21 8c  or  %o4, 0x18c, %o4
a0112908:  c2 03 00 00  ld  [ %o4 ], %g1
a011290c:  96 08 60 f3  and  %g1, 0xf3, %o3
a0112910:  82 12 e0 0c  or  %o3, 0xc, %g1
a0112914:  c2 23 00 00  st  %g1, [ %o4 ]
a0112918:  30 80 00 31  b,a   0xa01129dc
a011291c:  d4 03 00 00  ld  [ %o4 ], %o2
a0112920:  82 12 a0 21  or  %o2, 0x21, %g1
a0112924:  c2 23 00 00  st  %g1, [ %o4 ]
a0112928:  d0 02 c0 00  ld  [ %o3 ], %o0
a011292c:  92 12 20 04  or  %o0, 4, %o1
a0112930:  19 33 c0 47  sethi  %hi(0xcf011c00), %o4
a0112934:  d2 22 c0 00  st  %o1, [ %o3 ]
a0112938:  98 13 21 8c  or  %o4, 0x18c, %o4
a011293c:  da 03 00 00  ld  [ %o4 ], %o5
a0112940:  96 0b 60 cf  and  %o5, 0xcf, %o3
a0112944:  82 12 e0 30  or  %o3, 0x30, %g1
a0112948:  c2 23 00 00  st  %g1, [ %o4 ]
a011294c:  30 80 00 24  b,a   0xa01129dc
a0112950:  d6 03 00 00  ld  [ %o4 ], %o3
a0112954:  82 12 e0 21  or  %o3, 0x21, %g1
a0112958:  c2 23 00 00  st  %g1, [ %o4 ]
a011295c:  10 bf fe 6c  b  0xa011230c
a0112960:  82 1a 60 03  xor  %o1, 3, %g1
a0112964:  d2 03 00 00  ld  [ %o4 ], %o1
a0112968:  9a 12 60 10  or  %o1, 0x10, %o5
a011296c:  da 23 00 00  st  %o5, [ %o4 ]
a0112970:  d4 02 c0 00  ld  [ %o3 ], %o2
a0112974:  98 12 a0 42  or  %o2, 0x42, %o4
a0112978:  d8 22 c0 00  st  %o4, [ %o3 ]
a011297c:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a0112980:  98 10 61 8c  or  %g1, 0x18c, %o4	! 0xcf011d8c
a0112984:  d0 03 00 00  ld  [ %o4 ], %o0
a0112988:  96 0a 20 3f  and  %o0, 0x3f, %o3
a011298c:  82 12 e0 c0  or  %o3, 0xc0, %g1
a0112990:  c2 23 00 00  st  %g1, [ %o4 ]
a0112994:  30 80 00 12  b,a   0xa01129dc
a0112998:  da 03 00 00  ld  [ %o4 ], %o5
a011299c:  82 13 60 24  or  %o5, 0x24, %g1
a01129a0:  c2 23 00 00  st  %g1, [ %o4 ]
a01129a4:  10 bf fe 5a  b  0xa011230c
a01129a8:  82 1a 60 03  xor  %o1, 3, %g1
a01129ac:  d2 03 00 00  ld  [ %o4 ], %o1
a01129b0:  9a 12 60 21  or  %o1, 0x21, %o5
a01129b4:  da 23 00 00  st  %o5, [ %o4 ]
a01129b8:  d0 02 c0 00  ld  [ %o3 ], %o0
a01129bc:  82 12 20 04  or  %o0, 4, %g1
a01129c0:  19 33 c0 47  sethi  %hi(0xcf011c00), %o4
a01129c4:  c2 22 c0 00  st  %g1, [ %o3 ]
a01129c8:  98 13 21 8c  or  %o4, 0x18c, %o4
a01129cc:  d4 03 00 00  ld  [ %o4 ], %o2
a01129d0:  92 0a a0 fc  and  %o2, 0xfc, %o1
a01129d4:  82 12 60 03  or  %o1, 3, %g1
a01129d8:  c2 23 00 00  st  %g1, [ %o4 ]
a01129dc:  81 c3 e0 08  retl
a01129e0:  01 00 00 00  nop
