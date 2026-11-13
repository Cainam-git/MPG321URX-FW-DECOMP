# leon2s FUN_a008ed50 0xa008ed50-0xa008f270 (1312 bytes)
a008ed50:  9d e3 bf 98  save  %sp, -104, %sp
a008ed54:  b4 0e a0 ff  and  %i2, 0xff, %i2
a008ed58:  80 a6 a0 01  cmp  %i2, 1
a008ed5c:  32 80 00 ee  bne,a   0xa008f114
a008ed60:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008ed64:  b2 0e 60 ff  and  %i1, 0xff, %i1
a008ed68:  82 1e 60 31  xor  %i1, 0x31, %g1
a008ed6c:  80 a0 00 01  cmp  %g0, %g1
a008ed70:  ba 60 3f ff  subx  %g0, -1, %i5
a008ed74:  82 1e 60 41  xor  %i1, 0x41, %g1
a008ed78:  80 a0 00 01  cmp  %g0, %g1
a008ed7c:  82 60 3f ff  subx  %g0, -1, %g1
a008ed80:  80 97 40 01  orcc  %i5, %g1, %g0
a008ed84:  12 80 00 0b  bne  0xa008edb0
a008ed88:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008ed8c:  82 1e 60 51  xor  %i1, 0x51, %g1
a008ed90:  80 a0 00 01  cmp  %g0, %g1
a008ed94:  ba 60 3f ff  subx  %g0, -1, %i5
a008ed98:  82 1e 60 61  xor  %i1, 0x61, %g1
a008ed9c:  80 a0 00 01  cmp  %g0, %g1
a008eda0:  82 60 3f ff  subx  %g0, -1, %g1
a008eda4:  80 97 40 01  orcc  %i5, %g1, %g0
a008eda8:  02 80 00 96  be  0xa008f000
a008edac:  01 00 00 00  nop
a008edb0:  80 a6 20 00  cmp  %i0, 0
a008edb4:  12 80 00 30  bne  0xa008ee74
a008edb8:  80 a6 20 01  cmp  %i0, 1
a008edbc:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a008edc0:  ba 17 62 b4  or  %i5, 0x2b4, %i5	! 0xcf0116b4
a008edc4:  c2 07 40 00  ld  [ %i5 ], %g1
a008edc8:  82 08 60 fe  and  %g1, 0xfe, %g1
a008edcc:  c2 27 40 00  st  %g1, [ %i5 ]
a008edd0:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008edd4:  b6 10 60 40  or  %g1, 0x40, %i3	! 0xcf03c840
a008edd8:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008eddc:  9e 10 63 ff  or  %g1, 0x3ff, %o7	! 0xffff
a008ede0:  b4 10 3f ff  mov  -1, %i2
a008ede4:  b0 10 20 02  mov  2, %i0
a008ede8:  82 06 bf ff  add  %i2, -1, %g1
a008edec:  bb 28 60 10  sll  %g1, 0x10, %i5
a008edf0:  b9 37 60 10  srl  %i5, 0x10, %i4
a008edf4:  fa 06 c0 00  ld  [ %i3 ], %i5
a008edf8:  80 a7 60 01  cmp  %i5, 1
a008edfc:  02 80 00 03  be  0xa008ee08
a008ee00:  b4 10 00 01  mov  %g1, %i2
a008ee04:  f0 26 c0 00  st  %i0, [ %i3 ]
a008ee08:  c2 06 c0 00  ld  [ %i3 ], %g1
a008ee0c:  80 a0 60 02  cmp  %g1, 2
a008ee10:  02 80 00 06  be  0xa008ee28
a008ee14:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a008ee18:  80 a7 00 0f  cmp  %i4, %o7
a008ee1c:  32 bf ff f4  bne,a   0xa008edec
a008ee20:  82 06 bf ff  add  %i2, -1, %g1
a008ee24:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a008ee28:  82 10 20 02  mov  2, %g1
a008ee2c:  c2 26 c0 00  st  %g1, [ %i3 ]
a008ee30:  b8 17 62 00  or  %i5, 0x200, %i4
a008ee34:  c2 07 00 00  ld  [ %i4 ], %g1
a008ee38:  82 10 60 10  or  %g1, 0x10, %g1
a008ee3c:  c2 27 00 00  st  %g1, [ %i4 ]
a008ee40:  c0 26 c0 00  clr  [ %i3 ]
a008ee44:  ba 17 63 bc  or  %i5, 0x3bc, %i5
a008ee48:  c2 07 40 00  ld  [ %i5 ], %g1
a008ee4c:  82 10 60 01  or  %g1, 1, %g1
a008ee50:  c2 27 40 00  st  %g1, [ %i5 ]
a008ee54:  3b 33 c0 51  sethi  %hi(0xcf014400), %i5
a008ee58:  ba 17 63 54  or  %i5, 0x354, %i5	! 0xcf014754
a008ee5c:  c2 07 40 00  ld  [ %i5 ], %g1
a008ee60:  82 08 60 fc  and  %g1, 0xfc, %g1
a008ee64:  c2 27 40 00  st  %g1, [ %i5 ]
a008ee68:  c2 07 40 00  ld  [ %i5 ], %g1
a008ee6c:  10 80 00 31  b  0xa008ef30
a008ee70:  82 10 60 02  or  %g1, 2, %g1
a008ee74:  12 80 00 32  bne  0xa008ef3c
a008ee78:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008ee7c:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a008ee80:  ba 17 62 b4  or  %i5, 0x2b4, %i5	! 0xcf0116b4
a008ee84:  c2 07 40 00  ld  [ %i5 ], %g1
a008ee88:  82 08 60 fd  and  %g1, 0xfd, %g1
a008ee8c:  c2 27 40 00  st  %g1, [ %i5 ]
a008ee90:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008ee94:  b6 10 60 40  or  %g1, 0x40, %i3	! 0xcf03c840
a008ee98:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008ee9c:  9e 10 63 ff  or  %g1, 0x3ff, %o7	! 0xffff
a008eea0:  b4 10 3f ff  mov  -1, %i2
a008eea4:  b0 10 20 02  mov  2, %i0
a008eea8:  82 06 bf ff  add  %i2, -1, %g1
a008eeac:  bb 28 60 10  sll  %g1, 0x10, %i5
a008eeb0:  b9 37 60 10  srl  %i5, 0x10, %i4
a008eeb4:  fa 06 c0 00  ld  [ %i3 ], %i5
a008eeb8:  80 a7 60 01  cmp  %i5, 1
a008eebc:  02 80 00 03  be  0xa008eec8
a008eec0:  b4 10 00 01  mov  %g1, %i2
a008eec4:  f0 26 c0 00  st  %i0, [ %i3 ]
a008eec8:  c2 06 c0 00  ld  [ %i3 ], %g1
a008eecc:  80 a0 60 02  cmp  %g1, 2
a008eed0:  02 80 00 06  be  0xa008eee8
a008eed4:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a008eed8:  80 a7 00 0f  cmp  %i4, %o7
a008eedc:  12 bf ff f4  bne  0xa008eeac
a008eee0:  82 06 bf ff  add  %i2, -1, %g1
a008eee4:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a008eee8:  82 10 20 02  mov  2, %g1
a008eeec:  c2 26 c0 00  st  %g1, [ %i3 ]
a008eef0:  b8 17 62 00  or  %i5, 0x200, %i4
a008eef4:  c2 07 00 00  ld  [ %i4 ], %g1
a008eef8:  82 10 60 20  or  %g1, 0x20, %g1
a008eefc:  c2 27 00 00  st  %g1, [ %i4 ]
a008ef00:  c0 26 c0 00  clr  [ %i3 ]
a008ef04:  ba 17 63 bc  or  %i5, 0x3bc, %i5
a008ef08:  c2 07 40 00  ld  [ %i5 ], %g1
a008ef0c:  82 10 60 02  or  %g1, 2, %g1
a008ef10:  c2 27 40 00  st  %g1, [ %i5 ]
a008ef14:  3b 33 c0 51  sethi  %hi(0xcf014400), %i5
a008ef18:  ba 17 63 54  or  %i5, 0x354, %i5	! 0xcf014754
a008ef1c:  c2 07 40 00  ld  [ %i5 ], %g1
a008ef20:  82 08 60 f3  and  %g1, 0xf3, %g1
a008ef24:  c2 27 40 00  st  %g1, [ %i5 ]
a008ef28:  c2 07 40 00  ld  [ %i5 ], %g1
a008ef2c:  82 10 60 08  or  %g1, 8, %g1
a008ef30:  c2 27 40 00  st  %g1, [ %i5 ]
a008ef34:  10 80 00 1e  b  0xa008efac
a008ef38:  80 a6 60 41  cmp  %i1, 0x41
a008ef3c:  b8 10 60 40  or  %g1, 0x40, %i4
a008ef40:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008ef44:  9e 10 63 ff  or  %g1, 0x3ff, %o7	! 0xffff
a008ef48:  b4 10 3f ff  mov  -1, %i2
a008ef4c:  b0 10 20 02  mov  2, %i0
a008ef50:  82 06 bf ff  add  %i2, -1, %g1
a008ef54:  bb 28 60 10  sll  %g1, 0x10, %i5
a008ef58:  b7 37 60 10  srl  %i5, 0x10, %i3
a008ef5c:  fa 07 00 00  ld  [ %i4 ], %i5
a008ef60:  80 a7 60 01  cmp  %i5, 1
a008ef64:  02 80 00 03  be  0xa008ef70
a008ef68:  b4 10 00 01  mov  %g1, %i2
a008ef6c:  f0 27 00 00  st  %i0, [ %i4 ]
a008ef70:  c2 07 00 00  ld  [ %i4 ], %g1
a008ef74:  80 a0 60 02  cmp  %g1, 2
a008ef78:  02 80 00 04  be  0xa008ef88
a008ef7c:  80 a6 c0 0f  cmp  %i3, %o7
a008ef80:  12 bf ff f5  bne  0xa008ef54
a008ef84:  82 06 bf ff  add  %i2, -1, %g1
a008ef88:  82 10 20 02  mov  2, %g1
a008ef8c:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a008ef90:  c2 27 00 00  st  %g1, [ %i4 ]
a008ef94:  ba 17 62 00  or  %i5, 0x200, %i5
a008ef98:  c2 07 40 00  ld  [ %i5 ], %g1
a008ef9c:  82 08 7f cf  and  %g1, -49, %g1
a008efa0:  c2 27 40 00  st  %g1, [ %i5 ]
a008efa4:  c0 27 00 00  clr  [ %i4 ]
a008efa8:  80 a6 60 41  cmp  %i1, 0x41
a008efac:  02 80 00 0b  be  0xa008efd8
a008efb0:  80 a6 60 41  cmp  %i1, 0x41
a008efb4:  04 80 00 10  ble  0xa008eff4
a008efb8:  03 33 c0 49  sethi  %hi(0xcf012400), %g1
a008efbc:  80 a6 60 51  cmp  %i1, 0x51
a008efc0:  02 80 00 08  be  0xa008efe0
a008efc4:  80 a6 60 61  cmp  %i1, 0x61
a008efc8:  02 80 00 08  be  0xa008efe8
a008efcc:  ba 10 20 03  mov  3, %i5
a008efd0:  10 80 00 0a  b  0xa008eff8
a008efd4:  82 10 60 bc  or  %g1, 0xbc, %g1
a008efd8:  10 80 00 03  b  0xa008efe4
a008efdc:  ba 10 20 01  mov  1, %i5
a008efe0:  ba 10 20 02  mov  2, %i5
a008efe4:  03 33 c0 49  sethi  %hi(0xcf012400), %g1
a008efe8:  82 10 60 bc  or  %g1, 0xbc, %g1	! 0xcf0124bc
a008efec:  fa 20 40 00  st  %i5, [ %g1 ]
a008eff0:  30 80 00 9e  b,a   0xa008f268
a008eff4:  82 10 60 bc  or  %g1, 0xbc, %g1
a008eff8:  c0 20 40 00  clr  [ %g1 ]
a008effc:  30 80 00 9b  b,a   0xa008f268
a008f000:  80 a6 20 00  cmp  %i0, 0
a008f004:  12 80 00 18  bne  0xa008f064
a008f008:  80 a6 20 01  cmp  %i0, 1
a008f00c:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008f010:  b8 10 60 40  or  %g1, 0x40, %i4	! 0xcf03c840
a008f014:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008f018:  b0 10 63 ff  or  %g1, 0x3ff, %i0	! 0xffff
a008f01c:  b4 10 3f ff  mov  -1, %i2
a008f020:  b2 10 20 02  mov  2, %i1
a008f024:  82 06 bf ff  add  %i2, -1, %g1
a008f028:  bb 28 60 10  sll  %g1, 0x10, %i5
a008f02c:  b7 37 60 10  srl  %i5, 0x10, %i3
a008f030:  fa 07 00 00  ld  [ %i4 ], %i5
a008f034:  80 a7 60 01  cmp  %i5, 1
a008f038:  02 80 00 03  be  0xa008f044
a008f03c:  b4 10 00 01  mov  %g1, %i2
a008f040:  f2 27 00 00  st  %i1, [ %i4 ]
a008f044:  c2 07 00 00  ld  [ %i4 ], %g1
a008f048:  80 a0 60 02  cmp  %g1, 2
a008f04c:  02 80 00 49  be  0xa008f170
a008f050:  80 a6 c0 18  cmp  %i3, %i0
a008f054:  32 bf ff f5  bne,a   0xa008f028
a008f058:  82 06 bf ff  add  %i2, -1, %g1
a008f05c:  10 80 00 46  b  0xa008f174
a008f060:  82 10 20 02  mov  2, %g1
a008f064:  12 80 00 17  bne  0xa008f0c0
a008f068:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008f06c:  b8 10 60 40  or  %g1, 0x40, %i4	! 0xcf03c840
a008f070:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008f074:  b0 10 63 ff  or  %g1, 0x3ff, %i0	! 0xffff
a008f078:  b4 10 3f ff  mov  -1, %i2
a008f07c:  b2 10 20 02  mov  2, %i1
a008f080:  82 06 bf ff  add  %i2, -1, %g1
a008f084:  bb 28 60 10  sll  %g1, 0x10, %i5
a008f088:  b7 37 60 10  srl  %i5, 0x10, %i3
a008f08c:  fa 07 00 00  ld  [ %i4 ], %i5
a008f090:  80 a7 60 01  cmp  %i5, 1
a008f094:  02 80 00 03  be  0xa008f0a0
a008f098:  b4 10 00 01  mov  %g1, %i2
a008f09c:  f2 27 00 00  st  %i1, [ %i4 ]
a008f0a0:  c2 07 00 00  ld  [ %i4 ], %g1
a008f0a4:  80 a0 60 02  cmp  %g1, 2
a008f0a8:  02 80 00 4e  be  0xa008f1e0
a008f0ac:  80 a6 c0 18  cmp  %i3, %i0
a008f0b0:  32 bf ff f5  bne,a   0xa008f084
a008f0b4:  82 06 bf ff  add  %i2, -1, %g1
a008f0b8:  10 80 00 4b  b  0xa008f1e4
a008f0bc:  82 10 20 02  mov  2, %g1
a008f0c0:  b8 10 60 40  or  %g1, 0x40, %i4
a008f0c4:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008f0c8:  b0 10 63 ff  or  %g1, 0x3ff, %i0	! 0xffff
a008f0cc:  b4 10 3f ff  mov  -1, %i2
a008f0d0:  b2 10 20 02  mov  2, %i1
a008f0d4:  82 06 bf ff  add  %i2, -1, %g1
a008f0d8:  bb 28 60 10  sll  %g1, 0x10, %i5
a008f0dc:  b7 37 60 10  srl  %i5, 0x10, %i3
a008f0e0:  fa 07 00 00  ld  [ %i4 ], %i5
a008f0e4:  80 a7 60 01  cmp  %i5, 1
a008f0e8:  02 80 00 03  be  0xa008f0f4
a008f0ec:  b4 10 00 01  mov  %g1, %i2
a008f0f0:  f2 27 00 00  st  %i1, [ %i4 ]
a008f0f4:  c2 07 00 00  ld  [ %i4 ], %g1
a008f0f8:  80 a0 60 02  cmp  %g1, 2
a008f0fc:  02 80 00 53  be  0xa008f248
a008f100:  80 a6 c0 18  cmp  %i3, %i0
a008f104:  32 bf ff f5  bne,a   0xa008f0d8
a008f108:  82 06 bf ff  add  %i2, -1, %g1
a008f10c:  10 80 00 50  b  0xa008f24c
a008f110:  82 10 20 02  mov  2, %g1
a008f114:  80 a6 20 00  cmp  %i0, 0
a008f118:  12 80 00 1d  bne  0xa008f18c
a008f11c:  80 a6 20 01  cmp  %i0, 1
a008f120:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008f124:  b8 10 60 40  or  %g1, 0x40, %i4	! 0xcf03c840
a008f128:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008f12c:  b0 10 63 ff  or  %g1, 0x3ff, %i0	! 0xffff
a008f130:  b4 10 3f ff  mov  -1, %i2
a008f134:  b2 10 20 02  mov  2, %i1
a008f138:  82 06 bf ff  add  %i2, -1, %g1
a008f13c:  bb 28 60 10  sll  %g1, 0x10, %i5
a008f140:  b7 37 60 10  srl  %i5, 0x10, %i3
a008f144:  fa 07 00 00  ld  [ %i4 ], %i5
a008f148:  80 a7 60 01  cmp  %i5, 1
a008f14c:  02 80 00 03  be  0xa008f158
a008f150:  b4 10 00 01  mov  %g1, %i2
a008f154:  f2 27 00 00  st  %i1, [ %i4 ]
a008f158:  c2 07 00 00  ld  [ %i4 ], %g1
a008f15c:  80 a0 60 02  cmp  %g1, 2
a008f160:  02 80 00 04  be  0xa008f170
a008f164:  80 a6 c0 18  cmp  %i3, %i0
a008f168:  32 bf ff f5  bne,a   0xa008f13c
a008f16c:  82 06 bf ff  add  %i2, -1, %g1
a008f170:  82 10 20 02  mov  2, %g1
a008f174:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a008f178:  c2 27 00 00  st  %g1, [ %i4 ]
a008f17c:  ba 17 62 00  or  %i5, 0x200, %i5
a008f180:  c2 07 40 00  ld  [ %i5 ], %g1
a008f184:  10 80 00 37  b  0xa008f260
a008f188:  82 08 7f ef  and  %g1, -17, %g1
a008f18c:  12 80 00 1c  bne  0xa008f1fc
a008f190:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008f194:  b8 10 60 40  or  %g1, 0x40, %i4	! 0xcf03c840
a008f198:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008f19c:  b0 10 63 ff  or  %g1, 0x3ff, %i0	! 0xffff
a008f1a0:  b4 10 3f ff  mov  -1, %i2
a008f1a4:  b2 10 20 02  mov  2, %i1
a008f1a8:  82 06 bf ff  add  %i2, -1, %g1
a008f1ac:  bb 28 60 10  sll  %g1, 0x10, %i5
a008f1b0:  b7 37 60 10  srl  %i5, 0x10, %i3
a008f1b4:  fa 07 00 00  ld  [ %i4 ], %i5
a008f1b8:  80 a7 60 01  cmp  %i5, 1
a008f1bc:  02 80 00 03  be  0xa008f1c8
a008f1c0:  b4 10 00 01  mov  %g1, %i2
a008f1c4:  f2 27 00 00  st  %i1, [ %i4 ]
a008f1c8:  c2 07 00 00  ld  [ %i4 ], %g1
a008f1cc:  80 a0 60 02  cmp  %g1, 2
a008f1d0:  02 80 00 04  be  0xa008f1e0
a008f1d4:  80 a6 c0 18  cmp  %i3, %i0
a008f1d8:  32 bf ff f5  bne,a   0xa008f1ac
a008f1dc:  82 06 bf ff  add  %i2, -1, %g1
a008f1e0:  82 10 20 02  mov  2, %g1
a008f1e4:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a008f1e8:  c2 27 00 00  st  %g1, [ %i4 ]
a008f1ec:  ba 17 62 00  or  %i5, 0x200, %i5
a008f1f0:  c2 07 40 00  ld  [ %i5 ], %g1
a008f1f4:  10 80 00 1b  b  0xa008f260
a008f1f8:  82 08 7f df  and  %g1, -33, %g1
a008f1fc:  b8 10 60 40  or  %g1, 0x40, %i4
a008f200:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008f204:  b0 10 63 ff  or  %g1, 0x3ff, %i0	! 0xffff
a008f208:  b4 10 3f ff  mov  -1, %i2
a008f20c:  b2 10 20 02  mov  2, %i1
a008f210:  82 06 bf ff  add  %i2, -1, %g1
a008f214:  bb 28 60 10  sll  %g1, 0x10, %i5
a008f218:  b7 37 60 10  srl  %i5, 0x10, %i3
a008f21c:  fa 07 00 00  ld  [ %i4 ], %i5
a008f220:  80 a7 60 01  cmp  %i5, 1
a008f224:  02 80 00 03  be  0xa008f230
a008f228:  b4 10 00 01  mov  %g1, %i2
a008f22c:  f2 27 00 00  st  %i1, [ %i4 ]
a008f230:  c2 07 00 00  ld  [ %i4 ], %g1
a008f234:  80 a0 60 02  cmp  %g1, 2
a008f238:  02 80 00 04  be  0xa008f248
a008f23c:  80 a6 c0 18  cmp  %i3, %i0
a008f240:  12 bf ff f5  bne  0xa008f214
a008f244:  82 06 bf ff  add  %i2, -1, %g1
a008f248:  82 10 20 02  mov  2, %g1
a008f24c:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a008f250:  c2 27 00 00  st  %g1, [ %i4 ]
a008f254:  ba 17 62 00  or  %i5, 0x200, %i5
a008f258:  c2 07 40 00  ld  [ %i5 ], %g1
a008f25c:  82 08 7f cf  and  %g1, -49, %g1
a008f260:  c2 27 40 00  st  %g1, [ %i5 ]
a008f264:  c0 27 00 00  clr  [ %i4 ]
a008f268:  81 c7 e0 08  ret
a008f26c:  81 e8 00 00  restore
