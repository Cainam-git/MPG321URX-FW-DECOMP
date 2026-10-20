# leon2m FUN_a009b434 0xa009b434-0xa009b4e8 (180 bytes)
a009b434:  9d e3 bf 98  save  %sp, -104, %sp
a009b438:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009b43c:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009b440:  90 02 60 13  add  %o1, 0x13, %o0
a009b444:  40 00 37 de  call  0xa00a93bc
a009b448:  90 0a 20 ff  and  %o0, 0xff, %o0
a009b44c:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009b450:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009b454:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009b458:  9e 02 3f 15  add  %o0, -235, %o7
a009b45c:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009b460:  80 5b c0 19  smul  %o7, %i1, %g0
a009b464:  93 40 00 00  rd  %y, %o1
a009b468:  82 22 40 0a  sub  %o1, %o2, %g1
a009b46c:  b0 00 40 01  add  %g1, %g1, %i0
a009b470:  98 06 00 01  add  %i0, %g1, %o4
a009b474:  96 23 c0 0c  sub  %o7, %o4, %o3
a009b478:  9a 02 e0 ed  add  %o3, 0xed, %o5
a009b47c:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009b480:  40 00 3e 2c  call  0xa00aad30
a009b484:  90 0a e0 ff  and  %o3, 0xff, %o0
a009b488:  94 0a 20 ff  and  %o0, 0xff, %o2
a009b48c:  80 a2 a0 01  cmp  %o2, 1
a009b490:  12 bf ff f2  bne  0xa009b458
a009b494:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009b498:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a009b49c:  9a 03 20 13  add  %o4, 0x13, %o5
a009b4a0:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a009b4a4:  da 2b e0 0b  stb  %o5, [ %o7 + 0xb ]	! 0xa802d40b
a009b4a8:  90 0b 60 ff  and  %o5, 0xff, %o0
a009b4ac:  40 00 38 69  call  0xa00a9650
a009b4b0:  92 10 20 01  mov  1, %o1
a009b4b4:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009b4b8:  96 06 7f 13  add  %i1, -237, %o3
a009b4bc:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009b4c0:  f2 0e a0 55  ldub  [ %i2 + 0x55 ], %i1	! 0xa8025c55
a009b4c4:  b0 10 20 01  mov  1, %i0
a009b4c8:  80 a2 c0 19  cmp  %o3, %i1
a009b4cc:  02 80 00 04  be  0xa009b4dc
a009b4d0:  b4 10 20 00  clr  %i2
a009b4d4:  b0 10 20 01  mov  1, %i0
a009b4d8:  b4 10 20 01  mov  1, %i2
a009b4dc:  40 00 33 18  call  0xa00a813c
a009b4e0:  81 e8 00 00  restore
a009b4e4:  01 00 00 00  nop
