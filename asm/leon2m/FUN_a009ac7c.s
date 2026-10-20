# leon2m FUN_a009ac7c 0xa009ac7c-0xa009ad40 (196 bytes)
a009ac7c:  9d e3 bf 98  save  %sp, -104, %sp
a009ac80:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009ac84:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1	! 0xa802afec
a009ac88:  90 00 60 30  add  %g1, 0x30, %o0
a009ac8c:  40 00 39 cc  call  0xa00a93bc
a009ac90:  90 0a 20 ff  and  %o0, 0xff, %o0
a009ac94:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009ac98:  96 02 3f 33  add  %o0, -205, %o3
a009ac9c:  b3 3a e0 1f  sra  %o3, 0x1f, %i1
a009aca0:  b1 36 60 1e  srl  %i1, 0x1e, %i0
a009aca4:  9e 02 c0 18  add  %o3, %i0, %o7
a009aca8:  98 0b ff fc  and  %o7, -4, %o4
a009acac:  94 22 c0 0c  sub  %o3, %o4, %o2
a009acb0:  9a 02 a0 d0  add  %o2, 0xd0, %o5
a009acb4:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009acb8:  40 00 40 1e  call  0xa00aad30
a009acbc:  90 0a a0 ff  and  %o2, 0xff, %o0
a009acc0:  92 0a 20 ff  and  %o0, 0xff, %o1
a009acc4:  80 a2 60 01  cmp  %o1, 1
a009acc8:  32 bf ff f4  bne,a   0xa009ac98
a009accc:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009acd0:  d6 06 a3 ec  ld  [ %i2 + 0x3ec ], %o3
a009acd4:  9a 02 e0 30  add  %o3, 0x30, %o5
a009acd8:  90 0b 60 ff  and  %o5, 0xff, %o0
a009acdc:  40 00 3a 5d  call  0xa00a9650
a009ace0:  92 10 20 01  mov  1, %o1
a009ace4:  d4 06 a3 ec  ld  [ %i2 + 0x3ec ], %o2
a009ace8:  92 02 a0 30  add  %o2, 0x30, %o1
a009acec:  40 02 a6 2c  call  0xa014459c
a009acf0:  90 0a 60 ff  and  %o1, 0xff, %o0
a009acf4:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a009acf8:  b4 0a 20 ff  and  %o0, 0xff, %i2
a009acfc:  c2 08 60 55  ldub  [ %g1 + 0x55 ], %g1
a009ad00:  80 a6 80 01  cmp  %i2, %g1
a009ad04:  02 80 00 08  be  0xa009ad24
a009ad08:  01 00 00 00  nop
a009ad0c:  40 02 a6 3c  call  0xa01445fc
a009ad10:  90 10 00 01  mov  %g1, %o0
a009ad14:  b2 0a 20 ff  and  %o0, 0xff, %i1
a009ad18:  b0 10 20 01  mov  1, %i0
a009ad1c:  40 00 35 08  call  0xa00a813c
a009ad20:  95 e8 20 01  restore  %g0, 1, %o2
a009ad24:  40 02 a6 36  call  0xa01445fc
a009ad28:  90 10 00 01  mov  %g1, %o0
a009ad2c:  b2 0a 20 ff  and  %o0, 0xff, %i1
a009ad30:  b0 10 20 01  mov  1, %i0
a009ad34:  40 00 35 02  call  0xa00a813c
a009ad38:  95 e8 20 00  restore  %g0, 0, %o2
a009ad3c:  01 00 00 00  nop
