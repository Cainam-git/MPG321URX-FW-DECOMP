# leon2m FUN_a0159cf0 0xa0159cf0-0xa0159e28 (312 bytes)
a0159cf0:  9d e3 bf 98  save  %sp, -104, %sp
a0159cf4:  21 2a 00 aa  sethi  %hi(0xa802a800), %l0
a0159cf8:  d0 04 22 18  ld  [ %l0 + 0x218 ], %o0	! 0xa802aa18
a0159cfc:  80 a2 20 00  cmp  %o0, 0
a0159d00:  22 80 00 07  be,a   0xa0159d1c
a0159d04:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a0159d08:  c2 02 20 38  ld  [ %o0 + 0x38 ], %g1
a0159d0c:  80 a0 60 00  cmp  %g1, 0
a0159d10:  02 80 00 40  be  0xa0159e10
a0159d14:  01 00 00 00  nop
a0159d18:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a0159d1c:  80 88 60 08  btst  8, %g1
a0159d20:  12 80 00 2c  bne  0xa0159dd0
a0159d24:  98 10 00 01  mov  %g1, %o4
a0159d28:  80 88 60 10  btst  0x10, %g1
a0159d2c:  02 80 00 3d  be  0xa0159e20
a0159d30:  9a 10 3f ff  mov  -1, %o5
a0159d34:  80 88 60 04  btst  4, %g1
a0159d38:  02 80 00 33  be  0xa0159e04
a0159d3c:  82 13 20 08  or  %o4, 8, %g1
a0159d40:  d2 06 20 30  ld  [ %i0 + 0x30 ], %o1
a0159d44:  80 a2 60 00  cmp  %o1, 0
a0159d48:  02 80 00 0b  be  0xa0159d74
a0159d4c:  82 0b 3f db  and  %o4, -37, %g1
a0159d50:  82 06 20 40  add  %i0, 0x40, %g1
a0159d54:  80 a2 40 01  cmp  %o1, %g1
a0159d58:  22 80 00 06  be,a   0xa0159d70
a0159d5c:  c0 26 20 30  clr  [ %i0 + 0x30 ]
a0159d60:  40 00 06 d8  call  0xa015b8c0
a0159d64:  d0 04 22 18  ld  [ %l0 + 0x218 ], %o0
a0159d68:  d8 16 20 0c  lduh  [ %i0 + 0xc ], %o4
a0159d6c:  c0 26 20 30  clr  [ %i0 + 0x30 ]
a0159d70:  82 0b 3f db  and  %o4, -37, %g1
a0159d74:  c2 36 20 0c  sth  %g1, [ %i0 + 0xc ]
a0159d78:  98 10 00 01  mov  %g1, %o4
a0159d7c:  da 06 20 10  ld  [ %i0 + 0x10 ], %o5
a0159d80:  82 13 20 08  or  %o4, 8, %g1
a0159d84:  c0 26 20 04  clr  [ %i0 + 4 ]
a0159d88:  da 26 00 00  st  %o5, [ %i0 ]
a0159d8c:  c2 36 20 0c  sth  %g1, [ %i0 + 0xc ]
a0159d90:  80 a3 60 00  cmp  %o5, 0
a0159d94:  32 80 00 14  bne,a   0xa0159de4
a0159d98:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a0159d9c:  40 00 09 18  call  0xa015c1fc
a0159da0:  90 10 00 18  mov  %i0, %o0
a0159da4:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a0159da8:  80 88 60 01  btst  1, %g1
a0159dac:  32 80 00 12  bne,a   0xa0159df4
a0159db0:  c2 06 20 14  ld  [ %i0 + 0x14 ], %g1
a0159db4:  80 88 60 02  btst  2, %g1
a0159db8:  12 80 00 03  bne  0xa0159dc4
a0159dbc:  82 10 20 00  clr  %g1
a0159dc0:  c2 06 20 14  ld  [ %i0 + 0x14 ], %g1
a0159dc4:  c2 26 20 08  st  %g1, [ %i0 + 8 ]
a0159dc8:  10 80 00 16  b  0xa0159e20
a0159dcc:  9a 10 20 00  clr  %o5
a0159dd0:  da 06 20 10  ld  [ %i0 + 0x10 ], %o5
a0159dd4:  80 a3 60 00  cmp  %o5, 0
a0159dd8:  02 bf ff f1  be  0xa0159d9c
a0159ddc:  01 00 00 00  nop
a0159de0:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a0159de4:  80 88 60 01  btst  1, %g1
a0159de8:  02 bf ff f4  be  0xa0159db8
a0159dec:  80 88 60 02  btst  2, %g1
a0159df0:  c2 06 20 14  ld  [ %i0 + 0x14 ], %g1
a0159df4:  82 20 00 01  neg  %g1
a0159df8:  c2 26 20 18  st  %g1, [ %i0 + 0x18 ]
a0159dfc:  10 bf ff f3  b  0xa0159dc8
a0159e00:  c0 26 20 08  clr  [ %i0 + 8 ]
a0159e04:  da 06 20 10  ld  [ %i0 + 0x10 ], %o5
a0159e08:  10 bf ff e2  b  0xa0159d90
a0159e0c:  c2 36 20 0c  sth  %g1, [ %i0 + 0xc ]
a0159e10:  40 00 05 d2  call  0xa015b558
a0159e14:  01 00 00 00  nop
a0159e18:  10 bf ff c1  b  0xa0159d1c
a0159e1c:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a0159e20:  81 c7 e0 08  ret
a0159e24:  91 e8 00 0d  restore  %g0, %o5, %o0
