# leon2s FUN_a00a7bf8 0xa00a7bf8-0xa00a7cc0 (200 bytes)
a00a7bf8:  9d e3 bf 98  save  %sp, -104, %sp
a00a7bfc:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7c00:  96 10 61 70  or  %g1, 0x170, %o3	! 0xa00b4d70
a00a7c04:  82 10 00 19  mov  %i1, %g1
a00a7c08:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a7c0c:  83 28 60 10  sll  %g1, 0x10, %g1
a00a7c10:  9e 06 00 18  add  %i0, %i0, %o7
a00a7c14:  b9 30 60 10  srl  %g1, 0x10, %i4
a00a7c18:  94 10 00 0b  mov  %o3, %o2
a00a7c1c:  98 10 00 0f  mov  %o7, %o4
a00a7c20:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00a7c24:  80 a6 20 04  cmp  %i0, 4
a00a7c28:  18 80 00 24  bgu  0xa00a7cb8
a00a7c2c:  9a 10 00 1c  mov  %i4, %o5
a00a7c30:  83 2e 60 10  sll  %i1, 0x10, %g1
a00a7c34:  80 a6 20 00  cmp  %i0, 0
a00a7c38:  02 80 00 0f  be  0xa00a7c74
a00a7c3c:  b3 30 60 10  srl  %g1, 0x10, %i1
a00a7c40:  82 06 3f ff  add  %i0, -1, %g1
a00a7c44:  80 a6 60 5f  cmp  %i1, 0x5f
a00a7c48:  18 80 00 0b  bgu  0xa00a7c74
a00a7c4c:  b1 28 60 06  sll  %g1, 6, %i0
a00a7c50:  fa 12 c0 0f  lduh  [ %o3 + %o7 ], %i5
a00a7c54:  ba 07 60 60  add  %i5, 0x60, %i5
a00a7c58:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00a7c5c:  bb 2f 60 02  sll  %i5, 2, %i5
a00a7c60:  ba 17 40 01  or  %i5, %g1, %i5
a00a7c64:  c2 07 40 00  ld  [ %i5 ], %g1
a00a7c68:  82 08 60 3f  and  %g1, 0x3f, %g1
a00a7c6c:  82 10 40 18  or  %g1, %i0, %g1
a00a7c70:  c2 27 40 00  st  %g1, [ %i5 ]
a00a7c74:  c2 12 c0 0f  lduh  [ %o3 + %o7 ], %g1
a00a7c78:  82 00 40 1c  add  %g1, %i4, %g1
a00a7c7c:  83 28 60 02  sll  %g1, 2, %g1
a00a7c80:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a7c84:  82 10 40 1d  or  %g1, %i5, %g1
a00a7c88:  c2 00 40 00  ld  [ %g1 ], %g1
a00a7c8c:  80 a6 e0 01  cmp  %i3, 1
a00a7c90:  02 80 00 03  be  0xa00a7c9c
a00a7c94:  b8 10 40 1a  or  %g1, %i2, %i4
a00a7c98:  b8 28 40 1a  andn  %g1, %i2, %i4
a00a7c9c:  c2 12 80 0c  lduh  [ %o2 + %o4 ], %g1
a00a7ca0:  82 00 40 0d  add  %g1, %o5, %g1
a00a7ca4:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a7ca8:  83 28 60 02  sll  %g1, 2, %g1
a00a7cac:  82 10 40 1d  or  %g1, %i5, %g1
a00a7cb0:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00a7cb4:  fa 20 40 00  st  %i5, [ %g1 ]
a00a7cb8:  81 c7 e0 08  ret
a00a7cbc:  81 e8 00 00  restore
