# leon2m FUN_a01026e8 0xa01026e8-0xa0102f6c (164 bytes)
a01026e8:  9d e3 bf 98  save  %sp, -104, %sp
a01026ec:  11 07 00 e8  sethi  %hi(0x1c03a000), %o0
a01026f0:  82 12 21 7f  or  %o0, 0x17f, %g1	! 0x1c03a17f
a01026f4:  80 a6 40 01  cmp  %i1, %g1
a01026f8:  a2 10 20 00  clr  %l1
a01026fc:  08 80 00 08  bleu  0xa010271c
a0102700:  a0 10 00 19  mov  %i1, %l0
a0102704:  15 0e 01 d0  sethi  %hi(0x38074000), %o2
a0102708:  92 12 a2 ff  or  %o2, 0x2ff, %o1	! 0x380742ff
a010270c:  80 a6 40 09  cmp  %i1, %o1
a0102710:  a2 10 20 01  mov  1, %l1
a0102714:  18 80 00 32  bgu  0xa01027dc
a0102718:  a1 36 60 01  srl  %i1, 1, %l0
a010271c:  1b 00 2d c6  sethi  %hi(0xb71800), %o5
a0102720:  11 00 00 80  sethi  %hi(0x20000), %o0
a0102724:  92 54 00 08  umul  %l0, %o0, %o1
a0102728:  91 40 00 00  rd  %y, %o0
a010272c:  94 10 20 00  clr  %o2
a0102730:  40 01 4a b6  call  0xa0155208
a0102734:  96 13 63 00  or  %o5, 0x300, %o3
a0102738:  82 0e 20 ff  and  %i0, 0xff, %g1
a010273c:  80 a0 60 04  cmp  %g1, 4
a0102740:  18 80 02 09  bgu  0xa0102f64
a0102744:  b2 10 00 09  mov  %o1, %i1
a0102748:  13 00 02 87  sethi  %hi(0xa1c00), %o1
a010274c:  b1 28 60 02  sll  %g1, 2, %i0
a0102750:  90 12 61 10  or  %o1, 0x110, %o0
a0102754:  de 02 00 18  ld  [ %o0 + %i0 ], %o7
a0102758:  81 c3 c0 00  jmp  %o7
a010275c:  01 00 00 00  nop
a0102760:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a0102764:  21 00 00 3f  sethi  %hi(0xfc00), %l0
a0102768:  98 10 60 40  or  %g1, 0x40, %o4
a010276c:  96 14 23 ff  or  %l0, 0x3ff, %o3
a0102770:  9a 10 3f ff  mov  -1, %o5
a0102774:  94 10 20 01  mov  1, %o2
a0102778:  de 03 00 00  ld  [ %o4 ], %o7
a010277c:  80 a3 e0 02  cmp  %o7, 2
a0102780:  32 80 00 02  bne,a   0xa0102788
a0102784:  d4 23 00 00  st  %o2, [ %o4 ]
a0102788:  f0 03 00 00  ld  [ %o4 ], %i0
a010278c:  80 a6 20 01  cmp  %i0, 1
a0102790:  02 80 00 07  be  0xa01027ac
a0102794:  9a 03 7f ff  add  %o5, -1, %o5
a0102798:  93 2b 60 10  sll  %o5, 0x10, %o1
a010279c:  91 32 60 10  srl  %o1, 0x10, %o0
a01027a0:  80 a2 00 0b  cmp  %o0, %o3
a01027a4:  12 bf ff f5  bne  0xa0102778
a01027a8:  01 00 00 00  nop
a01027ac:  9e 10 20 01  mov  1, %o7	! 0x1
a01027b0:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a01027b4:  de 23 00 00  st  %o7, [ %o4 ]
a01027b8:  a0 10 63 44  or  %g1, 0x344, %l0
a01027bc:  d4 04 00 00  ld  [ %l0 ], %o2
a01027c0:  96 0a a0 ff  and  %o2, 0xff, %o3
a01027c4:  9b 32 e0 06  srl  %o3, 6, %o5
a01027c8:  c0 23 00 00  clr  [ %o4 ]
a01027cc:  80 a3 40 11  cmp  %o5, %l1
a01027d0:  12 80 01 67  bne  0xa0102d6c
a01027d4:  15 00 06 69  sethi  %hi(0x19a400), %o2
a01027d8:  30 80 01 e3  b,a   0xa0102f64
a01027dc:  19 1b dd 7b  sethi  %hi(0x6f75ec00), %o4
a01027e0:  96 13 23 7f  or  %o4, 0x37f, %o3	! 0x6f75ef7f
a01027e4:  80 a6 40 0b  cmp  %i1, %o3
a01027e8:  a2 10 20 02  mov  2, %l1
a01027ec:  08 bf ff cc  bleu  0xa010271c
a01027f0:  a1 36 60 02  srl  %i1, 2, %l0
a01027f4:  a1 36 60 03  srl  %i1, 3, %l0
a01027f8:  10 bf ff c9  b  0xa010271c
a01027fc:  a2 10 20 03  mov  3, %l1
a0102800:  03 00 06 69  sethi  %hi(0x19a400), %g1
a0102804:  a2 0c 60 ff  and  %l1, 0xff, %l1
a0102808:  92 10 00 10  mov  %l0, %o1
a010280c:  90 10 62 e0  or  %g1, 0x2e0, %o0
a0102810:  7f ff 72 58  call  0xa00df170
a0102814:  94 10 00 11  mov  %l1, %o2
a0102818:  21 33 c0 4a  sethi  %hi(0xcf012800), %l0
a010281c:  7f ff c2 23  call  0xa00f30a8
a0102820:  90 14 20 84  or  %l0, 0x84, %o0	! 0xcf012884
a0102824:  80 a2 00 19  cmp  %o0, %i1
a0102828:  02 80 01 b1  be  0xa0102eec
a010282c:  1f 33 c0 51  sethi  %hi(0xcf014400), %o7
a0102830:  13 00 06 69  sethi  %hi(0x19a400), %o1
a0102834:  7f ff 72 4f  call  0xa00df170
a0102838:  90 12 63 00  or  %o1, 0x300, %o0	! 0x19a700
a010283c:  11 33 c0 f2  sethi  %hi(0xcf03c800), %o0
a0102840:  31 00 00 3f  sethi  %hi(0xfc00), %i0
a0102844:  98 12 20 40  or  %o0, 0x40, %o4
a0102848:  96 16 23 ff  or  %i0, 0x3ff, %o3
a010284c:  9a 10 3f ff  mov  -1, %o5
a0102850:  94 10 20 01  mov  1, %o2
a0102854:  e0 03 00 00  ld  [ %o4 ], %l0
a0102858:  80 a4 20 02  cmp  %l0, 2
a010285c:  32 80 00 02  bne,a   0xa0102864
a0102860:  d4 23 00 00  st  %o2, [ %o4 ]
a0102864:  c2 03 00 00  ld  [ %o4 ], %g1
a0102868:  80 a0 60 01  cmp  %g1, 1
a010286c:  02 80 00 07  be  0xa0102888
a0102870:  9a 03 7f ff  add  %o5, -1, %o5
a0102874:  b1 2b 60 10  sll  %o5, 0x10, %i0
a0102878:  9f 36 20 10  srl  %i0, 0x10, %o7
a010287c:  80 a3 c0 0b  cmp  %o7, %o3
a0102880:  12 bf ff f5  bne  0xa0102854
a0102884:  01 00 00 00  nop
a0102888:  1b 33 c0 49  sethi  %hi(0xcf012400), %o5
a010288c:  a0 10 20 01  mov  1, %l0
a0102890:  e0 23 00 00  st  %l0, [ %o4 ]
a0102894:  96 13 60 44  or  %o5, 0x44, %o3
a0102898:  d2 02 c0 00  ld  [ %o3 ], %o1
a010289c:  90 12 60 01  or  %o1, 1, %o0
a01028a0:  d0 22 c0 00  st  %o0, [ %o3 ]
a01028a4:  c0 23 00 00  clr  [ %o4 ]
a01028a8:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a01028ac:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a01028b0:  96 13 20 40  or  %o4, 0x40, %o3
a01028b4:  98 12 a3 ff  or  %o2, 0x3ff, %o4
a01028b8:  9a 10 3f ff  mov  -1, %o5
a01028bc:  94 10 20 01  mov  1, %o2
a01028c0:  c2 02 c0 00  ld  [ %o3 ], %g1
a01028c4:  80 a0 60 02  cmp  %g1, 2
a01028c8:  32 80 00 02  bne,a   0xa01028d0
a01028cc:  d4 22 c0 00  st  %o2, [ %o3 ]
a01028d0:  de 02 c0 00  ld  [ %o3 ], %o7
a01028d4:  80 a3 e0 01  cmp  %o7, 1
a01028d8:  02 80 00 07  be  0xa01028f4
a01028dc:  9a 03 7f ff  add  %o5, -1, %o5
a01028e0:  91 2b 60 10  sll  %o5, 0x10, %o0
a01028e4:  b1 32 20 10  srl  %o0, 0x10, %i0
a01028e8:  80 a6 00 0c  cmp  %i0, %o4
a01028ec:  12 bf ff f5  bne  0xa01028c0
a01028f0:  01 00 00 00  nop
a01028f4:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a01028f8:  92 10 20 01  mov  1, %o1
a01028fc:  d2 22 c0 00  st  %o1, [ %o3 ]
a0102900:  90 13 63 7c  or  %o5, 0x37c, %o0
a0102904:  d8 02 00 00  ld  [ %o0 ], %o4
a0102908:  94 0b 3f fe  and  %o4, -2, %o2
a010290c:  d4 22 00 00  st  %o2, [ %o0 ]
a0102910:  c0 22 c0 00  clr  [ %o3 ]
a0102914:  96 13 63 40  or  %o5, 0x340, %o3
a0102918:  f0 02 c0 00  ld  [ %o3 ], %i0
a010291c:  9e 0e 3f 3f  and  %i0, -193, %o7
a0102920:  de 22 c0 00  st  %o7, [ %o3 ]
a0102924:  e0 02 c0 00  ld  [ %o3 ], %l0
a0102928:  83 2c 60 06  sll  %l1, 6, %g1
a010292c:  23 33 c0 4a  sethi  %hi(0xcf012800), %l1
a0102930:  92 14 00 01  or  %l0, %g1, %o1
a0102934:  d2 22 c0 00  st  %o1, [ %o3 ]
a0102938:  94 14 60 94  or  %l1, 0x94, %o2
a010293c:  98 10 20 20  mov  0x20, %o4
a0102940:  d8 22 80 00  st  %o4, [ %o2 ]
a0102944:  b0 14 60 84  or  %l1, 0x84, %i0
a0102948:  7f ff c1 ea  call  0xa00f30f0
a010294c:  81 e8 00 00  restore
a0102950:  92 10 00 10  mov  %l0, %o1
a0102954:  a2 0c 60 ff  and  %l1, 0xff, %l1
a0102958:  21 00 06 69  sethi  %hi(0x19a400), %l0
a010295c:  94 10 00 11  mov  %l1, %o2
a0102960:  7f ff 72 04  call  0xa00df170
a0102964:  90 14 23 10  or  %l0, 0x310, %o0
a0102968:  17 33 c0 4a  sethi  %hi(0xcf012800), %o3
a010296c:  7f ff c1 cf  call  0xa00f30a8
a0102970:  90 12 e0 c4  or  %o3, 0xc4, %o0	! 0xcf0128c4
a0102974:  80 a2 00 19  cmp  %o0, %i1
a0102978:  02 80 01 74  be  0xa0102f48
a010297c:  11 33 c0 51  sethi  %hi(0xcf014400), %o0
a0102980:  19 00 06 69  sethi  %hi(0x19a400), %o4
a0102984:  7f ff 71 fb  call  0xa00df170
a0102988:  90 13 23 30  or  %o4, 0x330, %o0	! 0x19a730
a010298c:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a0102990:  13 33 c0 f2  sethi  %hi(0xcf03c800), %o1
a0102994:  96 12 a3 ff  or  %o2, 0x3ff, %o3
a0102998:  98 12 60 40  or  %o1, 0x40, %o4
a010299c:  9a 10 3f ff  mov  -1, %o5
a01029a0:  94 10 20 01  mov  1, %o2
a01029a4:  e0 03 00 00  ld  [ %o4 ], %l0
a01029a8:  80 a4 20 02  cmp  %l0, 2
a01029ac:  32 80 00 02  bne,a   0xa01029b4
a01029b0:  d4 23 00 00  st  %o2, [ %o4 ]
a01029b4:  c2 03 00 00  ld  [ %o4 ], %g1
a01029b8:  80 a0 60 01  cmp  %g1, 1
a01029bc:  02 80 00 07  be  0xa01029d8
a01029c0:  9a 03 7f ff  add  %o5, -1, %o5
a01029c4:  b1 2b 60 10  sll  %o5, 0x10, %i0
a01029c8:  9f 36 20 10  srl  %i0, 0x10, %o7
a01029cc:  80 a3 c0 0b  cmp  %o7, %o3
a01029d0:  12 bf ff f5  bne  0xa01029a4
a01029d4:  01 00 00 00  nop
a01029d8:  82 10 20 01  mov  1, %g1	! 0x1
a01029dc:  21 33 c0 49  sethi  %hi(0xcf012400), %l0
a01029e0:  c2 23 00 00  st  %g1, [ %o4 ]
a01029e4:  96 14 20 44  or  %l0, 0x44, %o3
a01029e8:  d2 02 c0 00  ld  [ %o3 ], %o1
a01029ec:  94 12 60 02  or  %o1, 2, %o2
a01029f0:  d4 22 c0 00  st  %o2, [ %o3 ]
a01029f4:  1b 00 00 3f  sethi  %hi(0xfc00), %o5
a01029f8:  c0 23 00 00  clr  [ %o4 ]
a01029fc:  11 33 c0 f2  sethi  %hi(0xcf03c800), %o0
a0102a00:  98 13 63 ff  or  %o5, 0x3ff, %o4
a0102a04:  96 12 20 40  or  %o0, 0x40, %o3
a0102a08:  9a 10 3f ff  mov  -1, %o5
a0102a0c:  94 10 20 01  mov  1, %o2
a0102a10:  de 02 c0 00  ld  [ %o3 ], %o7
a0102a14:  80 a3 e0 02  cmp  %o7, 2
a0102a18:  32 80 00 02  bne,a   0xa0102a20
a0102a1c:  d4 22 c0 00  st  %o2, [ %o3 ]
a0102a20:  f0 02 c0 00  ld  [ %o3 ], %i0
a0102a24:  80 a6 20 01  cmp  %i0, 1
a0102a28:  02 80 00 07  be  0xa0102a44
a0102a2c:  9a 03 7f ff  add  %o5, -1, %o5
a0102a30:  93 2b 60 10  sll  %o5, 0x10, %o1
a0102a34:  91 32 60 10  srl  %o1, 0x10, %o0
a0102a38:  80 a2 00 0c  cmp  %o0, %o4
a0102a3c:  12 bf ff f5  bne  0xa0102a10
a0102a40:  01 00 00 00  nop
a0102a44:  11 33 c0 51  sethi  %hi(0xcf014400), %o0
a0102a48:  94 10 20 01  mov  1, %o2
a0102a4c:  d4 22 c0 00  st  %o2, [ %o3 ]
a0102a50:  92 12 23 7c  or  %o0, 0x37c, %o1
a0102a54:  da 02 40 00  ld  [ %o1 ], %o5
a0102a58:  98 0b 7f fd  and  %o5, -3, %o4
a0102a5c:  d8 22 40 00  st  %o4, [ %o1 ]
a0102a60:  c0 22 c0 00  clr  [ %o3 ]
a0102a64:  96 12 23 40  or  %o0, 0x340, %o3
a0102a68:  f0 02 c0 00  ld  [ %o3 ], %i0
a0102a6c:  9e 0e 3f cf  and  %i0, -49, %o7
a0102a70:  de 22 c0 00  st  %o7, [ %o3 ]
a0102a74:  e0 02 c0 00  ld  [ %o3 ], %l0
a0102a78:  83 2c 60 04  sll  %l1, 4, %g1
a0102a7c:  23 33 c0 4a  sethi  %hi(0xcf012800), %l1
a0102a80:  94 14 00 01  or  %l0, %g1, %o2
a0102a84:  d4 22 c0 00  st  %o2, [ %o3 ]
a0102a88:  98 14 60 d4  or  %l1, 0xd4, %o4
a0102a8c:  9a 10 20 20  mov  0x20, %o5
a0102a90:  da 23 00 00  st  %o5, [ %o4 ]
a0102a94:  b0 14 60 c4  or  %l1, 0xc4, %i0
a0102a98:  7f ff c1 96  call  0xa00f30f0
a0102a9c:  81 e8 00 00  restore
a0102aa0:  92 10 00 10  mov  %l0, %o1
a0102aa4:  a2 0c 60 ff  and  %l1, 0xff, %l1
a0102aa8:  21 00 06 69  sethi  %hi(0x19a400), %l0
a0102aac:  94 10 00 11  mov  %l1, %o2
a0102ab0:  7f ff 71 b0  call  0xa00df170
a0102ab4:  90 14 23 40  or  %l0, 0x340, %o0
a0102ab8:  17 33 c0 4a  sethi  %hi(0xcf012800), %o3
a0102abc:  7f ff c1 7b  call  0xa00f30a8
a0102ac0:  90 12 e1 04  or  %o3, 0x104, %o0	! 0xcf012904
a0102ac4:  80 a2 00 19  cmp  %o0, %i1
a0102ac8:  02 80 01 18  be  0xa0102f28
a0102acc:  13 33 c0 51  sethi  %hi(0xcf014400), %o1
a0102ad0:  19 00 06 69  sethi  %hi(0x19a400), %o4
a0102ad4:  7f ff 71 a7  call  0xa00df170
a0102ad8:  90 13 23 60  or  %o4, 0x360, %o0	! 0x19a760
a0102adc:  15 33 c0 f2  sethi  %hi(0xcf03c800), %o2
a0102ae0:  1b 00 00 3f  sethi  %hi(0xfc00), %o5
a0102ae4:  98 12 a0 40  or  %o2, 0x40, %o4
a0102ae8:  96 13 63 ff  or  %o5, 0x3ff, %o3
a0102aec:  9a 10 3f ff  mov  -1, %o5
a0102af0:  94 10 20 01  mov  1, %o2
a0102af4:  e0 03 00 00  ld  [ %o4 ], %l0
a0102af8:  80 a4 20 02  cmp  %l0, 2
a0102afc:  32 80 00 02  bne,a   0xa0102b04
a0102b00:  d4 23 00 00  st  %o2, [ %o4 ]
a0102b04:  c2 03 00 00  ld  [ %o4 ], %g1
a0102b08:  80 a0 60 01  cmp  %g1, 1
a0102b0c:  02 80 00 07  be  0xa0102b28
a0102b10:  9a 03 7f ff  add  %o5, -1, %o5
a0102b14:  b1 2b 60 10  sll  %o5, 0x10, %i0
a0102b18:  9f 36 20 10  srl  %i0, 0x10, %o7
a0102b1c:  80 a3 c0 0b  cmp  %o7, %o3
a0102b20:  12 bf ff f5  bne  0xa0102af4
a0102b24:  01 00 00 00  nop
a0102b28:  1b 33 c0 49  sethi  %hi(0xcf012400), %o5
a0102b2c:  82 10 20 01  mov  1, %g1
a0102b30:  c2 23 00 00  st  %g1, [ %o4 ]
a0102b34:  96 13 60 44  or  %o5, 0x44, %o3
a0102b38:  e0 02 c0 00  ld  [ %o3 ], %l0
a0102b3c:  94 14 20 04  or  %l0, 4, %o2
a0102b40:  d4 22 c0 00  st  %o2, [ %o3 ]
a0102b44:  c0 23 00 00  clr  [ %o4 ]
a0102b48:  13 33 c0 f2  sethi  %hi(0xcf03c800), %o1
a0102b4c:  11 00 00 3f  sethi  %hi(0xfc00), %o0
a0102b50:  96 12 60 40  or  %o1, 0x40, %o3
a0102b54:  98 12 23 ff  or  %o0, 0x3ff, %o4
a0102b58:  9a 10 3f ff  mov  -1, %o5
a0102b5c:  94 10 20 01  mov  1, %o2
a0102b60:  de 02 c0 00  ld  [ %o3 ], %o7
a0102b64:  80 a3 e0 02  cmp  %o7, 2
a0102b68:  32 80 00 02  bne,a   0xa0102b70
a0102b6c:  d4 22 c0 00  st  %o2, [ %o3 ]
a0102b70:  f0 02 c0 00  ld  [ %o3 ], %i0
a0102b74:  80 a6 20 01  cmp  %i0, 1
a0102b78:  02 80 00 07  be  0xa0102b94
a0102b7c:  9a 03 7f ff  add  %o5, -1, %o5
a0102b80:  93 2b 60 10  sll  %o5, 0x10, %o1
a0102b84:  91 32 60 10  srl  %o1, 0x10, %o0
a0102b88:  80 a2 00 0c  cmp  %o0, %o4
a0102b8c:  12 bf ff f5  bne  0xa0102b60
a0102b90:  01 00 00 00  nop
a0102b94:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a0102b98:  a0 10 20 01  mov  1, %l0
a0102b9c:  e0 22 c0 00  st  %l0, [ %o3 ]
a0102ba0:  92 13 63 7c  or  %o5, 0x37c, %o1
a0102ba4:  d4 02 40 00  ld  [ %o1 ], %o2
a0102ba8:  98 0a bf fb  and  %o2, -5, %o4
a0102bac:  d8 22 40 00  st  %o4, [ %o1 ]
a0102bb0:  c0 22 c0 00  clr  [ %o3 ]
a0102bb4:  94 13 63 40  or  %o5, 0x340, %o2
a0102bb8:  d0 02 80 00  ld  [ %o2 ], %o0
a0102bbc:  b0 0a 3f f3  and  %o0, -13, %i0
a0102bc0:  f0 22 80 00  st  %i0, [ %o2 ]
a0102bc4:  c2 02 80 00  ld  [ %o2 ], %g1
a0102bc8:  9f 2c 60 02  sll  %l1, 2, %o7
a0102bcc:  23 33 c0 4a  sethi  %hi(0xcf012800), %l1
a0102bd0:  a0 10 40 0f  or  %g1, %o7, %l0
a0102bd4:  e0 22 80 00  st  %l0, [ %o2 ]
a0102bd8:  98 14 61 14  or  %l1, 0x114, %o4
a0102bdc:  96 10 20 20  mov  0x20, %o3
a0102be0:  d6 23 00 00  st  %o3, [ %o4 ]
a0102be4:  b0 14 61 04  or  %l1, 0x104, %i0
a0102be8:  7f ff c1 42  call  0xa00f30f0
a0102bec:  81 e8 00 00  restore
a0102bf0:  03 00 06 69  sethi  %hi(0x19a400), %g1
a0102bf4:  a2 0c 60 ff  and  %l1, 0xff, %l1
a0102bf8:  92 10 00 10  mov  %l0, %o1
a0102bfc:  90 10 63 70  or  %g1, 0x370, %o0
a0102c00:  7f ff 71 5c  call  0xa00df170
a0102c04:  94 10 00 11  mov  %l1, %o2
a0102c08:  17 33 c0 4a  sethi  %hi(0xcf012800), %o3
a0102c0c:  7f ff c1 27  call  0xa00f30a8
a0102c10:  90 12 e1 44  or  %o3, 0x144, %o0	! 0xcf012944
a0102c14:  80 a2 00 19  cmp  %o0, %i1
a0102c18:  02 80 00 bd  be  0xa0102f0c
a0102c1c:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a0102c20:  19 00 06 69  sethi  %hi(0x19a400), %o4
a0102c24:  7f ff 71 53  call  0xa00df170
a0102c28:  90 13 23 90  or  %o4, 0x390, %o0	! 0x19a790
a0102c2c:  15 33 c0 f2  sethi  %hi(0xcf03c800), %o2
a0102c30:  98 12 a0 40  or  %o2, 0x40, %o4	! 0xcf03c840
a0102c34:  13 00 00 3f  sethi  %hi(0xfc00), %o1
a0102c38:  96 12 63 ff  or  %o1, 0x3ff, %o3	! 0xffff
a0102c3c:  9a 10 3f ff  mov  -1, %o5
a0102c40:  94 10 20 01  mov  1, %o2
a0102c44:  e0 03 00 00  ld  [ %o4 ], %l0
a0102c48:  80 a4 20 02  cmp  %l0, 2
a0102c4c:  32 80 00 02  bne,a   0xa0102c54
a0102c50:  d4 23 00 00  st  %o2, [ %o4 ]
a0102c54:  c2 03 00 00  ld  [ %o4 ], %g1
a0102c58:  80 a0 60 01  cmp  %g1, 1
a0102c5c:  02 80 00 07  be  0xa0102c78
a0102c60:  9a 03 7f ff  add  %o5, -1, %o5
a0102c64:  b1 2b 60 10  sll  %o5, 0x10, %i0
a0102c68:  9f 36 20 10  srl  %i0, 0x10, %o7
a0102c6c:  80 a3 c0 0b  cmp  %o7, %o3
a0102c70:  12 bf ff f5  bne  0xa0102c44
a0102c74:  01 00 00 00  nop
a0102c78:  82 10 20 01  mov  1, %g1	! 0x1
a0102c7c:  21 33 c0 49  sethi  %hi(0xcf012400), %l0
a0102c80:  c2 23 00 00  st  %g1, [ %o4 ]
a0102c84:  96 14 20 44  or  %l0, 0x44, %o3
a0102c88:  d4 02 c0 00  ld  [ %o3 ], %o2
a0102c8c:  92 12 a0 08  or  %o2, 8, %o1
a0102c90:  d2 22 c0 00  st  %o1, [ %o3 ]
a0102c94:  1b 33 c0 f2  sethi  %hi(0xcf03c800), %o5
a0102c98:  c0 23 00 00  clr  [ %o4 ]
a0102c9c:  96 13 60 40  or  %o5, 0x40, %o3
a0102ca0:  11 00 00 3f  sethi  %hi(0xfc00), %o0
a0102ca4:  98 12 23 ff  or  %o0, 0x3ff, %o4	! 0xffff
a0102ca8:  9a 10 3f ff  mov  -1, %o5
a0102cac:  94 10 20 01  mov  1, %o2
a0102cb0:  de 02 c0 00  ld  [ %o3 ], %o7
a0102cb4:  80 a3 e0 02  cmp  %o7, 2
a0102cb8:  32 80 00 02  bne,a   0xa0102cc0
a0102cbc:  d4 22 c0 00  st  %o2, [ %o3 ]
a0102cc0:  f0 02 c0 00  ld  [ %o3 ], %i0
a0102cc4:  80 a6 20 01  cmp  %i0, 1
a0102cc8:  02 80 00 07  be  0xa0102ce4
a0102ccc:  9a 03 7f ff  add  %o5, -1, %o5
a0102cd0:  93 2b 60 10  sll  %o5, 0x10, %o1
a0102cd4:  91 32 60 10  srl  %o1, 0x10, %o0
a0102cd8:  80 a2 00 0c  cmp  %o0, %o4
a0102cdc:  12 bf ff f5  bne  0xa0102cb0
a0102ce0:  01 00 00 00  nop
a0102ce4:  31 33 c0 51  sethi  %hi(0xcf014400), %i0
a0102ce8:  9a 10 20 01  mov  1, %o5
a0102cec:  da 22 c0 00  st  %o5, [ %o3 ]
a0102cf0:  90 16 23 7c  or  %i0, 0x37c, %o0
a0102cf4:  d8 02 00 00  ld  [ %o0 ], %o4
a0102cf8:  92 0b 3f f7  and  %o4, -9, %o1
a0102cfc:  d2 22 00 00  st  %o1, [ %o0 ]
a0102d00:  c0 22 c0 00  clr  [ %o3 ]
a0102d04:  96 16 23 40  or  %i0, 0x340, %o3
a0102d08:  de 02 c0 00  ld  [ %o3 ], %o7
a0102d0c:  82 0b ff fc  and  %o7, -4, %g1
a0102d10:  c2 22 c0 00  st  %g1, [ %o3 ]
a0102d14:  e0 02 c0 00  ld  [ %o3 ], %l0
a0102d18:  94 14 00 11  or  %l0, %l1, %o2
a0102d1c:  23 33 c0 4a  sethi  %hi(0xcf012800), %l1
a0102d20:  d4 22 c0 00  st  %o2, [ %o3 ]
a0102d24:  98 14 61 54  or  %l1, 0x154, %o4
a0102d28:  9a 10 20 20  mov  0x20, %o5
a0102d2c:  da 23 00 00  st  %o5, [ %o4 ]
a0102d30:  b0 14 61 44  or  %l1, 0x144, %i0
a0102d34:  7f ff c0 ef  call  0xa00f30f0
a0102d38:  81 e8 00 00  restore
a0102d3c:  15 00 06 69  sethi  %hi(0x19a400), %o2
a0102d40:  90 12 a3 a0  or  %o2, 0x3a0, %o0	! 0x19a7a0
a0102d44:  a2 0c 60 ff  and  %l1, 0xff, %l1
a0102d48:  92 10 00 10  mov  %l0, %o1
a0102d4c:  7f ff 71 09  call  0xa00df170
a0102d50:  94 10 00 11  mov  %l1, %o2
a0102d54:  17 33 c0 4a  sethi  %hi(0xcf012800), %o3
a0102d58:  7f ff c0 d4  call  0xa00f30a8
a0102d5c:  90 12 e1 84  or  %o3, 0x184, %o0	! 0xcf012984
a0102d60:  80 a2 00 19  cmp  %o0, %i1
a0102d64:  02 bf fe 7f  be  0xa0102760
a0102d68:  15 00 06 69  sethi  %hi(0x19a400), %o2
a0102d6c:  7f ff 71 01  call  0xa00df170
a0102d70:  90 12 a2 d0  or  %o2, 0x2d0, %o0	! 0x19a6d0
a0102d74:  1b 33 c0 49  sethi  %hi(0xcf012400), %o5
a0102d78:  90 13 60 40  or  %o5, 0x40, %o0	! 0xcf012440
a0102d7c:  d6 02 00 00  ld  [ %o0 ], %o3
a0102d80:  92 12 e0 01  or  %o3, 1, %o1
a0102d84:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a0102d88:  31 00 00 3f  sethi  %hi(0xfc00), %i0
a0102d8c:  d2 22 00 00  st  %o1, [ %o0 ]
a0102d90:  98 13 20 40  or  %o4, 0x40, %o4
a0102d94:  96 16 23 ff  or  %i0, 0x3ff, %o3
a0102d98:  9a 10 3f ff  mov  -1, %o5
a0102d9c:  94 10 20 01  mov  1, %o2
a0102da0:  e0 03 00 00  ld  [ %o4 ], %l0
a0102da4:  80 a4 20 02  cmp  %l0, 2
a0102da8:  32 80 00 02  bne,a   0xa0102db0
a0102dac:  d4 23 00 00  st  %o2, [ %o4 ]
a0102db0:  c2 03 00 00  ld  [ %o4 ], %g1
a0102db4:  80 a0 60 01  cmp  %g1, 1
a0102db8:  02 80 00 07  be  0xa0102dd4
a0102dbc:  9a 03 7f ff  add  %o5, -1, %o5
a0102dc0:  b1 2b 60 10  sll  %o5, 0x10, %i0
a0102dc4:  9f 36 20 10  srl  %i0, 0x10, %o7
a0102dc8:  80 a3 c0 0b  cmp  %o7, %o3
a0102dcc:  12 bf ff f5  bne  0xa0102da0
a0102dd0:  01 00 00 00  nop
a0102dd4:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a0102dd8:  82 10 20 01  mov  1, %g1
a0102ddc:  c2 23 00 00  st  %g1, [ %o4 ]
a0102de0:  96 13 63 7c  or  %o5, 0x37c, %o3
a0102de4:  e0 02 c0 00  ld  [ %o3 ], %l0
a0102de8:  94 0c 3f ef  and  %l0, -17, %o2
a0102dec:  d4 22 c0 00  st  %o2, [ %o3 ]
a0102df0:  c0 23 00 00  clr  [ %o4 ]
a0102df4:  13 33 c0 f2  sethi  %hi(0xcf03c800), %o1
a0102df8:  11 00 00 3f  sethi  %hi(0xfc00), %o0
a0102dfc:  98 12 60 40  or  %o1, 0x40, %o4
a0102e00:  96 12 23 ff  or  %o0, 0x3ff, %o3
a0102e04:  9a 10 3f ff  mov  -1, %o5
a0102e08:  94 10 20 01  mov  1, %o2
a0102e0c:  de 03 00 00  ld  [ %o4 ], %o7
a0102e10:  80 a3 e0 02  cmp  %o7, 2
a0102e14:  32 80 00 02  bne,a   0xa0102e1c
a0102e18:  d4 23 00 00  st  %o2, [ %o4 ]
a0102e1c:  f0 03 00 00  ld  [ %o4 ], %i0
a0102e20:  80 a6 20 01  cmp  %i0, 1
a0102e24:  02 80 00 07  be  0xa0102e40
a0102e28:  9a 03 7f ff  add  %o5, -1, %o5
a0102e2c:  93 2b 60 10  sll  %o5, 0x10, %o1
a0102e30:  91 32 60 10  srl  %o1, 0x10, %o0
a0102e34:  80 a2 00 0b  cmp  %o0, %o3
a0102e38:  12 bf ff f5  bne  0xa0102e0c
a0102e3c:  01 00 00 00  nop
a0102e40:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a0102e44:  9e 10 20 01  mov  1, %o7
a0102e48:  de 23 00 00  st  %o7, [ %o4 ]
a0102e4c:  96 13 63 44  or  %o5, 0x344, %o3
a0102e50:  c2 02 c0 00  ld  [ %o3 ], %g1
a0102e54:  a0 08 7f 3f  and  %g1, -193, %l0
a0102e58:  e0 22 c0 00  st  %l0, [ %o3 ]
a0102e5c:  c0 23 00 00  clr  [ %o4 ]
a0102e60:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a0102e64:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a0102e68:  96 13 20 40  or  %o4, 0x40, %o3
a0102e6c:  98 12 a3 ff  or  %o2, 0x3ff, %o4
a0102e70:  9a 10 3f ff  mov  -1, %o5
a0102e74:  94 10 20 01  mov  1, %o2
a0102e78:  f0 02 c0 00  ld  [ %o3 ], %i0
a0102e7c:  80 a6 20 02  cmp  %i0, 2
a0102e80:  32 80 00 02  bne,a   0xa0102e88
a0102e84:  d4 22 c0 00  st  %o2, [ %o3 ]
a0102e88:  d0 02 c0 00  ld  [ %o3 ], %o0
a0102e8c:  80 a2 20 01  cmp  %o0, 1
a0102e90:  02 80 00 07  be  0xa0102eac
a0102e94:  9a 03 7f ff  add  %o5, -1, %o5
a0102e98:  a1 2b 60 10  sll  %o5, 0x10, %l0
a0102e9c:  93 34 20 10  srl  %l0, 0x10, %o1
a0102ea0:  80 a2 40 0c  cmp  %o1, %o4
a0102ea4:  12 bf ff f5  bne  0xa0102e78
a0102ea8:  01 00 00 00  nop
a0102eac:  92 10 20 01  mov  1, %o1	! 0x1
a0102eb0:  11 33 c0 51  sethi  %hi(0xcf014400), %o0
a0102eb4:  d2 22 c0 00  st  %o1, [ %o3 ]
a0102eb8:  9a 12 23 44  or  %o0, 0x344, %o5
a0102ebc:  de 03 40 00  ld  [ %o5 ], %o7
a0102ec0:  b1 2c 60 06  sll  %l1, 6, %i0
a0102ec4:  82 13 c0 18  or  %o7, %i0, %g1
a0102ec8:  c2 23 40 00  st  %g1, [ %o5 ]
a0102ecc:  23 33 c0 4a  sethi  %hi(0xcf012800), %l1
a0102ed0:  c0 22 c0 00  clr  [ %o3 ]
a0102ed4:  94 14 61 94  or  %l1, 0x194, %o2
a0102ed8:  98 10 20 20  mov  0x20, %o4
a0102edc:  d8 22 80 00  st  %o4, [ %o2 ]
a0102ee0:  b0 14 61 84  or  %l1, 0x184, %i0
a0102ee4:  7f ff c0 83  call  0xa00f30f0
a0102ee8:  81 e8 00 00  restore
a0102eec:  9a 13 e3 40  or  %o7, 0x340, %o5
a0102ef0:  d8 03 40 00  ld  [ %o5 ], %o4
a0102ef4:  97 33 20 06  srl  %o4, 6, %o3
a0102ef8:  94 0a e0 03  and  %o3, 3, %o2
a0102efc:  80 a2 80 11  cmp  %o2, %l1
a0102f00:  12 bf fe 4d  bne  0xa0102834
a0102f04:  13 00 06 69  sethi  %hi(0x19a400), %o1
a0102f08:  30 80 00 17  b,a   0xa0102f64
a0102f0c:  90 13 63 40  or  %o5, 0x340, %o0
a0102f10:  f0 02 00 00  ld  [ %o0 ], %i0
a0102f14:  9e 0e 20 03  and  %i0, 3, %o7
a0102f18:  80 a3 c0 11  cmp  %o7, %l1
a0102f1c:  12 bf ff 42  bne  0xa0102c24
a0102f20:  19 00 06 69  sethi  %hi(0x19a400), %o4
a0102f24:  30 80 00 10  b,a   0xa0102f64
a0102f28:  90 12 63 40  or  %o1, 0x340, %o0
a0102f2c:  f0 02 00 00  ld  [ %o0 ], %i0
a0102f30:  9f 36 20 02  srl  %i0, 2, %o7
a0102f34:  82 0b e0 03  and  %o7, 3, %g1
a0102f38:  80 a0 40 11  cmp  %g1, %l1
a0102f3c:  12 bf fe e6  bne  0xa0102ad4
a0102f40:  19 00 06 69  sethi  %hi(0x19a400), %o4
a0102f44:  30 80 00 08  b,a   0xa0102f64
a0102f48:  9a 12 23 40  or  %o0, 0x340, %o5
a0102f4c:  f0 03 40 00  ld  [ %o5 ], %i0
a0102f50:  9f 36 20 04  srl  %i0, 4, %o7
a0102f54:  82 0b e0 03  and  %o7, 3, %g1
a0102f58:  80 a0 40 11  cmp  %g1, %l1
a0102f5c:  12 bf fe 8a  bne  0xa0102984
a0102f60:  19 00 06 69  sethi  %hi(0x19a400), %o4
a0102f64:  81 c7 e0 08  ret
a0102f68:  81 e8 00 00  restore
