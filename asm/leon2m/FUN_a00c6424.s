# leon2m FUN_a00c6424 0xa00c6424-0xa00c6690 (620 bytes)
a00c6424:  9d e3 bf 98  save  %sp, -104, %sp
a00c6428:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c642c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c6430:  80 a4 20 02  cmp  %l0, 2
a00c6434:  02 80 00 08  be  0xa00c6454
a00c6438:  82 10 60 40  or  %g1, 0x40, %g1
a00c643c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c6440:  80 a4 20 03  cmp  %l0, 3
a00c6444:  02 80 00 04  be  0xa00c6454
a00c6448:  82 12 20 98  or  %o0, 0x98, %g1
a00c644c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c6450:  82 12 60 d0  or  %o1, 0xd0, %g1	! 0xa802d0d0
a00c6454:  de 08 60 07  ldub  [ %g1 + 7 ], %o7
a00c6458:  94 03 ff d0  add  %o7, -48, %o2
a00c645c:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00c6460:  d6 08 60 09  ldub  [ %g1 + 9 ], %o3
a00c6464:  d8 08 60 08  ldub  [ %g1 + 8 ], %o4
a00c6468:  80 a3 60 01  cmp  %o5, 1
a00c646c:  18 80 00 07  bgu  0xa00c6488
a00c6470:  92 10 20 ff  mov  0xff, %o1
a00c6474:  98 03 3f d0  add  %o4, -48, %o4
a00c6478:  b0 0b 20 ff  and  %o4, 0xff, %i0
a00c647c:  80 a6 20 09  cmp  %i0, 9
a00c6480:  28 80 00 3f  bleu,a   0xa00c657c
a00c6484:  96 02 ff d0  add  %o3, -48, %o3
a00c6488:  80 a2 60 ff  cmp  %o1, 0xff
a00c648c:  02 80 00 3a  be  0xa00c6574
a00c6490:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c6494:  98 13 62 90  or  %o5, 0x290, %o4	! 0xa802d290
a00c6498:  d4 03 20 b0  ld  [ %o4 + 0xb0 ], %o2
a00c649c:  80 a2 a0 00  cmp  %o2, 0
a00c64a0:  12 80 00 7a  bne  0xa00c6688
a00c64a4:  b0 10 20 ff  mov  0xff, %i0
a00c64a8:  de 03 21 1c  ld  [ %o4 + 0x11c ], %o7
a00c64ac:  80 a3 e0 00  cmp  %o7, 0
a00c64b0:  06 80 00 76  bl  0xa00c6688
a00c64b4:  80 a2 60 64  cmp  %o1, 0x64
a00c64b8:  18 80 00 74  bgu  0xa00c6688
a00c64bc:  01 00 00 00  nop
a00c64c0:  40 00 4a 05  call  0xa00d8cd4
a00c64c4:  d2 2b 20 09  stb  %o1, [ %o4 + 9 ]
a00c64c8:  40 00 39 34  call  0xa00d4998
a00c64cc:  01 00 00 00  nop
a00c64d0:  7f ff c8 ff  call  0xa00b88cc
a00c64d4:  01 00 00 00  nop
a00c64d8:  80 a4 20 02  cmp  %l0, 2
a00c64dc:  02 80 00 37  be  0xa00c65b8
a00c64e0:  80 a4 20 03  cmp  %l0, 3
a00c64e4:  02 80 00 52  be  0xa00c662c
a00c64e8:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c64ec:  94 13 60 78  or  %o5, 0x78, %o2	! 0xa802d078
a00c64f0:  b0 10 20 30  mov  0x30, %i0
a00c64f4:  98 10 20 35  mov  0x35, %o4
a00c64f8:  9e 10 20 36  mov  0x36, %o7
a00c64fc:  82 10 20 2b  mov  0x2b, %g1
a00c6500:  90 10 20 0d  mov  0xd, %o0
a00c6504:  d8 2b 60 78  stb  %o4, [ %o5 + 0x78 ]
a00c6508:  de 2a a0 01  stb  %o7, [ %o2 + 1 ]
a00c650c:  f0 2a a0 03  stb  %i0, [ %o2 + 3 ]
a00c6510:  c2 2a a0 04  stb  %g1, [ %o2 + 4 ]
a00c6514:  d0 2a a0 05  stb  %o0, [ %o2 + 5 ]
a00c6518:  80 a4 20 02  cmp  %l0, 2
a00c651c:  02 80 00 34  be  0xa00c65ec
a00c6520:  f0 2a a0 02  stb  %i0, [ %o2 + 2 ]
a00c6524:  80 a4 20 03  cmp  %l0, 3
a00c6528:  02 80 00 4e  be  0xa00c6660
a00c652c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c6530:  9e 13 60 d0  or  %o5, 0xd0, %o7	! 0xa802d0d0
a00c6534:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c6538:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]	! 0xa802b09c
a00c653c:  c0 2b 60 d0  clrb  [ %o5 + 0xd0 ]
a00c6540:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00c6544:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00c6548:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00c654c:  80 a4 20 02  cmp  %l0, 2
a00c6550:  02 80 00 30  be  0xa00c6610
a00c6554:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00c6558:  80 a4 20 03  cmp  %l0, 3
a00c655c:  12 80 00 30  bne  0xa00c661c
a00c6560:  90 10 00 10  mov  %l0, %o0
a00c6564:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c6568:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c656c:  10 80 00 2c  b  0xa00c661c
a00c6570:  90 10 20 03  mov  3, %o0
a00c6574:  10 80 00 45  b  0xa00c6688
a00c6578:  b0 10 20 ff  mov  0xff, %i0
a00c657c:  82 0a e0 ff  and  %o3, 0xff, %g1
a00c6580:  80 a0 60 09  cmp  %g1, 9
a00c6584:  18 bf ff c2  bgu  0xa00c648c
a00c6588:  80 a2 60 ff  cmp  %o1, 0xff
a00c658c:  90 0b 20 ff  and  %o4, 0xff, %o0
a00c6590:  83 2a 20 02  sll  %o0, 2, %g1
a00c6594:  9e 00 40 08  add  %g1, %o0, %o7
a00c6598:  b0 0a a0 ff  and  %o2, 0xff, %i0
a00c659c:  92 5e 20 64  smul  %i0, 0x64, %o1
a00c65a0:  9a 03 c0 0f  add  %o7, %o7, %o5
a00c65a4:  90 02 40 0d  add  %o1, %o5, %o0
a00c65a8:  98 0a e0 ff  and  %o3, 0xff, %o4
a00c65ac:  94 02 00 0c  add  %o0, %o4, %o2
a00c65b0:  10 bf ff b6  b  0xa00c6488
a00c65b4:  92 0a a0 ff  and  %o2, 0xff, %o1
a00c65b8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c65bc:  a0 12 21 28  or  %o0, 0x128, %l0	! 0xa802d128
a00c65c0:  98 10 20 30  mov  0x30, %o4
a00c65c4:  82 10 20 35  mov  0x35, %g1
a00c65c8:  b0 10 20 0d  mov  0xd, %i0
a00c65cc:  92 10 20 36  mov  0x36, %o1
a00c65d0:  96 10 20 2b  mov  0x2b, %o3
a00c65d4:  c2 2a 21 28  stb  %g1, [ %o0 + 0x128 ]
a00c65d8:  f0 2c 20 05  stb  %i0, [ %l0 + 5 ]
a00c65dc:  d2 2c 20 01  stb  %o1, [ %l0 + 1 ]
a00c65e0:  d8 2c 20 03  stb  %o4, [ %l0 + 3 ]
a00c65e4:  d6 2c 20 04  stb  %o3, [ %l0 + 4 ]
a00c65e8:  d8 2c 20 02  stb  %o4, [ %l0 + 2 ]
a00c65ec:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c65f0:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c65f4:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c65f8:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00c65fc:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c6600:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c6604:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c6608:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c660c:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c6610:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c6614:  94 13 21 28  or  %o4, 0x128, %o2	! 0xa802d128
a00c6618:  90 10 20 02  mov  2, %o0
a00c661c:  40 02 08 73  call  0xa01487e8
a00c6620:  92 10 20 06  mov  6, %o1
a00c6624:  10 80 00 19  b  0xa00c6688
a00c6628:  b0 10 20 00  clr  %i0
a00c662c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c6630:  9e 12 e1 08  or  %o3, 0x108, %o7	! 0xa802d108
a00c6634:  94 10 20 30  mov  0x30, %o2
a00c6638:  92 10 20 35  mov  0x35, %o1
a00c663c:  98 10 20 0d  mov  0xd, %o4
a00c6640:  a0 10 20 36  mov  0x36, %l0
a00c6644:  9a 10 20 2b  mov  0x2b, %o5
a00c6648:  d2 2a e1 08  stb  %o1, [ %o3 + 0x108 ]
a00c664c:  d8 2b e0 05  stb  %o4, [ %o7 + 5 ]
a00c6650:  e0 2b e0 01  stb  %l0, [ %o7 + 1 ]
a00c6654:  d4 2b e0 03  stb  %o2, [ %o7 + 3 ]
a00c6658:  da 2b e0 04  stb  %o5, [ %o7 + 4 ]
a00c665c:  d4 2b e0 02  stb  %o2, [ %o7 + 2 ]
a00c6660:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c6664:  92 16 20 98  or  %i0, 0x98, %o1	! 0xa802d098
a00c6668:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00c666c:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]	! 0xa802b098
a00c6670:  c0 2e 20 98  clrb  [ %i0 + 0x98 ]
a00c6674:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c6678:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c667c:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c6680:  10 bf ff b9  b  0xa00c6564
a00c6684:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c6688:  81 c7 e0 08  ret
a00c668c:  81 e8 00 00  restore
