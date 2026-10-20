# leon2m FUN_a009dc84 0xa009dc84-0xa009dd34 (176 bytes)
a009dc84:  9d e3 bf 98  save  %sp, -104, %sp
a009dc88:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009dc8c:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1	! 0xa802afec
a009dc90:  90 00 7f bc  add  %g1, -68, %o0
a009dc94:  40 00 2d ca  call  0xa00a93bc
a009dc98:  90 0a 20 ff  and  %o0, 0xff, %o0
a009dc9c:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009dca0:  96 02 3f bd  add  %o0, -67, %o3
a009dca4:  b3 3a e0 1f  sra  %o3, 0x1f, %i1
a009dca8:  b1 36 60 1e  srl  %i1, 0x1e, %i0
a009dcac:  9e 02 c0 18  add  %o3, %i0, %o7
a009dcb0:  98 0b ff fc  and  %o7, -4, %o4
a009dcb4:  94 22 c0 0c  sub  %o3, %o4, %o2
a009dcb8:  9a 02 a0 44  add  %o2, 0x44, %o5
a009dcbc:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009dcc0:  40 00 34 1c  call  0xa00aad30
a009dcc4:  90 0a a0 ff  and  %o2, 0xff, %o0
a009dcc8:  92 0a 20 ff  and  %o0, 0xff, %o1
a009dccc:  80 a2 60 01  cmp  %o1, 1
a009dcd0:  12 bf ff f4  bne  0xa009dca0
a009dcd4:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009dcd8:  d6 06 a3 ec  ld  [ %i2 + 0x3ec ], %o3
a009dcdc:  9a 02 ff bc  add  %o3, -68, %o5
a009dce0:  92 10 20 01  mov  1, %o1
a009dce4:  40 00 2e 5b  call  0xa00a9650
a009dce8:  90 0b 60 ff  and  %o5, 0xff, %o0
a009dcec:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a009dcf0:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a009dcf4:  f2 0a a0 56  ldub  [ %o2 + 0x56 ], %i1
a009dcf8:  82 02 7f ba  add  %o1, -70, %g1
a009dcfc:  b4 0e 60 ff  and  %i1, 0xff, %i2
a009dd00:  80 a0 40 1a  cmp  %g1, %i2
a009dd04:  02 80 00 06  be  0xa009dd1c
a009dd08:  9e 06 60 02  add  %i1, 2, %o7
a009dd0c:  b2 0b e0 ff  and  %o7, 0xff, %i1
a009dd10:  b0 10 20 01  mov  1, %i0
a009dd14:  40 00 29 0a  call  0xa00a813c
a009dd18:  95 e8 20 01  restore  %g0, 1, %o2
a009dd1c:  98 06 60 02  add  %i1, 2, %o4
a009dd20:  b2 0b 20 ff  and  %o4, 0xff, %i1
a009dd24:  b0 10 20 01  mov  1, %i0
a009dd28:  40 00 29 05  call  0xa00a813c
a009dd2c:  95 e8 20 00  restore  %g0, 0, %o2
a009dd30:  01 00 00 00  nop
