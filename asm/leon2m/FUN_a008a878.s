# leon2m FUN_a008a878 0xa008a878-0xa008a95c (228 bytes)  [FUN_a008a954 = unreachable ret/restore tail, merged]
a008a878:  9d e3 bf 98  save  %sp, -104, %sp
a008a87c:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a008a880:  d6 0c 63 bd  ldub  [ %l1 + 0x3bd ], %o3	! 0xa802afbd
a008a884:  94 02 c0 0b  add  %o3, %o3, %o2
a008a888:  11 00 04 00  sethi  %hi(0x100000), %o0
a008a88c:  92 02 80 0b  add  %o2, %o3, %o1
a008a890:  a0 12 22 42  or  %o0, 0x242, %l0
a008a894:  98 02 40 10  add  %o1, %l0, %o4
a008a898:  d0 0c 00 09  ldub  [ %l0 + %o1 ], %o0
a008a89c:  d4 0b 20 02  ldub  [ %o4 + 2 ], %o2
a008a8a0:  d2 0b 20 01  ldub  [ %o4 + 1 ], %o1
a008a8a4:  96 10 27 90  mov  0x790, %o3
a008a8a8:  40 02 f0 76  call  0xa0146a80
a008a8ac:  98 10 20 00  clr  %o4
a008a8b0:  c2 0c 63 bd  ldub  [ %l1 + 0x3bd ], %g1
a008a8b4:  82 00 60 01  inc  %g1
a008a8b8:  9a 08 60 ff  and  %g1, 0xff, %o5
a008a8bc:  80 a3 60 1a  cmp  %o5, 0x1a
a008a8c0:  38 80 00 02  bgu,a   0xa008a8c8
a008a8c4:  82 10 20 0d  mov  0xd, %g1
a008a8c8:  c2 2c 63 bd  stb  %g1, [ %l1 + 0x3bd ]
a008a8cc:  c2 0c 63 bd  ldub  [ %l1 + 0x3bd ], %g1
a008a8d0:  98 00 40 01  add  %g1, %g1, %o4
a008a8d4:  9a 03 00 01  add  %o4, %g1, %o5
a008a8d8:  9e 03 40 10  add  %o5, %l0, %o7
a008a8dc:  d0 0c 00 0d  ldub  [ %l0 + %o5 ], %o0
a008a8e0:  d4 0b e0 02  ldub  [ %o7 + 2 ], %o2
a008a8e4:  d2 0b e0 01  ldub  [ %o7 + 1 ], %o1
a008a8e8:  96 10 20 90  mov  0x90, %o3
a008a8ec:  40 02 f0 65  call  0xa0146a80
a008a8f0:  98 10 20 00  clr  %o4
a008a8f4:  c2 0c 63 bd  ldub  [ %l1 + 0x3bd ], %g1
a008a8f8:  80 a0 60 01  cmp  %g1, 1
a008a8fc:  02 80 00 0d  be  0xa008a930
a008a900:  9a 10 20 02  mov  2, %o5
a008a904:  80 a0 60 07  cmp  %g1, 7
a008a908:  02 80 00 0a  be  0xa008a930
a008a90c:  9a 10 20 03  mov  3, %o5
a008a910:  80 a0 60 0a  cmp  %g1, 0xa
a008a914:  02 80 00 06  be  0xa008a92c
a008a918:  80 a0 60 04  cmp  %g1, 4
a008a91c:  02 80 00 09  be  0xa008a940
a008a920:  80 a0 60 14  cmp  %g1, 0x14
a008a924:  12 80 00 0b  bne  0xa008a950
a008a928:  01 00 00 00  nop
a008a92c:  9a 10 20 01  mov  1, %o5	! 0x1
a008a930:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a008a934:  da 2c 62 a1  stb  %o5, [ %l1 + 0x2a1 ]	! 0xa802d2a1
a008a938:  40 01 3b 8b  call  0xa00d9764
a008a93c:  81 e8 00 00  restore
a008a940:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a008a944:  c0 2c 22 a1  clrb  [ %l0 + 0x2a1 ]	! 0xa802d2a1
a008a948:  40 01 3b 87  call  0xa00d9764
a008a94c:  81 e8 00 00  restore
a008a950:  01 00 00 00  nop
a008a954:  81 c7 e0 08  ret
a008a958:  81 e8 00 00  restore
