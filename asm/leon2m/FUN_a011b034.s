# leon2m FUN_a011b034 0xa011b034-0xa011b36c (824 bytes)
a011b034:  9d e3 bf 98  save  %sp, -104, %sp
a011b038:  97 2e 20 10  sll  %i0, 0x10, %o3
a011b03c:  94 10 00 19  mov  %i1, %o2
a011b040:  9e 10 00 1c  mov  %i4, %o7
a011b044:  90 10 00 1a  mov  %i2, %o0
a011b048:  a2 10 00 1b  mov  %i3, %l1
a011b04c:  80 a2 e0 00  cmp  %o3, 0
a011b050:  02 80 00 61  be  0xa011b1d4
a011b054:  98 10 00 1c  mov  %i4, %o4
a011b058:  9a 0f 20 ff  and  %i4, 0xff, %o5
a011b05c:  80 a3 60 02  cmp  %o5, 2
a011b060:  82 60 20 00  subx  %g0, 0, %g1
a011b064:  b8 0f 00 01  and  %i4, %g1, %i4
a011b068:  ba 0b c0 01  and  %o7, %g1, %i5
a011b06c:  b6 0f 20 ff  and  %i4, 0xff, %i3
a011b070:  b4 10 00 01  mov  %g1, %i2
a011b074:  b4 0b c0 1a  and  %o7, %i2, %i2
a011b078:  b8 0f 60 ff  and  %i5, 0xff, %i4
a011b07c:  21 2a 00 9e  sethi  %hi(0xa8027800), %l0
a011b080:  b2 14 22 a8  or  %l0, 0x2a8, %i1	! 0xa8027aa8
a011b084:  82 06 c0 1b  add  %i3, %i3, %g1
a011b088:  ba 10 00 1a  mov  %i2, %i5
a011b08c:  f6 16 40 01  lduh  [ %i1 + %g1 ], %i3
a011b090:  b8 07 00 1c  add  %i4, %i4, %i4
a011b094:  b4 0e a0 ff  and  %i2, 0xff, %i2
a011b098:  c2 16 40 1c  lduh  [ %i1 + %i4 ], %g1
a011b09c:  b4 06 80 1a  add  %i2, %i2, %i2
a011b0a0:  b6 06 e0 c8  add  %i3, 0xc8, %i3
a011b0a4:  ba 0f 60 ff  and  %i5, 0xff, %i5
a011b0a8:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a011b0ac:  f8 16 40 1a  lduh  [ %i1 + %i2 ], %i4
a011b0b0:  ba 07 40 1d  add  %i5, %i5, %i5
a011b0b4:  b0 16 3f 80  or  %i0, -128, %i0
a011b0b8:  b7 2e e0 02  sll  %i3, 2, %i3
a011b0bc:  f4 16 40 1d  lduh  [ %i1 + %i5 ], %i2
a011b0c0:  b6 16 c0 0f  or  %i3, %o7, %i3
a011b0c4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a011b0c8:  82 00 60 d8  add  %g1, 0xd8, %g1
a011b0cc:  f0 26 c0 00  st  %i0, [ %i3 ]
a011b0d0:  bb 32 e0 17  srl  %o3, 0x17, %i5
a011b0d4:  b8 07 20 c9  add  %i4, 0xc9, %i4
a011b0d8:  83 28 60 02  sll  %g1, 2, %g1
a011b0dc:  b2 0f 60 07  and  %i5, 7, %i1
a011b0e0:  82 10 40 0f  or  %g1, %o7, %g1
a011b0e4:  b1 2f 20 02  sll  %i4, 2, %i0
a011b0e8:  f2 20 40 00  st  %i1, [ %g1 ]
a011b0ec:  b6 06 a0 d9  add  %i2, 0xd9, %i3
a011b0f0:  b8 16 00 0f  or  %i0, %o7, %i4
a011b0f4:  ba 0a a0 ff  and  %o2, 0xff, %i5
a011b0f8:  b1 32 a0 08  srl  %o2, 8, %i0
a011b0fc:  b3 2e e0 02  sll  %i3, 2, %i1
a011b100:  fa 27 00 00  st  %i5, [ %i4 ]
a011b104:  b4 16 40 0f  or  %i1, %o7, %i2
a011b108:  82 0e 20 03  and  %i0, 3, %g1
a011b10c:  97 2a 20 10  sll  %o0, 0x10, %o3
a011b110:  c2 26 80 00  st  %g1, [ %i2 ]
a011b114:  80 a2 e0 00  cmp  %o3, 0
a011b118:  02 80 00 62  be  0xa011b2a0
a011b11c:  80 a3 60 01  cmp  %o5, 1
a011b120:  80 a3 60 02  cmp  %o5, 2
a011b124:  b6 60 20 00  subx  %g0, 0, %i3
a011b128:  b4 0e c0 0c  and  %i3, %o4, %i2
a011b12c:  b8 10 00 1b  mov  %i3, %i4
a011b130:  b0 0e a0 ff  and  %i2, 0xff, %i0
a011b134:  ba 0e c0 0c  and  %i3, %o4, %i5
a011b138:  9e 14 22 a8  or  %l0, 0x2a8, %o7
a011b13c:  b4 0f 00 0c  and  %i4, %o4, %i2
a011b140:  b6 0f 60 ff  and  %i5, 0xff, %i3
a011b144:  82 06 00 18  add  %i0, %i0, %g1
a011b148:  f0 13 c0 01  lduh  [ %o7 + %g1 ], %i0
a011b14c:  b8 06 c0 1b  add  %i3, %i3, %i4
a011b150:  b2 10 00 1a  mov  %i2, %i1
a011b154:  ba 0e a0 ff  and  %i2, 0xff, %i5
a011b158:  b6 06 20 ca  add  %i0, 0xca, %i3
a011b15c:  b4 07 40 1d  add  %i5, %i5, %i2
a011b160:  b0 0e 60 ff  and  %i1, 0xff, %i0
a011b164:  ba 06 00 18  add  %i0, %i0, %i5
a011b168:  c2 13 c0 1c  lduh  [ %o7 + %i4 ], %g1
a011b16c:  31 33 c0 00  sethi  %hi(0xcf000000), %i0
a011b170:  f8 13 c0 1a  lduh  [ %o7 + %i2 ], %i4
a011b174:  b2 12 3f 80  or  %o0, -128, %i1
a011b178:  b7 2e e0 02  sll  %i3, 2, %i3
a011b17c:  f4 13 c0 1d  lduh  [ %o7 + %i5 ], %i2
a011b180:  b6 16 c0 18  or  %i3, %i0, %i3
a011b184:  b2 0e 60 ff  and  %i1, 0xff, %i1
a011b188:  82 00 60 da  add  %g1, 0xda, %g1
a011b18c:  f2 26 c0 00  st  %i1, [ %i3 ]
a011b190:  bb 32 e0 17  srl  %o3, 0x17, %i5
a011b194:  83 28 60 02  sll  %g1, 2, %g1
a011b198:  b6 10 40 18  or  %g1, %i0, %i3
a011b19c:  b2 0f 60 01  and  %i5, 1, %i1
a011b1a0:  b8 07 20 cb  add  %i4, 0xcb, %i4
a011b1a4:  f2 26 c0 00  st  %i1, [ %i3 ]
a011b1a8:  b9 2f 20 02  sll  %i4, 2, %i4
a011b1ac:  b4 06 a0 db  add  %i2, 0xdb, %i2
a011b1b0:  ba 17 00 18  or  %i4, %i0, %i5
a011b1b4:  b7 34 60 08  srl  %l1, 8, %i3
a011b1b8:  b3 2e a0 02  sll  %i2, 2, %i1
a011b1bc:  82 0c 60 ff  and  %l1, 0xff, %g1
a011b1c0:  c2 27 40 00  st  %g1, [ %i5 ]
a011b1c4:  b4 16 40 18  or  %i1, %i0, %i2
a011b1c8:  b8 0e e0 03  and  %i3, 3, %i4
a011b1cc:  f8 26 80 00  st  %i4, [ %i2 ]
a011b1d0:  30 80 00 65  b,a   0xa011b364
a011b1d4:  9a 0f 20 ff  and  %i4, 0xff, %o5
a011b1d8:  80 a3 60 02  cmp  %o5, 2
a011b1dc:  b0 60 20 00  subx  %g0, 0, %i0
a011b1e0:  82 0f 00 18  and  %i4, %i0, %g1
a011b1e4:  b8 08 60 ff  and  %g1, 0xff, %i4
a011b1e8:  b4 07 00 1c  add  %i4, %i4, %i2
a011b1ec:  21 2a 00 9e  sethi  %hi(0xa8027800), %l0
a011b1f0:  b8 14 22 a8  or  %l0, 0x2a8, %i4	! 0xa8027aa8
a011b1f4:  f6 17 00 1a  lduh  [ %i4 + %i2 ], %i3
a011b1f8:  ba 06 e0 c8  add  %i3, 0xc8, %i5
a011b1fc:  b3 2f 60 02  sll  %i5, 2, %i1
a011b200:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011b204:  b0 16 40 1a  or  %i1, %i2, %i0
a011b208:  c0 26 00 00  clr  [ %i0 ]
a011b20c:  80 a3 60 01  cmp  %o5, 1
a011b210:  18 80 00 53  bgu  0xa011b35c
a011b214:  ba 10 00 0f  mov  %o7, %i5
a011b218:  b2 0f 60 ff  and  %i5, 0xff, %i1
a011b21c:  b0 06 40 19  add  %i1, %i1, %i0
a011b220:  c2 17 00 18  lduh  [ %i4 + %i0 ], %g1
a011b224:  b6 00 60 d8  add  %g1, 0xd8, %i3
a011b228:  bb 2e e0 02  sll  %i3, 2, %i5
a011b22c:  b2 17 40 1a  or  %i5, %i2, %i1
a011b230:  c0 26 40 00  clr  [ %i1 ]
a011b234:  80 a3 60 01  cmp  %o5, 1
a011b238:  08 80 00 03  bleu  0xa011b244
a011b23c:  ba 10 00 0f  mov  %o7, %i5
a011b240:  ba 10 20 00  clr  %i5
a011b244:  ba 0f 60 ff  and  %i5, 0xff, %i5
a011b248:  b2 07 40 1d  add  %i5, %i5, %i1
a011b24c:  f0 17 00 19  lduh  [ %i4 + %i1 ], %i0
a011b250:  82 06 20 c9  add  %i0, 0xc9, %g1
a011b254:  b7 28 60 02  sll  %g1, 2, %i3
a011b258:  ba 16 c0 1a  or  %i3, %i2, %i5
a011b25c:  c0 27 40 00  clr  [ %i5 ]
a011b260:  80 a3 60 01  cmp  %o5, 1
a011b264:  08 80 00 03  bleu  0xa011b270
a011b268:  82 10 00 0f  mov  %o7, %g1
a011b26c:  82 10 20 00  clr  %g1
a011b270:  ba 08 60 ff  and  %g1, 0xff, %i5
a011b274:  b2 07 40 1d  add  %i5, %i5, %i1
a011b278:  f0 17 00 19  lduh  [ %i4 + %i1 ], %i0
a011b27c:  82 06 20 d9  add  %i0, 0xd9, %g1
a011b280:  b7 28 60 02  sll  %g1, 2, %i3
a011b284:  b8 16 c0 1a  or  %i3, %i2, %i4
a011b288:  97 2a 20 10  sll  %o0, 0x10, %o3
a011b28c:  c0 27 00 00  clr  [ %i4 ]
a011b290:  80 a2 e0 00  cmp  %o3, 0
a011b294:  12 bf ff a4  bne  0xa011b124
a011b298:  80 a3 60 02  cmp  %o5, 2
a011b29c:  80 a3 60 01  cmp  %o5, 1
a011b2a0:  18 80 00 2d  bgu  0xa011b354
a011b2a4:  ba 10 00 0c  mov  %o4, %i5
a011b2a8:  b6 0f 60 ff  and  %i5, 0xff, %i3
a011b2ac:  b2 14 22 a8  or  %l0, 0x2a8, %i1
a011b2b0:  b4 06 c0 1b  add  %i3, %i3, %i2
a011b2b4:  f8 16 40 1a  lduh  [ %i1 + %i2 ], %i4
a011b2b8:  b0 07 20 ca  add  %i4, 0xca, %i0
a011b2bc:  bb 2e 20 02  sll  %i0, 2, %i5
a011b2c0:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a011b2c4:  82 17 40 0f  or  %i5, %o7, %g1
a011b2c8:  c0 20 40 00  clr  [ %g1 ]
a011b2cc:  80 a3 60 01  cmp  %o5, 1
a011b2d0:  08 80 00 03  bleu  0xa011b2dc
a011b2d4:  ba 10 00 0c  mov  %o4, %i5
a011b2d8:  ba 10 20 00  clr  %i5
a011b2dc:  b6 0f 60 ff  and  %i5, 0xff, %i3
a011b2e0:  b4 06 c0 1b  add  %i3, %i3, %i2
a011b2e4:  f8 16 40 1a  lduh  [ %i1 + %i2 ], %i4
a011b2e8:  b0 07 20 da  add  %i4, 0xda, %i0
a011b2ec:  bb 2e 20 02  sll  %i0, 2, %i5
a011b2f0:  82 17 40 0f  or  %i5, %o7, %g1
a011b2f4:  c0 20 40 00  clr  [ %g1 ]
a011b2f8:  80 a3 60 01  cmp  %o5, 1
a011b2fc:  08 80 00 03  bleu  0xa011b308
a011b300:  ba 10 00 0c  mov  %o4, %i5
a011b304:  ba 10 20 00  clr  %i5
a011b308:  b6 0f 60 ff  and  %i5, 0xff, %i3
a011b30c:  b4 06 c0 1b  add  %i3, %i3, %i2
a011b310:  f8 16 40 1a  lduh  [ %i1 + %i2 ], %i4
a011b314:  b0 07 20 cb  add  %i4, 0xcb, %i0
a011b318:  bb 2e 20 02  sll  %i0, 2, %i5
a011b31c:  82 17 40 0f  or  %i5, %o7, %g1
a011b320:  c0 20 40 00  clr  [ %g1 ]
a011b324:  80 a3 60 01  cmp  %o5, 1
a011b328:  08 80 00 03  bleu  0xa011b334
a011b32c:  ba 10 00 0c  mov  %o4, %i5
a011b330:  ba 10 20 00  clr  %i5
a011b334:  b4 0f 60 ff  and  %i5, 0xff, %i2
a011b338:  b8 06 80 1a  add  %i2, %i2, %i4
a011b33c:  f0 16 40 1c  lduh  [ %i1 + %i4 ], %i0
a011b340:  ba 06 20 db  add  %i0, 0xdb, %i5
a011b344:  83 2f 60 02  sll  %i5, 2, %g1
a011b348:  b2 10 40 0f  or  %g1, %o7, %i1
a011b34c:  c0 26 40 00  clr  [ %i1 ]
a011b350:  30 80 00 05  b,a   0xa011b364
a011b354:  10 bf ff d5  b  0xa011b2a8
a011b358:  ba 10 20 00  clr  %i5
a011b35c:  10 bf ff af  b  0xa011b218
a011b360:  ba 10 20 00  clr  %i5
a011b364:  81 c7 e0 08  ret
a011b368:  81 e8 00 00  restore
