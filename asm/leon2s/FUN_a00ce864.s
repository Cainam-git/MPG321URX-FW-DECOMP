# leon2s FUN_a00ce864 0xa00ce864-0xa00cea60 (508 bytes)
a00ce864:  9d e3 bf 88  save  %sp, -120, %sp
a00ce868:  a4 0e 20 ff  and  %i0, 0xff, %l2
a00ce86c:  82 04 80 12  add  %l2, %l2, %g1
a00ce870:  82 00 40 12  add  %g1, %l2, %g1
a00ce874:  a1 28 60 03  sll  %g1, 3, %l0
a00ce878:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00ce87c:  29 2a 01 e2  sethi  %hi(0xa8078800), %l4
a00ce880:  a2 15 23 b0  or  %l4, 0x3b0, %l1	! 0xa8078bb0
a00ce884:  a6 10 63 ff  or  %g1, 0x3ff, %l3
a00ce888:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00ce88c:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00ce890:  82 08 40 13  and  %g1, %l3, %g1
a00ce894:  82 10 40 0d  or  %g1, %o5, %g1
a00ce898:  19 2a 01 f5  sethi  %hi(0xa807d400), %o4
a00ce89c:  da 0b 22 36  ldub  [ %o4 + 0x236 ], %o5	! 0xa807d636
a00ce8a0:  80 a3 40 12  cmp  %o5, %l2
a00ce8a4:  12 80 00 09  bne  0xa00ce8c8
a00ce8a8:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00ce8ac:  82 10 3f ff  mov  -1, %g1
a00ce8b0:  9a 04 00 11  add  %l0, %l1, %o5
a00ce8b4:  c2 2b 22 36  stb  %g1, [ %o4 + 0x236 ]
a00ce8b8:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00ce8bc:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00ce8c0:  40 3a d1 e1  call  0xa0f83044
a00ce8c4:  90 12 21 58  or  %o0, 0x158, %o0
a00ce8c8:  aa 07 bf e8  add  %fp, -24, %l5
a00ce8cc:  15 00 01 a5  sethi  %hi(0x69400), %o2
a00ce8d0:  96 10 20 00  clr  %o3
a00ce8d4:  94 12 a0 93  or  %o2, 0x93, %o2
a00ce8d8:  90 10 20 00  clr  %o0
a00ce8dc:  92 10 20 90  mov  0x90, %o1
a00ce8e0:  40 3b 1e c8  call  0xa0f96400
a00ce8e4:  98 10 00 15  mov  %l5, %o4
a00ce8e8:  d6 0f bf e8  ldub  [ %fp + -24 ], %o3
a00ce8ec:  80 8a e0 06  btst  6, %o3
a00ce8f0:  02 80 00 1d  be  0xa00ce964
a00ce8f4:  80 8a e0 18  btst  0x18, %o3
a00ce8f8:  d8 04 40 10  ld  [ %l1 + %l0 ], %o4
a00ce8fc:  83 33 20 18  srl  %o4, 0x18, %g1
a00ce900:  82 08 60 0f  and  %g1, 0xf, %g1
a00ce904:  82 00 7f ff  add  %g1, -1, %g1
a00ce908:  82 08 60 0f  and  %g1, 0xf, %g1
a00ce90c:  1b 03 c0 00  sethi  %hi(0xf000000), %o5
a00ce910:  83 28 60 18  sll  %g1, 0x18, %g1
a00ce914:  9a 2b 00 0d  andn  %o4, %o5, %o5
a00ce918:  9a 13 40 01  or  %o5, %g1, %o5
a00ce91c:  83 33 60 18  srl  %o5, 0x18, %g1
a00ce920:  80 88 60 0f  btst  0xf, %g1
a00ce924:  12 80 00 04  bne  0xa00ce934
a00ce928:  da 24 40 10  st  %o5, [ %l1 + %l0 ]
a00ce92c:  10 80 00 04  b  0xa00ce93c
a00ce930:  82 0b 40 13  and  %o5, %l3, %g1
a00ce934:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00ce938:  82 13 40 01  or  %o5, %g1, %g1
a00ce93c:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00ce940:  82 04 80 12  add  %l2, %l2, %g1
a00ce944:  82 00 40 12  add  %g1, %l2, %g1
a00ce948:  9a 15 23 b0  or  %l4, 0x3b0, %o5
a00ce94c:  83 28 60 03  sll  %g1, 3, %g1
a00ce950:  c2 13 40 01  lduh  [ %o5 + %g1 ], %g1
a00ce954:  82 08 60 03  and  %g1, 3, %g1
a00ce958:  80 a0 60 01  cmp  %g1, 1
a00ce95c:  12 80 00 3f  bne  0xa00cea58
a00ce960:  80 8a e0 18  btst  0x18, %o3
a00ce964:  a0 10 20 00  clr  %l0
a00ce968:  02 80 00 0d  be  0xa00ce99c
a00ce96c:  a2 07 bf f8  add  %fp, -8, %l1
a00ce970:  82 0e 20 ff  and  %i0, 0xff, %g1
a00ce974:  9a 00 40 01  add  %g1, %g1, %o5
a00ce978:  9a 03 40 01  add  %o5, %g1, %o5
a00ce97c:  19 2a 01 e2  sethi  %hi(0xa8078800), %o4
a00ce980:  98 13 23 b0  or  %o4, 0x3b0, %o4	! 0xa8078bb0
a00ce984:  9b 2b 60 03  sll  %o5, 3, %o5
a00ce988:  d6 03 00 0d  ld  [ %o4 + %o5 ], %o3
a00ce98c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00ce990:  82 2a c0 01  andn  %o3, %g1, %g1
a00ce994:  10 80 00 31  b  0xa00cea58
a00ce998:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a00ce99c:  96 04 20 01  add  %l0, 1, %o3
a00ce9a0:  83 2c 20 10  sll  %l0, 0x10, %g1
a00ce9a4:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce9a8:  99 2a e0 10  sll  %o3, 0x10, %o4
a00ce9ac:  9a 04 3f b0  add  %l0, -80, %o5
a00ce9b0:  82 04 40 01  add  %l1, %g1, %g1
a00ce9b4:  99 33 20 10  srl  %o4, 0x10, %o4
a00ce9b8:  da 28 7f f0  stb  %o5, [ %g1 + -16 ]
a00ce9bc:  80 a3 20 07  cmp  %o4, 7
a00ce9c0:  08 bf ff f7  bleu  0xa00ce99c
a00ce9c4:  a0 10 00 0b  mov  %o3, %l0
a00ce9c8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ce9cc:  90 10 00 18  mov  %i0, %o0
a00ce9d0:  92 10 20 08  mov  8, %o1
a00ce9d4:  7f ff e7 85  call  0xa00c87e8
a00ce9d8:  15 00 00 20  sethi  %hi(0x8000), %o2
a00ce9dc:  a0 10 20 00  clr  %l0
a00ce9e0:  83 2c 20 10  sll  %l0, 0x10, %g1
a00ce9e4:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce9e8:  82 04 40 01  add  %l1, %g1, %g1
a00ce9ec:  d4 08 7f f0  ldub  [ %g1 + -16 ], %o2
a00ce9f0:  90 10 00 18  mov  %i0, %o0
a00ce9f4:  7f ff e3 18  call  0xa00c7654
a00ce9f8:  92 10 20 01  mov  1, %o1
a00ce9fc:  9a 04 20 01  add  %l0, 1, %o5
a00cea00:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cea04:  83 30 60 10  srl  %g1, 0x10, %g1
a00cea08:  80 a0 60 07  cmp  %g1, 7
a00cea0c:  08 bf ff f5  bleu  0xa00ce9e0
a00cea10:  a0 10 00 0d  mov  %o5, %l0
a00cea14:  15 00 01 a4  sethi  %hi(0x69000), %o2
a00cea18:  94 12 a2 f0  or  %o2, 0x2f0, %o2	! 0x692f0
a00cea1c:  92 10 20 80  mov  0x80, %o1
a00cea20:  98 10 00 15  mov  %l5, %o4
a00cea24:  90 10 20 00  clr  %o0
a00cea28:  40 3b 1e 6b  call  0xa0f963d4
a00cea2c:  96 10 20 07  mov  7, %o3
a00cea30:  90 10 00 18  mov  %i0, %o0
a00cea34:  92 10 20 06  mov  6, %o1
a00cea38:  7f ff e3 07  call  0xa00c7654
a00cea3c:  94 10 20 d0  mov  0xd0, %o2
a00cea40:  90 10 00 18  mov  %i0, %o0
a00cea44:  7f ff e3 4b  call  0xa00c7770
a00cea48:  92 10 20 06  mov  6, %o1
a00cea4c:  80 8a 20 80  btst  0x80, %o0
a00cea50:  12 bf ff fd  bne  0xa00cea44
a00cea54:  90 10 00 18  mov  %i0, %o0
a00cea58:  81 c7 e0 08  ret
a00cea5c:  81 e8 00 00  restore
