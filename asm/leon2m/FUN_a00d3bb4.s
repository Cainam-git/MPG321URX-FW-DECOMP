# leon2m FUN_a00d3bb4 0xa00d3bb4-0xa00d3d30 (380 bytes)
a00d3bb4:  9d e3 bf 98  save  %sp, -104, %sp
a00d3bb8:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00d3bbc:  92 14 62 90  or  %l1, 0x290, %o1	! 0xa802d290
a00d3bc0:  94 10 20 00  clr  %o2
a00d3bc4:  96 10 21 fc  mov  0x1fc, %o3
a00d3bc8:  40 01 dc 95  call  0xa014ae1c
a00d3bcc:  90 10 20 30  mov  0x30, %o0
a00d3bd0:  a0 14 62 90  or  %l1, 0x290, %l0
a00d3bd4:  17 00 06 61  sethi  %hi(0x198400), %o3
a00d3bd8:  82 12 e1 24  or  %o3, 0x124, %g1	! 0x198524
a00d3bdc:  d8 14 21 f8  lduh  [ %l0 + 0x1f8 ], %o4
a00d3be0:  da 10 61 f8  lduh  [ %g1 + 0x1f8 ], %o5
a00d3be4:  2d 2a 00 b4  sethi  %hi(0xa802d000), %l6
a00d3be8:  92 10 00 01  mov  %g1, %o1
a00d3bec:  94 10 21 fc  mov  0x1fc, %o2
a00d3bf0:  90 10 00 10  mov  %l0, %o0
a00d3bf4:  b0 10 20 30  mov  0x30, %i0
a00d3bf8:  b4 10 22 e0  mov  0x2e0, %i2
a00d3bfc:  80 a3 00 0d  cmp  %o4, %o5
a00d3c00:  02 80 00 33  be  0xa00d3ccc
a00d3c04:  b6 10 20 1c  mov  0x1c, %i3
a00d3c08:  40 01 a3 42  call  0xa013c910
a00d3c0c:  a8 15 a2 74  or  %l6, 0x274, %l4
a00d3c10:  92 10 00 10  mov  %l0, %o1
a00d3c14:  94 10 20 00  clr  %o2
a00d3c18:  96 10 21 fc  mov  0x1fc, %o3
a00d3c1c:  40 01 dc ad  call  0xa014aed0
a00d3c20:  90 10 20 30  mov  0x30, %o0
a00d3c24:  92 15 a2 74  or  %l6, 0x274, %o1
a00d3c28:  94 10 22 e0  mov  0x2e0, %o2
a00d3c2c:  96 10 20 1c  mov  0x1c, %o3
a00d3c30:  40 01 dc 7b  call  0xa014ae1c
a00d3c34:  90 10 20 30  mov  0x30, %o0
a00d3c38:  19 00 06 61  sethi  %hi(0x198400), %o4
a00d3c3c:  aa 13 21 08  or  %o4, 0x108, %l5	! 0x198508
a00d3c40:  d0 15 60 1a  lduh  [ %l5 + 0x1a ], %o0
a00d3c44:  d2 15 20 1a  lduh  [ %l4 + 0x1a ], %o1
a00d3c48:  b2 10 00 14  mov  %l4, %i1
a00d3c4c:  80 a2 40 08  cmp  %o1, %o0
a00d3c50:  02 80 00 31  be  0xa00d3d14
a00d3c54:  ae 10 00 08  mov  %o0, %l7
a00d3c58:  e0 15 60 10  lduh  [ %l5 + 0x10 ], %l0
a00d3c5c:  c2 13 21 08  lduh  [ %o4 + 0x108 ], %g1
a00d3c60:  e0 35 20 10  sth  %l0, [ %l4 + 0x10 ]
a00d3c64:  da 15 60 02  lduh  [ %l5 + 2 ], %o5
a00d3c68:  d8 15 60 04  lduh  [ %l5 + 4 ], %o4
a00d3c6c:  d6 15 60 06  lduh  [ %l5 + 6 ], %o3
a00d3c70:  d4 15 60 08  lduh  [ %l5 + 8 ], %o2
a00d3c74:  d2 15 60 0a  lduh  [ %l5 + 0xa ], %o1
a00d3c78:  d0 15 60 0c  lduh  [ %l5 + 0xc ], %o0
a00d3c7c:  de 15 60 0e  lduh  [ %l5 + 0xe ], %o7
a00d3c80:  e2 15 60 12  lduh  [ %l5 + 0x12 ], %l1
a00d3c84:  e4 15 60 14  lduh  [ %l5 + 0x14 ], %l2
a00d3c88:  e6 15 60 16  lduh  [ %l5 + 0x16 ], %l3
a00d3c8c:  e0 15 60 18  lduh  [ %l5 + 0x18 ], %l0
a00d3c90:  c2 35 a2 74  sth  %g1, [ %l6 + 0x274 ]
a00d3c94:  da 35 20 02  sth  %o5, [ %l4 + 2 ]
a00d3c98:  d8 35 20 04  sth  %o4, [ %l4 + 4 ]
a00d3c9c:  d6 35 20 06  sth  %o3, [ %l4 + 6 ]
a00d3ca0:  d4 35 20 08  sth  %o2, [ %l4 + 8 ]
a00d3ca4:  d2 35 20 0a  sth  %o1, [ %l4 + 0xa ]
a00d3ca8:  d0 35 20 0c  sth  %o0, [ %l4 + 0xc ]
a00d3cac:  de 35 20 0e  sth  %o7, [ %l4 + 0xe ]
a00d3cb0:  e2 35 20 12  sth  %l1, [ %l4 + 0x12 ]
a00d3cb4:  e4 35 20 14  sth  %l2, [ %l4 + 0x14 ]
a00d3cb8:  e6 35 20 16  sth  %l3, [ %l4 + 0x16 ]
a00d3cbc:  e0 35 20 18  sth  %l0, [ %l4 + 0x18 ]
a00d3cc0:  ee 35 20 1a  sth  %l7, [ %l4 + 0x1a ]
a00d3cc4:  40 01 dc 83  call  0xa014aed0
a00d3cc8:  81 e8 00 00  restore
a00d3ccc:  e4 14 62 90  lduh  [ %l1 + 0x290 ], %l2
a00d3cd0:  de 12 e1 24  lduh  [ %o3 + 0x124 ], %o7
a00d3cd4:  80 a4 80 0f  cmp  %l2, %o7
a00d3cd8:  12 bf ff cc  bne  0xa00d3c08
a00d3cdc:  96 10 20 1c  mov  0x1c, %o3
a00d3ce0:  92 15 a2 74  or  %l6, 0x274, %o1
a00d3ce4:  94 10 22 e0  mov  0x2e0, %o2
a00d3ce8:  40 01 dc 4d  call  0xa014ae1c
a00d3cec:  90 10 20 30  mov  0x30, %o0
a00d3cf0:  19 00 06 61  sethi  %hi(0x198400), %o4
a00d3cf4:  a8 15 a2 74  or  %l6, 0x274, %l4
a00d3cf8:  aa 13 21 08  or  %o4, 0x108, %l5
a00d3cfc:  d0 15 60 1a  lduh  [ %l5 + 0x1a ], %o0
a00d3d00:  d2 15 20 1a  lduh  [ %l4 + 0x1a ], %o1
a00d3d04:  b2 10 00 14  mov  %l4, %i1
a00d3d08:  80 a2 40 08  cmp  %o1, %o0
a00d3d0c:  12 bf ff d3  bne  0xa00d3c58
a00d3d10:  ae 10 00 08  mov  %o0, %l7
a00d3d14:  d6 15 a2 74  lduh  [ %l6 + 0x274 ], %o3
a00d3d18:  d4 13 21 08  lduh  [ %o4 + 0x108 ], %o2
a00d3d1c:  80 a2 c0 0a  cmp  %o3, %o2
a00d3d20:  32 bf ff cf  bne,a   0xa00d3c5c
a00d3d24:  e0 15 60 10  lduh  [ %l5 + 0x10 ], %l0
a00d3d28:  81 c7 e0 08  ret
a00d3d2c:  81 e8 00 00  restore
