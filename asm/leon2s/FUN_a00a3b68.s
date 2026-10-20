# leon2s FUN_a00a3b68 0xa00a3b68-0xa00a4238 (1744 bytes)
a00a3b68:  9d e3 bf 78  save  %sp, -136, %sp
a00a3b6c:  9a 10 20 00  clr  %o5
a00a3b70:  98 10 20 00  clr  %o4
a00a3b74:  13 28 02 d3  sethi  %hi(0xa00b4c00), %o1
a00a3b78:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a00a3b7c:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a00a3b80:  c0 37 bf f0  clrh  [ %fp + -16 ]
a00a3b84:  92 12 61 14  or  %o1, 0x114, %o1
a00a3b88:  90 07 bf d8  add  %fp, -40, %o0
a00a3b8c:  40 00 36 93  call  0xa00b15d8
a00a3b90:  94 10 20 08  mov  8, %o2
a00a3b94:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a3b98:  a6 10 63 6c  or  %g1, 0x36c, %l3	! 0xa807db6c
a00a3b9c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a3ba0:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00a3ba4:  a1 2c 60 02  sll  %l1, 2, %l0
a00a3ba8:  a4 10 63 3c  or  %g1, 0x33c, %l2
a00a3bac:  da 04 c0 10  ld  [ %l3 + %l0 ], %o5
a00a3bb0:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00a3bb4:  80 a3 40 01  cmp  %o5, %g1
a00a3bb8:  02 80 00 08  be  0xa00a3bd8
a00a3bbc:  ac 10 20 00  clr  %l6
a00a3bc0:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a3bc4:  90 12 23 98  or  %o0, 0x398, %o0	! 0xa006bb98
a00a3bc8:  7f ff 3d 1f  call  0xa0073044
a00a3bcc:  92 10 00 11  mov  %l1, %o1
a00a3bd0:  c2 04 c0 10  ld  [ %l3 + %l0 ], %g1
a00a3bd4:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00a3bd8:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3bdc:  82 10 61 fc  or  %g1, 0x1fc, %g1	! 0xa80791fc
a00a3be0:  c2 00 40 10  ld  [ %g1 + %l0 ], %g1
a00a3be4:  80 a0 60 03  cmp  %g1, 3
a00a3be8:  2b 2a 01 e4  sethi  %hi(0xa8079000), %l5
a00a3bec:  a4 15 61 e8  or  %l5, 0x1e8, %l2	! 0xa80791e8
a00a3bf0:  82 10 20 04  mov  4, %g1
a00a3bf4:  da 0c 80 11  ldub  [ %l2 + %l1 ], %o5
a00a3bf8:  a8 60 60 00  subx  %g1, 0, %l4
a00a3bfc:  82 03 60 01  add  %o5, 1, %g1
a00a3c00:  80 a3 60 c8  cmp  %o5, 0xc8
a00a3c04:  08 80 00 13  bleu  0xa00a3c50
a00a3c08:  c2 2c 80 11  stb  %g1, [ %l2 + %l1 ]
a00a3c0c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3c10:  82 10 61 a8  or  %g1, 0x1a8, %g1	! 0xa80791a8
a00a3c14:  c2 08 40 11  ldub  [ %g1 + %l1 ], %g1
a00a3c18:  80 a0 60 00  cmp  %g1, 0
a00a3c1c:  12 80 00 0d  bne  0xa00a3c50
a00a3c20:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a3c24:  82 10 63 28  or  %g1, 0x328, %g1	! 0xa8078728
a00a3c28:  c2 08 40 11  ldub  [ %g1 + %l1 ], %g1
a00a3c2c:  80 a0 60 01  cmp  %g1, 1
a00a3c30:  12 80 00 08  bne  0xa00a3c50
a00a3c34:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a3c38:  90 12 23 e0  or  %o0, 0x3e0, %o0	! 0xa006bbe0
a00a3c3c:  7f ff 3d 02  call  0xa0073044
a00a3c40:  92 10 00 11  mov  %l1, %o1
a00a3c44:  82 10 20 06  mov  6, %g1
a00a3c48:  c2 24 c0 10  st  %g1, [ %l3 + %l0 ]
a00a3c4c:  c0 2c 80 11  clrb  [ %l2 + %l1 ]
a00a3c50:  7f ff b7 d7  call  0xa0091bac
a00a3c54:  90 10 00 11  mov  %l1, %o0
a00a3c58:  80 8a 20 ff  btst  0xff, %o0
a00a3c5c:  32 80 00 07  bne,a   0xa00a3c78
a00a3c60:  90 10 00 11  mov  %l1, %o0
a00a3c64:  11 28 01 af  sethi  %hi(0xa006bc00), %o0
a00a3c68:  92 10 00 11  mov  %l1, %o1
a00a3c6c:  7f ff 3c f6  call  0xa0073044
a00a3c70:  90 12 20 38  or  %o0, 0x38, %o0
a00a3c74:  30 80 01 6f  b,a   0xa00a4230
a00a3c78:  7f ff b8 3b  call  0xa0091d64
a00a3c7c:  92 10 20 10  mov  0x10, %o1
a00a3c80:  a4 0a 20 ff  and  %o0, 0xff, %l2
a00a3c84:  80 8c a0 08  btst  8, %l2
a00a3c88:  02 80 00 2f  be  0xa00a3d44
a00a3c8c:  80 8c a0 20  btst  0x20, %l2
a00a3c90:  92 10 20 35  mov  0x35, %o1
a00a3c94:  7f ff b8 34  call  0xa0091d64
a00a3c98:  90 10 00 11  mov  %l1, %o0
a00a3c9c:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00a3ca0:  11 28 01 af  sethi  %hi(0xa006bc00), %o0
a00a3ca4:  90 12 20 80  or  %o0, 0x80, %o0	! 0xa006bc80
a00a3ca8:  92 10 20 35  mov  0x35, %o1
a00a3cac:  94 10 00 10  mov  %l0, %o2
a00a3cb0:  96 0c 20 80  and  %l0, 0x80, %o3
a00a3cb4:  7f ff 3c e4  call  0xa0073044
a00a3cb8:  98 0c 20 20  and  %l0, 0x20, %o4
a00a3cbc:  80 8c 20 02  btst  2, %l0
a00a3cc0:  12 80 00 06  bne  0xa00a3cd8
a00a3cc4:  9a 10 20 01  mov  1, %o5
a00a3cc8:  80 8c 20 04  btst  4, %l0
a00a3ccc:  02 80 00 06  be  0xa00a3ce4
a00a3cd0:  80 8c 20 08  btst  8, %l0
a00a3cd4:  9a 10 20 02  mov  2, %o5
a00a3cd8:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3cdc:  10 80 00 09  b  0xa00a3d00
a00a3ce0:  da 28 61 e2  stb  %o5, [ %g1 + 0x1e2 ]	! 0xa80791e2
a00a3ce4:  02 80 00 05  be  0xa00a3cf8
a00a3ce8:  1b 2a 01 e4  sethi  %hi(0xa8079000), %o5
a00a3cec:  82 10 20 03  mov  3, %g1
a00a3cf0:  10 80 00 03  b  0xa00a3cfc
a00a3cf4:  c2 2b 61 e2  stb  %g1, [ %o5 + 0x1e2 ]
a00a3cf8:  c0 2b 61 e2  clrb  [ %o5 + 0x1e2 ]
a00a3cfc:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3d00:  d2 08 61 e2  ldub  [ %g1 + 0x1e2 ], %o1	! 0xa80791e2
a00a3d04:  7f ff fe 1d  call  0xa00a3578
a00a3d08:  90 10 00 11  mov  %l1, %o0
a00a3d0c:  80 8c 20 20  btst  0x20, %l0
a00a3d10:  02 80 00 06  be  0xa00a3d28
a00a3d14:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3d18:  9a 10 61 a8  or  %g1, 0x1a8, %o5	! 0xa80791a8
a00a3d1c:  82 10 20 01  mov  1, %g1
a00a3d20:  10 80 00 04  b  0xa00a3d30
a00a3d24:  c2 2b 40 11  stb  %g1, [ %o5 + %l1 ]
a00a3d28:  82 10 61 a8  or  %g1, 0x1a8, %g1
a00a3d2c:  c0 28 40 11  clrb  [ %g1 + %l1 ]
a00a3d30:  90 10 00 11  mov  %l1, %o0
a00a3d34:  92 10 20 10  mov  0x10, %o1
a00a3d38:  7f ff b7 ef  call  0xa0091cf4
a00a3d3c:  94 10 20 08  mov  8, %o2
a00a3d40:  80 8c a0 20  btst  0x20, %l2
a00a3d44:  02 80 01 3b  be  0xa00a4230
a00a3d48:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a3d4c:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00a3d50:  82 10 63 20  or  %g1, 0x320, %g1
a00a3d54:  c2 08 40 11  ldub  [ %g1 + %l1 ], %g1
a00a3d58:  80 a0 60 00  cmp  %g1, 0
a00a3d5c:  02 80 00 07  be  0xa00a3d78
a00a3d60:  90 10 00 11  mov  %l1, %o0
a00a3d64:  92 10 20 01  mov  1, %o1
a00a3d68:  94 10 20 39  mov  0x39, %o2
a00a3d6c:  96 10 20 10  mov  0x10, %o3
a00a3d70:  10 80 00 06  b  0xa00a3d88
a00a3d74:  98 10 20 01  mov  1, %o4
a00a3d78:  92 10 20 01  mov  1, %o1
a00a3d7c:  94 10 20 39  mov  0x39, %o2
a00a3d80:  96 10 20 10  mov  0x10, %o3
a00a3d84:  98 10 20 00  clr  %o4
a00a3d88:  40 00 10 d1  call  0xa00a80cc
a00a3d8c:  a8 0d 20 ff  and  %l4, 0xff, %l4
a00a3d90:  92 10 20 41  mov  0x41, %o1
a00a3d94:  7f ff b7 f4  call  0xa0091d64
a00a3d98:  90 10 00 11  mov  %l1, %o0
a00a3d9c:  d0 2f bf f0  stb  %o0, [ %fp + -16 ]
a00a3da0:  90 10 00 11  mov  %l1, %o0
a00a3da4:  7f ff b7 f0  call  0xa0091d64
a00a3da8:  92 10 20 42  mov  0x42, %o1
a00a3dac:  82 0a 20 ff  and  %o0, 0xff, %g1
a00a3db0:  83 28 60 08  sll  %g1, 8, %g1
a00a3db4:  da 0f bf f0  ldub  [ %fp + -16 ], %o5
a00a3db8:  82 10 40 0d  or  %g1, %o5, %g1
a00a3dbc:  d0 2f bf f1  stb  %o0, [ %fp + -15 ]
a00a3dc0:  80 a5 20 00  cmp  %l4, 0
a00a3dc4:  94 10 00 01  mov  %g1, %o2
a00a3dc8:  02 80 00 11  be  0xa00a3e0c
a00a3dcc:  a6 10 20 00  clr  %l3
a00a3dd0:  83 28 60 10  sll  %g1, 0x10, %g1
a00a3dd4:  97 30 60 10  srl  %g1, 0x10, %o3
a00a3dd8:  90 07 bf f8  add  %fp, -8, %o0
a00a3ddc:  92 10 20 0f  mov  0xf, %o1
a00a3de0:  82 0c e0 ff  and  %l3, 0xff, %g1
a00a3de4:  83 28 60 02  sll  %g1, 2, %g1
a00a3de8:  9b 2a 40 01  sll  %o1, %g1, %o5
a00a3dec:  9a 0a c0 0d  and  %o3, %o5, %o5
a00a3df0:  9b 3b 40 01  sra  %o5, %g1, %o5
a00a3df4:  a6 04 e0 01  inc  %l3
a00a3df8:  82 00 40 08  add  %g1, %o0, %g1
a00a3dfc:  98 0c e0 ff  and  %l3, 0xff, %o4
a00a3e00:  80 a3 00 14  cmp  %o4, %l4
a00a3e04:  0a bf ff f7  bcs  0xa00a3de0
a00a3e08:  da 20 7f e8  st  %o5, [ %g1 + -24 ]
a00a3e0c:  83 2a a0 10  sll  %o2, 0x10, %g1
a00a3e10:  9b 30 60 10  srl  %g1, 0x10, %o5
a00a3e14:  80 a3 60 00  cmp  %o5, 0
a00a3e18:  02 80 00 07  be  0xa00a3e34
a00a3e1c:  80 a5 20 03  cmp  %l4, 3
a00a3e20:  12 80 00 11  bne  0xa00a3e64
a00a3e24:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00a3e28:  80 8b 6f ff  btst  0xfff, %o5
a00a3e2c:  12 80 00 0f  bne  0xa00a3e68
a00a3e30:  82 10 63 ff  or  %g1, 0x3ff, %g1
a00a3e34:  96 10 20 20  mov  0x20, %o3
a00a3e38:  90 10 00 11  mov  %l1, %o0
a00a3e3c:  92 10 20 04  mov  4, %o1
a00a3e40:  40 00 10 85  call  0xa00a8054
a00a3e44:  94 10 20 0d  mov  0xd, %o2
a00a3e48:  90 10 00 11  mov  %l1, %o0
a00a3e4c:  7f ff c3 1e  call  0xa0094ac4
a00a3e50:  92 10 20 01  mov  1, %o1
a00a3e54:  96 15 61 e8  or  %l5, 0x1e8, %o3
a00a3e58:  99 2c 60 02  sll  %l1, 2, %o4
a00a3e5c:  10 80 00 0f  b  0xa00a3e98
a00a3e60:  9a 10 20 05  mov  5, %o5
a00a3e64:  82 10 63 ff  or  %g1, 0x3ff, %g1
a00a3e68:  80 a3 40 01  cmp  %o5, %g1
a00a3e6c:  02 80 00 08  be  0xa00a3e8c
a00a3e70:  80 a5 20 03  cmp  %l4, 3
a00a3e74:  12 80 00 0e  bne  0xa00a3eac
a00a3e78:  80 a4 60 00  cmp  %l1, 0
a00a3e7c:  82 0b 6f ff  and  %o5, 0xfff, %g1
a00a3e80:  80 a0 6f ff  cmp  %g1, 0xfff
a00a3e84:  12 80 00 0a  bne  0xa00a3eac
a00a3e88:  80 a4 60 00  cmp  %l1, 0
a00a3e8c:  96 15 61 e8  or  %l5, 0x1e8, %o3
a00a3e90:  99 2c 60 02  sll  %l1, 2, %o4
a00a3e94:  9a 10 20 04  mov  4, %o5
a00a3e98:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a3e9c:  82 10 63 6c  or  %g1, 0x36c, %g1	! 0xa807db6c
a00a3ea0:  da 20 40 0c  st  %o5, [ %g1 + %o4 ]
a00a3ea4:  10 80 00 df  b  0xa00a4220
a00a3ea8:  c0 2a c0 11  clrb  [ %o3 + %l1 ]
a00a3eac:  12 80 00 09  bne  0xa00a3ed0
a00a3eb0:  21 33 80 0d  sethi  %hi(0xce003400), %l0
a00a3eb4:  7f fe f5 9d  call  0xa0061528
a00a3eb8:  90 14 20 0c  or  %l0, 0xc, %o0	! 0xce00340c
a00a3ebc:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00a3ec0:  82 10 60 ff  or  %g1, 0xff, %g1	! 0xffff80ff
a00a3ec4:  92 0a 00 01  and  %o0, %g1, %o1
a00a3ec8:  10 80 00 08  b  0xa00a3ee8
a00a3ecc:  90 14 20 0c  or  %l0, 0xc, %o0
a00a3ed0:  7f fe f5 96  call  0xa0061528
a00a3ed4:  90 14 23 0c  or  %l0, 0x30c, %o0
a00a3ed8:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00a3edc:  82 10 60 ff  or  %g1, 0xff, %g1	! 0xffff80ff
a00a3ee0:  92 0a 00 01  and  %o0, %g1, %o1
a00a3ee4:  90 14 23 0c  or  %l0, 0x30c, %o0
a00a3ee8:  7f fe f5 93  call  0xa0061534
a00a3eec:  01 00 00 00  nop
a00a3ef0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a3ef4:  82 10 63 18  or  %g1, 0x318, %g1	! 0xa8078718
a00a3ef8:  c2 08 40 11  ldub  [ %g1 + %l1 ], %g1
a00a3efc:  80 a0 60 00  cmp  %g1, 0
a00a3f00:  02 80 00 07  be  0xa00a3f1c
a00a3f04:  90 10 00 11  mov  %l1, %o0
a00a3f08:  92 10 20 01  mov  1, %o1
a00a3f0c:  94 10 20 39  mov  0x39, %o2
a00a3f10:  96 10 20 02  mov  2, %o3
a00a3f14:  10 80 00 06  b  0xa00a3f2c
a00a3f18:  98 10 20 01  mov  1, %o4
a00a3f1c:  92 10 20 01  mov  1, %o1
a00a3f20:  94 10 20 39  mov  0x39, %o2
a00a3f24:  96 10 20 02  mov  2, %o3
a00a3f28:  98 10 20 00  clr  %o4
a00a3f2c:  40 00 10 68  call  0xa00a80cc
a00a3f30:  01 00 00 00  nop
a00a3f34:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a3f38:  82 10 63 10  or  %g1, 0x310, %g1	! 0xa8078710
a00a3f3c:  c2 08 40 11  ldub  [ %g1 + %l1 ], %g1
a00a3f40:  80 a0 60 00  cmp  %g1, 0
a00a3f44:  02 80 00 07  be  0xa00a3f60
a00a3f48:  90 10 00 11  mov  %l1, %o0
a00a3f4c:  92 10 20 01  mov  1, %o1
a00a3f50:  94 10 20 3c  mov  0x3c, %o2
a00a3f54:  96 10 20 0c  mov  0xc, %o3
a00a3f58:  10 80 00 06  b  0xa00a3f70
a00a3f5c:  98 10 20 00  clr  %o4
a00a3f60:  92 10 20 01  mov  1, %o1
a00a3f64:  94 10 20 3c  mov  0x3c, %o2
a00a3f68:  96 10 20 0c  mov  0xc, %o3
a00a3f6c:  98 10 20 01  mov  1, %o4
a00a3f70:  40 00 10 57  call  0xa00a80cc
a00a3f74:  aa 10 20 00  clr  %l5
a00a3f78:  80 a5 20 00  cmp  %l4, 0
a00a3f7c:  02 80 00 a6  be  0xa00a4214
a00a3f80:  a6 10 20 00  clr  %l3
a00a3f84:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00a3f88:  9b 2c 60 02  sll  %l1, 2, %o5
a00a3f8c:  82 07 bf f8  add  %fp, -8, %g1
a00a3f90:  a4 03 40 01  add  %o5, %g1, %l2
a00a3f94:  d6 04 bf e8  ld  [ %l2 + -24 ], %o3
a00a3f98:  80 a2 e0 0e  cmp  %o3, 0xe
a00a3f9c:  12 80 00 2f  bne  0xa00a4058
a00a3fa0:  82 02 ff ff  add  %o3, -1, %g1
a00a3fa4:  80 8d 60 ff  btst  0xff, %l5
a00a3fa8:  12 80 00 25  bne  0xa00a403c
a00a3fac:  ac 10 20 01  mov  1, %l6
a00a3fb0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3fb4:  96 10 61 f0  or  %g1, 0x1f0, %o3	! 0xa80791f0
a00a3fb8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a3fbc:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3fc0:  d8 0a c0 10  ldub  [ %o3 + %l0 ], %o4
a00a3fc4:  9b 2c 20 02  sll  %l0, 2, %o5
a00a3fc8:  82 10 61 f4  or  %g1, 0x1f4, %g1
a00a3fcc:  da 00 40 0d  ld  [ %g1 + %o5 ], %o5
a00a3fd0:  98 03 20 01  inc  %o4
a00a3fd4:  80 a3 00 0d  cmp  %o4, %o5
a00a3fd8:  18 80 00 15  bgu  0xa00a402c
a00a3fdc:  aa 10 20 01  mov  1, %l5
a00a3fe0:  9a 03 60 01  inc  %o5
a00a3fe4:  81 80 00 00  mov  %g0, %y
a00a3fe8:  01 00 00 00  nop
a00a3fec:  01 00 00 00  nop
a00a3ff0:  01 00 00 00  nop
a00a3ff4:  82 73 00 0d  udiv  %o4, %o5, %g1
a00a3ff8:  82 58 40 0d  smul  %g1, %o5, %g1
a00a3ffc:  82 23 00 01  sub  %o4, %g1, %g1
a00a4000:  11 28 01 af  sethi  %hi(0xa006bc00), %o0
a00a4004:  c2 2a c0 10  stb  %g1, [ %o3 + %l0 ]
a00a4008:  92 10 00 11  mov  %l1, %o1
a00a400c:  7f ff 3c 0e  call  0xa0073044
a00a4010:  90 12 20 e8  or  %o0, 0xe8, %o0
a00a4014:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4018:  90 10 00 10  mov  %l0, %o0
a00a401c:  7f ff fd 57  call  0xa00a3578
a00a4020:  d2 08 61 e2  ldub  [ %g1 + 0x1e2 ], %o1
a00a4024:  10 80 00 07  b  0xa00a4040
a00a4028:  11 28 01 af  sethi  %hi(0xa006bc00), %o0
a00a402c:  11 28 01 af  sethi  %hi(0xa006bc00), %o0
a00a4030:  90 12 21 88  or  %o0, 0x188, %o0	! 0xa006bd88
a00a4034:  7f ff 3c 04  call  0xa0073044
a00a4038:  92 10 00 11  mov  %l1, %o1
a00a403c:  11 28 01 af  sethi  %hi(0xa006bc00), %o0
a00a4040:  94 10 00 11  mov  %l1, %o2
a00a4044:  92 0e 20 ff  and  %i0, 0xff, %o1
a00a4048:  7f ff 3b ff  call  0xa0073044
a00a404c:  90 12 21 38  or  %o0, 0x138, %o0
a00a4050:  10 80 00 6d  b  0xa00a4204
a00a4054:  a6 04 e0 01  inc  %l3
a00a4058:  80 a0 60 07  cmp  %g1, 7
a00a405c:  18 80 00 63  bgu  0xa00a41e8
a00a4060:  82 02 ff fb  add  %o3, -5, %g1
a00a4064:  80 a0 60 03  cmp  %g1, 3
a00a4068:  38 80 00 11  bgu,a   0xa00a40ac
a00a406c:  c2 04 bf e8  ld  [ %l2 + -24 ], %g1
a00a4070:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a4074:  90 10 00 10  mov  %l0, %o0
a00a4078:  92 10 20 01  mov  1, %o1
a00a407c:  94 10 20 3b  mov  0x3b, %o2
a00a4080:  96 10 20 20  mov  0x20, %o3
a00a4084:  40 00 10 12  call  0xa00a80cc
a00a4088:  98 10 20 01  mov  1, %o4
a00a408c:  90 10 00 10  mov  %l0, %o0
a00a4090:  ac 10 20 01  mov  1, %l6
a00a4094:  92 10 20 01  mov  1, %o1
a00a4098:  94 10 20 3b  mov  0x3b, %o2
a00a409c:  96 10 20 10  mov  0x10, %o3
a00a40a0:  40 00 10 0b  call  0xa00a80cc
a00a40a4:  98 10 20 00  clr  %o4
a00a40a8:  c2 04 bf e8  ld  [ %l2 + -24 ], %g1
a00a40ac:  80 a0 60 03  cmp  %g1, 3
a00a40b0:  12 80 00 0f  bne  0xa00a40ec
a00a40b4:  80 a4 60 00  cmp  %l1, 0
a00a40b8:  1b 2a 01 e4  sethi  %hi(0xa8079000), %o5
a00a40bc:  82 0e 20 ff  and  %i0, 0xff, %g1
a00a40c0:  9a 13 61 a8  or  %o5, 0x1a8, %o5
a00a40c4:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a00a40c8:  80 a0 60 00  cmp  %g1, 0
a00a40cc:  12 80 00 08  bne  0xa00a40ec
a00a40d0:  80 a4 60 00  cmp  %l1, 0
a00a40d4:  11 28 01 af  sethi  %hi(0xa006bc00), %o0
a00a40d8:  92 10 00 11  mov  %l1, %o1
a00a40dc:  7f ff 3b da  call  0xa0073044
a00a40e0:  90 12 21 c8  or  %o0, 0x1c8, %o0
a00a40e4:  10 80 00 48  b  0xa00a4204
a00a40e8:  a6 04 e0 01  inc  %l3
a00a40ec:  12 80 00 0e  bne  0xa00a4124
a00a40f0:  80 a4 60 01  cmp  %l1, 1
a00a40f4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a40f8:  90 10 00 10  mov  %l0, %o0
a00a40fc:  92 10 20 04  mov  4, %o1
a00a4100:  94 10 20 e0  mov  0xe0, %o2
a00a4104:  96 10 20 0f  mov  0xf, %o3
a00a4108:  40 00 10 1f  call  0xa00a8184
a00a410c:  d8 0f bf e3  ldub  [ %fp + -29 ], %o4
a00a4110:  90 10 00 10  mov  %l0, %o0
a00a4114:  92 10 20 01  mov  1, %o1
a00a4118:  94 10 20 50  mov  0x50, %o2
a00a411c:  10 80 00 2f  b  0xa00a41d8
a00a4120:  96 10 20 01  mov  1, %o3
a00a4124:  12 80 00 10  bne  0xa00a4164
a00a4128:  80 a4 60 02  cmp  %l1, 2
a00a412c:  d8 07 bf e4  ld  [ %fp + -28 ], %o4
a00a4130:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a4134:  99 2b 20 04  sll  %o4, 4, %o4
a00a4138:  90 10 00 10  mov  %l0, %o0
a00a413c:  92 10 20 04  mov  4, %o1
a00a4140:  94 10 20 e0  mov  0xe0, %o2
a00a4144:  96 10 20 f0  mov  0xf0, %o3
a00a4148:  40 00 10 0f  call  0xa00a8184
a00a414c:  98 0b 20 f0  and  %o4, 0xf0, %o4
a00a4150:  90 10 00 10  mov  %l0, %o0
a00a4154:  92 10 20 01  mov  1, %o1
a00a4158:  94 10 20 50  mov  0x50, %o2
a00a415c:  10 80 00 1f  b  0xa00a41d8
a00a4160:  96 10 20 02  mov  2, %o3
a00a4164:  12 80 00 0e  bne  0xa00a419c
a00a4168:  80 a4 60 03  cmp  %l1, 3
a00a416c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a4170:  90 10 00 10  mov  %l0, %o0
a00a4174:  92 10 20 04  mov  4, %o1
a00a4178:  94 10 20 e1  mov  0xe1, %o2
a00a417c:  96 10 20 0f  mov  0xf, %o3
a00a4180:  40 00 10 01  call  0xa00a8184
a00a4184:  d8 0f bf eb  ldub  [ %fp + -21 ], %o4
a00a4188:  90 10 00 10  mov  %l0, %o0
a00a418c:  92 10 20 01  mov  1, %o1
a00a4190:  94 10 20 50  mov  0x50, %o2
a00a4194:  10 80 00 11  b  0xa00a41d8
a00a4198:  96 10 20 04  mov  4, %o3
a00a419c:  32 80 00 1a  bne,a   0xa00a4204
a00a41a0:  a6 04 e0 01  inc  %l3
a00a41a4:  d8 07 bf ec  ld  [ %fp + -20 ], %o4
a00a41a8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a41ac:  99 2b 20 04  sll  %o4, 4, %o4
a00a41b0:  90 10 00 10  mov  %l0, %o0
a00a41b4:  92 10 20 04  mov  4, %o1
a00a41b8:  94 10 20 e1  mov  0xe1, %o2
a00a41bc:  96 10 20 f0  mov  0xf0, %o3
a00a41c0:  40 00 0f f1  call  0xa00a8184
a00a41c4:  98 0b 20 f0  and  %o4, 0xf0, %o4
a00a41c8:  90 10 00 10  mov  %l0, %o0
a00a41cc:  92 10 20 01  mov  1, %o1
a00a41d0:  94 10 20 50  mov  0x50, %o2
a00a41d4:  96 10 20 08  mov  8, %o3
a00a41d8:  40 00 0f bd  call  0xa00a80cc
a00a41dc:  98 10 20 00  clr  %o4
a00a41e0:  10 80 00 09  b  0xa00a4204
a00a41e4:  a6 04 e0 01  inc  %l3
a00a41e8:  11 28 01 af  sethi  %hi(0xa006bc00), %o0
a00a41ec:  90 12 22 10  or  %o0, 0x210, %o0	! 0xa006be10
a00a41f0:  94 10 00 11  mov  %l1, %o2
a00a41f4:  96 0a e0 ff  and  %o3, 0xff, %o3
a00a41f8:  7f ff 3b 93  call  0xa0073044
a00a41fc:  92 0e 20 ff  and  %i0, 0xff, %o1
a00a4200:  a6 04 e0 01  inc  %l3
a00a4204:  82 0c e0 ff  and  %l3, 0xff, %g1
a00a4208:  80 a0 40 14  cmp  %g1, %l4
a00a420c:  0a bf ff 5f  bcs  0xa00a3f88
a00a4210:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00a4214:  92 0d a0 01  and  %l6, 1, %o1
a00a4218:  7f ff fc 5d  call  0xa00a338c
a00a421c:  90 0e 20 ff  and  %i0, 0xff, %o0
a00a4220:  90 0e 20 ff  and  %i0, 0xff, %o0
a00a4224:  92 10 20 10  mov  0x10, %o1
a00a4228:  7f ff b6 b3  call  0xa0091cf4
a00a422c:  94 10 20 20  mov  0x20, %o2
a00a4230:  81 c7 e0 08  ret
a00a4234:  91 e8 20 00  restore  %g0, 0, %o0
