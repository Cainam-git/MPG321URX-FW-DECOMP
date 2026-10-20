# leon2s FUN_a00a6c98 0xa00a6c98-0xa00a6da8 (272 bytes)
a00a6c98:  9d e3 bf 98  save  %sp, -104, %sp
a00a6c9c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a6ca0:  80 a6 20 02  cmp  %i0, 2
a00a6ca4:  9a 10 00 19  mov  %i1, %o5
a00a6ca8:  18 80 00 3e  bgu  0xa00a6da0
a00a6cac:  98 10 00 1a  mov  %i2, %o4
a00a6cb0:  80 a6 20 02  cmp  %i0, 2
a00a6cb4:  12 80 00 21  bne  0xa00a6d38
a00a6cb8:  1f 28 02 d3  sethi  %hi(0xa00b4c00), %o7
a00a6cbc:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00a6cc0:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a6cc4:  96 10 61 94  or  %g1, 0x194, %o3	! 0xa00b4d94
a00a6cc8:  b3 37 60 10  srl  %i5, 0x10, %i1
a00a6ccc:  9e 0e e0 ff  and  %i3, 0xff, %o7
a00a6cd0:  b4 38 00 1a  xnor  %g0, %i2, %i2
a00a6cd4:  b8 10 20 00  clr  %i4
a00a6cd8:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a6cdc:  82 0f 20 ff  and  %i4, 0xff, %g1
a00a6ce0:  ba 00 40 01  add  %g1, %g1, %i5
a00a6ce4:  c2 12 c0 1d  lduh  [ %o3 + %i5 ], %g1
a00a6ce8:  82 00 40 19  add  %g1, %i1, %g1
a00a6cec:  83 28 60 02  sll  %g1, 2, %g1
a00a6cf0:  82 10 40 0d  or  %g1, %o5, %g1
a00a6cf4:  b8 07 20 01  inc  %i4
a00a6cf8:  c2 00 40 00  ld  [ %g1 ], %g1
a00a6cfc:  b0 0f 20 ff  and  %i4, 0xff, %i0
a00a6d00:  80 a3 e0 01  cmp  %o7, 1
a00a6d04:  02 80 00 03  be  0xa00a6d10
a00a6d08:  b6 10 40 0c  or  %g1, %o4, %i3
a00a6d0c:  b6 08 40 1a  and  %g1, %i2, %i3
a00a6d10:  c2 12 c0 1d  lduh  [ %o3 + %i5 ], %g1
a00a6d14:  82 00 40 19  add  %g1, %i1, %g1
a00a6d18:  83 28 60 02  sll  %g1, 2, %g1
a00a6d1c:  82 10 40 0d  or  %g1, %o5, %g1
a00a6d20:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00a6d24:  fa 20 40 00  st  %i5, [ %g1 ]
a00a6d28:  80 a6 20 01  cmp  %i0, 1
a00a6d2c:  08 bf ff ed  bleu  0xa00a6ce0
a00a6d30:  82 0f 20 ff  and  %i4, 0xff, %g1
a00a6d34:  30 80 00 1b  b,a   0xa00a6da0
a00a6d38:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00a6d3c:  b8 13 e1 94  or  %o7, 0x194, %i4
a00a6d40:  82 06 00 18  add  %i0, %i0, %g1
a00a6d44:  bb 37 60 10  srl  %i5, 0x10, %i5
a00a6d48:  c2 17 00 01  lduh  [ %i4 + %g1 ], %g1
a00a6d4c:  82 00 40 1d  add  %g1, %i5, %g1
a00a6d50:  83 28 60 02  sll  %g1, 2, %g1
a00a6d54:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a6d58:  82 10 40 1d  or  %g1, %i5, %g1
a00a6d5c:  f2 00 40 00  ld  [ %g1 ], %i1
a00a6d60:  82 0e e0 ff  and  %i3, 0xff, %g1
a00a6d64:  80 a0 60 01  cmp  %g1, 1
a00a6d68:  02 80 00 04  be  0xa00a6d78
a00a6d6c:  b6 16 40 1a  or  %i1, %i2, %i3
a00a6d70:  b6 2e 40 1a  andn  %i1, %i2, %i3
a00a6d74:  b8 13 e1 94  or  %o7, 0x194, %i4
a00a6d78:  82 06 00 18  add  %i0, %i0, %g1
a00a6d7c:  bb 2b 60 10  sll  %o5, 0x10, %i5
a00a6d80:  bb 37 60 10  srl  %i5, 0x10, %i5
a00a6d84:  c2 17 00 01  lduh  [ %i4 + %g1 ], %g1
a00a6d88:  82 00 40 1d  add  %g1, %i5, %g1
a00a6d8c:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a6d90:  83 28 60 02  sll  %g1, 2, %g1
a00a6d94:  82 10 40 1d  or  %g1, %i5, %g1
a00a6d98:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00a6d9c:  fa 20 40 00  st  %i5, [ %g1 ]
a00a6da0:  81 c7 e0 08  ret
a00a6da4:  81 e8 00 00  restore
