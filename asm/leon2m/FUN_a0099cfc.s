# leon2m FUN_a0099cfc 0xa0099cfc-0xa0099d6c (112 bytes)
a0099cfc:  9d e3 bf 98  save  %sp, -104, %sp
a0099d00:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a0099d04:  a0 16 62 90  or  %i1, 0x290, %l0	! 0xa802d290
a0099d08:  f4 04 21 dc  ld  [ %l0 + 0x1dc ], %i2
a0099d0c:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0099d10:  b1 36 a0 0f  srl  %i2, 0xf, %i0
a0099d14:  de 04 63 ec  ld  [ %l1 + 0x3ec ], %o7
a0099d18:  9a 0e 20 01  and  %i0, 1, %o5
a0099d1c:  96 03 ff cc  add  %o7, -52, %o3
a0099d20:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a0099d24:  90 0a e0 ff  and  %o3, 0xff, %o0
a0099d28:  da 2b 20 56  stb  %o5, [ %o4 + 0x56 ]
a0099d2c:  40 00 3c b8  call  0xa00a900c
a0099d30:  92 10 20 02  mov  2, %o1
a0099d34:  d4 04 21 dc  ld  [ %l0 + 0x1dc ], %o2
a0099d38:  91 32 a0 0f  srl  %o2, 0xf, %o0
a0099d3c:  90 0a 20 01  and  %o0, 1, %o0
a0099d40:  92 02 20 bb  add  %o0, 0xbb, %o1
a0099d44:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a0099d48:  40 00 3e 42  call  0xa00a9650
a0099d4c:  92 10 20 01  mov  1, %o1
a0099d50:  c2 04 21 dc  ld  [ %l0 + 0x1dc ], %g1
a0099d54:  b3 30 60 0f  srl  %g1, 0xf, %i1
a0099d58:  b2 0e 60 01  and  %i1, 1, %i1
a0099d5c:  b0 10 20 01  mov  1, %i0
a0099d60:  40 00 38 f7  call  0xa00a813c
a0099d64:  95 e8 20 00  restore  %g0, 0, %o2
a0099d68:  01 00 00 00  nop
