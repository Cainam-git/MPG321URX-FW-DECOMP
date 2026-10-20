# leon2m FUN_a00bf538 0xa00bf538-0xa00bf6b0 (376 bytes)
a00bf538:  9d e3 bf 98  save  %sp, -104, %sp
a00bf53c:  40 00 65 7f  call  0xa00d8b38
a00bf540:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bf544:  13 14 7a e1  sethi  %hi(0x51eb8400), %o1
a00bf548:  b2 0a 20 ff  and  %o0, 0xff, %i1
a00bf54c:  82 12 61 1f  or  %o1, 0x11f, %g1
a00bf550:  80 56 40 01  umul  %i1, %g1, %g0
a00bf554:  97 40 00 00  rd  %y, %o3
a00bf558:  b3 32 e0 05  srl  %o3, 5, %i1
a00bf55c:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00bf560:  a0 5e a0 64  smul  %i2, 0x64, %l0
a00bf564:  b4 22 00 10  sub  %o0, %l0, %i2
a00bf568:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a00bf56c:  94 0e a0 ff  and  %i2, 0xff, %o2
a00bf570:  9e 13 20 cd  or  %o4, 0xcd, %o7
a00bf574:  80 52 80 0f  umul  %o2, %o7, %g0
a00bf578:  9b 40 00 00  rd  %y, %o5
a00bf57c:  9f 33 60 03  srl  %o5, 3, %o7
a00bf580:  92 0b e0 ff  and  %o7, 0xff, %o1
a00bf584:  83 2a 60 02  sll  %o1, 2, %g1
a00bf588:  a0 00 40 09  add  %g1, %o1, %l0
a00bf58c:  98 04 00 10  add  %l0, %l0, %o4
a00bf590:  94 26 80 0c  sub  %i2, %o4, %o2
a00bf594:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bf598:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bf59c:  92 02 a0 30  add  %o2, 0x30, %o1
a00bf5a0:  9a 03 e0 30  add  %o7, 0x30, %o5
a00bf5a4:  96 06 60 30  add  %i1, 0x30, %o3
a00bf5a8:  d2 2c 20 09  stb  %o1, [ %l0 + 9 ]
a00bf5ac:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a00bf5b0:  d6 2c 20 07  stb  %o3, [ %l0 + 7 ]
a00bf5b4:  92 10 20 00  clr  %o1
a00bf5b8:  40 02 54 21  call  0xa015463c
a00bf5bc:  90 10 20 32  mov  0x32, %o0
a00bf5c0:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bf5c4:  90 10 20 62  mov  0x62, %o0
a00bf5c8:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bf5cc:  92 10 20 02  mov  2, %o1
a00bf5d0:  40 02 54 1b  call  0xa015463c
a00bf5d4:  90 10 20 32  mov  0x32, %o0
a00bf5d8:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bf5dc:  92 10 20 03  mov  3, %o1
a00bf5e0:  40 02 54 17  call  0xa015463c
a00bf5e4:  90 10 20 32  mov  0x32, %o0
a00bf5e8:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bf5ec:  92 10 20 04  mov  4, %o1
a00bf5f0:  40 02 54 13  call  0xa015463c
a00bf5f4:  90 10 20 32  mov  0x32, %o0
a00bf5f8:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bf5fc:  92 10 20 05  mov  5, %o1
a00bf600:  40 02 54 0f  call  0xa015463c
a00bf604:  90 10 20 32  mov  0x32, %o0
a00bf608:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bf60c:  92 10 20 06  mov  6, %o1
a00bf610:  40 02 54 0b  call  0xa015463c
a00bf614:  90 10 20 32  mov  0x32, %o0
a00bf618:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bf61c:  82 10 20 0d  mov  0xd, %g1
a00bf620:  9a 13 20 40  or  %o4, 0x40, %o5
a00bf624:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00bf628:  80 a6 20 02  cmp  %i0, 2
a00bf62c:  02 80 00 12  be  0xa00bf674
a00bf630:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bf634:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bf638:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bf63c:  96 12 a0 98  or  %o2, 0x98, %o3
a00bf640:  80 a6 20 03  cmp  %i0, 3
a00bf644:  02 80 00 10  be  0xa00bf684
a00bf648:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bf64c:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00bf650:  c0 2a a0 9c  clrb  [ %o2 + 0x9c ]	! 0xa802b09c
a00bf654:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bf658:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bf65c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bf660:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bf664:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bf668:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bf66c:  40 02 24 5f  call  0xa01487e8
a00bf670:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bf674:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00bf678:  c0 2a 20 9a  clrb  [ %o0 + 0x9a ]	! 0xa802b09a
a00bf67c:  10 bf ff f7  b  0xa00bf658
a00bf680:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bf684:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00bf688:  c0 2b 60 98  clrb  [ %o5 + 0x98 ]	! 0xa802b098
a00bf68c:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bf690:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bf694:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bf698:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bf69c:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bf6a0:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bf6a4:  40 02 24 51  call  0xa01487e8
a00bf6a8:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bf6ac:  01 00 00 00  nop
