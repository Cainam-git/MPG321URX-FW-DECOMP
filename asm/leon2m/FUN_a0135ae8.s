# leon2m FUN_a0135ae8 0xa0135ae8-0xa0135dc0 (728 bytes)
a0135ae8:  9d e3 bf 70  save  %sp, -144, %sp
a0135aec:  9a 10 20 00  clr  %o5
a0135af0:  98 10 20 00  clr  %o4
a0135af4:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a0135af8:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0135afc:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0135b00:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a0135b04:  80 8e 20 80  btst  0x80, %i0
a0135b08:  9a 10 00 18  mov  %i0, %o5
a0135b0c:  ae 10 20 02  mov  2, %l7
a0135b10:  aa 10 20 10  mov  0x10, %l5
a0135b14:  12 80 00 a4  bne  0xa0135da4
a0135b18:  a2 10 20 00  clr  %l1
a0135b1c:  83 2f 20 10  sll  %i4, 0x10, %g1
a0135b20:  83 30 60 10  srl  %g1, 0x10, %g1
a0135b24:  80 a0 7f fe  cmp  %g1, -2
a0135b28:  a0 10 20 00  clr  %l0
a0135b2c:  02 80 00 7b  be  0xa0135d18
a0135b30:  27 2a 00 b2  sethi  %hi(0xa802c800), %l3
a0135b34:  11 2a 00 b6  sethi  %hi(0xa802d800), %o0
a0135b38:  98 10 00 01  mov  %g1, %o4
a0135b3c:  b0 0b 60 ff  and  %o5, 0xff, %i0
a0135b40:  ac 12 22 6c  or  %o0, 0x26c, %l6
a0135b44:  92 07 bf e8  add  %fp, -24, %o1
a0135b48:  a8 07 bf f8  add  %fp, -8, %l4
a0135b4c:  9e 07 bf d8  add  %fp, -40, %o7
a0135b50:  a4 10 00 01  mov  %g1, %l2
a0135b54:  9b 2c 20 10  sll  %l0, 0x10, %o5
a0135b58:  9b 33 60 10  srl  %o5, 0x10, %o5
a0135b5c:  96 23 00 0d  sub  %o4, %o5, %o3
a0135b60:  94 02 e0 02  add  %o3, 2, %o2
a0135b64:  80 a2 a0 0f  cmp  %o2, 0xf
a0135b68:  14 80 00 05  bg  0xa0135b7c
a0135b6c:  80 a3 60 00  cmp  %o5, 0
a0135b70:  98 27 00 10  sub  %i4, %l0, %o4
a0135b74:  aa 03 20 02  add  %o4, 2, %l5
a0135b78:  ae 10 20 01  mov  1, %l7
a0135b7c:  12 80 00 29  bne  0xa0135c20
a0135b80:  94 03 40 1b  add  %o5, %i3, %o2
a0135b84:  90 0d 60 ff  and  %l5, 0xff, %o0
a0135b88:  94 02 3f fe  add  %o0, -2, %o2
a0135b8c:  80 a3 40 0a  cmp  %o5, %o2
a0135b90:  f2 2f bf d8  stb  %i1, [ %fp + -40 ]
a0135b94:  f4 2f bf d9  stb  %i2, [ %fp + -39 ]
a0135b98:  16 80 00 0a  bge  0xa0135bc0
a0135b9c:  96 10 20 00  clr  %o3
a0135ba0:  98 10 20 00  clr  %o4
a0135ba4:  da 0b 00 1b  ldub  [ %o4 + %i3 ], %o5
a0135ba8:  82 05 00 0c  add  %l4, %o4, %g1
a0135bac:  96 02 e0 01  inc  %o3
a0135bb0:  98 0a e0 ff  and  %o3, 0xff, %o4
a0135bb4:  80 a3 00 0a  cmp  %o4, %o2
a0135bb8:  06 bf ff fb  bl  0xa0135ba4
a0135bbc:  da 28 7f e2  stb  %o5, [ %g1 + -30 ]
a0135bc0:  94 10 20 00  clr  %o2
a0135bc4:  9a 10 20 00  clr  %o5
a0135bc8:  97 2b 60 02  sll  %o5, 2, %o3
a0135bcc:  c2 0b c0 0b  ldub  [ %o7 + %o3 ], %g1
a0135bd0:  c2 22 40 0b  st  %g1, [ %o1 + %o3 ]
a0135bd4:  98 02 c0 0f  add  %o3, %o7, %o4
a0135bd8:  da 0b 20 01  ldub  [ %o4 + 1 ], %o5
a0135bdc:  83 28 60 08  sll  %g1, 8, %g1
a0135be0:  82 00 40 0d  add  %g1, %o5, %g1
a0135be4:  c2 22 40 0b  st  %g1, [ %o1 + %o3 ]
a0135be8:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a0135bec:  83 28 60 08  sll  %g1, 8, %g1
a0135bf0:  82 00 40 0d  add  %g1, %o5, %g1
a0135bf4:  c2 22 40 0b  st  %g1, [ %o1 + %o3 ]
a0135bf8:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a0135bfc:  83 28 60 08  sll  %g1, 8, %g1
a0135c00:  98 00 40 0d  add  %g1, %o5, %o4
a0135c04:  94 02 a0 01  inc  %o2
a0135c08:  9a 0a a0 ff  and  %o2, 0xff, %o5
a0135c0c:  80 a3 60 04  cmp  %o5, 4
a0135c10:  0a bf ff ee  bcs  0xa0135bc8
a0135c14:  d8 22 40 0b  st  %o4, [ %o1 + %o3 ]
a0135c18:  10 80 00 1b  b  0xa0135c84
a0135c1c:  99 2a 20 10  sll  %o0, 0x10, %o4
a0135c20:  90 02 bf fe  add  %o2, -2, %o0
a0135c24:  94 10 20 00  clr  %o2
a0135c28:  9a 10 20 00  clr  %o5
a0135c2c:  97 2b 60 02  sll  %o5, 2, %o3
a0135c30:  c2 0a 00 0b  ldub  [ %o0 + %o3 ], %g1
a0135c34:  c2 22 40 0b  st  %g1, [ %o1 + %o3 ]
a0135c38:  98 02 c0 08  add  %o3, %o0, %o4
a0135c3c:  da 0b 20 01  ldub  [ %o4 + 1 ], %o5
a0135c40:  83 28 60 08  sll  %g1, 8, %g1
a0135c44:  82 00 40 0d  add  %g1, %o5, %g1
a0135c48:  c2 22 40 0b  st  %g1, [ %o1 + %o3 ]
a0135c4c:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a0135c50:  83 28 60 08  sll  %g1, 8, %g1
a0135c54:  82 00 40 0d  add  %g1, %o5, %g1
a0135c58:  c2 22 40 0b  st  %g1, [ %o1 + %o3 ]
a0135c5c:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a0135c60:  83 28 60 08  sll  %g1, 8, %g1
a0135c64:  98 00 40 0d  add  %g1, %o5, %o4
a0135c68:  94 02 a0 01  inc  %o2
a0135c6c:  9a 0a a0 ff  and  %o2, 0xff, %o5
a0135c70:  80 a3 60 04  cmp  %o5, 4
a0135c74:  0a bf ff ee  bcs  0xa0135c2c
a0135c78:  d8 22 40 0b  st  %o4, [ %o1 + %o3 ]
a0135c7c:  90 0d 60 ff  and  %l5, 0xff, %o0
a0135c80:  99 2a 20 10  sll  %o0, 0x10, %o4
a0135c84:  d4 0c e3 97  ldub  [ %l3 + 0x397 ], %o2
a0135c88:  83 2c 60 18  sll  %l1, 0x18, %g1
a0135c8c:  96 0a a0 ff  and  %o2, 0xff, %o3
a0135c90:  90 00 40 0c  add  %g1, %o4, %o0
a0135c94:  9b 2e 20 08  sll  %i0, 8, %o5
a0135c98:  82 02 00 0d  add  %o0, %o5, %g1
a0135c9c:  99 2a e0 02  sll  %o3, 2, %o4
a0135ca0:  90 0d e0 ff  and  %l7, 0xff, %o0
a0135ca4:  98 03 00 0b  add  %o4, %o3, %o4
a0135ca8:  96 00 60 02  add  %g1, 2, %o3
a0135cac:  9b 2a 20 04  sll  %o0, 4, %o5
a0135cb0:  90 02 c0 0d  add  %o3, %o5, %o0
a0135cb4:  99 2b 20 02  sll  %o4, 2, %o4
a0135cb8:  d0 25 80 0c  st  %o0, [ %l6 + %o4 ]
a0135cbc:  96 03 00 16  add  %o4, %l6, %o3
a0135cc0:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a0135cc4:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a0135cc8:  94 02 a0 01  inc  %o2
a0135ccc:  c2 22 e0 10  st  %g1, [ %o3 + 0x10 ]
a0135cd0:  da 22 e0 04  st  %o5, [ %o3 + 4 ]
a0135cd4:  90 0a a0 ff  and  %o2, 0xff, %o0
a0135cd8:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a0135cdc:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a0135ce0:  c2 22 e0 08  st  %g1, [ %o3 + 8 ]
a0135ce4:  80 a2 20 24  cmp  %o0, 0x24
a0135ce8:  08 80 00 2d  bleu  0xa0135d9c
a0135cec:  da 22 e0 0c  st  %o5, [ %o3 + 0xc ]
a0135cf0:  c0 2c e3 97  clrb  [ %l3 + 0x397 ]
a0135cf4:  94 04 20 10  add  %l0, 0x10, %o2
a0135cf8:  91 2a a0 10  sll  %o2, 0x10, %o0
a0135cfc:  a0 04 a0 02  add  %l2, 2, %l0
a0135d00:  97 32 20 10  srl  %o0, 0x10, %o3
a0135d04:  80 a2 c0 10  cmp  %o3, %l0
a0135d08:  a2 04 60 01  inc  %l1
a0135d0c:  a0 10 00 0a  mov  %o2, %l0
a0135d10:  06 bf ff 91  bl  0xa0135b54
a0135d14:  98 10 00 12  mov  %l2, %o4
a0135d18:  c0 27 bf d4  clr  [ %fp + -44 ]
a0135d1c:  10 80 00 04  b  0xa0135d2c
a0135d20:  39 2a 00 b2  sethi  %hi(0xa802c800), %i4
a0135d24:  7f ff fc ee  call  0xa01350dc
a0135d28:  01 00 00 00  nop
a0135d2c:  de 0c e3 97  ldub  [ %l3 + 0x397 ], %o7
a0135d30:  d2 0f 23 96  ldub  [ %i4 + 0x396 ], %o1
a0135d34:  80 a3 c0 09  cmp  %o7, %o1
a0135d38:  12 bf ff fb  bne  0xa0135d24
a0135d3c:  b6 10 20 00  clr  %i3
a0135d40:  b8 10 20 00  clr  %i4
a0135d44:  98 10 20 00  clr  %o4
a0135d48:  b3 2b 20 02  sll  %o4, 2, %i1
a0135d4c:  b0 06 40 0c  add  %i1, %o4, %i0
a0135d50:  af 2e 20 02  sll  %i0, 2, %l7
a0135d54:  ac 05 e0 10  add  %l7, 0x10, %l6
a0135d58:  92 0d a0 fc  and  %l6, 0xfc, %o1
a0135d5c:  90 10 20 00  clr  %o0
a0135d60:  94 07 bf d4  add  %fp, -44, %o2
a0135d64:  67 fd 59 db  call  0x4008c4d0
a0135d68:  96 10 20 01  mov  1, %o3
a0135d6c:  b8 07 20 01  inc  %i4
a0135d70:  98 0f 20 ff  and  %i4, 0xff, %o4
a0135d74:  ab 2b 20 02  sll  %o4, 2, %l5
a0135d78:  a8 05 40 0c  add  %l5, %o4, %l4
a0135d7c:  a7 2d 20 02  sll  %l4, 2, %l3
a0135d80:  a2 04 e0 10  add  %l3, 0x10, %l1
a0135d84:  e4 07 bf d4  ld  [ %fp + -44 ], %l2
a0135d88:  80 a4 60 50  cmp  %l1, 0x50
a0135d8c:  04 bf ff ef  ble  0xa0135d48
a0135d90:  b6 16 c0 12  or  %i3, %l2, %i3
a0135d94:  10 80 00 07  b  0xa0135db0
a0135d98:  80 a6 e0 00  cmp  %i3, 0
a0135d9c:  10 bf ff d6  b  0xa0135cf4
a0135da0:  d4 2c e3 97  stb  %o2, [ %l3 + 0x397 ]
a0135da4:  a2 10 00 1c  mov  %i4, %l1
a0135da8:  10 bf ff 5d  b  0xa0135b1c
a0135dac:  b8 10 20 00  clr  %i4
a0135db0:  12 bf ff e4  bne  0xa0135d40
a0135db4:  b6 10 20 00  clr  %i3
a0135db8:  81 c7 e0 08  ret
a0135dbc:  81 e8 00 00  restore
