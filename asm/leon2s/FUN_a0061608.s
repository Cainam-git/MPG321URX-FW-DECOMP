# leon2s FUN_a0061608 0xa0061608-0xa00617f0 (488 bytes)
a0061608:  9d e3 bf 98  save  %sp, -104, %sp
a006160c:  80 8e 20 03  btst  3, %i0
a0061610:  02 80 00 19  be  0xa0061674
a0061614:  9e 10 00 1a  mov  %i2, %o7
a0061618:  9a 10 20 ff  mov  0xff, %o5
a006161c:  ba 0e 60 03  and  %i1, 3, %i5
a0061620:  82 0e 7f fc  and  %i1, -4, %g1
a0061624:  f6 00 40 00  ld  [ %g1 ], %i3
a0061628:  b5 2f 60 03  sll  %i5, 3, %i2
a006162c:  bb 36 c0 1a  srl  %i3, %i2, %i5
a0061630:  82 0e 20 03  and  %i0, 3, %g1
a0061634:  b8 0e 3f fc  and  %i0, -4, %i4
a0061638:  b5 28 60 03  sll  %g1, 3, %i2
a006163c:  f6 07 00 00  ld  [ %i4 ], %i3
a0061640:  ba 0f 60 ff  and  %i5, 0xff, %i5
a0061644:  83 2b 40 1a  sll  %o5, %i2, %g1
a0061648:  82 2e c0 01  andn  %i3, %g1, %g1
a006164c:  bb 2f 40 1a  sll  %i5, %i2, %i5
a0061650:  b6 10 40 1d  or  %g1, %i5, %i3
a0061654:  f6 27 00 00  st  %i3, [ %i4 ]
a0061658:  b0 06 20 01  inc  %i0
a006165c:  9e 83 ff ff  addcc  %o7, -1, %o7
a0061660:  02 80 00 62  be  0xa00617e8
a0061664:  b2 06 60 01  inc  %i1
a0061668:  80 8e 20 03  btst  3, %i0
a006166c:  12 bf ff ed  bne  0xa0061620
a0061670:  ba 0e 60 03  and  %i1, 3, %i5
a0061674:  82 0e 60 03  and  %i1, 3, %g1
a0061678:  80 a0 60 01  cmp  %g1, 1
a006167c:  b5 33 e0 02  srl  %o7, 2, %i2
a0061680:  02 80 00 16  be  0xa00616d8
a0061684:  b8 0e 7f fc  and  %i1, -4, %i4
a0061688:  80 a0 60 01  cmp  %g1, 1
a006168c:  0a 80 00 08  bcs  0xa00616ac
a0061690:  80 a6 a0 00  cmp  %i2, 0
a0061694:  80 a0 60 02  cmp  %g1, 2
a0061698:  02 80 00 20  be  0xa0061718
a006169c:  80 a0 60 03  cmp  %g1, 3
a00616a0:  02 80 00 2d  be  0xa0061754
a00616a4:  80 8b e0 03  btst  3, %o7
a00616a8:  30 80 00 3a  b,a   0xa0061790
a00616ac:  02 80 00 38  be  0xa006178c
a00616b0:  b2 10 00 1c  mov  %i4, %i1
a00616b4:  b6 10 00 1a  mov  %i2, %i3
a00616b8:  c2 07 00 00  ld  [ %i4 ], %g1
a00616bc:  c2 26 00 00  st  %g1, [ %i0 ]
a00616c0:  b8 07 20 04  add  %i4, 4, %i4
a00616c4:  b6 86 ff ff  addcc  %i3, -1, %i3
a00616c8:  12 bf ff fc  bne  0xa00616b8
a00616cc:  b0 06 20 04  add  %i0, 4, %i0
a00616d0:  10 80 00 2f  b  0xa006178c
a00616d4:  b2 10 00 1c  mov  %i4, %i1
a00616d8:  80 a6 a0 00  cmp  %i2, 0
a00616dc:  02 80 00 2c  be  0xa006178c
a00616e0:  b2 07 20 01  add  %i4, 1, %i1
a00616e4:  b6 10 00 1a  mov  %i2, %i3
a00616e8:  fa 07 00 00  ld  [ %i4 ], %i5
a00616ec:  c2 07 20 04  ld  [ %i4 + 4 ], %g1
a00616f0:  bb 37 60 08  srl  %i5, 8, %i5
a00616f4:  83 28 60 18  sll  %g1, 0x18, %g1
a00616f8:  ba 07 40 01  add  %i5, %g1, %i5
a00616fc:  fa 26 00 00  st  %i5, [ %i0 ]
a0061700:  b0 06 20 04  add  %i0, 4, %i0
a0061704:  b6 86 ff ff  addcc  %i3, -1, %i3
a0061708:  12 bf ff f8  bne  0xa00616e8
a006170c:  b8 07 20 04  add  %i4, 4, %i4
a0061710:  10 80 00 1f  b  0xa006178c
a0061714:  b2 07 20 01  add  %i4, 1, %i1
a0061718:  80 a6 a0 00  cmp  %i2, 0
a006171c:  02 80 00 1c  be  0xa006178c
a0061720:  b2 07 20 02  add  %i4, 2, %i1
a0061724:  b6 10 00 1a  mov  %i2, %i3
a0061728:  fa 07 20 04  ld  [ %i4 + 4 ], %i5
a006172c:  c2 17 00 00  lduh  [ %i4 ], %g1
a0061730:  bb 2f 60 10  sll  %i5, 0x10, %i5
a0061734:  82 00 40 1d  add  %g1, %i5, %g1
a0061738:  c2 26 00 00  st  %g1, [ %i0 ]
a006173c:  b0 06 20 04  add  %i0, 4, %i0
a0061740:  b6 86 ff ff  addcc  %i3, -1, %i3
a0061744:  12 bf ff f9  bne  0xa0061728
a0061748:  b8 07 20 04  add  %i4, 4, %i4
a006174c:  10 80 00 10  b  0xa006178c
a0061750:  b2 07 20 02  add  %i4, 2, %i1
a0061754:  80 a6 a0 00  cmp  %i2, 0
a0061758:  02 80 00 0d  be  0xa006178c
a006175c:  b2 07 20 03  add  %i4, 3, %i1
a0061760:  b6 10 00 1a  mov  %i2, %i3
a0061764:  fa 07 20 04  ld  [ %i4 + 4 ], %i5
a0061768:  c2 0f 00 00  ldub  [ %i4 ], %g1
a006176c:  bb 2f 60 08  sll  %i5, 8, %i5
a0061770:  82 00 40 1d  add  %g1, %i5, %g1
a0061774:  c2 26 00 00  st  %g1, [ %i0 ]
a0061778:  b0 06 20 04  add  %i0, 4, %i0
a006177c:  b6 86 ff ff  addcc  %i3, -1, %i3
a0061780:  12 bf ff f9  bne  0xa0061764
a0061784:  b8 07 20 04  add  %i4, 4, %i4
a0061788:  b2 07 20 03  add  %i4, 3, %i1
a006178c:  80 8b e0 03  btst  3, %o7
a0061790:  02 80 00 16  be  0xa00617e8
a0061794:  9a 10 20 ff  mov  0xff, %o5
a0061798:  ba 0e 60 03  and  %i1, 3, %i5
a006179c:  82 0e 7f fc  and  %i1, -4, %g1
a00617a0:  f6 00 40 00  ld  [ %g1 ], %i3
a00617a4:  b5 2f 60 03  sll  %i5, 3, %i2
a00617a8:  bb 36 c0 1a  srl  %i3, %i2, %i5
a00617ac:  82 0e 20 03  and  %i0, 3, %g1
a00617b0:  b8 0e 3f fc  and  %i0, -4, %i4
a00617b4:  b5 28 60 03  sll  %g1, 3, %i2
a00617b8:  f6 07 00 00  ld  [ %i4 ], %i3
a00617bc:  ba 0f 60 ff  and  %i5, 0xff, %i5
a00617c0:  83 2b 40 1a  sll  %o5, %i2, %g1
a00617c4:  82 2e c0 01  andn  %i3, %g1, %g1
a00617c8:  bb 2f 40 1a  sll  %i5, %i2, %i5
a00617cc:  b6 10 40 1d  or  %g1, %i5, %i3
a00617d0:  9e 03 ff ff  add  %o7, -1, %o7
a00617d4:  f6 27 00 00  st  %i3, [ %i4 ]
a00617d8:  b2 06 60 01  inc  %i1
a00617dc:  80 8b e0 03  btst  3, %o7
a00617e0:  12 bf ff ee  bne  0xa0061798
a00617e4:  b0 06 20 01  inc  %i0
a00617e8:  81 c7 e0 08  ret
a00617ec:  81 e8 00 00  restore
