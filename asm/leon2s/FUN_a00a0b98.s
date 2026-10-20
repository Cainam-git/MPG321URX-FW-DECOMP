# leon2s FUN_a00a0b98 0xa00a0b98-0xa00a0bfc (100 bytes)
a00a0b98:  9d e3 bf 98  save  %sp, -104, %sp
a00a0b9c:  82 10 20 01  mov  1, %g1
a00a0ba0:  b7 28 40 19  sll  %g1, %i1, %i3
a00a0ba4:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00a0ba8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a0bac:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a0bb0:  9f 2e 80 19  sll  %i2, %i1, %o7
a00a0bb4:  b8 5e 20 34  smul  %i0, 0x34, %i4
a00a0bb8:  80 a6 a0 01  cmp  %i2, 1
a00a0bbc:  12 80 00 08  bne  0xa00a0bdc
a00a0bc0:  ba 10 63 00  or  %g1, 0x300, %i5
a00a0bc4:  f8 07 40 1c  ld  [ %i5 + %i4 ], %i4
a00a0bc8:  fa 07 20 78  ld  [ %i4 + 0x78 ], %i5
a00a0bcc:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a00a0bd0:  82 2f 40 01  andn  %i5, %g1, %g1
a00a0bd4:  10 80 00 07  b  0xa00a0bf0
a00a0bd8:  82 10 40 0f  or  %g1, %o7, %g1
a00a0bdc:  f8 07 40 1c  ld  [ %i5 + %i4 ], %i4
a00a0be0:  fa 07 20 78  ld  [ %i4 + 0x78 ], %i5
a00a0be4:  ba 2f 40 1b  andn  %i5, %i3, %i5
a00a0be8:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a00a0bec:  82 2f 40 01  andn  %i5, %g1, %g1
a00a0bf0:  c2 27 20 78  st  %g1, [ %i4 + 0x78 ]
a00a0bf4:  81 c7 e0 08  ret
a00a0bf8:  81 e8 00 00  restore
