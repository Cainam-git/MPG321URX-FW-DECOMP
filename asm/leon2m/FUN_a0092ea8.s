# leon2m FUN_a0092ea8 0xa0092ea8-0xa0092f2c (132 bytes)
a0092ea8:  9d e3 bf 98  save  %sp, -104, %sp
a0092eac:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0092eb0:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1	! 0xa802afec
a0092eb4:  90 02 7f fe  add  %o1, -2, %o0
a0092eb8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0092ebc:  40 00 84 a2  call  0xa00b4144
a0092ec0:  92 10 20 02  mov  2, %o1
a0092ec4:  82 10 20 34  mov  0x34, %g1
a0092ec8:  c2 26 63 ec  st  %g1, [ %i1 + 0x3ec ]
a0092ecc:  10 80 00 0a  b  0xa0092ef4
a0092ed0:  b0 10 00 19  mov  %i1, %i0
a0092ed4:  90 03 3f cd  add  %o4, -51, %o0
a0092ed8:  97 3a 20 1f  sra  %o0, 0x1f, %o3
a0092edc:  95 32 e0 1d  srl  %o3, 0x1d, %o2
a0092ee0:  92 02 00 0a  add  %o0, %o2, %o1
a0092ee4:  82 0a 7f f8  and  %o1, -8, %g1
a0092ee8:  9e 22 00 01  sub  %o0, %g1, %o7
a0092eec:  9a 03 e0 34  add  %o7, 0x34, %o5
a0092ef0:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a0092ef4:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a0092ef8:  96 03 3f cc  add  %o4, -52, %o3
a0092efc:  40 00 5d 89  call  0xa00aa520
a0092f00:  90 0a e0 ff  and  %o3, 0xff, %o0
a0092f04:  94 0a 20 ff  and  %o0, 0xff, %o2
a0092f08:  80 a2 a0 01  cmp  %o2, 1
a0092f0c:  12 bf ff f2  bne  0xa0092ed4
a0092f10:  d8 16 63 ee  lduh  [ %i1 + 0x3ee ], %o4
a0092f14:  f2 06 23 ec  ld  [ %i0 + 0x3ec ], %i1
a0092f18:  b0 06 7f cc  add  %i1, -52, %i0
a0092f1c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0092f20:  40 00 58 3b  call  0xa00a900c
a0092f24:  93 e8 20 01  restore  %g0, 1, %o1
a0092f28:  01 00 00 00  nop
