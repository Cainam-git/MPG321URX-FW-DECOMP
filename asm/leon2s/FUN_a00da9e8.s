# leon2s FUN_a00da9e8 0xa00da9e8-0xa00daa98 (176 bytes)
a00da9e8:  9d e3 bf 98  save  %sp, -104, %sp
a00da9ec:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00da9f0:  c2 08 63 fc  ldub  [ %g1 + 0x3fc ], %g1	! 0xa80787fc
a00da9f4:  b6 00 40 01  add  %g1, %g1, %i3
a00da9f8:  b6 06 c0 01  add  %i3, %g1, %i3
a00da9fc:  35 2a 01 e7  sethi  %hi(0xa8079c00), %i2
a00daa00:  b7 2e e0 04  sll  %i3, 4, %i3
a00daa04:  b4 16 a0 98  or  %i2, 0x98, %i2
a00daa08:  f8 0e c0 1a  ldub  [ %i3 + %i2 ], %i4
a00daa0c:  82 0f 20 ff  and  %i4, 0xff, %g1
a00daa10:  b3 30 60 04  srl  %g1, 4, %i1
a00daa14:  ba 06 7f ff  add  %i1, -1, %i5
a00daa18:  83 37 60 1f  srl  %i5, 0x1f, %g1
a00daa1c:  82 07 40 01  add  %i5, %g1, %g1
a00daa20:  b8 0f 20 0f  and  %i4, 0xf, %i4
a00daa24:  b1 38 60 01  sra  %g1, 1, %i0
a00daa28:  80 8f 60 01  btst  1, %i5
a00daa2c:  9a 0f 20 ff  and  %i4, 0xff, %o5
a00daa30:  ba 26 40 0d  sub  %i1, %o5, %i5
a00daa34:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00daa38:  ba 07 40 1d  add  %i5, %i5, %i5
a00daa3c:  82 10 60 3d  or  %g1, 0x3d, %g1
a00daa40:  9e 07 40 01  add  %i5, %g1, %o7
a00daa44:  ba 10 00 18  mov  %i0, %i5
a00daa48:  02 80 00 03  be  0xa00daa54
a00daa4c:  b6 06 c0 1a  add  %i3, %i2, %i3
a00daa50:  ba 06 20 01  add  %i0, 1, %i5
a00daa54:  ba 0f 60 ff  and  %i5, 0xff, %i5
a00daa58:  ba 06 c0 1d  add  %i3, %i5, %i5
a00daa5c:  c2 0f 60 02  ldub  [ %i5 + 2 ], %g1
a00daa60:  82 08 60 10  and  %g1, 0x10, %g1
a00daa64:  80 a0 00 01  cmp  %g0, %g1
a00daa68:  b8 40 20 00  addx  %g0, 0, %i4
a00daa6c:  c2 0f 60 03  ldub  [ %i5 + 3 ], %g1
a00daa70:  82 08 60 7f  and  %g1, 0x7f, %g1
a00daa74:  fa 0b c0 1c  ldub  [ %o7 + %i4 ], %i5
a00daa78:  ba 1f 40 01  xor  %i5, %g1, %i5
a00daa7c:  80 a0 00 1d  cmp  %g0, %i5
a00daa80:  82 40 20 00  addx  %g0, 0, %g1
a00daa84:  80 a3 40 19  cmp  %o5, %i1
a00daa88:  b0 40 20 00  addx  %g0, 0, %i0
a00daa8c:  b0 08 40 18  and  %g1, %i0, %i0
a00daa90:  81 c7 e0 08  ret
a00daa94:  81 e8 00 00  restore
