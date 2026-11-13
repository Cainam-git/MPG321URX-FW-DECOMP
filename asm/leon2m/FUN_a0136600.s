# leon2m FUN_a0136600 0xa0136600-0xa0136a10 (1040 bytes)
a0136600:  9d e3 bf 30  save  %sp, -208, %sp
a0136604:  98 10 20 00  clr  %o4
a0136608:  9a 10 20 00  clr  %o5
a013660c:  d8 3f bf b0  std  %o4, [ %fp + -80 ]
a0136610:  d8 3f bf b8  std  %o4, [ %fp + -72 ]
a0136614:  d8 3f bf c0  std  %o4, [ %fp + -64 ]
a0136618:  d8 3f bf c8  std  %o4, [ %fp + -56 ]
a013661c:  d8 3f bf d0  std  %o4, [ %fp + -48 ]
a0136620:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a0136624:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a0136628:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a013662c:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0136630:  7f ff f1 fb  call  0xa0132e1c
a0136634:  d8 3f bf a8  std  %o4, [ %fp + -88 ]
a0136638:  7f ff f3 00  call  0xa0133238
a013663c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0136640:  80 a6 20 00  cmp  %i0, 0
a0136644:  b8 10 20 10  mov  0x10, %i4
a0136648:  12 80 00 b5  bne  0xa013691c
a013664c:  a6 10 20 00  clr  %l3
a0136650:  03 00 06 94  sethi  %hi(0x1a5000), %g1
a0136654:  94 10 63 88  or  %g1, 0x388, %o2	! 0x1a5388
a0136658:  82 10 20 00  clr  %g1
a013665c:  ae 07 bf f8  add  %fp, -8, %l7
a0136660:  96 00 60 01  add  %g1, 1, %o3
a0136664:  a1 28 60 10  sll  %g1, 0x10, %l0
a0136668:  93 34 20 10  srl  %l0, 0x10, %o1
a013666c:  9f 2a e0 10  sll  %o3, 0x10, %o7
a0136670:  d8 0a 80 09  ldub  [ %o2 + %o1 ], %o4
a0136674:  9b 33 e0 10  srl  %o7, 0x10, %o5
a0136678:  90 05 c0 09  add  %l7, %o1, %o0
a013667c:  d8 2a 3f c0  stb  %o4, [ %o0 + -64 ]
a0136680:  80 a3 60 23  cmp  %o5, 0x23
a0136684:  08 bf ff f7  bleu  0xa0136660
a0136688:  82 10 00 0b  mov  %o3, %g1
a013668c:  17 2a 00 b6  sethi  %hi(0xa802d800), %o3
a0136690:  94 12 e1 b8  or  %o3, 0x1b8, %o2	! 0xa802d9b8
a0136694:  82 10 20 00  clr  %g1
a0136698:  90 00 60 01  add  %g1, 1, %o0
a013669c:  a3 28 60 10  sll  %g1, 0x10, %l1
a01366a0:  9f 34 60 10  srl  %l1, 0x10, %o7
a01366a4:  a1 2a 20 10  sll  %o0, 0x10, %l0
a01366a8:  d8 0a 80 0f  ldub  [ %o2 + %o7 ], %o4
a01366ac:  9b 34 20 10  srl  %l0, 0x10, %o5
a01366b0:  92 05 c0 0f  add  %l7, %o7, %o1
a01366b4:  d8 2a 7f e4  stb  %o4, [ %o1 + -28 ]
a01366b8:  80 a3 60 0b  cmp  %o5, 0xb
a01366bc:  08 bf ff f7  bleu  0xa0136698
a01366c0:  82 10 00 08  mov  %o0, %g1
a01366c4:  25 2a 00 b6  sethi  %hi(0xa802d800), %l2
a01366c8:  94 14 a2 60  or  %l2, 0x260, %o2	! 0xa802da60
a01366cc:  82 10 20 00  clr  %g1
a01366d0:  a8 00 60 01  add  %g1, 1, %l4
a01366d4:  83 28 60 10  sll  %g1, 0x10, %g1
a01366d8:  bb 30 60 10  srl  %g1, 0x10, %i5
a01366dc:  97 2d 20 10  sll  %l4, 0x10, %o3
a01366e0:  f0 0a 80 1d  ldub  [ %o2 + %i5 ], %i0
a01366e4:  ab 32 e0 10  srl  %o3, 0x10, %l5
a01366e8:  ac 05 c0 1d  add  %l7, %i5, %l6
a01366ec:  f0 2d bf f0  stb  %i0, [ %l6 + -16 ]
a01366f0:  80 a5 60 0b  cmp  %l5, 0xb
a01366f4:  08 bf ff f7  bleu  0xa01366d0
a01366f8:  82 10 00 14  mov  %l4, %g1
a01366fc:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a0136700:  29 2a 00 b2  sethi  %hi(0xa802c800), %l4
a0136704:  10 80 00 04  b  0xa0136714
a0136708:  a0 10 20 30  mov  0x30, %l0
a013670c:  7f ff fa 74  call  0xa01350dc
a0136710:  01 00 00 00  nop
a0136714:  d6 0c a3 97  ldub  [ %l2 + 0x397 ], %o3
a0136718:  d8 0d 23 96  ldub  [ %l4 + 0x396 ], %o4
a013671c:  94 0b 20 ff  and  %o4, 0xff, %o2
a0136720:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0136724:  90 22 80 0d  sub  %o2, %o5, %o0
a0136728:  92 0a e0 ff  and  %o3, 0xff, %o1
a013672c:  94 0b 20 ff  and  %o4, 0xff, %o2
a0136730:  80 a2 40 0a  cmp  %o1, %o2
a0136734:  18 80 00 09  bgu  0xa0136758
a0136738:  82 02 20 24  add  %o0, 0x24, %g1
a013673c:  9e 0b 20 ff  and  %o4, 0xff, %o7
a0136740:  98 0a e0 ff  and  %o3, 0xff, %o4
a0136744:  80 a2 40 0a  cmp  %o1, %o2
a0136748:  9a 23 c0 0c  sub  %o7, %o4, %o5
a013674c:  1a 80 00 03  bcc  0xa0136758
a0136750:  82 10 20 24  mov  0x24, %g1
a0136754:  82 03 7f ff  add  %o5, -1, %g1
a0136758:  a3 28 60 14  sll  %g1, 0x14, %l1
a013675c:  93 34 60 10  srl  %l1, 0x10, %o1
a0136760:  80 a4 00 09  cmp  %l0, %o1
a0136764:  18 bf ff ea  bgu  0xa013670c
a0136768:  a2 10 20 00  clr  %l1
a013676c:  21 2a 00 b6  sethi  %hi(0xa802d800), %l0
a0136770:  aa 14 22 6c  or  %l0, 0x26c, %l5	! 0xa802da6c
a0136774:  ba 07 bf b8  add  %fp, -72, %i5
a0136778:  a0 07 bf a8  add  %fp, -88, %l0
a013677c:  ac 10 20 3c  mov  0x3c, %l6
a0136780:  83 2c 60 10  sll  %l1, 0x10, %g1
a0136784:  b1 30 60 10  srl  %g1, 0x10, %i0
a0136788:  96 25 80 18  sub  %l6, %i0, %o3
a013678c:  80 a2 e0 0f  cmp  %o3, 0xf
a0136790:  28 80 00 02  bleu,a   0xa0136798
a0136794:  b8 25 80 11  sub  %l6, %l1, %i4
a0136798:  7f fe 9b 9f  call  0xa00dd614
a013679c:  90 10 20 20  mov  0x20, %o0
a01367a0:  80 8a 20 ff  btst  0xff, %o0
a01367a4:  12 80 00 73  bne  0xa0136970
a01367a8:  82 05 c0 18  add  %l7, %i0, %g1
a01367ac:  7f fe 9b 9a  call  0xa00dd614
a01367b0:  90 10 20 20  mov  0x20, %o0
a01367b4:  80 8a 20 ff  btst  0xff, %o0
a01367b8:  12 80 00 82  bne  0xa01369c0
a01367bc:  82 05 c0 18  add  %l7, %i0, %g1
a01367c0:  92 07 40 18  add  %i5, %i0, %o1
a01367c4:  94 10 20 00  clr  %o2
a01367c8:  9a 10 20 00  clr  %o5
a01367cc:  b1 2b 60 02  sll  %o5, 2, %i0
a01367d0:  d0 0a 40 18  ldub  [ %o1 + %i0 ], %o0
a01367d4:  d0 24 00 18  st  %o0, [ %l0 + %i0 ]
a01367d8:  9e 06 00 09  add  %i0, %o1, %o7
a01367dc:  da 0b e0 01  ldub  [ %o7 + 1 ], %o5
a01367e0:  83 2a 20 08  sll  %o0, 8, %g1
a01367e4:  96 00 40 0d  add  %g1, %o5, %o3
a01367e8:  d6 24 00 18  st  %o3, [ %l0 + %i0 ]
a01367ec:  d8 0b e0 02  ldub  [ %o7 + 2 ], %o4
a01367f0:  91 2a e0 08  sll  %o3, 8, %o0
a01367f4:  82 02 00 0c  add  %o0, %o4, %g1
a01367f8:  c2 24 00 18  st  %g1, [ %l0 + %i0 ]
a01367fc:  da 0b e0 03  ldub  [ %o7 + 3 ], %o5
a0136800:  97 28 60 08  sll  %g1, 8, %o3
a0136804:  98 02 c0 0d  add  %o3, %o5, %o4
a0136808:  94 02 a0 01  inc  %o2
a013680c:  9a 0a a0 ff  and  %o2, 0xff, %o5
a0136810:  80 a3 60 04  cmp  %o5, 4
a0136814:  0a bf ff ee  bcs  0xa01367cc
a0136818:  d8 24 00 18  st  %o4, [ %l0 + %i0 ]
a013681c:  d4 0c a3 97  ldub  [ %l2 + 0x397 ], %o2
a0136820:  96 0a a0 ff  and  %o2, 0xff, %o3
a0136824:  82 0f 20 ff  and  %i4, 0xff, %g1
a0136828:  99 28 60 10  sll  %g1, 0x10, %o4
a013682c:  9b 2a e0 02  sll  %o3, 2, %o5
a0136830:  9f 2c e0 18  sll  %l3, 0x18, %o7
a0136834:  b0 03 40 0b  add  %o5, %o3, %i0
a0136838:  92 03 c0 0c  add  %o7, %o4, %o1
a013683c:  83 2e 20 02  sll  %i0, 2, %g1
a0136840:  90 02 60 08  add  %o1, 8, %o0
a0136844:  94 02 a0 01  inc  %o2
a0136848:  d0 25 40 01  st  %o0, [ %l5 + %g1 ]
a013684c:  b0 00 40 15  add  %g1, %l5, %i0
a0136850:  92 0a a0 ff  and  %o2, 0xff, %o1
a0136854:  da 07 bf b4  ld  [ %fp + -76 ], %o5
a0136858:  d6 07 bf a8  ld  [ %fp + -88 ], %o3
a013685c:  d8 07 bf ac  ld  [ %fp + -84 ], %o4
a0136860:  de 07 bf b0  ld  [ %fp + -80 ], %o7
a0136864:  da 26 20 10  st  %o5, [ %i0 + 0x10 ]
a0136868:  d6 26 20 04  st  %o3, [ %i0 + 4 ]
a013686c:  d8 26 20 08  st  %o4, [ %i0 + 8 ]
a0136870:  80 a2 60 24  cmp  %o1, 0x24
a0136874:  08 80 00 3d  bleu  0xa0136968
a0136878:  de 26 20 0c  st  %o7, [ %i0 + 0xc ]
a013687c:  c0 2c a3 97  clrb  [ %l2 + 0x397 ]
a0136880:  90 04 60 10  add  %l1, 0x10, %o0
a0136884:  95 2a 20 10  sll  %o0, 0x10, %o2
a0136888:  a3 32 a0 10  srl  %o2, 0x10, %l1
a013688c:  80 a4 60 3b  cmp  %l1, 0x3b
a0136890:  a6 04 e0 01  inc  %l3
a0136894:  08 bf ff bb  bleu  0xa0136780
a0136898:  a2 10 00 08  mov  %o0, %l1
a013689c:  10 80 00 04  b  0xa01368ac
a01368a0:  c0 27 bf a4  clr  [ %fp + -92 ]
a01368a4:  7f ff fa 0e  call  0xa01350dc
a01368a8:  01 00 00 00  nop
a01368ac:  ee 0c a3 97  ldub  [ %l2 + 0x397 ], %l7
a01368b0:  e6 0d 23 96  ldub  [ %l4 + 0x396 ], %l3
a01368b4:  80 a5 c0 13  cmp  %l7, %l3
a01368b8:  12 bf ff fb  bne  0xa01368a4
a01368bc:  a0 10 20 00  clr  %l0
a01368c0:  b0 10 20 00  clr  %i0
a01368c4:  98 10 20 00  clr  %o4
a01368c8:  9b 2b 20 02  sll  %o4, 2, %o5
a01368cc:  9e 03 40 0c  add  %o5, %o4, %o7
a01368d0:  93 2b e0 02  sll  %o7, 2, %o1
a01368d4:  ba 02 60 10  add  %o1, 0x10, %i5
a01368d8:  92 0f 60 fc  and  %i5, 0xfc, %o1
a01368dc:  90 10 20 00  clr  %o0
a01368e0:  94 07 bf a4  add  %fp, -92, %o2
a01368e4:  67 fd 56 fb  call  0x4008c4d0
a01368e8:  96 10 20 01  mov  1, %o3
a01368ec:  b0 06 20 01  inc  %i0
a01368f0:  98 0e 20 ff  and  %i0, 0xff, %o4
a01368f4:  ad 2b 20 02  sll  %o4, 2, %l6
a01368f8:  aa 05 80 0c  add  %l6, %o4, %l5
a01368fc:  a9 2d 60 02  sll  %l5, 2, %l4
a0136900:  b8 05 20 10  add  %l4, 0x10, %i4
a0136904:  e4 07 bf a4  ld  [ %fp + -92 ], %l2
a0136908:  80 a7 20 50  cmp  %i4, 0x50
a013690c:  04 bf ff ef  ble  0xa01368c8
a0136910:  a0 14 00 12  or  %l0, %l2, %l0
a0136914:  10 80 00 3b  b  0xa0136a00
a0136918:  80 a4 20 00  cmp  %l0, 0
a013691c:  80 a6 20 01  cmp  %i0, 1
a0136920:  12 bf ff 5b  bne  0xa013668c
a0136924:  ae 07 bf f8  add  %fp, -8, %l7
a0136928:  23 00 06 94  sethi  %hi(0x1a5000), %l1
a013692c:  94 14 63 60  or  %l1, 0x360, %o2	! 0x1a5360
a0136930:  82 10 20 00  clr  %g1
a0136934:  a4 00 60 01  add  %g1, 1, %l2
a0136938:  83 28 60 10  sll  %g1, 0x10, %g1
a013693c:  b1 30 60 10  srl  %g1, 0x10, %i0
a0136940:  bb 2c a0 10  sll  %l2, 0x10, %i5
a0136944:  ec 0a 80 18  ldub  [ %o2 + %i0 ], %l6
a0136948:  a9 37 60 10  srl  %i5, 0x10, %l4
a013694c:  aa 05 c0 18  add  %l7, %i0, %l5
a0136950:  ec 2d 7f c0  stb  %l6, [ %l5 + -64 ]
a0136954:  80 a5 20 23  cmp  %l4, 0x23
a0136958:  08 bf ff f7  bleu  0xa0136934
a013695c:  82 10 00 12  mov  %l2, %g1
a0136960:  10 bf ff 4c  b  0xa0136690
a0136964:  17 2a 00 b6  sethi  %hi(0xa802d800), %o3
a0136968:  10 bf ff c6  b  0xa0136880
a013696c:  d4 2c a3 97  stb  %o2, [ %l2 + 0x397 ]
a0136970:  de 08 7f c5  ldub  [ %g1 + -59 ], %o7
a0136974:  d2 08 7f c0  ldub  [ %g1 + -64 ], %o1
a0136978:  d4 08 7f c1  ldub  [ %g1 + -63 ], %o2
a013697c:  d6 08 7f c2  ldub  [ %g1 + -62 ], %o3
a0136980:  d8 08 7f c3  ldub  [ %g1 + -61 ], %o4
a0136984:  da 08 7f c4  ldub  [ %g1 + -60 ], %o5
a0136988:  de 23 a0 5c  st  %o7, [ %sp + 0x5c ]
a013698c:  d0 08 7f c6  ldub  [ %g1 + -58 ], %o0
a0136990:  d0 23 a0 60  st  %o0, [ %sp + 0x60 ]
a0136994:  de 08 7f c7  ldub  [ %g1 + -57 ], %o7
a0136998:  11 00 06 95  sethi  %hi(0x1a5400), %o0
a013699c:  de 23 a0 64  st  %o7, [ %sp + 0x64 ]
a01369a0:  7f fe a1 f4  call  0xa00df170
a01369a4:  90 12 21 50  or  %o0, 0x150, %o0
a01369a8:  7f fe 9b 1b  call  0xa00dd614
a01369ac:  90 10 20 20  mov  0x20, %o0
a01369b0:  80 8a 20 ff  btst  0xff, %o0
a01369b4:  22 bf ff 84  be,a   0xa01367c4
a01369b8:  92 07 40 18  add  %i5, %i0, %o1
a01369bc:  82 05 c0 18  add  %l7, %i0, %g1
a01369c0:  d2 08 7f c8  ldub  [ %g1 + -56 ], %o1
a01369c4:  d4 08 7f c9  ldub  [ %g1 + -55 ], %o2
a01369c8:  d6 08 7f ca  ldub  [ %g1 + -54 ], %o3
a01369cc:  d8 08 7f cb  ldub  [ %g1 + -53 ], %o4
a01369d0:  da 08 7f cc  ldub  [ %g1 + -52 ], %o5
a01369d4:  d0 08 7f cd  ldub  [ %g1 + -51 ], %o0
a01369d8:  d0 23 a0 5c  st  %o0, [ %sp + 0x5c ]
a01369dc:  de 08 7f ce  ldub  [ %g1 + -50 ], %o7
a01369e0:  de 23 a0 60  st  %o7, [ %sp + 0x60 ]
a01369e4:  d0 08 7f cf  ldub  [ %g1 + -49 ], %o0
a01369e8:  d0 23 a0 64  st  %o0, [ %sp + 0x64 ]
a01369ec:  03 00 06 95  sethi  %hi(0x1a5400), %g1
a01369f0:  7f fe a1 e0  call  0xa00df170
a01369f4:  90 10 61 50  or  %g1, 0x150, %o0	! 0x1a5550
a01369f8:  10 bf ff 73  b  0xa01367c4
a01369fc:  92 07 40 18  add  %i5, %i0, %o1
a0136a00:  12 bf ff b0  bne  0xa01368c0
a0136a04:  a0 10 20 00  clr  %l0
a0136a08:  81 c7 e0 08  ret
a0136a0c:  81 e8 00 00  restore
