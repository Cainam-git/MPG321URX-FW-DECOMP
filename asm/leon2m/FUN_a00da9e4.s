# leon2m FUN_a00da9e4 0xa00da9e4-0xa00daa7c (152 bytes)
a00da9e4:  9d e3 bf 98  save  %sp, -104, %sp
a00da9e8:  33 2a 00 b3  sethi  %hi(0xa802cc00), %i1
a00da9ec:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00da9f0:  82 0e 20 ff  and  %i0, 0xff, %g1
a00da9f4:  98 16 63 f4  or  %i1, 0x3f4, %o4
a00da9f8:  b8 10 00 18  mov  %i0, %i4
a00da9fc:  b6 13 62 68  or  %o5, 0x268, %i3
a00daa00:  9e 10 20 30  mov  0x30, %o7
a00daa04:  b4 10 00 1b  mov  %i3, %i2
a00daa08:  b0 10 20 02  mov  2, %i0
a00daa0c:  80 a0 60 0a  cmp  %g1, 0xa
a00daa10:  08 80 00 03  bleu  0xa00daa1c
a00daa14:  b2 10 20 0b  mov  0xb, %i1
a00daa18:  b8 10 20 01  mov  1, %i4
a00daa1c:  fa 13 20 14  lduh  [ %o4 + 0x14 ], %i5
a00daa20:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00daa24:  ba 17 40 01  or  %i5, %g1, %i5
a00daa28:  82 10 20 35  mov  0x35, %g1
a00daa2c:  c2 2b 62 68  stb  %g1, [ %o5 + 0x268 ]
a00daa30:  fa 33 20 14  sth  %i5, [ %o4 + 0x14 ]
a00daa34:  b8 07 20 30  add  %i4, 0x30, %i4
a00daa38:  ba 10 20 62  mov  0x62, %i5
a00daa3c:  fa 2e e0 01  stb  %i5, [ %i3 + 1 ]
a00daa40:  f8 2e e0 09  stb  %i4, [ %i3 + 9 ]
a00daa44:  82 10 20 3b  mov  0x3b, %g1
a00daa48:  ba 10 20 33  mov  0x33, %i5
a00daa4c:  b8 10 20 0d  mov  0xd, %i4
a00daa50:  c2 2e e0 04  stb  %g1, [ %i3 + 4 ]
a00daa54:  fa 2e e0 05  stb  %i5, [ %i3 + 5 ]
a00daa58:  de 2e e0 08  stb  %o7, [ %i3 + 8 ]
a00daa5c:  f8 2e e0 0a  stb  %i4, [ %i3 + 0xa ]
a00daa60:  de 2e e0 02  stb  %o7, [ %i3 + 2 ]
a00daa64:  de 2e e0 03  stb  %o7, [ %i3 + 3 ]
a00daa68:  de 2e e0 06  stb  %o7, [ %i3 + 6 ]
a00daa6c:  de 2e e0 07  stb  %o7, [ %i3 + 7 ]
a00daa70:  40 01 b7 5e  call  0xa01487e8
a00daa74:  81 e8 00 00  restore
a00daa78:  01 00 00 00  nop
