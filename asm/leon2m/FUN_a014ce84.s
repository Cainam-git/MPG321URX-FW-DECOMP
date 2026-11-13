# leon2m FUN_a014ce84 0xa014ce84-0xa014d3d4 (44 bytes)
a014ce84:  82 02 3f fa  add  %o0, -6, %g1
a014ce88:  80 a0 60 1d  cmp  %g1, 0x1d
a014ce8c:  18 80 01 50  bgu  0xa014d3cc
a014ce90:  11 00 03 8d  sethi  %hi(0xe3400), %o0
a014ce94:  83 28 60 02  sll  %g1, 2, %g1
a014ce98:  9a 12 22 28  or  %o0, 0x228, %o5
a014ce9c:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a014cea0:  81 c3 00 00  jmp  %o4
a014cea4:  01 00 00 00  nop
a014cea8:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014ceac:  80 8a a0 ff  btst  0xff, %o2
a014ceb0:  02 80 01 47  be  0xa014d3cc
a014ceb4:  d2 28 62 10  stb  %o1, [ %g1 + 0x210 ]
a014ceb8:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014cebc:  da 0a 23 db  ldub  [ %o0 + 0x3db ], %o5	! 0xa802e3db
a014cec0:  80 a3 60 0b  cmp  %o5, 0xb
a014cec4:  12 80 01 42  bne  0xa014d3cc
a014cec8:  01 00 00 00  nop
a014cecc:  30 80 00 0a  b,a   0xa014cef4
a014ced0:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014ced4:  80 8a a0 ff  btst  0xff, %o2
a014ced8:  02 80 01 3d  be  0xa014d3cc
a014cedc:  d2 2b 22 0f  stb  %o1, [ %o4 + 0x20f ]
a014cee0:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014cee4:  d2 0a a3 db  ldub  [ %o2 + 0x3db ], %o1	! 0xa802e3db
a014cee8:  80 a2 60 0b  cmp  %o1, 0xb
a014ceec:  12 80 01 38  bne  0xa014d3cc
a014cef0:  01 00 00 00  nop
a014cef4:  90 10 20 0b  mov  0xb, %o0	! 0xb
a014cef8:  82 13 c0 00  mov  %o7, %g1
a014cefc:  7f ff fc 87  call  0xa014c118
a014cf00:  9e 10 40 00  mov  %g1, %o7
a014cf04:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014cf08:  80 8a a0 ff  btst  0xff, %o2
a014cf0c:  02 80 01 30  be  0xa014d3cc
a014cf10:  d2 28 62 0e  stb  %o1, [ %g1 + 0x20e ]
a014cf14:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014cf18:  da 0a 23 db  ldub  [ %o0 + 0x3db ], %o5	! 0xa802e3db
a014cf1c:  80 a3 60 0b  cmp  %o5, 0xb
a014cf20:  12 80 01 2b  bne  0xa014d3cc
a014cf24:  01 00 00 00  nop
a014cf28:  30 bf ff f3  b,a   0xa014cef4
a014cf2c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014cf30:  80 8a a0 ff  btst  0xff, %o2
a014cf34:  02 80 01 26  be  0xa014d3cc
a014cf38:  d2 2b 22 0d  stb  %o1, [ %o4 + 0x20d ]
a014cf3c:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014cf40:  d2 0a a3 db  ldub  [ %o2 + 0x3db ], %o1	! 0xa802e3db
a014cf44:  80 a2 60 0a  cmp  %o1, 0xa
a014cf48:  12 80 01 21  bne  0xa014d3cc
a014cf4c:  01 00 00 00  nop
a014cf50:  90 10 20 0a  mov  0xa, %o0	! 0xa
a014cf54:  82 13 c0 00  mov  %o7, %g1
a014cf58:  7f ff fc 70  call  0xa014c118
a014cf5c:  9e 10 40 00  mov  %g1, %o7
a014cf60:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014cf64:  80 8a a0 ff  btst  0xff, %o2
a014cf68:  02 80 01 19  be  0xa014d3cc
a014cf6c:  d2 28 62 0c  stb  %o1, [ %g1 + 0x20c ]
a014cf70:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014cf74:  da 0a 23 db  ldub  [ %o0 + 0x3db ], %o5	! 0xa802e3db
a014cf78:  80 a3 60 0a  cmp  %o5, 0xa
a014cf7c:  12 80 01 14  bne  0xa014d3cc
a014cf80:  01 00 00 00  nop
a014cf84:  30 bf ff f3  b,a   0xa014cf50
a014cf88:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014cf8c:  80 8a a0 ff  btst  0xff, %o2
a014cf90:  02 80 01 0f  be  0xa014d3cc
a014cf94:  d2 2b 22 0b  stb  %o1, [ %o4 + 0x20b ]
a014cf98:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014cf9c:  d2 0a a3 db  ldub  [ %o2 + 0x3db ], %o1	! 0xa802e3db
a014cfa0:  80 a2 60 0a  cmp  %o1, 0xa
a014cfa4:  12 80 01 0a  bne  0xa014d3cc
a014cfa8:  01 00 00 00  nop
a014cfac:  30 bf ff e9  b,a   0xa014cf50
a014cfb0:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014cfb4:  80 8a a0 ff  btst  0xff, %o2
a014cfb8:  02 80 01 05  be  0xa014d3cc
a014cfbc:  d2 28 62 0a  stb  %o1, [ %g1 + 0x20a ]
a014cfc0:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014cfc4:  da 0a 23 db  ldub  [ %o0 + 0x3db ], %o5	! 0xa802e3db
a014cfc8:  80 a3 60 09  cmp  %o5, 9
a014cfcc:  12 80 01 00  bne  0xa014d3cc
a014cfd0:  01 00 00 00  nop
a014cfd4:  90 10 20 09  mov  9, %o0	! 0x9
a014cfd8:  82 13 c0 00  mov  %o7, %g1
a014cfdc:  7f ff fc 4f  call  0xa014c118
a014cfe0:  9e 10 40 00  mov  %g1, %o7
a014cfe4:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014cfe8:  80 8a a0 ff  btst  0xff, %o2
a014cfec:  02 80 00 f8  be  0xa014d3cc
a014cff0:  d2 2b 22 09  stb  %o1, [ %o4 + 0x209 ]
a014cff4:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014cff8:  d2 0a a3 db  ldub  [ %o2 + 0x3db ], %o1	! 0xa802e3db
a014cffc:  80 a2 60 09  cmp  %o1, 9
a014d000:  12 80 00 f3  bne  0xa014d3cc
a014d004:  01 00 00 00  nop
a014d008:  30 bf ff f3  b,a   0xa014cfd4
a014d00c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014d010:  80 8a a0 ff  btst  0xff, %o2
a014d014:  02 80 00 ee  be  0xa014d3cc
a014d018:  d2 28 62 08  stb  %o1, [ %g1 + 0x208 ]
a014d01c:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014d020:  da 0a 23 db  ldub  [ %o0 + 0x3db ], %o5	! 0xa802e3db
a014d024:  80 a3 60 09  cmp  %o5, 9
a014d028:  12 80 00 e9  bne  0xa014d3cc
a014d02c:  01 00 00 00  nop
a014d030:  30 bf ff e9  b,a   0xa014cfd4
a014d034:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014d038:  80 8a a0 ff  btst  0xff, %o2
a014d03c:  02 80 00 e4  be  0xa014d3cc
a014d040:  d2 2b 22 13  stb  %o1, [ %o4 + 0x213 ]
a014d044:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014d048:  d2 0a a3 db  ldub  [ %o2 + 0x3db ], %o1	! 0xa802e3db
a014d04c:  80 a2 60 0f  cmp  %o1, 0xf
a014d050:  12 80 00 df  bne  0xa014d3cc
a014d054:  01 00 00 00  nop
a014d058:  90 10 20 0f  mov  0xf, %o0	! 0xf
a014d05c:  82 13 c0 00  mov  %o7, %g1
a014d060:  7f ff fc 2e  call  0xa014c118
a014d064:  9e 10 40 00  mov  %g1, %o7
a014d068:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014d06c:  80 8a a0 ff  btst  0xff, %o2
a014d070:  02 80 00 d7  be  0xa014d3cc
a014d074:  d2 28 62 12  stb  %o1, [ %g1 + 0x212 ]
a014d078:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014d07c:  da 0a 23 db  ldub  [ %o0 + 0x3db ], %o5	! 0xa802e3db
a014d080:  80 a3 60 0f  cmp  %o5, 0xf
a014d084:  12 80 00 d2  bne  0xa014d3cc
a014d088:  01 00 00 00  nop
a014d08c:  30 bf ff f3  b,a   0xa014d058
a014d090:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014d094:  80 8a a0 ff  btst  0xff, %o2
a014d098:  02 80 00 cd  be  0xa014d3cc
a014d09c:  d2 28 62 07  stb  %o1, [ %g1 + 0x207 ]
a014d0a0:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014d0a4:  da 0a 23 db  ldub  [ %o0 + 0x3db ], %o5	! 0xa802e3db
a014d0a8:  80 a3 60 08  cmp  %o5, 8
a014d0ac:  12 80 00 c8  bne  0xa014d3cc
a014d0b0:  01 00 00 00  nop
a014d0b4:  90 10 20 08  mov  8, %o0	! 0x8
a014d0b8:  82 13 c0 00  mov  %o7, %g1
a014d0bc:  7f ff fc 17  call  0xa014c118
a014d0c0:  9e 10 40 00  mov  %g1, %o7
a014d0c4:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014d0c8:  80 8a a0 ff  btst  0xff, %o2
a014d0cc:  02 80 00 c0  be  0xa014d3cc
a014d0d0:  d2 2b 22 06  stb  %o1, [ %o4 + 0x206 ]
a014d0d4:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014d0d8:  d2 0a a3 db  ldub  [ %o2 + 0x3db ], %o1	! 0xa802e3db
a014d0dc:  80 a2 60 08  cmp  %o1, 8
a014d0e0:  12 80 00 bb  bne  0xa014d3cc
a014d0e4:  01 00 00 00  nop
a014d0e8:  30 bf ff f3  b,a   0xa014d0b4
a014d0ec:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014d0f0:  80 8a a0 ff  btst  0xff, %o2
a014d0f4:  02 80 00 b6  be  0xa014d3cc
a014d0f8:  d2 2b 22 11  stb  %o1, [ %o4 + 0x211 ]
a014d0fc:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014d100:  d2 0a a3 db  ldub  [ %o2 + 0x3db ], %o1	! 0xa802e3db
a014d104:  80 a2 60 0f  cmp  %o1, 0xf
a014d108:  12 80 00 b1  bne  0xa014d3cc
a014d10c:  01 00 00 00  nop
a014d110:  30 bf ff d2  b,a   0xa014d058
a014d114:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014d118:  80 8a a0 ff  btst  0xff, %o2
a014d11c:  02 80 00 ac  be  0xa014d3cc
a014d120:  d2 28 62 05  stb  %o1, [ %g1 + 0x205 ]
a014d124:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014d128:  da 0a 23 db  ldub  [ %o0 + 0x3db ], %o5	! 0xa802e3db
a014d12c:  80 a3 60 08  cmp  %o5, 8
a014d130:  12 80 00 a7  bne  0xa014d3cc
a014d134:  01 00 00 00  nop
a014d138:  30 bf ff df  b,a   0xa014d0b4
a014d13c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014d140:  80 8a a0 ff  btst  0xff, %o2
a014d144:  02 80 00 a2  be  0xa014d3cc
a014d148:  d2 2b 22 04  stb  %o1, [ %o4 + 0x204 ]
a014d14c:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014d150:  d2 0a a3 db  ldub  [ %o2 + 0x3db ], %o1	! 0xa802e3db
a014d154:  80 a2 60 07  cmp  %o1, 7
a014d158:  12 80 00 9d  bne  0xa014d3cc
a014d15c:  01 00 00 00  nop
a014d160:  90 10 20 07  mov  7, %o0	! 0x7
a014d164:  82 13 c0 00  mov  %o7, %g1
a014d168:  7f ff fb ec  call  0xa014c118
a014d16c:  9e 10 40 00  mov  %g1, %o7
a014d170:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014d174:  80 8a a0 ff  btst  0xff, %o2
a014d178:  02 80 00 95  be  0xa014d3cc
a014d17c:  d2 28 62 03  stb  %o1, [ %g1 + 0x203 ]
a014d180:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014d184:  da 0a 23 db  ldub  [ %o0 + 0x3db ], %o5	! 0xa802e3db
a014d188:  80 a3 60 07  cmp  %o5, 7
a014d18c:  12 80 00 90  bne  0xa014d3cc
a014d190:  01 00 00 00  nop
a014d194:  30 bf ff f3  b,a   0xa014d160
a014d198:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014d19c:  80 8a a0 ff  btst  0xff, %o2
a014d1a0:  02 80 00 8b  be  0xa014d3cc
a014d1a4:  d2 2b 22 02  stb  %o1, [ %o4 + 0x202 ]
a014d1a8:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014d1ac:  d2 0a a3 db  ldub  [ %o2 + 0x3db ], %o1	! 0xa802e3db
a014d1b0:  80 a2 60 07  cmp  %o1, 7
a014d1b4:  12 80 00 86  bne  0xa014d3cc
a014d1b8:  01 00 00 00  nop
a014d1bc:  30 bf ff e9  b,a   0xa014d160
a014d1c0:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014d1c4:  80 8a a0 ff  btst  0xff, %o2
a014d1c8:  02 80 00 81  be  0xa014d3cc
a014d1cc:  d2 28 62 01  stb  %o1, [ %g1 + 0x201 ]
a014d1d0:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014d1d4:  da 0a 23 db  ldub  [ %o0 + 0x3db ], %o5	! 0xa802e3db
a014d1d8:  80 a3 60 06  cmp  %o5, 6
a014d1dc:  12 80 00 7c  bne  0xa014d3cc
a014d1e0:  01 00 00 00  nop
a014d1e4:  90 10 20 06  mov  6, %o0	! 0x6
a014d1e8:  82 13 c0 00  mov  %o7, %g1
a014d1ec:  7f ff fb cb  call  0xa014c118
a014d1f0:  9e 10 40 00  mov  %g1, %o7
a014d1f4:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014d1f8:  80 8a a0 ff  btst  0xff, %o2
a014d1fc:  02 80 00 74  be  0xa014d3cc
a014d200:  d2 2b 22 00  stb  %o1, [ %o4 + 0x200 ]
a014d204:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014d208:  d2 0a a3 db  ldub  [ %o2 + 0x3db ], %o1	! 0xa802e3db
a014d20c:  80 a2 60 06  cmp  %o1, 6
a014d210:  12 80 00 6f  bne  0xa014d3cc
a014d214:  01 00 00 00  nop
a014d218:  30 bf ff f3  b,a   0xa014d1e4
a014d21c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014d220:  80 8a a0 ff  btst  0xff, %o2
a014d224:  02 80 00 6a  be  0xa014d3cc
a014d228:  d2 28 61 ff  stb  %o1, [ %g1 + 0x1ff ]
a014d22c:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014d230:  da 0a 23 db  ldub  [ %o0 + 0x3db ], %o5	! 0xa802e3db
a014d234:  80 a3 60 06  cmp  %o5, 6
a014d238:  12 80 00 65  bne  0xa014d3cc
a014d23c:  01 00 00 00  nop
a014d240:  30 bf ff e9  b,a   0xa014d1e4
a014d244:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014d248:  80 8a a0 ff  btst  0xff, %o2
a014d24c:  02 80 00 60  be  0xa014d3cc
a014d250:  d2 2b 21 fe  stb  %o1, [ %o4 + 0x1fe ]
a014d254:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014d258:  d2 0a a3 db  ldub  [ %o2 + 0x3db ], %o1	! 0xa802e3db
a014d25c:  80 a2 60 05  cmp  %o1, 5
a014d260:  12 80 00 5b  bne  0xa014d3cc
a014d264:  01 00 00 00  nop
a014d268:  90 10 20 05  mov  5, %o0	! 0x5
a014d26c:  82 13 c0 00  mov  %o7, %g1
a014d270:  7f ff fb aa  call  0xa014c118
a014d274:  9e 10 40 00  mov  %g1, %o7
a014d278:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014d27c:  80 8a a0 ff  btst  0xff, %o2
a014d280:  02 80 00 53  be  0xa014d3cc
a014d284:  d2 28 61 fd  stb  %o1, [ %g1 + 0x1fd ]
a014d288:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014d28c:  da 0a 23 db  ldub  [ %o0 + 0x3db ], %o5	! 0xa802e3db
a014d290:  80 a3 60 05  cmp  %o5, 5
a014d294:  12 80 00 4e  bne  0xa014d3cc
a014d298:  01 00 00 00  nop
a014d29c:  30 bf ff f3  b,a   0xa014d268
a014d2a0:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014d2a4:  80 8a a0 ff  btst  0xff, %o2
a014d2a8:  02 80 00 49  be  0xa014d3cc
a014d2ac:  d2 28 61 f9  stb  %o1, [ %g1 + 0x1f9 ]
a014d2b0:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014d2b4:  da 0a 23 db  ldub  [ %o0 + 0x3db ], %o5	! 0xa802e3db
a014d2b8:  80 a3 60 04  cmp  %o5, 4
a014d2bc:  12 80 00 44  bne  0xa014d3cc
a014d2c0:  01 00 00 00  nop
a014d2c4:  90 10 20 04  mov  4, %o0	! 0x4
a014d2c8:  82 13 c0 00  mov  %o7, %g1
a014d2cc:  7f ff fb 93  call  0xa014c118
a014d2d0:  9e 10 40 00  mov  %g1, %o7
a014d2d4:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014d2d8:  80 8a a0 ff  btst  0xff, %o2
a014d2dc:  02 80 00 3c  be  0xa014d3cc
a014d2e0:  d2 2b 21 f8  stb  %o1, [ %o4 + 0x1f8 ]
a014d2e4:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014d2e8:  d2 0a a3 db  ldub  [ %o2 + 0x3db ], %o1	! 0xa802e3db
a014d2ec:  80 a2 60 01  cmp  %o1, 1
a014d2f0:  12 80 00 37  bne  0xa014d3cc
a014d2f4:  01 00 00 00  nop
a014d2f8:  90 10 20 01  mov  1, %o0	! 0x1
a014d2fc:  82 13 c0 00  mov  %o7, %g1
a014d300:  7f ff fb 86  call  0xa014c118
a014d304:  9e 10 40 00  mov  %g1, %o7
a014d308:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014d30c:  80 8a a0 ff  btst  0xff, %o2
a014d310:  02 80 00 2f  be  0xa014d3cc
a014d314:  d2 28 61 fb  stb  %o1, [ %g1 + 0x1fb ]
a014d318:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014d31c:  da 0a 23 db  ldub  [ %o0 + 0x3db ], %o5	! 0xa802e3db
a014d320:  80 a3 60 04  cmp  %o5, 4
a014d324:  12 80 00 2a  bne  0xa014d3cc
a014d328:  01 00 00 00  nop
a014d32c:  30 bf ff e6  b,a   0xa014d2c4
a014d330:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014d334:  80 8a a0 ff  btst  0xff, %o2
a014d338:  02 80 00 25  be  0xa014d3cc
a014d33c:  d2 28 61 f7  stb  %o1, [ %g1 + 0x1f7 ]
a014d340:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014d344:  da 0a 23 db  ldub  [ %o0 + 0x3db ], %o5	! 0xa802e3db
a014d348:  80 a3 60 01  cmp  %o5, 1
a014d34c:  12 80 00 20  bne  0xa014d3cc
a014d350:  01 00 00 00  nop
a014d354:  30 bf ff e9  b,a   0xa014d2f8
a014d358:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014d35c:  80 8a a0 ff  btst  0xff, %o2
a014d360:  02 80 00 1b  be  0xa014d3cc
a014d364:  d2 2b 21 f6  stb  %o1, [ %o4 + 0x1f6 ]
a014d368:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014d36c:  d2 0a a3 db  ldub  [ %o2 + 0x3db ], %o1	! 0xa802e3db
a014d370:  80 a2 60 01  cmp  %o1, 1
a014d374:  12 80 00 16  bne  0xa014d3cc
a014d378:  01 00 00 00  nop
a014d37c:  30 bf ff df  b,a   0xa014d2f8
a014d380:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014d384:  80 8a a0 ff  btst  0xff, %o2
a014d388:  02 80 00 11  be  0xa014d3cc
a014d38c:  d2 2b 21 fc  stb  %o1, [ %o4 + 0x1fc ]
a014d390:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014d394:  d2 0a a3 db  ldub  [ %o2 + 0x3db ], %o1	! 0xa802e3db
a014d398:  80 a2 60 05  cmp  %o1, 5
a014d39c:  12 80 00 0c  bne  0xa014d3cc
a014d3a0:  01 00 00 00  nop
a014d3a4:  30 bf ff b1  b,a   0xa014d268
a014d3a8:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014d3ac:  80 8a a0 ff  btst  0xff, %o2
a014d3b0:  02 80 00 07  be  0xa014d3cc
a014d3b4:  d2 2b 21 fa  stb  %o1, [ %o4 + 0x1fa ]
a014d3b8:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014d3bc:  d2 0a a3 db  ldub  [ %o2 + 0x3db ], %o1	! 0xa802e3db
a014d3c0:  80 a2 60 04  cmp  %o1, 4
a014d3c4:  02 bf ff c0  be  0xa014d2c4
a014d3c8:  01 00 00 00  nop
a014d3cc:  81 c3 e0 08  retl
a014d3d0:  01 00 00 00  nop
