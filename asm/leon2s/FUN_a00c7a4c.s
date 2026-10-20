# leon2s FUN_a00c7a4c 0xa00c7a4c-0xa00c7b60 (276 bytes)
a00c7a4c:  9d e3 bf 98  save  %sp, -104, %sp
a00c7a50:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c7a54:  82 06 00 18  add  %i0, %i0, %g1
a00c7a58:  82 00 40 18  add  %g1, %i0, %g1
a00c7a5c:  3b 2a 01 e2  sethi  %hi(0xa8078800), %i5
a00c7a60:  b7 28 60 03  sll  %g1, 3, %i3
a00c7a64:  b4 17 63 b0  or  %i5, 0x3b0, %i2
a00c7a68:  fa 06 80 1b  ld  [ %i2 + %i3 ], %i5
a00c7a6c:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00c7a70:  ba 17 40 01  or  %i5, %g1, %i5
a00c7a74:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00c7a78:  82 2f 40 01  andn  %i5, %g1, %g1
a00c7a7c:  3b 08 00 00  sethi  %hi(0x20000000), %i5
a00c7a80:  ba 28 40 1d  andn  %g1, %i5, %i5
a00c7a84:  39 00 00 c0  sethi  %hi(0x30000), %i4
a00c7a88:  b8 2f 40 1c  andn  %i5, %i4, %i4
a00c7a8c:  03 00 00 40  sethi  %hi(0x10000), %g1
a00c7a90:  b8 17 00 01  or  %i4, %g1, %i4
a00c7a94:  03 04 00 00  sethi  %hi(0x10000000), %g1
a00c7a98:  82 2f 00 01  andn  %i4, %g1, %g1
a00c7a9c:  3b 03 c0 00  sethi  %hi(0xf000000), %i5
a00c7aa0:  ba 28 40 1d  andn  %g1, %i5, %i5
a00c7aa4:  03 01 40 00  sethi  %hi(0x5000000), %g1
a00c7aa8:  ba 17 40 01  or  %i5, %g1, %i5
a00c7aac:  1f 2a 01 f5  sethi  %hi(0xa807d400), %o7
a00c7ab0:  c2 0b e2 36  ldub  [ %o7 + 0x236 ], %g1	! 0xa807d636
a00c7ab4:  80 a0 40 18  cmp  %g1, %i0
a00c7ab8:  fa 26 80 1b  st  %i5, [ %i2 + %i3 ]
a00c7abc:  b8 06 c0 1a  add  %i3, %i2, %i4
a00c7ac0:  82 10 20 01  mov  1, %g1
a00c7ac4:  c2 2f 20 02  stb  %g1, [ %i4 + 2 ]
a00c7ac8:  ba 10 3f ff  mov  -1, %i5
a00c7acc:  82 10 20 64  mov  0x64, %g1
a00c7ad0:  c2 37 20 16  sth  %g1, [ %i4 + 0x16 ]
a00c7ad4:  12 80 00 03  bne  0xa00c7ae0
a00c7ad8:  fa 2f 20 09  stb  %i5, [ %i4 + 9 ]
a00c7adc:  fa 2b e2 36  stb  %i5, [ %o7 + 0x236 ]
a00c7ae0:  80 8e 60 ff  btst  0xff, %i1
a00c7ae4:  02 80 00 10  be  0xa00c7b24
a00c7ae8:  c2 06 80 1b  ld  [ %i2 + %i3 ], %g1
a00c7aec:  3b 00 01 00  sethi  %hi(0x40000), %i5
a00c7af0:  82 10 40 1d  or  %g1, %i5, %g1
a00c7af4:  3b 00 20 00  sethi  %hi(0x800000), %i5
a00c7af8:  ba 28 40 1d  andn  %g1, %i5, %i5
a00c7afc:  03 00 02 00  sethi  %hi(0x80000), %g1
a00c7b00:  82 2f 40 01  andn  %i5, %g1, %g1
a00c7b04:  c2 26 80 1b  st  %g1, [ %i2 + %i3 ]
a00c7b08:  c0 2f 20 03  clrb  [ %i4 + 3 ]
a00c7b0c:  c0 2f 20 04  clrb  [ %i4 + 4 ]
a00c7b10:  c0 2f 20 05  clrb  [ %i4 + 5 ]
a00c7b14:  c0 2f 20 06  clrb  [ %i4 + 6 ]
a00c7b18:  c0 2f 20 07  clrb  [ %i4 + 7 ]
a00c7b1c:  c0 2f 20 08  clrb  [ %i4 + 8 ]
a00c7b20:  c2 06 80 1b  ld  [ %i2 + %i3 ], %g1
a00c7b24:  3b 00 10 00  sethi  %hi(0x400000), %i5
a00c7b28:  82 10 40 1d  or  %g1, %i5, %g1
a00c7b2c:  c2 26 80 1b  st  %g1, [ %i2 + %i3 ]
a00c7b30:  82 10 20 1f  mov  0x1f, %g1
a00c7b34:  c2 2f 20 14  stb  %g1, [ %i4 + 0x14 ]
a00c7b38:  c0 27 20 10  clr  [ %i4 + 0x10 ]
a00c7b3c:  c0 27 20 0c  clr  [ %i4 + 0xc ]
a00c7b40:  c2 06 80 1b  ld  [ %i2 + %i3 ], %g1
a00c7b44:  3b 00 04 00  sethi  %hi(0x100000), %i5
a00c7b48:  ba 28 40 1d  andn  %g1, %i5, %i5
a00c7b4c:  03 00 08 00  sethi  %hi(0x200000), %g1
a00c7b50:  82 2f 40 01  andn  %i5, %g1, %g1
a00c7b54:  c2 26 80 1b  st  %g1, [ %i2 + %i3 ]
a00c7b58:  81 c7 e0 08  ret
a00c7b5c:  81 e8 00 00  restore
