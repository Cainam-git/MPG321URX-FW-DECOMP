# leon2s FUN_a00d68cc 0xa00d68cc-0xa00d6a54 (392 bytes)
a00d68cc:  9d e3 bf 98  save  %sp, -104, %sp
a00d68d0:  c2 0e 00 00  ldub  [ %i0 ], %g1
a00d68d4:  c2 2e 40 00  stb  %g1, [ %i1 ]
a00d68d8:  c2 0e 00 00  ldub  [ %i0 ], %g1
a00d68dc:  b9 30 60 04  srl  %g1, 4, %i4
a00d68e0:  ba 07 3f ff  add  %i4, -1, %i5
a00d68e4:  83 37 60 1f  srl  %i5, 0x1f, %g1
a00d68e8:  82 07 40 01  add  %i5, %g1, %g1
a00d68ec:  83 38 60 01  sra  %g1, 1, %g1
a00d68f0:  96 10 00 19  mov  %i1, %o3
a00d68f4:  80 8f 60 01  btst  1, %i5
a00d68f8:  02 80 00 03  be  0xa00d6904
a00d68fc:  98 10 00 01  mov  %g1, %o4
a00d6900:  98 00 60 01  add  %g1, 1, %o4
a00d6904:  80 a7 20 00  cmp  %i4, 0
a00d6908:  b6 10 20 01  mov  1, %i3
a00d690c:  02 80 00 17  be  0xa00d6968
a00d6910:  b8 10 20 00  clr  %i4
a00d6914:  82 0f 20 ff  and  %i4, 0xff, %g1
a00d6918:  b4 07 20 01  add  %i4, 1, %i2
a00d691c:  ba 06 00 01  add  %i0, %g1, %i5
a00d6920:  80 88 60 01  btst  1, %g1
a00d6924:  02 80 00 08  be  0xa00d6944
a00d6928:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00d692c:  fa 0f 60 01  ldub  [ %i5 + 1 ], %i5
a00d6930:  c2 0a c0 1c  ldub  [ %o3 + %i4 ], %g1
a00d6934:  82 10 40 1d  or  %g1, %i5, %g1
a00d6938:  c2 2a c0 1c  stb  %g1, [ %o3 + %i4 ]
a00d693c:  10 80 00 05  b  0xa00d6950
a00d6940:  b6 06 e0 01  inc  %i3
a00d6944:  c2 0f 60 01  ldub  [ %i5 + 1 ], %g1
a00d6948:  83 28 60 04  sll  %g1, 4, %g1
a00d694c:  c2 2a c0 1c  stb  %g1, [ %o3 + %i4 ]
a00d6950:  c2 0e 00 00  ldub  [ %i0 ], %g1
a00d6954:  83 30 60 04  srl  %g1, 4, %g1
a00d6958:  ba 0e a0 ff  and  %i2, 0xff, %i5
a00d695c:  80 a7 40 01  cmp  %i5, %g1
a00d6960:  0a bf ff ed  bcs  0xa00d6914
a00d6964:  b8 10 00 1a  mov  %i2, %i4
a00d6968:  82 0b 20 ff  and  %o4, 0xff, %g1
a00d696c:  fa 0e 20 11  ldub  [ %i0 + 0x11 ], %i5
a00d6970:  b2 02 c0 01  add  %o3, %g1, %i1
a00d6974:  fa 2e 60 01  stb  %i5, [ %i1 + 1 ]
a00d6978:  fa 0e 20 12  ldub  [ %i0 + 0x12 ], %i5
a00d697c:  82 00 40 01  add  %g1, %g1, %g1
a00d6980:  ba 0f 60 d0  and  %i5, 0xd0, %i5
a00d6984:  82 00 60 05  add  %g1, 5, %g1
a00d6988:  82 08 60 ff  and  %g1, 0xff, %g1
a00d698c:  fa 2e 60 02  stb  %i5, [ %i1 + 2 ]
a00d6990:  80 a0 60 00  cmp  %g1, 0
a00d6994:  b8 10 3f 80  mov  -128, %i4
a00d6998:  b0 10 20 07  mov  7, %i0
a00d699c:  9e 10 20 00  clr  %o7
a00d69a0:  b7 28 60 02  sll  %g1, 2, %i3
a00d69a4:  ba 10 20 00  clr  %i5
a00d69a8:  02 80 00 18  be  0xa00d6a08
a00d69ac:  82 0b e0 ff  and  %o7, 0xff, %g1
a00d69b0:  c2 0a c0 01  ldub  [ %o3 + %g1 ], %g1
a00d69b4:  82 08 40 1c  and  %g1, %i4, %g1
a00d69b8:  83 38 40 18  sra  %g1, %i0, %g1
a00d69bc:  ba 07 40 1d  add  %i5, %i5, %i5
a00d69c0:  b4 17 40 01  or  %i5, %g1, %i2
a00d69c4:  b8 0f 20 ff  and  %i4, 0xff, %i4
a00d69c8:  82 06 ff ff  add  %i3, -1, %g1
a00d69cc:  b9 37 20 01  srl  %i4, 1, %i4
a00d69d0:  9b 28 60 10  sll  %g1, 0x10, %o5
a00d69d4:  80 a7 20 00  cmp  %i4, 0
a00d69d8:  ba 10 00 1a  mov  %i2, %i5
a00d69dc:  b0 06 3f ff  add  %i0, -1, %i0
a00d69e0:  12 80 00 05  bne  0xa00d69f4
a00d69e4:  b6 10 00 01  mov  %g1, %i3
a00d69e8:  b8 10 3f 80  mov  -128, %i4
a00d69ec:  b0 10 20 07  mov  7, %i0
a00d69f0:  9e 03 e0 01  inc  %o7
a00d69f4:  80 8f 60 10  btst  0x10, %i5
a00d69f8:  32 80 00 02  bne,a   0xa00d6a00
a00d69fc:  ba 1e a0 13  xor  %i2, 0x13, %i5
a00d6a00:  10 bf ff ea  b  0xa00d69a8
a00d6a04:  80 a3 60 00  cmp  %o5, 0
a00d6a08:  b6 10 20 04  mov  4, %i3
a00d6a0c:  b8 07 40 1d  add  %i5, %i5, %i4
a00d6a10:  82 06 ff ff  add  %i3, -1, %g1
a00d6a14:  b5 28 60 10  sll  %g1, 0x10, %i2
a00d6a18:  ba 10 00 1c  mov  %i4, %i5
a00d6a1c:  80 8f 20 10  btst  0x10, %i4
a00d6a20:  02 80 00 03  be  0xa00d6a2c
a00d6a24:  b6 10 00 01  mov  %g1, %i3
a00d6a28:  ba 1f 20 13  xor  %i4, 0x13, %i5
a00d6a2c:  80 a6 a0 00  cmp  %i2, 0
a00d6a30:  12 bf ff f8  bne  0xa00d6a10
a00d6a34:  b8 07 40 1d  add  %i5, %i5, %i4
a00d6a38:  c2 0e 60 02  ldub  [ %i1 + 2 ], %g1
a00d6a3c:  82 17 40 01  or  %i5, %g1, %g1
a00d6a40:  b0 03 20 03  add  %o4, 3, %i0
a00d6a44:  c2 2e 60 02  stb  %g1, [ %i1 + 2 ]
a00d6a48:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d6a4c:  81 c7 e0 08  ret
a00d6a50:  81 e8 00 00  restore
