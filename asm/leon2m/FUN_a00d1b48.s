# leon2m FUN_a00d1b48 0xa00d1b48-0xa00d1ce4 (412 bytes)
a00d1b48:  9d e3 bf 98  save  %sp, -104, %sp
a00d1b4c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a00d1b50:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00d1b54:  11 00 3f ff  sethi  %hi(0xfffc00), %o0
a00d1b58:  96 13 21 a0  or  %o4, 0x1a0, %o3
a00d1b5c:  a0 12 a2 90  or  %o2, 0x290, %l0
a00d1b60:  b0 12 23 00  or  %o0, 0x300, %i0
a00d1b64:  d8 04 20 08  ld  [ %l0 + 8 ], %o4
a00d1b68:  13 00 00 40  sethi  %hi(0x10000), %o1
a00d1b6c:  9a 0b 00 18  and  %o4, %i0, %o5
a00d1b70:  82 12 62 00  or  %o1, 0x200, %g1
a00d1b74:  80 a3 40 01  cmp  %o5, %g1
a00d1b78:  02 80 00 14  be  0xa00d1bc8
a00d1b7c:  90 10 20 01  mov  1, %o0
a00d1b80:  9a 0b 00 18  and  %o4, %i0, %o5
a00d1b84:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a00d1b88:  31 00 00 41  sethi  %hi(0x10400), %i0
a00d1b8c:  80 a3 40 18  cmp  %o5, %i0
a00d1b90:  02 80 00 1b  be  0xa00d1bfc
a00d1b94:  96 12 61 a0  or  %o1, 0x1a0, %o3
a00d1b98:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00d1b9c:  03 00 00 15  sethi  %hi(0x5400), %g1
a00d1ba0:  b0 12 a2 74  or  %o2, 0x274, %i0
a00d1ba4:  da 14 21 f6  lduh  [ %l0 + 0x1f6 ], %o5
a00d1ba8:  9e 10 61 aa  or  %g1, 0x1aa, %o7
a00d1bac:  96 10 3f f6  mov  -10, %o3
a00d1bb0:  90 10 20 0b  mov  0xb, %o0
a00d1bb4:  92 10 20 00  clr  %o1
a00d1bb8:  80 a3 40 0f  cmp  %o5, %o7
a00d1bbc:  12 80 00 37  bne  0xa00d1c98
a00d1bc0:  d6 2e 20 10  stb  %o3, [ %i0 + 0x10 ]
a00d1bc4:  30 80 00 1f  b,a   0xa00d1c40
a00d1bc8:  c2 12 e0 3a  lduh  [ %o3 + 0x3a ], %g1
a00d1bcc:  9e 00 60 01  add  %g1, 1, %o7
a00d1bd0:  de 32 e0 3a  sth  %o7, [ %o3 + 0x3a ]
a00d1bd4:  40 01 cd e3  call  0xa0145360
a00d1bd8:  01 00 00 00  nop
a00d1bdc:  d8 04 20 08  ld  [ %l0 + 8 ], %o4
a00d1be0:  9a 0b 00 18  and  %o4, %i0, %o5
a00d1be4:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a00d1be8:  31 00 00 41  sethi  %hi(0x10400), %i0
a00d1bec:  96 12 61 a0  or  %o1, 0x1a0, %o3
a00d1bf0:  80 a3 40 18  cmp  %o5, %i0
a00d1bf4:  12 bf ff e9  bne  0xa00d1b98
a00d1bf8:  90 10 20 01  mov  1, %o0
a00d1bfc:  d8 12 e0 3a  lduh  [ %o3 + 0x3a ], %o4
a00d1c00:  94 03 20 01  add  %o4, 1, %o2
a00d1c04:  40 01 cd d7  call  0xa0145360
a00d1c08:  d4 32 e0 3a  sth  %o2, [ %o3 + 0x3a ]
a00d1c0c:  40 01 dd 92  call  0xa0149254
a00d1c10:  90 10 20 00  clr  %o0
a00d1c14:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00d1c18:  03 00 00 15  sethi  %hi(0x5400), %g1
a00d1c1c:  b0 12 a2 74  or  %o2, 0x274, %i0
a00d1c20:  da 14 21 f6  lduh  [ %l0 + 0x1f6 ], %o5
a00d1c24:  9e 10 61 aa  or  %g1, 0x1aa, %o7
a00d1c28:  96 10 3f f6  mov  -10, %o3
a00d1c2c:  90 10 20 0b  mov  0xb, %o0
a00d1c30:  92 10 20 00  clr  %o1
a00d1c34:  80 a3 40 0f  cmp  %o5, %o7
a00d1c38:  12 80 00 18  bne  0xa00d1c98
a00d1c3c:  d6 2e 20 10  stb  %o3, [ %i0 + 0x10 ]
a00d1c40:  40 01 d0 07  call  0xa0145c5c
a00d1c44:  01 00 00 00  nop
a00d1c48:  90 10 20 0a  mov  0xa, %o0	! 0xa
a00d1c4c:  40 01 d0 04  call  0xa0145c5c
a00d1c50:  92 10 20 00  clr  %o1
a00d1c54:  90 10 20 0d  mov  0xd, %o0
a00d1c58:  40 01 d0 01  call  0xa0145c5c
a00d1c5c:  92 10 20 00  clr  %o1
a00d1c60:  90 10 20 0c  mov  0xc, %o0
a00d1c64:  40 01 cf fe  call  0xa0145c5c
a00d1c68:  92 10 20 00  clr  %o1
a00d1c6c:  90 10 20 10  mov  0x10, %o0
a00d1c70:  40 01 cf fb  call  0xa0145c5c
a00d1c74:  92 10 20 00  clr  %o1
a00d1c78:  90 10 20 0e  mov  0xe, %o0
a00d1c7c:  40 01 cf f8  call  0xa0145c5c
a00d1c80:  92 10 20 00  clr  %o1
a00d1c84:  90 10 20 0f  mov  0xf, %o0
a00d1c88:  40 01 cf f5  call  0xa0145c5c
a00d1c8c:  92 10 20 00  clr  %o1
a00d1c90:  40 01 cd b4  call  0xa0145360
a00d1c94:  90 10 20 01  mov  1, %o0
a00d1c98:  40 00 29 d1  call  0xa00dc3dc
a00d1c9c:  01 00 00 00  nop
a00d1ca0:  92 10 00 10  mov  %l0, %o1
a00d1ca4:  94 10 20 00  clr  %o2
a00d1ca8:  96 10 21 fc  mov  0x1fc, %o3
a00d1cac:  40 01 e4 89  call  0xa014aed0
a00d1cb0:  90 10 20 30  mov  0x30, %o0
a00d1cb4:  7f ff f3 64  call  0xa00cea44
a00d1cb8:  c0 2e 20 10  clrb  [ %i0 + 0x10 ]
a00d1cbc:  13 3f ff ee  sethi  %hi(0xffffb800), %o1
a00d1cc0:  90 12 63 99  or  %o1, 0x399, %o0	! 0xffffbb99
a00d1cc4:  d0 34 21 f6  sth  %o0, [ %l0 + 0x1f6 ]
a00d1cc8:  92 10 00 18  mov  %i0, %o1
a00d1ccc:  90 10 20 30  mov  0x30, %o0
a00d1cd0:  94 10 22 e0  mov  0x2e0, %o2
a00d1cd4:  40 01 e4 7f  call  0xa014aed0
a00d1cd8:  96 10 20 1c  mov  0x1c, %o3
a00d1cdc:  81 c7 e0 08  ret
a00d1ce0:  91 e8 20 e0  restore  %g0, 0xe0, %o0
