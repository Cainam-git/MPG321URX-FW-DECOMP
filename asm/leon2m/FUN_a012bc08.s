# leon2m FUN_a012bc08 0xa012bc08-0xa012be4c (580 bytes)
a012bc08:  9d e3 bf 38  save  %sp, -200, %sp
a012bc0c:  98 10 20 00  clr  %o4
a012bc10:  9a 10 20 00  clr  %o5
a012bc14:  d8 3f bf d0  std  %o4, [ %fp + -48 ]
a012bc18:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a012bc1c:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a012bc20:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a012bc24:  d8 3f bf c0  std  %o4, [ %fp + -64 ]
a012bc28:  d8 3f bf c8  std  %o4, [ %fp + -56 ]
a012bc2c:  7f ff e1 74  call  0xa01241fc
a012bc30:  c0 27 bf d8  clr  [ %fp + -40 ]
a012bc34:  a0 10 00 08  mov  %o0, %l0
a012bc38:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012bc3c:  7f ff 46 f9  call  0xa00fd820
a012bc40:  90 10 00 18  mov  %i0, %o0
a012bc44:  a2 0e 60 ff  and  %i1, 0xff, %l1
a012bc48:  a6 10 00 08  mov  %o0, %l3
a012bc4c:  80 a4 60 00  cmp  %l1, 0
a012bc50:  02 80 00 13  be  0xa012bc9c
a012bc54:  a4 10 20 01  mov  1, %l2
a012bc58:  d0 0c 20 06  ldub  [ %l0 + 6 ], %o0
a012bc5c:  82 0a 20 ff  and  %o0, 0xff, %g1
a012bc60:  80 a0 60 20  cmp  %g1, 0x20
a012bc64:  02 80 00 08  be  0xa012bc84
a012bc68:  80 a0 60 21  cmp  %g1, 0x21
a012bc6c:  02 80 00 74  be  0xa012be3c
a012bc70:  80 a0 60 22  cmp  %g1, 0x22
a012bc74:  02 80 00 6e  be  0xa012be2c
a012bc78:  80 a0 60 23  cmp  %g1, 0x23
a012bc7c:  22 80 00 02  be,a   0xa012bc84
a012bc80:  a4 10 20 08  mov  8, %l2
a012bc84:  90 0a 20 ff  and  %o0, 0xff, %o0
a012bc88:  80 a2 20 24  cmp  %o0, 0x24
a012bc8c:  02 80 00 6a  be  0xa012be34
a012bc90:  80 a2 20 25  cmp  %o0, 0x25
a012bc94:  22 80 00 02  be,a   0xa012bc9c
a012bc98:  a4 10 20 02  mov  2, %l2
a012bc9c:  90 10 00 18  mov  %i0, %o0
a012bca0:  7f ff ff 42  call  0xa012b9a8
a012bca4:  92 07 bf e0  add  %fp, -32, %o1
a012bca8:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a012bcac:  f0 08 63 7f  ldub  [ %g1 + 0x37f ], %i0	! 0xa802e37f
a012bcb0:  80 8e a0 ff  btst  0xff, %i2
a012bcb4:  02 80 00 4c  be  0xa012bde4
a012bcb8:  f0 2f bf f5  stb  %i0, [ %fp + -11 ]
a012bcbc:  d4 17 bf e4  lduh  [ %fp + -28 ], %o2
a012bcc0:  9a 0c a0 ff  and  %l2, 0xff, %o5
a012bcc4:  b3 2c 60 03  sll  %l1, 3, %i1
a012bcc8:  d6 17 bf e0  lduh  [ %fp + -32 ], %o3
a012bccc:  e0 17 bf e8  lduh  [ %fp + -24 ], %l0
a012bcd0:  d2 17 bf ea  lduh  [ %fp + -22 ], %o1
a012bcd4:  83 3a a0 1f  sra  %o2, 0x1f, %g1
a012bcd8:  81 80 60 00  mov  %g1, %y
a012bcdc:  01 00 00 00  nop
a012bce0:  01 00 00 00  nop
a012bce4:  01 00 00 00  nop
a012bce8:  a4 7a 80 0d  sdiv  %o2, %o5, %l2
a012bcec:  90 06 40 11  add  %i1, %l1, %o0
a012bcf0:  1f 2a 00 b6  sethi  %hi(0xa802d800), %o7
a012bcf4:  83 3a e0 1f  sra  %o3, 0x1f, %g1
a012bcf8:  81 80 60 00  mov  %g1, %y
a012bcfc:  01 00 00 00  nop
a012bd00:  01 00 00 00  nop
a012bd04:  01 00 00 00  nop
a012bd08:  98 7a c0 0d  sdiv  %o3, %o5, %o4
a012bd0c:  83 3c 20 1f  sra  %l0, 0x1f, %g1
a012bd10:  81 80 60 00  mov  %g1, %y
a012bd14:  01 00 00 00  nop
a012bd18:  01 00 00 00  nop
a012bd1c:  01 00 00 00  nop
a012bd20:  94 7c 00 0d  sdiv  %l0, %o5, %o2
a012bd24:  b4 13 e0 dc  or  %o7, 0xdc, %i2
a012bd28:  b3 2a 20 02  sll  %o0, 2, %i1
a012bd2c:  83 3a 60 1f  sra  %o1, 0x1f, %g1
a012bd30:  81 80 60 00  mov  %g1, %y
a012bd34:  01 00 00 00  nop
a012bd38:  01 00 00 00  nop
a012bd3c:  01 00 00 00  nop
a012bd40:  92 7a 40 0d  sdiv  %o1, %o5, %o1
a012bd44:  a0 06 40 1a  add  %i1, %i2, %l0
a012bd48:  c2 17 bf e2  lduh  [ %fp + -30 ], %g1
a012bd4c:  d8 34 20 04  sth  %o4, [ %l0 + 4 ]
a012bd50:  c2 34 20 06  sth  %g1, [ %l0 + 6 ]
a012bd54:  d6 17 bf e6  lduh  [ %fp + -26 ], %o3
a012bd58:  da 17 bf ec  lduh  [ %fp + -20 ], %o5
a012bd5c:  d8 17 bf ee  lduh  [ %fp + -18 ], %o4
a012bd60:  c2 0f bf f4  ldub  [ %fp + -12 ], %g1
a012bd64:  e4 34 20 08  sth  %l2, [ %l0 + 8 ]
a012bd68:  d2 34 20 0e  sth  %o1, [ %l0 + 0xe ]
a012bd6c:  da 34 20 10  sth  %o5, [ %l0 + 0x10 ]
a012bd70:  d8 34 20 12  sth  %o4, [ %l0 + 0x12 ]
a012bd74:  d6 34 20 0a  sth  %o3, [ %l0 + 0xa ]
a012bd78:  d4 34 20 0c  sth  %o2, [ %l0 + 0xc ]
a012bd7c:  c2 2c 20 18  stb  %g1, [ %l0 + 0x18 ]
a012bd80:  f0 2c 20 19  stb  %i0, [ %l0 + 0x19 ]
a012bd84:  e6 2c 20 02  stb  %l3, [ %l0 + 2 ]
a012bd88:  e6 2c 20 01  stb  %l3, [ %l0 + 1 ]
a012bd8c:  d2 04 20 10  ld  [ %l0 + 0x10 ], %o1
a012bd90:  e6 06 80 19  ld  [ %i2 + %i1 ], %l3
a012bd94:  e4 04 20 04  ld  [ %l0 + 4 ], %l2
a012bd98:  d6 04 20 08  ld  [ %l0 + 8 ], %o3
a012bd9c:  d4 04 20 0c  ld  [ %l0 + 0xc ], %o2
a012bda0:  de 04 20 14  ld  [ %l0 + 0x14 ], %o7
a012bda4:  d2 27 bf a8  st  %o1, [ %fp + -88 ]
a012bda8:  e6 27 bf 98  st  %l3, [ %fp + -104 ]
a012bdac:  e4 27 bf 9c  st  %l2, [ %fp + -100 ]
a012bdb0:  d6 27 bf a0  st  %o3, [ %fp + -96 ]
a012bdb4:  d4 27 bf a4  st  %o2, [ %fp + -92 ]
a012bdb8:  de 27 bf ac  st  %o7, [ %fp + -84 ]
a012bdbc:  d0 04 20 18  ld  [ %l0 + 0x18 ], %o0
a012bdc0:  d0 27 bf b0  st  %o0, [ %fp + -80 ]
a012bdc4:  d8 04 20 20  ld  [ %l0 + 0x20 ], %o4
a012bdc8:  da 04 20 1c  ld  [ %l0 + 0x1c ], %o5
a012bdcc:  da 27 bf b4  st  %o5, [ %fp + -76 ]
a012bdd0:  d8 27 bf b8  st  %o4, [ %fp + -72 ]
a012bdd4:  90 10 00 11  mov  %l1, %o0
a012bdd8:  40 00 31 55  call  0xa013832c
a012bddc:  92 07 bf 98  add  %fp, -104, %o1
a012bde0:  30 80 00 19  b,a   0xa012be44
a012bde4:  a1 2c 60 03  sll  %l1, 3, %l0
a012bde8:  82 04 00 11  add  %l0, %l1, %g1
a012bdec:  19 2a 00 b6  sethi  %hi(0xa802d800), %o4
a012bdf0:  b5 28 60 02  sll  %g1, 2, %i2
a012bdf4:  a4 13 20 dc  or  %o4, 0xdc, %l2
a012bdf8:  a2 06 80 12  add  %i2, %l2, %l1
a012bdfc:  f0 2c 60 19  stb  %i0, [ %l1 + 0x19 ]
a012be00:  e6 0f bf f4  ldub  [ %fp + -12 ], %l3
a012be04:  f2 2f bf c0  stb  %i1, [ %fp + -64 ]
a012be08:  e6 2f bf c1  stb  %l3, [ %fp + -63 ]
a012be0c:  f0 2f bf c2  stb  %i0, [ %fp + -62 ]
a012be10:  e6 2c 60 18  stb  %l3, [ %l1 + 0x18 ]
a012be14:  90 10 20 51  mov  0x51, %o0
a012be18:  92 10 20 1c  mov  0x1c, %o1
a012be1c:  94 07 bf c0  add  %fp, -64, %o2
a012be20:  40 00 2c af  call  0xa01370dc
a012be24:  96 10 20 00  clr  %o3
a012be28:  30 80 00 07  b,a   0xa012be44
a012be2c:  10 bf ff 96  b  0xa012bc84
a012be30:  a4 10 20 04  mov  4, %l2
a012be34:  10 bf ff 9a  b  0xa012bc9c
a012be38:  a4 10 20 01  mov  1, %l2
a012be3c:  10 bf ff 92  b  0xa012bc84
a012be40:  a4 10 20 02  mov  2, %l2
a012be44:  81 c7 e0 08  ret
a012be48:  81 e8 00 00  restore
