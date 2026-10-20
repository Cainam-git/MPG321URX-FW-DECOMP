# leon2m FUN_a0136a10 0xa0136a10-0xa0136d08 (760 bytes)
a0136a10:  9d e3 bf 70  save  %sp, -144, %sp
a0136a14:  98 10 20 00  clr  %o4
a0136a18:  9a 10 20 00  clr  %o5
a0136a1c:  83 2e 60 10  sll  %i1, 0x10, %g1
a0136a20:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0136a24:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0136a28:  a1 30 60 10  srl  %g1, 0x10, %l0
a0136a2c:  29 2a 00 b2  sethi  %hi(0xa802c800), %l4
a0136a30:  10 80 00 04  b  0xa0136a40
a0136a34:  2d 2a 00 b2  sethi  %hi(0xa802c800), %l6
a0136a38:  7f ff f9 a9  call  0xa01350dc
a0136a3c:  01 00 00 00  nop
a0136a40:  d6 0d 23 97  ldub  [ %l4 + 0x397 ], %o3
a0136a44:  d8 0d a3 96  ldub  [ %l6 + 0x396 ], %o4
a0136a48:  92 0b 20 ff  and  %o4, 0xff, %o1
a0136a4c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0136a50:  90 22 40 0d  sub  %o1, %o5, %o0
a0136a54:  92 0a e0 ff  and  %o3, 0xff, %o1
a0136a58:  94 0b 20 ff  and  %o4, 0xff, %o2
a0136a5c:  80 a2 40 0a  cmp  %o1, %o2
a0136a60:  18 80 00 09  bgu  0xa0136a84
a0136a64:  82 02 20 24  add  %o0, 0x24, %g1
a0136a68:  9e 0b 20 ff  and  %o4, 0xff, %o7
a0136a6c:  98 0a e0 ff  and  %o3, 0xff, %o4
a0136a70:  80 a2 40 0a  cmp  %o1, %o2
a0136a74:  9a 23 c0 0c  sub  %o7, %o4, %o5
a0136a78:  1a 80 00 03  bcc  0xa0136a84
a0136a7c:  82 10 20 24  mov  0x24, %g1
a0136a80:  82 03 7f ff  add  %o5, -1, %g1
a0136a84:  97 28 60 14  sll  %g1, 0x14, %o3
a0136a88:  95 32 e0 10  srl  %o3, 0x10, %o2
a0136a8c:  80 a4 00 0a  cmp  %l0, %o2
a0136a90:  18 bf ff ea  bgu  0xa0136a38
a0136a94:  a3 2e 60 10  sll  %i1, 0x10, %l1
a0136a98:  a1 2e 20 10  sll  %i0, 0x10, %l0
a0136a9c:  83 34 60 10  srl  %l1, 0x10, %g1
a0136aa0:  ab 34 20 14  srl  %l0, 0x14, %l5
a0136aa4:  80 a0 60 00  cmp  %g1, 0
a0136aa8:  ba 10 20 10  mov  0x10, %i5
a0136aac:  02 80 00 95  be  0xa0136d00
a0136ab0:  ae 10 20 00  clr  %l7
a0136ab4:  25 2a 00 b6  sethi  %hi(0xa802d800), %l2
a0136ab8:  9a 10 00 01  mov  %g1, %o5
a0136abc:  b6 14 a2 6c  or  %l2, 0x26c, %i3
a0136ac0:  a2 07 bf e8  add  %fp, -24, %l1
a0136ac4:  b8 10 00 01  mov  %g1, %i4
a0136ac8:  83 2d e0 10  sll  %l7, 0x10, %g1
a0136acc:  b1 30 60 10  srl  %g1, 0x10, %i0
a0136ad0:  a6 23 40 18  sub  %o5, %i0, %l3
a0136ad4:  80 a4 e0 0f  cmp  %l3, 0xf
a0136ad8:  24 80 00 02  ble,a   0xa0136ae0
a0136adc:  ba 26 40 17  sub  %i1, %l7, %i5
a0136ae0:  7f fe 9a cd  call  0xa00dd614
a0136ae4:  90 10 20 20  mov  0x20, %o0
a0136ae8:  80 8a 20 ff  btst  0xff, %o0
a0136aec:  12 80 00 7e  bne  0xa0136ce4
a0136af0:  a6 0d 60 ff  and  %l5, 0xff, %l3
a0136af4:  7f fe 9a c8  call  0xa00dd614
a0136af8:  90 10 20 20  mov  0x20, %o0
a0136afc:  80 8a 20 ff  btst  0xff, %o0
a0136b00:  12 80 00 74  bne  0xa0136cd0
a0136b04:  a4 0f 60 ff  and  %i5, 0xff, %l2
a0136b08:  7f fe 9a c3  call  0xa00dd614
a0136b0c:  90 10 20 20  mov  0x20, %o0
a0136b10:  80 8a 20 ff  btst  0xff, %o0
a0136b14:  12 80 00 5f  bne  0xa0136c90
a0136b18:  a0 06 00 1a  add  %i0, %i2, %l0
a0136b1c:  94 10 20 00  clr  %o2
a0136b20:  9a 10 20 00  clr  %o5
a0136b24:  97 2b 60 02  sll  %o5, 2, %o3
a0136b28:  f0 0c 00 0b  ldub  [ %l0 + %o3 ], %i0
a0136b2c:  f0 24 40 0b  st  %i0, [ %l1 + %o3 ]
a0136b30:  9e 02 c0 10  add  %o3, %l0, %o7
a0136b34:  da 0b e0 01  ldub  [ %o7 + 1 ], %o5
a0136b38:  93 2e 20 08  sll  %i0, 8, %o1
a0136b3c:  98 02 40 0d  add  %o1, %o5, %o4
a0136b40:  d8 24 40 0b  st  %o4, [ %l1 + %o3 ]
a0136b44:  d0 0b e0 02  ldub  [ %o7 + 2 ], %o0
a0136b48:  83 2b 20 08  sll  %o4, 8, %g1
a0136b4c:  b0 00 40 08  add  %g1, %o0, %i0
a0136b50:  f0 24 40 0b  st  %i0, [ %l1 + %o3 ]
a0136b54:  da 0b e0 03  ldub  [ %o7 + 3 ], %o5
a0136b58:  93 2e 20 08  sll  %i0, 8, %o1
a0136b5c:  98 02 40 0d  add  %o1, %o5, %o4
a0136b60:  94 02 a0 01  inc  %o2
a0136b64:  9a 0a a0 ff  and  %o2, 0xff, %o5
a0136b68:  80 a3 60 04  cmp  %o5, 4
a0136b6c:  0a bf ff ee  bcs  0xa0136b24
a0136b70:  d8 24 40 0b  st  %o4, [ %l1 + %o3 ]
a0136b74:  d4 0d 23 97  ldub  [ %l4 + 0x397 ], %o2
a0136b78:  96 0a a0 ff  and  %o2, 0xff, %o3
a0136b7c:  a1 2c a0 10  sll  %l2, 0x10, %l0
a0136b80:  a5 2a e0 02  sll  %o3, 2, %l2
a0136b84:  9b 2c e0 18  sll  %l3, 0x18, %o5
a0136b88:  b0 04 80 0b  add  %l2, %o3, %i0
a0136b8c:  92 03 40 10  add  %o5, %l0, %o1
a0136b90:  83 2e 20 02  sll  %i0, 2, %g1
a0136b94:  98 02 60 01  add  %o1, 1, %o4
a0136b98:  94 02 a0 01  inc  %o2
a0136b9c:  d8 26 c0 01  st  %o4, [ %i3 + %g1 ]
a0136ba0:  a4 00 40 1b  add  %g1, %i3, %l2
a0136ba4:  a0 0a a0 ff  and  %o2, 0xff, %l0
a0136ba8:  d0 07 bf f4  ld  [ %fp + -12 ], %o0
a0136bac:  de 07 bf e8  ld  [ %fp + -24 ], %o7
a0136bb0:  d6 07 bf ec  ld  [ %fp + -20 ], %o3
a0136bb4:  e6 07 bf f0  ld  [ %fp + -16 ], %l3
a0136bb8:  d0 24 a0 10  st  %o0, [ %l2 + 0x10 ]
a0136bbc:  de 24 a0 04  st  %o7, [ %l2 + 4 ]
a0136bc0:  d6 24 a0 08  st  %o3, [ %l2 + 8 ]
a0136bc4:  80 a4 20 24  cmp  %l0, 0x24
a0136bc8:  08 80 00 4c  bleu  0xa0136cf8
a0136bcc:  e6 24 a0 0c  st  %l3, [ %l2 + 0xc ]
a0136bd0:  c0 2d 23 97  clrb  [ %l4 + 0x397 ]
a0136bd4:  c0 27 bf e4  clr  [ %fp + -28 ]
a0136bd8:  11 2a 00 b2  sethi  %hi(0xa802c800), %o0
a0136bdc:  de 0a 23 97  ldub  [ %o0 + 0x397 ], %o7	! 0xa802cb97
a0136be0:  e6 0d a3 96  ldub  [ %l6 + 0x396 ], %l3
a0136be4:  80 a3 c0 13  cmp  %o7, %l3
a0136be8:  02 80 00 09  be  0xa0136c0c
a0136bec:  aa 05 60 01  inc  %l5
a0136bf0:  7f ff f9 3b  call  0xa01350dc
a0136bf4:  01 00 00 00  nop
a0136bf8:  d8 0d 23 97  ldub  [ %l4 + 0x397 ], %o4
a0136bfc:  c2 0d a3 96  ldub  [ %l6 + 0x396 ], %g1
a0136c00:  80 a3 00 01  cmp  %o4, %g1
a0136c04:  12 bf ff fb  bne  0xa0136bf0
a0136c08:  01 00 00 00  nop
a0136c0c:  a0 10 20 00  clr  %l0	! 0x0
a0136c10:  b0 10 20 00  clr  %i0
a0136c14:  98 10 20 00  clr  %o4
a0136c18:  83 2b 20 02  sll  %o4, 2, %g1
a0136c1c:  90 00 40 0c  add  %g1, %o4, %o0
a0136c20:  9f 2a 20 02  sll  %o0, 2, %o7
a0136c24:  a6 03 e0 10  add  %o7, 0x10, %l3
a0136c28:  92 0c e0 fc  and  %l3, 0xfc, %o1
a0136c2c:  94 07 bf e4  add  %fp, -28, %o2
a0136c30:  96 10 20 01  mov  1, %o3
a0136c34:  67 fd 56 27  call  0x4008c4d0
a0136c38:  90 10 20 00  clr  %o0
a0136c3c:  b0 06 20 01  inc  %i0
a0136c40:  98 0e 20 ff  and  %i0, 0xff, %o4
a0136c44:  97 2b 20 02  sll  %o4, 2, %o3
a0136c48:  a4 02 c0 0c  add  %o3, %o4, %l2
a0136c4c:  9b 2c a0 02  sll  %l2, 2, %o5
a0136c50:  94 03 60 10  add  %o5, 0x10, %o2
a0136c54:  d2 07 bf e4  ld  [ %fp + -28 ], %o1
a0136c58:  80 a2 a0 50  cmp  %o2, 0x50
a0136c5c:  04 bf ff ef  ble  0xa0136c18
a0136c60:  a0 14 00 09  or  %l0, %o1, %l0
a0136c64:  80 a4 20 00  cmp  %l0, 0
a0136c68:  12 bf ff ea  bne  0xa0136c10
a0136c6c:  a0 10 20 00  clr  %l0
a0136c70:  b0 05 e0 10  add  %l7, 0x10, %i0
a0136c74:  a1 2e 20 10  sll  %i0, 0x10, %l0
a0136c78:  af 34 20 10  srl  %l0, 0x10, %l7
a0136c7c:  80 a5 c0 1c  cmp  %l7, %i4
a0136c80:  ae 10 00 18  mov  %i0, %l7
a0136c84:  0a bf ff 91  bcs  0xa0136ac8
a0136c88:  9a 10 00 1c  mov  %i4, %o5
a0136c8c:  30 80 00 1d  b,a   0xa0136d00
a0136c90:  d0 0c 20 05  ldub  [ %l0 + 5 ], %o0
a0136c94:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a0136c98:  d6 0c 20 02  ldub  [ %l0 + 2 ], %o3
a0136c9c:  d8 0c 20 03  ldub  [ %l0 + 3 ], %o4
a0136ca0:  da 0c 20 04  ldub  [ %l0 + 4 ], %o5
a0136ca4:  d0 23 a0 5c  st  %o0, [ %sp + 0x5c ]
a0136ca8:  c2 0c 20 06  ldub  [ %l0 + 6 ], %g1
a0136cac:  c2 23 a0 60  st  %g1, [ %sp + 0x60 ]
a0136cb0:  d2 0e 00 1a  ldub  [ %i0 + %i2 ], %o1
a0136cb4:  de 0c 20 07  ldub  [ %l0 + 7 ], %o7
a0136cb8:  31 00 06 95  sethi  %hi(0x1a5400), %i0
a0136cbc:  de 23 a0 64  st  %o7, [ %sp + 0x64 ]
a0136cc0:  7f fe a1 2c  call  0xa00df170
a0136cc4:  90 16 21 50  or  %i0, 0x150, %o0
a0136cc8:  10 bf ff 96  b  0xa0136b20
a0136ccc:  94 10 20 00  clr  %o2
a0136cd0:  13 00 06 95  sethi  %hi(0x1a5400), %o1
a0136cd4:  90 12 61 88  or  %o1, 0x188, %o0	! 0x1a5588
a0136cd8:  7f fe a1 26  call  0xa00df170
a0136cdc:  92 10 00 12  mov  %l2, %o1
a0136ce0:  30 bf ff 8a  b,a   0xa0136b08
a0136ce4:  11 00 06 95  sethi  %hi(0x1a5400), %o0
a0136ce8:  92 10 00 13  mov  %l3, %o1
a0136cec:  7f fe a1 21  call  0xa00df170
a0136cf0:  90 12 21 98  or  %o0, 0x198, %o0
a0136cf4:  30 bf ff 80  b,a   0xa0136af4
a0136cf8:  10 bf ff b7  b  0xa0136bd4
a0136cfc:  d4 2d 23 97  stb  %o2, [ %l4 + 0x397 ]
a0136d00:  81 c7 e0 08  ret
a0136d04:  81 e8 00 00  restore
