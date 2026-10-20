# leon2s FUN_a00de8ac 0xa00de8ac-0xa00dea60 (436 bytes)
a00de8ac:  9d e3 bf 98  save  %sp, -104, %sp
a00de8b0:  25 2a 01 e5  sethi  %hi(0xa8079400), %l2
a00de8b4:  98 14 a1 38  or  %l2, 0x138, %o4	! 0xa8079538
a00de8b8:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a00de8bc:  c2 2b 20 18  stb  %g1, [ %o4 + 0x18 ]
a00de8c0:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a00de8c4:  83 30 60 08  srl  %g1, 8, %g1
a00de8c8:  c2 2b 20 05  stb  %g1, [ %o4 + 5 ]
a00de8cc:  c2 16 20 04  lduh  [ %i0 + 4 ], %g1
a00de8d0:  c2 2b 20 07  stb  %g1, [ %o4 + 7 ]
a00de8d4:  c2 0e 20 04  ldub  [ %i0 + 4 ], %g1
a00de8d8:  c2 2b 20 04  stb  %g1, [ %o4 + 4 ]
a00de8dc:  d0 06 20 08  ld  [ %i0 + 8 ], %o0
a00de8e0:  de 06 20 0c  ld  [ %i0 + 0xc ], %o7
a00de8e4:  e0 06 20 10  ld  [ %i0 + 0x10 ], %l0
a00de8e8:  e2 06 20 14  ld  [ %i0 + 0x14 ], %l1
a00de8ec:  c2 06 20 18  ld  [ %i0 + 0x18 ], %g1
a00de8f0:  c2 23 20 20  st  %g1, [ %o4 + 0x20 ]
a00de8f4:  c2 06 20 18  ld  [ %i0 + 0x18 ], %g1
a00de8f8:  9b 30 60 08  srl  %g1, 8, %o5
a00de8fc:  9b 2b 40 01  sll  %o5, %g1, %o5
a00de900:  83 2b 60 02  sll  %o5, 2, %g1
a00de904:  82 00 40 0d  add  %g1, %o5, %g1
a00de908:  82 00 40 01  add  %g1, %g1, %g1
a00de90c:  83 30 60 11  srl  %g1, 0x11, %g1
a00de910:  9a 00 40 01  add  %g1, %g1, %o5
a00de914:  9a 03 40 01  add  %o5, %g1, %o5
a00de918:  03 33 33 33  sethi  %hi(0xcccccc00), %g1
a00de91c:  82 10 60 cd  or  %g1, 0xcd, %g1	! 0xcccccccd
a00de920:  9b 2b 60 02  sll  %o5, 2, %o5
a00de924:  80 53 40 01  umul  %o5, %g1, %g0
a00de928:  9b 40 00 00  rd  %y, %o5
a00de92c:  a7 33 60 03  srl  %o5, 3, %l3
a00de930:  e6 24 a1 38  st  %l3, [ %l2 + 0x138 ]
a00de934:  83 32 20 10  srl  %o0, 0x10, %g1
a00de938:  9b 33 e0 10  srl  %o7, 0x10, %o5
a00de93c:  97 34 20 10  srl  %l0, 0x10, %o3
a00de940:  95 34 60 10  srl  %l1, 0x10, %o2
a00de944:  d2 4e 20 1b  ldsb  [ %i0 + 0x1b ], %o1
a00de948:  c2 33 20 0a  sth  %g1, [ %o4 + 0xa ]
a00de94c:  da 33 20 0e  sth  %o5, [ %o4 + 0xe ]
a00de950:  d6 33 20 12  sth  %o3, [ %o4 + 0x12 ]
a00de954:  d4 33 20 16  sth  %o2, [ %o4 + 0x16 ]
a00de958:  80 a2 60 00  cmp  %o1, 0
a00de95c:  d0 33 20 08  sth  %o0, [ %o4 + 8 ]
a00de960:  de 33 20 0c  sth  %o7, [ %o4 + 0xc ]
a00de964:  e0 33 20 10  sth  %l0, [ %o4 + 0x10 ]
a00de968:  16 80 00 04  bge  0xa00de978
a00de96c:  e2 33 20 14  sth  %l1, [ %o4 + 0x14 ]
a00de970:  82 04 c0 13  add  %l3, %l3, %g1
a00de974:  c2 24 a1 38  st  %g1, [ %l2 + 0x138 ]
a00de978:  c2 04 a1 38  ld  [ %l2 + 0x138 ], %g1
a00de97c:  80 a0 6a 9f  cmp  %g1, 0xa9f
a00de980:  08 80 00 08  bleu  0xa00de9a0
a00de984:  9a 58 60 64  smul  %g1, 0x64, %o5
a00de988:  03 14 7a e1  sethi  %hi(0x51eb8400), %g1
a00de98c:  82 10 61 1f  or  %g1, 0x11f, %g1	! 0x51eb851f
a00de990:  80 53 40 01  umul  %o5, %g1, %g0
a00de994:  83 40 00 00  rd  %y, %g1
a00de998:  10 80 00 07  b  0xa00de9b4
a00de99c:  83 30 60 07  srl  %g1, 7, %g1
a00de9a0:  03 30 30 30  sethi  %hi(0xc0c0c000), %g1
a00de9a4:  82 10 60 c1  or  %g1, 0xc1, %g1	! 0xc0c0c0c1
a00de9a8:  80 53 40 01  umul  %o5, %g1, %g0
a00de9ac:  83 40 00 00  rd  %y, %g1
a00de9b0:  83 30 60 08  srl  %g1, 8, %g1
a00de9b4:  83 28 60 10  sll  %g1, 0x10, %g1
a00de9b8:  83 30 60 10  srl  %g1, 0x10, %g1
a00de9bc:  80 a0 61 90  cmp  %g1, 0x190
a00de9c0:  18 80 00 04  bgu  0xa00de9d0
a00de9c4:  9a 14 a1 38  or  %l2, 0x138, %o5
a00de9c8:  10 80 00 03  b  0xa00de9d4
a00de9cc:  82 10 20 04  mov  4, %g1
a00de9d0:  82 10 20 08  mov  8, %g1
a00de9d4:  c2 2b 60 19  stb  %g1, [ %o5 + 0x19 ]
a00de9d8:  21 2a 01 e5  sethi  %hi(0xa8079400), %l0
a00de9dc:  c2 04 21 38  ld  [ %l0 + 0x138 ], %g1	! 0xa8079538
a00de9e0:  80 a0 6b b7  cmp  %g1, 0xbb7
a00de9e4:  08 80 00 04  bleu  0xa00de9f4
a00de9e8:  9a 14 21 38  or  %l0, 0x138, %o5
a00de9ec:  10 80 00 03  b  0xa00de9f8
a00de9f0:  82 10 20 03  mov  3, %g1
a00de9f4:  82 10 20 02  mov  2, %g1
a00de9f8:  a0 14 21 38  or  %l0, 0x138, %l0
a00de9fc:  23 27 c7 3b  sethi  %hi(0x9f1cec00), %l1
a00dea00:  c2 2b 60 1a  stb  %g1, [ %o5 + 0x1a ]
a00dea04:  d2 14 20 08  lduh  [ %l0 + 8 ], %o1
a00dea08:  d4 14 20 0a  lduh  [ %l0 + 0xa ], %o2
a00dea0c:  d6 14 20 0c  lduh  [ %l0 + 0xc ], %o3
a00dea10:  d8 14 20 0e  lduh  [ %l0 + 0xe ], %o4
a00dea14:  40 3a 91 8c  call  0xa0f83044
a00dea18:  90 14 62 a0  or  %l1, 0x2a0, %o0
a00dea1c:  d8 14 20 16  lduh  [ %l0 + 0x16 ], %o4
a00dea20:  d2 14 20 10  lduh  [ %l0 + 0x10 ], %o1
a00dea24:  d4 14 20 12  lduh  [ %l0 + 0x12 ], %o2
a00dea28:  d6 14 20 14  lduh  [ %l0 + 0x14 ], %o3
a00dea2c:  40 3a 91 86  call  0xa0f83044
a00dea30:  90 14 62 a0  or  %l1, 0x2a0, %o0
a00dea34:  7f ff f8 93  call  0xa00dcc80
a00dea38:  01 00 00 00  nop
a00dea3c:  7f ff f8 a7  call  0xa00dccd8
a00dea40:  01 00 00 00  nop
a00dea44:  7f ff fa 91  call  0xa00dd488
a00dea48:  01 00 00 00  nop
a00dea4c:  9a 10 20 01  mov  1, %o5	! 0x1
a00dea50:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dea54:  da 28 63 58  stb  %o5, [ %g1 + 0x358 ]	! 0xa8078b58
a00dea58:  81 c7 e0 08  ret
a00dea5c:  81 e8 00 00  restore
