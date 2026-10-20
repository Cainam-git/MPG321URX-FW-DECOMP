# leon2s FUN_a006c9c0 0xa006c9c0-0xa006cb98 (472 bytes)
a006c9c0:  9d e3 bf 98  save  %sp, -104, %sp
a006c9c4:  b5 2e a0 10  sll  %i2, 0x10, %i2
a006c9c8:  b5 36 a0 10  srl  %i2, 0x10, %i2
a006c9cc:  9a 10 00 18  mov  %i0, %o5
a006c9d0:  9e 10 00 19  mov  %i1, %o7
a006c9d4:  80 a6 a0 00  cmp  %i2, 0
a006c9d8:  02 80 00 6e  be  0xa006cb90
a006c9dc:  96 10 20 00  clr  %o3
a006c9e0:  31 33 c0 47  sethi  %hi(0xcf011c00), %i0
a006c9e4:  94 10 00 1a  mov  %i2, %o2
a006c9e8:  a0 10 20 80  mov  0x80, %l0
a006c9ec:  90 16 23 90  or  %i0, 0x390, %o0
a006c9f0:  92 10 00 18  mov  %i0, %o1
a006c9f4:  82 16 23 a0  or  %i0, 0x3a0, %g1
a006c9f8:  de 20 40 00  st  %o7, [ %g1 ]
a006c9fc:  ba 16 23 a4  or  %i0, 0x3a4, %i5
a006ca00:  83 33 e0 08  srl  %o7, 8, %g1
a006ca04:  c2 27 40 00  st  %g1, [ %i5 ]
a006ca08:  ba 16 23 a8  or  %i0, 0x3a8, %i5
a006ca0c:  83 33 e0 10  srl  %o7, 0x10, %g1
a006ca10:  c2 27 40 00  st  %g1, [ %i5 ]
a006ca14:  83 33 e0 18  srl  %o7, 0x18, %g1
a006ca18:  ba 16 23 ac  or  %i0, 0x3ac, %i5
a006ca1c:  c2 27 40 00  st  %g1, [ %i5 ]
a006ca20:  82 16 23 84  or  %i0, 0x384, %g1
a006ca24:  e0 20 40 00  st  %l0, [ %g1 ]
a006ca28:  82 16 23 8c  or  %i0, 0x38c, %g1
a006ca2c:  e0 20 40 00  st  %l0, [ %g1 ]
a006ca30:  c2 02 00 00  ld  [ %o0 ], %g1
a006ca34:  80 a0 60 80  cmp  %g1, 0x80
a006ca38:  b4 10 3f ff  mov  -1, %i2
a006ca3c:  02 80 00 09  be  0xa006ca60
a006ca40:  ba 06 bf ff  add  %i2, -1, %i5
a006ca44:  83 2f 60 10  sll  %i5, 0x10, %g1
a006ca48:  80 a0 60 00  cmp  %g1, 0
a006ca4c:  02 80 00 05  be  0xa006ca60
a006ca50:  b4 10 00 1d  mov  %i5, %i2
a006ca54:  c2 02 00 00  ld  [ %o0 ], %g1
a006ca58:  10 bf ff f9  b  0xa006ca3c
a006ca5c:  80 a0 60 80  cmp  %g1, 0x80
a006ca60:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a006ca64:  c2 08 63 e0  ldub  [ %g1 + 0x3e0 ], %g1	! 0xa80787e0
a006ca68:  80 a0 60 01  cmp  %g1, 1
a006ca6c:  12 80 00 23  bne  0xa006caf8
a006ca70:  83 2a e0 10  sll  %o3, 0x10, %g1
a006ca74:  83 30 60 10  srl  %g1, 0x10, %g1
a006ca78:  bb 28 60 13  sll  %g1, 0x13, %i5
a006ca7c:  83 28 60 03  sll  %g1, 3, %g1
a006ca80:  bb 37 60 10  srl  %i5, 0x10, %i5
a006ca84:  b8 00 60 08  add  %g1, 8, %i4
a006ca88:  80 a7 40 1c  cmp  %i5, %i4
a006ca8c:  16 80 00 3a  bge  0xa006cb74
a006ca90:  b4 10 00 01  mov  %g1, %i2
a006ca94:  98 10 00 1c  mov  %i4, %o4
a006ca98:  b2 12 63 94  or  %o1, 0x394, %i1
a006ca9c:  b7 2e a0 10  sll  %i2, 0x10, %i3
a006caa0:  fa 06 40 00  ld  [ %i1 ], %i5
a006caa4:  b7 36 e0 0e  srl  %i3, 0xe, %i3
a006caa8:  fa 23 40 1b  st  %i5, [ %o5 + %i3 ]
a006caac:  c2 06 40 00  ld  [ %i1 ], %g1
a006cab0:  83 28 60 08  sll  %g1, 8, %g1
a006cab4:  ba 17 40 01  or  %i5, %g1, %i5
a006cab8:  fa 23 40 1b  st  %i5, [ %o5 + %i3 ]
a006cabc:  c2 06 40 00  ld  [ %i1 ], %g1
a006cac0:  83 28 60 10  sll  %g1, 0x10, %g1
a006cac4:  ba 17 40 01  or  %i5, %g1, %i5
a006cac8:  fa 23 40 1b  st  %i5, [ %o5 + %i3 ]
a006cacc:  c2 06 40 00  ld  [ %i1 ], %g1
a006cad0:  b4 06 a0 01  inc  %i2
a006cad4:  83 28 60 18  sll  %g1, 0x18, %g1
a006cad8:  b9 2e a0 10  sll  %i2, 0x10, %i4
a006cadc:  ba 17 40 01  or  %i5, %g1, %i5
a006cae0:  b9 37 20 10  srl  %i4, 0x10, %i4
a006cae4:  80 a7 00 0c  cmp  %i4, %o4
a006cae8:  06 bf ff ed  bl  0xa006ca9c
a006caec:  fa 23 40 1b  st  %i5, [ %o5 + %i3 ]
a006caf0:  10 80 00 22  b  0xa006cb78
a006caf4:  ba 02 e0 01  add  %o3, 1, %i5
a006caf8:  83 30 60 10  srl  %g1, 0x10, %g1
a006cafc:  bb 28 60 13  sll  %g1, 0x13, %i5
a006cb00:  83 28 60 03  sll  %g1, 3, %g1
a006cb04:  bb 37 60 10  srl  %i5, 0x10, %i5
a006cb08:  b8 00 60 08  add  %g1, 8, %i4
a006cb0c:  80 a7 40 1c  cmp  %i5, %i4
a006cb10:  16 80 00 19  bge  0xa006cb74
a006cb14:  b4 10 00 01  mov  %g1, %i2
a006cb18:  98 10 00 1c  mov  %i4, %o4
a006cb1c:  b2 12 63 94  or  %o1, 0x394, %i1
a006cb20:  fa 06 40 00  ld  [ %i1 ], %i5
a006cb24:  b7 2e a0 10  sll  %i2, 0x10, %i3
a006cb28:  b7 36 e0 0e  srl  %i3, 0xe, %i3
a006cb2c:  bb 2f 60 18  sll  %i5, 0x18, %i5
a006cb30:  fa 23 40 1b  st  %i5, [ %o5 + %i3 ]
a006cb34:  c2 06 40 00  ld  [ %i1 ], %g1
a006cb38:  83 28 60 10  sll  %g1, 0x10, %g1
a006cb3c:  ba 17 40 01  or  %i5, %g1, %i5
a006cb40:  fa 23 40 1b  st  %i5, [ %o5 + %i3 ]
a006cb44:  c2 06 40 00  ld  [ %i1 ], %g1
a006cb48:  83 28 60 08  sll  %g1, 8, %g1
a006cb4c:  ba 17 40 01  or  %i5, %g1, %i5
a006cb50:  fa 23 40 1b  st  %i5, [ %o5 + %i3 ]
a006cb54:  b4 06 a0 01  inc  %i2
a006cb58:  c2 06 40 00  ld  [ %i1 ], %g1
a006cb5c:  b9 2e a0 10  sll  %i2, 0x10, %i4
a006cb60:  ba 17 40 01  or  %i5, %g1, %i5
a006cb64:  b9 37 20 10  srl  %i4, 0x10, %i4
a006cb68:  80 a7 00 0c  cmp  %i4, %o4
a006cb6c:  06 bf ff ed  bl  0xa006cb20
a006cb70:  fa 23 40 1b  st  %i5, [ %o5 + %i3 ]
a006cb74:  ba 02 e0 01  add  %o3, 1, %i5
a006cb78:  83 2f 60 10  sll  %i5, 0x10, %g1
a006cb7c:  83 30 60 10  srl  %g1, 0x10, %g1
a006cb80:  80 a0 40 0a  cmp  %g1, %o2
a006cb84:  9e 03 e0 01  inc  %o7
a006cb88:  0a bf ff 9b  bcs  0xa006c9f4
a006cb8c:  96 10 00 1d  mov  %i5, %o3
a006cb90:  81 c7 e0 08  ret
a006cb94:  81 e8 00 00  restore
