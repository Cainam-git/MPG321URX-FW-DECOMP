# leon2m FUN_a00c573c 0xa00c573c-0xa00c5a00 (708 bytes)
a00c573c:  9d e3 bf 98  save  %sp, -104, %sp
a00c5740:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c5744:  9a 12 e2 90  or  %o3, 0x290, %o5	! 0xa802d290
a00c5748:  c2 0b 60 11  ldub  [ %o5 + 0x11 ], %g1
a00c574c:  80 a0 60 03  cmp  %g1, 3
a00c5750:  02 80 00 03  be  0xa00c575c
a00c5754:  90 10 20 03  mov  3, %o0
a00c5758:  d0 2b 60 11  stb  %o0, [ %o5 + 0x11 ]
a00c575c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c5760:  80 a6 20 02  cmp  %i0, 2
a00c5764:  02 80 00 63  be  0xa00c58f0
a00c5768:  80 a6 20 03  cmp  %i0, 3
a00c576c:  02 80 00 87  be  0xa00c5988
a00c5770:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c5774:  c2 0b 20 d7  ldub  [ %o4 + 0xd7 ], %g1	! 0xa802d0d7
a00c5778:  9a 00 7f d0  add  %g1, -48, %o5
a00c577c:  82 0b 60 ff  and  %o5, 0xff, %g1
a00c5780:  80 a0 60 64  cmp  %g1, 0x64
a00c5784:  18 80 00 03  bgu  0xa00c5790
a00c5788:  9a 10 20 ff  mov  0xff, %o5
a00c578c:  9a 10 00 01  mov  %g1, %o5
a00c5790:  80 a3 60 ff  cmp  %o5, 0xff
a00c5794:  02 80 00 99  be  0xa00c59f8
a00c5798:  82 10 20 ff  mov  0xff, %g1
a00c579c:  9e 12 e2 90  or  %o3, 0x290, %o7
a00c57a0:  80 a6 20 02  cmp  %i0, 2
a00c57a4:  02 80 00 56  be  0xa00c58fc
a00c57a8:  da 2b e0 12  stb  %o5, [ %o7 + 0x12 ]
a00c57ac:  80 a6 20 03  cmp  %i0, 3
a00c57b0:  02 80 00 4d  be  0xa00c58e4
a00c57b4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c57b8:  c2 0a 60 d8  ldub  [ %o1 + 0xd8 ], %g1	! 0xa802d0d8
a00c57bc:  94 00 7f d0  add  %g1, -48, %o2
a00c57c0:  82 0a a0 ff  and  %o2, 0xff, %g1
a00c57c4:  80 a0 60 64  cmp  %g1, 0x64
a00c57c8:  18 80 00 03  bgu  0xa00c57d4
a00c57cc:  9a 10 20 ff  mov  0xff, %o5
a00c57d0:  9a 10 00 01  mov  %g1, %o5
a00c57d4:  80 a3 60 ff  cmp  %o5, 0xff
a00c57d8:  02 80 00 88  be  0xa00c59f8
a00c57dc:  82 10 20 ff  mov  0xff, %g1
a00c57e0:  98 12 e2 90  or  %o3, 0x290, %o4
a00c57e4:  80 a6 20 02  cmp  %i0, 2
a00c57e8:  02 80 00 48  be  0xa00c5908
a00c57ec:  da 2b 20 13  stb  %o5, [ %o4 + 0x13 ]
a00c57f0:  80 a6 20 03  cmp  %i0, 3
a00c57f4:  22 80 00 7f  be,a   0xa00c59f0
a00c57f8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c57fc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c5800:  c2 08 60 d9  ldub  [ %g1 + 0xd9 ], %g1	! 0xa802d0d9
a00c5804:  90 00 7f d0  add  %g1, -48, %o0
a00c5808:  82 0a 20 ff  and  %o0, 0xff, %g1
a00c580c:  80 a0 60 64  cmp  %g1, 0x64
a00c5810:  18 80 00 03  bgu  0xa00c581c
a00c5814:  9a 10 20 ff  mov  0xff, %o5
a00c5818:  9a 10 00 01  mov  %g1, %o5
a00c581c:  80 a3 60 ff  cmp  %o5, 0xff
a00c5820:  02 80 00 76  be  0xa00c59f8
a00c5824:  82 10 20 ff  mov  0xff, %g1
a00c5828:  92 12 e2 90  or  %o3, 0x290, %o1
a00c582c:  40 00 4f ce  call  0xa00d9764
a00c5830:  da 2a 60 14  stb  %o5, [ %o1 + 0x14 ]
a00c5834:  7f ff cc 26  call  0xa00b88cc
a00c5838:  01 00 00 00  nop
a00c583c:  80 a6 20 02  cmp  %i0, 2
a00c5840:  02 80 00 35  be  0xa00c5914
a00c5844:  80 a6 20 03  cmp  %i0, 3
a00c5848:  02 80 00 53  be  0xa00c5994
a00c584c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c5850:  94 12 e0 78  or  %o3, 0x78, %o2	! 0xa802d078
a00c5854:  9e 10 20 30  mov  0x30, %o7
a00c5858:  98 10 20 35  mov  0x35, %o4
a00c585c:  92 10 20 36  mov  0x36, %o1
a00c5860:  90 10 20 2b  mov  0x2b, %o0
a00c5864:  82 10 20 0d  mov  0xd, %g1
a00c5868:  d8 2a e0 78  stb  %o4, [ %o3 + 0x78 ]
a00c586c:  d2 2a a0 01  stb  %o1, [ %o2 + 1 ]
a00c5870:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00c5874:  d0 2a a0 04  stb  %o0, [ %o2 + 4 ]
a00c5878:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00c587c:  80 a6 20 02  cmp  %i0, 2
a00c5880:  02 80 00 32  be  0xa00c5948
a00c5884:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00c5888:  80 a6 20 03  cmp  %i0, 3
a00c588c:  02 80 00 4f  be  0xa00c59c8
a00c5890:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c5894:  92 12 e0 d0  or  %o3, 0xd0, %o1	! 0xa802d0d0
a00c5898:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00c589c:  c0 2b 20 9c  clrb  [ %o4 + 0x9c ]	! 0xa802b09c
a00c58a0:  c0 2a e0 d0  clrb  [ %o3 + 0xd0 ]
a00c58a4:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c58a8:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c58ac:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c58b0:  80 a6 20 02  cmp  %i0, 2
a00c58b4:  02 80 00 2e  be  0xa00c596c
a00c58b8:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c58bc:  80 a6 20 03  cmp  %i0, 3
a00c58c0:  12 80 00 2e  bne  0xa00c5978
a00c58c4:  90 10 00 18  mov  %i0, %o0
a00c58c8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c58cc:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c58d0:  90 10 20 03  mov  3, %o0
a00c58d4:  40 02 0b c5  call  0xa01487e8
a00c58d8:  92 10 20 06  mov  6, %o1
a00c58dc:  10 80 00 47  b  0xa00c59f8
a00c58e0:  82 10 20 00  clr  %g1
a00c58e4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c58e8:  10 bf ff b5  b  0xa00c57bc
a00c58ec:  c2 0a 20 a0  ldub  [ %o0 + 0xa0 ], %g1	! 0xa802d0a0
a00c58f0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c58f4:  10 bf ff a1  b  0xa00c5778
a00c58f8:  c2 0a 60 47  ldub  [ %o1 + 0x47 ], %g1	! 0xa802d047
a00c58fc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c5900:  10 bf ff af  b  0xa00c57bc
a00c5904:  c2 08 60 48  ldub  [ %g1 + 0x48 ], %g1	! 0xa802d048
a00c5908:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c590c:  10 bf ff be  b  0xa00c5804
a00c5910:  c2 0b 60 49  ldub  [ %o5 + 0x49 ], %g1	! 0xa802d049
a00c5914:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c5918:  b0 13 e1 28  or  %o7, 0x128, %i0	! 0xa802d128
a00c591c:  94 10 20 30  mov  0x30, %o2
a00c5920:  82 10 20 35  mov  0x35, %g1
a00c5924:  9a 10 20 0d  mov  0xd, %o5
a00c5928:  98 10 20 36  mov  0x36, %o4
a00c592c:  96 10 20 2b  mov  0x2b, %o3
a00c5930:  c2 2b e1 28  stb  %g1, [ %o7 + 0x128 ]
a00c5934:  da 2e 20 05  stb  %o5, [ %i0 + 5 ]
a00c5938:  d8 2e 20 01  stb  %o4, [ %i0 + 1 ]
a00c593c:  d4 2e 20 03  stb  %o2, [ %i0 + 3 ]
a00c5940:  d6 2e 20 04  stb  %o3, [ %i0 + 4 ]
a00c5944:  d4 2e 20 02  stb  %o2, [ %i0 + 2 ]
a00c5948:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c594c:  b0 12 a0 40  or  %o2, 0x40, %i0	! 0xa802d040
a00c5950:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c5954:  c0 2b 60 9a  clrb  [ %o5 + 0x9a ]	! 0xa802b09a
a00c5958:  c0 2a a0 40  clrb  [ %o2 + 0x40 ]
a00c595c:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00c5960:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00c5964:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00c5968:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00c596c:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c5970:  94 16 21 28  or  %i0, 0x128, %o2	! 0xa802d128
a00c5974:  90 10 20 02  mov  2, %o0
a00c5978:  40 02 0b 9c  call  0xa01487e8
a00c597c:  92 10 20 06  mov  6, %o1
a00c5980:  10 80 00 1e  b  0xa00c59f8
a00c5984:  82 10 20 00  clr  %g1
a00c5988:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c598c:  10 bf ff 7b  b  0xa00c5778
a00c5990:  c2 0a a0 9f  ldub  [ %o2 + 0x9f ], %g1	! 0xa802d09f
a00c5994:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c5998:  90 13 21 08  or  %o4, 0x108, %o0	! 0xa802d108
a00c599c:  92 10 20 30  mov  0x30, %o1
a00c59a0:  9a 10 20 35  mov  0x35, %o5
a00c59a4:  96 10 20 0d  mov  0xd, %o3
a00c59a8:  94 10 20 36  mov  0x36, %o2
a00c59ac:  b0 10 20 2b  mov  0x2b, %i0
a00c59b0:  da 2b 21 08  stb  %o5, [ %o4 + 0x108 ]
a00c59b4:  d6 2a 20 05  stb  %o3, [ %o0 + 5 ]
a00c59b8:  d4 2a 20 01  stb  %o2, [ %o0 + 1 ]
a00c59bc:  d2 2a 20 03  stb  %o1, [ %o0 + 3 ]
a00c59c0:  f0 2a 20 04  stb  %i0, [ %o0 + 4 ]
a00c59c4:  d2 2a 20 02  stb  %o1, [ %o0 + 2 ]
a00c59c8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c59cc:  9e 12 20 98  or  %o0, 0x98, %o7	! 0xa802d098
a00c59d0:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c59d4:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c59d8:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00c59dc:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00c59e0:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00c59e4:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00c59e8:  10 bf ff b8  b  0xa00c58c8
a00c59ec:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00c59f0:  10 bf ff 85  b  0xa00c5804
a00c59f4:  c2 0b e0 a1  ldub  [ %o7 + 0xa1 ], %g1
a00c59f8:  81 c7 e0 08  ret
a00c59fc:  91 e8 00 01  restore  %g0, %g1, %o0
