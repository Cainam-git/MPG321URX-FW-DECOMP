# leon2m FUN_a009c590 0xa009c590-0xa009c67c (236 bytes)
a009c590:  9d e3 bf 98  save  %sp, -104, %sp
a009c594:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009c598:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009c59c:  90 02 7f 9c  add  %o1, -100, %o0
a009c5a0:  40 00 33 87  call  0xa00a93bc
a009c5a4:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c5a8:  03 19 99 99  sethi  %hi(0x66666400), %g1
a009c5ac:  b2 10 62 67  or  %g1, 0x267, %i1	! 0x66666667
a009c5b0:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009c5b4:  9e 02 3f 9d  add  %o0, -99, %o7
a009c5b8:  80 5b c0 19  smul  %o7, %i1, %g0
a009c5bc:  97 40 00 00  rd  %y, %o3
a009c5c0:  93 3a e0 01  sra  %o3, 1, %o1
a009c5c4:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009c5c8:  82 22 40 0a  sub  %o1, %o2, %g1
a009c5cc:  b1 28 60 02  sll  %g1, 2, %i0
a009c5d0:  98 06 00 01  add  %i0, %g1, %o4
a009c5d4:  96 23 c0 0c  sub  %o7, %o4, %o3
a009c5d8:  9a 02 e0 64  add  %o3, 0x64, %o5
a009c5dc:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009c5e0:  40 00 39 d4  call  0xa00aad30
a009c5e4:  90 0a e0 ff  and  %o3, 0xff, %o0
a009c5e8:  94 0a 20 ff  and  %o0, 0xff, %o2
a009c5ec:  80 a2 a0 01  cmp  %o2, 1
a009c5f0:  12 bf ff f1  bne  0xa009c5b4
a009c5f4:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009c5f8:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009c5fc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a009c600:  b0 13 22 90  or  %o4, 0x290, %i0	! 0xa802d290
a009c604:  b2 03 7f 9c  add  %o5, -100, %i1
a009c608:  d6 06 20 34  ld  [ %i0 + 0x34 ], %o3
a009c60c:  90 0e 60 0f  and  %i1, 0xf, %o0
a009c610:  1f 00 03 c0  sethi  %hi(0xf0000), %o7
a009c614:  92 2a c0 0f  andn  %o3, %o7, %o1
a009c618:  95 2a 20 10  sll  %o0, 0x10, %o2
a009c61c:  82 12 40 0a  or  %o1, %o2, %g1
a009c620:  40 00 e4 b6  call  0xa00d58f8
a009c624:  c2 26 20 34  st  %g1, [ %i0 + 0x34 ]
a009c628:  40 00 e4 ac  call  0xa00d58d8
a009c62c:  b0 10 20 01  mov  1, %i0
a009c630:  40 00 e0 da  call  0xa00d4998
a009c634:  01 00 00 00  nop
a009c638:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a009c63c:  9a 03 3f 9c  add  %o4, -100, %o5
a009c640:  90 0b 60 ff  and  %o5, 0xff, %o0
a009c644:  40 00 34 03  call  0xa00a9650
a009c648:  92 10 20 01  mov  1, %o1
a009c64c:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009c650:  9e 06 7f 9c  add  %i1, -100, %o7
a009c654:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009c658:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009c65c:  80 a3 c0 19  cmp  %o7, %i1
a009c660:  02 80 00 04  be  0xa009c670
a009c664:  b4 10 20 00  clr  %i2
a009c668:  b0 10 20 01  mov  1, %i0
a009c66c:  b4 10 20 01  mov  1, %i2
a009c670:  40 00 2e b3  call  0xa00a813c
a009c674:  81 e8 00 00  restore
a009c678:  01 00 00 00  nop
