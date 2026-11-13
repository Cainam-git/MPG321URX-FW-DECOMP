# leon2m FUN_a011eadc 0xa011eadc-0xa011f1c8 (1772 bytes)
a011eadc:  9d e3 bf 98  save  %sp, -104, %sp
a011eae0:  31 00 06 8b  sethi  %hi(0x1a2c00), %i0
a011eae4:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011eae8:  98 16 23 c8  or  %i0, 0x3c8, %o4
a011eaec:  9a 17 60 28  or  %i5, 0x28, %o5
a011eaf0:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a011eaf4:  b0 10 63 b0  or  %g1, 0x3b0, %i0	! 0x1a2fb0
a011eaf8:  9e 10 20 00  clr  %o7
a011eafc:  ba 10 20 00  clr  %i5
a011eb00:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011eb04:  c2 03 40 00  ld  [ %o5 ], %g1
a011eb08:  b4 10 60 03  or  %g1, 3, %i2
a011eb0c:  b6 03 e0 12  add  %o7, 0x12, %i3
a011eb10:  f4 23 40 00  st  %i2, [ %o5 ]
a011eb14:  f8 0b 00 1d  ldub  [ %o4 + %i5 ], %i4
a011eb18:  b4 0e e0 ff  and  %i3, 0xff, %i2
a011eb1c:  b6 10 20 00  clr  %i3
a011eb20:  ba 10 20 00  clr  %i5
a011eb24:  ba 07 40 1d  add  %i5, %i5, %i5
a011eb28:  c2 16 00 1d  lduh  [ %i0 + %i5 ], %g1
a011eb2c:  82 00 40 1a  add  %g1, %i2, %g1
a011eb30:  bb 28 60 02  sll  %g1, 2, %i5
a011eb34:  82 17 40 19  or  %i5, %i1, %g1
a011eb38:  b6 06 e0 01  inc  %i3
a011eb3c:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011eb40:  f8 20 40 00  st  %i4, [ %g1 ]
a011eb44:  80 a7 60 01  cmp  %i5, 1
a011eb48:  08 bf ff f8  bleu  0xa011eb28
a011eb4c:  ba 07 40 1d  add  %i5, %i5, %i5
a011eb50:  9e 03 e0 01  inc  %o7
a011eb54:  ba 0b e0 ff  and  %o7, 0xff, %i5
a011eb58:  80 a7 60 0b  cmp  %i5, 0xb
a011eb5c:  08 bf ff ea  bleu  0xa011eb04
a011eb60:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011eb64:  31 00 06 8b  sethi  %hi(0x1a2c00), %i0
a011eb68:  33 00 06 8b  sethi  %hi(0x1a2c00), %i1
a011eb6c:  98 16 23 c0  or  %i0, 0x3c0, %o4
a011eb70:  b0 16 63 b0  or  %i1, 0x3b0, %i0
a011eb74:  9a 17 20 28  or  %i4, 0x28, %o5
a011eb78:  9e 10 20 00  clr  %o7
a011eb7c:  ba 10 20 00  clr  %i5
a011eb80:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011eb84:  c2 03 40 00  ld  [ %o5 ], %g1
a011eb88:  b4 10 60 03  or  %g1, 3, %i2
a011eb8c:  b6 03 e0 38  add  %o7, 0x38, %i3
a011eb90:  f4 23 40 00  st  %i2, [ %o5 ]
a011eb94:  f8 0b 00 1d  ldub  [ %o4 + %i5 ], %i4
a011eb98:  b4 0e e0 ff  and  %i3, 0xff, %i2
a011eb9c:  b6 10 20 00  clr  %i3
a011eba0:  ba 10 20 00  clr  %i5
a011eba4:  ba 07 40 1d  add  %i5, %i5, %i5
a011eba8:  c2 16 00 1d  lduh  [ %i0 + %i5 ], %g1
a011ebac:  82 00 40 1a  add  %g1, %i2, %g1
a011ebb0:  bb 28 60 02  sll  %g1, 2, %i5
a011ebb4:  82 17 40 19  or  %i5, %i1, %g1
a011ebb8:  b6 06 e0 01  inc  %i3
a011ebbc:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011ebc0:  f8 20 40 00  st  %i4, [ %g1 ]
a011ebc4:  80 a7 60 01  cmp  %i5, 1
a011ebc8:  08 bf ff f8  bleu  0xa011eba8
a011ebcc:  ba 07 40 1d  add  %i5, %i5, %i5
a011ebd0:  9e 03 e0 01  inc  %o7
a011ebd4:  ba 0b e0 ff  and  %o7, 0xff, %i5
a011ebd8:  80 a7 60 07  cmp  %i5, 7
a011ebdc:  08 bf ff ea  bleu  0xa011eb84
a011ebe0:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011ebe4:  31 00 06 8b  sethi  %hi(0x1a2c00), %i0
a011ebe8:  33 00 06 8b  sethi  %hi(0x1a2c00), %i1
a011ebec:  98 16 23 b8  or  %i0, 0x3b8, %o4
a011ebf0:  b0 16 63 b0  or  %i1, 0x3b0, %i0
a011ebf4:  9a 17 20 28  or  %i4, 0x28, %o5
a011ebf8:  9e 10 20 00  clr  %o7
a011ebfc:  ba 10 20 00  clr  %i5
a011ec00:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011ec04:  c2 03 40 00  ld  [ %o5 ], %g1
a011ec08:  b4 10 60 03  or  %g1, 3, %i2
a011ec0c:  b6 03 e0 48  add  %o7, 0x48, %i3
a011ec10:  f4 23 40 00  st  %i2, [ %o5 ]
a011ec14:  f8 0b 00 1d  ldub  [ %o4 + %i5 ], %i4
a011ec18:  b4 0e e0 ff  and  %i3, 0xff, %i2
a011ec1c:  b6 10 20 00  clr  %i3
a011ec20:  ba 10 20 00  clr  %i5
a011ec24:  ba 07 40 1d  add  %i5, %i5, %i5
a011ec28:  c2 16 00 1d  lduh  [ %i0 + %i5 ], %g1
a011ec2c:  82 00 40 1a  add  %g1, %i2, %g1
a011ec30:  bb 28 60 02  sll  %g1, 2, %i5
a011ec34:  82 17 40 19  or  %i5, %i1, %g1
a011ec38:  b6 06 e0 01  inc  %i3
a011ec3c:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011ec40:  f8 20 40 00  st  %i4, [ %g1 ]
a011ec44:  80 a7 60 01  cmp  %i5, 1
a011ec48:  08 bf ff f8  bleu  0xa011ec28
a011ec4c:  ba 07 40 1d  add  %i5, %i5, %i5
a011ec50:  9e 03 e0 01  inc  %o7
a011ec54:  ba 0b e0 ff  and  %o7, 0xff, %i5
a011ec58:  80 a7 60 07  cmp  %i5, 7
a011ec5c:  08 bf ff ea  bleu  0xa011ec04
a011ec60:  35 33 c0 45  sethi  %hi(0xcf011400), %i2
a011ec64:  b8 16 a0 28  or  %i2, 0x28, %i4	! 0xcf011428
a011ec68:  f6 07 00 00  ld  [ %i4 ], %i3
a011ec6c:  b0 16 e0 03  or  %i3, 3, %i0
a011ec70:  33 00 06 8b  sethi  %hi(0x1a2c00), %i1
a011ec74:  f0 27 00 00  st  %i0, [ %i4 ]
a011ec78:  b8 16 63 b0  or  %i1, 0x3b0, %i4
a011ec7c:  b6 10 20 00  clr  %i3
a011ec80:  ba 10 20 00  clr  %i5
a011ec84:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011ec88:  b4 10 20 40  mov  0x40, %i2
a011ec8c:  82 07 40 1d  add  %i5, %i5, %g1
a011ec90:  f0 17 00 01  lduh  [ %i4 + %g1 ], %i0
a011ec94:  bb 2e 20 02  sll  %i0, 2, %i5
a011ec98:  82 17 40 19  or  %i5, %i1, %g1
a011ec9c:  b6 06 e0 01  inc  %i3
a011eca0:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011eca4:  f4 20 40 00  st  %i2, [ %g1 ]
a011eca8:  80 a7 60 01  cmp  %i5, 1
a011ecac:  08 bf ff f9  bleu  0xa011ec90
a011ecb0:  82 07 40 1d  add  %i5, %i5, %g1
a011ecb4:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011ecb8:  b8 17 60 28  or  %i5, 0x28, %i4	! 0xcf011428
a011ecbc:  f4 07 00 00  ld  [ %i4 ], %i2
a011ecc0:  b6 16 a0 03  or  %i2, 3, %i3
a011ecc4:  f6 27 00 00  st  %i3, [ %i4 ]
a011ecc8:  33 00 06 8b  sethi  %hi(0x1a2c00), %i1
a011eccc:  b8 16 63 b0  or  %i1, 0x3b0, %i4	! 0x1a2fb0
a011ecd0:  b6 10 20 00  clr  %i3
a011ecd4:  ba 10 20 00  clr  %i5
a011ecd8:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011ecdc:  b4 10 20 80  mov  0x80, %i2
a011ece0:  82 07 40 1d  add  %i5, %i5, %g1
a011ece4:  f0 17 00 01  lduh  [ %i4 + %g1 ], %i0
a011ece8:  ba 06 20 01  add  %i0, 1, %i5
a011ecec:  83 2f 60 02  sll  %i5, 2, %g1
a011ecf0:  b6 06 e0 01  inc  %i3
a011ecf4:  b0 10 40 19  or  %g1, %i1, %i0
a011ecf8:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011ecfc:  f4 26 00 00  st  %i2, [ %i0 ]
a011ed00:  80 a7 60 01  cmp  %i5, 1
a011ed04:  08 bf ff f8  bleu  0xa011ece4
a011ed08:  82 07 40 1d  add  %i5, %i5, %g1
a011ed0c:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011ed10:  b8 17 60 28  or  %i5, 0x28, %i4	! 0xcf011428
a011ed14:  f4 07 00 00  ld  [ %i4 ], %i2
a011ed18:  b6 16 a0 03  or  %i2, 3, %i3
a011ed1c:  f6 27 00 00  st  %i3, [ %i4 ]
a011ed20:  33 00 06 8b  sethi  %hi(0x1a2c00), %i1
a011ed24:  b8 16 63 b0  or  %i1, 0x3b0, %i4	! 0x1a2fb0
a011ed28:  b6 10 20 00  clr  %i3
a011ed2c:  ba 10 20 00  clr  %i5
a011ed30:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011ed34:  b4 10 20 cc  mov  0xcc, %i2
a011ed38:  82 07 40 1d  add  %i5, %i5, %g1
a011ed3c:  f0 17 00 01  lduh  [ %i4 + %g1 ], %i0
a011ed40:  ba 06 20 0c  add  %i0, 0xc, %i5
a011ed44:  83 2f 60 02  sll  %i5, 2, %g1
a011ed48:  b6 06 e0 01  inc  %i3
a011ed4c:  b0 10 40 19  or  %g1, %i1, %i0
a011ed50:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011ed54:  f4 26 00 00  st  %i2, [ %i0 ]
a011ed58:  80 a7 60 01  cmp  %i5, 1
a011ed5c:  08 bf ff f8  bleu  0xa011ed3c
a011ed60:  82 07 40 1d  add  %i5, %i5, %g1
a011ed64:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011ed68:  b8 17 60 28  or  %i5, 0x28, %i4	! 0xcf011428
a011ed6c:  f4 07 00 00  ld  [ %i4 ], %i2
a011ed70:  b6 16 a0 03  or  %i2, 3, %i3
a011ed74:  f6 27 00 00  st  %i3, [ %i4 ]
a011ed78:  33 00 06 8b  sethi  %hi(0x1a2c00), %i1
a011ed7c:  b8 16 63 b0  or  %i1, 0x3b0, %i4	! 0x1a2fb0
a011ed80:  b6 10 20 00  clr  %i3
a011ed84:  ba 10 20 00  clr  %i5
a011ed88:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011ed8c:  ba 07 40 1d  add  %i5, %i5, %i5
a011ed90:  f0 17 00 1d  lduh  [ %i4 + %i5 ], %i0
a011ed94:  b2 06 20 0d  add  %i0, 0xd, %i1
a011ed98:  83 2e 60 02  sll  %i1, 2, %g1
a011ed9c:  b6 06 e0 01  inc  %i3
a011eda0:  b0 10 40 1a  or  %g1, %i2, %i0
a011eda4:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011eda8:  c0 26 00 00  clr  [ %i0 ]
a011edac:  80 a7 60 01  cmp  %i5, 1
a011edb0:  08 bf ff f8  bleu  0xa011ed90
a011edb4:  ba 07 40 1d  add  %i5, %i5, %i5
a011edb8:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011edbc:  b6 10 60 28  or  %g1, 0x28, %i3	! 0xcf011428
a011edc0:  f2 06 c0 00  ld  [ %i3 ], %i1
a011edc4:  b4 16 60 03  or  %i1, 3, %i2
a011edc8:  f4 26 c0 00  st  %i2, [ %i3 ]
a011edcc:  39 00 06 8b  sethi  %hi(0x1a2c00), %i4
a011edd0:  b8 17 23 b0  or  %i4, 0x3b0, %i4	! 0x1a2fb0
a011edd4:  b6 10 20 00  clr  %i3
a011edd8:  ba 10 20 00  clr  %i5
a011eddc:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011ede0:  b0 07 40 1d  add  %i5, %i5, %i0
a011ede4:  c2 17 00 18  lduh  [ %i4 + %i0 ], %g1
a011ede8:  b2 00 60 0e  add  %g1, 0xe, %i1
a011edec:  bb 2e 60 02  sll  %i1, 2, %i5
a011edf0:  b0 17 40 1a  or  %i5, %i2, %i0
a011edf4:  b6 06 e0 01  inc  %i3
a011edf8:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011edfc:  c0 26 00 00  clr  [ %i0 ]
a011ee00:  80 a7 60 01  cmp  %i5, 1
a011ee04:  08 bf ff f8  bleu  0xa011ede4
a011ee08:  b0 07 40 1d  add  %i5, %i5, %i0
a011ee0c:  33 33 c0 45  sethi  %hi(0xcf011400), %i1
a011ee10:  b6 16 60 28  or  %i1, 0x28, %i3	! 0xcf011428
a011ee14:  fa 06 c0 00  ld  [ %i3 ], %i5
a011ee18:  b4 17 60 03  or  %i5, 3, %i2
a011ee1c:  f4 26 c0 00  st  %i2, [ %i3 ]
a011ee20:  39 00 06 8b  sethi  %hi(0x1a2c00), %i4
a011ee24:  b8 17 23 b0  or  %i4, 0x3b0, %i4	! 0x1a2fb0
a011ee28:  b6 10 20 00  clr  %i3
a011ee2c:  ba 10 20 00  clr  %i5
a011ee30:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011ee34:  82 07 40 1d  add  %i5, %i5, %g1
a011ee38:  f2 17 00 01  lduh  [ %i4 + %g1 ], %i1
a011ee3c:  ba 06 60 0f  add  %i1, 0xf, %i5
a011ee40:  b1 2f 60 02  sll  %i5, 2, %i0
a011ee44:  b6 06 e0 01  inc  %i3
a011ee48:  82 16 00 1a  or  %i0, %i2, %g1
a011ee4c:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011ee50:  c0 20 40 00  clr  [ %g1 ]
a011ee54:  80 a7 60 01  cmp  %i5, 1
a011ee58:  08 bf ff f8  bleu  0xa011ee38
a011ee5c:  82 07 40 1d  add  %i5, %i5, %g1
a011ee60:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011ee64:  b6 17 60 28  or  %i5, 0x28, %i3	! 0xcf011428
a011ee68:  f0 06 c0 00  ld  [ %i3 ], %i0
a011ee6c:  b4 16 20 03  or  %i0, 3, %i2
a011ee70:  f4 26 c0 00  st  %i2, [ %i3 ]
a011ee74:  39 00 06 8b  sethi  %hi(0x1a2c00), %i4
a011ee78:  b8 17 23 b0  or  %i4, 0x3b0, %i4	! 0x1a2fb0
a011ee7c:  b6 10 20 00  clr  %i3
a011ee80:  ba 10 20 00  clr  %i5
a011ee84:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011ee88:  ba 07 40 1d  add  %i5, %i5, %i5
a011ee8c:  f2 17 00 1d  lduh  [ %i4 + %i5 ], %i1
a011ee90:  b0 06 60 20  add  %i1, 0x20, %i0
a011ee94:  83 2e 20 02  sll  %i0, 2, %g1
a011ee98:  b6 06 e0 01  inc  %i3
a011ee9c:  b2 10 40 1a  or  %g1, %i2, %i1
a011eea0:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011eea4:  c0 26 40 00  clr  [ %i1 ]
a011eea8:  80 a7 60 01  cmp  %i5, 1
a011eeac:  08 bf ff f8  bleu  0xa011ee8c
a011eeb0:  ba 07 40 1d  add  %i5, %i5, %i5
a011eeb4:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011eeb8:  b6 10 60 28  or  %g1, 0x28, %i3	! 0xcf011428
a011eebc:  f0 06 c0 00  ld  [ %i3 ], %i0
a011eec0:  b4 16 20 03  or  %i0, 3, %i2
a011eec4:  f4 26 c0 00  st  %i2, [ %i3 ]
a011eec8:  39 00 06 8b  sethi  %hi(0x1a2c00), %i4
a011eecc:  b8 17 23 b0  or  %i4, 0x3b0, %i4	! 0x1a2fb0
a011eed0:  b6 10 20 00  clr  %i3
a011eed4:  ba 10 20 00  clr  %i5
a011eed8:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011eedc:  b2 07 40 1d  add  %i5, %i5, %i1
a011eee0:  c2 17 00 19  lduh  [ %i4 + %i1 ], %g1
a011eee4:  b0 00 60 21  add  %g1, 0x21, %i0
a011eee8:  bb 2e 20 02  sll  %i0, 2, %i5
a011eeec:  b2 17 40 1a  or  %i5, %i2, %i1
a011eef0:  b6 06 e0 01  inc  %i3
a011eef4:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011eef8:  c0 26 40 00  clr  [ %i1 ]
a011eefc:  80 a7 60 01  cmp  %i5, 1
a011ef00:  08 bf ff f8  bleu  0xa011eee0
a011ef04:  b2 07 40 1d  add  %i5, %i5, %i1
a011ef08:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011ef0c:  b6 16 20 28  or  %i0, 0x28, %i3	! 0xcf011428
a011ef10:  fa 06 c0 00  ld  [ %i3 ], %i5
a011ef14:  b4 17 60 03  or  %i5, 3, %i2
a011ef18:  f4 26 c0 00  st  %i2, [ %i3 ]
a011ef1c:  39 00 06 8b  sethi  %hi(0x1a2c00), %i4
a011ef20:  b8 17 23 b0  or  %i4, 0x3b0, %i4	! 0x1a2fb0
a011ef24:  b6 10 20 00  clr  %i3
a011ef28:  ba 10 20 00  clr  %i5
a011ef2c:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011ef30:  b4 10 20 c4  mov  0xc4, %i2
a011ef34:  ba 07 40 1d  add  %i5, %i5, %i5
a011ef38:  c2 17 00 1d  lduh  [ %i4 + %i5 ], %g1
a011ef3c:  b0 00 60 22  add  %g1, 0x22, %i0
a011ef40:  bb 2e 20 02  sll  %i0, 2, %i5
a011ef44:  82 17 40 19  or  %i5, %i1, %g1
a011ef48:  b6 06 e0 01  inc  %i3
a011ef4c:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011ef50:  f4 20 40 00  st  %i2, [ %g1 ]
a011ef54:  80 a7 60 01  cmp  %i5, 1
a011ef58:  08 bf ff f8  bleu  0xa011ef38
a011ef5c:  ba 07 40 1d  add  %i5, %i5, %i5
a011ef60:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011ef64:  b8 16 20 28  or  %i0, 0x28, %i4	! 0xcf011428
a011ef68:  f4 07 00 00  ld  [ %i4 ], %i2
a011ef6c:  b6 16 a0 03  or  %i2, 3, %i3
a011ef70:  f6 27 00 00  st  %i3, [ %i4 ]
a011ef74:  33 00 06 8b  sethi  %hi(0x1a2c00), %i1
a011ef78:  b8 16 63 b0  or  %i1, 0x3b0, %i4	! 0x1a2fb0
a011ef7c:  b6 10 20 00  clr  %i3
a011ef80:  ba 10 20 00  clr  %i5
a011ef84:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011ef88:  b4 10 20 07  mov  7, %i2
a011ef8c:  ba 07 40 1d  add  %i5, %i5, %i5
a011ef90:  c2 17 00 1d  lduh  [ %i4 + %i5 ], %g1
a011ef94:  b0 00 60 23  add  %g1, 0x23, %i0
a011ef98:  bb 2e 20 02  sll  %i0, 2, %i5
a011ef9c:  82 17 40 19  or  %i5, %i1, %g1
a011efa0:  b6 06 e0 01  inc  %i3
a011efa4:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011efa8:  f4 20 40 00  st  %i2, [ %g1 ]
a011efac:  80 a7 60 01  cmp  %i5, 1
a011efb0:  08 bf ff f8  bleu  0xa011ef90
a011efb4:  ba 07 40 1d  add  %i5, %i5, %i5
a011efb8:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011efbc:  b8 16 20 28  or  %i0, 0x28, %i4	! 0xcf011428
a011efc0:  f4 07 00 00  ld  [ %i4 ], %i2
a011efc4:  b6 16 a0 03  or  %i2, 3, %i3
a011efc8:  f6 27 00 00  st  %i3, [ %i4 ]
a011efcc:  33 00 06 8b  sethi  %hi(0x1a2c00), %i1
a011efd0:  b8 16 63 b0  or  %i1, 0x3b0, %i4	! 0x1a2fb0
a011efd4:  b6 10 20 00  clr  %i3
a011efd8:  ba 10 20 00  clr  %i5
a011efdc:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011efe0:  b4 10 20 23  mov  0x23, %i2
a011efe4:  ba 07 40 1d  add  %i5, %i5, %i5
a011efe8:  c2 17 00 1d  lduh  [ %i4 + %i5 ], %g1
a011efec:  b0 00 60 2c  add  %g1, 0x2c, %i0
a011eff0:  bb 2e 20 02  sll  %i0, 2, %i5
a011eff4:  82 17 40 19  or  %i5, %i1, %g1
a011eff8:  b6 06 e0 01  inc  %i3
a011effc:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011f000:  f4 20 40 00  st  %i2, [ %g1 ]
a011f004:  80 a7 60 01  cmp  %i5, 1
a011f008:  08 bf ff f8  bleu  0xa011efe8
a011f00c:  ba 07 40 1d  add  %i5, %i5, %i5
a011f010:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011f014:  b8 16 20 28  or  %i0, 0x28, %i4	! 0xcf011428
a011f018:  f4 07 00 00  ld  [ %i4 ], %i2
a011f01c:  b6 16 a0 03  or  %i2, 3, %i3
a011f020:  f6 27 00 00  st  %i3, [ %i4 ]
a011f024:  33 00 06 8b  sethi  %hi(0x1a2c00), %i1
a011f028:  b8 16 63 b0  or  %i1, 0x3b0, %i4	! 0x1a2fb0
a011f02c:  b6 10 20 00  clr  %i3
a011f030:  ba 10 20 00  clr  %i5
a011f034:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011f038:  b4 10 20 44  mov  0x44, %i2
a011f03c:  ba 07 40 1d  add  %i5, %i5, %i5
a011f040:  c2 17 00 1d  lduh  [ %i4 + %i5 ], %g1
a011f044:  b0 00 60 2d  add  %g1, 0x2d, %i0
a011f048:  bb 2e 20 02  sll  %i0, 2, %i5
a011f04c:  82 17 40 19  or  %i5, %i1, %g1
a011f050:  b6 06 e0 01  inc  %i3
a011f054:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011f058:  f4 20 40 00  st  %i2, [ %g1 ]
a011f05c:  80 a7 60 01  cmp  %i5, 1
a011f060:  08 bf ff f8  bleu  0xa011f040
a011f064:  ba 07 40 1d  add  %i5, %i5, %i5
a011f068:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011f06c:  b8 16 20 28  or  %i0, 0x28, %i4	! 0xcf011428
a011f070:  f4 07 00 00  ld  [ %i4 ], %i2
a011f074:  b6 16 a0 03  or  %i2, 3, %i3
a011f078:  f6 27 00 00  st  %i3, [ %i4 ]
a011f07c:  33 00 06 8b  sethi  %hi(0x1a2c00), %i1
a011f080:  b8 16 63 b0  or  %i1, 0x3b0, %i4	! 0x1a2fb0
a011f084:  b6 10 20 00  clr  %i3
a011f088:  ba 10 20 00  clr  %i5
a011f08c:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011f090:  b4 10 20 10  mov  0x10, %i2
a011f094:  ba 07 40 1d  add  %i5, %i5, %i5
a011f098:  c2 17 00 1d  lduh  [ %i4 + %i5 ], %g1
a011f09c:  b0 00 60 55  add  %g1, 0x55, %i0
a011f0a0:  bb 2e 20 02  sll  %i0, 2, %i5
a011f0a4:  82 17 40 19  or  %i5, %i1, %g1
a011f0a8:  b6 06 e0 01  inc  %i3
a011f0ac:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011f0b0:  f4 20 40 00  st  %i2, [ %g1 ]
a011f0b4:  80 a7 60 01  cmp  %i5, 1
a011f0b8:  08 bf ff f8  bleu  0xa011f098
a011f0bc:  ba 07 40 1d  add  %i5, %i5, %i5
a011f0c0:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011f0c4:  b8 16 20 28  or  %i0, 0x28, %i4	! 0xcf011428
a011f0c8:  f4 07 00 00  ld  [ %i4 ], %i2
a011f0cc:  b6 16 a0 03  or  %i2, 3, %i3
a011f0d0:  f6 27 00 00  st  %i3, [ %i4 ]
a011f0d4:  33 00 06 8b  sethi  %hi(0x1a2c00), %i1
a011f0d8:  b8 16 63 b0  or  %i1, 0x3b0, %i4	! 0x1a2fb0
a011f0dc:  b6 10 20 00  clr  %i3
a011f0e0:  ba 10 20 00  clr  %i5
a011f0e4:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011f0e8:  82 07 40 1d  add  %i5, %i5, %g1
a011f0ec:  f0 17 00 01  lduh  [ %i4 + %g1 ], %i0
a011f0f0:  b2 06 20 56  add  %i0, 0x56, %i1
a011f0f4:  bb 2e 60 02  sll  %i1, 2, %i5
a011f0f8:  82 17 40 1a  or  %i5, %i2, %g1
a011f0fc:  b6 06 e0 01  inc  %i3
a011f100:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011f104:  c0 20 40 00  clr  [ %g1 ]
a011f108:  80 a7 60 01  cmp  %i5, 1
a011f10c:  08 bf ff f8  bleu  0xa011f0ec
a011f110:  82 07 40 1d  add  %i5, %i5, %g1
a011f114:  33 33 c0 45  sethi  %hi(0xcf011400), %i1
a011f118:  b6 16 60 28  or  %i1, 0x28, %i3	! 0xcf011428
a011f11c:  fa 06 c0 00  ld  [ %i3 ], %i5
a011f120:  b4 17 60 03  or  %i5, 3, %i2
a011f124:  f4 26 c0 00  st  %i2, [ %i3 ]
a011f128:  39 00 06 8b  sethi  %hi(0x1a2c00), %i4
a011f12c:  b8 17 23 b0  or  %i4, 0x3b0, %i4	! 0x1a2fb0
a011f130:  b6 10 20 00  clr  %i3
a011f134:  ba 10 20 00  clr  %i5
a011f138:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011f13c:  b4 10 20 04  mov  4, %i2
a011f140:  82 07 40 1d  add  %i5, %i5, %g1
a011f144:  f0 17 00 01  lduh  [ %i4 + %g1 ], %i0
a011f148:  ba 06 20 58  add  %i0, 0x58, %i5
a011f14c:  83 2f 60 02  sll  %i5, 2, %g1
a011f150:  b6 06 e0 01  inc  %i3
a011f154:  b0 10 40 19  or  %g1, %i1, %i0
a011f158:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011f15c:  f4 26 00 00  st  %i2, [ %i0 ]
a011f160:  80 a7 60 01  cmp  %i5, 1
a011f164:  08 bf ff f8  bleu  0xa011f144
a011f168:  82 07 40 1d  add  %i5, %i5, %g1
a011f16c:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011f170:  b6 17 60 28  or  %i5, 0x28, %i3	! 0xcf011428
a011f174:  f2 06 c0 00  ld  [ %i3 ], %i1
a011f178:  b4 16 60 03  or  %i1, 3, %i2
a011f17c:  f4 26 c0 00  st  %i2, [ %i3 ]
a011f180:  39 00 06 8b  sethi  %hi(0x1a2c00), %i4
a011f184:  b8 17 23 b0  or  %i4, 0x3b0, %i4	! 0x1a2fb0
a011f188:  b6 10 20 00  clr  %i3
a011f18c:  ba 10 20 00  clr  %i5
a011f190:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011f194:  ba 07 40 1d  add  %i5, %i5, %i5
a011f198:  f0 17 00 1d  lduh  [ %i4 + %i5 ], %i0
a011f19c:  b2 06 20 59  add  %i0, 0x59, %i1
a011f1a0:  83 2e 60 02  sll  %i1, 2, %g1
a011f1a4:  b6 06 e0 01  inc  %i3
a011f1a8:  b0 10 40 1a  or  %g1, %i2, %i0
a011f1ac:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011f1b0:  c0 26 00 00  clr  [ %i0 ]
a011f1b4:  80 a7 60 01  cmp  %i5, 1
a011f1b8:  08 bf ff f8  bleu  0xa011f198
a011f1bc:  ba 07 40 1d  add  %i5, %i5, %i5
a011f1c0:  81 c7 e0 08  ret
a011f1c4:  81 e8 00 00  restore
