# leon2m FUN_a0118be4 0xa0118be4-0xa0118e04 (544 bytes)
a0118be4:  9d e3 bf 58  save  %sp, -168, %sp
a0118be8:  23 2a 00 9e  sethi  %hi(0xa8027800), %l1
a0118bec:  a0 14 62 98  or  %l1, 0x298, %l0	! 0xa8027a98
a0118bf0:  13 00 06 8b  sethi  %hi(0x1a2c00), %o1
a0118bf4:  92 12 63 2f  or  %o1, 0x32f, %o1	! 0x1a2f2f
a0118bf8:  94 10 20 1e  mov  0x1e, %o2
a0118bfc:  f0 24 20 08  st  %i0, [ %l0 + 8 ]
a0118c00:  f2 24 20 0c  st  %i1, [ %l0 + 0xc ]
a0118c04:  40 00 8f 43  call  0xa013c910
a0118c08:  90 07 bf d8  add  %fp, -40, %o0
a0118c0c:  90 10 20 00  clr  %o0
a0118c10:  7f ff 64 e3  call  0xa00f1f9c
a0118c14:  92 10 20 29  mov  0x29, %o1
a0118c18:  80 8a 20 04  btst  4, %o0
a0118c1c:  12 80 00 03  bne  0xa0118c28
a0118c20:  98 10 20 20  mov  0x20, %o4
a0118c24:  98 10 21 00  mov  0x100, %o4
a0118c28:  d6 04 20 08  ld  [ %l0 + 8 ], %o3
a0118c2c:  80 a2 e0 00  cmp  %o3, 0
a0118c30:  12 80 00 33  bne  0xa0118cfc
a0118c34:  15 00 2d c6  sethi  %hi(0xb71800), %o2
a0118c38:  03 33 c0 4b  sethi  %hi(0xcf012c00), %g1
a0118c3c:  9e 10 63 d8  or  %g1, 0x3d8, %o7	! 0xcf012fd8
a0118c40:  98 10 20 00  clr  %o4
a0118c44:  90 07 bf f8  add  %fp, -8, %o0
a0118c48:  92 10 63 d0  or  %g1, 0x3d0, %o1
a0118c4c:  94 10 63 d4  or  %g1, 0x3d4, %o2
a0118c50:  a6 03 00 0c  add  %o4, %o4, %l3
a0118c54:  9a 04 c0 08  add  %l3, %o0, %o5
a0118c58:  a5 2b 20 04  sll  %o4, 4, %l2
a0118c5c:  e4 22 40 00  st  %l2, [ %o1 ]
a0118c60:  d8 0b 7f e0  ldub  [ %o5 + -32 ], %o4
a0118c64:  d8 22 80 00  st  %o4, [ %o2 ]
a0118c68:  96 02 e0 01  inc  %o3
a0118c6c:  e0 0b 7f e1  ldub  [ %o5 + -31 ], %l0
a0118c70:  98 0a e0 ff  and  %o3, 0xff, %o4
a0118c74:  e0 23 c0 00  st  %l0, [ %o7 ]
a0118c78:  80 a3 20 0e  cmp  %o4, 0xe
a0118c7c:  28 bf ff f6  bleu,a   0xa0118c54
a0118c80:  a6 03 00 0c  add  %o4, %o4, %l3
a0118c84:  13 00 06 8b  sethi  %hi(0x1a2c00), %o1
a0118c88:  92 12 63 4d  or  %o1, 0x34d, %o1	! 0x1a2f4d
a0118c8c:  90 07 bf b8  add  %fp, -72, %o0
a0118c90:  40 00 8f 20  call  0xa013c910
a0118c94:  94 10 20 20  mov  0x20, %o2
a0118c98:  9a 14 62 98  or  %l1, 0x298, %o5
a0118c9c:  d6 03 60 08  ld  [ %o5 + 8 ], %o3
a0118ca0:  80 a2 e0 00  cmp  %o3, 0
a0118ca4:  12 80 00 44  bne  0xa0118db4
a0118ca8:  25 33 c0 4b  sethi  %hi(0xcf012c00), %l2
a0118cac:  23 33 c0 4b  sethi  %hi(0xcf012c00), %l1
a0118cb0:  9e 14 63 e8  or  %l1, 0x3e8, %o7	! 0xcf012fe8
a0118cb4:  96 10 20 00  clr  %o3
a0118cb8:  90 07 bf f8  add  %fp, -8, %o0
a0118cbc:  9a 10 20 00  clr  %o5
a0118cc0:  92 14 63 e0  or  %l1, 0x3e0, %o1
a0118cc4:  94 14 63 e4  or  %l1, 0x3e4, %o2
a0118cc8:  82 03 40 0d  add  %o5, %o5, %g1
a0118ccc:  da 22 40 00  st  %o5, [ %o1 ]
a0118cd0:  b2 00 40 08  add  %g1, %o0, %i1
a0118cd4:  da 0e 7f c0  ldub  [ %i1 + -64 ], %o5
a0118cd8:  da 22 80 00  st  %o5, [ %o2 ]
a0118cdc:  96 02 e0 01  inc  %o3
a0118ce0:  e0 0e 7f c1  ldub  [ %i1 + -63 ], %l0
a0118ce4:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0118ce8:  e0 23 c0 00  st  %l0, [ %o7 ]
a0118cec:  80 a3 60 0f  cmp  %o5, 0xf
a0118cf0:  08 bf ff f7  bleu  0xa0118ccc
a0118cf4:  82 03 40 0d  add  %o5, %o5, %g1
a0118cf8:  30 80 00 41  b,a   0xa0118dfc
a0118cfc:  90 0b 21 20  and  %o4, 0x120, %o0
a0118d00:  9e 12 a3 00  or  %o2, 0x300, %o7
a0118d04:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a0118d08:  81 82 a0 00  mov  %o2, %y
a0118d0c:  01 00 00 00  nop
a0118d10:  01 00 00 00  nop
a0118d14:  01 00 00 00  nop
a0118d18:  92 7b c0 08  sdiv  %o7, %o0, %o1
a0118d1c:  31 33 c0 4b  sethi  %hi(0xcf012c00), %i0
a0118d20:  94 10 00 0b  mov  %o3, %o2
a0118d24:  a0 16 23 d8  or  %i0, 0x3d8, %l0
a0118d28:  96 10 20 00  clr  %o3
a0118d2c:  98 10 20 00  clr  %o4
a0118d30:  9e 16 23 d0  or  %i0, 0x3d0, %o7
a0118d34:  90 16 23 d4  or  %i0, 0x3d4, %o0
a0118d38:  a6 03 00 0c  add  %o4, %o4, %l3
a0118d3c:  f0 12 80 13  lduh  [ %o2 + %l3 ], %i0
a0118d40:  a7 3a 60 1f  sra  %o1, 0x1f, %l3
a0118d44:  81 84 e0 00  mov  %l3, %y
a0118d48:  01 00 00 00  nop
a0118d4c:  01 00 00 00  nop
a0118d50:  01 00 00 00  nop
a0118d54:  9a 7a 40 18  sdiv  %o1, %i0, %o5
a0118d58:  99 2b 20 04  sll  %o4, 4, %o4
a0118d5c:  a5 2b 60 10  sll  %o5, 0x10, %l2
a0118d60:  d8 23 c0 00  st  %o4, [ %o7 ]
a0118d64:  83 34 a0 18  srl  %l2, 0x18, %g1
a0118d68:  96 02 e0 01  inc  %o3
a0118d6c:  c2 22 00 00  st  %g1, [ %o0 ]
a0118d70:  b2 0b 60 ff  and  %o5, 0xff, %i1
a0118d74:  98 0a e0 ff  and  %o3, 0xff, %o4
a0118d78:  f2 24 00 00  st  %i1, [ %l0 ]
a0118d7c:  80 a3 20 0e  cmp  %o4, 0xe
a0118d80:  08 bf ff ef  bleu  0xa0118d3c
a0118d84:  a6 03 00 0c  add  %o4, %o4, %l3
a0118d88:  13 00 06 8b  sethi  %hi(0x1a2c00), %o1
a0118d8c:  92 12 63 4d  or  %o1, 0x34d, %o1	! 0x1a2f4d
a0118d90:  90 07 bf b8  add  %fp, -72, %o0
a0118d94:  40 00 8e df  call  0xa013c910
a0118d98:  94 10 20 20  mov  0x20, %o2
a0118d9c:  9a 14 62 98  or  %l1, 0x298, %o5
a0118da0:  d6 03 60 08  ld  [ %o5 + 8 ], %o3
a0118da4:  80 a2 e0 00  cmp  %o3, 0
a0118da8:  02 bf ff c2  be  0xa0118cb0
a0118dac:  23 33 c0 4b  sethi  %hi(0xcf012c00), %l1
a0118db0:  25 33 c0 4b  sethi  %hi(0xcf012c00), %l2
a0118db4:  d4 03 60 0c  ld  [ %o5 + 0xc ], %o2
a0118db8:  9e 14 a3 e8  or  %l2, 0x3e8, %o7
a0118dbc:  96 10 20 00  clr  %o3
a0118dc0:  98 10 20 00  clr  %o4
a0118dc4:  90 14 a3 e0  or  %l2, 0x3e0, %o0
a0118dc8:  92 14 a3 e4  or  %l2, 0x3e4, %o1
a0118dcc:  d8 22 00 00  st  %o4, [ %o0 ]
a0118dd0:  a6 03 00 0c  add  %o4, %o4, %l3
a0118dd4:  e2 0a 80 13  ldub  [ %o2 + %l3 ], %l1
a0118dd8:  e2 22 40 00  st  %l1, [ %o1 ]
a0118ddc:  98 04 c0 0a  add  %l3, %o2, %o4
a0118de0:  f0 0b 20 01  ldub  [ %o4 + 1 ], %i0
a0118de4:  96 02 e0 01  inc  %o3
a0118de8:  98 0a e0 ff  and  %o3, 0xff, %o4
a0118dec:  f0 23 c0 00  st  %i0, [ %o7 ]
a0118df0:  80 a3 20 0f  cmp  %o4, 0xf
a0118df4:  08 bf ff f6  bleu  0xa0118dcc
a0118df8:  01 00 00 00  nop
a0118dfc:  81 c7 e0 08  ret
a0118e00:  81 e8 00 00  restore
