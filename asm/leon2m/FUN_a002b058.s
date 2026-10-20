# leon2m FUN_a002b058 0xa002b058-0xa002b3e4 (908 bytes)
a002b058:  9d e3 bf 90  save  %sp, -112, %sp
a002b05c:  d4 16 00 00  lduh  [ %i0 ], %o2
a002b060:  2f 2a 00 b6  sethi  %hi(0xa802d800), %l7
a002b064:  d4 35 e1 92  sth  %o2, [ %l7 + 0x192 ]	! 0xa802d992
a002b068:  98 15 e1 92  or  %l7, 0x192, %o4
a002b06c:  d2 16 20 02  lduh  [ %i0 + 2 ], %o1
a002b070:  d2 33 20 02  sth  %o1, [ %o4 + 2 ]
a002b074:  da 16 20 04  lduh  [ %i0 + 4 ], %o5
a002b078:  da 33 20 04  sth  %o5, [ %o4 + 4 ]
a002b07c:  d0 16 20 06  lduh  [ %i0 + 6 ], %o0
a002b080:  d0 33 20 06  sth  %o0, [ %o4 + 6 ]
a002b084:  c2 16 20 08  lduh  [ %i0 + 8 ], %g1
a002b088:  f6 27 a0 50  st  %i3, [ %fp + 0x50 ]
a002b08c:  f8 37 bf f6  sth  %i4, [ %fp + -10 ]
a002b090:  a8 10 00 0c  mov  %o4, %l4
a002b094:  c2 33 20 08  sth  %g1, [ %o4 + 8 ]
a002b098:  f6 0f a0 5f  ldub  [ %fp + 0x5f ], %i3
a002b09c:  a4 10 20 01  mov  1, %l2
a002b0a0:  ac 10 20 00  clr  %l6
a002b0a4:  10 80 00 0c  b  0xa002b0d4
a002b0a8:  f8 0b 20 06  ldub  [ %o4 + 6 ], %i4
a002b0ac:  92 1e 20 01  xor  %i0, 1, %o1
a002b0b0:  80 a0 00 09  cmp  %g0, %o1
a002b0b4:  a0 60 3f ff  subx  %g0, -1, %l0
a002b0b8:  9a 0d a0 ff  and  %l6, 0xff, %o5
a002b0bc:  82 0f 60 ff  and  %i5, 0xff, %g1
a002b0c0:  80 a0 40 0d  cmp  %g1, %o5
a002b0c4:  b0 60 3f ff  subx  %g0, -1, %i0
a002b0c8:  80 8c 00 18  btst  %l0, %i0
a002b0cc:  22 80 00 4c  be,a   0xa002b1fc
a002b0d0:  b7 2d 60 10  sll  %l5, 0x10, %i3
a002b0d4:  e2 15 20 08  lduh  [ %l4 + 8 ], %l1
a002b0d8:  27 3f ff f0  sethi  %hi(0xffffc000), %l3
a002b0dc:  a0 0c 40 13  and  %l1, %l3, %l0
a002b0e0:  9f 2c 20 10  sll  %l0, 0x10, %o7
a002b0e4:  17 20 00 00  sethi  %hi(0x80000000), %o3
a002b0e8:  80 a3 c0 0b  cmp  %o7, %o3
a002b0ec:  aa 10 20 00  clr  %l5
a002b0f0:  12 bf ff ef  bne  0xa002b0ac
a002b0f4:  b0 0c a0 ff  and  %l2, 0xff, %i0
a002b0f8:  7f ff fe 06  call  0xa002a910
a002b0fc:  a0 10 20 00  clr  %l0
a002b100:  b0 0f 20 ff  and  %i4, 0xff, %i0
a002b104:  19 2a 00 b6  sethi  %hi(0xa802d800), %o4
a002b108:  a2 13 21 92  or  %o4, 0x192, %l1	! 0xa802d992
a002b10c:  7f ff fe 7e  call  0xa002ab04
a002b110:  90 10 00 18  mov  %i0, %o0
a002b114:  80 8a 20 ff  btst  0xff, %o0
a002b118:  02 80 00 0d  be  0xa002b14c
a002b11c:  97 2c 20 10  sll  %l0, 0x10, %o3
a002b120:  d4 14 60 04  lduh  [ %l1 + 4 ], %o2
a002b124:  93 2a a0 11  sll  %o2, 0x11, %o1
a002b128:  40 00 08 45  call  0xa002d23c
a002b12c:  91 32 60 10  srl  %o1, 0x10, %o0
a002b130:  90 04 20 01  add  %l0, 1, %o0
a002b134:  9b 2a 20 10  sll  %o0, 0x10, %o5
a002b138:  83 33 60 10  srl  %o5, 0x10, %g1
a002b13c:  80 a0 60 09  cmp  %g1, 9
a002b140:  08 bf ff f3  bleu  0xa002b10c
a002b144:  a0 10 00 08  mov  %o0, %l0
a002b148:  97 2c 20 10  sll  %l0, 0x10, %o3
a002b14c:  b1 32 e0 10  srl  %o3, 0x10, %i0
a002b150:  80 a6 20 0a  cmp  %i0, 0xa
a002b154:  02 80 00 73  be  0xa002b320
a002b158:  a7 2e a0 10  sll  %i2, 0x10, %l3
a002b15c:  83 34 e0 10  srl  %l3, 0x10, %g1
a002b160:  80 a0 60 00  cmp  %g1, 0
a002b164:  a0 10 20 00  clr  %l0
a002b168:  02 80 00 13  be  0xa002b1b4
a002b16c:  b0 10 20 00  clr  %i0
a002b170:  a2 10 00 01  mov  %g1, %l1
a002b174:  b1 2c 20 10  sll  %l0, 0x10, %i0
a002b178:  99 36 20 10  srl  %i0, 0x10, %o4
a002b17c:  7f ff fe 62  call  0xa002ab04
a002b180:  d0 0b 00 19  ldub  [ %o4 + %i1 ], %o0
a002b184:  a4 10 00 08  mov  %o0, %l2
a002b188:  90 04 20 01  add  %l0, 1, %o0
a002b18c:  97 2a 20 10  sll  %o0, 0x10, %o3
a002b190:  9e 0c a0 ff  and  %l2, 0xff, %o7
a002b194:  99 32 e0 10  srl  %o3, 0x10, %o4
a002b198:  80 a3 e0 01  cmp  %o7, 1
a002b19c:  02 80 00 06  be  0xa002b1b4
a002b1a0:  a0 10 00 08  mov  %o0, %l0
a002b1a4:  80 a3 00 11  cmp  %o4, %l1
a002b1a8:  2a bf ff f4  bcs,a   0xa002b178
a002b1ac:  b1 2c 20 10  sll  %l0, 0x10, %i0
a002b1b0:  b0 10 00 0b  mov  %o3, %i0
a002b1b4:  80 a4 c0 18  cmp  %l3, %i0
a002b1b8:  02 80 00 41  be  0xa002b2bc
a002b1bc:  b0 0c a0 ff  and  %l2, 0xff, %i0
a002b1c0:  80 a6 e0 00  cmp  %i3, 0
a002b1c4:  12 80 00 10  bne  0xa002b204
a002b1c8:  a0 15 e1 92  or  %l7, 0x192, %l0
a002b1cc:  ac 05 a0 01  inc  %l6
a002b1d0:  92 1e 20 01  xor  %i0, 1, %o1
a002b1d4:  80 a0 00 09  cmp  %g0, %o1
a002b1d8:  a0 60 3f ff  subx  %g0, -1, %l0
a002b1dc:  9a 0d a0 ff  and  %l6, 0xff, %o5
a002b1e0:  82 0f 60 ff  and  %i5, 0xff, %g1
a002b1e4:  80 a0 40 0d  cmp  %g1, %o5
a002b1e8:  b0 60 3f ff  subx  %g0, -1, %i0
a002b1ec:  80 8c 00 18  btst  %l0, %i0
a002b1f0:  32 bf ff ba  bne,a   0xa002b0d8
a002b1f4:  e2 15 20 08  lduh  [ %l4 + 8 ], %l1
a002b1f8:  b7 2d 60 10  sll  %l5, 0x10, %i3
a002b1fc:  10 80 00 78  b  0xa002b3dc
a002b200:  b1 36 e0 10  srl  %i3, 0x10, %i0
a002b204:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002b208:  94 10 20 00  clr  %o2
a002b20c:  40 00 05 98  call  0xa002c86c
a002b210:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002b214:  de 14 20 04  lduh  [ %l0 + 4 ], %o7
a002b218:  97 2b e0 11  sll  %o7, 0x11, %o3
a002b21c:  40 00 08 08  call  0xa002d23c
a002b220:  91 32 e0 10  srl  %o3, 0x10, %o0
a002b224:  d0 0d e1 92  ldub  [ %l7 + 0x192 ], %o0
a002b228:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002b22c:  40 00 05 90  call  0xa002c86c
a002b230:  94 10 20 01  mov  1, %o2
a002b234:  d0 0d e1 92  ldub  [ %l7 + 0x192 ], %o0
a002b238:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002b23c:  40 00 06 3d  call  0xa002cb30
a002b240:  94 10 20 01  mov  1, %o2
a002b244:  10 80 00 07  b  0xa002b260
a002b248:  a2 10 3f ff  mov  -1, %l1
a002b24c:  80 a3 60 00  cmp  %o5, 0
a002b250:  02 80 00 0d  be  0xa002b284
a002b254:  27 2a 00 b6  sethi  %hi(0xa802d800), %l3
a002b258:  01 00 00 00  nop
a002b25c:  01 00 00 00  nop
a002b260:  d0 0d e1 92  ldub  [ %l7 + 0x192 ], %o0
a002b264:  40 00 06 b5  call  0xa002cd38
a002b268:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002b26c:  98 04 7f ff  add  %l1, -1, %o4
a002b270:  9b 2b 20 10  sll  %o4, 0x10, %o5
a002b274:  80 8a 20 ff  btst  0xff, %o0
a002b278:  02 bf ff f5  be  0xa002b24c
a002b27c:  a2 10 00 0c  mov  %o4, %l1
a002b280:  27 2a 00 b6  sethi  %hi(0xa802d800), %l3
a002b284:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002b288:  94 10 20 00  clr  %o2
a002b28c:  40 00 06 29  call  0xa002cb30
a002b290:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002b294:  e2 14 20 04  lduh  [ %l0 + 4 ], %l1
a002b298:  91 2c 60 11  sll  %l1, 0x11, %o0
a002b29c:  40 00 07 e8  call  0xa002d23c
a002b2a0:  91 32 20 10  srl  %o0, 0x10, %o0
a002b2a4:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002b2a8:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002b2ac:  40 00 05 70  call  0xa002c86c
a002b2b0:  94 10 20 01  mov  1, %o2
a002b2b4:  10 bf ff c7  b  0xa002b1d0
a002b2b8:  ac 05 a0 01  inc  %l6
a002b2bc:  e2 17 bf f6  lduh  [ %fp + -10 ], %l1
a002b2c0:  a1 2c 60 10  sll  %l1, 0x10, %l0
a002b2c4:  83 34 20 10  srl  %l0, 0x10, %g1
a002b2c8:  80 a0 60 00  cmp  %g1, 0
a002b2cc:  02 bf ff bd  be  0xa002b1c0
a002b2d0:  a0 10 20 00  clr  %l0
a002b2d4:  a2 10 00 01  mov  %g1, %l1
a002b2d8:  95 2c 20 10  sll  %l0, 0x10, %o2
a002b2dc:  93 32 a0 10  srl  %o2, 0x10, %o1
a002b2e0:  da 07 a0 50  ld  [ %fp + 0x50 ], %o5
a002b2e4:  7f ff fe 08  call  0xa002ab04
a002b2e8:  d0 0a 40 0d  ldub  [ %o1 + %o5 ], %o0
a002b2ec:  a6 04 20 01  add  %l0, 1, %l3
a002b2f0:  83 2c e0 10  sll  %l3, 0x10, %g1
a002b2f4:  b0 0a 20 ff  and  %o0, 0xff, %i0
a002b2f8:  a4 10 00 08  mov  %o0, %l2
a002b2fc:  83 30 60 10  srl  %g1, 0x10, %g1
a002b300:  80 a6 20 01  cmp  %i0, 1
a002b304:  02 bf ff af  be  0xa002b1c0
a002b308:  a0 10 00 13  mov  %l3, %l0
a002b30c:  80 a0 40 11  cmp  %g1, %l1
a002b310:  0a bf ff f2  bcs  0xa002b2d8
a002b314:  aa 05 60 01  inc  %l5
a002b318:  10 bf ff ab  b  0xa002b1c4
a002b31c:  80 a6 e0 00  cmp  %i3, 0
a002b320:  d2 0d 20 03  ldub  [ %l4 + 3 ], %o1
a002b324:  d0 0d 20 02  ldub  [ %l4 + 2 ], %o0
a002b328:  40 00 05 51  call  0xa002c86c
a002b32c:  94 10 20 00  clr  %o2
a002b330:  ec 15 20 04  lduh  [ %l4 + 4 ], %l6
a002b334:  ab 2d a0 11  sll  %l6, 0x11, %l5
a002b338:  40 00 07 c1  call  0xa002d23c
a002b33c:  91 35 60 10  srl  %l5, 0x10, %o0
a002b340:  d0 0d e1 92  ldub  [ %l7 + 0x192 ], %o0
a002b344:  d2 0d 20 01  ldub  [ %l4 + 1 ], %o1
a002b348:  40 00 05 49  call  0xa002c86c
a002b34c:  94 10 20 01  mov  1, %o2
a002b350:  d2 0d 20 01  ldub  [ %l4 + 1 ], %o1
a002b354:  d0 0d e1 92  ldub  [ %l7 + 0x192 ], %o0
a002b358:  40 00 05 f6  call  0xa002cb30
a002b35c:  94 10 20 01  mov  1, %o2
a002b360:  a0 10 3f ff  mov  -1, %l0
a002b364:  25 2a 00 b6  sethi  %hi(0xa802d800), %l2
a002b368:  10 80 00 07  b  0xa002b384
a002b36c:  a2 14 a1 92  or  %l2, 0x192, %l1	! 0xa802d992
a002b370:  80 a3 60 00  cmp  %o5, 0
a002b374:  02 80 00 0d  be  0xa002b3a8
a002b378:  35 2a 00 b6  sethi  %hi(0xa802d800), %i2
a002b37c:  01 00 00 00  nop
a002b380:  01 00 00 00  nop
a002b384:  d0 0d e1 92  ldub  [ %l7 + 0x192 ], %o0
a002b388:  40 00 06 6c  call  0xa002cd38
a002b38c:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002b390:  a8 04 3f ff  add  %l0, -1, %l4
a002b394:  9b 2d 20 10  sll  %l4, 0x10, %o5
a002b398:  80 8a 20 ff  btst  0xff, %o0
a002b39c:  02 bf ff f5  be  0xa002b370
a002b3a0:  a0 10 00 14  mov  %l4, %l0
a002b3a4:  35 2a 00 b6  sethi  %hi(0xa802d800), %i2
a002b3a8:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002b3ac:  94 10 20 00  clr  %o2
a002b3b0:  40 00 05 e0  call  0xa002cb30
a002b3b4:  d0 0e a1 92  ldub  [ %i2 + 0x192 ], %o0
a002b3b8:  f2 14 60 04  lduh  [ %l1 + 4 ], %i1
a002b3bc:  af 2e 60 11  sll  %i1, 0x11, %l7
a002b3c0:  40 00 07 9f  call  0xa002d23c
a002b3c4:  91 35 e0 10  srl  %l7, 0x10, %o0
a002b3c8:  d2 0c 60 03  ldub  [ %l1 + 3 ], %o1
a002b3cc:  d0 0c 60 02  ldub  [ %l1 + 2 ], %o0
a002b3d0:  40 00 05 27  call  0xa002c86c
a002b3d4:  94 10 20 01  mov  1, %o2
a002b3d8:  b0 10 20 00  clr  %i0
a002b3dc:  81 c7 e0 08  ret
a002b3e0:  81 e8 00 00  restore
