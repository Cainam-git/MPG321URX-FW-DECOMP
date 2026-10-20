# leon2m FUN_a00bd59c 0xa00bd59c-0xa00bd6e4 (328 bytes)
a00bd59c:  9d e3 bf 98  save  %sp, -104, %sp
a00bd5a0:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00bd5a4:  da 08 60 1c  ldub  [ %g1 + 0x1c ], %o5	! 0xa802d41c
a00bd5a8:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bd5ac:  82 03 60 26  add  %o5, 0x26, %g1
a00bd5b0:  98 16 a0 78  or  %i2, 0x78, %o4
a00bd5b4:  96 10 20 30  mov  0x30, %o3
a00bd5b8:  80 a3 60 09  cmp  %o5, 9
a00bd5bc:  d6 2b 20 07  stb  %o3, [ %o4 + 7 ]
a00bd5c0:  08 80 00 37  bleu  0xa00bd69c
a00bd5c4:  9a 03 60 30  add  %o5, 0x30, %o5
a00bd5c8:  90 10 20 31  mov  0x31, %o0
a00bd5cc:  c2 2b 20 09  stb  %g1, [ %o4 + 9 ]
a00bd5d0:  d0 2b 20 08  stb  %o0, [ %o4 + 8 ]
a00bd5d4:  92 10 20 00  clr  %o1
a00bd5d8:  40 02 5c 19  call  0xa015463c
a00bd5dc:  90 10 20 2a  mov  0x2a, %o0
a00bd5e0:  a0 16 a0 78  or  %i2, 0x78, %l0
a00bd5e4:  94 10 20 62  mov  0x62, %o2
a00bd5e8:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bd5ec:  d4 2c 20 01  stb  %o2, [ %l0 + 1 ]
a00bd5f0:  92 10 20 02  mov  2, %o1
a00bd5f4:  40 02 5c 12  call  0xa015463c
a00bd5f8:  90 10 20 2a  mov  0x2a, %o0
a00bd5fc:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bd600:  92 10 20 03  mov  3, %o1
a00bd604:  40 02 5c 0e  call  0xa015463c
a00bd608:  90 10 20 2a  mov  0x2a, %o0
a00bd60c:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bd610:  92 10 20 04  mov  4, %o1
a00bd614:  40 02 5c 0a  call  0xa015463c
a00bd618:  90 10 20 2a  mov  0x2a, %o0
a00bd61c:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bd620:  92 10 20 05  mov  5, %o1
a00bd624:  40 02 5c 06  call  0xa015463c
a00bd628:  90 10 20 2a  mov  0x2a, %o0
a00bd62c:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bd630:  92 10 20 06  mov  6, %o1
a00bd634:  40 02 5c 02  call  0xa015463c
a00bd638:  90 10 20 2a  mov  0x2a, %o0
a00bd63c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bd640:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bd644:  92 10 20 0d  mov  0xd, %o1
a00bd648:  9a 13 20 40  or  %o4, 0x40, %o5
a00bd64c:  d2 2c 20 0a  stb  %o1, [ %l0 + 0xa ]
a00bd650:  80 a6 20 02  cmp  %i0, 2
a00bd654:  02 80 00 15  be  0xa00bd6a8
a00bd658:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bd65c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bd660:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bd664:  96 12 a0 98  or  %o2, 0x98, %o3
a00bd668:  80 a6 20 03  cmp  %i0, 3
a00bd66c:  02 80 00 13  be  0xa00bd6b8
a00bd670:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bd674:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bd678:  c0 2b e0 9c  clrb  [ %o7 + 0x9c ]	! 0xa802b09c
a00bd67c:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bd680:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bd684:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bd688:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bd68c:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bd690:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bd694:  40 02 2c 55  call  0xa01487e8
a00bd698:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd69c:  da 2b 20 09  stb  %o5, [ %o4 + 9 ]
a00bd6a0:  10 bf ff cd  b  0xa00bd5d4
a00bd6a4:  d6 2b 20 08  stb  %o3, [ %o4 + 8 ]
a00bd6a8:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00bd6ac:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00bd6b0:  10 bf ff f4  b  0xa00bd680
a00bd6b4:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bd6b8:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00bd6bc:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]	! 0xa802b098
a00bd6c0:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bd6c4:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bd6c8:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bd6cc:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bd6d0:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bd6d4:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bd6d8:  40 02 2c 44  call  0xa01487e8
a00bd6dc:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd6e0:  01 00 00 00  nop
