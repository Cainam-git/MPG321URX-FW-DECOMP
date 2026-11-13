# leon2m FUN_a009b4e8 0xa009b4e8-0xa009b59c (180 bytes)
a009b4e8:  9d e3 bf 98  save  %sp, -104, %sp
a009b4ec:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009b4f0:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009b4f4:  90 02 60 13  add  %o1, 0x13, %o0
a009b4f8:  40 00 37 b1  call  0xa00a93bc
a009b4fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a009b500:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009b504:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009b508:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009b50c:  9e 02 3f 14  add  %o0, -236, %o7
a009b510:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009b514:  80 5b c0 19  smul  %o7, %i1, %g0
a009b518:  93 40 00 00  rd  %y, %o1
a009b51c:  82 22 40 0a  sub  %o1, %o2, %g1
a009b520:  b0 00 40 01  add  %g1, %g1, %i0
a009b524:  98 06 00 01  add  %i0, %g1, %o4
a009b528:  96 23 c0 0c  sub  %o7, %o4, %o3
a009b52c:  9a 02 e0 ed  add  %o3, 0xed, %o5
a009b530:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009b534:  40 00 3d ff  call  0xa00aad30
a009b538:  90 0a e0 ff  and  %o3, 0xff, %o0
a009b53c:  94 0a 20 ff  and  %o0, 0xff, %o2
a009b540:  80 a2 a0 01  cmp  %o2, 1
a009b544:  12 bf ff f2  bne  0xa009b50c
a009b548:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009b54c:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a009b550:  9a 03 20 13  add  %o4, 0x13, %o5
a009b554:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a009b558:  da 2b e0 0b  stb  %o5, [ %o7 + 0xb ]	! 0xa802d40b
a009b55c:  90 0b 60 ff  and  %o5, 0xff, %o0
a009b560:  40 00 38 3c  call  0xa00a9650
a009b564:  92 10 20 01  mov  1, %o1
a009b568:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009b56c:  96 06 7f 13  add  %i1, -237, %o3
a009b570:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009b574:  f2 0e a0 55  ldub  [ %i2 + 0x55 ], %i1	! 0xa8025c55
a009b578:  b0 10 20 01  mov  1, %i0
a009b57c:  80 a2 c0 19  cmp  %o3, %i1
a009b580:  02 80 00 04  be  0xa009b590
a009b584:  b4 10 20 00  clr  %i2
a009b588:  b0 10 20 01  mov  1, %i0
a009b58c:  b4 10 20 01  mov  1, %i2
a009b590:  40 00 32 eb  call  0xa00a813c
a009b594:  81 e8 00 00  restore
a009b598:  01 00 00 00  nop
