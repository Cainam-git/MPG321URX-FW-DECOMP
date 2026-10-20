# leon2s FUN_a00a9020 0xa00a9020-0xa00a9380 (864 bytes)
a00a9020:  9d e3 bf 80  save  %sp, -128, %sp
a00a9024:  90 07 bf e0  add  %fp, -32, %o0
a00a9028:  92 10 20 00  clr  %o1
a00a902c:  40 00 21 60  call  0xa00b15ac
a00a9030:  94 10 20 18  mov  0x18, %o2
a00a9034:  da 0e 60 01  ldub  [ %i1 + 1 ], %o5
a00a9038:  80 8b 60 40  btst  0x40, %o5
a00a903c:  32 80 00 3f  bne,a   0xa00a9138
a00a9040:  d8 0e 60 02  ldub  [ %i1 + 2 ], %o4
a00a9044:  82 10 20 02  mov  2, %g1
a00a9048:  c2 27 bf ec  st  %g1, [ %fp + -20 ]
a00a904c:  80 8b 60 80  btst  0x80, %o5
a00a9050:  12 80 00 9f  bne  0xa00a92cc
a00a9054:  c0 27 bf f0  clr  [ %fp + -16 ]
a00a9058:  c2 0e 40 00  ldub  [ %i1 ], %g1
a00a905c:  82 08 60 1e  and  %g1, 0x1e, %g1
a00a9060:  80 a0 60 1c  cmp  %g1, 0x1c
a00a9064:  38 80 00 32  bgu,a   0xa00a912c
a00a9068:  c0 27 bf e4  clr  [ %fp + -28 ]
a00a906c:  1b 28 02 a3  sethi  %hi(0xa00a8c00), %o5
a00a9070:  83 28 60 02  sll  %g1, 2, %g1
a00a9074:  9a 13 63 ac  or  %o5, 0x3ac, %o5
a00a9078:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00a907c:  81 c0 40 00  jmp  %g1
a00a9080:  01 00 00 00  nop
a00a9084:  82 10 20 01  mov  1, %g1	! 0x1
a00a9088:  10 80 00 28  b  0xa00a9128
a00a908c:  c2 27 bf ec  st  %g1, [ %fp + -20 ]
a00a9090:  10 80 00 07  b  0xa00a90ac
a00a9094:  82 10 20 01  mov  1, %g1
a00a9098:  10 80 00 0d  b  0xa00a90cc
a00a909c:  82 10 20 01  mov  1, %g1
a00a90a0:  10 80 00 07  b  0xa00a90bc
a00a90a4:  82 10 20 02  mov  2, %g1
a00a90a8:  82 10 20 02  mov  2, %g1
a00a90ac:  c2 27 bf e0  st  %g1, [ %fp + -32 ]
a00a90b0:  10 80 00 0a  b  0xa00a90d8
a00a90b4:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a90b8:  82 10 20 03  mov  3, %g1
a00a90bc:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a90c0:  10 80 00 05  b  0xa00a90d4
a00a90c4:  82 10 20 01  mov  1, %g1
a00a90c8:  82 10 20 03  mov  3, %g1
a00a90cc:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a90d0:  82 10 20 02  mov  2, %g1
a00a90d4:  c2 27 bf e0  st  %g1, [ %fp + -32 ]
a00a90d8:  10 80 00 7d  b  0xa00a92cc
a00a90dc:  c0 27 bf e8  clr  [ %fp + -24 ]
a00a90e0:  9a 10 20 01  mov  1, %o5
a00a90e4:  82 10 20 03  mov  3, %g1
a00a90e8:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a90ec:  da 27 bf e0  st  %o5, [ %fp + -32 ]
a00a90f0:  10 80 00 77  b  0xa00a92cc
a00a90f4:  da 27 bf e8  st  %o5, [ %fp + -24 ]
a00a90f8:  82 10 20 03  mov  3, %g1
a00a90fc:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a9100:  82 10 20 01  mov  1, %g1
a00a9104:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a00a9108:  82 10 20 02  mov  2, %g1
a00a910c:  10 80 00 70  b  0xa00a92cc
a00a9110:  c2 27 bf e0  st  %g1, [ %fp + -32 ]
a00a9114:  82 10 20 03  mov  3, %g1
a00a9118:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a911c:  82 10 20 04  mov  4, %g1
a00a9120:  10 80 00 04  b  0xa00a9130
a00a9124:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a00a9128:  c0 27 bf e4  clr  [ %fp + -28 ]
a00a912c:  c0 27 bf e8  clr  [ %fp + -24 ]
a00a9130:  10 80 00 67  b  0xa00a92cc
a00a9134:  c0 27 bf e0  clr  [ %fp + -32 ]
a00a9138:  82 0b 20 ff  and  %o4, 0xff, %g1
a00a913c:  9a 88 60 f0  andcc  %g1, 0xf0, %o5
a00a9140:  32 80 00 23  bne,a   0xa00a91cc
a00a9144:  82 03 7f f0  add  %o5, -16, %g1
a00a9148:  9a 08 60 0f  and  %g1, 0xf, %o5
a00a914c:  80 a3 60 04  cmp  %o5, 4
a00a9150:  02 80 00 10  be  0xa00a9190
a00a9154:  c0 27 bf e0  clr  [ %fp + -32 ]
a00a9158:  80 a3 60 04  cmp  %o5, 4
a00a915c:  14 80 00 07  bg  0xa00a9178
a00a9160:  80 a3 60 06  cmp  %o5, 6
a00a9164:  80 a3 60 03  cmp  %o5, 3
a00a9168:  02 80 00 08  be  0xa00a9188
a00a916c:  82 10 20 03  mov  3, %g1
a00a9170:  10 80 00 0f  b  0xa00a91ac
a00a9174:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a9178:  02 80 00 0a  be  0xa00a91a0
a00a917c:  82 10 20 03  mov  3, %g1
a00a9180:  10 80 00 0b  b  0xa00a91ac
a00a9184:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a9188:  10 80 00 09  b  0xa00a91ac
a00a918c:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a00a9190:  82 10 20 03  mov  3, %g1
a00a9194:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a9198:  10 80 00 06  b  0xa00a91b0
a00a919c:  82 10 20 07  mov  7, %g1
a00a91a0:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a91a4:  10 80 00 04  b  0xa00a91b4
a00a91a8:  da 27 bf e8  st  %o5, [ %fp + -24 ]
a00a91ac:  82 10 20 04  mov  4, %g1
a00a91b0:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a00a91b4:  c2 4e 60 03  ldsb  [ %i1 + 3 ], %g1
a00a91b8:  83 30 60 1f  srl  %g1, 0x1f, %g1
a00a91bc:  9a 10 20 02  mov  2, %o5
a00a91c0:  82 23 40 01  sub  %o5, %g1, %g1
a00a91c4:  10 80 00 41  b  0xa00a92c8
a00a91c8:  c2 27 bf ec  st  %g1, [ %fp + -20 ]
a00a91cc:  80 a0 60 20  cmp  %g1, 0x20
a00a91d0:  18 80 00 39  bgu  0xa00a92b4
a00a91d4:  82 10 20 03  mov  3, %g1
a00a91d8:  80 a3 60 20  cmp  %o5, 0x20
a00a91dc:  02 80 00 09  be  0xa00a9200
a00a91e0:  82 10 20 01  mov  1, %g1
a00a91e4:  80 a3 60 20  cmp  %o5, 0x20
a00a91e8:  04 80 00 06  ble  0xa00a9200
a00a91ec:  82 10 20 02  mov  2, %g1
a00a91f0:  80 a3 60 30  cmp  %o5, 0x30
a00a91f4:  02 80 00 03  be  0xa00a9200
a00a91f8:  82 10 20 03  mov  3, %g1
a00a91fc:  82 10 20 02  mov  2, %g1
a00a9200:  c2 27 bf e0  st  %g1, [ %fp + -32 ]
a00a9204:  82 0b 20 0f  and  %o4, 0xf, %g1
a00a9208:  80 a0 60 07  cmp  %g1, 7
a00a920c:  38 80 00 22  bgu,a   0xa00a9294
a00a9210:  82 10 20 01  mov  1, %g1
a00a9214:  1b 28 02 a3  sethi  %hi(0xa00a8c00), %o5
a00a9218:  83 28 60 02  sll  %g1, 2, %g1
a00a921c:  9a 13 63 8c  or  %o5, 0x38c, %o5
a00a9220:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00a9224:  81 c0 40 00  jmp  %g1
a00a9228:  01 00 00 00  nop
a00a922c:  10 80 00 1a  b  0xa00a9294
a00a9230:  82 10 20 02  mov  2, %g1	! 0x2
a00a9234:  10 80 00 18  b  0xa00a9294
a00a9238:  82 10 20 03  mov  3, %g1
a00a923c:  82 10 20 03  mov  3, %g1
a00a9240:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a9244:  10 80 00 11  b  0xa00a9288
a00a9248:  82 10 20 01  mov  1, %g1
a00a924c:  82 10 20 03  mov  3, %g1
a00a9250:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a9254:  10 80 00 0d  b  0xa00a9288
a00a9258:  82 10 20 02  mov  2, %g1
a00a925c:  82 10 20 03  mov  3, %g1
a00a9260:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a00a9264:  10 80 00 0e  b  0xa00a929c
a00a9268:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a926c:  82 10 20 03  mov  3, %g1
a00a9270:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a9274:  10 80 00 05  b  0xa00a9288
a00a9278:  82 10 20 05  mov  5, %g1
a00a927c:  82 10 20 03  mov  3, %g1
a00a9280:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a9284:  82 10 20 06  mov  6, %g1
a00a9288:  10 80 00 05  b  0xa00a929c
a00a928c:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a00a9290:  82 10 20 01  mov  1, %g1
a00a9294:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a9298:  c0 27 bf e8  clr  [ %fp + -24 ]
a00a929c:  c2 4e 60 03  ldsb  [ %i1 + 3 ], %g1
a00a92a0:  82 38 00 01  xnor  %g0, %g1, %g1
a00a92a4:  83 30 60 1f  srl  %g1, 0x1f, %g1
a00a92a8:  c2 27 bf f0  st  %g1, [ %fp + -16 ]
a00a92ac:  10 80 00 08  b  0xa00a92cc
a00a92b0:  c0 27 bf ec  clr  [ %fp + -20 ]
a00a92b4:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00a92b8:  82 10 20 04  mov  4, %g1
a00a92bc:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a00a92c0:  c0 27 bf e0  clr  [ %fp + -32 ]
a00a92c4:  c0 27 bf ec  clr  [ %fp + -20 ]
a00a92c8:  c0 27 bf f0  clr  [ %fp + -16 ]
a00a92cc:  80 a6 20 19  cmp  %i0, 0x19
a00a92d0:  38 80 00 04  bgu,a   0xa00a92e0
a00a92d4:  c0 27 bf f4  clr  [ %fp + -12 ]
a00a92d8:  82 10 20 01  mov  1, %g1
a00a92dc:  c2 27 bf f4  st  %g1, [ %fp + -12 ]
a00a92e0:  d4 07 bf e8  ld  [ %fp + -24 ], %o2
a00a92e4:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a00a92e8:  83 28 60 02  sll  %g1, 2, %g1
a00a92ec:  95 2a a0 04  sll  %o2, 4, %o2
a00a92f0:  94 12 80 01  or  %o2, %g1, %o2
a00a92f4:  d6 07 bf f0  ld  [ %fp + -16 ], %o3
a00a92f8:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a92fc:  97 2a e0 06  sll  %o3, 6, %o3
a00a9300:  96 12 c0 01  or  %o3, %g1, %o3
a00a9304:  82 10 3f 82  mov  -126, %g1
a00a9308:  c2 2e 80 00  stb  %g1, [ %i2 ]
a00a930c:  82 10 20 02  mov  2, %g1
a00a9310:  c2 2e a0 01  stb  %g1, [ %i2 + 1 ]
a00a9314:  82 10 20 0d  mov  0xd, %g1
a00a9318:  d8 07 bf e0  ld  [ %fp + -32 ], %o4
a00a931c:  99 2b 20 05  sll  %o4, 5, %o4
a00a9320:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a00a9324:  c2 2e a0 02  stb  %g1, [ %i2 + 2 ]
a00a9328:  9b 2b 60 06  sll  %o5, 6, %o5
a00a932c:  d8 2e a0 04  stb  %o4, [ %i2 + 4 ]
a00a9330:  d6 2e a0 08  stb  %o3, [ %i2 + 8 ]
a00a9334:  82 10 3f 91  mov  -111, %g1
a00a9338:  da 2e a0 05  stb  %o5, [ %i2 + 5 ]
a00a933c:  d4 2e a0 06  stb  %o2, [ %i2 + 6 ]
a00a9340:  c2 2e a0 03  stb  %g1, [ %i2 + 3 ]
a00a9344:  98 10 20 00  clr  %o4
a00a9348:  96 10 3f 91  mov  -111, %o3
a00a934c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00a9350:  82 06 80 01  add  %i2, %g1, %g1
a00a9354:  c2 08 60 04  ldub  [ %g1 + 4 ], %g1
a00a9358:  9a 02 c0 01  add  %o3, %g1, %o5
a00a935c:  98 03 20 01  inc  %o4
a00a9360:  82 0b 20 ff  and  %o4, 0xff, %g1
a00a9364:  80 a0 60 04  cmp  %g1, 4
a00a9368:  08 bf ff fa  bleu  0xa00a9350
a00a936c:  96 10 00 0d  mov  %o5, %o3
a00a9370:  82 20 00 0d  neg  %o5, %g1
a00a9374:  c2 2e a0 03  stb  %g1, [ %i2 + 3 ]
a00a9378:  81 c7 e0 08  ret
a00a937c:  81 e8 00 00  restore
