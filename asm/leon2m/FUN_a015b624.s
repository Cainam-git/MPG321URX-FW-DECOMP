# leon2m FUN_a015b624 0xa015b624-0xa015b738 (276 bytes)
a015b624:  9d e3 bf 88  save  %sp, -120, %sp
a015b628:  7f ff ff f3  call  0xa015b5f4
a015b62c:  a2 10 00 18  mov  %i0, %l1
a015b630:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a015b634:  e0 00 63 d8  ld  [ %g1 + 0x3d8 ], %l0	! 0x1a83d8
a015b638:  da 04 20 38  ld  [ %l0 + 0x38 ], %o5
a015b63c:  80 a3 60 00  cmp  %o5, 0
a015b640:  02 80 00 13  be  0xa015b68c
a015b644:  01 00 00 00  nop
a015b648:  a0 04 22 e0  add  %l0, 0x2e0, %l0
a015b64c:  da 04 20 04  ld  [ %l0 + 4 ], %o5
a015b650:  9a 83 7f ff  addcc  %o5, -1, %o5
a015b654:  0c 80 00 08  bneg  0xa015b674
a015b658:  f0 04 20 08  ld  [ %l0 + 8 ], %i0
a015b65c:  c2 56 20 0c  ldsh  [ %i0 + 0xc ], %g1
a015b660:  80 a0 60 00  cmp  %g1, 0
a015b664:  02 80 00 18  be  0xa015b6c4
a015b668:  9a 83 7f ff  addcc  %o5, -1, %o5
a015b66c:  1c bf ff fc  bpos  0xa015b65c
a015b670:  b0 06 20 cc  add  %i0, 0xcc, %i0
a015b674:  d0 04 00 00  ld  [ %l0 ], %o0
a015b678:  80 a2 20 00  cmp  %o0, 0
a015b67c:  22 80 00 08  be,a   0xa015b69c
a015b680:  90 10 00 11  mov  %l1, %o0
a015b684:  10 bf ff f2  b  0xa015b64c
a015b688:  a0 10 00 08  mov  %o0, %l0
a015b68c:  7f ff ff b3  call  0xa015b558
a015b690:  90 10 00 10  mov  %l0, %o0
a015b694:  10 bf ff ee  b  0xa015b64c
a015b698:  a0 04 22 e0  add  %l0, 0x2e0, %l0
a015b69c:  7f ff ff 97  call  0xa015b4f8
a015b6a0:  92 10 20 04  mov  4, %o1
a015b6a4:  80 a2 20 00  cmp  %o0, 0
a015b6a8:  12 bf ff f7  bne  0xa015b684
a015b6ac:  d0 24 00 00  st  %o0, [ %l0 ]
a015b6b0:  7f ff ff d7  call  0xa015b60c
a015b6b4:  b0 10 20 00  clr  %i0
a015b6b8:  82 10 20 0c  mov  0xc, %g1
a015b6bc:  10 80 00 1d  b  0xa015b730
a015b6c0:  c2 24 40 00  st  %g1, [ %l1 ]
a015b6c4:  82 10 3f ff  mov  -1, %g1
a015b6c8:  9a 10 20 01  mov  1, %o5
a015b6cc:  a0 07 bf e8  add  %fp, -24, %l0
a015b6d0:  c2 36 20 0e  sth  %g1, [ %i0 + 0xe ]
a015b6d4:  da 36 20 0c  sth  %o5, [ %i0 + 0xc ]
a015b6d8:  40 00 0c f0  call  0xa015ea98
a015b6dc:  90 10 00 10  mov  %l0, %o0
a015b6e0:  92 10 20 01  mov  1, %o1
a015b6e4:  40 00 0d 05  call  0xa015eaf8
a015b6e8:  90 10 00 10  mov  %l0, %o0
a015b6ec:  92 10 00 10  mov  %l0, %o1
a015b6f0:  40 00 0c ad  call  0xa015e9a4
a015b6f4:  90 06 20 58  add  %i0, 0x58, %o0
a015b6f8:  40 00 0c f4  call  0xa015eac8
a015b6fc:  90 10 00 10  mov  %l0, %o0
a015b700:  7f ff ff c3  call  0xa015b60c
a015b704:  01 00 00 00  nop
a015b708:  c0 26 00 00  clr  [ %i0 ]
a015b70c:  c0 26 20 08  clr  [ %i0 + 8 ]
a015b710:  c0 26 20 04  clr  [ %i0 + 4 ]
a015b714:  c0 26 20 10  clr  [ %i0 + 0x10 ]
a015b718:  c0 26 20 14  clr  [ %i0 + 0x14 ]
a015b71c:  c0 26 20 18  clr  [ %i0 + 0x18 ]
a015b720:  c0 26 20 30  clr  [ %i0 + 0x30 ]
a015b724:  c0 26 20 34  clr  [ %i0 + 0x34 ]
a015b728:  c0 26 20 44  clr  [ %i0 + 0x44 ]
a015b72c:  c0 26 20 48  clr  [ %i0 + 0x48 ]
a015b730:  81 c7 e0 08  ret
a015b734:  81 e8 00 00  restore
