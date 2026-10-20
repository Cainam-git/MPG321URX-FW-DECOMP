# leon2m FUN_a00bb560 0xa00bb560-0xa00bb86c (780 bytes)
a00bb560:  9d e3 bf 90  save  %sp, -112, %sp
a00bb564:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00bb568:  d0 0c 20 9a  ldub  [ %l0 + 0x9a ], %o0	! 0xa802b09a
a00bb56c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00bb570:  98 10 20 30  mov  0x30, %o4
a00bb574:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00bb578:  96 23 00 0d  sub  %o4, %o5, %o3
a00bb57c:  94 14 60 40  or  %l1, 0x40, %o2
a00bb580:  93 2a e0 10  sll  %o3, 0x10, %o1
a00bb584:  94 02 00 0a  add  %o0, %o2, %o2
a00bb588:  c0 37 bf f6  clrh  [ %fp + -10 ]
a00bb58c:  90 0e 20 ff  and  %i0, 0xff, %o0
a00bb590:  93 32 60 10  srl  %o1, 0x10, %o1
a00bb594:  40 02 34 8e  call  0xa01487cc
a00bb598:  96 07 bf f6  add  %fp, -10, %o3
a00bb59c:  c2 17 bf f6  lduh  [ %fp + -10 ], %g1
a00bb5a0:  80 a0 60 00  cmp  %g1, 0
a00bb5a4:  a4 10 20 00  clr  %l2
a00bb5a8:  02 80 00 5f  be  0xa00bb724
a00bb5ac:  9a 10 00 01  mov  %g1, %o5
a00bb5b0:  c2 0c 20 9a  ldub  [ %l0 + 0x9a ], %g1
a00bb5b4:  82 00 40 0d  add  %g1, %o5, %g1
a00bb5b8:  92 08 60 ff  and  %g1, 0xff, %o1
a00bb5bc:  80 a2 60 2f  cmp  %o1, 0x2f
a00bb5c0:  18 80 00 14  bgu  0xa00bb610
a00bb5c4:  d6 0c 60 40  ldub  [ %l1 + 0x40 ], %o3
a00bb5c8:  98 1a e0 35  xor  %o3, 0x35, %o4
a00bb5cc:  80 a0 00 0c  cmp  %g0, %o4
a00bb5d0:  90 40 20 00  addx  %g0, 0, %o0
a00bb5d4:  80 a0 00 0b  cmp  %g0, %o3
a00bb5d8:  94 40 20 00  addx  %g0, 0, %o2
a00bb5dc:  80 8a 00 0a  btst  %o0, %o2
a00bb5e0:  12 80 00 14  bne  0xa00bb630
a00bb5e4:  c2 2c 20 9a  stb  %g1, [ %l0 + 0x9a ]
a00bb5e8:  d2 0c 60 40  ldub  [ %l1 + 0x40 ], %o1
a00bb5ec:  80 a2 60 35  cmp  %o1, 0x35
a00bb5f0:  12 80 00 06  bne  0xa00bb608
a00bb5f4:  b0 14 60 40  or  %l1, 0x40, %i0
a00bb5f8:  c2 0c 20 9a  ldub  [ %l0 + 0x9a ], %g1
a00bb5fc:  80 a0 60 05  cmp  %g1, 5
a00bb600:  18 80 00 1a  bgu  0xa00bb668
a00bb604:  01 00 00 00  nop
a00bb608:  10 80 00 97  b  0xa00bb864
a00bb60c:  b0 10 20 08  mov  8, %i0	! 0x8
a00bb610:  98 1a e0 35  xor  %o3, 0x35, %o4
a00bb614:  80 a0 00 0c  cmp  %g0, %o4
a00bb618:  90 40 20 00  addx  %g0, 0, %o0
a00bb61c:  80 a0 00 0b  cmp  %g0, %o3
a00bb620:  94 40 20 00  addx  %g0, 0, %o2
a00bb624:  80 8a 00 0a  btst  %o0, %o2
a00bb628:  02 bf ff f0  be  0xa00bb5e8
a00bb62c:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]
a00bb630:  7f ff 2d 03  call  0xa0086a3c
a00bb634:  90 10 20 10  mov  0x10, %o0
a00bb638:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00bb63c:  80 a3 60 00  cmp  %o5, 0
a00bb640:  32 bf ff eb  bne,a   0xa00bb5ec
a00bb644:  d2 0c 60 40  ldub  [ %l1 + 0x40 ], %o1
a00bb648:  b0 10 20 01  mov  1, %i0
a00bb64c:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bb650:  f0 2b e0 99  stb  %i0, [ %o7 + 0x99 ]	! 0xa802b099
a00bb654:  90 10 20 10  mov  0x10, %o0
a00bb658:  7f ff 2c d6  call  0xa00869b0
a00bb65c:  92 10 20 32  mov  0x32, %o1
a00bb660:  10 bf ff e3  b  0xa00bb5ec
a00bb664:  d2 0c 60 40  ldub  [ %l1 + 0x40 ], %o1
a00bb668:  7f ff 2c f5  call  0xa0086a3c
a00bb66c:  90 10 20 10  mov  0x10, %o0
a00bb670:  95 2a 20 10  sll  %o0, 0x10, %o2
a00bb674:  80 a2 a0 00  cmp  %o2, 0
a00bb678:  02 80 00 38  be  0xa00bb758
a00bb67c:  96 10 20 01  mov  1, %o3
a00bb680:  c2 0e 20 01  ldub  [ %i0 + 1 ], %g1
a00bb684:  80 a0 60 38  cmp  %g1, 0x38
a00bb688:  02 80 00 49  be  0xa00bb7ac
a00bb68c:  80 a0 60 62  cmp  %g1, 0x62
a00bb690:  02 80 00 5c  be  0xa00bb800
a00bb694:  80 a0 60 36  cmp  %g1, 0x36
a00bb698:  22 80 00 02  be,a   0xa00bb6a0
a00bb69c:  a4 10 20 05  mov  5, %l2
a00bb6a0:  9a 0c a0 0f  and  %l2, 0xf, %o5
a00bb6a4:  d4 0c 20 9a  ldub  [ %l0 + 0x9a ], %o2
a00bb6a8:  80 a2 80 0d  cmp  %o2, %o5
a00bb6ac:  08 80 00 6e  bleu  0xa00bb864
a00bb6b0:  b0 10 20 08  mov  8, %i0
a00bb6b4:  98 14 60 40  or  %l1, 0x40, %o4
a00bb6b8:  d0 0b 00 0d  ldub  [ %o4 + %o5 ], %o0
a00bb6bc:  80 a2 20 0d  cmp  %o0, 0xd
a00bb6c0:  12 80 00 69  bne  0xa00bb864
a00bb6c4:  b0 10 20 10  mov  0x10, %i0
a00bb6c8:  da 0b 20 01  ldub  [ %o4 + 1 ], %o5
a00bb6cc:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00bb6d0:  c0 2a e0 99  clrb  [ %o3 + 0x99 ]	! 0xa802b099
a00bb6d4:  80 a3 60 38  cmp  %o5, 0x38
a00bb6d8:  02 80 00 63  be  0xa00bb864
a00bb6dc:  b0 10 20 02  mov  2, %i0
a00bb6e0:  80 a3 60 62  cmp  %o5, 0x62
a00bb6e4:  02 80 00 60  be  0xa00bb864
a00bb6e8:  b0 10 20 04  mov  4, %i0
a00bb6ec:  e4 0b 20 02  ldub  [ %o4 + 2 ], %l2
a00bb6f0:  80 a4 a0 30  cmp  %l2, 0x30
a00bb6f4:  22 80 00 30  be,a   0xa00bb7b4
a00bb6f8:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a00bb6fc:  94 14 60 40  or  %l1, 0x40, %o2
a00bb700:  e2 0a a0 02  ldub  [ %o2 + 2 ], %l1
a00bb704:  80 a4 60 30  cmp  %l1, 0x30
a00bb708:  12 80 00 57  bne  0xa00bb864
a00bb70c:  b0 10 20 10  mov  0x10, %i0
a00bb710:  d8 0a a0 03  ldub  [ %o2 + 3 ], %o4
a00bb714:  80 a3 20 30  cmp  %o4, 0x30
a00bb718:  22 80 00 17  be,a   0xa00bb774
a00bb71c:  f0 0a a0 04  ldub  [ %o2 + 4 ], %i0
a00bb720:  30 80 00 51  b,a   0xa00bb864
a00bb724:  7f ff 2c c6  call  0xa0086a3c
a00bb728:  90 10 20 10  mov  0x10, %o0
a00bb72c:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00bb730:  80 a3 e0 00  cmp  %o7, 0
a00bb734:  12 bf ff 9f  bne  0xa00bb5b0
a00bb738:  da 17 bf f6  lduh  [ %fp + -10 ], %o5
a00bb73c:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00bb740:  f0 0b 60 99  ldub  [ %o5 + 0x99 ], %i0	! 0xa802b099
a00bb744:  80 a6 20 01  cmp  %i0, 1
a00bb748:  22 80 00 40  be,a   0xa00bb848
a00bb74c:  c0 2b 60 99  clrb  [ %o5 + 0x99 ]
a00bb750:  10 bf ff 98  b  0xa00bb5b0
a00bb754:  da 17 bf f6  lduh  [ %fp + -10 ], %o5
a00bb758:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00bb75c:  d6 2a 20 99  stb  %o3, [ %o0 + 0x99 ]	! 0xa802b099
a00bb760:  90 10 20 10  mov  0x10, %o0
a00bb764:  7f ff 2c 93  call  0xa00869b0
a00bb768:  92 10 20 fa  mov  0xfa, %o1
a00bb76c:  10 bf ff c6  b  0xa00bb684
a00bb770:  c2 0e 20 01  ldub  [ %i0 + 1 ], %g1
a00bb774:  80 a6 20 2d  cmp  %i0, 0x2d
a00bb778:  12 80 00 3b  bne  0xa00bb864
a00bb77c:  b0 10 20 10  mov  0x10, %i0
a00bb780:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]
a00bb784:  9a 10 20 00  clr  %o5
a00bb788:  82 10 20 00  clr  %g1
a00bb78c:  c0 2a 80 01  clrb  [ %o2 + %g1 ]
a00bb790:  9a 03 60 01  inc  %o5
a00bb794:  82 0b 60 ff  and  %o5, 0xff, %g1
a00bb798:  80 a0 60 31  cmp  %g1, 0x31
a00bb79c:  28 bf ff fd  bleu,a   0xa00bb790
a00bb7a0:  c0 2a 80 01  clrb  [ %o2 + %g1 ]
a00bb7a4:  10 80 00 30  b  0xa00bb864
a00bb7a8:  b0 10 20 08  mov  8, %i0
a00bb7ac:  10 bf ff bd  b  0xa00bb6a0
a00bb7b0:  a4 10 20 07  mov  7, %l2
a00bb7b4:  80 a3 60 30  cmp  %o5, 0x30
a00bb7b8:  12 bf ff d2  bne  0xa00bb700
a00bb7bc:  94 14 60 40  or  %l1, 0x40, %o2
a00bb7c0:  de 0b 20 04  ldub  [ %o4 + 4 ], %o7
a00bb7c4:  80 a3 e0 2b  cmp  %o7, 0x2b
a00bb7c8:  32 bf ff cf  bne,a   0xa00bb704
a00bb7cc:  e2 0a a0 02  ldub  [ %o2 + 2 ], %l1
a00bb7d0:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00bb7d4:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00bb7d8:  9a 10 20 00  clr  %o5
a00bb7dc:  82 10 20 00  clr  %g1
a00bb7e0:  c0 2b 00 01  clrb  [ %o4 + %g1 ]
a00bb7e4:  9a 03 60 01  inc  %o5
a00bb7e8:  82 0b 60 ff  and  %o5, 0xff, %g1
a00bb7ec:  80 a0 60 31  cmp  %g1, 0x31
a00bb7f0:  28 bf ff fd  bleu,a   0xa00bb7e4
a00bb7f4:  c0 2b 00 01  clrb  [ %o4 + %g1 ]
a00bb7f8:  10 80 00 1b  b  0xa00bb864
a00bb7fc:  b0 10 20 08  mov  8, %i0
a00bb800:  e4 0e 20 04  ldub  [ %i0 + 4 ], %l2
a00bb804:  80 a4 a0 3b  cmp  %l2, 0x3b
a00bb808:  12 bf ff a6  bne  0xa00bb6a0
a00bb80c:  a4 10 20 0a  mov  0xa, %l2
a00bb810:  d8 0e 20 05  ldub  [ %i0 + 5 ], %o4
a00bb814:  80 a3 20 34  cmp  %o4, 0x34
a00bb818:  12 bf ff a3  bne  0xa00bb6a4
a00bb81c:  9a 0c a0 0f  and  %l2, 0xf, %o5
a00bb820:  da 0e 20 09  ldub  [ %i0 + 9 ], %o5
a00bb824:  80 a3 60 31  cmp  %o5, 0x31
a00bb828:  22 80 00 0a  be,a   0xa00bb850
a00bb82c:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a00bb830:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00bb834:  9a 10 63 f4  or  %g1, 0x3f4, %o5	! 0xa802cff4
a00bb838:  d2 13 60 18  lduh  [ %o5 + 0x18 ], %o1
a00bb83c:  82 0a 7b ff  and  %o1, -1025, %g1
a00bb840:  10 bf ff 98  b  0xa00bb6a0
a00bb844:  c2 33 60 18  sth  %g1, [ %o5 + 0x18 ]
a00bb848:  10 80 00 07  b  0xa00bb864
a00bb84c:  b0 10 20 10  mov  0x10, %i0
a00bb850:  9a 16 23 f4  or  %i0, 0x3f4, %o5
a00bb854:  de 13 60 18  lduh  [ %o5 + 0x18 ], %o7
a00bb858:  82 13 e4 00  or  %o7, 0x400, %g1
a00bb85c:  10 bf ff 91  b  0xa00bb6a0
a00bb860:  c2 33 60 18  sth  %g1, [ %o5 + 0x18 ]
a00bb864:  81 c7 e0 08  ret
a00bb868:  81 e8 00 00  restore
