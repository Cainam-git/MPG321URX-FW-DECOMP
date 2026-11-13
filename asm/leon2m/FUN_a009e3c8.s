# leon2m FUN_a009e3c8 0xa009e3c8-0xa009e480 (184 bytes)
a009e3c8:  9d e3 bf 98  save  %sp, -104, %sp
a009e3cc:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009e3d0:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009e3d4:  90 02 60 0f  add  %o1, 0xf, %o0
a009e3d8:  40 00 2b f9  call  0xa00a93bc
a009e3dc:  90 0a 20 ff  and  %o0, 0xff, %o0
a009e3e0:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009e3e4:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009e3e8:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009e3ec:  9e 02 3f 10  add  %o0, -240, %o7
a009e3f0:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009e3f4:  80 5b c0 19  smul  %o7, %i1, %g0
a009e3f8:  93 40 00 00  rd  %y, %o1
a009e3fc:  82 22 40 0a  sub  %o1, %o2, %g1
a009e400:  b0 00 40 01  add  %g1, %g1, %i0
a009e404:  98 06 00 01  add  %i0, %g1, %o4
a009e408:  96 23 c0 0c  sub  %o7, %o4, %o3
a009e40c:  9a 02 e0 f1  add  %o3, 0xf1, %o5
a009e410:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009e414:  40 00 32 47  call  0xa00aad30
a009e418:  90 0a e0 ff  and  %o3, 0xff, %o0
a009e41c:  94 0a 20 ff  and  %o0, 0xff, %o2
a009e420:  80 a2 a0 01  cmp  %o2, 1
a009e424:  12 bf ff f2  bne  0xa009e3ec
a009e428:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009e42c:  f0 06 a3 ec  ld  [ %i2 + 0x3ec ], %i0
a009e430:  b2 06 20 0f  add  %i0, 0xf, %i1
a009e434:  90 0e 60 ff  and  %i1, 0xff, %o0
a009e438:  40 00 2c 86  call  0xa00a9650
a009e43c:  92 10 20 01  mov  1, %o1
a009e440:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a009e444:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a009e448:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a009e44c:  9a 03 e0 0f  add  %o7, 0xf, %o5
a009e450:  96 03 ff 0f  add  %o7, -241, %o3
a009e454:  f2 0b 20 55  ldub  [ %o4 + 0x55 ], %i1
a009e458:  da 2e a0 6d  stb  %o5, [ %i2 + 0x6d ]
a009e45c:  b0 10 20 01  mov  1, %i0
a009e460:  80 a2 c0 19  cmp  %o3, %i1
a009e464:  02 80 00 04  be  0xa009e474
a009e468:  b4 10 20 00  clr  %i2
a009e46c:  b0 10 20 01  mov  1, %i0
a009e470:  b4 10 20 01  mov  1, %i2
a009e474:  40 00 27 32  call  0xa00a813c
a009e478:  81 e8 00 00  restore
a009e47c:  01 00 00 00  nop
