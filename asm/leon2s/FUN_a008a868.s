# leon2s FUN_a008a868 0xa008a868-0xa008a924 (188 bytes)
a008a868:  9d e3 bf 98  save  %sp, -104, %sp
a008a86c:  03 2a 01 d9  sethi  %hi(0xa8076400), %g1
a008a870:  90 0e 20 ff  and  %i0, 0xff, %o0
a008a874:  a0 10 62 88  or  %g1, 0x288, %l0
a008a878:  80 a2 20 00  cmp  %o0, 0
a008a87c:  02 80 00 15  be  0xa008a8d0
a008a880:  b0 10 00 10  mov  %l0, %i0
a008a884:  c2 0c 20 02  ldub  [ %l0 + 2 ], %g1
a008a888:  80 88 60 01  btst  1, %g1
a008a88c:  02 80 00 05  be  0xa008a8a0
a008a890:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a894:  7f ff ff e4  call  0xa008a824
a008a898:  01 00 00 00  nop
a008a89c:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a8a0:  9a 10 62 0c  or  %g1, 0x20c, %o5	! 0xcf01120c
a008a8a4:  98 10 62 18  or  %g1, 0x218, %o4
a008a8a8:  c2 0c 20 02  ldub  [ %l0 + 2 ], %g1
a008a8ac:  80 88 60 02  btst  2, %g1
a008a8b0:  02 80 00 1b  be  0xa008a91c
a008a8b4:  01 00 00 00  nop
a008a8b8:  c2 03 40 00  ld  [ %o5 ], %g1
a008a8bc:  82 10 60 80  or  %g1, 0x80, %g1
a008a8c0:  c2 23 40 00  st  %g1, [ %o5 ]
a008a8c4:  c2 03 00 00  ld  [ %o4 ], %g1
a008a8c8:  10 80 00 14  b  0xa008a918
a008a8cc:  82 10 60 80  or  %g1, 0x80, %g1
a008a8d0:  c2 0c 20 02  ldub  [ %l0 + 2 ], %g1
a008a8d4:  80 88 60 01  btst  1, %g1
a008a8d8:  02 80 00 04  be  0xa008a8e8
a008a8dc:  90 10 20 00  clr  %o0
a008a8e0:  7f ff ff d1  call  0xa008a824
a008a8e4:  01 00 00 00  nop
a008a8e8:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a8ec:  9a 10 62 0c  or  %g1, 0x20c, %o5	! 0xcf01120c
a008a8f0:  98 10 62 18  or  %g1, 0x218, %o4
a008a8f4:  c2 0e 20 02  ldub  [ %i0 + 2 ], %g1
a008a8f8:  80 88 60 02  btst  2, %g1
a008a8fc:  02 80 00 08  be  0xa008a91c
a008a900:  01 00 00 00  nop
a008a904:  c2 03 40 00  ld  [ %o5 ], %g1
a008a908:  82 08 7f 7f  and  %g1, -129, %g1
a008a90c:  c2 23 40 00  st  %g1, [ %o5 ]
a008a910:  c2 03 00 00  ld  [ %o4 ], %g1
a008a914:  82 08 7f 7f  and  %g1, -129, %g1
a008a918:  c2 23 00 00  st  %g1, [ %o4 ]
a008a91c:  81 c7 e0 08  ret
a008a920:  81 e8 00 00  restore
