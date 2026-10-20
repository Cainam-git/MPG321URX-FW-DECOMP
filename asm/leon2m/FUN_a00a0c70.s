# leon2m FUN_a00a0c70 0xa00a0c70-0xa00a0ee8 (632 bytes)
a00a0c70:  9d e3 bf 98  save  %sp, -104, %sp
a00a0c74:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00a0c78:  a2 14 22 90  or  %l0, 0x290, %l1	! 0xa802d290
a00a0c7c:  19 00 00 15  sethi  %hi(0x5400), %o4
a00a0c80:  da 14 61 f6  lduh  [ %l1 + 0x1f6 ], %o5
a00a0c84:  82 13 21 aa  or  %o4, 0x1aa, %g1
a00a0c88:  80 a3 40 01  cmp  %o5, %g1
a00a0c8c:  02 80 00 12  be  0xa00a0cd4
a00a0c90:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a00a0c94:  c2 13 63 f4  lduh  [ %o5 + 0x3f4 ], %g1	! 0xa802cff4
a00a0c98:  80 88 64 00  btst  0x400, %g1
a00a0c9c:  12 80 00 91  bne  0xa00a0ee0
a00a0ca0:  98 13 63 f4  or  %o5, 0x3f4, %o4
a00a0ca4:  d0 0c 61 a9  ldub  [ %l1 + 0x1a9 ], %o0
a00a0ca8:  80 a2 20 01  cmp  %o0, 1
a00a0cac:  22 80 00 3a  be,a   0xa00a0d94
a00a0cb0:  d2 0c 61 8a  ldub  [ %l1 + 0x18a ], %o1
a00a0cb4:  40 02 70 6e  call  0xa013ce6c
a00a0cb8:  90 10 20 00  clr  %o0
a00a0cbc:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00a0cc0:  80 a4 60 0c  cmp  %l1, 0xc
a00a0cc4:  12 80 00 87  bne  0xa00a0ee0
a00a0cc8:  9a 14 22 90  or  %l0, 0x290, %o5
a00a0ccc:  10 80 00 16  b  0xa00a0d24
a00a0cd0:  c2 0b 61 8a  ldub  [ %o5 + 0x18a ], %g1
a00a0cd4:  17 00 3f ff  sethi  %hi(0xfffc00), %o3
a00a0cd8:  d2 04 61 d4  ld  [ %l1 + 0x1d4 ], %o1
a00a0cdc:  94 12 e3 00  or  %o3, 0x300, %o2
a00a0ce0:  90 0a 40 0a  and  %o1, %o2, %o0
a00a0ce4:  98 13 21 00  or  %o4, 0x100, %o4
a00a0ce8:  80 a2 00 0c  cmp  %o0, %o4
a00a0cec:  12 bf ff f2  bne  0xa00a0cb4
a00a0cf0:  01 00 00 00  nop
a00a0cf4:  40 02 8e 2a  call  0xa014459c
a00a0cf8:  90 10 20 01  mov  1, %o0	! 0x1
a00a0cfc:  40 00 e1 4f  call  0xa00d9238
a00a0d00:  d0 2c 60 1e  stb  %o0, [ %l1 + 0x1e ]
a00a0d04:  90 10 20 04  mov  4, %o0
a00a0d08:  7f ff 7e e9  call  0xa00808ac
a00a0d0c:  92 10 20 00  clr  %o1
a00a0d10:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00a0d14:  e2 0b e0 8e  ldub  [ %o7 + 0x8e ], %l1	! 0xa802b08e
a00a0d18:  a0 14 60 02  or  %l1, 2, %l0
a00a0d1c:  10 80 00 71  b  0xa00a0ee0
a00a0d20:  e0 2b e0 8e  stb  %l0, [ %o7 + 0x8e ]
a00a0d24:  80 a0 60 00  cmp  %g1, 0
a00a0d28:  02 80 00 6e  be  0xa00a0ee0
a00a0d2c:  80 a0 60 01  cmp  %g1, 1
a00a0d30:  22 80 00 39  be,a   0xa00a0e14
a00a0d34:  de 03 61 1c  ld  [ %o5 + 0x11c ], %o7
a00a0d38:  a0 14 22 90  or  %l0, 0x290, %l0
a00a0d3c:  da 0c 21 8a  ldub  [ %l0 + 0x18a ], %o5
a00a0d40:  80 a3 60 06  cmp  %o5, 6
a00a0d44:  02 80 00 48  be  0xa00a0e64
a00a0d48:  01 00 00 00  nop
a00a0d4c:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a0d50:  80 a0 60 06  cmp  %g1, 6
a00a0d54:  02 80 00 2a  be  0xa00a0dfc
a00a0d58:  80 a0 60 09  cmp  %g1, 9
a00a0d5c:  02 80 00 56  be  0xa00a0eb4
a00a0d60:  01 00 00 00  nop
a00a0d64:  92 0b 60 ff  and  %o5, 0xff, %o1
a00a0d68:  80 a2 60 0a  cmp  %o1, 0xa
a00a0d6c:  02 80 00 4c  be  0xa00a0e9c
a00a0d70:  01 00 00 00  nop
a00a0d74:  40 00 60 42  call  0xa00b8e7c
a00a0d78:  90 10 20 00  clr  %o0	! 0x0
a00a0d7c:  e2 0c 21 8a  ldub  [ %l0 + 0x18a ], %l1
a00a0d80:  94 04 60 f9  add  %l1, 0xf9, %o2
a00a0d84:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00a0d88:  d4 24 23 ec  st  %o2, [ %l0 + 0x3ec ]	! 0xa802afec
a00a0d8c:  40 00 0e 07  call  0xa00a45a8
a00a0d90:  81 e8 00 00  restore
a00a0d94:  80 a2 60 02  cmp  %o1, 2
a00a0d98:  12 bf ff c7  bne  0xa00a0cb4
a00a0d9c:  1b 3f ff e0  sethi  %hi(0xffff8000), %o5
a00a0da0:  d6 13 20 04  lduh  [ %o4 + 4 ], %o3
a00a0da4:  a0 0a c0 0d  and  %o3, %o5, %l0
a00a0da8:  95 2c 20 10  sll  %l0, 0x10, %o2
a00a0dac:  9e 10 20 05  mov  5, %o7
a00a0db0:  80 a2 a0 00  cmp  %o2, 0
a00a0db4:  12 80 00 33  bne  0xa00a0e80
a00a0db8:  de 2b 20 0a  stb  %o7, [ %o4 + 0xa ]
a00a0dbc:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00a0dc0:  40 00 50 b0  call  0xa00b5080
a00a0dc4:  c0 24 23 ec  clr  [ %l0 + 0x3ec ]	! 0xa802afec
a00a0dc8:  40 00 40 60  call  0xa00b0f48
a00a0dcc:  01 00 00 00  nop
a00a0dd0:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00a0dd4:  d4 0a e0 8e  ldub  [ %o3 + 0x8e ], %o2	! 0xa802b08e
a00a0dd8:  90 12 a0 02  or  %o2, 2, %o0
a00a0ddc:  92 10 21 16  mov  0x116, %o1
a00a0de0:  d2 24 23 ec  st  %o1, [ %l0 + 0x3ec ]
a00a0de4:  d0 2a e0 8e  stb  %o0, [ %o3 + 0x8e ]
a00a0de8:  67 ff b1 e8  call  0x4008d588
a00a0dec:  c0 2c 61 aa  clrb  [ %l1 + 0x1aa ]
a00a0df0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00a0df4:  10 80 00 3b  b  0xa00a0ee0
a00a0df8:  d0 33 20 3c  sth  %o0, [ %o4 + 0x3c ]	! 0xa802d03c
a00a0dfc:  d8 04 21 f4  ld  [ %l0 + 0x1f4 ], %o4
a00a0e00:  80 a3 20 00  cmp  %o4, 0
a00a0e04:  06 80 00 37  bl  0xa00a0ee0
a00a0e08:  92 0b 60 ff  and  %o5, 0xff, %o1
a00a0e0c:  10 bf ff d8  b  0xa00a0d6c
a00a0e10:  80 a2 60 0a  cmp  %o1, 0xa
a00a0e14:  80 a3 e0 00  cmp  %o7, 0
a00a0e18:  06 80 00 32  bl  0xa00a0ee0
a00a0e1c:  01 00 00 00  nop
a00a0e20:  c2 03 60 b0  ld  [ %o5 + 0xb0 ], %g1
a00a0e24:  80 a0 60 00  cmp  %g1, 0
a00a0e28:  02 80 00 08  be  0xa00a0e48
a00a0e2c:  01 00 00 00  nop
a00a0e30:  40 00 df 6a  call  0xa00d8bd8
a00a0e34:  01 00 00 00  nop
a00a0e38:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00a0e3c:  80 a3 60 01  cmp  %o5, 1
a00a0e40:  02 80 00 28  be  0xa00a0ee0
a00a0e44:  01 00 00 00  nop
a00a0e48:  40 00 db c0  call  0xa00d7d48
a00a0e4c:  01 00 00 00  nop
a00a0e50:  80 a2 20 00  cmp  %o0, 0
a00a0e54:  12 80 00 23  bne  0xa00a0ee0
a00a0e58:  a0 14 22 90  or  %l0, 0x290, %l0
a00a0e5c:  10 bf ff b9  b  0xa00a0d40
a00a0e60:  da 0c 21 8a  ldub  [ %l0 + 0x18a ], %o5
a00a0e64:  40 00 db b9  call  0xa00d7d48
a00a0e68:  01 00 00 00  nop
a00a0e6c:  80 a2 20 00  cmp  %o0, 0
a00a0e70:  12 80 00 1c  bne  0xa00a0ee0
a00a0e74:  01 00 00 00  nop
a00a0e78:  10 bf ff b5  b  0xa00a0d4c
a00a0e7c:  da 0c 21 8a  ldub  [ %l0 + 0x18a ], %o5
a00a0e80:  82 12 e4 00  or  %o3, 0x400, %g1
a00a0e84:  c2 33 20 04  sth  %g1, [ %o4 + 4 ]
a00a0e88:  90 10 20 04  mov  4, %o0
a00a0e8c:  7f ff 7e 88  call  0xa00808ac
a00a0e90:  92 10 20 00  clr  %o1
a00a0e94:  10 bf ff cb  b  0xa00a0dc0
a00a0e98:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00a0e9c:  40 00 db ab  call  0xa00d7d48
a00a0ea0:  01 00 00 00  nop
a00a0ea4:  80 a2 20 00  cmp  %o0, 0
a00a0ea8:  02 bf ff b3  be  0xa00a0d74
a00a0eac:  01 00 00 00  nop
a00a0eb0:  30 80 00 0c  b,a   0xa00a0ee0
a00a0eb4:  40 00 db a5  call  0xa00d7d48
a00a0eb8:  01 00 00 00  nop
a00a0ebc:  80 a2 20 00  cmp  %o0, 0
a00a0ec0:  12 80 00 08  bne  0xa00a0ee0
a00a0ec4:  17 00 00 20  sethi  %hi(0x8000), %o3
a00a0ec8:  d0 04 21 74  ld  [ %l0 + 0x174 ], %o0
a00a0ecc:  80 8a 00 0b  btst  %o0, %o3
a00a0ed0:  12 80 00 04  bne  0xa00a0ee0
a00a0ed4:  01 00 00 00  nop
a00a0ed8:  10 bf ff a3  b  0xa00a0d64
a00a0edc:  da 0c 21 8a  ldub  [ %l0 + 0x18a ], %o5
a00a0ee0:  81 c7 e0 08  ret
a00a0ee4:  81 e8 00 00  restore
