# leon2m FUN_a0098e6c 0xa0098e6c-0xa0098f28 (188 bytes)
a0098e6c:  9d e3 bf 98  save  %sp, -104, %sp
a0098e70:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a0098e74:  d6 06 a3 ec  ld  [ %i2 + 0x3ec ], %o3	! 0xa802afec
a0098e78:  94 02 ff d6  add  %o3, -42, %o2
a0098e7c:  90 0a a0 ff  and  %o2, 0xff, %o0
a0098e80:  40 00 40 63  call  0xa00a900c
a0098e84:  92 10 20 02  mov  2, %o1
a0098e88:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a0098e8c:  da 02 63 38  ld  [ %o1 + 0x338 ], %o5	! 0xa802d338
a0098e90:  91 33 60 05  srl  %o5, 5, %o0
a0098e94:  99 33 60 06  srl  %o5, 6, %o4
a0098e98:  82 0a 20 01  and  %o0, 1, %g1
a0098e9c:  80 8b 60 40  btst  0x40, %o5
a0098ea0:  98 0b 20 01  and  %o4, 1, %o4
a0098ea4:  96 00 60 01  add  %g1, 1, %o3
a0098ea8:  12 80 00 11  bne  0xa0098eec
a0098eac:  9a 00 60 b2  add  %g1, 0xb2, %o5
a0098eb0:  9a 10 20 b1  mov  0xb1, %o5
a0098eb4:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a0098eb8:  d0 06 a3 ec  ld  [ %i2 + 0x3ec ], %o0
a0098ebc:  1f 2a 00 97  sethi  %hi(0xa8025c00), %o7
a0098ec0:  9a 02 20 4f  add  %o0, 0x4f, %o5
a0098ec4:  d8 2b e0 56  stb  %o4, [ %o7 + 0x56 ]
a0098ec8:  90 0b 60 ff  and  %o5, 0xff, %o0
a0098ecc:  40 00 41 e1  call  0xa00a9650
a0098ed0:  92 10 20 01  mov  1, %o1
a0098ed4:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1
a0098ed8:  b2 00 60 4f  add  %g1, 0x4f, %i1
a0098edc:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0098ee0:  b0 10 20 01  mov  1, %i0
a0098ee4:  40 00 3c 96  call  0xa00a813c
a0098ee8:  95 e8 20 00  restore  %g0, 0, %o2
a0098eec:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a0098ef0:  d0 06 a3 ec  ld  [ %i2 + 0x3ec ], %o0
a0098ef4:  31 2a 00 97  sethi  %hi(0xa8025c00), %i0
a0098ef8:  9a 02 20 4f  add  %o0, 0x4f, %o5
a0098efc:  d6 2e 20 56  stb  %o3, [ %i0 + 0x56 ]
a0098f00:  90 0b 60 ff  and  %o5, 0xff, %o0
a0098f04:  40 00 41 d3  call  0xa00a9650
a0098f08:  92 10 20 01  mov  1, %o1
a0098f0c:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1
a0098f10:  b2 00 60 4f  add  %g1, 0x4f, %i1
a0098f14:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0098f18:  b0 10 20 01  mov  1, %i0
a0098f1c:  40 00 3c 88  call  0xa00a813c
a0098f20:  95 e8 20 00  restore  %g0, 0, %o2
a0098f24:  01 00 00 00  nop
