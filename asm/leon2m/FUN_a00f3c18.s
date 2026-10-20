# leon2m FUN_a00f3c18 0xa00f3c18-0xa00f3f64 (844 bytes)
a00f3c18:  9d e3 bf 98  save  %sp, -104, %sp
a00f3c1c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f3c20:  40 00 14 74  call  0xa00f8df0
a00f3c24:  90 10 00 18  mov  %i0, %o0
a00f3c28:  40 00 14 6b  call  0xa00f8dd4
a00f3c2c:  90 10 00 18  mov  %i0, %o0
a00f3c30:  40 00 b8 83  call  0xa0121e3c
a00f3c34:  90 10 00 18  mov  %i0, %o0
a00f3c38:  90 10 00 18  mov  %i0, %o0
a00f3c3c:  92 10 20 36  mov  0x36, %o1
a00f3c40:  7f ff f7 a5  call  0xa00f1ad4
a00f3c44:  94 10 20 00  clr  %o2
a00f3c48:  a8 10 20 30  mov  0x30, %l4
a00f3c4c:  a6 10 20 30  mov  0x30, %l3
a00f3c50:  90 10 00 18  mov  %i0, %o0
a00f3c54:  92 10 20 37  mov  0x37, %o1
a00f3c58:  7f ff f7 9f  call  0xa00f1ad4
a00f3c5c:  94 10 00 13  mov  %l3, %o2
a00f3c60:  a4 10 20 00  clr  %l2
a00f3c64:  90 10 00 18  mov  %i0, %o0
a00f3c68:  92 10 20 36  mov  0x36, %o1
a00f3c6c:  7f ff f7 9a  call  0xa00f1ad4
a00f3c70:  94 10 20 41  mov  0x41, %o2
a00f3c74:  67 fe 66 45  call  0x4008d588
a00f3c78:  a2 10 20 00  clr  %l1
a00f3c7c:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00f3c80:  40 00 b5 bd  call  0xa0121374
a00f3c84:  90 10 00 18  mov  %i0, %o0
a00f3c88:  82 0a 20 ff  and  %o0, 0xff, %g1
a00f3c8c:  92 10 20 36  mov  0x36, %o1
a00f3c90:  80 a0 60 01  cmp  %g1, 1
a00f3c94:  02 80 00 0e  be  0xa00f3ccc
a00f3c98:  90 10 00 18  mov  %i0, %o0
a00f3c9c:  7f ff f7 7d  call  0xa00f1a90
a00f3ca0:  01 00 00 00  nop
a00f3ca4:  80 8a 20 01  btst  1, %o0
a00f3ca8:  02 80 00 3c  be  0xa00f3d98
a00f3cac:  91 34 20 10  srl  %l0, 0x10, %o0
a00f3cb0:  67 fe 66 39  call  0x4008d594
a00f3cb4:  01 00 00 00  nop
a00f3cb8:  93 2a 20 10  sll  %o0, 0x10, %o1
a00f3cbc:  91 32 60 10  srl  %o1, 0x10, %o0
a00f3cc0:  80 a2 20 63  cmp  %o0, 0x63
a00f3cc4:  08 bf ff ef  bleu  0xa00f3c80
a00f3cc8:  01 00 00 00  nop
a00f3ccc:  98 0c 60 ff  and  %l1, 0xff, %o4
a00f3cd0:  80 a3 20 00  cmp  %o4, 0
a00f3cd4:  12 80 00 05  bne  0xa00f3ce8
a00f3cd8:  9a 10 20 01  mov  1, %o5
a00f3cdc:  15 2a 00 ad  sethi  %hi(0xa802b400), %o2
a00f3ce0:  da 2a a3 ac  stb  %o5, [ %o2 + 0x3ac ]	! 0xa802b7ac
a00f3ce4:  80 a3 20 00  cmp  %o4, 0
a00f3ce8:  02 80 00 9d  be  0xa00f3f5c
a00f3cec:  82 10 20 00  clr  %g1
a00f3cf0:  92 10 20 3c  mov  0x3c, %o1
a00f3cf4:  7f ff f7 fc  call  0xa00f1ce4
a00f3cf8:  90 10 00 18  mov  %i0, %o0
a00f3cfc:  a0 0a 27 ff  and  %o0, 0x7ff, %l0
a00f3d00:  90 10 00 18  mov  %i0, %o0
a00f3d04:  7f ff f7 f8  call  0xa00f1ce4
a00f3d08:  92 10 20 40  mov  0x40, %o1
a00f3d0c:  90 0a 2f ff  and  %o0, 0xfff, %o0
a00f3d10:  80 a4 21 00  cmp  %l0, 0x100
a00f3d14:  a2 10 00 08  mov  %o0, %l1
a00f3d18:  18 80 00 03  bgu  0xa00f3d24
a00f3d1c:  9a 10 20 01  mov  1, %o5
a00f3d20:  9a 10 20 00  clr  %o5
a00f3d24:  80 a2 21 00  cmp  %o0, 0x100
a00f3d28:  18 80 00 03  bgu  0xa00f3d34
a00f3d2c:  82 10 20 01  mov  1, %g1
a00f3d30:  82 10 20 00  clr  %g1
a00f3d34:  80 8b 40 01  btst  %o5, %g1
a00f3d38:  12 80 00 03  bne  0xa00f3d44
a00f3d3c:  82 10 20 01  mov  1, %g1
a00f3d40:  82 10 20 00  clr  %g1
a00f3d44:  80 88 60 ff  btst  0xff, %g1
a00f3d48:  02 80 00 07  be  0xa00f3d64
a00f3d4c:  82 0c a0 ff  and  %l2, 0xff, %g1
a00f3d50:  a4 04 a0 01  inc  %l2
a00f3d54:  82 0c a0 ff  and  %l2, 0xff, %g1
a00f3d58:  80 a0 60 04  cmp  %g1, 4
a00f3d5c:  08 bf ff c3  bleu  0xa00f3c68
a00f3d60:  90 10 00 18  mov  %i0, %o0
a00f3d64:  80 a0 60 05  cmp  %g1, 5
a00f3d68:  02 80 00 08  be  0xa00f3d88
a00f3d6c:  80 a4 e0 a0  cmp  %l3, 0xa0
a00f3d70:  a8 05 20 10  add  %l4, 0x10, %l4
a00f3d74:  a6 0d 20 ff  and  %l4, 0xff, %l3
a00f3d78:  80 a4 e0 9f  cmp  %l3, 0x9f
a00f3d7c:  08 bf ff b6  bleu  0xa00f3c54
a00f3d80:  90 10 00 18  mov  %i0, %o0
a00f3d84:  80 a4 e0 a0  cmp  %l3, 0xa0
a00f3d88:  18 80 00 75  bgu  0xa00f3f5c
a00f3d8c:  82 10 20 00  clr  %g1
a00f3d90:  10 80 00 2f  b  0xa00f3e4c
a00f3d94:  90 10 00 18  mov  %i0, %o0
a00f3d98:  10 bf ff cd  b  0xa00f3ccc
a00f3d9c:  a2 10 20 01  mov  1, %l1
a00f3da0:  a6 10 20 01  mov  1, %l3
a00f3da4:  98 0c e0 ff  and  %l3, 0xff, %o4
a00f3da8:  80 a3 20 00  cmp  %o4, 0
a00f3dac:  12 80 00 06  bne  0xa00f3dc4
a00f3db0:  a6 0b 20 ff  and  %o4, 0xff, %l3
a00f3db4:  a6 10 20 01  mov  1, %l3
a00f3db8:  25 2a 00 ad  sethi  %hi(0xa802b400), %l2
a00f3dbc:  e6 2c a3 ac  stb  %l3, [ %l2 + 0x3ac ]	! 0xa802b7ac
a00f3dc0:  a6 0b 20 ff  and  %o4, 0xff, %l3
a00f3dc4:  80 a4 e0 01  cmp  %l3, 1
a00f3dc8:  12 80 00 65  bne  0xa00f3f5c
a00f3dcc:  82 10 20 00  clr  %g1
a00f3dd0:  92 10 20 3c  mov  0x3c, %o1
a00f3dd4:  7f ff f7 c4  call  0xa00f1ce4
a00f3dd8:  90 10 00 18  mov  %i0, %o0
a00f3ddc:  a4 0a 27 ff  and  %o0, 0x7ff, %l2
a00f3de0:  90 10 00 18  mov  %i0, %o0
a00f3de4:  7f ff f7 c0  call  0xa00f1ce4
a00f3de8:  92 10 20 40  mov  0x40, %o1
a00f3dec:  aa 0a 2f ff  and  %o0, 0xfff, %l5
a00f3df0:  90 0c 6f ff  and  %l1, 0xfff, %o0
a00f3df4:  82 25 40 08  sub  %l5, %o0, %g1
a00f3df8:  ad 38 60 1f  sra  %g1, 0x1f, %l6
a00f3dfc:  a8 1d 80 01  xor  %l6, %g1, %l4
a00f3e00:  a2 25 00 16  sub  %l4, %l6, %l1
a00f3e04:  80 a4 60 05  cmp  %l1, 5
a00f3e08:  14 80 00 0a  bg  0xa00f3e30
a00f3e0c:  a8 10 00 12  mov  %l2, %l4
a00f3e10:  96 0c 27 ff  and  %l0, 0x7ff, %o3
a00f3e14:  9a 24 80 0b  sub  %l2, %o3, %o5
a00f3e18:  95 3b 60 1f  sra  %o5, 0x1f, %o2
a00f3e1c:  92 1a 80 0d  xor  %o2, %o5, %o1
a00f3e20:  a0 22 40 0a  sub  %o1, %o2, %l0
a00f3e24:  80 a4 20 05  cmp  %l0, 5
a00f3e28:  04 80 00 24  ble  0xa00f3eb8
a00f3e2c:  92 10 20 3e  mov  0x3e, %o1
a00f3e30:  2b 2a 00 ad  sethi  %hi(0xa802b400), %l5
a00f3e34:  e6 2d 63 ad  stb  %l3, [ %l5 + 0x3ad ]	! 0xa802b7ad
a00f3e38:  90 10 00 18  mov  %i0, %o0
a00f3e3c:  7f ff fe fd  call  0xa00f3a30
a00f3e40:  92 10 00 19  mov  %i1, %o1
a00f3e44:  10 80 00 46  b  0xa00f3f5c
a00f3e48:  82 10 20 00  clr  %g1
a00f3e4c:  92 10 20 36  mov  0x36, %o1
a00f3e50:  7f ff f7 21  call  0xa00f1ad4
a00f3e54:  94 10 20 41  mov  0x41, %o2
a00f3e58:  67 fe 65 cc  call  0x4008d588
a00f3e5c:  a6 10 20 00  clr  %l3
a00f3e60:  a5 2a 20 10  sll  %o0, 0x10, %l2
a00f3e64:  40 00 b5 44  call  0xa0121374
a00f3e68:  90 10 00 18  mov  %i0, %o0
a00f3e6c:  96 0a 20 ff  and  %o0, 0xff, %o3
a00f3e70:  92 10 20 36  mov  0x36, %o1
a00f3e74:  80 a2 e0 01  cmp  %o3, 1
a00f3e78:  02 bf ff cb  be  0xa00f3da4
a00f3e7c:  90 10 00 18  mov  %i0, %o0
a00f3e80:  7f ff f7 04  call  0xa00f1a90
a00f3e84:  01 00 00 00  nop
a00f3e88:  80 8a 20 01  btst  1, %o0
a00f3e8c:  02 bf ff c5  be  0xa00f3da0
a00f3e90:  91 34 a0 10  srl  %l2, 0x10, %o0
a00f3e94:  67 fe 65 c0  call  0x4008d594
a00f3e98:  01 00 00 00  nop
a00f3e9c:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00f3ea0:  99 33 e0 10  srl  %o7, 0x10, %o4
a00f3ea4:  80 a3 20 63  cmp  %o4, 0x63
a00f3ea8:  08 bf ff ef  bleu  0xa00f3e64
a00f3eac:  98 0c e0 ff  and  %l3, 0xff, %o4
a00f3eb0:  10 bf ff bf  b  0xa00f3dac
a00f3eb4:  80 a3 20 00  cmp  %o4, 0
a00f3eb8:  7f ff f7 8b  call  0xa00f1ce4
a00f3ebc:  90 10 00 18  mov  %i0, %o0
a00f3ec0:  a0 0a 2f ff  and  %o0, 0xfff, %l0
a00f3ec4:  90 10 00 18  mov  %i0, %o0
a00f3ec8:  7f ff f7 87  call  0xa00f1ce4
a00f3ecc:  92 10 20 38  mov  0x38, %o1
a00f3ed0:  2d 2a 00 ad  sethi  %hi(0xa802b400), %l6
a00f3ed4:  98 15 a3 9c  or  %l6, 0x39c, %o4	! 0xa802b79c
a00f3ed8:  c2 03 20 04  ld  [ %o4 + 4 ], %g1
a00f3edc:  a4 0a 27 ff  and  %o0, 0x7ff, %l2
a00f3ee0:  80 a0 60 00  cmp  %g1, 0
a00f3ee4:  02 80 00 09  be  0xa00f3f08
a00f3ee8:  a2 10 00 10  mov  %l0, %l1
a00f3eec:  92 10 00 10  mov  %l0, %o1
a00f3ef0:  94 10 00 15  mov  %l5, %o2
a00f3ef4:  9f c0 40 00  call  %g1
a00f3ef8:  90 10 00 18  mov  %i0, %o0
a00f3efc:  80 8a 20 ff  btst  0xff, %o0
a00f3f00:  12 bf ff cd  bne  0xa00f3e34
a00f3f04:  2b 2a 00 ad  sethi  %hi(0xa802b400), %l5
a00f3f08:  92 0c 6f ff  and  %l1, 0xfff, %o1
a00f3f0c:  40 00 13 c0  call  0xa00f8e0c
a00f3f10:  90 10 00 18  mov  %i0, %o0
a00f3f14:  b2 15 a3 9c  or  %l6, 0x39c, %i1
a00f3f18:  c2 06 60 08  ld  [ %i1 + 8 ], %g1
a00f3f1c:  80 a0 60 00  cmp  %g1, 0
a00f3f20:  12 80 00 04  bne  0xa00f3f30
a00f3f24:  a0 0c a7 ff  and  %l2, 0x7ff, %l0
a00f3f28:  10 80 00 0d  b  0xa00f3f5c
a00f3f2c:  82 10 20 01  mov  1, %g1
a00f3f30:  94 0d 27 ff  and  %l4, 0x7ff, %o2
a00f3f34:  90 10 00 18  mov  %i0, %o0
a00f3f38:  9f c0 40 00  call  %g1
a00f3f3c:  92 10 00 10  mov  %l0, %o1
a00f3f40:  80 8a 20 ff  btst  0xff, %o0
a00f3f44:  32 80 00 06  bne,a   0xa00f3f5c
a00f3f48:  82 10 20 01  mov  1, %g1
a00f3f4c:  90 10 00 18  mov  %i0, %o0
a00f3f50:  40 00 13 bd  call  0xa00f8e44
a00f3f54:  92 10 00 10  mov  %l0, %o1
a00f3f58:  82 10 20 01  mov  1, %g1
a00f3f5c:  81 c7 e0 08  ret
a00f3f60:  91 e8 00 01  restore  %g0, %g1, %o0
