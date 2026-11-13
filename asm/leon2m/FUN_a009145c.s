# leon2m FUN_a009145c 0xa009145c-0xa0091648 (492 bytes)
a009145c:  9d e3 bf 98  save  %sp, -104, %sp
a0091460:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0091464:  d6 06 63 ec  ld  [ %i1 + 0x3ec ], %o3	! 0xa802afec
a0091468:  80 a2 e0 0a  cmp  %o3, 0xa
a009146c:  02 80 00 43  be  0xa0091578
a0091470:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0091474:  80 a2 e0 01  cmp  %o3, 1
a0091478:  02 80 00 29  be  0xa009151c
a009147c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a0091480:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a0091484:  90 02 7f fe  add  %o1, -2, %o0
a0091488:  40 00 5a 5e  call  0xa00a7e00
a009148c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091490:  03 0e 38 e3  sethi  %hi(0x38e38c00), %g1
a0091494:  b0 10 62 39  or  %g1, 0x239, %i0	! 0x38e38e39
a0091498:  de 16 63 ee  lduh  [ %i1 + 0x3ee ], %o7
a009149c:  90 03 ff ff  add  %o7, -1, %o0
a00914a0:  80 5a 00 18  smul  %o0, %i0, %g0
a00914a4:  97 40 00 00  rd  %y, %o3
a00914a8:  95 3a 20 1f  sra  %o0, 0x1f, %o2
a00914ac:  93 3a e0 01  sra  %o3, 1, %o1
a00914b0:  9a 22 40 0a  sub  %o1, %o2, %o5
a00914b4:  83 2b 60 03  sll  %o5, 3, %g1
a00914b8:  98 00 40 0d  add  %g1, %o5, %o4
a00914bc:  96 22 00 0c  sub  %o0, %o4, %o3
a00914c0:  9e 02 e0 02  add  %o3, 2, %o7
a00914c4:  de 26 63 ec  st  %o7, [ %i1 + 0x3ec ]
a00914c8:  40 00 64 06  call  0xa00aa4e0
a00914cc:  90 0a e0 ff  and  %o3, 0xff, %o0
a00914d0:  94 0a 20 ff  and  %o0, 0xff, %o2
a00914d4:  80 a2 a0 01  cmp  %o2, 1
a00914d8:  12 bf ff f1  bne  0xa009149c
a00914dc:  de 16 63 ee  lduh  [ %i1 + 0x3ee ], %o7
a00914e0:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1
a00914e4:  80 a0 60 09  cmp  %g1, 9
a00914e8:  02 80 00 2a  be  0xa0091590
a00914ec:  80 a0 60 02  cmp  %g1, 2
a00914f0:  02 80 00 38  be  0xa00915d0
a00914f4:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a00914f8:  90 03 3f fe  add  %o4, -2, %o0
a00914fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091500:  40 00 8b 11  call  0xa00b4144
a0091504:  92 10 20 01  mov  1, %o1
a0091508:  f0 06 63 ec  ld  [ %i1 + 0x3ec ], %i0
a009150c:  b2 06 3f fe  add  %i0, -2, %i1
a0091510:  b0 0e 60 ff  and  %i1, 0xff, %i0
a0091514:  40 00 7a c8  call  0xa00b0034
a0091518:  81 e8 00 00  restore
a009151c:  d2 02 a2 90  ld  [ %o2 + 0x290 ], %o1
a0091520:  11 00 00 10  sethi  %hi(0x4000), %o0
a0091524:  80 8a 40 08  btst  %o1, %o0
a0091528:  02 bf ff d7  be  0xa0091484
a009152c:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a0091530:  98 10 20 02  mov  2, %o4
a0091534:  d8 26 63 ec  st  %o4, [ %i1 + 0x3ec ]
a0091538:  96 10 27 92  mov  0x792, %o3
a009153c:  90 10 20 01  mov  1, %o0
a0091540:  92 10 20 04  mov  4, %o1
a0091544:  94 10 20 01  mov  1, %o2
a0091548:  40 02 d5 4e  call  0xa0146a80
a009154c:  98 10 20 00  clr  %o4
a0091550:  da 06 63 ec  ld  [ %i1 + 0x3ec ], %o5
a0091554:  9e 03 7f fe  add  %o5, -2, %o7
a0091558:  90 0b e0 ff  and  %o7, 0xff, %o0
a009155c:  40 00 7a b6  call  0xa00b0034
a0091560:  01 00 00 00  nop
a0091564:  d6 06 63 ec  ld  [ %i1 + 0x3ec ], %o3
a0091568:  b0 02 ff fe  add  %o3, -2, %i0
a009156c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0091570:  40 00 8a f5  call  0xa00b4144
a0091574:  93 e8 20 01  restore  %g0, 1, %o1
a0091578:  d8 00 62 90  ld  [ %g1 + 0x290 ], %o4
a009157c:  1b 00 00 10  sethi  %hi(0x4000), %o5
a0091580:  80 8b 00 0d  btst  %o4, %o5
a0091584:  02 bf ff bd  be  0xa0091478
a0091588:  80 a2 e0 01  cmp  %o3, 1
a009158c:  30 80 00 19  b,a   0xa00915f0
a0091590:  40 00 66 bc  call  0xa00ab080
a0091594:  01 00 00 00  nop
a0091598:  40 00 59 55  call  0xa00a7aec
a009159c:  90 10 20 01  mov  1, %o0	! 0x1
a00915a0:  40 00 89 dd  call  0xa00b3d14
a00915a4:  90 10 20 01  mov  1, %o0
a00915a8:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a00915ac:  90 03 3f fe  add  %o4, -2, %o0
a00915b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00915b4:  40 00 8a e4  call  0xa00b4144
a00915b8:  92 10 20 01  mov  1, %o1
a00915bc:  f0 06 63 ec  ld  [ %i1 + 0x3ec ], %i0
a00915c0:  b2 06 3f fe  add  %i0, -2, %i1
a00915c4:  b0 0e 60 ff  and  %i1, 0xff, %i0
a00915c8:  40 00 7a 9b  call  0xa00b0034
a00915cc:  81 e8 00 00  restore
a00915d0:  40 00 66 ac  call  0xa00ab080
a00915d4:  01 00 00 00  nop
a00915d8:  40 00 59 45  call  0xa00a7aec
a00915dc:  90 10 20 00  clr  %o0	! 0x0
a00915e0:  40 00 89 cd  call  0xa00b3d14
a00915e4:  90 10 20 00  clr  %o0
a00915e8:  10 bf ff f1  b  0xa00915ac
a00915ec:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a00915f0:  40 00 5a 04  call  0xa00a7e00
a00915f4:  90 10 20 08  mov  8, %o0
a00915f8:  40 00 66 a2  call  0xa00ab080
a00915fc:  01 00 00 00  nop
a0091600:  40 00 59 3b  call  0xa00a7aec
a0091604:  90 10 20 00  clr  %o0	! 0x0
a0091608:  40 00 89 c3  call  0xa00b3d14
a009160c:  90 10 20 00  clr  %o0
a0091610:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a0091614:  9a 02 7f fe  add  %o1, -2, %o5
a0091618:  40 00 7a 87  call  0xa00b0034
a009161c:  90 0b 60 ff  and  %o5, 0xff, %o0
a0091620:  90 10 20 01  mov  1, %o0
a0091624:  92 10 20 04  mov  4, %o1
a0091628:  94 10 20 01  mov  1, %o2
a009162c:  96 10 25 92  mov  0x592, %o3
a0091630:  40 02 d5 14  call  0xa0146a80
a0091634:  98 10 20 00  clr  %o4
a0091638:  82 10 20 01  mov  1, %g1
a009163c:  c2 26 63 ec  st  %g1, [ %i1 + 0x3ec ]
a0091640:  81 c7 e0 08  ret
a0091644:  81 e8 00 00  restore
