# leon2s MAX_RSED 0xa0099c18-0xa0099ffc (996 bytes)
a0099c18:  9d e3 bf 98  save  %sp, -104, %sp
a0099c1c:  21 2a 01 f5  sethi  %hi(0xa807d400), %l0
a0099c20:  a4 0e 20 ff  and  %i0, 0xff, %l2
a0099c24:  82 14 22 80  or  %l0, 0x280, %g1
a0099c28:  9a 5c a0 b0  smul  %l2, 0xb0, %o5
a0099c2c:  98 03 40 01  add  %o5, %g1, %o4
a0099c30:  c2 0b 20 ab  ldub  [ %o4 + 0xab ], %g1
a0099c34:  80 a0 60 00  cmp  %g1, 0
a0099c38:  12 80 00 0c  bne  0xa0099c68
a0099c3c:  aa 10 00 18  mov  %i0, %l5
a0099c40:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0099c44:  da 00 62 34  ld  [ %g1 + 0x234 ], %o5	! 0xa8078634
a0099c48:  03 00 00 10  sethi  %hi(0x4000), %g1
a0099c4c:  80 8b 40 01  btst  %o5, %g1
a0099c50:  02 80 00 07  be  0xa0099c6c
a0099c54:  2d 2a 01 f6  sethi  %hi(0xa807d800), %l6
a0099c58:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a0099c5c:  90 12 20 f0  or  %o0, 0xf0, %o0	! 0xa006a0f0
a0099c60:  7f ff 64 f9  call  0xa0073044
a0099c64:  d2 0b 20 aa  ldub  [ %o4 + 0xaa ], %o1
a0099c68:  2d 2a 01 f6  sethi  %hi(0xa807d800), %l6
a0099c6c:  9a 15 a3 00  or  %l6, 0x300, %o5	! 0xa807db00
a0099c70:  82 5c a0 34  smul  %l2, 0x34, %g1
a0099c74:  a2 00 40 0d  add  %g1, %o5, %l1
a0099c78:  90 10 20 0f  mov  0xf, %o0
a0099c7c:  40 00 35 e3  call  0xa00a7408
a0099c80:  d2 04 60 20  ld  [ %l1 + 0x20 ], %o1
a0099c84:  80 a2 20 00  cmp  %o0, 0
a0099c88:  02 80 00 b1  be  0xa0099f4c
a0099c8c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0099c90:  d4 04 60 20  ld  [ %l1 + 0x20 ], %o2
a0099c94:  da 02 80 00  ld  [ %o2 ], %o5
a0099c98:  13 00 00 1f  sethi  %hi(0x7c00), %o1
a0099c9c:  96 12 63 ff  or  %o1, 0x3ff, %o3	! 0x7fff
a0099ca0:  c2 02 a0 04  ld  [ %o2 + 4 ], %g1
a0099ca4:  82 08 40 0b  and  %g1, %o3, %g1
a0099ca8:  9a 0b 40 0b  and  %o5, %o3, %o5
a0099cac:  d8 02 a0 08  ld  [ %o2 + 8 ], %o4
a0099cb0:  9a 03 40 01  add  %o5, %g1, %o5
a0099cb4:  98 0b 00 0b  and  %o4, %o3, %o4
a0099cb8:  c2 02 a0 0c  ld  [ %o2 + 0xc ], %g1
a0099cbc:  9a 03 40 0c  add  %o5, %o4, %o5
a0099cc0:  82 08 40 0b  and  %g1, %o3, %g1
a0099cc4:  9a 03 40 01  add  %o5, %g1, %o5
a0099cc8:  9a 0b 40 0b  and  %o5, %o3, %o5
a0099ccc:  92 12 63 fc  or  %o1, 0x3fc, %o1
a0099cd0:  80 a3 40 09  cmp  %o5, %o1
a0099cd4:  12 80 00 12  bne  0xa0099d1c
a0099cd8:  a6 10 00 0d  mov  %o5, %l3
a0099cdc:  82 14 22 80  or  %l0, 0x280, %g1
a0099ce0:  9a 5c a0 b0  smul  %l2, 0xb0, %o5
a0099ce4:  a0 03 40 01  add  %o5, %g1, %l0
a0099ce8:  c2 0c 20 ae  ldub  [ %l0 + 0xae ], %g1
a0099cec:  80 a0 60 00  cmp  %g1, 0
a0099cf0:  12 80 00 0c  bne  0xa0099d20
a0099cf4:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a0099cf8:  d2 04 60 18  ld  [ %l1 + 0x18 ], %o1
a0099cfc:  90 10 20 06  mov  6, %o0
a0099d00:  40 00 35 ab  call  0xa00a73ac
a0099d04:  92 02 60 80  add  %o1, 0x80, %o1
a0099d08:  82 10 20 01  mov  1, %g1
a0099d0c:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a0099d10:  c2 2c 20 ae  stb  %g1, [ %l0 + 0xae ]
a0099d14:  7f ff 65 ec  call  0xa00734c4
a0099d18:  90 12 21 18  or  %o0, 0x118, %o0
a0099d1c:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a0099d20:  82 5c a0 b0  smul  %l2, 0xb0, %g1
a0099d24:  98 15 22 80  or  %l4, 0x280, %o4
a0099d28:  9a 00 40 0c  add  %g1, %o4, %o5
a0099d2c:  c2 0b 60 ab  ldub  [ %o5 + 0xab ], %g1
a0099d30:  80 a0 60 00  cmp  %g1, 0
a0099d34:  32 80 00 90  bne,a   0xa0099f74
a0099d38:  98 0d 60 ff  and  %l5, 0xff, %o4
a0099d3c:  da 0b 60 aa  ldub  [ %o5 + 0xaa ], %o5
a0099d40:  82 5c a0 58  smul  %l2, 0x58, %g1
a0099d44:  82 00 40 0d  add  %g1, %o5, %g1
a0099d48:  82 00 40 01  add  %g1, %g1, %g1
a0099d4c:  82 00 40 0c  add  %g1, %o4, %g1
a0099d50:  e6 30 60 96  sth  %l3, [ %g1 + 0x96 ]
a0099d54:  a0 10 20 00  clr  %l0
a0099d58:  9a 0c 20 ff  and  %l0, 0xff, %o5
a0099d5c:  82 5c a0 58  smul  %l2, 0x58, %g1
a0099d60:  82 00 40 0d  add  %g1, %o5, %g1
a0099d64:  82 00 40 01  add  %g1, %g1, %g1
a0099d68:  9a 15 22 80  or  %l4, 0x280, %o5
a0099d6c:  23 2a 01 e1  sethi  %hi(0xa8078400), %l1
a0099d70:  9a 00 40 0d  add  %g1, %o5, %o5
a0099d74:  c2 04 62 34  ld  [ %l1 + 0x234 ], %g1
a0099d78:  27 00 00 10  sethi  %hi(0x4000), %l3
a0099d7c:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a0099d80:  a0 04 20 01  inc  %l0
a0099d84:  80 88 40 13  btst  %g1, %l3
a0099d88:  02 80 00 04  be  0xa0099d98
a0099d8c:  90 12 20 e8  or  %o0, 0xe8, %o0
a0099d90:  7f ff 64 ad  call  0xa0073044
a0099d94:  d2 13 60 96  lduh  [ %o5 + 0x96 ], %o1
a0099d98:  82 0c 20 ff  and  %l0, 0xff, %g1
a0099d9c:  80 a0 60 09  cmp  %g1, 9
a0099da0:  08 bf ff ef  bleu  0xa0099d5c
a0099da4:  9a 0c 20 ff  and  %l0, 0xff, %o5
a0099da8:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0099dac:  b0 0d 60 ff  and  %l5, 0xff, %i0
a0099db0:  92 10 62 80  or  %g1, 0x280, %o1
a0099db4:  82 5e 20 b0  smul  %i0, 0xb0, %g1
a0099db8:  a0 00 40 09  add  %g1, %o1, %l0
a0099dbc:  c2 0c 20 ad  ldub  [ %l0 + 0xad ], %g1
a0099dc0:  80 a0 60 00  cmp  %g1, 0
a0099dc4:  a4 10 00 11  mov  %l1, %l2
a0099dc8:  c2 0c 20 aa  ldub  [ %l0 + 0xaa ], %g1
a0099dcc:  02 80 00 31  be  0xa0099e90
a0099dd0:  94 5e 20 58  smul  %i0, 0x58, %o2
a0099dd4:  96 08 60 ff  and  %g1, 0xff, %o3
a0099dd8:  03 19 99 99  sethi  %hi(0x66666400), %g1
a0099ddc:  98 02 e0 01  add  %o3, 1, %o4
a0099de0:  82 10 62 67  or  %g1, 0x267, %g1
a0099de4:  80 5b 00 01  smul  %o4, %g1, %g0
a0099de8:  83 40 00 00  rd  %y, %g1
a0099dec:  83 38 60 02  sra  %g1, 2, %g1
a0099df0:  9b 28 60 02  sll  %g1, 2, %o5
a0099df4:  9a 03 40 01  add  %o5, %g1, %o5
a0099df8:  9a 03 40 0d  add  %o5, %o5, %o5
a0099dfc:  98 23 00 0d  sub  %o4, %o5, %o4
a0099e00:  98 02 80 0c  add  %o2, %o4, %o4
a0099e04:  96 02 80 0b  add  %o2, %o3, %o3
a0099e08:  96 02 c0 0b  add  %o3, %o3, %o3
a0099e0c:  98 03 00 0c  add  %o4, %o4, %o4
a0099e10:  98 03 00 09  add  %o4, %o1, %o4
a0099e14:  96 02 c0 09  add  %o3, %o1, %o3
a0099e18:  d2 12 e0 96  lduh  [ %o3 + 0x96 ], %o1
a0099e1c:  c2 13 20 96  lduh  [ %o4 + 0x96 ], %g1
a0099e20:  80 a2 40 01  cmp  %o1, %g1
a0099e24:  2a 80 00 25  bcs,a   0xa0099eb8
a0099e28:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1
a0099e2c:  92 22 40 01  sub  %o1, %g1, %o1
a0099e30:  80 a2 60 04  cmp  %o1, 4
a0099e34:  04 80 00 3f  ble  0xa0099f30
a0099e38:  da 04 a2 34  ld  [ %l2 + 0x234 ], %o5
a0099e3c:  c2 0c 20 af  ldub  [ %l0 + 0xaf ], %g1
a0099e40:  80 a0 60 00  cmp  %g1, 0
a0099e44:  12 80 00 3c  bne  0xa0099f34
a0099e48:  03 00 00 10  sethi  %hi(0x4000), %g1
a0099e4c:  c2 04 62 34  ld  [ %l1 + 0x234 ], %g1
a0099e50:  80 88 40 13  btst  %g1, %l3
a0099e54:  02 80 00 06  be  0xa0099e6c
a0099e58:  9a 15 a3 00  or  %l6, 0x300, %o5
a0099e5c:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a0099e60:  7f ff 64 79  call  0xa0073044
a0099e64:  90 12 21 28  or  %o0, 0x128, %o0	! 0xa006a128
a0099e68:  9a 15 a3 00  or  %l6, 0x300, %o5
a0099e6c:  82 5e 20 34  smul  %i0, 0x34, %g1
a0099e70:  82 00 40 0d  add  %g1, %o5, %g1
a0099e74:  d2 00 60 18  ld  [ %g1 + 0x18 ], %o1
a0099e78:  92 02 60 80  add  %o1, 0x80, %o1
a0099e7c:  40 00 35 4c  call  0xa00a73ac
a0099e80:  90 10 20 06  mov  6, %o0
a0099e84:  82 10 20 01  mov  1, %g1
a0099e88:  10 80 00 29  b  0xa0099f2c
a0099e8c:  c2 2c 20 af  stb  %g1, [ %l0 + 0xaf ]
a0099e90:  82 08 60 ff  and  %g1, 0xff, %g1
a0099e94:  82 02 80 01  add  %o2, %g1, %g1
a0099e98:  82 00 40 01  add  %g1, %g1, %g1
a0099e9c:  82 00 40 09  add  %g1, %o1, %g1
a0099ea0:  e2 10 60 96  lduh  [ %g1 + 0x96 ], %l1
a0099ea4:  c2 14 20 96  lduh  [ %l0 + 0x96 ], %g1
a0099ea8:  80 a4 40 01  cmp  %l1, %g1
a0099eac:  1a 80 00 0a  bcc  0xa0099ed4
a0099eb0:  80 a4 60 04  cmp  %l1, 4
a0099eb4:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1
a0099eb8:  80 88 40 13  btst  %g1, %l3
a0099ebc:  02 80 00 04  be  0xa0099ecc
a0099ec0:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a0099ec4:  7f ff 65 80  call  0xa00734c4
a0099ec8:  90 12 21 50  or  %o0, 0x150, %o0	! 0xa006a150
a0099ecc:  7f ff fd d1  call  0xa0099610
a0099ed0:  81 e8 00 00  restore
a0099ed4:  08 80 00 17  bleu  0xa0099f30
a0099ed8:  da 04 a2 34  ld  [ %l2 + 0x234 ], %o5
a0099edc:  c2 0c 20 af  ldub  [ %l0 + 0xaf ], %g1
a0099ee0:  80 a0 60 00  cmp  %g1, 0
a0099ee4:  12 80 00 14  bne  0xa0099f34
a0099ee8:  03 00 00 10  sethi  %hi(0x4000), %g1
a0099eec:  9a 15 a3 00  or  %l6, 0x300, %o5
a0099ef0:  82 5e 20 34  smul  %i0, 0x34, %g1
a0099ef4:  82 00 40 0d  add  %g1, %o5, %g1
a0099ef8:  d2 00 60 18  ld  [ %g1 + 0x18 ], %o1
a0099efc:  92 02 60 80  add  %o1, 0x80, %o1
a0099f00:  40 00 35 2b  call  0xa00a73ac
a0099f04:  90 10 20 06  mov  6, %o0
a0099f08:  da 04 a2 34  ld  [ %l2 + 0x234 ], %o5
a0099f0c:  82 10 20 01  mov  1, %g1
a0099f10:  80 8b 40 13  btst  %o5, %l3
a0099f14:  02 80 00 06  be  0xa0099f2c
a0099f18:  c2 2c 20 af  stb  %g1, [ %l0 + 0xaf ]
a0099f1c:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a0099f20:  90 12 21 28  or  %o0, 0x128, %o0	! 0xa006a128
a0099f24:  7f ff 64 48  call  0xa0073044
a0099f28:  92 10 00 11  mov  %l1, %o1
a0099f2c:  da 04 a2 34  ld  [ %l2 + 0x234 ], %o5
a0099f30:  03 00 00 10  sethi  %hi(0x4000), %g1
a0099f34:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a0099f38:  80 8b 40 01  btst  %o5, %g1
a0099f3c:  12 80 00 0b  bne  0xa0099f68
a0099f40:  90 12 22 e8  or  %o0, 0x2e8, %o0
a0099f44:  10 80 00 0c  b  0xa0099f74
a0099f48:  98 0d 60 ff  and  %l5, 0xff, %o4
a0099f4c:  da 00 62 34  ld  [ %g1 + 0x234 ], %o5
a0099f50:  03 00 00 10  sethi  %hi(0x4000), %g1
a0099f54:  80 8b 40 01  btst  %o5, %g1
a0099f58:  02 80 00 07  be  0xa0099f74
a0099f5c:  98 0d 60 ff  and  %l5, 0xff, %o4
a0099f60:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a0099f64:  90 12 21 88  or  %o0, 0x188, %o0	! 0xa006a188
a0099f68:  7f ff 65 57  call  0xa00734c4
a0099f6c:  01 00 00 00  nop
a0099f70:  98 0d 60 ff  and  %l5, 0xff, %o4
a0099f74:  15 2a 01 f5  sethi  %hi(0xa807d400), %o2
a0099f78:  82 12 a2 80  or  %o2, 0x280, %g1	! 0xa807d680
a0099f7c:  9a 5b 20 b0  smul  %o4, 0xb0, %o5
a0099f80:  96 03 40 01  add  %o5, %g1, %o3
a0099f84:  c2 0a e0 ab  ldub  [ %o3 + 0xab ], %g1
a0099f88:  80 a0 60 00  cmp  %g1, 0
a0099f8c:  12 80 00 0c  bne  0xa0099fbc
a0099f90:  82 12 a2 80  or  %o2, 0x280, %g1
a0099f94:  c2 0a e0 aa  ldub  [ %o3 + 0xaa ], %g1
a0099f98:  82 00 60 01  inc  %g1
a0099f9c:  9a 08 60 ff  and  %g1, 0xff, %o5
a0099fa0:  80 a3 60 0a  cmp  %o5, 0xa
a0099fa4:  12 80 00 05  bne  0xa0099fb8
a0099fa8:  c2 2a e0 aa  stb  %g1, [ %o3 + 0xaa ]
a0099fac:  82 10 20 01  mov  1, %g1
a0099fb0:  c2 2a e0 ad  stb  %g1, [ %o3 + 0xad ]
a0099fb4:  c0 2a e0 aa  clrb  [ %o3 + 0xaa ]
a0099fb8:  82 12 a2 80  or  %o2, 0x280, %g1
a0099fbc:  98 5b 20 b0  smul  %o4, 0xb0, %o4
a0099fc0:  98 03 00 01  add  %o4, %g1, %o4
a0099fc4:  da 0b 20 ab  ldub  [ %o4 + 0xab ], %o5
a0099fc8:  9a 03 60 01  inc  %o5
a0099fcc:  d6 0b 20 ac  ldub  [ %o4 + 0xac ], %o3
a0099fd0:  95 3b 60 1f  sra  %o5, 0x1f, %o2
a0099fd4:  81 82 a0 00  mov  %o2, %y
a0099fd8:  01 00 00 00  nop
a0099fdc:  01 00 00 00  nop
a0099fe0:  01 00 00 00  nop
a0099fe4:  82 7b 40 0b  sdiv  %o5, %o3, %g1
a0099fe8:  82 58 40 0b  smul  %g1, %o3, %g1
a0099fec:  9a 23 40 01  sub  %o5, %g1, %o5
a0099ff0:  da 2b 20 ab  stb  %o5, [ %o4 + 0xab ]
a0099ff4:  81 c7 e0 08  ret
a0099ff8:  81 e8 00 00  restore
