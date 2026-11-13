# leon2m FUN_a00eef7c 0xa00eef7c-0xa00ef034 (184 bytes)
a00eef7c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00eef80:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00eef84:  80 a3 60 07  cmp  %o5, 7
a00eef88:  18 80 00 29  bgu  0xa00ef02c
a00eef8c:  d0 28 62 79  stb  %o0, [ %g1 + 0x279 ]
a00eef90:  91 2b 60 02  sll  %o5, 2, %o0
a00eef94:  17 00 02 3b  sethi  %hi(0x8ec00), %o3
a00eef98:  9a 12 e3 3c  or  %o3, 0x33c, %o5	! 0x8ef3c
a00eef9c:  d8 03 40 08  ld  [ %o5 + %o0 ], %o4
a00eefa0:  81 c3 00 00  jmp  %o4
a00eefa4:  01 00 00 00  nop
a00eefa8:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a00eefac:  98 13 63 50  or  %o5, 0x350, %o4	! 0xcf014750
a00eefb0:  d0 03 00 00  ld  [ %o4 ], %o0
a00eefb4:  9a 0a 3f fb  and  %o0, -5, %o5
a00eefb8:  96 10 20 03  mov  3, %o3
a00eefbc:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00eefc0:  d6 2a 22 78  stb  %o3, [ %o0 + 0x278 ]	! 0xa8026a78
a00eefc4:  da 23 00 00  st  %o5, [ %o4 ]
a00eefc8:  30 80 00 19  b,a   0xa00ef02c
a00eefcc:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a00eefd0:  98 10 63 50  or  %g1, 0x350, %o4	! 0xcf014750
a00eefd4:  d6 03 00 00  ld  [ %o4 ], %o3
a00eefd8:  10 bf ff f8  b  0xa00eefb8
a00eefdc:  9a 12 e0 04  or  %o3, 4, %o5
a00eefe0:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00eefe4:  10 80 00 12  b  0xa00ef02c
a00eefe8:  c0 28 62 78  clrb  [ %g1 + 0x278 ]	! 0xa8026a78
a00eefec:  90 10 20 01  mov  1, %o0
a00eeff0:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00eeff4:  10 80 00 0e  b  0xa00ef02c
a00eeff8:  d0 2b 22 78  stb  %o0, [ %o4 + 0x278 ]	! 0xa8026a78
a00eeffc:  17 33 c0 51  sethi  %hi(0xcf014400), %o3
a00ef000:  98 12 e3 50  or  %o3, 0x350, %o4	! 0xcf014750
a00ef004:  da 03 00 00  ld  [ %o4 ], %o5
a00ef008:  9a 0b 7f fe  and  %o5, -2, %o5
a00ef00c:  10 bf ff ec  b  0xa00eefbc
a00ef010:  96 10 20 02  mov  2, %o3
a00ef014:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a00ef018:  98 13 23 50  or  %o4, 0x350, %o4	! 0xcf014750
a00ef01c:  c2 03 00 00  ld  [ %o4 ], %g1
a00ef020:  9a 10 60 01  or  %g1, 1, %o5
a00ef024:  10 bf ff e6  b  0xa00eefbc
a00ef028:  96 10 20 02  mov  2, %o3
a00ef02c:  81 c3 e0 08  retl
a00ef030:  01 00 00 00  nop
