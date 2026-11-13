# leon2m FUN_a00ca644 0xa00ca644-0xa00ca878 (564 bytes)
a00ca644:  9d e3 bf 98  save  %sp, -104, %sp
a00ca648:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ca64c:  80 a6 20 02  cmp  %i0, 2
a00ca650:  02 80 00 3a  be  0xa00ca738
a00ca654:  80 a6 20 03  cmp  %i0, 3
a00ca658:  02 80 00 58  be  0xa00ca7b8
a00ca65c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ca660:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00ca664:  96 08 60 ff  and  %g1, 0xff, %o3
a00ca668:  94 02 ff d0  add  %o3, -48, %o2
a00ca66c:  a0 0a a0 ff  and  %o2, 0xff, %l0
a00ca670:  80 a4 20 01  cmp  %l0, 1
a00ca674:  38 80 00 7f  bgu,a   0xa00ca870
a00ca678:  b0 10 20 ff  mov  0xff, %i0
a00ca67c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ca680:  98 14 62 90  or  %l1, 0x290, %o4	! 0xa802d290
a00ca684:  da 0b 21 e4  ldub  [ %o4 + 0x1e4 ], %o5
a00ca688:  80 a3 60 01  cmp  %o5, 1
a00ca68c:  02 80 00 68  be  0xa00ca82c
a00ca690:  80 a4 20 01  cmp  %l0, 1
a00ca694:  02 80 00 6f  be  0xa00ca850
a00ca698:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a00ca69c:  7f ff b8 8c  call  0xa00b88cc
a00ca6a0:  01 00 00 00  nop
a00ca6a4:  80 a6 20 02  cmp  %i0, 2
a00ca6a8:  02 80 00 27  be  0xa00ca744
a00ca6ac:  80 a6 20 03  cmp  %i0, 3
a00ca6b0:  02 80 00 45  be  0xa00ca7c4
a00ca6b4:  9e 10 20 30  mov  0x30, %o7
a00ca6b8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ca6bc:  94 12 20 78  or  %o0, 0x78, %o2	! 0xa802d078
a00ca6c0:  a2 10 20 35  mov  0x35, %l1
a00ca6c4:  82 10 20 36  mov  0x36, %g1
a00ca6c8:  98 10 20 2b  mov  0x2b, %o4
a00ca6cc:  9a 10 20 0d  mov  0xd, %o5
a00ca6d0:  e2 2a 20 78  stb  %l1, [ %o0 + 0x78 ]
a00ca6d4:  c2 2a a0 01  stb  %g1, [ %o2 + 1 ]
a00ca6d8:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00ca6dc:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00ca6e0:  da 2a a0 05  stb  %o5, [ %o2 + 5 ]
a00ca6e4:  80 a6 20 02  cmp  %i0, 2
a00ca6e8:  02 80 00 24  be  0xa00ca778
a00ca6ec:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00ca6f0:  80 a6 20 03  cmp  %i0, 3
a00ca6f4:  02 80 00 41  be  0xa00ca7f8
a00ca6f8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ca6fc:  9a 13 20 d0  or  %o4, 0xd0, %o5	! 0xa802d0d0
a00ca700:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00ca704:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]	! 0xa802b09c
a00ca708:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00ca70c:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00ca710:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00ca714:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00ca718:  80 a6 20 02  cmp  %i0, 2
a00ca71c:  02 80 00 20  be  0xa00ca79c
a00ca720:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00ca724:  80 a6 20 03  cmp  %i0, 3
a00ca728:  12 80 00 20  bne  0xa00ca7a8
a00ca72c:  90 10 00 18  mov  %i0, %o0
a00ca730:  10 80 00 3c  b  0xa00ca820
a00ca734:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ca738:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ca73c:  10 bf ff ca  b  0xa00ca664
a00ca740:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00ca744:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00ca748:  a0 13 e1 28  or  %o7, 0x128, %l0	! 0xa802d128
a00ca74c:  b0 10 20 30  mov  0x30, %i0
a00ca750:  82 10 20 35  mov  0x35, %g1
a00ca754:  98 10 20 0d  mov  0xd, %o4
a00ca758:  9a 10 20 36  mov  0x36, %o5
a00ca75c:  96 10 20 2b  mov  0x2b, %o3
a00ca760:  c2 2b e1 28  stb  %g1, [ %o7 + 0x128 ]
a00ca764:  d8 2c 20 05  stb  %o4, [ %l0 + 5 ]
a00ca768:  da 2c 20 01  stb  %o5, [ %l0 + 1 ]
a00ca76c:  f0 2c 20 03  stb  %i0, [ %l0 + 3 ]
a00ca770:  d6 2c 20 04  stb  %o3, [ %l0 + 4 ]
a00ca774:  f0 2c 20 02  stb  %i0, [ %l0 + 2 ]
a00ca778:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ca77c:  92 12 a0 40  or  %o2, 0x40, %o1	! 0xa802d040
a00ca780:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00ca784:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00ca788:  c0 2a a0 40  clrb  [ %o2 + 0x40 ]
a00ca78c:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00ca790:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00ca794:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00ca798:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00ca79c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ca7a0:  94 12 21 28  or  %o0, 0x128, %o2	! 0xa802d128
a00ca7a4:  90 10 20 02  mov  2, %o0
a00ca7a8:  40 01 f8 10  call  0xa01487e8
a00ca7ac:  92 10 20 06  mov  6, %o1
a00ca7b0:  10 80 00 30  b  0xa00ca870
a00ca7b4:  b0 10 20 00  clr  %i0
a00ca7b8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ca7bc:  10 bf ff aa  b  0xa00ca664
a00ca7c0:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00ca7c4:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00ca7c8:  90 16 21 08  or  %i0, 0x108, %o0	! 0xa802d108
a00ca7cc:  a2 10 20 30  mov  0x30, %l1
a00ca7d0:  96 10 20 35  mov  0x35, %o3
a00ca7d4:  a0 10 20 0d  mov  0xd, %l0
a00ca7d8:  94 10 20 36  mov  0x36, %o2
a00ca7dc:  92 10 20 2b  mov  0x2b, %o1
a00ca7e0:  d6 2e 21 08  stb  %o3, [ %i0 + 0x108 ]
a00ca7e4:  e0 2a 20 05  stb  %l0, [ %o0 + 5 ]
a00ca7e8:  d4 2a 20 01  stb  %o2, [ %o0 + 1 ]
a00ca7ec:  e2 2a 20 03  stb  %l1, [ %o0 + 3 ]
a00ca7f0:  d2 2a 20 04  stb  %o1, [ %o0 + 4 ]
a00ca7f4:  e2 2a 20 02  stb  %l1, [ %o0 + 2 ]
a00ca7f8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ca7fc:  b0 12 e0 98  or  %o3, 0x98, %i0	! 0xa802d098
a00ca800:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00ca804:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00ca808:  c0 2a e0 98  clrb  [ %o3 + 0x98 ]
a00ca80c:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00ca810:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00ca814:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00ca818:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00ca81c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ca820:  94 14 61 08  or  %l1, 0x108, %o2	! 0xa802d108
a00ca824:  10 bf ff e1  b  0xa00ca7a8
a00ca828:  90 10 20 03  mov  3, %o0
a00ca82c:  7f ff 19 e8  call  0xa0090fcc
a00ca830:  01 00 00 00  nop
a00ca834:  83 2a 20 10  sll  %o0, 0x10, %g1
a00ca838:  9f 30 60 10  srl  %g1, 0x10, %o7
a00ca83c:  80 a3 e1 0a  cmp  %o7, 0x10a
a00ca840:  12 bf ff 95  bne  0xa00ca694
a00ca844:  80 a4 20 01  cmp  %l0, 1
a00ca848:  10 80 00 0a  b  0xa00ca870
a00ca84c:  b0 10 20 ff  mov  0xff, %i0
a00ca850:  d4 12 23 f4  lduh  [ %o0 + 0x3f4 ], %o2
a00ca854:  92 14 62 90  or  %l1, 0x290, %o1
a00ca858:  a2 0a be ff  and  %o2, -257, %l1
a00ca85c:  e0 2a 61 e4  stb  %l0, [ %o1 + 0x1e4 ]
a00ca860:  e2 32 23 f4  sth  %l1, [ %o0 + 0x3f4 ]
a00ca864:  40 00 40 ba  call  0xa00dab4c
a00ca868:  90 10 20 00  clr  %o0
a00ca86c:  30 bf ff 8c  b,a   0xa00ca69c
a00ca870:  81 c7 e0 08  ret
a00ca874:  81 e8 00 00  restore
