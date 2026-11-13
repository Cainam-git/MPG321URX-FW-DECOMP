# leon2m FUN_a015d7f0 0xa015d7f0-0xa015d918 (296 bytes)
a015d7f0:  9d e3 bf 90  save  %sp, -112, %sp
a015d7f4:  90 10 00 18  mov  %i0, %o0
a015d7f8:  7f ff fd 23  call  0xa015cc84
a015d7fc:  92 10 20 01  mov  1, %o1
a015d800:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a015d804:  a0 2e 40 0d  andn  %i1, %o5, %l0
a015d808:  a2 10 00 1a  mov  %i2, %l1
a015d80c:  03 3f fc 00  sethi  %hi(0xfff00000), %g1
a015d810:  98 2e 40 01  andn  %i1, %g1, %o4
a015d814:  b5 34 20 14  srl  %l0, 0x14, %i2
a015d818:  b0 10 00 08  mov  %o0, %i0
a015d81c:  80 a6 a0 00  cmp  %i2, 0
a015d820:  02 80 00 04  be  0xa015d830
a015d824:  b2 02 20 14  add  %o0, 0x14, %i1
a015d828:  03 00 04 00  sethi  %hi(0x100000), %g1
a015d82c:  98 13 00 01  or  %o4, %g1, %o4
a015d830:  80 a4 60 00  cmp  %l1, 0
a015d834:  02 80 00 1d  be  0xa015d8a8
a015d838:  d8 27 bf f0  st  %o4, [ %fp + -16 ]
a015d83c:  e2 27 bf f4  st  %l1, [ %fp + -12 ]
a015d840:  7f ff fd ce  call  0xa015cf78
a015d844:  90 07 bf f4  add  %fp, -12, %o0
a015d848:  80 a2 20 00  cmp  %o0, 0
a015d84c:  12 80 00 28  bne  0xa015d8ec
a015d850:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a015d854:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a015d858:  c2 26 20 14  st  %g1, [ %i0 + 0x14 ]
a015d85c:  d8 07 bf f0  ld  [ %fp + -16 ], %o4
a015d860:  80 a0 00 0c  cmp  %g0, %o4
a015d864:  82 10 20 02  mov  2, %g1
a015d868:  82 40 7f ff  addx  %g1, -1, %g1
a015d86c:  d8 26 60 04  st  %o4, [ %i1 + 4 ]
a015d870:  c2 26 20 10  st  %g1, [ %i0 + 0x10 ]
a015d874:  80 a6 a0 00  cmp  %i2, 0
a015d878:  12 80 00 16  bne  0xa015d8d0
a015d87c:  a0 10 00 01  mov  %g1, %l0
a015d880:  83 2c 20 02  sll  %l0, 2, %g1
a015d884:  9a 02 3b ce  add  %o0, -1074, %o5
a015d888:  82 00 40 19  add  %g1, %i1, %g1
a015d88c:  da 26 c0 00  st  %o5, [ %i3 ]
a015d890:  7f ff fd 9a  call  0xa015cef8
a015d894:  d0 00 7f fc  ld  [ %g1 + -4 ], %o0
a015d898:  a1 2c 20 05  sll  %l0, 5, %l0
a015d89c:  a0 24 00 08  sub  %l0, %o0, %l0
a015d8a0:  10 80 00 1c  b  0xa015d910
a015d8a4:  e0 27 00 00  st  %l0, [ %i4 ]
a015d8a8:  7f ff fd b4  call  0xa015cf78
a015d8ac:  90 07 bf f0  add  %fp, -16, %o0
a015d8b0:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a015d8b4:  9a 10 20 01  mov  1, %o5
a015d8b8:  c2 26 20 14  st  %g1, [ %i0 + 0x14 ]
a015d8bc:  da 26 20 10  st  %o5, [ %i0 + 0x10 ]
a015d8c0:  90 02 20 20  add  %o0, 0x20, %o0
a015d8c4:  80 a6 a0 00  cmp  %i2, 0
a015d8c8:  02 bf ff ee  be  0xa015d880
a015d8cc:  a0 10 20 01  mov  1, %l0
a015d8d0:  82 06 80 08  add  %i2, %o0, %g1
a015d8d4:  82 00 7b cd  add  %g1, -1075, %g1
a015d8d8:  9a 10 20 35  mov  0x35, %o5
a015d8dc:  c2 26 c0 00  st  %g1, [ %i3 ]
a015d8e0:  9a 23 40 08  sub  %o5, %o0, %o5
a015d8e4:  10 80 00 0b  b  0xa015d910
a015d8e8:  da 27 00 00  st  %o5, [ %i4 ]
a015d8ec:  98 20 00 08  neg  %o0, %o4
a015d8f0:  da 07 bf f4  ld  [ %fp + -12 ], %o5
a015d8f4:  83 28 40 0c  sll  %g1, %o4, %g1
a015d8f8:  82 10 40 0d  or  %g1, %o5, %g1
a015d8fc:  c2 26 20 14  st  %g1, [ %i0 + 0x14 ]
a015d900:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a015d904:  99 33 40 08  srl  %o5, %o0, %o4
a015d908:  10 bf ff d6  b  0xa015d860
a015d90c:  d8 27 bf f0  st  %o4, [ %fp + -16 ]
a015d910:  81 c7 e0 08  ret
a015d914:  81 e8 00 00  restore
