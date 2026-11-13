# leon2m FUN_a00c68d8 0xa00c68d8-0xa00c762c (3412 bytes)
a00c68d8:  9d e3 bf 98  save  %sp, -104, %sp
a00c68dc:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00c68e0:  9a 14 e2 90  or  %l3, 0x290, %o5	! 0xa802d290
a00c68e4:  d0 03 60 a8  ld  [ %o5 + 0xa8 ], %o0
a00c68e8:  83 32 20 07  srl  %o0, 7, %g1
a00c68ec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c68f0:  80 a6 20 02  cmp  %i0, 2
a00c68f4:  02 80 02 0d  be  0xa00c7128
a00c68f8:  a8 08 60 01  and  %g1, 1, %l4
a00c68fc:  80 a6 20 03  cmp  %i0, 3
a00c6900:  02 80 02 75  be  0xa00c72d4
a00c6904:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c6908:  c2 0a e0 e5  ldub  [ %o3 + 0xe5 ], %g1	! 0xa802d0e5
a00c690c:  94 08 60 ff  and  %g1, 0xff, %o2
a00c6910:  80 a0 00 0a  cmp  %g0, %o2
a00c6914:  9e 40 20 00  addx  %g0, 0, %o7
a00c6918:  a0 1a a0 ff  xor  %o2, 0xff, %l0
a00c691c:  80 a0 00 10  cmp  %g0, %l0
a00c6920:  98 40 20 00  addx  %g0, 0, %o4
a00c6924:  80 8b c0 0c  btst  %o7, %o4
a00c6928:  02 80 00 09  be  0xa00c694c
a00c692c:  96 10 00 0a  mov  %o2, %o3
a00c6930:  9a 02 bf d0  add  %o2, -48, %o5
a00c6934:  96 0b 60 ff  and  %o5, 0xff, %o3
a00c6938:  80 a2 e0 03  cmp  %o3, 3
a00c693c:  18 80 03 3a  bgu  0xa00c7624
a00c6940:  92 10 20 ff  mov  0xff, %o1
a00c6944:  a2 14 e2 90  or  %l3, 0x290, %l1
a00c6948:  da 2c 60 11  stb  %o5, [ %l1 + 0x11 ]
a00c694c:  80 a2 e0 03  cmp  %o3, 3
a00c6950:  02 80 01 f9  be  0xa00c7134
a00c6954:  80 a6 20 02  cmp  %i0, 2
a00c6958:  02 80 02 3b  be  0xa00c7244
a00c695c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c6960:  80 a6 20 03  cmp  %i0, 3
a00c6964:  02 80 02 62  be  0xa00c72ec
a00c6968:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c696c:  c2 0a e0 e0  ldub  [ %o3 + 0xe0 ], %g1	! 0xa802d0e0
a00c6970:  96 08 60 ff  and  %g1, 0xff, %o3
a00c6974:  80 a0 00 0b  cmp  %g0, %o3
a00c6978:  a0 40 20 00  addx  %g0, 0, %l0
a00c697c:  a2 1a e0 ff  xor  %o3, 0xff, %l1
a00c6980:  80 a0 00 11  cmp  %g0, %l1
a00c6984:  9e 40 20 00  addx  %g0, 0, %o7
a00c6988:  80 8c 00 0f  btst  %l0, %o7
a00c698c:  02 80 00 12  be  0xa00c69d4
a00c6990:  80 a6 20 02  cmp  %i0, 2
a00c6994:  82 02 ff d0  add  %o3, -48, %g1
a00c6998:  82 08 60 ff  and  %g1, 0xff, %g1
a00c699c:  80 a0 60 01  cmp  %g1, 1
a00c69a0:  18 80 03 21  bgu  0xa00c7624
a00c69a4:  92 10 20 ff  mov  0xff, %o1
a00c69a8:  98 14 e2 90  or  %l3, 0x290, %o4
a00c69ac:  d6 03 21 1c  ld  [ %o4 + 0x11c ], %o3
a00c69b0:  9a 08 60 01  and  %g1, 1, %o5
a00c69b4:  95 2b 60 04  sll  %o5, 4, %o2
a00c69b8:  92 0a ff ef  and  %o3, -17, %o1
a00c69bc:  90 12 40 0a  or  %o1, %o2, %o0
a00c69c0:  80 8a 20 10  btst  0x10, %o0
a00c69c4:  02 80 00 03  be  0xa00c69d0
a00c69c8:  d0 23 21 1c  st  %o0, [ %o4 + 0x11c ]
a00c69cc:  c0 2b 21 78  clrb  [ %o4 + 0x178 ]
a00c69d0:  80 a6 20 02  cmp  %i0, 2
a00c69d4:  02 80 02 1e  be  0xa00c724c
a00c69d8:  80 a6 20 03  cmp  %i0, 3
a00c69dc:  02 80 02 a7  be  0xa00c7478
a00c69e0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c69e4:  c2 0c 20 e3  ldub  [ %l0 + 0xe3 ], %g1	! 0xa802d0e3
a00c69e8:  96 08 60 ff  and  %g1, 0xff, %o3
a00c69ec:  80 a0 00 0b  cmp  %g0, %o3
a00c69f0:  a4 40 20 00  addx  %g0, 0, %l2
a00c69f4:  82 1a e0 ff  xor  %o3, 0xff, %g1
a00c69f8:  80 a0 00 01  cmp  %g0, %g1
a00c69fc:  a2 40 20 00  addx  %g0, 0, %l1
a00c6a00:  80 8c 80 11  btst  %l2, %l1
a00c6a04:  02 80 00 08  be  0xa00c6a24
a00c6a08:  9a 02 ff d0  add  %o3, -48, %o5
a00c6a0c:  92 0b 60 ff  and  %o5, 0xff, %o1
a00c6a10:  80 a2 60 64  cmp  %o1, 0x64
a00c6a14:  18 80 03 04  bgu  0xa00c7624
a00c6a18:  92 10 20 ff  mov  0xff, %o1
a00c6a1c:  94 14 e2 90  or  %l3, 0x290, %o2
a00c6a20:  da 2a a0 0a  stb  %o5, [ %o2 + 0xa ]
a00c6a24:  40 00 44 ef  call  0xa00d7de0
a00c6a28:  01 00 00 00  nop
a00c6a2c:  40 00 4b 4e  call  0xa00d9764
a00c6a30:  01 00 00 00  nop
a00c6a34:  80 a6 20 02  cmp  %i0, 2
a00c6a38:  02 80 02 08  be  0xa00c7258
a00c6a3c:  80 a6 20 03  cmp  %i0, 3
a00c6a40:  02 80 02 a9  be  0xa00c74e4
a00c6a44:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c6a48:  c2 0b 20 e1  ldub  [ %o4 + 0xe1 ], %g1	! 0xa802d0e1
a00c6a4c:  96 08 60 ff  and  %g1, 0xff, %o3
a00c6a50:  80 a0 00 0b  cmp  %g0, %o3
a00c6a54:  a0 40 20 00  addx  %g0, 0, %l0
a00c6a58:  a2 1a e0 ff  xor  %o3, 0xff, %l1
a00c6a5c:  80 a0 00 11  cmp  %g0, %l1
a00c6a60:  9e 40 20 00  addx  %g0, 0, %o7
a00c6a64:  80 8c 00 0f  btst  %l0, %o7
a00c6a68:  02 80 00 13  be  0xa00c6ab4
a00c6a6c:  80 a6 20 02  cmp  %i0, 2
a00c6a70:  82 02 ff d0  add  %o3, -48, %g1
a00c6a74:  82 08 60 ff  and  %g1, 0xff, %g1
a00c6a78:  80 a0 60 04  cmp  %g1, 4
a00c6a7c:  18 80 02 ea  bgu  0xa00c7624
a00c6a80:  92 10 20 ff  mov  0xff, %o1
a00c6a84:  90 14 e2 90  or  %l3, 0x290, %o0
a00c6a88:  d8 02 20 34  ld  [ %o0 + 0x34 ], %o4
a00c6a8c:  9a 08 60 0f  and  %g1, 0xf, %o5
a00c6a90:  1f 00 03 c0  sethi  %hi(0xf0000), %o7
a00c6a94:  94 2b 00 0f  andn  %o4, %o7, %o2
a00c6a98:  97 2b 60 10  sll  %o5, 0x10, %o3
a00c6a9c:  92 12 80 0b  or  %o2, %o3, %o1
a00c6aa0:  40 00 3b 96  call  0xa00d58f8
a00c6aa4:  d2 22 20 34  st  %o1, [ %o0 + 0x34 ]
a00c6aa8:  40 00 3b 8c  call  0xa00d58d8
a00c6aac:  01 00 00 00  nop
a00c6ab0:  80 a6 20 02  cmp  %i0, 2
a00c6ab4:  02 80 01 f6  be  0xa00c728c
a00c6ab8:  80 a6 20 03  cmp  %i0, 3
a00c6abc:  02 80 02 90  be  0xa00c74fc
a00c6ac0:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00c6ac4:  c2 0c a0 e4  ldub  [ %l2 + 0xe4 ], %g1	! 0xa802d0e4
a00c6ac8:  96 08 60 ff  and  %g1, 0xff, %o3
a00c6acc:  80 a0 00 0b  cmp  %g0, %o3
a00c6ad0:  90 40 20 00  addx  %g0, 0, %o0
a00c6ad4:  92 1a e0 ff  xor  %o3, 0xff, %o1
a00c6ad8:  80 a0 00 09  cmp  %g0, %o1
a00c6adc:  82 40 20 00  addx  %g0, 0, %g1
a00c6ae0:  80 8a 00 01  btst  %o0, %g1
a00c6ae4:  12 80 01 e0  bne  0xa00c7264
a00c6ae8:  80 a6 20 02  cmp  %i0, 2
a00c6aec:  02 80 01 e6  be  0xa00c7284
a00c6af0:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c6af4:  80 a6 20 03  cmp  %i0, 3
a00c6af8:  02 80 02 84  be  0xa00c7508
a00c6afc:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c6b00:  c2 0c 20 d9  ldub  [ %l0 + 0xd9 ], %g1	! 0xa802d0d9
a00c6b04:  96 08 60 ff  and  %g1, 0xff, %o3
a00c6b08:  80 a0 00 0b  cmp  %g0, %o3
a00c6b0c:  a4 40 20 00  addx  %g0, 0, %l2
a00c6b10:  82 1a e0 ff  xor  %o3, 0xff, %g1
a00c6b14:  80 a0 00 01  cmp  %g0, %g1
a00c6b18:  a2 40 20 00  addx  %g0, 0, %l1
a00c6b1c:  80 8c 80 11  btst  %l2, %l1
a00c6b20:  02 80 00 13  be  0xa00c6b6c
a00c6b24:  92 02 ff d0  add  %o3, -48, %o1
a00c6b28:  98 0a 60 ff  and  %o1, 0xff, %o4
a00c6b2c:  80 a3 20 01  cmp  %o4, 1
a00c6b30:  18 80 02 bd  bgu  0xa00c7624
a00c6b34:  92 10 20 ff  mov  0xff, %o1
a00c6b38:  96 14 e2 90  or  %l3, 0x290, %o3
a00c6b3c:  e2 02 e1 1c  ld  [ %o3 + 0x11c ], %l1
a00c6b40:  21 20 00 00  sethi  %hi(0x80000000), %l0
a00c6b44:  9a 2c 40 10  andn  %l1, %l0, %o5
a00c6b48:  9f 2b 20 1f  sll  %o4, 0x1f, %o7
a00c6b4c:  94 13 40 0f  or  %o5, %o7, %o2
a00c6b50:  80 a2 a0 00  cmp  %o2, 0
a00c6b54:  16 80 00 06  bge  0xa00c6b6c
a00c6b58:  d4 22 e1 1c  st  %o2, [ %o3 + 0x11c ]
a00c6b5c:  d8 02 e0 b0  ld  [ %o3 + 0xb0 ], %o4
a00c6b60:  80 a3 20 00  cmp  %o4, 0
a00c6b64:  12 80 02 03  bne  0xa00c7370
a00c6b68:  01 00 00 00  nop
a00c6b6c:  40 00 49 24  call  0xa00d8ffc
a00c6b70:  01 00 00 00  nop
a00c6b74:  80 a6 20 02  cmp  %i0, 2
a00c6b78:  02 80 01 c8  be  0xa00c7298
a00c6b7c:  80 a6 20 03  cmp  %i0, 3
a00c6b80:  02 80 02 65  be  0xa00c7514
a00c6b84:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00c6b88:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c6b8c:  c2 08 60 d8  ldub  [ %g1 + 0xd8 ], %g1	! 0xa802d0d8
a00c6b90:  96 08 60 ff  and  %g1, 0xff, %o3
a00c6b94:  80 a0 00 0b  cmp  %g0, %o3
a00c6b98:  92 40 20 00  addx  %g0, 0, %o1
a00c6b9c:  94 1a e0 ff  xor  %o3, 0xff, %o2
a00c6ba0:  80 a0 00 0a  cmp  %g0, %o2
a00c6ba4:  90 40 20 00  addx  %g0, 0, %o0
a00c6ba8:  80 8a 40 08  btst  %o1, %o0
a00c6bac:  02 80 00 2f  be  0xa00c6c68
a00c6bb0:  80 a6 20 02  cmp  %i0, 2
a00c6bb4:  9e 02 ff d0  add  %o3, -48, %o7
a00c6bb8:  9a 0b e0 ff  and  %o7, 0xff, %o5
a00c6bbc:  80 a3 60 01  cmp  %o5, 1
a00c6bc0:  18 80 02 99  bgu  0xa00c7624
a00c6bc4:  92 10 20 ff  mov  0xff, %o1
a00c6bc8:  a0 14 e2 90  or  %l3, 0x290, %l0
a00c6bcc:  e2 04 20 b0  ld  [ %l0 + 0xb0 ], %l1
a00c6bd0:  80 a4 40 0d  cmp  %l1, %o5
a00c6bd4:  22 80 00 11  be,a   0xa00c6c18
a00c6bd8:  9a 14 e2 90  or  %l3, 0x290, %o5
a00c6bdc:  d8 0c 20 4a  ldub  [ %l0 + 0x4a ], %o4
a00c6be0:  80 a3 20 00  cmp  %o4, 0
a00c6be4:  12 80 01 e6  bne  0xa00c737c
a00c6be8:  da 24 20 b0  st  %o5, [ %l0 + 0xb0 ]
a00c6bec:  da 04 21 1c  ld  [ %l0 + 0x11c ], %o5
a00c6bf0:  80 a3 60 00  cmp  %o5, 0
a00c6bf4:  16 80 00 06  bge  0xa00c6c0c
a00c6bf8:  01 00 00 00  nop
a00c6bfc:  d6 04 20 b0  ld  [ %l0 + 0xb0 ], %o3
a00c6c00:  80 a2 e0 00  cmp  %o3, 0
a00c6c04:  12 80 02 7d  bne  0xa00c75f8
a00c6c08:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00c6c0c:  40 00 3c cc  call  0xa00d5f3c
a00c6c10:  01 00 00 00  nop
a00c6c14:  9a 14 e2 90  or  %l3, 0x290, %o5
a00c6c18:  e0 0b 60 1f  ldub  [ %o5 + 0x1f ], %l0
a00c6c1c:  80 a4 20 00  cmp  %l0, 0
a00c6c20:  02 80 00 06  be  0xa00c6c38
a00c6c24:  01 00 00 00  nop
a00c6c28:  d0 03 60 b0  ld  [ %o5 + 0xb0 ], %o0
a00c6c2c:  80 a2 20 00  cmp  %o0, 0
a00c6c30:  32 80 02 61  bne,a   0xa00c75b4
a00c6c34:  c0 2b 60 1f  clrb  [ %o5 + 0x1f ]
a00c6c38:  7f fe f2 eb  call  0xa00837e4
a00c6c3c:  01 00 00 00  nop
a00c6c40:  92 0a 20 ff  and  %o0, 0xff, %o1
a00c6c44:  80 a2 60 01  cmp  %o1, 1
a00c6c48:  12 80 00 08  bne  0xa00c6c68
a00c6c4c:  80 a6 20 02  cmp  %i0, 2
a00c6c50:  a0 14 e2 90  or  %l3, 0x290, %l0
a00c6c54:  d4 04 20 b0  ld  [ %l0 + 0xb0 ], %o2
a00c6c58:  80 a2 a0 00  cmp  %o2, 0
a00c6c5c:  12 80 02 6b  bne  0xa00c7608
a00c6c60:  01 00 00 00  nop
a00c6c64:  80 a6 20 02  cmp  %i0, 2
a00c6c68:  02 80 01 8f  be  0xa00c72a4
a00c6c6c:  80 a6 20 03  cmp  %i0, 3
a00c6c70:  02 80 02 2b  be  0xa00c751c
a00c6c74:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c6c78:  c2 0c 60 d7  ldub  [ %l1 + 0xd7 ], %g1	! 0xa802d0d7
a00c6c7c:  96 08 60 ff  and  %g1, 0xff, %o3
a00c6c80:  80 a0 00 0b  cmp  %g0, %o3
a00c6c84:  98 40 20 00  addx  %g0, 0, %o4
a00c6c88:  82 1a e0 ff  xor  %o3, 0xff, %g1
a00c6c8c:  80 a0 00 01  cmp  %g0, %g1
a00c6c90:  a4 40 20 00  addx  %g0, 0, %l2
a00c6c94:  80 8b 00 12  btst  %o4, %l2
a00c6c98:  02 80 00 11  be  0xa00c6cdc
a00c6c9c:  80 a6 20 02  cmp  %i0, 2
a00c6ca0:  a4 02 ff d0  add  %o3, -48, %l2
a00c6ca4:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00c6ca8:  80 a4 60 02  cmp  %l1, 2
a00c6cac:  18 80 02 5e  bgu  0xa00c7624
a00c6cb0:  92 10 20 ff  mov  0xff, %o1
a00c6cb4:  a0 14 e2 90  or  %l3, 0x290, %l0
a00c6cb8:  d6 04 20 b0  ld  [ %l0 + 0xb0 ], %o3
a00c6cbc:  80 a2 e0 00  cmp  %o3, 0
a00c6cc0:  12 80 02 2d  bne  0xa00c7574
a00c6cc4:  01 00 00 00  nop
a00c6cc8:  d0 0c 20 1f  ldub  [ %l0 + 0x1f ], %o0
a00c6ccc:  80 a2 20 00  cmp  %o0, 0
a00c6cd0:  22 80 01 91  be,a   0xa00c7314
a00c6cd4:  d2 0c 20 19  ldub  [ %l0 + 0x19 ], %o1
a00c6cd8:  80 a6 20 02  cmp  %i0, 2
a00c6cdc:  02 80 01 75  be  0xa00c72b0
a00c6ce0:  80 a6 20 03  cmp  %i0, 3
a00c6ce4:  02 80 02 11  be  0xa00c7528
a00c6ce8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c6cec:  c2 0b e0 d6  ldub  [ %o7 + 0xd6 ], %g1	! 0xa802d0d6
a00c6cf0:  96 08 60 ff  and  %g1, 0xff, %o3
a00c6cf4:  80 a0 00 0b  cmp  %g0, %o3
a00c6cf8:  a4 40 20 00  addx  %g0, 0, %l2
a00c6cfc:  98 1a e0 ff  xor  %o3, 0xff, %o4
a00c6d00:  80 a0 00 0c  cmp  %g0, %o4
a00c6d04:  a2 40 20 00  addx  %g0, 0, %l1
a00c6d08:  80 8c 80 11  btst  %l2, %l1
a00c6d0c:  02 80 00 0b  be  0xa00c6d38
a00c6d10:  80 a6 20 02  cmp  %i0, 2
a00c6d14:  9a 02 ff d0  add  %o3, -48, %o5
a00c6d18:  a0 0b 60 ff  and  %o5, 0xff, %l0
a00c6d1c:  80 a4 20 0a  cmp  %l0, 0xa
a00c6d20:  18 80 02 41  bgu  0xa00c7624
a00c6d24:  92 10 20 ff  mov  0xff, %o1
a00c6d28:  96 14 e2 90  or  %l3, 0x290, %o3
a00c6d2c:  40 00 47 81  call  0xa00d8b30
a00c6d30:  da 2a e1 40  stb  %o5, [ %o3 + 0x140 ]
a00c6d34:  80 a6 20 02  cmp  %i0, 2
a00c6d38:  02 80 01 61  be  0xa00c72bc
a00c6d3c:  80 a6 20 03  cmp  %i0, 3
a00c6d40:  02 80 01 fd  be  0xa00c7534
a00c6d44:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c6d48:  c2 0a a0 e2  ldub  [ %o2 + 0xe2 ], %g1	! 0xa802d0e2
a00c6d4c:  96 08 60 ff  and  %g1, 0xff, %o3
a00c6d50:  80 a0 00 0b  cmp  %g0, %o3
a00c6d54:  9e 40 20 00  addx  %g0, 0, %o7
a00c6d58:  a2 1a e0 ff  xor  %o3, 0xff, %l1
a00c6d5c:  80 a0 00 11  cmp  %g0, %l1
a00c6d60:  9a 40 20 00  addx  %g0, 0, %o5
a00c6d64:  80 8b c0 0d  btst  %o7, %o5
a00c6d68:  02 80 00 0d  be  0xa00c6d9c
a00c6d6c:  80 a6 20 02  cmp  %i0, 2
a00c6d70:  98 02 ff d0  add  %o3, -48, %o4
a00c6d74:  82 0b 20 ff  and  %o4, 0xff, %g1
a00c6d78:  80 a0 60 64  cmp  %g1, 0x64
a00c6d7c:  18 80 02 2a  bgu  0xa00c7624
a00c6d80:  92 10 20 ff  mov  0xff, %o1
a00c6d84:  9a 14 e2 90  or  %l3, 0x290, %o5
a00c6d88:  e0 03 60 b0  ld  [ %o5 + 0xb0 ], %l0
a00c6d8c:  80 a4 20 00  cmp  %l0, 0
a00c6d90:  22 80 01 5a  be,a   0xa00c72f8
a00c6d94:  d6 03 61 1c  ld  [ %o5 + 0x11c ], %o3
a00c6d98:  80 a6 20 02  cmp  %i0, 2
a00c6d9c:  02 80 01 4b  be  0xa00c72c8
a00c6da0:  80 a6 20 03  cmp  %i0, 3
a00c6da4:  02 80 01 e7  be  0xa00c7540
a00c6da8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c6dac:  c2 0a 60 da  ldub  [ %o1 + 0xda ], %g1	! 0xa802d0da
a00c6db0:  96 08 60 ff  and  %g1, 0xff, %o3
a00c6db4:  80 a0 00 0b  cmp  %g0, %o3
a00c6db8:  9a 40 20 00  addx  %g0, 0, %o5
a00c6dbc:  9e 1a e0 ff  xor  %o3, 0xff, %o7
a00c6dc0:  80 a0 00 0f  cmp  %g0, %o7
a00c6dc4:  94 40 20 00  addx  %g0, 0, %o2
a00c6dc8:  80 8b 40 0a  btst  %o5, %o2
a00c6dcc:  02 80 00 10  be  0xa00c6e0c
a00c6dd0:  80 a6 20 02  cmp  %i0, 2
a00c6dd4:  a4 02 ff d0  add  %o3, -48, %l2
a00c6dd8:  82 0c a0 ff  and  %l2, 0xff, %g1
a00c6ddc:  80 a0 60 01  cmp  %g1, 1
a00c6de0:  18 80 02 11  bgu  0xa00c7624
a00c6de4:  92 10 20 ff  mov  0xff, %o1
a00c6de8:  a0 14 e2 90  or  %l3, 0x290, %l0
a00c6dec:  90 08 60 01  and  %g1, 1, %o0
a00c6df0:  d4 04 20 a8  ld  [ %l0 + 0xa8 ], %o2
a00c6df4:  13 00 00 04  sethi  %hi(0x1000), %o1
a00c6df8:  96 2a 80 09  andn  %o2, %o1, %o3
a00c6dfc:  99 2a 20 0c  sll  %o0, 0xc, %o4
a00c6e00:  82 12 c0 0c  or  %o3, %o4, %g1
a00c6e04:  c2 24 20 a8  st  %g1, [ %l0 + 0xa8 ]
a00c6e08:  80 a6 20 02  cmp  %i0, 2
a00c6e0c:  02 80 01 35  be  0xa00c72e0
a00c6e10:  80 a6 20 03  cmp  %i0, 3
a00c6e14:  22 80 01 ce  be,a   0xa00c754c
a00c6e18:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c6e1c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c6e20:  c2 0c 60 db  ldub  [ %l1 + 0xdb ], %g1	! 0xa802d0db
a00c6e24:  96 08 60 ff  and  %g1, 0xff, %o3
a00c6e28:  80 a0 00 0b  cmp  %g0, %o3
a00c6e2c:  a0 40 20 00  addx  %g0, 0, %l0
a00c6e30:  82 1a e0 ff  xor  %o3, 0xff, %g1
a00c6e34:  80 a0 00 01  cmp  %g0, %g1
a00c6e38:  a4 40 20 00  addx  %g0, 0, %l2
a00c6e3c:  80 8c 00 12  btst  %l0, %l2
a00c6e40:  02 80 00 0a  be  0xa00c6e68
a00c6e44:  80 a6 20 02  cmp  %i0, 2
a00c6e48:  9a 02 ff d0  add  %o3, -48, %o5
a00c6e4c:  96 0b 60 ff  and  %o5, 0xff, %o3
a00c6e50:  80 a2 e0 04  cmp  %o3, 4
a00c6e54:  18 80 01 f4  bgu  0xa00c7624
a00c6e58:  92 10 20 ff  mov  0xff, %o1
a00c6e5c:  90 14 e2 90  or  %l3, 0x290, %o0
a00c6e60:  da 2a 21 3e  stb  %o5, [ %o0 + 0x13e ]
a00c6e64:  80 a6 20 02  cmp  %i0, 2
a00c6e68:  02 80 01 7e  be  0xa00c7460
a00c6e6c:  80 a6 20 03  cmp  %i0, 3
a00c6e70:  22 80 01 b9  be,a   0xa00c7554
a00c6e74:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c6e78:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c6e7c:  c2 0b 60 dc  ldub  [ %o5 + 0xdc ], %g1	! 0xa802d0dc
a00c6e80:  96 08 60 ff  and  %g1, 0xff, %o3
a00c6e84:  80 a0 00 0b  cmp  %g0, %o3
a00c6e88:  a2 40 20 00  addx  %g0, 0, %l1
a00c6e8c:  a4 1a e0 ff  xor  %o3, 0xff, %l2
a00c6e90:  80 a0 00 12  cmp  %g0, %l2
a00c6e94:  9e 40 20 00  addx  %g0, 0, %o7
a00c6e98:  80 8c 40 0f  btst  %l1, %o7
a00c6e9c:  02 80 00 14  be  0xa00c6eec
a00c6ea0:  80 a6 20 02  cmp  %i0, 2
a00c6ea4:  90 02 ff d0  add  %o3, -48, %o0
a00c6ea8:  94 0a 20 ff  and  %o0, 0xff, %o2
a00c6eac:  80 a2 a0 04  cmp  %o2, 4
a00c6eb0:  18 80 01 dd  bgu  0xa00c7624
a00c6eb4:  92 10 20 ff  mov  0xff, %o1
a00c6eb8:  96 14 e2 90  or  %l3, 0x290, %o3
a00c6ebc:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a00c6ec0:  94 02 80 0b  add  %o2, %o3, %o2
a00c6ec4:  de 12 63 f4  lduh  [ %o1 + 0x3f4 ], %o7
a00c6ec8:  d8 0a a1 9b  ldub  [ %o2 + 0x19b ], %o4
a00c6ecc:  23 00 00 10  sethi  %hi(0x4000), %l1
a00c6ed0:  c2 0a a1 97  ldub  [ %o2 + 0x197 ], %g1
a00c6ed4:  9a 13 c0 11  or  %o7, %l1, %o5
a00c6ed8:  d8 2a e1 a2  stb  %o4, [ %o3 + 0x1a2 ]
a00c6edc:  da 32 63 f4  sth  %o5, [ %o1 + 0x3f4 ]
a00c6ee0:  d0 2a e1 a0  stb  %o0, [ %o3 + 0x1a0 ]
a00c6ee4:  c2 2a e1 a1  stb  %g1, [ %o3 + 0x1a1 ]
a00c6ee8:  80 a6 20 02  cmp  %i0, 2
a00c6eec:  02 80 01 60  be  0xa00c746c
a00c6ef0:  80 a6 20 03  cmp  %i0, 3
a00c6ef4:  22 80 01 9a  be,a   0xa00c755c
a00c6ef8:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00c6efc:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c6f00:  c2 0c 20 dd  ldub  [ %l0 + 0xdd ], %g1	! 0xa802d0dd
a00c6f04:  96 08 60 ff  and  %g1, 0xff, %o3
a00c6f08:  80 a0 00 0b  cmp  %g0, %o3
a00c6f0c:  92 40 20 00  addx  %g0, 0, %o1
a00c6f10:  9a 1a e0 ff  xor  %o3, 0xff, %o5
a00c6f14:  80 a0 00 0d  cmp  %g0, %o5
a00c6f18:  82 40 20 00  addx  %g0, 0, %g1
a00c6f1c:  80 8a 40 01  btst  %o1, %g1
a00c6f20:  02 80 00 0a  be  0xa00c6f48
a00c6f24:  80 a6 20 02  cmp  %i0, 2
a00c6f28:  9a 02 ff d0  add  %o3, -48, %o5
a00c6f2c:  96 0b 60 ff  and  %o5, 0xff, %o3
a00c6f30:  80 a2 e0 04  cmp  %o3, 4
a00c6f34:  18 80 01 bc  bgu  0xa00c7624
a00c6f38:  92 10 20 ff  mov  0xff, %o1
a00c6f3c:  94 14 e2 90  or  %l3, 0x290, %o2
a00c6f40:  da 2a a1 3f  stb  %o5, [ %o2 + 0x13f ]
a00c6f44:  80 a6 20 02  cmp  %i0, 2
a00c6f48:  02 80 01 55  be  0xa00c749c
a00c6f4c:  80 a6 20 03  cmp  %i0, 3
a00c6f50:  22 80 01 85  be,a   0xa00c7564
a00c6f54:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c6f58:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c6f5c:  c2 0a 20 de  ldub  [ %o0 + 0xde ], %g1	! 0xa802d0de
a00c6f60:  96 08 60 ff  and  %g1, 0xff, %o3
a00c6f64:  80 a0 00 0b  cmp  %g0, %o3
a00c6f68:  a0 40 20 00  addx  %g0, 0, %l0
a00c6f6c:  82 1a e0 ff  xor  %o3, 0xff, %g1
a00c6f70:  80 a0 00 01  cmp  %g0, %g1
a00c6f74:  a4 40 20 00  addx  %g0, 0, %l2
a00c6f78:  80 8c 00 12  btst  %l0, %l2
a00c6f7c:  22 80 00 0a  be,a   0xa00c6fa4
a00c6f80:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a00c6f84:  9a 02 ff d0  add  %o3, -48, %o5
a00c6f88:  98 0b 60 ff  and  %o5, 0xff, %o4
a00c6f8c:  80 a3 20 0c  cmp  %o4, 0xc
a00c6f90:  18 80 01 a5  bgu  0xa00c7624
a00c6f94:  92 10 20 ff  mov  0xff, %o1
a00c6f98:  96 14 e2 90  or  %l3, 0x290, %o3
a00c6f9c:  da 2a e1 90  stb  %o5, [ %o3 + 0x190 ]
a00c6fa0:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a00c6fa4:  a2 12 a3 f4  or  %o2, 0x3f4, %l1	! 0xa802cff4
a00c6fa8:  da 14 60 04  lduh  [ %l1 + 4 ], %o5
a00c6fac:  21 00 00 18  sethi  %hi(0x6000), %l0
a00c6fb0:  80 8c 00 0d  btst  %l0, %o5
a00c6fb4:  02 80 01 34  be  0xa00c7484
a00c6fb8:  01 00 00 00  nop
a00c6fbc:  98 14 e2 90  or  %l3, 0x290, %o4
a00c6fc0:  de 0b 21 90  ldub  [ %o4 + 0x190 ], %o7
a00c6fc4:  80 a3 e0 00  cmp  %o7, 0
a00c6fc8:  12 80 00 08  bne  0xa00c6fe8
a00c6fcc:  80 a6 20 02  cmp  %i0, 2
a00c6fd0:  e4 03 20 a8  ld  [ %o4 + 0xa8 ], %l2
a00c6fd4:  11 00 00 04  sethi  %hi(0x1000), %o0
a00c6fd8:  80 8c 80 08  btst  %l2, %o0
a00c6fdc:  22 80 00 d5  be,a   0xa00c7330
a00c6fe0:  c2 0b 21 a0  ldub  [ %o4 + 0x1a0 ], %g1
a00c6fe4:  80 a6 20 02  cmp  %i0, 2
a00c6fe8:  02 80 01 42  be  0xa00c74f0
a00c6fec:  80 a6 20 03  cmp  %i0, 3
a00c6ff0:  22 80 01 5f  be,a   0xa00c756c
a00c6ff4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c6ff8:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c6ffc:  c2 0b 60 df  ldub  [ %o5 + 0xdf ], %g1	! 0xa802d0df
a00c7000:  96 08 60 ff  and  %g1, 0xff, %o3
a00c7004:  80 a0 00 0b  cmp  %g0, %o3
a00c7008:  9e 40 20 00  addx  %g0, 0, %o7
a00c700c:  90 1a e0 ff  xor  %o3, 0xff, %o0
a00c7010:  80 a0 00 08  cmp  %g0, %o0
a00c7014:  94 40 20 00  addx  %g0, 0, %o2
a00c7018:  80 8b c0 0a  btst  %o7, %o2
a00c701c:  22 80 00 0f  be,a   0xa00c7058
a00c7020:  a0 14 e2 90  or  %l3, 0x290, %l0
a00c7024:  82 02 ff d0  add  %o3, -48, %g1
a00c7028:  82 08 60 ff  and  %g1, 0xff, %g1
a00c702c:  80 a0 60 01  cmp  %g1, 1
a00c7030:  18 80 01 7d  bgu  0xa00c7624
a00c7034:  92 10 20 ff  mov  0xff, %o1
a00c7038:  92 14 e2 90  or  %l3, 0x290, %o1
a00c703c:  e0 02 60 a8  ld  [ %o1 + 0xa8 ], %l0
a00c7040:  9a 08 60 01  and  %g1, 1, %o5
a00c7044:  a3 2b 60 07  sll  %o5, 7, %l1
a00c7048:  98 0c 3f 7f  and  %l0, -129, %o4
a00c704c:  96 13 00 11  or  %o4, %l1, %o3
a00c7050:  d6 22 60 a8  st  %o3, [ %o1 + 0xa8 ]
a00c7054:  a0 14 e2 90  or  %l3, 0x290, %l0
a00c7058:  de 04 20 a8  ld  [ %l0 + 0xa8 ], %o7
a00c705c:  95 33 e0 07  srl  %o7, 7, %o2
a00c7060:  a6 1a 80 14  xor  %o2, %l4, %l3
a00c7064:  80 8c e0 01  btst  1, %l3
a00c7068:  12 80 01 10  bne  0xa00c74a8
a00c706c:  01 00 00 00  nop
a00c7070:  40 00 36 4a  call  0xa00d4998
a00c7074:  01 00 00 00  nop
a00c7078:  7f ff c6 15  call  0xa00b88cc
a00c707c:  01 00 00 00  nop
a00c7080:  80 a6 20 02  cmp  %i0, 2
a00c7084:  02 80 00 dd  be  0xa00c73f8
a00c7088:  80 a6 20 03  cmp  %i0, 3
a00c708c:  02 80 00 c1  be  0xa00c7390
a00c7090:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c7094:  94 13 20 78  or  %o4, 0x78, %o2	! 0xa802d078
a00c7098:  a4 10 20 30  mov  0x30, %l2
a00c709c:  a2 10 20 35  mov  0x35, %l1
a00c70a0:  96 10 20 36  mov  0x36, %o3
a00c70a4:  92 10 20 2b  mov  0x2b, %o1
a00c70a8:  82 10 20 0d  mov  0xd, %g1
a00c70ac:  e2 2b 20 78  stb  %l1, [ %o4 + 0x78 ]
a00c70b0:  d6 2a a0 01  stb  %o3, [ %o2 + 1 ]
a00c70b4:  e4 2a a0 03  stb  %l2, [ %o2 + 3 ]
a00c70b8:  d2 2a a0 04  stb  %o1, [ %o2 + 4 ]
a00c70bc:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00c70c0:  80 a6 20 02  cmp  %i0, 2
a00c70c4:  02 80 00 da  be  0xa00c742c
a00c70c8:  e4 2a a0 02  stb  %l2, [ %o2 + 2 ]
a00c70cc:  80 a6 20 03  cmp  %i0, 3
a00c70d0:  02 80 00 bd  be  0xa00c73c4
a00c70d4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c70d8:  a8 12 20 d0  or  %o0, 0xd0, %l4	! 0xa802d0d0
a00c70dc:  25 2a 00 ac  sethi  %hi(0xa802b000), %l2
a00c70e0:  c0 2c a0 9c  clrb  [ %l2 + 0x9c ]	! 0xa802b09c
a00c70e4:  c0 2a 20 d0  clrb  [ %o0 + 0xd0 ]
a00c70e8:  c0 2d 20 19  clrb  [ %l4 + 0x19 ]
a00c70ec:  c0 2d 20 01  clrb  [ %l4 + 1 ]
a00c70f0:  c0 2d 20 07  clrb  [ %l4 + 7 ]
a00c70f4:  80 a6 20 02  cmp  %i0, 2
a00c70f8:  02 80 00 d6  be  0xa00c7450
a00c70fc:  c0 2d 20 0a  clrb  [ %l4 + 0xa ]
a00c7100:  80 a6 20 03  cmp  %i0, 3
a00c7104:  12 80 00 05  bne  0xa00c7118
a00c7108:  90 10 00 18  mov  %i0, %o0
a00c710c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c7110:  94 12 61 08  or  %o1, 0x108, %o2	! 0xa802d108
a00c7114:  90 10 20 03  mov  3, %o0
a00c7118:  40 02 05 b4  call  0xa01487e8
a00c711c:  92 10 20 06  mov  6, %o1
a00c7120:  10 80 01 41  b  0xa00c7624
a00c7124:  92 10 20 00  clr  %o1
a00c7128:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c712c:  10 bf fd f8  b  0xa00c690c
a00c7130:  c2 0a 60 55  ldub  [ %o1 + 0x55 ], %g1	! 0xa802d055
a00c7134:  02 80 01 17  be  0xa00c7590
a00c7138:  80 a6 20 03  cmp  %i0, 3
a00c713c:  02 80 00 ac  be  0xa00c73ec
a00c7140:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c7144:  c2 0a 20 e6  ldub  [ %o0 + 0xe6 ], %g1	! 0xa802d0e6
a00c7148:  96 08 60 ff  and  %g1, 0xff, %o3
a00c714c:  80 a0 00 0b  cmp  %g0, %o3
a00c7150:  92 40 20 00  addx  %g0, 0, %o1
a00c7154:  94 1a e0 ff  xor  %o3, 0xff, %o2
a00c7158:  80 a0 00 0a  cmp  %g0, %o2
a00c715c:  9a 40 20 00  addx  %g0, 0, %o5
a00c7160:  80 8a 40 0d  btst  %o1, %o5
a00c7164:  02 80 00 0a  be  0xa00c718c
a00c7168:  80 a6 20 02  cmp  %i0, 2
a00c716c:  9a 02 ff d0  add  %o3, -48, %o5
a00c7170:  96 0b 60 ff  and  %o5, 0xff, %o3
a00c7174:  80 a2 e0 64  cmp  %o3, 0x64
a00c7178:  18 80 01 2b  bgu  0xa00c7624
a00c717c:  92 10 20 ff  mov  0xff, %o1
a00c7180:  9e 14 e2 90  or  %l3, 0x290, %o7
a00c7184:  da 2b e0 12  stb  %o5, [ %o7 + 0x12 ]
a00c7188:  80 a6 20 02  cmp  %i0, 2
a00c718c:  02 80 01 04  be  0xa00c759c
a00c7190:  80 a6 20 03  cmp  %i0, 3
a00c7194:  02 80 01 13  be  0xa00c75e0
a00c7198:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00c719c:  c2 0c a0 e7  ldub  [ %l2 + 0xe7 ], %g1	! 0xa802d0e7
a00c71a0:  96 08 60 ff  and  %g1, 0xff, %o3
a00c71a4:  80 a0 00 0b  cmp  %g0, %o3
a00c71a8:  90 40 20 00  addx  %g0, 0, %o0
a00c71ac:  9a 1a e0 ff  xor  %o3, 0xff, %o5
a00c71b0:  80 a0 00 0d  cmp  %g0, %o5
a00c71b4:  82 40 20 00  addx  %g0, 0, %g1
a00c71b8:  80 8a 00 01  btst  %o0, %g1
a00c71bc:  02 80 00 0a  be  0xa00c71e4
a00c71c0:  80 a6 20 02  cmp  %i0, 2
a00c71c4:  9a 02 ff d0  add  %o3, -48, %o5
a00c71c8:  94 0b 60 ff  and  %o5, 0xff, %o2
a00c71cc:  80 a2 a0 64  cmp  %o2, 0x64
a00c71d0:  18 80 01 15  bgu  0xa00c7624
a00c71d4:  92 10 20 ff  mov  0xff, %o1
a00c71d8:  98 14 e2 90  or  %l3, 0x290, %o4
a00c71dc:  da 2b 20 13  stb  %o5, [ %o4 + 0x13 ]
a00c71e0:  80 a6 20 02  cmp  %i0, 2
a00c71e4:  02 80 00 f1  be  0xa00c75a8
a00c71e8:  80 a6 20 03  cmp  %i0, 3
a00c71ec:  02 80 01 00  be  0xa00c75ec
a00c71f0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c71f4:  c2 0c 20 e8  ldub  [ %l0 + 0xe8 ], %g1	! 0xa802d0e8
a00c71f8:  96 08 60 ff  and  %g1, 0xff, %o3
a00c71fc:  80 a0 00 0b  cmp  %g0, %o3
a00c7200:  a4 40 20 00  addx  %g0, 0, %l2
a00c7204:  82 1a e0 ff  xor  %o3, 0xff, %g1
a00c7208:  80 a0 00 01  cmp  %g0, %g1
a00c720c:  a2 40 20 00  addx  %g0, 0, %l1
a00c7210:  80 8c 80 11  btst  %l2, %l1
a00c7214:  02 bf fd d1  be  0xa00c6958
a00c7218:  80 a6 20 02  cmp  %i0, 2
a00c721c:  9a 02 ff d0  add  %o3, -48, %o5
a00c7220:  92 0b 60 ff  and  %o5, 0xff, %o1
a00c7224:  80 a2 60 64  cmp  %o1, 0x64
a00c7228:  18 80 00 ff  bgu  0xa00c7624
a00c722c:  92 10 20 ff  mov  0xff, %o1
a00c7230:  94 14 e2 90  or  %l3, 0x290, %o2
a00c7234:  80 a6 20 02  cmp  %i0, 2
a00c7238:  12 bf fd ca  bne  0xa00c6960
a00c723c:  da 2a a0 14  stb  %o5, [ %o2 + 0x14 ]
a00c7240:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c7244:  10 bf fd cb  b  0xa00c6970
a00c7248:  c2 0b 60 50  ldub  [ %o5 + 0x50 ], %g1	! 0xa802d050
a00c724c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c7250:  10 bf fd e6  b  0xa00c69e8
a00c7254:  c2 0b 20 53  ldub  [ %o4 + 0x53 ], %g1	! 0xa802d053
a00c7258:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c725c:  10 bf fd fc  b  0xa00c6a4c
a00c7260:  c2 0a e0 51  ldub  [ %o3 + 0x51 ], %g1	! 0xa802d051
a00c7264:  9a 02 ff d0  add  %o3, -48, %o5
a00c7268:  96 14 e2 90  or  %l3, 0x290, %o3
a00c726c:  40 00 33 86  call  0xa00d4084
a00c7270:  da 2a e0 49  stb  %o5, [ %o3 + 0x49 ]
a00c7274:  80 a6 20 02  cmp  %i0, 2
a00c7278:  12 bf fe 20  bne  0xa00c6af8
a00c727c:  80 a6 20 03  cmp  %i0, 3
a00c7280:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c7284:  10 bf fe 20  b  0xa00c6b04
a00c7288:  c2 0b e0 49  ldub  [ %o7 + 0x49 ], %g1	! 0xa802d049
a00c728c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c7290:  10 bf fe 0e  b  0xa00c6ac8
a00c7294:  c2 0c 20 54  ldub  [ %l0 + 0x54 ], %g1	! 0xa802d054
a00c7298:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c729c:  10 bf fe 3d  b  0xa00c6b90
a00c72a0:  c2 0a e0 48  ldub  [ %o3 + 0x48 ], %g1	! 0xa802d048
a00c72a4:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c72a8:  10 bf fe 75  b  0xa00c6c7c
a00c72ac:  c2 0b 60 47  ldub  [ %o5 + 0x47 ], %g1	! 0xa802d047
a00c72b0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c72b4:  10 bf fe 8f  b  0xa00c6cf0
a00c72b8:  c2 0a a0 46  ldub  [ %o2 + 0x46 ], %g1	! 0xa802d046
a00c72bc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c72c0:  10 bf fe a3  b  0xa00c6d4c
a00c72c4:  c2 0a 20 52  ldub  [ %o0 + 0x52 ], %g1	! 0xa802d052
a00c72c8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c72cc:  10 bf fe b9  b  0xa00c6db0
a00c72d0:  c2 0b 20 4a  ldub  [ %o4 + 0x4a ], %g1	! 0xa802d04a
a00c72d4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c72d8:  10 bf fd 8d  b  0xa00c690c
a00c72dc:  c2 0a a0 ad  ldub  [ %o2 + 0xad ], %g1	! 0xa802d0ad
a00c72e0:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c72e4:  10 bf fe d0  b  0xa00c6e24
a00c72e8:  c2 0b 60 4b  ldub  [ %o5 + 0x4b ], %g1	! 0xa802d04b
a00c72ec:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c72f0:  10 bf fd a0  b  0xa00c6970
a00c72f4:  c2 0b 20 a8  ldub  [ %o4 + 0xa8 ], %g1	! 0xa802d0a8
a00c72f8:  80 a2 e0 00  cmp  %o3, 0
a00c72fc:  26 bf fe a8  bl,a   0xa00c6d9c
a00c7300:  80 a6 20 02  cmp  %i0, 2
a00c7304:  40 00 46 74  call  0xa00d8cd4
a00c7308:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00c730c:  10 bf fe a4  b  0xa00c6d9c
a00c7310:  80 a6 20 02  cmp  %i0, 2
a00c7314:  80 a2 40 11  cmp  %o1, %l1
a00c7318:  22 bf fe 71  be,a   0xa00c6cdc
a00c731c:  80 a6 20 02  cmp  %i0, 2
a00c7320:  40 00 46 3f  call  0xa00d8c1c
a00c7324:  e4 2c 20 19  stb  %l2, [ %l0 + 0x19 ]
a00c7328:  10 bf fe 6d  b  0xa00c6cdc
a00c732c:  80 a6 20 02  cmp  %i0, 2
a00c7330:  80 a0 60 00  cmp  %g1, 0
a00c7334:  12 bf ff 2d  bne  0xa00c6fe8
a00c7338:  80 a6 20 02  cmp  %i0, 2
a00c733c:  d6 03 20 ac  ld  [ %o4 + 0xac ], %o3
a00c7340:  13 00 10 00  sethi  %hi(0x400000), %o1
a00c7344:  80 8a c0 09  btst  %o3, %o1
a00c7348:  12 bf ff 28  bne  0xa00c6fe8
a00c734c:  80 a6 20 02  cmp  %i0, 2
a00c7350:  d8 14 60 04  lduh  [ %l1 + 4 ], %o4
a00c7354:  80 8c 00 0c  btst  %l0, %o4
a00c7358:  32 bf ff 24  bne,a   0xa00c6fe8
a00c735c:  80 a6 20 02  cmp  %i0, 2
a00c7360:  7f ff 27 1e  call  0xa0090fd8
a00c7364:  01 00 00 00  nop
a00c7368:  10 bf ff 20  b  0xa00c6fe8
a00c736c:  80 a6 20 02  cmp  %i0, 2
a00c7370:  40 00 3a f3  call  0xa00d5f3c
a00c7374:  c0 22 e0 b0  clr  [ %o3 + 0xb0 ]
a00c7378:  30 bf fd fd  b,a   0xa00c6b6c
a00c737c:  c0 2c 20 4a  clrb  [ %l0 + 0x4a ]
a00c7380:  40 00 3a cb  call  0xa00d5eac
a00c7384:  90 10 20 00  clr  %o0
a00c7388:  10 bf fe 1a  b  0xa00c6bf0
a00c738c:  da 04 21 1c  ld  [ %l0 + 0x11c ], %o5
a00c7390:  29 2a 00 b4  sethi  %hi(0xa802d000), %l4
a00c7394:  a0 15 21 08  or  %l4, 0x108, %l0	! 0xa802d108
a00c7398:  a6 10 20 30  mov  0x30, %l3
a00c739c:  90 10 20 35  mov  0x35, %o0
a00c73a0:  9e 10 20 0d  mov  0xd, %o7
a00c73a4:  94 10 20 36  mov  0x36, %o2
a00c73a8:  9a 10 20 2b  mov  0x2b, %o5
a00c73ac:  d0 2d 21 08  stb  %o0, [ %l4 + 0x108 ]
a00c73b0:  de 2c 20 05  stb  %o7, [ %l0 + 5 ]
a00c73b4:  d4 2c 20 01  stb  %o2, [ %l0 + 1 ]
a00c73b8:  e6 2c 20 03  stb  %l3, [ %l0 + 3 ]
a00c73bc:  da 2c 20 04  stb  %o5, [ %l0 + 4 ]
a00c73c0:  e6 2c 20 02  stb  %l3, [ %l0 + 2 ]
a00c73c4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c73c8:  9a 12 a0 98  or  %o2, 0x98, %o5	! 0xa802d098
a00c73cc:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00c73d0:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00c73d4:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00c73d8:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00c73dc:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00c73e0:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00c73e4:  10 bf ff 4a  b  0xa00c710c
a00c73e8:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00c73ec:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c73f0:  10 bf ff 56  b  0xa00c7148
a00c73f4:  c2 08 60 ae  ldub  [ %g1 + 0xae ], %g1	! 0xa802d0ae
a00c73f8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c73fc:  b0 13 21 28  or  %o4, 0x128, %i0	! 0xa802d128
a00c7400:  a4 10 20 30  mov  0x30, %l2
a00c7404:  a2 10 20 35  mov  0x35, %l1
a00c7408:  96 10 20 0d  mov  0xd, %o3
a00c740c:  92 10 20 36  mov  0x36, %o1
a00c7410:  82 10 20 2b  mov  0x2b, %g1
a00c7414:  e2 2b 21 28  stb  %l1, [ %o4 + 0x128 ]
a00c7418:  d6 2e 20 05  stb  %o3, [ %i0 + 5 ]
a00c741c:  d2 2e 20 01  stb  %o1, [ %i0 + 1 ]
a00c7420:  e4 2e 20 03  stb  %l2, [ %i0 + 3 ]
a00c7424:  c2 2e 20 04  stb  %g1, [ %i0 + 4 ]
a00c7428:  e4 2e 20 02  stb  %l2, [ %i0 + 2 ]
a00c742c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c7430:  b0 14 20 40  or  %l0, 0x40, %i0	! 0xa802d040
a00c7434:  27 2a 00 ac  sethi  %hi(0xa802b000), %l3
a00c7438:  c0 2c e0 9a  clrb  [ %l3 + 0x9a ]	! 0xa802b09a
a00c743c:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c7440:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00c7444:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00c7448:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00c744c:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00c7450:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c7454:  94 10 61 28  or  %g1, 0x128, %o2	! 0xa802d128
a00c7458:  10 bf ff 30  b  0xa00c7118
a00c745c:  90 10 20 02  mov  2, %o0
a00c7460:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c7464:  10 bf fe 87  b  0xa00c6e80
a00c7468:  c2 0a 60 4c  ldub  [ %o1 + 0x4c ], %g1	! 0xa802d04c
a00c746c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c7470:  10 bf fe a5  b  0xa00c6f04
a00c7474:  c2 0a 20 4d  ldub  [ %o0 + 0x4d ], %g1	! 0xa802d04d
a00c7478:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c747c:  10 bf fd 5b  b  0xa00c69e8
a00c7480:  c2 0b e0 ab  ldub  [ %o7 + 0xab ], %g1	! 0xa802d0ab
a00c7484:  7f ff 26 d5  call  0xa0090fd8
a00c7488:  01 00 00 00  nop
a00c748c:  7f ff 26 c8  call  0xa0090fac
a00c7490:  01 00 00 00  nop
a00c7494:  10 bf fe cb  b  0xa00c6fc0
a00c7498:  98 14 e2 90  or  %l3, 0x290, %o4
a00c749c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c74a0:  10 bf fe b0  b  0xa00c6f60
a00c74a4:  c2 0b e0 4e  ldub  [ %o7 + 0x4e ], %g1	! 0xa802d04e
a00c74a8:  40 01 76 a7  call  0xa0124f44
a00c74ac:  01 00 00 00  nop
a00c74b0:  40 00 47 53  call  0xa00d91fc
a00c74b4:  90 10 20 00  clr  %o0	! 0x0
a00c74b8:  40 00 4b 33  call  0xa00da184
a00c74bc:  01 00 00 00  nop
a00c74c0:  e8 04 20 a8  ld  [ %l0 + 0xa8 ], %l4
a00c74c4:  80 8d 20 80  btst  0x80, %l4
a00c74c8:  02 bf fe ea  be  0xa00c7070
a00c74cc:  01 00 00 00  nop
a00c74d0:  d0 04 20 b0  ld  [ %l0 + 0xb0 ], %o0
a00c74d4:  80 a2 20 00  cmp  %o0, 0
a00c74d8:  32 bf fe e6  bne,a   0xa00c7070
a00c74dc:  c0 24 20 b0  clr  [ %l0 + 0xb0 ]
a00c74e0:  30 bf fe e4  b,a   0xa00c7070
a00c74e4:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c74e8:  10 bf fd 59  b  0xa00c6a4c
a00c74ec:  c2 0b 60 a9  ldub  [ %o5 + 0xa9 ], %g1	! 0xa802d0a9
a00c74f0:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c74f4:  10 bf fe c3  b  0xa00c7000
a00c74f8:  c2 0c 60 4f  ldub  [ %l1 + 0x4f ], %g1	! 0xa802d04f
a00c74fc:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c7500:  10 bf fd 72  b  0xa00c6ac8
a00c7504:  c2 0c 60 ac  ldub  [ %l1 + 0xac ], %g1	! 0xa802d0ac
a00c7508:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c750c:  10 bf fd 7e  b  0xa00c6b04
a00c7510:  c2 0b 20 a1  ldub  [ %o4 + 0xa1 ], %g1	! 0xa802d0a1
a00c7514:  10 bf fd 9f  b  0xa00c6b90
a00c7518:  c2 0c a0 a0  ldub  [ %l2 + 0xa0 ], %g1
a00c751c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c7520:  10 bf fd d7  b  0xa00c6c7c
a00c7524:  c2 0b e0 9f  ldub  [ %o7 + 0x9f ], %g1	! 0xa802d09f
a00c7528:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c752c:  10 bf fd f1  b  0xa00c6cf0
a00c7530:  c2 0b 60 9e  ldub  [ %o5 + 0x9e ], %g1	! 0xa802d09e
a00c7534:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c7538:  10 bf fe 05  b  0xa00c6d4c
a00c753c:  c2 0a 60 aa  ldub  [ %o1 + 0xaa ], %g1	! 0xa802d0aa
a00c7540:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c7544:  10 bf fe 1b  b  0xa00c6db0
a00c7548:  c2 0a 20 a2  ldub  [ %o0 + 0xa2 ], %g1	! 0xa802d0a2
a00c754c:  10 bf fe 36  b  0xa00c6e24
a00c7550:  c2 0b e0 a3  ldub  [ %o7 + 0xa3 ], %g1
a00c7554:  10 bf fe 4b  b  0xa00c6e80
a00c7558:  c2 0a a0 a4  ldub  [ %o2 + 0xa4 ], %g1
a00c755c:  10 bf fe 6a  b  0xa00c6f04
a00c7560:  c2 0c a0 a5  ldub  [ %l2 + 0xa5 ], %g1
a00c7564:  10 bf fe 7f  b  0xa00c6f60
a00c7568:  c2 0c 60 a6  ldub  [ %l1 + 0xa6 ], %g1
a00c756c:  10 bf fe a5  b  0xa00c7000
a00c7570:  c2 0c 20 a7  ldub  [ %l0 + 0xa7 ], %g1
a00c7574:  40 00 41 f5  call  0xa00d7d48
a00c7578:  01 00 00 00  nop
a00c757c:  80 a2 20 00  cmp  %o0, 0
a00c7580:  02 bf fd d7  be  0xa00c6cdc
a00c7584:  80 a6 20 02  cmp  %i0, 2
a00c7588:  10 bf fd d1  b  0xa00c6ccc
a00c758c:  d0 0c 20 1f  ldub  [ %l0 + 0x1f ], %o0
a00c7590:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00c7594:  10 bf fe ed  b  0xa00c7148
a00c7598:  c2 0c a0 56  ldub  [ %l2 + 0x56 ], %g1	! 0xa802d056
a00c759c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c75a0:  10 bf ff 00  b  0xa00c71a0
a00c75a4:  c2 0c 20 57  ldub  [ %l0 + 0x57 ], %g1	! 0xa802d057
a00c75a8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c75ac:  10 bf ff 13  b  0xa00c71f8
a00c75b0:  c2 0a e0 58  ldub  [ %o3 + 0x58 ], %g1	! 0xa802d058
a00c75b4:  40 00 47 12  call  0xa00d91fc
a00c75b8:  90 10 20 00  clr  %o0
a00c75bc:  90 10 20 00  clr  %o0
a00c75c0:  40 02 03 2a  call  0xa0148268
a00c75c4:  92 10 20 01  mov  1, %o1
a00c75c8:  90 10 20 01  mov  1, %o0
a00c75cc:  40 02 03 27  call  0xa0148268
a00c75d0:  92 10 20 01  mov  1, %o1
a00c75d4:  40 00 4b 20  call  0xa00da254
a00c75d8:  01 00 00 00  nop
a00c75dc:  30 bf fd 97  b,a   0xa00c6c38
a00c75e0:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c75e4:  10 bf fe ef  b  0xa00c71a0
a00c75e8:  c2 0c 60 af  ldub  [ %l1 + 0xaf ], %g1	! 0xa802d0af
a00c75ec:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c75f0:  10 bf ff 02  b  0xa00c71f8
a00c75f4:  c2 0b e0 b0  ldub  [ %o7 + 0xb0 ], %g1	! 0xa802d0b0
a00c75f8:  a4 2b 40 01  andn  %o5, %g1, %l2
a00c75fc:  40 00 46 80  call  0xa00d8ffc
a00c7600:  e4 24 21 1c  st  %l2, [ %l0 + 0x11c ]
a00c7604:  30 bf fd 82  b,a   0xa00c6c0c
a00c7608:  40 00 46 fd  call  0xa00d91fc
a00c760c:  90 10 20 00  clr  %o0
a00c7610:  c0 2c 21 a4  clrb  [ %l0 + 0x1a4 ]
a00c7614:  7f fe ee b8  call  0xa00830f4
a00c7618:  90 10 20 00  clr  %o0
a00c761c:  10 bf fd 93  b  0xa00c6c68
a00c7620:  80 a6 20 02  cmp  %i0, 2
a00c7624:  81 c7 e0 08  ret
a00c7628:  91 e8 00 09  restore  %g0, %o1, %o0
