# leon2m FUN_a00da870 0xa00da870-0xa00da9e4 (372 bytes)
a00da870:  80 8a 20 ff  btst  0xff, %o0
a00da874:  12 80 00 16  bne  0xa00da8cc
a00da878:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00da87c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00da880:  96 10 62 90  or  %g1, 0x290, %o3	! 0xa802d290
a00da884:  da 0a e1 e4  ldub  [ %o3 + 0x1e4 ], %o5
a00da888:  80 a3 60 00  cmp  %o5, 0
a00da88c:  12 80 00 45  bne  0xa00da9a0
a00da890:  d8 0a e1 e2  ldub  [ %o3 + 0x1e2 ], %o4
a00da894:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a00da898:  92 12 a3 f4  or  %o2, 0x3f4, %o1	! 0xa802cff4
a00da89c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00da8a0:  c2 12 60 10  lduh  [ %o1 + 0x10 ], %g1
a00da8a4:  80 a3 40 01  cmp  %o5, %g1
a00da8a8:  22 80 00 2a  be,a   0xa00da950
a00da8ac:  d0 0a e1 e6  ldub  [ %o3 + 0x1e6 ], %o0
a00da8b0:  80 a3 20 02  cmp  %o4, 2
a00da8b4:  18 80 00 40  bgu  0xa00da9b4
a00da8b8:  9a 12 a3 f4  or  %o2, 0x3f4, %o5
a00da8bc:  92 10 20 01  mov  1, %o1
a00da8c0:  d2 2b 60 19  stb  %o1, [ %o5 + 0x19 ]
a00da8c4:  10 80 00 46  b  0xa00da9dc
a00da8c8:  90 10 20 01  mov  1, %o0
a00da8cc:  96 13 22 90  or  %o4, 0x290, %o3
a00da8d0:  d4 0a e1 e5  ldub  [ %o3 + 0x1e5 ], %o2
a00da8d4:  80 a2 a0 00  cmp  %o2, 0
a00da8d8:  12 80 00 2d  bne  0xa00da98c
a00da8dc:  d8 0a e1 e3  ldub  [ %o3 + 0x1e3 ], %o4
a00da8e0:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a00da8e4:  92 12 a3 f4  or  %o2, 0x3f4, %o1	! 0xa802cff4
a00da8e8:  82 0b 20 ff  and  %o4, 0xff, %g1
a00da8ec:  d0 12 60 12  lduh  [ %o1 + 0x12 ], %o0
a00da8f0:  80 a0 40 08  cmp  %g1, %o0
a00da8f4:  22 80 00 0e  be,a   0xa00da92c
a00da8f8:  da 0a e1 e7  ldub  [ %o3 + 0x1e7 ], %o5
a00da8fc:  80 a3 20 02  cmp  %o4, 2
a00da900:  38 80 00 07  bgu,a   0xa00da91c
a00da904:  90 12 a3 f4  or  %o2, 0x3f4, %o0
a00da908:  92 12 a3 f4  or  %o2, 0x3f4, %o1
a00da90c:  96 10 20 02  mov  2, %o3
a00da910:  d6 2a 60 19  stb  %o3, [ %o1 + 0x19 ]
a00da914:  10 80 00 32  b  0xa00da9dc
a00da918:  90 10 20 02  mov  2, %o0
a00da91c:  82 10 20 04  mov  4, %g1
a00da920:  c2 2a 20 19  stb  %g1, [ %o0 + 0x19 ]
a00da924:  10 80 00 2e  b  0xa00da9dc
a00da928:  90 10 20 04  mov  4, %o0
a00da92c:  80 a3 60 01  cmp  %o5, 1
a00da930:  12 bf ff f4  bne  0xa00da900
a00da934:  80 a3 20 02  cmp  %o4, 2
a00da938:  18 80 00 27  bgu  0xa00da9d4
a00da93c:  98 10 20 0a  mov  0xa, %o4
a00da940:  94 10 20 08  mov  8, %o2
a00da944:  d4 2a 60 19  stb  %o2, [ %o1 + 0x19 ]
a00da948:  10 80 00 25  b  0xa00da9dc
a00da94c:  90 10 20 08  mov  8, %o0
a00da950:  80 a2 20 01  cmp  %o0, 1
a00da954:  12 bf ff d8  bne  0xa00da8b4
a00da958:  80 a3 20 02  cmp  %o4, 2
a00da95c:  82 93 60 00  orcc  %o5, 0, %g1
a00da960:  02 80 00 05  be  0xa00da974
a00da964:  80 a0 60 02  cmp  %g1, 2
a00da968:  94 03 3f ff  add  %o4, -1, %o2
a00da96c:  82 0a a0 ff  and  %o2, 0xff, %g1
a00da970:  80 a0 60 02  cmp  %g1, 2
a00da974:  18 80 00 15  bgu  0xa00da9c8
a00da978:  98 10 20 09  mov  9, %o4
a00da97c:  96 10 20 07  mov  7, %o3
a00da980:  d6 2a 60 19  stb  %o3, [ %o1 + 0x19 ]
a00da984:  10 80 00 16  b  0xa00da9dc
a00da988:  90 10 20 07  mov  7, %o0
a00da98c:  9a 10 20 06  mov  6, %o5
a00da990:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00da994:  da 2a e0 0d  stb  %o5, [ %o3 + 0xd ]	! 0xa802d00d
a00da998:  10 80 00 11  b  0xa00da9dc
a00da99c:  90 10 20 06  mov  6, %o0
a00da9a0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00da9a4:  92 10 20 05  mov  5, %o1
a00da9a8:  d2 2a 20 0d  stb  %o1, [ %o0 + 0xd ]
a00da9ac:  10 80 00 0c  b  0xa00da9dc
a00da9b0:  90 10 20 05  mov  5, %o0
a00da9b4:  90 12 a3 f4  or  %o2, 0x3f4, %o0
a00da9b8:  82 10 20 03  mov  3, %g1
a00da9bc:  c2 2a 20 19  stb  %g1, [ %o0 + 0x19 ]
a00da9c0:  10 80 00 07  b  0xa00da9dc
a00da9c4:  90 10 20 03  mov  3, %o0
a00da9c8:  d8 2a 60 19  stb  %o4, [ %o1 + 0x19 ]
a00da9cc:  10 80 00 04  b  0xa00da9dc
a00da9d0:  90 10 20 09  mov  9, %o0
a00da9d4:  d8 2a 60 19  stb  %o4, [ %o1 + 0x19 ]
a00da9d8:  90 10 20 0a  mov  0xa, %o0
a00da9dc:  81 c3 e0 08  retl
a00da9e0:  01 00 00 00  nop
