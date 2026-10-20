# leon2m FUN_a0122634 0xa0122634-0xa01227f0 (444 bytes)
a0122634:  9d e3 bf 98  save  %sp, -104, %sp
a0122638:  80 a0 00 18  cmp  %g0, %i0
a012263c:  82 60 3f ff  subx  %g0, -1, %g1
a0122640:  b4 1e 20 04  xor  %i0, 4, %i2
a0122644:  80 a0 00 1a  cmp  %g0, %i2
a0122648:  b7 2e 60 04  sll  %i1, 4, %i3
a012264c:  ba 06 c0 19  add  %i3, %i1, %i5
a0122650:  b8 60 3f ff  subx  %g0, -1, %i4
a0122654:  80 90 40 1c  orcc  %g1, %i4, %g0
a0122658:  02 80 00 08  be  0xa0122678
a012265c:  9e 07 7f ef  add  %i5, -17, %o7
a0122660:  80 a6 60 00  cmp  %i1, 0
a0122664:  12 80 00 53  bne  0xa01227b0
a0122668:  03 33 c0 73  sethi  %hi(0xcf01cc00), %g1
a012266c:  39 33 c0 73  sethi  %hi(0xcf01cc00), %i4
a0122670:  ba 17 21 0c  or  %i4, 0x10c, %i5	! 0xcf01cd0c
a0122674:  c0 27 40 00  clr  [ %i5 ]
a0122678:  b6 1e 20 01  xor  %i0, 1, %i3
a012267c:  80 a0 00 1b  cmp  %g0, %i3
a0122680:  ba 60 3f ff  subx  %g0, -1, %i5
a0122684:  80 a0 00 1a  cmp  %g0, %i2
a0122688:  82 60 3f ff  subx  %g0, -1, %g1
a012268c:  80 97 40 01  orcc  %i5, %g1, %g0
a0122690:  02 80 00 08  be  0xa01226b0
a0122694:  b8 1e 20 02  xor  %i0, 2, %i4
a0122698:  80 a6 60 00  cmp  %i1, 0
a012269c:  12 80 00 37  bne  0xa0122778
a01226a0:  03 33 c0 73  sethi  %hi(0xcf01cc00), %g1
a01226a4:  b8 10 61 98  or  %g1, 0x198, %i4	! 0xcf01cd98
a01226a8:  c0 27 00 00  clr  [ %i4 ]
a01226ac:  b8 1e 20 02  xor  %i0, 2, %i4
a01226b0:  80 a0 00 1c  cmp  %g0, %i4
a01226b4:  82 60 3f ff  subx  %g0, -1, %g1
a01226b8:  80 a0 00 1a  cmp  %g0, %i2
a01226bc:  b4 60 3f ff  subx  %g0, -1, %i2
a01226c0:  80 90 40 1a  orcc  %g1, %i2, %g0
a01226c4:  02 80 00 09  be  0xa01226e8
a01226c8:  82 06 3f fd  add  %i0, -3, %g1
a01226cc:  80 a6 60 00  cmp  %i1, 0
a01226d0:  12 80 00 1c  bne  0xa0122740
a01226d4:  03 33 c0 73  sethi  %hi(0xcf01cc00), %g1
a01226d8:  3b 33 c0 73  sethi  %hi(0xcf01cc00), %i5
a01226dc:  b6 17 62 24  or  %i5, 0x224, %i3	! 0xcf01ce24
a01226e0:  c0 26 c0 00  clr  [ %i3 ]
a01226e4:  82 06 3f fd  add  %i0, -3, %g1
a01226e8:  80 a0 60 01  cmp  %g1, 1
a01226ec:  18 80 00 3f  bgu  0xa01227e8
a01226f0:  80 a6 60 00  cmp  %i1, 0
a01226f4:  12 80 00 06  bne  0xa012270c
a01226f8:  37 33 c0 73  sethi  %hi(0xcf01cc00), %i3
a01226fc:  33 33 c0 73  sethi  %hi(0xcf01cc00), %i1
a0122700:  b0 16 62 b0  or  %i1, 0x2b0, %i0	! 0xcf01ceb0
a0122704:  c0 26 00 00  clr  [ %i0 ]
a0122708:  30 80 00 38  b,a   0xa01227e8
a012270c:  ba 10 20 ff  mov  0xff, %i5
a0122710:  b2 16 e2 b0  or  %i3, 0x2b0, %i1
a0122714:  fa 26 40 00  st  %i5, [ %i1 ]
a0122718:  b4 0b e0 ff  and  %o7, 0xff, %i2
a012271c:  b0 16 e2 a0  or  %i3, 0x2a0, %i0
a0122720:  f4 26 00 00  st  %i2, [ %i0 ]
a0122724:  82 16 e2 a4  or  %i3, 0x2a4, %g1
a0122728:  f4 20 40 00  st  %i2, [ %g1 ]
a012272c:  b8 16 e2 a8  or  %i3, 0x2a8, %i4
a0122730:  f4 27 00 00  st  %i2, [ %i4 ]
a0122734:  ba 16 e2 ac  or  %i3, 0x2ac, %i5
a0122738:  f4 27 40 00  st  %i2, [ %i5 ]
a012273c:  30 80 00 2b  b,a   0xa01227e8
a0122740:  b6 10 62 24  or  %g1, 0x224, %i3
a0122744:  b8 10 20 ff  mov  0xff, %i4
a0122748:  f8 26 c0 00  st  %i4, [ %i3 ]
a012274c:  b6 0b e0 ff  and  %o7, 0xff, %i3
a0122750:  b4 10 62 14  or  %g1, 0x214, %i2
a0122754:  f6 26 80 00  st  %i3, [ %i2 ]
a0122758:  ba 10 62 18  or  %g1, 0x218, %i5
a012275c:  f6 27 40 00  st  %i3, [ %i5 ]
a0122760:  b8 10 62 1c  or  %g1, 0x21c, %i4
a0122764:  f6 27 00 00  st  %i3, [ %i4 ]
a0122768:  b4 10 62 20  or  %g1, 0x220, %i2
a012276c:  f6 26 80 00  st  %i3, [ %i2 ]
a0122770:  10 bf ff de  b  0xa01226e8
a0122774:  82 06 3f fd  add  %i0, -3, %g1
a0122778:  b6 10 61 98  or  %g1, 0x198, %i3
a012277c:  ba 10 20 ff  mov  0xff, %i5
a0122780:  fa 26 c0 00  st  %i5, [ %i3 ]
a0122784:  b6 0b e0 ff  and  %o7, 0xff, %i3
a0122788:  b8 10 61 88  or  %g1, 0x188, %i4
a012278c:  f6 27 00 00  st  %i3, [ %i4 ]
a0122790:  ba 10 61 8c  or  %g1, 0x18c, %i5
a0122794:  f6 27 40 00  st  %i3, [ %i5 ]
a0122798:  b8 10 61 90  or  %g1, 0x190, %i4
a012279c:  f6 27 00 00  st  %i3, [ %i4 ]
a01227a0:  ba 10 61 94  or  %g1, 0x194, %i5
a01227a4:  f6 27 40 00  st  %i3, [ %i5 ]
a01227a8:  10 bf ff c2  b  0xa01226b0
a01227ac:  b8 1e 20 02  xor  %i0, 2, %i4
a01227b0:  b6 10 61 0c  or  %g1, 0x10c, %i3
a01227b4:  b8 10 20 ff  mov  0xff, %i4
a01227b8:  f8 26 c0 00  st  %i4, [ %i3 ]
a01227bc:  b6 0b e0 ff  and  %o7, 0xff, %i3
a01227c0:  ba 10 60 fc  or  %g1, 0xfc, %i5
a01227c4:  f6 27 40 00  st  %i3, [ %i5 ]
a01227c8:  b8 10 61 00  or  %g1, 0x100, %i4
a01227cc:  f6 27 00 00  st  %i3, [ %i4 ]
a01227d0:  ba 10 61 04  or  %g1, 0x104, %i5
a01227d4:  f6 27 40 00  st  %i3, [ %i5 ]
a01227d8:  82 10 61 08  or  %g1, 0x108, %g1
a01227dc:  f6 20 40 00  st  %i3, [ %g1 ]
a01227e0:  10 bf ff a7  b  0xa012267c
a01227e4:  b6 1e 20 01  xor  %i0, 1, %i3
a01227e8:  81 c7 e0 08  ret
a01227ec:  81 e8 00 00  restore
