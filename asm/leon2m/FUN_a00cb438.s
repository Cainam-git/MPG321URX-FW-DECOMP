# leon2m FUN_a00cb438 0xa00cb438-0xa00cb618 (480 bytes)
a00cb438:  9d e3 bf 98  save  %sp, -104, %sp
a00cb43c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00cb440:  80 a4 20 02  cmp  %l0, 2
a00cb444:  02 80 00 53  be  0xa00cb590
a00cb448:  80 a4 20 03  cmp  %l0, 3
a00cb44c:  02 80 00 54  be  0xa00cb59c
a00cb450:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cb454:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00cb458:  9a 08 60 ff  and  %g1, 0xff, %o5
a00cb45c:  96 03 7f d0  add  %o5, -48, %o3
a00cb460:  94 0a e0 ff  and  %o3, 0xff, %o2
a00cb464:  80 a2 a0 02  cmp  %o2, 2
a00cb468:  18 80 00 6a  bgu  0xa00cb610
a00cb46c:  b0 10 20 ff  mov  0xff, %i0
a00cb470:  9a 03 7f d1  add  %o5, -47, %o5
a00cb474:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a00cb478:  40 00 3d d4  call  0xa00dabc8
a00cb47c:  da 2b 20 7b  stb  %o5, [ %o4 + 0x7b ]	! 0xa802d47b
a00cb480:  7f ff b5 13  call  0xa00b88cc
a00cb484:  01 00 00 00  nop
a00cb488:  80 a4 20 02  cmp  %l0, 2
a00cb48c:  02 80 00 24  be  0xa00cb51c
a00cb490:  80 a4 20 03  cmp  %l0, 3
a00cb494:  02 80 00 45  be  0xa00cb5a8
a00cb498:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cb49c:  94 12 e0 78  or  %o3, 0x78, %o2	! 0xa802d078
a00cb4a0:  90 10 20 30  mov  0x30, %o0
a00cb4a4:  9a 10 20 35  mov  0x35, %o5
a00cb4a8:  9e 10 20 36  mov  0x36, %o7
a00cb4ac:  98 10 20 2b  mov  0x2b, %o4
a00cb4b0:  92 10 20 0d  mov  0xd, %o1
a00cb4b4:  da 2a e0 78  stb  %o5, [ %o3 + 0x78 ]
a00cb4b8:  de 2a a0 01  stb  %o7, [ %o2 + 1 ]
a00cb4bc:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00cb4c0:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00cb4c4:  d2 2a a0 05  stb  %o1, [ %o2 + 5 ]
a00cb4c8:  80 a4 20 02  cmp  %l0, 2
a00cb4cc:  02 80 00 21  be  0xa00cb550
a00cb4d0:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00cb4d4:  80 a4 20 03  cmp  %l0, 3
a00cb4d8:  02 80 00 41  be  0xa00cb5dc
a00cb4dc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cb4e0:  9e 13 20 d0  or  %o4, 0xd0, %o7	! 0xa802d0d0
a00cb4e4:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00cb4e8:  c0 2a e0 9c  clrb  [ %o3 + 0x9c ]	! 0xa802b09c
a00cb4ec:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00cb4f0:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00cb4f4:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00cb4f8:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00cb4fc:  80 a4 20 02  cmp  %l0, 2
a00cb500:  02 80 00 1d  be  0xa00cb574
a00cb504:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00cb508:  80 a4 20 03  cmp  %l0, 3
a00cb50c:  12 80 00 1d  bne  0xa00cb580
a00cb510:  90 10 00 10  mov  %l0, %o0
a00cb514:  10 80 00 3c  b  0xa00cb604
a00cb518:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cb51c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cb520:  9e 12 61 28  or  %o1, 0x128, %o7	! 0xa802d128
a00cb524:  a0 10 20 30  mov  0x30, %l0
a00cb528:  94 10 20 35  mov  0x35, %o2
a00cb52c:  90 10 20 0d  mov  0xd, %o0
a00cb530:  82 10 20 36  mov  0x36, %g1
a00cb534:  b0 10 20 2b  mov  0x2b, %i0
a00cb538:  d4 2a 61 28  stb  %o2, [ %o1 + 0x128 ]
a00cb53c:  d0 2b e0 05  stb  %o0, [ %o7 + 5 ]
a00cb540:  c2 2b e0 01  stb  %g1, [ %o7 + 1 ]
a00cb544:  e0 2b e0 03  stb  %l0, [ %o7 + 3 ]
a00cb548:  f0 2b e0 04  stb  %i0, [ %o7 + 4 ]
a00cb54c:  e0 2b e0 02  stb  %l0, [ %o7 + 2 ]
a00cb550:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00cb554:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00cb558:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00cb55c:  c0 2e 20 9a  clrb  [ %i0 + 0x9a ]	! 0xa802b09a
a00cb560:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00cb564:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00cb568:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00cb56c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00cb570:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00cb574:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00cb578:  94 13 61 28  or  %o5, 0x128, %o2	! 0xa802d128
a00cb57c:  90 10 20 02  mov  2, %o0
a00cb580:  40 01 f4 9a  call  0xa01487e8
a00cb584:  92 10 20 06  mov  6, %o1
a00cb588:  10 80 00 22  b  0xa00cb610
a00cb58c:  b0 10 20 00  clr  %i0
a00cb590:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cb594:  10 bf ff b1  b  0xa00cb458
a00cb598:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00cb59c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cb5a0:  10 bf ff ae  b  0xa00cb458
a00cb5a4:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00cb5a8:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00cb5ac:  98 16 21 08  or  %i0, 0x108, %o4	! 0xa802d108
a00cb5b0:  9e 10 20 30  mov  0x30, %o7
a00cb5b4:  82 10 20 35  mov  0x35, %g1
a00cb5b8:  a0 10 20 0d  mov  0xd, %l0
a00cb5bc:  9a 10 20 36  mov  0x36, %o5
a00cb5c0:  96 10 20 2b  mov  0x2b, %o3
a00cb5c4:  c2 2e 21 08  stb  %g1, [ %i0 + 0x108 ]
a00cb5c8:  e0 2b 20 05  stb  %l0, [ %o4 + 5 ]
a00cb5cc:  da 2b 20 01  stb  %o5, [ %o4 + 1 ]
a00cb5d0:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00cb5d4:  d6 2b 20 04  stb  %o3, [ %o4 + 4 ]
a00cb5d8:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00cb5dc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cb5e0:  90 12 60 98  or  %o1, 0x98, %o0	! 0xa802d098
a00cb5e4:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00cb5e8:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00cb5ec:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]
a00cb5f0:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00cb5f4:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00cb5f8:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00cb5fc:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00cb600:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cb604:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00cb608:  10 bf ff de  b  0xa00cb580
a00cb60c:  90 10 20 03  mov  3, %o0
a00cb610:  81 c7 e0 08  ret
a00cb614:  81 e8 00 00  restore
