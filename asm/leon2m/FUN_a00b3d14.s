# leon2m FUN_a00b3d14 0xa00b3d14-0xa00b3ed0 (444 bytes)
a00b3d14:  9d e3 bf 98  save  %sp, -104, %sp
a00b3d18:  90 10 20 46  mov  0x46, %o0
a00b3d1c:  40 02 4b 8d  call  0xa0146b50
a00b3d20:  92 10 20 00  clr  %o1
a00b3d24:  90 10 20 00  clr  %o0
a00b3d28:  40 02 4b 91  call  0xa0146b6c
a00b3d2c:  92 10 20 00  clr  %o1
a00b3d30:  40 00 90 06  call  0xa00d7d48
a00b3d34:  01 00 00 00  nop
a00b3d38:  80 a2 20 00  cmp  %o0, 0
a00b3d3c:  12 80 00 2a  bne  0xa00b3de4
a00b3d40:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00b3d44:  da 00 60 84  ld  [ %g1 + 0x84 ], %o5	! 0xa802d484
a00b3d48:  80 a3 60 00  cmp  %o5, 0
a00b3d4c:  26 80 00 27  bl,a   0xa00b3de8
a00b3d50:  90 10 20 06  mov  6, %o0
a00b3d54:  80 8e 20 ff  btst  0xff, %i0
a00b3d58:  32 80 00 2d  bne,a   0xa00b3e0c
a00b3d5c:  a0 10 20 07  mov  7, %l0
a00b3d60:  a0 10 20 00  clr  %l0
a00b3d64:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00b3d68:  b0 10 20 00  clr  %i0
a00b3d6c:  23 00 06 5b  sethi  %hi(0x196c00), %l1
a00b3d70:  95 2e 20 03  sll  %i0, 3, %o2
a00b3d74:  82 22 80 18  sub  %o2, %i0, %g1
a00b3d78:  9b 28 60 02  sll  %g1, 2, %o5
a00b3d7c:  9e 14 a2 90  or  %l2, 0x290, %o7
a00b3d80:  96 03 40 18  add  %o5, %i0, %o3
a00b3d84:  d8 0b e0 08  ldub  [ %o7 + 8 ], %o4
a00b3d88:  90 02 c0 0c  add  %o3, %o4, %o0
a00b3d8c:  93 2a 20 10  sll  %o0, 0x10, %o1
a00b3d90:  93 32 60 10  srl  %o1, 0x10, %o1
a00b3d94:  7f ff be ac  call  0xa00a3844
a00b3d98:  90 14 61 c0  or  %l1, 0x1c0, %o0
a00b3d9c:  98 10 00 08  mov  %o0, %o4
a00b3da0:  94 06 00 18  add  %i0, %i0, %o2
a00b3da4:  94 02 a0 06  add  %o2, 6, %o2
a00b3da8:  90 10 20 00  clr  %o0
a00b3dac:  92 10 20 06  mov  6, %o1
a00b3db0:  96 10 20 01  mov  1, %o3
a00b3db4:  9a 10 20 00  clr  %o5
a00b3db8:  7f ff bc fb  call  0xa00a31a4
a00b3dbc:  a0 04 20 01  inc  %l0
a00b3dc0:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00b3dc4:  80 a6 20 07  cmp  %i0, 7
a00b3dc8:  0a bf ff eb  bcs  0xa00b3d74
a00b3dcc:  95 2e 20 03  sll  %i0, 3, %o2
a00b3dd0:  90 10 27 92  mov  0x792, %o0
a00b3dd4:  40 02 4b 37  call  0xa0146ab0
a00b3dd8:  92 10 20 00  clr  %o1
a00b3ddc:  10 80 00 2b  b  0xa00b3e88
a00b3de0:  b0 10 20 00  clr  %i0
a00b3de4:  90 10 20 06  mov  6, %o0
a00b3de8:  92 10 20 10  mov  0x10, %o1
a00b3dec:  94 10 20 0a  mov  0xa, %o2
a00b3df0:  96 10 26 92  mov  0x692, %o3
a00b3df4:  40 02 4b 23  call  0xa0146a80
a00b3df8:  98 10 20 00  clr  %o4
a00b3dfc:  80 8e 20 ff  btst  0xff, %i0
a00b3e00:  22 bf ff d9  be,a   0xa00b3d64
a00b3e04:  a0 10 20 00  clr  %l0
a00b3e08:  a0 10 20 07  mov  7, %l0
a00b3e0c:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00b3e10:  b0 10 20 07  mov  7, %i0
a00b3e14:  23 00 06 5b  sethi  %hi(0x196c00), %l1
a00b3e18:  91 2e 20 03  sll  %i0, 3, %o0
a00b3e1c:  92 22 00 18  sub  %o0, %i0, %o1
a00b3e20:  95 2a 60 02  sll  %o1, 2, %o2
a00b3e24:  9a 14 a2 90  or  %l2, 0x290, %o5
a00b3e28:  9e 02 80 18  add  %o2, %i0, %o7
a00b3e2c:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a00b3e30:  98 03 c0 01  add  %o7, %g1, %o4
a00b3e34:  97 2b 20 10  sll  %o4, 0x10, %o3
a00b3e38:  93 32 e0 10  srl  %o3, 0x10, %o1
a00b3e3c:  7f ff be 82  call  0xa00a3844
a00b3e40:  90 14 61 c0  or  %l1, 0x1c0, %o0
a00b3e44:  98 10 00 08  mov  %o0, %o4
a00b3e48:  90 06 00 18  add  %i0, %i0, %o0
a00b3e4c:  92 02 3f f8  add  %o0, -8, %o1
a00b3e50:  b1 2a 60 10  sll  %o1, 0x10, %i0
a00b3e54:  95 36 20 10  srl  %i0, 0x10, %o2
a00b3e58:  90 10 20 00  clr  %o0
a00b3e5c:  92 10 20 06  mov  6, %o1
a00b3e60:  96 10 20 01  mov  1, %o3
a00b3e64:  9a 10 20 00  clr  %o5
a00b3e68:  7f ff bc cf  call  0xa00a31a4
a00b3e6c:  a0 04 20 01  inc  %l0
a00b3e70:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00b3e74:  80 a6 20 08  cmp  %i0, 8
a00b3e78:  28 bf ff e9  bleu,a   0xa00b3e1c
a00b3e7c:  91 2e 20 03  sll  %i0, 3, %o0
a00b3e80:  10 bf ff d5  b  0xa00b3dd4
a00b3e84:  90 10 27 92  mov  0x792, %o0
a00b3e88:  98 0e 20 ff  and  %i0, 0xff, %o4
a00b3e8c:  96 03 20 09  add  %o4, 9, %o3
a00b3e90:  a5 2a e0 10  sll  %o3, 0x10, %l2
a00b3e94:  a2 06 20 28  add  %i0, 0x28, %l1
a00b3e98:  93 34 a0 10  srl  %l2, 0x10, %o1
a00b3e9c:  98 0c 60 ff  and  %l1, 0xff, %o4
a00b3ea0:  90 10 20 01  mov  1, %o0
a00b3ea4:  94 10 20 15  mov  0x15, %o2
a00b3ea8:  96 10 20 01  mov  1, %o3
a00b3eac:  9a 10 20 00  clr  %o5
a00b3eb0:  40 02 4b 1c  call  0xa0146b20
a00b3eb4:  b0 06 20 01  inc  %i0
a00b3eb8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00b3ebc:  80 a4 20 02  cmp  %l0, 2
a00b3ec0:  0a bf ff f3  bcs  0xa00b3e8c
a00b3ec4:  98 0e 20 ff  and  %i0, 0xff, %o4
a00b3ec8:  81 c7 e0 08  ret
a00b3ecc:  81 e8 00 00  restore
