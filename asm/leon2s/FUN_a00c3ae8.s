# leon2s FUN_a00c3ae8 0xa00c3ae8-0xa00c44ac (212 bytes)
a00c3ae8:  9d e3 bf 98  save  %sp, -104, %sp
a00c3aec:  ac 10 20 00  clr  %l6
a00c3af0:  aa 10 20 00  clr  %l5
a00c3af4:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00c3af8:  19 2a 01 f5  sethi  %hi(0xa807d400), %o4
a00c3afc:  98 13 21 e8  or  %o4, 0x1e8, %o4	! 0xa807d5e8
a00c3b00:  97 2c 20 04  sll  %l0, 4, %o3
a00c3b04:  1b 01 c0 00  sethi  %hi(0x7000000), %o5
a00c3b08:  c2 02 c0 0c  ld  [ %o3 + %o4 ], %g1
a00c3b0c:  82 08 40 0d  and  %g1, %o5, %g1
a00c3b10:  1b 01 40 00  sethi  %hi(0x5000000), %o5
a00c3b14:  80 a0 40 0d  cmp  %g1, %o5
a00c3b18:  12 80 02 63  bne  0xa00c44a4
a00c3b1c:  a4 02 c0 0c  add  %o3, %o4, %l2
a00c3b20:  90 10 00 10  mov  %l0, %o0
a00c3b24:  40 3b cb a4  call  0xa0fb69b4
a00c3b28:  92 10 20 a8  mov  0xa8, %o1
a00c3b2c:  80 8a 20 01  btst  1, %o0
a00c3b30:  22 80 00 05  be,a   0xa00c3b44
a00c3b34:  c2 0c a0 04  ldub  [ %l2 + 4 ], %g1
a00c3b38:  c0 2c a0 0d  clrb  [ %l2 + 0xd ]
a00c3b3c:  c0 2c a0 0c  clrb  [ %l2 + 0xc ]
a00c3b40:  c2 0c a0 04  ldub  [ %l2 + 4 ], %g1
a00c3b44:  80 88 60 01  btst  1, %g1
a00c3b48:  02 80 00 04  be  0xa00c3b58
a00c3b4c:  80 88 60 02  btst  2, %g1
a00c3b50:  10 80 00 08  b  0xa00c3b70
a00c3b54:  ac 10 20 00  clr  %l6
a00c3b58:  02 80 00 04  be  0xa00c3b68
a00c3b5c:  80 88 60 04  btst  4, %g1
a00c3b60:  10 80 00 04  b  0xa00c3b70
a00c3b64:  ac 10 20 01  mov  1, %l6
a00c3b68:  32 80 00 02  bne,a   0xa00c3b70
a00c3b6c:  ac 10 20 02  mov  2, %l6
a00c3b70:  c2 0c a0 0d  ldub  [ %l2 + 0xd ], %g1
a00c3b74:  80 a0 60 0d  cmp  %g1, 0xd
a00c3b78:  18 80 02 44  bgu  0xa00c4488
a00c3b7c:  90 05 60 02  add  %l5, 2, %o0
a00c3b80:  1b 27 c6 ce  sethi  %hi(0x9f1b3800), %o5
a00c3b84:  83 28 60 02  sll  %g1, 2, %g1
a00c3b88:  9a 13 62 b0  or  %o5, 0x2b0, %o5
a00c3b8c:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00c3b90:  81 c0 40 00  jmp  %g1
a00c3b94:  01 00 00 00  nop
a00c3b98:  90 10 00 10  mov  %l0, %o0
a00c3b9c:  40 3b cb 86  call  0xa0fb69b4
a00c3ba0:  92 10 20 a8  mov  0xa8, %o1
a00c3ba4:  80 8a 20 01  btst  1, %o0
a00c3ba8:  02 80 02 38  be  0xa00c4488
a00c3bac:  90 05 60 02  add  %l5, 2, %o0
a00c3bb0:  29 2a 01 e1  sethi  %hi(0xa8078400), %l4
a00c3bb4:  7f ff f9 a6  call  0xa00c224c
a00c3bb8:  90 15 22 20  or  %l4, 0x220, %o0	! 0xa8078620
a00c3bbc:  90 10 00 10  mov  %l0, %o0
a00c3bc0:  92 10 20 a6  mov  0xa6, %o1
a00c3bc4:  40 3b cb 8e  call  0xa0fb69fc
a00c3bc8:  94 10 20 0a  mov  0xa, %o2
a00c3bcc:  90 10 00 10  mov  %l0, %o0
a00c3bd0:  92 10 20 a4  mov  0xa4, %o1
a00c3bd4:  40 3b cb 8a  call  0xa0fb69fc
a00c3bd8:  94 10 20 02  mov  2, %o2
a00c3bdc:  a6 10 20 00  clr  %l3
a00c3be0:  a2 10 20 00  clr  %l1
a00c3be4:  94 04 60 0a  add  %l1, 0xa, %o2
a00c3be8:  94 0a a0 ff  and  %o2, 0xff, %o2
a00c3bec:  90 10 00 10  mov  %l0, %o0
a00c3bf0:  40 3b cb 83  call  0xa0fb69fc
a00c3bf4:  92 10 20 a5  mov  0xa5, %o1
a00c3bf8:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00c3bfc:  82 15 22 20  or  %l4, 0x220, %g1
a00c3c00:  d4 08 40 0d  ldub  [ %g1 + %o5 ], %o2
a00c3c04:  90 10 00 10  mov  %l0, %o0
a00c3c08:  40 3b cb 7d  call  0xa0fb69fc
a00c3c0c:  92 10 20 a7  mov  0xa7, %o1
a00c3c10:  a2 04 60 01  inc  %l1
a00c3c14:  82 0c 60 ff  and  %l1, 0xff, %g1
a00c3c18:  80 a0 60 07  cmp  %g1, 7
a00c3c1c:  28 bf ff f3  bleu,a   0xa00c3be8
a00c3c20:  94 04 60 0a  add  %l1, 0xa, %o2
a00c3c24:  90 10 00 10  mov  %l0, %o0
a00c3c28:  92 10 20 a6  mov  0xa6, %o1
a00c3c2c:  40 3b cb 74  call  0xa0fb69fc
a00c3c30:  94 10 20 08  mov  8, %o2
a00c3c34:  90 10 00 10  mov  %l0, %o0
a00c3c38:  92 10 20 a4  mov  0xa4, %o1
a00c3c3c:  40 3b cb 70  call  0xa0fb69fc
a00c3c40:  94 10 20 00  clr  %o2
a00c3c44:  a2 10 20 00  clr  %l1
a00c3c48:  94 0c 60 ff  and  %l1, 0xff, %o2
a00c3c4c:  90 10 00 10  mov  %l0, %o0
a00c3c50:  40 3b cb 6b  call  0xa0fb69fc
a00c3c54:  92 10 20 a5  mov  0xa5, %o1
a00c3c58:  90 10 00 10  mov  %l0, %o0
a00c3c5c:  92 10 20 a7  mov  0xa7, %o1
a00c3c60:  40 3b cb 67  call  0xa0fb69fc
a00c3c64:  94 10 20 00  clr  %o2
a00c3c68:  a2 04 60 01  inc  %l1
a00c3c6c:  82 0c 60 ff  and  %l1, 0xff, %g1
a00c3c70:  80 a0 60 01  cmp  %g1, 1
a00c3c74:  08 bf ff f6  bleu  0xa00c3c4c
a00c3c78:  94 0c 60 ff  and  %l1, 0xff, %o2
a00c3c7c:  90 10 00 10  mov  %l0, %o0
a00c3c80:  92 10 20 a9  mov  0xa9, %o1
a00c3c84:  40 3b cb 5e  call  0xa0fb69fc
a00c3c88:  94 10 20 60  mov  0x60, %o2
a00c3c8c:  10 80 00 03  b  0xa00c3c98
a00c3c90:  90 10 00 10  mov  %l0, %o0
a00c3c94:  90 10 00 10  mov  %l0, %o0
a00c3c98:  40 3b cb 47  call  0xa0fb69b4
a00c3c9c:  92 10 20 a9  mov  0xa9, %o1
a00c3ca0:  80 8a 20 40  btst  0x40, %o0
a00c3ca4:  12 80 00 06  bne  0xa00c3cbc
a00c3ca8:  83 2c e0 10  sll  %l3, 0x10, %g1
a00c3cac:  83 30 60 10  srl  %g1, 0x10, %g1
a00c3cb0:  80 a0 6b b7  cmp  %g1, 0xbb7
a00c3cb4:  28 bf ff f8  bleu,a   0xa00c3c94
a00c3cb8:  a6 04 e0 01  inc  %l3
a00c3cbc:  90 10 00 10  mov  %l0, %o0
a00c3cc0:  92 10 20 a6  mov  0xa6, %o1
a00c3cc4:  40 3b cb 4e  call  0xa0fb69fc
a00c3cc8:  94 10 20 01  mov  1, %o2
a00c3ccc:  90 10 00 10  mov  %l0, %o0
a00c3cd0:  92 10 20 a4  mov  0xa4, %o1
a00c3cd4:  40 3b cb 4a  call  0xa0fb69fc
a00c3cd8:  94 10 20 00  clr  %o2
a00c3cdc:  90 10 00 10  mov  %l0, %o0
a00c3ce0:  92 10 20 a5  mov  0xa5, %o1
a00c3ce4:  40 3b cb 46  call  0xa0fb69fc
a00c3ce8:  94 10 20 01  mov  1, %o2
a00c3cec:  96 10 20 01  mov  1, %o3
a00c3cf0:  90 10 00 10  mov  %l0, %o0
a00c3cf4:  92 10 20 a7  mov  0xa7, %o1
a00c3cf8:  40 3b cb 6a  call  0xa0fb6aa0
a00c3cfc:  94 10 20 05  mov  5, %o2
a00c3d00:  90 10 00 10  mov  %l0, %o0
a00c3d04:  92 10 20 a6  mov  0xa6, %o1
a00c3d08:  40 3b cb 3d  call  0xa0fb69fc
a00c3d0c:  94 10 20 09  mov  9, %o2
a00c3d10:  90 10 00 10  mov  %l0, %o0
a00c3d14:  92 10 20 a4  mov  0xa4, %o1
a00c3d18:  40 3b cb 39  call  0xa0fb69fc
a00c3d1c:  94 10 20 00  clr  %o2
a00c3d20:  90 10 00 10  mov  %l0, %o0
a00c3d24:  92 10 20 a5  mov  0xa5, %o1
a00c3d28:  40 3b cb 35  call  0xa0fb69fc
a00c3d2c:  94 10 20 00  clr  %o2
a00c3d30:  90 10 00 10  mov  %l0, %o0
a00c3d34:  92 10 20 a7  mov  0xa7, %o1
a00c3d38:  40 3b cb 31  call  0xa0fb69fc
a00c3d3c:  94 10 20 02  mov  2, %o2
a00c3d40:  90 10 00 10  mov  %l0, %o0
a00c3d44:  92 10 20 a8  mov  0xa8, %o1
a00c3d48:  40 3b cb 2d  call  0xa0fb69fc
a00c3d4c:  94 10 20 ff  mov  0xff, %o2
a00c3d50:  90 10 00 10  mov  %l0, %o0
a00c3d54:  92 10 20 a9  mov  0xa9, %o1
a00c3d58:  40 3b cb 29  call  0xa0fb69fc
a00c3d5c:  94 10 20 10  mov  0x10, %o2
a00c3d60:  a0 0d a0 ff  and  %l6, 0xff, %l0
a00c3d64:  82 10 20 02  mov  2, %g1
a00c3d68:  80 a4 20 02  cmp  %l0, 2
a00c3d6c:  02 80 00 0d  be  0xa00c3da0
a00c3d70:  c2 2c a0 0d  stb  %g1, [ %l2 + 0xd ]
a00c3d74:  90 10 00 10  mov  %l0, %o0
a00c3d78:  92 10 20 04  mov  4, %o1
a00c3d7c:  94 10 20 10  mov  0x10, %o2
a00c3d80:  40 00 0e 50  call  0xa00c76c0
a00c3d84:  96 10 20 00  clr  %o3
a00c3d88:  90 10 00 10  mov  %l0, %o0
a00c3d8c:  92 10 20 00  clr  %o1
a00c3d90:  94 10 20 0f  mov  0xf, %o2
a00c3d94:  96 10 20 01  mov  1, %o3
a00c3d98:  40 3b d0 cd  call  0xa0fb80cc
a00c3d9c:  98 10 20 00  clr  %o4
a00c3da0:  da 04 80 00  ld  [ %l2 ], %o5
a00c3da4:  03 00 20 00  sethi  %hi(0x800000), %g1
a00c3da8:  82 2b 40 01  andn  %o5, %g1, %g1
a00c3dac:  10 80 01 b6  b  0xa00c4484
a00c3db0:  c2 24 80 00  st  %g1, [ %l2 ]
a00c3db4:  90 10 00 10  mov  %l0, %o0
a00c3db8:  40 3b ca ff  call  0xa0fb69b4
a00c3dbc:  92 10 20 a8  mov  0xa8, %o1
a00c3dc0:  80 8a 20 02  btst  2, %o0
a00c3dc4:  02 80 00 0d  be  0xa00c3df8
a00c3dc8:  90 10 00 10  mov  %l0, %o0
a00c3dcc:  92 10 20 a8  mov  0xa8, %o1
a00c3dd0:  40 3b cb 0b  call  0xa0fb69fc
a00c3dd4:  94 10 20 02  mov  2, %o2
a00c3dd8:  c2 04 80 00  ld  [ %l2 ], %g1
a00c3ddc:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a00c3de0:  9a 28 40 0d  andn  %g1, %o5, %o5
a00c3de4:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00c3de8:  82 2b 40 01  andn  %o5, %g1, %g1
a00c3dec:  c2 24 80 00  st  %g1, [ %l2 ]
a00c3df0:  10 80 00 f6  b  0xa00c41c8
a00c3df4:  82 10 20 03  mov  3, %g1
a00c3df8:  40 3b ca ef  call  0xa0fb69b4
a00c3dfc:  92 10 20 a8  mov  0xa8, %o1
a00c3e00:  80 8a 20 04  btst  4, %o0
a00c3e04:  22 80 01 a1  be,a   0xa00c4488
a00c3e08:  90 05 60 02  add  %l5, 2, %o0
a00c3e0c:  90 10 00 10  mov  %l0, %o0
a00c3e10:  92 10 20 a8  mov  0xa8, %o1
a00c3e14:  40 3b ca fa  call  0xa0fb69fc
a00c3e18:  94 10 20 04  mov  4, %o2
a00c3e1c:  10 80 00 eb  b  0xa00c41c8
a00c3e20:  82 10 20 04  mov  4, %g1
a00c3e24:  c2 04 80 00  ld  [ %l2 ], %g1
a00c3e28:  80 a0 60 00  cmp  %g1, 0
a00c3e2c:  06 80 00 19  bl  0xa00c3e90
a00c3e30:  1b 30 00 00  sethi  %hi(0xc0000000), %o5
a00c3e34:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c3e38:  da 08 62 29  ldub  [ %g1 + 0x229 ], %o5	! 0xa807d629
a00c3e3c:  80 a3 60 ff  cmp  %o5, 0xff
a00c3e40:  02 80 00 05  be  0xa00c3e54
a00c3e44:  82 04 20 02  add  %l0, 2, %g1
a00c3e48:  80 a3 40 01  cmp  %o5, %g1
a00c3e4c:  32 80 00 0c  bne,a   0xa00c3e7c
a00c3e50:  da 04 80 00  ld  [ %l2 ], %o5
a00c3e54:  90 05 60 02  add  %l5, 2, %o0
a00c3e58:  7f ff fa 40  call  0xa00c2758
a00c3e5c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c3e60:  da 04 80 00  ld  [ %l2 ], %o5
a00c3e64:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00c3e68:  82 2b 40 01  andn  %o5, %g1, %g1
a00c3e6c:  91 2a 20 1f  sll  %o0, 0x1f, %o0
a00c3e70:  82 10 40 08  or  %g1, %o0, %g1
a00c3e74:  c2 24 80 00  st  %g1, [ %l2 ]
a00c3e78:  da 04 80 00  ld  [ %l2 ], %o5
a00c3e7c:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00c3e80:  82 2b 40 01  andn  %o5, %g1, %g1
a00c3e84:  c2 24 80 00  st  %g1, [ %l2 ]
a00c3e88:  1b 30 00 00  sethi  %hi(0xc0000000), %o5
a00c3e8c:  c2 04 80 00  ld  [ %l2 ], %g1
a00c3e90:  82 08 40 0d  and  %g1, %o5, %g1
a00c3e94:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a00c3e98:  80 a0 40 0d  cmp  %g1, %o5
a00c3e9c:  32 80 00 26  bne,a   0xa00c3f34
a00c3ea0:  da 04 80 00  ld  [ %l2 ], %o5
a00c3ea4:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00c3ea8:  90 10 00 10  mov  %l0, %o0
a00c3eac:  40 3b ca c2  call  0xa0fb69b4
a00c3eb0:  92 10 20 a8  mov  0xa8, %o1
a00c3eb4:  80 8a 20 08  btst  8, %o0
a00c3eb8:  22 80 00 1f  be,a   0xa00c3f34
a00c3ebc:  da 04 80 00  ld  [ %l2 ], %o5
a00c3ec0:  90 10 00 10  mov  %l0, %o0
a00c3ec4:  92 10 20 a8  mov  0xa8, %o1
a00c3ec8:  40 3b ca cd  call  0xa0fb69fc
a00c3ecc:  94 10 20 08  mov  8, %o2
a00c3ed0:  90 10 00 10  mov  %l0, %o0
a00c3ed4:  92 10 20 a6  mov  0xa6, %o1
a00c3ed8:  40 3b ca c9  call  0xa0fb69fc
a00c3edc:  94 10 20 09  mov  9, %o2
a00c3ee0:  90 10 00 10  mov  %l0, %o0
a00c3ee4:  92 10 20 a4  mov  0xa4, %o1
a00c3ee8:  40 3b ca c5  call  0xa0fb69fc
a00c3eec:  94 10 20 00  clr  %o2
a00c3ef0:  90 10 00 10  mov  %l0, %o0
a00c3ef4:  92 10 20 a5  mov  0xa5, %o1
a00c3ef8:  40 3b ca c1  call  0xa0fb69fc
a00c3efc:  94 10 20 00  clr  %o2
a00c3f00:  90 10 00 10  mov  %l0, %o0
a00c3f04:  92 10 20 a7  mov  0xa7, %o1
a00c3f08:  40 3b ca bd  call  0xa0fb69fc
a00c3f0c:  94 10 20 04  mov  4, %o2
a00c3f10:  90 10 00 10  mov  %l0, %o0
a00c3f14:  92 10 20 a4  mov  0xa4, %o1
a00c3f18:  40 3b ca b9  call  0xa0fb69fc
a00c3f1c:  94 10 20 20  mov  0x20, %o2
a00c3f20:  c2 04 80 00  ld  [ %l2 ], %g1
a00c3f24:  1b 10 00 00  sethi  %hi(0x40000000), %o5
a00c3f28:  82 10 40 0d  or  %g1, %o5, %g1
a00c3f2c:  c2 24 80 00  st  %g1, [ %l2 ]
a00c3f30:  da 04 80 00  ld  [ %l2 ], %o5
a00c3f34:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00c3f38:  80 8b 40 01  btst  %o5, %g1
a00c3f3c:  02 80 01 53  be  0xa00c4488
a00c3f40:  90 05 60 02  add  %l5, 2, %o0
a00c3f44:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00c3f48:  90 10 00 10  mov  %l0, %o0
a00c3f4c:  92 10 20 a6  mov  0xa6, %o1
a00c3f50:  40 3b ca ab  call  0xa0fb69fc
a00c3f54:  94 10 20 09  mov  9, %o2
a00c3f58:  90 10 00 10  mov  %l0, %o0
a00c3f5c:  92 10 20 a4  mov  0xa4, %o1
a00c3f60:  40 3b ca a7  call  0xa0fb69fc
a00c3f64:  94 10 20 20  mov  0x20, %o2
a00c3f68:  90 10 00 10  mov  %l0, %o0
a00c3f6c:  92 10 20 a5  mov  0xa5, %o1
a00c3f70:  40 3b ca a3  call  0xa0fb69fc
a00c3f74:  94 10 20 02  mov  2, %o2
a00c3f78:  90 10 00 10  mov  %l0, %o0
a00c3f7c:  40 3b ca 8e  call  0xa0fb69b4
a00c3f80:  92 10 20 a7  mov  0xa7, %o1
a00c3f84:  80 8a 20 1c  btst  0x1c, %o0
a00c3f88:  32 80 01 40  bne,a   0xa00c4488
a00c3f8c:  90 05 60 02  add  %l5, 2, %o0
a00c3f90:  90 10 00 10  mov  %l0, %o0
a00c3f94:  92 10 20 a8  mov  0xa8, %o1
a00c3f98:  40 3b ca 99  call  0xa0fb69fc
a00c3f9c:  94 10 20 10  mov  0x10, %o2
a00c3fa0:  90 10 00 10  mov  %l0, %o0
a00c3fa4:  92 10 20 a4  mov  0xa4, %o1
a00c3fa8:  40 3b ca 95  call  0xa0fb69fc
a00c3fac:  94 10 20 00  clr  %o2
a00c3fb0:  90 10 00 10  mov  %l0, %o0
a00c3fb4:  92 10 20 a5  mov  0xa5, %o1
a00c3fb8:  40 3b ca 91  call  0xa0fb69fc
a00c3fbc:  94 10 20 00  clr  %o2
a00c3fc0:  90 10 00 10  mov  %l0, %o0
a00c3fc4:  92 10 20 a7  mov  0xa7, %o1
a00c3fc8:  10 80 00 1b  b  0xa00c4034
a00c3fcc:  94 10 20 08  mov  8, %o2
a00c3fd0:  90 10 00 10  mov  %l0, %o0
a00c3fd4:  40 3b ca 78  call  0xa0fb69b4
a00c3fd8:  92 10 20 a8  mov  0xa8, %o1
a00c3fdc:  80 8a 20 08  btst  8, %o0
a00c3fe0:  22 80 01 2a  be,a   0xa00c4488
a00c3fe4:  90 05 60 02  add  %l5, 2, %o0
a00c3fe8:  90 10 00 10  mov  %l0, %o0
a00c3fec:  92 10 20 a8  mov  0xa8, %o1
a00c3ff0:  40 3b ca 83  call  0xa0fb69fc
a00c3ff4:  94 10 20 08  mov  8, %o2
a00c3ff8:  90 10 00 10  mov  %l0, %o0
a00c3ffc:  92 10 20 a6  mov  0xa6, %o1
a00c4000:  40 3b ca 7f  call  0xa0fb69fc
a00c4004:  94 10 20 09  mov  9, %o2
a00c4008:  90 10 00 10  mov  %l0, %o0
a00c400c:  92 10 20 a4  mov  0xa4, %o1
a00c4010:  40 3b ca 7b  call  0xa0fb69fc
a00c4014:  94 10 20 00  clr  %o2
a00c4018:  90 10 00 10  mov  %l0, %o0
a00c401c:  92 10 20 a5  mov  0xa5, %o1
a00c4020:  40 3b ca 77  call  0xa0fb69fc
a00c4024:  94 10 20 00  clr  %o2
a00c4028:  90 10 00 10  mov  %l0, %o0
a00c402c:  92 10 20 a7  mov  0xa7, %o1
a00c4030:  94 10 20 04  mov  4, %o2
a00c4034:  40 3b ca 72  call  0xa0fb69fc
a00c4038:  01 00 00 00  nop
a00c403c:  90 10 00 10  mov  %l0, %o0
a00c4040:  92 10 20 a4  mov  0xa4, %o1
a00c4044:  40 3b ca 6e  call  0xa0fb69fc
a00c4048:  94 10 20 20  mov  0x20, %o2
a00c404c:  10 80 00 5f  b  0xa00c41c8
a00c4050:  82 10 20 05  mov  5, %g1
a00c4054:  90 10 00 10  mov  %l0, %o0
a00c4058:  40 3b ca 57  call  0xa0fb69b4
a00c405c:  92 10 20 a8  mov  0xa8, %o1
a00c4060:  80 8a 20 80  btst  0x80, %o0
a00c4064:  22 80 01 09  be,a   0xa00c4488
a00c4068:  90 05 60 02  add  %l5, 2, %o0
a00c406c:  90 10 00 10  mov  %l0, %o0
a00c4070:  92 10 20 a8  mov  0xa8, %o1
a00c4074:  40 3b ca 62  call  0xa0fb69fc
a00c4078:  94 10 20 80  mov  0x80, %o2
a00c407c:  10 80 00 53  b  0xa00c41c8
a00c4080:  82 10 20 08  mov  8, %g1
a00c4084:  90 10 00 10  mov  %l0, %o0
a00c4088:  40 3b ca 4b  call  0xa0fb69b4
a00c408c:  92 10 20 a9  mov  0xa9, %o1
a00c4090:  80 8a 20 01  btst  1, %o0
a00c4094:  02 80 00 fd  be  0xa00c4488
a00c4098:  90 05 60 02  add  %l5, 2, %o0
a00c409c:  90 10 00 10  mov  %l0, %o0
a00c40a0:  92 10 20 a9  mov  0xa9, %o1
a00c40a4:  40 3b ca 56  call  0xa0fb69fc
a00c40a8:  94 10 20 01  mov  1, %o2
a00c40ac:  c2 04 80 00  ld  [ %l2 ], %g1
a00c40b0:  1b 00 07 c0  sethi  %hi(0x1f0000), %o5
a00c40b4:  9a 28 40 0d  andn  %g1, %o5, %o5
a00c40b8:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c40bc:  d8 08 60 58  ldub  [ %g1 + 0x58 ], %o4	! 0xa8078c58
a00c40c0:  96 04 20 02  add  %l0, 2, %o3
a00c40c4:  03 00 00 40  sethi  %hi(0x10000), %g1
a00c40c8:  9a 13 40 01  or  %o5, %g1, %o5
a00c40cc:  99 3b 00 0b  sra  %o4, %o3, %o4
a00c40d0:  80 8b 20 01  btst  1, %o4
a00c40d4:  02 80 00 05  be  0xa00c40e8
a00c40d8:  da 24 80 00  st  %o5, [ %l2 ]
a00c40dc:  82 10 20 09  mov  9, %g1
a00c40e0:  10 80 00 e7  b  0xa00c447c
a00c40e4:  c2 2c a0 0d  stb  %g1, [ %l2 + 0xd ]
a00c40e8:  82 10 20 0d  mov  0xd, %g1
a00c40ec:  11 27 c6 dd  sethi  %hi(0x9f1b7400), %o0
a00c40f0:  c2 2c a0 0d  stb  %g1, [ %l2 + 0xd ]
a00c40f4:  92 10 00 10  mov  %l0, %o1
a00c40f8:  40 3a fb d3  call  0xa0f83044
a00c40fc:  90 12 21 b8  or  %o0, 0x1b8, %o0
a00c4100:  10 80 00 e2  b  0xa00c4488
a00c4104:  90 05 60 02  add  %l5, 2, %o0
a00c4108:  a2 0d a0 ff  and  %l6, 0xff, %l1
a00c410c:  80 a4 60 02  cmp  %l1, 2
a00c4110:  02 80 00 0c  be  0xa00c4140
a00c4114:  90 10 00 11  mov  %l1, %o0
a00c4118:  92 10 20 04  mov  4, %o1
a00c411c:  94 10 20 10  mov  0x10, %o2
a00c4120:  40 00 0d 68  call  0xa00c76c0
a00c4124:  96 10 20 00  clr  %o3
a00c4128:  90 10 00 11  mov  %l1, %o0
a00c412c:  92 10 20 00  clr  %o1
a00c4130:  94 10 20 0f  mov  0xf, %o2
a00c4134:  96 10 20 01  mov  1, %o3
a00c4138:  40 3b cf e5  call  0xa0fb80cc
a00c413c:  98 10 20 00  clr  %o4
a00c4140:  da 04 80 00  ld  [ %l2 ], %o5
a00c4144:  03 00 10 00  sethi  %hi(0x400000), %g1
a00c4148:  80 8b 40 01  btst  %o5, %g1
a00c414c:  22 80 00 cf  be,a   0xa00c4488
a00c4150:  90 05 60 02  add  %l5, 2, %o0
a00c4154:  90 10 00 10  mov  %l0, %o0
a00c4158:  92 10 20 a6  mov  0xa6, %o1
a00c415c:  40 3b ca 28  call  0xa0fb69fc
a00c4160:  94 10 20 09  mov  9, %o2
a00c4164:  90 10 00 10  mov  %l0, %o0
a00c4168:  92 10 20 a4  mov  0xa4, %o1
a00c416c:  40 3b ca 24  call  0xa0fb69fc
a00c4170:  94 10 20 00  clr  %o2
a00c4174:  90 10 00 10  mov  %l0, %o0
a00c4178:  92 10 20 a5  mov  0xa5, %o1
a00c417c:  40 3b ca 20  call  0xa0fb69fc
a00c4180:  94 10 20 00  clr  %o2
a00c4184:  90 10 00 10  mov  %l0, %o0
a00c4188:  92 10 20 a7  mov  0xa7, %o1
a00c418c:  40 3b ca 1c  call  0xa0fb69fc
a00c4190:  94 10 20 00  clr  %o2
a00c4194:  90 10 00 10  mov  %l0, %o0
a00c4198:  92 10 20 a7  mov  0xa7, %o1
a00c419c:  40 3b ca 18  call  0xa0fb69fc
a00c41a0:  94 10 20 20  mov  0x20, %o2
a00c41a4:  90 10 00 10  mov  %l0, %o0
a00c41a8:  92 10 20 a7  mov  0xa7, %o1
a00c41ac:  40 3b ca 14  call  0xa0fb69fc
a00c41b0:  94 10 20 00  clr  %o2
a00c41b4:  90 10 00 10  mov  %l0, %o0
a00c41b8:  92 10 20 a4  mov  0xa4, %o1
a00c41bc:  40 3b ca 10  call  0xa0fb69fc
a00c41c0:  94 10 20 20  mov  0x20, %o2
a00c41c4:  82 10 20 0a  mov  0xa, %g1
a00c41c8:  10 80 00 af  b  0xa00c4484
a00c41cc:  c2 2c a0 0d  stb  %g1, [ %l2 + 0xd ]
a00c41d0:  7f ff fb 62  call  0xa00c2f58
a00c41d4:  90 10 00 10  mov  %l0, %o0
a00c41d8:  80 8a 20 ff  btst  0xff, %o0
a00c41dc:  22 80 00 18  be,a   0xa00c423c
a00c41e0:  90 10 00 10  mov  %l0, %o0
a00c41e4:  11 27 c6 dd  sethi  %hi(0x9f1b7400), %o0
a00c41e8:  92 10 00 10  mov  %l0, %o1
a00c41ec:  40 3a fb 96  call  0xa0f83044
a00c41f0:  90 12 21 d8  or  %o0, 0x1d8, %o0
a00c41f4:  90 10 00 10  mov  %l0, %o0
a00c41f8:  92 10 20 a4  mov  0xa4, %o1
a00c41fc:  40 3b ca 00  call  0xa0fb69fc
a00c4200:  94 10 20 00  clr  %o2
a00c4204:  90 10 00 10  mov  %l0, %o0
a00c4208:  92 10 20 a5  mov  0xa5, %o1
a00c420c:  40 3b c9 fc  call  0xa0fb69fc
a00c4210:  94 10 20 01  mov  1, %o2
a00c4214:  90 10 00 10  mov  %l0, %o0
a00c4218:  92 10 20 a6  mov  0xa6, %o1
a00c421c:  40 3b c9 f8  call  0xa0fb69fc
a00c4220:  94 10 20 08  mov  8, %o2
a00c4224:  90 10 00 10  mov  %l0, %o0
a00c4228:  92 10 20 a7  mov  0xa7, %o1
a00c422c:  40 3b c9 f4  call  0xa0fb69fc
a00c4230:  94 10 20 08  mov  8, %o2
a00c4234:  10 80 00 95  b  0xa00c4488
a00c4238:  90 05 60 02  add  %l5, 2, %o0
a00c423c:  40 3b c9 de  call  0xa0fb69b4
a00c4240:  92 10 20 aa  mov  0xaa, %o1
a00c4244:  80 8a 20 01  btst  1, %o0
a00c4248:  02 80 00 32  be  0xa00c4310
a00c424c:  90 10 00 10  mov  %l0, %o0
a00c4250:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c4254:  c2 08 60 b0  ldub  [ %g1 + 0xb0 ], %g1	! 0xa8078cb0
a00c4258:  80 a0 60 00  cmp  %g1, 0
a00c425c:  12 80 00 2d  bne  0xa00c4310
a00c4260:  92 10 20 aa  mov  0xaa, %o1
a00c4264:  40 3b c9 e6  call  0xa0fb69fc
a00c4268:  94 10 20 01  mov  1, %o2
a00c426c:  90 10 00 10  mov  %l0, %o0
a00c4270:  92 10 20 a6  mov  0xa6, %o1
a00c4274:  40 3b c9 e2  call  0xa0fb69fc
a00c4278:  94 10 20 08  mov  8, %o2
a00c427c:  90 10 00 10  mov  %l0, %o0
a00c4280:  92 10 20 a4  mov  0xa4, %o1
a00c4284:  40 3b c9 de  call  0xa0fb69fc
a00c4288:  94 10 20 00  clr  %o2
a00c428c:  90 10 00 10  mov  %l0, %o0
a00c4290:  92 10 20 a5  mov  0xa5, %o1
a00c4294:  40 3b c9 da  call  0xa0fb69fc
a00c4298:  94 10 20 01  mov  1, %o2
a00c429c:  90 10 00 10  mov  %l0, %o0
a00c42a0:  92 10 20 a7  mov  0xa7, %o1
a00c42a4:  40 3b c9 d6  call  0xa0fb69fc
a00c42a8:  94 10 20 04  mov  4, %o2
a00c42ac:  90 10 00 10  mov  %l0, %o0
a00c42b0:  92 10 20 a4  mov  0xa4, %o1
a00c42b4:  40 3b c9 d2  call  0xa0fb69fc
a00c42b8:  94 10 20 20  mov  0x20, %o2
a00c42bc:  90 10 00 10  mov  %l0, %o0
a00c42c0:  92 10 20 a6  mov  0xa6, %o1
a00c42c4:  40 3b c9 ce  call  0xa0fb69fc
a00c42c8:  94 10 20 09  mov  9, %o2
a00c42cc:  90 10 00 10  mov  %l0, %o0
a00c42d0:  92 10 20 a4  mov  0xa4, %o1
a00c42d4:  40 3b c9 ca  call  0xa0fb69fc
a00c42d8:  94 10 20 00  clr  %o2
a00c42dc:  90 10 00 10  mov  %l0, %o0
a00c42e0:  92 10 20 a5  mov  0xa5, %o1
a00c42e4:  40 3b c9 c6  call  0xa0fb69fc
a00c42e8:  94 10 20 00  clr  %o2
a00c42ec:  90 10 00 10  mov  %l0, %o0
a00c42f0:  92 10 20 a7  mov  0xa7, %o1
a00c42f4:  40 3b c9 c2  call  0xa0fb69fc
a00c42f8:  94 10 20 40  mov  0x40, %o2
a00c42fc:  90 10 00 10  mov  %l0, %o0
a00c4300:  92 10 20 a4  mov  0xa4, %o1
a00c4304:  40 3b c9 be  call  0xa0fb69fc
a00c4308:  94 10 20 20  mov  0x20, %o2
a00c430c:  90 10 00 10  mov  %l0, %o0
a00c4310:  40 3b c9 a9  call  0xa0fb69b4
a00c4314:  92 10 20 aa  mov  0xaa, %o1
a00c4318:  80 8a 20 02  btst  2, %o0
a00c431c:  02 80 00 1a  be  0xa00c4384
a00c4320:  90 10 00 10  mov  %l0, %o0
a00c4324:  92 10 20 aa  mov  0xaa, %o1
a00c4328:  40 3b c9 b5  call  0xa0fb69fc
a00c432c:  94 10 20 02  mov  2, %o2
a00c4330:  90 10 00 10  mov  %l0, %o0
a00c4334:  92 10 20 a6  mov  0xa6, %o1
a00c4338:  40 3b c9 b1  call  0xa0fb69fc
a00c433c:  94 10 20 08  mov  8, %o2
a00c4340:  90 10 00 10  mov  %l0, %o0
a00c4344:  92 10 20 a4  mov  0xa4, %o1
a00c4348:  40 3b c9 ad  call  0xa0fb69fc
a00c434c:  94 10 20 00  clr  %o2
a00c4350:  90 10 00 10  mov  %l0, %o0
a00c4354:  92 10 20 a5  mov  0xa5, %o1
a00c4358:  40 3b c9 a9  call  0xa0fb69fc
a00c435c:  94 10 20 01  mov  1, %o2
a00c4360:  90 10 00 10  mov  %l0, %o0
a00c4364:  92 10 20 a7  mov  0xa7, %o1
a00c4368:  40 3b c9 a5  call  0xa0fb69fc
a00c436c:  94 10 20 00  clr  %o2
a00c4370:  90 10 00 10  mov  %l0, %o0
a00c4374:  92 10 20 a4  mov  0xa4, %o1
a00c4378:  40 3b c9 a1  call  0xa0fb69fc
a00c437c:  94 10 20 20  mov  0x20, %o2
a00c4380:  90 10 00 10  mov  %l0, %o0
a00c4384:  40 3b c9 8c  call  0xa0fb69b4
a00c4388:  92 10 20 aa  mov  0xaa, %o1
a00c438c:  80 8a 20 04  btst  4, %o0
a00c4390:  02 80 00 06  be  0xa00c43a8
a00c4394:  90 10 00 10  mov  %l0, %o0
a00c4398:  92 10 20 aa  mov  0xaa, %o1
a00c439c:  40 3b c9 98  call  0xa0fb69fc
a00c43a0:  94 10 20 04  mov  4, %o2
a00c43a4:  90 10 00 10  mov  %l0, %o0
a00c43a8:  40 3b c9 83  call  0xa0fb69b4
a00c43ac:  92 10 20 aa  mov  0xaa, %o1
a00c43b0:  80 8a 20 40  btst  0x40, %o0
a00c43b4:  02 80 00 09  be  0xa00c43d8
a00c43b8:  92 10 20 aa  mov  0xaa, %o1
a00c43bc:  90 10 00 10  mov  %l0, %o0
a00c43c0:  40 3b c9 8f  call  0xa0fb69fc
a00c43c4:  94 10 20 40  mov  0x40, %o2
a00c43c8:  9a 10 20 01  mov  1, %o5
a00c43cc:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c43d0:  da 28 60 b0  stb  %o5, [ %g1 + 0xb0 ]	! 0xa8078cb0
a00c43d4:  92 10 20 aa  mov  0xaa, %o1
a00c43d8:  40 3b c9 77  call  0xa0fb69b4
a00c43dc:  90 10 00 10  mov  %l0, %o0
a00c43e0:  90 10 00 10  mov  %l0, %o0
a00c43e4:  40 3b c9 74  call  0xa0fb69b4
a00c43e8:  92 10 20 aa  mov  0xaa, %o1
a00c43ec:  80 8a 20 20  btst  0x20, %o0
a00c43f0:  02 80 00 1a  be  0xa00c4458
a00c43f4:  90 10 00 10  mov  %l0, %o0
a00c43f8:  92 10 20 aa  mov  0xaa, %o1
a00c43fc:  40 3b c9 80  call  0xa0fb69fc
a00c4400:  94 10 20 38  mov  0x38, %o2
a00c4404:  90 10 00 10  mov  %l0, %o0
a00c4408:  92 10 20 a6  mov  0xa6, %o1
a00c440c:  40 3b c9 7c  call  0xa0fb69fc
a00c4410:  94 10 20 09  mov  9, %o2
a00c4414:  90 10 00 10  mov  %l0, %o0
a00c4418:  92 10 20 a4  mov  0xa4, %o1
a00c441c:  40 3b c9 78  call  0xa0fb69fc
a00c4420:  94 10 20 00  clr  %o2
a00c4424:  90 10 00 10  mov  %l0, %o0
a00c4428:  92 10 20 a5  mov  0xa5, %o1
a00c442c:  40 3b c9 74  call  0xa0fb69fc
a00c4430:  94 10 20 00  clr  %o2
a00c4434:  90 10 00 10  mov  %l0, %o0
a00c4438:  92 10 20 a7  mov  0xa7, %o1
a00c443c:  40 3b c9 70  call  0xa0fb69fc
a00c4440:  94 10 20 80  mov  0x80, %o2
a00c4444:  90 10 00 10  mov  %l0, %o0
a00c4448:  92 10 20 a4  mov  0xa4, %o1
a00c444c:  40 3b c9 6c  call  0xa0fb69fc
a00c4450:  94 10 20 20  mov  0x20, %o2
a00c4454:  90 10 00 10  mov  %l0, %o0
a00c4458:  40 3b c9 57  call  0xa0fb69b4
a00c445c:  92 10 20 aa  mov  0xaa, %o1
a00c4460:  80 8a 20 80  btst  0x80, %o0
a00c4464:  22 80 00 09  be,a   0xa00c4488
a00c4468:  90 05 60 02  add  %l5, 2, %o0
a00c446c:  90 10 00 10  mov  %l0, %o0
a00c4470:  92 10 20 aa  mov  0xaa, %o1
a00c4474:  40 3b c9 62  call  0xa0fb69fc
a00c4478:  94 10 20 80  mov  0x80, %o2
a00c447c:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c4480:  c0 28 60 b0  clrb  [ %g1 + 0xb0 ]	! 0xa8078cb0
a00c4484:  90 05 60 02  add  %l5, 2, %o0
a00c4488:  7f ff fb 2f  call  0xa00c3144
a00c448c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c4490:  aa 05 60 01  inc  %l5
a00c4494:  82 0d 60 ff  and  %l5, 0xff, %g1
a00c4498:  80 a0 60 01  cmp  %g1, 1
a00c449c:  08 bf fd 97  bleu  0xa00c3af8
a00c44a0:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00c44a4:  81 c7 e0 08  ret
a00c44a8:  81 e8 00 00  restore
