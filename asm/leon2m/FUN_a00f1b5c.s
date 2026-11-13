# leon2m FUN_a00f1b5c 0xa00f1b5c-0xa00f1ce4 (392 bytes)
a00f1b5c:  9d e3 bf 98  save  %sp, -104, %sp
a00f1b60:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f1b64:  9e 10 00 19  mov  %i1, %o7
a00f1b68:  80 a6 20 07  cmp  %i0, 7
a00f1b6c:  08 80 00 28  bleu  0xa00f1c0c
a00f1b70:  b2 10 00 1a  mov  %i2, %i1
a00f1b74:  b4 0e e0 ff  and  %i3, 0xff, %i2
a00f1b78:  37 00 06 68  sethi  %hi(0x19a000), %i3
a00f1b7c:  80 a6 a0 01  cmp  %i2, 1
a00f1b80:  b4 0b e0 ff  and  %o7, 0xff, %i2
a00f1b84:  9a 16 e3 1c  or  %i3, 0x31c, %o5
a00f1b88:  b6 10 20 00  clr  %i3
a00f1b8c:  b8 10 20 00  clr  %i4
a00f1b90:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a00f1b94:  02 80 00 37  be  0xa00f1c70
a00f1b98:  b0 38 00 19  xnor  %g0, %i1, %i0
a00f1b9c:  ba 07 00 1c  add  %i4, %i4, %i5
a00f1ba0:  f2 13 40 1d  lduh  [ %o5 + %i5 ], %i1
a00f1ba4:  82 06 40 1a  add  %i1, %i2, %g1
a00f1ba8:  bb 28 60 02  sll  %g1, 2, %i5
a00f1bac:  ba 17 40 0f  or  %i5, %o7, %i5
a00f1bb0:  f8 07 40 00  ld  [ %i5 ], %i4
a00f1bb4:  b2 0f 00 18  and  %i4, %i0, %i1
a00f1bb8:  b6 06 e0 01  inc  %i3
a00f1bbc:  82 0e 60 ff  and  %i1, 0xff, %g1
a00f1bc0:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f1bc4:  c2 27 40 00  st  %g1, [ %i5 ]
a00f1bc8:  80 a7 20 07  cmp  %i4, 7
a00f1bcc:  18 80 00 44  bgu  0xa00f1cdc
a00f1bd0:  ba 07 00 1c  add  %i4, %i4, %i5
a00f1bd4:  f2 13 40 1d  lduh  [ %o5 + %i5 ], %i1
a00f1bd8:  82 06 40 1a  add  %i1, %i2, %g1
a00f1bdc:  bb 28 60 02  sll  %g1, 2, %i5
a00f1be0:  ba 17 40 0f  or  %i5, %o7, %i5
a00f1be4:  f8 07 40 00  ld  [ %i5 ], %i4
a00f1be8:  b2 0f 00 18  and  %i4, %i0, %i1
a00f1bec:  b6 06 e0 01  inc  %i3
a00f1bf0:  82 0e 60 ff  and  %i1, 0xff, %g1
a00f1bf4:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f1bf8:  c2 27 40 00  st  %g1, [ %i5 ]
a00f1bfc:  80 a7 20 07  cmp  %i4, 7
a00f1c00:  08 bf ff e8  bleu  0xa00f1ba0
a00f1c04:  ba 07 00 1c  add  %i4, %i4, %i5
a00f1c08:  30 80 00 35  b,a   0xa00f1cdc
a00f1c0c:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f1c10:  b8 13 63 1c  or  %o5, 0x31c, %i4	! 0x19a31c
a00f1c14:  b2 06 00 18  add  %i0, %i0, %i1
a00f1c18:  c2 17 00 19  lduh  [ %i4 + %i1 ], %g1
a00f1c1c:  b2 0b e0 ff  and  %o7, 0xff, %i1
a00f1c20:  82 00 40 19  add  %g1, %i1, %g1
a00f1c24:  b9 28 60 02  sll  %g1, 2, %i4
a00f1c28:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00f1c2c:  82 17 00 1d  or  %i4, %i5, %g1
a00f1c30:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f1c34:  c2 00 40 00  ld  [ %g1 ], %g1
a00f1c38:  80 a7 20 01  cmp  %i4, 1
a00f1c3c:  02 80 00 03  be  0xa00f1c48
a00f1c40:  b6 10 40 1a  or  %g1, %i2, %i3
a00f1c44:  b6 28 40 1a  andn  %g1, %i2, %i3
a00f1c48:  82 13 63 1c  or  %o5, 0x31c, %g1
a00f1c4c:  b4 06 00 18  add  %i0, %i0, %i2
a00f1c50:  f0 10 40 1a  lduh  [ %g1 + %i2 ], %i0
a00f1c54:  b8 06 00 19  add  %i0, %i1, %i4
a00f1c58:  83 2f 20 02  sll  %i4, 2, %g1
a00f1c5c:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00f1c60:  b0 10 40 1d  or  %g1, %i5, %i0
a00f1c64:  b4 0e e0 ff  and  %i3, 0xff, %i2
a00f1c68:  f4 26 00 00  st  %i2, [ %i0 ]
a00f1c6c:  30 80 00 1c  b,a   0xa00f1cdc
a00f1c70:  82 07 00 1c  add  %i4, %i4, %g1
a00f1c74:  f8 13 40 01  lduh  [ %o5 + %g1 ], %i4
a00f1c78:  b0 07 00 1a  add  %i4, %i2, %i0
a00f1c7c:  bb 2e 20 02  sll  %i0, 2, %i5
a00f1c80:  ba 17 40 0f  or  %i5, %o7, %i5
a00f1c84:  c2 07 40 00  ld  [ %i5 ], %g1
a00f1c88:  b8 10 40 19  or  %g1, %i1, %i4
a00f1c8c:  b0 0f 20 ff  and  %i4, 0xff, %i0
a00f1c90:  b6 06 e0 01  inc  %i3
a00f1c94:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f1c98:  f0 27 40 00  st  %i0, [ %i5 ]
a00f1c9c:  80 a7 20 07  cmp  %i4, 7
a00f1ca0:  18 80 00 0f  bgu  0xa00f1cdc
a00f1ca4:  82 07 00 1c  add  %i4, %i4, %g1
a00f1ca8:  f8 13 40 01  lduh  [ %o5 + %g1 ], %i4
a00f1cac:  b0 07 00 1a  add  %i4, %i2, %i0
a00f1cb0:  bb 2e 20 02  sll  %i0, 2, %i5
a00f1cb4:  ba 17 40 0f  or  %i5, %o7, %i5
a00f1cb8:  c2 07 40 00  ld  [ %i5 ], %g1
a00f1cbc:  b8 10 40 19  or  %g1, %i1, %i4
a00f1cc0:  b0 0f 20 ff  and  %i4, 0xff, %i0
a00f1cc4:  b6 06 e0 01  inc  %i3
a00f1cc8:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f1ccc:  f0 27 40 00  st  %i0, [ %i5 ]
a00f1cd0:  80 a7 20 07  cmp  %i4, 7
a00f1cd4:  08 bf ff e8  bleu  0xa00f1c74
a00f1cd8:  82 07 00 1c  add  %i4, %i4, %g1
a00f1cdc:  81 c7 e0 08  ret
a00f1ce0:  81 e8 00 00  restore
