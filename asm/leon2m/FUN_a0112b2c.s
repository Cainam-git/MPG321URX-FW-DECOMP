# leon2m FUN_a0112b2c 0xa0112b2c-0xa0112db0 (644 bytes)
a0112b2c:  9d e3 bf 98  save  %sp, -104, %sp
a0112b30:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a0112b34:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a0112b38:  d8 0c 61 8f  ldub  [ %l1 + 0x18f ], %o4
a0112b3c:  d6 0c a1 8e  ldub  [ %l2 + 0x18e ], %o3
a0112b40:  90 03 00 0c  add  %o4, %o4, %o0
a0112b44:  9e 02 c0 0b  add  %o3, %o3, %o7
a0112b48:  82 02 00 0c  add  %o0, %o4, %g1
a0112b4c:  94 03 c0 0b  add  %o7, %o3, %o2
a0112b50:  93 28 60 05  sll  %g1, 5, %o1
a0112b54:  9b 2a a0 06  sll  %o2, 6, %o5
a0112b58:  21 00 06 9a  sethi  %hi(0x1a6800), %l0
a0112b5c:  a0 14 23 34  or  %l0, 0x334, %l0	! 0x1a6b34
a0112b60:  90 02 40 0d  add  %o1, %o5, %o0
a0112b64:  9e 02 00 10  add  %o0, %l0, %o7
a0112b68:  d2 02 00 10  ld  [ %o0 + %l0 ], %o1
a0112b6c:  d6 03 e0 08  ld  [ %o7 + 8 ], %o3
a0112b70:  d4 03 e0 04  ld  [ %o7 + 4 ], %o2
a0112b74:  7f ff ff 9c  call  0xa01129e4
a0112b78:  90 10 20 00  clr  %o0
a0112b7c:  d8 0c 61 8f  ldub  [ %l1 + 0x18f ], %o4
a0112b80:  d6 0c a1 8e  ldub  [ %l2 + 0x18e ], %o3
a0112b84:  94 03 00 0c  add  %o4, %o4, %o2
a0112b88:  9a 02 c0 0b  add  %o3, %o3, %o5
a0112b8c:  82 02 80 0c  add  %o2, %o4, %g1
a0112b90:  92 03 40 0b  add  %o5, %o3, %o1
a0112b94:  91 28 60 05  sll  %g1, 5, %o0
a0112b98:  9f 2a 60 06  sll  %o1, 6, %o7
a0112b9c:  94 02 00 0f  add  %o0, %o7, %o2
a0112ba0:  9a 02 80 10  add  %o2, %l0, %o5
a0112ba4:  d6 03 60 14  ld  [ %o5 + 0x14 ], %o3
a0112ba8:  d2 03 60 0c  ld  [ %o5 + 0xc ], %o1
a0112bac:  d4 03 60 10  ld  [ %o5 + 0x10 ], %o2
a0112bb0:  7f ff ff 8d  call  0xa01129e4
a0112bb4:  90 10 20 01  mov  1, %o0
a0112bb8:  d8 0c 61 8f  ldub  [ %l1 + 0x18f ], %o4
a0112bbc:  d6 0c a1 8e  ldub  [ %l2 + 0x18e ], %o3
a0112bc0:  92 03 00 0c  add  %o4, %o4, %o1
a0112bc4:  9e 02 c0 0b  add  %o3, %o3, %o7
a0112bc8:  82 02 40 0c  add  %o1, %o4, %g1
a0112bcc:  90 03 c0 0b  add  %o7, %o3, %o0
a0112bd0:  95 28 60 05  sll  %g1, 5, %o2
a0112bd4:  9b 2a 20 06  sll  %o0, 6, %o5
a0112bd8:  92 02 80 0d  add  %o2, %o5, %o1
a0112bdc:  9e 02 40 10  add  %o1, %l0, %o7
a0112be0:  d6 03 e0 20  ld  [ %o7 + 0x20 ], %o3
a0112be4:  d2 03 e0 18  ld  [ %o7 + 0x18 ], %o1
a0112be8:  d4 03 e0 1c  ld  [ %o7 + 0x1c ], %o2
a0112bec:  7f ff ff 7e  call  0xa01129e4
a0112bf0:  90 10 20 02  mov  2, %o0
a0112bf4:  d8 0c 61 8f  ldub  [ %l1 + 0x18f ], %o4
a0112bf8:  d6 0c a1 8e  ldub  [ %l2 + 0x18e ], %o3
a0112bfc:  90 03 00 0c  add  %o4, %o4, %o0
a0112c00:  9a 02 c0 0b  add  %o3, %o3, %o5
a0112c04:  82 02 00 0c  add  %o0, %o4, %g1
a0112c08:  94 03 40 0b  add  %o5, %o3, %o2
a0112c0c:  93 28 60 05  sll  %g1, 5, %o1
a0112c10:  9f 2a a0 06  sll  %o2, 6, %o7
a0112c14:  90 02 40 0f  add  %o1, %o7, %o0
a0112c18:  9a 02 00 10  add  %o0, %l0, %o5
a0112c1c:  d6 03 60 2c  ld  [ %o5 + 0x2c ], %o3
a0112c20:  d2 03 60 24  ld  [ %o5 + 0x24 ], %o1
a0112c24:  d4 03 60 28  ld  [ %o5 + 0x28 ], %o2
a0112c28:  7f ff ff 6f  call  0xa01129e4
a0112c2c:  90 10 20 03  mov  3, %o0
a0112c30:  d8 0c 61 8f  ldub  [ %l1 + 0x18f ], %o4
a0112c34:  d6 0c a1 8e  ldub  [ %l2 + 0x18e ], %o3
a0112c38:  94 03 00 0c  add  %o4, %o4, %o2
a0112c3c:  9e 02 c0 0b  add  %o3, %o3, %o7
a0112c40:  82 02 80 0c  add  %o2, %o4, %g1
a0112c44:  92 03 c0 0b  add  %o7, %o3, %o1
a0112c48:  91 28 60 05  sll  %g1, 5, %o0
a0112c4c:  9b 2a 60 06  sll  %o1, 6, %o5
a0112c50:  94 02 00 0d  add  %o0, %o5, %o2
a0112c54:  9e 02 80 10  add  %o2, %l0, %o7
a0112c58:  d6 03 e0 38  ld  [ %o7 + 0x38 ], %o3
a0112c5c:  d2 03 e0 30  ld  [ %o7 + 0x30 ], %o1
a0112c60:  d4 03 e0 34  ld  [ %o7 + 0x34 ], %o2
a0112c64:  7f ff ff 60  call  0xa01129e4
a0112c68:  90 10 20 04  mov  4, %o0
a0112c6c:  d8 0c 61 8f  ldub  [ %l1 + 0x18f ], %o4
a0112c70:  d6 0c a1 8e  ldub  [ %l2 + 0x18e ], %o3
a0112c74:  92 03 00 0c  add  %o4, %o4, %o1
a0112c78:  9a 02 c0 0b  add  %o3, %o3, %o5
a0112c7c:  82 02 40 0c  add  %o1, %o4, %g1
a0112c80:  90 03 40 0b  add  %o5, %o3, %o0
a0112c84:  95 28 60 05  sll  %g1, 5, %o2
a0112c88:  9f 2a 20 06  sll  %o0, 6, %o7
a0112c8c:  92 02 80 0f  add  %o2, %o7, %o1
a0112c90:  9a 02 40 10  add  %o1, %l0, %o5
a0112c94:  d2 03 60 3c  ld  [ %o5 + 0x3c ], %o1
a0112c98:  90 10 20 05  mov  5, %o0
a0112c9c:  94 10 20 00  clr  %o2
a0112ca0:  7f ff ff 51  call  0xa01129e4
a0112ca4:  96 10 20 00  clr  %o3
a0112ca8:  d8 0c 61 8f  ldub  [ %l1 + 0x18f ], %o4
a0112cac:  d6 0c a1 8e  ldub  [ %l2 + 0x18e ], %o3
a0112cb0:  90 03 00 0c  add  %o4, %o4, %o0
a0112cb4:  9e 02 c0 0b  add  %o3, %o3, %o7
a0112cb8:  82 02 00 0c  add  %o0, %o4, %g1
a0112cbc:  94 03 c0 0b  add  %o7, %o3, %o2
a0112cc0:  93 28 60 05  sll  %g1, 5, %o1
a0112cc4:  9b 2a a0 06  sll  %o2, 6, %o5
a0112cc8:  90 02 40 0d  add  %o1, %o5, %o0
a0112ccc:  9e 02 00 10  add  %o0, %l0, %o7
a0112cd0:  d4 03 e0 44  ld  [ %o7 + 0x44 ], %o2
a0112cd4:  d2 03 e0 40  ld  [ %o7 + 0x40 ], %o1
a0112cd8:  90 10 20 0a  mov  0xa, %o0
a0112cdc:  7f ff ff 42  call  0xa01129e4
a0112ce0:  96 10 20 00  clr  %o3
a0112ce4:  d8 0c 61 8f  ldub  [ %l1 + 0x18f ], %o4
a0112ce8:  d6 0c a1 8e  ldub  [ %l2 + 0x18e ], %o3
a0112cec:  94 03 00 0c  add  %o4, %o4, %o2
a0112cf0:  9a 02 c0 0b  add  %o3, %o3, %o5
a0112cf4:  82 02 80 0c  add  %o2, %o4, %g1
a0112cf8:  92 03 40 0b  add  %o5, %o3, %o1
a0112cfc:  91 28 60 05  sll  %g1, 5, %o0
a0112d00:  9f 2a 60 06  sll  %o1, 6, %o7
a0112d04:  94 02 00 0f  add  %o0, %o7, %o2
a0112d08:  9a 02 80 10  add  %o2, %l0, %o5
a0112d0c:  d4 03 60 4c  ld  [ %o5 + 0x4c ], %o2
a0112d10:  d2 03 60 48  ld  [ %o5 + 0x48 ], %o1
a0112d14:  90 10 20 0b  mov  0xb, %o0
a0112d18:  7f ff ff 33  call  0xa01129e4
a0112d1c:  96 10 20 00  clr  %o3
a0112d20:  d8 0c 61 8f  ldub  [ %l1 + 0x18f ], %o4
a0112d24:  d6 0c a1 8e  ldub  [ %l2 + 0x18e ], %o3
a0112d28:  92 03 00 0c  add  %o4, %o4, %o1
a0112d2c:  9e 02 c0 0b  add  %o3, %o3, %o7
a0112d30:  82 02 40 0c  add  %o1, %o4, %g1
a0112d34:  90 03 c0 0b  add  %o7, %o3, %o0
a0112d38:  95 28 60 05  sll  %g1, 5, %o2
a0112d3c:  9b 2a 20 06  sll  %o0, 6, %o5
a0112d40:  92 02 80 0d  add  %o2, %o5, %o1
a0112d44:  9e 02 40 10  add  %o1, %l0, %o7
a0112d48:  d2 03 e0 50  ld  [ %o7 + 0x50 ], %o1
a0112d4c:  90 10 20 13  mov  0x13, %o0
a0112d50:  94 10 20 00  clr  %o2
a0112d54:  7f ff ff 24  call  0xa01129e4
a0112d58:  96 10 20 00  clr  %o3
a0112d5c:  d8 0c 61 8f  ldub  [ %l1 + 0x18f ], %o4
a0112d60:  d6 0c a1 8e  ldub  [ %l2 + 0x18e ], %o3
a0112d64:  82 03 00 0c  add  %o4, %o4, %g1
a0112d68:  90 02 c0 0b  add  %o3, %o3, %o0
a0112d6c:  94 00 40 0c  add  %g1, %o4, %o2
a0112d70:  9a 02 00 0b  add  %o0, %o3, %o5
a0112d74:  a3 2a a0 05  sll  %o2, 5, %l1
a0112d78:  a5 2b 60 06  sll  %o5, 6, %l2
a0112d7c:  9e 04 40 12  add  %l1, %l2, %o7
a0112d80:  92 03 c0 10  add  %o7, %l0, %o1
a0112d84:  d4 02 60 5c  ld  [ %o1 + 0x5c ], %o2
a0112d88:  d8 02 60 54  ld  [ %o1 + 0x54 ], %o4
a0112d8c:  d6 02 60 58  ld  [ %o1 + 0x58 ], %o3
a0112d90:  11 2a 00 b2  sethi  %hi(0xa802c800), %o0
a0112d94:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0112d98:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a0112d9c:  d8 22 21 94  st  %o4, [ %o0 + 0x194 ]
a0112da0:  d6 20 61 98  st  %o3, [ %g1 + 0x198 ]
a0112da4:  d4 23 61 90  st  %o2, [ %o5 + 0x190 ]
a0112da8:  81 c7 e0 08  ret
a0112dac:  81 e8 00 00  restore
