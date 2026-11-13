# leon2m FUN_a013a8d4 0xa013a8d4-0xa013a98c (184 bytes)
a013a8d4:  9d e3 bf 90  save  %sp, -112, %sp
a013a8d8:  90 10 3f ff  mov  -1, %o0
a013a8dc:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a013a8e0:  90 10 20 02  mov  2, %o0
a013a8e4:  92 10 20 20  mov  0x20, %o1
a013a8e8:  94 07 bf f4  add  %fp, -12, %o2
a013a8ec:  67 fd 46 f9  call  0x4008c4d0
a013a8f0:  96 10 20 01  mov  1, %o3
a013a8f4:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013a8f8:  80 a0 60 00  cmp  %g1, 0
a013a8fc:  02 80 00 10  be  0xa013a93c
a013a900:  a0 10 20 64  mov  0x64, %l0
a013a904:  67 fd 4a 27  call  0x4008d1a0
a013a908:  90 10 20 01  mov  1, %o0
a013a90c:  90 10 20 02  mov  2, %o0
a013a910:  92 10 20 20  mov  0x20, %o1
a013a914:  94 07 bf f4  add  %fp, -12, %o2
a013a918:  67 fd 46 ee  call  0x4008c4d0
a013a91c:  96 10 20 01  mov  1, %o3
a013a920:  a0 04 3f ff  add  %l0, -1, %l0
a013a924:  80 a4 20 00  cmp  %l0, 0
a013a928:  02 80 00 13  be  0xa013a974
a013a92c:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013a930:  80 a2 60 00  cmp  %o1, 0
a013a934:  12 bf ff f4  bne  0xa013a904
a013a938:  01 00 00 00  nop
a013a93c:  82 0e 60 ff  and  %i1, 0xff, %g1
a013a940:  b3 28 60 10  sll  %g1, 0x10, %i1
a013a944:  a1 2e 20 10  sll  %i0, 0x10, %l0
a013a948:  19 21 00 00  sethi  %hi(0x84000000), %o4
a013a94c:  9e 16 40 0c  or  %i1, %o4, %o7
a013a950:  9b 34 20 10  srl  %l0, 0x10, %o5
a013a954:  96 13 c0 0d  or  %o7, %o5, %o3
a013a958:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a013a95c:  90 10 20 02  mov  2, %o0
a013a960:  92 10 20 20  mov  0x20, %o1
a013a964:  94 07 bf f4  add  %fp, -12, %o2
a013a968:  67 fd 47 24  call  0x4008c5f8
a013a96c:  96 10 20 01  mov  1, %o3
a013a970:  30 80 00 05  b,a   0xa013a984
a013a974:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013a978:  80 a2 a0 00  cmp  %o2, 0
a013a97c:  02 bf ff f1  be  0xa013a940
a013a980:  82 0e 60 ff  and  %i1, 0xff, %g1
a013a984:  81 c7 e0 08  ret
a013a988:  81 e8 00 00  restore
