# leon2s EQ_handler_3 0xa007afdc-0xa007b2a0 (708 bytes)
a007afdc:  9d e3 bf 98  save  %sp, -104, %sp
a007afe0:  82 1e 20 02  xor  %i0, 2, %g1
a007afe4:  a6 06 00 18  add  %i0, %i0, %l3
a007afe8:  80 a0 00 01  cmp  %g0, %g1
a007afec:  2f 2a 01 f3  sethi  %hi(0xa807cc00), %l7
a007aff0:  a8 04 c0 18  add  %l3, %i0, %l4
a007aff4:  9a 15 e0 64  or  %l7, 0x64, %o5
a007aff8:  83 2d 20 03  sll  %l4, 3, %g1
a007affc:  a2 00 40 0d  add  %g1, %o5, %l1
a007b000:  82 40 20 00  addx  %g0, 0, %g1
a007b004:  a4 0e 20 ff  and  %i0, 0xff, %l2
a007b008:  2b 00 00 07  sethi  %hi(0x1c00), %l5
a007b00c:  ac 10 00 01  mov  %g1, %l6
a007b010:  e0 0c 60 03  ldub  [ %l1 + 3 ], %l0
a007b014:  90 10 20 1c  mov  0x1c, %o0
a007b018:  92 10 00 12  mov  %l2, %o1
a007b01c:  40 00 b1 13  call  0xa00a7468
a007b020:  94 15 60 04  or  %l5, 4, %o2
a007b024:  80 a0 00 08  cmp  %g0, %o0
a007b028:  82 40 20 00  addx  %g0, 0, %g1
a007b02c:  80 a4 00 01  cmp  %l0, %g1
a007b030:  02 80 00 59  be  0xa007b194
a007b034:  c2 0c 60 03  ldub  [ %l1 + 3 ], %g1
a007b038:  80 a0 60 00  cmp  %g1, 0
a007b03c:  02 80 00 06  be  0xa007b054
a007b040:  94 15 60 04  or  %l5, 4, %o2
a007b044:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a007b048:  9a 10 20 01  mov  1, %o5
a007b04c:  82 10 61 98  or  %g1, 0x198, %g1
a007b050:  da 28 40 18  stb  %o5, [ %g1 + %i0 ]
a007b054:  90 10 20 1c  mov  0x1c, %o0
a007b058:  40 00 b1 04  call  0xa00a7468
a007b05c:  92 10 00 12  mov  %l2, %o1
a007b060:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a007b064:  82 10 61 f0  or  %g1, 0x1f0, %g1	! 0xa807a9f0
a007b068:  9a 5e 28 98  smul  %i0, 0x898, %o5
a007b06c:  9a 03 40 01  add  %o5, %g1, %o5
a007b070:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a007b074:  82 10 60 c4  or  %g1, 0xc4, %g1	! 0xa807ccc4
a007b078:  99 2d 20 02  sll  %l4, 2, %o4
a007b07c:  c0 20 40 0c  clr  [ %g1 + %o4 ]
a007b080:  80 a0 00 08  cmp  %g0, %o0
a007b084:  82 10 20 01  mov  1, %g1
a007b088:  96 40 20 00  addx  %g0, 0, %o3
a007b08c:  c2 2b 60 37  stb  %g1, [ %o5 + 0x37 ]
a007b090:  c0 2c 60 01  clrb  [ %l1 + 1 ]
a007b094:  80 a2 e0 00  cmp  %o3, 0
a007b098:  02 80 00 11  be  0xa007b0dc
a007b09c:  d6 2c 60 03  stb  %o3, [ %l1 + 3 ]
a007b0a0:  15 00 00 0d  sethi  %hi(0x3400), %o2
a007b0a4:  94 12 a2 00  or  %o2, 0x200, %o2	! 0x3600
a007b0a8:  90 10 20 00  clr  %o0
a007b0ac:  40 00 b0 ef  call  0xa00a7468
a007b0b0:  92 10 00 12  mov  %l2, %o1
a007b0b4:  80 a2 20 00  cmp  %o0, 0
a007b0b8:  02 80 00 0a  be  0xa007b0e0
a007b0bc:  21 2a 01 e1  sethi  %hi(0xa8078400), %l0
a007b0c0:  90 0d a0 ff  and  %l6, 0xff, %o0
a007b0c4:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a007b0c8:  9a 5a 20 b0  smul  %o0, 0xb0, %o5
a007b0cc:  82 10 62 80  or  %g1, 0x280, %g1
a007b0d0:  9a 03 40 01  add  %o5, %g1, %o5
a007b0d4:  40 00 8e d3  call  0xa009ec20
a007b0d8:  d2 0b 60 01  ldub  [ %o5 + 1 ], %o1
a007b0dc:  21 2a 01 e1  sethi  %hi(0xa8078400), %l0
a007b0e0:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1	! 0xa8078634
a007b0e4:  80 88 60 02  btst  2, %g1
a007b0e8:  02 80 00 10  be  0xa007b128
a007b0ec:  82 04 c0 18  add  %l3, %i0, %g1
a007b0f0:  15 00 00 07  sethi  %hi(0x1c00), %o2
a007b0f4:  92 10 00 12  mov  %l2, %o1
a007b0f8:  94 12 a0 04  or  %o2, 4, %o2
a007b0fc:  40 00 b0 db  call  0xa00a7468
a007b100:  90 10 20 1c  mov  0x1c, %o0
a007b104:  80 a0 00 08  cmp  %g0, %o0
a007b108:  92 06 20 41  add  %i0, 0x41, %o1
a007b10c:  93 2a 60 18  sll  %o1, 0x18, %o1
a007b110:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007b114:  94 40 20 00  addx  %g0, 0, %o2
a007b118:  90 12 20 e0  or  %o0, 0xe0, %o0
a007b11c:  7f ff df ca  call  0xa0073044
a007b120:  93 3a 60 18  sra  %o1, 0x18, %o1
a007b124:  82 04 c0 18  add  %l3, %i0, %g1
a007b128:  9a 15 e0 64  or  %l7, 0x64, %o5
a007b12c:  83 28 60 03  sll  %g1, 3, %g1
a007b130:  82 00 40 0d  add  %g1, %o5, %g1
a007b134:  c2 08 60 03  ldub  [ %g1 + 3 ], %g1
a007b138:  80 a0 60 00  cmp  %g1, 0
a007b13c:  02 80 00 3d  be  0xa007b230
a007b140:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007b144:  7f ff e7 a0  call  0xa0074fc4
a007b148:  90 0e 20 ff  and  %i0, 0xff, %o0
a007b14c:  80 8a 20 ff  btst  0xff, %o0
a007b150:  02 80 00 38  be  0xa007b230
a007b154:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007b158:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007b15c:  da 04 22 34  ld  [ %l0 + 0x234 ], %o5
a007b160:  82 10 61 98  or  %g1, 0x198, %g1
a007b164:  80 8b 60 02  btst  2, %o5
a007b168:  02 80 00 31  be  0xa007b22c
a007b16c:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a007b170:  92 06 20 41  add  %i0, 0x41, %o1
a007b174:  93 2a 60 18  sll  %o1, 0x18, %o1
a007b178:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007b17c:  93 3a 60 18  sra  %o1, 0x18, %o1
a007b180:  94 10 22 b1  mov  0x2b1, %o2
a007b184:  7f ff df b0  call  0xa0073044
a007b188:  90 12 21 20  or  %o0, 0x120, %o0
a007b18c:  10 80 00 29  b  0xa007b230
a007b190:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007b194:  80 a0 60 00  cmp  %g1, 0
a007b198:  02 80 00 26  be  0xa007b230
a007b19c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007b1a0:  7f ff e7 89  call  0xa0074fc4
a007b1a4:  90 10 00 12  mov  %l2, %o0
a007b1a8:  80 8a 20 ff  btst  0xff, %o0
a007b1ac:  02 80 00 21  be  0xa007b230
a007b1b0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007b1b4:  c2 0c 60 01  ldub  [ %l1 + 1 ], %g1
a007b1b8:  80 a0 60 01  cmp  %g1, 1
a007b1bc:  12 80 00 0e  bne  0xa007b1f4
a007b1c0:  9a 04 c0 18  add  %l3, %i0, %o5
a007b1c4:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007b1c8:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007b1cc:  80 88 60 02  btst  2, %g1
a007b1d0:  02 80 00 0a  be  0xa007b1f8
a007b1d4:  82 15 e0 64  or  %l7, 0x64, %g1
a007b1d8:  92 06 20 41  add  %i0, 0x41, %o1
a007b1dc:  93 2a 60 18  sll  %o1, 0x18, %o1
a007b1e0:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007b1e4:  90 12 21 58  or  %o0, 0x158, %o0	! 0xa0067958
a007b1e8:  7f ff df 97  call  0xa0073044
a007b1ec:  93 3a 60 18  sra  %o1, 0x18, %o1
a007b1f0:  9a 04 c0 18  add  %l3, %i0, %o5
a007b1f4:  82 15 e0 64  or  %l7, 0x64, %g1
a007b1f8:  97 2b 60 03  sll  %o5, 3, %o3
a007b1fc:  96 02 c0 01  add  %o3, %g1, %o3
a007b200:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a007b204:  82 10 61 f0  or  %g1, 0x1f0, %g1	! 0xa807a9f0
a007b208:  98 5e 28 98  smul  %i0, 0x898, %o4
a007b20c:  98 03 00 01  add  %o4, %g1, %o4
a007b210:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a007b214:  82 10 60 c4  or  %g1, 0xc4, %g1	! 0xa807ccc4
a007b218:  9b 2b 60 02  sll  %o5, 2, %o5
a007b21c:  c0 20 40 0d  clr  [ %g1 + %o5 ]
a007b220:  82 10 20 01  mov  1, %g1
a007b224:  c2 2b 20 37  stb  %g1, [ %o4 + 0x37 ]
a007b228:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a007b22c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007b230:  a4 0e 20 ff  and  %i0, 0xff, %l2
a007b234:  a6 10 61 c8  or  %g1, 0x1c8, %l3
a007b238:  7f ff ff 4d  call  0xa007af6c
a007b23c:  90 10 00 12  mov  %l2, %o0
a007b240:  90 0a 20 ff  and  %o0, 0xff, %o0
a007b244:  c2 0c c0 18  ldub  [ %l3 + %i0 ], %g1
a007b248:  80 a0 40 08  cmp  %g1, %o0
a007b24c:  02 80 00 13  be  0xa007b298
a007b250:  82 06 00 18  add  %i0, %i0, %g1
a007b254:  a2 00 40 18  add  %g1, %i0, %l1
a007b258:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a007b25c:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa807cc64
a007b260:  9b 2c 60 03  sll  %l1, 3, %o5
a007b264:  a0 03 40 01  add  %o5, %g1, %l0
a007b268:  c2 0c 20 07  ldub  [ %l0 + 7 ], %g1
a007b26c:  80 a0 60 01  cmp  %g1, 1
a007b270:  02 80 00 0a  be  0xa007b298
a007b274:  01 00 00 00  nop
a007b278:  7f ff ff 3d  call  0xa007af6c
a007b27c:  90 10 00 12  mov  %l2, %o0
a007b280:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a007b284:  d0 2c c0 18  stb  %o0, [ %l3 + %i0 ]
a007b288:  9b 2c 60 02  sll  %l1, 2, %o5
a007b28c:  82 10 60 c4  or  %g1, 0xc4, %g1
a007b290:  c0 20 40 0d  clr  [ %g1 + %o5 ]
a007b294:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a007b298:  81 c7 e0 08  ret
a007b29c:  81 e8 00 00  restore
