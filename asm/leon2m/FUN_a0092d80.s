# leon2m FUN_a0092d80 0xa0092d80-0xa0092ea8 (296 bytes)
a0092d80:  9d e3 bf 98  save  %sp, -104, %sp
a0092d84:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0092d88:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0	! 0xa802afec
a0092d8c:  82 02 3f d6  add  %o0, -42, %g1
a0092d90:  40 00 58 56  call  0xa00a8ee8
a0092d94:  90 08 60 ff  and  %g1, 0xff, %o0
a0092d98:  da 06 63 ec  ld  [ %i1 + 0x3ec ], %o5
a0092d9c:  b0 03 7f d6  add  %o5, -42, %i0
a0092da0:  90 0e 20 ff  and  %i0, 0xff, %o0
a0092da4:  40 00 5d 66  call  0xa00aa33c
a0092da8:  92 10 20 00  clr  %o1
a0092dac:  e0 06 63 ec  ld  [ %i1 + 0x3ec ], %l0
a0092db0:  1f 09 24 92  sethi  %hi(0x24924800), %o7
a0092db4:  96 04 3f d6  add  %l0, -42, %o3
a0092db8:  98 13 e1 25  or  %o7, 0x125, %o4
a0092dbc:  80 52 c0 0c  umul  %o3, %o4, %g0
a0092dc0:  91 40 00 00  rd  %y, %o0
a0092dc4:  94 22 c0 08  sub  %o3, %o0, %o2
a0092dc8:  93 32 a0 01  srl  %o2, 1, %o1
a0092dcc:  82 02 00 09  add  %o0, %o1, %g1
a0092dd0:  1b 19 99 99  sethi  %hi(0x66666400), %o5
a0092dd4:  a1 30 60 02  srl  %g1, 2, %l0
a0092dd8:  b0 13 62 67  or  %o5, 0x267, %i0
a0092ddc:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a0092de0:  9e 02 3f d7  add  %o0, -41, %o7
a0092de4:  80 5b c0 18  smul  %o7, %i0, %g0
a0092de8:  99 40 00 00  rd  %y, %o4
a0092dec:  95 3b 20 02  sra  %o4, 2, %o2
a0092df0:  97 3b e0 1f  sra  %o7, 0x1f, %o3
a0092df4:  9a 22 80 0b  sub  %o2, %o3, %o5
a0092df8:  93 2b 60 02  sll  %o5, 2, %o1
a0092dfc:  82 02 40 0d  add  %o1, %o5, %g1
a0092e00:  98 00 40 01  add  %g1, %g1, %o4
a0092e04:  94 23 c0 0c  sub  %o7, %o4, %o2
a0092e08:  96 02 a0 2a  add  %o2, 0x2a, %o3
a0092e0c:  d6 26 63 ec  st  %o3, [ %i1 + 0x3ec ]
a0092e10:  40 00 5d c4  call  0xa00aa520
a0092e14:  90 0a a0 ff  and  %o2, 0xff, %o0
a0092e18:  92 0a 20 ff  and  %o0, 0xff, %o1
a0092e1c:  80 a2 60 01  cmp  %o1, 1
a0092e20:  12 bf ff f0  bne  0xa0092de0
a0092e24:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a0092e28:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a0092e2c:  17 09 24 92  sethi  %hi(0x24924800), %o3
a0092e30:  94 03 3f d6  add  %o4, -42, %o2
a0092e34:  9a 12 e1 25  or  %o3, 0x125, %o5
a0092e38:  80 52 80 0d  umul  %o2, %o5, %g0
a0092e3c:  9f 40 00 00  rd  %y, %o7
a0092e40:  92 22 80 0f  sub  %o2, %o7, %o1
a0092e44:  83 32 60 01  srl  %o1, 1, %g1
a0092e48:  b0 03 c0 01  add  %o7, %g1, %i0
a0092e4c:  b2 0c 20 ff  and  %l0, 0xff, %i1
a0092e50:  91 36 20 02  srl  %i0, 2, %o0
a0092e54:  80 a2 00 19  cmp  %o0, %i1
a0092e58:  02 80 00 04  be  0xa0092e68
a0092e5c:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0092e60:  40 00 68 d8  call  0xa00ad1c0
a0092e64:  90 0a 20 ff  and  %o0, 0xff, %o0
a0092e68:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a0092e6c:  82 02 7f d6  add  %o1, -42, %g1
a0092e70:  90 08 60 ff  and  %g1, 0xff, %o0
a0092e74:  40 00 58 66  call  0xa00a900c
a0092e78:  92 10 20 01  mov  1, %o1
a0092e7c:  de 06 63 ec  ld  [ %i1 + 0x3ec ], %o7
a0092e80:  b0 03 ff d6  add  %o7, -42, %i0
a0092e84:  90 0e 20 ff  and  %i0, 0xff, %o0
a0092e88:  40 00 5d 2d  call  0xa00aa33c
a0092e8c:  92 10 20 01  mov  1, %o1
a0092e90:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0
a0092e94:  a0 02 3f d6  add  %o0, -42, %l0
a0092e98:  b2 0c 20 ff  and  %l0, 0xff, %i1
a0092e9c:  40 00 71 6c  call  0xa00af44c
a0092ea0:  91 e8 20 2a  restore  %g0, 0x2a, %o0
a0092ea4:  01 00 00 00  nop
