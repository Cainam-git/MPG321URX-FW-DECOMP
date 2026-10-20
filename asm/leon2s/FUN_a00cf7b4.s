# leon2s FUN_a00cf7b4 0xa00cf7b4-0xa00cf954 (416 bytes)
a00cf7b4:  9d e3 bf 88  save  %sp, -120, %sp
a00cf7b8:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00cf7bc:  82 03 40 0d  add  %o5, %o5, %g1
a00cf7c0:  82 00 40 0d  add  %g1, %o5, %g1
a00cf7c4:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00cf7c8:  a3 28 60 03  sll  %g1, 3, %l1
a00cf7cc:  a4 13 63 b0  or  %o5, 0x3b0, %l2
a00cf7d0:  da 04 80 11  ld  [ %l2 + %l1 ], %o5
a00cf7d4:  83 33 60 16  srl  %o5, 0x16, %g1
a00cf7d8:  80 88 60 01  btst  1, %g1
a00cf7dc:  12 80 00 05  bne  0xa00cf7f0
a00cf7e0:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cf7e4:  82 13 40 01  or  %o5, %g1, %g1
a00cf7e8:  10 80 00 59  b  0xa00cf94c
a00cf7ec:  c2 24 80 11  st  %g1, [ %l2 + %l1 ]
a00cf7f0:  82 2b 40 01  andn  %o5, %g1, %g1
a00cf7f4:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cf7f8:  82 10 40 0d  or  %g1, %o5, %g1
a00cf7fc:  a8 07 bf e8  add  %fp, -24, %l4
a00cf800:  15 00 01 a5  sethi  %hi(0x69400), %o2
a00cf804:  c2 24 80 11  st  %g1, [ %l2 + %l1 ]
a00cf808:  94 12 a0 93  or  %o2, 0x93, %o2
a00cf80c:  92 10 20 90  mov  0x90, %o1
a00cf810:  96 10 20 00  clr  %o3
a00cf814:  98 10 00 14  mov  %l4, %o4
a00cf818:  40 3b 1a fa  call  0xa0f96400
a00cf81c:  90 10 20 00  clr  %o0
a00cf820:  21 00 01 a4  sethi  %hi(0x69000), %l0
a00cf824:  19 2a 01 f4  sethi  %hi(0xa807d000), %o4
a00cf828:  98 13 20 88  or  %o4, 0x88, %o4	! 0xa807d088
a00cf82c:  90 10 20 00  clr  %o0
a00cf830:  92 10 20 80  mov  0x80, %o1
a00cf834:  94 14 23 f0  or  %l0, 0x3f0, %o2
a00cf838:  40 3b 1a e7  call  0xa0f963d4
a00cf83c:  96 10 20 04  mov  4, %o3
a00cf840:  82 04 40 12  add  %l1, %l2, %g1
a00cf844:  c2 08 60 14  ldub  [ %g1 + 0x14 ], %g1
a00cf848:  80 a0 60 00  cmp  %g1, 0
a00cf84c:  aa 14 23 f5  or  %l0, 0x3f5, %l5
a00cf850:  02 80 00 3f  be  0xa00cf94c
a00cf854:  a4 10 20 00  clr  %l2
a00cf858:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00cf85c:  82 04 40 11  add  %l1, %l1, %g1
a00cf860:  82 00 40 11  add  %g1, %l1, %g1
a00cf864:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a00cf868:  9a 14 e3 b0  or  %l3, 0x3b0, %o5	! 0xa8078bb0
a00cf86c:  83 28 60 03  sll  %g1, 3, %g1
a00cf870:  82 00 40 0d  add  %g1, %o5, %g1
a00cf874:  d8 08 60 14  ldub  [ %g1 + 0x14 ], %o4
a00cf878:  90 0c a0 ff  and  %l2, 0xff, %o0
a00cf87c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00cf880:  9a 02 20 08  add  %o0, 8, %o5
a00cf884:  80 a3 40 01  cmp  %o5, %g1
a00cf888:  04 80 00 03  ble  0xa00cf894
a00cf88c:  82 10 20 08  mov  8, %g1
a00cf890:  82 23 00 12  sub  %o4, %l2, %g1
a00cf894:  92 08 60 ff  and  %g1, 0xff, %o1
a00cf898:  80 a2 60 00  cmp  %o1, 0
a00cf89c:  02 80 00 15  be  0xa00cf8f0
a00cf8a0:  94 10 20 00  clr  %o2
a00cf8a4:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cf8a8:  9e 10 62 50  or  %g1, 0x250, %o7	! 0xa807ce50
a00cf8ac:  a0 07 bf f8  add  %fp, -8, %l0
a00cf8b0:  83 2a a0 10  sll  %o2, 0x10, %g1
a00cf8b4:  83 30 60 10  srl  %g1, 0x10, %g1
a00cf8b8:  9a 00 40 08  add  %g1, %o0, %o5
a00cf8bc:  9a 03 40 0d  add  %o5, %o5, %o5
a00cf8c0:  94 02 a0 01  inc  %o2
a00cf8c4:  96 03 40 0f  add  %o5, %o7, %o3
a00cf8c8:  99 2a a0 10  sll  %o2, 0x10, %o4
a00cf8cc:  82 00 40 01  add  %g1, %g1, %g1
a00cf8d0:  82 00 40 10  add  %g1, %l0, %g1
a00cf8d4:  d6 0a e0 01  ldub  [ %o3 + 1 ], %o3
a00cf8d8:  99 33 20 10  srl  %o4, 0x10, %o4
a00cf8dc:  da 0b c0 0d  ldub  [ %o7 + %o5 ], %o5
a00cf8e0:  d6 28 7f f1  stb  %o3, [ %g1 + -15 ]
a00cf8e4:  80 a3 00 09  cmp  %o4, %o1
a00cf8e8:  0a bf ff f2  bcs  0xa00cf8b0
a00cf8ec:  da 28 7f f0  stb  %o5, [ %g1 + -16 ]
a00cf8f0:  97 2a a0 10  sll  %o2, 0x10, %o3
a00cf8f4:  97 32 e0 0f  srl  %o3, 0xf, %o3
a00cf8f8:  94 0c a0 ff  and  %l2, 0xff, %o2
a00cf8fc:  96 02 ff ff  add  %o3, -1, %o3
a00cf900:  95 2a a0 04  sll  %o2, 4, %o2
a00cf904:  97 2a e0 18  sll  %o3, 0x18, %o3
a00cf908:  94 05 40 0a  add  %l5, %o2, %o2
a00cf90c:  97 3a e0 18  sra  %o3, 0x18, %o3
a00cf910:  90 10 20 00  clr  %o0
a00cf914:  92 10 20 80  mov  0x80, %o1
a00cf918:  40 3b 1a af  call  0xa0f963d4
a00cf91c:  98 10 00 14  mov  %l4, %o4
a00cf920:  82 04 40 11  add  %l1, %l1, %g1
a00cf924:  82 00 40 11  add  %g1, %l1, %g1
a00cf928:  9a 14 e3 b0  or  %l3, 0x3b0, %o5
a00cf92c:  83 28 60 03  sll  %g1, 3, %g1
a00cf930:  82 00 40 0d  add  %g1, %o5, %g1
a00cf934:  da 08 60 14  ldub  [ %g1 + 0x14 ], %o5
a00cf938:  a4 04 a0 08  add  %l2, 8, %l2
a00cf93c:  82 0c a0 ff  and  %l2, 0xff, %g1
a00cf940:  80 a0 40 0d  cmp  %g1, %o5
a00cf944:  0a bf ff c6  bcs  0xa00cf85c
a00cf948:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00cf94c:  81 c7 e0 08  ret
a00cf950:  81 e8 00 00  restore
