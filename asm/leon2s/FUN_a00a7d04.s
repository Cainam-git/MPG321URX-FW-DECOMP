# leon2s FUN_a00a7d04 0xa00a7d04-0xa00a7d88 (132 bytes)
a00a7d04:  9d e3 bf 98  save  %sp, -104, %sp
a00a7d08:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7d0c:  9a 10 61 6c  or  %g1, 0x16c, %o5	! 0xa00b4d6c
a00a7d10:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a7d14:  83 2e 60 10  sll  %i1, 0x10, %g1
a00a7d18:  b8 06 00 18  add  %i0, %i0, %i4
a00a7d1c:  80 a6 20 01  cmp  %i0, 1
a00a7d20:  b3 2e 60 10  sll  %i1, 0x10, %i1
a00a7d24:  98 10 00 0d  mov  %o5, %o4
a00a7d28:  9e 10 00 1c  mov  %i4, %o7
a00a7d2c:  bb 30 60 10  srl  %g1, 0x10, %i5
a00a7d30:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00a7d34:  18 80 00 13  bgu  0xa00a7d80
a00a7d38:  b1 36 60 10  srl  %i1, 0x10, %i0
a00a7d3c:  c2 13 40 1c  lduh  [ %o5 + %i4 ], %g1
a00a7d40:  82 00 40 1d  add  %g1, %i5, %g1
a00a7d44:  83 28 60 02  sll  %g1, 2, %g1
a00a7d48:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a7d4c:  82 10 40 1d  or  %g1, %i5, %g1
a00a7d50:  c2 00 40 00  ld  [ %g1 ], %g1
a00a7d54:  80 a6 e0 01  cmp  %i3, 1
a00a7d58:  02 80 00 03  be  0xa00a7d64
a00a7d5c:  b8 10 40 1a  or  %g1, %i2, %i4
a00a7d60:  b8 28 40 1a  andn  %g1, %i2, %i4
a00a7d64:  c2 13 00 0f  lduh  [ %o4 + %o7 ], %g1
a00a7d68:  82 00 40 18  add  %g1, %i0, %g1
a00a7d6c:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a7d70:  83 28 60 02  sll  %g1, 2, %g1
a00a7d74:  82 10 40 1d  or  %g1, %i5, %g1
a00a7d78:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00a7d7c:  fa 20 40 00  st  %i5, [ %g1 ]
a00a7d80:  81 c7 e0 08  ret
a00a7d84:  81 e8 00 00  restore
