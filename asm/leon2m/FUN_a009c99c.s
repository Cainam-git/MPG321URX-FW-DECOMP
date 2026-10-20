# leon2m FUN_a009c99c 0xa009c99c-0xa009ca54 (184 bytes)
a009c99c:  9d e3 bf 98  save  %sp, -104, %sp
a009c9a0:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009c9a4:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009c9a8:  90 02 7f 90  add  %o1, -112, %o0
a009c9ac:  40 00 32 84  call  0xa00a93bc
a009c9b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c9b4:  03 24 92 49  sethi  %hi(0x92492400), %g1
a009c9b8:  b2 10 60 93  or  %g1, 0x93, %i1	! 0x92492493
a009c9bc:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009c9c0:  9e 02 3f 96  add  %o0, -106, %o7
a009c9c4:  80 5b c0 19  smul  %o7, %i1, %g0
a009c9c8:  99 40 00 00  rd  %y, %o4
a009c9cc:  96 03 00 0f  add  %o4, %o7, %o3
a009c9d0:  93 3a e0 02  sra  %o3, 2, %o1
a009c9d4:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009c9d8:  82 22 40 0a  sub  %o1, %o2, %g1
a009c9dc:  b1 28 60 03  sll  %g1, 3, %i0
a009c9e0:  9a 26 00 01  sub  %i0, %g1, %o5
a009c9e4:  96 23 c0 0d  sub  %o7, %o5, %o3
a009c9e8:  98 02 e0 70  add  %o3, 0x70, %o4
a009c9ec:  d8 26 a3 ec  st  %o4, [ %i2 + 0x3ec ]
a009c9f0:  40 00 38 d0  call  0xa00aad30
a009c9f4:  90 0a e0 ff  and  %o3, 0xff, %o0
a009c9f8:  94 0a 20 ff  and  %o0, 0xff, %o2
a009c9fc:  80 a2 a0 01  cmp  %o2, 1
a009ca00:  12 bf ff f0  bne  0xa009c9c0
a009ca04:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009ca08:  f0 06 a3 ec  ld  [ %i2 + 0x3ec ], %i0
a009ca0c:  9a 06 3f 90  add  %i0, -112, %o5
a009ca10:  90 0b 60 ff  and  %o5, 0xff, %o0
a009ca14:  40 00 33 0f  call  0xa00a9650
a009ca18:  92 10 20 01  mov  1, %o1
a009ca1c:  40 00 41 36  call  0xa00acef4
a009ca20:  b0 10 20 01  mov  1, %i0
a009ca24:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009ca28:  9e 06 7f 90  add  %i1, -112, %o7
a009ca2c:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009ca30:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009ca34:  80 a3 c0 19  cmp  %o7, %i1
a009ca38:  02 80 00 04  be  0xa009ca48
a009ca3c:  b4 10 20 00  clr  %i2
a009ca40:  b0 10 20 01  mov  1, %i0
a009ca44:  b4 10 20 01  mov  1, %i2
a009ca48:  40 00 2d bd  call  0xa00a813c
a009ca4c:  81 e8 00 00  restore
a009ca50:  01 00 00 00  nop
