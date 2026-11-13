# leon2m FUN_a009deb0 0xa009deb0-0xa009df5c (172 bytes)
a009deb0:  9d e3 bf 98  save  %sp, -104, %sp
a009deb4:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009deb8:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009debc:  90 02 60 48  add  %o1, 0x48, %o0
a009dec0:  40 00 2d 3f  call  0xa00a93bc
a009dec4:  90 0a 20 ff  and  %o0, 0xff, %o0
a009dec8:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009decc:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009ded0:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009ded4:  9e 02 3f 49  add  %o0, -183, %o7
a009ded8:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009dedc:  80 5b c0 19  smul  %o7, %i1, %g0
a009dee0:  93 40 00 00  rd  %y, %o1
a009dee4:  82 22 40 0a  sub  %o1, %o2, %g1
a009dee8:  b0 00 40 01  add  %g1, %g1, %i0
a009deec:  98 06 00 01  add  %i0, %g1, %o4
a009def0:  96 23 c0 0c  sub  %o7, %o4, %o3
a009def4:  9a 02 e0 b8  add  %o3, 0xb8, %o5
a009def8:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009defc:  40 00 33 8d  call  0xa00aad30
a009df00:  90 0a e0 ff  and  %o3, 0xff, %o0
a009df04:  94 0a 20 ff  and  %o0, 0xff, %o2
a009df08:  80 a2 a0 01  cmp  %o2, 1
a009df0c:  12 bf ff f2  bne  0xa009ded4
a009df10:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009df14:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a009df18:  9a 03 e0 48  add  %o7, 0x48, %o5
a009df1c:  90 0b 60 ff  and  %o5, 0xff, %o0
a009df20:  40 00 2d cc  call  0xa00a9650
a009df24:  92 10 20 01  mov  1, %o1
a009df28:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009df2c:  96 06 7f 48  add  %i1, -184, %o3
a009df30:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009df34:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009df38:  b0 10 20 01  mov  1, %i0
a009df3c:  80 a2 c0 19  cmp  %o3, %i1
a009df40:  02 80 00 04  be  0xa009df50
a009df44:  b4 10 20 00  clr  %i2
a009df48:  b0 10 20 01  mov  1, %i0
a009df4c:  b4 10 20 01  mov  1, %i2
a009df50:  40 00 28 7b  call  0xa00a813c
a009df54:  81 e8 00 00  restore
a009df58:  01 00 00 00  nop
