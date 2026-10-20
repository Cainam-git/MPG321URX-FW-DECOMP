# leon2s FUN_a008686c 0xa008686c-0xa0086bd8 (876 bytes)
a008686c:  9d e3 bf 88  save  %sp, -120, %sp
a0086870:  9a 10 20 00  clr  %o5
a0086874:  98 10 20 00  clr  %o4
a0086878:  a2 0e 20 ff  and  %i0, 0xff, %l1
a008687c:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0086880:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0086884:  aa 07 bf e8  add  %fp, -24, %l5
a0086888:  98 10 00 15  mov  %l5, %o4
a008688c:  90 10 00 11  mov  %l1, %o0
a0086890:  92 10 20 90  mov  0x90, %o1
a0086894:  94 10 20 00  clr  %o2
a0086898:  7f ff fe da  call  0xa0086400
a008689c:  96 10 20 0f  mov  0xf, %o3
a00868a0:  9a 04 40 11  add  %l1, %l1, %o5
a00868a4:  9a 03 40 11  add  %o5, %l1, %o5
a00868a8:  27 2a 01 f3  sethi  %hi(0xa807cc00), %l3
a00868ac:  9a 03 40 0d  add  %o5, %o5, %o5
a00868b0:  82 14 e1 2e  or  %l3, 0x12e, %g1
a00868b4:  a0 03 40 01  add  %o5, %g1, %l0
a00868b8:  d8 0f bf f6  ldub  [ %fp + -10 ], %o4
a00868bc:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00868c0:  c2 2c 20 01  stb  %g1, [ %l0 + 1 ]
a00868c4:  c2 0f bf e9  ldub  [ %fp + -23 ], %g1
a00868c8:  c2 2c 20 02  stb  %g1, [ %l0 + 2 ]
a00868cc:  c2 0f bf ea  ldub  [ %fp + -22 ], %g1
a00868d0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00868d4:  80 a0 00 08  cmp  %g0, %o0
a00868d8:  c2 2c 20 03  stb  %g1, [ %l0 + 3 ]
a00868dc:  a4 40 20 00  addx  %g0, 0, %l2
a00868e0:  c2 0f bf eb  ldub  [ %fp + -21 ], %g1
a00868e4:  9a 0b 20 7f  and  %o4, 0x7f, %o5
a00868e8:  c2 2c 20 04  stb  %g1, [ %l0 + 4 ]
a00868ec:  da 2c 20 05  stb  %o5, [ %l0 + 5 ]
a00868f0:  80 8b 20 80  btst  0x80, %o4
a00868f4:  02 80 00 25  be  0xa0086988
a00868f8:  a8 10 00 12  mov  %l2, %l4
a00868fc:  15 00 00 08  sethi  %hi(0x2000), %o2
a0086900:  96 10 20 0f  mov  0xf, %o3
a0086904:  98 10 00 15  mov  %l5, %o4
a0086908:  94 12 a2 00  or  %o2, 0x200, %o2
a008690c:  90 10 00 11  mov  %l1, %o0
a0086910:  7f ff fe bc  call  0xa0086400
a0086914:  92 10 20 90  mov  0x90, %o1
a0086918:  90 0a 20 ff  and  %o0, 0xff, %o0
a008691c:  80 a0 00 08  cmp  %g0, %o0
a0086920:  d6 0f bf e8  ldub  [ %fp + -24 ], %o3
a0086924:  98 60 20 00  subx  %g0, 0, %o4
a0086928:  9a 0a e0 ff  and  %o3, 0xff, %o5
a008692c:  c2 0c 20 01  ldub  [ %l0 + 1 ], %g1
a0086930:  80 a3 40 01  cmp  %o5, %g1
a0086934:  08 80 00 03  bleu  0xa0086940
a0086938:  a8 0c 80 0c  and  %l2, %o4, %l4
a008693c:  d6 2c 20 01  stb  %o3, [ %l0 + 1 ]
a0086940:  d8 0f bf e9  ldub  [ %fp + -23 ], %o4
a0086944:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0086948:  c2 0c 20 02  ldub  [ %l0 + 2 ], %g1
a008694c:  80 a3 40 01  cmp  %o5, %g1
a0086950:  38 80 00 02  bgu,a   0xa0086958
a0086954:  d8 2c 20 02  stb  %o4, [ %l0 + 2 ]
a0086958:  d8 0f bf ea  ldub  [ %fp + -22 ], %o4
a008695c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0086960:  c2 0c 20 03  ldub  [ %l0 + 3 ], %g1
a0086964:  80 a3 40 01  cmp  %o5, %g1
a0086968:  38 80 00 02  bgu,a   0xa0086970
a008696c:  d8 2c 20 03  stb  %o4, [ %l0 + 3 ]
a0086970:  d8 0f bf f6  ldub  [ %fp + -10 ], %o4
a0086974:  9a 0b 20 7f  and  %o4, 0x7f, %o5
a0086978:  c2 0c 20 05  ldub  [ %l0 + 5 ], %g1
a008697c:  80 a3 40 01  cmp  %o5, %g1
a0086980:  34 80 00 02  bg,a   0xa0086988
a0086984:  d8 2c 20 05  stb  %o4, [ %l0 + 5 ]
a0086988:  82 04 40 11  add  %l1, %l1, %g1
a008698c:  82 00 40 11  add  %g1, %l1, %g1
a0086990:  82 00 40 01  add  %g1, %g1, %g1
a0086994:  9a 14 e1 2e  or  %l3, 0x12e, %o5
a0086998:  96 00 40 0d  add  %g1, %o5, %o3
a008699c:  c2 0a e0 02  ldub  [ %o3 + 2 ], %g1
a00869a0:  82 00 7f e1  add  %g1, -31, %g1
a00869a4:  82 08 60 ff  and  %g1, 0xff, %g1
a00869a8:  80 a0 60 09  cmp  %g1, 9
a00869ac:  38 80 00 05  bgu,a   0xa00869c0
a00869b0:  d8 0a e0 02  ldub  [ %o3 + 2 ], %o4
a00869b4:  82 10 20 1e  mov  0x1e, %g1
a00869b8:  c2 2a e0 02  stb  %g1, [ %o3 + 2 ]
a00869bc:  d8 0a e0 02  ldub  [ %o3 + 2 ], %o4
a00869c0:  82 1b 20 06  xor  %o4, 6, %g1
a00869c4:  80 a0 00 01  cmp  %g0, %g1
a00869c8:  9a 40 20 00  addx  %g0, 0, %o5
a00869cc:  82 1b 20 0a  xor  %o4, 0xa, %g1
a00869d0:  80 a0 00 01  cmp  %g0, %g1
a00869d4:  82 40 20 00  addx  %g0, 0, %g1
a00869d8:  80 8b 40 01  btst  %o5, %g1
a00869dc:  22 80 00 0b  be,a   0xa0086a08
a00869e0:  82 04 40 11  add  %l1, %l1, %g1
a00869e4:  80 a3 20 14  cmp  %o4, 0x14
a00869e8:  02 80 00 07  be  0xa0086a04
a00869ec:  80 a3 20 1e  cmp  %o4, 0x1e
a00869f0:  22 80 00 06  be,a   0xa0086a08
a00869f4:  82 04 40 11  add  %l1, %l1, %g1
a00869f8:  82 10 20 06  mov  6, %g1
a00869fc:  c2 2a e0 02  stb  %g1, [ %o3 + 2 ]
a0086a00:  a8 10 20 00  clr  %l4
a0086a04:  82 04 40 11  add  %l1, %l1, %g1
a0086a08:  82 00 40 11  add  %g1, %l1, %g1
a0086a0c:  9a 00 40 01  add  %g1, %g1, %o5
a0086a10:  98 14 e1 2e  or  %l3, 0x12e, %o4
a0086a14:  82 03 40 0c  add  %o5, %o4, %g1
a0086a18:  c2 48 60 03  ldsb  [ %g1 + 3 ], %g1
a0086a1c:  80 a0 60 00  cmp  %g1, 0
a0086a20:  16 80 00 04  bge  0xa0086a30
a0086a24:  c2 0b 00 0d  ldub  [ %o4 + %o5 ], %g1
a0086a28:  10 80 00 03  b  0xa0086a34
a0086a2c:  82 10 60 10  or  %g1, 0x10, %g1
a0086a30:  82 08 7f ef  and  %g1, -17, %g1
a0086a34:  c2 2b 00 0d  stb  %g1, [ %o4 + %o5 ]
a0086a38:  82 04 40 11  add  %l1, %l1, %g1
a0086a3c:  82 00 40 11  add  %g1, %l1, %g1
a0086a40:  9a 00 40 01  add  %g1, %g1, %o5
a0086a44:  98 14 e1 2e  or  %l3, 0x12e, %o4
a0086a48:  82 03 40 0c  add  %o5, %o4, %g1
a0086a4c:  c2 08 60 03  ldub  [ %g1 + 3 ], %g1
a0086a50:  80 88 60 40  btst  0x40, %g1
a0086a54:  02 80 00 04  be  0xa0086a64
a0086a58:  c2 0b 00 0d  ldub  [ %o4 + %o5 ], %g1
a0086a5c:  10 80 00 03  b  0xa0086a68
a0086a60:  82 10 60 40  or  %g1, 0x40, %g1
a0086a64:  82 08 7f bf  and  %g1, -65, %g1
a0086a68:  c2 2b 00 0d  stb  %g1, [ %o4 + %o5 ]
a0086a6c:  82 04 40 11  add  %l1, %l1, %g1
a0086a70:  82 00 40 11  add  %g1, %l1, %g1
a0086a74:  9a 00 40 01  add  %g1, %g1, %o5
a0086a78:  98 14 e1 2e  or  %l3, 0x12e, %o4
a0086a7c:  82 03 40 0c  add  %o5, %o4, %g1
a0086a80:  c2 48 60 04  ldsb  [ %g1 + 4 ], %g1
a0086a84:  80 a0 60 00  cmp  %g1, 0
a0086a88:  16 80 00 04  bge  0xa0086a98
a0086a8c:  c2 0b 00 0d  ldub  [ %o4 + %o5 ], %g1
a0086a90:  10 80 00 03  b  0xa0086a9c
a0086a94:  82 10 60 20  or  %g1, 0x20, %g1
a0086a98:  82 08 7f df  and  %g1, -33, %g1
a0086a9c:  c2 2b 00 0d  stb  %g1, [ %o4 + %o5 ]
a0086aa0:  82 04 40 11  add  %l1, %l1, %g1
a0086aa4:  82 00 40 11  add  %g1, %l1, %g1
a0086aa8:  82 00 40 01  add  %g1, %g1, %g1
a0086aac:  9a 14 e1 2e  or  %l3, 0x12e, %o5
a0086ab0:  98 00 40 0d  add  %g1, %o5, %o4
a0086ab4:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a0086ab8:  9a 0b 60 1f  and  %o5, 0x1f, %o5
a0086abc:  82 03 7f ff  add  %o5, -1, %g1
a0086ac0:  82 08 60 ff  and  %g1, 0xff, %g1
a0086ac4:  80 a0 60 01  cmp  %g1, 1
a0086ac8:  da 2b 20 03  stb  %o5, [ %o4 + 3 ]
a0086acc:  82 10 00 0d  mov  %o5, %g1
a0086ad0:  18 80 00 03  bgu  0xa0086adc
a0086ad4:  9a 10 20 01  mov  1, %o5
a0086ad8:  9a 10 20 00  clr  %o5
a0086adc:  82 08 60 ff  and  %g1, 0xff, %g1
a0086ae0:  82 18 60 04  xor  %g1, 4, %g1
a0086ae4:  80 a0 00 01  cmp  %g0, %g1
a0086ae8:  82 40 20 00  addx  %g0, 0, %g1
a0086aec:  80 8b 40 01  btst  %o5, %g1
a0086af0:  22 80 00 06  be,a   0xa0086b08
a0086af4:  da 0b 20 05  ldub  [ %o4 + 5 ], %o5
a0086af8:  82 10 20 01  mov  1, %g1
a0086afc:  c2 2b 20 03  stb  %g1, [ %o4 + 3 ]
a0086b00:  a8 10 20 00  clr  %l4
a0086b04:  da 0b 20 05  ldub  [ %o4 + 5 ], %o5
a0086b08:  82 03 7f ff  add  %o5, -1, %g1
a0086b0c:  82 08 60 ff  and  %g1, 0xff, %g1
a0086b10:  80 a0 60 03  cmp  %g1, 3
a0086b14:  38 80 00 03  bgu,a   0xa0086b20
a0086b18:  82 10 20 01  mov  1, %g1
a0086b1c:  83 2b 60 02  sll  %o5, 2, %g1
a0086b20:  c2 2b 20 05  stb  %g1, [ %o4 + 5 ]
a0086b24:  c2 0f bf ef  ldub  [ %fp + -17 ], %g1
a0086b28:  80 88 60 40  btst  0x40, %g1
a0086b2c:  02 80 00 08  be  0xa0086b4c
a0086b30:  82 04 40 11  add  %l1, %l1, %g1
a0086b34:  82 00 40 11  add  %g1, %l1, %g1
a0086b38:  98 14 e1 2e  or  %l3, 0x12e, %o4
a0086b3c:  82 00 40 01  add  %g1, %g1, %g1
a0086b40:  da 0b 00 01  ldub  [ %o4 + %g1 ], %o5
a0086b44:  10 80 00 07  b  0xa0086b60
a0086b48:  9a 13 60 08  or  %o5, 8, %o5
a0086b4c:  82 00 40 11  add  %g1, %l1, %g1
a0086b50:  98 14 e1 2e  or  %l3, 0x12e, %o4
a0086b54:  82 00 40 01  add  %g1, %g1, %g1
a0086b58:  da 0b 00 01  ldub  [ %o4 + %g1 ], %o5
a0086b5c:  9a 0b 7f f7  and  %o5, -9, %o5
a0086b60:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0086b64:  da 2b 00 01  stb  %o5, [ %o4 + %g1 ]
a0086b68:  96 10 00 15  mov  %l5, %o3
a0086b6c:  94 10 20 21  mov  0x21, %o2
a0086b70:  90 10 00 10  mov  %l0, %o0
a0086b74:  7f ff fe 0a  call  0xa008639c
a0086b78:  92 10 20 90  mov  0x90, %o1
a0086b7c:  96 04 00 10  add  %l0, %l0, %o3
a0086b80:  96 02 c0 10  add  %o3, %l0, %o3
a0086b84:  15 2a 01 f3  sethi  %hi(0xa807cc00), %o2
a0086b88:  d8 0f bf e8  ldub  [ %fp + -24 ], %o4
a0086b8c:  94 12 a1 2e  or  %o2, 0x12e, %o2
a0086b90:  96 02 c0 0b  add  %o3, %o3, %o3
a0086b94:  c2 0a 80 0b  ldub  [ %o2 + %o3 ], %g1
a0086b98:  9a 0b 20 01  and  %o4, 1, %o5
a0086b9c:  9b 2b 60 02  sll  %o5, 2, %o5
a0086ba0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0086ba4:  82 08 7f f9  and  %g1, -7, %g1
a0086ba8:  82 10 40 0d  or  %g1, %o5, %g1
a0086bac:  80 a0 00 08  cmp  %g0, %o0
a0086bb0:  9a 40 3f ff  addx  %g0, -1, %o5
a0086bb4:  98 0b 20 02  and  %o4, 2, %o4
a0086bb8:  9a 0b 40 14  and  %o5, %l4, %o5
a0086bbc:  82 10 40 0c  or  %g1, %o4, %g1
a0086bc0:  9b 2b 60 07  sll  %o5, 7, %o5
a0086bc4:  82 08 60 7f  and  %g1, 0x7f, %g1
a0086bc8:  82 10 40 0d  or  %g1, %o5, %g1
a0086bcc:  c2 2a 80 0b  stb  %g1, [ %o2 + %o3 ]
a0086bd0:  81 c7 e0 08  ret
a0086bd4:  81 e8 00 00  restore
