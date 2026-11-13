# leon2m FUN_a009de04 0xa009de04-0xa009deb0 (172 bytes)
a009de04:  9d e3 bf 98  save  %sp, -104, %sp
a009de08:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009de0c:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009de10:  90 02 60 48  add  %o1, 0x48, %o0
a009de14:  40 00 2d 6a  call  0xa00a93bc
a009de18:  90 0a 20 ff  and  %o0, 0xff, %o0
a009de1c:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009de20:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009de24:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009de28:  9e 02 3f 4a  add  %o0, -182, %o7
a009de2c:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009de30:  80 5b c0 19  smul  %o7, %i1, %g0
a009de34:  93 40 00 00  rd  %y, %o1
a009de38:  82 22 40 0a  sub  %o1, %o2, %g1
a009de3c:  b0 00 40 01  add  %g1, %g1, %i0
a009de40:  98 06 00 01  add  %i0, %g1, %o4
a009de44:  96 23 c0 0c  sub  %o7, %o4, %o3
a009de48:  9a 02 e0 b8  add  %o3, 0xb8, %o5
a009de4c:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009de50:  40 00 33 b8  call  0xa00aad30
a009de54:  90 0a e0 ff  and  %o3, 0xff, %o0
a009de58:  94 0a 20 ff  and  %o0, 0xff, %o2
a009de5c:  80 a2 a0 01  cmp  %o2, 1
a009de60:  12 bf ff f2  bne  0xa009de28
a009de64:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009de68:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a009de6c:  9a 03 e0 48  add  %o7, 0x48, %o5
a009de70:  90 0b 60 ff  and  %o5, 0xff, %o0
a009de74:  40 00 2d f7  call  0xa00a9650
a009de78:  92 10 20 01  mov  1, %o1
a009de7c:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009de80:  96 06 7f 48  add  %i1, -184, %o3
a009de84:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009de88:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009de8c:  b0 10 20 01  mov  1, %i0
a009de90:  80 a2 c0 19  cmp  %o3, %i1
a009de94:  02 80 00 04  be  0xa009dea4
a009de98:  b4 10 20 00  clr  %i2
a009de9c:  b0 10 20 01  mov  1, %i0
a009dea0:  b4 10 20 01  mov  1, %i2
a009dea4:  40 00 28 a6  call  0xa00a813c
a009dea8:  81 e8 00 00  restore
a009deac:  01 00 00 00  nop
