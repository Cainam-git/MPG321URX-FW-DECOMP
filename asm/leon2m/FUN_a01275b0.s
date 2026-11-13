# leon2m FUN_a01275b0 0xa01275b0-0xa0127724 (372 bytes)
a01275b0:  9d e3 bf 90  save  %sp, -112, %sp
a01275b4:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a01275b8:  a2 15 60 90  or  %l5, 0x90, %l1	! 0xa802d890
a01275bc:  f0 2c 60 01  stb  %i0, [ %l1 + 1 ]
a01275c0:  7f ff f4 c2  call  0xa01248c8
a01275c4:  c0 2d 60 90  clrb  [ %l5 + 0x90 ]
a01275c8:  80 8a 20 ff  btst  0xff, %o0
a01275cc:  02 80 00 54  be  0xa012771c
a01275d0:  15 00 06 92  sethi  %hi(0x1a4800), %o2
a01275d4:  92 0e 20 ff  and  %i0, 0xff, %o1
a01275d8:  7f fe de e6  call  0xa00df170
a01275dc:  90 12 a1 88  or  %o2, 0x188, %o0
a01275e0:  82 10 20 01  mov  1, %g1
a01275e4:  a4 10 20 02  mov  2, %l2
a01275e8:  c2 23 a0 60  st  %g1, [ %sp + 0x60 ]
a01275ec:  9a 10 00 11  mov  %l1, %o5
a01275f0:  92 10 20 02  mov  2, %o1
a01275f4:  94 10 21 c6  mov  0x1c6, %o2
a01275f8:  96 10 20 05  mov  5, %o3
a01275fc:  98 10 20 00  clr  %o4
a0127600:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0127604:  40 00 81 27  call  0xa0147aa0
a0127608:  90 10 20 60  mov  0x60, %o0
a012760c:  67 fd 96 e5  call  0x4008d1a0
a0127610:  90 10 20 32  mov  0x32, %o0
a0127614:  2d 2a 00 b6  sethi  %hi(0xa802d800), %l6
a0127618:  96 10 20 05  mov  5, %o3
a012761c:  98 10 20 00  clr  %o4
a0127620:  9a 15 a0 88  or  %l6, 0x88, %o5
a0127624:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0127628:  92 10 20 02  mov  2, %o1
a012762c:  94 10 21 c6  mov  0x1c6, %o2
a0127630:  40 00 81 2e  call  0xa0147ae8
a0127634:  90 10 20 60  mov  0x60, %o0
a0127638:  a0 15 a0 88  or  %l6, 0x88, %l0
a012763c:  11 00 06 92  sethi  %hi(0x1a4800), %o0
a0127640:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a0127644:  d2 0d a0 88  ldub  [ %l6 + 0x88 ], %o1
a0127648:  7f fe de ca  call  0xa00df170
a012764c:  90 12 21 b0  or  %o0, 0x1b0, %o0
a0127650:  a4 10 00 11  mov  %l1, %l2
a0127654:  90 10 20 32  mov  0x32, %o0
a0127658:  67 fd 96 d2  call  0x4008d1a0
a012765c:  a2 10 00 10  mov  %l0, %l1
a0127660:  a8 10 00 15  mov  %l5, %l4
a0127664:  a6 10 00 16  mov  %l6, %l3
a0127668:  10 80 00 1f  b  0xa01276e4
a012766c:  a0 10 20 02  mov  2, %l0
a0127670:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0127674:  80 a2 e0 09  cmp  %o3, 9
a0127678:  18 80 00 29  bgu  0xa012771c
a012767c:  d2 0d 20 90  ldub  [ %l4 + 0x90 ], %o1
a0127680:  7f fe de bc  call  0xa00df170
a0127684:  d6 0c e0 88  ldub  [ %l3 + 0x88 ], %o3
a0127688:  98 10 20 01  mov  1, %o4
a012768c:  d8 23 a0 60  st  %o4, [ %sp + 0x60 ]
a0127690:  92 10 20 02  mov  2, %o1
a0127694:  94 10 21 c6  mov  0x1c6, %o2
a0127698:  96 10 20 05  mov  5, %o3
a012769c:  98 10 20 00  clr  %o4
a01276a0:  9a 10 00 12  mov  %l2, %o5
a01276a4:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a01276a8:  40 00 80 fe  call  0xa0147aa0
a01276ac:  90 10 20 60  mov  0x60, %o0
a01276b0:  67 fd 96 bc  call  0x4008d1a0
a01276b4:  90 10 20 05  mov  5, %o0
a01276b8:  92 10 20 02  mov  2, %o1
a01276bc:  96 10 20 05  mov  5, %o3
a01276c0:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a01276c4:  90 10 20 60  mov  0x60, %o0
a01276c8:  94 10 21 c6  mov  0x1c6, %o2
a01276cc:  98 10 20 00  clr  %o4
a01276d0:  40 00 81 06  call  0xa0147ae8
a01276d4:  9a 10 00 11  mov  %l1, %o5
a01276d8:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a01276dc:  92 02 e0 01  add  %o3, 1, %o1
a01276e0:  d2 2e 21 fd  stb  %o1, [ %i0 + 0x1fd ]
a01276e4:  31 00 06 92  sethi  %hi(0x1a4800), %i0
a01276e8:  da 0c a0 01  ldub  [ %l2 + 1 ], %o5
a01276ec:  de 0c 60 01  ldub  [ %l1 + 1 ], %o7
a01276f0:  90 16 21 e0  or  %i0, 0x1e0, %o0
a01276f4:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a01276f8:  94 10 00 0d  mov  %o5, %o2
a01276fc:  80 a3 40 0f  cmp  %o5, %o7
a0127700:  12 bf ff dc  bne  0xa0127670
a0127704:  98 10 00 0f  mov  %o7, %o4
a0127708:  d2 0d 60 90  ldub  [ %l5 + 0x90 ], %o1
a012770c:  c2 0d a0 88  ldub  [ %l6 + 0x88 ], %g1
a0127710:  80 a2 40 01  cmp  %o1, %g1
a0127714:  12 bf ff d8  bne  0xa0127674
a0127718:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a012771c:  81 c7 e0 08  ret
a0127720:  81 e8 00 00  restore
