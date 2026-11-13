# leon2s FUN_a00a0930 0xa00a0930-0xa00a0b10 (480 bytes)
a00a0930:  9d e3 bf 98  save  %sp, -104, %sp
a00a0934:  80 a6 60 3f  cmp  %i1, 0x3f
a00a0938:  18 80 00 74  bgu  0xa00a0b08
a00a093c:  a0 10 00 1a  mov  %i2, %l0
a00a0940:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a0944:  92 10 00 19  mov  %i1, %o1
a00a0948:  7f ff ff 9c  call  0xa00a07b8
a00a094c:  90 10 00 18  mov  %i0, %o0
a00a0950:  03 28 02 d2  sethi  %hi(0xa00b4800), %g1
a00a0954:  82 10 62 00  or  %g1, 0x200, %g1	! 0xa00b4a00
a00a0958:  97 2e 60 03  sll  %i1, 3, %o3
a00a095c:  98 02 c0 01  add  %o3, %g1, %o4
a00a0960:  d2 02 c0 01  ld  [ %o3 + %g1 ], %o1
a00a0964:  da 0b 20 05  ldub  [ %o4 + 5 ], %o5
a00a0968:  9b 2b 60 03  sll  %o5, 3, %o5
a00a096c:  c2 0b 20 06  ldub  [ %o4 + 6 ], %g1
a00a0970:  80 a2 60 07  cmp  %o1, 7
a00a0974:  18 80 00 65  bgu  0xa00a0b08
a00a0978:  b4 03 40 01  add  %o5, %g1, %i2
a00a097c:  1b 28 02 82  sethi  %hi(0xa00a0800), %o5
a00a0980:  83 2a 60 02  sll  %o1, 2, %g1
a00a0984:  9a 13 61 10  or  %o5, 0x110, %o5
a00a0988:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00a098c:  81 c0 40 00  jmp  %g1
a00a0990:  96 0c 20 ff  and  %l0, 0xff, %o3
a00a0994:  80 a2 e0 01  cmp  %o3, 1
a00a0998:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00a099c:  12 80 00 0a  bne  0xa00a09c4
a00a09a0:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a00a09a4:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xa807db00
a00a09a8:  82 5e 20 34  smul  %i0, 0x34, %g1
a00a09ac:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a09b0:  c2 03 20 74  ld  [ %o4 + 0x74 ], %g1
a00a09b4:  9b 2a c0 1a  sll  %o3, %i2, %o5
a00a09b8:  82 08 7f 00  and  %g1, -256, %g1
a00a09bc:  10 80 00 0a  b  0xa00a09e4
a00a09c0:  82 10 40 0d  or  %g1, %o5, %g1
a00a09c4:  9a 13 63 00  or  %o5, 0x300, %o5
a00a09c8:  82 5e 20 34  smul  %i0, 0x34, %g1
a00a09cc:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a09d0:  82 10 20 01  mov  1, %g1
a00a09d4:  83 28 40 1a  sll  %g1, %i2, %g1
a00a09d8:  da 03 20 74  ld  [ %o4 + 0x74 ], %o5
a00a09dc:  82 2b 40 01  andn  %o5, %g1, %g1
a00a09e0:  82 08 7f 00  and  %g1, -256, %g1
a00a09e4:  c2 23 20 74  st  %g1, [ %o4 + 0x74 ]
a00a09e8:  30 80 00 48  b,a   0xa00a0b08
a00a09ec:  80 a2 e0 01  cmp  %o3, 1
a00a09f0:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00a09f4:  12 80 00 0b  bne  0xa00a0a20
a00a09f8:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a00a09fc:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xa807db00
a00a0a00:  82 5e 20 34  smul  %i0, 0x34, %g1
a00a0a04:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a0a08:  da 03 20 78  ld  [ %o4 + 0x78 ], %o5
a00a0a0c:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a00a0a10:  82 2b 40 01  andn  %o5, %g1, %g1
a00a0a14:  9b 2a c0 1a  sll  %o3, %i2, %o5
a00a0a18:  10 80 00 0b  b  0xa00a0a44
a00a0a1c:  82 10 40 0d  or  %g1, %o5, %g1
a00a0a20:  9a 13 63 00  or  %o5, 0x300, %o5
a00a0a24:  82 5e 20 34  smul  %i0, 0x34, %g1
a00a0a28:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a0a2c:  9a 10 20 01  mov  1, %o5
a00a0a30:  c2 03 20 78  ld  [ %o4 + 0x78 ], %g1
a00a0a34:  9b 2b 40 1a  sll  %o5, %i2, %o5
a00a0a38:  9a 28 40 0d  andn  %g1, %o5, %o5
a00a0a3c:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a00a0a40:  82 2b 40 01  andn  %o5, %g1, %g1
a00a0a44:  c2 23 20 78  st  %g1, [ %o4 + 0x78 ]
a00a0a48:  30 80 00 30  b,a   0xa00a0b08
a00a0a4c:  80 a2 e0 01  cmp  %o3, 1
a00a0a50:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00a0a54:  12 80 00 0a  bne  0xa00a0a7c
a00a0a58:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a00a0a5c:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xa807db00
a00a0a60:  82 5e 20 34  smul  %i0, 0x34, %g1
a00a0a64:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a0a68:  c2 03 20 7c  ld  [ %o4 + 0x7c ], %g1
a00a0a6c:  9b 2a c0 1a  sll  %o3, %i2, %o5
a00a0a70:  82 08 7f 00  and  %g1, -256, %g1
a00a0a74:  10 80 00 0a  b  0xa00a0a9c
a00a0a78:  82 10 40 0d  or  %g1, %o5, %g1
a00a0a7c:  9a 13 63 00  or  %o5, 0x300, %o5
a00a0a80:  82 5e 20 34  smul  %i0, 0x34, %g1
a00a0a84:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a0a88:  82 10 20 01  mov  1, %g1
a00a0a8c:  83 28 40 1a  sll  %g1, %i2, %g1
a00a0a90:  da 03 20 7c  ld  [ %o4 + 0x7c ], %o5
a00a0a94:  82 2b 40 01  andn  %o5, %g1, %g1
a00a0a98:  82 08 7f 00  and  %g1, -256, %g1
a00a0a9c:  c2 23 20 7c  st  %g1, [ %o4 + 0x7c ]
a00a0aa0:  30 80 00 1a  b,a   0xa00a0b08
a00a0aa4:  80 a2 e0 01  cmp  %o3, 1
a00a0aa8:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00a0aac:  12 80 00 0c  bne  0xa00a0adc
a00a0ab0:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a00a0ab4:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xa807db00
a00a0ab8:  82 5e 20 34  smul  %i0, 0x34, %g1
a00a0abc:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a0ac0:  03 3f c0 3f  sethi  %hi(0xff00fc00), %g1
a00a0ac4:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00ff00
a00a0ac8:  da 03 20 90  ld  [ %o4 + 0x90 ], %o5
a00a0acc:  9a 0b 40 01  and  %o5, %g1, %o5
a00a0ad0:  83 2a c0 1a  sll  %o3, %i2, %g1
a00a0ad4:  10 80 00 0c  b  0xa00a0b04
a00a0ad8:  9a 13 40 01  or  %o5, %g1, %o5
a00a0adc:  9a 13 63 00  or  %o5, 0x300, %o5
a00a0ae0:  82 5e 20 34  smul  %i0, 0x34, %g1
a00a0ae4:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a0ae8:  9a 10 20 01  mov  1, %o5
a00a0aec:  c2 03 20 90  ld  [ %o4 + 0x90 ], %g1
a00a0af0:  9b 2b 40 1a  sll  %o5, %i2, %o5
a00a0af4:  9a 28 40 0d  andn  %g1, %o5, %o5
a00a0af8:  03 3f c0 3f  sethi  %hi(0xff00fc00), %g1
a00a0afc:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00ff00
a00a0b00:  9a 0b 40 01  and  %o5, %g1, %o5
a00a0b04:  da 23 20 90  st  %o5, [ %o4 + 0x90 ]
a00a0b08:  81 c7 e0 08  ret
a00a0b0c:  81 e8 00 00  restore
