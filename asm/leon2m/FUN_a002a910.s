# leon2m FUN_a002a910 0xa002a910-0xa002ab04 (500 bytes)
a002a910:  9d e3 bf 98  save  %sp, -104, %sp
a002a914:  33 2a 00 b6  sethi  %hi(0xa802d800), %i1
a002a918:  a0 16 61 92  or  %i1, 0x192, %l0	! 0xa802d992
a002a91c:  d0 0e 61 92  ldub  [ %i1 + 0x192 ], %o0
a002a920:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002a924:  40 00 08 83  call  0xa002cb30
a002a928:  94 10 20 00  clr  %o2
a002a92c:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002a930:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002a934:  40 00 07 ce  call  0xa002c86c
a002a938:  94 10 20 01  mov  1, %o2
a002a93c:  d0 0e 61 92  ldub  [ %i1 + 0x192 ], %o0
a002a940:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002a944:  40 00 07 ca  call  0xa002c86c
a002a948:  94 10 20 01  mov  1, %o2
a002a94c:  d0 0e 61 92  ldub  [ %i1 + 0x192 ], %o0
a002a950:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002a954:  40 00 08 77  call  0xa002cb30
a002a958:  94 10 20 01  mov  1, %o2
a002a95c:  a2 10 3f ff  mov  -1, %l1
a002a960:  10 80 00 07  b  0xa002a97c
a002a964:  a4 10 00 19  mov  %i1, %l2
a002a968:  80 a3 60 00  cmp  %o5, 0
a002a96c:  02 80 00 0d  be  0xa002a9a0
a002a970:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002a974:  01 00 00 00  nop
a002a978:  01 00 00 00  nop
a002a97c:  d0 0e 61 92  ldub  [ %i1 + 0x192 ], %o0
a002a980:  40 00 08 ee  call  0xa002cd38
a002a984:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002a988:  82 04 7f ff  add  %l1, -1, %g1
a002a98c:  9b 28 60 10  sll  %g1, 0x10, %o5
a002a990:  80 8a 20 ff  btst  0xff, %o0
a002a994:  02 bf ff f5  be  0xa002a968
a002a998:  a2 10 00 01  mov  %g1, %l1
a002a99c:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002a9a0:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002a9a4:  40 00 08 63  call  0xa002cb30
a002a9a8:  94 10 20 00  clr  %o2
a002a9ac:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002a9b0:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002a9b4:  40 00 08 5f  call  0xa002cb30
a002a9b8:  94 10 20 01  mov  1, %o2
a002a9bc:  d2 14 20 04  lduh  [ %l0 + 4 ], %o1
a002a9c0:  91 2a 60 11  sll  %o1, 0x11, %o0
a002a9c4:  25 2a 00 b6  sethi  %hi(0xa802d800), %l2
a002a9c8:  91 32 20 10  srl  %o0, 0x10, %o0
a002a9cc:  40 00 0a 1c  call  0xa002d23c
a002a9d0:  a2 14 a1 92  or  %l2, 0x192, %l1
a002a9d4:  b0 10 20 00  clr  %i0
a002a9d8:  a6 10 00 11  mov  %l1, %l3
a002a9dc:  d0 0c 60 02  ldub  [ %l1 + 2 ], %o0
a002a9e0:  40 00 08 d6  call  0xa002cd38
a002a9e4:  d2 0c 60 03  ldub  [ %l1 + 3 ], %o1
a002a9e8:  80 8a 20 ff  btst  0xff, %o0
a002a9ec:  32 80 00 36  bne,a   0xa002aac4
a002a9f0:  d0 0c 60 02  ldub  [ %l1 + 2 ], %o0
a002a9f4:  b4 0e 20 ff  and  %i0, 0xff, %i2
a002a9f8:  80 a6 a0 08  cmp  %i2, 8
a002a9fc:  38 80 00 32  bgu,a   0xa002aac4
a002aa00:  d0 0c 60 02  ldub  [ %l1 + 2 ], %o0
a002aa04:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002aa08:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002aa0c:  40 00 07 98  call  0xa002c86c
a002aa10:  94 10 20 00  clr  %o2
a002aa14:  d6 14 60 04  lduh  [ %l1 + 4 ], %o3
a002aa18:  95 2a e0 11  sll  %o3, 0x11, %o2
a002aa1c:  40 00 0a 08  call  0xa002d23c
a002aa20:  91 32 a0 10  srl  %o2, 0x10, %o0
a002aa24:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002aa28:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002aa2c:  40 00 07 90  call  0xa002c86c
a002aa30:  94 10 20 01  mov  1, %o2
a002aa34:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002aa38:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002aa3c:  40 00 08 3d  call  0xa002cb30
a002aa40:  94 10 20 01  mov  1, %o2
a002aa44:  a0 10 3f ff  mov  -1, %l0
a002aa48:  10 80 00 07  b  0xa002aa64
a002aa4c:  b4 10 00 13  mov  %l3, %i2
a002aa50:  80 a3 60 00  cmp  %o5, 0
a002aa54:  22 80 00 0d  be,a   0xa002aa88
a002aa58:  21 2a 00 b6  sethi  %hi(0xa802d800), %l0
a002aa5c:  01 00 00 00  nop
a002aa60:  01 00 00 00  nop
a002aa64:  d0 0e 61 92  ldub  [ %i1 + 0x192 ], %o0
a002aa68:  40 00 08 b4  call  0xa002cd38
a002aa6c:  d2 0e a0 01  ldub  [ %i2 + 1 ], %o1
a002aa70:  98 04 3f ff  add  %l0, -1, %o4
a002aa74:  9b 2b 20 10  sll  %o4, 0x10, %o5
a002aa78:  80 8a 20 ff  btst  0xff, %o0
a002aa7c:  02 bf ff f5  be  0xa002aa50
a002aa80:  a0 10 00 0c  mov  %o4, %l0
a002aa84:  21 2a 00 b6  sethi  %hi(0xa802d800), %l0
a002aa88:  d2 0e a0 01  ldub  [ %i2 + 1 ], %o1
a002aa8c:  94 10 20 00  clr  %o2
a002aa90:  40 00 08 28  call  0xa002cb30
a002aa94:  d0 0c 21 92  ldub  [ %l0 + 0x192 ], %o0
a002aa98:  de 16 a0 04  lduh  [ %i2 + 4 ], %o7
a002aa9c:  9b 2b e0 11  sll  %o7, 0x11, %o5
a002aaa0:  40 00 09 e7  call  0xa002d23c
a002aaa4:  91 33 60 10  srl  %o5, 0x10, %o0
a002aaa8:  d0 0c 60 02  ldub  [ %l1 + 2 ], %o0
a002aaac:  40 00 08 a3  call  0xa002cd38
a002aab0:  d2 0c 60 03  ldub  [ %l1 + 3 ], %o1
a002aab4:  80 8a 20 ff  btst  0xff, %o0
a002aab8:  02 bf ff cf  be  0xa002a9f4
a002aabc:  b0 06 20 01  inc  %i0
a002aac0:  d0 0c 60 02  ldub  [ %l1 + 2 ], %o0
a002aac4:  d2 0c 60 03  ldub  [ %l1 + 3 ], %o1
a002aac8:  40 00 08 1a  call  0xa002cb30
a002aacc:  94 10 20 00  clr  %o2
a002aad0:  d0 0c 60 02  ldub  [ %l1 + 2 ], %o0
a002aad4:  d2 0c 60 03  ldub  [ %l1 + 3 ], %o1
a002aad8:  40 00 07 65  call  0xa002c86c
a002aadc:  94 10 20 00  clr  %o2
a002aae0:  f0 14 60 04  lduh  [ %l1 + 4 ], %i0
a002aae4:  a7 2e 20 11  sll  %i0, 0x11, %l3
a002aae8:  40 00 09 d5  call  0xa002d23c
a002aaec:  91 34 e0 10  srl  %l3, 0x10, %o0
a002aaf0:  f0 0c a1 92  ldub  [ %l2 + 0x192 ], %i0
a002aaf4:  f2 0c 60 01  ldub  [ %l1 + 1 ], %i1
a002aaf8:  40 00 07 5d  call  0xa002c86c
a002aafc:  95 e8 20 00  restore  %g0, 0, %o2
a002ab00:  01 00 00 00  nop
