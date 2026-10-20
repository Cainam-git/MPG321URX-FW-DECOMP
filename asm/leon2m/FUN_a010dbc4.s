# leon2m FUN_a010dbc4 0xa010dbc4-0xa010dc8c (200 bytes)
a010dbc4:  9d e3 bf 98  save  %sp, -104, %sp
a010dbc8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a010dbcc:  9e 10 00 1b  mov  %i3, %o7
a010dbd0:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010dbd4:  80 a6 20 01  cmp  %i0, 1
a010dbd8:  02 80 00 26  be  0xa010dc70
a010dbdc:  b6 10 63 04  or  %g1, 0x304, %i3
a010dbe0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a010dbe4:  80 a6 60 00  cmp  %i1, 0
a010dbe8:  32 80 00 13  bne,a   0xa010dc34
a010dbec:  c2 0e e0 3e  ldub  [ %i3 + 0x3e ], %g1
a010dbf0:  bb 2e a0 10  sll  %i2, 0x10, %i5
a010dbf4:  f4 36 e0 18  sth  %i2, [ %i3 + 0x18 ]
a010dbf8:  b5 37 60 10  srl  %i5, 0x10, %i2
a010dbfc:  83 2b e0 10  sll  %o7, 0x10, %g1
a010dc00:  bb 2e a0 10  sll  %i2, 0x10, %i5
a010dc04:  b9 30 60 10  srl  %g1, 0x10, %i4
a010dc08:  de 36 e0 20  sth  %o7, [ %i3 + 0x20 ]
a010dc0c:  b4 17 40 1c  or  %i5, %i4, %i2
a010dc10:  37 00 06 6b  sethi  %hi(0x19ac00), %i3
a010dc14:  83 2e 20 02  sll  %i0, 2, %g1
a010dc18:  80 a6 60 00  cmp  %i1, 0
a010dc1c:  02 80 00 18  be  0xa010dc7c
a010dc20:  ba 16 e2 c4  or  %i3, 0x2c4, %i5
a010dc24:  83 2e 20 02  sll  %i0, 2, %g1
a010dc28:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010dc2c:  10 80 00 14  b  0xa010dc7c
a010dc30:  ba 16 22 bc  or  %i0, 0x2bc, %i5	! 0x19aebc
a010dc34:  80 88 60 01  btst  1, %g1
a010dc38:  02 80 00 08  be  0xa010dc58
a010dc3c:  f4 36 e0 1a  sth  %i2, [ %i3 + 0x1a ]
a010dc40:  bb 2e a0 10  sll  %i2, 0x10, %i5
a010dc44:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a010dc48:  83 37 60 10  srl  %i5, 0x10, %g1
a010dc4c:  f8 0e a3 00  ldub  [ %i2 + 0x300 ], %i4
a010dc50:  10 bf ff eb  b  0xa010dbfc
a010dc54:  b4 20 40 1c  sub  %g1, %i4, %i2
a010dc58:  bb 2e a0 10  sll  %i2, 0x10, %i5
a010dc5c:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a010dc60:  83 37 60 10  srl  %i5, 0x10, %g1
a010dc64:  f8 0e a3 00  ldub  [ %i2 + 0x300 ], %i4
a010dc68:  10 bf ff e5  b  0xa010dbfc
a010dc6c:  b4 00 40 1c  add  %g1, %i4, %i2
a010dc70:  39 2a 00 b6  sethi  %hi(0xa802d800), %i4
a010dc74:  10 bf ff db  b  0xa010dbe0
a010dc78:  b6 17 20 04  or  %i4, 4, %i3	! 0xa802d804
a010dc7c:  f2 07 40 01  ld  [ %i5 + %g1 ], %i1
a010dc80:  f4 26 40 00  st  %i2, [ %i1 ]
a010dc84:  81 c7 e0 08  ret
a010dc88:  81 e8 00 00  restore
