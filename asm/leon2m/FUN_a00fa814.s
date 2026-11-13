# leon2m FUN_a00fa814 0xa00fa814-0xa00fb434 (3104 bytes)
a00fa814:  9d e3 bf 28  save  %sp, -216, %sp
a00fa818:  39 34 01 00  sethi  %hi(0xd0040000), %i4
a00fa81c:  b2 17 20 14  or  %i4, 0x14, %i1	! 0xd0040014
a00fa820:  f0 06 40 00  ld  [ %i1 ], %i0
a00fa824:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00fa828:  f6 03 23 f4  ld  [ %o4 + 0x3f4 ], %i3	! 0xa802b7f4
a00fa82c:  b5 2e 20 06  sll  %i0, 6, %i2
a00fa830:  82 06 e0 01  add  %i3, 1, %g1
a00fa834:  bb 36 a0 16  srl  %i2, 0x16, %i5
a00fa838:  33 2a 00 b2  sethi  %hi(0xa802c800), %i1
a00fa83c:  b7 36 20 1e  srl  %i0, 0x1e, %i3
a00fa840:  b4 10 20 01  mov  1, %i2
a00fa844:  11 2a 00 af  sethi  %hi(0xa802bc00), %o0
a00fa848:  f8 0e 60 5e  ldub  [ %i1 + 0x5e ], %i4
a00fa84c:  1b 2a 00 af  sethi  %hi(0xa802bc00), %o5
a00fa850:  c2 23 23 f4  st  %g1, [ %o4 + 0x3f4 ]
a00fa854:  fa 32 22 c0  sth  %i5, [ %o0 + 0x2c0 ]
a00fa858:  80 a6 c0 1c  cmp  %i3, %i4
a00fa85c:  02 80 00 63  be  0xa00fa9e8
a00fa860:  f4 2b 62 c4  stb  %i2, [ %o5 + 0x2c4 ]
a00fa864:  3b 2a 00 ad  sethi  %hi(0xa802b400), %i5
a00fa868:  f6 2e 60 5e  stb  %i3, [ %i1 + 0x5e ]
a00fa86c:  f4 2f 63 fe  stb  %i2, [ %i5 + 0x3fe ]
a00fa870:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00fa874:  f4 0a e3 f8  ldub  [ %o3 + 0x3f8 ], %i2	! 0xa802b7f8
a00fa878:  b0 06 bf ff  add  %i2, -1, %i0
a00fa87c:  82 0e 20 ff  and  %i0, 0xff, %g1
a00fa880:  80 a0 60 02  cmp  %g1, 2
a00fa884:  18 80 00 08  bgu  0xa00fa8a4
a00fa888:  35 34 01 00  sethi  %hi(0xd0040000), %i2
a00fa88c:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00fa890:  f6 0b 63 fe  ldub  [ %o5 + 0x3fe ], %i3	! 0xa802b7fe
a00fa894:  80 a6 e0 00  cmp  %i3, 0
a00fa898:  12 80 00 1c  bne  0xa00fa908
a00fa89c:  35 2a 00 af  sethi  %hi(0xa802bc00), %i2
a00fa8a0:  35 34 01 00  sethi  %hi(0xd0040000), %i2
a00fa8a4:  b2 16 a0 d8  or  %i2, 0xd8, %i1	! 0xd00400d8
a00fa8a8:  c2 06 40 00  ld  [ %i1 ], %g1
a00fa8ac:  f8 0a e3 f8  ldub  [ %o3 + 0x3f8 ], %i4
a00fa8b0:  ba 08 60 0f  and  %g1, 0xf, %i5
a00fa8b4:  b6 0f 20 ff  and  %i4, 0xff, %i3
a00fa8b8:  80 a6 c0 1d  cmp  %i3, %i5
a00fa8bc:  02 80 00 07  be  0xa00fa8d8
a00fa8c0:  b0 07 3f ff  add  %i4, -1, %i0
a00fa8c4:  39 2a 00 ad  sethi  %hi(0xa802b400), %i4
a00fa8c8:  c0 2f 23 f0  clrb  [ %i4 + 0x3f0 ]	! 0xa802b7f0
a00fa8cc:  fa 2a e3 f8  stb  %i5, [ %o3 + 0x3f8 ]
a00fa8d0:  b8 10 00 1d  mov  %i5, %i4
a00fa8d4:  b0 07 3f ff  add  %i4, -1, %i0
a00fa8d8:  ba 0e 20 ff  and  %i0, 0xff, %i5
a00fa8dc:  80 a7 60 01  cmp  %i5, 1
a00fa8e0:  28 80 02 d2  bleu,a   0xa00fb428
a00fa8e4:  3b 2a 00 af  sethi  %hi(0xa802bc00), %i5
a00fa8e8:  82 0f 20 ff  and  %i4, 0xff, %g1
a00fa8ec:  80 a0 60 03  cmp  %g1, 3
a00fa8f0:  02 80 00 41  be  0xa00fa9f4
a00fa8f4:  80 a0 60 04  cmp  %g1, 4
a00fa8f8:  02 80 02 cb  be  0xa00fb424
a00fa8fc:  35 2a 00 ad  sethi  %hi(0xa802b400), %i2
a00fa900:  10 80 02 c9  b  0xa00fb424
a00fa904:  c0 2e a3 f0  clrb  [ %i2 + 0x3f0 ]	! 0xa802b7f0
a00fa908:  f8 12 22 c0  lduh  [ %o0 + 0x2c0 ], %i4
a00fa90c:  33 2a 00 af  sethi  %hi(0xa802bc00), %i1
a00fa910:  f8 36 a2 c2  sth  %i4, [ %i2 + 0x2c2 ]
a00fa914:  31 2a 00 9a  sethi  %hi(0xa8026800), %i0
a00fa918:  b4 16 60 80  or  %i1, 0x80, %i2
a00fa91c:  03 2a 00 ae  sethi  %hi(0xa802b800), %g1
a00fa920:  3b 2a 00 ae  sethi  %hi(0xa802b800), %i5
a00fa924:  c0 36 22 94  clrh  [ %i0 + 0x294 ]
a00fa928:  b2 10 60 00  mov  %g1, %i1
a00fa92c:  ba 17 62 40  or  %i5, 0x240, %i5
a00fa930:  b6 10 20 00  clr  %i3
a00fa934:  82 06 c0 1b  add  %i3, %i3, %g1
a00fa938:  b6 06 e0 01  inc  %i3
a00fa93c:  f8 37 40 01  sth  %i4, [ %i5 + %g1 ]
a00fa940:  f8 36 80 01  sth  %i4, [ %i2 + %g1 ]
a00fa944:  80 a6 e1 1f  cmp  %i3, 0x11f
a00fa948:  08 bf ff fb  bleu  0xa00fa934
a00fa94c:  f8 36 40 01  sth  %i4, [ %i1 + %g1 ]
a00fa950:  39 3f bf ff  sethi  %hi(0xfefffc00), %i4
a00fa954:  37 34 01 00  sethi  %hi(0xd0040000), %i3
a00fa958:  9e 10 00 19  mov  %i1, %o7
a00fa95c:  b0 17 23 ff  or  %i4, 0x3ff, %i0
a00fa960:  9a 16 e0 a0  or  %i3, 0xa0, %o5
a00fa964:  98 10 20 00  clr  %o4
a00fa968:  b8 10 20 00  clr  %i4
a00fa96c:  b2 16 e0 a4  or  %i3, 0xa4, %i1
a00fa970:  b4 07 00 1c  add  %i4, %i4, %i2
a00fa974:  ba 06 80 1c  add  %i2, %i4, %i5
a00fa978:  b5 2f 60 03  sll  %i5, 3, %i2
a00fa97c:  b6 10 20 00  clr  %i3
a00fa980:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00fa984:  82 06 80 1d  add  %i2, %i5, %g1
a00fa988:  b9 28 60 10  sll  %g1, 0x10, %i4
a00fa98c:  83 37 20 10  srl  %i4, 0x10, %g1
a00fa990:  ba 00 40 01  add  %g1, %g1, %i5
a00fa994:  f8 13 c0 1d  lduh  [ %o7 + %i5 ], %i4
a00fa998:  f8 26 40 00  st  %i4, [ %i1 ]
a00fa99c:  82 10 62 00  or  %g1, 0x200, %g1
a00fa9a0:  b6 06 e0 01  inc  %i3
a00fa9a4:  82 08 40 18  and  %g1, %i0, %g1
a00fa9a8:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00fa9ac:  80 a7 20 17  cmp  %i4, 0x17
a00fa9b0:  c2 23 40 00  st  %g1, [ %o5 ]
a00fa9b4:  08 bf ff f4  bleu  0xa00fa984
a00fa9b8:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00fa9bc:  98 03 20 01  inc  %o4
a00fa9c0:  b8 0b 20 ff  and  %o4, 0xff, %i4
a00fa9c4:  80 a7 20 0b  cmp  %i4, 0xb
a00fa9c8:  08 bf ff eb  bleu  0xa00fa974
a00fa9cc:  b4 07 00 1c  add  %i4, %i4, %i2
a00fa9d0:  c0 26 40 00  clr  [ %i1 ]
a00fa9d4:  b0 08 7d ff  and  %g1, -513, %i0
a00fa9d8:  f0 23 40 00  st  %i0, [ %o5 ]
a00fa9dc:  33 2a 00 b2  sethi  %hi(0xa802c800), %i1
a00fa9e0:  10 bf ff b0  b  0xa00fa8a0
a00fa9e4:  f0 26 60 60  st  %i0, [ %i1 + 0x60 ]	! 0xa802c860
a00fa9e8:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00fa9ec:  10 bf ff a1  b  0xa00fa870
a00fa9f0:  c0 2b 23 fe  clrb  [ %o4 + 0x3fe ]	! 0xa802b7fe
a00fa9f4:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00fa9f8:  f6 0b 23 f0  ldub  [ %o4 + 0x3f0 ], %i3	! 0xa802b7f0
a00fa9fc:  80 a6 e0 00  cmp  %i3, 0
a00faa00:  12 80 00 66  bne  0xa00fab98
a00faa04:  31 34 01 00  sethi  %hi(0xd0040000), %i0
a00faa08:  f0 06 80 00  ld  [ %i2 ], %i0
a00faa0c:  39 10 00 00  sethi  %hi(0x40000000), %i4
a00faa10:  82 2e 00 1c  andn  %i0, %i4, %g1
a00faa14:  c2 26 80 00  st  %g1, [ %i2 ]
a00faa18:  b8 16 a0 90  or  %i2, 0x90, %i4
a00faa1c:  fa 07 00 00  ld  [ %i4 ], %i5
a00faa20:  b6 0f 7f 00  and  %i5, -256, %i3
a00faa24:  b0 16 e0 80  or  %i3, 0x80, %i0
a00faa28:  f0 27 00 00  st  %i0, [ %i4 ]
a00faa2c:  b0 16 a0 94  or  %i2, 0x94, %i0
a00faa30:  c2 06 00 00  ld  [ %i0 ], %g1
a00faa34:  ba 08 7f 00  and  %g1, -256, %i5
a00faa38:  b6 17 60 e0  or  %i5, 0xe0, %i3
a00faa3c:  f6 26 00 00  st  %i3, [ %i0 ]
a00faa40:  b0 16 a0 98  or  %i2, 0x98, %i0
a00faa44:  f8 06 00 00  ld  [ %i0 ], %i4
a00faa48:  03 00 00 3c  sethi  %hi(0xf000), %g1
a00faa4c:  b6 2f 00 01  andn  %i4, %g1, %i3
a00faa50:  3b 00 00 0c  sethi  %hi(0x3000), %i5
a00faa54:  82 16 c0 1d  or  %i3, %i5, %g1
a00faa58:  c2 26 00 00  st  %g1, [ %i0 ]
a00faa5c:  b8 16 a0 c4  or  %i2, 0xc4, %i4
a00faa60:  f6 07 00 00  ld  [ %i4 ], %i3
a00faa64:  b0 0e ff 0f  and  %i3, -241, %i0
a00faa68:  f0 27 00 00  st  %i0, [ %i4 ]
a00faa6c:  b8 16 a0 bc  or  %i2, 0xbc, %i4
a00faa70:  3b 1f ff f3  sethi  %hi(0x7fffcc00), %i5
a00faa74:  f6 07 00 00  ld  [ %i4 ], %i3
a00faa78:  82 17 60 ff  or  %i5, 0xff, %g1
a00faa7c:  b0 0e c0 01  and  %i3, %g1, %i0
a00faa80:  f0 27 00 00  st  %i0, [ %i4 ]
a00faa84:  c2 06 40 00  ld  [ %i1 ], %g1
a00faa88:  3b 00 40 00  sethi  %hi(0x1000000), %i5
a00faa8c:  b6 10 40 1d  or  %g1, %i5, %i3
a00faa90:  f6 26 40 00  st  %i3, [ %i1 ]
a00faa94:  b6 16 a0 f0  or  %i2, 0xf0, %i3
a00faa98:  f8 06 c0 00  ld  [ %i3 ], %i4
a00faa9c:  31 3f ff c0  sethi  %hi(0xffff0000), %i0
a00faaa0:  3b 00 00 3c  sethi  %hi(0xf000), %i5
a00faaa4:  b4 0f 00 18  and  %i4, %i0, %i2
a00faaa8:  82 17 60 f0  or  %i5, 0xf0, %g1
a00faaac:  b2 16 80 01  or  %i2, %g1, %i1
a00faab0:  f2 26 c0 00  st  %i1, [ %i3 ]
a00faab4:  39 2a 00 af  sethi  %hi(0xa802bc00), %i4
a00faab8:  3b 2a 00 9a  sethi  %hi(0xa8026800), %i5
a00faabc:  33 2a 00 ae  sethi  %hi(0xa802b800), %i1
a00faac0:  b6 17 20 80  or  %i4, 0x80, %i3
a00faac4:  f4 12 22 c0  lduh  [ %o0 + 0x2c0 ], %i2
a00faac8:  31 2a 00 af  sethi  %hi(0xa802bc00), %i0
a00faacc:  c0 37 62 94  clrh  [ %i5 + 0x294 ]
a00faad0:  b8 16 62 40  or  %i1, 0x240, %i4
a00faad4:  03 2a 00 ae  sethi  %hi(0xa802b800), %g1
a00faad8:  f4 36 22 c2  sth  %i2, [ %i0 + 0x2c2 ]
a00faadc:  b2 10 60 00  mov  %g1, %i1
a00faae0:  ba 10 20 00  clr  %i5
a00faae4:  82 07 40 1d  add  %i5, %i5, %g1
a00faae8:  ba 07 60 01  inc  %i5
a00faaec:  f4 36 40 01  sth  %i2, [ %i1 + %g1 ]
a00faaf0:  f4 36 c0 01  sth  %i2, [ %i3 + %g1 ]
a00faaf4:  80 a7 61 1f  cmp  %i5, 0x11f
a00faaf8:  08 bf ff fb  bleu  0xa00faae4
a00faafc:  f4 37 00 01  sth  %i2, [ %i4 + %g1 ]
a00fab00:  9e 10 00 19  mov  %i1, %o7
a00fab04:  33 3f bf ff  sethi  %hi(0xfefffc00), %i1
a00fab08:  35 34 01 00  sethi  %hi(0xd0040000), %i2
a00fab0c:  b0 16 63 ff  or  %i1, 0x3ff, %i0
a00fab10:  9a 16 a0 a0  or  %i2, 0xa0, %o5
a00fab14:  98 10 20 00  clr  %o4
a00fab18:  b8 10 20 00  clr  %i4
a00fab1c:  b2 16 a0 a4  or  %i2, 0xa4, %i1
a00fab20:  ba 07 00 1c  add  %i4, %i4, %i5
a00fab24:  b6 07 40 1c  add  %i5, %i4, %i3
a00fab28:  b5 2e e0 03  sll  %i3, 3, %i2
a00fab2c:  b6 10 20 00  clr  %i3
a00fab30:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00fab34:  82 06 80 1d  add  %i2, %i5, %g1
a00fab38:  b9 28 60 10  sll  %g1, 0x10, %i4
a00fab3c:  83 37 20 10  srl  %i4, 0x10, %g1
a00fab40:  ba 00 40 01  add  %g1, %g1, %i5
a00fab44:  f8 13 c0 1d  lduh  [ %o7 + %i5 ], %i4
a00fab48:  f8 26 40 00  st  %i4, [ %i1 ]
a00fab4c:  82 10 62 00  or  %g1, 0x200, %g1
a00fab50:  b6 06 e0 01  inc  %i3
a00fab54:  82 08 40 18  and  %g1, %i0, %g1
a00fab58:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00fab5c:  80 a7 20 17  cmp  %i4, 0x17
a00fab60:  c2 23 40 00  st  %g1, [ %o5 ]
a00fab64:  28 bf ff f4  bleu,a   0xa00fab34
a00fab68:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00fab6c:  98 03 20 01  inc  %o4
a00fab70:  b8 0b 20 ff  and  %o4, 0xff, %i4
a00fab74:  80 a7 20 0b  cmp  %i4, 0xb
a00fab78:  08 bf ff eb  bleu  0xa00fab24
a00fab7c:  ba 07 00 1c  add  %i4, %i4, %i5
a00fab80:  c0 26 40 00  clr  [ %i1 ]
a00fab84:  b4 08 7d ff  and  %g1, -513, %i2
a00fab88:  f4 23 40 00  st  %i2, [ %o5 ]
a00fab8c:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a00fab90:  f4 26 20 60  st  %i2, [ %i0 + 0x60 ]	! 0xa802c860
a00fab94:  31 34 01 00  sethi  %hi(0xd0040000), %i0
a00fab98:  82 16 20 98  or  %i0, 0x98, %g1	! 0xd0040098
a00fab9c:  f6 00 40 00  ld  [ %g1 ], %i3
a00faba0:  b9 36 e0 0c  srl  %i3, 0xc, %i4
a00faba4:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00faba8:  b4 0f 20 0f  and  %i4, 0xf, %i2
a00fabac:  f2 0e e2 92  ldub  [ %i3 + 0x292 ], %i1
a00fabb0:  80 a6 40 1a  cmp  %i1, %i2
a00fabb4:  02 80 00 55  be  0xa00fad08
a00fabb8:  b8 16 20 b0  or  %i0, 0xb0, %i4
a00fabbc:  c2 07 00 00  ld  [ %i4 ], %g1
a00fabc0:  b2 10 62 00  or  %g1, 0x200, %i1
a00fabc4:  f4 2e e2 92  stb  %i2, [ %i3 + 0x292 ]
a00fabc8:  3b 00 40 00  sethi  %hi(0x1000000), %i5
a00fabcc:  9a 16 20 b4  or  %i0, 0xb4, %o5
a00fabd0:  b6 2e 40 1d  andn  %i1, %i5, %i3
a00fabd4:  31 2a 00 9d  sethi  %hi(0xa8027400), %i0
a00fabd8:  3b 2a 00 9c  sethi  %hi(0xa8027000), %i5
a00fabdc:  94 16 21 36  or  %i0, 0x136, %o2
a00fabe0:  31 2a 00 9b  sethi  %hi(0xa8026c00), %i0
a00fabe4:  b2 10 00 1a  mov  %i2, %i1
a00fabe8:  92 17 63 16  or  %i5, 0x316, %o1
a00fabec:  03 2a 00 9c  sethi  %hi(0xa8027000), %g1
a00fabf0:  35 2a 00 9b  sethi  %hi(0xa8026c00), %i2
a00fabf4:  a4 16 20 b6  or  %i0, 0xb6, %l2
a00fabf8:  3b 2a 00 9a  sethi  %hi(0xa8026800), %i5
a00fabfc:  a0 10 60 f6  or  %g1, 0xf6, %l0
a00fac00:  a2 16 a2 d6  or  %i2, 0x2d6, %l1
a00fac04:  a6 17 62 96  or  %i5, 0x296, %l3
a00fac08:  98 10 00 1c  mov  %i4, %o4
a00fac0c:  96 10 20 00  clr  %o3
a00fac10:  b0 10 20 00  clr  %i0
a00fac14:  b4 10 20 00  clr  %i2
a00fac18:  10 80 00 19  b  0xa00fac7c
a00fac1c:  b8 10 20 00  clr  %i4
a00fac20:  02 80 01 ea  be  0xa00fb3c8
a00fac24:  80 a6 60 03  cmp  %i1, 3
a00fac28:  02 80 01 ee  be  0xa00fb3e0
a00fac2c:  80 a6 60 04  cmp  %i1, 4
a00fac30:  02 80 01 f2  be  0xa00fb3f8
a00fac34:  80 a6 60 05  cmp  %i1, 5
a00fac38:  02 80 01 f6  be  0xa00fb410
a00fac3c:  bb 2f 20 04  sll  %i4, 4, %i5
a00fac40:  83 2f 20 04  sll  %i4, 4, %g1
a00fac44:  ba 00 40 1c  add  %g1, %i4, %i5
a00fac48:  82 07 40 18  add  %i5, %i0, %g1
a00fac4c:  b8 00 40 01  add  %g1, %g1, %i4
a00fac50:  fa 12 80 1c  lduh  [ %o2 + %i4 ], %i5
a00fac54:  fa 23 40 00  st  %i5, [ %o5 ]
a00fac58:  b8 0b e1 ff  and  %o7, 0x1ff, %i4
a00fac5c:  ba 0e fe 00  and  %i3, -512, %i5
a00fac60:  b6 17 40 1c  or  %i5, %i4, %i3
a00fac64:  b4 06 a0 01  inc  %i2
a00fac68:  b8 0e a0 ff  and  %i2, 0xff, %i4
a00fac6c:  f6 23 00 00  st  %i3, [ %o4 ]
a00fac70:  80 a7 20 0f  cmp  %i4, 0xf
a00fac74:  38 80 00 1a  bgu,a   0xa00facdc
a00fac78:  96 02 e0 01  inc  %o3
a00fac7c:  ba 0e a0 ff  and  %i2, 0xff, %i5
a00fac80:  83 2e 20 04  sll  %i0, 4, %g1
a00fac84:  80 a6 60 00  cmp  %i1, 0
a00fac88:  02 bf ff ee  be  0xa00fac40
a00fac8c:  9e 00 40 1d  add  %g1, %i5, %o7
a00fac90:  80 a6 60 01  cmp  %i1, 1
a00fac94:  12 bf ff e3  bne  0xa00fac20
a00fac98:  80 a6 60 02  cmp  %i1, 2
a00fac9c:  bb 2f 20 04  sll  %i4, 4, %i5
a00faca0:  82 07 40 1c  add  %i5, %i4, %g1
a00faca4:  ba 00 40 18  add  %g1, %i0, %i5
a00faca8:  b8 07 40 1d  add  %i5, %i5, %i4
a00facac:  fa 12 40 1c  lduh  [ %o1 + %i4 ], %i5
a00facb0:  fa 23 40 00  st  %i5, [ %o5 ]
a00facb4:  b8 0b e1 ff  and  %o7, 0x1ff, %i4
a00facb8:  ba 0e fe 00  and  %i3, -512, %i5
a00facbc:  b6 17 40 1c  or  %i5, %i4, %i3
a00facc0:  b4 06 a0 01  inc  %i2
a00facc4:  b8 0e a0 ff  and  %i2, 0xff, %i4
a00facc8:  f6 23 00 00  st  %i3, [ %o4 ]
a00faccc:  80 a7 20 0f  cmp  %i4, 0xf
a00facd0:  08 bf ff ec  bleu  0xa00fac80
a00facd4:  ba 0e a0 ff  and  %i2, 0xff, %i5
a00facd8:  96 02 e0 01  inc  %o3
a00facdc:  b0 0a e0 ff  and  %o3, 0xff, %i0
a00face0:  80 a6 20 10  cmp  %i0, 0x10
a00face4:  08 bf ff cd  bleu  0xa00fac18
a00face8:  b4 10 20 00  clr  %i2
a00facec:  03 34 01 00  sethi  %hi(0xd0040000), %g1
a00facf0:  b0 0e fd ff  and  %i3, -513, %i0
a00facf4:  b2 10 60 b4  or  %g1, 0xb4, %i1
a00facf8:  35 00 40 00  sethi  %hi(0x1000000), %i2
a00facfc:  c0 26 40 00  clr  [ %i1 ]
a00fad00:  b6 2e 00 1a  andn  %i0, %i2, %i3
a00fad04:  f6 23 00 00  st  %i3, [ %o4 ]
a00fad08:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00fad0c:  f8 0b 63 fe  ldub  [ %o5 + 0x3fe ], %i4	! 0xa802b7fe
a00fad10:  80 a7 20 00  cmp  %i4, 0
a00fad14:  12 80 01 91  bne  0xa00fb358
a00fad18:  b2 10 20 01  mov  1, %i1
a00fad1c:  35 34 01 00  sethi  %hi(0xd0040000), %i2
a00fad20:  de 12 22 c0  lduh  [ %o0 + 0x2c0 ], %o7
a00fad24:  b2 16 a0 f4  or  %i2, 0xf4, %i1
a00fad28:  b1 2b e0 10  sll  %o7, 0x10, %i0
a00fad2c:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00fad30:  c2 06 40 00  ld  [ %i1 ], %g1
a00fad34:  f8 13 22 90  lduh  [ %o4 + 0x290 ], %i4
a00fad38:  b7 36 20 12  srl  %i0, 0x12, %i3
a00fad3c:  3b 3f ff c0  sethi  %hi(0xffff0000), %i5
a00fad40:  82 08 40 1d  and  %g1, %i5, %g1
a00fad44:  b1 37 20 02  srl  %i4, 2, %i0
a00fad48:  82 10 40 1b  or  %g1, %i3, %g1
a00fad4c:  b9 2e 20 08  sll  %i0, 8, %i4
a00fad50:  ba 10 40 1c  or  %g1, %i4, %i5
a00fad54:  fa 26 40 00  st  %i5, [ %i1 ]
a00fad58:  b0 16 a0 90  or  %i2, 0x90, %i0
a00fad5c:  f2 06 00 00  ld  [ %i0 ], %i1
a00fad60:  b6 16 a0 94  or  %i2, 0x94, %i3
a00fad64:  da 06 c0 00  ld  [ %i3 ], %o5
a00fad68:  82 16 a0 c4  or  %i2, 0xc4, %g1
a00fad6c:  39 00 00 3f  sethi  %hi(0xfc00), %i4
a00fad70:  f6 00 40 00  ld  [ %g1 ], %i3
a00fad74:  ba 17 23 00  or  %i4, 0x300, %i5
a00fad78:  82 16 a0 c0  or  %i2, 0xc0, %g1
a00fad7c:  ba 0e 40 1d  and  %i1, %i5, %i5
a00fad80:  92 10 00 1a  mov  %i2, %o1
a00fad84:  f0 00 40 00  ld  [ %g1 ], %i0
a00fad88:  b5 37 60 08  srl  %i5, 8, %i2
a00fad8c:  b8 16 20 01  or  %i0, 1, %i4
a00fad90:  98 0e ef 00  and  %i3, 0xf00, %o4
a00fad94:  bb 36 60 18  srl  %i1, 0x18, %i5
a00fad98:  b6 0e e0 f0  and  %i3, 0xf0, %i3
a00fad9c:  31 2a 00 af  sethi  %hi(0xa802bc00), %i0
a00fada0:  f4 2f bf cf  stb  %i2, [ %fp + -49 ]
a00fada4:  fa 2f bf bf  stb  %i5, [ %fp + -65 ]
a00fada8:  f8 20 40 00  st  %i4, [ %g1 ]
a00fadac:  bb 36 60 10  srl  %i1, 0x10, %i5
a00fadb0:  de 36 22 c2  sth  %o7, [ %i0 + 0x2c2 ]
a00fadb4:  91 36 e0 04  srl  %i3, 4, %o0
a00fadb8:  35 2a 00 ad  sethi  %hi(0xa802b400), %i2
a00fadbc:  da 2f bf b7  stb  %o5, [ %fp + -73 ]
a00fadc0:  39 00 00 0f  sethi  %hi(0x3c00), %i4
a00fadc4:  03 2a 00 b1  sethi  %hi(0xa802c400), %g1
a00fadc8:  31 2a 00 b0  sethi  %hi(0xa802c000), %i0
a00fadcc:  f6 06 a3 f4  ld  [ %i2 + 0x3f4 ], %i3
a00fadd0:  fa 2f bf c7  stb  %i5, [ %fp + -57 ]
a00fadd4:  99 33 20 08  srl  %o4, 8, %o4
a00fadd8:  a8 17 23 ff  or  %i4, 0x3ff, %l4
a00faddc:  a4 10 62 1e  or  %g1, 0x21e, %l2
a00fade0:  a6 16 23 de  or  %i0, 0x3de, %l3
a00fade4:  f6 27 bf d4  st  %i3, [ %fp + -44 ]
a00fade8:  9a 10 20 00  clr  %o5
a00fadec:  94 10 20 00  clr  %o2
a00fadf0:  96 10 20 00  clr  %o3
a00fadf4:  c0 2f bf af  clrb  [ %fp + -81 ]
a00fadf8:  c0 37 bf a6  clrh  [ %fp + -90 ]
a00fadfc:  ae 10 00 19  mov  %i1, %l7
a00fae00:  ac 10 20 00  clr  %l6
a00fae04:  ba 10 20 00  clr  %i5
a00fae08:  aa 12 62 cc  or  %o1, 0x2cc, %l5
a00fae0c:  b4 07 40 1d  add  %i5, %i5, %i2
a00fae10:  a0 06 80 1d  add  %i2, %i5, %l0
a00fae14:  b4 10 20 00  clr  %i2
a00fae18:  b8 10 20 00  clr  %i4
a00fae1c:  a3 2c 20 03  sll  %l0, 3, %l1
a00fae20:  b1 2c 20 02  sll  %l0, 2, %i0
a00fae24:  ba 07 00 18  add  %i4, %i0, %i5
a00fae28:  82 12 60 c8  or  %o1, 0xc8, %g1
a00fae2c:  b1 2f 60 10  sll  %i5, 0x10, %i0
a00fae30:  b2 12 60 cc  or  %o1, 0xcc, %i1
a00fae34:  f0 20 40 00  st  %i0, [ %g1 ]
a00fae38:  c2 06 40 00  ld  [ %i1 ], %g1
a00fae3c:  b6 08 63 ff  and  %g1, 0x3ff, %i3
a00fae40:  b3 2e c0 08  sll  %i3, %o0, %i1
a00fae44:  80 a6 63 ff  cmp  %i1, 0x3ff
a00fae48:  08 80 00 03  bleu  0xa00fae54
a00fae4c:  b6 07 00 11  add  %i4, %l1, %i3
a00fae50:  b2 10 23 ff  mov  0x3ff, %i1
a00fae54:  b9 30 60 0a  srl  %g1, 0xa, %i4
a00fae58:  82 0f 00 14  and  %i4, %l4, %g1
a00fae5c:  b9 28 40 0c  sll  %g1, %o4, %i4
a00fae60:  80 a7 23 ff  cmp  %i4, 0x3ff
a00fae64:  38 80 00 02  bgu,a   0xa00fae6c
a00fae68:  b8 10 23 ff  mov  0x3ff, %i4
a00fae6c:  80 a3 40 19  cmp  %o5, %i1
a00fae70:  2a 80 00 02  bcs,a   0xa00fae78
a00fae74:  9a 10 00 19  mov  %i1, %o5
a00fae78:  ba 12 62 c8  or  %o1, 0x2c8, %i5
a00fae7c:  f0 27 40 00  st  %i0, [ %i5 ]
a00fae80:  de 05 40 00  ld  [ %l5 ], %o7
a00fae84:  ba 06 c0 1b  add  %i3, %i3, %i5
a00fae88:  82 0b e3 ff  and  %o7, 0x3ff, %g1
a00fae8c:  b1 28 40 08  sll  %g1, %o0, %i0
a00fae90:  f8 34 c0 1d  sth  %i4, [ %l3 + %i5 ]
a00fae94:  f2 34 80 1d  sth  %i1, [ %l2 + %i5 ]
a00fae98:  96 02 c0 1c  add  %o3, %i4, %o3
a00fae9c:  b2 02 80 19  add  %o2, %i1, %i1
a00faea0:  80 a6 23 ff  cmp  %i0, 0x3ff
a00faea4:  08 80 00 03  bleu  0xa00faeb0
a00faea8:  b8 06 e0 0c  add  %i3, 0xc, %i4
a00faeac:  b0 10 23 ff  mov  0x3ff, %i0
a00faeb0:  83 33 e0 0a  srl  %o7, 0xa, %g1
a00faeb4:  b6 08 40 14  and  %g1, %l4, %i3
a00faeb8:  bb 2e c0 0c  sll  %i3, %o4, %i5
a00faebc:  80 a7 63 ff  cmp  %i5, 0x3ff
a00faec0:  38 80 00 02  bgu,a   0xa00faec8
a00faec4:  ba 10 23 ff  mov  0x3ff, %i5
a00faec8:  80 a3 40 18  cmp  %o5, %i0
a00faecc:  2a 80 00 02  bcs,a   0xa00faed4
a00faed0:  9a 10 00 18  mov  %i0, %o5
a00faed4:  b6 07 00 1c  add  %i4, %i4, %i3
a00faed8:  b4 06 a0 01  inc  %i2
a00faedc:  b8 0e a0 ff  and  %i2, 0xff, %i4
a00faee0:  fa 34 c0 1b  sth  %i5, [ %l3 + %i3 ]
a00faee4:  f0 34 80 1b  sth  %i0, [ %l2 + %i3 ]
a00faee8:  94 06 40 18  add  %i1, %i0, %o2
a00faeec:  80 a7 20 0b  cmp  %i4, 0xb
a00faef0:  08 bf ff cc  bleu  0xa00fae20
a00faef4:  96 02 c0 1d  add  %o3, %i5, %o3
a00faef8:  ac 05 a0 01  inc  %l6
a00faefc:  ba 0d a0 ff  and  %l6, 0xff, %i5
a00faf00:  80 a7 60 0b  cmp  %i5, 0xb
a00faf04:  08 bf ff c3  bleu  0xa00fae10
a00faf08:  b4 07 40 1d  add  %i5, %i5, %i2
a00faf0c:  3b 2a aa aa  sethi  %hi(0xaaaaa800), %i5
a00faf10:  b2 17 62 ab  or  %i5, 0x2ab, %i1	! 0xaaaaaaab
a00faf14:  80 52 80 19  umul  %o2, %i1, %g0
a00faf18:  b9 40 00 00  rd  %y, %i4
a00faf1c:  83 37 20 03  srl  %i4, 3, %g1
a00faf20:  b0 00 40 01  add  %g1, %g1, %i0
a00faf24:  35 34 01 00  sethi  %hi(0xd0040000), %i2
a00faf28:  b8 06 00 01  add  %i0, %g1, %i4
a00faf2c:  b4 16 a0 c0  or  %i2, 0xc0, %i2
a00faf30:  f0 06 80 00  ld  [ %i2 ], %i0
a00faf34:  80 52 c0 19  umul  %o3, %i1, %g0
a00faf38:  b7 40 00 00  rd  %y, %i3
a00faf3c:  82 0e 3f fe  and  %i0, -2, %g1
a00faf40:  d8 0f bf b7  ldub  [ %fp + -73 ], %o4
a00faf44:  bb 36 e0 03  srl  %i3, 3, %i5
a00faf48:  b0 20 00 0c  neg  %o4, %i0
a00faf4c:  b2 07 40 1d  add  %i5, %i5, %i1
a00faf50:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00faf54:  b6 06 40 1d  add  %i1, %i5, %i3
a00faf58:  da 33 22 90  sth  %o5, [ %o4 + 0x290 ]
a00faf5c:  b3 2f 20 03  sll  %i4, 3, %i1
a00faf60:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00faf64:  ba 20 00 17  neg  %l7, %i5
a00faf68:  f2 33 62 8e  sth  %i1, [ %o5 + 0x28e ]
a00faf6c:  c2 26 80 00  st  %g1, [ %i2 ]
a00faf70:  b7 2e e0 03  sll  %i3, 3, %i3
a00faf74:  39 2a 00 9a  sethi  %hi(0xa8026800), %i4
a00faf78:  90 0f 60 ff  and  %i5, 0xff, %o0
a00faf7c:  33 2a 00 b0  sethi  %hi(0xa802c000), %i1
a00faf80:  35 2a 00 9d  sethi  %hi(0xa8027400), %i2
a00faf84:  a2 10 00 13  mov  %l3, %l1
a00faf88:  f6 37 22 8c  sth  %i3, [ %i4 + 0x28c ]
a00faf8c:  a0 0d e0 ff  and  %l7, 0xff, %l0
a00faf90:  da 0f bf b7  ldub  [ %fp + -73 ], %o5
a00faf94:  92 0e 20 ff  and  %i0, 0xff, %o1
a00faf98:  94 16 61 06  or  %i1, 0x106, %o2
a00faf9c:  96 16 a3 58  or  %i2, 0x358, %o3
a00fafa0:  a6 10 20 00  clr  %l3
a00fafa4:  ba 10 20 00  clr  %i5
a00fafa8:  82 07 40 1d  add  %i5, %i5, %g1
a00fafac:  b0 00 40 1d  add  %g1, %i5, %i0
a00fafb0:  99 2e 20 03  sll  %i0, 3, %o4
a00fafb4:  9e 5f 60 1a  smul  %i5, 0x1a, %o7
a00fafb8:  b0 10 20 00  clr  %i0
a00fafbc:  b8 10 20 00  clr  %i4
a00fafc0:  82 07 00 0f  add  %i4, %o7, %g1
a00fafc4:  b4 00 60 1b  add  %g1, 0x1b, %i2
a00fafc8:  b2 07 00 0c  add  %i4, %o4, %i1
a00fafcc:  b4 06 80 1a  add  %i2, %i2, %i2
a00fafd0:  b8 06 40 19  add  %i1, %i1, %i4
a00fafd4:  fa 12 80 1a  lduh  [ %o2 + %i2 ], %i5
a00fafd8:  f6 14 80 1c  lduh  [ %l2 + %i4 ], %i3
a00fafdc:  f2 14 40 1c  lduh  [ %l1 + %i4 ], %i1
a00fafe0:  c2 12 c0 1a  lduh  [ %o3 + %i2 ], %g1
a00fafe4:  ba 5c 00 1d  smul  %l0, %i5, %i5
a00fafe8:  b6 5a 00 1b  smul  %o0, %i3, %i3
a00fafec:  b8 07 40 1b  add  %i5, %i3, %i4
a00faff0:  b2 5a 40 19  smul  %o1, %i1, %i1
a00faff4:  82 5b 40 01  smul  %o5, %g1, %g1
a00faff8:  82 00 40 19  add  %g1, %i1, %g1
a00faffc:  ba 07 20 80  add  %i4, 0x80, %i5
a00fb000:  b8 00 60 80  add  %g1, 0x80, %i4
a00fb004:  b3 3f 20 08  sra  %i4, 8, %i1
a00fb008:  b0 06 20 01  inc  %i0
a00fb00c:  b7 3f 60 08  sra  %i5, 8, %i3
a00fb010:  b8 0e 20 ff  and  %i0, 0xff, %i4
a00fb014:  f2 32 c0 1a  sth  %i1, [ %o3 + %i2 ]
a00fb018:  80 a7 20 17  cmp  %i4, 0x17
a00fb01c:  08 bf ff e9  bleu  0xa00fafc0
a00fb020:  f6 32 80 1a  sth  %i3, [ %o2 + %i2 ]
a00fb024:  a6 04 e0 01  inc  %l3
a00fb028:  ba 0c e0 ff  and  %l3, 0xff, %i5
a00fb02c:  80 a7 60 0b  cmp  %i5, 0xb
a00fb030:  28 bf ff df  bleu,a   0xa00fafac
a00fb034:  82 07 40 1d  add  %i5, %i5, %g1
a00fb038:  e6 0f bf c7  ldub  [ %fp + -57 ], %l3
a00fb03c:  e8 0f bf bf  ldub  [ %fp + -65 ], %l4
a00fb040:  b4 04 c0 13  add  %l3, %l3, %i2
a00fb044:  b6 06 80 13  add  %i2, %l3, %i3
a00fb048:  b0 04 c0 14  add  %l3, %l4, %i0
a00fb04c:  82 05 00 14  add  %l4, %l4, %g1
a00fb050:  b8 06 c0 01  add  %i3, %g1, %i4
a00fb054:  bb 2e 20 02  sll  %i0, 2, %i5
a00fb058:  b2 06 80 14  add  %i2, %l4, %i1
a00fb05c:  37 2a 00 b0  sethi  %hi(0xa802c000), %i3
a00fb060:  b0 10 20 01  mov  1, %i0
a00fb064:  f8 27 bf 98  st  %i4, [ %fp + -104 ]
a00fb068:  fa 27 bf 94  st  %i5, [ %fp + -108 ]
a00fb06c:  f2 27 bf 9c  st  %i1, [ %fp + -100 ]
a00fb070:  f2 27 bf d8  st  %i1, [ %fp + -40 ]
a00fb074:  f8 27 bf dc  st  %i4, [ %fp + -36 ]
a00fb078:  fa 27 bf e0  st  %i5, [ %fp + -32 ]
a00fb07c:  d4 0f bf cf  ldub  [ %fp + -49 ], %o2
a00fb080:  a4 16 e1 06  or  %i3, 0x106, %l2
a00fb084:  f0 2f bf 8f  stb  %i0, [ %fp + -113 ]
a00fb088:  a0 10 20 01  mov  1, %l0
a00fb08c:  a2 07 bf f8  add  %fp, -8, %l1
a00fb090:  82 1c 20 01  xor  %l0, 1, %g1
a00fb094:  80 a0 00 01  cmp  %g0, %g1
a00fb098:  b2 1c 20 0c  xor  %l0, 0xc, %i1
a00fb09c:  b4 60 3f ff  subx  %g0, -1, %i2
a00fb0a0:  80 a0 00 19  cmp  %g0, %i1
a00fb0a4:  b0 60 3f ff  subx  %g0, -1, %i0
a00fb0a8:  80 a0 00 01  cmp  %g0, %g1
a00fb0ac:  b8 40 20 00  addx  %g0, 0, %i4
a00fb0b0:  80 a0 00 19  cmp  %g0, %i1
a00fb0b4:  b6 04 00 10  add  %l0, %l0, %i3
a00fb0b8:  b2 06 c0 10  add  %i3, %l0, %i1
a00fb0bc:  ba 40 20 00  addx  %g0, 0, %i5
a00fb0c0:  ac 16 80 18  or  %i2, %i0, %l6
a00fb0c4:  ae 0f 00 1d  and  %i4, %i5, %l7
a00fb0c8:  ab 2e 60 03  sll  %i1, 3, %l5
a00fb0cc:  92 10 20 01  mov  1, %o1
a00fb0d0:  98 10 20 01  mov  1, %o4
a00fb0d4:  b8 03 00 15  add  %o4, %l5, %i4
a00fb0d8:  ba 5c 20 1a  smul  %l0, 0x1a, %i5
a00fb0dc:  90 07 3f e7  add  %i4, -25, %o0
a00fb0e0:  80 a3 20 01  cmp  %o4, 1
a00fb0e4:  02 80 00 a2  be  0xa00fb36c
a00fb0e8:  82 03 00 1d  add  %o4, %i5, %g1
a00fb0ec:  fa 0f bf af  ldub  [ %fp + -81 ], %i5
a00fb0f0:  9a 07 60 01  add  %i5, 1, %o5
a00fb0f4:  b6 0b 60 ff  and  %o5, 0xff, %i3
a00fb0f8:  b4 06 e0 02  add  %i3, 2, %i2
a00fb0fc:  b0 0e a0 03  and  %i2, 3, %i0
a00fb100:  96 00 40 01  add  %g1, %g1, %o3
a00fb104:  b4 02 c0 12  add  %o3, %l2, %i2
a00fb108:  b8 06 e0 01  add  %i3, 1, %i4
a00fb10c:  c2 16 a0 36  lduh  [ %i2 + 0x36 ], %g1
a00fb110:  bb 2e 20 02  sll  %i0, 2, %i5
a00fb114:  f2 16 bf ce  lduh  [ %i2 + -50 ], %i1
a00fb118:  b2 06 40 01  add  %i1, %g1, %i1
a00fb11c:  b0 0f 20 03  and  %i4, 3, %i0
a00fb120:  b6 0e e0 03  and  %i3, 3, %i3
a00fb124:  ba 07 40 11  add  %i5, %l1, %i5
a00fb128:  f2 27 7f f0  st  %i1, [ %i5 + -16 ]
a00fb12c:  b9 2e 20 02  sll  %i0, 2, %i4
a00fb130:  83 2e e0 02  sll  %i3, 2, %g1
a00fb134:  f0 16 a0 02  lduh  [ %i2 + 2 ], %i0
a00fb138:  b6 00 40 11  add  %g1, %l1, %i3
a00fb13c:  fa 16 bf fe  lduh  [ %i2 + -2 ], %i5
a00fb140:  b8 07 00 11  add  %i4, %l1, %i4
a00fb144:  82 07 40 18  add  %i5, %i0, %g1
a00fb148:  f4 07 3f f0  ld  [ %i4 + -16 ], %i2
a00fb14c:  fa 06 ff f0  ld  [ %i3 + -16 ], %i5
a00fb150:  b0 00 40 1a  add  %g1, %i2, %i0
a00fb154:  b6 07 40 19  add  %i5, %i1, %i3
a00fb158:  b8 5e 00 13  smul  %i0, %l3, %i4
a00fb15c:  ba 5e c0 14  smul  %i3, %l4, %i5
a00fb160:  da 2f bf af  stb  %o5, [ %fp + -81 ]
a00fb164:  ba 07 00 1d  add  %i4, %i5, %i5
a00fb168:  c2 14 80 0b  lduh  [ %l2 + %o3 ], %g1
a00fb16c:  b2 58 40 0a  smul  %g1, %o2, %i1
a00fb170:  80 a5 a0 00  cmp  %l6, 0
a00fb174:  02 80 00 0b  be  0xa00fb1a0
a00fb178:  b4 07 40 19  add  %i5, %i1, %i2
a00fb17c:  ba 1b 20 01  xor  %o4, 1, %i5
a00fb180:  80 a0 00 1d  cmp  %g0, %i5
a00fb184:  b8 60 3f ff  subx  %g0, -1, %i4
a00fb188:  b0 1b 20 18  xor  %o4, 0x18, %i0
a00fb18c:  80 a0 00 18  cmp  %g0, %i0
a00fb190:  b6 60 3f ff  subx  %g0, -1, %i3
a00fb194:  80 97 00 1b  orcc  %i4, %i3, %g0
a00fb198:  12 80 00 0e  bne  0xa00fb1d0
a00fb19c:  c2 07 bf 9c  ld  [ %fp + -100 ], %g1
a00fb1a0:  80 a5 e0 00  cmp  %l7, 0
a00fb1a4:  22 80 00 0b  be,a   0xa00fb1d0
a00fb1a8:  c2 07 bf 98  ld  [ %fp + -104 ], %g1
a00fb1ac:  b8 1b 20 01  xor  %o4, 1, %i4
a00fb1b0:  80 a0 00 1c  cmp  %g0, %i4
a00fb1b4:  b6 40 20 00  addx  %g0, 0, %i3
a00fb1b8:  82 1b 20 18  xor  %o4, 0x18, %g1
a00fb1bc:  80 a0 00 01  cmp  %g0, %g1
a00fb1c0:  b2 40 20 00  addx  %g0, 0, %i1
a00fb1c4:  80 8e c0 19  btst  %i3, %i1
a00fb1c8:  02 80 00 67  be  0xa00fb364
a00fb1cc:  c2 07 bf 94  ld  [ %fp + -108 ], %g1
a00fb1d0:  82 80 40 0a  addcc  %g1, %o2, %g1
a00fb1d4:  22 80 00 02  be,a   0xa00fb1dc
a00fb1d8:  82 10 20 01  mov  1, %g1
a00fb1dc:  81 80 00 00  mov  %g0, %y
a00fb1e0:  01 00 00 00  nop
a00fb1e4:  01 00 00 00  nop
a00fb1e8:  01 00 00 00  nop
a00fb1ec:  b4 76 80 01  udiv  %i2, %g1, %i2
a00fb1f0:  80 a6 a3 ff  cmp  %i2, 0x3ff
a00fb1f4:  08 80 00 03  bleu  0xa00fb200
a00fb1f8:  b8 02 00 08  add  %o0, %o0, %i4
a00fb1fc:  b4 10 23 ff  mov  0x3ff, %i2
a00fb200:  c2 17 bf a6  lduh  [ %fp + -90 ], %g1
a00fb204:  3b 2a 00 af  sethi  %hi(0xa802bc00), %i5
a00fb208:  31 2a 00 af  sethi  %hi(0xa802bc00), %i0
a00fb20c:  b3 28 60 10  sll  %g1, 0x10, %i1
a00fb210:  b7 2e a0 10  sll  %i2, 0x10, %i3
a00fb214:  98 17 60 80  or  %i5, 0x80, %o4
a00fb218:  9a 16 22 c6  or  %i0, 0x2c6, %o5
a00fb21c:  80 a6 c0 19  cmp  %i3, %i1
a00fb220:  f4 33 00 1c  sth  %i2, [ %o4 + %i4 ]
a00fb224:  08 80 00 03  bleu  0xa00fb230
a00fb228:  f4 33 40 1c  sth  %i2, [ %o5 + %i4 ]
a00fb22c:  f4 37 bf a6  sth  %i2, [ %fp + -90 ]
a00fb230:  92 02 60 01  inc  %o1
a00fb234:  98 0a 60 ff  and  %o1, 0xff, %o4
a00fb238:  80 a3 20 18  cmp  %o4, 0x18
a00fb23c:  08 bf ff a7  bleu  0xa00fb0d8
a00fb240:  b8 03 00 15  add  %o4, %l5, %i4
a00fb244:  f8 0f bf 8f  ldub  [ %fp + -113 ], %i4
a00fb248:  b4 07 20 01  add  %i4, 1, %i2
a00fb24c:  a0 0e a0 ff  and  %i2, 0xff, %l0
a00fb250:  80 a4 20 0c  cmp  %l0, 0xc
a00fb254:  08 bf ff 8f  bleu  0xa00fb090
a00fb258:  f4 2f bf 8f  stb  %i2, [ %fp + -113 ]
a00fb25c:  31 2a 00 9d  sethi  %hi(0xa8027400), %i0
a00fb260:  d8 17 bf a6  lduh  [ %fp + -90 ], %o4
a00fb264:  d8 36 23 56  sth  %o4, [ %i0 + 0x356 ]
a00fb268:  1f 2a 00 af  sethi  %hi(0xa802bc00), %o7
a00fb26c:  3b 3f bf ff  sethi  %hi(0xfefffc00), %i5
a00fb270:  15 34 01 00  sethi  %hi(0xd0040000), %o2
a00fb274:  b0 17 63 ff  or  %i5, 0x3ff, %i0
a00fb278:  9e 13 e0 80  or  %o7, 0x80, %o7
a00fb27c:  98 10 20 00  clr  %o4
a00fb280:  ba 10 20 00  clr  %i5
a00fb284:  9a 12 a0 a4  or  %o2, 0xa4, %o5
a00fb288:  96 12 a0 a0  or  %o2, 0xa0, %o3
a00fb28c:  b6 07 40 1d  add  %i5, %i5, %i3
a00fb290:  b2 06 c0 1d  add  %i3, %i5, %i1
a00fb294:  b5 2e 60 03  sll  %i1, 3, %i2
a00fb298:  b6 10 20 00  clr  %i3
a00fb29c:  b2 0e e0 ff  and  %i3, 0xff, %i1
a00fb2a0:  b8 06 80 19  add  %i2, %i1, %i4
a00fb2a4:  83 2f 20 10  sll  %i4, 0x10, %g1
a00fb2a8:  b3 30 60 10  srl  %g1, 0x10, %i1
a00fb2ac:  ba 06 40 19  add  %i1, %i1, %i5
a00fb2b0:  f8 13 c0 1d  lduh  [ %o7 + %i5 ], %i4
a00fb2b4:  ba 16 62 00  or  %i1, 0x200, %i5
a00fb2b8:  b6 06 e0 01  inc  %i3
a00fb2bc:  f8 23 40 00  st  %i4, [ %o5 ]
a00fb2c0:  b2 0f 40 18  and  %i5, %i0, %i1
a00fb2c4:  82 0e e0 ff  and  %i3, 0xff, %g1
a00fb2c8:  80 a0 60 17  cmp  %g1, 0x17
a00fb2cc:  f2 22 c0 00  st  %i1, [ %o3 ]
a00fb2d0:  28 bf ff f4  bleu,a   0xa00fb2a0
a00fb2d4:  b2 0e e0 ff  and  %i3, 0xff, %i1
a00fb2d8:  98 03 20 01  inc  %o4
a00fb2dc:  ba 0b 20 ff  and  %o4, 0xff, %i5
a00fb2e0:  80 a7 60 0b  cmp  %i5, 0xb
a00fb2e4:  08 bf ff eb  bleu  0xa00fb290
a00fb2e8:  b6 07 40 1d  add  %i5, %i5, %i3
a00fb2ec:  31 2a 00 ad  sethi  %hi(0xa802b400), %i0
a00fb2f0:  f6 06 23 f4  ld  [ %i0 + 0x3f4 ], %i3	! 0xa802b7f4
a00fb2f4:  39 2a 00 9a  sethi  %hi(0xa8026800), %i4
a00fb2f8:  f0 17 22 8c  lduh  [ %i4 + 0x28c ], %i0	! 0xa8026a8c
a00fb2fc:  c2 07 bf d4  ld  [ %fp + -44 ], %g1
a00fb300:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00fb304:  ba 26 c0 01  sub  %i3, %g1, %i5
a00fb308:  f8 16 a2 8e  lduh  [ %i2 + 0x28e ], %i4
a00fb30c:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00fb310:  f4 0b 23 fe  ldub  [ %o4 + 0x3fe ], %i2	! 0xa802b7fe
a00fb314:  b6 0f 60 ff  and  %i5, 0xff, %i3
a00fb318:  83 2e 20 0c  sll  %i0, 0xc, %g1
a00fb31c:  b0 17 00 01  or  %i4, %g1, %i0
a00fb320:  ba 10 20 0f  mov  0xf, %i5
a00fb324:  b5 2e a0 18  sll  %i2, 0x18, %i2
a00fb328:  82 27 40 1b  sub  %i5, %i3, %g1
a00fb32c:  b8 16 00 1a  or  %i0, %i2, %i4
a00fb330:  c0 23 40 00  clr  [ %o5 ]
a00fb334:  b0 0e 7d ff  and  %i1, -513, %i0
a00fb338:  bb 28 60 1c  sll  %g1, 0x1c, %i5
a00fb33c:  f0 22 c0 00  st  %i0, [ %o3 ]
a00fb340:  82 17 00 1d  or  %i4, %i5, %g1
a00fb344:  b6 12 a0 fc  or  %o2, 0xfc, %i3
a00fb348:  c2 26 c0 00  st  %g1, [ %i3 ]
a00fb34c:  35 2a 00 b2  sethi  %hi(0xa802c800), %i2
a00fb350:  f0 26 a0 60  st  %i0, [ %i2 + 0x60 ]	! 0xa802c860
a00fb354:  b2 10 20 01  mov  1, %i1
a00fb358:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00fb35c:  10 80 00 32  b  0xa00fb424
a00fb360:  f2 2b 63 f0  stb  %i1, [ %o5 + 0x3f0 ]	! 0xa802b7f0
a00fb364:  10 bf ff 9b  b  0xa00fb1d0
a00fb368:  c2 07 bf 98  ld  [ %fp + -104 ], %g1
a00fb36c:  96 00 40 01  add  %g1, %g1, %o3
a00fb370:  82 02 c0 12  add  %o3, %l2, %g1
a00fb374:  f0 10 60 34  lduh  [ %g1 + 0x34 ], %i0
a00fb378:  f6 10 7f cc  lduh  [ %g1 + -52 ], %i3
a00fb37c:  f2 10 60 36  lduh  [ %g1 + 0x36 ], %i1
a00fb380:  b6 06 c0 18  add  %i3, %i0, %i3
a00fb384:  f8 10 7f ce  lduh  [ %g1 + -50 ], %i4
a00fb388:  fa 10 7f fe  lduh  [ %g1 + -2 ], %i5
a00fb38c:  b0 07 00 19  add  %i4, %i1, %i0
a00fb390:  da 10 60 02  lduh  [ %g1 + 2 ], %o5
a00fb394:  f4 10 7f ca  lduh  [ %g1 + -54 ], %i2
a00fb398:  de 10 60 32  lduh  [ %g1 + 0x32 ], %o7
a00fb39c:  b4 06 80 0f  add  %i2, %o7, %i2
a00fb3a0:  b2 07 40 0d  add  %i5, %o5, %i1
a00fb3a4:  ba 06 40 1b  add  %i1, %i3, %i5
a00fb3a8:  82 06 80 18  add  %i2, %i0, %g1
a00fb3ac:  b2 5f 40 13  smul  %i5, %l3, %i1
a00fb3b0:  82 58 40 14  smul  %g1, %l4, %g1
a00fb3b4:  ba 06 40 01  add  %i1, %g1, %i5
a00fb3b8:  f4 3f bf e8  std  %i2, [ %fp + -24 ]
a00fb3bc:  f0 27 bf f0  st  %i0, [ %fp + -16 ]
a00fb3c0:  10 bf ff 6a  b  0xa00fb168
a00fb3c4:  c0 2f bf af  clrb  [ %fp + -81 ]
a00fb3c8:  83 2f 20 04  sll  %i4, 4, %g1
a00fb3cc:  ba 00 40 1c  add  %g1, %i4, %i5
a00fb3d0:  82 07 40 18  add  %i5, %i0, %g1
a00fb3d4:  b8 00 40 01  add  %g1, %g1, %i4
a00fb3d8:  10 bf fe 1f  b  0xa00fac54
a00fb3dc:  fa 14 00 1c  lduh  [ %l0 + %i4 ], %i5
a00fb3e0:  bb 2f 20 04  sll  %i4, 4, %i5
a00fb3e4:  82 07 40 1c  add  %i5, %i4, %g1
a00fb3e8:  ba 00 40 18  add  %g1, %i0, %i5
a00fb3ec:  b8 07 40 1d  add  %i5, %i5, %i4
a00fb3f0:  10 bf fe 19  b  0xa00fac54
a00fb3f4:  fa 14 40 1c  lduh  [ %l1 + %i4 ], %i5
a00fb3f8:  83 2f 20 04  sll  %i4, 4, %g1
a00fb3fc:  ba 00 40 1c  add  %g1, %i4, %i5
a00fb400:  82 07 40 18  add  %i5, %i0, %g1
a00fb404:  b8 00 40 01  add  %g1, %g1, %i4
a00fb408:  10 bf fe 13  b  0xa00fac54
a00fb40c:  fa 14 80 1c  lduh  [ %l2 + %i4 ], %i5
a00fb410:  82 07 40 1c  add  %i5, %i4, %g1
a00fb414:  ba 00 40 18  add  %g1, %i0, %i5
a00fb418:  b8 07 40 1d  add  %i5, %i5, %i4
a00fb41c:  10 bf fe 0e  b  0xa00fac54
a00fb420:  fa 14 c0 1c  lduh  [ %l3 + %i4 ], %i5
a00fb424:  3b 2a 00 af  sethi  %hi(0xa802bc00), %i5
a00fb428:  c0 2f 62 c4  clrb  [ %i5 + 0x2c4 ]	! 0xa802bec4
a00fb42c:  81 c7 e0 08  ret
a00fb430:  81 e8 00 00  restore
