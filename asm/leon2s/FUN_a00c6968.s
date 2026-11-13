# leon2s FUN_a00c6968 0xa00c6968-0xa00c6c74 (780 bytes)
a00c6968:  9d e3 bd 88  save  %sp, -632, %sp
a00c696c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c6970:  80 a6 20 01  cmp  %i0, 1
a00c6974:  a0 10 20 00  clr  %l0
a00c6978:  12 80 00 43  bne  0xa00c6a84
a00c697c:  a2 10 20 00  clr  %l1
a00c6980:  b0 07 bd e8  add  %fp, -536, %i0
a00c6984:  90 10 21 42  mov  0x142, %o0
a00c6988:  92 10 20 03  mov  3, %o1
a00c698c:  40 3b 5a 55  call  0xa0f9d2e0
a00c6990:  94 10 00 18  mov  %i0, %o2
a00c6994:  c2 0f bd ea  ldub  [ %fp + -534 ], %g1
a00c6998:  da 0f bd e9  ldub  [ %fp + -535 ], %o5
a00c699c:  83 28 60 08  sll  %g1, 8, %g1
a00c69a0:  82 00 40 0d  add  %g1, %o5, %g1
a00c69a4:  83 28 60 08  sll  %g1, 8, %g1
a00c69a8:  da 0f bd e8  ldub  [ %fp + -536 ], %o5
a00c69ac:  a6 00 40 0d  add  %g1, %o5, %l3
a00c69b0:  90 10 20 20  mov  0x20, %o0
a00c69b4:  92 10 21 18  mov  0x118, %o1
a00c69b8:  40 3b 5a 4a  call  0xa0f9d2e0
a00c69bc:  94 10 00 18  mov  %i0, %o2
a00c69c0:  98 10 20 00  clr  %o4
a00c69c4:  a4 07 bf f8  add  %fp, -8, %l2
a00c69c8:  83 2b 20 10  sll  %o4, 0x10, %g1
a00c69cc:  83 30 60 10  srl  %g1, 0x10, %g1
a00c69d0:  82 04 80 01  add  %l2, %g1, %g1
a00c69d4:  da 48 7d f0  ldsb  [ %g1 + -528 ], %o5
a00c69d8:  80 a3 60 00  cmp  %o5, 0
a00c69dc:  da 08 7d f0  ldub  [ %g1 + -528 ], %o5
a00c69e0:  82 38 00 0d  xnor  %g0, %o5, %g1
a00c69e4:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00c69e8:  06 80 00 04  bl  0xa00c69f8
a00c69ec:  82 08 60 ff  and  %g1, 0xff, %g1
a00c69f0:  10 80 00 04  b  0xa00c6a00
a00c69f4:  a0 04 00 0d  add  %l0, %o5, %l0
a00c69f8:  a0 04 00 01  add  %l0, %g1, %l0
a00c69fc:  a2 04 60 01  inc  %l1
a00c6a00:  9a 03 20 01  add  %o4, 1, %o5
a00c6a04:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c6a08:  83 30 60 10  srl  %g1, 0x10, %g1
a00c6a0c:  80 a0 61 17  cmp  %g1, 0x117
a00c6a10:  08 bf ff ee  bleu  0xa00c69c8
a00c6a14:  98 10 00 0d  mov  %o5, %o4
a00c6a18:  94 10 00 18  mov  %i0, %o2
a00c6a1c:  90 10 21 38  mov  0x138, %o0
a00c6a20:  40 3b 5a 30  call  0xa0f9d2e0
a00c6a24:  92 10 20 05  mov  5, %o1
a00c6a28:  98 10 20 00  clr  %o4
a00c6a2c:  83 2b 20 10  sll  %o4, 0x10, %g1
a00c6a30:  83 30 60 10  srl  %g1, 0x10, %g1
a00c6a34:  82 04 80 01  add  %l2, %g1, %g1
a00c6a38:  da 48 7d f0  ldsb  [ %g1 + -528 ], %o5
a00c6a3c:  80 a3 60 00  cmp  %o5, 0
a00c6a40:  da 08 7d f0  ldub  [ %g1 + -528 ], %o5
a00c6a44:  82 38 00 0d  xnor  %g0, %o5, %g1
a00c6a48:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00c6a4c:  06 80 00 04  bl  0xa00c6a5c
a00c6a50:  82 08 60 ff  and  %g1, 0xff, %g1
a00c6a54:  10 80 00 04  b  0xa00c6a64
a00c6a58:  a0 04 00 0d  add  %l0, %o5, %l0
a00c6a5c:  a0 04 00 01  add  %l0, %g1, %l0
a00c6a60:  a2 04 60 01  inc  %l1
a00c6a64:  9a 03 20 01  add  %o4, 1, %o5
a00c6a68:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c6a6c:  83 30 60 10  srl  %g1, 0x10, %g1
a00c6a70:  80 a0 60 04  cmp  %g1, 4
a00c6a74:  08 bf ff ee  bleu  0xa00c6a2c
a00c6a78:  98 10 00 0d  mov  %o5, %o4
a00c6a7c:  10 80 00 77  b  0xa00c6c58
a00c6a80:  83 2c 60 10  sll  %l1, 0x10, %g1
a00c6a84:  80 a6 20 02  cmp  %i0, 2
a00c6a88:  12 80 00 79  bne  0xa00c6c6c
a00c6a8c:  b0 10 20 00  clr  %i0
a00c6a90:  b0 07 bd e8  add  %fp, -536, %i0
a00c6a94:  90 10 25 8a  mov  0x58a, %o0
a00c6a98:  92 10 20 03  mov  3, %o1
a00c6a9c:  40 3b 5a 11  call  0xa0f9d2e0
a00c6aa0:  94 10 00 18  mov  %i0, %o2
a00c6aa4:  c2 0f bd ea  ldub  [ %fp + -534 ], %g1
a00c6aa8:  da 0f bd e9  ldub  [ %fp + -535 ], %o5
a00c6aac:  83 28 60 08  sll  %g1, 8, %g1
a00c6ab0:  82 00 40 0d  add  %g1, %o5, %g1
a00c6ab4:  83 28 60 08  sll  %g1, 8, %g1
a00c6ab8:  da 0f bd e8  ldub  [ %fp + -536 ], %o5
a00c6abc:  a6 00 40 0d  add  %g1, %o5, %l3
a00c6ac0:  90 10 22 70  mov  0x270, %o0
a00c6ac4:  92 10 20 10  mov  0x10, %o1
a00c6ac8:  40 3b 5a 06  call  0xa0f9d2e0
a00c6acc:  94 10 00 18  mov  %i0, %o2
a00c6ad0:  98 10 20 00  clr  %o4
a00c6ad4:  a4 07 bf f8  add  %fp, -8, %l2
a00c6ad8:  83 2b 20 10  sll  %o4, 0x10, %g1
a00c6adc:  83 30 60 10  srl  %g1, 0x10, %g1
a00c6ae0:  82 04 80 01  add  %l2, %g1, %g1
a00c6ae4:  da 48 7d f0  ldsb  [ %g1 + -528 ], %o5
a00c6ae8:  80 a3 60 00  cmp  %o5, 0
a00c6aec:  da 08 7d f0  ldub  [ %g1 + -528 ], %o5
a00c6af0:  82 38 00 0d  xnor  %g0, %o5, %g1
a00c6af4:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00c6af8:  06 80 00 04  bl  0xa00c6b08
a00c6afc:  82 08 60 ff  and  %g1, 0xff, %g1
a00c6b00:  10 80 00 04  b  0xa00c6b10
a00c6b04:  a0 04 00 0d  add  %l0, %o5, %l0
a00c6b08:  a0 04 00 01  add  %l0, %g1, %l0
a00c6b0c:  a2 04 60 01  inc  %l1
a00c6b10:  9a 03 20 01  add  %o4, 1, %o5
a00c6b14:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c6b18:  83 30 60 10  srl  %g1, 0x10, %g1
a00c6b1c:  80 a0 60 0f  cmp  %g1, 0xf
a00c6b20:  08 bf ff ee  bleu  0xa00c6ad8
a00c6b24:  98 10 00 0d  mov  %o5, %o4
a00c6b28:  90 10 22 80  mov  0x280, %o0
a00c6b2c:  92 10 22 0a  mov  0x20a, %o1
a00c6b30:  40 3b 59 ec  call  0xa0f9d2e0
a00c6b34:  94 10 00 18  mov  %i0, %o2
a00c6b38:  98 10 20 00  clr  %o4
a00c6b3c:  83 2b 20 10  sll  %o4, 0x10, %g1
a00c6b40:  83 30 60 10  srl  %g1, 0x10, %g1
a00c6b44:  82 04 80 01  add  %l2, %g1, %g1
a00c6b48:  da 48 7d f0  ldsb  [ %g1 + -528 ], %o5
a00c6b4c:  80 a3 60 00  cmp  %o5, 0
a00c6b50:  da 08 7d f0  ldub  [ %g1 + -528 ], %o5
a00c6b54:  82 38 00 0d  xnor  %g0, %o5, %g1
a00c6b58:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00c6b5c:  06 80 00 04  bl  0xa00c6b6c
a00c6b60:  82 08 60 ff  and  %g1, 0xff, %g1
a00c6b64:  10 80 00 04  b  0xa00c6b74
a00c6b68:  a0 04 00 0d  add  %l0, %o5, %l0
a00c6b6c:  a0 04 00 01  add  %l0, %g1, %l0
a00c6b70:  a2 04 60 01  inc  %l1
a00c6b74:  9a 03 20 01  add  %o4, 1, %o5
a00c6b78:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c6b7c:  83 30 60 10  srl  %g1, 0x10, %g1
a00c6b80:  80 a0 62 09  cmp  %g1, 0x209
a00c6b84:  08 bf ff ee  bleu  0xa00c6b3c
a00c6b88:  98 10 00 0d  mov  %o5, %o4
a00c6b8c:  90 10 24 8a  mov  0x48a, %o0
a00c6b90:  92 10 20 80  mov  0x80, %o1
a00c6b94:  40 3b 59 d3  call  0xa0f9d2e0
a00c6b98:  94 10 00 18  mov  %i0, %o2
a00c6b9c:  98 10 20 00  clr  %o4
a00c6ba0:  83 2b 20 10  sll  %o4, 0x10, %g1
a00c6ba4:  83 30 60 10  srl  %g1, 0x10, %g1
a00c6ba8:  82 04 80 01  add  %l2, %g1, %g1
a00c6bac:  da 48 7d f0  ldsb  [ %g1 + -528 ], %o5
a00c6bb0:  80 a3 60 00  cmp  %o5, 0
a00c6bb4:  da 08 7d f0  ldub  [ %g1 + -528 ], %o5
a00c6bb8:  82 38 00 0d  xnor  %g0, %o5, %g1
a00c6bbc:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00c6bc0:  06 80 00 04  bl  0xa00c6bd0
a00c6bc4:  82 08 60 ff  and  %g1, 0xff, %g1
a00c6bc8:  10 80 00 04  b  0xa00c6bd8
a00c6bcc:  a0 04 00 0d  add  %l0, %o5, %l0
a00c6bd0:  a0 04 00 01  add  %l0, %g1, %l0
a00c6bd4:  a2 04 60 01  inc  %l1
a00c6bd8:  9a 03 20 01  add  %o4, 1, %o5
a00c6bdc:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c6be0:  83 30 60 10  srl  %g1, 0x10, %g1
a00c6be4:  80 a0 60 7f  cmp  %g1, 0x7f
a00c6be8:  08 bf ff ee  bleu  0xa00c6ba0
a00c6bec:  98 10 00 0d  mov  %o5, %o4
a00c6bf0:  94 10 00 18  mov  %i0, %o2
a00c6bf4:  90 10 25 0a  mov  0x50a, %o0
a00c6bf8:  40 3b 59 ba  call  0xa0f9d2e0
a00c6bfc:  92 10 20 80  mov  0x80, %o1
a00c6c00:  98 10 20 00  clr  %o4
a00c6c04:  83 2b 20 10  sll  %o4, 0x10, %g1
a00c6c08:  83 30 60 10  srl  %g1, 0x10, %g1
a00c6c0c:  82 04 80 01  add  %l2, %g1, %g1
a00c6c10:  da 48 7d f0  ldsb  [ %g1 + -528 ], %o5
a00c6c14:  80 a3 60 00  cmp  %o5, 0
a00c6c18:  da 08 7d f0  ldub  [ %g1 + -528 ], %o5
a00c6c1c:  82 38 00 0d  xnor  %g0, %o5, %g1
a00c6c20:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00c6c24:  06 80 00 04  bl  0xa00c6c34
a00c6c28:  82 08 60 ff  and  %g1, 0xff, %g1
a00c6c2c:  10 80 00 04  b  0xa00c6c3c
a00c6c30:  a0 04 00 0d  add  %l0, %o5, %l0
a00c6c34:  a0 04 00 01  add  %l0, %g1, %l0
a00c6c38:  a2 04 60 01  inc  %l1
a00c6c3c:  9a 03 20 01  add  %o4, 1, %o5
a00c6c40:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c6c44:  83 30 60 10  srl  %g1, 0x10, %g1
a00c6c48:  80 a0 60 7f  cmp  %g1, 0x7f
a00c6c4c:  08 bf ff ee  bleu  0xa00c6c04
a00c6c50:  98 10 00 0d  mov  %o5, %o4
a00c6c54:  83 2c 60 10  sll  %l1, 0x10, %g1
a00c6c58:  83 30 60 10  srl  %g1, 0x10, %g1
a00c6c5c:  82 04 00 01  add  %l0, %g1, %g1
a00c6c60:  82 1c c0 01  xor  %l3, %g1, %g1
a00c6c64:  80 a0 00 01  cmp  %g0, %g1
a00c6c68:  b0 60 3f ff  subx  %g0, -1, %i0
a00c6c6c:  81 c7 e0 08  ret
a00c6c70:  81 e8 00 00  restore
