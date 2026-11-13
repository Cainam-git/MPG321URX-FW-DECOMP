# leon2m FUN_a00b7d14 0xa00b7d14-0xa00b7e68 (340 bytes)
a00b7d14:  9d e3 bf 90  save  %sp, -112, %sp
a00b7d18:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00b7d1c:  90 14 62 90  or  %l1, 0x290, %o0	! 0xa802d290
a00b7d20:  da 0a 21 df  ldub  [ %o0 + 0x1df ], %o5
a00b7d24:  83 2b 60 04  sll  %o5, 4, %g1
a00b7d28:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b7d2c:  96 10 20 06  mov  6, %o3
a00b7d30:  90 10 20 2c  mov  0x2c, %o0
a00b7d34:  92 10 20 06  mov  6, %o1
a00b7d38:  a0 10 27 42  mov  0x742, %l0
a00b7d3c:  80 a3 60 05  cmp  %o5, 5
a00b7d40:  82 00 40 0d  add  %g1, %o5, %g1
a00b7d44:  08 80 00 03  bleu  0xa00b7d50
a00b7d48:  98 10 00 18  mov  %i0, %o4
a00b7d4c:  82 10 20 64  mov  0x64, %g1
a00b7d50:  7f ff ce 28  call  0xa00ab5f0
a00b7d54:  94 08 60 ff  and  %g1, 0xff, %o2
a00b7d58:  90 10 20 01  mov  1, %o0
a00b7d5c:  80 a6 20 00  cmp  %i0, 0
a00b7d60:  12 80 00 05  bne  0xa00b7d74
a00b7d64:  92 10 20 03  mov  3, %o1
a00b7d68:  a0 10 27 92  mov  0x792, %l0
a00b7d6c:  90 10 20 01  mov  1, %o0
a00b7d70:  92 10 20 02  mov  2, %o1
a00b7d74:  7f ff c5 bd  call  0xa00a9468
a00b7d78:  b0 0c 27 d2  and  %l0, 0x7d2, %i0
a00b7d7c:  90 10 20 28  mov  0x28, %o0
a00b7d80:  92 10 20 06  mov  6, %o1
a00b7d84:  94 10 20 03  mov  3, %o2
a00b7d88:  96 10 00 18  mov  %i0, %o3
a00b7d8c:  40 02 3b 3d  call  0xa0146a80
a00b7d90:  98 10 20 00  clr  %o4
a00b7d94:  90 10 20 2b  mov  0x2b, %o0
a00b7d98:  92 10 20 06  mov  6, %o1
a00b7d9c:  94 10 20 01  mov  1, %o2
a00b7da0:  96 10 00 18  mov  %i0, %o3
a00b7da4:  40 02 3b 37  call  0xa0146a80
a00b7da8:  98 10 20 00  clr  %o4
a00b7dac:  9a 10 20 00  clr  %o5
a00b7db0:  90 10 20 00  clr  %o0
a00b7db4:  92 10 20 2b  mov  0x2b, %o1
a00b7db8:  94 10 20 06  mov  6, %o2
a00b7dbc:  96 10 20 01  mov  1, %o3
a00b7dc0:  40 02 3b 58  call  0xa0146b20
a00b7dc4:  98 10 20 3f  mov  0x3f, %o4
a00b7dc8:  96 10 00 18  mov  %i0, %o3
a00b7dcc:  90 10 20 32  mov  0x32, %o0
a00b7dd0:  92 10 20 06  mov  6, %o1
a00b7dd4:  94 10 20 01  mov  1, %o2
a00b7dd8:  40 02 3b 2a  call  0xa0146a80
a00b7ddc:  98 10 20 00  clr  %o4
a00b7de0:  9a 10 20 00  clr  %o5
a00b7de4:  96 10 20 01  mov  1, %o3
a00b7de8:  98 10 20 40  mov  0x40, %o4
a00b7dec:  94 10 20 06  mov  6, %o2
a00b7df0:  90 10 20 00  clr  %o0
a00b7df4:  40 02 3b 4b  call  0xa0146b20
a00b7df8:  92 10 20 32  mov  0x32, %o1
a00b7dfc:  90 10 20 e6  mov  0xe6, %o0
a00b7e00:  40 02 3b 54  call  0xa0146b50
a00b7e04:  92 10 20 00  clr  %o1
a00b7e08:  9e 14 62 90  or  %l1, 0x290, %o7
a00b7e0c:  d8 0b e1 df  ldub  [ %o7 + 0x1df ], %o4
a00b7e10:  94 03 20 01  add  %o4, 1, %o2
a00b7e14:  17 00 06 60  sethi  %hi(0x198000), %o3
a00b7e18:  a0 07 bf f0  add  %fp, -16, %l0
a00b7e1c:  92 12 e1 d0  or  %o3, 0x1d0, %o1
a00b7e20:  94 0a a0 ff  and  %o2, 0xff, %o2
a00b7e24:  40 02 7e 74  call  0xa01577f4
a00b7e28:  90 10 00 10  mov  %l0, %o0
a00b7e2c:  92 10 20 03  mov  3, %o1
a00b7e30:  d2 2f bf f0  stb  %o1, [ %fp + -16 ]
a00b7e34:  90 10 20 02  mov  2, %o0
a00b7e38:  40 02 3b 4d  call  0xa0146b6c
a00b7e3c:  92 10 20 00  clr  %o1
a00b7e40:  98 10 00 10  mov  %l0, %o4
a00b7e44:  90 10 20 00  clr  %o0
a00b7e48:  92 10 20 28  mov  0x28, %o1
a00b7e4c:  94 10 20 06  mov  6, %o2
a00b7e50:  96 10 20 02  mov  2, %o3
a00b7e54:  7f ff ac d4  call  0xa00a31a4
a00b7e58:  9a 10 20 00  clr  %o5
a00b7e5c:  01 00 00 00  nop
a00b7e60:  81 c7 e0 08  ret
a00b7e64:  81 e8 00 00  restore
