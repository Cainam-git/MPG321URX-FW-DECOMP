# leon2s DPTX_SetBrilliantMode 0xa0089a38-0xa0089d38 (768 bytes)
a0089a38:  9d e3 bf 98  save  %sp, -104, %sp
a0089a3c:  2b 2a 01 f3  sethi  %hi(0xa807cc00), %l5
a0089a40:  a2 0e 20 ff  and  %i0, 0xff, %l1
a0089a44:  82 15 61 04  or  %l5, 0x104, %g1
a0089a48:  9b 2c 60 03  sll  %l1, 3, %o5
a0089a4c:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a0089a50:  80 a0 60 00  cmp  %g1, 0
a0089a54:  02 80 00 b7  be  0xa0089d30
a0089a58:  01 00 00 00  nop
a0089a5c:  7f ff ff 8f  call  0xa0089898
a0089a60:  90 10 00 11  mov  %l1, %o0
a0089a64:  a4 10 00 08  mov  %o0, %l2
a0089a68:  92 10 20 03  mov  3, %o1
a0089a6c:  40 00 77 92  call  0xa00a78b4
a0089a70:  90 10 00 11  mov  %l1, %o0
a0089a74:  a0 0a 20 0f  and  %o0, 0xf, %l0
a0089a78:  90 10 00 11  mov  %l1, %o0
a0089a7c:  40 00 77 8e  call  0xa00a78b4
a0089a80:  92 10 20 66  mov  0x66, %o1
a0089a84:  82 0a 20 e0  and  %o0, 0xe0, %g1
a0089a88:  80 a0 60 40  cmp  %g1, 0x40
a0089a8c:  02 80 00 06  be  0xa0089aa4
a0089a90:  a6 10 20 1e  mov  0x1e, %l3
a0089a94:  80 a0 00 01  cmp  %g0, %g1
a0089a98:  82 60 20 00  subx  %g0, 0, %g1
a0089a9c:  82 08 60 06  and  %g1, 6, %g1
a0089aa0:  a6 00 60 12  add  %g1, 0x12, %l3
a0089aa4:  80 a4 a0 00  cmp  %l2, 0
a0089aa8:  02 80 00 a2  be  0xa0089d30
a0089aac:  19 2a 01 e2  sethi  %hi(0xa8078800), %o4
a0089ab0:  82 13 22 10  or  %o4, 0x210, %g1	! 0xa8078a10
a0089ab4:  9b 2c 60 02  sll  %l1, 2, %o5
a0089ab8:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a0089abc:  82 20 40 12  sub  %g1, %l2, %g1
a0089ac0:  80 a0 7f fe  cmp  %g1, -2
a0089ac4:  06 80 00 12  bl  0xa0089b0c
a0089ac8:  80 a0 60 02  cmp  %g1, 2
a0089acc:  14 80 00 11  bg  0xa0089b10
a0089ad0:  9a 13 22 10  or  %o4, 0x210, %o5
a0089ad4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0089ad8:  82 10 62 28  or  %g1, 0x228, %g1	! 0xa8078a28
a0089adc:  da 08 40 11  ldub  [ %g1 + %l1 ], %o5
a0089ae0:  82 0c e0 ff  and  %l3, 0xff, %g1
a0089ae4:  80 a3 40 01  cmp  %o5, %g1
a0089ae8:  12 80 00 0a  bne  0xa0089b10
a0089aec:  9a 13 22 10  or  %o4, 0x210, %o5
a0089af0:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0089af4:  82 10 61 c8  or  %g1, 0x1c8, %g1	! 0xa80761c8
a0089af8:  da 08 40 11  ldub  [ %g1 + %l1 ], %o5
a0089afc:  82 0c 20 ff  and  %l0, 0xff, %g1
a0089b00:  80 a3 40 01  cmp  %o5, %g1
a0089b04:  02 80 00 8b  be  0xa0089d30
a0089b08:  01 00 00 00  nop
a0089b0c:  9a 13 22 10  or  %o4, 0x210, %o5
a0089b10:  83 2c 60 02  sll  %l1, 2, %g1
a0089b14:  e4 23 40 01  st  %l2, [ %o5 + %g1 ]
a0089b18:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0089b1c:  82 10 62 28  or  %g1, 0x228, %g1	! 0xa8078a28
a0089b20:  e6 28 40 11  stb  %l3, [ %g1 + %l1 ]
a0089b24:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0089b28:  82 10 61 c8  or  %g1, 0x1c8, %g1	! 0xa80761c8
a0089b2c:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0089b30:  e0 28 40 11  stb  %l0, [ %g1 + %l1 ]
a0089b34:  94 10 00 12  mov  %l2, %o2
a0089b38:  92 10 00 11  mov  %l1, %o1
a0089b3c:  7f ff a5 42  call  0xa0073044
a0089b40:  90 12 23 e0  or  %o0, 0x3e0, %o0
a0089b44:  a8 0c e0 ff  and  %l3, 0xff, %l4
a0089b48:  11 28 01 a3  sethi  %hi(0xa0068c00), %o0
a0089b4c:  92 10 00 14  mov  %l4, %o1
a0089b50:  7f ff a5 3d  call  0xa0073044
a0089b54:  90 12 20 10  or  %o0, 0x10, %o0
a0089b58:  a6 0c 20 ff  and  %l0, 0xff, %l3
a0089b5c:  11 28 01 a3  sethi  %hi(0xa0068c00), %o0
a0089b60:  92 10 00 13  mov  %l3, %o1
a0089b64:  7f ff a5 38  call  0xa0073044
a0089b68:  90 12 20 20  or  %o0, 0x20, %o0
a0089b6c:  90 10 00 11  mov  %l1, %o0
a0089b70:  40 00 77 51  call  0xa00a78b4
a0089b74:  92 10 20 02  mov  2, %o1
a0089b78:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089b7c:  80 a2 20 0a  cmp  %o0, 0xa
a0089b80:  02 80 00 0e  be  0xa0089bb8
a0089b84:  a0 10 21 0e  mov  0x10e, %l0
a0089b88:  80 a2 20 0a  cmp  %o0, 0xa
a0089b8c:  34 80 00 05  bg,a   0xa0089ba0
a0089b90:  80 a2 20 14  cmp  %o0, 0x14
a0089b94:  80 a2 20 06  cmp  %o0, 6
a0089b98:  10 80 00 06  b  0xa0089bb0
a0089b9c:  a0 10 20 a2  mov  0xa2, %l0
a0089ba0:  02 80 00 06  be  0xa0089bb8
a0089ba4:  a0 10 22 1c  mov  0x21c, %l0
a0089ba8:  80 a2 20 1e  cmp  %o0, 0x1e
a0089bac:  a0 10 23 2a  mov  0x32a, %l0
a0089bb0:  32 80 00 02  bne,a   0xa0089bb8
a0089bb4:  a0 10 22 1c  mov  0x21c, %l0
a0089bb8:  11 28 01 a3  sethi  %hi(0xa0068c00), %o0
a0089bbc:  92 10 00 12  mov  %l2, %o1
a0089bc0:  7f ff a5 21  call  0xa0073044
a0089bc4:  90 12 20 38  or  %o0, 0x38, %o0
a0089bc8:  82 5c 80 14  smul  %l2, %l4, %g1
a0089bcc:  83 30 60 05  srl  %g1, 5, %g1
a0089bd0:  82 58 40 13  smul  %g1, %l3, %g1
a0089bd4:  a9 2c 20 10  sll  %l0, 0x10, %l4
a0089bd8:  a1 35 20 10  srl  %l4, 0x10, %l0
a0089bdc:  83 28 60 03  sll  %g1, 3, %g1
a0089be0:  81 80 00 00  mov  %g0, %y
a0089be4:  01 00 00 00  nop
a0089be8:  01 00 00 00  nop
a0089bec:  01 00 00 00  nop
a0089bf0:  82 70 40 10  udiv  %g1, %l0, %g1
a0089bf4:  83 30 60 01  srl  %g1, 1, %g1
a0089bf8:  82 00 60 01  inc  %g1
a0089bfc:  94 08 60 ff  and  %g1, 0xff, %o2
a0089c00:  90 10 00 11  mov  %l1, %o0
a0089c04:  40 00 77 3e  call  0xa00a78fc
a0089c08:  92 10 20 7e  mov  0x7e, %o1
a0089c0c:  a0 5c 00 13  smul  %l0, %l3, %l0
a0089c10:  82 04 00 10  add  %l0, %l0, %g1
a0089c14:  9a 04 80 12  add  %l2, %l2, %o5
a0089c18:  82 00 40 10  add  %g1, %l0, %g1
a0089c1c:  81 80 00 00  mov  %g0, %y
a0089c20:  01 00 00 00  nop
a0089c24:  01 00 00 00  nop
a0089c28:  01 00 00 00  nop
a0089c2c:  82 70 40 0d  udiv  %g1, %o5, %g1
a0089c30:  82 00 60 05  add  %g1, 5, %g1
a0089c34:  94 08 60 ff  and  %g1, 0xff, %o2
a0089c38:  90 10 00 11  mov  %l1, %o0
a0089c3c:  40 00 77 30  call  0xa00a78fc
a0089c40:  92 10 20 7c  mov  0x7c, %o1
a0089c44:  40 00 0e ef  call  0xa008d800
a0089c48:  01 00 00 00  nop
a0089c4c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089c50:  80 a2 20 83  cmp  %o0, 0x83
a0089c54:  08 80 00 0b  bleu  0xa0089c80
a0089c58:  80 a4 a2 bb  cmp  %l2, 0x2bb
a0089c5c:  80 a4 60 00  cmp  %l1, 0
a0089c60:  02 80 00 08  be  0xa0089c80
a0089c64:  80 a4 a2 bb  cmp  %l2, 0x2bb
a0089c68:  90 10 00 11  mov  %l1, %o0
a0089c6c:  92 10 20 7c  mov  0x7c, %o1
a0089c70:  94 10 20 80  mov  0x80, %o2
a0089c74:  40 00 77 33  call  0xa00a7940
a0089c78:  96 10 20 01  mov  1, %o3
a0089c7c:  80 a4 a2 bb  cmp  %l2, 0x2bb
a0089c80:  18 80 00 03  bgu  0xa0089c8c
a0089c84:  9a 10 20 01  mov  1, %o5
a0089c88:  9a 10 20 00  clr  %o5
a0089c8c:  83 35 20 10  srl  %l4, 0x10, %g1
a0089c90:  82 18 62 1c  xor  %g1, 0x21c, %g1
a0089c94:  80 a0 00 01  cmp  %g0, %g1
a0089c98:  82 60 3f ff  subx  %g0, -1, %g1
a0089c9c:  90 10 00 11  mov  %l1, %o0
a0089ca0:  92 10 20 7b  mov  0x7b, %o1
a0089ca4:  80 8b 40 01  btst  %o5, %g1
a0089ca8:  12 80 00 14  bne  0xa0089cf8
a0089cac:  94 10 20 12  mov  0x12, %o2
a0089cb0:  90 10 00 11  mov  %l1, %o0
a0089cb4:  40 00 77 00  call  0xa00a78b4
a0089cb8:  92 10 20 7e  mov  0x7e, %o1
a0089cbc:  90 0a 20 3f  and  %o0, 0x3f, %o0
a0089cc0:  80 a2 20 10  cmp  %o0, 0x10
a0089cc4:  24 80 00 06  ble,a   0xa0089cdc
a0089cc8:  92 10 20 7e  mov  0x7e, %o1
a0089ccc:  90 10 00 11  mov  %l1, %o0
a0089cd0:  92 10 20 7b  mov  0x7b, %o1
a0089cd4:  10 80 00 09  b  0xa0089cf8
a0089cd8:  94 10 20 20  mov  0x20, %o2
a0089cdc:  40 00 76 f6  call  0xa00a78b4
a0089ce0:  90 10 00 11  mov  %l1, %o0
a0089ce4:  94 0a 20 3f  and  %o0, 0x3f, %o2
a0089ce8:  94 02 a0 01  inc  %o2
a0089cec:  90 10 00 11  mov  %l1, %o0
a0089cf0:  94 02 80 0a  add  %o2, %o2, %o2
a0089cf4:  92 10 20 7b  mov  0x7b, %o1
a0089cf8:  40 00 77 01  call  0xa00a78fc
a0089cfc:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0089d00:  90 10 00 10  mov  %l0, %o0
a0089d04:  92 10 20 7b  mov  0x7b, %o1
a0089d08:  94 10 20 01  mov  1, %o2
a0089d0c:  40 00 77 0d  call  0xa00a7940
a0089d10:  96 10 20 01  mov  1, %o3
a0089d14:  82 15 61 04  or  %l5, 0x104, %g1
a0089d18:  a1 2c 20 03  sll  %l0, 3, %l0
a0089d1c:  40 00 a0 d2  call  0xa00b2064
a0089d20:  a0 04 00 01  add  %l0, %g1, %l0
a0089d24:  82 10 20 01  mov  1, %g1
a0089d28:  c2 2c 20 01  stb  %g1, [ %l0 + 1 ]
a0089d2c:  d0 34 20 02  sth  %o0, [ %l0 + 2 ]
a0089d30:  81 c7 e0 08  ret
a0089d34:  81 e8 00 00  restore
