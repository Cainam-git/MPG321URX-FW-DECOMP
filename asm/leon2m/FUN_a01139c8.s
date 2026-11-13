# leon2m FUN_a01139c8 0xa01139c8-0xa0113cd8 (784 bytes)
a01139c8:  9d e3 bf 98  save  %sp, -104, %sp
a01139cc:  11 33 c0 47  sethi  %hi(0xcf011c00), %o0
a01139d0:  aa 10 00 19  mov  %i1, %l5
a01139d4:  94 10 00 18  mov  %i0, %o2
a01139d8:  ac 10 00 1a  mov  %i2, %l6
a01139dc:  ae 10 00 1b  mov  %i3, %l7
a01139e0:  b2 10 20 00  clr  %i1
a01139e4:  a4 10 20 00  clr  %l2
a01139e8:  9e 10 20 00  clr  %o7
a01139ec:  96 10 20 00  clr  %o3
a01139f0:  98 10 20 00  clr  %o4
a01139f4:  9a 10 20 00  clr  %o5
a01139f8:  a6 10 20 00  clr  %l3
a01139fc:  a8 12 23 90  or  %o0, 0x390, %l4
a0113a00:  b4 12 23 a0  or  %o0, 0x3a0, %i2
a0113a04:  d4 26 80 00  st  %o2, [ %i2 ]
a0113a08:  b8 12 23 a4  or  %o0, 0x3a4, %i4
a0113a0c:  b1 32 a0 08  srl  %o2, 8, %i0
a0113a10:  f0 27 00 00  st  %i0, [ %i4 ]
a0113a14:  ba 12 23 a8  or  %o0, 0x3a8, %i5
a0113a18:  83 32 a0 10  srl  %o2, 0x10, %g1
a0113a1c:  c2 27 40 00  st  %g1, [ %i5 ]
a0113a20:  b4 12 23 ac  or  %o0, 0x3ac, %i2
a0113a24:  b7 32 a0 18  srl  %o2, 0x18, %i3
a0113a28:  f6 26 80 00  st  %i3, [ %i2 ]
a0113a2c:  b8 10 20 80  mov  0x80, %i4
a0113a30:  b0 12 23 84  or  %o0, 0x384, %i0
a0113a34:  f8 26 00 00  st  %i4, [ %i0 ]
a0113a38:  ba 12 23 8c  or  %o0, 0x38c, %i5
a0113a3c:  f8 27 40 00  st  %i4, [ %i5 ]
a0113a40:  c2 05 00 00  ld  [ %l4 ], %g1
a0113a44:  80 a0 60 80  cmp  %g1, 0x80
a0113a48:  02 80 00 0b  be  0xa0113a74
a0113a4c:  ba 10 3f ff  mov  -1, %i5
a0113a50:  ba 07 7f ff  add  %i5, -1, %i5
a0113a54:  b7 2f 60 10  sll  %i5, 0x10, %i3
a0113a58:  80 a6 e0 00  cmp  %i3, 0
a0113a5c:  02 80 00 07  be  0xa0113a78
a0113a60:  b7 2c e0 10  sll  %l3, 0x10, %i3
a0113a64:  c2 05 00 00  ld  [ %l4 ], %g1
a0113a68:  80 a0 60 80  cmp  %g1, 0x80
a0113a6c:  12 bf ff fa  bne  0xa0113a54
a0113a70:  ba 07 7f ff  add  %i5, -1, %i5
a0113a74:  b7 2c e0 10  sll  %l3, 0x10, %i3
a0113a78:  b1 36 e0 10  srl  %i3, 0x10, %i0
a0113a7c:  b9 2e 20 13  sll  %i0, 0x13, %i4
a0113a80:  b5 2e 20 03  sll  %i0, 3, %i2
a0113a84:  bb 37 20 10  srl  %i4, 0x10, %i5
a0113a88:  b8 06 a0 08  add  %i2, 8, %i4
a0113a8c:  80 a7 40 1c  cmp  %i5, %i4
a0113a90:  16 80 00 89  bge  0xa0113cb4
a0113a94:  b0 10 00 1a  mov  %i2, %i0
a0113a98:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a0113a9c:  e0 00 63 18  ld  [ %g1 + 0x318 ], %l0	! 0x1a2f18
a0113aa0:  92 10 00 1c  mov  %i4, %o1
a0113aa4:  10 80 00 0c  b  0xa0113ad4
a0113aa8:  a2 10 00 10  mov  %l0, %l1
a0113aac:  04 80 00 43  ble  0xa0113bb8
a0113ab0:  80 a0 60 02  cmp  %g1, 2
a0113ab4:  02 80 00 21  be  0xa0113b38
a0113ab8:  b8 06 60 01  add  %i1, 1, %i4
a0113abc:  b6 06 20 01  add  %i0, 1, %i3
a0113ac0:  b5 2e e0 10  sll  %i3, 0x10, %i2
a0113ac4:  b1 36 a0 10  srl  %i2, 0x10, %i0
a0113ac8:  80 a6 00 09  cmp  %i0, %o1
a0113acc:  16 80 00 7a  bge  0xa0113cb4
a0113ad0:  b0 10 00 1b  mov  %i3, %i0
a0113ad4:  82 0b 60 ff  and  %o5, 0xff, %g1
a0113ad8:  80 a0 60 01  cmp  %g1, 1
a0113adc:  12 bf ff f4  bne  0xa0113aac
a0113ae0:  01 00 00 00  nop
a0113ae4:  f6 04 00 00  ld  [ %l0 ], %i3
a0113ae8:  b2 06 60 01  inc  %i1
a0113aec:  f8 04 00 00  ld  [ %l0 ], %i4
a0113af0:  82 0e 60 ff  and  %i1, 0xff, %g1
a0113af4:  b6 02 c0 1b  add  %o3, %i3, %i3
a0113af8:  80 a0 60 08  cmp  %g1, 8
a0113afc:  02 80 00 44  be  0xa0113c0c
a0113b00:  9e 03 c0 1c  add  %o7, %i4, %o7
a0113b04:  c2 04 00 00  ld  [ %l0 ], %g1
a0113b08:  f4 04 00 00  ld  [ %l0 ], %i2
a0113b0c:  98 03 00 01  add  %o4, %g1, %o4
a0113b10:  96 06 c0 1a  add  %i3, %i2, %o3
a0113b14:  9a 03 60 01  inc  %o5
a0113b18:  b6 06 20 01  add  %i0, 1, %i3
a0113b1c:  b5 2e e0 10  sll  %i3, 0x10, %i2
a0113b20:  b1 36 a0 10  srl  %i2, 0x10, %i0
a0113b24:  80 a6 00 09  cmp  %i0, %o1
a0113b28:  06 bf ff eb  bl  0xa0113ad4
a0113b2c:  b0 10 00 1b  mov  %i3, %i0
a0113b30:  10 80 00 62  b  0xa0113cb8
a0113b34:  ba 04 e0 01  add  %l3, 1, %i5
a0113b38:  f2 04 40 00  ld  [ %l1 ], %i1
a0113b3c:  b6 0f 20 ff  and  %i4, 0xff, %i3
a0113b40:  80 a6 e0 08  cmp  %i3, 8
a0113b44:  02 80 00 40  be  0xa0113c44
a0113b48:  b4 03 c0 19  add  %o7, %i1, %i2
a0113b4c:  f6 04 40 00  ld  [ %l1 ], %i3
a0113b50:  c2 04 40 00  ld  [ %l1 ], %g1
a0113b54:  b2 07 20 01  add  %i4, 1, %i1
a0113b58:  fa 04 40 00  ld  [ %l1 ], %i5
a0113b5c:  b8 0e 60 ff  and  %i1, 0xff, %i4
a0113b60:  98 03 00 1b  add  %o4, %i3, %o4
a0113b64:  96 02 c0 01  add  %o3, %g1, %o3
a0113b68:  80 a7 20 08  cmp  %i4, 8
a0113b6c:  02 80 00 04  be  0xa0113b7c
a0113b70:  9e 06 80 1d  add  %i2, %i5, %o7
a0113b74:  10 bf ff d2  b  0xa0113abc
a0113b78:  9a 10 20 00  clr  %o5
a0113b7c:  b9 2c a0 10  sll  %l2, 0x10, %i4
a0113b80:  b3 37 20 10  srl  %i4, 0x10, %i1
a0113b84:  83 33 e0 03  srl  %o7, 3, %g1
a0113b88:  c2 2e 40 15  stb  %g1, [ %i1 + %l5 ]
a0113b8c:  bb 32 e0 03  srl  %o3, 3, %i5
a0113b90:  fa 2e 40 16  stb  %i5, [ %i1 + %l6 ]
a0113b94:  b5 33 20 03  srl  %o4, 3, %i2
a0113b98:  f4 2e 40 17  stb  %i2, [ %i1 + %l7 ]
a0113b9c:  b2 10 20 00  clr  %i1
a0113ba0:  a4 04 a0 01  inc  %l2
a0113ba4:  98 10 20 00  clr  %o4
a0113ba8:  96 10 20 00  clr  %o3
a0113bac:  9e 10 20 00  clr  %o7
a0113bb0:  10 bf ff c3  b  0xa0113abc
a0113bb4:  9a 10 20 00  clr  %o5
a0113bb8:  80 a0 60 00  cmp  %g1, 0
a0113bbc:  12 bf ff c1  bne  0xa0113ac0
a0113bc0:  b6 06 20 01  add  %i0, 1, %i3
a0113bc4:  39 00 06 8b  sethi  %hi(0x1a2c00), %i4
a0113bc8:  c2 07 23 18  ld  [ %i4 + 0x318 ], %g1	! 0x1a2f18
a0113bcc:  f6 00 40 00  ld  [ %g1 ], %i3
a0113bd0:  f4 00 40 00  ld  [ %g1 ], %i2
a0113bd4:  b2 06 60 01  inc  %i1
a0113bd8:  fa 00 40 00  ld  [ %g1 ], %i5
a0113bdc:  b8 0e 60 ff  and  %i1, 0xff, %i4
a0113be0:  b6 03 00 1b  add  %o4, %i3, %i3
a0113be4:  96 02 c0 1a  add  %o3, %i2, %o3
a0113be8:  80 a7 20 08  cmp  %i4, 8
a0113bec:  02 80 00 24  be  0xa0113c7c
a0113bf0:  9e 03 c0 1d  add  %o7, %i5, %o7
a0113bf4:  35 33 c0 47  sethi  %hi(0xcf011c00), %i2
a0113bf8:  98 16 a3 94  or  %i2, 0x394, %o4	! 0xcf011f94
a0113bfc:  fa 03 00 00  ld  [ %o4 ], %i5
a0113c00:  98 06 c0 1d  add  %i3, %i5, %o4
a0113c04:  10 bf ff c5  b  0xa0113b18
a0113c08:  9a 03 60 01  inc  %o5
a0113c0c:  b9 2c a0 10  sll  %l2, 0x10, %i4
a0113c10:  b3 37 20 10  srl  %i4, 0x10, %i1
a0113c14:  bb 33 e0 03  srl  %o7, 3, %i5
a0113c18:  fa 2e 40 15  stb  %i5, [ %i1 + %l5 ]
a0113c1c:  83 36 e0 03  srl  %i3, 3, %g1
a0113c20:  c2 2e 40 16  stb  %g1, [ %i1 + %l6 ]
a0113c24:  b5 33 20 03  srl  %o4, 3, %i2
a0113c28:  f4 2e 40 17  stb  %i2, [ %i1 + %l7 ]
a0113c2c:  b2 10 20 00  clr  %i1
a0113c30:  a4 04 a0 01  inc  %l2
a0113c34:  98 10 20 00  clr  %o4
a0113c38:  b6 10 20 00  clr  %i3
a0113c3c:  10 bf ff b2  b  0xa0113b04
a0113c40:  9e 10 20 00  clr  %o7
a0113c44:  b7 2c a0 10  sll  %l2, 0x10, %i3
a0113c48:  b9 36 e0 10  srl  %i3, 0x10, %i4
a0113c4c:  83 36 a0 03  srl  %i2, 3, %g1
a0113c50:  c2 2f 00 15  stb  %g1, [ %i4 + %l5 ]
a0113c54:  b5 32 e0 03  srl  %o3, 3, %i2
a0113c58:  f4 2f 00 16  stb  %i2, [ %i4 + %l6 ]
a0113c5c:  bb 33 20 03  srl  %o4, 3, %i5
a0113c60:  fa 2f 00 17  stb  %i5, [ %i4 + %l7 ]
a0113c64:  b8 10 20 00  clr  %i4
a0113c68:  a4 04 a0 01  inc  %l2
a0113c6c:  98 10 20 00  clr  %o4
a0113c70:  96 10 20 00  clr  %o3
a0113c74:  10 bf ff b6  b  0xa0113b4c
a0113c78:  b4 10 20 00  clr  %i2
a0113c7c:  b9 2c a0 10  sll  %l2, 0x10, %i4
a0113c80:  b3 37 20 10  srl  %i4, 0x10, %i1
a0113c84:  83 33 e0 03  srl  %o7, 3, %g1
a0113c88:  c2 2e 40 15  stb  %g1, [ %i1 + %l5 ]
a0113c8c:  b5 32 e0 03  srl  %o3, 3, %i2
a0113c90:  f4 2e 40 16  stb  %i2, [ %i1 + %l6 ]
a0113c94:  bb 36 e0 03  srl  %i3, 3, %i5
a0113c98:  fa 2e 40 17  stb  %i5, [ %i1 + %l7 ]
a0113c9c:  b2 10 20 00  clr  %i1
a0113ca0:  a4 04 a0 01  inc  %l2
a0113ca4:  b6 10 20 00  clr  %i3
a0113ca8:  96 10 20 00  clr  %o3
a0113cac:  10 bf ff d2  b  0xa0113bf4
a0113cb0:  9e 10 20 00  clr  %o7
a0113cb4:  ba 04 e0 01  add  %l3, 1, %i5
a0113cb8:  b9 2f 60 10  sll  %i5, 0x10, %i4
a0113cbc:  83 37 20 10  srl  %i4, 0x10, %g1
a0113cc0:  80 a0 60 0c  cmp  %g1, 0xc
a0113cc4:  94 02 a0 01  inc  %o2
a0113cc8:  0a bf ff 4e  bcs  0xa0113a00
a0113ccc:  a6 10 00 1d  mov  %i5, %l3
a0113cd0:  81 c7 e0 08  ret
a0113cd4:  81 e8 00 00  restore
