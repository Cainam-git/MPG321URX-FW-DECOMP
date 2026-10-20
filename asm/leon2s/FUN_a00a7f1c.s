# leon2s FUN_a00a7f1c 0xa00a7f1c-0xa00a7fa0 (132 bytes)
a00a7f1c:  9d e3 bf 98  save  %sp, -104, %sp
a00a7f20:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7f24:  9a 10 61 5c  or  %g1, 0x15c, %o5	! 0xa00b4d5c
a00a7f28:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a7f2c:  83 2e 60 10  sll  %i1, 0x10, %g1
a00a7f30:  b8 06 00 18  add  %i0, %i0, %i4
a00a7f34:  80 a6 20 03  cmp  %i0, 3
a00a7f38:  b3 2e 60 10  sll  %i1, 0x10, %i1
a00a7f3c:  98 10 00 0d  mov  %o5, %o4
a00a7f40:  9e 10 00 1c  mov  %i4, %o7
a00a7f44:  bb 30 60 10  srl  %g1, 0x10, %i5
a00a7f48:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00a7f4c:  18 80 00 13  bgu  0xa00a7f98
a00a7f50:  b1 36 60 10  srl  %i1, 0x10, %i0
a00a7f54:  c2 13 40 1c  lduh  [ %o5 + %i4 ], %g1
a00a7f58:  82 00 40 1d  add  %g1, %i5, %g1
a00a7f5c:  83 28 60 02  sll  %g1, 2, %g1
a00a7f60:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a7f64:  82 10 40 1d  or  %g1, %i5, %g1
a00a7f68:  c2 00 40 00  ld  [ %g1 ], %g1
a00a7f6c:  80 a6 e0 01  cmp  %i3, 1
a00a7f70:  02 80 00 03  be  0xa00a7f7c
a00a7f74:  b8 10 40 1a  or  %g1, %i2, %i4
a00a7f78:  b8 28 40 1a  andn  %g1, %i2, %i4
a00a7f7c:  c2 13 00 0f  lduh  [ %o4 + %o7 ], %g1
a00a7f80:  82 00 40 18  add  %g1, %i0, %g1
a00a7f84:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a7f88:  83 28 60 02  sll  %g1, 2, %g1
a00a7f8c:  82 10 40 1d  or  %g1, %i5, %g1
a00a7f90:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00a7f94:  fa 20 40 00  st  %i5, [ %g1 ]
a00a7f98:  81 c7 e0 08  ret
a00a7f9c:  81 e8 00 00  restore
