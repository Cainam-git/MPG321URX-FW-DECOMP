# leon2m FUN_a012a774 0xa012a774-0xa012ad64 (1520 bytes)
a012a774:  9d e3 bf 78  save  %sp, -136, %sp
a012a778:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012a77c:  80 a6 20 00  cmp  %i0, 0
a012a780:  02 80 00 17  be  0xa012a7dc
a012a784:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a012a788:  11 2a 00 b2  sethi  %hi(0xa802c800), %o0
a012a78c:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a012a790:  1b 00 06 93  sethi  %hi(0x1a4c00), %o5
a012a794:  c0 22 62 08  clr  [ %o1 + 0x208 ]
a012a798:  9a 13 62 a8  or  %o5, 0x2a8, %o5
a012a79c:  c0 32 22 12  clrh  [ %o0 + 0x212 ]
a012a7a0:  96 10 20 00  clr  %o3
a012a7a4:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a012a7a8:  92 10 62 e0  or  %g1, 0x2e0, %o1	! 0xa802cae0
a012a7ac:  98 10 20 00  clr  %o4
a012a7b0:  94 10 20 00  clr  %o2
a012a7b4:  de 0b 00 0d  ldub  [ %o4 + %o5 ], %o7
a012a7b8:  de 2a 40 0c  stb  %o7, [ %o1 + %o4 ]
a012a7bc:  96 02 e0 01  inc  %o3
a012a7c0:  82 03 c0 0a  add  %o7, %o2, %g1
a012a7c4:  98 0a e0 ff  and  %o3, 0xff, %o4
a012a7c8:  80 a3 20 0f  cmp  %o4, 0xf
a012a7cc:  08 bf ff fa  bleu  0xa012a7b4
a012a7d0:  94 10 00 01  mov  %g1, %o2
a012a7d4:  c2 32 22 12  sth  %g1, [ %o0 + 0x212 ]
a012a7d8:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a012a7dc:  94 14 23 d0  or  %l0, 0x3d0, %o2	! 0xa802e3d0
a012a7e0:  d0 0a a0 07  ldub  [ %o2 + 7 ], %o0
a012a7e4:  80 a2 20 01  cmp  %o0, 1
a012a7e8:  12 80 01 5d  bne  0xa012ad5c
a012a7ec:  01 00 00 00  nop
a012a7f0:  7f ff 31 41  call  0xa00f6cf4
a012a7f4:  27 2a 00 b2  sethi  %hi(0xa802c800), %l3
a012a7f8:  a8 10 00 08  mov  %o0, %l4
a012a7fc:  90 10 00 18  mov  %i0, %o0
a012a800:  7f ff 33 b7  call  0xa00f76dc
a012a804:  92 14 e2 5c  or  %l3, 0x25c, %o1
a012a808:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a012a80c:  c0 24 a2 0c  clr  [ %l2 + 0x20c ]	! 0xa802ca0c
a012a810:  98 10 20 00  clr  %o4
a012a814:  82 10 20 00  clr  %g1
a012a818:  94 14 e2 5c  or  %l3, 0x25c, %o2
a012a81c:  96 10 20 00  clr  %o3
a012a820:  83 28 60 02  sll  %g1, 2, %g1
a012a824:  e2 02 80 01  ld  [ %o2 + %g1 ], %l1
a012a828:  98 03 20 01  inc  %o4
a012a82c:  82 0b 20 ff  and  %o4, 0xff, %g1
a012a830:  80 a0 60 0f  cmp  %g1, 0xf
a012a834:  08 bf ff fb  bleu  0xa012a820
a012a838:  96 04 40 0b  add  %l1, %o3, %o3
a012a83c:  80 a6 20 00  cmp  %i0, 0
a012a840:  02 80 00 37  be  0xa012a91c
a012a844:  d6 24 a2 0c  st  %o3, [ %l2 + 0x20c ]
a012a848:  c0 2f bf f1  clrb  [ %fp + -15 ]
a012a84c:  c0 2f bf f0  clrb  [ %fp + -16 ]
a012a850:  94 10 20 10  mov  0x10, %o2
a012a854:  e2 17 bf f0  lduh  [ %fp + -16 ], %l1
a012a858:  e2 37 bf e8  sth  %l1, [ %fp + -24 ]
a012a85c:  90 07 bf e8  add  %fp, -24, %o0
a012a860:  d4 2f bf ea  stb  %o2, [ %fp + -22 ]
a012a864:  7f ff 34 0c  call  0xa00f7894
a012a868:  d4 2f bf f2  stb  %o2, [ %fp + -14 ]
a012a86c:  90 14 23 d0  or  %l0, 0x3d0, %o0
a012a870:  de 0a 20 08  ldub  [ %o0 + 8 ], %o7
a012a874:  93 2b e0 0a  sll  %o7, 0xa, %o1
a012a878:  9a 22 40 0f  sub  %o1, %o7, %o5
a012a87c:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a012a880:  31 14 7a e1  sethi  %hi(0x51eb8400), %i0
a012a884:  a0 10 23 ff  mov  0x3ff, %l0
a012a888:  a4 03 60 32  add  %o5, 0x32, %l2
a012a88c:  98 14 60 1c  or  %l1, 0x1c, %o4
a012a890:  a6 16 21 1f  or  %i0, 0x11f, %l3
a012a894:  80 54 80 13  umul  %l2, %l3, %g0
a012a898:  97 40 00 00  rd  %y, %o3
a012a89c:  d8 03 20 34  ld  [ %o4 + 0x34 ], %o4
a012a8a0:  e0 37 bf e6  sth  %l0, [ %fp + -26 ]
a012a8a4:  80 a3 20 00  cmp  %o4, 0
a012a8a8:  12 80 00 9e  bne  0xa012ab20
a012a8ac:  a1 32 e0 05  srl  %o3, 5, %l0
a012a8b0:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a012a8b4:  e0 33 22 f2  sth  %l0, [ %o4 + 0x2f2 ]	! 0xa802caf2
a012a8b8:  e6 13 22 f2  lduh  [ %o4 + 0x2f2 ], %l3
a012a8bc:  93 2c e0 03  sll  %l3, 3, %o1
a012a8c0:  b0 22 40 13  sub  %o1, %l3, %i0
a012a8c4:  83 2e 20 07  sll  %i0, 7, %g1
a012a8c8:  25 00 10 04  sethi  %hi(0x401000), %l2
a012a8cc:  a0 00 40 13  add  %g1, %l3, %l0
a012a8d0:  98 14 a0 05  or  %l2, 5, %o4
a012a8d4:  80 54 00 0c  umul  %l0, %o4, %g0
a012a8d8:  91 40 00 00  rd  %y, %o0
a012a8dc:  96 24 00 08  sub  %l0, %o0, %o3
a012a8e0:  95 32 e0 01  srl  %o3, 1, %o2
a012a8e4:  9e 02 00 0a  add  %o0, %o2, %o7
a012a8e8:  9b 33 e0 09  srl  %o7, 9, %o5
a012a8ec:  92 14 60 1c  or  %l1, 0x1c, %o1
a012a8f0:  b0 03 60 7e  add  %o5, 0x7e, %i0
a012a8f4:  c2 02 60 34  ld  [ %o1 + 0x34 ], %g1
a012a8f8:  80 a0 60 00  cmp  %g1, 0
a012a8fc:  12 80 00 72  bne  0xa012aac4
a012a900:  f0 37 bf e4  sth  %i0, [ %fp + -28 ]
a012a904:  d0 17 bf e4  lduh  [ %fp + -28 ], %o0
a012a908:  40 00 63 bf  call  0xa0143804
a012a90c:  01 00 00 00  nop
a012a910:  7f ff 2e ab  call  0xa00f63bc
a012a914:  90 0d 20 ff  and  %l4, 0xff, %o0
a012a918:  30 80 01 11  b,a   0xa012ad5c
a012a91c:  40 00 67 f8  call  0xa01448fc
a012a920:  90 10 20 00  clr  %o0
a012a924:  a0 10 00 08  mov  %o0, %l0
a012a928:  7f ff 2e 61  call  0xa00f62ac
a012a92c:  90 10 20 00  clr  %o0
a012a930:  80 8a 20 ff  btst  0xff, %o0
a012a934:  12 80 00 8a  bne  0xa012ab5c
a012a938:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a012a93c:  7f ff bc 0c  call  0xa011996c
a012a940:  90 10 20 00  clr  %o0
a012a944:  80 8a 20 ff  btst  0xff, %o0
a012a948:  02 80 00 54  be  0xa012aa98
a012a94c:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a012a950:  c0 2c 62 18  clrb  [ %l1 + 0x218 ]
a012a954:  da 0c 62 18  ldub  [ %l1 + 0x218 ], %o5
a012a958:  80 a3 60 00  cmp  %o5, 0
a012a95c:  32 80 00 62  bne,a   0xa012aae4
a012a960:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a012a964:  67 fd 8b 09  call  0x4008d588
a012a968:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a012a96c:  de 0c 62 14  ldub  [ %l1 + 0x214 ], %o7	! 0xa802ca14
a012a970:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a012a974:  80 a3 e0 00  cmp  %o7, 0
a012a978:  12 80 00 9f  bne  0xa012abf4
a012a97c:  d0 32 a2 16  sth  %o0, [ %o2 + 0x216 ]
a012a980:  d4 04 a2 0c  ld  [ %l2 + 0x20c ], %o2
a012a984:  80 a2 a0 00  cmp  %o2, 0
a012a988:  02 bf ff e2  be  0xa012a910
a012a98c:  d8 04 e2 5c  ld  [ %l3 + 0x25c ], %o4
a012a990:  90 22 80 0c  sub  %o2, %o4, %o0
a012a994:  96 10 00 0a  mov  %o2, %o3
a012a998:  92 52 23 ff  umul  %o0, 0x3ff, %o1
a012a99c:  91 40 00 00  rd  %y, %o0
a012a9a0:  40 00 aa 1a  call  0xa0155208
a012a9a4:  94 10 20 00  clr  %o2
a012a9a8:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a012a9ac:  a7 2a 60 10  sll  %o1, 0x10, %l3
a012a9b0:  83 34 e0 10  srl  %l3, 0x10, %g1
a012a9b4:  e4 12 e2 f0  lduh  [ %o3 + 0x2f0 ], %l2
a012a9b8:  80 a0 40 12  cmp  %g1, %l2
a012a9bc:  02 80 00 05  be  0xa012a9d0
a012a9c0:  80 a0 60 00  cmp  %g1, 0
a012a9c4:  12 80 00 cc  bne  0xa012acf4
a012a9c8:  80 a0 63 ff  cmp  %g1, 0x3ff
a012a9cc:  c0 32 e2 f0  clrh  [ %o3 + 0x2f0 ]
a012a9d0:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a012a9d4:  da 12 62 f2  lduh  [ %o1 + 0x2f2 ], %o5	! 0xa802caf2
a012a9d8:  d8 12 e2 f0  lduh  [ %o3 + 0x2f0 ], %o4
a012a9dc:  a2 23 40 0c  sub  %o5, %o4, %l1
a012a9e0:  9e 04 60 05  add  %l1, 5, %o7
a012a9e4:  80 a3 e0 0a  cmp  %o7, 0xa
a012a9e8:  9e 10 00 09  mov  %o1, %o7
a012a9ec:  90 10 00 0d  mov  %o5, %o0
a012a9f0:  a0 10 00 0c  mov  %o4, %l0
a012a9f4:  18 80 00 06  bgu  0xa012aa0c
a012a9f8:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a012a9fc:  c2 0a a2 19  ldub  [ %o2 + 0x219 ], %g1	! 0xa802ca19
a012aa00:  80 a0 60 00  cmp  %g1, 0
a012aa04:  02 bf ff c3  be  0xa012a910
a012aa08:  01 00 00 00  nop
a012aa0c:  a4 10 20 01  mov  1, %l2	! 0x1
a012aa10:  80 a3 40 0c  cmp  %o5, %o4
a012aa14:  02 80 00 c8  be  0xa012ad34
a012aa18:  e4 2a a2 19  stb  %l2, [ %o2 + 0x219 ]
a012aa1c:  80 a3 40 0c  cmp  %o5, %o4
a012aa20:  1a 80 00 ba  bcc  0xa012ad08
a012aa24:  80 a3 60 04  cmp  %o5, 4
a012aa28:  9a 02 20 04  add  %o0, 4, %o5
a012aa2c:  91 2b 60 10  sll  %o5, 0x10, %o0
a012aa30:  95 32 20 10  srl  %o0, 0x10, %o2
a012aa34:  80 a2 80 0c  cmp  %o2, %o4
a012aa38:  28 80 00 03  bleu,a   0xa012aa44
a012aa3c:  da 33 e2 f2  sth  %o5, [ %o7 + 0x2f2 ]
a012aa40:  e0 33 e2 f2  sth  %l0, [ %o7 + 0x2f2 ]
a012aa44:  e0 12 62 f2  lduh  [ %o1 + 0x2f2 ], %l0
a012aa48:  93 2c 20 03  sll  %l0, 3, %o1
a012aa4c:  96 22 40 10  sub  %o1, %l0, %o3
a012aa50:  9b 2a e0 07  sll  %o3, 7, %o5
a012aa54:  11 00 10 04  sethi  %hi(0x401000), %o0
a012aa58:  a4 03 40 10  add  %o5, %l0, %l2
a012aa5c:  94 12 20 05  or  %o0, 5, %o2
a012aa60:  80 54 80 0a  umul  %l2, %o2, %g0
a012aa64:  9f 40 00 00  rd  %y, %o7
a012aa68:  82 24 80 0f  sub  %l2, %o7, %g1
a012aa6c:  a3 30 60 01  srl  %g1, 1, %l1
a012aa70:  b0 03 c0 11  add  %o7, %l1, %i0
a012aa74:  99 36 20 09  srl  %i0, 9, %o4
a012aa78:  27 2a 00 b3  sethi  %hi(0xa802cc00), %l3
a012aa7c:  92 03 20 7e  add  %o4, 0x7e, %o1
a012aa80:  c2 04 e0 50  ld  [ %l3 + 0x50 ], %g1
a012aa84:  80 a0 60 00  cmp  %g1, 0
a012aa88:  12 80 00 13  bne  0xa012aad4
a012aa8c:  d2 37 bf de  sth  %o1, [ %fp + -34 ]
a012aa90:  10 bf ff 9e  b  0xa012a908
a012aa94:  d0 17 bf de  lduh  [ %fp + -34 ], %o0
a012aa98:  f0 0a 61 a7  ldub  [ %o1 + 0x1a7 ], %i0
a012aa9c:  80 a0 00 18  cmp  %g0, %i0
a012aaa0:  98 40 20 00  addx  %g0, 0, %o4
a012aaa4:  82 1e 20 02  xor  %i0, 2, %g1
a012aaa8:  80 a0 00 01  cmp  %g0, %g1
a012aaac:  96 40 20 00  addx  %g0, 0, %o3
a012aab0:  80 8b 00 0b  btst  %o4, %o3
a012aab4:  02 bf ff a9  be  0xa012a958
a012aab8:  da 0c 62 18  ldub  [ %l1 + 0x218 ], %o5
a012aabc:  10 bf ff a6  b  0xa012a954
a012aac0:  c0 2c 62 18  clrb  [ %l1 + 0x218 ]
a012aac4:  9f c0 40 00  call  %g1
a012aac8:  90 07 bf e4  add  %fp, -28, %o0
a012aacc:  10 bf ff 8f  b  0xa012a908
a012aad0:  d0 17 bf e4  lduh  [ %fp + -28 ], %o0
a012aad4:  9f c0 40 00  call  %g1
a012aad8:  90 07 bf de  add  %fp, -34, %o0
a012aadc:  10 bf ff 8b  b  0xa012a908
a012aae0:  d0 17 bf de  lduh  [ %fp + -34 ], %o0
a012aae4:  67 fd 8a ac  call  0x4008d594
a012aae8:  d0 14 22 16  lduh  [ %l0 + 0x216 ], %o0
a012aaec:  91 2a 20 10  sll  %o0, 0x10, %o0
a012aaf0:  1b 00 00 09  sethi  %hi(0x2400), %o5
a012aaf4:  a2 13 63 10  or  %o5, 0x310, %l1	! 0x2710
a012aaf8:  95 32 20 10  srl  %o0, 0x10, %o2
a012aafc:  80 a2 80 11  cmp  %o2, %l1
a012ab00:  18 80 00 5f  bgu  0xa012ac7c
a012ab04:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a012ab08:  c2 0c 62 14  ldub  [ %l1 + 0x214 ], %g1	! 0xa802ca14
a012ab0c:  80 a0 60 00  cmp  %g1, 0
a012ab10:  12 bf ff 80  bne  0xa012a910
a012ab14:  d4 04 a2 0c  ld  [ %l2 + 0x20c ], %o2
a012ab18:  10 bf ff 9c  b  0xa012a988
a012ab1c:  80 a2 a0 00  cmp  %o2, 0
a012ab20:  a7 2c 20 10  sll  %l0, 0x10, %l3
a012ab24:  9f c3 00 00  call  %o4
a012ab28:  90 07 bf e6  add  %fp, -26, %o0
a012ab2c:  a5 34 e0 10  srl  %l3, 0x10, %l2
a012ab30:  99 2c a0 0a  sll  %l2, 0xa, %o4
a012ab34:  a0 23 00 12  sub  %o4, %l2, %l0
a012ab38:  c2 17 bf e6  lduh  [ %fp + -26 ], %g1
a012ab3c:  81 80 00 00  mov  %g0, %y
a012ab40:  01 00 00 00  nop
a012ab44:  01 00 00 00  nop
a012ab48:  01 00 00 00  nop
a012ab4c:  96 74 00 01  udiv  %l0, %g1, %o3
a012ab50:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a012ab54:  10 bf ff 59  b  0xa012a8b8
a012ab58:  d6 33 22 f2  sth  %o3, [ %o4 + 0x2f2 ]	! 0xa802caf2
a012ab5c:  7f ff 2d f9  call  0xa00f6340
a012ab60:  90 10 20 00  clr  %o0
a012ab64:  a2 10 00 08  mov  %o0, %l1
a012ab68:  7f ff 2d fd  call  0xa00f635c
a012ab6c:  90 10 20 00  clr  %o0
a012ab70:  b0 10 00 08  mov  %o0, %i0
a012ab74:  7f ff 2e 01  call  0xa00f6378
a012ab78:  90 10 20 00  clr  %o0
a012ab7c:  80 8c 20 01  btst  1, %l0
a012ab80:  12 80 00 0c  bne  0xa012abb0
a012ab84:  96 10 00 08  mov  %o0, %o3
a012ab88:  90 0e 20 ff  and  %i0, 0xff, %o0
a012ab8c:  80 a2 20 10  cmp  %o0, 0x10
a012ab90:  18 80 00 04  bgu  0xa012aba0
a012ab94:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a012ab98:  9a 10 20 01  mov  1, %o5
a012ab9c:  da 2c 62 18  stb  %o5, [ %l1 + 0x218 ]
a012aba0:  80 a2 20 13  cmp  %o0, 0x13
a012aba4:  38 bf ff 66  bgu,a   0xa012a93c
a012aba8:  c0 2c 62 18  clrb  [ %l1 + 0x218 ]
a012abac:  30 bf ff 64  b,a   0xa012a93c
a012abb0:  90 0c 60 ff  and  %l1, 0xff, %o0
a012abb4:  80 a2 20 04  cmp  %o0, 4
a012abb8:  a2 60 20 00  subx  %g0, 0, %l1
a012abbc:  98 0e 20 ff  and  %i0, 0xff, %o4
a012abc0:  80 a3 20 04  cmp  %o4, 4
a012abc4:  9e 40 20 00  addx  %g0, 0, %o7
a012abc8:  80 8b c0 11  btst  %o7, %l1
a012abcc:  02 80 00 3a  be  0xa012acb4
a012abd0:  80 a2 20 07  cmp  %o0, 7
a012abd4:  94 0a e0 ff  and  %o3, 0xff, %o2
a012abd8:  80 a2 a0 03  cmp  %o2, 3
a012abdc:  18 80 00 36  bgu  0xa012acb4
a012abe0:  80 a2 20 07  cmp  %o0, 7
a012abe4:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a012abe8:  90 10 20 01  mov  1, %o0
a012abec:  10 bf ff 54  b  0xa012a93c
a012abf0:  d0 2c 62 18  stb  %o0, [ %l1 + 0x218 ]
a012abf4:  7f ff e7 7e  call  0xa01249ec
a012abf8:  c0 2c 62 14  clrb  [ %l1 + 0x214 ]
a012abfc:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a012ac00:  96 14 20 1c  or  %l0, 0x1c, %o3	! 0xa802cc1c
a012ac04:  c2 02 e0 34  ld  [ %o3 + 0x34 ], %g1
a012ac08:  90 10 23 ff  mov  0x3ff, %o0
a012ac0c:  80 a0 60 00  cmp  %g1, 0
a012ac10:  12 80 00 4f  bne  0xa012ad4c
a012ac14:  d0 37 bf e2  sth  %o0, [ %fp + -30 ]
a012ac18:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a012ac1c:  c0 33 e2 f2  clrh  [ %o7 + 0x2f2 ]	! 0xa802caf2
a012ac20:  d8 13 e2 f2  lduh  [ %o7 + 0x2f2 ], %o4
a012ac24:  93 2b 20 03  sll  %o4, 3, %o1
a012ac28:  b0 22 40 0c  sub  %o1, %o4, %i0
a012ac2c:  83 2e 20 07  sll  %i0, 7, %g1
a012ac30:  17 00 10 04  sethi  %hi(0x401000), %o3
a012ac34:  90 00 40 0c  add  %g1, %o4, %o0
a012ac38:  9a 12 e0 05  or  %o3, 5, %o5
a012ac3c:  80 52 00 0d  umul  %o0, %o5, %g0
a012ac40:  93 40 00 00  rd  %y, %o1
a012ac44:  94 22 00 09  sub  %o0, %o1, %o2
a012ac48:  9f 32 a0 01  srl  %o2, 1, %o7
a012ac4c:  b0 02 40 0f  add  %o1, %o7, %i0
a012ac50:  83 36 20 09  srl  %i0, 9, %g1
a012ac54:  98 14 20 1c  or  %l0, 0x1c, %o4
a012ac58:  a0 00 60 7e  add  %g1, 0x7e, %l0
a012ac5c:  c2 03 20 34  ld  [ %o4 + 0x34 ], %g1
a012ac60:  80 a0 60 00  cmp  %g1, 0
a012ac64:  12 80 00 37  bne  0xa012ad40
a012ac68:  e0 37 bf e0  sth  %l0, [ %fp + -32 ]
a012ac6c:  40 00 62 e6  call  0xa0143804
a012ac70:  d0 17 bf e0  lduh  [ %fp + -32 ], %o0
a012ac74:  10 bf ff a6  b  0xa012ab0c
a012ac78:  c2 0c 62 14  ldub  [ %l1 + 0x214 ], %g1
a012ac7c:  67 fd 8a 43  call  0x4008d588
a012ac80:  01 00 00 00  nop
a012ac84:  d6 0c 62 14  ldub  [ %l1 + 0x214 ], %o3
a012ac88:  80 a2 e0 00  cmp  %o3, 0
a012ac8c:  12 bf ff 21  bne  0xa012a910
a012ac90:  d0 34 22 16  sth  %o0, [ %l0 + 0x216 ]
a012ac94:  a0 10 20 01  mov  1, %l0
a012ac98:  90 10 20 20  mov  0x20, %o0
a012ac9c:  40 00 62 da  call  0xa0143804
a012aca0:  e0 2c 62 14  stb  %l0, [ %l1 + 0x214 ]
a012aca4:  7f ff e7 59  call  0xa0124a08
a012aca8:  01 00 00 00  nop
a012acac:  10 bf ff 98  b  0xa012ab0c
a012acb0:  c2 0c 62 14  ldub  [ %l1 + 0x214 ], %g1
a012acb4:  18 80 00 03  bgu  0xa012acc0
a012acb8:  9a 10 20 01  mov  1, %o5
a012acbc:  9a 10 20 00  clr  %o5
a012acc0:  80 a3 20 07  cmp  %o4, 7
a012acc4:  18 80 00 03  bgu  0xa012acd0
a012acc8:  82 10 20 01  mov  1, %g1
a012accc:  82 10 20 00  clr  %g1
a012acd0:  80 93 40 01  orcc  %o5, %g1, %g0
a012acd4:  12 80 00 06  bne  0xa012acec
a012acd8:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a012acdc:  a0 0a e0 ff  and  %o3, 0xff, %l0
a012ace0:  80 a4 20 07  cmp  %l0, 7
a012ace4:  08 bf ff 16  bleu  0xa012a93c
a012ace8:  01 00 00 00  nop
a012acec:  10 bf ff 14  b  0xa012a93c
a012acf0:  c0 2c 62 18  clrb  [ %l1 + 0x218 ]
a012acf4:  08 bf ff 37  bleu  0xa012a9d0
a012acf8:  d2 32 e2 f0  sth  %o1, [ %o3 + 0x2f0 ]
a012acfc:  b0 10 23 ff  mov  0x3ff, %i0
a012ad00:  10 bf ff 34  b  0xa012a9d0
a012ad04:  f0 32 e2 f0  sth  %i0, [ %o3 + 0x2f0 ]
a012ad08:  28 80 00 04  bleu,a   0xa012ad18
a012ad0c:  c0 33 e2 f2  clrh  [ %o7 + 0x2f2 ]
a012ad10:  9a 02 3f fc  add  %o0, -4, %o5
a012ad14:  da 33 e2 f2  sth  %o5, [ %o7 + 0x2f2 ]
a012ad18:  e0 12 e2 f0  lduh  [ %o3 + 0x2f0 ], %l0
a012ad1c:  d6 12 62 f2  lduh  [ %o1 + 0x2f2 ], %o3
a012ad20:  80 a2 c0 10  cmp  %o3, %l0
a012ad24:  2a bf ff 48  bcs,a   0xa012aa44
a012ad28:  e0 32 62 f2  sth  %l0, [ %o1 + 0x2f2 ]
a012ad2c:  10 bf ff 47  b  0xa012aa48
a012ad30:  e0 12 62 f2  lduh  [ %o1 + 0x2f2 ], %l0
a012ad34:  27 2a 00 b2  sethi  %hi(0xa802c800), %l3
a012ad38:  10 bf fe f6  b  0xa012a910
a012ad3c:  c0 2c e2 19  clrb  [ %l3 + 0x219 ]	! 0xa802ca19
a012ad40:  9f c0 40 00  call  %g1
a012ad44:  90 07 bf e0  add  %fp, -32, %o0
a012ad48:  30 bf ff c9  b,a   0xa012ac6c
a012ad4c:  9f c0 40 00  call  %g1
a012ad50:  90 07 bf e2  add  %fp, -30, %o0
a012ad54:  10 bf ff b2  b  0xa012ac1c
a012ad58:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a012ad5c:  81 c7 e0 08  ret
a012ad60:  81 e8 00 00  restore
