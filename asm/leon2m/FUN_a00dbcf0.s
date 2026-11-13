# leon2m FUN_a00dbcf0 0xa00dbcf0-0xa00dc2dc (1448 bytes)
a00dbcf0:  9d e3 bf 98  save  %sp, -104, %sp
a00dbcf4:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00dbcf8:  a0 14 a2 90  or  %l2, 0x290, %l0	! 0xa802d290
a00dbcfc:  90 10 20 00  clr  %o0
a00dbd00:  7f ff f1 00  call  0xa00d8100
a00dbd04:  e6 0c 20 b3  ldub  [ %l0 + 0xb3 ], %l3
a00dbd08:  7f ff f0 fe  call  0xa00d8100
a00dbd0c:  90 10 20 01  mov  1, %o0
a00dbd10:  c2 0c 20 1f  ldub  [ %l0 + 0x1f ], %g1
a00dbd14:  80 a0 60 00  cmp  %g1, 0
a00dbd18:  02 80 00 fc  be  0xa00dc108
a00dbd1c:  01 00 00 00  nop
a00dbd20:  7f ff f0 f8  call  0xa00d8100
a00dbd24:  90 10 20 03  mov  3, %o0	! 0x3
a00dbd28:  7f ff f0 f6  call  0xa00d8100
a00dbd2c:  90 10 20 05  mov  5, %o0
a00dbd30:  7f ff f0 f4  call  0xa00d8100
a00dbd34:  90 10 20 06  mov  6, %o0
a00dbd38:  7f ff f0 f2  call  0xa00d8100
a00dbd3c:  90 10 20 07  mov  7, %o0
a00dbd40:  7f ff f0 f0  call  0xa00d8100
a00dbd44:  90 10 20 08  mov  8, %o0
a00dbd48:  11 00 06 62  sethi  %hi(0x198800), %o0
a00dbd4c:  d2 0c 21 82  ldub  [ %l0 + 0x182 ], %o1
a00dbd50:  40 00 0d 08  call  0xa00df170
a00dbd54:  90 12 22 48  or  %o0, 0x248, %o0
a00dbd58:  67 fe c9 53  call  0x4008e2a4
a00dbd5c:  01 00 00 00  nop
a00dbd60:  c2 0c 21 82  ldub  [ %l0 + 0x182 ], %g1
a00dbd64:  80 a0 60 05  cmp  %g1, 5
a00dbd68:  18 80 00 09  bgu  0xa00dbd8c
a00dbd6c:  15 00 01 ce  sethi  %hi(0x73800), %o2
a00dbd70:  93 28 60 02  sll  %g1, 2, %o1
a00dbd74:  9a 12 a3 9c  or  %o2, 0x39c, %o5
a00dbd78:  d8 03 40 09  ld  [ %o5 + %o1 ], %o4
a00dbd7c:  81 c3 00 00  jmp  %o4
a00dbd80:  01 00 00 00  nop
a00dbd84:  7f fe af 24  call  0xa0087a14
a00dbd88:  90 10 20 00  clr  %o0	! 0x0
a00dbd8c:  7f ff ef 8d  call  0xa00d7bc0
a00dbd90:  01 00 00 00  nop
a00dbd94:  7f ff f6 74  call  0xa00d9764
a00dbd98:  01 00 00 00  nop
a00dbd9c:  9a 14 a2 90  or  %l2, 0x290, %o5
a00dbda0:  d6 03 60 b0  ld  [ %o5 + 0xb0 ], %o3
a00dbda4:  80 a2 e0 00  cmp  %o3, 0
a00dbda8:  12 80 00 06  bne  0xa00dbdc0
a00dbdac:  01 00 00 00  nop
a00dbdb0:  de 03 61 1c  ld  [ %o5 + 0x11c ], %o7
a00dbdb4:  80 a3 e0 00  cmp  %o7, 0
a00dbdb8:  16 80 00 dd  bge  0xa00dc12c
a00dbdbc:  01 00 00 00  nop
a00dbdc0:  7f ff f0 08  call  0xa00d7de0
a00dbdc4:  01 00 00 00  nop
a00dbdc8:  7f ff f4 d6  call  0xa00d9120
a00dbdcc:  01 00 00 00  nop
a00dbdd0:  40 01 bf e8  call  0xa014bd70
a00dbdd4:  90 10 20 00  clr  %o0	! 0x0
a00dbdd8:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00dbddc:  80 a4 20 01  cmp  %l0, 1
a00dbde0:  02 80 00 0d  be  0xa00dbe14
a00dbde4:  90 10 20 00  clr  %o0
a00dbde8:  40 01 9e bd  call  0xa01438dc
a00dbdec:  90 10 20 00  clr  %o0
a00dbdf0:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00dbdf4:  80 a4 60 01  cmp  %l1, 1
a00dbdf8:  02 80 00 82  be  0xa00dc000
a00dbdfc:  90 14 a2 90  or  %l2, 0x290, %o0
a00dbe00:  d8 02 21 74  ld  [ %o0 + 0x174 ], %o4
a00dbe04:  03 00 00 20  sethi  %hi(0x8000), %g1
a00dbe08:  80 8b 00 01  btst  %o4, %g1
a00dbe0c:  02 80 00 8a  be  0xa00dc034
a00dbe10:  90 10 20 01  mov  1, %o0
a00dbe14:  40 01 ca 99  call  0xa014e878
a00dbe18:  a0 14 a2 90  or  %l2, 0x290, %l0
a00dbe1c:  7f ff f4 c1  call  0xa00d9120
a00dbe20:  01 00 00 00  nop
a00dbe24:  da 14 20 34  lduh  [ %l0 + 0x34 ], %o5
a00dbe28:  92 0b 60 0f  and  %o5, 0xf, %o1
a00dbe2c:  40 01 b4 8e  call  0xa0149064
a00dbe30:  90 10 20 00  clr  %o0
a00dbe34:  d2 14 20 34  lduh  [ %l0 + 0x34 ], %o1
a00dbe38:  92 0a 60 0f  and  %o1, 0xf, %o1
a00dbe3c:  40 01 b4 8a  call  0xa0149064
a00dbe40:  90 10 20 01  mov  1, %o0
a00dbe44:  da 0c 20 49  ldub  [ %l0 + 0x49 ], %o5
a00dbe48:  80 a3 60 05  cmp  %o5, 5
a00dbe4c:  38 80 00 02  bgu,a   0xa00dbe54
a00dbe50:  9a 10 20 05  mov  5, %o5
a00dbe54:  a2 0b 60 ff  and  %o5, 0xff, %l1
a00dbe58:  9e 04 40 11  add  %l1, %l1, %o7
a00dbe5c:  96 03 c0 11  add  %o7, %l1, %o3
a00dbe60:  94 0a e0 ff  and  %o3, 0xff, %o2
a00dbe64:  da 2c 20 49  stb  %o5, [ %l0 + 0x49 ]
a00dbe68:  90 10 20 00  clr  %o0
a00dbe6c:  40 01 ac cd  call  0xa01471a0
a00dbe70:  92 10 20 0d  mov  0xd, %o1
a00dbe74:  d4 0c 20 1f  ldub  [ %l0 + 0x1f ], %o2
a00dbe78:  80 a2 a0 00  cmp  %o2, 0
a00dbe7c:  12 80 00 30  bne  0xa00dbf3c
a00dbe80:  9e 14 a2 90  or  %l2, 0x290, %o7
a00dbe84:  c2 04 20 b0  ld  [ %l0 + 0xb0 ], %g1
a00dbe88:  80 a0 60 00  cmp  %g1, 0
a00dbe8c:  12 80 00 d1  bne  0xa00dc1d0
a00dbe90:  e2 0c 20 19  ldub  [ %l0 + 0x19 ], %l1
a00dbe94:  82 0c 60 ff  and  %l1, 0xff, %g1
a00dbe98:  80 a0 60 03  cmp  %g1, 3
a00dbe9c:  08 80 00 05  bleu  0xa00dbeb0
a00dbea0:  80 a0 60 00  cmp  %g1, 0
a00dbea4:  a2 10 20 03  mov  3, %l1
a00dbea8:  82 10 20 03  mov  3, %g1
a00dbeac:  80 a0 60 00  cmp  %g1, 0
a00dbeb0:  02 80 00 9d  be  0xa00dc124
a00dbeb4:  e2 2c 20 8f  stb  %l1, [ %l0 + 0x8f ]
a00dbeb8:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00dbebc:  40 01 b4 a0  call  0xa014913c
a00dbec0:  90 10 20 05  mov  5, %o0
a00dbec4:  a0 14 a2 90  or  %l2, 0x290, %l0
a00dbec8:  de 0c 20 8f  ldub  [ %l0 + 0x8f ], %o7
a00dbecc:  de 2c 20 19  stb  %o7, [ %l0 + 0x19 ]
a00dbed0:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00dbed4:  82 14 a2 90  or  %l2, 0x290, %g1
a00dbed8:  e6 00 60 b0  ld  [ %g1 + 0xb0 ], %l3
a00dbedc:  80 a4 40 13  cmp  %l1, %l3
a00dbee0:  02 80 00 17  be  0xa00dbf3c
a00dbee4:  9e 14 a2 90  or  %l2, 0x290, %o7
a00dbee8:  40 01 bf a2  call  0xa014bd70
a00dbeec:  90 10 20 00  clr  %o0
a00dbef0:  98 0a 20 ff  and  %o0, 0xff, %o4
a00dbef4:  80 a3 20 01  cmp  %o4, 1
a00dbef8:  02 80 00 11  be  0xa00dbf3c
a00dbefc:  9e 14 a2 90  or  %l2, 0x290, %o7
a00dbf00:  40 01 9e 77  call  0xa01438dc
a00dbf04:  90 10 20 00  clr  %o0
a00dbf08:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dbf0c:  80 a2 20 01  cmp  %o0, 1
a00dbf10:  02 80 00 d8  be  0xa00dc270
a00dbf14:  9a 14 a2 90  or  %l2, 0x290, %o5
a00dbf18:  d2 0b 60 4a  ldub  [ %o5 + 0x4a ], %o1
a00dbf1c:  80 a2 60 00  cmp  %o1, 0
a00dbf20:  02 80 00 07  be  0xa00dbf3c
a00dbf24:  9e 14 a2 90  or  %l2, 0x290, %o7
a00dbf28:  d4 03 60 b0  ld  [ %o5 + 0xb0 ], %o2
a00dbf2c:  80 a2 a0 00  cmp  %o2, 0
a00dbf30:  32 80 00 bd  bne,a   0xa00dc224
a00dbf34:  d6 0b 60 1f  ldub  [ %o5 + 0x1f ], %o3
a00dbf38:  9e 14 a2 90  or  %l2, 0x290, %o7
a00dbf3c:  d8 03 e1 1c  ld  [ %o7 + 0x11c ], %o4
a00dbf40:  a1 33 20 1f  srl  %o4, 0x1f, %l0
a00dbf44:  94 0c 20 ff  and  %l0, 0xff, %o2
a00dbf48:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00dbf4c:  a2 2b 00 01  andn  %o4, %g1, %l1
a00dbf50:  9b 2a a0 1f  sll  %o2, 0x1f, %o5
a00dbf54:  a6 14 40 0d  or  %l1, %o5, %l3
a00dbf58:  80 a2 a0 01  cmp  %o2, 1
a00dbf5c:  02 80 00 70  be  0xa00dc11c
a00dbf60:  e6 23 e1 1c  st  %l3, [ %o7 + 0x11c ]
a00dbf64:  80 a2 a0 01  cmp  %o2, 1
a00dbf68:  04 80 00 ab  ble  0xa00dc214
a00dbf6c:  80 a2 a0 02  cmp  %o2, 2
a00dbf70:  22 80 00 02  be,a   0xa00dbf78
a00dbf74:  a0 10 20 02  mov  2, %l0
a00dbf78:  40 01 bf 7e  call  0xa014bd70
a00dbf7c:  90 10 20 00  clr  %o0
a00dbf80:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dbf84:  80 a2 20 01  cmp  %o0, 1
a00dbf88:  22 80 00 3b  be,a   0xa00dc074
a00dbf8c:  a0 10 20 00  clr  %l0
a00dbf90:  40 01 9e 53  call  0xa01438dc
a00dbf94:  90 10 20 00  clr  %o0
a00dbf98:  92 0a 20 ff  and  %o0, 0xff, %o1
a00dbf9c:  80 a2 60 01  cmp  %o1, 1
a00dbfa0:  02 80 00 27  be  0xa00dc03c
a00dbfa4:  01 00 00 00  nop
a00dbfa8:  40 01 b4 c4  call  0xa01492b8
a00dbfac:  90 0c 20 03  and  %l0, 3, %o0
a00dbfb0:  a0 14 a2 90  or  %l2, 0x290, %l0
a00dbfb4:  d4 04 21 1c  ld  [ %l0 + 0x11c ], %o2
a00dbfb8:  80 a2 a0 00  cmp  %o2, 0
a00dbfbc:  16 80 00 35  bge  0xa00dc090
a00dbfc0:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a00dbfc4:  d6 13 e3 fe  lduh  [ %o7 + 0x3fe ], %o3	! 0xa802cffe
a00dbfc8:  80 8a e0 80  btst  0x80, %o3
a00dbfcc:  02 80 00 38  be  0xa00dc0ac
a00dbfd0:  01 00 00 00  nop
a00dbfd4:  d8 04 20 a8  ld  [ %l0 + 0xa8 ], %o4
a00dbfd8:  91 33 20 01  srl  %o4, 1, %o0
a00dbfdc:  82 0a 24 00  and  %o0, 0x400, %g1
a00dbfe0:  9a 0b 3b ff  and  %o4, -1025, %o5
a00dbfe4:  a6 13 40 01  or  %o5, %g1, %l3
a00dbfe8:  e4 0c 21 82  ldub  [ %l0 + 0x182 ], %l2
a00dbfec:  e2 0c 21 81  ldub  [ %l0 + 0x181 ], %l1
a00dbff0:  e2 2c 21 83  stb  %l1, [ %l0 + 0x183 ]
a00dbff4:  e6 24 20 a8  st  %l3, [ %l0 + 0xa8 ]
a00dbff8:  10 80 00 b7  b  0xa00dc2d4
a00dbffc:  e4 2c 21 84  stb  %l2, [ %l0 + 0x184 ]
a00dc000:  40 01 be 9a  call  0xa014ba68
a00dc004:  01 00 00 00  nop
a00dc008:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dc00c:  80 a2 20 02  cmp  %o0, 2
a00dc010:  22 bf ff 81  be,a   0xa00dbe14
a00dc014:  90 10 20 00  clr  %o0
a00dc018:  04 80 00 92  ble  0xa00dc260
a00dc01c:  80 a2 20 01  cmp  %o0, 1
a00dc020:  80 a2 20 03  cmp  %o0, 3
a00dc024:  02 80 00 04  be  0xa00dc034
a00dc028:  80 a2 20 04  cmp  %o0, 4
a00dc02c:  32 bf ff 75  bne,a   0xa00dbe00
a00dc030:  90 14 a2 90  or  %l2, 0x290, %o0
a00dc034:  10 bf ff 78  b  0xa00dbe14
a00dc038:  90 10 20 00  clr  %o0
a00dc03c:  40 01 be 8b  call  0xa014ba68
a00dc040:  01 00 00 00  nop
a00dc044:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dc048:  80 a2 20 02  cmp  %o0, 2
a00dc04c:  22 80 00 0a  be,a   0xa00dc074
a00dc050:  a0 10 20 00  clr  %l0
a00dc054:  04 80 00 7f  ble  0xa00dc250
a00dc058:  80 a2 20 01  cmp  %o0, 1
a00dc05c:  80 a2 20 03  cmp  %o0, 3
a00dc060:  02 80 00 04  be  0xa00dc070
a00dc064:  80 a2 20 04  cmp  %o0, 4
a00dc068:  12 bf ff d0  bne  0xa00dbfa8
a00dc06c:  01 00 00 00  nop
a00dc070:  a0 10 20 00  clr  %l0	! 0x0
a00dc074:  40 01 b4 91  call  0xa01492b8
a00dc078:  90 0c 20 03  and  %l0, 3, %o0
a00dc07c:  a0 14 a2 90  or  %l2, 0x290, %l0
a00dc080:  d4 04 21 1c  ld  [ %l0 + 0x11c ], %o2
a00dc084:  80 a2 a0 00  cmp  %o2, 0
a00dc088:  06 bf ff cf  bl  0xa00dbfc4
a00dc08c:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a00dc090:  7f ff f3 11  call  0xa00d8cd4
a00dc094:  01 00 00 00  nop
a00dc098:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a00dc09c:  d6 13 e3 fe  lduh  [ %o7 + 0x3fe ], %o3	! 0xa802cffe
a00dc0a0:  80 8a e0 80  btst  0x80, %o3
a00dc0a4:  32 bf ff cd  bne,a   0xa00dbfd8
a00dc0a8:  d8 04 20 a8  ld  [ %l0 + 0xa8 ], %o4
a00dc0ac:  40 01 bf 31  call  0xa014bd70
a00dc0b0:  90 10 20 00  clr  %o0
a00dc0b4:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00dc0b8:  80 a4 20 01  cmp  %l0, 1
a00dc0bc:  02 80 00 2b  be  0xa00dc168
a00dc0c0:  94 14 a2 90  or  %l2, 0x290, %o2
a00dc0c4:  40 01 9e 06  call  0xa01438dc
a00dc0c8:  90 10 20 00  clr  %o0
a00dc0cc:  92 0a 20 ff  and  %o0, 0xff, %o1
a00dc0d0:  80 a2 60 01  cmp  %o1, 1
a00dc0d4:  02 80 00 19  be  0xa00dc138
a00dc0d8:  98 14 a2 90  or  %l2, 0x290, %o4
a00dc0dc:  de 03 20 a8  ld  [ %o4 + 0xa8 ], %o7
a00dc0e0:  a5 33 e0 02  srl  %o7, 2, %l2
a00dc0e4:  96 0c a2 00  and  %l2, 0x200, %o3
a00dc0e8:  94 0b fd ff  and  %o7, -513, %o2
a00dc0ec:  a0 12 80 0b  or  %o2, %o3, %l0
a00dc0f0:  d0 0b 21 82  ldub  [ %o4 + 0x182 ], %o0
a00dc0f4:  d2 0b 21 81  ldub  [ %o4 + 0x181 ], %o1
a00dc0f8:  d2 2b 21 85  stb  %o1, [ %o4 + 0x185 ]
a00dc0fc:  e0 23 20 a8  st  %l0, [ %o4 + 0xa8 ]
a00dc100:  10 80 00 75  b  0xa00dc2d4
a00dc104:  d0 2b 21 86  stb  %o0, [ %o4 + 0x186 ]
a00dc108:  7f ff ef fe  call  0xa00d8100
a00dc10c:  90 10 20 02  mov  2, %o0
a00dc110:  7f ff ef fc  call  0xa00d8100
a00dc114:  90 10 20 04  mov  4, %o0
a00dc118:  30 bf ff 02  b,a   0xa00dbd20
a00dc11c:  10 bf ff 97  b  0xa00dbf78
a00dc120:  a0 10 20 01  mov  1, %l0
a00dc124:  10 bf ff 66  b  0xa00dbebc
a00dc128:  e2 2c 20 19  stb  %l1, [ %l0 + 0x19 ]
a00dc12c:  7f ff f2 ea  call  0xa00d8cd4
a00dc130:  01 00 00 00  nop
a00dc134:  30 bf ff 23  b,a   0xa00dbdc0
a00dc138:  40 01 be 4c  call  0xa014ba68
a00dc13c:  01 00 00 00  nop
a00dc140:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dc144:  80 a2 20 02  cmp  %o0, 2
a00dc148:  02 80 00 08  be  0xa00dc168
a00dc14c:  94 14 a2 90  or  %l2, 0x290, %o2
a00dc150:  14 80 00 55  bg  0xa00dc2a4
a00dc154:  80 a2 20 03  cmp  %o0, 3
a00dc158:  80 a2 20 01  cmp  %o0, 1
a00dc15c:  12 bf ff e0  bne  0xa00dc0dc
a00dc160:  98 14 a2 90  or  %l2, 0x290, %o4
a00dc164:  94 14 a2 90  or  %l2, 0x290, %o2
a00dc168:  da 02 a0 a8  ld  [ %o2 + 0xa8 ], %o5
a00dc16c:  83 33 60 03  srl  %o5, 3, %g1
a00dc170:  a2 08 61 00  and  %g1, 0x100, %l1
a00dc174:  a6 0b 7e ff  and  %o5, -257, %l3
a00dc178:  9e 14 c0 11  or  %l3, %l1, %o7
a00dc17c:  d6 0a a1 82  ldub  [ %o2 + 0x182 ], %o3
a00dc180:  e4 0a a1 81  ldub  [ %o2 + 0x181 ], %l2
a00dc184:  e4 2a a1 87  stb  %l2, [ %o2 + 0x187 ]
a00dc188:  de 22 a0 a8  st  %o7, [ %o2 + 0xa8 ]
a00dc18c:  10 80 00 52  b  0xa00dc2d4
a00dc190:  d6 2a a1 88  stb  %o3, [ %o2 + 0x188 ]
a00dc194:  7f fe ae 20  call  0xa0087a14
a00dc198:  90 10 20 01  mov  1, %o0
a00dc19c:  30 bf fe fc  b,a   0xa00dbd8c
a00dc1a0:  7f fe ae 1d  call  0xa0087a14
a00dc1a4:  90 10 20 02  mov  2, %o0
a00dc1a8:  30 bf fe f9  b,a   0xa00dbd8c
a00dc1ac:  7f fe ae 1a  call  0xa0087a14
a00dc1b0:  90 10 20 03  mov  3, %o0
a00dc1b4:  30 bf fe f6  b,a   0xa00dbd8c
a00dc1b8:  7f fe ae 17  call  0xa0087a14
a00dc1bc:  90 10 20 04  mov  4, %o0
a00dc1c0:  30 bf fe f3  b,a   0xa00dbd8c
a00dc1c4:  7f fe ae 14  call  0xa0087a14
a00dc1c8:  90 10 20 05  mov  5, %o0
a00dc1cc:  30 bf fe f0  b,a   0xa00dbd8c
a00dc1d0:  92 10 20 01  mov  1, %o1
a00dc1d4:  40 01 a5 23  call  0xa0145660
a00dc1d8:  90 10 20 00  clr  %o0
a00dc1dc:  97 2a 20 10  sll  %o0, 0x10, %o3
a00dc1e0:  15 33 33 33  sethi  %hi(0xcccccc00), %o2
a00dc1e4:  93 32 e0 10  srl  %o3, 0x10, %o1
a00dc1e8:  9a 12 a0 cd  or  %o2, 0xcd, %o5
a00dc1ec:  80 52 40 0d  umul  %o1, %o5, %g0
a00dc1f0:  91 40 00 00  rd  %y, %o0
a00dc1f4:  99 2a 20 0d  sll  %o0, 0xd, %o4
a00dc1f8:  7f fe ac 98  call  0xa0087458
a00dc1fc:  91 33 20 10  srl  %o4, 0x10, %o0
a00dc200:  80 a2 20 00  cmp  %o0, 0
a00dc204:  02 bf ff 25  be  0xa00dbe98
a00dc208:  82 0c 60 ff  and  %l1, 0xff, %g1
a00dc20c:  10 bf ff 32  b  0xa00dbed4
a00dc210:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00dc214:  80 a2 a0 00  cmp  %o2, 0
a00dc218:  22 bf ff 58  be,a   0xa00dbf78
a00dc21c:  a0 10 20 00  clr  %l0
a00dc220:  30 bf ff 56  b,a   0xa00dbf78
a00dc224:  80 a2 e0 00  cmp  %o3, 0
a00dc228:  12 bf ff 44  bne  0xa00dbf38
a00dc22c:  c0 2b 60 4a  clrb  [ %o5 + 0x4a ]
a00dc230:  90 10 20 01  mov  1, %o0
a00dc234:  40 01 c4 90  call  0xa014d474
a00dc238:  92 10 20 00  clr  %o1
a00dc23c:  90 10 20 01  mov  1, %o0
a00dc240:  40 01 c6 d6  call  0xa014dd98
a00dc244:  92 10 20 00  clr  %o1
a00dc248:  10 bf ff 3d  b  0xa00dbf3c
a00dc24c:  9e 14 a2 90  or  %l2, 0x290, %o7
a00dc250:  12 bf ff 56  bne  0xa00dbfa8
a00dc254:  01 00 00 00  nop
a00dc258:  10 bf ff 87  b  0xa00dc074
a00dc25c:  a0 10 20 00  clr  %l0	! 0x0
a00dc260:  32 bf fe e8  bne,a   0xa00dbe00
a00dc264:  90 14 a2 90  or  %l2, 0x290, %o0
a00dc268:  10 bf fe eb  b  0xa00dbe14
a00dc26c:  90 10 20 00  clr  %o0
a00dc270:  40 01 bd fe  call  0xa014ba68
a00dc274:  01 00 00 00  nop
a00dc278:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dc27c:  80 a2 20 02  cmp  %o0, 2
a00dc280:  02 bf ff 2f  be  0xa00dbf3c
a00dc284:  9e 14 a2 90  or  %l2, 0x290, %o7
a00dc288:  14 80 00 0d  bg  0xa00dc2bc
a00dc28c:  80 a2 20 03  cmp  %o0, 3
a00dc290:  80 a2 20 01  cmp  %o0, 1
a00dc294:  12 bf ff 21  bne  0xa00dbf18
a00dc298:  9a 14 a2 90  or  %l2, 0x290, %o5
a00dc29c:  10 bf ff 29  b  0xa00dbf40
a00dc2a0:  d8 03 e1 1c  ld  [ %o7 + 0x11c ], %o4
a00dc2a4:  02 bf ff b0  be  0xa00dc164
a00dc2a8:  80 a2 20 04  cmp  %o0, 4
a00dc2ac:  12 bf ff 8c  bne  0xa00dc0dc
a00dc2b0:  98 14 a2 90  or  %l2, 0x290, %o4
a00dc2b4:  10 bf ff ad  b  0xa00dc168
a00dc2b8:  94 14 a2 90  or  %l2, 0x290, %o2
a00dc2bc:  02 bf ff 1f  be  0xa00dbf38
a00dc2c0:  80 a2 20 04  cmp  %o0, 4
a00dc2c4:  12 bf ff 15  bne  0xa00dbf18
a00dc2c8:  9a 14 a2 90  or  %l2, 0x290, %o5
a00dc2cc:  10 bf ff 1c  b  0xa00dbf3c
a00dc2d0:  9e 14 a2 90  or  %l2, 0x290, %o7
a00dc2d4:  81 c7 e0 08  ret
a00dc2d8:  81 e8 00 00  restore
