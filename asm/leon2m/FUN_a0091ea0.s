# leon2m FUN_a0091ea0 0xa0091ea0-0xa0091f58 (184 bytes)
a0091ea0:  9d e3 bf 98  save  %sp, -104, %sp
a0091ea4:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0091ea8:  d6 06 63 ec  ld  [ %i1 + 0x3ec ], %o3	! 0xa802afec
a0091eac:  94 02 ff eb  add  %o3, -21, %o2
a0091eb0:  40 00 5c 0e  call  0xa00a8ee8
a0091eb4:  90 0a a0 ff  and  %o2, 0xff, %o0
a0091eb8:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a0091ebc:  90 02 7f eb  add  %o1, -21, %o0
a0091ec0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091ec4:  40 00 60 e5  call  0xa00aa258
a0091ec8:  92 10 20 00  clr  %o1
a0091ecc:  03 15 55 55  sethi  %hi(0x55555400), %g1
a0091ed0:  b0 10 61 56  or  %g1, 0x156, %i0	! 0x55555556
a0091ed4:  de 16 63 ee  lduh  [ %i1 + 0x3ee ], %o7
a0091ed8:  90 03 ff ec  add  %o7, -20, %o0
a0091edc:  99 3a 20 1f  sra  %o0, 0x1f, %o4
a0091ee0:  80 5a 00 18  smul  %o0, %i0, %g0
a0091ee4:  97 40 00 00  rd  %y, %o3
a0091ee8:  94 22 c0 0c  sub  %o3, %o4, %o2
a0091eec:  92 02 80 0a  add  %o2, %o2, %o1
a0091ef0:  82 02 40 0a  add  %o1, %o2, %g1
a0091ef4:  9e 22 00 01  sub  %o0, %g1, %o7
a0091ef8:  9a 03 e0 15  add  %o7, 0x15, %o5
a0091efc:  90 0b e0 ff  and  %o7, 0xff, %o0
a0091f00:  40 00 61 88  call  0xa00aa520
a0091f04:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a0091f08:  98 0a 20 ff  and  %o0, 0xff, %o4
a0091f0c:  80 a3 20 01  cmp  %o4, 1
a0091f10:  12 bf ff f2  bne  0xa0091ed8
a0091f14:  de 16 63 ee  lduh  [ %i1 + 0x3ee ], %o7
a0091f18:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a0091f1c:  82 02 7f eb  add  %o1, -21, %g1
a0091f20:  90 08 60 ff  and  %g1, 0xff, %o0
a0091f24:  40 00 5c 3a  call  0xa00a900c
a0091f28:  92 10 20 01  mov  1, %o1
a0091f2c:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0
a0091f30:  9a 02 3f eb  add  %o0, -21, %o5
a0091f34:  90 0b 60 ff  and  %o5, 0xff, %o0
a0091f38:  40 00 60 c8  call  0xa00aa258
a0091f3c:  92 10 20 01  mov  1, %o1
a0091f40:  f0 06 63 ec  ld  [ %i1 + 0x3ec ], %i0
a0091f44:  b2 06 3f eb  add  %i0, -21, %i1
a0091f48:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0091f4c:  40 00 75 40  call  0xa00af44c
a0091f50:  91 e8 20 15  restore  %g0, 0x15, %o0
a0091f54:  01 00 00 00  nop
