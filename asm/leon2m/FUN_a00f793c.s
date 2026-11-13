# leon2m FUN_a00f793c 0xa00f793c-0xa00f87b0 (3700 bytes)
a00f793c:  9d e3 bf 88  save  %sp, -120, %sp
a00f7940:  2d 2a 00 ad  sethi  %hi(0xa802b400), %l6
a00f7944:  da 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %o5	! 0xa802b7b4
a00f7948:  82 10 20 10  mov  0x10, %g1
a00f794c:  c2 2f bf f2  stb  %g1, [ %fp + -14 ]
a00f7950:  80 a3 60 03  cmp  %o5, 3
a00f7954:  c0 2f bf f1  clrb  [ %fp + -15 ]
a00f7958:  02 80 00 10  be  0xa00f7998
a00f795c:  c0 2f bf f0  clrb  [ %fp + -16 ]
a00f7960:  29 33 c0 3b  sethi  %hi(0xcf00ec00), %l4
a00f7964:  a0 15 20 84  or  %l4, 0x84, %l0	! 0xcf00ec84
a00f7968:  e6 04 00 00  ld  [ %l0 ], %l3
a00f796c:  a4 0c e0 fc  and  %l3, 0xfc, %l2
a00f7970:  a2 14 a0 03  or  %l2, 3, %l1
a00f7974:  1f 33 c0 3a  sethi  %hi(0xcf00e800), %o7
a00f7978:  e2 24 00 00  st  %l1, [ %l0 ]
a00f797c:  98 13 e1 80  or  %o7, 0x180, %o4
a00f7980:  d6 03 00 00  ld  [ %o4 ], %o3
a00f7984:  94 0a e0 fc  and  %o3, 0xfc, %o2
a00f7988:  92 12 a0 03  or  %o2, 3, %o1
a00f798c:  d2 23 00 00  st  %o1, [ %o4 ]
a00f7990:  90 10 20 03  mov  3, %o0
a00f7994:  d0 2d a3 b4  stb  %o0, [ %l6 + 0x3b4 ]
a00f7998:  96 10 20 ff  mov  0xff, %o3
a00f799c:  90 10 20 01  mov  1, %o0
a00f79a0:  92 10 20 02  mov  2, %o1
a00f79a4:  7f ff fd 90  call  0xa00f6fe4
a00f79a8:  94 10 20 00  clr  %o2
a00f79ac:  ea 0f bf f2  ldub  [ %fp + -14 ], %l5
a00f79b0:  ee 17 bf f0  lduh  [ %fp + -16 ], %l7
a00f79b4:  ee 37 bf e8  sth  %l7, [ %fp + -24 ]
a00f79b8:  ea 2f bf ea  stb  %l5, [ %fp + -22 ]
a00f79bc:  80 a5 60 08  cmp  %l5, 8
a00f79c0:  02 80 03 47  be  0xa00f86dc
a00f79c4:  96 10 20 00  clr  %o3
a00f79c8:  80 a5 60 08  cmp  %l5, 8
a00f79cc:  14 80 03 40  bg  0xa00f86cc
a00f79d0:  80 a5 60 10  cmp  %l5, 0x10
a00f79d4:  25 33 c0 3b  sethi  %hi(0xcf00ec00), %l2
a00f79d8:  a2 14 a2 80  or  %l2, 0x280, %l1	! 0xcf00ee80
a00f79dc:  da 04 40 00  ld  [ %l1 ], %o5
a00f79e0:  d2 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %o1
a00f79e4:  ae 02 40 09  add  %o1, %o1, %l7
a00f79e8:  ba 0b 60 f9  and  %o5, 0xf9, %i5
a00f79ec:  a0 17 40 17  or  %i5, %l7, %l0
a00f79f0:  e0 24 40 00  st  %l0, [ %l1 ]
a00f79f4:  a0 14 a2 c0  or  %l2, 0x2c0, %l0
a00f79f8:  ea 04 00 00  ld  [ %l0 ], %l5
a00f79fc:  e8 0f bf e8  ldub  [ %fp + -24 ], %l4
a00f7a00:  9e 0d 60 3a  and  %l5, 0x3a, %o7
a00f7a04:  d4 0f bf e9  ldub  [ %fp + -23 ], %o2
a00f7a08:  a7 2d 20 07  sll  %l4, 7, %l3
a00f7a0c:  82 13 c0 13  or  %o7, %l3, %g1
a00f7a10:  99 2a a0 06  sll  %o2, 6, %o4
a00f7a14:  90 0a e0 ff  and  %o3, 0xff, %o0
a00f7a18:  ae 10 40 0c  or  %g1, %o4, %l7
a00f7a1c:  9b 2a 20 02  sll  %o0, 2, %o5
a00f7a20:  ba 15 c0 0d  or  %l7, %o5, %i5
a00f7a24:  fa 24 00 00  st  %i5, [ %l0 ]
a00f7a28:  3b 00 06 68  sethi  %hi(0x19a000), %i5
a00f7a2c:  d4 0f bf ea  ldub  [ %fp + -22 ], %o2
a00f7a30:  7f ff 9d d0  call  0xa00df170
a00f7a34:  90 17 63 c0  or  %i5, 0x3c0, %o0
a00f7a38:  ea 04 40 00  ld  [ %l1 ], %l5
a00f7a3c:  e8 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %l4
a00f7a40:  a6 05 00 14  add  %l4, %l4, %l3
a00f7a44:  9e 0d 60 f9  and  %l5, 0xf9, %o7
a00f7a48:  96 13 c0 13  or  %o7, %l3, %o3
a00f7a4c:  d6 24 40 00  st  %o3, [ %l1 ]
a00f7a50:  d4 04 00 00  ld  [ %l0 ], %o2
a00f7a54:  92 0a bf df  and  %o2, -33, %o1
a00f7a58:  d2 24 00 00  st  %o1, [ %l0 ]
a00f7a5c:  9a 14 a2 c4  or  %l2, 0x2c4, %o5
a00f7a60:  d8 03 40 00  ld  [ %o5 ], %o4
a00f7a64:  90 0b 20 0f  and  %o4, 0xf, %o0
a00f7a68:  a8 12 20 50  or  %o0, 0x50, %l4
a00f7a6c:  aa 10 00 12  mov  %l2, %l5
a00f7a70:  82 0d 20 ff  and  %l4, 0xff, %g1
a00f7a74:  2f 00 06 68  sethi  %hi(0x19a000), %l7
a00f7a78:  c2 23 40 00  st  %g1, [ %o5 ]
a00f7a7c:  a6 15 e3 78  or  %l7, 0x378, %l3
a00f7a80:  a2 10 20 00  clr  %l1
a00f7a84:  a0 10 20 00  clr  %l0
a00f7a88:  a4 14 a2 c8  or  %l2, 0x2c8, %l2
a00f7a8c:  98 04 00 10  add  %l0, %l0, %o4
a00f7a90:  a0 03 00 13  add  %o4, %l3, %l0
a00f7a94:  c2 0c 20 03  ldub  [ %l0 + 3 ], %g1
a00f7a98:  c2 24 80 00  st  %g1, [ %l2 ]
a00f7a9c:  7f ff ec f6  call  0xa00f2e74
a00f7aa0:  01 00 00 00  nop
a00f7aa4:  d0 14 20 02  lduh  [ %l0 + 2 ], %o0
a00f7aa8:  97 32 20 08  srl  %o0, 8, %o3
a00f7aac:  d6 24 80 00  st  %o3, [ %l2 ]
a00f7ab0:  7f ff ec f1  call  0xa00f2e74
a00f7ab4:  a2 04 60 01  inc  %l1
a00f7ab8:  d2 0c c0 00  ldub  [ %l3 ], %o1
a00f7abc:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00f7ac0:  80 a2 40 10  cmp  %o1, %l0
a00f7ac4:  1a bf ff f3  bcc  0xa00f7a90
a00f7ac8:  98 04 00 10  add  %l0, %l0, %o4
a00f7acc:  9a 15 3f 90  or  %l4, -112, %o5
a00f7ad0:  92 0b 60 ff  and  %o5, 0xff, %o1
a00f7ad4:  a4 15 62 c4  or  %l5, 0x2c4, %l2
a00f7ad8:  d2 24 80 00  st  %o1, [ %l2 ]
a00f7adc:  67 fe 59 f2  call  0x4008e2a4
a00f7ae0:  01 00 00 00  nop
a00f7ae4:  d4 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %o2
a00f7ae8:  98 02 a0 04  add  %o2, 4, %o4
a00f7aec:  92 15 62 80  or  %l5, 0x280, %o1
a00f7af0:  94 10 20 01  mov  1, %o2
a00f7af4:  e8 02 40 00  ld  [ %o1 ], %l4
a00f7af8:  91 2a 80 0c  sll  %o2, %o4, %o0
a00f7afc:  a6 15 00 08  or  %l4, %o0, %l3
a00f7b00:  9e 0c e0 ff  and  %l3, 0xff, %o7
a00f7b04:  de 22 40 00  st  %o7, [ %o1 ]
a00f7b08:  e2 04 80 00  ld  [ %l2 ], %l1
a00f7b0c:  82 0c 7f 7f  and  %l1, -129, %g1
a00f7b10:  c2 24 80 00  st  %g1, [ %l2 ]
a00f7b14:  e0 02 40 00  ld  [ %o1 ], %l0
a00f7b18:  96 2c 00 08  andn  %l0, %o0, %o3
a00f7b1c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00f7b20:  da 22 40 00  st  %o5, [ %o1 ]
a00f7b24:  9e 15 63 30  or  %l5, 0x330, %o7
a00f7b28:  e8 03 c0 00  ld  [ %o7 ], %l4
a00f7b2c:  a6 0d 3f fd  and  %l4, -3, %l3
a00f7b30:  25 33 c0 3b  sethi  %hi(0xcf00ec00), %l2
a00f7b34:  e6 23 c0 00  st  %l3, [ %o7 ]
a00f7b38:  a2 15 63 34  or  %l5, 0x334, %l1
a00f7b3c:  d4 24 40 00  st  %o2, [ %l1 ]
a00f7b40:  96 14 a3 3c  or  %l2, 0x33c, %o3
a00f7b44:  98 10 20 00  clr  %o4
a00f7b48:  9a 10 20 00  clr  %o5
a00f7b4c:  82 14 a3 38  or  %l2, 0x338, %g1
a00f7b50:  da 20 40 00  st  %o5, [ %g1 ]
a00f7b54:  98 03 20 01  inc  %o4
a00f7b58:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f7b5c:  c0 22 c0 00  clr  [ %o3 ]
a00f7b60:  80 a3 60 17  cmp  %o5, 0x17
a00f7b64:  08 bf ff fb  bleu  0xa00f7b50
a00f7b68:  2b 33 c0 3b  sethi  %hi(0xcf00ec00), %l5
a00f7b6c:  a0 15 63 30  or  %l5, 0x330, %l0	! 0xcf00ef30
a00f7b70:  de 04 00 00  ld  [ %l0 ], %o7
a00f7b74:  a2 13 e0 02  or  %o7, 2, %l1
a00f7b78:  e2 24 00 00  st  %l1, [ %l0 ]
a00f7b7c:  c2 04 00 00  ld  [ %l0 ], %g1
a00f7b80:  a4 08 7f fd  and  %g1, -3, %l2
a00f7b84:  96 15 63 34  or  %l5, 0x334, %o3
a00f7b88:  e4 24 00 00  st  %l2, [ %l0 ]
a00f7b8c:  90 10 20 02  mov  2, %o0
a00f7b90:  d0 22 c0 00  st  %o0, [ %o3 ]
a00f7b94:  96 15 63 3c  or  %l5, 0x33c, %o3
a00f7b98:  9a 10 20 00  clr  %o5
a00f7b9c:  82 10 20 00  clr  %g1
a00f7ba0:  94 15 63 38  or  %l5, 0x338, %o2
a00f7ba4:  98 10 20 80  mov  0x80, %o4
a00f7ba8:  c2 22 80 00  st  %g1, [ %o2 ]
a00f7bac:  9a 03 60 01  inc  %o5
a00f7bb0:  82 0b 60 ff  and  %o5, 0xff, %g1
a00f7bb4:  d8 22 c0 00  st  %o4, [ %o3 ]
a00f7bb8:  80 a0 60 17  cmp  %g1, 0x17
a00f7bbc:  08 bf ff fb  bleu  0xa00f7ba8
a00f7bc0:  27 33 c0 3b  sethi  %hi(0xcf00ec00), %l3
a00f7bc4:  98 14 e3 30  or  %l3, 0x330, %o4	! 0xcf00ef30
a00f7bc8:  ea 03 00 00  ld  [ %o4 ], %l5
a00f7bcc:  9a 15 60 02  or  %l5, 2, %o5
a00f7bd0:  da 23 00 00  st  %o5, [ %o4 ]
a00f7bd4:  d2 03 00 00  ld  [ %o4 ], %o1
a00f7bd8:  94 0a 7f fd  and  %o1, -3, %o2
a00f7bdc:  d4 23 00 00  st  %o2, [ %o4 ]
a00f7be0:  a8 14 e3 34  or  %l3, 0x334, %l4
a00f7be4:  c0 25 00 00  clr  [ %l4 ]
a00f7be8:  94 14 e3 3c  or  %l3, 0x33c, %o2
a00f7bec:  9a 10 20 00  clr  %o5
a00f7bf0:  82 10 20 00  clr  %g1
a00f7bf4:  96 14 e3 38  or  %l3, 0x338, %o3
a00f7bf8:  98 10 20 80  mov  0x80, %o4
a00f7bfc:  c2 22 c0 00  st  %g1, [ %o3 ]
a00f7c00:  9a 03 60 01  inc  %o5
a00f7c04:  82 0b 60 ff  and  %o5, 0xff, %g1
a00f7c08:  d8 22 80 00  st  %o4, [ %o2 ]
a00f7c0c:  80 a0 60 10  cmp  %g1, 0x10
a00f7c10:  08 bf ff fb  bleu  0xa00f7bfc
a00f7c14:  01 00 00 00  nop
a00f7c18:  15 33 c0 3b  sethi  %hi(0xcf00ec00), %o2
a00f7c1c:  96 12 a3 30  or  %o2, 0x330, %o3	! 0xcf00ef30
a00f7c20:  e8 02 c0 00  ld  [ %o3 ], %l4
a00f7c24:  a6 15 20 02  or  %l4, 2, %l3
a00f7c28:  e6 22 c0 00  st  %l3, [ %o3 ]
a00f7c2c:  a8 12 a3 00  or  %o2, 0x300, %l4
a00f7c30:  de 05 00 00  ld  [ %l4 ], %o7
a00f7c34:  a2 0b ff bf  and  %o7, -65, %l1
a00f7c38:  e2 25 00 00  st  %l1, [ %l4 ]
a00f7c3c:  c2 05 00 00  ld  [ %l4 ], %g1
a00f7c40:  a4 08 7f df  and  %g1, -33, %l2
a00f7c44:  e4 25 00 00  st  %l2, [ %l4 ]
a00f7c48:  e0 05 00 00  ld  [ %l4 ], %l0
a00f7c4c:  90 0c 3f ef  and  %l0, -17, %o0
a00f7c50:  d0 25 00 00  st  %o0, [ %l4 ]
a00f7c54:  ea 05 00 00  ld  [ %l4 ], %l5
a00f7c58:  9a 0d 7f f7  and  %l5, -9, %o5
a00f7c5c:  da 25 00 00  st  %o5, [ %l4 ]
a00f7c60:  d2 05 00 00  ld  [ %l4 ], %o1
a00f7c64:  98 0a 7f fb  and  %o1, -5, %o4
a00f7c68:  d8 25 00 00  st  %o4, [ %l4 ]
a00f7c6c:  e6 02 c0 00  ld  [ %o3 ], %l3
a00f7c70:  9e 0c ff 7f  and  %l3, -129, %o7
a00f7c74:  de 22 c0 00  st  %o7, [ %o3 ]
a00f7c78:  e2 02 c0 00  ld  [ %o3 ], %l1
a00f7c7c:  82 0c 7f bf  and  %l1, -65, %g1
a00f7c80:  c2 22 c0 00  st  %g1, [ %o3 ]
a00f7c84:  e4 02 c0 00  ld  [ %o3 ], %l2
a00f7c88:  a0 0c bf ef  and  %l2, -17, %l0
a00f7c8c:  e0 22 c0 00  st  %l0, [ %o3 ]
a00f7c90:  d0 02 c0 00  ld  [ %o3 ], %o0
a00f7c94:  80 8a 20 e0  btst  0xe0, %o0
a00f7c98:  32 80 00 06  bne,a   0xa00f7cb0
a00f7c9c:  d6 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %o3
a00f7ca0:  d2 02 c0 00  ld  [ %o3 ], %o1
a00f7ca4:  98 0a 7f fe  and  %o1, -2, %o4
a00f7ca8:  d8 22 c0 00  st  %o4, [ %o3 ]
a00f7cac:  d6 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %o3
a00f7cb0:  80 a2 e0 02  cmp  %o3, 2
a00f7cb4:  02 80 00 0e  be  0xa00f7cec
a00f7cb8:  a2 12 a0 84  or  %o2, 0x84, %l1
a00f7cbc:  e6 04 40 00  ld  [ %l1 ], %l3
a00f7cc0:  9e 0c e0 fc  and  %l3, 0xfc, %o7
a00f7cc4:  82 13 e0 02  or  %o7, 2, %g1
a00f7cc8:  25 33 c0 3a  sethi  %hi(0xcf00e800), %l2
a00f7ccc:  c2 24 40 00  st  %g1, [ %l1 ]
a00f7cd0:  9a 14 a1 80  or  %l2, 0x180, %o5
a00f7cd4:  e0 03 40 00  ld  [ %o5 ], %l0
a00f7cd8:  90 0c 20 fc  and  %l0, 0xfc, %o0
a00f7cdc:  aa 12 20 02  or  %o0, 2, %l5
a00f7ce0:  ea 23 40 00  st  %l5, [ %o5 ]
a00f7ce4:  94 10 20 02  mov  2, %o2
a00f7ce8:  d4 2d a3 b4  stb  %o2, [ %l6 + 0x3b4 ]
a00f7cec:  92 10 20 02  mov  2, %o1
a00f7cf0:  96 10 20 ff  mov  0xff, %o3
a00f7cf4:  90 10 20 01  mov  1, %o0
a00f7cf8:  7f ff fc bb  call  0xa00f6fe4
a00f7cfc:  94 10 20 00  clr  %o2
a00f7d00:  e8 0f bf f2  ldub  [ %fp + -14 ], %l4
a00f7d04:  d2 17 bf f0  lduh  [ %fp + -16 ], %o1
a00f7d08:  d2 37 bf e8  sth  %o1, [ %fp + -24 ]
a00f7d0c:  e8 2f bf ea  stb  %l4, [ %fp + -22 ]
a00f7d10:  80 a5 20 08  cmp  %l4, 8
a00f7d14:  02 80 02 78  be  0xa00f86f4
a00f7d18:  96 10 20 00  clr  %o3
a00f7d1c:  80 a5 20 08  cmp  %l4, 8
a00f7d20:  04 80 00 06  ble  0xa00f7d38
a00f7d24:  25 33 c0 3b  sethi  %hi(0xcf00ec00), %l2
a00f7d28:  80 a5 20 10  cmp  %l4, 0x10
a00f7d2c:  22 80 00 03  be,a   0xa00f7d38
a00f7d30:  96 10 20 02  mov  2, %o3
a00f7d34:  25 33 c0 3b  sethi  %hi(0xcf00ec00), %l2
a00f7d38:  a2 14 a2 80  or  %l2, 0x280, %l1	! 0xcf00ee80
a00f7d3c:  d0 04 40 00  ld  [ %l1 ], %o0
a00f7d40:  d2 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %o1
a00f7d44:  9a 02 40 09  add  %o1, %o1, %o5
a00f7d48:  94 0a 20 f9  and  %o0, 0xf9, %o2
a00f7d4c:  aa 12 80 0d  or  %o2, %o5, %l5
a00f7d50:  ea 24 40 00  st  %l5, [ %l1 ]
a00f7d54:  aa 14 a2 c0  or  %l2, 0x2c0, %l5
a00f7d58:  c2 05 40 00  ld  [ %l5 ], %g1
a00f7d5c:  d8 0f bf e8  ldub  [ %fp + -24 ], %o4
a00f7d60:  a6 08 60 3a  and  %g1, 0x3a, %l3
a00f7d64:  de 0f bf e9  ldub  [ %fp + -23 ], %o7
a00f7d68:  a9 2b 20 07  sll  %o4, 7, %l4
a00f7d6c:  90 14 c0 14  or  %l3, %l4, %o0
a00f7d70:  a1 2b e0 06  sll  %o7, 6, %l0
a00f7d74:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00f7d78:  96 12 00 10  or  %o0, %l0, %o3
a00f7d7c:  95 2b 60 02  sll  %o5, 2, %o2
a00f7d80:  98 12 c0 0a  or  %o3, %o2, %o4
a00f7d84:  d8 25 40 00  st  %o4, [ %l5 ]
a00f7d88:  d4 0f bf ea  ldub  [ %fp + -22 ], %o2
a00f7d8c:  7f ff 9c f9  call  0xa00df170
a00f7d90:  90 17 63 c0  or  %i5, 0x3c0, %o0
a00f7d94:  d2 04 40 00  ld  [ %l1 ], %o1
a00f7d98:  e8 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %l4
a00f7d9c:  a6 0a 60 f9  and  %o1, 0xf9, %l3
a00f7da0:  82 05 00 14  add  %l4, %l4, %g1
a00f7da4:  9e 14 c0 01  or  %l3, %g1, %o7
a00f7da8:  de 24 40 00  st  %o7, [ %l1 ]
a00f7dac:  e0 05 40 00  ld  [ %l5 ], %l0
a00f7db0:  90 0c 3f df  and  %l0, -33, %o0
a00f7db4:  d0 25 40 00  st  %o0, [ %l5 ]
a00f7db8:  98 14 a2 c4  or  %l2, 0x2c4, %o4
a00f7dbc:  da 03 00 00  ld  [ %o4 ], %o5
a00f7dc0:  94 0b 60 0f  and  %o5, 0xf, %o2
a00f7dc4:  a8 12 a0 50  or  %o2, 0x50, %l4
a00f7dc8:  aa 10 00 12  mov  %l2, %l5
a00f7dcc:  96 0d 20 ff  and  %l4, 0xff, %o3
a00f7dd0:  d6 23 00 00  st  %o3, [ %o4 ]
a00f7dd4:  a6 15 e3 78  or  %l7, 0x378, %l3
a00f7dd8:  a2 10 20 00  clr  %l1
a00f7ddc:  a0 10 20 00  clr  %l0
a00f7de0:  a4 14 a2 c8  or  %l2, 0x2c8, %l2
a00f7de4:  82 04 00 10  add  %l0, %l0, %g1
a00f7de8:  a0 00 40 13  add  %g1, %l3, %l0
a00f7dec:  d8 0c 20 03  ldub  [ %l0 + 3 ], %o4
a00f7df0:  d8 24 80 00  st  %o4, [ %l2 ]
a00f7df4:  7f ff ec 20  call  0xa00f2e74
a00f7df8:  01 00 00 00  nop
a00f7dfc:  de 14 20 02  lduh  [ %l0 + 2 ], %o7
a00f7e00:  97 33 e0 08  srl  %o7, 8, %o3
a00f7e04:  d6 24 80 00  st  %o3, [ %l2 ]
a00f7e08:  7f ff ec 1b  call  0xa00f2e74
a00f7e0c:  a2 04 60 01  inc  %l1
a00f7e10:  d2 0c c0 00  ldub  [ %l3 ], %o1
a00f7e14:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00f7e18:  80 a2 40 10  cmp  %o1, %l0
a00f7e1c:  1a bf ff f3  bcc  0xa00f7de8
a00f7e20:  82 04 00 10  add  %l0, %l0, %g1
a00f7e24:  92 15 3f 90  or  %l4, -112, %o1
a00f7e28:  90 0a 60 ff  and  %o1, 0xff, %o0
a00f7e2c:  a4 15 62 c4  or  %l5, 0x2c4, %l2
a00f7e30:  d0 24 80 00  st  %o0, [ %l2 ]
a00f7e34:  67 fe 59 1c  call  0x4008e2a4
a00f7e38:  01 00 00 00  nop
a00f7e3c:  e6 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %l3
a00f7e40:  98 04 e0 04  add  %l3, 4, %o4
a00f7e44:  90 15 62 80  or  %l5, 0x280, %o0
a00f7e48:  a6 10 20 01  mov  1, %l3
a00f7e4c:  da 02 00 00  ld  [ %o0 ], %o5
a00f7e50:  9f 2c c0 0c  sll  %l3, %o4, %o7
a00f7e54:  94 13 40 0f  or  %o5, %o7, %o2
a00f7e58:  a8 0a a0 ff  and  %o2, 0xff, %l4
a00f7e5c:  e8 22 00 00  st  %l4, [ %o0 ]
a00f7e60:  e2 04 80 00  ld  [ %l2 ], %l1
a00f7e64:  82 0c 7f 7f  and  %l1, -129, %g1
a00f7e68:  c2 24 80 00  st  %g1, [ %l2 ]
a00f7e6c:  e0 02 00 00  ld  [ %o0 ], %l0
a00f7e70:  96 2c 00 0f  andn  %l0, %o7, %o3
a00f7e74:  92 0a e0 ff  and  %o3, 0xff, %o1
a00f7e78:  d2 22 00 00  st  %o1, [ %o0 ]
a00f7e7c:  a8 15 63 30  or  %l5, 0x330, %l4
a00f7e80:  da 05 00 00  ld  [ %l4 ], %o5
a00f7e84:  94 0b 7f fd  and  %o5, -3, %o2
a00f7e88:  25 33 c0 3b  sethi  %hi(0xcf00ec00), %l2
a00f7e8c:  d4 25 00 00  st  %o2, [ %l4 ]
a00f7e90:  a2 15 63 34  or  %l5, 0x334, %l1
a00f7e94:  e6 24 40 00  st  %l3, [ %l1 ]
a00f7e98:  96 14 a3 3c  or  %l2, 0x33c, %o3
a00f7e9c:  98 10 20 00  clr  %o4
a00f7ea0:  9a 10 20 00  clr  %o5
a00f7ea4:  82 14 a3 38  or  %l2, 0x338, %g1
a00f7ea8:  da 20 40 00  st  %o5, [ %g1 ]
a00f7eac:  98 03 20 01  inc  %o4
a00f7eb0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f7eb4:  c0 22 c0 00  clr  [ %o3 ]
a00f7eb8:  80 a3 60 17  cmp  %o5, 0x17
a00f7ebc:  08 bf ff fb  bleu  0xa00f7ea8
a00f7ec0:  01 00 00 00  nop
a00f7ec4:  2b 33 c0 3b  sethi  %hi(0xcf00ec00), %l5
a00f7ec8:  a0 15 63 30  or  %l5, 0x330, %l0	! 0xcf00ef30
a00f7ecc:  e8 04 00 00  ld  [ %l0 ], %l4
a00f7ed0:  a2 15 20 02  or  %l4, 2, %l1
a00f7ed4:  e2 24 00 00  st  %l1, [ %l0 ]
a00f7ed8:  c2 04 00 00  ld  [ %l0 ], %g1
a00f7edc:  a4 08 7f fd  and  %g1, -3, %l2
a00f7ee0:  96 15 63 34  or  %l5, 0x334, %o3
a00f7ee4:  e4 24 00 00  st  %l2, [ %l0 ]
a00f7ee8:  9e 10 20 02  mov  2, %o7
a00f7eec:  de 22 c0 00  st  %o7, [ %o3 ]
a00f7ef0:  96 15 63 3c  or  %l5, 0x33c, %o3
a00f7ef4:  9a 10 20 00  clr  %o5
a00f7ef8:  82 10 20 00  clr  %g1
a00f7efc:  94 15 63 38  or  %l5, 0x338, %o2
a00f7f00:  98 10 20 80  mov  0x80, %o4
a00f7f04:  c2 22 80 00  st  %g1, [ %o2 ]
a00f7f08:  9a 03 60 01  inc  %o5
a00f7f0c:  82 0b 60 ff  and  %o5, 0xff, %g1
a00f7f10:  d8 22 c0 00  st  %o4, [ %o3 ]
a00f7f14:  80 a0 60 17  cmp  %g1, 0x17
a00f7f18:  08 bf ff fb  bleu  0xa00f7f04
a00f7f1c:  01 00 00 00  nop
a00f7f20:  27 33 c0 3b  sethi  %hi(0xcf00ec00), %l3
a00f7f24:  98 14 e3 30  or  %l3, 0x330, %o4	! 0xcf00ef30
a00f7f28:  ea 03 00 00  ld  [ %o4 ], %l5
a00f7f2c:  92 15 60 02  or  %l5, 2, %o1
a00f7f30:  d2 23 00 00  st  %o1, [ %o4 ]
a00f7f34:  d0 03 00 00  ld  [ %o4 ], %o0
a00f7f38:  9a 0a 3f fd  and  %o0, -3, %o5
a00f7f3c:  da 23 00 00  st  %o5, [ %o4 ]
a00f7f40:  94 14 e3 34  or  %l3, 0x334, %o2
a00f7f44:  c0 22 80 00  clr  [ %o2 ]
a00f7f48:  94 14 e3 3c  or  %l3, 0x33c, %o2
a00f7f4c:  9a 10 20 00  clr  %o5
a00f7f50:  82 10 20 00  clr  %g1
a00f7f54:  96 14 e3 38  or  %l3, 0x338, %o3
a00f7f58:  98 10 20 80  mov  0x80, %o4
a00f7f5c:  c2 22 c0 00  st  %g1, [ %o3 ]
a00f7f60:  9a 03 60 01  inc  %o5
a00f7f64:  82 0b 60 ff  and  %o5, 0xff, %g1
a00f7f68:  d8 22 80 00  st  %o4, [ %o2 ]
a00f7f6c:  80 a0 60 10  cmp  %g1, 0x10
a00f7f70:  08 bf ff fb  bleu  0xa00f7f5c
a00f7f74:  01 00 00 00  nop
a00f7f78:  15 33 c0 3b  sethi  %hi(0xcf00ec00), %o2
a00f7f7c:  96 12 a3 30  or  %o2, 0x330, %o3	! 0xcf00ef30
a00f7f80:  d8 02 c0 00  ld  [ %o3 ], %o4
a00f7f84:  a6 13 20 02  or  %o4, 2, %l3
a00f7f88:  e6 22 c0 00  st  %l3, [ %o3 ]
a00f7f8c:  98 12 a3 00  or  %o2, 0x300, %o4
a00f7f90:  e8 03 00 00  ld  [ %o4 ], %l4
a00f7f94:  a2 0d 3f bf  and  %l4, -65, %l1
a00f7f98:  e2 23 00 00  st  %l1, [ %o4 ]
a00f7f9c:  c2 03 00 00  ld  [ %o4 ], %g1
a00f7fa0:  a4 08 7f df  and  %g1, -33, %l2
a00f7fa4:  e4 23 00 00  st  %l2, [ %o4 ]
a00f7fa8:  e0 03 00 00  ld  [ %o4 ], %l0
a00f7fac:  9e 0c 3f ef  and  %l0, -17, %o7
a00f7fb0:  de 23 00 00  st  %o7, [ %o4 ]
a00f7fb4:  ea 03 00 00  ld  [ %o4 ], %l5
a00f7fb8:  92 0d 7f f7  and  %l5, -9, %o1
a00f7fbc:  d2 23 00 00  st  %o1, [ %o4 ]
a00f7fc0:  d0 03 00 00  ld  [ %o4 ], %o0
a00f7fc4:  9a 0a 3f fb  and  %o0, -5, %o5
a00f7fc8:  da 23 00 00  st  %o5, [ %o4 ]
a00f7fcc:  e6 02 c0 00  ld  [ %o3 ], %l3
a00f7fd0:  a8 0c ff 7f  and  %l3, -129, %l4
a00f7fd4:  e8 22 c0 00  st  %l4, [ %o3 ]
a00f7fd8:  e2 02 c0 00  ld  [ %o3 ], %l1
a00f7fdc:  82 0c 7f bf  and  %l1, -65, %g1
a00f7fe0:  c2 22 c0 00  st  %g1, [ %o3 ]
a00f7fe4:  e4 02 c0 00  ld  [ %o3 ], %l2
a00f7fe8:  a0 0c bf ef  and  %l2, -17, %l0
a00f7fec:  e0 22 c0 00  st  %l0, [ %o3 ]
a00f7ff0:  de 02 c0 00  ld  [ %o3 ], %o7
a00f7ff4:  80 8b e0 e0  btst  0xe0, %o7
a00f7ff8:  32 80 00 06  bne,a   0xa00f8010
a00f7ffc:  d6 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %o3
a00f8000:  d0 02 c0 00  ld  [ %o3 ], %o0
a00f8004:  9a 0a 3f fe  and  %o0, -2, %o5
a00f8008:  da 22 c0 00  st  %o5, [ %o3 ]
a00f800c:  d6 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %o3
a00f8010:  80 a2 e0 01  cmp  %o3, 1
a00f8014:  02 80 00 10  be  0xa00f8054
a00f8018:  90 10 20 01  mov  1, %o0
a00f801c:  a2 12 a0 84  or  %o2, 0x84, %l1
a00f8020:  e6 04 40 00  ld  [ %l1 ], %l3
a00f8024:  a8 0c e0 fc  and  %l3, 0xfc, %l4
a00f8028:  82 15 20 01  or  %l4, 1, %g1
a00f802c:  25 33 c0 3a  sethi  %hi(0xcf00e800), %l2
a00f8030:  c2 24 40 00  st  %g1, [ %l1 ]
a00f8034:  92 14 a1 80  or  %l2, 0x180, %o1
a00f8038:  e0 02 40 00  ld  [ %o1 ], %l0
a00f803c:  9e 0c 20 fc  and  %l0, 0xfc, %o7
a00f8040:  aa 13 e0 01  or  %o7, 1, %l5
a00f8044:  ea 22 40 00  st  %l5, [ %o1 ]
a00f8048:  94 10 20 01  mov  1, %o2
a00f804c:  d4 2d a3 b4  stb  %o2, [ %l6 + 0x3b4 ]
a00f8050:  90 10 20 01  mov  1, %o0
a00f8054:  96 10 20 ff  mov  0xff, %o3
a00f8058:  92 10 20 02  mov  2, %o1
a00f805c:  7f ff fb e2  call  0xa00f6fe4
a00f8060:  94 10 20 00  clr  %o2
a00f8064:  da 0f bf f2  ldub  [ %fp + -14 ], %o5
a00f8068:  d0 17 bf f0  lduh  [ %fp + -16 ], %o0
a00f806c:  d0 37 bf e8  sth  %o0, [ %fp + -24 ]
a00f8070:  da 2f bf ea  stb  %o5, [ %fp + -22 ]
a00f8074:  80 a3 60 08  cmp  %o5, 8
a00f8078:  02 80 01 9b  be  0xa00f86e4
a00f807c:  96 10 20 00  clr  %o3
a00f8080:  80 a3 60 08  cmp  %o5, 8
a00f8084:  04 80 00 06  ble  0xa00f809c
a00f8088:  25 33 c0 3b  sethi  %hi(0xcf00ec00), %l2
a00f808c:  80 a3 60 10  cmp  %o5, 0x10
a00f8090:  22 80 00 03  be,a   0xa00f809c
a00f8094:  96 10 20 02  mov  2, %o3
a00f8098:  25 33 c0 3b  sethi  %hi(0xcf00ec00), %l2
a00f809c:  a2 14 a2 80  or  %l2, 0x280, %l1	! 0xcf00ee80
a00f80a0:  e0 04 40 00  ld  [ %l1 ], %l0
a00f80a4:  d2 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %o1
a00f80a8:  9e 02 40 09  add  %o1, %o1, %o7
a00f80ac:  94 0c 20 f9  and  %l0, 0xf9, %o2
a00f80b0:  aa 12 80 0f  or  %o2, %o7, %l5
a00f80b4:  ea 24 40 00  st  %l5, [ %l1 ]
a00f80b8:  aa 14 a2 c0  or  %l2, 0x2c0, %l5
a00f80bc:  d8 05 40 00  ld  [ %l5 ], %o4
a00f80c0:  da 0f bf e8  ldub  [ %fp + -24 ], %o5
a00f80c4:  82 0b 20 3a  and  %o4, 0x3a, %g1
a00f80c8:  91 2b 60 07  sll  %o5, 7, %o0
a00f80cc:  e6 0f bf e9  ldub  [ %fp + -23 ], %l3
a00f80d0:  a0 10 40 08  or  %g1, %o0, %l0
a00f80d4:  9e 0a e0 ff  and  %o3, 0xff, %o7
a00f80d8:  a9 2c e0 06  sll  %l3, 6, %l4
a00f80dc:  96 14 00 14  or  %l0, %l4, %o3
a00f80e0:  95 2b e0 02  sll  %o7, 2, %o2
a00f80e4:  98 12 c0 0a  or  %o3, %o2, %o4
a00f80e8:  d8 25 40 00  st  %o4, [ %l5 ]
a00f80ec:  d4 0f bf ea  ldub  [ %fp + -22 ], %o2
a00f80f0:  7f ff 9c 20  call  0xa00df170
a00f80f4:  90 17 63 c0  or  %i5, 0x3c0, %o0
a00f80f8:  da 04 40 00  ld  [ %l1 ], %o5
a00f80fc:  d0 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %o0
a00f8100:  a6 0b 60 f9  and  %o5, 0xf9, %l3
a00f8104:  82 02 00 08  add  %o0, %o0, %g1
a00f8108:  a8 14 c0 01  or  %l3, %g1, %l4
a00f810c:  e8 24 40 00  st  %l4, [ %l1 ]
a00f8110:  e0 05 40 00  ld  [ %l5 ], %l0
a00f8114:  9e 0c 3f df  and  %l0, -33, %o7
a00f8118:  de 25 40 00  st  %o7, [ %l5 ]
a00f811c:  98 14 a2 c4  or  %l2, 0x2c4, %o4
a00f8120:  d2 03 00 00  ld  [ %o4 ], %o1
a00f8124:  94 0a 60 0f  and  %o1, 0xf, %o2
a00f8128:  a8 12 a0 50  or  %o2, 0x50, %l4
a00f812c:  aa 10 00 12  mov  %l2, %l5
a00f8130:  96 0d 20 ff  and  %l4, 0xff, %o3
a00f8134:  d6 23 00 00  st  %o3, [ %o4 ]
a00f8138:  a6 15 e3 78  or  %l7, 0x378, %l3
a00f813c:  a2 10 20 00  clr  %l1
a00f8140:  a0 10 20 00  clr  %l0
a00f8144:  a4 14 a2 c8  or  %l2, 0x2c8, %l2
a00f8148:  9a 04 00 10  add  %l0, %l0, %o5
a00f814c:  a0 03 40 13  add  %o5, %l3, %l0
a00f8150:  d0 0c 20 03  ldub  [ %l0 + 3 ], %o0
a00f8154:  d0 24 80 00  st  %o0, [ %l2 ]
a00f8158:  7f ff eb 47  call  0xa00f2e74
a00f815c:  01 00 00 00  nop
a00f8160:  c2 14 20 02  lduh  [ %l0 + 2 ], %g1
a00f8164:  97 30 60 08  srl  %g1, 8, %o3
a00f8168:  d6 24 80 00  st  %o3, [ %l2 ]
a00f816c:  7f ff eb 42  call  0xa00f2e74
a00f8170:  a2 04 60 01  inc  %l1
a00f8174:  d2 0c c0 00  ldub  [ %l3 ], %o1
a00f8178:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00f817c:  80 a2 40 10  cmp  %o1, %l0
a00f8180:  1a bf ff f3  bcc  0xa00f814c
a00f8184:  9a 04 00 10  add  %l0, %l0, %o5
a00f8188:  92 15 3f 90  or  %l4, -112, %o1
a00f818c:  9e 0a 60 ff  and  %o1, 0xff, %o7
a00f8190:  a0 15 62 c4  or  %l5, 0x2c4, %l0
a00f8194:  de 24 00 00  st  %o7, [ %l0 ]
a00f8198:  67 fe 58 43  call  0x4008e2a4
a00f819c:  01 00 00 00  nop
a00f81a0:  e8 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %l4
a00f81a4:  98 05 20 04  add  %l4, 4, %o4
a00f81a8:  9e 15 62 80  or  %l5, 0x280, %o7
a00f81ac:  a8 10 20 01  mov  1, %l4
a00f81b0:  d4 03 c0 00  ld  [ %o7 ], %o2
a00f81b4:  91 2d 00 0c  sll  %l4, %o4, %o0
a00f81b8:  a6 12 80 08  or  %o2, %o0, %l3
a00f81bc:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00f81c0:  e2 23 c0 00  st  %l1, [ %o7 ]
a00f81c4:  e4 04 00 00  ld  [ %l0 ], %l2
a00f81c8:  9a 0c bf 7f  and  %l2, -129, %o5
a00f81cc:  da 24 00 00  st  %o5, [ %l0 ]
a00f81d0:  c2 03 c0 00  ld  [ %o7 ], %g1
a00f81d4:  96 28 40 08  andn  %g1, %o0, %o3
a00f81d8:  92 0a e0 ff  and  %o3, 0xff, %o1
a00f81dc:  d2 23 c0 00  st  %o1, [ %o7 ]
a00f81e0:  a6 15 63 30  or  %l5, 0x330, %l3
a00f81e4:  d4 04 c0 00  ld  [ %l3 ], %o2
a00f81e8:  98 0a bf fd  and  %o2, -3, %o4
a00f81ec:  d8 24 c0 00  st  %o4, [ %l3 ]
a00f81f0:  25 33 c0 3b  sethi  %hi(0xcf00ec00), %l2
a00f81f4:  a2 15 63 34  or  %l5, 0x334, %l1
a00f81f8:  e8 24 40 00  st  %l4, [ %l1 ]
a00f81fc:  96 14 a3 3c  or  %l2, 0x33c, %o3
a00f8200:  98 10 20 00  clr  %o4
a00f8204:  9a 10 20 00  clr  %o5
a00f8208:  82 14 a3 38  or  %l2, 0x338, %g1
a00f820c:  da 20 40 00  st  %o5, [ %g1 ]
a00f8210:  98 03 20 01  inc  %o4
a00f8214:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f8218:  c0 22 c0 00  clr  [ %o3 ]
a00f821c:  80 a3 60 17  cmp  %o5, 0x17
a00f8220:  08 bf ff fb  bleu  0xa00f820c
a00f8224:  01 00 00 00  nop
a00f8228:  2b 33 c0 3b  sethi  %hi(0xcf00ec00), %l5
a00f822c:  a0 15 63 30  or  %l5, 0x330, %l0	! 0xcf00ef30
a00f8230:  e2 04 00 00  ld  [ %l0 ], %l1
a00f8234:  a4 14 60 02  or  %l1, 2, %l2
a00f8238:  e4 24 00 00  st  %l2, [ %l0 ]
a00f823c:  da 04 00 00  ld  [ %l0 ], %o5
a00f8240:  82 0b 7f fd  and  %o5, -3, %g1
a00f8244:  c2 24 00 00  st  %g1, [ %l0 ]
a00f8248:  96 15 63 34  or  %l5, 0x334, %o3
a00f824c:  90 10 20 02  mov  2, %o0
a00f8250:  d0 22 c0 00  st  %o0, [ %o3 ]
a00f8254:  96 15 63 3c  or  %l5, 0x33c, %o3
a00f8258:  9a 10 20 00  clr  %o5
a00f825c:  82 10 20 00  clr  %g1
a00f8260:  94 15 63 38  or  %l5, 0x338, %o2
a00f8264:  98 10 20 80  mov  0x80, %o4
a00f8268:  c2 22 80 00  st  %g1, [ %o2 ]
a00f826c:  9a 03 60 01  inc  %o5
a00f8270:  82 0b 60 ff  and  %o5, 0xff, %g1
a00f8274:  d8 22 c0 00  st  %o4, [ %o3 ]
a00f8278:  80 a0 60 17  cmp  %g1, 0x17
a00f827c:  08 bf ff fb  bleu  0xa00f8268
a00f8280:  01 00 00 00  nop
a00f8284:  27 33 c0 3b  sethi  %hi(0xcf00ec00), %l3
a00f8288:  98 14 e3 30  or  %l3, 0x330, %o4	! 0xcf00ef30
a00f828c:  ea 03 00 00  ld  [ %o4 ], %l5
a00f8290:  92 15 60 02  or  %l5, 2, %o1
a00f8294:  d2 23 00 00  st  %o1, [ %o4 ]
a00f8298:  de 03 00 00  ld  [ %o4 ], %o7
a00f829c:  a8 0b ff fd  and  %o7, -3, %l4
a00f82a0:  e8 23 00 00  st  %l4, [ %o4 ]
a00f82a4:  94 14 e3 34  or  %l3, 0x334, %o2
a00f82a8:  c0 22 80 00  clr  [ %o2 ]
a00f82ac:  94 14 e3 3c  or  %l3, 0x33c, %o2
a00f82b0:  9a 10 20 00  clr  %o5
a00f82b4:  82 10 20 00  clr  %g1
a00f82b8:  96 14 e3 38  or  %l3, 0x338, %o3
a00f82bc:  98 10 20 80  mov  0x80, %o4
a00f82c0:  c2 22 c0 00  st  %g1, [ %o3 ]
a00f82c4:  9a 03 60 01  inc  %o5
a00f82c8:  82 0b 60 ff  and  %o5, 0xff, %g1
a00f82cc:  d8 22 80 00  st  %o4, [ %o2 ]
a00f82d0:  80 a0 60 10  cmp  %g1, 0x10
a00f82d4:  08 bf ff fb  bleu  0xa00f82c0
a00f82d8:  01 00 00 00  nop
a00f82dc:  15 33 c0 3b  sethi  %hi(0xcf00ec00), %o2
a00f82e0:  96 12 a3 30  or  %o2, 0x330, %o3	! 0xcf00ef30
a00f82e4:  d8 02 c0 00  ld  [ %o3 ], %o4
a00f82e8:  a6 13 20 02  or  %o4, 2, %l3
a00f82ec:  e6 22 c0 00  st  %l3, [ %o3 ]
a00f82f0:  98 12 a3 00  or  %o2, 0x300, %o4
a00f82f4:  e2 03 00 00  ld  [ %o4 ], %l1
a00f82f8:  a4 0c 7f bf  and  %l1, -65, %l2
a00f82fc:  e4 23 00 00  st  %l2, [ %o4 ]
a00f8300:  da 03 00 00  ld  [ %o4 ], %o5
a00f8304:  82 0b 7f df  and  %o5, -33, %g1
a00f8308:  c2 23 00 00  st  %g1, [ %o4 ]
a00f830c:  e0 03 00 00  ld  [ %o4 ], %l0
a00f8310:  90 0c 3f ef  and  %l0, -17, %o0
a00f8314:  d0 23 00 00  st  %o0, [ %o4 ]
a00f8318:  ea 03 00 00  ld  [ %o4 ], %l5
a00f831c:  92 0d 7f f7  and  %l5, -9, %o1
a00f8320:  d2 23 00 00  st  %o1, [ %o4 ]
a00f8324:  de 03 00 00  ld  [ %o4 ], %o7
a00f8328:  a8 0b ff fb  and  %o7, -5, %l4
a00f832c:  e8 23 00 00  st  %l4, [ %o4 ]
a00f8330:  e6 02 c0 00  ld  [ %o3 ], %l3
a00f8334:  a2 0c ff 7f  and  %l3, -129, %l1
a00f8338:  e2 22 c0 00  st  %l1, [ %o3 ]
a00f833c:  e4 02 c0 00  ld  [ %o3 ], %l2
a00f8340:  9a 0c bf bf  and  %l2, -65, %o5
a00f8344:  da 22 c0 00  st  %o5, [ %o3 ]
a00f8348:  c2 02 c0 00  ld  [ %o3 ], %g1
a00f834c:  a0 08 7f ef  and  %g1, -17, %l0
a00f8350:  e0 22 c0 00  st  %l0, [ %o3 ]
a00f8354:  d0 02 c0 00  ld  [ %o3 ], %o0
a00f8358:  80 8a 20 e0  btst  0xe0, %o0
a00f835c:  32 80 00 06  bne,a   0xa00f8374
a00f8360:  d6 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %o3
a00f8364:  de 02 c0 00  ld  [ %o3 ], %o7
a00f8368:  a8 0b ff fe  and  %o7, -2, %l4
a00f836c:  e8 22 c0 00  st  %l4, [ %o3 ]
a00f8370:  d6 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %o3
a00f8374:  80 a2 e0 00  cmp  %o3, 0
a00f8378:  22 80 00 0d  be,a   0xa00f83ac
a00f837c:  96 10 20 ff  mov  0xff, %o3
a00f8380:  a0 12 a0 84  or  %o2, 0x84, %l0
a00f8384:  da 04 00 00  ld  [ %l0 ], %o5
a00f8388:  82 0b 60 fc  and  %o5, 0xfc, %g1
a00f838c:  11 33 c0 3a  sethi  %hi(0xcf00e800), %o0
a00f8390:  c2 24 00 00  st  %g1, [ %l0 ]
a00f8394:  94 12 21 80  or  %o0, 0x180, %o2
a00f8398:  ea 02 80 00  ld  [ %o2 ], %l5
a00f839c:  92 0d 60 fc  and  %l5, 0xfc, %o1
a00f83a0:  d2 22 80 00  st  %o1, [ %o2 ]
a00f83a4:  c0 2d a3 b4  clrb  [ %l6 + 0x3b4 ]
a00f83a8:  96 10 20 ff  mov  0xff, %o3
a00f83ac:  90 10 20 01  mov  1, %o0
a00f83b0:  92 10 20 02  mov  2, %o1
a00f83b4:  7f ff fb 0c  call  0xa00f6fe4
a00f83b8:  94 10 20 00  clr  %o2
a00f83bc:  e4 0f bf f2  ldub  [ %fp + -14 ], %l2
a00f83c0:  e2 17 bf f0  lduh  [ %fp + -16 ], %l1
a00f83c4:  e2 37 bf e8  sth  %l1, [ %fp + -24 ]
a00f83c8:  e4 2f bf ea  stb  %l2, [ %fp + -22 ]
a00f83cc:  80 a4 a0 08  cmp  %l2, 8
a00f83d0:  02 80 00 c7  be  0xa00f86ec
a00f83d4:  96 10 20 00  clr  %o3
a00f83d8:  80 a4 a0 08  cmp  %l2, 8
a00f83dc:  24 80 00 06  ble,a   0xa00f83f4
a00f83e0:  25 33 c0 3b  sethi  %hi(0xcf00ec00), %l2
a00f83e4:  80 a4 a0 10  cmp  %l2, 0x10
a00f83e8:  22 80 00 02  be,a   0xa00f83f0
a00f83ec:  96 10 20 02  mov  2, %o3
a00f83f0:  25 33 c0 3b  sethi  %hi(0xcf00ec00), %l2
a00f83f4:  a0 14 a2 80  or  %l2, 0x280, %l0	! 0xcf00ee80
a00f83f8:  de 04 00 00  ld  [ %l0 ], %o7
a00f83fc:  d2 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %o1
a00f8400:  a8 02 40 09  add  %o1, %o1, %l4
a00f8404:  98 0b e0 f9  and  %o7, 0xf9, %o4
a00f8408:  aa 13 00 14  or  %o4, %l4, %l5
a00f840c:  ea 24 00 00  st  %l5, [ %l0 ]
a00f8410:  aa 14 a2 c0  or  %l2, 0x2c0, %l5
a00f8414:  e6 05 40 00  ld  [ %l5 ], %l3
a00f8418:  e2 0f bf e8  ldub  [ %fp + -24 ], %l1
a00f841c:  82 0c e0 3a  and  %l3, 0x3a, %g1
a00f8420:  9b 2c 60 07  sll  %l1, 7, %o5
a00f8424:  d0 0f bf e9  ldub  [ %fp + -23 ], %o0
a00f8428:  9e 10 40 0d  or  %g1, %o5, %o7
a00f842c:  a8 0a e0 ff  and  %o3, 0xff, %l4
a00f8430:  95 2a 20 06  sll  %o0, 6, %o2
a00f8434:  a6 13 c0 0a  or  %o7, %o2, %l3
a00f8438:  99 2d 20 02  sll  %l4, 2, %o4
a00f843c:  a2 14 c0 0c  or  %l3, %o4, %l1
a00f8440:  e2 25 40 00  st  %l1, [ %l5 ]
a00f8444:  90 17 63 c0  or  %i5, 0x3c0, %o0
a00f8448:  7f ff 9b 4a  call  0xa00df170
a00f844c:  d4 0f bf ea  ldub  [ %fp + -22 ], %o2
a00f8450:  da 04 00 00  ld  [ %l0 ], %o5
a00f8454:  c2 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %g1
a00f8458:  92 0b 60 f9  and  %o5, 0xf9, %o1
a00f845c:  90 00 40 01  add  %g1, %g1, %o0
a00f8460:  94 12 40 08  or  %o1, %o0, %o2
a00f8464:  d4 24 00 00  st  %o2, [ %l0 ]
a00f8468:  d6 05 40 00  ld  [ %l5 ], %o3
a00f846c:  9e 0a ff df  and  %o3, -33, %o7
a00f8470:  de 25 40 00  st  %o7, [ %l5 ]
a00f8474:  ba 14 a2 c4  or  %l2, 0x2c4, %i5
a00f8478:  e8 07 40 00  ld  [ %i5 ], %l4
a00f847c:  98 0d 20 0f  and  %l4, 0xf, %o4
a00f8480:  a8 13 20 50  or  %o4, 0x50, %l4
a00f8484:  a6 0d 20 ff  and  %l4, 0xff, %l3
a00f8488:  aa 10 00 12  mov  %l2, %l5
a00f848c:  e6 27 40 00  st  %l3, [ %i5 ]
a00f8490:  a6 15 e3 78  or  %l7, 0x378, %l3
a00f8494:  a2 10 20 00  clr  %l1
a00f8498:  a0 10 20 00  clr  %l0
a00f849c:  a4 14 a2 c8  or  %l2, 0x2c8, %l2
a00f84a0:  94 04 00 10  add  %l0, %l0, %o2
a00f84a4:  a0 02 80 13  add  %o2, %l3, %l0
a00f84a8:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a00f84ac:  d2 24 80 00  st  %o1, [ %l2 ]
a00f84b0:  7f ff ea 71  call  0xa00f2e74
a00f84b4:  01 00 00 00  nop
a00f84b8:  d6 14 20 02  lduh  [ %l0 + 2 ], %o3
a00f84bc:  bb 32 e0 08  srl  %o3, 8, %i5
a00f84c0:  fa 24 80 00  st  %i5, [ %l2 ]
a00f84c4:  7f ff ea 6c  call  0xa00f2e74
a00f84c8:  a2 04 60 01  inc  %l1
a00f84cc:  ee 0c c0 00  ldub  [ %l3 ], %l7
a00f84d0:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00f84d4:  80 a5 c0 10  cmp  %l7, %l0
a00f84d8:  1a bf ff f3  bcc  0xa00f84a4
a00f84dc:  94 04 00 10  add  %l0, %l0, %o2
a00f84e0:  82 15 3f 90  or  %l4, -112, %g1
a00f84e4:  9a 08 60 ff  and  %g1, 0xff, %o5
a00f84e8:  ba 15 62 c4  or  %l5, 0x2c4, %i5
a00f84ec:  da 27 40 00  st  %o5, [ %i5 ]
a00f84f0:  67 fe 57 6d  call  0x4008e2a4
a00f84f4:  a6 15 62 80  or  %l5, 0x280, %l3
a00f84f8:  d0 0d a3 b4  ldub  [ %l6 + 0x3b4 ], %o0
a00f84fc:  a4 02 20 04  add  %o0, 4, %l2
a00f8500:  90 10 20 01  mov  1, %o0
a00f8504:  ec 04 c0 00  ld  [ %l3 ], %l6
a00f8508:  9f 2a 00 12  sll  %o0, %l2, %o7
a00f850c:  94 15 80 0f  or  %l6, %o7, %o2
a00f8510:  92 0a a0 ff  and  %o2, 0xff, %o1
a00f8514:  d2 24 c0 00  st  %o1, [ %l3 ]
a00f8518:  e0 07 40 00  ld  [ %i5 ], %l0
a00f851c:  96 0c 3f 7f  and  %l0, -129, %o3
a00f8520:  d6 27 40 00  st  %o3, [ %i5 ]
a00f8524:  ee 04 c0 00  ld  [ %l3 ], %l7
a00f8528:  a8 2d c0 0f  andn  %l7, %o7, %l4
a00f852c:  98 0d 20 ff  and  %l4, 0xff, %o4
a00f8530:  d8 24 c0 00  st  %o4, [ %l3 ]
a00f8534:  9a 15 63 30  or  %l5, 0x330, %o5
a00f8538:  e2 03 40 00  ld  [ %o5 ], %l1
a00f853c:  82 0c 7f fd  and  %l1, -3, %g1
a00f8540:  c2 23 40 00  st  %g1, [ %o5 ]
a00f8544:  2d 33 c0 3b  sethi  %hi(0xcf00ec00), %l6
a00f8548:  a4 15 63 34  or  %l5, 0x334, %l2
a00f854c:  d0 24 80 00  st  %o0, [ %l2 ]
a00f8550:  96 15 a3 3c  or  %l6, 0x33c, %o3
a00f8554:  98 10 20 00  clr  %o4
a00f8558:  9a 10 20 00  clr  %o5
a00f855c:  82 15 a3 38  or  %l6, 0x338, %g1
a00f8560:  da 20 40 00  st  %o5, [ %g1 ]
a00f8564:  98 03 20 01  inc  %o4
a00f8568:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f856c:  c0 22 c0 00  clr  [ %o3 ]
a00f8570:  80 a3 60 17  cmp  %o5, 0x17
a00f8574:  08 bf ff fb  bleu  0xa00f8560
a00f8578:  01 00 00 00  nop
a00f857c:  2b 33 c0 3b  sethi  %hi(0xcf00ec00), %l5
a00f8580:  98 15 63 30  or  %l5, 0x330, %o4	! 0xcf00ef30
a00f8584:  fa 03 00 00  ld  [ %o4 ], %i5
a00f8588:  ae 17 60 02  or  %i5, 2, %l7
a00f858c:  ee 23 00 00  st  %l7, [ %o4 ]
a00f8590:  de 03 00 00  ld  [ %o4 ], %o7
a00f8594:  a8 0b ff fd  and  %o7, -3, %l4
a00f8598:  e8 23 00 00  st  %l4, [ %o4 ]
a00f859c:  a2 15 63 34  or  %l5, 0x334, %l1
a00f85a0:  a6 10 20 02  mov  2, %l3
a00f85a4:  e6 24 40 00  st  %l3, [ %l1 ]
a00f85a8:  96 15 63 3c  or  %l5, 0x33c, %o3
a00f85ac:  9a 10 20 00  clr  %o5
a00f85b0:  82 10 20 00  clr  %g1
a00f85b4:  94 15 63 38  or  %l5, 0x338, %o2
a00f85b8:  98 10 20 80  mov  0x80, %o4
a00f85bc:  c2 22 80 00  st  %g1, [ %o2 ]
a00f85c0:  9a 03 60 01  inc  %o5
a00f85c4:  82 0b 60 ff  and  %o5, 0xff, %g1
a00f85c8:  d8 22 c0 00  st  %o4, [ %o3 ]
a00f85cc:  80 a0 60 17  cmp  %g1, 0x17
a00f85d0:  08 bf ff fb  bleu  0xa00f85bc
a00f85d4:  01 00 00 00  nop
a00f85d8:  17 33 c0 3b  sethi  %hi(0xcf00ec00), %o3
a00f85dc:  92 12 e3 30  or  %o3, 0x330, %o1	! 0xcf00ef30
a00f85e0:  d0 02 40 00  ld  [ %o1 ], %o0
a00f85e4:  a4 12 20 02  or  %o0, 2, %l2
a00f85e8:  e4 22 40 00  st  %l2, [ %o1 ]
a00f85ec:  ec 02 40 00  ld  [ %o1 ], %l6
a00f85f0:  94 0d bf fd  and  %l6, -3, %o2
a00f85f4:  d4 22 40 00  st  %o2, [ %o1 ]
a00f85f8:  a0 12 e3 34  or  %o3, 0x334, %l0
a00f85fc:  94 12 e3 3c  or  %o3, 0x33c, %o2
a00f8600:  c0 24 00 00  clr  [ %l0 ]
a00f8604:  9a 10 20 00  clr  %o5
a00f8608:  82 10 20 00  clr  %g1
a00f860c:  96 12 e3 38  or  %o3, 0x338, %o3
a00f8610:  98 10 20 80  mov  0x80, %o4
a00f8614:  c2 22 c0 00  st  %g1, [ %o3 ]
a00f8618:  9a 03 60 01  inc  %o5
a00f861c:  82 0b 60 ff  and  %o5, 0xff, %g1
a00f8620:  d8 22 80 00  st  %o4, [ %o2 ]
a00f8624:  80 a0 60 10  cmp  %g1, 0x10
a00f8628:  08 bf ff fb  bleu  0xa00f8614
a00f862c:  01 00 00 00  nop
a00f8630:  15 33 c0 3b  sethi  %hi(0xcf00ec00), %o2
a00f8634:  96 12 a3 30  or  %o2, 0x330, %o3	! 0xcf00ef30
a00f8638:  e6 02 c0 00  ld  [ %o3 ], %l3
a00f863c:  a2 14 e0 02  or  %l3, 2, %l1
a00f8640:  e2 22 c0 00  st  %l1, [ %o3 ]
a00f8644:  9e 12 a3 00  or  %o2, 0x300, %o7
a00f8648:  ea 03 c0 00  ld  [ %o7 ], %l5
a00f864c:  82 0d 7f bf  and  %l5, -65, %g1
a00f8650:  c2 23 c0 00  st  %g1, [ %o7 ]
a00f8654:  da 03 c0 00  ld  [ %o7 ], %o5
a00f8658:  90 0b 7f df  and  %o5, -33, %o0
a00f865c:  d0 23 c0 00  st  %o0, [ %o7 ]
a00f8660:  e4 03 c0 00  ld  [ %o7 ], %l2
a00f8664:  ac 0c bf ef  and  %l2, -17, %l6
a00f8668:  ec 23 c0 00  st  %l6, [ %o7 ]
a00f866c:  d2 03 c0 00  ld  [ %o7 ], %o1
a00f8670:  a0 0a 7f f7  and  %o1, -9, %l0
a00f8674:  e0 23 c0 00  st  %l0, [ %o7 ]
a00f8678:  fa 03 c0 00  ld  [ %o7 ], %i5
a00f867c:  ae 0f 7f fb  and  %i5, -5, %l7
a00f8680:  ee 23 c0 00  st  %l7, [ %o7 ]
a00f8684:  e8 02 c0 00  ld  [ %o3 ], %l4
a00f8688:  98 0d 3f 7f  and  %l4, -129, %o4
a00f868c:  d8 22 c0 00  st  %o4, [ %o3 ]
a00f8690:  e6 02 c0 00  ld  [ %o3 ], %l3
a00f8694:  a2 0c ff bf  and  %l3, -65, %l1
a00f8698:  e2 22 c0 00  st  %l1, [ %o3 ]
a00f869c:  ea 02 c0 00  ld  [ %o3 ], %l5
a00f86a0:  82 0d 7f ef  and  %l5, -17, %g1
a00f86a4:  c2 22 c0 00  st  %g1, [ %o3 ]
a00f86a8:  da 02 c0 00  ld  [ %o3 ], %o5
a00f86ac:  80 8b 60 e0  btst  0xe0, %o5
a00f86b0:  32 80 00 13  bne,a   0xa00f86fc
a00f86b4:  aa 12 a2 40  or  %o2, 0x240, %l5
a00f86b8:  e8 02 c0 00  ld  [ %o3 ], %l4
a00f86bc:  98 0d 3f fe  and  %l4, -2, %o4
a00f86c0:  d8 22 c0 00  st  %o4, [ %o3 ]
a00f86c4:  10 80 00 0e  b  0xa00f86fc
a00f86c8:  aa 12 a2 40  or  %o2, 0x240, %l5
a00f86cc:  22 bf fc c2  be,a   0xa00f79d4
a00f86d0:  96 10 20 02  mov  2, %o3
a00f86d4:  10 bf fc c1  b  0xa00f79d8
a00f86d8:  25 33 c0 3b  sethi  %hi(0xcf00ec00), %l2
a00f86dc:  10 bf fc be  b  0xa00f79d4
a00f86e0:  96 10 20 01  mov  1, %o3
a00f86e4:  10 bf fe 6d  b  0xa00f8098
a00f86e8:  96 10 20 01  mov  1, %o3
a00f86ec:  10 bf ff 41  b  0xa00f83f0
a00f86f0:  96 10 20 01  mov  1, %o3
a00f86f4:  10 bf fd 90  b  0xa00f7d34
a00f86f8:  96 10 20 01  mov  1, %o3
a00f86fc:  d8 05 40 00  ld  [ %l5 ], %o4
a00f8700:  a6 0b 20 3f  and  %o4, 0x3f, %l3
a00f8704:  e6 25 40 00  st  %l3, [ %l5 ]
a00f8708:  e2 05 40 00  ld  [ %l5 ], %l1
a00f870c:  82 14 60 10  or  %l1, 0x10, %g1
a00f8710:  c2 25 40 00  st  %g1, [ %l5 ]
a00f8714:  ac 12 a2 68  or  %o2, 0x268, %l6
a00f8718:  da 05 80 00  ld  [ %l6 ], %o5
a00f871c:  90 13 60 40  or  %o5, 0x40, %o0
a00f8720:  a4 0a 20 ff  and  %o0, 0xff, %l2
a00f8724:  e4 25 80 00  st  %l2, [ %l6 ]
a00f8728:  a0 12 a2 50  or  %o2, 0x250, %l0
a00f872c:  c0 24 00 00  clr  [ %l0 ]
a00f8730:  a0 12 a0 80  or  %o2, 0x80, %l0
a00f8734:  d2 04 00 00  ld  [ %l0 ], %o1
a00f8738:  ba 0a 60 f3  and  %o1, 0xf3, %i5
a00f873c:  ae 17 60 08  or  %i5, 8, %l7
a00f8740:  ee 24 00 00  st  %l7, [ %l0 ]
a00f8744:  d6 04 00 00  ld  [ %l0 ], %o3
a00f8748:  9e 0a e0 cf  and  %o3, 0xcf, %o7
a00f874c:  a8 13 e0 20  or  %o7, 0x20, %l4
a00f8750:  e8 24 00 00  st  %l4, [ %l0 ]
a00f8754:  9e 12 a0 a8  or  %o2, 0xa8, %o7
a00f8758:  d8 03 c0 00  ld  [ %o7 ], %o4
a00f875c:  a6 0b 20 f3  and  %o4, 0xf3, %l3
a00f8760:  a2 14 e0 08  or  %l3, 8, %l1
a00f8764:  e2 23 c0 00  st  %l1, [ %o7 ]
a00f8768:  ea 03 c0 00  ld  [ %o7 ], %l5
a00f876c:  82 0d 60 cf  and  %l5, 0xcf, %g1
a00f8770:  9a 10 60 20  or  %g1, 0x20, %o5
a00f8774:  da 23 c0 00  st  %o5, [ %o7 ]
a00f8778:  d0 04 00 00  ld  [ %l0 ], %o0
a00f877c:  a4 0a 20 fe  and  %o0, 0xfe, %l2
a00f8780:  e4 24 00 00  st  %l2, [ %l0 ]
a00f8784:  ec 04 00 00  ld  [ %l0 ], %l6
a00f8788:  92 0d a0 fd  and  %l6, 0xfd, %o1
a00f878c:  d2 24 00 00  st  %o1, [ %l0 ]
a00f8790:  fa 03 c0 00  ld  [ %o7 ], %i5
a00f8794:  ae 0f 60 fe  and  %i5, 0xfe, %l7
a00f8798:  ee 23 c0 00  st  %l7, [ %o7 ]
a00f879c:  d4 03 c0 00  ld  [ %o7 ], %o2
a00f87a0:  96 0a a0 fd  and  %o2, 0xfd, %o3
a00f87a4:  d6 23 c0 00  st  %o3, [ %o7 ]
a00f87a8:  81 c7 e0 08  ret
a00f87ac:  81 e8 00 00  restore
