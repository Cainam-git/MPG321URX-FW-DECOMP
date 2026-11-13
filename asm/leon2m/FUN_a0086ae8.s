# leon2m FUN_a0086ae8 0xa0086ae8-0xa0087020 (1336 bytes)
a0086ae8:  9d e3 bf 98  save  %sp, -104, %sp
a0086aec:  92 10 20 00  clr  %o1
a0086af0:  40 02 fc fe  call  0xa0145ee8
a0086af4:  90 10 20 00  clr  %o0
a0086af8:  40 02 fd 2d  call  0xa0145fac
a0086afc:  90 10 20 01  mov  1, %o0
a0086b00:  17 00 03 fd  sethi  %hi(0xff400), %o3
a0086b04:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0086b08:  90 12 e1 50  or  %o3, 0x150, %o0
a0086b0c:  92 10 00 18  mov  %i0, %o1
a0086b10:  40 01 61 98  call  0xa00df170
a0086b14:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a0086b18:  a0 14 62 90  or  %l1, 0x290, %l0	! 0xa802d290
a0086b1c:  d4 04 20 a8  ld  [ %l0 + 0xa8 ], %o2
a0086b20:  91 32 a0 07  srl  %o2, 7, %o0
a0086b24:  92 0a 20 01  and  %o0, 1, %o1
a0086b28:  40 03 0f 10  call  0xa014a768
a0086b2c:  90 10 20 0c  mov  0xc, %o0
a0086b30:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a0086b34:  93 30 60 07  srl  %g1, 7, %o1
a0086b38:  92 0a 60 01  and  %o1, 1, %o1
a0086b3c:  40 03 0f 0b  call  0xa014a768
a0086b40:  90 10 20 0d  mov  0xd, %o0
a0086b44:  80 a6 20 01  cmp  %i0, 1
a0086b48:  02 80 01 02  be  0xa0086f50
a0086b4c:  80 a6 20 04  cmp  %i0, 4
a0086b50:  02 80 00 e4  be  0xa0086ee0
a0086b54:  92 10 20 00  clr  %o1
a0086b58:  40 02 77 fa  call  0xa0124b40
a0086b5c:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a0086b60:  40 02 77 c2  call  0xa0124a68
a0086b64:  01 00 00 00  nop
a0086b68:  40 02 7b 7a  call  0xa0125950
a0086b6c:  01 00 00 00  nop
a0086b70:  40 02 7b 43  call  0xa012587c
a0086b74:  01 00 00 00  nop
a0086b78:  40 01 51 6d  call  0xa00db12c
a0086b7c:  90 10 20 00  clr  %o0	! 0x0
a0086b80:  40 02 7b 6d  call  0xa0125934
a0086b84:  01 00 00 00  nop
a0086b88:  68 00 19 86  call  0x4008d1a0
a0086b8c:  90 10 20 32  mov  0x32, %o0	! 0x32
a0086b90:  40 02 7b 62  call  0xa0125918
a0086b94:  01 00 00 00  nop
a0086b98:  40 02 7c 37  call  0xa0125c74
a0086b9c:  01 00 00 00  nop
a0086ba0:  40 02 7b 7a  call  0xa0125988
a0086ba4:  01 00 00 00  nop
a0086ba8:  40 02 7c 07  call  0xa0125bc4
a0086bac:  01 00 00 00  nop
a0086bb0:  40 02 7c 86  call  0xa0125dc8
a0086bb4:  01 00 00 00  nop
a0086bb8:  a0 14 62 90  or  %l1, 0x290, %l0
a0086bbc:  03 00 00 15  sethi  %hi(0x5400), %g1
a0086bc0:  b2 10 61 aa  or  %g1, 0x1aa, %i1	! 0x55aa
a0086bc4:  d2 14 21 f6  lduh  [ %l0 + 0x1f6 ], %o1
a0086bc8:  80 a2 40 19  cmp  %o1, %i1
a0086bcc:  02 80 00 c3  be  0xa0086ed8
a0086bd0:  90 10 20 02  mov  2, %o0
a0086bd4:  40 01 36 eb  call  0xa00d4780
a0086bd8:  01 00 00 00  nop
a0086bdc:  40 01 36 f5  call  0xa00d47b0
a0086be0:  01 00 00 00  nop
a0086be4:  40 01 36 5f  call  0xa00d4560
a0086be8:  01 00 00 00  nop
a0086bec:  40 01 36 83  call  0xa00d45f8
a0086bf0:  01 00 00 00  nop
a0086bf4:  40 01 36 8e  call  0xa00d462c
a0086bf8:  01 00 00 00  nop
a0086bfc:  40 01 4a cc  call  0xa00d972c
a0086c00:  01 00 00 00  nop
a0086c04:  7f ff f0 12  call  0xa0082c4c
a0086c08:  01 00 00 00  nop
a0086c0c:  80 8a 20 ff  btst  0xff, %o0
a0086c10:  02 80 00 a9  be  0xa0086eb4
a0086c14:  01 00 00 00  nop
a0086c18:  40 01 3b 38  call  0xa00d58f8
a0086c1c:  01 00 00 00  nop
a0086c20:  40 01 3b 2e  call  0xa00d58d8
a0086c24:  01 00 00 00  nop
a0086c28:  40 03 03 7b  call  0xa0147a14
a0086c2c:  90 10 20 01  mov  1, %o0	! 0x1
a0086c30:  80 a6 20 01  cmp  %i0, 1
a0086c34:  08 80 00 83  bleu  0xa0086e40
a0086c38:  01 00 00 00  nop
a0086c3c:  d4 14 21 f6  lduh  [ %l0 + 0x1f6 ], %o2
a0086c40:  80 a2 80 19  cmp  %o2, %i1
a0086c44:  22 80 00 88  be,a   0xa0086e64
a0086c48:  d6 0c 21 d6  ldub  [ %l0 + 0x1d6 ], %o3
a0086c4c:  a0 14 62 90  or  %l1, 0x290, %l0
a0086c50:  03 00 00 15  sethi  %hi(0x5400), %g1
a0086c54:  d2 14 21 f6  lduh  [ %l0 + 0x1f6 ], %o1
a0086c58:  b2 10 61 aa  or  %g1, 0x1aa, %i1
a0086c5c:  80 a2 40 19  cmp  %o1, %i1
a0086c60:  22 80 00 48  be,a   0xa0086d80
a0086c64:  d0 0c 21 d6  ldub  [ %l0 + 0x1d6 ], %o0
a0086c68:  40 01 3b 2c  call  0xa00d5918
a0086c6c:  01 00 00 00  nop
a0086c70:  40 01 47 eb  call  0xa00d8c1c
a0086c74:  01 00 00 00  nop
a0086c78:  7f ff ef f5  call  0xa0082c4c
a0086c7c:  01 00 00 00  nop
a0086c80:  80 8a 20 ff  btst  0xff, %o0
a0086c84:  02 80 00 4f  be  0xa0086dc0
a0086c88:  01 00 00 00  nop
a0086c8c:  40 01 3b 2b  call  0xa00d5938
a0086c90:  90 10 20 01  mov  1, %o0	! 0x1
a0086c94:  80 a6 20 02  cmp  %i0, 2
a0086c98:  02 80 00 53  be  0xa0086de4
a0086c9c:  01 00 00 00  nop
a0086ca0:  40 01 49 66  call  0xa00d9238
a0086ca4:  01 00 00 00  nop
a0086ca8:  7f ff ef e9  call  0xa0082c4c
a0086cac:  01 00 00 00  nop
a0086cb0:  80 8a 20 ff  btst  0xff, %o0
a0086cb4:  02 80 00 5f  be  0xa0086e30
a0086cb8:  01 00 00 00  nop
a0086cbc:  90 10 20 ff  mov  0xff, %o0	! 0xff
a0086cc0:  40 00 1f e2  call  0xa008ec48
a0086cc4:  92 10 20 00  clr  %o1
a0086cc8:  90 10 20 ff  mov  0xff, %o0
a0086ccc:  40 00 20 0d  call  0xa008ed00
a0086cd0:  92 10 20 00  clr  %o1
a0086cd4:  92 10 20 00  clr  %o1
a0086cd8:  40 00 20 38  call  0xa008edb8
a0086cdc:  90 10 20 ff  mov  0xff, %o0
a0086ce0:  40 00 20 91  call  0xa008ef24
a0086ce4:  90 10 21 f4  mov  0x1f4, %o0
a0086ce8:  40 00 20 92  call  0xa008ef30
a0086cec:  90 10 20 32  mov  0x32, %o0
a0086cf0:  40 00 20 93  call  0xa008ef3c
a0086cf4:  90 10 27 d0  mov  0x7d0, %o0
a0086cf8:  98 14 62 90  or  %l1, 0x290, %o4
a0086cfc:  de 03 20 ac  ld  [ %o4 + 0xac ], %o7
a0086d00:  23 00 04 00  sethi  %hi(0x100000), %l1
a0086d04:  80 8b c0 11  btst  %o7, %l1
a0086d08:  02 80 00 06  be  0xa0086d20
a0086d0c:  90 10 20 fe  mov  0xfe, %o0
a0086d10:  f2 0b 20 1f  ldub  [ %o4 + 0x1f ], %i1
a0086d14:  80 a6 60 00  cmp  %i1, 0
a0086d18:  02 80 00 81  be  0xa0086f1c
a0086d1c:  01 00 00 00  nop
a0086d20:  40 03 11 e5  call  0xa014b4b4
a0086d24:  92 10 20 01  mov  1, %o1	! 0x1
a0086d28:  80 a6 20 04  cmp  %i0, 4
a0086d2c:  02 80 00 05  be  0xa0086d40
a0086d30:  21 00 00 06  sethi  %hi(0x1800), %l0
a0086d34:  40 01 4c aa  call  0xa00d9fdc
a0086d38:  90 10 20 02  mov  2, %o0
a0086d3c:  21 00 00 06  sethi  %hi(0x1800), %l0
a0086d40:  40 03 05 86  call  0xa0148358
a0086d44:  90 14 21 64  or  %l0, 0x164, %o0	! 0x1964
a0086d48:  40 01 3c 4f  call  0xa00d5e84
a0086d4c:  31 00 03 fd  sethi  %hi(0xff400), %i0
a0086d50:  40 02 75 3d  call  0xa0124244
a0086d54:  90 10 20 01  mov  1, %o0
a0086d58:  92 14 a3 f4  or  %l2, 0x3f4, %o1
a0086d5c:  90 10 20 09  mov  9, %o0
a0086d60:  d0 2a 60 0a  stb  %o0, [ %o1 + 0xa ]
a0086d64:  c2 12 60 0a  lduh  [ %o1 + 0xa ], %g1
a0086d68:  a4 08 7f 7f  and  %g1, -129, %l2
a0086d6c:  40 02 6f fc  call  0xa0122d5c
a0086d70:  e4 32 60 0a  sth  %l2, [ %o1 + 0xa ]
a0086d74:  b0 16 21 68  or  %i0, 0x168, %i0
a0086d78:  40 01 60 fe  call  0xa00df170
a0086d7c:  93 e8 21 fc  restore  %g0, 0x1fc, %o1
a0086d80:  80 a2 20 aa  cmp  %o0, 0xaa
a0086d84:  12 bf ff b9  bne  0xa0086c68
a0086d88:  01 00 00 00  nop
a0086d8c:  40 02 f6 04  call  0xa014459c
a0086d90:  90 10 20 00  clr  %o0	! 0x0
a0086d94:  40 01 49 29  call  0xa00d9238
a0086d98:  d0 2c 20 1e  stb  %o0, [ %l0 + 0x1e ]
a0086d9c:  d4 14 a3 f4  lduh  [ %l2 + 0x3f4 ], %o2
a0086da0:  a0 12 a4 00  or  %o2, 0x400, %l0
a0086da4:  e0 34 a3 f4  sth  %l0, [ %l2 + 0x3f4 ]
a0086da8:  90 10 20 00  clr  %o0
a0086dac:  7f ff e6 c0  call  0xa00808ac
a0086db0:  92 10 20 00  clr  %o1
a0086db4:  40 03 07 f9  call  0xa0148d98
a0086db8:  90 10 20 00  clr  %o0
a0086dbc:  30 bf ff ad  b,a   0xa0086c70
a0086dc0:  40 01 36 5b  call  0xa00d472c
a0086dc4:  01 00 00 00  nop
a0086dc8:  40 00 b8 c4  call  0xa00b50d8
a0086dcc:  90 10 20 01  mov  1, %o0	! 0x1
a0086dd0:  40 01 3a da  call  0xa00d5938
a0086dd4:  90 10 20 01  mov  1, %o0
a0086dd8:  80 a6 20 02  cmp  %i0, 2
a0086ddc:  12 bf ff b1  bne  0xa0086ca0
a0086de0:  01 00 00 00  nop
a0086de4:  40 03 06 e4  call  0xa0148974
a0086de8:  01 00 00 00  nop
a0086dec:  96 0a 20 ff  and  %o0, 0xff, %o3
a0086df0:  80 a2 e0 ff  cmp  %o3, 0xff
a0086df4:  02 80 00 05  be  0xa0086e08
a0086df8:  d8 04 62 90  ld  [ %l1 + 0x290 ], %o4
a0086dfc:  80 8b 22 00  btst  0x200, %o4
a0086e00:  12 80 00 7f  bne  0xa0086ffc
a0086e04:  a0 14 62 90  or  %l1, 0x290, %l0
a0086e08:  1b 00 03 fd  sethi  %hi(0xff400), %o5
a0086e0c:  40 01 60 d9  call  0xa00df170
a0086e10:  90 13 61 78  or  %o5, 0x178, %o0	! 0xff578
a0086e14:  40 01 49 09  call  0xa00d9238
a0086e18:  01 00 00 00  nop
a0086e1c:  7f ff ef 8c  call  0xa0082c4c
a0086e20:  01 00 00 00  nop
a0086e24:  80 8a 20 ff  btst  0xff, %o0
a0086e28:  32 bf ff a6  bne,a   0xa0086cc0
a0086e2c:  90 10 20 ff  mov  0xff, %o0
a0086e30:  40 01 4d 09  call  0xa00da254
a0086e34:  01 00 00 00  nop
a0086e38:  10 bf ff a2  b  0xa0086cc0
a0086e3c:  90 10 20 ff  mov  0xff, %o0	! 0xff
a0086e40:  40 01 4a ce  call  0xa00d9978
a0086e44:  01 00 00 00  nop
a0086e48:  40 01 4e 43  call  0xa00da754
a0086e4c:  d0 0c 20 ac  ldub  [ %l0 + 0xac ], %o0
a0086e50:  d4 14 21 f6  lduh  [ %l0 + 0x1f6 ], %o2
a0086e54:  80 a2 80 19  cmp  %o2, %i1
a0086e58:  32 bf ff 7e  bne,a   0xa0086c50
a0086e5c:  a0 14 62 90  or  %l1, 0x290, %l0
a0086e60:  d6 0c 21 d6  ldub  [ %l0 + 0x1d6 ], %o3
a0086e64:  80 a2 e0 55  cmp  %o3, 0x55
a0086e68:  32 bf ff 7a  bne,a   0xa0086c50
a0086e6c:  a0 14 62 90  or  %l1, 0x290, %l0
a0086e70:  40 03 07 ca  call  0xa0148d98
a0086e74:  90 10 20 00  clr  %o0
a0086e78:  d8 0c 21 d5  ldub  [ %l0 + 0x1d5 ], %o4
a0086e7c:  80 a3 20 00  cmp  %o4, 0
a0086e80:  02 bf ff 7c  be  0xa0086c70
a0086e84:  01 00 00 00  nop
a0086e88:  40 02 f5 c5  call  0xa014459c
a0086e8c:  90 10 20 00  clr  %o0	! 0x0
a0086e90:  40 01 48 ea  call  0xa00d9238
a0086e94:  d0 2c 20 1e  stb  %o0, [ %l0 + 0x1e ]
a0086e98:  de 14 a3 f4  lduh  [ %l2 + 0x3f4 ], %o7
a0086e9c:  9a 13 e4 00  or  %o7, 0x400, %o5
a0086ea0:  da 34 a3 f4  sth  %o5, [ %l2 + 0x3f4 ]
a0086ea4:  90 10 20 00  clr  %o0
a0086ea8:  7f ff e6 81  call  0xa00808ac
a0086eac:  92 10 20 00  clr  %o1
a0086eb0:  30 bf ff 70  b,a   0xa0086c70
a0086eb4:  40 01 47 88  call  0xa00d8cd4
a0086eb8:  01 00 00 00  nop
a0086ebc:  40 01 43 c9  call  0xa00d7de0
a0086ec0:  01 00 00 00  nop
a0086ec4:  40 01 4a 28  call  0xa00d9764
a0086ec8:  01 00 00 00  nop
a0086ecc:  40 01 43 3d  call  0xa00d7bc0
a0086ed0:  01 00 00 00  nop
a0086ed4:  30 bf ff 51  b,a   0xa0086c18
a0086ed8:  10 bf ff 3f  b  0xa0086bd4
a0086edc:  d0 2c 21 a4  stb  %o0, [ %l0 + 0x1a4 ]
a0086ee0:  40 01 4a c6  call  0xa00d99f8
a0086ee4:  90 10 20 02  mov  2, %o0
a0086ee8:  40 03 2a bc  call  0xa01519d8
a0086eec:  90 10 20 04  mov  4, %o0
a0086ef0:  40 03 2a ba  call  0xa01519d8
a0086ef4:  90 10 20 08  mov  8, %o0
a0086ef8:  f2 04 20 a8  ld  [ %l0 + 0xa8 ], %i1
a0086efc:  25 00 00 20  sethi  %hi(0x8000), %l2
a0086f00:  80 8e 40 12  btst  %i1, %l2
a0086f04:  12 80 00 0a  bne  0xa0086f2c
a0086f08:  01 00 00 00  nop
a0086f0c:  7f ff e5 61  call  0xa0080490
a0086f10:  90 10 20 01  mov  1, %o0	! 0x1
a0086f14:  10 bf ff 29  b  0xa0086bb8
a0086f18:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a0086f1c:  40 03 02 44  call  0xa014782c
a0086f20:  90 10 20 04  mov  4, %o0
a0086f24:  10 bf ff 7f  b  0xa0086d20
a0086f28:  90 10 20 fe  mov  0xfe, %o0
a0086f2c:  40 02 7a 89  call  0xa0125950
a0086f30:  01 00 00 00  nop
a0086f34:  40 02 7a 95  call  0xa0125988
a0086f38:  01 00 00 00  nop
a0086f3c:  40 02 7b 22  call  0xa0125bc4
a0086f40:  01 00 00 00  nop
a0086f44:  40 02 7a 4e  call  0xa012587c
a0086f48:  01 00 00 00  nop
a0086f4c:  30 bf ff f0  b,a   0xa0086f0c
a0086f50:  40 02 76 fc  call  0xa0124b40
a0086f54:  01 00 00 00  nop
a0086f58:  40 02 76 c4  call  0xa0124a68
a0086f5c:  01 00 00 00  nop
a0086f60:  40 03 06 d2  call  0xa0148aa8
a0086f64:  90 10 20 01  mov  1, %o0	! 0x1
a0086f68:  40 02 f8 fe  call  0xa0145360
a0086f6c:  90 10 20 01  mov  1, %o0
a0086f70:  da 04 20 ac  ld  [ %l0 + 0xac ], %o5
a0086f74:  19 00 04 00  sethi  %hi(0x100000), %o4
a0086f78:  80 8b 40 0c  btst  %o5, %o4
a0086f7c:  02 80 00 06  be  0xa0086f94
a0086f80:  01 00 00 00  nop
a0086f84:  de 0c 20 1f  ldub  [ %l0 + 0x1f ], %o7
a0086f88:  80 a3 e0 00  cmp  %o7, 0
a0086f8c:  02 80 00 20  be  0xa008700c
a0086f90:  01 00 00 00  nop
a0086f94:  40 02 7a 6f  call  0xa0125950
a0086f98:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a0086f9c:  68 00 18 81  call  0x4008d1a0
a0086fa0:  90 10 20 32  mov  0x32, %o0
a0086fa4:  40 02 7a 36  call  0xa012587c
a0086fa8:  a0 14 a3 f4  or  %l2, 0x3f4, %l0
a0086fac:  40 01 50 60  call  0xa00db12c
a0086fb0:  90 10 20 00  clr  %o0
a0086fb4:  40 02 7a 60  call  0xa0125934
a0086fb8:  01 00 00 00  nop
a0086fbc:  68 00 18 79  call  0x4008d1a0
a0086fc0:  90 10 20 32  mov  0x32, %o0	! 0x32
a0086fc4:  40 02 7a 55  call  0xa0125918
a0086fc8:  01 00 00 00  nop
a0086fcc:  40 02 7b 2a  call  0xa0125c74
a0086fd0:  01 00 00 00  nop
a0086fd4:  40 02 7a 6d  call  0xa0125988
a0086fd8:  01 00 00 00  nop
a0086fdc:  40 02 7a fa  call  0xa0125bc4
a0086fe0:  01 00 00 00  nop
a0086fe4:  40 02 7b 79  call  0xa0125dc8
a0086fe8:  01 00 00 00  nop
a0086fec:  68 00 19 67  call  0x4008d588
a0086ff0:  01 00 00 00  nop
a0086ff4:  10 bf fe f1  b  0xa0086bb8
a0086ff8:  d0 34 20 1a  sth  %o0, [ %l0 + 0x1a ]
a0086ffc:  40 03 06 5e  call  0xa0148974
a0087000:  01 00 00 00  nop
a0087004:  10 bf ff 27  b  0xa0086ca0
a0087008:  d0 2c 20 1e  stb  %o0, [ %l0 + 0x1e ]
a008700c:  40 03 02 08  call  0xa014782c
a0087010:  90 10 20 02  mov  2, %o0
a0087014:  40 03 02 06  call  0xa014782c
a0087018:  90 10 20 03  mov  3, %o0
a008701c:  30 bf ff de  b,a   0xa0086f94
