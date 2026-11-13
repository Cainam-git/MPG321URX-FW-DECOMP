# leon2m FUN_a013358c 0xa013358c-0xa01337e8 (604 bytes)
a013358c:  9d e3 bf 78  save  %sp, -136, %sp
a0133590:  9a 10 20 00  clr  %o5
a0133594:  98 10 20 00  clr  %o4
a0133598:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a013359c:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a01335a0:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a01335a4:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a01335a8:  80 8e 20 80  btst  0x80, %i0
a01335ac:  a0 10 00 1b  mov  %i3, %l0
a01335b0:  aa 10 00 19  mov  %i1, %l5
a01335b4:  ac 10 00 1a  mov  %i2, %l6
a01335b8:  92 10 00 1c  mov  %i4, %o1
a01335bc:  a8 10 20 02  mov  2, %l4
a01335c0:  a2 10 20 10  mov  0x10, %l1
a01335c4:  12 80 00 84  bne  0xa01337d4
a01335c8:  9a 10 20 00  clr  %o5
a01335cc:  83 2a 60 10  sll  %o1, 0x10, %g1
a01335d0:  83 30 60 10  srl  %g1, 0x10, %g1
a01335d4:  80 a0 7f fe  cmp  %g1, -2
a01335d8:  02 80 00 82  be  0xa01337e0
a01335dc:  9e 10 20 00  clr  %o7
a01335e0:  a4 0e 20 ff  and  %i0, 0xff, %l2
a01335e4:  31 2a 00 b6  sethi  %hi(0xa802d800), %i0
a01335e8:  a6 16 22 6c  or  %i0, 0x26c, %l3	! 0xa802da6c
a01335ec:  b8 10 00 01  mov  %g1, %i4
a01335f0:  98 07 bf e8  add  %fp, -24, %o4
a01335f4:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a01335f8:  90 07 bf f8  add  %fp, -8, %o0
a01335fc:  b0 07 bf d8  add  %fp, -40, %i0
a0133600:  96 10 00 01  mov  %g1, %o3
a0133604:  bb 2b e0 10  sll  %o7, 0x10, %i5
a0133608:  bb 37 60 10  srl  %i5, 0x10, %i5
a013360c:  b4 27 00 1d  sub  %i4, %i5, %i2
a0133610:  b2 06 a0 02  add  %i2, 2, %i1
a0133614:  80 a6 60 0f  cmp  %i1, 0xf
a0133618:  14 80 00 05  bg  0xa013362c
a013361c:  80 a7 60 00  cmp  %i5, 0
a0133620:  b6 22 40 0f  sub  %o1, %o7, %i3
a0133624:  a2 06 e0 02  add  %i3, 2, %l1
a0133628:  a8 10 20 01  mov  1, %l4
a013362c:  12 80 00 29  bne  0xa01336d0
a0133630:  b4 07 40 10  add  %i5, %l0, %i2
a0133634:  b2 0c 60 ff  and  %l1, 0xff, %i1
a0133638:  b4 06 7f fe  add  %i1, -2, %i2
a013363c:  80 a7 40 1a  cmp  %i5, %i2
a0133640:  ea 2f bf d8  stb  %l5, [ %fp + -40 ]
a0133644:  ec 2f bf d9  stb  %l6, [ %fp + -39 ]
a0133648:  16 80 00 0a  bge  0xa0133670
a013364c:  b6 10 20 00  clr  %i3
a0133650:  b8 10 20 00  clr  %i4
a0133654:  fa 0f 00 10  ldub  [ %i4 + %l0 ], %i5
a0133658:  82 02 00 1c  add  %o0, %i4, %g1
a013365c:  b6 06 e0 01  inc  %i3
a0133660:  b8 0e e0 ff  and  %i3, 0xff, %i4
a0133664:  80 a7 00 1a  cmp  %i4, %i2
a0133668:  06 bf ff fb  bl  0xa0133654
a013366c:  fa 28 7f e2  stb  %i5, [ %g1 + -30 ]
a0133670:  b4 10 20 00  clr  %i2
a0133674:  ba 10 20 00  clr  %i5
a0133678:  b7 2f 60 02  sll  %i5, 2, %i3
a013367c:  c2 0e 00 1b  ldub  [ %i0 + %i3 ], %g1
a0133680:  c2 23 00 1b  st  %g1, [ %o4 + %i3 ]
a0133684:  b8 06 c0 18  add  %i3, %i0, %i4
a0133688:  fa 0f 20 01  ldub  [ %i4 + 1 ], %i5
a013368c:  83 28 60 08  sll  %g1, 8, %g1
a0133690:  82 00 40 1d  add  %g1, %i5, %g1
a0133694:  c2 23 00 1b  st  %g1, [ %o4 + %i3 ]
a0133698:  fa 0f 20 02  ldub  [ %i4 + 2 ], %i5
a013369c:  83 28 60 08  sll  %g1, 8, %g1
a01336a0:  82 00 40 1d  add  %g1, %i5, %g1
a01336a4:  c2 23 00 1b  st  %g1, [ %o4 + %i3 ]
a01336a8:  fa 0f 20 03  ldub  [ %i4 + 3 ], %i5
a01336ac:  83 28 60 08  sll  %g1, 8, %g1
a01336b0:  b8 00 40 1d  add  %g1, %i5, %i4
a01336b4:  b4 06 a0 01  inc  %i2
a01336b8:  ba 0e a0 ff  and  %i2, 0xff, %i5
a01336bc:  80 a7 60 04  cmp  %i5, 4
a01336c0:  0a bf ff ee  bcs  0xa0133678
a01336c4:  f8 23 00 1b  st  %i4, [ %o4 + %i3 ]
a01336c8:  10 80 00 1b  b  0xa0133734
a01336cc:  b9 2e 60 10  sll  %i1, 0x10, %i4
a01336d0:  b2 06 bf fe  add  %i2, -2, %i1
a01336d4:  b4 10 20 00  clr  %i2
a01336d8:  ba 10 20 00  clr  %i5
a01336dc:  b7 2f 60 02  sll  %i5, 2, %i3
a01336e0:  c2 0e 40 1b  ldub  [ %i1 + %i3 ], %g1
a01336e4:  c2 23 00 1b  st  %g1, [ %o4 + %i3 ]
a01336e8:  b8 06 c0 19  add  %i3, %i1, %i4
a01336ec:  fa 0f 20 01  ldub  [ %i4 + 1 ], %i5
a01336f0:  83 28 60 08  sll  %g1, 8, %g1
a01336f4:  82 00 40 1d  add  %g1, %i5, %g1
a01336f8:  c2 23 00 1b  st  %g1, [ %o4 + %i3 ]
a01336fc:  fa 0f 20 02  ldub  [ %i4 + 2 ], %i5
a0133700:  83 28 60 08  sll  %g1, 8, %g1
a0133704:  82 00 40 1d  add  %g1, %i5, %g1
a0133708:  c2 23 00 1b  st  %g1, [ %o4 + %i3 ]
a013370c:  fa 0f 20 03  ldub  [ %i4 + 3 ], %i5
a0133710:  83 28 60 08  sll  %g1, 8, %g1
a0133714:  b8 00 40 1d  add  %g1, %i5, %i4
a0133718:  b4 06 a0 01  inc  %i2
a013371c:  ba 0e a0 ff  and  %i2, 0xff, %i5
a0133720:  80 a7 60 04  cmp  %i5, 4
a0133724:  0a bf ff ee  bcs  0xa01336dc
a0133728:  f8 23 00 1b  st  %i4, [ %o4 + %i3 ]
a013372c:  b2 0c 60 ff  and  %l1, 0xff, %i1
a0133730:  b9 2e 60 10  sll  %i1, 0x10, %i4
a0133734:  f4 0a a3 97  ldub  [ %o2 + 0x397 ], %i2
a0133738:  83 2b 60 18  sll  %o5, 0x18, %g1
a013373c:  b6 0e a0 ff  and  %i2, 0xff, %i3
a0133740:  b2 00 40 1c  add  %g1, %i4, %i1
a0133744:  bb 2c a0 08  sll  %l2, 8, %i5
a0133748:  82 06 40 1d  add  %i1, %i5, %g1
a013374c:  b9 2e e0 02  sll  %i3, 2, %i4
a0133750:  b2 0d 20 ff  and  %l4, 0xff, %i1
a0133754:  b8 07 00 1b  add  %i4, %i3, %i4
a0133758:  b6 00 60 02  add  %g1, 2, %i3
a013375c:  bb 2e 60 04  sll  %i1, 4, %i5
a0133760:  b2 06 c0 1d  add  %i3, %i5, %i1
a0133764:  b9 2f 20 02  sll  %i4, 2, %i4
a0133768:  f2 24 c0 1c  st  %i1, [ %l3 + %i4 ]
a013376c:  b6 07 00 13  add  %i4, %l3, %i3
a0133770:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a0133774:  fa 07 bf e8  ld  [ %fp + -24 ], %i5
a0133778:  b4 06 a0 01  inc  %i2
a013377c:  c2 26 e0 10  st  %g1, [ %i3 + 0x10 ]
a0133780:  fa 26 e0 04  st  %i5, [ %i3 + 4 ]
a0133784:  b2 0e a0 ff  and  %i2, 0xff, %i1
a0133788:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a013378c:  fa 07 bf f0  ld  [ %fp + -16 ], %i5
a0133790:  c2 26 e0 08  st  %g1, [ %i3 + 8 ]
a0133794:  80 a6 60 24  cmp  %i1, 0x24
a0133798:  08 80 00 0d  bleu  0xa01337cc
a013379c:  fa 26 e0 0c  st  %i5, [ %i3 + 0xc ]
a01337a0:  c0 2a a3 97  clrb  [ %o2 + 0x397 ]
a01337a4:  b4 03 e0 10  add  %o7, 0x10, %i2
a01337a8:  bb 2e a0 10  sll  %i2, 0x10, %i5
a01337ac:  b3 37 60 10  srl  %i5, 0x10, %i1
a01337b0:  b6 02 e0 02  add  %o3, 2, %i3
a01337b4:  80 a6 40 1b  cmp  %i1, %i3
a01337b8:  9a 03 60 01  inc  %o5
a01337bc:  9e 10 00 1a  mov  %i2, %o7
a01337c0:  06 bf ff 91  bl  0xa0133604
a01337c4:  b8 10 00 0b  mov  %o3, %i4
a01337c8:  30 80 00 06  b,a   0xa01337e0
a01337cc:  10 bf ff f6  b  0xa01337a4
a01337d0:  f4 2a a3 97  stb  %i2, [ %o2 + 0x397 ]
a01337d4:  9a 10 00 1c  mov  %i4, %o5
a01337d8:  10 bf ff 7d  b  0xa01335cc
a01337dc:  92 10 20 00  clr  %o1
a01337e0:  81 c7 e0 08  ret
a01337e4:  81 e8 00 00  restore
