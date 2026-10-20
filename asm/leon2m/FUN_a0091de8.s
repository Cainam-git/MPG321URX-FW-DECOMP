# leon2m FUN_a0091de8 0xa0091de8-0xa0091ea0 (184 bytes)
a0091de8:  9d e3 bf 98  save  %sp, -104, %sp
a0091dec:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0091df0:  d6 06 63 ec  ld  [ %i1 + 0x3ec ], %o3	! 0xa802afec
a0091df4:  94 02 ff eb  add  %o3, -21, %o2
a0091df8:  40 00 5c 3c  call  0xa00a8ee8
a0091dfc:  90 0a a0 ff  and  %o2, 0xff, %o0
a0091e00:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a0091e04:  90 02 7f eb  add  %o1, -21, %o0
a0091e08:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091e0c:  40 00 61 13  call  0xa00aa258
a0091e10:  92 10 20 00  clr  %o1
a0091e14:  03 15 55 55  sethi  %hi(0x55555400), %g1
a0091e18:  b0 10 61 56  or  %g1, 0x156, %i0	! 0x55555556
a0091e1c:  de 16 63 ee  lduh  [ %i1 + 0x3ee ], %o7
a0091e20:  90 03 ff ed  add  %o7, -19, %o0
a0091e24:  99 3a 20 1f  sra  %o0, 0x1f, %o4
a0091e28:  80 5a 00 18  smul  %o0, %i0, %g0
a0091e2c:  97 40 00 00  rd  %y, %o3
a0091e30:  94 22 c0 0c  sub  %o3, %o4, %o2
a0091e34:  92 02 80 0a  add  %o2, %o2, %o1
a0091e38:  82 02 40 0a  add  %o1, %o2, %g1
a0091e3c:  9e 22 00 01  sub  %o0, %g1, %o7
a0091e40:  9a 03 e0 15  add  %o7, 0x15, %o5
a0091e44:  90 0b e0 ff  and  %o7, 0xff, %o0
a0091e48:  40 00 61 b6  call  0xa00aa520
a0091e4c:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a0091e50:  98 0a 20 ff  and  %o0, 0xff, %o4
a0091e54:  80 a3 20 01  cmp  %o4, 1
a0091e58:  12 bf ff f2  bne  0xa0091e20
a0091e5c:  de 16 63 ee  lduh  [ %i1 + 0x3ee ], %o7
a0091e60:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a0091e64:  82 02 7f eb  add  %o1, -21, %g1
a0091e68:  90 08 60 ff  and  %g1, 0xff, %o0
a0091e6c:  40 00 5c 68  call  0xa00a900c
a0091e70:  92 10 20 01  mov  1, %o1
a0091e74:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0
a0091e78:  9a 02 3f eb  add  %o0, -21, %o5
a0091e7c:  90 0b 60 ff  and  %o5, 0xff, %o0
a0091e80:  40 00 60 f6  call  0xa00aa258
a0091e84:  92 10 20 01  mov  1, %o1
a0091e88:  f0 06 63 ec  ld  [ %i1 + 0x3ec ], %i0
a0091e8c:  b2 06 3f eb  add  %i0, -21, %i1
a0091e90:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0091e94:  40 00 75 6e  call  0xa00af44c
a0091e98:  91 e8 20 15  restore  %g0, 0x15, %o0
a0091e9c:  01 00 00 00  nop
