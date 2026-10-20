# leon2m FUN_a00e2d8c 0xa00e2d8c-0xa00e312c (928 bytes)
a00e2d8c:  9d e3 bf 80  save  %sp, -128, %sp
a00e2d90:  f6 27 a0 50  st  %i3, [ %fp + 0x50 ]
a00e2d94:  80 a6 e0 00  cmp  %i3, 0
a00e2d98:  c0 27 bf f4  clr  [ %fp + -12 ]
a00e2d9c:  c0 27 bf f0  clr  [ %fp + -16 ]
a00e2da0:  c0 27 bf ec  clr  [ %fp + -20 ]
a00e2da4:  b6 10 20 00  clr  %i3
a00e2da8:  b8 10 20 00  clr  %i4
a00e2dac:  a8 10 20 00  clr  %l4
a00e2db0:  a6 10 20 01  mov  1, %l3
a00e2db4:  12 80 00 04  bne  0xa00e2dc4
a00e2db8:  a4 10 20 3f  mov  0x3f, %l2
a00e2dbc:  a6 10 20 00  clr  %l3
a00e2dc0:  a4 10 20 00  clr  %l2
a00e2dc4:  c0 27 bf e8  clr  [ %fp + -24 ]
a00e2dc8:  c0 27 bf e4  clr  [ %fp + -28 ]
a00e2dcc:  3b 2a 00 b5  sethi  %hi(0xa802d400), %i5
a00e2dd0:  2f 2a 00 b5  sethi  %hi(0xa802d400), %l7
a00e2dd4:  2d 2a 00 b5  sethi  %hi(0xa802d400), %l6
a00e2dd8:  2b 2a 00 b5  sethi  %hi(0xa802d400), %l5
a00e2ddc:  90 10 00 18  mov  %i0, %o0
a00e2de0:  92 10 00 19  mov  %i1, %o1
a00e2de4:  e0 07 62 60  ld  [ %i5 + 0x260 ], %l0
a00e2de8:  9f c4 00 00  call  %l0
a00e2dec:  94 10 00 1a  mov  %i2, %o2
a00e2df0:  90 10 00 18  mov  %i0, %o0
a00e2df4:  92 10 00 19  mov  %i1, %o1
a00e2df8:  94 10 00 1a  mov  %i2, %o2
a00e2dfc:  96 10 00 14  mov  %l4, %o3
a00e2e00:  98 10 00 12  mov  %l2, %o4
a00e2e04:  e2 05 e2 68  ld  [ %l7 + 0x268 ], %l1
a00e2e08:  9f c4 40 00  call  %l1
a00e2e0c:  9a 10 00 13  mov  %l3, %o5
a00e2e10:  c2 05 e2 68  ld  [ %l7 + 0x268 ], %g1
a00e2e14:  92 10 00 19  mov  %i1, %o1
a00e2e18:  94 10 00 1a  mov  %i2, %o2
a00e2e1c:  96 10 00 14  mov  %l4, %o3
a00e2e20:  98 10 00 12  mov  %l2, %o4
a00e2e24:  9a 10 00 13  mov  %l3, %o5
a00e2e28:  9f c0 40 00  call  %g1
a00e2e2c:  90 10 00 18  mov  %i0, %o0
a00e2e30:  da 05 a2 5c  ld  [ %l6 + 0x25c ], %o5
a00e2e34:  9f c3 40 00  call  %o5
a00e2e38:  90 10 00 18  mov  %i0, %o0
a00e2e3c:  a0 10 00 08  mov  %o0, %l0
a00e2e40:  d8 05 62 64  ld  [ %l5 + 0x264 ], %o4
a00e2e44:  9f c3 00 00  call  %o4
a00e2e48:  90 10 00 18  mov  %i0, %o0
a00e2e4c:  a2 10 00 08  mov  %o0, %l1
a00e2e50:  d6 05 a2 5c  ld  [ %l6 + 0x25c ], %o3
a00e2e54:  9f c2 c0 00  call  %o3
a00e2e58:  90 10 00 18  mov  %i0, %o0
a00e2e5c:  a0 04 00 08  add  %l0, %o0, %l0
a00e2e60:  d4 05 62 64  ld  [ %l5 + 0x264 ], %o2
a00e2e64:  9f c2 80 00  call  %o2
a00e2e68:  90 10 00 18  mov  %i0, %o0
a00e2e6c:  a2 04 40 08  add  %l1, %o0, %l1
a00e2e70:  d2 05 a2 5c  ld  [ %l6 + 0x25c ], %o1
a00e2e74:  9f c2 40 00  call  %o1
a00e2e78:  90 10 00 18  mov  %i0, %o0
a00e2e7c:  a0 04 00 08  add  %l0, %o0, %l0
a00e2e80:  c2 05 62 64  ld  [ %l5 + 0x264 ], %g1
a00e2e84:  9f c0 40 00  call  %g1
a00e2e88:  90 10 00 18  mov  %i0, %o0
a00e2e8c:  9a 15 00 13  or  %l4, %l3, %o5
a00e2e90:  80 93 40 12  orcc  %o5, %l2, %g0
a00e2e94:  12 80 00 06  bne  0xa00e2eac
a00e2e98:  a2 04 40 08  add  %l1, %o0, %l1
a00e2e9c:  80 a4 40 10  cmp  %l1, %l0
a00e2ea0:  18 80 00 03  bgu  0xa00e2eac
a00e2ea4:  b8 24 40 10  sub  %l1, %l0, %i4
a00e2ea8:  b8 24 00 11  sub  %l0, %l1, %i4
a00e2eac:  d0 07 a0 50  ld  [ %fp + 0x50 ], %o0
a00e2eb0:  80 a2 20 00  cmp  %o0, 0
a00e2eb4:  02 80 00 0c  be  0xa00e2ee4
a00e2eb8:  13 2a 00 ad  sethi  %hi(0xa802b400), %o1
a00e2ebc:  80 a5 20 00  cmp  %l4, 0
a00e2ec0:  12 80 00 2f  bne  0xa00e2f7c
a00e2ec4:  80 a4 a0 3f  cmp  %l2, 0x3f
a00e2ec8:  80 a4 e0 00  cmp  %l3, 0
a00e2ecc:  12 80 00 50  bne  0xa00e300c
a00e2ed0:  80 a4 a0 00  cmp  %l2, 0
a00e2ed4:  a8 10 20 01  mov  1, %l4
a00e2ed8:  a6 10 20 01  mov  1, %l3
a00e2edc:  10 bf ff c0  b  0xa00e2ddc
a00e2ee0:  a4 10 20 00  clr  %l2
a00e2ee4:  da 02 63 28  ld  [ %o1 + 0x328 ], %o5
a00e2ee8:  80 a0 00 0d  cmp  %g0, %o5
a00e2eec:  98 60 3f ff  subx  %g0, -1, %o4
a00e2ef0:  80 a4 00 11  cmp  %l0, %l1
a00e2ef4:  9e 40 20 00  addx  %g0, 0, %o7
a00e2ef8:  80 8b 00 0f  btst  %o4, %o7
a00e2efc:  32 80 00 0b  bne,a   0xa00e2f28
a00e2f00:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a00e2f04:  96 1b 60 01  xor  %o5, 1, %o3
a00e2f08:  80 a0 00 0b  cmp  %g0, %o3
a00e2f0c:  9a 60 3f ff  subx  %g0, -1, %o5
a00e2f10:  80 a4 40 10  cmp  %l1, %l0
a00e2f14:  94 40 20 00  addx  %g0, 0, %o2
a00e2f18:  80 8b 40 0a  btst  %o5, %o2
a00e2f1c:  02 80 00 1d  be  0xa00e2f90
a00e2f20:  80 a4 40 10  cmp  %l1, %l0
a00e2f24:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a00e2f28:  98 10 20 01  mov  1, %o4
a00e2f2c:  80 a3 60 00  cmp  %o5, 0
a00e2f30:  12 80 00 41  bne  0xa00e3034
a00e2f34:  d8 27 bf e8  st  %o4, [ %fp + -24 ]
a00e2f38:  80 a4 40 10  cmp  %l1, %l0
a00e2f3c:  e8 27 bf f4  st  %l4, [ %fp + -12 ]
a00e2f40:  e6 27 bf f0  st  %l3, [ %fp + -16 ]
a00e2f44:  e4 27 bf ec  st  %l2, [ %fp + -20 ]
a00e2f48:  18 80 00 03  bgu  0xa00e2f54
a00e2f4c:  b6 24 40 10  sub  %l1, %l0, %i3
a00e2f50:  b6 24 00 11  sub  %l0, %l1, %i3
a00e2f54:  80 a5 20 01  cmp  %l4, 1
a00e2f58:  02 80 00 34  be  0xa00e3028
a00e2f5c:  80 a4 a0 13  cmp  %l2, 0x13
a00e2f60:  18 80 00 50  bgu  0xa00e30a0
a00e2f64:  80 a4 e0 00  cmp  %l3, 0
a00e2f68:  22 bf ff 9d  be,a   0xa00e2ddc
a00e2f6c:  a6 10 20 01  mov  1, %l3
a00e2f70:  a4 04 a0 01  inc  %l2
a00e2f74:  10 bf ff 9a  b  0xa00e2ddc
a00e2f78:  a6 10 20 01  mov  1, %l3
a00e2f7c:  02 80 00 6a  be  0xa00e3124
a00e2f80:  a4 04 a0 01  inc  %l2
a00e2f84:  a8 10 20 01  mov  1, %l4
a00e2f88:  10 bf ff 95  b  0xa00e2ddc
a00e2f8c:  a6 10 20 01  mov  1, %l3
a00e2f90:  82 40 20 00  addx  %g0, 0, %g1
a00e2f94:  80 8b 00 01  btst  %o4, %g1
a00e2f98:  12 80 00 07  bne  0xa00e2fb4
a00e2f9c:  d2 07 bf e8  ld  [ %fp + -24 ], %o1
a00e2fa0:  80 a4 00 11  cmp  %l0, %l1
a00e2fa4:  90 40 20 00  addx  %g0, 0, %o0
a00e2fa8:  80 8b 40 08  btst  %o5, %o0
a00e2fac:  02 80 00 5e  be  0xa00e3124
a00e2fb0:  01 00 00 00  nop
a00e2fb4:  9e 10 20 01  mov  1, %o7	! 0x1
a00e2fb8:  80 a2 60 00  cmp  %o1, 0
a00e2fbc:  12 80 00 53  bne  0xa00e3108
a00e2fc0:  de 27 bf e4  st  %o7, [ %fp + -28 ]
a00e2fc4:  e6 27 bf f0  st  %l3, [ %fp + -16 ]
a00e2fc8:  80 a4 40 10  cmp  %l1, %l0
a00e2fcc:  e8 27 bf f4  st  %l4, [ %fp + -12 ]
a00e2fd0:  e4 27 bf ec  st  %l2, [ %fp + -20 ]
a00e2fd4:  18 80 00 03  bgu  0xa00e2fe0
a00e2fd8:  b6 24 40 10  sub  %l1, %l0, %i3
a00e2fdc:  b6 24 00 11  sub  %l0, %l1, %i3
a00e2fe0:  80 a5 20 01  cmp  %l4, 1
a00e2fe4:  32 bf ff e9  bne,a   0xa00e2f88
a00e2fe8:  a8 10 20 01  mov  1, %l4
a00e2fec:  80 a4 a0 13  cmp  %l2, 0x13
a00e2ff0:  28 bf ff e1  bleu,a   0xa00e2f74
a00e2ff4:  a4 04 a0 01  inc  %l2
a00e2ff8:  80 a6 c0 1c  cmp  %i3, %i4
a00e2ffc:  08 80 00 4a  bleu  0xa00e3124
a00e3000:  90 10 00 18  mov  %i0, %o0
a00e3004:  10 80 00 2b  b  0xa00e30b0
a00e3008:  92 10 00 19  mov  %i1, %o1
a00e300c:  32 80 00 05  bne,a   0xa00e3020
a00e3010:  a4 04 bf ff  add  %l2, -1, %l2
a00e3014:  a6 10 20 00  clr  %l3
a00e3018:  10 bf ff 71  b  0xa00e2ddc
a00e301c:  a4 10 00 13  mov  %l3, %l2
a00e3020:  10 bf ff 6f  b  0xa00e2ddc
a00e3024:  a6 10 20 01  mov  1, %l3
a00e3028:  a8 10 20 00  clr  %l4
a00e302c:  10 bf ff 6c  b  0xa00e2ddc
a00e3030:  a6 10 20 01  mov  1, %l3
a00e3034:  80 a4 40 10  cmp  %l1, %l0
a00e3038:  08 80 00 32  bleu  0xa00e3100
a00e303c:  82 24 40 10  sub  %l1, %l0, %g1
a00e3040:  80 a0 40 1b  cmp  %g1, %i3
a00e3044:  08 80 00 38  bleu  0xa00e3124
a00e3048:  90 10 00 18  mov  %i0, %o0
a00e304c:  92 10 00 19  mov  %i1, %o1
a00e3050:  e6 07 62 60  ld  [ %i5 + 0x260 ], %l3
a00e3054:  9f c4 c0 00  call  %l3
a00e3058:  94 10 00 1a  mov  %i2, %o2
a00e305c:  90 10 00 18  mov  %i0, %o0
a00e3060:  92 10 00 19  mov  %i1, %o1
a00e3064:  94 10 00 1a  mov  %i2, %o2
a00e3068:  d6 07 bf f4  ld  [ %fp + -12 ], %o3
a00e306c:  d8 07 bf ec  ld  [ %fp + -20 ], %o4
a00e3070:  e4 05 e2 68  ld  [ %l7 + 0x268 ], %l2
a00e3074:  9f c4 80 00  call  %l2
a00e3078:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a00e307c:  e0 05 e2 68  ld  [ %l7 + 0x268 ], %l0
a00e3080:  90 10 00 18  mov  %i0, %o0
a00e3084:  92 10 00 19  mov  %i1, %o1
a00e3088:  94 10 00 1a  mov  %i2, %o2
a00e308c:  d6 07 bf f4  ld  [ %fp + -12 ], %o3
a00e3090:  d8 07 bf ec  ld  [ %fp + -20 ], %o4
a00e3094:  9f c4 00 00  call  %l0
a00e3098:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a00e309c:  30 80 00 22  b,a   0xa00e3124
a00e30a0:  80 a6 c0 1c  cmp  %i3, %i4
a00e30a4:  08 80 00 20  bleu  0xa00e3124
a00e30a8:  90 10 00 18  mov  %i0, %o0
a00e30ac:  92 10 00 19  mov  %i1, %o1
a00e30b0:  ea 07 62 60  ld  [ %i5 + 0x260 ], %l5
a00e30b4:  9f c5 40 00  call  %l5
a00e30b8:  94 10 00 1a  mov  %i2, %o2
a00e30bc:  90 10 00 18  mov  %i0, %o0
a00e30c0:  92 10 00 19  mov  %i1, %o1
a00e30c4:  94 10 00 1a  mov  %i2, %o2
a00e30c8:  e8 05 e2 68  ld  [ %l7 + 0x268 ], %l4
a00e30cc:  96 10 20 00  clr  %o3
a00e30d0:  98 10 20 00  clr  %o4
a00e30d4:  9f c5 00 00  call  %l4
a00e30d8:  9a 10 20 00  clr  %o5
a00e30dc:  e0 05 e2 68  ld  [ %l7 + 0x268 ], %l0
a00e30e0:  90 10 00 18  mov  %i0, %o0
a00e30e4:  92 10 00 19  mov  %i1, %o1
a00e30e8:  94 10 00 1a  mov  %i2, %o2
a00e30ec:  96 10 20 00  clr  %o3
a00e30f0:  98 10 20 00  clr  %o4
a00e30f4:  9f c4 00 00  call  %l0
a00e30f8:  9a 10 20 00  clr  %o5
a00e30fc:  30 80 00 0a  b,a   0xa00e3124
a00e3100:  10 bf ff d0  b  0xa00e3040
a00e3104:  82 24 00 11  sub  %l0, %l1, %g1
a00e3108:  80 a4 40 10  cmp  %l1, %l0
a00e310c:  18 80 00 03  bgu  0xa00e3118
a00e3110:  82 24 40 10  sub  %l1, %l0, %g1
a00e3114:  82 24 00 11  sub  %l0, %l1, %g1
a00e3118:  80 a0 40 1b  cmp  %g1, %i3
a00e311c:  18 bf ff cc  bgu  0xa00e304c
a00e3120:  90 10 00 18  mov  %i0, %o0
a00e3124:  81 c7 e0 08  ret
a00e3128:  81 e8 00 00  restore
