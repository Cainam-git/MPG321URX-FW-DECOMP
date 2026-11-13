# leon2m FUN_a009dbd4 0xa009dbd4-0xa009dc84 (176 bytes)
a009dbd4:  9d e3 bf 98  save  %sp, -104, %sp
a009dbd8:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009dbdc:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1	! 0xa802afec
a009dbe0:  90 00 7f bc  add  %g1, -68, %o0
a009dbe4:  40 00 2d f6  call  0xa00a93bc
a009dbe8:  90 0a 20 ff  and  %o0, 0xff, %o0
a009dbec:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009dbf0:  96 02 3f bf  add  %o0, -65, %o3
a009dbf4:  b3 3a e0 1f  sra  %o3, 0x1f, %i1
a009dbf8:  b1 36 60 1e  srl  %i1, 0x1e, %i0
a009dbfc:  9e 02 c0 18  add  %o3, %i0, %o7
a009dc00:  98 0b ff fc  and  %o7, -4, %o4
a009dc04:  94 22 c0 0c  sub  %o3, %o4, %o2
a009dc08:  9a 02 a0 44  add  %o2, 0x44, %o5
a009dc0c:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009dc10:  40 00 34 48  call  0xa00aad30
a009dc14:  90 0a a0 ff  and  %o2, 0xff, %o0
a009dc18:  92 0a 20 ff  and  %o0, 0xff, %o1
a009dc1c:  80 a2 60 01  cmp  %o1, 1
a009dc20:  12 bf ff f4  bne  0xa009dbf0
a009dc24:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009dc28:  d6 06 a3 ec  ld  [ %i2 + 0x3ec ], %o3
a009dc2c:  9a 02 ff bc  add  %o3, -68, %o5
a009dc30:  92 10 20 01  mov  1, %o1
a009dc34:  40 00 2e 87  call  0xa00a9650
a009dc38:  90 0b 60 ff  and  %o5, 0xff, %o0
a009dc3c:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a009dc40:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a009dc44:  f2 0a a0 56  ldub  [ %o2 + 0x56 ], %i1
a009dc48:  82 02 7f ba  add  %o1, -70, %g1
a009dc4c:  b4 0e 60 ff  and  %i1, 0xff, %i2
a009dc50:  80 a0 40 1a  cmp  %g1, %i2
a009dc54:  02 80 00 06  be  0xa009dc6c
a009dc58:  9e 06 60 02  add  %i1, 2, %o7
a009dc5c:  b2 0b e0 ff  and  %o7, 0xff, %i1
a009dc60:  b0 10 20 01  mov  1, %i0
a009dc64:  40 00 29 36  call  0xa00a813c
a009dc68:  95 e8 20 01  restore  %g0, 1, %o2
a009dc6c:  98 06 60 02  add  %i1, 2, %o4
a009dc70:  b2 0b 20 ff  and  %o4, 0xff, %i1
a009dc74:  b0 10 20 01  mov  1, %i0
a009dc78:  40 00 29 31  call  0xa00a813c
a009dc7c:  95 e8 20 00  restore  %g0, 0, %o2
a009dc80:  01 00 00 00  nop
