# leon2m FUN_a009aec8 0xa009aec8-0xa009af8c (196 bytes)
a009aec8:  9d e3 bf 98  save  %sp, -104, %sp
a009aecc:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009aed0:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1	! 0xa802afec
a009aed4:  90 00 60 2c  add  %g1, 0x2c, %o0
a009aed8:  40 00 39 39  call  0xa00a93bc
a009aedc:  90 0a 20 ff  and  %o0, 0xff, %o0
a009aee0:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009aee4:  96 02 3f 2d  add  %o0, -211, %o3
a009aee8:  b3 3a e0 1f  sra  %o3, 0x1f, %i1
a009aeec:  b1 36 60 1e  srl  %i1, 0x1e, %i0
a009aef0:  9e 02 c0 18  add  %o3, %i0, %o7
a009aef4:  98 0b ff fc  and  %o7, -4, %o4
a009aef8:  94 22 c0 0c  sub  %o3, %o4, %o2
a009aefc:  9a 02 a0 d4  add  %o2, 0xd4, %o5
a009af00:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009af04:  40 00 3f 8b  call  0xa00aad30
a009af08:  90 0a a0 ff  and  %o2, 0xff, %o0
a009af0c:  92 0a 20 ff  and  %o0, 0xff, %o1
a009af10:  80 a2 60 01  cmp  %o1, 1
a009af14:  32 bf ff f4  bne,a   0xa009aee4
a009af18:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009af1c:  d6 06 a3 ec  ld  [ %i2 + 0x3ec ], %o3
a009af20:  9a 02 e0 2c  add  %o3, 0x2c, %o5
a009af24:  90 0b 60 ff  and  %o5, 0xff, %o0
a009af28:  40 00 39 ca  call  0xa00a9650
a009af2c:  92 10 20 01  mov  1, %o1
a009af30:  d4 06 a3 ec  ld  [ %i2 + 0x3ec ], %o2
a009af34:  92 02 a0 2c  add  %o2, 0x2c, %o1
a009af38:  40 02 a5 99  call  0xa014459c
a009af3c:  90 0a 60 ff  and  %o1, 0xff, %o0
a009af40:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a009af44:  b4 0a 20 ff  and  %o0, 0xff, %i2
a009af48:  c2 08 60 55  ldub  [ %g1 + 0x55 ], %g1
a009af4c:  80 a6 80 01  cmp  %i2, %g1
a009af50:  02 80 00 08  be  0xa009af70
a009af54:  01 00 00 00  nop
a009af58:  40 02 a5 a9  call  0xa01445fc
a009af5c:  90 10 00 01  mov  %g1, %o0
a009af60:  b2 0a 20 ff  and  %o0, 0xff, %i1
a009af64:  b0 10 20 01  mov  1, %i0
a009af68:  40 00 34 75  call  0xa00a813c
a009af6c:  95 e8 20 01  restore  %g0, 1, %o2
a009af70:  40 02 a5 a3  call  0xa01445fc
a009af74:  90 10 00 01  mov  %g1, %o0
a009af78:  b2 0a 20 ff  and  %o0, 0xff, %i1
a009af7c:  b0 10 20 01  mov  1, %i0
a009af80:  40 00 34 6f  call  0xa00a813c
a009af84:  95 e8 20 00  restore  %g0, 0, %o2
a009af88:  01 00 00 00  nop
