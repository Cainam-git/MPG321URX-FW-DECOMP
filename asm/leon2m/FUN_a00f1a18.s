# leon2m FUN_a00f1a18 0xa00f1a18-0xa00f1a90 (120 bytes)
a00f1a18:  9d e3 bf 98  save  %sp, -104, %sp
a00f1a1c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f1a20:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f1a24:  bb 2e 20 02  sll  %i0, 2, %i5
a00f1a28:  b9 2e 60 10  sll  %i1, 0x10, %i4
a00f1a2c:  9e 13 62 d8  or  %o5, 0x2d8, %o7
a00f1a30:  c2 03 c0 1d  ld  [ %o7 + %i5 ], %g1
a00f1a34:  b9 37 20 10  srl  %i4, 0x10, %i4
a00f1a38:  82 00 40 1c  add  %g1, %i4, %g1
a00f1a3c:  b0 10 00 1d  mov  %i5, %i0
a00f1a40:  b9 28 60 02  sll  %g1, 2, %i4
a00f1a44:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00f1a48:  82 17 00 1d  or  %i4, %i5, %g1
a00f1a4c:  c2 00 40 00  ld  [ %g1 ], %g1
a00f1a50:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00f1a54:  b3 2e 60 10  sll  %i1, 0x10, %i1
a00f1a58:  80 a6 e0 01  cmp  %i3, 1
a00f1a5c:  b8 10 40 1a  or  %g1, %i2, %i4
a00f1a60:  02 80 00 03  be  0xa00f1a6c
a00f1a64:  9b 36 60 10  srl  %i1, 0x10, %o5
a00f1a68:  b8 28 40 1a  andn  %g1, %i2, %i4
a00f1a6c:  f4 03 c0 18  ld  [ %o7 + %i0 ], %i2
a00f1a70:  82 06 80 0d  add  %i2, %o5, %g1
a00f1a74:  b7 28 60 02  sll  %g1, 2, %i3
a00f1a78:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00f1a7c:  b4 16 c0 1d  or  %i3, %i5, %i2
a00f1a80:  b2 0f 20 ff  and  %i4, 0xff, %i1
a00f1a84:  f2 26 80 00  st  %i1, [ %i2 ]
a00f1a88:  81 c7 e0 08  ret
a00f1a8c:  81 e8 00 00  restore
