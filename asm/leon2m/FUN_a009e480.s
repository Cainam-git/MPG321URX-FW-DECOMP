# leon2m FUN_a009e480 0xa009e480-0xa009e538 (184 bytes)
a009e480:  9d e3 bf 98  save  %sp, -104, %sp
a009e484:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009e488:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009e48c:  90 02 60 0f  add  %o1, 0xf, %o0
a009e490:  40 00 2b cb  call  0xa00a93bc
a009e494:  90 0a 20 ff  and  %o0, 0xff, %o0
a009e498:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009e49c:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009e4a0:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009e4a4:  9e 02 3f 11  add  %o0, -239, %o7
a009e4a8:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009e4ac:  80 5b c0 19  smul  %o7, %i1, %g0
a009e4b0:  93 40 00 00  rd  %y, %o1
a009e4b4:  82 22 40 0a  sub  %o1, %o2, %g1
a009e4b8:  b0 00 40 01  add  %g1, %g1, %i0
a009e4bc:  98 06 00 01  add  %i0, %g1, %o4
a009e4c0:  96 23 c0 0c  sub  %o7, %o4, %o3
a009e4c4:  9a 02 e0 f1  add  %o3, 0xf1, %o5
a009e4c8:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009e4cc:  40 00 32 19  call  0xa00aad30
a009e4d0:  90 0a e0 ff  and  %o3, 0xff, %o0
a009e4d4:  94 0a 20 ff  and  %o0, 0xff, %o2
a009e4d8:  80 a2 a0 01  cmp  %o2, 1
a009e4dc:  12 bf ff f2  bne  0xa009e4a4
a009e4e0:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009e4e4:  f0 06 a3 ec  ld  [ %i2 + 0x3ec ], %i0
a009e4e8:  b2 06 20 0f  add  %i0, 0xf, %i1
a009e4ec:  90 0e 60 ff  and  %i1, 0xff, %o0
a009e4f0:  40 00 2c 58  call  0xa00a9650
a009e4f4:  92 10 20 01  mov  1, %o1
a009e4f8:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a009e4fc:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a009e500:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a009e504:  9a 03 e0 0f  add  %o7, 0xf, %o5
a009e508:  96 03 ff 0f  add  %o7, -241, %o3
a009e50c:  f2 0b 20 55  ldub  [ %o4 + 0x55 ], %i1
a009e510:  da 2e a0 6d  stb  %o5, [ %i2 + 0x6d ]
a009e514:  b0 10 20 01  mov  1, %i0
a009e518:  80 a2 c0 19  cmp  %o3, %i1
a009e51c:  02 80 00 04  be  0xa009e52c
a009e520:  b4 10 20 00  clr  %i2
a009e524:  b0 10 20 01  mov  1, %i0
a009e528:  b4 10 20 01  mov  1, %i2
a009e52c:  40 00 27 04  call  0xa00a813c
a009e530:  81 e8 00 00  restore
a009e534:  01 00 00 00  nop
