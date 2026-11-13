# leon2m FUN_a0099658 0xa0099658-0xa0099864 (524 bytes)
a0099658:  9d e3 bf 98  save  %sp, -104, %sp
a009965c:  31 2a 00 ab  sethi  %hi(0xa802ac00), %i0
a0099660:  c2 06 23 ec  ld  [ %i0 + 0x3ec ], %g1	! 0xa802afec
a0099664:  80 a0 60 47  cmp  %g1, 0x47
a0099668:  02 80 00 09  be  0xa009968c
a009966c:  da 06 23 ec  ld  [ %i0 + 0x3ec ], %o5
a0099670:  80 a3 60 45  cmp  %o5, 0x45
a0099674:  08 80 00 7a  bleu  0xa009985c
a0099678:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a009967c:  a2 03 7f ba  add  %o5, -70, %l1
a0099680:  e2 2e 22 da  stb  %l1, [ %i0 + 0x2da ]
a0099684:  40 00 f2 0a  call  0xa00d5eac
a0099688:  91 e8 20 00  restore  %g0, 0, %o0
a009968c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a0099690:  a0 14 62 90  or  %l1, 0x290, %l0	! 0xa802d290
a0099694:  da 04 20 b0  ld  [ %l0 + 0xb0 ], %o5
a0099698:  90 10 20 01  mov  1, %o0
a009969c:  80 a3 60 00  cmp  %o5, 0
a00996a0:  12 80 00 3f  bne  0xa009979c
a00996a4:  d0 2c 20 4a  stb  %o0, [ %l0 + 0x4a ]
a00996a8:  7f ff a8 4f  call  0xa00837e4
a00996ac:  01 00 00 00  nop
a00996b0:  92 0a 20 ff  and  %o0, 0xff, %o1
a00996b4:  80 a2 60 01  cmp  %o1, 1
a00996b8:  02 80 00 4a  be  0xa00997e0
a00996bc:  98 14 62 90  or  %l1, 0x290, %o4
a00996c0:  e0 0b 20 1f  ldub  [ %o4 + 0x1f ], %l0
a00996c4:  80 a4 20 00  cmp  %l0, 0
a00996c8:  12 80 00 23  bne  0xa0099754
a00996cc:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a00996d0:  96 14 62 90  or  %l1, 0x290, %o3
a00996d4:  da 02 e0 a8  ld  [ %o3 + 0xa8 ], %o5
a00996d8:  80 8b 60 80  btst  0x80, %o5
a00996dc:  02 80 00 13  be  0xa0099728
a00996e0:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a00996e4:  94 12 63 f4  or  %o1, 0x3f4, %o2	! 0xa802cff4
a00996e8:  d8 12 a0 04  lduh  [ %o2 + 4 ], %o4
a00996ec:  21 3f ff e0  sethi  %hi(0xffff8000), %l0
a00996f0:  82 0b 00 10  and  %o4, %l0, %g1
a00996f4:  90 0b 7f 7f  and  %o5, -129, %o0
a00996f8:  a3 28 60 10  sll  %g1, 0x10, %l1
a00996fc:  80 a4 60 00  cmp  %l1, 0
a0099700:  12 80 00 2c  bne  0xa00997b0
a0099704:  d0 22 e0 a8  st  %o0, [ %o3 + 0xa8 ]
a0099708:  40 00 6e 5e  call  0xa00b5080
a009970c:  c0 26 23 ec  clr  [ %i0 + 0x3ec ]
a0099710:  40 02 2e 0d  call  0xa0124f44
a0099714:  01 00 00 00  nop
a0099718:  40 00 fe b9  call  0xa00d91fc
a009971c:  90 10 20 00  clr  %o0	! 0x0
a0099720:  40 01 02 99  call  0xa00da184
a0099724:  01 00 00 00  nop
a0099728:  40 00 f1 e1  call  0xa00d5eac
a009972c:  90 10 20 00  clr  %o0	! 0x0
a0099730:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a0099734:  d8 0b e0 8e  ldub  [ %o7 + 0x8e ], %o4	! 0xa802b08e
a0099738:  9a 13 20 02  or  %o4, 2, %o5
a009973c:  d4 06 23 ec  ld  [ %i0 + 0x3ec ], %o2
a0099740:  80 a2 a0 00  cmp  %o2, 0
a0099744:  02 80 00 46  be  0xa009985c
a0099748:  da 2b e0 8e  stb  %o5, [ %o7 + 0x8e ]
a009974c:  10 bf ff c9  b  0xa0099670
a0099750:  da 06 23 ec  ld  [ %i0 + 0x3ec ], %o5
a0099754:  96 13 63 f4  or  %o5, 0x3f4, %o3
a0099758:  da 12 e0 04  lduh  [ %o3 + 4 ], %o5
a009975c:  1f 3f ff e0  sethi  %hi(0xffff8000), %o7
a0099760:  94 0b 40 0f  and  %o5, %o7, %o2
a0099764:  93 2a a0 10  sll  %o2, 0x10, %o1
a0099768:  80 a2 60 00  cmp  %o1, 0
a009976c:  12 80 00 17  bne  0xa00997c8
a0099770:  c0 2b 20 1f  clrb  [ %o4 + 0x1f ]
a0099774:  40 00 6e 43  call  0xa00b5080
a0099778:  c0 26 23 ec  clr  [ %i0 + 0x3ec ]
a009977c:  40 02 2d f2  call  0xa0124f44
a0099780:  01 00 00 00  nop
a0099784:  40 00 fe 9e  call  0xa00d91fc
a0099788:  90 10 20 00  clr  %o0	! 0x0
a009978c:  40 01 02 b2  call  0xa00da254
a0099790:  01 00 00 00  nop
a0099794:  10 bf ff d0  b  0xa00996d4
a0099798:  96 14 62 90  or  %l1, 0x290, %o3
a009979c:  40 00 ec 7f  call  0xa00d4998
a00997a0:  c0 24 20 b0  clr  [ %l0 + 0xb0 ]
a00997a4:  40 00 f1 e6  call  0xa00d5f3c
a00997a8:  01 00 00 00  nop
a00997ac:  30 bf ff bf  b,a   0xa00996a8
a00997b0:  96 13 24 00  or  %o4, 0x400, %o3
a00997b4:  d6 32 a0 04  sth  %o3, [ %o2 + 4 ]
a00997b8:  90 10 20 04  mov  4, %o0
a00997bc:  7f ff 9c 3c  call  0xa00808ac
a00997c0:  92 10 20 00  clr  %o1
a00997c4:  30 bf ff d1  b,a   0xa0099708
a00997c8:  98 13 64 00  or  %o5, 0x400, %o4
a00997cc:  d8 32 e0 04  sth  %o4, [ %o3 + 4 ]
a00997d0:  90 10 20 04  mov  4, %o0
a00997d4:  7f ff 9c 36  call  0xa00808ac
a00997d8:  92 10 20 00  clr  %o1
a00997dc:  30 bf ff e6  b,a   0xa0099774
a00997e0:  40 00 fe 87  call  0xa00d91fc
a00997e4:  90 10 20 00  clr  %o0
a00997e8:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00997ec:  98 10 63 f4  or  %g1, 0x3f4, %o4	! 0xa802cff4
a00997f0:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a00997f4:  1f 3f ff e0  sethi  %hi(0xffff8000), %o7
a00997f8:  96 0b 40 0f  and  %o5, %o7, %o3
a00997fc:  95 2a e0 10  sll  %o3, 0x10, %o2
a0099800:  80 a2 a0 00  cmp  %o2, 0
a0099804:  32 80 00 11  bne,a   0xa0099848
a0099808:  90 13 64 00  or  %o5, 0x400, %o0
a009980c:  40 00 6e 1d  call  0xa00b5080
a0099810:  c0 26 23 ec  clr  [ %i0 + 0x3ec ]
a0099814:  c0 2c 21 a4  clrb  [ %l0 + 0x1a4 ]
a0099818:  90 10 20 00  clr  %o0
a009981c:  40 02 ba 93  call  0xa0148268
a0099820:  92 10 20 01  mov  1, %o1
a0099824:  90 10 20 01  mov  1, %o0
a0099828:  40 02 ba 90  call  0xa0148268
a009982c:  92 10 20 01  mov  1, %o1
a0099830:  40 01 02 89  call  0xa00da254
a0099834:  01 00 00 00  nop
a0099838:  7f ff a6 2f  call  0xa00830f4
a009983c:  90 10 20 00  clr  %o0	! 0x0
a0099840:  10 bf ff a0  b  0xa00996c0
a0099844:  98 14 62 90  or  %l1, 0x290, %o4
a0099848:  d0 33 20 04  sth  %o0, [ %o4 + 4 ]
a009984c:  90 10 20 04  mov  4, %o0
a0099850:  7f ff 9c 17  call  0xa00808ac
a0099854:  92 10 20 00  clr  %o1
a0099858:  30 bf ff ed  b,a   0xa009980c
a009985c:  81 c7 e0 08  ret
a0099860:  81 e8 00 00  restore
