# leon2m FUN_a008e7b0 0xa008e7b0-0xa008ec48 (1176 bytes)
a008e7b0:  9d e3 bf 98  save  %sp, -104, %sp
a008e7b4:  40 02 5e 9a  call  0xa012621c
a008e7b8:  29 2a 00 b3  sethi  %hi(0xa802cc00), %l4
a008e7bc:  40 02 5e 98  call  0xa012621c
a008e7c0:  a2 10 00 08  mov  %o0, %l1
a008e7c4:  a0 0a 20 ff  and  %o0, 0xff, %l0
a008e7c8:  80 a4 20 00  cmp  %l0, 0
a008e7cc:  02 80 00 19  be  0xa008e830
a008e7d0:  9e 10 20 00  clr  %o7
a008e7d4:  03 00 04 01  sethi  %hi(0x100400), %g1
a008e7d8:  94 10 61 3f  or  %g1, 0x13f, %o2	! 0x10053f
a008e7dc:  96 10 20 00  clr  %o3
a008e7e0:  9a 10 20 00  clr  %o5
a008e7e4:  98 03 40 0d  add  %o5, %o5, %o4
a008e7e8:  96 02 e0 01  inc  %o3
a008e7ec:  d2 0a 80 0c  ldub  [ %o2 + %o4 ], %o1
a008e7f0:  80 8a 40 08  btst  %o1, %o0
a008e7f4:  12 80 00 c5  bne  0xa008eb08
a008e7f8:  9a 0a e0 ff  and  %o3, 0xff, %o5
a008e7fc:  80 a3 60 05  cmp  %o5, 5
a008e800:  08 bf ff fa  bleu  0xa008e7e8
a008e804:  98 03 40 0d  add  %o5, %o5, %o4
a008e808:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a008e80c:  96 14 a2 90  or  %l2, 0x290, %o3	! 0xa802d290
a008e810:  29 2a 00 b3  sethi  %hi(0xa802cc00), %l4
a008e814:  15 00 00 15  sethi  %hi(0x5400), %o2
a008e818:  98 15 23 f4  or  %l4, 0x3f4, %o4
a008e81c:  da 12 e1 f6  lduh  [ %o3 + 0x1f6 ], %o5
a008e820:  90 12 a1 aa  or  %o2, 0x1aa, %o0
a008e824:  80 a3 40 08  cmp  %o5, %o0
a008e828:  02 80 00 9f  be  0xa008eaa4
a008e82c:  de 2b 20 06  stb  %o7, [ %o4 + 6 ]
a008e830:  de 15 23 f4  lduh  [ %l4 + 0x3f4 ], %o7
a008e834:  80 8b e8 00  btst  0x800, %o7
a008e838:  02 80 00 0a  be  0xa008e860
a008e83c:  ea 15 23 f4  lduh  [ %l4 + 0x3f4 ], %l5
a008e840:  80 a4 20 02  cmp  %l0, 2
a008e844:  02 80 00 ab  be  0xa008eaf0
a008e848:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a008e84c:  da 02 a2 90  ld  [ %o2 + 0x290 ], %o5	! 0xa802d290
a008e850:  27 00 00 10  sethi  %hi(0x4000), %l3
a008e854:  a4 2b 40 13  andn  %o5, %l3, %l2
a008e858:  e4 22 a2 90  st  %l2, [ %o2 + 0x290 ]
a008e85c:  ea 15 23 f4  lduh  [ %l4 + 0x3f4 ], %l5
a008e860:  82 0d 77 ff  and  %l5, -2049, %g1
a008e864:  2b 00 04 01  sethi  %hi(0x100400), %l5
a008e868:  c2 35 23 f4  sth  %g1, [ %l4 + 0x3f4 ]
a008e86c:  90 0c 60 ff  and  %l1, 0xff, %o0
a008e870:  96 10 20 00  clr  %o3
a008e874:  98 10 20 00  clr  %o4
a008e878:  94 15 61 1f  or  %l5, 0x11f, %o2
a008e87c:  9e 03 00 0c  add  %o4, %o4, %o7
a008e880:  e2 0a 80 0f  ldub  [ %o2 + %o7 ], %l1
a008e884:  80 a4 40 08  cmp  %l1, %o0
a008e888:  02 80 00 06  be  0xa008e8a0
a008e88c:  96 02 e0 01  inc  %o3
a008e890:  98 0a e0 ff  and  %o3, 0xff, %o4
a008e894:  80 a3 20 0f  cmp  %o4, 0xf
a008e898:  08 bf ff fa  bleu  0xa008e880
a008e89c:  9e 03 00 0c  add  %o4, %o4, %o7
a008e8a0:  96 0b 20 0f  and  %o4, 0xf, %o3
a008e8a4:  27 2a 00 ab  sethi  %hi(0xa802ac00), %l3
a008e8a8:  da 0c e3 e2  ldub  [ %l3 + 0x3e2 ], %o5	! 0xa802afe2
a008e8ac:  a0 0a e0 ff  and  %o3, 0xff, %l0
a008e8b0:  80 a3 40 10  cmp  %o5, %l0
a008e8b4:  02 80 00 59  be  0xa008ea18
a008e8b8:  a4 10 00 0b  mov  %o3, %l2
a008e8bc:  80 a4 20 00  cmp  %l0, 0
a008e8c0:  12 80 00 21  bne  0xa008e944
a008e8c4:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a008e8c8:  19 2a 00 ab  sethi  %hi(0xa802ac00), %o4
a008e8cc:  d2 03 23 e4  ld  [ %o4 + 0x3e4 ], %o1	! 0xa802afe4
a008e8d0:  80 a2 60 03  cmp  %o1, 3
a008e8d4:  22 80 00 a2  be,a   0xa008eb5c
a008e8d8:  c0 2c e3 e2  clrb  [ %l3 + 0x3e2 ]
a008e8dc:  d6 2c e3 e2  stb  %o3, [ %l3 + 0x3e2 ]
a008e8e0:  9a 15 61 1f  or  %l5, 0x11f, %o5
a008e8e4:  82 04 00 10  add  %l0, %l0, %g1
a008e8e8:  90 00 40 0d  add  %g1, %o5, %o0
a008e8ec:  ea 0a 20 01  ldub  [ %o0 + 1 ], %l5
a008e8f0:  94 15 23 f4  or  %l4, 0x3f4, %o2
a008e8f4:  40 02 e3 93  call  0xa0147740
a008e8f8:  d0 12 a0 1a  lduh  [ %o2 + 0x1a ], %o0
a008e8fc:  a3 2a 20 10  sll  %o0, 0x10, %l1
a008e900:  a1 34 60 10  srl  %l1, 0x10, %l0
a008e904:  80 a4 23 e7  cmp  %l0, 0x3e7
a008e908:  18 80 00 05  bgu  0xa008e91c
a008e90c:  90 0d 60 ff  and  %l5, 0xff, %o0
a008e910:  80 a2 20 40  cmp  %o0, 0x40
a008e914:  22 80 00 02  be,a   0xa008e91c
a008e918:  90 10 20 4f  mov  0x4f, %o0
a008e91c:  7f ff ee 1a  call  0xa008a184
a008e920:  01 00 00 00  nop
a008e924:  d8 15 23 f4  lduh  [ %l4 + 0x3f4 ], %o4
a008e928:  1f 3f ff e0  sethi  %hi(0xffff8000), %o7
a008e92c:  a6 0b 00 0f  and  %o4, %o7, %l3
a008e930:  97 2c e0 10  sll  %l3, 0x10, %o3
a008e934:  80 a2 e0 00  cmp  %o3, 0
a008e938:  02 80 00 c2  be  0xa008ec40
a008e93c:  01 00 00 00  nop
a008e940:  30 80 00 2f  b,a   0xa008e9fc
a008e944:  e2 10 63 dc  lduh  [ %g1 + 0x3dc ], %l1
a008e948:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a008e94c:  99 3c 40 10  sra  %l1, %l0, %o4
a008e950:  d4 13 63 da  lduh  [ %o5 + 0x3da ], %o2
a008e954:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a008e958:  98 0b 20 01  and  %o4, 1, %o4
a008e95c:  91 3a 80 10  sra  %o2, %l0, %o0
a008e960:  d6 2c e3 e2  stb  %o3, [ %l3 + 0x3e2 ]
a008e964:  80 8a 20 01  btst  1, %o0
a008e968:  d8 24 63 e4  st  %o4, [ %l1 + 0x3e4 ]
a008e96c:  12 80 00 3c  bne  0xa008ea5c
a008e970:  96 14 63 e4  or  %l1, 0x3e4, %o3
a008e974:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a008e978:  d2 12 23 d8  lduh  [ %o0 + 0x3d8 ], %o1	! 0xa802afd8
a008e97c:  d8 22 c0 00  st  %o4, [ %o3 ]
a008e980:  9f 3a 40 10  sra  %o1, %l0, %o7
a008e984:  80 8b e0 01  btst  1, %o7
a008e988:  96 14 63 e4  or  %l1, 0x3e4, %o3
a008e98c:  12 80 00 03  bne  0xa008e998
a008e990:  98 10 20 03  mov  3, %o4
a008e994:  d8 04 63 e4  ld  [ %l1 + 0x3e4 ], %o4
a008e998:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a008e99c:  c2 13 63 c0  lduh  [ %o5 + 0x3c0 ], %g1	! 0xa802afc0
a008e9a0:  95 38 40 10  sra  %g1, %l0, %o2
a008e9a4:  d8 22 c0 00  st  %o4, [ %o3 ]
a008e9a8:  80 8a a0 01  btst  1, %o2
a008e9ac:  9a 14 63 e4  or  %l1, 0x3e4, %o5
a008e9b0:  12 80 00 03  bne  0xa008e9bc
a008e9b4:  82 10 20 04  mov  4, %g1
a008e9b8:  c2 04 63 e4  ld  [ %l1 + 0x3e4 ], %g1
a008e9bc:  40 02 e3 5a  call  0xa0147724
a008e9c0:  c2 23 40 00  st  %g1, [ %o5 ]
a008e9c4:  da 04 63 e4  ld  [ %l1 + 0x3e4 ], %o5
a008e9c8:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a008e9cc:  80 a3 60 01  cmp  %o5, 1
a008e9d0:  02 80 00 66  be  0xa008eb68
a008e9d4:  d0 32 e3 de  sth  %o0, [ %o3 + 0x3de ]
a008e9d8:  80 a3 60 02  cmp  %o5, 2
a008e9dc:  02 80 00 59  be  0xa008eb40
a008e9e0:  80 a3 60 03  cmp  %o5, 3
a008e9e4:  02 80 00 57  be  0xa008eb40
a008e9e8:  80 a3 60 04  cmp  %o5, 4
a008e9ec:  22 80 00 65  be,a   0xa008eb80
a008e9f0:  c0 2c e3 e2  clrb  [ %l3 + 0x3e2 ]
a008e9f4:  10 bf ff bb  b  0xa008e8e0
a008e9f8:  a0 0c a0 ff  and  %l2, 0xff, %l0
a008e9fc:  7f ff ed e2  call  0xa008a184
a008ea00:  90 10 20 41  mov  0x41, %o0
a008ea04:  ea 15 23 f4  lduh  [ %l4 + 0x3f4 ], %l5
a008ea08:  25 3f ff e0  sethi  %hi(0xffff8000), %l2
a008ea0c:  92 2d 40 12  andn  %l5, %l2, %o1
a008ea10:  10 80 00 8c  b  0xa008ec40
a008ea14:  d2 35 23 f4  sth  %o1, [ %l4 + 0x3f4 ]
a008ea18:  80 a4 20 00  cmp  %l0, 0
a008ea1c:  12 80 00 12  bne  0xa008ea64
a008ea20:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a008ea24:  80 a4 20 00  cmp  %l0, 0
a008ea28:  02 80 00 07  be  0xa008ea44
a008ea2c:  c2 04 63 e4  ld  [ %l1 + 0x3e4 ], %g1
a008ea30:  80 a0 60 03  cmp  %g1, 3
a008ea34:  02 80 00 55  be  0xa008eb88
a008ea38:  80 a0 60 01  cmp  %g1, 1
a008ea3c:  22 80 00 71  be,a   0xa008ec00
a008ea40:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a008ea44:  40 02 e3 38  call  0xa0147724
a008ea48:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a008ea4c:  d0 34 a3 de  sth  %o0, [ %l2 + 0x3de ]	! 0xa802afde
a008ea50:  c0 24 63 e4  clr  [ %l1 + 0x3e4 ]
a008ea54:  10 bf ff a3  b  0xa008e8e0
a008ea58:  a0 10 20 00  clr  %l0
a008ea5c:  10 bf ff c6  b  0xa008e974
a008ea60:  98 10 20 02  mov  2, %o4
a008ea64:  d2 04 63 e4  ld  [ %l1 + 0x3e4 ], %o1
a008ea68:  80 a2 60 02  cmp  %o1, 2
a008ea6c:  12 bf ff ef  bne  0xa008ea28
a008ea70:  80 a4 20 00  cmp  %l0, 0
a008ea74:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a008ea78:  40 02 e3 32  call  0xa0147740
a008ea7c:  d0 12 e3 de  lduh  [ %o3 + 0x3de ], %o0	! 0xa802afde
a008ea80:  9b 2a 20 10  sll  %o0, 0x10, %o5
a008ea84:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a008ea88:  91 33 60 10  srl  %o5, 0x10, %o0
a008ea8c:  d4 10 63 e0  lduh  [ %g1 + 0x3e0 ], %o2
a008ea90:  80 a2 00 0a  cmp  %o0, %o2
a008ea94:  28 bf ff 93  bleu,a   0xa008e8e0
a008ea98:  a0 10 20 00  clr  %l0
a008ea9c:  10 bf ff 91  b  0xa008e8e0
a008eaa0:  c0 24 63 e4  clr  [ %l1 + 0x3e4 ]
a008eaa4:  2b 2a 00 b4  sethi  %hi(0xa802d000), %l5
a008eaa8:  92 15 62 74  or  %l5, 0x274, %o1	! 0xa802d274
a008eaac:  da 0a 60 10  ldub  [ %o1 + 0x10 ], %o5
a008eab0:  a6 0b 40 0f  and  %o5, %o7, %l3
a008eab4:  80 8c e0 ff  btst  0xff, %l3
a008eab8:  32 bf ff 5f  bne,a   0xa008e834
a008eabc:  de 15 23 f4  lduh  [ %l4 + 0x3f4 ], %o7
a008eac0:  c2 0a e1 d5  ldub  [ %o3 + 0x1d5 ], %g1
a008eac4:  80 a0 60 00  cmp  %g1, 0
a008eac8:  32 bf ff 5b  bne,a   0xa008e834
a008eacc:  de 15 23 f4  lduh  [ %l4 + 0x3f4 ], %o7
a008ead0:  96 13 40 0f  or  %o5, %o7, %o3
a008ead4:  d6 2a 60 10  stb  %o3, [ %o1 + 0x10 ]
a008ead8:  94 10 22 e0  mov  0x2e0, %o2
a008eadc:  96 10 20 1c  mov  0x1c, %o3
a008eae0:  40 02 f0 fc  call  0xa014aed0
a008eae4:  90 10 20 30  mov  0x30, %o0
a008eae8:  10 bf ff 53  b  0xa008e834
a008eaec:  de 15 23 f4  lduh  [ %l4 + 0x3f4 ], %o7
a008eaf0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a008eaf4:  d0 04 22 90  ld  [ %l0 + 0x290 ], %o0	! 0xa802d290
a008eaf8:  19 00 00 10  sethi  %hi(0x4000), %o4
a008eafc:  92 12 00 0c  or  %o0, %o4, %o1
a008eb00:  10 bf ff 57  b  0xa008e85c
a008eb04:  d2 24 22 90  st  %o1, [ %l0 + 0x290 ]
a008eb08:  a8 03 00 0a  add  %o4, %o2, %l4
a008eb0c:  de 0d 20 01  ldub  [ %l4 + 1 ], %o7
a008eb10:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a008eb14:  96 14 a2 90  or  %l2, 0x290, %o3	! 0xa802d290
a008eb18:  29 2a 00 b3  sethi  %hi(0xa802cc00), %l4
a008eb1c:  15 00 00 15  sethi  %hi(0x5400), %o2
a008eb20:  98 15 23 f4  or  %l4, 0x3f4, %o4
a008eb24:  da 12 e1 f6  lduh  [ %o3 + 0x1f6 ], %o5
a008eb28:  90 12 a1 aa  or  %o2, 0x1aa, %o0
a008eb2c:  80 a3 40 08  cmp  %o5, %o0
a008eb30:  12 bf ff 40  bne  0xa008e830
a008eb34:  de 2b 20 06  stb  %o7, [ %o4 + 6 ]
a008eb38:  10 bf ff dc  b  0xa008eaa8
a008eb3c:  2b 2a 00 b4  sethi  %hi(0xa802d000), %l5
a008eb40:  1f 2a 00 90  sethi  %hi(0xa8024000), %o7
a008eb44:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a008eb48:  e2 13 e0 44  lduh  [ %o7 + 0x44 ], %l1
a008eb4c:  e2 34 a3 e0  sth  %l1, [ %l2 + 0x3e0 ]
a008eb50:  a4 10 20 00  clr  %l2
a008eb54:  10 bf ff 63  b  0xa008e8e0
a008eb58:  a0 0c a0 ff  and  %l2, 0xff, %l0
a008eb5c:  c0 23 23 e4  clr  [ %o4 + 0x3e4 ]
a008eb60:  10 bf ff 60  b  0xa008e8e0
a008eb64:  a0 10 00 0d  mov  %o5, %l0
a008eb68:  19 2a 00 90  sethi  %hi(0xa8024000), %o4
a008eb6c:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a008eb70:  e6 13 20 48  lduh  [ %o4 + 0x48 ], %l3
a008eb74:  e6 34 23 e0  sth  %l3, [ %l0 + 0x3e0 ]
a008eb78:  10 bf ff 5a  b  0xa008e8e0
a008eb7c:  a0 0c a0 ff  and  %l2, 0xff, %l0
a008eb80:  10 bf ff 58  b  0xa008e8e0
a008eb84:  a0 10 20 00  clr  %l0
a008eb88:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a008eb8c:  40 02 e2 ed  call  0xa0147740
a008eb90:  d0 12 63 de  lduh  [ %o1 + 0x3de ], %o0	! 0xa802afde
a008eb94:  9f 2a 20 10  sll  %o0, 0x10, %o7
a008eb98:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a008eb9c:  99 33 e0 10  srl  %o7, 0x10, %o4
a008eba0:  e6 14 a3 e0  lduh  [ %l2 + 0x3e0 ], %l3
a008eba4:  80 a3 00 13  cmp  %o4, %l3
a008eba8:  28 bf ff 4e  bleu,a   0xa008e8e0
a008ebac:  a0 10 20 00  clr  %l0
a008ebb0:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a008ebb4:  c0 24 63 e4  clr  [ %l1 + 0x3e4 ]
a008ebb8:  a2 12 a3 c8  or  %o2, 0x3c8, %l1
a008ebbc:  d4 0c 40 10  ldub  [ %l1 + %l0 ], %o2
a008ebc0:  21 00 04 01  sethi  %hi(0x100400), %l0
a008ebc4:  92 14 21 1f  or  %l0, 0x11f, %o1	! 0x10051f
a008ebc8:  96 10 20 00  clr  %o3
a008ebcc:  98 10 20 00  clr  %o4
a008ebd0:  9a 03 00 0c  add  %o4, %o4, %o5
a008ebd4:  82 03 40 09  add  %o5, %o1, %g1
a008ebd8:  d0 08 60 01  ldub  [ %g1 + 1 ], %o0
a008ebdc:  80 a2 00 0a  cmp  %o0, %o2
a008ebe0:  02 80 00 06  be  0xa008ebf8
a008ebe4:  96 02 e0 01  inc  %o3
a008ebe8:  98 0a e0 ff  and  %o3, 0xff, %o4
a008ebec:  80 a3 20 0f  cmp  %o4, 0xf
a008ebf0:  08 bf ff f9  bleu  0xa008ebd4
a008ebf4:  9a 03 00 0c  add  %o4, %o4, %o5
a008ebf8:  10 bf ff 3a  b  0xa008e8e0
a008ebfc:  a0 0b 20 0f  and  %o4, 0xf, %l0
a008ec00:  40 02 e2 d0  call  0xa0147740
a008ec04:  d0 14 63 de  lduh  [ %l1 + 0x3de ], %o0
a008ec08:  99 2a 20 10  sll  %o0, 0x10, %o4
a008ec0c:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a008ec10:  a7 33 20 10  srl  %o4, 0x10, %l3
a008ec14:  d6 14 a3 e0  lduh  [ %l2 + 0x3e0 ], %o3
a008ec18:  80 a4 c0 0b  cmp  %l3, %o3
a008ec1c:  28 bf ff 31  bleu,a   0xa008e8e0
a008ec20:  a0 10 20 00  clr  %l0
a008ec24:  40 02 e2 c0  call  0xa0147724
a008ec28:  01 00 00 00  nop
a008ec2c:  13 2a 00 90  sethi  %hi(0xa8024000), %o1
a008ec30:  de 12 60 46  lduh  [ %o1 + 0x46 ], %o7	! 0xa8024046
a008ec34:  d0 34 63 de  sth  %o0, [ %l1 + 0x3de ]
a008ec38:  10 bf ff 2a  b  0xa008e8e0
a008ec3c:  de 34 a3 e0  sth  %o7, [ %l2 + 0x3e0 ]
a008ec40:  81 c7 e0 08  ret
a008ec44:  81 e8 00 00  restore
