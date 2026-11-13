# leon2m FUN_a00f6940 0xa00f6940-0xa00f6ab4 (104 bytes)
a00f6940:  9d e3 bf 98  save  %sp, -104, %sp
a00f6944:  80 a6 20 04  cmp  %i0, 4
a00f6948:  18 80 00 4b  bgu  0xa00f6a74
a00f694c:  9e 10 00 1b  mov  %i3, %o7
a00f6950:  37 00 02 58  sethi  %hi(0x96000), %i3
a00f6954:  83 2e 20 02  sll  %i0, 2, %g1
a00f6958:  ba 16 e3 94  or  %i3, 0x394, %i5
a00f695c:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a00f6960:  81 c7 00 00  jmp  %i4
a00f6964:  01 00 00 00  nop
a00f6968:  3b 33 c0 3b  sethi  %hi(0xcf00ec00), %i5
a00f696c:  b6 17 60 84  or  %i5, 0x84, %i3	! 0xcf00ec84
a00f6970:  c2 06 c0 00  ld  [ %i3 ], %g1
a00f6974:  b8 08 60 fc  and  %g1, 0xfc, %i4
a00f6978:  82 17 00 18  or  %i4, %i0, %g1
a00f697c:  c2 26 c0 00  st  %g1, [ %i3 ]
a00f6980:  b6 17 62 68  or  %i5, 0x268, %i3
a00f6984:  b8 10 20 40  mov  0x40, %i4
a00f6988:  f8 26 c0 00  st  %i4, [ %i3 ]
a00f698c:  b0 17 62 30  or  %i5, 0x230, %i0
a00f6990:  82 10 20 80  mov  0x80, %g1
a00f6994:  c2 26 00 00  st  %g1, [ %i0 ]
a00f6998:  b6 17 62 34  or  %i5, 0x234, %i3
a00f699c:  b8 10 20 01  mov  1, %i4
a00f69a0:  f8 26 c0 00  st  %i4, [ %i3 ]
a00f69a4:  10 80 00 35  b  0xa00f6a78
a00f69a8:  31 33 c0 3b  sethi  %hi(0xcf00ec00), %i0
a00f69ac:  37 33 c0 3b  sethi  %hi(0xcf00ec00), %i3
a00f69b0:  b8 16 e0 84  or  %i3, 0x84, %i4	! 0xcf00ec84
a00f69b4:  fa 07 00 00  ld  [ %i4 ], %i5
a00f69b8:  82 0f 60 fc  and  %i5, 0xfc, %g1
a00f69bc:  ba 10 40 18  or  %g1, %i0, %i5
a00f69c0:  fa 27 00 00  st  %i5, [ %i4 ]
a00f69c4:  ba 16 e2 40  or  %i3, 0x240, %i5
a00f69c8:  f0 07 40 00  ld  [ %i5 ], %i0
a00f69cc:  82 16 20 40  or  %i0, 0x40, %g1
a00f69d0:  b0 16 e2 20  or  %i3, 0x220, %i0
a00f69d4:  c2 27 40 00  st  %g1, [ %i5 ]
a00f69d8:  b8 10 20 80  mov  0x80, %i4
a00f69dc:  f8 26 00 00  st  %i4, [ %i0 ]
a00f69e0:  b6 16 e2 24  or  %i3, 0x224, %i3
a00f69e4:  b0 10 20 01  mov  1, %i0
a00f69e8:  f0 26 c0 00  st  %i0, [ %i3 ]
a00f69ec:  10 80 00 23  b  0xa00f6a78
a00f69f0:  31 33 c0 3b  sethi  %hi(0xcf00ec00), %i0
a00f69f4:  37 33 c0 3b  sethi  %hi(0xcf00ec00), %i3
a00f69f8:  b8 16 e0 84  or  %i3, 0x84, %i4	! 0xcf00ec84
a00f69fc:  fa 07 00 00  ld  [ %i4 ], %i5
a00f6a00:  82 0f 60 fc  and  %i5, 0xfc, %g1
a00f6a04:  ba 10 40 18  or  %g1, %i0, %i5
a00f6a08:  fa 27 00 00  st  %i5, [ %i4 ]
a00f6a0c:  ba 16 e2 40  or  %i3, 0x240, %i5
a00f6a10:  f0 07 40 00  ld  [ %i5 ], %i0
a00f6a14:  82 16 20 80  or  %i0, 0x80, %g1
a00f6a18:  b0 16 e2 28  or  %i3, 0x228, %i0
a00f6a1c:  c2 27 40 00  st  %g1, [ %i5 ]
a00f6a20:  b8 10 20 80  mov  0x80, %i4
a00f6a24:  f8 26 00 00  st  %i4, [ %i0 ]
a00f6a28:  b6 16 e2 2c  or  %i3, 0x22c, %i3
a00f6a2c:  b0 10 20 01  mov  1, %i0
a00f6a30:  f0 26 c0 00  st  %i0, [ %i3 ]
a00f6a34:  10 80 00 11  b  0xa00f6a78
a00f6a38:  31 33 c0 3b  sethi  %hi(0xcf00ec00), %i0
a00f6a3c:  39 33 c0 3b  sethi  %hi(0xcf00ec00), %i4
a00f6a40:  b6 17 20 84  or  %i4, 0x84, %i3	! 0xcf00ec84
a00f6a44:  c2 06 c0 00  ld  [ %i3 ], %g1
a00f6a48:  ba 08 60 fc  and  %g1, 0xfc, %i5
a00f6a4c:  82 17 40 18  or  %i5, %i0, %g1
a00f6a50:  c2 26 c0 00  st  %g1, [ %i3 ]
a00f6a54:  b6 10 20 80  mov  0x80, %i3
a00f6a58:  ba 17 22 68  or  %i4, 0x268, %i5
a00f6a5c:  f6 27 40 00  st  %i3, [ %i5 ]
a00f6a60:  82 17 22 38  or  %i4, 0x238, %g1
a00f6a64:  f6 20 40 00  st  %i3, [ %g1 ]
a00f6a68:  ba 17 22 3c  or  %i4, 0x23c, %i5
a00f6a6c:  b0 10 20 01  mov  1, %i0
a00f6a70:  f0 27 40 00  st  %i0, [ %i5 ]
a00f6a74:  31 33 c0 3b  sethi  %hi(0xcf00ec00), %i0
a00f6a78:  b6 16 22 50  or  %i0, 0x250, %i3	! 0xcf00ee50
a00f6a7c:  fa 06 c0 00  ld  [ %i3 ], %i5
a00f6a80:  b8 17 60 07  or  %i5, 7, %i4
a00f6a84:  f8 26 c0 00  st  %i4, [ %i3 ]
a00f6a88:  82 0e 60 ff  and  %i1, 0xff, %g1
a00f6a8c:  ba 16 22 44  or  %i0, 0x244, %i5
a00f6a90:  c2 27 40 00  st  %g1, [ %i5 ]
a00f6a94:  b8 0e a0 ff  and  %i2, 0xff, %i4
a00f6a98:  b6 16 22 48  or  %i0, 0x248, %i3
a00f6a9c:  f8 26 c0 00  st  %i4, [ %i3 ]
a00f6aa0:  b2 16 22 4c  or  %i0, 0x24c, %i1
a00f6aa4:  b4 0b e0 ff  and  %o7, 0xff, %i2
a00f6aa8:  f4 26 40 00  st  %i2, [ %i1 ]
a00f6aac:  81 c7 e0 08  ret
a00f6ab0:  81 e8 00 00  restore
