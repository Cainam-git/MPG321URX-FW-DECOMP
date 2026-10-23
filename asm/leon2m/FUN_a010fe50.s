# leon2m FUN_a010fe50 0xa010fe50-0xa0110084 (564 bytes)
a010fe50:  90 0a 20 ff  and  %o0, 0xff, %o0
a010fe54:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010fe58:  80 a2 20 01  cmp  %o0, 1
a010fe5c:  02 80 00 64  be  0xa010ffec
a010fe60:  96 10 63 04  or  %g1, 0x304, %o3
a010fe64:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a010fe68:  da 03 22 a4  ld  [ %o4 + 0x2a4 ], %o5	! 0xa802d6a4
a010fe6c:  c2 13 60 08  lduh  [ %o5 + 8 ], %g1
a010fe70:  99 30 60 01  srl  %g1, 1, %o4
a010fe74:  da 12 e0 14  lduh  [ %o3 + 0x14 ], %o5
a010fe78:  80 a3 40 0c  cmp  %o5, %o4
a010fe7c:  2a 80 00 1e  bcs,a   0xa010fef4
a010fe80:  c2 12 e0 16  lduh  [ %o3 + 0x16 ], %g1
a010fe84:  80 a2 20 01  cmp  %o0, 1
a010fe88:  02 80 00 5c  be  0xa010fff8
a010fe8c:  03 34 00 c8  sethi  %hi(0xd0032000), %g1
a010fe90:  d8 00 40 00  ld  [ %g1 ], %o4
a010fe94:  9a 0b 3f fd  and  %o4, -3, %o5
a010fe98:  da 20 40 00  st  %o5, [ %g1 ]
a010fe9c:  82 10 62 70  or  %g1, 0x270, %g1
a010fea0:  d6 00 40 00  ld  [ %g1 ], %o3
a010fea4:  9a 12 e0 01  or  %o3, 1, %o5
a010fea8:  da 20 40 00  st  %o5, [ %g1 ]
a010feac:  19 34 00 e8  sethi  %hi(0xd003a000), %o4
a010feb0:  da 03 00 00  ld  [ %o4 ], %o5
a010feb4:  03 38 00 00  sethi  %hi(0xe0000000), %g1
a010feb8:  96 2b 40 01  andn  %o5, %g1, %o3
a010febc:  d6 23 00 00  st  %o3, [ %o4 ]
a010fec0:  80 a2 20 01  cmp  %o0, 1
a010fec4:  02 80 00 28  be  0xa010ff64
a010fec8:  11 04 00 00  sethi  %hi(0x10000000), %o0
a010fecc:  17 04 00 00  sethi  %hi(0x10000000), %o3
a010fed0:  d0 03 00 00  ld  [ %o4 ], %o0
a010fed4:  82 12 e0 02  or  %o3, 2, %g1
a010fed8:  9a 12 00 01  or  %o0, %g1, %o5
a010fedc:  da 23 00 00  st  %o5, [ %o4 ]
a010fee0:  98 13 22 70  or  %o4, 0x270, %o4
a010fee4:  d6 03 00 00  ld  [ %o4 ], %o3
a010fee8:  82 0a ff fe  and  %o3, -2, %g1
a010feec:  c2 23 00 00  st  %g1, [ %o4 ]
a010fef0:  30 80 00 63  b,a   0xa011007c
a010fef4:  96 03 40 01  add  %o5, %g1, %o3
a010fef8:  80 a2 c0 0c  cmp  %o3, %o4
a010fefc:  04 80 00 22  ble  0xa010ff84
a010ff00:  19 34 00 c8  sethi  %hi(0xd0032000), %o4
a010ff04:  da 03 00 00  ld  [ %o4 ], %o5
a010ff08:  03 38 00 00  sethi  %hi(0xe0000000), %g1
a010ff0c:  96 2b 40 01  andn  %o5, %g1, %o3
a010ff10:  d6 23 00 00  st  %o3, [ %o4 ]
a010ff14:  80 a2 20 01  cmp  %o0, 1
a010ff18:  02 80 00 47  be  0xa0110034
a010ff1c:  1b 04 00 00  sethi  %hi(0x10000000), %o5
a010ff20:  d6 03 00 00  ld  [ %o4 ], %o3
a010ff24:  82 13 60 02  or  %o5, 2, %g1
a010ff28:  9a 12 c0 01  or  %o3, %g1, %o5
a010ff2c:  da 23 00 00  st  %o5, [ %o4 ]
a010ff30:  98 13 22 70  or  %o4, 0x270, %o4
a010ff34:  d6 03 00 00  ld  [ %o4 ], %o3
a010ff38:  82 0a ff fe  and  %o3, -2, %g1
a010ff3c:  c2 23 00 00  st  %g1, [ %o4 ]
a010ff40:  19 34 00 e8  sethi  %hi(0xd003a000), %o4
a010ff44:  da 03 00 00  ld  [ %o4 ], %o5
a010ff48:  03 38 00 00  sethi  %hi(0xe0000000), %g1
a010ff4c:  96 2b 40 01  andn  %o5, %g1, %o3
a010ff50:  d6 23 00 00  st  %o3, [ %o4 ]
a010ff54:  80 a2 20 01  cmp  %o0, 1
a010ff58:  12 bf ff de  bne  0xa010fed0
a010ff5c:  17 04 00 00  sethi  %hi(0x10000000), %o3
a010ff60:  11 04 00 00  sethi  %hi(0x10000000), %o0
a010ff64:  da 03 00 00  ld  [ %o4 ], %o5
a010ff68:  82 12 20 04  or  %o0, 4, %g1
a010ff6c:  96 13 40 01  or  %o5, %g1, %o3
a010ff70:  d6 23 00 00  st  %o3, [ %o4 ]
a010ff74:  98 13 22 70  or  %o4, 0x270, %o4
a010ff78:  d0 03 00 00  ld  [ %o4 ], %o0
a010ff7c:  10 bf ff dc  b  0xa010feec
a010ff80:  82 0a 3f fd  and  %o0, -3, %g1
a010ff84:  da 03 00 00  ld  [ %o4 ], %o5
a010ff88:  17 38 00 00  sethi  %hi(0xe0000000), %o3
a010ff8c:  82 2b 40 0b  andn  %o5, %o3, %g1
a010ff90:  c2 23 00 00  st  %g1, [ %o4 ]
a010ff94:  80 a2 20 01  cmp  %o0, 1
a010ff98:  02 80 00 1f  be  0xa0110014
a010ff9c:  17 04 00 00  sethi  %hi(0x10000000), %o3
a010ffa0:  da 03 00 00  ld  [ %o4 ], %o5
a010ffa4:  82 12 e0 02  or  %o3, 2, %g1
a010ffa8:  96 13 40 01  or  %o5, %g1, %o3
a010ffac:  d6 23 00 00  st  %o3, [ %o4 ]
a010ffb0:  98 13 22 70  or  %o4, 0x270, %o4
a010ffb4:  da 03 00 00  ld  [ %o4 ], %o5
a010ffb8:  82 0b 7f fe  and  %o5, -2, %g1
a010ffbc:  c2 23 00 00  st  %g1, [ %o4 ]
a010ffc0:  80 a2 20 01  cmp  %o0, 1
a010ffc4:  02 80 00 26  be  0xa011005c
a010ffc8:  19 34 00 e8  sethi  %hi(0xd003a000), %o4
a010ffcc:  da 03 00 00  ld  [ %o4 ], %o5
a010ffd0:  90 0b 7f fd  and  %o5, -3, %o0
a010ffd4:  d0 23 00 00  st  %o0, [ %o4 ]
a010ffd8:  82 13 22 70  or  %o4, 0x270, %g1
a010ffdc:  d6 00 40 00  ld  [ %g1 ], %o3
a010ffe0:  9a 12 e0 01  or  %o3, 1, %o5
a010ffe4:  da 20 40 00  st  %o5, [ %g1 ]
a010ffe8:  30 80 00 25  b,a   0xa011007c
a010ffec:  19 2a 00 b6  sethi  %hi(0xa802d800), %o4
a010fff0:  10 bf ff 9d  b  0xa010fe64
a010fff4:  96 13 20 04  or  %o4, 4, %o3	! 0xa802d804
a010fff8:  d8 00 40 00  ld  [ %g1 ], %o4
a010fffc:  9a 0b 3f fb  and  %o4, -5, %o5
a0110000:  da 20 40 00  st  %o5, [ %g1 ]
a0110004:  82 10 62 70  or  %g1, 0x270, %g1
a0110008:  d6 00 40 00  ld  [ %g1 ], %o3
a011000c:  10 bf ff a7  b  0xa010fea8
a0110010:  9a 12 e0 02  or  %o3, 2, %o5
a0110014:  da 03 00 00  ld  [ %o4 ], %o5
a0110018:  82 12 e0 04  or  %o3, 4, %g1
a011001c:  96 13 40 01  or  %o5, %g1, %o3
a0110020:  d6 23 00 00  st  %o3, [ %o4 ]
a0110024:  98 13 22 70  or  %o4, 0x270, %o4
a0110028:  c2 03 00 00  ld  [ %o4 ], %g1
a011002c:  10 bf ff e4  b  0xa010ffbc
a0110030:  82 08 7f fd  and  %g1, -3, %g1
a0110034:  d6 03 00 00  ld  [ %o4 ], %o3
a0110038:  82 13 60 04  or  %o5, 4, %g1
a011003c:  9a 12 c0 01  or  %o3, %g1, %o5
a0110040:  da 23 00 00  st  %o5, [ %o4 ]
a0110044:  98 13 22 70  or  %o4, 0x270, %o4
a0110048:  d6 03 00 00  ld  [ %o4 ], %o3
a011004c:  82 0a ff fd  and  %o3, -3, %g1
a0110050:  c2 23 00 00  st  %g1, [ %o4 ]
a0110054:  10 bf ff bc  b  0xa010ff44
a0110058:  19 34 00 e8  sethi  %hi(0xd003a000), %o4
a011005c:  11 34 00 e8  sethi  %hi(0xd003a000), %o0
a0110060:  c2 02 00 00  ld  [ %o0 ], %g1
a0110064:  9a 08 7f fb  and  %g1, -5, %o5
a0110068:  da 22 00 00  st  %o5, [ %o0 ]
a011006c:  82 12 22 70  or  %o0, 0x270, %g1
a0110070:  d8 00 40 00  ld  [ %g1 ], %o4
a0110074:  9a 13 20 02  or  %o4, 2, %o5
a0110078:  da 20 40 00  st  %o5, [ %g1 ]
a011007c:  81 c3 e0 08  retl
a0110080:  01 00 00 00  nop
