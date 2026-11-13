# leon2s FUN_a00a7e14 0xa00a7e14-0xa00a7e98 (132 bytes)
a00a7e14:  9d e3 bf 98  save  %sp, -104, %sp
a00a7e18:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7e1c:  9a 10 61 64  or  %g1, 0x164, %o5	! 0xa00b4d64
a00a7e20:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a7e24:  83 2e 60 10  sll  %i1, 0x10, %g1
a00a7e28:  b8 06 00 18  add  %i0, %i0, %i4
a00a7e2c:  80 a6 20 03  cmp  %i0, 3
a00a7e30:  b3 2e 60 10  sll  %i1, 0x10, %i1
a00a7e34:  98 10 00 0d  mov  %o5, %o4
a00a7e38:  9e 10 00 1c  mov  %i4, %o7
a00a7e3c:  bb 30 60 10  srl  %g1, 0x10, %i5
a00a7e40:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00a7e44:  18 80 00 13  bgu  0xa00a7e90
a00a7e48:  b1 36 60 10  srl  %i1, 0x10, %i0
a00a7e4c:  c2 13 40 1c  lduh  [ %o5 + %i4 ], %g1
a00a7e50:  82 00 40 1d  add  %g1, %i5, %g1
a00a7e54:  83 28 60 02  sll  %g1, 2, %g1
a00a7e58:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a7e5c:  82 10 40 1d  or  %g1, %i5, %g1
a00a7e60:  c2 00 40 00  ld  [ %g1 ], %g1
a00a7e64:  80 a6 e0 01  cmp  %i3, 1
a00a7e68:  02 80 00 03  be  0xa00a7e74
a00a7e6c:  b8 10 40 1a  or  %g1, %i2, %i4
a00a7e70:  b8 28 40 1a  andn  %g1, %i2, %i4
a00a7e74:  c2 13 00 0f  lduh  [ %o4 + %o7 ], %g1
a00a7e78:  82 00 40 18  add  %g1, %i0, %g1
a00a7e7c:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a7e80:  83 28 60 02  sll  %g1, 2, %g1
a00a7e84:  82 10 40 1d  or  %g1, %i5, %g1
a00a7e88:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00a7e8c:  fa 20 40 00  st  %i5, [ %g1 ]
a00a7e90:  81 c7 e0 08  ret
a00a7e94:  81 e8 00 00  restore
