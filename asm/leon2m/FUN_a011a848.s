# leon2m FUN_a011a848 0xa011a848-0xa011a974 (300 bytes)
a011a848:  9d e3 bf 98  save  %sp, -104, %sp
a011a84c:  b6 0e 20 ff  and  %i0, 0xff, %i3
a011a850:  80 a6 e0 ff  cmp  %i3, 0xff
a011a854:  02 80 00 46  be  0xa011a96c
a011a858:  9a 10 00 19  mov  %i1, %o5
a011a85c:  80 a6 e0 08  cmp  %i3, 8
a011a860:  08 80 00 30  bleu  0xa011a920
a011a864:  82 0e 60 ff  and  %i1, 0xff, %g1
a011a868:  b6 10 20 08  mov  8, %i3
a011a86c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a011a870:  80 a6 60 02  cmp  %i1, 2
a011a874:  b4 60 20 00  subx  %g0, 0, %i2
a011a878:  82 0b 40 1a  and  %o5, %i2, %g1
a011a87c:  ba 08 60 ff  and  %g1, 0xff, %i5
a011a880:  31 2a 00 9e  sethi  %hi(0xa8027800), %i0
a011a884:  b0 16 22 a8  or  %i0, 0x2a8, %i0	! 0xa8027aa8
a011a888:  b8 07 40 1d  add  %i5, %i5, %i4
a011a88c:  80 a6 60 02  cmp  %i1, 2
a011a890:  f4 16 00 1c  lduh  [ %i0 + %i4 ], %i2
a011a894:  82 60 20 00  subx  %g0, 0, %g1
a011a898:  ba 06 a0 a1  add  %i2, 0xa1, %i5
a011a89c:  b8 0b 40 01  and  %o5, %g1, %i4
a011a8a0:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a011a8a4:  b5 2f 60 02  sll  %i5, 2, %i2
a011a8a8:  82 0f 20 ff  and  %i4, 0xff, %g1
a011a8ac:  b8 00 40 01  add  %g1, %g1, %i4
a011a8b0:  ba 16 80 0f  or  %i2, %o7, %i5
a011a8b4:  f4 07 40 00  ld  [ %i5 ], %i2
a011a8b8:  82 06 ff ff  add  %i3, -1, %g1
a011a8bc:  f6 16 00 1c  lduh  [ %i0 + %i4 ], %i3
a011a8c0:  b2 06 40 19  add  %i1, %i1, %i1
a011a8c4:  ba 0e a0 c7  and  %i2, 0xc7, %i5
a011a8c8:  83 28 60 03  sll  %g1, 3, %g1
a011a8cc:  f8 16 00 19  lduh  [ %i0 + %i1 ], %i4
a011a8d0:  b4 17 40 01  or  %i5, %g1, %i2
a011a8d4:  b6 06 e0 a1  add  %i3, 0xa1, %i3
a011a8d8:  b3 2e e0 02  sll  %i3, 2, %i1
a011a8dc:  ba 07 20 aa  add  %i4, 0xaa, %i5
a011a8e0:  b6 16 40 0f  or  %i1, %o7, %i3
a011a8e4:  b8 0b 60 ff  and  %o5, 0xff, %i4
a011a8e8:  82 0e a0 ff  and  %i2, 0xff, %g1
a011a8ec:  b2 07 00 1c  add  %i4, %i4, %i1
a011a8f0:  f4 16 00 19  lduh  [ %i0 + %i1 ], %i2
a011a8f4:  bb 2f 60 02  sll  %i5, 2, %i5
a011a8f8:  c2 26 c0 00  st  %g1, [ %i3 ]
a011a8fc:  b0 17 40 0f  or  %i5, %o7, %i0
a011a900:  f8 06 00 00  ld  [ %i0 ], %i4
a011a904:  82 06 a0 aa  add  %i2, 0xaa, %g1
a011a908:  b2 17 20 10  or  %i4, 0x10, %i1
a011a90c:  b7 28 60 02  sll  %g1, 2, %i3
a011a910:  b4 16 c0 0f  or  %i3, %o7, %i2
a011a914:  ba 0e 60 ff  and  %i1, 0xff, %i5
a011a918:  fa 26 80 00  st  %i5, [ %i2 ]
a011a91c:  30 80 00 14  b,a   0xa011a96c
a011a920:  ba 00 40 01  add  %g1, %g1, %i5
a011a924:  80 a6 e0 00  cmp  %i3, 0
a011a928:  12 bf ff d1  bne  0xa011a86c
a011a92c:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011a930:  31 2a 00 9e  sethi  %hi(0xa8027800), %i0
a011a934:  82 16 22 a8  or  %i0, 0x2a8, %g1	! 0xa8027aa8
a011a938:  f2 10 40 1d  lduh  [ %g1 + %i5 ], %i1
a011a93c:  b8 06 60 a1  add  %i1, 0xa1, %i4
a011a940:  b7 2f 20 02  sll  %i4, 2, %i3
a011a944:  b8 16 c0 1a  or  %i3, %i2, %i4
a011a948:  f0 07 00 00  ld  [ %i4 ], %i0
a011a94c:  ba 06 60 aa  add  %i1, 0xaa, %i5
a011a950:  82 0e 20 c7  and  %i0, 0xc7, %g1
a011a954:  b7 2f 60 02  sll  %i5, 2, %i3
a011a958:  c2 27 00 00  st  %g1, [ %i4 ]
a011a95c:  ba 16 c0 1a  or  %i3, %i2, %i5
a011a960:  f2 07 40 00  ld  [ %i5 ], %i1
a011a964:  b0 0e 60 ef  and  %i1, 0xef, %i0
a011a968:  f0 27 40 00  st  %i0, [ %i5 ]
a011a96c:  81 c7 e0 08  ret
a011a970:  81 e8 00 00  restore
