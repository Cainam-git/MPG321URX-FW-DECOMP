# leon2m FUN_a002b758 0xa002b758-0xa002bb28 (976 bytes)
a002b758:  9d e3 bf 98  save  %sp, -104, %sp
a002b75c:  e0 16 00 00  lduh  [ %i0 ], %l0
a002b760:  25 2a 00 b6  sethi  %hi(0xa802d800), %l2
a002b764:  e0 34 a1 92  sth  %l0, [ %l2 + 0x192 ]	! 0xa802d992
a002b768:  a2 14 a1 92  or  %l2, 0x192, %l1
a002b76c:  de 16 20 02  lduh  [ %i0 + 2 ], %o7
a002b770:  de 34 60 02  sth  %o7, [ %l1 + 2 ]
a002b774:  d6 16 20 04  lduh  [ %i0 + 4 ], %o3
a002b778:  d6 34 60 04  sth  %o3, [ %l1 + 4 ]
a002b77c:  d4 16 20 06  lduh  [ %i0 + 6 ], %o2
a002b780:  d4 34 60 06  sth  %o2, [ %l1 + 6 ]
a002b784:  d8 16 20 08  lduh  [ %i0 + 8 ], %o4
a002b788:  13 3f ff f0  sethi  %hi(0xffffc000), %o1
a002b78c:  90 0b 00 09  and  %o4, %o1, %o0
a002b790:  83 2a 20 10  sll  %o0, 0x10, %g1
a002b794:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a002b798:  80 a0 40 0d  cmp  %g1, %o5
a002b79c:  d8 34 60 08  sth  %o4, [ %l1 + 8 ]
a002b7a0:  a6 10 20 00  clr  %l3
a002b7a4:  02 80 00 05  be  0xa002b7b8
a002b7a8:  e0 0c 60 06  ldub  [ %l1 + 6 ], %l0
a002b7ac:  a1 2c e0 10  sll  %l3, 0x10, %l0
a002b7b0:  10 80 00 dc  b  0xa002bb20
a002b7b4:  b1 34 20 10  srl  %l0, 0x10, %i0
a002b7b8:  7f ff fc 56  call  0xa002a910
a002b7bc:  b0 0c 20 ff  and  %l0, 0xff, %i0
a002b7c0:  a0 10 20 00  clr  %l0
a002b7c4:  7f ff fc d0  call  0xa002ab04
a002b7c8:  90 10 00 18  mov  %i0, %o0
a002b7cc:  80 8a 20 ff  btst  0xff, %o0
a002b7d0:  22 80 00 0d  be,a   0xa002b804
a002b7d4:  b1 2c 20 10  sll  %l0, 0x10, %i0
a002b7d8:  d2 14 60 04  lduh  [ %l1 + 4 ], %o1
a002b7dc:  91 2a 60 11  sll  %o1, 0x11, %o0
a002b7e0:  40 00 06 97  call  0xa002d23c
a002b7e4:  91 32 20 10  srl  %o0, 0x10, %o0
a002b7e8:  98 04 20 01  add  %l0, 1, %o4
a002b7ec:  83 2b 20 10  sll  %o4, 0x10, %g1
a002b7f0:  9b 30 60 10  srl  %g1, 0x10, %o5
a002b7f4:  80 a3 60 09  cmp  %o5, 9
a002b7f8:  08 bf ff f3  bleu  0xa002b7c4
a002b7fc:  a0 10 00 0c  mov  %o4, %l0
a002b800:  b1 2c 20 10  sll  %l0, 0x10, %i0
a002b804:  a3 36 20 10  srl  %i0, 0x10, %l1
a002b808:  80 a4 60 0a  cmp  %l1, 0xa
a002b80c:  02 80 00 a3  be  0xa002ba98
a002b810:  b5 2e a0 10  sll  %i2, 0x10, %i2
a002b814:  83 36 a0 10  srl  %i2, 0x10, %g1
a002b818:  80 a0 60 00  cmp  %g1, 0
a002b81c:  a0 10 20 00  clr  %l0
a002b820:  02 80 00 13  be  0xa002b86c
a002b824:  a2 10 20 00  clr  %l1
a002b828:  b0 10 00 01  mov  %g1, %i0
a002b82c:  a3 2c 20 10  sll  %l0, 0x10, %l1
a002b830:  9f 34 60 10  srl  %l1, 0x10, %o7
a002b834:  d0 0b c0 19  ldub  [ %o7 + %i1 ], %o0
a002b838:  7f ff fc b3  call  0xa002ab04
a002b83c:  01 00 00 00  nop
a002b840:  96 04 20 01  add  %l0, 1, %o3
a002b844:  99 2a e0 10  sll  %o3, 0x10, %o4
a002b848:  94 0a 20 ff  and  %o0, 0xff, %o2
a002b84c:  9b 33 20 10  srl  %o4, 0x10, %o5
a002b850:  80 a2 a0 01  cmp  %o2, 1
a002b854:  02 80 00 06  be  0xa002b86c
a002b858:  a0 10 00 0b  mov  %o3, %l0
a002b85c:  80 a3 40 18  cmp  %o5, %i0
a002b860:  0a bf ff f4  bcs  0xa002b830
a002b864:  a3 2c 20 10  sll  %l0, 0x10, %l1
a002b868:  a2 10 00 0c  mov  %o4, %l1
a002b86c:  80 a6 80 11  cmp  %i2, %l1
a002b870:  28 80 00 31  bleu,a   0xa002b934
a002b874:  21 2a 00 b6  sethi  %hi(0xa802d800), %l0
a002b878:  a0 14 a1 92  or  %l2, 0x192, %l0
a002b87c:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002b880:  94 10 20 00  clr  %o2
a002b884:  40 00 03 fa  call  0xa002c86c
a002b888:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002b88c:  f8 14 20 04  lduh  [ %l0 + 4 ], %i4
a002b890:  b7 2f 20 11  sll  %i4, 0x11, %i3
a002b894:  40 00 06 6a  call  0xa002d23c
a002b898:  91 36 e0 10  srl  %i3, 0x10, %o0
a002b89c:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002b8a0:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002b8a4:  40 00 03 f2  call  0xa002c86c
a002b8a8:  94 10 20 01  mov  1, %o2
a002b8ac:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002b8b0:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002b8b4:  40 00 04 9f  call  0xa002cb30
a002b8b8:  94 10 20 01  mov  1, %o2
a002b8bc:  10 80 00 07  b  0xa002b8d8
a002b8c0:  a2 10 3f ff  mov  -1, %l1
a002b8c4:  80 a3 60 00  cmp  %o5, 0
a002b8c8:  02 80 00 0d  be  0xa002b8fc
a002b8cc:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a002b8d0:  01 00 00 00  nop
a002b8d4:  01 00 00 00  nop
a002b8d8:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002b8dc:  40 00 05 17  call  0xa002cd38
a002b8e0:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002b8e4:  98 04 7f ff  add  %l1, -1, %o4
a002b8e8:  9b 2b 20 10  sll  %o4, 0x10, %o5
a002b8ec:  80 8a 20 ff  btst  0xff, %o0
a002b8f0:  02 bf ff f5  be  0xa002b8c4
a002b8f4:  a2 10 00 0c  mov  %o4, %l1
a002b8f8:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a002b8fc:  d0 08 61 92  ldub  [ %g1 + 0x192 ], %o0	! 0xa802d992
a002b900:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002b904:  40 00 04 8b  call  0xa002cb30
a002b908:  94 10 20 00  clr  %o2
a002b90c:  da 14 20 04  lduh  [ %l0 + 4 ], %o5
a002b910:  a5 2b 60 11  sll  %o5, 0x11, %l2
a002b914:  40 00 06 4a  call  0xa002d23c
a002b918:  91 34 a0 10  srl  %l2, 0x10, %o0
a002b91c:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002b920:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002b924:  40 00 03 d2  call  0xa002c86c
a002b928:  94 10 20 01  mov  1, %o2
a002b92c:  10 80 00 7d  b  0xa002bb20
a002b930:  b0 10 20 00  clr  %i0
a002b934:  7f ff fb f7  call  0xa002a910
a002b938:  a2 14 21 92  or  %l0, 0x192, %l1
a002b93c:  a0 10 20 00  clr  %l0
a002b940:  d0 0c 60 06  ldub  [ %l1 + 6 ], %o0
a002b944:  7f ff fc 70  call  0xa002ab04
a002b948:  90 12 20 01  or  %o0, 1, %o0
a002b94c:  80 8a 20 ff  btst  0xff, %o0
a002b950:  22 80 00 0d  be,a   0xa002b984
a002b954:  a3 2f 20 10  sll  %i4, 0x10, %l1
a002b958:  d4 14 60 04  lduh  [ %l1 + 4 ], %o2
a002b95c:  b5 2a a0 11  sll  %o2, 0x11, %i2
a002b960:  40 00 06 37  call  0xa002d23c
a002b964:  91 36 a0 10  srl  %i2, 0x10, %o0
a002b968:  92 04 20 01  add  %l0, 1, %o1
a002b96c:  b3 2a 60 10  sll  %o1, 0x10, %i1
a002b970:  b1 36 60 10  srl  %i1, 0x10, %i0
a002b974:  80 a6 20 09  cmp  %i0, 9
a002b978:  08 bf ff f2  bleu  0xa002b940
a002b97c:  a0 10 00 09  mov  %o1, %l0
a002b980:  a3 2f 20 10  sll  %i4, 0x10, %l1
a002b984:  83 34 60 10  srl  %l1, 0x10, %g1
a002b988:  80 a0 60 00  cmp  %g1, 0
a002b98c:  02 80 00 14  be  0xa002b9dc
a002b990:  a2 10 20 00  clr  %l1
a002b994:  b8 10 00 01  mov  %g1, %i4
a002b998:  9f 2c 60 10  sll  %l1, 0x10, %o7
a002b99c:  a1 33 e0 10  srl  %o7, 0x10, %l0
a002b9a0:  96 00 7f ff  add  %g1, -1, %o3
a002b9a4:  80 a4 00 0b  cmp  %l0, %o3
a002b9a8:  02 80 00 03  be  0xa002b9b4
a002b9ac:  90 10 20 01  mov  1, %o0
a002b9b0:  90 10 20 00  clr  %o0
a002b9b4:  7f ff fd 26  call  0xa002ae4c
a002b9b8:  a6 04 e0 01  inc  %l3
a002b9bc:  98 04 60 01  add  %l1, 1, %o4
a002b9c0:  83 2b 20 10  sll  %o4, 0x10, %g1
a002b9c4:  9b 30 60 10  srl  %g1, 0x10, %o5
a002b9c8:  d0 2c 00 1b  stb  %o0, [ %l0 + %i3 ]
a002b9cc:  80 a3 40 1c  cmp  %o5, %i4
a002b9d0:  a2 10 00 0c  mov  %o4, %l1
a002b9d4:  0a bf ff f1  bcs  0xa002b998
a002b9d8:  82 10 00 1c  mov  %i4, %g1
a002b9dc:  a0 14 a1 92  or  %l2, 0x192, %l0
a002b9e0:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002b9e4:  94 10 20 00  clr  %o2
a002b9e8:  40 00 03 a1  call  0xa002c86c
a002b9ec:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002b9f0:  f8 14 20 04  lduh  [ %l0 + 4 ], %i4
a002b9f4:  b7 2f 20 11  sll  %i4, 0x11, %i3
a002b9f8:  40 00 06 11  call  0xa002d23c
a002b9fc:  91 36 e0 10  srl  %i3, 0x10, %o0
a002ba00:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002ba04:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002ba08:  40 00 03 99  call  0xa002c86c
a002ba0c:  94 10 20 01  mov  1, %o2
a002ba10:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002ba14:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002ba18:  40 00 04 46  call  0xa002cb30
a002ba1c:  94 10 20 01  mov  1, %o2
a002ba20:  10 80 00 07  b  0xa002ba3c
a002ba24:  a2 10 3f ff  mov  -1, %l1
a002ba28:  80 a3 60 00  cmp  %o5, 0
a002ba2c:  02 80 00 0d  be  0xa002ba60
a002ba30:  31 2a 00 b6  sethi  %hi(0xa802d800), %i0
a002ba34:  01 00 00 00  nop
a002ba38:  01 00 00 00  nop
a002ba3c:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002ba40:  40 00 04 be  call  0xa002cd38
a002ba44:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002ba48:  92 04 7f ff  add  %l1, -1, %o1
a002ba4c:  9b 2a 60 10  sll  %o1, 0x10, %o5
a002ba50:  80 8a 20 ff  btst  0xff, %o0
a002ba54:  02 bf ff f5  be  0xa002ba28
a002ba58:  a2 10 00 09  mov  %o1, %l1
a002ba5c:  31 2a 00 b6  sethi  %hi(0xa802d800), %i0
a002ba60:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002ba64:  d0 0e 21 92  ldub  [ %i0 + 0x192 ], %o0
a002ba68:  40 00 04 32  call  0xa002cb30
a002ba6c:  94 10 20 00  clr  %o2
a002ba70:  d0 14 20 04  lduh  [ %l0 + 4 ], %o0
a002ba74:  a5 2a 20 11  sll  %o0, 0x11, %l2
a002ba78:  40 00 05 f1  call  0xa002d23c
a002ba7c:  91 34 a0 10  srl  %l2, 0x10, %o0
a002ba80:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002ba84:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002ba88:  40 00 03 79  call  0xa002c86c
a002ba8c:  94 10 20 01  mov  1, %o2
a002ba90:  10 bf ff 48  b  0xa002b7b0
a002ba94:  a1 2c e0 10  sll  %l3, 0x10, %l0
a002ba98:  a0 14 a1 92  or  %l2, 0x192, %l0
a002ba9c:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002baa0:  94 10 20 00  clr  %o2
a002baa4:  40 00 03 72  call  0xa002c86c
a002baa8:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002baac:  f2 14 20 04  lduh  [ %l0 + 4 ], %i1
a002bab0:  a7 2e 60 11  sll  %i1, 0x11, %l3
a002bab4:  40 00 05 e2  call  0xa002d23c
a002bab8:  91 34 e0 10  srl  %l3, 0x10, %o0
a002babc:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002bac0:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002bac4:  40 00 03 6a  call  0xa002c86c
a002bac8:  94 10 20 01  mov  1, %o2
a002bacc:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002bad0:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002bad4:  40 00 04 17  call  0xa002cb30
a002bad8:  94 10 20 01  mov  1, %o2
a002badc:  10 80 00 07  b  0xa002baf8
a002bae0:  a2 10 3f ff  mov  -1, %l1
a002bae4:  80 a3 60 00  cmp  %o5, 0
a002bae8:  02 bf ff 85  be  0xa002b8fc
a002baec:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a002baf0:  01 00 00 00  nop
a002baf4:  01 00 00 00  nop
a002baf8:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002bafc:  40 00 04 8f  call  0xa002cd38
a002bb00:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002bb04:  b4 04 7f ff  add  %l1, -1, %i2
a002bb08:  9b 2e a0 10  sll  %i2, 0x10, %o5
a002bb0c:  80 8a 20 ff  btst  0xff, %o0
a002bb10:  02 bf ff f5  be  0xa002bae4
a002bb14:  a2 10 00 1a  mov  %i2, %l1
a002bb18:  10 bf ff 79  b  0xa002b8fc
a002bb1c:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a002bb20:  81 c7 e0 08  ret
a002bb24:  81 e8 00 00  restore
