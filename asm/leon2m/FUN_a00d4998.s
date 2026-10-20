# leon2m FUN_a00d4998 0xa00d4998-0xa00d5748 (112 bytes)
a00d4998:  9d e3 bf 98  save  %sp, -104, %sp
a00d499c:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a00d49a0:  ba 16 e2 90  or  %i3, 0x290, %i5	! 0xa802d290
a00d49a4:  c2 07 60 a8  ld  [ %i5 + 0xa8 ], %g1
a00d49a8:  80 88 68 00  btst  0x800, %g1
a00d49ac:  32 80 00 31  bne,a   0xa00d4a70
a00d49b0:  fa 0f 61 81  ldub  [ %i5 + 0x181 ], %i5
a00d49b4:  c2 0f 61 82  ldub  [ %i5 + 0x182 ], %g1
a00d49b8:  82 08 60 ff  and  %g1, 0xff, %g1
a00d49bc:  80 a0 60 0c  cmp  %g1, 0xc
a00d49c0:  18 80 03 5d  bgu  0xa00d5734
a00d49c4:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00d49c8:  33 00 01 ce  sethi  %hi(0x73800), %i1
a00d49cc:  b1 28 60 02  sll  %g1, 2, %i0
a00d49d0:  ba 16 62 30  or  %i1, 0x230, %i5
a00d49d4:  f8 07 40 18  ld  [ %i5 + %i0 ], %i4
a00d49d8:  81 c7 00 00  jmp  %i4
a00d49dc:  01 00 00 00  nop
a00d49e0:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d49e4:  f0 10 63 fe  lduh  [ %g1 + 0x3fe ], %i0	! 0xa802cffe
a00d49e8:  80 8e 20 80  btst  0x80, %i0
a00d49ec:  02 80 02 e2  be  0xa00d5574
a00d49f0:  82 16 e2 90  or  %i3, 0x290, %g1
a00d49f4:  ba 16 e2 90  or  %i3, 0x290, %i5
a00d49f8:  f8 07 61 1c  ld  [ %i5 + 0x11c ], %i4
a00d49fc:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d4a00:  b3 2e e0 08  sll  %i3, 8, %i1
a00d4a04:  b4 0f 3e ff  and  %i4, -257, %i2
a00d4a08:  b4 16 80 19  or  %i2, %i1, %i2
a00d4a0c:  b1 36 a0 04  srl  %i2, 4, %i0
a00d4a10:  b8 0e 20 01  and  %i0, 1, %i4
a00d4a14:  c2 07 61 20  ld  [ %i5 + 0x120 ], %g1
a00d4a18:  37 00 00 08  sethi  %hi(0x2000), %i3
a00d4a1c:  b0 28 40 1b  andn  %g1, %i3, %i0
a00d4a20:  b3 2f 20 0d  sll  %i4, 0xd, %i1
a00d4a24:  b6 16 00 19  or  %i0, %i1, %i3
a00d4a28:  c2 17 60 34  lduh  [ %i5 + 0x34 ], %g1
a00d4a2c:  82 08 60 0f  and  %g1, 0xf, %g1
a00d4a30:  f8 0f 60 09  ldub  [ %i5 + 9 ], %i4
a00d4a34:  f2 0f 60 0a  ldub  [ %i5 + 0xa ], %i1
a00d4a38:  f0 0f 60 19  ldub  [ %i5 + 0x19 ], %i0
a00d4a3c:  de 0f 61 5b  ldub  [ %i5 + 0x15b ], %o7
a00d4a40:  da 07 60 b0  ld  [ %i5 + 0xb0 ], %o5
a00d4a44:  d8 0f 60 49  ldub  [ %i5 + 0x49 ], %o4
a00d4a48:  f6 27 61 20  st  %i3, [ %i5 + 0x120 ]
a00d4a4c:  f8 2f 60 6d  stb  %i4, [ %i5 + 0x6d ]
a00d4a50:  f2 2f 60 87  stb  %i1, [ %i5 + 0x87 ]
a00d4a54:  f0 2f 60 a5  stb  %i0, [ %i5 + 0xa5 ]
a00d4a58:  de 2f 61 71  stb  %o7, [ %i5 + 0x171 ]
a00d4a5c:  da 27 61 0c  st  %o5, [ %i5 + 0x10c ]
a00d4a60:  c2 2f 61 d0  stb  %g1, [ %i5 + 0x1d0 ]
a00d4a64:  d8 2f 61 38  stb  %o4, [ %i5 + 0x138 ]
a00d4a68:  10 80 03 32  b  0xa00d5730
a00d4a6c:  f4 27 61 1c  st  %i2, [ %i5 + 0x11c ]
a00d4a70:  80 a7 60 00  cmp  %i5, 0
a00d4a74:  02 bf ff d1  be  0xa00d49b8
a00d4a78:  82 10 20 01  mov  1, %g1
a00d4a7c:  10 bf ff cf  b  0xa00d49b8
a00d4a80:  82 07 60 05  add  %i5, 5, %g1
a00d4a84:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d4a88:  f0 10 63 fe  lduh  [ %g1 + 0x3fe ], %i0	! 0xa802cffe
a00d4a8c:  80 8e 20 80  btst  0x80, %i0
a00d4a90:  02 80 01 e5  be  0xa00d5224
a00d4a94:  82 16 e2 90  or  %i3, 0x290, %g1
a00d4a98:  ba 16 e2 90  or  %i3, 0x290, %i5
a00d4a9c:  f8 07 61 1c  ld  [ %i5 + 0x11c ], %i4
a00d4aa0:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d4aa4:  b3 2e e0 0b  sll  %i3, 0xb, %i1
a00d4aa8:  b4 0f 37 ff  and  %i4, -2049, %i2
a00d4aac:  b4 16 80 19  or  %i2, %i1, %i2
a00d4ab0:  b1 36 a0 04  srl  %i2, 4, %i0
a00d4ab4:  b8 0e 20 01  and  %i0, 1, %i4
a00d4ab8:  c2 07 61 20  ld  [ %i5 + 0x120 ], %g1
a00d4abc:  37 00 00 40  sethi  %hi(0x10000), %i3
a00d4ac0:  b0 28 40 1b  andn  %g1, %i3, %i0
a00d4ac4:  b3 2f 20 10  sll  %i4, 0x10, %i1
a00d4ac8:  b6 16 00 19  or  %i0, %i1, %i3
a00d4acc:  c2 17 60 34  lduh  [ %i5 + 0x34 ], %g1
a00d4ad0:  82 08 60 0f  and  %g1, 0xf, %g1
a00d4ad4:  f8 0f 60 09  ldub  [ %i5 + 9 ], %i4
a00d4ad8:  f2 0f 60 0a  ldub  [ %i5 + 0xa ], %i1
a00d4adc:  f0 0f 60 19  ldub  [ %i5 + 0x19 ], %i0
a00d4ae0:  de 0f 61 5b  ldub  [ %i5 + 0x15b ], %o7
a00d4ae4:  da 07 60 b0  ld  [ %i5 + 0xb0 ], %o5
a00d4ae8:  d8 0f 60 49  ldub  [ %i5 + 0x49 ], %o4
a00d4aec:  f6 27 61 20  st  %i3, [ %i5 + 0x120 ]
a00d4af0:  f8 2f 60 71  stb  %i4, [ %i5 + 0x71 ]
a00d4af4:  f2 2f 60 8b  stb  %i1, [ %i5 + 0x8b ]
a00d4af8:  f0 2f 60 a9  stb  %i0, [ %i5 + 0xa9 ]
a00d4afc:  de 2f 61 75  stb  %o7, [ %i5 + 0x175 ]
a00d4b00:  da 27 61 00  st  %o5, [ %i5 + 0x100 ]
a00d4b04:  c2 2f 61 d4  stb  %g1, [ %i5 + 0x1d4 ]
a00d4b08:  d8 2f 61 3c  stb  %o4, [ %i5 + 0x13c ]
a00d4b0c:  10 80 03 09  b  0xa00d5730
a00d4b10:  f4 27 61 1c  st  %i2, [ %i5 + 0x11c ]
a00d4b14:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d4b18:  f0 10 63 fe  lduh  [ %g1 + 0x3fe ], %i0	! 0xa802cffe
a00d4b1c:  80 8e 20 80  btst  0x80, %i0
a00d4b20:  02 80 01 83  be  0xa00d512c
a00d4b24:  82 16 e2 90  or  %i3, 0x290, %g1
a00d4b28:  f0 00 61 1c  ld  [ %g1 + 0x11c ], %i0
a00d4b2c:  b3 36 20 1f  srl  %i0, 0x1f, %i1
a00d4b30:  b5 2e 60 05  sll  %i1, 5, %i2
a00d4b34:  b6 0e 3f df  and  %i0, -33, %i3
a00d4b38:  b6 16 c0 1a  or  %i3, %i2, %i3
a00d4b3c:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d4b40:  b9 2e e0 06  sll  %i3, 6, %i4
a00d4b44:  b2 0f 24 00  and  %i4, 0x400, %i1
a00d4b48:  b0 0f 7b ff  and  %i5, -1025, %i0
a00d4b4c:  ba 16 00 19  or  %i0, %i1, %i5
a00d4b50:  f4 10 60 34  lduh  [ %g1 + 0x34 ], %i2
a00d4b54:  b4 0e a0 0f  and  %i2, 0xf, %i2
a00d4b58:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d4b5c:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d4b60:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d4b64:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d4b68:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d4b6c:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d4b70:  fa 20 61 20  st  %i5, [ %g1 + 0x120 ]
a00d4b74:  f8 28 60 70  stb  %i4, [ %g1 + 0x70 ]
a00d4b78:  f2 28 60 8a  stb  %i1, [ %g1 + 0x8a ]
a00d4b7c:  f0 28 60 a8  stb  %i0, [ %g1 + 0xa8 ]
a00d4b80:  de 28 61 74  stb  %o7, [ %g1 + 0x174 ]
a00d4b84:  da 20 61 18  st  %o5, [ %g1 + 0x118 ]
a00d4b88:  f4 28 61 d3  stb  %i2, [ %g1 + 0x1d3 ]
a00d4b8c:  d8 28 61 3b  stb  %o4, [ %g1 + 0x13b ]
a00d4b90:  10 80 02 e8  b  0xa00d5730
a00d4b94:  f6 20 61 1c  st  %i3, [ %g1 + 0x11c ]
a00d4b98:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d4b9c:  f0 10 63 fe  lduh  [ %g1 + 0x3fe ], %i0	! 0xa802cffe
a00d4ba0:  80 8e 20 80  btst  0x80, %i0
a00d4ba4:  02 80 01 bf  be  0xa00d52a0
a00d4ba8:  82 16 e2 90  or  %i3, 0x290, %g1
a00d4bac:  f0 00 61 1c  ld  [ %g1 + 0x11c ], %i0
a00d4bb0:  b3 36 20 1f  srl  %i0, 0x1f, %i1
a00d4bb4:  b5 2e 60 06  sll  %i1, 6, %i2
a00d4bb8:  b6 0e 3f bf  and  %i0, -65, %i3
a00d4bbc:  b6 16 c0 1a  or  %i3, %i2, %i3
a00d4bc0:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d4bc4:  b9 2e e0 07  sll  %i3, 7, %i4
a00d4bc8:  b2 0f 28 00  and  %i4, 0x800, %i1
a00d4bcc:  b0 0f 77 ff  and  %i5, -2049, %i0
a00d4bd0:  ba 16 00 19  or  %i0, %i1, %i5
a00d4bd4:  f4 10 60 34  lduh  [ %g1 + 0x34 ], %i2
a00d4bd8:  b4 0e a0 0f  and  %i2, 0xf, %i2
a00d4bdc:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d4be0:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d4be4:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d4be8:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d4bec:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d4bf0:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d4bf4:  fa 20 61 20  st  %i5, [ %g1 + 0x120 ]
a00d4bf8:  f8 28 60 6f  stb  %i4, [ %g1 + 0x6f ]
a00d4bfc:  f2 28 60 89  stb  %i1, [ %g1 + 0x89 ]
a00d4c00:  f0 28 60 a7  stb  %i0, [ %g1 + 0xa7 ]
a00d4c04:  de 28 61 73  stb  %o7, [ %g1 + 0x173 ]
a00d4c08:  da 20 61 14  st  %o5, [ %g1 + 0x114 ]
a00d4c0c:  f4 28 61 d2  stb  %i2, [ %g1 + 0x1d2 ]
a00d4c10:  d8 28 61 3a  stb  %o4, [ %g1 + 0x13a ]
a00d4c14:  10 80 02 c7  b  0xa00d5730
a00d4c18:  f6 20 61 1c  st  %i3, [ %g1 + 0x11c ]
a00d4c1c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d4c20:  f0 10 63 fe  lduh  [ %g1 + 0x3fe ], %i0	! 0xa802cffe
a00d4c24:  80 8e 20 80  btst  0x80, %i0
a00d4c28:  02 80 01 bd  be  0xa00d531c
a00d4c2c:  82 16 e2 90  or  %i3, 0x290, %g1
a00d4c30:  ba 16 e2 90  or  %i3, 0x290, %i5
a00d4c34:  f8 07 61 1c  ld  [ %i5 + 0x11c ], %i4
a00d4c38:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d4c3c:  b3 2e e0 07  sll  %i3, 7, %i1
a00d4c40:  b4 0f 3f 7f  and  %i4, -129, %i2
a00d4c44:  b4 16 80 19  or  %i2, %i1, %i2
a00d4c48:  b1 36 a0 04  srl  %i2, 4, %i0
a00d4c4c:  b8 0e 20 01  and  %i0, 1, %i4
a00d4c50:  c2 07 61 20  ld  [ %i5 + 0x120 ], %g1
a00d4c54:  37 00 00 04  sethi  %hi(0x1000), %i3
a00d4c58:  b0 28 40 1b  andn  %g1, %i3, %i0
a00d4c5c:  b3 2f 20 0c  sll  %i4, 0xc, %i1
a00d4c60:  b6 16 00 19  or  %i0, %i1, %i3
a00d4c64:  c2 17 60 34  lduh  [ %i5 + 0x34 ], %g1
a00d4c68:  82 08 60 0f  and  %g1, 0xf, %g1
a00d4c6c:  f8 0f 60 09  ldub  [ %i5 + 9 ], %i4
a00d4c70:  f2 0f 60 0a  ldub  [ %i5 + 0xa ], %i1
a00d4c74:  f0 0f 60 19  ldub  [ %i5 + 0x19 ], %i0
a00d4c78:  de 0f 61 5b  ldub  [ %i5 + 0x15b ], %o7
a00d4c7c:  da 07 60 b0  ld  [ %i5 + 0xb0 ], %o5
a00d4c80:  d8 0f 60 49  ldub  [ %i5 + 0x49 ], %o4
a00d4c84:  f6 27 61 20  st  %i3, [ %i5 + 0x120 ]
a00d4c88:  f8 2f 60 6e  stb  %i4, [ %i5 + 0x6e ]
a00d4c8c:  f2 2f 60 88  stb  %i1, [ %i5 + 0x88 ]
a00d4c90:  f0 2f 60 a6  stb  %i0, [ %i5 + 0xa6 ]
a00d4c94:  de 2f 61 72  stb  %o7, [ %i5 + 0x172 ]
a00d4c98:  da 27 61 10  st  %o5, [ %i5 + 0x110 ]
a00d4c9c:  c2 2f 61 d1  stb  %g1, [ %i5 + 0x1d1 ]
a00d4ca0:  d8 2f 61 39  stb  %o4, [ %i5 + 0x139 ]
a00d4ca4:  10 80 02 a3  b  0xa00d5730
a00d4ca8:  f4 27 61 1c  st  %i2, [ %i5 + 0x11c ]
a00d4cac:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d4cb0:  f0 10 63 fe  lduh  [ %g1 + 0x3fe ], %i0	! 0xa802cffe
a00d4cb4:  80 8e 20 80  btst  0x80, %i0
a00d4cb8:  02 80 01 b8  be  0xa00d5398
a00d4cbc:  82 16 e2 90  or  %i3, 0x290, %g1
a00d4cc0:  ba 16 e2 90  or  %i3, 0x290, %i5
a00d4cc4:  f8 07 61 1c  ld  [ %i5 + 0x11c ], %i4
a00d4cc8:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d4ccc:  b3 2e e0 09  sll  %i3, 9, %i1
a00d4cd0:  b4 0f 3d ff  and  %i4, -513, %i2
a00d4cd4:  b4 16 80 19  or  %i2, %i1, %i2
a00d4cd8:  b1 36 a0 04  srl  %i2, 4, %i0
a00d4cdc:  b8 0e 20 01  and  %i0, 1, %i4
a00d4ce0:  c2 07 61 20  ld  [ %i5 + 0x120 ], %g1
a00d4ce4:  37 00 00 10  sethi  %hi(0x4000), %i3
a00d4ce8:  b0 28 40 1b  andn  %g1, %i3, %i0
a00d4cec:  b3 2f 20 0e  sll  %i4, 0xe, %i1
a00d4cf0:  b6 16 00 19  or  %i0, %i1, %i3
a00d4cf4:  c2 17 60 34  lduh  [ %i5 + 0x34 ], %g1
a00d4cf8:  82 08 60 0f  and  %g1, 0xf, %g1
a00d4cfc:  f8 0f 60 09  ldub  [ %i5 + 9 ], %i4
a00d4d00:  f2 0f 60 0a  ldub  [ %i5 + 0xa ], %i1
a00d4d04:  f0 0f 60 19  ldub  [ %i5 + 0x19 ], %i0
a00d4d08:  de 0f 61 5b  ldub  [ %i5 + 0x15b ], %o7
a00d4d0c:  da 07 60 b0  ld  [ %i5 + 0xb0 ], %o5
a00d4d10:  d8 0f 60 49  ldub  [ %i5 + 0x49 ], %o4
a00d4d14:  f6 27 61 20  st  %i3, [ %i5 + 0x120 ]
a00d4d18:  f8 2f 60 6c  stb  %i4, [ %i5 + 0x6c ]
a00d4d1c:  f2 2f 60 86  stb  %i1, [ %i5 + 0x86 ]
a00d4d20:  f0 2f 60 a4  stb  %i0, [ %i5 + 0xa4 ]
a00d4d24:  de 2f 61 70  stb  %o7, [ %i5 + 0x170 ]
a00d4d28:  da 27 61 08  st  %o5, [ %i5 + 0x108 ]
a00d4d2c:  c2 2f 61 cf  stb  %g1, [ %i5 + 0x1cf ]
a00d4d30:  d8 2f 61 37  stb  %o4, [ %i5 + 0x137 ]
a00d4d34:  10 80 02 7f  b  0xa00d5730
a00d4d38:  f4 27 61 1c  st  %i2, [ %i5 + 0x11c ]
a00d4d3c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d4d40:  fa 10 63 fe  lduh  [ %g1 + 0x3fe ], %i5	! 0xa802cffe
a00d4d44:  80 8f 60 80  btst  0x80, %i5
a00d4d48:  02 80 02 45  be  0xa00d565c
a00d4d4c:  82 16 e2 90  or  %i3, 0x290, %g1
a00d4d50:  f8 00 61 1c  ld  [ %g1 + 0x11c ], %i4
a00d4d54:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d4d58:  3b 00 00 10  sethi  %hi(0x4000), %i5
a00d4d5c:  b4 2f 00 1d  andn  %i4, %i5, %i2
a00d4d60:  b3 2e e0 0e  sll  %i3, 0xe, %i1
a00d4d64:  b4 16 80 19  or  %i2, %i1, %i2
a00d4d68:  b1 36 a0 04  srl  %i2, 4, %i0
a00d4d6c:  b8 0e 20 01  and  %i0, 1, %i4
a00d4d70:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d4d74:  37 00 02 00  sethi  %hi(0x80000), %i3
a00d4d78:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00d4d7c:  b3 2f 20 13  sll  %i4, 0x13, %i1
a00d4d80:  b6 16 00 19  or  %i0, %i1, %i3
a00d4d84:  fa 10 60 34  lduh  [ %g1 + 0x34 ], %i5
a00d4d88:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d4d8c:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d4d90:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d4d94:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d4d98:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d4d9c:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d4da0:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d4da4:  f6 20 61 20  st  %i3, [ %g1 + 0x120 ]
a00d4da8:  f8 28 60 68  stb  %i4, [ %g1 + 0x68 ]
a00d4dac:  f2 28 60 82  stb  %i1, [ %g1 + 0x82 ]
a00d4db0:  f0 28 60 a0  stb  %i0, [ %g1 + 0xa0 ]
a00d4db4:  de 28 61 6c  stb  %o7, [ %g1 + 0x16c ]
a00d4db8:  da 20 60 f4  st  %o5, [ %g1 + 0xf4 ]
a00d4dbc:  fa 28 61 cb  stb  %i5, [ %g1 + 0x1cb ]
a00d4dc0:  d8 28 61 33  stb  %o4, [ %g1 + 0x133 ]
a00d4dc4:  10 80 02 5b  b  0xa00d5730
a00d4dc8:  f4 20 61 1c  st  %i2, [ %g1 + 0x11c ]
a00d4dcc:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d4dd0:  fa 10 63 fe  lduh  [ %g1 + 0x3fe ], %i5	! 0xa802cffe
a00d4dd4:  80 8f 60 80  btst  0x80, %i5
a00d4dd8:  02 80 00 f4  be  0xa00d51a8
a00d4ddc:  82 16 e2 90  or  %i3, 0x290, %g1
a00d4de0:  f8 00 61 1c  ld  [ %g1 + 0x11c ], %i4
a00d4de4:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d4de8:  3b 00 00 04  sethi  %hi(0x1000), %i5
a00d4dec:  b4 2f 00 1d  andn  %i4, %i5, %i2
a00d4df0:  b3 2e e0 0c  sll  %i3, 0xc, %i1
a00d4df4:  b4 16 80 19  or  %i2, %i1, %i2
a00d4df8:  b1 36 a0 04  srl  %i2, 4, %i0
a00d4dfc:  b8 0e 20 01  and  %i0, 1, %i4
a00d4e00:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d4e04:  37 00 00 80  sethi  %hi(0x20000), %i3
a00d4e08:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00d4e0c:  b3 2f 20 11  sll  %i4, 0x11, %i1
a00d4e10:  b6 16 00 19  or  %i0, %i1, %i3
a00d4e14:  fa 10 60 34  lduh  [ %g1 + 0x34 ], %i5
a00d4e18:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d4e1c:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d4e20:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d4e24:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d4e28:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d4e2c:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d4e30:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d4e34:  f6 20 61 20  st  %i3, [ %g1 + 0x120 ]
a00d4e38:  f8 28 60 6a  stb  %i4, [ %g1 + 0x6a ]
a00d4e3c:  f2 28 60 84  stb  %i1, [ %g1 + 0x84 ]
a00d4e40:  f0 28 60 a2  stb  %i0, [ %g1 + 0xa2 ]
a00d4e44:  de 28 61 6e  stb  %o7, [ %g1 + 0x16e ]
a00d4e48:  da 20 60 fc  st  %o5, [ %g1 + 0xfc ]
a00d4e4c:  fa 28 61 cd  stb  %i5, [ %g1 + 0x1cd ]
a00d4e50:  d8 28 61 35  stb  %o4, [ %g1 + 0x135 ]
a00d4e54:  10 80 02 37  b  0xa00d5730
a00d4e58:  f4 20 61 1c  st  %i2, [ %g1 + 0x11c ]
a00d4e5c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d4e60:  fa 10 63 fe  lduh  [ %g1 + 0x3fe ], %i5	! 0xa802cffe
a00d4e64:  80 8f 60 80  btst  0x80, %i5
a00d4e68:  02 80 01 8a  be  0xa00d5490
a00d4e6c:  82 16 e2 90  or  %i3, 0x290, %g1
a00d4e70:  f8 00 61 1c  ld  [ %g1 + 0x11c ], %i4
a00d4e74:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d4e78:  3b 00 00 08  sethi  %hi(0x2000), %i5
a00d4e7c:  b4 2f 00 1d  andn  %i4, %i5, %i2
a00d4e80:  b3 2e e0 0d  sll  %i3, 0xd, %i1
a00d4e84:  b4 16 80 19  or  %i2, %i1, %i2
a00d4e88:  b1 36 a0 04  srl  %i2, 4, %i0
a00d4e8c:  b8 0e 20 01  and  %i0, 1, %i4
a00d4e90:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d4e94:  37 00 01 00  sethi  %hi(0x40000), %i3
a00d4e98:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00d4e9c:  b3 2f 20 12  sll  %i4, 0x12, %i1
a00d4ea0:  b6 16 00 19  or  %i0, %i1, %i3
a00d4ea4:  fa 10 60 34  lduh  [ %g1 + 0x34 ], %i5
a00d4ea8:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d4eac:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d4eb0:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d4eb4:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d4eb8:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d4ebc:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d4ec0:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d4ec4:  f6 20 61 20  st  %i3, [ %g1 + 0x120 ]
a00d4ec8:  f8 28 60 69  stb  %i4, [ %g1 + 0x69 ]
a00d4ecc:  f2 28 60 83  stb  %i1, [ %g1 + 0x83 ]
a00d4ed0:  f0 28 60 a1  stb  %i0, [ %g1 + 0xa1 ]
a00d4ed4:  de 28 61 6d  stb  %o7, [ %g1 + 0x16d ]
a00d4ed8:  da 20 60 f8  st  %o5, [ %g1 + 0xf8 ]
a00d4edc:  fa 28 61 cc  stb  %i5, [ %g1 + 0x1cc ]
a00d4ee0:  d8 28 61 34  stb  %o4, [ %g1 + 0x134 ]
a00d4ee4:  10 80 02 13  b  0xa00d5730
a00d4ee8:  f4 20 61 1c  st  %i2, [ %g1 + 0x11c ]
a00d4eec:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d4ef0:  fa 10 63 fe  lduh  [ %g1 + 0x3fe ], %i5	! 0xa802cffe
a00d4ef4:  80 8f 60 80  btst  0x80, %i5
a00d4ef8:  02 80 01 be  be  0xa00d55f0
a00d4efc:  82 16 e2 90  or  %i3, 0x290, %g1
a00d4f00:  f8 00 61 1c  ld  [ %g1 + 0x11c ], %i4
a00d4f04:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d4f08:  3b 00 00 40  sethi  %hi(0x10000), %i5
a00d4f0c:  b4 2f 00 1d  andn  %i4, %i5, %i2
a00d4f10:  b3 2e e0 10  sll  %i3, 0x10, %i1
a00d4f14:  b4 16 80 19  or  %i2, %i1, %i2
a00d4f18:  b1 36 a0 04  srl  %i2, 4, %i0
a00d4f1c:  b8 0e 20 01  and  %i0, 1, %i4
a00d4f20:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d4f24:  37 00 08 00  sethi  %hi(0x200000), %i3
a00d4f28:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00d4f2c:  b3 2f 20 15  sll  %i4, 0x15, %i1
a00d4f30:  b6 16 00 19  or  %i0, %i1, %i3
a00d4f34:  fa 10 60 34  lduh  [ %g1 + 0x34 ], %i5
a00d4f38:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d4f3c:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d4f40:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d4f44:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d4f48:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d4f4c:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d4f50:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d4f54:  f6 20 61 20  st  %i3, [ %g1 + 0x120 ]
a00d4f58:  f8 28 60 66  stb  %i4, [ %g1 + 0x66 ]
a00d4f5c:  f2 28 60 80  stb  %i1, [ %g1 + 0x80 ]
a00d4f60:  f0 28 60 9e  stb  %i0, [ %g1 + 0x9e ]
a00d4f64:  de 28 61 6a  stb  %o7, [ %g1 + 0x16a ]
a00d4f68:  da 20 60 ec  st  %o5, [ %g1 + 0xec ]
a00d4f6c:  fa 28 61 c9  stb  %i5, [ %g1 + 0x1c9 ]
a00d4f70:  d8 28 61 31  stb  %o4, [ %g1 + 0x131 ]
a00d4f74:  10 80 01 ef  b  0xa00d5730
a00d4f78:  f4 20 61 1c  st  %i2, [ %g1 + 0x11c ]
a00d4f7c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d4f80:  f0 10 63 fe  lduh  [ %g1 + 0x3fe ], %i0	! 0xa802cffe
a00d4f84:  80 8e 20 80  btst  0x80, %i0
a00d4f88:  02 80 01 23  be  0xa00d5414
a00d4f8c:  82 16 e2 90  or  %i3, 0x290, %g1
a00d4f90:  ba 16 e2 90  or  %i3, 0x290, %i5
a00d4f94:  f8 07 61 1c  ld  [ %i5 + 0x11c ], %i4
a00d4f98:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d4f9c:  b3 2e e0 0a  sll  %i3, 0xa, %i1
a00d4fa0:  b4 0f 3b ff  and  %i4, -1025, %i2
a00d4fa4:  b4 16 80 19  or  %i2, %i1, %i2
a00d4fa8:  b1 36 a0 04  srl  %i2, 4, %i0
a00d4fac:  b8 0e 20 01  and  %i0, 1, %i4
a00d4fb0:  c2 07 61 20  ld  [ %i5 + 0x120 ], %g1
a00d4fb4:  37 00 00 20  sethi  %hi(0x8000), %i3
a00d4fb8:  b0 28 40 1b  andn  %g1, %i3, %i0
a00d4fbc:  b3 2f 20 0f  sll  %i4, 0xf, %i1
a00d4fc0:  b6 16 00 19  or  %i0, %i1, %i3
a00d4fc4:  c2 17 60 34  lduh  [ %i5 + 0x34 ], %g1
a00d4fc8:  82 08 60 0f  and  %g1, 0xf, %g1
a00d4fcc:  f8 0f 60 09  ldub  [ %i5 + 9 ], %i4
a00d4fd0:  f2 0f 60 0a  ldub  [ %i5 + 0xa ], %i1
a00d4fd4:  f0 0f 60 19  ldub  [ %i5 + 0x19 ], %i0
a00d4fd8:  de 0f 61 5b  ldub  [ %i5 + 0x15b ], %o7
a00d4fdc:  da 07 60 b0  ld  [ %i5 + 0xb0 ], %o5
a00d4fe0:  d8 0f 60 49  ldub  [ %i5 + 0x49 ], %o4
a00d4fe4:  f6 27 61 20  st  %i3, [ %i5 + 0x120 ]
a00d4fe8:  f8 2f 60 6b  stb  %i4, [ %i5 + 0x6b ]
a00d4fec:  f2 2f 60 85  stb  %i1, [ %i5 + 0x85 ]
a00d4ff0:  f0 2f 60 a3  stb  %i0, [ %i5 + 0xa3 ]
a00d4ff4:  de 2f 61 6f  stb  %o7, [ %i5 + 0x16f ]
a00d4ff8:  da 27 61 04  st  %o5, [ %i5 + 0x104 ]
a00d4ffc:  c2 2f 61 ce  stb  %g1, [ %i5 + 0x1ce ]
a00d5000:  d8 2f 61 36  stb  %o4, [ %i5 + 0x136 ]
a00d5004:  10 80 01 cb  b  0xa00d5730
a00d5008:  f4 27 61 1c  st  %i2, [ %i5 + 0x11c ]
a00d500c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d5010:  fa 10 63 fe  lduh  [ %g1 + 0x3fe ], %i5	! 0xa802cffe
a00d5014:  80 8f 60 80  btst  0x80, %i5
a00d5018:  02 80 01 3c  be  0xa00d5508
a00d501c:  82 16 e2 90  or  %i3, 0x290, %g1
a00d5020:  f8 00 61 1c  ld  [ %g1 + 0x11c ], %i4
a00d5024:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d5028:  3b 00 00 20  sethi  %hi(0x8000), %i5
a00d502c:  b4 2f 00 1d  andn  %i4, %i5, %i2
a00d5030:  b3 2e e0 0f  sll  %i3, 0xf, %i1
a00d5034:  b4 16 80 19  or  %i2, %i1, %i2
a00d5038:  b1 36 a0 04  srl  %i2, 4, %i0
a00d503c:  b8 0e 20 01  and  %i0, 1, %i4
a00d5040:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d5044:  37 00 04 00  sethi  %hi(0x100000), %i3
a00d5048:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00d504c:  b3 2f 20 14  sll  %i4, 0x14, %i1
a00d5050:  b6 16 00 19  or  %i0, %i1, %i3
a00d5054:  fa 10 60 34  lduh  [ %g1 + 0x34 ], %i5
a00d5058:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d505c:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d5060:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d5064:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d5068:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d506c:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d5070:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d5074:  f6 20 61 20  st  %i3, [ %g1 + 0x120 ]
a00d5078:  f8 28 60 67  stb  %i4, [ %g1 + 0x67 ]
a00d507c:  f2 28 60 81  stb  %i1, [ %g1 + 0x81 ]
a00d5080:  f0 28 60 9f  stb  %i0, [ %g1 + 0x9f ]
a00d5084:  de 28 61 6b  stb  %o7, [ %g1 + 0x16b ]
a00d5088:  da 20 60 f0  st  %o5, [ %g1 + 0xf0 ]
a00d508c:  fa 28 61 ca  stb  %i5, [ %g1 + 0x1ca ]
a00d5090:  d8 28 61 32  stb  %o4, [ %g1 + 0x132 ]
a00d5094:  10 80 01 a7  b  0xa00d5730
a00d5098:  f4 20 61 1c  st  %i2, [ %g1 + 0x11c ]
a00d509c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d50a0:  f4 10 63 fe  lduh  [ %g1 + 0x3fe ], %i2	! 0xa802cffe
a00d50a4:  80 8e a0 80  btst  0x80, %i2
a00d50a8:  02 80 01 88  be  0xa00d56c8
a00d50ac:  82 16 e2 90  or  %i3, 0x290, %g1
a00d50b0:  f8 00 61 1c  ld  [ %g1 + 0x11c ], %i4
a00d50b4:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d50b8:  3b 00 00 80  sethi  %hi(0x20000), %i5
a00d50bc:  b4 2f 00 1d  andn  %i4, %i5, %i2
a00d50c0:  b3 2e e0 11  sll  %i3, 0x11, %i1
a00d50c4:  b4 16 80 19  or  %i2, %i1, %i2
a00d50c8:  b1 36 a0 04  srl  %i2, 4, %i0
a00d50cc:  b8 0e 20 01  and  %i0, 1, %i4
a00d50d0:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d50d4:  37 00 10 00  sethi  %hi(0x400000), %i3
a00d50d8:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00d50dc:  b3 2f 20 16  sll  %i4, 0x16, %i1
a00d50e0:  b6 16 00 19  or  %i0, %i1, %i3
a00d50e4:  fa 10 60 34  lduh  [ %g1 + 0x34 ], %i5
a00d50e8:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d50ec:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d50f0:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d50f4:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d50f8:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d50fc:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d5100:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d5104:  f6 20 61 20  st  %i3, [ %g1 + 0x120 ]
a00d5108:  f8 28 60 65  stb  %i4, [ %g1 + 0x65 ]
a00d510c:  f2 28 60 7f  stb  %i1, [ %g1 + 0x7f ]
a00d5110:  f0 28 60 9d  stb  %i0, [ %g1 + 0x9d ]
a00d5114:  de 28 61 69  stb  %o7, [ %g1 + 0x169 ]
a00d5118:  da 20 60 e8  st  %o5, [ %g1 + 0xe8 ]
a00d511c:  fa 28 61 c8  stb  %i5, [ %g1 + 0x1c8 ]
a00d5120:  d8 28 61 30  stb  %o4, [ %g1 + 0x130 ]
a00d5124:  10 80 01 83  b  0xa00d5730
a00d5128:  f4 20 61 1c  st  %i2, [ %g1 + 0x11c ]
a00d512c:  f8 00 61 1c  ld  [ %g1 + 0x11c ], %i4
a00d5130:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d5134:  3b 00 01 00  sethi  %hi(0x40000), %i5
a00d5138:  b4 2f 00 1d  andn  %i4, %i5, %i2
a00d513c:  b3 2e e0 12  sll  %i3, 0x12, %i1
a00d5140:  b4 16 80 19  or  %i2, %i1, %i2
a00d5144:  b1 36 a0 04  srl  %i2, 4, %i0
a00d5148:  b8 0e 20 01  and  %i0, 1, %i4
a00d514c:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d5150:  37 00 20 00  sethi  %hi(0x800000), %i3
a00d5154:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00d5158:  b3 2f 20 17  sll  %i4, 0x17, %i1
a00d515c:  b6 16 00 19  or  %i0, %i1, %i3
a00d5160:  fa 10 60 34  lduh  [ %g1 + 0x34 ], %i5
a00d5164:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d5168:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d516c:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d5170:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d5174:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d5178:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d517c:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d5180:  f6 20 61 20  st  %i3, [ %g1 + 0x120 ]
a00d5184:  f8 28 60 63  stb  %i4, [ %g1 + 0x63 ]
a00d5188:  f2 28 60 7d  stb  %i1, [ %g1 + 0x7d ]
a00d518c:  f0 28 60 9b  stb  %i0, [ %g1 + 0x9b ]
a00d5190:  de 28 61 67  stb  %o7, [ %g1 + 0x167 ]
a00d5194:  da 20 60 e4  st  %o5, [ %g1 + 0xe4 ]
a00d5198:  fa 28 61 c6  stb  %i5, [ %g1 + 0x1c6 ]
a00d519c:  d8 28 61 2e  stb  %o4, [ %g1 + 0x12e ]
a00d51a0:  10 80 01 64  b  0xa00d5730
a00d51a4:  f4 20 61 1c  st  %i2, [ %g1 + 0x11c ]
a00d51a8:  f8 00 61 1c  ld  [ %g1 + 0x11c ], %i4
a00d51ac:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d51b0:  3b 00 80 00  sethi  %hi(0x2000000), %i5
a00d51b4:  b4 2f 00 1d  andn  %i4, %i5, %i2
a00d51b8:  b3 2e e0 19  sll  %i3, 0x19, %i1
a00d51bc:  b4 16 80 19  or  %i2, %i1, %i2
a00d51c0:  b1 36 a0 04  srl  %i2, 4, %i0
a00d51c4:  b8 0e 20 01  and  %i0, 1, %i4
a00d51c8:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d51cc:  37 10 00 00  sethi  %hi(0x40000000), %i3
a00d51d0:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00d51d4:  b3 2f 20 1e  sll  %i4, 0x1e, %i1
a00d51d8:  b6 16 00 19  or  %i0, %i1, %i3
a00d51dc:  fa 10 60 34  lduh  [ %g1 + 0x34 ], %i5
a00d51e0:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d51e4:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d51e8:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d51ec:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d51f0:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d51f4:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d51f8:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d51fc:  f6 20 61 20  st  %i3, [ %g1 + 0x120 ]
a00d5200:  f8 28 60 5d  stb  %i4, [ %g1 + 0x5d ]
a00d5204:  f2 28 60 77  stb  %i1, [ %g1 + 0x77 ]
a00d5208:  f0 28 60 95  stb  %i0, [ %g1 + 0x95 ]
a00d520c:  de 28 61 61  stb  %o7, [ %g1 + 0x161 ]
a00d5210:  da 20 60 c8  st  %o5, [ %g1 + 0xc8 ]
a00d5214:  fa 28 61 c0  stb  %i5, [ %g1 + 0x1c0 ]
a00d5218:  d8 28 61 28  stb  %o4, [ %g1 + 0x128 ]
a00d521c:  10 80 01 45  b  0xa00d5730
a00d5220:  f4 20 61 1c  st  %i2, [ %g1 + 0x11c ]
a00d5224:  f8 00 61 1c  ld  [ %g1 + 0x11c ], %i4
a00d5228:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d522c:  3b 00 40 00  sethi  %hi(0x1000000), %i5
a00d5230:  b4 2f 00 1d  andn  %i4, %i5, %i2
a00d5234:  b3 2e e0 18  sll  %i3, 0x18, %i1
a00d5238:  b4 16 80 19  or  %i2, %i1, %i2
a00d523c:  b1 36 a0 04  srl  %i2, 4, %i0
a00d5240:  b8 0e 20 01  and  %i0, 1, %i4
a00d5244:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d5248:  37 08 00 00  sethi  %hi(0x20000000), %i3
a00d524c:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00d5250:  b3 2f 20 1d  sll  %i4, 0x1d, %i1
a00d5254:  b6 16 00 19  or  %i0, %i1, %i3
a00d5258:  fa 10 60 34  lduh  [ %g1 + 0x34 ], %i5
a00d525c:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d5260:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d5264:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d5268:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d526c:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d5270:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d5274:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d5278:  f6 20 61 20  st  %i3, [ %g1 + 0x120 ]
a00d527c:  f8 28 60 64  stb  %i4, [ %g1 + 0x64 ]
a00d5280:  f2 28 60 7e  stb  %i1, [ %g1 + 0x7e ]
a00d5284:  f0 28 60 9c  stb  %i0, [ %g1 + 0x9c ]
a00d5288:  de 28 61 68  stb  %o7, [ %g1 + 0x168 ]
a00d528c:  da 20 60 d0  st  %o5, [ %g1 + 0xd0 ]
a00d5290:  fa 28 61 c7  stb  %i5, [ %g1 + 0x1c7 ]
a00d5294:  d8 28 61 2f  stb  %o4, [ %g1 + 0x12f ]
a00d5298:  10 80 01 26  b  0xa00d5730
a00d529c:  f4 20 61 1c  st  %i2, [ %g1 + 0x11c ]
a00d52a0:  f8 00 61 1c  ld  [ %g1 + 0x11c ], %i4
a00d52a4:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d52a8:  3b 00 02 00  sethi  %hi(0x80000), %i5
a00d52ac:  b4 2f 00 1d  andn  %i4, %i5, %i2
a00d52b0:  b3 2e e0 13  sll  %i3, 0x13, %i1
a00d52b4:  b4 16 80 19  or  %i2, %i1, %i2
a00d52b8:  b1 36 a0 04  srl  %i2, 4, %i0
a00d52bc:  b8 0e 20 01  and  %i0, 1, %i4
a00d52c0:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d52c4:  37 00 40 00  sethi  %hi(0x1000000), %i3
a00d52c8:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00d52cc:  b3 2f 20 18  sll  %i4, 0x18, %i1
a00d52d0:  b6 16 00 19  or  %i0, %i1, %i3
a00d52d4:  fa 10 60 34  lduh  [ %g1 + 0x34 ], %i5
a00d52d8:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d52dc:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d52e0:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d52e4:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d52e8:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d52ec:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d52f0:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d52f4:  f6 20 61 20  st  %i3, [ %g1 + 0x120 ]
a00d52f8:  f8 28 60 62  stb  %i4, [ %g1 + 0x62 ]
a00d52fc:  f2 28 60 7c  stb  %i1, [ %g1 + 0x7c ]
a00d5300:  f0 28 60 9a  stb  %i0, [ %g1 + 0x9a ]
a00d5304:  de 28 61 66  stb  %o7, [ %g1 + 0x166 ]
a00d5308:  da 20 60 e0  st  %o5, [ %g1 + 0xe0 ]
a00d530c:  fa 28 61 c5  stb  %i5, [ %g1 + 0x1c5 ]
a00d5310:  d8 28 61 2d  stb  %o4, [ %g1 + 0x12d ]
a00d5314:  10 80 01 07  b  0xa00d5730
a00d5318:  f4 20 61 1c  st  %i2, [ %g1 + 0x11c ]
a00d531c:  f8 00 61 1c  ld  [ %g1 + 0x11c ], %i4
a00d5320:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d5324:  3b 00 04 00  sethi  %hi(0x100000), %i5
a00d5328:  b4 2f 00 1d  andn  %i4, %i5, %i2
a00d532c:  b3 2e e0 14  sll  %i3, 0x14, %i1
a00d5330:  b4 16 80 19  or  %i2, %i1, %i2
a00d5334:  b1 36 a0 04  srl  %i2, 4, %i0
a00d5338:  b8 0e 20 01  and  %i0, 1, %i4
a00d533c:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d5340:  37 00 80 00  sethi  %hi(0x2000000), %i3
a00d5344:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00d5348:  b3 2f 20 19  sll  %i4, 0x19, %i1
a00d534c:  b6 16 00 19  or  %i0, %i1, %i3
a00d5350:  fa 10 60 34  lduh  [ %g1 + 0x34 ], %i5
a00d5354:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d5358:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d535c:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d5360:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d5364:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d5368:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d536c:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d5370:  f6 20 61 20  st  %i3, [ %g1 + 0x120 ]
a00d5374:  f8 28 60 61  stb  %i4, [ %g1 + 0x61 ]
a00d5378:  f2 28 60 7b  stb  %i1, [ %g1 + 0x7b ]
a00d537c:  f0 28 60 99  stb  %i0, [ %g1 + 0x99 ]
a00d5380:  de 28 61 65  stb  %o7, [ %g1 + 0x165 ]
a00d5384:  da 20 60 dc  st  %o5, [ %g1 + 0xdc ]
a00d5388:  fa 28 61 c4  stb  %i5, [ %g1 + 0x1c4 ]
a00d538c:  d8 28 61 2c  stb  %o4, [ %g1 + 0x12c ]
a00d5390:  10 80 00 e8  b  0xa00d5730
a00d5394:  f4 20 61 1c  st  %i2, [ %g1 + 0x11c ]
a00d5398:  f8 00 61 1c  ld  [ %g1 + 0x11c ], %i4
a00d539c:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d53a0:  3b 00 10 00  sethi  %hi(0x400000), %i5
a00d53a4:  b4 2f 00 1d  andn  %i4, %i5, %i2
a00d53a8:  b3 2e e0 16  sll  %i3, 0x16, %i1
a00d53ac:  b4 16 80 19  or  %i2, %i1, %i2
a00d53b0:  b1 36 a0 04  srl  %i2, 4, %i0
a00d53b4:  b8 0e 20 01  and  %i0, 1, %i4
a00d53b8:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d53bc:  37 02 00 00  sethi  %hi(0x8000000), %i3
a00d53c0:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00d53c4:  b3 2f 20 1b  sll  %i4, 0x1b, %i1
a00d53c8:  b6 16 00 19  or  %i0, %i1, %i3
a00d53cc:  fa 10 60 34  lduh  [ %g1 + 0x34 ], %i5
a00d53d0:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d53d4:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d53d8:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d53dc:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d53e0:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d53e4:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d53e8:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d53ec:  f6 20 61 20  st  %i3, [ %g1 + 0x120 ]
a00d53f0:  f8 28 60 5f  stb  %i4, [ %g1 + 0x5f ]
a00d53f4:  f2 28 60 79  stb  %i1, [ %g1 + 0x79 ]
a00d53f8:  f0 28 60 97  stb  %i0, [ %g1 + 0x97 ]
a00d53fc:  de 28 61 63  stb  %o7, [ %g1 + 0x163 ]
a00d5400:  da 20 60 d4  st  %o5, [ %g1 + 0xd4 ]
a00d5404:  fa 28 61 c2  stb  %i5, [ %g1 + 0x1c2 ]
a00d5408:  d8 28 61 2a  stb  %o4, [ %g1 + 0x12a ]
a00d540c:  10 80 00 c9  b  0xa00d5730
a00d5410:  f4 20 61 1c  st  %i2, [ %g1 + 0x11c ]
a00d5414:  f8 00 61 1c  ld  [ %g1 + 0x11c ], %i4
a00d5418:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d541c:  3b 00 20 00  sethi  %hi(0x800000), %i5
a00d5420:  b4 2f 00 1d  andn  %i4, %i5, %i2
a00d5424:  b3 2e e0 17  sll  %i3, 0x17, %i1
a00d5428:  b4 16 80 19  or  %i2, %i1, %i2
a00d542c:  b1 36 a0 04  srl  %i2, 4, %i0
a00d5430:  b8 0e 20 01  and  %i0, 1, %i4
a00d5434:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d5438:  37 04 00 00  sethi  %hi(0x10000000), %i3
a00d543c:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00d5440:  b3 2f 20 1c  sll  %i4, 0x1c, %i1
a00d5444:  b6 16 00 19  or  %i0, %i1, %i3
a00d5448:  fa 10 60 34  lduh  [ %g1 + 0x34 ], %i5
a00d544c:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d5450:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d5454:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d5458:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d545c:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d5460:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d5464:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d5468:  f6 20 61 20  st  %i3, [ %g1 + 0x120 ]
a00d546c:  f8 28 60 5e  stb  %i4, [ %g1 + 0x5e ]
a00d5470:  f2 28 60 78  stb  %i1, [ %g1 + 0x78 ]
a00d5474:  f0 28 60 96  stb  %i0, [ %g1 + 0x96 ]
a00d5478:  de 28 61 62  stb  %o7, [ %g1 + 0x162 ]
a00d547c:  da 20 60 cc  st  %o5, [ %g1 + 0xcc ]
a00d5480:  fa 28 61 c1  stb  %i5, [ %g1 + 0x1c1 ]
a00d5484:  d8 28 61 29  stb  %o4, [ %g1 + 0x129 ]
a00d5488:  10 80 00 aa  b  0xa00d5730
a00d548c:  f4 20 61 1c  st  %i2, [ %g1 + 0x11c ]
a00d5490:  f8 00 61 1c  ld  [ %g1 + 0x11c ], %i4
a00d5494:  b3 37 20 1f  srl  %i4, 0x1f, %i1
a00d5498:  37 01 00 00  sethi  %hi(0x4000000), %i3
a00d549c:  b4 2f 00 1b  andn  %i4, %i3, %i2
a00d54a0:  b1 2e 60 1a  sll  %i1, 0x1a, %i0
a00d54a4:  b4 16 80 18  or  %i2, %i0, %i2
a00d54a8:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d54ac:  b9 36 a0 04  srl  %i2, 4, %i4
a00d54b0:  37 20 00 00  sethi  %hi(0x80000000), %i3
a00d54b4:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00d54b8:  b3 2f 20 1f  sll  %i4, 0x1f, %i1
a00d54bc:  b6 16 00 19  or  %i0, %i1, %i3
a00d54c0:  fa 10 60 34  lduh  [ %g1 + 0x34 ], %i5
a00d54c4:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d54c8:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d54cc:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d54d0:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d54d4:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d54d8:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d54dc:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d54e0:  f6 20 61 20  st  %i3, [ %g1 + 0x120 ]
a00d54e4:  f8 28 60 5c  stb  %i4, [ %g1 + 0x5c ]
a00d54e8:  f2 28 60 76  stb  %i1, [ %g1 + 0x76 ]
a00d54ec:  f0 28 60 94  stb  %i0, [ %g1 + 0x94 ]
a00d54f0:  de 28 61 60  stb  %o7, [ %g1 + 0x160 ]
a00d54f4:  da 20 60 c4  st  %o5, [ %g1 + 0xc4 ]
a00d54f8:  fa 28 61 bf  stb  %i5, [ %g1 + 0x1bf ]
a00d54fc:  d8 28 61 27  stb  %o4, [ %g1 + 0x127 ]
a00d5500:  10 80 00 8c  b  0xa00d5730
a00d5504:  f4 20 61 1c  st  %i2, [ %g1 + 0x11c ]
a00d5508:  f4 00 61 1c  ld  [ %g1 + 0x11c ], %i2
a00d550c:  b1 36 a0 1f  srl  %i2, 0x1f, %i0
a00d5510:  33 04 00 00  sethi  %hi(0x10000000), %i1
a00d5514:  ba 2e 80 19  andn  %i2, %i1, %i5
a00d5518:  b9 2e 20 1c  sll  %i0, 0x1c, %i4
a00d551c:  b4 17 40 1c  or  %i5, %i4, %i2
a00d5520:  b7 36 a0 03  srl  %i2, 3, %i3
a00d5524:  b2 0e e0 02  and  %i3, 2, %i1
a00d5528:  b0 0e bf fd  and  %i2, -3, %i0
a00d552c:  ba 16 00 19  or  %i0, %i1, %i5
a00d5530:  f8 10 60 34  lduh  [ %g1 + 0x34 ], %i4
a00d5534:  b8 0f 20 0f  and  %i4, 0xf, %i4
a00d5538:  f6 08 60 09  ldub  [ %g1 + 9 ], %i3
a00d553c:  f4 08 60 0a  ldub  [ %g1 + 0xa ], %i2
a00d5540:  f2 08 60 19  ldub  [ %g1 + 0x19 ], %i1
a00d5544:  f0 08 61 5b  ldub  [ %g1 + 0x15b ], %i0
a00d5548:  de 00 60 b0  ld  [ %g1 + 0xb0 ], %o7
a00d554c:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5
a00d5550:  fa 20 61 1c  st  %i5, [ %g1 + 0x11c ]
a00d5554:  f6 28 60 5a  stb  %i3, [ %g1 + 0x5a ]
a00d5558:  f4 28 60 74  stb  %i2, [ %g1 + 0x74 ]
a00d555c:  f2 28 60 92  stb  %i1, [ %g1 + 0x92 ]
a00d5560:  f0 28 61 5e  stb  %i0, [ %g1 + 0x15e ]
a00d5564:  de 20 60 bc  st  %o7, [ %g1 + 0xbc ]
a00d5568:  f8 28 61 bd  stb  %i4, [ %g1 + 0x1bd ]
a00d556c:  10 80 00 71  b  0xa00d5730
a00d5570:  da 28 61 25  stb  %o5, [ %g1 + 0x125 ]
a00d5574:  f8 00 61 1c  ld  [ %g1 + 0x11c ], %i4
a00d5578:  b7 37 20 1f  srl  %i4, 0x1f, %i3
a00d557c:  3b 00 08 00  sethi  %hi(0x200000), %i5
a00d5580:  b4 2f 00 1d  andn  %i4, %i5, %i2
a00d5584:  b3 2e e0 15  sll  %i3, 0x15, %i1
a00d5588:  b4 16 80 19  or  %i2, %i1, %i2
a00d558c:  b1 36 a0 04  srl  %i2, 4, %i0
a00d5590:  b8 0e 20 01  and  %i0, 1, %i4
a00d5594:  fa 00 61 20  ld  [ %g1 + 0x120 ], %i5
a00d5598:  37 01 00 00  sethi  %hi(0x4000000), %i3
a00d559c:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00d55a0:  b3 2f 20 1a  sll  %i4, 0x1a, %i1
a00d55a4:  b6 16 00 19  or  %i0, %i1, %i3
a00d55a8:  fa 10 60 34  lduh  [ %g1 + 0x34 ], %i5
a00d55ac:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d55b0:  f8 08 60 09  ldub  [ %g1 + 9 ], %i4
a00d55b4:  f2 08 60 0a  ldub  [ %g1 + 0xa ], %i1
a00d55b8:  f0 08 60 19  ldub  [ %g1 + 0x19 ], %i0
a00d55bc:  de 08 61 5b  ldub  [ %g1 + 0x15b ], %o7
a00d55c0:  da 00 60 b0  ld  [ %g1 + 0xb0 ], %o5
a00d55c4:  d8 08 60 49  ldub  [ %g1 + 0x49 ], %o4
a00d55c8:  f6 20 61 20  st  %i3, [ %g1 + 0x120 ]
a00d55cc:  f8 28 60 60  stb  %i4, [ %g1 + 0x60 ]
a00d55d0:  f2 28 60 7a  stb  %i1, [ %g1 + 0x7a ]
a00d55d4:  f0 28 60 98  stb  %i0, [ %g1 + 0x98 ]
a00d55d8:  de 28 61 64  stb  %o7, [ %g1 + 0x164 ]
a00d55dc:  da 20 60 d8  st  %o5, [ %g1 + 0xd8 ]
a00d55e0:  fa 28 61 c3  stb  %i5, [ %g1 + 0x1c3 ]
a00d55e4:  d8 28 61 2b  stb  %o4, [ %g1 + 0x12b ]
a00d55e8:  10 80 00 52  b  0xa00d5730
a00d55ec:  f4 20 61 1c  st  %i2, [ %g1 + 0x11c ]
a00d55f0:  f4 00 61 1c  ld  [ %g1 + 0x11c ], %i2
a00d55f4:  b1 36 a0 1f  srl  %i2, 0x1f, %i0
a00d55f8:  33 08 00 00  sethi  %hi(0x20000000), %i1
a00d55fc:  ba 2e 80 19  andn  %i2, %i1, %i5
a00d5600:  b9 2e 20 1d  sll  %i0, 0x1d, %i4
a00d5604:  b4 17 40 1c  or  %i5, %i4, %i2
a00d5608:  b7 36 a0 02  srl  %i2, 2, %i3
a00d560c:  b2 0e e0 04  and  %i3, 4, %i1
a00d5610:  b0 0e bf fb  and  %i2, -5, %i0
a00d5614:  ba 16 00 19  or  %i0, %i1, %i5
a00d5618:  f8 10 60 34  lduh  [ %g1 + 0x34 ], %i4
a00d561c:  b8 0f 20 0f  and  %i4, 0xf, %i4
a00d5620:  f6 08 60 09  ldub  [ %g1 + 9 ], %i3
a00d5624:  f4 08 60 0a  ldub  [ %g1 + 0xa ], %i2
a00d5628:  f2 08 60 19  ldub  [ %g1 + 0x19 ], %i1
a00d562c:  f0 08 61 5b  ldub  [ %g1 + 0x15b ], %i0
a00d5630:  de 00 60 b0  ld  [ %g1 + 0xb0 ], %o7
a00d5634:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5
a00d5638:  fa 20 61 1c  st  %i5, [ %g1 + 0x11c ]
a00d563c:  f6 28 60 59  stb  %i3, [ %g1 + 0x59 ]
a00d5640:  f4 28 60 73  stb  %i2, [ %g1 + 0x73 ]
a00d5644:  f2 28 60 91  stb  %i1, [ %g1 + 0x91 ]
a00d5648:  f0 28 61 5d  stb  %i0, [ %g1 + 0x15d ]
a00d564c:  de 20 60 b8  st  %o7, [ %g1 + 0xb8 ]
a00d5650:  f8 28 61 bc  stb  %i4, [ %g1 + 0x1bc ]
a00d5654:  10 80 00 37  b  0xa00d5730
a00d5658:  da 28 61 24  stb  %o5, [ %g1 + 0x124 ]
a00d565c:  f4 00 61 1c  ld  [ %g1 + 0x11c ], %i2
a00d5660:  b1 36 a0 1f  srl  %i2, 0x1f, %i0
a00d5664:  33 02 00 00  sethi  %hi(0x8000000), %i1
a00d5668:  ba 2e 80 19  andn  %i2, %i1, %i5
a00d566c:  b9 2e 20 1b  sll  %i0, 0x1b, %i4
a00d5670:  b4 17 40 1c  or  %i5, %i4, %i2
a00d5674:  b7 36 a0 04  srl  %i2, 4, %i3
a00d5678:  b2 0e e0 01  and  %i3, 1, %i1
a00d567c:  b0 0e bf fe  and  %i2, -2, %i0
a00d5680:  ba 16 00 19  or  %i0, %i1, %i5
a00d5684:  f8 10 60 34  lduh  [ %g1 + 0x34 ], %i4
a00d5688:  b8 0f 20 0f  and  %i4, 0xf, %i4
a00d568c:  f6 08 60 09  ldub  [ %g1 + 9 ], %i3
a00d5690:  f4 08 60 0a  ldub  [ %g1 + 0xa ], %i2
a00d5694:  f2 08 60 19  ldub  [ %g1 + 0x19 ], %i1
a00d5698:  f0 08 61 5b  ldub  [ %g1 + 0x15b ], %i0
a00d569c:  de 00 60 b0  ld  [ %g1 + 0xb0 ], %o7
a00d56a0:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5
a00d56a4:  fa 20 61 1c  st  %i5, [ %g1 + 0x11c ]
a00d56a8:  f6 28 60 5b  stb  %i3, [ %g1 + 0x5b ]
a00d56ac:  f4 28 60 75  stb  %i2, [ %g1 + 0x75 ]
a00d56b0:  f2 28 60 93  stb  %i1, [ %g1 + 0x93 ]
a00d56b4:  f0 28 61 5f  stb  %i0, [ %g1 + 0x15f ]
a00d56b8:  de 20 60 c0  st  %o7, [ %g1 + 0xc0 ]
a00d56bc:  f8 28 61 be  stb  %i4, [ %g1 + 0x1be ]
a00d56c0:  10 80 00 1c  b  0xa00d5730
a00d56c4:  da 28 61 26  stb  %o5, [ %g1 + 0x126 ]
a00d56c8:  f4 00 61 1c  ld  [ %g1 + 0x11c ], %i2
a00d56cc:  b1 36 a0 1f  srl  %i2, 0x1f, %i0
a00d56d0:  33 10 00 00  sethi  %hi(0x40000000), %i1
a00d56d4:  ba 2e 80 19  andn  %i2, %i1, %i5
a00d56d8:  b9 2e 20 1e  sll  %i0, 0x1e, %i4
a00d56dc:  b4 17 40 1c  or  %i5, %i4, %i2
a00d56e0:  b7 36 a0 01  srl  %i2, 1, %i3
a00d56e4:  b2 0e e0 08  and  %i3, 8, %i1
a00d56e8:  b0 0e bf f7  and  %i2, -9, %i0
a00d56ec:  ba 16 00 19  or  %i0, %i1, %i5
a00d56f0:  f8 10 60 34  lduh  [ %g1 + 0x34 ], %i4
a00d56f4:  b8 0f 20 0f  and  %i4, 0xf, %i4
a00d56f8:  f6 08 60 09  ldub  [ %g1 + 9 ], %i3
a00d56fc:  f4 08 60 0a  ldub  [ %g1 + 0xa ], %i2
a00d5700:  f2 08 60 19  ldub  [ %g1 + 0x19 ], %i1
a00d5704:  f0 08 61 5b  ldub  [ %g1 + 0x15b ], %i0
a00d5708:  de 00 60 b0  ld  [ %g1 + 0xb0 ], %o7
a00d570c:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5
a00d5710:  fa 20 61 1c  st  %i5, [ %g1 + 0x11c ]
a00d5714:  f6 28 60 58  stb  %i3, [ %g1 + 0x58 ]
a00d5718:  f4 28 60 72  stb  %i2, [ %g1 + 0x72 ]
a00d571c:  f2 28 60 90  stb  %i1, [ %g1 + 0x90 ]
a00d5720:  f0 28 61 5c  stb  %i0, [ %g1 + 0x15c ]
a00d5724:  de 20 60 b4  st  %o7, [ %g1 + 0xb4 ]
a00d5728:  f8 28 61 bb  stb  %i4, [ %g1 + 0x1bb ]
a00d572c:  da 28 61 23  stb  %o5, [ %g1 + 0x123 ]
a00d5730:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00d5734:  f4 0e 20 8e  ldub  [ %i0 + 0x8e ], %i2	! 0xa802b08e
a00d5738:  82 16 a0 02  or  %i2, 2, %g1
a00d573c:  c2 2e 20 8e  stb  %g1, [ %i0 + 0x8e ]
a00d5740:  81 c7 e0 08  ret
a00d5744:  81 e8 00 00  restore
