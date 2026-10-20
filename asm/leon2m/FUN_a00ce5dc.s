# leon2m FUN_a00ce5dc 0xa00ce5dc-0xa00ce958 (892 bytes)
a00ce5dc:  9d e3 bf 98  save  %sp, -104, %sp
a00ce5e0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ce5e4:  80 a6 20 02  cmp  %i0, 2
a00ce5e8:  02 80 00 76  be  0xa00ce7c0
a00ce5ec:  80 a6 20 03  cmp  %i0, 3
a00ce5f0:  02 80 00 77  be  0xa00ce7cc
a00ce5f4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ce5f8:  c2 0a 60 d6  ldub  [ %o1 + 0xd6 ], %g1	! 0xa802d0d6
a00ce5fc:  98 08 60 ff  and  %g1, 0xff, %o4
a00ce600:  96 03 3f d0  add  %o4, -48, %o3
a00ce604:  94 0a e0 ff  and  %o3, 0xff, %o2
a00ce608:  80 a2 a0 01  cmp  %o2, 1
a00ce60c:  38 80 00 d1  bgu,a   0xa00ce950
a00ce610:  b0 10 20 ff  mov  0xff, %i0
a00ce614:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00ce618:  9a 14 22 90  or  %l0, 0x290, %o5	! 0xa802d290
a00ce61c:  de 03 60 b0  ld  [ %o5 + 0xb0 ], %o7
a00ce620:  80 a3 e0 00  cmp  %o7, 0
a00ce624:  22 80 00 04  be,a   0xa00ce634
a00ce628:  e2 0b 60 1f  ldub  [ %o5 + 0x1f ], %l1
a00ce62c:  10 80 00 c9  b  0xa00ce950
a00ce630:  b0 10 20 ff  mov  0xff, %i0
a00ce634:  80 a4 60 00  cmp  %l1, 0
a00ce638:  32 80 00 c6  bne,a   0xa00ce950
a00ce63c:  b0 10 20 ff  mov  0xff, %i0
a00ce640:  7f fe d4 69  call  0xa00837e4
a00ce644:  01 00 00 00  nop
a00ce648:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00ce64c:  80 a3 60 01  cmp  %o5, 1
a00ce650:  02 bf ff f7  be  0xa00ce62c
a00ce654:  80 a6 20 02  cmp  %i0, 2
a00ce658:  02 80 00 7e  be  0xa00ce850
a00ce65c:  80 a6 20 03  cmp  %i0, 3
a00ce660:  02 80 00 7f  be  0xa00ce85c
a00ce664:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ce668:  c2 0a 60 d7  ldub  [ %o1 + 0xd7 ], %g1	! 0xa802d0d7
a00ce66c:  94 08 60 ff  and  %g1, 0xff, %o2
a00ce670:  98 02 bf d0  add  %o2, -48, %o4
a00ce674:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00ce678:  80 a3 60 08  cmp  %o5, 8
a00ce67c:  18 bf ff ec  bgu  0xa00ce62c
a00ce680:  96 14 22 90  or  %l0, 0x290, %o3
a00ce684:  c2 0a e0 1f  ldub  [ %o3 + 0x1f ], %g1
a00ce688:  80 a0 60 02  cmp  %g1, 2
a00ce68c:  02 bf ff e8  be  0xa00ce62c
a00ce690:  80 a3 60 04  cmp  %o5, 4
a00ce694:  02 80 00 51  be  0xa00ce7d8
a00ce698:  80 a0 60 01  cmp  %g1, 1
a00ce69c:  a2 14 22 90  or  %l0, 0x290, %l1
a00ce6a0:  7f fe d4 51  call  0xa00837e4
a00ce6a4:  d8 2c 61 a4  stb  %o4, [ %l1 + 0x1a4 ]
a00ce6a8:  98 0a 20 ff  and  %o0, 0xff, %o4
a00ce6ac:  80 a3 20 01  cmp  %o4, 1
a00ce6b0:  22 80 00 88  be,a   0xa00ce8d0
a00ce6b4:  de 04 60 b0  ld  [ %l1 + 0xb0 ], %o7
a00ce6b8:  7f fe d4 4b  call  0xa00837e4
a00ce6bc:  01 00 00 00  nop
a00ce6c0:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00ce6c4:  80 a4 60 01  cmp  %l1, 1
a00ce6c8:  02 80 00 9b  be  0xa00ce934
a00ce6cc:  9a 14 22 90  or  %l0, 0x290, %o5
a00ce6d0:  7f fe d4 45  call  0xa00837e4
a00ce6d4:  01 00 00 00  nop
a00ce6d8:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00ce6dc:  80 a3 60 01  cmp  %o5, 1
a00ce6e0:  02 80 00 82  be  0xa00ce8e8
a00ce6e4:  a2 14 22 90  or  %l0, 0x290, %l1
a00ce6e8:  7f fe d2 83  call  0xa00830f4
a00ce6ec:  90 10 20 00  clr  %o0
a00ce6f0:  40 00 2e d9  call  0xa00da254
a00ce6f4:  01 00 00 00  nop
a00ce6f8:  82 14 22 90  or  %l0, 0x290, %g1
a00ce6fc:  e2 00 60 a8  ld  [ %g1 + 0xa8 ], %l1
a00ce700:  21 00 00 10  sethi  %hi(0x4000), %l0
a00ce704:  80 8c 40 10  btst  %l1, %l0
a00ce708:  12 80 00 6f  bne  0xa00ce8c4
a00ce70c:  01 00 00 00  nop
a00ce710:  7f ff a8 6f  call  0xa00b88cc
a00ce714:  01 00 00 00  nop
a00ce718:  80 a6 20 02  cmp  %i0, 2
a00ce71c:  02 80 00 33  be  0xa00ce7e8
a00ce720:  80 a6 20 03  cmp  %i0, 3
a00ce724:  02 80 00 51  be  0xa00ce868
a00ce728:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00ce72c:  94 14 20 78  or  %l0, 0x78, %o2	! 0xa802d078
a00ce730:  92 10 20 30  mov  0x30, %o1
a00ce734:  a2 10 20 35  mov  0x35, %l1
a00ce738:  9e 10 20 36  mov  0x36, %o7
a00ce73c:  98 10 20 2b  mov  0x2b, %o4
a00ce740:  96 10 20 0d  mov  0xd, %o3
a00ce744:  e2 2c 20 78  stb  %l1, [ %l0 + 0x78 ]
a00ce748:  de 2a a0 01  stb  %o7, [ %o2 + 1 ]
a00ce74c:  d2 2a a0 03  stb  %o1, [ %o2 + 3 ]
a00ce750:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00ce754:  d6 2a a0 05  stb  %o3, [ %o2 + 5 ]
a00ce758:  80 a6 20 02  cmp  %i0, 2
a00ce75c:  02 80 00 30  be  0xa00ce81c
a00ce760:  d2 2a a0 02  stb  %o1, [ %o2 + 2 ]
a00ce764:  80 a6 20 03  cmp  %i0, 3
a00ce768:  02 80 00 4d  be  0xa00ce89c
a00ce76c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ce770:  96 13 20 d0  or  %o4, 0xd0, %o3	! 0xa802d0d0
a00ce774:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00ce778:  c0 2b e0 9c  clrb  [ %o7 + 0x9c ]	! 0xa802b09c
a00ce77c:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00ce780:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00ce784:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00ce788:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00ce78c:  80 a6 20 02  cmp  %i0, 2
a00ce790:  02 80 00 2c  be  0xa00ce840
a00ce794:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00ce798:  80 a6 20 03  cmp  %i0, 3
a00ce79c:  12 80 00 05  bne  0xa00ce7b0
a00ce7a0:  90 10 00 18  mov  %i0, %o0
a00ce7a4:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ce7a8:  94 14 61 08  or  %l1, 0x108, %o2	! 0xa802d108
a00ce7ac:  90 10 20 03  mov  3, %o0
a00ce7b0:  40 01 e8 0e  call  0xa01487e8
a00ce7b4:  92 10 20 06  mov  6, %o1
a00ce7b8:  10 80 00 66  b  0xa00ce950
a00ce7bc:  b0 10 20 00  clr  %i0
a00ce7c0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ce7c4:  10 bf ff 8e  b  0xa00ce5fc
a00ce7c8:  c2 08 60 46  ldub  [ %g1 + 0x46 ], %g1	! 0xa802d046
a00ce7cc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ce7d0:  10 bf ff 8b  b  0xa00ce5fc
a00ce7d4:  c2 0a 20 9e  ldub  [ %o0 + 0x9e ], %g1	! 0xa802d09e
a00ce7d8:  12 bf ff b2  bne  0xa00ce6a0
a00ce7dc:  a2 14 22 90  or  %l0, 0x290, %l1
a00ce7e0:  10 80 00 5c  b  0xa00ce950
a00ce7e4:  b0 10 20 ff  mov  0xff, %i0
a00ce7e8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ce7ec:  b0 12 e1 28  or  %o3, 0x128, %i0	! 0xa802d128
a00ce7f0:  90 10 20 30  mov  0x30, %o0
a00ce7f4:  98 10 20 35  mov  0x35, %o4
a00ce7f8:  94 10 20 0d  mov  0xd, %o2
a00ce7fc:  92 10 20 36  mov  0x36, %o1
a00ce800:  9a 10 20 2b  mov  0x2b, %o5
a00ce804:  d8 2a e1 28  stb  %o4, [ %o3 + 0x128 ]
a00ce808:  d4 2e 20 05  stb  %o2, [ %i0 + 5 ]
a00ce80c:  d2 2e 20 01  stb  %o1, [ %i0 + 1 ]
a00ce810:  d0 2e 20 03  stb  %o0, [ %i0 + 3 ]
a00ce814:  da 2e 20 04  stb  %o5, [ %i0 + 4 ]
a00ce818:  d0 2e 20 02  stb  %o0, [ %i0 + 2 ]
a00ce81c:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00ce820:  94 16 20 40  or  %i0, 0x40, %o2	! 0xa802d040
a00ce824:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00ce828:  c0 28 60 9a  clrb  [ %g1 + 0x9a ]	! 0xa802b09a
a00ce82c:  c0 2e 20 40  clrb  [ %i0 + 0x40 ]
a00ce830:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00ce834:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00ce838:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00ce83c:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00ce840:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00ce844:  94 14 21 28  or  %l0, 0x128, %o2	! 0xa802d128
a00ce848:  10 bf ff da  b  0xa00ce7b0
a00ce84c:  90 10 20 02  mov  2, %o0
a00ce850:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ce854:  10 bf ff 86  b  0xa00ce66c
a00ce858:  c2 08 60 47  ldub  [ %g1 + 0x47 ], %g1	! 0xa802d047
a00ce85c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ce860:  10 bf ff 83  b  0xa00ce66c
a00ce864:  c2 0a 20 9f  ldub  [ %o0 + 0x9f ], %g1	! 0xa802d09f
a00ce868:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ce86c:  9e 12 21 08  or  %o0, 0x108, %o7	! 0xa802d108
a00ce870:  a0 10 20 30  mov  0x30, %l0
a00ce874:  9a 10 20 35  mov  0x35, %o5
a00ce878:  b0 10 20 0d  mov  0xd, %i0
a00ce87c:  82 10 20 36  mov  0x36, %g1
a00ce880:  a2 10 20 2b  mov  0x2b, %l1
a00ce884:  da 2a 21 08  stb  %o5, [ %o0 + 0x108 ]
a00ce888:  f0 2b e0 05  stb  %i0, [ %o7 + 5 ]
a00ce88c:  c2 2b e0 01  stb  %g1, [ %o7 + 1 ]
a00ce890:  e0 2b e0 03  stb  %l0, [ %o7 + 3 ]
a00ce894:  e2 2b e0 04  stb  %l1, [ %o7 + 4 ]
a00ce898:  e0 2b e0 02  stb  %l0, [ %o7 + 2 ]
a00ce89c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00ce8a0:  90 13 60 98  or  %o5, 0x98, %o0	! 0xa802d098
a00ce8a4:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00ce8a8:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]	! 0xa802b098
a00ce8ac:  c0 2b 60 98  clrb  [ %o5 + 0x98 ]
a00ce8b0:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00ce8b4:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00ce8b8:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00ce8bc:  10 bf ff ba  b  0xa00ce7a4
a00ce8c0:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00ce8c4:  40 00 1d 05  call  0xa00d5cd8
a00ce8c8:  01 00 00 00  nop
a00ce8cc:  30 bf ff 91  b,a   0xa00ce710
a00ce8d0:  80 a3 e0 00  cmp  %o7, 0
a00ce8d4:  02 bf ff 79  be  0xa00ce6b8
a00ce8d8:  01 00 00 00  nop
a00ce8dc:  40 00 1d 98  call  0xa00d5f3c
a00ce8e0:  c0 24 60 b0  clr  [ %l1 + 0xb0 ]
a00ce8e4:  30 bf ff 75  b,a   0xa00ce6b8
a00ce8e8:  d0 04 60 a8  ld  [ %l1 + 0xa8 ], %o0
a00ce8ec:  80 8a 20 80  btst  0x80, %o0
a00ce8f0:  02 bf ff 7e  be  0xa00ce6e8
a00ce8f4:  01 00 00 00  nop
a00ce8f8:  7f ff 09 b8  call  0xa0090fd8
a00ce8fc:  01 00 00 00  nop
a00ce900:  de 04 60 a8  ld  [ %l1 + 0xa8 ], %o7
a00ce904:  98 0b ff 7f  and  %o7, -129, %o4
a00ce908:  40 01 59 8f  call  0xa0124f44
a00ce90c:  d8 24 60 a8  st  %o4, [ %l1 + 0xa8 ]
a00ce910:  40 00 2a 3b  call  0xa00d91fc
a00ce914:  90 10 20 00  clr  %o0
a00ce918:  40 00 2e 1b  call  0xa00da184
a00ce91c:  01 00 00 00  nop
a00ce920:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00ce924:  d6 0a 60 8e  ldub  [ %o1 + 0x8e ], %o3	! 0xa802b08e
a00ce928:  94 12 e0 02  or  %o3, 2, %o2
a00ce92c:  10 bf ff 6f  b  0xa00ce6e8
a00ce930:  d4 2a 60 8e  stb  %o2, [ %o1 + 0x8e ]
a00ce934:  c2 0b 60 1f  ldub  [ %o5 + 0x1f ], %g1
a00ce938:  80 a0 60 00  cmp  %g1, 0
a00ce93c:  02 bf ff 65  be  0xa00ce6d0
a00ce940:  01 00 00 00  nop
a00ce944:  40 00 2e 44  call  0xa00da254
a00ce948:  c0 2b 60 1f  clrb  [ %o5 + 0x1f ]
a00ce94c:  30 bf ff 61  b,a   0xa00ce6d0
a00ce950:  81 c7 e0 08  ret
a00ce954:  81 e8 00 00  restore
