# leon2m FUN_a00c46d4 0xa00c46d4-0xa00c49b8 (740 bytes)
a00c46d4:  9d e3 bf 98  save  %sp, -104, %sp
a00c46d8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c46dc:  80 a4 20 02  cmp  %l0, 2
a00c46e0:  02 80 00 79  be  0xa00c48c4
a00c46e4:  80 a4 20 03  cmp  %l0, 3
a00c46e8:  02 80 00 7a  be  0xa00c48d0
a00c46ec:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c46f0:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c46f4:  94 08 60 ff  and  %g1, 0xff, %o2
a00c46f8:  9a 02 bf d0  add  %o2, -48, %o5
a00c46fc:  98 0b 60 ff  and  %o5, 0xff, %o4
a00c4700:  80 a3 20 01  cmp  %o4, 1
a00c4704:  18 80 00 ab  bgu  0xa00c49b0
a00c4708:  b0 10 20 ff  mov  0xff, %i0
a00c470c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c4710:  b0 12 e2 90  or  %o3, 0x290, %i0	! 0xa802d290
a00c4714:  80 a3 20 01  cmp  %o4, 1
a00c4718:  02 80 00 2f  be  0xa00c47d4
a00c471c:  da 2e 20 4a  stb  %o5, [ %i0 + 0x4a ]
a00c4720:  40 00 45 e3  call  0xa00d5eac
a00c4724:  90 10 20 00  clr  %o0
a00c4728:  80 a4 20 02  cmp  %l0, 2
a00c472c:  02 80 00 4a  be  0xa00c4854
a00c4730:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c4734:  80 a4 20 03  cmp  %l0, 3
a00c4738:  02 80 00 69  be  0xa00c48dc
a00c473c:  96 10 20 30  mov  0x30, %o3
a00c4740:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c4744:  94 16 20 78  or  %i0, 0x78, %o2	! 0xa802d078
a00c4748:  82 10 20 35  mov  0x35, %g1
a00c474c:  9a 10 20 36  mov  0x36, %o5
a00c4750:  9e 10 20 2b  mov  0x2b, %o7
a00c4754:  98 10 20 0d  mov  0xd, %o4
a00c4758:  c2 2e 20 78  stb  %g1, [ %i0 + 0x78 ]
a00c475c:  da 2a a0 01  stb  %o5, [ %o2 + 1 ]
a00c4760:  d6 2a a0 03  stb  %o3, [ %o2 + 3 ]
a00c4764:  de 2a a0 04  stb  %o7, [ %o2 + 4 ]
a00c4768:  d8 2a a0 05  stb  %o4, [ %o2 + 5 ]
a00c476c:  80 a4 20 02  cmp  %l0, 2
a00c4770:  02 80 00 45  be  0xa00c4884
a00c4774:  d6 2a a0 02  stb  %o3, [ %o2 + 2 ]
a00c4778:  80 a4 20 03  cmp  %l0, 3
a00c477c:  02 80 00 65  be  0xa00c4910
a00c4780:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c4784:  9e 13 60 d0  or  %o5, 0xd0, %o7	! 0xa802d0d0
a00c4788:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00c478c:  c0 2e 20 9c  clrb  [ %i0 + 0x9c ]	! 0xa802b09c
a00c4790:  c0 2b 60 d0  clrb  [ %o5 + 0xd0 ]
a00c4794:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00c4798:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00c479c:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00c47a0:  80 a4 20 02  cmp  %l0, 2
a00c47a4:  02 80 00 41  be  0xa00c48a8
a00c47a8:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00c47ac:  80 a4 20 03  cmp  %l0, 3
a00c47b0:  12 80 00 41  bne  0xa00c48b4
a00c47b4:  90 10 00 10  mov  %l0, %o0
a00c47b8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c47bc:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c47c0:  90 10 20 03  mov  3, %o0
a00c47c4:  40 02 10 09  call  0xa01487e8
a00c47c8:  92 10 20 06  mov  6, %o1
a00c47cc:  10 80 00 79  b  0xa00c49b0
a00c47d0:  b0 10 20 00  clr  %i0
a00c47d4:  d8 06 20 b0  ld  [ %i0 + 0xb0 ], %o4
a00c47d8:  80 a3 20 00  cmp  %o4, 0
a00c47dc:  12 80 00 57  bne  0xa00c4938
a00c47e0:  01 00 00 00  nop
a00c47e4:  7f fe fc 00  call  0xa00837e4
a00c47e8:  01 00 00 00  nop
a00c47ec:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00c47f0:  80 a3 60 01  cmp  %o5, 1
a00c47f4:  02 80 00 60  be  0xa00c4974
a00c47f8:  01 00 00 00  nop
a00c47fc:  de 0e 20 1f  ldub  [ %i0 + 0x1f ], %o7
a00c4800:  80 a3 e0 00  cmp  %o7, 0
a00c4804:  12 80 00 52  bne  0xa00c494c
a00c4808:  01 00 00 00  nop
a00c480c:  c2 06 20 a8  ld  [ %i0 + 0xa8 ], %g1
a00c4810:  80 88 60 80  btst  0x80, %g1
a00c4814:  02 bf ff c3  be  0xa00c4720
a00c4818:  82 08 7f 7f  and  %g1, -129, %g1
a00c481c:  7f ff 31 ef  call  0xa0090fd8
a00c4820:  c2 26 20 a8  st  %g1, [ %i0 + 0xa8 ]
a00c4824:  40 01 81 c8  call  0xa0124f44
a00c4828:  01 00 00 00  nop
a00c482c:  40 00 52 74  call  0xa00d91fc
a00c4830:  90 10 20 00  clr  %o0	! 0x0
a00c4834:  40 00 56 54  call  0xa00da184
a00c4838:  01 00 00 00  nop
a00c483c:  40 00 45 9c  call  0xa00d5eac
a00c4840:  90 10 20 00  clr  %o0	! 0x0
a00c4844:  80 a4 20 02  cmp  %l0, 2
a00c4848:  12 bf ff bc  bne  0xa00c4738
a00c484c:  80 a4 20 03  cmp  %l0, 3
a00c4850:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c4854:  a0 12 e1 28  or  %o3, 0x128, %l0	! 0xa802d128
a00c4858:  b0 10 20 30  mov  0x30, %i0
a00c485c:  98 10 20 35  mov  0x35, %o4
a00c4860:  94 10 20 0d  mov  0xd, %o2
a00c4864:  92 10 20 36  mov  0x36, %o1
a00c4868:  90 10 20 2b  mov  0x2b, %o0
a00c486c:  d8 2a e1 28  stb  %o4, [ %o3 + 0x128 ]
a00c4870:  d4 2c 20 05  stb  %o2, [ %l0 + 5 ]
a00c4874:  d2 2c 20 01  stb  %o1, [ %l0 + 1 ]
a00c4878:  f0 2c 20 03  stb  %i0, [ %l0 + 3 ]
a00c487c:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00c4880:  f0 2c 20 02  stb  %i0, [ %l0 + 2 ]
a00c4884:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c4888:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c488c:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00c4890:  c0 2a 20 9a  clrb  [ %o0 + 0x9a ]	! 0xa802b09a
a00c4894:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c4898:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c489c:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c48a0:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c48a4:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c48a8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c48ac:  94 10 61 28  or  %g1, 0x128, %o2	! 0xa802d128
a00c48b0:  90 10 20 02  mov  2, %o0
a00c48b4:  40 02 0f cd  call  0xa01487e8
a00c48b8:  92 10 20 06  mov  6, %o1
a00c48bc:  10 80 00 3d  b  0xa00c49b0
a00c48c0:  b0 10 20 00  clr  %i0
a00c48c4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c48c8:  10 bf ff 8b  b  0xa00c46f4
a00c48cc:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c48d0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c48d4:  10 bf ff 88  b  0xa00c46f4
a00c48d8:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c48dc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c48e0:  9e 12 21 08  or  %o0, 0x108, %o7	! 0xa802d108
a00c48e4:  a0 10 20 30  mov  0x30, %l0
a00c48e8:  92 10 20 35  mov  0x35, %o1
a00c48ec:  b0 10 20 0d  mov  0xd, %i0
a00c48f0:  82 10 20 36  mov  0x36, %g1
a00c48f4:  9a 10 20 2b  mov  0x2b, %o5
a00c48f8:  d2 2a 21 08  stb  %o1, [ %o0 + 0x108 ]
a00c48fc:  f0 2b e0 05  stb  %i0, [ %o7 + 5 ]
a00c4900:  c2 2b e0 01  stb  %g1, [ %o7 + 1 ]
a00c4904:  e0 2b e0 03  stb  %l0, [ %o7 + 3 ]
a00c4908:  da 2b e0 04  stb  %o5, [ %o7 + 4 ]
a00c490c:  e0 2b e0 02  stb  %l0, [ %o7 + 2 ]
a00c4910:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c4914:  92 12 e0 98  or  %o3, 0x98, %o1	! 0xa802d098
a00c4918:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00c491c:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]	! 0xa802b098
a00c4920:  c0 2a e0 98  clrb  [ %o3 + 0x98 ]
a00c4924:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c4928:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c492c:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c4930:  10 bf ff a2  b  0xa00c47b8
a00c4934:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c4938:  40 00 40 18  call  0xa00d4998
a00c493c:  c0 26 20 b0  clr  [ %i0 + 0xb0 ]
a00c4940:  40 00 45 7f  call  0xa00d5f3c
a00c4944:  01 00 00 00  nop
a00c4948:  30 bf ff a7  b,a   0xa00c47e4
a00c494c:  7f ff 31 a3  call  0xa0090fd8
a00c4950:  c0 2e 20 1f  clrb  [ %i0 + 0x1f ]
a00c4954:  40 01 81 7c  call  0xa0124f44
a00c4958:  01 00 00 00  nop
a00c495c:  40 00 52 28  call  0xa00d91fc
a00c4960:  90 10 20 00  clr  %o0	! 0x0
a00c4964:  40 00 56 3c  call  0xa00da254
a00c4968:  01 00 00 00  nop
a00c496c:  10 bf ff a9  b  0xa00c4810
a00c4970:  c2 06 20 a8  ld  [ %i0 + 0xa8 ], %g1
a00c4974:  40 00 52 22  call  0xa00d91fc
a00c4978:  90 10 20 00  clr  %o0
a00c497c:  c0 2e 21 a4  clrb  [ %i0 + 0x1a4 ]
a00c4980:  90 10 20 00  clr  %o0
a00c4984:  40 02 0e 39  call  0xa0148268
a00c4988:  92 10 20 01  mov  1, %o1
a00c498c:  90 10 20 01  mov  1, %o0
a00c4990:  40 02 0e 36  call  0xa0148268
a00c4994:  92 10 20 01  mov  1, %o1
a00c4998:  40 00 56 2f  call  0xa00da254
a00c499c:  01 00 00 00  nop
a00c49a0:  7f fe f9 d5  call  0xa00830f4
a00c49a4:  90 10 20 00  clr  %o0	! 0x0
a00c49a8:  10 bf ff 96  b  0xa00c4800
a00c49ac:  de 0e 20 1f  ldub  [ %i0 + 0x1f ], %o7
a00c49b0:  81 c7 e0 08  ret
a00c49b4:  81 e8 00 00  restore
