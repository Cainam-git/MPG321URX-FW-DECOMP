# leon2m FUN_a009b59c 0xa009b59c-0xa009b864 (712 bytes)
a009b59c:  9d e3 bf 98  save  %sp, -104, %sp
a009b5a0:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a009b5a4:  a0 12 a3 f4  or  %o2, 0x3f4, %l0	! 0xa802cff4
a009b5a8:  da 14 20 04  lduh  [ %l0 + 4 ], %o5
a009b5ac:  13 3f ff e0  sethi  %hi(0xffff8000), %o1
a009b5b0:  90 0b 40 09  and  %o5, %o1, %o0
a009b5b4:  83 2a 20 10  sll  %o0, 0x10, %g1
a009b5b8:  80 a0 60 00  cmp  %g1, 0
a009b5bc:  12 80 00 1c  bne  0xa009b62c
a009b5c0:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a009b5c4:  c0 24 a3 ec  clr  [ %l2 + 0x3ec ]	! 0xa802afec
a009b5c8:  40 00 66 ae  call  0xa00b5080
a009b5cc:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a009b5d0:  a2 14 e2 90  or  %l3, 0x290, %l1	! 0xa802d290
a009b5d4:  d8 0c 61 aa  ldub  [ %l1 + 0x1aa ], %o4
a009b5d8:  80 a3 20 01  cmp  %o4, 1
a009b5dc:  02 80 00 22  be  0xa009b664
a009b5e0:  c2 0c 20 0a  ldub  [ %l0 + 0xa ], %g1
a009b5e4:  80 a0 60 00  cmp  %g1, 0
a009b5e8:  02 80 00 08  be  0xa009b608
a009b5ec:  80 a0 60 02  cmp  %g1, 2
a009b5f0:  02 80 00 5a  be  0xa009b758
a009b5f4:  90 10 20 15  mov  0x15, %o0
a009b5f8:  a0 14 e2 90  or  %l3, 0x290, %l0
a009b5fc:  c0 2c 21 aa  clrb  [ %l0 + 0x1aa ]
a009b600:  40 00 74 ae  call  0xa00b88b8
a009b604:  81 e8 00 00  restore
a009b608:  9e 10 20 0e  mov  0xe, %o7
a009b60c:  de 24 a3 ec  st  %o7, [ %l2 + 0x3ec ]
a009b610:  90 10 20 00  clr  %o0
a009b614:  40 00 56 7c  call  0xa00b1004
a009b618:  92 10 20 00  clr  %o1
a009b61c:  a0 14 e2 90  or  %l3, 0x290, %l0
a009b620:  c0 2c 21 aa  clrb  [ %l0 + 0x1aa ]
a009b624:  40 00 74 a5  call  0xa00b88b8
a009b628:  81 e8 00 00  restore
a009b62c:  96 13 64 00  or  %o5, 0x400, %o3
a009b630:  d6 34 20 04  sth  %o3, [ %l0 + 4 ]
a009b634:  90 10 20 04  mov  4, %o0
a009b638:  7f ff 94 9d  call  0xa00808ac
a009b63c:  92 10 20 00  clr  %o1
a009b640:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a009b644:  c0 24 a3 ec  clr  [ %l2 + 0x3ec ]	! 0xa802afec
a009b648:  40 00 66 8e  call  0xa00b5080
a009b64c:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a009b650:  a2 14 e2 90  or  %l3, 0x290, %l1	! 0xa802d290
a009b654:  d8 0c 61 aa  ldub  [ %l1 + 0x1aa ], %o4
a009b658:  80 a3 20 01  cmp  %o4, 1
a009b65c:  12 bf ff e2  bne  0xa009b5e4
a009b660:  c2 0c 20 0a  ldub  [ %l0 + 0xa ], %g1
a009b664:  80 a0 60 02  cmp  %g1, 2
a009b668:  02 80 00 5d  be  0xa009b7dc
a009b66c:  9a 10 20 09  mov  9, %o5
a009b670:  14 80 00 1b  bg  0xa009b6dc
a009b674:  80 a0 60 05  cmp  %g1, 5
a009b678:  80 a0 60 00  cmp  %g1, 0
a009b67c:  32 bf ff e0  bne,a   0xa009b5fc
a009b680:  a0 14 e2 90  or  %l3, 0x290, %l0
a009b684:  da 0c 61 82  ldub  [ %l1 + 0x182 ], %o5
a009b688:  d8 04 60 a8  ld  [ %l1 + 0xa8 ], %o4
a009b68c:  94 03 60 48  add  %o5, 0x48, %o2
a009b690:  96 10 20 09  mov  9, %o3
a009b694:  92 0b 37 ff  and  %o4, -2049, %o1
a009b698:  d6 2c 20 0a  stb  %o3, [ %l0 + 0xa ]
a009b69c:  d4 24 a3 ec  st  %o2, [ %l2 + 0x3ec ]
a009b6a0:  d2 24 60 a8  st  %o1, [ %l1 + 0xa8 ]
a009b6a4:  40 01 01 93  call  0xa00dbcf0
a009b6a8:  c0 2c 61 a9  clrb  [ %l1 + 0x1a9 ]
a009b6ac:  90 10 20 00  clr  %o0
a009b6b0:  40 00 56 55  call  0xa00b1004
a009b6b4:  92 10 20 01  mov  1, %o1
a009b6b8:  d0 04 60 a8  ld  [ %l1 + 0xa8 ], %o0
a009b6bc:  83 32 20 0b  srl  %o0, 0xb, %g1
a009b6c0:  9e 08 60 01  and  %g1, 1, %o7
a009b6c4:  e4 0c 61 82  ldub  [ %l1 + 0x182 ], %l2
a009b6c8:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a009b6cc:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a009b6d0:  e4 2c 20 56  stb  %l2, [ %l0 + 0x56 ]
a009b6d4:  10 bf ff c9  b  0xa009b5f8
a009b6d8:  de 2b 60 55  stb  %o7, [ %o5 + 0x55 ]
a009b6dc:  32 bf ff c8  bne,a   0xa009b5fc
a009b6e0:  a0 14 e2 90  or  %l3, 0x290, %l0
a009b6e4:  d6 04 60 a8  ld  [ %l1 + 0xa8 ], %o3
a009b6e8:  94 10 20 09  mov  9, %o2
a009b6ec:  82 10 20 fb  mov  0xfb, %g1
a009b6f0:  90 0a f7 ff  and  %o3, -2049, %o0
a009b6f4:  c2 24 a3 ec  st  %g1, [ %l2 + 0x3ec ]
a009b6f8:  d4 2c 20 0a  stb  %o2, [ %l0 + 0xa ]
a009b6fc:  d0 24 60 a8  st  %o0, [ %l1 + 0xa8 ]
a009b700:  40 01 01 7c  call  0xa00dbcf0
a009b704:  c0 2c 61 a9  clrb  [ %l1 + 0x1a9 ]
a009b708:  e4 0c 61 8a  ldub  [ %l1 + 0x18a ], %l2
a009b70c:  80 a4 a0 02  cmp  %l2, 2
a009b710:  02 80 00 2d  be  0xa009b7c4
a009b714:  90 10 20 00  clr  %o0
a009b718:  d2 0c 61 8b  ldub  [ %l1 + 0x18b ], %o1
a009b71c:  80 a2 60 02  cmp  %o1, 2
a009b720:  02 80 00 29  be  0xa009b7c4
a009b724:  90 10 20 01  mov  1, %o0
a009b728:  d8 0c 61 8c  ldub  [ %l1 + 0x18c ], %o4
a009b72c:  80 a3 20 02  cmp  %o4, 2
a009b730:  02 80 00 25  be  0xa009b7c4
a009b734:  90 10 20 02  mov  2, %o0
a009b738:  da 0c 61 8d  ldub  [ %l1 + 0x18d ], %o5
a009b73c:  80 a3 60 02  cmp  %o5, 2
a009b740:  02 80 00 21  be  0xa009b7c4
a009b744:  90 10 20 03  mov  3, %o0
a009b748:  40 00 23 98  call  0xa00a45a8
a009b74c:  a0 14 e2 90  or  %l3, 0x290, %l0
a009b750:  10 bf ff ac  b  0xa009b600
a009b754:  c0 2c 21 aa  clrb  [ %l0 + 0x1aa ]
a009b758:  d0 24 a3 ec  st  %o0, [ %l2 + 0x3ec ]
a009b75c:  90 10 20 02  mov  2, %o0
a009b760:  40 00 56 29  call  0xa00b1004
a009b764:  92 10 20 00  clr  %o1
a009b768:  90 10 20 00  clr  %o0
a009b76c:  40 00 36 28  call  0xa00a900c
a009b770:  92 10 20 01  mov  1, %o1
a009b774:  d0 0c 61 81  ldub  [ %l1 + 0x181 ], %o0
a009b778:  40 00 6d 04  call  0xa00b6b88
a009b77c:  92 10 20 00  clr  %o1
a009b780:  23 09 24 92  sethi  %hi(0x24924800), %l1
a009b784:  a0 0a 20 ff  and  %o0, 0xff, %l0
a009b788:  9e 14 61 25  or  %l1, 0x125, %o7
a009b78c:  80 54 00 0f  umul  %l0, %o7, %g0
a009b790:  93 40 00 00  rd  %y, %o1
a009b794:  9a 24 00 09  sub  %l0, %o1, %o5
a009b798:  99 33 60 01  srl  %o5, 1, %o4
a009b79c:  96 02 40 0c  add  %o1, %o4, %o3
a009b7a0:  83 32 e0 02  srl  %o3, 2, %g1
a009b7a4:  95 28 60 03  sll  %g1, 3, %o2
a009b7a8:  a4 22 80 01  sub  %o2, %g1, %l2
a009b7ac:  a2 24 00 12  sub  %l0, %l2, %l1
a009b7b0:  90 0c 60 ff  and  %l1, 0xff, %o0
a009b7b4:  40 00 37 a7  call  0xa00a9650
a009b7b8:  92 10 20 02  mov  2, %o1
a009b7bc:  10 bf ff 90  b  0xa009b5fc
a009b7c0:  a0 14 e2 90  or  %l3, 0x290, %l0
a009b7c4:  40 00 75 ae  call  0xa00b8e7c
a009b7c8:  a0 14 e2 90  or  %l3, 0x290, %l0
a009b7cc:  40 00 23 77  call  0xa00a45a8
a009b7d0:  01 00 00 00  nop
a009b7d4:  10 bf ff 8b  b  0xa009b600
a009b7d8:  c0 2c 21 aa  clrb  [ %l0 + 0x1aa ]
a009b7dc:  da 2c 20 0a  stb  %o5, [ %l0 + 0xa ]
a009b7e0:  92 10 20 00  clr  %o1
a009b7e4:  c0 2c 61 a9  clrb  [ %l1 + 0x1a9 ]
a009b7e8:  40 00 6c e8  call  0xa00b6b88
a009b7ec:  d0 0c 61 81  ldub  [ %l1 + 0x181 ], %o0
a009b7f0:  98 0a 20 ff  and  %o0, 0xff, %o4
a009b7f4:  92 03 20 5c  add  %o4, 0x5c, %o1
a009b7f8:  d2 24 a3 ec  st  %o1, [ %l2 + 0x3ec ]
a009b7fc:  90 10 20 02  mov  2, %o0
a009b800:  40 00 56 01  call  0xa00b1004
a009b804:  92 10 20 01  mov  1, %o1
a009b808:  d2 04 60 a8  ld  [ %l1 + 0xa8 ], %o1
a009b80c:  97 32 60 0b  srl  %o1, 0xb, %o3
a009b810:  90 0a e0 01  and  %o3, 1, %o0
a009b814:  d4 0c 61 81  ldub  [ %l1 + 0x181 ], %o2
a009b818:  e0 0c 60 11  ldub  [ %l1 + 0x11 ], %l0
a009b81c:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a009b820:  25 2a 00 97  sethi  %hi(0xa8025c00), %l2
a009b824:  1f 2a 00 97  sethi  %hi(0xa8025c00), %o7
a009b828:  d4 28 60 56  stb  %o2, [ %g1 + 0x56 ]
a009b82c:  d0 2c a0 55  stb  %o0, [ %l2 + 0x55 ]
a009b830:  80 8a 68 00  btst  0x800, %o1
a009b834:  02 80 00 06  be  0xa009b84c
a009b838:  e0 2b e0 54  stb  %l0, [ %o7 + 0x54 ]
a009b83c:  a0 10 20 0c  mov  0xc, %l0
a009b840:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a009b844:  10 bf ff 6d  b  0xa009b5f8
a009b848:  e0 2c 60 8f  stb  %l0, [ %l1 + 0x8f ]	! 0xa802b08f
a009b84c:  9e 12 68 00  or  %o1, 0x800, %o7
a009b850:  de 24 60 a8  st  %o7, [ %l1 + 0xa8 ]
a009b854:  40 00 ff b9  call  0xa00db738
a009b858:  a0 10 20 0c  mov  0xc, %l0
a009b85c:  10 bf ff fa  b  0xa009b844
a009b860:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
