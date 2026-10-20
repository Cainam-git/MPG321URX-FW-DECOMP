# leon2m FUN_a0133b54 0xa0133b54-0xa0133cbc (360 bytes)
a0133b54:  9d e3 bf 88  save  %sp, -120, %sp
a0133b58:  83 2e 60 10  sll  %i1, 0x10, %g1
a0133b5c:  b8 10 20 00  clr  %i4
a0133b60:  ba 10 20 00  clr  %i5
a0133b64:  83 30 60 10  srl  %g1, 0x10, %g1
a0133b68:  f8 3f bf f0  std  %i4, [ %fp + -16 ]
a0133b6c:  a4 10 00 1a  mov  %i2, %l2
a0133b70:  f8 3f bf e8  std  %i4, [ %fp + -24 ]
a0133b74:  80 a0 60 00  cmp  %g1, 0
a0133b78:  90 10 20 02  mov  2, %o0
a0133b7c:  a0 10 20 10  mov  0x10, %l0
a0133b80:  9a 10 20 00  clr  %o5
a0133b84:  02 80 00 4c  be  0xa0133cb4
a0133b88:  9e 10 20 00  clr  %o7
a0133b8c:  92 0e 20 ff  and  %i0, 0xff, %o1
a0133b90:  31 2a 00 b6  sethi  %hi(0xa802d800), %i0
a0133b94:  94 16 22 6c  or  %i0, 0x26c, %o2	! 0xa802da6c
a0133b98:  96 10 00 01  mov  %g1, %o3
a0133b9c:  a2 10 00 19  mov  %i1, %l1
a0133ba0:  b0 07 bf e8  add  %fp, -24, %i0
a0133ba4:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a0133ba8:  b3 2b e0 10  sll  %o7, 0x10, %i1
a0133bac:  83 36 60 10  srl  %i1, 0x10, %g1
a0133bb0:  ba 22 c0 01  sub  %o3, %g1, %i5
a0133bb4:  80 a7 60 10  cmp  %i5, 0x10
a0133bb8:  14 80 00 04  bg  0xa0133bc8
a0133bbc:  b2 00 40 12  add  %g1, %l2, %i1
a0133bc0:  a0 24 40 0f  sub  %l1, %o7, %l0
a0133bc4:  90 10 20 01  mov  1, %o0
a0133bc8:  b4 10 20 00  clr  %i2
a0133bcc:  ba 10 20 00  clr  %i5
a0133bd0:  b7 2f 60 02  sll  %i5, 2, %i3
a0133bd4:  b8 06 c0 19  add  %i3, %i1, %i4
a0133bd8:  c2 0e 40 1b  ldub  [ %i1 + %i3 ], %g1
a0133bdc:  fa 0f 20 01  ldub  [ %i4 + 1 ], %i5
a0133be0:  83 28 60 08  sll  %g1, 8, %g1
a0133be4:  82 00 40 1d  add  %g1, %i5, %g1
a0133be8:  fa 0f 20 02  ldub  [ %i4 + 2 ], %i5
a0133bec:  83 28 60 08  sll  %g1, 8, %g1
a0133bf0:  82 00 40 1d  add  %g1, %i5, %g1
a0133bf4:  fa 0f 20 03  ldub  [ %i4 + 3 ], %i5
a0133bf8:  83 28 60 08  sll  %g1, 8, %g1
a0133bfc:  b8 00 40 1d  add  %g1, %i5, %i4
a0133c00:  b4 06 a0 01  inc  %i2
a0133c04:  ba 0e a0 ff  and  %i2, 0xff, %i5
a0133c08:  80 a7 60 04  cmp  %i5, 4
a0133c0c:  0a bf ff f1  bcs  0xa0133bd0
a0133c10:  f8 26 00 1b  st  %i4, [ %i0 + %i3 ]
a0133c14:  b4 0c 20 ff  and  %l0, 0xff, %i2
a0133c18:  b9 2e a0 10  sll  %i2, 0x10, %i4
a0133c1c:  f4 0b 23 97  ldub  [ %o4 + 0x397 ], %i2
a0133c20:  83 2b 60 18  sll  %o5, 0x18, %g1
a0133c24:  b6 0e a0 ff  and  %i2, 0xff, %i3
a0133c28:  b2 00 40 1c  add  %g1, %i4, %i1
a0133c2c:  bb 2a 60 08  sll  %o1, 8, %i5
a0133c30:  82 06 40 1d  add  %i1, %i5, %g1
a0133c34:  b9 2e e0 02  sll  %i3, 2, %i4
a0133c38:  b2 0a 20 ff  and  %o0, 0xff, %i1
a0133c3c:  b8 07 00 1b  add  %i4, %i3, %i4
a0133c40:  b6 00 60 04  add  %g1, 4, %i3
a0133c44:  bb 2e 60 04  sll  %i1, 4, %i5
a0133c48:  b2 06 c0 1d  add  %i3, %i5, %i1
a0133c4c:  b9 2f 20 02  sll  %i4, 2, %i4
a0133c50:  f2 22 80 1c  st  %i1, [ %o2 + %i4 ]
a0133c54:  b6 07 00 0a  add  %i4, %o2, %i3
a0133c58:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a0133c5c:  fa 07 bf e8  ld  [ %fp + -24 ], %i5
a0133c60:  b4 06 a0 01  inc  %i2
a0133c64:  c2 26 e0 10  st  %g1, [ %i3 + 0x10 ]
a0133c68:  fa 26 e0 04  st  %i5, [ %i3 + 4 ]
a0133c6c:  b2 0e a0 ff  and  %i2, 0xff, %i1
a0133c70:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a0133c74:  fa 07 bf f0  ld  [ %fp + -16 ], %i5
a0133c78:  c2 26 e0 08  st  %g1, [ %i3 + 8 ]
a0133c7c:  80 a6 60 24  cmp  %i1, 0x24
a0133c80:  08 80 00 0b  bleu  0xa0133cac
a0133c84:  fa 26 e0 0c  st  %i5, [ %i3 + 0xc ]
a0133c88:  c0 2b 23 97  clrb  [ %o4 + 0x397 ]
a0133c8c:  b6 03 e0 10  add  %o7, 0x10, %i3
a0133c90:  bb 2e e0 10  sll  %i3, 0x10, %i5
a0133c94:  b3 37 60 10  srl  %i5, 0x10, %i1
a0133c98:  80 a6 40 0b  cmp  %i1, %o3
a0133c9c:  9a 03 60 01  inc  %o5
a0133ca0:  0a bf ff c2  bcs  0xa0133ba8
a0133ca4:  9e 10 00 1b  mov  %i3, %o7
a0133ca8:  30 80 00 03  b,a   0xa0133cb4
a0133cac:  10 bf ff f8  b  0xa0133c8c
a0133cb0:  f4 2b 23 97  stb  %i2, [ %o4 + 0x397 ]
a0133cb4:  81 c7 e0 08  ret
a0133cb8:  81 e8 00 00  restore
