# leon2m FUN_a00945a8 0xa00945a8-0xa009478c (484 bytes)
a00945a8:  9d e3 bf 98  save  %sp, -104, %sp
a00945ac:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00945b0:  b4 16 62 90  or  %i1, 0x290, %i2	! 0xa802d290
a00945b4:  c2 0e a1 a3  ldub  [ %i2 + 0x1a3 ], %g1
a00945b8:  80 a0 60 00  cmp  %g1, 0
a00945bc:  12 80 00 10  bne  0xa00945fc
a00945c0:  80 a0 60 01  cmp  %g1, 1
a00945c4:  c2 0e a1 a5  ldub  [ %i2 + 0x1a5 ], %g1
a00945c8:  80 a0 60 00  cmp  %g1, 0
a00945cc:  02 80 00 6e  be  0xa0094784
a00945d0:  90 10 20 00  clr  %o0
a00945d4:  92 10 20 00  clr  %o1
a00945d8:  40 00 49 70  call  0xa00a6b98
a00945dc:  94 10 20 01  mov  1, %o2
a00945e0:  d2 0e a1 a5  ldub  [ %i2 + 0x1a5 ], %o1
a00945e4:  90 02 7f ff  add  %o1, -1, %o0
a00945e8:  d0 2e a1 a5  stb  %o0, [ %i2 + 0x1a5 ]
a00945ec:  b0 10 20 00  clr  %i0
a00945f0:  b2 10 20 00  clr  %i1
a00945f4:  40 00 49 69  call  0xa00a6b98
a00945f8:  95 e8 20 00  restore  %g0, 0, %o2
a00945fc:  02 80 00 05  be  0xa0094610
a0094600:  80 a0 60 02  cmp  %g1, 2
a0094604:  12 80 00 60  bne  0xa0094784
a0094608:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009460c:  30 80 00 0d  b,a   0xa0094640
a0094610:  d4 0e a1 a7  ldub  [ %i2 + 0x1a7 ], %o2
a0094614:  80 a2 a0 00  cmp  %o2, 0
a0094618:  02 80 00 5b  be  0xa0094784
a009461c:  90 10 20 01  mov  1, %o0
a0094620:  92 10 20 00  clr  %o1
a0094624:  40 00 49 5d  call  0xa00a6b98
a0094628:  94 10 20 01  mov  1, %o2
a009462c:  d8 0e a1 a7  ldub  [ %i2 + 0x1a7 ], %o4
a0094630:  96 03 3f ff  add  %o4, -1, %o3
a0094634:  d6 2e a1 a7  stb  %o3, [ %i2 + 0x1a7 ]
a0094638:  10 bf ff ee  b  0xa00945f0
a009463c:  b0 10 20 01  mov  1, %i0
a0094640:  67 ff e3 d5  call  0x4008d594
a0094644:  d0 14 20 34  lduh  [ %l0 + 0x34 ], %o0
a0094648:  9f 2a 20 10  sll  %o0, 0x10, %o7
a009464c:  9b 33 e0 10  srl  %o7, 0x10, %o5
a0094650:  80 a3 60 64  cmp  %o5, 0x64
a0094654:  a2 10 00 10  mov  %l0, %l1
a0094658:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a009465c:  18 80 00 2b  bgu  0xa0094708
a0094660:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a0094664:  40 02 cc 30  call  0xa0147724
a0094668:  b4 14 a3 f4  or  %l2, 0x3f4, %i2
a009466c:  d4 0e a0 08  ldub  [ %i2 + 8 ], %o2
a0094670:  93 32 a0 04  srl  %o2, 4, %o1
a0094674:  80 a2 60 02  cmp  %o1, 2
a0094678:  02 80 00 06  be  0xa0094690
a009467c:  d0 34 60 34  sth  %o0, [ %l1 + 0x34 ]
a0094680:  90 10 20 22  mov  0x22, %o0
a0094684:  40 02 cc 28  call  0xa0147724
a0094688:  d0 2e a0 08  stb  %o0, [ %i2 + 8 ]
a009468c:  d0 36 20 3a  sth  %o0, [ %i0 + 0x3a ]
a0094690:  67 ff e3 c1  call  0x4008d594
a0094694:  d0 16 20 3a  lduh  [ %i0 + 0x3a ], %o0
a0094698:  99 2a 20 10  sll  %o0, 0x10, %o4
a009469c:  97 33 20 10  srl  %o4, 0x10, %o3
a00946a0:  80 a2 e7 d0  cmp  %o3, 0x7d0
a00946a4:  18 80 00 24  bgu  0xa0094734
a00946a8:  01 00 00 00  nop
a00946ac:  67 ff e3 ba  call  0x4008d594
a00946b0:  d0 16 20 3a  lduh  [ %i0 + 0x3a ], %o0
a00946b4:  93 2a 20 10  sll  %o0, 0x10, %o1
a00946b8:  03 00 00 04  sethi  %hi(0x1000), %g1
a00946bc:  b5 32 60 10  srl  %o1, 0x10, %i2
a00946c0:  b0 10 63 88  or  %g1, 0x388, %i0
a00946c4:  80 a6 80 18  cmp  %i2, %i0
a00946c8:  18 80 00 24  bgu  0xa0094758
a00946cc:  a2 14 a3 f4  or  %l2, 0x3f4, %l1
a00946d0:  d8 0c 60 08  ldub  [ %l1 + 8 ], %o4
a00946d4:  a4 0b 20 0f  and  %o4, 0xf, %l2
a00946d8:  96 16 62 90  or  %i1, 0x290, %o3
a00946dc:  d8 12 e1 ac  lduh  [ %o3 + 0x1ac ], %o4
a00946e0:  80 a4 80 0c  cmp  %l2, %o4
a00946e4:  18 80 00 0f  bgu  0xa0094720
a00946e8:  82 0c a0 ff  and  %l2, 0xff, %g1
a00946ec:  82 23 00 01  sub  %o4, %g1, %g1
a00946f0:  c2 32 e1 ac  sth  %g1, [ %o3 + 0x1ac ]
a00946f4:  9a 16 62 90  or  %i1, 0x290, %o5
a00946f8:  f2 13 61 ae  lduh  [ %o5 + 0x1ae ], %i1
a00946fc:  f0 13 61 ac  lduh  [ %o5 + 0x1ac ], %i0
a0094700:  40 02 c7 93  call  0xa014654c
a0094704:  95 e8 20 01  restore  %g0, 1, %o2
a0094708:  82 10 20 22  mov  0x22, %g1
a009470c:  b4 14 a3 f4  or  %l2, 0x3f4, %i2
a0094710:  40 02 cc 05  call  0xa0147724
a0094714:  c2 2e a0 08  stb  %g1, [ %i2 + 8 ]
a0094718:  10 bf ff d3  b  0xa0094664
a009471c:  d0 36 20 3a  sth  %o0, [ %i0 + 0x3a ]
a0094720:  80 a3 20 01  cmp  %o4, 1
a0094724:  08 bf ff f5  bleu  0xa00946f8
a0094728:  9a 16 62 90  or  %i1, 0x290, %o5
a009472c:  10 bf ff f1  b  0xa00946f0
a0094730:  82 03 3f fe  add  %o4, -2, %g1
a0094734:  67 ff e3 98  call  0x4008d594
a0094738:  d0 14 60 34  lduh  [ %l1 + 0x34 ], %o0
a009473c:  9b 2a 20 10  sll  %o0, 0x10, %o5
a0094740:  a3 33 60 10  srl  %o5, 0x10, %l1
a0094744:  80 a4 60 63  cmp  %l1, 0x63
a0094748:  18 bf ff d9  bgu  0xa00946ac
a009474c:  9e 10 20 26  mov  0x26, %o7
a0094750:  10 bf ff d7  b  0xa00946ac
a0094754:  de 2e a0 08  stb  %o7, [ %i2 + 8 ]
a0094758:  67 ff e3 8f  call  0x4008d594
a009475c:  d0 14 20 34  lduh  [ %l0 + 0x34 ], %o0
a0094760:  95 2a 20 10  sll  %o0, 0x10, %o2
a0094764:  a1 32 a0 10  srl  %o2, 0x10, %l0
a0094768:  80 a4 20 63  cmp  %l0, 0x63
a009476c:  18 bf ff d9  bgu  0xa00946d0
a0094770:  a2 14 a3 f4  or  %l2, 0x3f4, %l1
a0094774:  90 14 a3 f4  or  %l2, 0x3f4, %o0
a0094778:  96 10 20 2a  mov  0x2a, %o3
a009477c:  10 bf ff d5  b  0xa00946d0
a0094780:  d6 2a 20 08  stb  %o3, [ %o0 + 8 ]
a0094784:  81 c7 e0 08  ret
a0094788:  81 e8 00 00  restore
