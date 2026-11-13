# leon2m FUN_a009ae04 0xa009ae04-0xa009aec8 (196 bytes)
a009ae04:  9d e3 bf 98  save  %sp, -104, %sp
a009ae08:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009ae0c:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1	! 0xa802afec
a009ae10:  90 00 60 2c  add  %g1, 0x2c, %o0
a009ae14:  40 00 39 6a  call  0xa00a93bc
a009ae18:  90 0a 20 ff  and  %o0, 0xff, %o0
a009ae1c:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009ae20:  96 02 3f 2f  add  %o0, -209, %o3
a009ae24:  b3 3a e0 1f  sra  %o3, 0x1f, %i1
a009ae28:  b1 36 60 1e  srl  %i1, 0x1e, %i0
a009ae2c:  9e 02 c0 18  add  %o3, %i0, %o7
a009ae30:  98 0b ff fc  and  %o7, -4, %o4
a009ae34:  94 22 c0 0c  sub  %o3, %o4, %o2
a009ae38:  9a 02 a0 d4  add  %o2, 0xd4, %o5
a009ae3c:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009ae40:  40 00 3f bc  call  0xa00aad30
a009ae44:  90 0a a0 ff  and  %o2, 0xff, %o0
a009ae48:  92 0a 20 ff  and  %o0, 0xff, %o1
a009ae4c:  80 a2 60 01  cmp  %o1, 1
a009ae50:  32 bf ff f4  bne,a   0xa009ae20
a009ae54:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009ae58:  d6 06 a3 ec  ld  [ %i2 + 0x3ec ], %o3
a009ae5c:  9a 02 e0 2c  add  %o3, 0x2c, %o5
a009ae60:  90 0b 60 ff  and  %o5, 0xff, %o0
a009ae64:  40 00 39 fb  call  0xa00a9650
a009ae68:  92 10 20 01  mov  1, %o1
a009ae6c:  d4 06 a3 ec  ld  [ %i2 + 0x3ec ], %o2
a009ae70:  92 02 a0 2c  add  %o2, 0x2c, %o1
a009ae74:  40 02 a5 ca  call  0xa014459c
a009ae78:  90 0a 60 ff  and  %o1, 0xff, %o0
a009ae7c:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a009ae80:  b4 0a 20 ff  and  %o0, 0xff, %i2
a009ae84:  c2 08 60 55  ldub  [ %g1 + 0x55 ], %g1
a009ae88:  80 a6 80 01  cmp  %i2, %g1
a009ae8c:  02 80 00 08  be  0xa009aeac
a009ae90:  01 00 00 00  nop
a009ae94:  40 02 a5 da  call  0xa01445fc
a009ae98:  90 10 00 01  mov  %g1, %o0
a009ae9c:  b2 0a 20 ff  and  %o0, 0xff, %i1
a009aea0:  b0 10 20 01  mov  1, %i0
a009aea4:  40 00 34 a6  call  0xa00a813c
a009aea8:  95 e8 20 01  restore  %g0, 1, %o2
a009aeac:  40 02 a5 d4  call  0xa01445fc
a009aeb0:  90 10 00 01  mov  %g1, %o0
a009aeb4:  b2 0a 20 ff  and  %o0, 0xff, %i1
a009aeb8:  b0 10 20 01  mov  1, %i0
a009aebc:  40 00 34 a0  call  0xa00a813c
a009aec0:  95 e8 20 00  restore  %g0, 0, %o2
a009aec4:  01 00 00 00  nop
