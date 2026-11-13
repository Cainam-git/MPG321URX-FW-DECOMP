# leon2m FUN_a0129c64 0xa0129c64-0xa0129edc (632 bytes)
a0129c64:  9d e3 bf 98  save  %sp, -104, %sp
a0129c68:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0129c6c:  82 10 63 d0  or  %g1, 0x3d0, %g1	! 0xa802e3d0
a0129c70:  da 00 60 38  ld  [ %g1 + 0x38 ], %o5
a0129c74:  80 a3 60 01  cmp  %o5, 1
a0129c78:  02 80 00 88  be  0xa0129e98
a0129c7c:  80 a3 60 02  cmp  %o5, 2
a0129c80:  22 80 00 87  be,a   0xa0129e9c
a0129c84:  e2 08 60 08  ldub  [ %g1 + 8 ], %l1
a0129c88:  e0 08 60 08  ldub  [ %g1 + 8 ], %l0
a0129c8c:  a5 2c 20 03  sll  %l0, 3, %l2
a0129c90:  a2 24 80 10  sub  %l2, %l0, %l1
a0129c94:  9f 2c 60 07  sll  %l1, 7, %o7
a0129c98:  19 14 7a e1  sethi  %hi(0x51eb8400), %o4
a0129c9c:  9a 03 c0 10  add  %o7, %l0, %o5
a0129ca0:  96 13 21 1f  or  %o4, 0x11f, %o3
a0129ca4:  94 03 60 32  add  %o5, 0x32, %o2
a0129ca8:  80 52 80 0b  umul  %o2, %o3, %g0
a0129cac:  93 40 00 00  rd  %y, %o1
a0129cb0:  91 32 60 05  srl  %o1, 5, %o0
a0129cb4:  82 02 20 7e  add  %o0, 0x7e, %g1
a0129cb8:  a5 30 60 02  srl  %g1, 2, %l2
a0129cbc:  19 2a 00 a9  sethi  %hi(0xa802a400), %o4
a0129cc0:  e4 2b 20 49  stb  %l2, [ %o4 + 0x49 ]	! 0xa802a449
a0129cc4:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a0129cc8:  d0 0a 62 02  ldub  [ %o1 + 0x202 ], %o0	! 0xa802ca02
a0129ccc:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a0129cd0:  82 10 20 7e  mov  0x7e, %g1
a0129cd4:  80 8a 20 01  btst  1, %o0
a0129cd8:  02 80 00 3a  be  0xa0129dc0
a0129cdc:  c2 2a a2 03  stb  %g1, [ %o2 + 0x203 ]
a0129ce0:  da 0b 20 49  ldub  [ %o4 + 0x49 ], %o5
a0129ce4:  9a 0b 60 ff  and  %o5, 0xff, %o5
a0129ce8:  c2 0a a2 03  ldub  [ %o2 + 0x203 ], %g1
a0129cec:  80 a3 40 01  cmp  %o5, %g1
a0129cf0:  2a 80 00 02  bcs,a   0xa0129cf8
a0129cf4:  9a 10 00 01  mov  %g1, %o5
a0129cf8:  17 2a 00 a9  sethi  %hi(0xa802a400), %o3
a0129cfc:  c2 0a e0 48  ldub  [ %o3 + 0x48 ], %g1	! 0xa802a448
a0129d00:  98 08 60 ff  and  %g1, 0xff, %o4
a0129d04:  80 a3 00 0d  cmp  %o4, %o5
a0129d08:  02 80 00 73  be  0xa0129ed4
a0129d0c:  01 00 00 00  nop
a0129d10:  38 80 00 37  bgu,a   0xa0129dec
a0129d14:  82 00 7f ff  add  %g1, -1, %g1
a0129d18:  82 00 60 01  inc  %g1
a0129d1c:  c2 2a e0 48  stb  %g1, [ %o3 + 0x48 ]
a0129d20:  d0 0a a2 03  ldub  [ %o2 + 0x203 ], %o0
a0129d24:  7f ff 5f 41  call  0xa0101a28
a0129d28:  d2 0a e0 48  ldub  [ %o3 + 0x48 ], %o1
a0129d2c:  7f ff 5f e2  call  0xa0101cb4
a0129d30:  25 2a 00 a9  sethi  %hi(0xa802a400), %l2
a0129d34:  96 0a 20 ff  and  %o0, 0xff, %o3
a0129d38:  d4 0c a0 4b  ldub  [ %l2 + 0x4b ], %o2
a0129d3c:  80 a2 c0 0a  cmp  %o3, %o2
a0129d40:  08 80 00 36  bleu  0xa0129e18
a0129d44:  a2 10 00 08  mov  %o0, %l1
a0129d48:  21 2a 00 a9  sethi  %hi(0xa802a400), %l0
a0129d4c:  d8 0c 20 4a  ldub  [ %l0 + 0x4a ], %o4	! 0xa802a44a
a0129d50:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0129d54:  80 a3 60 3f  cmp  %o5, 0x3f
a0129d58:  18 80 00 0c  bgu  0xa0129d88
a0129d5c:  03 00 06 8c  sethi  %hi(0x1a3000), %g1
a0129d60:  94 10 61 28  or  %g1, 0x128, %o2	! 0x1a3128
a0129d64:  d2 0a 80 0d  ldub  [ %o2 + %o5 ], %o1
a0129d68:  80 a2 40 0b  cmp  %o1, %o3
a0129d6c:  3a 80 00 07  bcc,a   0xa0129d88
a0129d70:  d8 2c 20 4a  stb  %o4, [ %l0 + 0x4a ]
a0129d74:  98 03 20 01  inc  %o4
a0129d78:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0129d7c:  80 a3 60 3f  cmp  %o5, 0x3f
a0129d80:  28 bf ff fa  bleu,a   0xa0129d68
a0129d84:  d2 0a 80 0d  ldub  [ %o2 + %o5 ], %o1
a0129d88:  80 a3 60 18  cmp  %o5, 0x18
a0129d8c:  28 80 00 37  bleu,a   0xa0129e68
a0129d90:  9a 10 20 18  mov  0x18, %o5
a0129d94:  d2 0c 20 4a  ldub  [ %l0 + 0x4a ], %o1
a0129d98:  83 2a 60 02  sll  %o1, 2, %g1
a0129d9c:  7f ff 5f 6b  call  0xa0101b48
a0129da0:  90 08 60 fc  and  %g1, 0xfc, %o0
a0129da4:  d4 0c 20 4a  ldub  [ %l0 + 0x4a ], %o2
a0129da8:  99 2a a0 02  sll  %o2, 2, %o4
a0129dac:  7f ff 5f 6d  call  0xa0101b60
a0129db0:  90 0b 20 fc  and  %o4, 0xfc, %o0
a0129db4:  e2 2c a0 4b  stb  %l1, [ %l2 + 0x4b ]
a0129db8:  67 fd 91 3b  call  0x4008e2a4
a0129dbc:  81 e8 00 00  restore
a0129dc0:  d0 0b 20 49  ldub  [ %o4 + 0x49 ], %o0
a0129dc4:  a5 2a 20 02  sll  %o0, 2, %l2
a0129dc8:  a0 04 80 08  add  %l2, %o0, %l0
a0129dcc:  a3 2c 20 04  sll  %l0, 4, %l1
a0129dd0:  1f 14 7a e1  sethi  %hi(0x51eb8400), %o7
a0129dd4:  9a 04 00 11  add  %l0, %l1, %o5
a0129dd8:  98 13 e1 1f  or  %o7, 0x11f, %o4
a0129ddc:  80 5b 40 0c  smul  %o5, %o4, %g0
a0129de0:  97 40 00 00  rd  %y, %o3
a0129de4:  10 bf ff c0  b  0xa0129ce4
a0129de8:  9b 32 e0 05  srl  %o3, 5, %o5
a0129dec:  c2 2a e0 48  stb  %g1, [ %o3 + 0x48 ]
a0129df0:  d0 0a a2 03  ldub  [ %o2 + 0x203 ], %o0
a0129df4:  7f ff 5f 0d  call  0xa0101a28
a0129df8:  d2 0a e0 48  ldub  [ %o3 + 0x48 ], %o1
a0129dfc:  7f ff 5f ae  call  0xa0101cb4
a0129e00:  25 2a 00 a9  sethi  %hi(0xa802a400), %l2
a0129e04:  96 0a 20 ff  and  %o0, 0xff, %o3
a0129e08:  d4 0c a0 4b  ldub  [ %l2 + 0x4b ], %o2
a0129e0c:  80 a2 c0 0a  cmp  %o3, %o2
a0129e10:  18 bf ff ce  bgu  0xa0129d48
a0129e14:  a2 10 00 08  mov  %o0, %l1
a0129e18:  21 2a 00 a9  sethi  %hi(0xa802a400), %l0
a0129e1c:  d8 0c 20 4a  ldub  [ %l0 + 0x4a ], %o4	! 0xa802a44a
a0129e20:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0129e24:  80 a3 60 17  cmp  %o5, 0x17
a0129e28:  08 bf ff d8  bleu  0xa0129d88
a0129e2c:  1f 00 06 8c  sethi  %hi(0x1a3000), %o7
a0129e30:  94 13 e1 28  or  %o7, 0x128, %o2	! 0x1a3128
a0129e34:  d0 0a 80 0d  ldub  [ %o2 + %o5 ], %o0
a0129e38:  80 a2 00 0b  cmp  %o0, %o3
a0129e3c:  2a 80 00 24  bcs,a   0xa0129ecc
a0129e40:  96 03 20 01  add  %o4, 1, %o3
a0129e44:  98 03 3f ff  add  %o4, -1, %o4
a0129e48:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0129e4c:  80 a3 60 17  cmp  %o5, 0x17
a0129e50:  38 bf ff fa  bgu,a   0xa0129e38
a0129e54:  d0 0a 80 0d  ldub  [ %o2 + %o5 ], %o0
a0129e58:  80 a3 60 18  cmp  %o5, 0x18
a0129e5c:  18 bf ff cf  bgu  0xa0129d98
a0129e60:  d2 0c 20 4a  ldub  [ %l0 + 0x4a ], %o1
a0129e64:  9a 10 20 18  mov  0x18, %o5
a0129e68:  da 2c 20 4a  stb  %o5, [ %l0 + 0x4a ]
a0129e6c:  d2 0c 20 4a  ldub  [ %l0 + 0x4a ], %o1
a0129e70:  83 2a 60 02  sll  %o1, 2, %g1
a0129e74:  7f ff 5f 35  call  0xa0101b48
a0129e78:  90 08 60 fc  and  %g1, 0xfc, %o0
a0129e7c:  d4 0c 20 4a  ldub  [ %l0 + 0x4a ], %o2
a0129e80:  99 2a a0 02  sll  %o2, 2, %o4
a0129e84:  7f ff 5f 37  call  0xa0101b60
a0129e88:  90 0b 20 fc  and  %o4, 0xfc, %o0
a0129e8c:  e2 2c a0 4b  stb  %l1, [ %l2 + 0x4b ]
a0129e90:  67 fd 91 05  call  0x4008e2a4
a0129e94:  81 e8 00 00  restore
a0129e98:  e2 08 60 08  ldub  [ %g1 + 8 ], %l1
a0129e9c:  a0 5c 62 5f  smul  %l1, 0x25f, %l0
a0129ea0:  1f 14 7a e1  sethi  %hi(0x51eb8400), %o7
a0129ea4:  98 04 20 32  add  %l0, 0x32, %o4
a0129ea8:  9a 13 e1 1f  or  %o7, 0x11f, %o5
a0129eac:  80 53 00 0d  umul  %o4, %o5, %g0
a0129eb0:  97 40 00 00  rd  %y, %o3
a0129eb4:  95 32 e0 05  srl  %o3, 5, %o2
a0129eb8:  92 02 a0 7e  add  %o2, 0x7e, %o1
a0129ebc:  91 32 60 02  srl  %o1, 2, %o0
a0129ec0:  19 2a 00 a9  sethi  %hi(0xa802a400), %o4
a0129ec4:  10 bf ff 80  b  0xa0129cc4
a0129ec8:  d0 2b 20 49  stb  %o0, [ %o4 + 0x49 ]	! 0xa802a449
a0129ecc:  10 bf ff af  b  0xa0129d88
a0129ed0:  d6 2c 20 4a  stb  %o3, [ %l0 + 0x4a ]
a0129ed4:  81 c7 e0 08  ret
a0129ed8:  81 e8 00 00  restore
