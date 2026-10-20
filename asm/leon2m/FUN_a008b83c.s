# leon2m FUN_a008b83c 0xa008b83c-0xa008c25c (180 bytes)
a008b83c:  9d e3 bf 98  save  %sp, -104, %sp
a008b840:  27 2a 00 ab  sethi  %hi(0xa802ac00), %l3
a008b844:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1	! 0xa802afbd
a008b848:  80 a0 60 1a  cmp  %g1, 0x1a
a008b84c:  38 80 00 29  bgu,a   0xa008b8f0
a008b850:  80 a0 60 13  cmp  %g1, 0x13
a008b854:  11 00 00 a8  sethi  %hi(0x2a000), %o0
a008b858:  83 28 60 02  sll  %g1, 2, %g1
a008b85c:  9a 12 23 5c  or  %o0, 0x35c, %o5
a008b860:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a008b864:  81 c3 00 00  jmp  %o4
a008b868:  01 00 00 00  nop
a008b86c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a008b870:  98 14 22 90  or  %l0, 0x290, %o4	! 0xa802d290
a008b874:  1f 00 00 15  sethi  %hi(0x5400), %o7
a008b878:  82 13 e1 aa  or  %o7, 0x1aa, %g1	! 0x55aa
a008b87c:  d6 13 21 f6  lduh  [ %o4 + 0x1f6 ], %o3
a008b880:  80 a2 c0 01  cmp  %o3, %g1
a008b884:  02 80 02 50  be  0xa008c1c4
a008b888:  23 3f ff ee  sethi  %hi(0xffffb800), %l1
a008b88c:  90 10 20 d6  mov  0xd6, %o0
a008b890:  92 10 20 00  clr  %o1
a008b894:  40 02 ec af  call  0xa0146b50
a008b898:  c2 33 21 f6  sth  %g1, [ %o4 + 0x1f6 ]
a008b89c:  92 14 22 90  or  %l0, 0x290, %o1
a008b8a0:  11 00 00 15  sethi  %hi(0x5400), %o0
a008b8a4:  e4 12 61 f6  lduh  [ %o1 + 0x1f6 ], %l2
a008b8a8:  9a 12 21 aa  or  %o0, 0x1aa, %o5
a008b8ac:  80 a4 80 0d  cmp  %l2, %o5
a008b8b0:  02 80 02 42  be  0xa008c1b8
a008b8b4:  03 00 04 00  sethi  %hi(0x100000), %g1
a008b8b8:  98 10 62 a0  or  %g1, 0x2a0, %o4	! 0x1002a0
a008b8bc:  90 10 20 00  clr  %o0
a008b8c0:  92 10 20 09  mov  9, %o1
a008b8c4:  94 10 20 0d  mov  0xd, %o2
a008b8c8:  96 10 20 03  mov  3, %o3
a008b8cc:  40 00 5e 36  call  0xa00a31a4
a008b8d0:  9a 10 20 00  clr  %o5
a008b8d4:  92 14 22 90  or  %l0, 0x290, %o1
a008b8d8:  94 10 20 00  clr  %o2
a008b8dc:  96 10 21 fc  mov  0x1fc, %o3
a008b8e0:  40 02 fd 7c  call  0xa014aed0
a008b8e4:  90 10 20 30  mov  0x30, %o0
a008b8e8:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008b8ec:  80 a0 60 13  cmp  %g1, 0x13
a008b8f0:  18 80 02 59  bgu  0xa008c254
a008b8f4:  9e 10 20 01  mov  1, %o7
a008b8f8:  17 00 00 07  sethi  %hi(0x1c00), %o3
a008b8fc:  9b 2b c0 01  sll  %o7, %g1, %o5
a008b900:  a6 12 e0 7e  or  %o3, 0x7e, %l3
a008b904:  80 8b 40 13  btst  %o5, %l3
a008b908:  12 80 00 0b  bne  0xa008b934
a008b90c:  80 8b 63 80  btst  0x380, %o5
a008b910:  12 80 00 10  bne  0xa008b950
a008b914:  11 00 02 00  sethi  %hi(0x80000), %o0
a008b918:  80 8b 40 08  btst  %o5, %o0
a008b91c:  02 80 02 4e  be  0xa008c254
a008b920:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a008b924:  e4 0b 60 8e  ldub  [ %o5 + 0x8e ], %l2	! 0xa802b08e
a008b928:  82 14 a0 02  or  %l2, 2, %g1
a008b92c:  10 80 02 4a  b  0xa008c254
a008b930:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a008b934:  40 01 37 8c  call  0xa00d9764
a008b938:  01 00 00 00  nop
a008b93c:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a008b940:  e2 0b 60 8e  ldub  [ %o5 + 0x8e ], %l1	! 0xa802b08e
a008b944:  82 14 60 04  or  %l1, 4, %g1
a008b948:  10 80 02 43  b  0xa008c254
a008b94c:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a008b950:  40 01 37 85  call  0xa00d9764
a008b954:  01 00 00 00  nop
a008b958:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a008b95c:  e0 0b 60 8e  ldub  [ %o5 + 0x8e ], %l0	! 0xa802b08e
a008b960:  82 14 20 06  or  %l0, 6, %g1
a008b964:  10 80 02 3c  b  0xa008c254
a008b968:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a008b96c:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a008b970:  98 14 a2 90  or  %l2, 0x290, %o4	! 0xa802d290
a008b974:  da 0b 20 13  ldub  [ %o4 + 0x13 ], %o5
a008b978:  9a 03 7f ff  add  %o5, -1, %o5
a008b97c:  82 0b 60 ff  and  %o5, 0xff, %g1
a008b980:  80 a0 60 ff  cmp  %g1, 0xff
a008b984:  12 80 01 a2  bne  0xa008c00c
a008b988:  a1 28 60 08  sll  %g1, 8, %l0
a008b98c:  10 bf ff d7  b  0xa008b8e8
a008b990:  c0 2b 20 13  clrb  [ %o4 + 0x13 ]
a008b994:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a008b998:  d4 0b 21 f6  ldub  [ %o4 + 0x1f6 ], %o2	! 0xa802e1f6
a008b99c:  82 02 bf ff  add  %o2, -1, %g1
a008b9a0:  92 08 60 ff  and  %g1, 0xff, %o1
a008b9a4:  80 a2 60 ff  cmp  %o1, 0xff
a008b9a8:  02 80 01 fb  be  0xa008c194
a008b9ac:  a0 13 21 f6  or  %o4, 0x1f6, %l0
a008b9b0:  c2 2b 21 f6  stb  %g1, [ %o4 + 0x1f6 ]
a008b9b4:  10 80 01 31  b  0xa008be78
a008b9b8:  a0 04 3f fa  add  %l0, -6, %l0
a008b9bc:  40 02 6b 3d  call  0xa01266b0
a008b9c0:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a008b9c4:  80 8a 20 ff  btst  0xff, %o0
a008b9c8:  12 80 01 ca  bne  0xa008c0f0
a008b9cc:  9a 02 3f ff  add  %o0, -1, %o5
a008b9d0:  a2 10 20 02  mov  2, %l1
a008b9d4:  e2 2c 23 bc  stb  %l1, [ %l0 + 0x3bc ]
a008b9d8:  90 10 20 02  mov  2, %o0
a008b9dc:  40 02 6a d8  call  0xa012653c
a008b9e0:  01 00 00 00  nop
a008b9e4:  d2 0c 23 bc  ldub  [ %l0 + 0x3bc ], %o1
a008b9e8:  7f ff fa e0  call  0xa008a568
a008b9ec:  90 10 20 15  mov  0x15, %o0
a008b9f0:  10 bf ff bf  b  0xa008b8ec
a008b9f4:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008b9f8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a008b9fc:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a008ba00:  d6 14 21 da  lduh  [ %l0 + 0x1da ], %o3
a008ba04:  a2 02 ff 81  add  %o3, -127, %l1
a008ba08:  9b 2c 60 10  sll  %l1, 0x10, %o5
a008ba0c:  9f 33 60 10  srl  %o5, 0x10, %o7
a008ba10:  80 a3 e3 81  cmp  %o7, 0x381
a008ba14:  08 80 01 b5  bleu  0xa008c0e8
a008ba18:  9a 02 ff ff  add  %o3, -1, %o5
a008ba1c:  a4 10 20 7e  mov  0x7e, %l2
a008ba20:  e4 34 21 da  sth  %l2, [ %l0 + 0x1da ]
a008ba24:  40 01 34 ac  call  0xa00d8cd4
a008ba28:  01 00 00 00  nop
a008ba2c:  d2 14 21 da  lduh  [ %l0 + 0x1da ], %o1
a008ba30:  7f ff fa ce  call  0xa008a568
a008ba34:  90 10 20 14  mov  0x14, %o0
a008ba38:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a008ba3c:  e0 0b 60 8e  ldub  [ %o5 + 0x8e ], %l0	! 0xa802b08e
a008ba40:  82 14 20 0a  or  %l0, 0xa, %g1
a008ba44:  10 bf ff a9  b  0xa008b8e8
a008ba48:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a008ba4c:  40 02 e8 2b  call  0xa0145af8
a008ba50:  90 10 20 10  mov  0x10, %o0
a008ba54:  a1 2a 20 10  sll  %o0, 0x10, %l0
a008ba58:  99 34 20 10  srl  %l0, 0x10, %o4
a008ba5c:  80 a3 20 01  cmp  %o4, 1
a008ba60:  02 80 01 c3  be  0xa008c16c
a008ba64:  90 10 20 10  mov  0x10, %o0
a008ba68:  92 10 20 01  mov  1, %o1
a008ba6c:  40 02 e8 7c  call  0xa0145c5c
a008ba70:  01 00 00 00  nop
a008ba74:  90 10 20 f7  mov  0xf7, %o0	! 0xf7
a008ba78:  40 02 ec 36  call  0xa0146b50
a008ba7c:  92 10 20 00  clr  %o1
a008ba80:  40 02 e8 1e  call  0xa0145af8
a008ba84:  90 10 20 10  mov  0x10, %o0
a008ba88:  97 2a 20 10  sll  %o0, 0x10, %o3
a008ba8c:  80 a2 e0 00  cmp  %o3, 0
a008ba90:  02 80 01 8d  be  0xa008c0c4
a008ba94:  21 00 04 00  sethi  %hi(0x100000), %l0
a008ba98:  11 00 04 00  sethi  %hi(0x100000), %o0
a008ba9c:  e4 0a 22 87  ldub  [ %o0 + 0x287 ], %l2	! 0x100287
a008baa0:  9a 04 a0 0b  add  %l2, 0xb, %o5
a008baa4:  a3 2b 60 10  sll  %o5, 0x10, %l1
a008baa8:  1f 00 04 00  sethi  %hi(0x100000), %o7
a008baac:  93 34 60 10  srl  %l1, 0x10, %o1
a008bab0:  98 13 e2 a8  or  %o7, 0x2a8, %o4
a008bab4:  90 10 20 00  clr  %o0
a008bab8:  10 80 00 31  b  0xa008bb7c
a008babc:  94 10 20 13  mov  0x13, %o2
a008bac0:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a008bac4:  c2 0c 23 ba  ldub  [ %l0 + 0x3ba ], %g1	! 0xa802afba
a008bac8:  9a 08 60 ff  and  %g1, 0xff, %o5
a008bacc:  80 a3 60 00  cmp  %o5, 0
a008bad0:  02 80 01 92  be  0xa008c118
a008bad4:  80 a3 60 01  cmp  %o5, 1
a008bad8:  02 80 01 db  be  0xa008c244
a008badc:  92 00 7f ff  add  %g1, -1, %o1
a008bae0:  90 10 20 01  mov  1, %o0
a008bae4:  40 02 6e b3  call  0xa01275b0
a008bae8:  d2 2c 23 ba  stb  %o1, [ %l0 + 0x3ba ]
a008baec:  d0 0c 23 ba  ldub  [ %l0 + 0x3ba ], %o0
a008baf0:  40 02 6f 0d  call  0xa0127724
a008baf4:  01 00 00 00  nop
a008baf8:  d2 0c 23 ba  ldub  [ %l0 + 0x3ba ], %o1
a008bafc:  7f ff fa 9b  call  0xa008a568
a008bb00:  90 10 20 16  mov  0x16, %o0
a008bb04:  10 bf ff 7a  b  0xa008b8ec
a008bb08:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008bb0c:  40 02 e7 fb  call  0xa0145af8
a008bb10:  90 10 20 02  mov  2, %o0
a008bb14:  83 2a 20 10  sll  %o0, 0x10, %g1
a008bb18:  95 30 60 10  srl  %g1, 0x10, %o2
a008bb1c:  80 a2 a0 01  cmp  %o2, 1
a008bb20:  02 80 01 91  be  0xa008c164
a008bb24:  90 10 20 02  mov  2, %o0
a008bb28:  92 10 20 01  mov  1, %o1
a008bb2c:  40 02 e8 4c  call  0xa0145c5c
a008bb30:  01 00 00 00  nop
a008bb34:  90 10 20 d3  mov  0xd3, %o0	! 0xd3
a008bb38:  40 02 ec 06  call  0xa0146b50
a008bb3c:  92 10 20 00  clr  %o1
a008bb40:  40 02 e7 ee  call  0xa0145af8
a008bb44:  90 10 20 02  mov  2, %o0
a008bb48:  99 2a 20 10  sll  %o0, 0x10, %o4
a008bb4c:  80 a3 20 00  cmp  %o4, 0
a008bb50:  22 80 01 56  be,a   0xa008c0a8
a008bb54:  03 00 04 00  sethi  %hi(0x100000), %g1
a008bb58:  1b 00 04 00  sethi  %hi(0x100000), %o5
a008bb5c:  e2 0b 62 8a  ldub  [ %o5 + 0x28a ], %l1	! 0x10028a
a008bb60:  9e 04 60 0b  add  %l1, 0xb, %o7
a008bb64:  97 2b e0 10  sll  %o7, 0x10, %o3
a008bb68:  21 00 04 00  sethi  %hi(0x100000), %l0
a008bb6c:  93 32 e0 10  srl  %o3, 0x10, %o1
a008bb70:  98 14 22 a8  or  %l0, 0x2a8, %o4
a008bb74:  90 10 20 00  clr  %o0
a008bb78:  94 10 20 14  mov  0x14, %o2
a008bb7c:  96 10 20 03  mov  3, %o3
a008bb80:  40 00 5d 89  call  0xa00a31a4
a008bb84:  9a 10 20 00  clr  %o5
a008bb88:  40 02 e5 f6  call  0xa0145360
a008bb8c:  90 10 20 01  mov  1, %o0
a008bb90:  10 bf ff 57  b  0xa008b8ec
a008bb94:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008bb98:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a008bb9c:  a0 14 62 90  or  %l1, 0x290, %l0	! 0xa802d290
a008bba0:  de 0c 21 d5  ldub  [ %l0 + 0x1d5 ], %o7
a008bba4:  96 1b e0 01  xor  %o7, 1, %o3
a008bba8:  d6 2c 21 d5  stb  %o3, [ %l0 + 0x1d5 ]
a008bbac:  90 10 20 ca  mov  0xca, %o0
a008bbb0:  40 02 eb e8  call  0xa0146b50
a008bbb4:  92 10 20 00  clr  %o1
a008bbb8:  90 10 20 00  clr  %o0
a008bbbc:  40 02 eb ec  call  0xa0146b6c
a008bbc0:  92 10 20 00  clr  %o1
a008bbc4:  d8 0c 21 d5  ldub  [ %l0 + 0x1d5 ], %o4
a008bbc8:  80 a3 20 01  cmp  %o4, 1
a008bbcc:  02 80 01 8b  be  0xa008c1f8
a008bbd0:  1f 00 04 00  sethi  %hi(0x100000), %o7
a008bbd4:  d6 0b e2 7b  ldub  [ %o7 + 0x27b ], %o3	! 0x10027b
a008bbd8:  a0 02 e0 08  add  %o3, 8, %l0
a008bbdc:  99 2c 20 10  sll  %l0, 0x10, %o4
a008bbe0:  93 33 20 10  srl  %o4, 0x10, %o1
a008bbe4:  03 00 04 00  sethi  %hi(0x100000), %g1
a008bbe8:  98 10 62 a0  or  %g1, 0x2a0, %o4	! 0x1002a0
a008bbec:  90 10 20 00  clr  %o0
a008bbf0:  94 10 20 0f  mov  0xf, %o2
a008bbf4:  96 10 20 03  mov  3, %o3
a008bbf8:  40 00 5d 6b  call  0xa00a31a4
a008bbfc:  9a 10 20 00  clr  %o5
a008bc00:  10 bf ff 3b  b  0xa008b8ec
a008bc04:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008bc08:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a008bc0c:  d8 0b 63 b9  ldub  [ %o5 + 0x3b9 ], %o4	! 0xa802afb9
a008bc10:  82 03 3f ff  add  %o4, -1, %g1
a008bc14:  92 08 60 ff  and  %g1, 0xff, %o1
a008bc18:  80 a2 60 08  cmp  %o1, 8
a008bc1c:  28 80 01 4c  bleu,a   0xa008c14c
a008bc20:  c2 2b 63 b9  stb  %g1, [ %o5 + 0x3b9 ]
a008bc24:  10 bf ff 31  b  0xa008b8e8
a008bc28:  c0 2b 63 b9  clrb  [ %o5 + 0x3b9 ]
a008bc2c:  23 2a 00 90  sethi  %hi(0xa8024000), %l1
a008bc30:  d2 0c 60 40  ldub  [ %l1 + 0x40 ], %o1	! 0xa8024040
a008bc34:  82 1a 60 01  xor  %o1, 1, %g1
a008bc38:  92 08 60 ff  and  %g1, 0xff, %o1
a008bc3c:  c2 2c 60 40  stb  %g1, [ %l1 + 0x40 ]
a008bc40:  40 03 08 ca  call  0xa014df68
a008bc44:  90 10 20 0d  mov  0xd, %o0
a008bc48:  90 10 20 0c  mov  0xc, %o0
a008bc4c:  40 03 08 c7  call  0xa014df68
a008bc50:  d2 0c 60 40  ldub  [ %l1 + 0x40 ], %o1
a008bc54:  90 10 20 f4  mov  0xf4, %o0
a008bc58:  40 02 eb be  call  0xa0146b50
a008bc5c:  92 10 20 00  clr  %o1
a008bc60:  90 10 20 00  clr  %o0
a008bc64:  40 02 eb c2  call  0xa0146b6c
a008bc68:  92 10 20 00  clr  %o1
a008bc6c:  d4 0c 60 40  ldub  [ %l1 + 0x40 ], %o2
a008bc70:  80 a2 a0 01  cmp  %o2, 1
a008bc74:  02 80 01 69  be  0xa008c218
a008bc78:  21 00 04 00  sethi  %hi(0x100000), %l0
a008bc7c:  03 00 04 00  sethi  %hi(0x100000), %g1
a008bc80:  a2 10 62 42  or  %g1, 0x242, %l1	! 0x100242
a008bc84:  d8 0c 60 4e  ldub  [ %l1 + 0x4e ], %o4
a008bc88:  92 03 20 08  add  %o4, 8, %o1
a008bc8c:  95 2a 60 10  sll  %o1, 0x10, %o2
a008bc90:  93 32 a0 10  srl  %o2, 0x10, %o1
a008bc94:  d4 0c 60 4f  ldub  [ %l1 + 0x4f ], %o2
a008bc98:  98 14 22 a0  or  %l0, 0x2a0, %o4
a008bc9c:  10 bf ff d6  b  0xa008bbf4
a008bca0:  90 10 20 00  clr  %o0
a008bca4:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a008bca8:  c2 0b 22 02  ldub  [ %o4 + 0x202 ], %g1	! 0xa802e202
a008bcac:  82 00 7f ff  add  %g1, -1, %g1
a008bcb0:  94 08 60 ff  and  %g1, 0xff, %o2
a008bcb4:  80 a2 a0 ff  cmp  %o2, 0xff
a008bcb8:  02 80 01 4c  be  0xa008c1e8
a008bcbc:  a0 13 22 02  or  %o4, 0x202, %l0
a008bcc0:  c2 2b 22 02  stb  %g1, [ %o4 + 0x202 ]
a008bcc4:  a0 04 3f ee  add  %l0, -18, %l0
a008bcc8:  d2 0c 20 12  ldub  [ %l0 + 0x12 ], %o1
a008bccc:  7f ff fa 27  call  0xa008a568
a008bcd0:  90 10 20 04  mov  4, %o0
a008bcd4:  d2 0c 20 13  ldub  [ %l0 + 0x13 ], %o1
a008bcd8:  7f ff fa 24  call  0xa008a568
a008bcdc:  90 10 20 05  mov  5, %o0
a008bce0:  d2 0c 20 14  ldub  [ %l0 + 0x14 ], %o1
a008bce4:  7f ff fa 21  call  0xa008a568
a008bce8:  90 10 20 06  mov  6, %o0
a008bcec:  10 bf ff 00  b  0xa008b8ec
a008bcf0:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008bcf4:  19 2a 00 ab  sethi  %hi(0xa802ac00), %o4
a008bcf8:  c2 0b 23 b8  ldub  [ %o4 + 0x3b8 ], %g1	! 0xa802afb8
a008bcfc:  82 00 7f ff  add  %g1, -1, %g1
a008bd00:  94 08 60 ff  and  %g1, 0xff, %o2
a008bd04:  80 a2 a0 07  cmp  %o2, 7
a008bd08:  08 80 01 0b  bleu  0xa008c134
a008bd0c:  01 00 00 00  nop
a008bd10:  10 bf fe f6  b  0xa008b8e8
a008bd14:  c0 2b 23 b8  clrb  [ %o4 + 0x3b8 ]
a008bd18:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a008bd1c:  de 0b 21 f7  ldub  [ %o4 + 0x1f7 ], %o7	! 0xa802e1f7
a008bd20:  82 03 ff ff  add  %o7, -1, %g1
a008bd24:  96 08 60 ff  and  %g1, 0xff, %o3
a008bd28:  80 a2 e0 ff  cmp  %o3, 0xff
a008bd2c:  02 80 01 1d  be  0xa008c1a0
a008bd30:  a0 13 21 f7  or  %o4, 0x1f7, %l0
a008bd34:  c2 2b 21 f7  stb  %g1, [ %o4 + 0x1f7 ]
a008bd38:  10 80 00 50  b  0xa008be78
a008bd3c:  a0 04 3f f9  add  %l0, -7, %l0
a008bd40:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a008bd44:  d2 0b 21 fb  ldub  [ %o4 + 0x1fb ], %o1	! 0xa802e1fb
a008bd48:  82 02 7f ff  add  %o1, -1, %g1
a008bd4c:  90 08 60 ff  and  %g1, 0xff, %o0
a008bd50:  80 a2 20 ff  cmp  %o0, 0xff
a008bd54:  02 80 01 22  be  0xa008c1dc
a008bd58:  a0 13 21 fb  or  %o4, 0x1fb, %l0
a008bd5c:  c2 2b 21 fb  stb  %g1, [ %o4 + 0x1fb ]
a008bd60:  10 80 00 82  b  0xa008bf68
a008bd64:  a0 04 3f f5  add  %l0, -11, %l0
a008bd68:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a008bd6c:  e4 0b 21 fa  ldub  [ %o4 + 0x1fa ], %l2	! 0xa802e1fa
a008bd70:  82 04 bf ff  add  %l2, -1, %g1
a008bd74:  9a 08 60 ff  and  %g1, 0xff, %o5
a008bd78:  80 a3 60 ff  cmp  %o5, 0xff
a008bd7c:  02 80 01 03  be  0xa008c188
a008bd80:  a0 13 21 fa  or  %o4, 0x1fa, %l0
a008bd84:  c2 2b 21 fa  stb  %g1, [ %o4 + 0x1fa ]
a008bd88:  10 80 00 78  b  0xa008bf68
a008bd8c:  a0 04 3f f6  add  %l0, -10, %l0
a008bd90:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a008bd94:  a0 14 22 90  or  %l0, 0x290, %l0	! 0xa802d290
a008bd98:  d2 04 21 d4  ld  [ %l0 + 0x1d4 ], %o1
a008bd9c:  97 32 60 07  srl  %o1, 7, %o3
a008bda0:  98 0a e0 01  and  %o3, 1, %o4
a008bda4:  82 1b 20 01  xor  %o4, 1, %g1
a008bda8:  95 28 60 07  sll  %g1, 7, %o2
a008bdac:  90 0a 7f 7f  and  %o1, -129, %o0
a008bdb0:  a4 12 00 0a  or  %o0, %o2, %l2
a008bdb4:  40 01 26 d9  call  0xa00d5918
a008bdb8:  e4 24 21 d4  st  %l2, [ %l0 + 0x1d4 ]
a008bdbc:  90 10 20 ea  mov  0xea, %o0
a008bdc0:  40 02 eb 64  call  0xa0146b50
a008bdc4:  92 10 20 00  clr  %o1
a008bdc8:  90 10 20 00  clr  %o0
a008bdcc:  40 02 eb 68  call  0xa0146b6c
a008bdd0:  92 10 20 00  clr  %o1
a008bdd4:  23 00 04 00  sethi  %hi(0x100000), %l1
a008bdd8:  9a 14 62 42  or  %l1, 0x242, %o5	! 0x100242
a008bddc:  e4 0b 60 4c  ldub  [ %o5 + 0x4c ], %l2
a008bde0:  e2 0b 60 4b  ldub  [ %o5 + 0x4b ], %l1
a008bde4:  1f 00 04 00  sethi  %hi(0x100000), %o7
a008bde8:  96 10 20 08  mov  8, %o3
a008bdec:  98 13 e3 30  or  %o7, 0x330, %o4
a008bdf0:  90 10 20 00  clr  %o0
a008bdf4:  92 0c 60 ff  and  %l1, 0xff, %o1
a008bdf8:  94 10 00 12  mov  %l2, %o2
a008bdfc:  40 00 5c ea  call  0xa00a31a4
a008be00:  9a 10 20 00  clr  %o5
a008be04:  d6 04 21 d4  ld  [ %l0 + 0x1d4 ], %o3
a008be08:  80 8a e0 80  btst  0x80, %o3
a008be0c:  02 80 00 bc  be  0xa008c0fc
a008be10:  82 0c 60 ff  and  %l1, 0xff, %g1
a008be14:  90 0c 60 ff  and  %l1, 0xff, %o0
a008be18:  a2 02 20 0c  add  %o0, 0xc, %l1
a008be1c:  9b 2c 60 10  sll  %l1, 0x10, %o5
a008be20:  1f 00 04 00  sethi  %hi(0x100000), %o7
a008be24:  93 33 60 10  srl  %o5, 0x10, %o1
a008be28:  94 10 00 12  mov  %l2, %o2
a008be2c:  98 13 e2 a8  or  %o7, 0x2a8, %o4
a008be30:  9a 10 20 00  clr  %o5
a008be34:  90 10 20 00  clr  %o0
a008be38:  40 00 5c db  call  0xa00a31a4
a008be3c:  96 10 20 03  mov  3, %o3
a008be40:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a008be44:  d8 0b 60 8e  ldub  [ %o5 + 0x8e ], %o4	! 0xa802b08e
a008be48:  82 13 20 02  or  %o4, 2, %g1
a008be4c:  10 bf fe a7  b  0xa008b8e8
a008be50:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a008be54:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a008be58:  e2 0b 21 f8  ldub  [ %o4 + 0x1f8 ], %l1	! 0xa802e1f8
a008be5c:  82 04 7f ff  add  %l1, -1, %g1
a008be60:  a0 08 60 ff  and  %g1, 0xff, %l0
a008be64:  80 a4 20 ff  cmp  %l0, 0xff
a008be68:  02 80 00 e2  be  0xa008c1f0
a008be6c:  a0 13 21 f8  or  %o4, 0x1f8, %l0
a008be70:  c2 2b 21 f8  stb  %g1, [ %o4 + 0x1f8 ]
a008be74:  a0 04 3f f8  add  %l0, -8, %l0
a008be78:  d2 0c 20 06  ldub  [ %l0 + 6 ], %o1
a008be7c:  7f ff f9 bb  call  0xa008a568
a008be80:  90 10 20 01  mov  1, %o0
a008be84:  d2 0c 20 07  ldub  [ %l0 + 7 ], %o1
a008be88:  7f ff f9 b8  call  0xa008a568
a008be8c:  90 10 20 02  mov  2, %o0
a008be90:  d2 0c 20 08  ldub  [ %l0 + 8 ], %o1
a008be94:  7f ff f9 b5  call  0xa008a568
a008be98:  90 10 20 03  mov  3, %o0
a008be9c:  10 bf fe 94  b  0xa008b8ec
a008bea0:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008bea4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a008bea8:  d2 0b 22 9a  ldub  [ %o4 + 0x29a ], %o1	! 0xa802d29a
a008beac:  82 02 7f ff  add  %o1, -1, %g1
a008beb0:  90 08 60 ff  and  %g1, 0xff, %o0
a008beb4:  80 a2 20 ff  cmp  %o0, 0xff
a008beb8:  02 80 00 c5  be  0xa008c1cc
a008bebc:  9a 13 22 9a  or  %o4, 0x29a, %o5
a008bec0:  c2 2b 22 9a  stb  %g1, [ %o4 + 0x29a ]
a008bec4:  d2 0b 40 00  ldub  [ %o5 ], %o1
a008bec8:  7f ff f9 a8  call  0xa008a568
a008becc:  90 10 20 0e  mov  0xe, %o0
a008bed0:  40 01 2f c4  call  0xa00d7de0
a008bed4:  01 00 00 00  nop
a008bed8:  10 bf fe 85  b  0xa008b8ec
a008bedc:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008bee0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a008bee4:  e4 0b 22 99  ldub  [ %o4 + 0x299 ], %l2	! 0xa802d299
a008bee8:  82 04 bf ff  add  %l2, -1, %g1
a008beec:  9a 08 60 ff  and  %g1, 0xff, %o5
a008bef0:  80 a3 60 ff  cmp  %o5, 0xff
a008bef4:  02 80 00 a0  be  0xa008c174
a008bef8:  9a 13 22 99  or  %o4, 0x299, %o5
a008befc:  c2 2b 22 99  stb  %g1, [ %o4 + 0x299 ]
a008bf00:  d2 0b 40 00  ldub  [ %o5 ], %o1
a008bf04:  7f ff f9 99  call  0xa008a568
a008bf08:  90 10 20 0d  mov  0xd, %o0
a008bf0c:  40 01 33 72  call  0xa00d8cd4
a008bf10:  01 00 00 00  nop
a008bf14:  10 bf fe 76  b  0xa008b8ec
a008bf18:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008bf1c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a008bf20:  e2 0b 22 04  ldub  [ %o4 + 0x204 ], %l1	! 0xa802e204
a008bf24:  82 04 7f ff  add  %l1, -1, %g1
a008bf28:  a0 08 60 ff  and  %g1, 0xff, %l0
a008bf2c:  80 a4 20 ff  cmp  %l0, 0xff
a008bf30:  02 80 00 9f  be  0xa008c1ac
a008bf34:  a0 13 22 04  or  %o4, 0x204, %l0
a008bf38:  c2 2b 22 04  stb  %g1, [ %o4 + 0x204 ]
a008bf3c:  10 bf ff 63  b  0xa008bcc8
a008bf40:  a0 04 3f ec  add  %l0, -20, %l0
a008bf44:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a008bf48:  e2 0b 21 f9  ldub  [ %o4 + 0x1f9 ], %l1	! 0xa802e1f9
a008bf4c:  82 04 7f ff  add  %l1, -1, %g1
a008bf50:  a0 08 60 ff  and  %g1, 0xff, %l0
a008bf54:  80 a4 20 ff  cmp  %l0, 0xff
a008bf58:  02 80 00 9f  be  0xa008c1d4
a008bf5c:  a0 13 21 f9  or  %o4, 0x1f9, %l0
a008bf60:  c2 2b 21 f9  stb  %g1, [ %o4 + 0x1f9 ]
a008bf64:  a0 04 3f f7  add  %l0, -9, %l0
a008bf68:  d2 0c 20 09  ldub  [ %l0 + 9 ], %o1
a008bf6c:  7f ff f9 7f  call  0xa008a568
a008bf70:  90 10 20 0a  mov  0xa, %o0
a008bf74:  d2 0c 20 0a  ldub  [ %l0 + 0xa ], %o1
a008bf78:  7f ff f9 7c  call  0xa008a568
a008bf7c:  90 10 20 0b  mov  0xb, %o0
a008bf80:  d2 0c 20 0b  ldub  [ %l0 + 0xb ], %o1
a008bf84:  7f ff f9 79  call  0xa008a568
a008bf88:  90 10 20 0c  mov  0xc, %o0
a008bf8c:  10 bf fe 58  b  0xa008b8ec
a008bf90:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008bf94:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a008bf98:  98 13 62 90  or  %o5, 0x290, %o4	! 0xa802d290
a008bf9c:  e2 0b 20 14  ldub  [ %o4 + 0x14 ], %l1
a008bfa0:  9a 04 7f ff  add  %l1, -1, %o5
a008bfa4:  82 0b 60 ff  and  %o5, 0xff, %g1
a008bfa8:  80 a0 60 ff  cmp  %g1, 0xff
a008bfac:  12 80 00 25  bne  0xa008c040
a008bfb0:  9f 28 60 08  sll  %g1, 8, %o7
a008bfb4:  10 bf fe 4d  b  0xa008b8e8
a008bfb8:  c0 2b 20 14  clrb  [ %o4 + 0x14 ]
a008bfbc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a008bfc0:  98 10 62 90  or  %g1, 0x290, %o4	! 0xa802d290
a008bfc4:  e4 0b 20 12  ldub  [ %o4 + 0x12 ], %l2
a008bfc8:  9a 04 bf ff  add  %l2, -1, %o5
a008bfcc:  82 0b 60 ff  and  %o5, 0xff, %g1
a008bfd0:  80 a0 60 ff  cmp  %g1, 0xff
a008bfd4:  12 80 00 28  bne  0xa008c074
a008bfd8:  a3 28 60 08  sll  %g1, 8, %l1
a008bfdc:  10 bf fe 43  b  0xa008b8e8
a008bfe0:  c0 2b 20 12  clrb  [ %o4 + 0x12 ]
a008bfe4:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a008bfe8:  de 0b 22 03  ldub  [ %o4 + 0x203 ], %o7	! 0xa802e203
a008bfec:  82 03 ff ff  add  %o7, -1, %g1
a008bff0:  96 08 60 ff  and  %g1, 0xff, %o3
a008bff4:  80 a2 e0 ff  cmp  %o3, 0xff
a008bff8:  02 80 00 61  be  0xa008c17c
a008bffc:  a0 13 22 03  or  %o4, 0x203, %l0
a008c000:  c2 2b 22 03  stb  %g1, [ %o4 + 0x203 ]
a008c004:  10 bf ff 31  b  0xa008bcc8
a008c008:  a0 04 3f ed  add  %l0, -19, %l0
a008c00c:  9e 24 00 01  sub  %l0, %g1, %o7
a008c010:  17 14 7a e1  sethi  %hi(0x51eb8400), %o3
a008c014:  92 03 e0 32  add  %o7, 0x32, %o1
a008c018:  94 12 e1 1f  or  %o3, 0x11f, %o2
a008c01c:  80 52 40 0a  umul  %o1, %o2, %g0
a008c020:  91 40 00 00  rd  %y, %o0
a008c024:  83 2a 20 0b  sll  %o0, 0xb, %g1
a008c028:  da 2b 20 13  stb  %o5, [ %o4 + 0x13 ]
a008c02c:  93 30 60 10  srl  %g1, 0x10, %o1
a008c030:  7f ff f9 4e  call  0xa008a568
a008c034:  90 10 20 08  mov  8, %o0
a008c038:  10 bf fe 2d  b  0xa008b8ec
a008c03c:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008c040:  96 23 c0 01  sub  %o7, %g1, %o3
a008c044:  15 14 7a e1  sethi  %hi(0x51eb8400), %o2
a008c048:  92 02 e0 32  add  %o3, 0x32, %o1
a008c04c:  82 12 a1 1f  or  %o2, 0x11f, %g1
a008c050:  80 52 40 01  umul  %o1, %g1, %g0
a008c054:  91 40 00 00  rd  %y, %o0
a008c058:  a5 2a 20 0b  sll  %o0, 0xb, %l2
a008c05c:  da 2b 20 14  stb  %o5, [ %o4 + 0x14 ]
a008c060:  93 34 a0 10  srl  %l2, 0x10, %o1
a008c064:  7f ff f9 41  call  0xa008a568
a008c068:  90 10 20 09  mov  9, %o0
a008c06c:  10 bf fe 20  b  0xa008b8ec
a008c070:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008c074:  a0 24 40 01  sub  %l1, %g1, %l0
a008c078:  1f 14 7a e1  sethi  %hi(0x51eb8400), %o7
a008c07c:  94 04 20 32  add  %l0, 0x32, %o2
a008c080:  96 13 e1 1f  or  %o7, 0x11f, %o3
a008c084:  80 52 80 0b  umul  %o2, %o3, %g0
a008c088:  93 40 00 00  rd  %y, %o1
a008c08c:  91 2a 60 0b  sll  %o1, 0xb, %o0
a008c090:  93 32 20 10  srl  %o0, 0x10, %o1
a008c094:  da 2b 20 12  stb  %o5, [ %o4 + 0x12 ]
a008c098:  7f ff f9 34  call  0xa008a568
a008c09c:  90 10 20 07  mov  7, %o0
a008c0a0:  10 bf fe 13  b  0xa008b8ec
a008c0a4:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008c0a8:  d4 08 62 8a  ldub  [ %g1 + 0x28a ], %o2
a008c0ac:  92 02 a0 0b  add  %o2, 0xb, %o1
a008c0b0:  91 2a 60 10  sll  %o1, 0x10, %o0
a008c0b4:  25 00 04 00  sethi  %hi(0x100000), %l2
a008c0b8:  93 32 20 10  srl  %o0, 0x10, %o1
a008c0bc:  10 bf fe ae  b  0xa008bb74
a008c0c0:  98 14 a2 a0  or  %l2, 0x2a0, %o4
a008c0c4:  d8 0c 22 87  ldub  [ %l0 + 0x287 ], %o4
a008c0c8:  82 03 20 0b  add  %o4, 0xb, %g1
a008c0cc:  15 00 04 00  sethi  %hi(0x100000), %o2
a008c0d0:  93 28 60 10  sll  %g1, 0x10, %o1
a008c0d4:  98 12 a2 a0  or  %o2, 0x2a0, %o4
a008c0d8:  93 32 60 10  srl  %o1, 0x10, %o1
a008c0dc:  90 10 20 00  clr  %o0
a008c0e0:  10 bf fe a7  b  0xa008bb7c
a008c0e4:  94 10 20 13  mov  0x13, %o2
a008c0e8:  10 bf fe 4f  b  0xa008ba24
a008c0ec:  da 34 21 da  sth  %o5, [ %l0 + 0x1da ]
a008c0f0:  da 2c 23 bc  stb  %o5, [ %l0 + 0x3bc ]
a008c0f4:  10 bf fe 3a  b  0xa008b9dc
a008c0f8:  90 0b 60 ff  and  %o5, 0xff, %o0
a008c0fc:  92 00 60 0c  add  %g1, 0xc, %o1
a008c100:  95 2a 60 10  sll  %o1, 0x10, %o2
a008c104:  93 32 a0 10  srl  %o2, 0x10, %o1
a008c108:  94 10 00 12  mov  %l2, %o2
a008c10c:  25 00 04 00  sethi  %hi(0x100000), %l2
a008c110:  10 bf ff 48  b  0xa008be30
a008c114:  98 14 a2 a0  or  %l2, 0x2a0, %o4	! 0x1002a0
a008c118:  a4 10 20 07  mov  7, %l2
a008c11c:  e4 2c 23 ba  stb  %l2, [ %l0 + 0x3ba ]
a008c120:  90 10 20 01  mov  1, %o0
a008c124:  40 02 6d 23  call  0xa01275b0
a008c128:  01 00 00 00  nop
a008c12c:  10 bf fe 71  b  0xa008baf0
a008c130:  90 10 20 00  clr  %o0	! 0x0
a008c134:  7f ff fc 93  call  0xa008b380
a008c138:  c2 2b 23 b8  stb  %g1, [ %o4 + 0x3b8 ]
a008c13c:  7f ff fd 29  call  0xa008b5e0
a008c140:  01 00 00 00  nop
a008c144:  10 bf fd ea  b  0xa008b8ec
a008c148:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008c14c:  7f ff f9 07  call  0xa008a568
a008c150:  90 10 20 10  mov  0x10, %o0
a008c154:  7f ff fd 23  call  0xa008b5e0
a008c158:  01 00 00 00  nop
a008c15c:  10 bf fd e4  b  0xa008b8ec
a008c160:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008c164:  10 bf fe 72  b  0xa008bb2c
a008c168:  92 10 20 00  clr  %o1
a008c16c:  10 bf fe 40  b  0xa008ba6c
a008c170:  92 10 20 00  clr  %o1
a008c174:  10 bf ff 63  b  0xa008bf00
a008c178:  c0 2b 22 99  clrb  [ %o4 + 0x299 ]
a008c17c:  c0 2b 22 03  clrb  [ %o4 + 0x203 ]
a008c180:  10 bf fe d2  b  0xa008bcc8
a008c184:  a0 04 3f ed  add  %l0, -19, %l0
a008c188:  c0 2b 21 fa  clrb  [ %o4 + 0x1fa ]
a008c18c:  10 bf ff 77  b  0xa008bf68
a008c190:  a0 04 3f f6  add  %l0, -10, %l0
a008c194:  c0 2b 21 f6  clrb  [ %o4 + 0x1f6 ]
a008c198:  10 bf ff 38  b  0xa008be78
a008c19c:  a0 04 3f fa  add  %l0, -6, %l0
a008c1a0:  c0 2b 21 f7  clrb  [ %o4 + 0x1f7 ]
a008c1a4:  10 bf ff 35  b  0xa008be78
a008c1a8:  a0 04 3f f9  add  %l0, -7, %l0
a008c1ac:  c0 2b 22 04  clrb  [ %o4 + 0x204 ]
a008c1b0:  10 bf fe c6  b  0xa008bcc8
a008c1b4:  a0 04 3f ec  add  %l0, -20, %l0
a008c1b8:  15 00 04 00  sethi  %hi(0x100000), %o2
a008c1bc:  10 bf fd c0  b  0xa008b8bc
a008c1c0:  98 12 a2 a8  or  %o2, 0x2a8, %o4	! 0x1002a8
a008c1c4:  10 bf fd b2  b  0xa008b88c
a008c1c8:  82 14 63 99  or  %l1, 0x399, %g1
a008c1cc:  10 bf ff 3e  b  0xa008bec4
a008c1d0:  c0 2b 22 9a  clrb  [ %o4 + 0x29a ]
a008c1d4:  10 bf ff 64  b  0xa008bf64
a008c1d8:  c0 2b 21 f9  clrb  [ %o4 + 0x1f9 ]
a008c1dc:  c0 2b 21 fb  clrb  [ %o4 + 0x1fb ]
a008c1e0:  10 bf ff 62  b  0xa008bf68
a008c1e4:  a0 04 3f f5  add  %l0, -11, %l0
a008c1e8:  10 bf fe b7  b  0xa008bcc4
a008c1ec:  c0 2b 22 02  clrb  [ %o4 + 0x202 ]
a008c1f0:  10 bf ff 21  b  0xa008be74
a008c1f4:  c0 2b 21 f8  clrb  [ %o4 + 0x1f8 ]
a008c1f8:  15 00 04 00  sethi  %hi(0x100000), %o2
a008c1fc:  d2 0a a2 7b  ldub  [ %o2 + 0x27b ], %o1	! 0x10027b
a008c200:  90 02 60 08  add  %o1, 8, %o0
a008c204:  a5 2a 20 10  sll  %o0, 0x10, %l2
a008c208:  1b 00 04 00  sethi  %hi(0x100000), %o5
a008c20c:  93 34 a0 10  srl  %l2, 0x10, %o1
a008c210:  10 bf fe 77  b  0xa008bbec
a008c214:  98 13 62 a8  or  %o5, 0x2a8, %o4
a008c218:  25 00 04 00  sethi  %hi(0x100000), %l2
a008c21c:  96 14 a2 42  or  %l2, 0x242, %o3	! 0x100242
a008c220:  d0 0a e0 4e  ldub  [ %o3 + 0x4e ], %o0
a008c224:  9a 02 20 08  add  %o0, 8, %o5
a008c228:  9f 2b 60 10  sll  %o5, 0x10, %o7
a008c22c:  19 00 04 00  sethi  %hi(0x100000), %o4
a008c230:  93 33 e0 10  srl  %o7, 0x10, %o1
a008c234:  d4 0a e0 4f  ldub  [ %o3 + 0x4f ], %o2
a008c238:  98 13 22 a8  or  %o4, 0x2a8, %o4
a008c23c:  10 bf fe 6e  b  0xa008bbf4
a008c240:  90 10 20 00  clr  %o0
a008c244:  90 00 7f ff  add  %g1, -1, %o0
a008c248:  d0 2c 23 ba  stb  %o0, [ %l0 + 0x3ba ]
a008c24c:  10 bf ff b6  b  0xa008c124
a008c250:  90 10 20 00  clr  %o0
a008c254:  81 c7 e0 08  ret
a008c258:  81 e8 00 00  restore
