# leon2m FUN_a00f29d4 0xa00f29d4-0xa00f2b48 (372 bytes)
a00f29d4:  9d e3 bf 98  save  %sp, -104, %sp
a00f29d8:  94 0e 20 ff  and  %i0, 0xff, %o2
a00f29dc:  80 a2 a0 08  cmp  %o2, 8
a00f29e0:  ba 60 20 00  subx  %g0, 0, %i5
a00f29e4:  b8 0e 00 1d  and  %i0, %i5, %i4
a00f29e8:  96 10 00 18  mov  %i0, %o3
a00f29ec:  b0 0f 20 ff  and  %i4, 0xff, %i0
a00f29f0:  1f 00 06 68  sethi  %hi(0x19a000), %o7
a00f29f4:  b4 06 00 18  add  %i0, %i0, %i2
a00f29f8:  9e 13 e2 ec  or  %o7, 0x2ec, %o7
a00f29fc:  f6 13 c0 1a  lduh  [ %o7 + %i2 ], %i3
a00f2a00:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00f2a04:  b6 06 c0 0d  add  %i3, %o5, %i3
a00f2a08:  b2 06 e0 02  add  %i3, 2, %i1
a00f2a0c:  83 2e 60 02  sll  %i1, 2, %g1
a00f2a10:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a00f2a14:  ba 06 e0 01  add  %i3, 1, %i5
a00f2a18:  b8 10 40 19  or  %g1, %i1, %i4
a00f2a1c:  b1 2f 60 02  sll  %i5, 2, %i0
a00f2a20:  fa 07 00 00  ld  [ %i4 ], %i5
a00f2a24:  b4 16 00 19  or  %i0, %i1, %i2
a00f2a28:  f0 06 80 00  ld  [ %i2 ], %i0
a00f2a2c:  83 2e e0 02  sll  %i3, 2, %g1
a00f2a30:  b6 10 40 19  or  %g1, %i1, %i3
a00f2a34:  b5 2f 60 08  sll  %i5, 8, %i2
a00f2a38:  b8 0e 20 ff  and  %i0, 0xff, %i4
a00f2a3c:  f0 06 c0 00  ld  [ %i3 ], %i0
a00f2a40:  b2 16 80 1c  or  %i2, %i4, %i1
a00f2a44:  bb 2e 60 08  sll  %i1, 8, %i5
a00f2a48:  82 0e 20 ff  and  %i0, 0xff, %g1
a00f2a4c:  b0 17 40 01  or  %i5, %g1, %i0
a00f2a50:  90 10 00 0f  mov  %o7, %o0
a00f2a54:  10 80 00 1b  b  0xa00f2ac0
a00f2a58:  98 10 20 00  clr  %o4
a00f2a5c:  18 80 00 39  bgu  0xa00f2b40
a00f2a60:  80 a2 a0 07  cmp  %o2, 7
a00f2a64:  38 80 00 02  bgu,a   0xa00f2a6c
a00f2a68:  92 10 20 00  clr  %o1
a00f2a6c:  82 0a 60 ff  and  %o1, 0xff, %g1
a00f2a70:  ba 00 40 01  add  %g1, %g1, %i5
a00f2a74:  f6 12 00 1d  lduh  [ %o0 + %i5 ], %i3
a00f2a78:  b6 06 c0 0d  add  %i3, %o5, %i3
a00f2a7c:  b8 06 e0 02  add  %i3, 2, %i4
a00f2a80:  b1 2f 20 02  sll  %i4, 2, %i0
a00f2a84:  b4 06 e0 01  add  %i3, 1, %i2
a00f2a88:  82 16 00 19  or  %i0, %i1, %g1
a00f2a8c:  bb 2e a0 02  sll  %i2, 2, %i5
a00f2a90:  b8 17 40 19  or  %i5, %i1, %i4
a00f2a94:  f4 00 40 00  ld  [ %g1 ], %i2
a00f2a98:  c2 07 00 00  ld  [ %i4 ], %g1
a00f2a9c:  b1 2e e0 02  sll  %i3, 2, %i0
a00f2aa0:  b6 16 00 19  or  %i0, %i1, %i3
a00f2aa4:  b9 2e a0 08  sll  %i2, 8, %i4
a00f2aa8:  ba 08 60 ff  and  %g1, 0xff, %i5
a00f2aac:  b0 17 00 1d  or  %i4, %i5, %i0
a00f2ab0:  f4 06 c0 00  ld  [ %i3 ], %i2
a00f2ab4:  b3 2e 20 08  sll  %i0, 8, %i1
a00f2ab8:  82 0e a0 ff  and  %i2, 0xff, %g1
a00f2abc:  b0 16 40 01  or  %i1, %g1, %i0
a00f2ac0:  9e 0b 20 ff  and  %o4, 0xff, %o7
a00f2ac4:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a00f2ac8:  80 a2 a0 07  cmp  %o2, 7
a00f2acc:  82 10 00 0b  mov  %o3, %g1
a00f2ad0:  92 10 00 0b  mov  %o3, %o1
a00f2ad4:  08 80 00 03  bleu  0xa00f2ae0
a00f2ad8:  98 03 20 01  inc  %o4
a00f2adc:  82 10 20 00  clr  %g1
a00f2ae0:  ba 08 60 ff  and  %g1, 0xff, %i5
a00f2ae4:  82 07 40 1d  add  %i5, %i5, %g1
a00f2ae8:  f6 12 00 01  lduh  [ %o0 + %g1 ], %i3
a00f2aec:  b6 06 c0 0d  add  %i3, %o5, %i3
a00f2af0:  b4 06 e0 02  add  %i3, 2, %i2
a00f2af4:  b9 2e a0 02  sll  %i2, 2, %i4
a00f2af8:  ba 06 e0 01  add  %i3, 1, %i5
a00f2afc:  82 17 00 19  or  %i4, %i1, %g1
a00f2b00:  b5 2f 60 02  sll  %i5, 2, %i2
a00f2b04:  fa 00 40 00  ld  [ %g1 ], %i5
a00f2b08:  b8 16 80 19  or  %i2, %i1, %i4
a00f2b0c:  f4 07 00 00  ld  [ %i4 ], %i2
a00f2b10:  b7 2e e0 02  sll  %i3, 2, %i3
a00f2b14:  83 2f 60 08  sll  %i5, 8, %g1
a00f2b18:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00f2b1c:  b8 16 c0 19  or  %i3, %i1, %i4
a00f2b20:  ba 10 40 1a  or  %g1, %i2, %i5
a00f2b24:  c2 07 00 00  ld  [ %i4 ], %g1
a00f2b28:  b9 2f 60 08  sll  %i5, 8, %i4
a00f2b2c:  b6 08 60 ff  and  %g1, 0xff, %i3
a00f2b30:  b4 17 00 1b  or  %i4, %i3, %i2
a00f2b34:  80 a6 80 18  cmp  %i2, %i0
a00f2b38:  12 bf ff c9  bne  0xa00f2a5c
a00f2b3c:  80 a3 e0 04  cmp  %o7, 4
a00f2b40:  81 c7 e0 08  ret
a00f2b44:  81 e8 00 00  restore
