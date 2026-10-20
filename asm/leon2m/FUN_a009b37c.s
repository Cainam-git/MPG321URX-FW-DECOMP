# leon2m FUN_a009b37c 0xa009b37c-0xa009b434 (184 bytes)
a009b37c:  9d e3 bf 98  save  %sp, -104, %sp
a009b380:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009b384:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009b388:  90 02 60 1e  add  %o1, 0x1e, %o0
a009b38c:  40 00 38 0c  call  0xa00a93bc
a009b390:  90 0a 20 ff  and  %o0, 0xff, %o0
a009b394:  03 19 99 99  sethi  %hi(0x66666400), %g1
a009b398:  b2 10 62 67  or  %g1, 0x267, %i1	! 0x66666667
a009b39c:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009b3a0:  9e 02 3f 1f  add  %o0, -225, %o7
a009b3a4:  80 5b c0 19  smul  %o7, %i1, %g0
a009b3a8:  97 40 00 00  rd  %y, %o3
a009b3ac:  93 3a e0 01  sra  %o3, 1, %o1
a009b3b0:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009b3b4:  82 22 40 0a  sub  %o1, %o2, %g1
a009b3b8:  b1 28 60 02  sll  %g1, 2, %i0
a009b3bc:  98 06 00 01  add  %i0, %g1, %o4
a009b3c0:  96 23 c0 0c  sub  %o7, %o4, %o3
a009b3c4:  9a 02 e0 e2  add  %o3, 0xe2, %o5
a009b3c8:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009b3cc:  40 00 3e 59  call  0xa00aad30
a009b3d0:  90 0a e0 ff  and  %o3, 0xff, %o0
a009b3d4:  94 0a 20 ff  and  %o0, 0xff, %o2
a009b3d8:  80 a2 a0 01  cmp  %o2, 1
a009b3dc:  12 bf ff f1  bne  0xa009b3a0
a009b3e0:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009b3e4:  f0 06 a3 ec  ld  [ %i2 + 0x3ec ], %i0
a009b3e8:  9a 06 20 1e  add  %i0, 0x1e, %o5
a009b3ec:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a009b3f0:  da 2b 23 cf  stb  %o5, [ %o4 + 0x3cf ]	! 0xa802d3cf
a009b3f4:  90 0b 60 ff  and  %o5, 0xff, %o0
a009b3f8:  40 00 38 96  call  0xa00a9650
a009b3fc:  92 10 20 01  mov  1, %o1
a009b400:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009b404:  9e 06 7f 1e  add  %i1, -226, %o7
a009b408:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009b40c:  f2 0e a0 55  ldub  [ %i2 + 0x55 ], %i1	! 0xa8025c55
a009b410:  b0 10 20 01  mov  1, %i0
a009b414:  80 a3 c0 19  cmp  %o7, %i1
a009b418:  02 80 00 04  be  0xa009b428
a009b41c:  b4 10 20 00  clr  %i2
a009b420:  b0 10 20 01  mov  1, %i0
a009b424:  b4 10 20 01  mov  1, %i2
a009b428:  40 00 33 45  call  0xa00a813c
a009b42c:  81 e8 00 00  restore
a009b430:  01 00 00 00  nop
