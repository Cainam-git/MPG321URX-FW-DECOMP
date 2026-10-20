# leon2s FUN_a00db784 0xa00db784-0xa00db9d4 (592 bytes)
a00db784:  9d e3 bf 90  save  %sp, -112, %sp
a00db788:  27 2a 01 e1  sethi  %hi(0xa8078400), %l3
a00db78c:  d6 0c e3 fd  ldub  [ %l3 + 0x3fd ], %o3	! 0xa80787fd
a00db790:  9a 02 c0 0b  add  %o3, %o3, %o5
a00db794:  9a 03 40 0b  add  %o5, %o3, %o5
a00db798:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a00db79c:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00db7a0:  9b 2b 60 04  sll  %o5, 4, %o5
a00db7a4:  d8 0c a0 41  ldub  [ %l2 + 0x41 ], %o4
a00db7a8:  82 10 60 98  or  %g1, 0x98, %g1
a00db7ac:  a0 03 40 01  add  %o5, %g1, %l0
a00db7b0:  80 8b 20 10  btst  0x10, %o4
a00db7b4:  02 80 00 25  be  0xa00db848
a00db7b8:  c0 2f bf f7  clrb  [ %fp + -9 ]
a00db7bc:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00db7c0:  82 10 60 50  or  %g1, 0x50, %g1	! 0xa8079c50
a00db7c4:  c0 28 40 0b  clrb  [ %g1 + %o3 ]
a00db7c8:  90 10 20 00  clr  %o0
a00db7cc:  92 10 20 90  mov  0x90, %o1
a00db7d0:  15 00 00 05  sethi  %hi(0x1400), %o2
a00db7d4:  96 10 20 0f  mov  0xf, %o3
a00db7d8:  40 3a eb 0a  call  0xa0f96400
a00db7dc:  98 10 00 10  mov  %l0, %o4
a00db7e0:  80 8a 20 ff  btst  0xff, %o0
a00db7e4:  02 80 00 2a  be  0xa00db88c
a00db7e8:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db7ec:  23 00 00 05  sethi  %hi(0x1400), %l1
a00db7f0:  90 10 20 00  clr  %o0
a00db7f4:  92 10 20 90  mov  0x90, %o1
a00db7f8:  94 14 60 10  or  %l1, 0x10, %o2
a00db7fc:  96 10 20 0f  mov  0xf, %o3
a00db800:  40 3a eb 00  call  0xa0f96400
a00db804:  98 04 20 10  add  %l0, 0x10, %o4
a00db808:  80 8a 20 ff  btst  0xff, %o0
a00db80c:  02 80 00 2b  be  0xa00db8b8
a00db810:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db814:  94 14 60 20  or  %l1, 0x20, %o2
a00db818:  90 10 20 00  clr  %o0
a00db81c:  92 10 20 90  mov  0x90, %o1
a00db820:  96 10 20 0f  mov  0xf, %o3
a00db824:  40 3a ea f7  call  0xa0f96400
a00db828:  98 04 20 20  add  %l0, 0x20, %o4
a00db82c:  80 8a 20 ff  btst  0xff, %o0
a00db830:  02 80 00 2c  be  0xa00db8e0
a00db834:  c2 0c a0 41  ldub  [ %l2 + 0x41 ], %g1
a00db838:  da 0f bf f7  ldub  [ %fp + -9 ], %o5
a00db83c:  9a 13 60 10  or  %o5, 0x10, %o5
a00db840:  10 80 00 30  b  0xa00db900
a00db844:  82 08 7f ef  and  %g1, -17, %g1
a00db848:  80 8b 20 20  btst  0x20, %o4
a00db84c:  02 80 00 5f  be  0xa00db9c8
a00db850:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00db854:  9a 10 20 01  mov  1, %o5
a00db858:  82 10 60 50  or  %g1, 0x50, %g1
a00db85c:  da 28 40 0b  stb  %o5, [ %g1 + %o3 ]
a00db860:  23 00 00 05  sethi  %hi(0x1400), %l1
a00db864:  90 10 20 00  clr  %o0
a00db868:  92 10 20 90  mov  0x90, %o1
a00db86c:  94 14 62 00  or  %l1, 0x200, %o2
a00db870:  96 10 20 0f  mov  0xf, %o3
a00db874:  40 3a ea e3  call  0xa0f96400
a00db878:  98 10 00 10  mov  %l0, %o4
a00db87c:  80 8a 20 ff  btst  0xff, %o0
a00db880:  32 80 00 05  bne,a   0xa00db894
a00db884:  90 10 20 00  clr  %o0
a00db888:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db88c:  10 80 00 17  b  0xa00db8e8
a00db890:  90 12 23 58  or  %o0, 0x358, %o0	! 0x9f1ccb58
a00db894:  92 10 20 90  mov  0x90, %o1
a00db898:  94 14 62 10  or  %l1, 0x210, %o2
a00db89c:  96 10 20 0f  mov  0xf, %o3
a00db8a0:  40 3a ea d8  call  0xa0f96400
a00db8a4:  98 04 20 10  add  %l0, 0x10, %o4
a00db8a8:  80 8a 20 ff  btst  0xff, %o0
a00db8ac:  12 80 00 05  bne  0xa00db8c0
a00db8b0:  94 14 62 20  or  %l1, 0x220, %o2
a00db8b4:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db8b8:  10 80 00 0c  b  0xa00db8e8
a00db8bc:  90 12 23 78  or  %o0, 0x378, %o0	! 0x9f1ccb78
a00db8c0:  90 10 20 00  clr  %o0
a00db8c4:  92 10 20 90  mov  0x90, %o1
a00db8c8:  96 10 20 0f  mov  0xf, %o3
a00db8cc:  40 3a ea cd  call  0xa0f96400
a00db8d0:  98 04 20 20  add  %l0, 0x20, %o4
a00db8d4:  80 8a 20 ff  btst  0xff, %o0
a00db8d8:  12 80 00 07  bne  0xa00db8f4
a00db8dc:  c2 0c a0 41  ldub  [ %l2 + 0x41 ], %g1
a00db8e0:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db8e4:  90 12 23 98  or  %o0, 0x398, %o0	! 0x9f1ccb98
a00db8e8:  40 3a 9e f7  call  0xa0f834c4
a00db8ec:  01 00 00 00  nop
a00db8f0:  30 80 00 36  b,a   0xa00db9c8
a00db8f4:  da 0f bf f7  ldub  [ %fp + -9 ], %o5
a00db8f8:  9a 13 60 20  or  %o5, 0x20, %o5
a00db8fc:  82 08 7f df  and  %g1, -33, %g1
a00db900:  c2 2c a0 41  stb  %g1, [ %l2 + 0x41 ]
a00db904:  da 2f bf f7  stb  %o5, [ %fp + -9 ]
a00db908:  d8 0c 00 00  ldub  [ %l0 ], %o4
a00db90c:  9b 33 20 04  srl  %o4, 4, %o5
a00db910:  9a 03 7f ff  add  %o5, -1, %o5
a00db914:  83 33 60 1f  srl  %o5, 0x1f, %g1
a00db918:  82 03 40 01  add  %o5, %g1, %g1
a00db91c:  83 38 60 01  sra  %g1, 1, %g1
a00db920:  80 8b 60 01  btst  1, %o5
a00db924:  02 80 00 03  be  0xa00db930
a00db928:  a2 10 00 01  mov  %g1, %l1
a00db92c:  a2 00 60 01  add  %g1, 1, %l1
a00db930:  80 8b 20 0f  btst  0xf, %o4
a00db934:  02 80 00 06  be  0xa00db94c
a00db938:  15 00 00 08  sethi  %hi(0x2000), %o2
a00db93c:  c2 0c e3 fd  ldub  [ %l3 + 0x3fd ], %g1
a00db940:  82 00 60 01  inc  %g1
a00db944:  82 08 60 0f  and  %g1, 0xf, %g1
a00db948:  c2 2c e3 fd  stb  %g1, [ %l3 + 0x3fd ]
a00db94c:  94 12 a0 03  or  %o2, 3, %o2
a00db950:  90 10 20 00  clr  %o0
a00db954:  92 10 20 80  mov  0x80, %o1
a00db958:  96 10 20 00  clr  %o3
a00db95c:  40 3a ea 9e  call  0xa0f963d4
a00db960:  98 07 bf f7  add  %fp, -9, %o4
a00db964:  80 8a 20 ff  btst  0xff, %o0
a00db968:  12 80 00 06  bne  0xa00db980
a00db96c:  82 0c 60 ff  and  %l1, 0xff, %g1
a00db970:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db974:  40 3a 9e d4  call  0xa0f834c4
a00db978:  90 12 23 b8  or  %o0, 0x3b8, %o0	! 0x9f1ccbb8
a00db97c:  82 0c 60 ff  and  %l1, 0xff, %g1
a00db980:  98 04 00 01  add  %l0, %g1, %o4
a00db984:  c2 0b 20 03  ldub  [ %o4 + 3 ], %g1
a00db988:  80 a0 60 11  cmp  %g1, 0x11
a00db98c:  12 80 00 0f  bne  0xa00db9c8
a00db990:  01 00 00 00  nop
a00db994:  c2 0b 20 06  ldub  [ %o4 + 6 ], %g1
a00db998:  80 a0 60 00  cmp  %g1, 0
a00db99c:  12 80 00 0b  bne  0xa00db9c8
a00db9a0:  01 00 00 00  nop
a00db9a4:  c2 0b 20 07  ldub  [ %o4 + 7 ], %g1
a00db9a8:  80 a0 60 00  cmp  %g1, 0
a00db9ac:  12 80 00 07  bne  0xa00db9c8
a00db9b0:  92 10 20 01  mov  1, %o1
a00db9b4:  d0 0b 20 05  ldub  [ %o4 + 5 ], %o0
a00db9b8:  7f ff fd 36  call  0xa00dae90
a00db9bc:  94 10 20 00  clr  %o2
a00db9c0:  7f ff ea cb  call  0xa00d64ec
a00db9c4:  01 00 00 00  nop
a00db9c8:  01 00 00 00  nop
a00db9cc:  81 c7 e0 08  ret
a00db9d0:  81 e8 00 00  restore
