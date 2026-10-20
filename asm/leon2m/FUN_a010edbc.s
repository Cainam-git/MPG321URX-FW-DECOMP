# leon2m FUN_a010edbc 0xa010edbc-0xa010ef64 (424 bytes)
a010edbc:  9d e3 bf 98  save  %sp, -104, %sp
a010edc0:  b6 0e 20 ff  and  %i0, 0xff, %i3
a010edc4:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010edc8:  80 a6 e0 01  cmp  %i3, 1
a010edcc:  02 80 00 06  be  0xa010ede4
a010edd0:  ba 10 63 c4  or  %g1, 0x3c4, %i5
a010edd4:  33 2a 00 b5  sethi  %hi(0xa802d400), %i1
a010edd8:  80 a6 e0 02  cmp  %i3, 2
a010eddc:  02 80 00 5d  be  0xa010ef50
a010ede0:  ba 16 63 44  or  %i1, 0x344, %i5
a010ede4:  f8 0f 60 3e  ldub  [ %i5 + 0x3e ], %i4
a010ede8:  b4 17 20 01  or  %i4, 1, %i2
a010edec:  f4 2f 60 3e  stb  %i2, [ %i5 + 0x3e ]
a010edf0:  33 2a 00 b5  sethi  %hi(0xa802d400), %i1
a010edf4:  c2 06 62 a4  ld  [ %i1 + 0x2a4 ], %g1	! 0xa802d6a4
a010edf8:  fa 10 60 08  lduh  [ %g1 + 8 ], %i5
a010edfc:  b9 37 60 01  srl  %i5, 1, %i4
a010ee00:  80 a6 e0 02  cmp  %i3, 2
a010ee04:  08 80 00 2f  bleu  0xa010eec0
a010ee08:  b5 2f 20 10  sll  %i4, 0x10, %i2
a010ee0c:  1f 00 06 6b  sethi  %hi(0x19ac00), %o7
a010ee10:  b8 10 20 00  clr  %i4
a010ee14:  b2 13 e2 d8  or  %o7, 0x2d8, %i1
a010ee18:  83 2f 20 02  sll  %i4, 2, %g1
a010ee1c:  fa 06 40 01  ld  [ %i1 + %g1 ], %i5
a010ee20:  b8 07 20 01  inc  %i4
a010ee24:  f4 27 60 0c  st  %i2, [ %i5 + 0xc ]
a010ee28:  80 a7 20 02  cmp  %i4, 2
a010ee2c:  28 bf ff fc  bleu,a   0xa010ee1c
a010ee30:  83 2f 20 02  sll  %i4, 2, %g1
a010ee34:  80 a6 e0 02  cmp  %i3, 2
a010ee38:  18 80 00 2a  bgu  0xa010eee0
a010ee3c:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010ee40:  ba 13 62 cc  or  %o5, 0x2cc, %i5	! 0x19aecc
a010ee44:  b9 2e e0 02  sll  %i3, 2, %i4
a010ee48:  f2 07 40 1c  ld  [ %i5 + %i4 ], %i1
a010ee4c:  f4 26 60 0c  st  %i2, [ %i1 + 0xc ]
a010ee50:  80 a6 e0 02  cmp  %i3, 2
a010ee54:  38 80 00 02  bgu,a   0xa010ee5c
a010ee58:  b0 10 20 00  clr  %i0
a010ee5c:  ba 0e 20 ff  and  %i0, 0xff, %i5
a010ee60:  b4 13 e2 d8  or  %o7, 0x2d8, %i2
a010ee64:  b9 2f 60 02  sll  %i5, 2, %i4
a010ee68:  f0 06 80 1c  ld  [ %i2 + %i4 ], %i0
a010ee6c:  f2 06 20 04  ld  [ %i0 + 4 ], %i1
a010ee70:  03 00 00 10  sethi  %hi(0x4000), %g1
a010ee74:  80 a6 e0 02  cmp  %i3, 2
a010ee78:  08 80 00 25  bleu  0xa010ef0c
a010ee7c:  b0 16 40 01  or  %i1, %g1, %i0
a010ee80:  b8 10 20 00  clr  %i4
a010ee84:  83 2f 20 02  sll  %i4, 2, %g1
a010ee88:  f2 06 80 01  ld  [ %i2 + %g1 ], %i1
a010ee8c:  b8 07 20 01  inc  %i4
a010ee90:  f0 26 60 04  st  %i0, [ %i1 + 4 ]
a010ee94:  80 a7 20 02  cmp  %i4, 2
a010ee98:  28 bf ff fc  bleu,a   0xa010ee88
a010ee9c:  83 2f 20 02  sll  %i4, 2, %g1
a010eea0:  80 a6 e0 02  cmp  %i3, 2
a010eea4:  38 80 00 21  bgu,a   0xa010ef28
a010eea8:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a010eeac:  ba 13 62 cc  or  %o5, 0x2cc, %i5
a010eeb0:  b9 2e e0 02  sll  %i3, 2, %i4
a010eeb4:  f6 07 40 1c  ld  [ %i5 + %i4 ], %i3
a010eeb8:  f0 26 e0 04  st  %i0, [ %i3 + 4 ]
a010eebc:  30 80 00 28  b,a   0xa010ef5c
a010eec0:  1f 00 06 6b  sethi  %hi(0x19ac00), %o7
a010eec4:  ba 13 e2 d8  or  %o7, 0x2d8, %i5	! 0x19aed8
a010eec8:  b9 2e e0 02  sll  %i3, 2, %i4
a010eecc:  f2 07 40 1c  ld  [ %i5 + %i4 ], %i1
a010eed0:  f4 26 60 0c  st  %i2, [ %i1 + 0xc ]
a010eed4:  80 a6 e0 02  cmp  %i3, 2
a010eed8:  08 bf ff da  bleu  0xa010ee40
a010eedc:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010eee0:  b8 10 20 00  clr  %i4
a010eee4:  b2 13 62 cc  or  %o5, 0x2cc, %i1
a010eee8:  83 2f 20 02  sll  %i4, 2, %g1
a010eeec:  fa 06 40 01  ld  [ %i1 + %g1 ], %i5
a010eef0:  b8 07 20 01  inc  %i4
a010eef4:  f4 27 60 0c  st  %i2, [ %i5 + 0xc ]
a010eef8:  80 a7 20 02  cmp  %i4, 2
a010eefc:  08 bf ff fc  bleu  0xa010eeec
a010ef00:  83 2f 20 02  sll  %i4, 2, %g1
a010ef04:  10 bf ff d4  b  0xa010ee54
a010ef08:  80 a6 e0 02  cmp  %i3, 2
a010ef0c:  bb 2e e0 02  sll  %i3, 2, %i5
a010ef10:  f8 06 80 1d  ld  [ %i2 + %i5 ], %i4
a010ef14:  f0 27 20 04  st  %i0, [ %i4 + 4 ]
a010ef18:  80 a6 e0 02  cmp  %i3, 2
a010ef1c:  08 bf ff e5  bleu  0xa010eeb0
a010ef20:  ba 13 62 cc  or  %o5, 0x2cc, %i5
a010ef24:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a010ef28:  b6 16 a2 cc  or  %i2, 0x2cc, %i3	! 0x19aecc
a010ef2c:  b8 10 20 00  clr  %i4
a010ef30:  83 2f 20 02  sll  %i4, 2, %g1
a010ef34:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010ef38:  b8 07 20 01  inc  %i4
a010ef3c:  f0 26 60 04  st  %i0, [ %i1 + 4 ]
a010ef40:  80 a7 20 02  cmp  %i4, 2
a010ef44:  08 bf ff fc  bleu  0xa010ef34
a010ef48:  83 2f 20 02  sll  %i4, 2, %g1
a010ef4c:  30 80 00 04  b,a   0xa010ef5c
a010ef50:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a010ef54:  10 bf ff a4  b  0xa010ede4
a010ef58:  ba 16 a3 84  or  %i2, 0x384, %i5	! 0xa802d784
a010ef5c:  81 c7 e0 08  ret
a010ef60:  81 e8 00 00  restore
