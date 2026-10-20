# leon2m FUN_a012653c 0xa012653c-0xa01266b0 (372 bytes)
a012653c:  9d e3 bf 90  save  %sp, -112, %sp
a0126540:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a0126544:  a2 15 60 90  or  %l5, 0x90, %l1	! 0xa802d890
a0126548:  f0 2c 60 01  stb  %i0, [ %l1 + 1 ]
a012654c:  7f ff f8 df  call  0xa01248c8
a0126550:  c0 2d 60 90  clrb  [ %l5 + 0x90 ]
a0126554:  80 8a 20 ff  btst  0xff, %o0
a0126558:  02 80 00 54  be  0xa01266a8
a012655c:  15 00 06 91  sethi  %hi(0x1a4400), %o2
a0126560:  92 0e 20 ff  and  %i0, 0xff, %o1
a0126564:  7f fe e3 03  call  0xa00df170
a0126568:  90 12 a0 18  or  %o2, 0x18, %o0
a012656c:  82 10 20 01  mov  1, %g1
a0126570:  a4 10 20 02  mov  2, %l2
a0126574:  c2 23 a0 60  st  %g1, [ %sp + 0x60 ]
a0126578:  9a 10 00 11  mov  %l1, %o5
a012657c:  92 10 20 02  mov  2, %o1
a0126580:  94 10 20 1e  mov  0x1e, %o2
a0126584:  96 10 20 05  mov  5, %o3
a0126588:  98 10 20 00  clr  %o4
a012658c:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0126590:  40 00 85 44  call  0xa0147aa0
a0126594:  90 10 20 60  mov  0x60, %o0
a0126598:  67 fd 9b 02  call  0x4008d1a0
a012659c:  90 10 20 32  mov  0x32, %o0
a01265a0:  2d 2a 00 b6  sethi  %hi(0xa802d800), %l6
a01265a4:  96 10 20 05  mov  5, %o3
a01265a8:  98 10 20 00  clr  %o4
a01265ac:  9a 15 a0 88  or  %l6, 0x88, %o5
a01265b0:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a01265b4:  92 10 20 02  mov  2, %o1
a01265b8:  94 10 20 1e  mov  0x1e, %o2
a01265bc:  40 00 85 4b  call  0xa0147ae8
a01265c0:  90 10 20 60  mov  0x60, %o0
a01265c4:  a0 15 a0 88  or  %l6, 0x88, %l0
a01265c8:  11 00 06 91  sethi  %hi(0x1a4400), %o0
a01265cc:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a01265d0:  d2 0d a0 88  ldub  [ %l6 + 0x88 ], %o1
a01265d4:  7f fe e2 e7  call  0xa00df170
a01265d8:  90 12 20 40  or  %o0, 0x40, %o0
a01265dc:  a4 10 00 11  mov  %l1, %l2
a01265e0:  90 10 20 32  mov  0x32, %o0
a01265e4:  67 fd 9a ef  call  0x4008d1a0
a01265e8:  a2 10 00 10  mov  %l0, %l1
a01265ec:  a8 10 00 15  mov  %l5, %l4
a01265f0:  a6 10 00 16  mov  %l6, %l3
a01265f4:  10 80 00 1f  b  0xa0126670
a01265f8:  a0 10 20 02  mov  2, %l0
a01265fc:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0126600:  80 a2 e0 09  cmp  %o3, 9
a0126604:  18 80 00 29  bgu  0xa01266a8
a0126608:  d2 0d 20 90  ldub  [ %l4 + 0x90 ], %o1
a012660c:  7f fe e2 d9  call  0xa00df170
a0126610:  d6 0c e0 88  ldub  [ %l3 + 0x88 ], %o3
a0126614:  98 10 20 01  mov  1, %o4
a0126618:  d8 23 a0 60  st  %o4, [ %sp + 0x60 ]
a012661c:  92 10 20 02  mov  2, %o1
a0126620:  94 10 20 1e  mov  0x1e, %o2
a0126624:  96 10 20 05  mov  5, %o3
a0126628:  98 10 20 00  clr  %o4
a012662c:  9a 10 00 12  mov  %l2, %o5
a0126630:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a0126634:  40 00 85 1b  call  0xa0147aa0
a0126638:  90 10 20 60  mov  0x60, %o0
a012663c:  67 fd 9a d9  call  0x4008d1a0
a0126640:  90 10 20 32  mov  0x32, %o0
a0126644:  92 10 20 02  mov  2, %o1
a0126648:  96 10 20 05  mov  5, %o3
a012664c:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a0126650:  90 10 20 60  mov  0x60, %o0
a0126654:  94 10 20 1e  mov  0x1e, %o2
a0126658:  98 10 20 00  clr  %o4
a012665c:  40 00 85 23  call  0xa0147ae8
a0126660:  9a 10 00 11  mov  %l1, %o5
a0126664:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0126668:  92 02 e0 01  add  %o3, 1, %o1
a012666c:  d2 2e 21 fd  stb  %o1, [ %i0 + 0x1fd ]
a0126670:  31 00 06 91  sethi  %hi(0x1a4400), %i0
a0126674:  da 0c a0 01  ldub  [ %l2 + 1 ], %o5
a0126678:  de 0c 60 01  ldub  [ %l1 + 1 ], %o7
a012667c:  90 16 20 68  or  %i0, 0x68, %o0
a0126680:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a0126684:  94 10 00 0d  mov  %o5, %o2
a0126688:  80 a3 40 0f  cmp  %o5, %o7
a012668c:  12 bf ff dc  bne  0xa01265fc
a0126690:  98 10 00 0f  mov  %o7, %o4
a0126694:  d2 0d 60 90  ldub  [ %l5 + 0x90 ], %o1
a0126698:  c2 0d a0 88  ldub  [ %l6 + 0x88 ], %g1
a012669c:  80 a2 40 01  cmp  %o1, %g1
a01266a0:  12 bf ff d8  bne  0xa0126600
a01266a4:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a01266a8:  81 c7 e0 08  ret
a01266ac:  81 e8 00 00  restore
