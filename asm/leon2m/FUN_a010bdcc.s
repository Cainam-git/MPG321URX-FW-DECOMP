# leon2m FUN_a010bdcc 0xa010bdcc-0xa010bea4 (216 bytes)
a010bdcc:  9d e3 bf 98  save  %sp, -104, %sp
a010bdd0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a010bdd4:  9e 10 00 1b  mov  %i3, %o7
a010bdd8:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010bddc:  80 a6 20 01  cmp  %i0, 1
a010bde0:  02 80 00 06  be  0xa010bdf8
a010bde4:  b6 10 63 c4  or  %g1, 0x3c4, %i3
a010bde8:  39 2a 00 b5  sethi  %hi(0xa802d400), %i4
a010bdec:  80 a6 20 02  cmp  %i0, 2
a010bdf0:  02 80 00 26  be  0xa010be88
a010bdf4:  b6 17 23 44  or  %i4, 0x344, %i3
a010bdf8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a010bdfc:  80 a6 60 00  cmp  %i1, 0
a010be00:  32 80 00 13  bne,a   0xa010be4c
a010be04:  f8 0e e0 3e  ldub  [ %i3 + 0x3e ], %i4
a010be08:  83 2e a0 10  sll  %i2, 0x10, %g1
a010be0c:  f4 36 e0 18  sth  %i2, [ %i3 + 0x18 ]
a010be10:  b5 30 60 10  srl  %g1, 0x10, %i2
a010be14:  83 2b e0 10  sll  %o7, 0x10, %g1
a010be18:  bb 2e a0 10  sll  %i2, 0x10, %i5
a010be1c:  b9 30 60 10  srl  %g1, 0x10, %i4
a010be20:  de 36 e0 20  sth  %o7, [ %i3 + 0x20 ]
a010be24:  b4 17 40 1c  or  %i5, %i4, %i2
a010be28:  37 00 06 6b  sethi  %hi(0x19ac00), %i3
a010be2c:  83 2e 20 02  sll  %i0, 2, %g1
a010be30:  80 a6 60 00  cmp  %i1, 0
a010be34:  02 80 00 18  be  0xa010be94
a010be38:  ba 16 e2 d8  or  %i3, 0x2d8, %i5
a010be3c:  83 2e 20 02  sll  %i0, 2, %g1
a010be40:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010be44:  10 80 00 14  b  0xa010be94
a010be48:  ba 16 22 cc  or  %i0, 0x2cc, %i5	! 0x19aecc
a010be4c:  80 8f 20 01  btst  1, %i4
a010be50:  02 80 00 08  be  0xa010be70
a010be54:  f4 36 e0 1a  sth  %i2, [ %i3 + 0x1a ]
a010be58:  bb 2e a0 10  sll  %i2, 0x10, %i5
a010be5c:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a010be60:  83 37 60 10  srl  %i5, 0x10, %g1
a010be64:  f8 0e a3 00  ldub  [ %i2 + 0x300 ], %i4
a010be68:  10 bf ff eb  b  0xa010be14
a010be6c:  b4 20 40 1c  sub  %g1, %i4, %i2
a010be70:  bb 2e a0 10  sll  %i2, 0x10, %i5
a010be74:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a010be78:  83 37 60 10  srl  %i5, 0x10, %g1
a010be7c:  f8 0e a3 00  ldub  [ %i2 + 0x300 ], %i4
a010be80:  10 bf ff e5  b  0xa010be14
a010be84:  b4 00 40 1c  add  %g1, %i4, %i2
a010be88:  3b 2a 00 b5  sethi  %hi(0xa802d400), %i5
a010be8c:  10 bf ff db  b  0xa010bdf8
a010be90:  b6 17 63 84  or  %i5, 0x384, %i3	! 0xa802d784
a010be94:  f2 07 40 01  ld  [ %i5 + %g1 ], %i1
a010be98:  f4 26 60 14  st  %i2, [ %i1 + 0x14 ]
a010be9c:  81 c7 e0 08  ret
a010bea0:  81 e8 00 00  restore
