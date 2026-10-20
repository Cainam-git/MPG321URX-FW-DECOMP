# leon2m FUN_a0083c88 0xa0083c88-0xa0083d80 (248 bytes)
a0083c88:  9d e3 bf 88  save  %sp, -120, %sp
a0083c8c:  b6 10 20 50  mov  0x50, %i3
a0083c90:  b4 10 20 6c  mov  0x6c, %i2
a0083c94:  b2 10 20 61  mov  0x61, %i1
a0083c98:  82 10 20 79  mov  0x79, %g1
a0083c9c:  39 2a 00 90  sethi  %hi(0xa8024000), %i4
a0083ca0:  ba 10 20 4e  mov  0x4e, %i5
a0083ca4:  f6 2f bf e8  stb  %i3, [ %fp + -24 ]
a0083ca8:  f4 2f bf e9  stb  %i2, [ %fp + -23 ]
a0083cac:  f2 2f bf ea  stb  %i1, [ %fp + -22 ]
a0083cb0:  c2 2f bf eb  stb  %g1, [ %fp + -21 ]
a0083cb4:  b0 17 20 18  or  %i4, 0x18, %i0
a0083cb8:  b6 10 20 69  mov  0x69, %i3
a0083cbc:  b4 10 20 6e  mov  0x6e, %i2
a0083cc0:  b2 10 20 74  mov  0x74, %i1
a0083cc4:  82 10 20 42  mov  0x42, %g1
a0083cc8:  fa 2f bf ec  stb  %i5, [ %fp + -20 ]
a0083ccc:  b8 10 20 58  mov  0x58, %i4
a0083cd0:  f6 2f bf ed  stb  %i3, [ %fp + -19 ]
a0083cd4:  f4 2f bf ee  stb  %i2, [ %fp + -18 ]
a0083cd8:  f2 2f bf ef  stb  %i1, [ %fp + -17 ]
a0083cdc:  c2 2f bf f1  stb  %g1, [ %fp + -15 ]
a0083ce0:  ba 10 20 4f  mov  0x4f, %i5
a0083ce4:  fa 2f bf f2  stb  %i5, [ %fp + -14 ]
a0083ce8:  f8 2f bf f3  stb  %i4, [ %fp + -13 ]
a0083cec:  f8 2f bf f0  stb  %i4, [ %fp + -16 ]
a0083cf0:  9e 10 3f ff  mov  -1, %o7
a0083cf4:  b6 10 20 00  clr  %i3
a0083cf8:  82 10 20 00  clr  %g1
a0083cfc:  b2 07 bf f8  add  %fp, -8, %i1
a0083d00:  10 80 00 07  b  0xa0083d1c
a0083d04:  f4 0e 20 01  ldub  [ %i0 + 1 ], %i2
a0083d08:  b6 06 e0 01  inc  %i3
a0083d0c:  82 0e e0 ff  and  %i3, 0xff, %g1
a0083d10:  80 a0 60 02  cmp  %g1, 2
a0083d14:  38 80 00 19  bgu,a   0xa0083d78
a0083d18:  b0 0b e0 ff  and  %o7, 0xff, %i0
a0083d1c:  83 28 60 02  sll  %g1, 2, %g1
a0083d20:  b8 00 40 19  add  %g1, %i1, %i4
a0083d24:  fa 0f 3f f0  ldub  [ %i4 + -16 ], %i5
a0083d28:  80 a7 40 1a  cmp  %i5, %i2
a0083d2c:  32 bf ff f8  bne,a   0xa0083d0c
a0083d30:  b6 06 e0 01  inc  %i3
a0083d34:  fa 0f 3f f1  ldub  [ %i4 + -15 ], %i5
a0083d38:  c2 0e 20 02  ldub  [ %i0 + 2 ], %g1
a0083d3c:  80 a7 40 01  cmp  %i5, %g1
a0083d40:  32 bf ff f3  bne,a   0xa0083d0c
a0083d44:  b6 06 e0 01  inc  %i3
a0083d48:  fa 0f 3f f2  ldub  [ %i4 + -14 ], %i5
a0083d4c:  c2 0e 20 03  ldub  [ %i0 + 3 ], %g1
a0083d50:  80 a7 40 01  cmp  %i5, %g1
a0083d54:  32 bf ff ee  bne,a   0xa0083d0c
a0083d58:  b6 06 e0 01  inc  %i3
a0083d5c:  c2 0f 3f f3  ldub  [ %i4 + -13 ], %g1
a0083d60:  f8 0e 20 04  ldub  [ %i0 + 4 ], %i4
a0083d64:  80 a0 40 1c  cmp  %g1, %i4
a0083d68:  22 bf ff e8  be,a   0xa0083d08
a0083d6c:  9e 10 00 1b  mov  %i3, %o7
a0083d70:  10 bf ff e7  b  0xa0083d0c
a0083d74:  b6 06 e0 01  inc  %i3
a0083d78:  81 c7 e0 08  ret
a0083d7c:  81 e8 00 00  restore
