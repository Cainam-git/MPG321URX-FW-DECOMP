# leon2m FUN_a00ae790 0xa00ae790-0xa00ae8e0 (336 bytes)
a00ae790:  9d e3 bf 90  save  %sp, -112, %sp
a00ae794:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ae798:  94 14 62 90  or  %l1, 0x290, %o2	! 0xa802d290
a00ae79c:  d2 0a a1 82  ldub  [ %o2 + 0x182 ], %o1
a00ae7a0:  90 0a 60 03  and  %o1, 3, %o0
a00ae7a4:  82 02 00 08  add  %o0, %o0, %g1
a00ae7a8:  a0 00 60 04  add  %g1, 4, %l0
a00ae7ac:  90 10 20 00  clr  %o0
a00ae7b0:  92 10 20 00  clr  %o1
a00ae7b4:  94 10 20 00  clr  %o2
a00ae7b8:  40 00 15 c6  call  0xa00b3ed0
a00ae7bc:  96 10 20 00  clr  %o3
a00ae7c0:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00ae7c4:  90 10 20 00  clr  %o0
a00ae7c8:  92 10 20 00  clr  %o1
a00ae7cc:  94 10 27 92  mov  0x792, %o2
a00ae7d0:  96 10 20 03  mov  3, %o3
a00ae7d4:  98 10 20 0a  mov  0xa, %o4
a00ae7d8:  80 a4 20 0a  cmp  %l0, 0xa
a00ae7dc:  02 80 00 2a  be  0xa00ae884
a00ae7e0:  9a 10 20 02  mov  2, %o5
a00ae7e4:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae7e8:  90 10 20 00  clr  %o0
a00ae7ec:  92 10 20 00  clr  %o1
a00ae7f0:  94 10 27 92  mov  0x792, %o2
a00ae7f4:  96 10 20 03  mov  3, %o3
a00ae7f8:  98 10 00 10  mov  %l0, %o4
a00ae7fc:  9a 10 20 03  mov  3, %o5
a00ae800:  40 00 12 b9  call  0xa00b32e4
a00ae804:  01 00 00 00  nop
a00ae808:  98 10 00 10  mov  %l0, %o4
a00ae80c:  96 10 20 12  mov  0x12, %o3
a00ae810:  9a 10 20 03  mov  3, %o5
a00ae814:  90 10 20 00  clr  %o0
a00ae818:  92 10 20 00  clr  %o1
a00ae81c:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae820:  40 00 12 b1  call  0xa00b32e4
a00ae824:  94 10 27 92  mov  0x792, %o2
a00ae828:  9e 14 62 90  or  %l1, 0x290, %o7
a00ae82c:  d2 0b e1 82  ldub  [ %o7 + 0x182 ], %o1
a00ae830:  a0 02 60 05  add  %o1, 5, %l0
a00ae834:  97 3c 20 1f  sra  %l0, 0x1f, %o3
a00ae838:  81 82 e0 00  mov  %o3, %y
a00ae83c:  01 00 00 00  nop
a00ae840:  01 00 00 00  nop
a00ae844:  01 00 00 00  nop
a00ae848:  90 7c 20 06  sdiv  %l0, 6, %o0
a00ae84c:  82 5a 20 06  smul  %o0, 6, %g1
a00ae850:  9a 24 00 01  sub  %l0, %g1, %o5
a00ae854:  98 0b 60 ff  and  %o5, 0xff, %o4
a00ae858:  da 2b e1 82  stb  %o5, [ %o7 + 0x182 ]
a00ae85c:  80 a3 20 05  cmp  %o4, 5
a00ae860:  02 80 00 05  be  0xa00ae874
a00ae864:  91 33 20 02  srl  %o4, 2, %o0
a00ae868:  80 a3 20 03  cmp  %o4, 3
a00ae86c:  32 80 00 13  bne,a   0xa00ae8b8
a00ae870:  d8 0b e1 82  ldub  [ %o7 + 0x182 ], %o4
a00ae874:  40 00 29 0d  call  0xa00b8ca8
a00ae878:  01 00 00 00  nop
a00ae87c:  10 80 00 0e  b  0xa00ae8b4
a00ae880:  9e 14 62 90  or  %l1, 0x290, %o7
a00ae884:  40 00 12 98  call  0xa00b32e4
a00ae888:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae88c:  98 10 20 11  mov  0x11, %o4
a00ae890:  17 00 00 0c  sethi  %hi(0x3000), %o3
a00ae894:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00ae898:  94 12 e0 92  or  %o3, 0x92, %o2
a00ae89c:  90 10 20 01  mov  1, %o0
a00ae8a0:  92 10 20 00  clr  %o1
a00ae8a4:  96 10 20 03  mov  3, %o3
a00ae8a8:  98 10 20 0c  mov  0xc, %o4
a00ae8ac:  10 bf ff d5  b  0xa00ae800
a00ae8b0:  9a 10 20 01  mov  1, %o5
a00ae8b4:  d8 0b e1 82  ldub  [ %o7 + 0x182 ], %o4
a00ae8b8:  90 0b 20 03  and  %o4, 3, %o0
a00ae8bc:  7f ff fb ec  call  0xa00ad86c
a00ae8c0:  92 10 20 01  mov  1, %o1
a00ae8c4:  40 00 b5 0b  call  0xa00dbcf0
a00ae8c8:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00ae8cc:  d6 0c 60 8e  ldub  [ %l1 + 0x8e ], %o3	! 0xa802b08e
a00ae8d0:  94 12 e0 02  or  %o3, 2, %o2
a00ae8d4:  d4 2c 60 8e  stb  %o2, [ %l1 + 0x8e ]
a00ae8d8:  81 c7 e0 08  ret
a00ae8dc:  81 e8 00 00  restore
