# leon2s FUN_a009ea34 0xa009ea34-0xa009ec20 (492 bytes)
a009ea34:  9d e3 bf 98  save  %sp, -104, %sp
a009ea38:  b2 0e 60 ff  and  %i1, 0xff, %i1
a009ea3c:  82 06 7f ff  add  %i1, -1, %g1
a009ea40:  80 a0 60 05  cmp  %g1, 5
a009ea44:  18 80 00 75  bgu  0xa009ec18
a009ea48:  1b 28 02 7a  sethi  %hi(0xa009e800), %o5
a009ea4c:  83 28 60 02  sll  %g1, 2, %g1
a009ea50:  9a 13 62 1c  or  %o5, 0x21c, %o5
a009ea54:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a009ea58:  81 c0 40 00  jmp  %g1
a009ea5c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009ea60:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009ea64:  7f ff 51 78  call  0xa0073044
a009ea68:  90 12 23 70  or  %o0, 0x370, %o0	! 0xa006af70
a009ea6c:  80 a6 20 00  cmp  %i0, 0
a009ea70:  12 80 00 07  bne  0xa009ea8c
a009ea74:  80 a6 20 01  cmp  %i0, 1
a009ea78:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a009ea7c:  9a 13 63 4c  or  %o5, 0x34c, %o5	! 0xcf01474c
a009ea80:  c2 03 40 00  ld  [ %o5 ], %g1
a009ea84:  10 80 00 07  b  0xa009eaa0
a009ea88:  82 08 60 f0  and  %g1, 0xf0, %g1
a009ea8c:  12 80 00 63  bne  0xa009ec18
a009ea90:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a009ea94:  9a 13 63 4c  or  %o5, 0x34c, %o5	! 0xcf01474c
a009ea98:  c2 03 40 00  ld  [ %o5 ], %g1
a009ea9c:  82 08 60 0f  and  %g1, 0xf, %g1
a009eaa0:  c2 23 40 00  st  %g1, [ %o5 ]
a009eaa4:  30 80 00 5d  b,a   0xa009ec18
a009eaa8:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009eaac:  7f ff 51 66  call  0xa0073044
a009eab0:  90 12 23 90  or  %o0, 0x390, %o0	! 0xa006af90
a009eab4:  80 a6 20 00  cmp  %i0, 0
a009eab8:  12 80 00 0a  bne  0xa009eae0
a009eabc:  80 a6 20 01  cmp  %i0, 1
a009eac0:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a009eac4:  82 10 63 4c  or  %g1, 0x34c, %g1	! 0xcf01474c
a009eac8:  da 00 40 00  ld  [ %g1 ], %o5
a009eacc:  9a 0b 60 f0  and  %o5, 0xf0, %o5
a009ead0:  da 20 40 00  st  %o5, [ %g1 ]
a009ead4:  da 00 40 00  ld  [ %g1 ], %o5
a009ead8:  10 80 00 4f  b  0xa009ec14
a009eadc:  9a 13 60 01  or  %o5, 1, %o5
a009eae0:  12 80 00 4e  bne  0xa009ec18
a009eae4:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a009eae8:  82 10 63 4c  or  %g1, 0x34c, %g1	! 0xcf01474c
a009eaec:  da 00 40 00  ld  [ %g1 ], %o5
a009eaf0:  9a 0b 60 0f  and  %o5, 0xf, %o5
a009eaf4:  da 20 40 00  st  %o5, [ %g1 ]
a009eaf8:  da 00 40 00  ld  [ %g1 ], %o5
a009eafc:  10 80 00 46  b  0xa009ec14
a009eb00:  9a 13 60 10  or  %o5, 0x10, %o5
a009eb04:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009eb08:  7f ff 51 4f  call  0xa0073044
a009eb0c:  90 12 23 b0  or  %o0, 0x3b0, %o0	! 0xa006afb0
a009eb10:  80 a6 20 00  cmp  %i0, 0
a009eb14:  12 80 00 0a  bne  0xa009eb3c
a009eb18:  80 a6 20 01  cmp  %i0, 1
a009eb1c:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a009eb20:  82 10 63 4c  or  %g1, 0x34c, %g1	! 0xcf01474c
a009eb24:  da 00 40 00  ld  [ %g1 ], %o5
a009eb28:  9a 0b 60 f0  and  %o5, 0xf0, %o5
a009eb2c:  da 20 40 00  st  %o5, [ %g1 ]
a009eb30:  da 00 40 00  ld  [ %g1 ], %o5
a009eb34:  10 80 00 38  b  0xa009ec14
a009eb38:  9a 13 60 02  or  %o5, 2, %o5
a009eb3c:  12 80 00 37  bne  0xa009ec18
a009eb40:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a009eb44:  82 10 63 4c  or  %g1, 0x34c, %g1	! 0xcf01474c
a009eb48:  da 00 40 00  ld  [ %g1 ], %o5
a009eb4c:  9a 0b 60 0f  and  %o5, 0xf, %o5
a009eb50:  da 20 40 00  st  %o5, [ %g1 ]
a009eb54:  da 00 40 00  ld  [ %g1 ], %o5
a009eb58:  10 80 00 2f  b  0xa009ec14
a009eb5c:  9a 13 60 20  or  %o5, 0x20, %o5
a009eb60:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009eb64:  7f ff 51 38  call  0xa0073044
a009eb68:  90 12 23 d0  or  %o0, 0x3d0, %o0	! 0xa006afd0
a009eb6c:  80 a6 20 00  cmp  %i0, 0
a009eb70:  12 80 00 0a  bne  0xa009eb98
a009eb74:  80 a6 20 01  cmp  %i0, 1
a009eb78:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a009eb7c:  82 10 63 4c  or  %g1, 0x34c, %g1	! 0xcf01474c
a009eb80:  da 00 40 00  ld  [ %g1 ], %o5
a009eb84:  9a 0b 60 f0  and  %o5, 0xf0, %o5
a009eb88:  da 20 40 00  st  %o5, [ %g1 ]
a009eb8c:  da 00 40 00  ld  [ %g1 ], %o5
a009eb90:  10 80 00 21  b  0xa009ec14
a009eb94:  9a 13 60 03  or  %o5, 3, %o5
a009eb98:  12 80 00 20  bne  0xa009ec18
a009eb9c:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a009eba0:  82 10 63 4c  or  %g1, 0x34c, %g1	! 0xcf01474c
a009eba4:  da 00 40 00  ld  [ %g1 ], %o5
a009eba8:  9a 0b 60 0f  and  %o5, 0xf, %o5
a009ebac:  da 20 40 00  st  %o5, [ %g1 ]
a009ebb0:  da 00 40 00  ld  [ %g1 ], %o5
a009ebb4:  10 80 00 18  b  0xa009ec14
a009ebb8:  9a 13 60 30  or  %o5, 0x30, %o5
a009ebbc:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009ebc0:  7f ff 51 21  call  0xa0073044
a009ebc4:  90 12 23 f0  or  %o0, 0x3f0, %o0	! 0xa006aff0
a009ebc8:  80 a6 20 00  cmp  %i0, 0
a009ebcc:  12 80 00 0a  bne  0xa009ebf4
a009ebd0:  80 a6 20 01  cmp  %i0, 1
a009ebd4:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a009ebd8:  82 10 63 4c  or  %g1, 0x34c, %g1	! 0xcf01474c
a009ebdc:  da 00 40 00  ld  [ %g1 ], %o5
a009ebe0:  9a 0b 60 f0  and  %o5, 0xf0, %o5
a009ebe4:  da 20 40 00  st  %o5, [ %g1 ]
a009ebe8:  da 00 40 00  ld  [ %g1 ], %o5
a009ebec:  10 80 00 0a  b  0xa009ec14
a009ebf0:  9a 13 60 04  or  %o5, 4, %o5
a009ebf4:  12 80 00 09  bne  0xa009ec18
a009ebf8:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a009ebfc:  82 10 63 4c  or  %g1, 0x34c, %g1	! 0xcf01474c
a009ec00:  da 00 40 00  ld  [ %g1 ], %o5
a009ec04:  9a 0b 60 0f  and  %o5, 0xf, %o5
a009ec08:  da 20 40 00  st  %o5, [ %g1 ]
a009ec0c:  da 00 40 00  ld  [ %g1 ], %o5
a009ec10:  9a 13 60 40  or  %o5, 0x40, %o5
a009ec14:  da 20 40 00  st  %o5, [ %g1 ]
a009ec18:  81 c7 e0 08  ret
a009ec1c:  81 e8 00 00  restore
