# leon2m FUN_a009a8dc 0xa009a8dc-0xa009aa34 (344 bytes)
a009a8dc:  9d e3 bf 98  save  %sp, -104, %sp
a009a8e0:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009a8e4:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009a8e8:  90 02 7f ad  add  %o1, -83, %o0
a009a8ec:  40 00 3a b4  call  0xa00a93bc
a009a8f0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009a8f4:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009a8f8:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009a8fc:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009a900:  9e 02 3f ae  add  %o0, -82, %o7
a009a904:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009a908:  80 5b c0 19  smul  %o7, %i1, %g0
a009a90c:  93 40 00 00  rd  %y, %o1
a009a910:  82 22 40 0a  sub  %o1, %o2, %g1
a009a914:  b0 00 40 01  add  %g1, %g1, %i0
a009a918:  98 06 00 01  add  %i0, %g1, %o4
a009a91c:  96 23 c0 0c  sub  %o7, %o4, %o3
a009a920:  9a 02 e0 53  add  %o3, 0x53, %o5
a009a924:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009a928:  40 00 41 02  call  0xa00aad30
a009a92c:  90 0a e0 ff  and  %o3, 0xff, %o0
a009a930:  94 0a 20 ff  and  %o0, 0xff, %o2
a009a934:  80 a2 a0 01  cmp  %o2, 1
a009a938:  12 bf ff f2  bne  0xa009a900
a009a93c:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009a940:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009a944:  80 a3 60 53  cmp  %o5, 0x53
a009a948:  08 80 00 1e  bleu  0xa009a9c0
a009a94c:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a009a950:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a009a954:  b2 13 22 90  or  %o4, 0x290, %i1	! 0xa802d290
a009a958:  d2 06 60 a8  ld  [ %i1 + 0xa8 ], %o1
a009a95c:  03 00 00 04  sethi  %hi(0x1000), %g1
a009a960:  b0 0b 60 01  and  %o5, 1, %i0
a009a964:  9e 2a 40 01  andn  %o1, %g1, %o7
a009a968:  9b 2e 20 0c  sll  %i0, 0xc, %o5
a009a96c:  96 13 c0 0d  or  %o7, %o5, %o3
a009a970:  d6 26 60 a8  st  %o3, [ %i1 + 0xa8 ]
a009a974:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009a978:  96 03 7f ad  add  %o5, -83, %o3
a009a97c:  90 0a e0 ff  and  %o3, 0xff, %o0
a009a980:  40 00 3b 34  call  0xa00a9650
a009a984:  92 10 20 01  mov  1, %o1
a009a988:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a009a98c:  f2 0e 60 56  ldub  [ %i1 + 0x56 ], %i1	! 0xa8025c56
a009a990:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a009a994:  90 0e 60 ff  and  %i1, 0xff, %o0
a009a998:  94 03 ff ad  add  %o7, -83, %o2
a009a99c:  b4 02 20 01  add  %o0, 1, %i2
a009a9a0:  80 a2 80 1a  cmp  %o2, %i2
a009a9a4:  22 80 00 1f  be,a   0xa009aa20
a009a9a8:  b2 06 60 01  inc  %i1
a009a9ac:  b0 06 60 01  add  %i1, 1, %i0
a009a9b0:  b2 0e 20 ff  and  %i0, 0xff, %i1
a009a9b4:  b0 10 20 01  mov  1, %i0
a009a9b8:  40 00 35 e1  call  0xa00a813c
a009a9bc:  95 e8 20 01  restore  %g0, 1, %o2
a009a9c0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a009a9c4:  d2 0e 60 56  ldub  [ %i1 + 0x56 ], %o1
a009a9c8:  94 13 22 90  or  %o4, 0x290, %o2
a009a9cc:  c2 02 a0 a8  ld  [ %o2 + 0xa8 ], %g1
a009a9d0:  9a 0a 60 01  and  %o1, 1, %o5
a009a9d4:  31 00 00 04  sethi  %hi(0x1000), %i0
a009a9d8:  9e 28 40 18  andn  %g1, %i0, %o7
a009a9dc:  97 2b 60 0c  sll  %o5, 0xc, %o3
a009a9e0:  90 13 c0 0b  or  %o7, %o3, %o0
a009a9e4:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009a9e8:  d0 22 a0 a8  st  %o0, [ %o2 + 0xa8 ]
a009a9ec:  96 03 7f ad  add  %o5, -83, %o3
a009a9f0:  90 0a e0 ff  and  %o3, 0xff, %o0
a009a9f4:  40 00 3b 17  call  0xa00a9650
a009a9f8:  92 10 20 01  mov  1, %o1
a009a9fc:  f2 0e 60 56  ldub  [ %i1 + 0x56 ], %i1
a009aa00:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a009aa04:  90 0e 60 ff  and  %i1, 0xff, %o0
a009aa08:  94 03 ff ad  add  %o7, -83, %o2
a009aa0c:  b4 02 20 01  add  %o0, 1, %i2
a009aa10:  80 a2 80 1a  cmp  %o2, %i2
a009aa14:  12 bf ff e7  bne  0xa009a9b0
a009aa18:  b0 06 60 01  add  %i1, 1, %i0
a009aa1c:  b2 06 60 01  inc  %i1
a009aa20:  b2 0e 60 ff  and  %i1, 0xff, %i1
a009aa24:  b0 10 20 01  mov  1, %i0
a009aa28:  40 00 35 c5  call  0xa00a813c
a009aa2c:  95 e8 20 00  restore  %g0, 0, %o2
a009aa30:  01 00 00 00  nop
