# leon2m FUN_a00bc574 0xa00bc574-0xa00bc6f0 (380 bytes)
a00bc574:  9d e3 bf 98  save  %sp, -104, %sp
a00bc578:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bc57c:  d4 0b 62 a3  ldub  [ %o5 + 0x2a3 ], %o2	! 0xa802d2a3
a00bc580:  11 14 7a e1  sethi  %hi(0x51eb8400), %o0
a00bc584:  b2 0a a0 ff  and  %o2, 0xff, %i1
a00bc588:  82 12 21 1f  or  %o0, 0x11f, %g1
a00bc58c:  80 56 40 01  umul  %i1, %g1, %g0
a00bc590:  97 40 00 00  rd  %y, %o3
a00bc594:  b3 32 e0 05  srl  %o3, 5, %i1
a00bc598:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00bc59c:  a0 5e a0 64  smul  %i2, 0x64, %l0
a00bc5a0:  b4 22 80 10  sub  %o2, %l0, %i2
a00bc5a4:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a00bc5a8:  92 0e a0 ff  and  %i2, 0xff, %o1
a00bc5ac:  9e 13 20 cd  or  %o4, 0xcd, %o7
a00bc5b0:  80 52 40 0f  umul  %o1, %o7, %g0
a00bc5b4:  9b 40 00 00  rd  %y, %o5
a00bc5b8:  9f 33 60 03  srl  %o5, 3, %o7
a00bc5bc:  90 0b e0 ff  and  %o7, 0xff, %o0
a00bc5c0:  83 2a 20 02  sll  %o0, 2, %g1
a00bc5c4:  a0 00 40 08  add  %g1, %o0, %l0
a00bc5c8:  98 04 00 10  add  %l0, %l0, %o4
a00bc5cc:  92 26 80 0c  sub  %i2, %o4, %o1
a00bc5d0:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bc5d4:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bc5d8:  9a 03 e0 30  add  %o7, 0x30, %o5
a00bc5dc:  94 02 60 30  add  %o1, 0x30, %o2
a00bc5e0:  96 06 60 30  add  %i1, 0x30, %o3
a00bc5e4:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a00bc5e8:  d6 2c 20 07  stb  %o3, [ %l0 + 7 ]
a00bc5ec:  d4 2c 20 09  stb  %o2, [ %l0 + 9 ]
a00bc5f0:  92 10 20 00  clr  %o1
a00bc5f4:  40 02 60 12  call  0xa015463c
a00bc5f8:  90 10 20 08  mov  8, %o0
a00bc5fc:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bc600:  90 10 20 62  mov  0x62, %o0
a00bc604:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bc608:  92 10 20 02  mov  2, %o1
a00bc60c:  40 02 60 0c  call  0xa015463c
a00bc610:  90 10 20 08  mov  8, %o0
a00bc614:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bc618:  92 10 20 03  mov  3, %o1
a00bc61c:  40 02 60 08  call  0xa015463c
a00bc620:  90 10 20 08  mov  8, %o0
a00bc624:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bc628:  92 10 20 04  mov  4, %o1
a00bc62c:  40 02 60 04  call  0xa015463c
a00bc630:  90 10 20 08  mov  8, %o0
a00bc634:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bc638:  92 10 20 05  mov  5, %o1
a00bc63c:  40 02 60 00  call  0xa015463c
a00bc640:  90 10 20 08  mov  8, %o0
a00bc644:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bc648:  92 10 20 06  mov  6, %o1
a00bc64c:  40 02 5f fc  call  0xa015463c
a00bc650:  90 10 20 08  mov  8, %o0
a00bc654:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bc658:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bc65c:  82 10 20 0d  mov  0xd, %g1
a00bc660:  9a 13 20 40  or  %o4, 0x40, %o5
a00bc664:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00bc668:  80 a6 20 02  cmp  %i0, 2
a00bc66c:  02 80 00 12  be  0xa00bc6b4
a00bc670:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bc674:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bc678:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bc67c:  96 12 a0 98  or  %o2, 0x98, %o3
a00bc680:  80 a6 20 03  cmp  %i0, 3
a00bc684:  02 80 00 10  be  0xa00bc6c4
a00bc688:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bc68c:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00bc690:  c0 2a a0 9c  clrb  [ %o2 + 0x9c ]	! 0xa802b09c
a00bc694:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bc698:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bc69c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bc6a0:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bc6a4:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bc6a8:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bc6ac:  40 02 30 4f  call  0xa01487e8
a00bc6b0:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bc6b4:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00bc6b8:  c0 2a 60 9a  clrb  [ %o1 + 0x9a ]	! 0xa802b09a
a00bc6bc:  10 bf ff f7  b  0xa00bc698
a00bc6c0:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bc6c4:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bc6c8:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00bc6cc:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bc6d0:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bc6d4:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bc6d8:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bc6dc:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bc6e0:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bc6e4:  40 02 30 41  call  0xa01487e8
a00bc6e8:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bc6ec:  01 00 00 00  nop
