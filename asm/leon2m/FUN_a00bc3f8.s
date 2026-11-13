# leon2m FUN_a00bc3f8 0xa00bc3f8-0xa00bc574 (380 bytes)
a00bc3f8:  9d e3 bf 98  save  %sp, -104, %sp
a00bc3fc:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bc400:  d4 0b 62 a2  ldub  [ %o5 + 0x2a2 ], %o2	! 0xa802d2a2
a00bc404:  11 14 7a e1  sethi  %hi(0x51eb8400), %o0
a00bc408:  b2 0a a0 ff  and  %o2, 0xff, %i1
a00bc40c:  82 12 21 1f  or  %o0, 0x11f, %g1
a00bc410:  80 56 40 01  umul  %i1, %g1, %g0
a00bc414:  97 40 00 00  rd  %y, %o3
a00bc418:  b3 32 e0 05  srl  %o3, 5, %i1
a00bc41c:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00bc420:  a0 5e a0 64  smul  %i2, 0x64, %l0
a00bc424:  b4 22 80 10  sub  %o2, %l0, %i2
a00bc428:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a00bc42c:  92 0e a0 ff  and  %i2, 0xff, %o1
a00bc430:  9e 13 20 cd  or  %o4, 0xcd, %o7
a00bc434:  80 52 40 0f  umul  %o1, %o7, %g0
a00bc438:  9b 40 00 00  rd  %y, %o5
a00bc43c:  9f 33 60 03  srl  %o5, 3, %o7
a00bc440:  90 0b e0 ff  and  %o7, 0xff, %o0
a00bc444:  83 2a 20 02  sll  %o0, 2, %g1
a00bc448:  a0 00 40 08  add  %g1, %o0, %l0
a00bc44c:  98 04 00 10  add  %l0, %l0, %o4
a00bc450:  92 26 80 0c  sub  %i2, %o4, %o1
a00bc454:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bc458:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bc45c:  9a 03 e0 30  add  %o7, 0x30, %o5
a00bc460:  94 02 60 30  add  %o1, 0x30, %o2
a00bc464:  96 06 60 30  add  %i1, 0x30, %o3
a00bc468:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a00bc46c:  d6 2c 20 07  stb  %o3, [ %l0 + 7 ]
a00bc470:  d4 2c 20 09  stb  %o2, [ %l0 + 9 ]
a00bc474:  92 10 20 00  clr  %o1
a00bc478:  40 02 60 71  call  0xa015463c
a00bc47c:  90 10 20 07  mov  7, %o0
a00bc480:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bc484:  90 10 20 62  mov  0x62, %o0
a00bc488:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bc48c:  92 10 20 02  mov  2, %o1
a00bc490:  40 02 60 6b  call  0xa015463c
a00bc494:  90 10 20 07  mov  7, %o0
a00bc498:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bc49c:  92 10 20 03  mov  3, %o1
a00bc4a0:  40 02 60 67  call  0xa015463c
a00bc4a4:  90 10 20 07  mov  7, %o0
a00bc4a8:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bc4ac:  92 10 20 04  mov  4, %o1
a00bc4b0:  40 02 60 63  call  0xa015463c
a00bc4b4:  90 10 20 07  mov  7, %o0
a00bc4b8:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bc4bc:  92 10 20 05  mov  5, %o1
a00bc4c0:  40 02 60 5f  call  0xa015463c
a00bc4c4:  90 10 20 07  mov  7, %o0
a00bc4c8:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bc4cc:  92 10 20 06  mov  6, %o1
a00bc4d0:  40 02 60 5b  call  0xa015463c
a00bc4d4:  90 10 20 07  mov  7, %o0
a00bc4d8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bc4dc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bc4e0:  82 10 20 0d  mov  0xd, %g1
a00bc4e4:  9a 13 20 40  or  %o4, 0x40, %o5
a00bc4e8:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00bc4ec:  80 a6 20 02  cmp  %i0, 2
a00bc4f0:  02 80 00 12  be  0xa00bc538
a00bc4f4:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bc4f8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bc4fc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bc500:  96 12 a0 98  or  %o2, 0x98, %o3
a00bc504:  80 a6 20 03  cmp  %i0, 3
a00bc508:  02 80 00 10  be  0xa00bc548
a00bc50c:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bc510:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00bc514:  c0 2a a0 9c  clrb  [ %o2 + 0x9c ]	! 0xa802b09c
a00bc518:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bc51c:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bc520:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bc524:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bc528:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bc52c:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bc530:  40 02 30 ae  call  0xa01487e8
a00bc534:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bc538:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00bc53c:  c0 2a 60 9a  clrb  [ %o1 + 0x9a ]	! 0xa802b09a
a00bc540:  10 bf ff f7  b  0xa00bc51c
a00bc544:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bc548:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bc54c:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00bc550:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bc554:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bc558:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bc55c:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bc560:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bc564:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bc568:  40 02 30 a0  call  0xa01487e8
a00bc56c:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bc570:  01 00 00 00  nop
