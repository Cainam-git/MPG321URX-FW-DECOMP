# leon2s FUN_a006c788 0xa006c788-0xa006c9c0 (568 bytes)
a006c788:  9d e3 bf 98  save  %sp, -104, %sp
a006c78c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a006c790:  c2 08 63 e0  ldub  [ %g1 + 0x3e0 ], %g1	! 0xa80787e0
a006c794:  96 10 00 18  mov  %i0, %o3
a006c798:  80 a0 60 01  cmp  %g1, 1
a006c79c:  b0 10 00 19  mov  %i1, %i0
a006c7a0:  12 80 00 59  bne  0xa006c904
a006c7a4:  9a 10 20 00  clr  %o5
a006c7a8:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a006c7ac:  b8 10 60 40  or  %g1, 0x40, %i4	! 0xcf03c840
a006c7b0:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a006c7b4:  98 10 63 ff  or  %g1, 0x3ff, %o4	! 0xffff
a006c7b8:  b2 10 3f ff  mov  -1, %i1
a006c7bc:  9e 10 20 02  mov  2, %o7
a006c7c0:  82 06 7f ff  add  %i1, -1, %g1
a006c7c4:  bb 28 60 10  sll  %g1, 0x10, %i5
a006c7c8:  b7 37 60 10  srl  %i5, 0x10, %i3
a006c7cc:  fa 07 00 00  ld  [ %i4 ], %i5
a006c7d0:  80 a7 60 01  cmp  %i5, 1
a006c7d4:  02 80 00 03  be  0xa006c7e0
a006c7d8:  b2 10 00 01  mov  %g1, %i1
a006c7dc:  de 27 00 00  st  %o7, [ %i4 ]
a006c7e0:  c2 07 00 00  ld  [ %i4 ], %g1
a006c7e4:  80 a0 60 02  cmp  %g1, 2
a006c7e8:  02 80 00 04  be  0xa006c7f8
a006c7ec:  80 a6 c0 0c  cmp  %i3, %o4
a006c7f0:  12 bf ff f5  bne  0xa006c7c4
a006c7f4:  82 06 7f ff  add  %i1, -1, %g1
a006c7f8:  82 10 20 02  mov  2, %g1
a006c7fc:  3b 33 c0 4d  sethi  %hi(0xcf013400), %i5
a006c800:  c2 27 00 00  st  %g1, [ %i4 ]
a006c804:  ba 17 60 28  or  %i5, 0x28, %i5
a006c808:  c2 07 40 00  ld  [ %i5 ], %g1
a006c80c:  82 10 60 01  or  %g1, 1, %g1
a006c810:  c2 27 40 00  st  %g1, [ %i5 ]
a006c814:  bb 2e 20 05  sll  %i0, 5, %i5
a006c818:  03 08 00 00  sethi  %hi(0x20000000), %g1
a006c81c:  c0 27 00 00  clr  [ %i4 ]
a006c820:  80 a6 a0 00  cmp  %i2, 0
a006c824:  02 80 00 1b  be  0xa006c890
a006c828:  98 07 40 01  add  %i5, %g1, %o4
a006c82c:  b0 10 00 1a  mov  %i2, %i0
a006c830:  b2 10 00 0d  mov  %o5, %i1
a006c834:  9e 03 60 08  add  %o5, 8, %o7
a006c838:  80 a6 40 0f  cmp  %i1, %o7
a006c83c:  1a 80 00 12  bcc  0xa006c884
a006c840:  b5 2e 60 02  sll  %i1, 2, %i2
a006c844:  f6 02 c0 1a  ld  [ %o3 + %i2 ], %i3
a006c848:  bb 36 e0 10  srl  %i3, 0x10, %i5
a006c84c:  b9 36 e0 08  srl  %i3, 8, %i4
a006c850:  ba 0f 60 ff  and  %i5, 0xff, %i5
a006c854:  83 36 e0 18  srl  %i3, 0x18, %g1
a006c858:  bb 2f 60 08  sll  %i5, 8, %i5
a006c85c:  b8 0f 20 ff  and  %i4, 0xff, %i4
a006c860:  82 10 40 1d  or  %g1, %i5, %g1
a006c864:  b9 2f 20 10  sll  %i4, 0x10, %i4
a006c868:  82 10 40 1c  or  %g1, %i4, %g1
a006c86c:  b7 2e e0 18  sll  %i3, 0x18, %i3
a006c870:  82 10 40 1b  or  %g1, %i3, %g1
a006c874:  b2 06 60 01  inc  %i1
a006c878:  c2 23 00 1a  st  %g1, [ %o4 + %i2 ]
a006c87c:  10 bf ff f0  b  0xa006c83c
a006c880:  80 a6 40 0f  cmp  %i1, %o7
a006c884:  b0 86 3f ff  addcc  %i0, -1, %i0
a006c888:  12 bf ff ea  bne  0xa006c830
a006c88c:  9a 03 60 08  add  %o5, 8, %o5
a006c890:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a006c894:  b8 10 60 40  or  %g1, 0x40, %i4	! 0xcf03c840
a006c898:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a006c89c:  b0 10 63 ff  or  %g1, 0x3ff, %i0	! 0xffff
a006c8a0:  b4 10 3f ff  mov  -1, %i2
a006c8a4:  b2 10 20 02  mov  2, %i1
a006c8a8:  82 06 bf ff  add  %i2, -1, %g1
a006c8ac:  bb 28 60 10  sll  %g1, 0x10, %i5
a006c8b0:  b7 37 60 10  srl  %i5, 0x10, %i3
a006c8b4:  fa 07 00 00  ld  [ %i4 ], %i5
a006c8b8:  80 a7 60 01  cmp  %i5, 1
a006c8bc:  02 80 00 03  be  0xa006c8c8
a006c8c0:  b4 10 00 01  mov  %g1, %i2
a006c8c4:  f2 27 00 00  st  %i1, [ %i4 ]
a006c8c8:  c2 07 00 00  ld  [ %i4 ], %g1
a006c8cc:  80 a0 60 02  cmp  %g1, 2
a006c8d0:  02 80 00 04  be  0xa006c8e0
a006c8d4:  80 a6 c0 18  cmp  %i3, %i0
a006c8d8:  12 bf ff f5  bne  0xa006c8ac
a006c8dc:  82 06 bf ff  add  %i2, -1, %g1
a006c8e0:  82 10 20 02  mov  2, %g1
a006c8e4:  3b 33 c0 4d  sethi  %hi(0xcf013400), %i5
a006c8e8:  c2 27 00 00  st  %g1, [ %i4 ]
a006c8ec:  ba 17 60 28  or  %i5, 0x28, %i5
a006c8f0:  c2 07 40 00  ld  [ %i5 ], %g1
a006c8f4:  82 08 7f fe  and  %g1, -2, %g1
a006c8f8:  c2 27 40 00  st  %g1, [ %i5 ]
a006c8fc:  c0 27 00 00  clr  [ %i4 ]
a006c900:  30 80 00 2e  b,a   0xa006c9b8
a006c904:  80 a6 a0 00  cmp  %i2, 0
a006c908:  02 80 00 2c  be  0xa006c9b8
a006c90c:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a006c910:  b2 10 00 1a  mov  %i2, %i1
a006c914:  a2 10 00 01  mov  %g1, %l1
a006c918:  a0 10 63 a4  or  %g1, 0x3a4, %l0
a006c91c:  90 10 63 a8  or  %g1, 0x3a8, %o0
a006c920:  92 10 63 ac  or  %g1, 0x3ac, %o1
a006c924:  94 10 63 84  or  %g1, 0x384, %o2
a006c928:  98 10 63 a0  or  %g1, 0x3a0, %o4
a006c92c:  9e 10 20 80  mov  0x80, %o7
a006c930:  f0 23 00 00  st  %i0, [ %o4 ]
a006c934:  83 36 20 08  srl  %i0, 8, %g1
a006c938:  c2 24 00 00  st  %g1, [ %l0 ]
a006c93c:  83 36 20 10  srl  %i0, 0x10, %g1
a006c940:  c2 22 00 00  st  %g1, [ %o0 ]
a006c944:  83 36 20 18  srl  %i0, 0x18, %g1
a006c948:  c2 22 40 00  st  %g1, [ %o1 ]
a006c94c:  b6 03 60 08  add  %o5, 8, %i3
a006c950:  b8 10 00 0d  mov  %o5, %i4
a006c954:  de 22 80 00  st  %o7, [ %o2 ]
a006c958:  80 a3 40 1b  cmp  %o5, %i3
a006c95c:  1a 80 00 14  bcc  0xa006c9ac
a006c960:  9a 10 00 1b  mov  %i3, %o5
a006c964:  b4 14 63 88  or  %l1, 0x388, %i2
a006c968:  bb 2f 20 02  sll  %i4, 2, %i5
a006c96c:  c2 0a c0 1d  ldub  [ %o3 + %i5 ], %g1
a006c970:  c2 26 80 00  st  %g1, [ %i2 ]
a006c974:  c2 12 c0 1d  lduh  [ %o3 + %i5 ], %g1
a006c978:  82 08 60 ff  and  %g1, 0xff, %g1
a006c97c:  c2 26 80 00  st  %g1, [ %i2 ]
a006c980:  82 02 c0 1d  add  %o3, %i5, %g1
a006c984:  c2 08 60 02  ldub  [ %g1 + 2 ], %g1
a006c988:  c2 26 80 00  st  %g1, [ %i2 ]
a006c98c:  c2 02 c0 1d  ld  [ %o3 + %i5 ], %g1
a006c990:  82 08 60 ff  and  %g1, 0xff, %g1
a006c994:  b8 07 20 01  inc  %i4
a006c998:  c2 26 80 00  st  %g1, [ %i2 ]
a006c99c:  80 a7 00 1b  cmp  %i4, %i3
a006c9a0:  0a bf ff f3  bcs  0xa006c96c
a006c9a4:  bb 2f 20 02  sll  %i4, 2, %i5
a006c9a8:  9a 10 00 1b  mov  %i3, %o5
a006c9ac:  b2 86 7f ff  addcc  %i1, -1, %i1
a006c9b0:  12 bf ff e0  bne  0xa006c930
a006c9b4:  b0 06 20 01  inc  %i0
a006c9b8:  81 c7 e0 08  ret
a006c9bc:  81 e8 00 00  restore
