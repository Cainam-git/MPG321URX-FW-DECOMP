# leon2m FUN_a0092c58 0xa0092c58-0xa0092d80 (296 bytes)
a0092c58:  9d e3 bf 98  save  %sp, -104, %sp
a0092c5c:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0092c60:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0	! 0xa802afec
a0092c64:  82 02 3f d6  add  %o0, -42, %g1
a0092c68:  40 00 58 a0  call  0xa00a8ee8
a0092c6c:  90 08 60 ff  and  %g1, 0xff, %o0
a0092c70:  da 06 63 ec  ld  [ %i1 + 0x3ec ], %o5
a0092c74:  b0 03 7f d6  add  %o5, -42, %i0
a0092c78:  90 0e 20 ff  and  %i0, 0xff, %o0
a0092c7c:  40 00 5d b0  call  0xa00aa33c
a0092c80:  92 10 20 00  clr  %o1
a0092c84:  e0 06 63 ec  ld  [ %i1 + 0x3ec ], %l0
a0092c88:  1f 09 24 92  sethi  %hi(0x24924800), %o7
a0092c8c:  96 04 3f d6  add  %l0, -42, %o3
a0092c90:  98 13 e1 25  or  %o7, 0x125, %o4
a0092c94:  80 52 c0 0c  umul  %o3, %o4, %g0
a0092c98:  91 40 00 00  rd  %y, %o0
a0092c9c:  94 22 c0 08  sub  %o3, %o0, %o2
a0092ca0:  93 32 a0 01  srl  %o2, 1, %o1
a0092ca4:  82 02 00 09  add  %o0, %o1, %g1
a0092ca8:  1b 19 99 99  sethi  %hi(0x66666400), %o5
a0092cac:  a1 30 60 02  srl  %g1, 2, %l0
a0092cb0:  b0 13 62 67  or  %o5, 0x267, %i0
a0092cb4:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a0092cb8:  9e 02 3f df  add  %o0, -33, %o7
a0092cbc:  80 5b c0 18  smul  %o7, %i0, %g0
a0092cc0:  99 40 00 00  rd  %y, %o4
a0092cc4:  95 3b 20 02  sra  %o4, 2, %o2
a0092cc8:  97 3b e0 1f  sra  %o7, 0x1f, %o3
a0092ccc:  9a 22 80 0b  sub  %o2, %o3, %o5
a0092cd0:  93 2b 60 02  sll  %o5, 2, %o1
a0092cd4:  82 02 40 0d  add  %o1, %o5, %g1
a0092cd8:  98 00 40 01  add  %g1, %g1, %o4
a0092cdc:  94 23 c0 0c  sub  %o7, %o4, %o2
a0092ce0:  96 02 a0 2a  add  %o2, 0x2a, %o3
a0092ce4:  d6 26 63 ec  st  %o3, [ %i1 + 0x3ec ]
a0092ce8:  40 00 5e 0e  call  0xa00aa520
a0092cec:  90 0a a0 ff  and  %o2, 0xff, %o0
a0092cf0:  92 0a 20 ff  and  %o0, 0xff, %o1
a0092cf4:  80 a2 60 01  cmp  %o1, 1
a0092cf8:  12 bf ff f0  bne  0xa0092cb8
a0092cfc:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a0092d00:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a0092d04:  17 09 24 92  sethi  %hi(0x24924800), %o3
a0092d08:  94 03 3f d6  add  %o4, -42, %o2
a0092d0c:  9a 12 e1 25  or  %o3, 0x125, %o5
a0092d10:  80 52 80 0d  umul  %o2, %o5, %g0
a0092d14:  9f 40 00 00  rd  %y, %o7
a0092d18:  92 22 80 0f  sub  %o2, %o7, %o1
a0092d1c:  83 32 60 01  srl  %o1, 1, %g1
a0092d20:  b0 03 c0 01  add  %o7, %g1, %i0
a0092d24:  b2 0c 20 ff  and  %l0, 0xff, %i1
a0092d28:  91 36 20 02  srl  %i0, 2, %o0
a0092d2c:  80 a2 00 19  cmp  %o0, %i1
a0092d30:  02 80 00 04  be  0xa0092d40
a0092d34:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0092d38:  40 00 69 22  call  0xa00ad1c0
a0092d3c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0092d40:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a0092d44:  82 02 7f d6  add  %o1, -42, %g1
a0092d48:  90 08 60 ff  and  %g1, 0xff, %o0
a0092d4c:  40 00 58 b0  call  0xa00a900c
a0092d50:  92 10 20 01  mov  1, %o1
a0092d54:  de 06 63 ec  ld  [ %i1 + 0x3ec ], %o7
a0092d58:  b0 03 ff d6  add  %o7, -42, %i0
a0092d5c:  90 0e 20 ff  and  %i0, 0xff, %o0
a0092d60:  40 00 5d 77  call  0xa00aa33c
a0092d64:  92 10 20 01  mov  1, %o1
a0092d68:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0
a0092d6c:  a0 02 3f d6  add  %o0, -42, %l0
a0092d70:  b2 0c 20 ff  and  %l0, 0xff, %i1
a0092d74:  40 00 71 b6  call  0xa00af44c
a0092d78:  91 e8 20 2a  restore  %g0, 0x2a, %o0
a0092d7c:  01 00 00 00  nop
