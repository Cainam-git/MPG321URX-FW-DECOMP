# leon2m FUN_a010dc8c 0xa010dc8c-0xa010de54 (456 bytes)
a010dc8c:  9d e3 bf 98  save  %sp, -104, %sp
a010dc90:  b0 0e 20 ff  and  %i0, 0xff, %i0
a010dc94:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010dc98:  94 10 00 1b  mov  %i3, %o2
a010dc9c:  80 a6 20 01  cmp  %i0, 1
a010dca0:  02 80 00 67  be  0xa010de3c
a010dca4:  9e 10 63 04  or  %g1, 0x304, %o7
a010dca8:  f6 0b e0 24  ldub  [ %o7 + 0x24 ], %i3
a010dcac:  83 36 e0 03  srl  %i3, 3, %g1
a010dcb0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a010dcb4:  ba 0f 20 1f  and  %i4, 0x1f, %i5
a010dcb8:  81 80 00 00  mov  %g0, %y
a010dcbc:  01 00 00 00  nop
a010dcc0:  01 00 00 00  nop
a010dcc4:  01 00 00 00  nop
a010dcc8:  98 77 40 01  udiv  %i5, %g1, %o4
a010dccc:  80 a6 60 00  cmp  %i1, 0
a010dcd0:  12 80 00 4b  bne  0xa010ddfc
a010dcd4:  bb 37 20 05  srl  %i4, 5, %i5
a010dcd8:  83 37 20 05  srl  %i4, 5, %g1
a010dcdc:  c2 23 e0 04  st  %g1, [ %o7 + 4 ]
a010dce0:  f4 33 e0 10  sth  %i2, [ %o7 + 0x10 ]
a010dce4:  f8 13 e0 0c  lduh  [ %o7 + 0xc ], %i4
a010dce8:  d4 33 e0 0e  sth  %o2, [ %o7 + 0xe ]
a010dcec:  9b 2f 20 10  sll  %i4, 0x10, %o5
a010dcf0:  80 a6 60 00  cmp  %i1, 0
a010dcf4:  12 80 00 3a  bne  0xa010dddc
a010dcf8:  96 10 00 1c  mov  %i4, %o3
a010dcfc:  39 00 06 6b  sethi  %hi(0x19ac00), %i4
a010dd00:  bb 2e 20 02  sll  %i0, 2, %i5
a010dd04:  82 17 22 c4  or  %i4, 0x2c4, %g1
a010dd08:  f6 00 40 1d  ld  [ %g1 + %i5 ], %i3
a010dd0c:  da 26 e0 04  st  %o5, [ %i3 + 4 ]
a010dd10:  d8 26 e0 18  st  %o4, [ %i3 + 0x18 ]
a010dd14:  83 2e a0 10  sll  %i2, 0x10, %g1
a010dd18:  b5 30 60 10  srl  %g1, 0x10, %i2
a010dd1c:  37 00 06 6b  sethi  %hi(0x19ac00), %i3
a010dd20:  83 2e 20 02  sll  %i0, 2, %g1
a010dd24:  80 a6 60 00  cmp  %i1, 0
a010dd28:  02 80 00 05  be  0xa010dd3c
a010dd2c:  ba 16 e2 c4  or  %i3, 0x2c4, %i5
a010dd30:  3b 00 06 6b  sethi  %hi(0x19ac00), %i5
a010dd34:  83 2e 20 02  sll  %i0, 2, %g1
a010dd38:  ba 17 62 bc  or  %i5, 0x2bc, %i5
a010dd3c:  f6 07 40 01  ld  [ %i5 + %g1 ], %i3
a010dd40:  f4 26 e0 20  st  %i2, [ %i3 + 0x20 ]
a010dd44:  f4 0b e0 24  ldub  [ %o7 + 0x24 ], %i2
a010dd48:  b7 2a e0 10  sll  %o3, 0x10, %i3
a010dd4c:  b9 36 a0 03  srl  %i2, 3, %i4
a010dd50:  ba 10 20 20  mov  0x20, %i5
a010dd54:  83 36 e0 10  srl  %i3, 0x10, %g1
a010dd58:  9b 3f 60 1f  sra  %i5, 0x1f, %o5
a010dd5c:  81 83 60 00  mov  %o5, %y
a010dd60:  01 00 00 00  nop
a010dd64:  01 00 00 00  nop
a010dd68:  01 00 00 00  nop
a010dd6c:  ba 7f 40 1c  sdiv  %i5, %i4, %i5
a010dd70:  81 80 00 00  mov  %g0, %y
a010dd74:  01 00 00 00  nop
a010dd78:  01 00 00 00  nop
a010dd7c:  01 00 00 00  nop
a010dd80:  b8 70 40 1d  udiv  %g1, %i5, %i4
a010dd84:  b6 5f 00 1d  smul  %i4, %i5, %i3
a010dd88:  80 a0 40 1b  cmp  %g1, %i3
a010dd8c:  22 80 00 05  be,a   0xa010dda0
a010dd90:  bb 2a a0 10  sll  %o2, 0x10, %i5
a010dd94:  82 07 20 01  add  %i4, 1, %g1
a010dd98:  b6 58 40 1d  smul  %g1, %i5, %i3
a010dd9c:  bb 2a a0 10  sll  %o2, 0x10, %i5
a010dda0:  83 37 60 10  srl  %i5, 0x10, %g1
a010dda4:  b8 58 40 1b  smul  %g1, %i3, %i4
a010dda8:  ba 5f 00 1a  smul  %i4, %i2, %i5
a010ddac:  80 a6 20 00  cmp  %i0, 0
a010ddb0:  12 80 00 16  bne  0xa010de08
a010ddb4:  b7 37 60 07  srl  %i5, 7, %i3
a010ddb8:  80 a6 60 00  cmp  %i1, 0
a010ddbc:  22 80 00 1e  be,a   0xa010de34
a010ddc0:  03 34 00 c8  sethi  %hi(0xd0032000), %g1
a010ddc4:  03 34 00 e8  sethi  %hi(0xd003a000), %g1
a010ddc8:  f8 03 e0 08  ld  [ %o7 + 8 ], %i4
a010ddcc:  b0 10 62 80  or  %g1, 0x280, %i0
a010ddd0:  f8 26 00 00  st  %i4, [ %i0 ]
a010ddd4:  10 80 00 1d  b  0xa010de48
a010ddd8:  82 10 60 e8  or  %g1, 0xe8, %g1
a010dddc:  39 00 06 6b  sethi  %hi(0x19ac00), %i4
a010dde0:  83 2e 20 02  sll  %i0, 2, %g1
a010dde4:  ba 17 22 bc  or  %i4, 0x2bc, %i5
a010dde8:  f6 07 40 01  ld  [ %i5 + %g1 ], %i3
a010ddec:  da 26 e0 04  st  %o5, [ %i3 + 4 ]
a010ddf0:  d8 26 e0 18  st  %o4, [ %i3 + 0x18 ]
a010ddf4:  10 bf ff c9  b  0xa010dd18
a010ddf8:  83 2e a0 10  sll  %i2, 0x10, %g1
a010ddfc:  fa 23 e0 08  st  %i5, [ %o7 + 8 ]
a010de00:  10 bf ff b9  b  0xa010dce4
a010de04:  f4 33 e0 12  sth  %i2, [ %o7 + 0x12 ]
a010de08:  80 a6 60 00  cmp  %i1, 0
a010de0c:  22 80 00 08  be,a   0xa010de2c
a010de10:  03 34 00 c8  sethi  %hi(0xd0032000), %g1
a010de14:  03 34 00 e8  sethi  %hi(0xd003a000), %g1
a010de18:  f8 03 e0 08  ld  [ %o7 + 8 ], %i4
a010de1c:  b2 10 62 84  or  %g1, 0x284, %i1
a010de20:  f8 26 40 00  st  %i4, [ %i1 ]
a010de24:  10 80 00 09  b  0xa010de48
a010de28:  82 10 60 ec  or  %g1, 0xec, %g1
a010de2c:  10 bf ff fc  b  0xa010de1c
a010de30:  f8 03 e0 04  ld  [ %o7 + 4 ], %i4
a010de34:  10 bf ff e6  b  0xa010ddcc
a010de38:  f8 03 e0 04  ld  [ %o7 + 4 ], %i4
a010de3c:  37 2a 00 b6  sethi  %hi(0xa802d800), %i3
a010de40:  10 bf ff 9a  b  0xa010dca8
a010de44:  9e 16 e0 04  or  %i3, 4, %o7	! 0xa802d804
a010de48:  f6 20 40 00  st  %i3, [ %g1 ]
a010de4c:  81 c7 e0 08  ret
a010de50:  81 e8 00 00  restore
