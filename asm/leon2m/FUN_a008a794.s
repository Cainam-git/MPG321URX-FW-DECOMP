# leon2m FUN_a008a794 0xa008a794-0xa008a878 (228 bytes)  [FUN_a008a870 = unreachable ret/restore tail, merged]
a008a794:  9d e3 bf 98  save  %sp, -104, %sp
a008a798:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a008a79c:  d6 0c 63 bd  ldub  [ %l1 + 0x3bd ], %o3	! 0xa802afbd
a008a7a0:  94 02 c0 0b  add  %o3, %o3, %o2
a008a7a4:  11 00 04 00  sethi  %hi(0x100000), %o0
a008a7a8:  92 02 80 0b  add  %o2, %o3, %o1
a008a7ac:  a0 12 22 42  or  %o0, 0x242, %l0
a008a7b0:  98 02 40 10  add  %o1, %l0, %o4
a008a7b4:  d0 0c 00 09  ldub  [ %l0 + %o1 ], %o0
a008a7b8:  d4 0b 20 02  ldub  [ %o4 + 2 ], %o2
a008a7bc:  d2 0b 20 01  ldub  [ %o4 + 1 ], %o1
a008a7c0:  96 10 27 90  mov  0x790, %o3
a008a7c4:  40 02 f0 af  call  0xa0146a80
a008a7c8:  98 10 20 00  clr  %o4
a008a7cc:  c2 0c 63 bd  ldub  [ %l1 + 0x3bd ], %g1
a008a7d0:  82 00 7f ff  add  %g1, -1, %g1
a008a7d4:  9a 08 60 ff  and  %g1, 0xff, %o5
a008a7d8:  80 a3 60 0c  cmp  %o5, 0xc
a008a7dc:  28 80 00 02  bleu,a   0xa008a7e4
a008a7e0:  82 10 20 1a  mov  0x1a, %g1
a008a7e4:  c2 2c 63 bd  stb  %g1, [ %l1 + 0x3bd ]
a008a7e8:  c2 0c 63 bd  ldub  [ %l1 + 0x3bd ], %g1
a008a7ec:  98 00 40 01  add  %g1, %g1, %o4
a008a7f0:  9a 03 00 01  add  %o4, %g1, %o5
a008a7f4:  9e 03 40 10  add  %o5, %l0, %o7
a008a7f8:  d0 0c 00 0d  ldub  [ %l0 + %o5 ], %o0
a008a7fc:  d4 0b e0 02  ldub  [ %o7 + 2 ], %o2
a008a800:  d2 0b e0 01  ldub  [ %o7 + 1 ], %o1
a008a804:  96 10 20 90  mov  0x90, %o3
a008a808:  40 02 f0 9e  call  0xa0146a80
a008a80c:  98 10 20 00  clr  %o4
a008a810:  c2 0c 63 bd  ldub  [ %l1 + 0x3bd ], %g1
a008a814:  80 a0 60 03  cmp  %g1, 3
a008a818:  02 80 00 0d  be  0xa008a84c
a008a81c:  9a 10 20 02  mov  2, %o5
a008a820:  80 a0 60 09  cmp  %g1, 9
a008a824:  02 80 00 0a  be  0xa008a84c
a008a828:  9a 10 20 03  mov  3, %o5
a008a82c:  80 a0 60 0c  cmp  %g1, 0xc
a008a830:  02 80 00 06  be  0xa008a848
a008a834:  80 a0 60 06  cmp  %g1, 6
a008a838:  02 80 00 09  be  0xa008a85c
a008a83c:  80 a0 60 14  cmp  %g1, 0x14
a008a840:  12 80 00 0b  bne  0xa008a86c
a008a844:  01 00 00 00  nop
a008a848:  9a 10 20 01  mov  1, %o5	! 0x1
a008a84c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a008a850:  da 2c 62 a1  stb  %o5, [ %l1 + 0x2a1 ]	! 0xa802d2a1
a008a854:  40 01 3b c4  call  0xa00d9764
a008a858:  81 e8 00 00  restore
a008a85c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a008a860:  c0 2c 22 a1  clrb  [ %l0 + 0x2a1 ]	! 0xa802d2a1
a008a864:  40 01 3b c0  call  0xa00d9764
a008a868:  81 e8 00 00  restore
a008a86c:  01 00 00 00  nop
a008a870:  81 c7 e0 08  ret
a008a874:  81 e8 00 00  restore
