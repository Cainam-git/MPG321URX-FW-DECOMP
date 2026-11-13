# leon2m FUN_a009b070 0xa009b070-0xa009b154 (228 bytes)
a009b070:  9d e3 bf 98  save  %sp, -104, %sp
a009b074:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009b078:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009b07c:  90 02 60 33  add  %o1, 0x33, %o0
a009b080:  40 00 38 cf  call  0xa00a93bc
a009b084:  90 0a 20 ff  and  %o0, 0xff, %o0
a009b088:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009b08c:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009b090:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009b094:  9e 02 3f 34  add  %o0, -204, %o7
a009b098:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009b09c:  80 5b c0 19  smul  %o7, %i1, %g0
a009b0a0:  93 40 00 00  rd  %y, %o1
a009b0a4:  82 22 40 0a  sub  %o1, %o2, %g1
a009b0a8:  b0 00 40 01  add  %g1, %g1, %i0
a009b0ac:  98 06 00 01  add  %i0, %g1, %o4
a009b0b0:  96 23 c0 0c  sub  %o7, %o4, %o3
a009b0b4:  9a 02 e0 cd  add  %o3, 0xcd, %o5
a009b0b8:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009b0bc:  40 00 3f 1d  call  0xa00aad30
a009b0c0:  90 0a e0 ff  and  %o3, 0xff, %o0
a009b0c4:  94 0a 20 ff  and  %o0, 0xff, %o2
a009b0c8:  80 a2 a0 01  cmp  %o2, 1
a009b0cc:  12 bf ff f2  bne  0xa009b094
a009b0d0:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009b0d4:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a009b0d8:  94 10 3f cf  mov  -49, %o2
a009b0dc:  96 02 60 33  add  %o1, 0x33, %o3
a009b0e0:  82 22 80 09  sub  %o2, %o1, %g1
a009b0e4:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a009b0e8:  90 0a e0 ff  and  %o3, 0xff, %o0
a009b0ec:  c2 2e 22 c1  stb  %g1, [ %i0 + 0x2c1 ]
a009b0f0:  40 00 39 58  call  0xa00a9650
a009b0f4:  92 10 20 01  mov  1, %o1
a009b0f8:  40 00 f2 8a  call  0xa00d7b20
a009b0fc:  01 00 00 00  nop
a009b100:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a009b104:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a009b108:  d6 0b 20 55  ldub  [ %o4 + 0x55 ], %o3
a009b10c:  9a 10 20 cf  mov  0xcf, %o5
a009b110:  b4 23 40 0f  sub  %o5, %o7, %i2
a009b114:  b2 0a e0 ff  and  %o3, 0xff, %i1
a009b118:  80 a6 80 19  cmp  %i2, %i1
a009b11c:  02 80 00 07  be  0xa009b138
a009b120:  9a 10 20 02  mov  2, %o5
a009b124:  b4 23 40 0b  sub  %o5, %o3, %i2
a009b128:  b2 0e a0 ff  and  %i2, 0xff, %i1
a009b12c:  b0 10 20 01  mov  1, %i0
a009b130:  40 00 34 03  call  0xa00a813c
a009b134:  95 e8 20 01  restore  %g0, 1, %o2
a009b138:  b2 10 20 02  mov  2, %i1
a009b13c:  90 26 40 0b  sub  %i1, %o3, %o0
a009b140:  b2 0a 20 ff  and  %o0, 0xff, %i1
a009b144:  b0 10 20 01  mov  1, %i0
a009b148:  40 00 33 fd  call  0xa00a813c
a009b14c:  95 e8 20 00  restore  %g0, 0, %o2
a009b150:  01 00 00 00  nop
