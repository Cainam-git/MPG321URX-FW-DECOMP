# leon2s FUN_a00d90dc 0xa00d90dc-0xa00d9474 (920 bytes)
a00d90dc:  9d e3 bf 68  save  %sp, -152, %sp
a00d90e0:  98 10 20 00  clr  %o4
a00d90e4:  9a 10 20 00  clr  %o5
a00d90e8:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a00d90ec:  94 10 20 01  mov  1, %o2
a00d90f0:  96 10 20 38  mov  0x38, %o3
a00d90f4:  90 07 bf e8  add  %fp, -24, %o0
a00d90f8:  92 10 20 00  clr  %o1
a00d90fc:  7f ff f8 ae  call  0xa00d73b4
a00d9100:  c0 37 bf f0  clrh  [ %fp + -16 ]
a00d9104:  7f ff fa bd  call  0xa00d7bf8
a00d9108:  01 00 00 00  nop
a00d910c:  da 07 bf d0  ld  [ %fp + -48 ], %o5
a00d9110:  03 1f c0 00  sethi  %hi(0x7f000000), %g1
a00d9114:  82 2b 40 01  andn  %o5, %g1, %g1
a00d9118:  1b 0e 00 00  sethi  %hi(0x38000000), %o5
a00d911c:  82 10 40 0d  or  %g1, %o5, %g1
a00d9120:  c2 27 bf d0  st  %g1, [ %fp + -48 ]
a00d9124:  92 10 22 a8  mov  0x2a8, %o1
a00d9128:  40 3b 76 a4  call  0xa0fb6bb8
a00d912c:  90 10 20 00  clr  %o0
a00d9130:  90 0a 20 02  and  %o0, 2, %o0
a00d9134:  80 a0 00 08  cmp  %g0, %o0
a00d9138:  da 07 bf d0  ld  [ %fp + -48 ], %o5
a00d913c:  98 40 20 00  addx  %g0, 0, %o4
a00d9140:  03 00 08 00  sethi  %hi(0x200000), %g1
a00d9144:  82 2b 40 01  andn  %o5, %g1, %g1
a00d9148:  99 2b 20 15  sll  %o4, 0x15, %o4
a00d914c:  82 10 40 0c  or  %g1, %o4, %g1
a00d9150:  c2 27 bf d0  st  %g1, [ %fp + -48 ]
a00d9154:  90 10 20 00  clr  %o0
a00d9158:  40 3b 76 98  call  0xa0fb6bb8
a00d915c:  92 10 20 32  mov  0x32, %o1
a00d9160:  90 0a 20 08  and  %o0, 8, %o0
a00d9164:  80 a0 00 08  cmp  %g0, %o0
a00d9168:  c2 07 bf d0  ld  [ %fp + -48 ], %g1
a00d916c:  98 40 20 00  addx  %g0, 0, %o4
a00d9170:  1b 00 04 00  sethi  %hi(0x100000), %o5
a00d9174:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d9178:  99 2b 20 14  sll  %o4, 0x14, %o4
a00d917c:  9a 13 40 0c  or  %o5, %o4, %o5
a00d9180:  03 00 02 00  sethi  %hi(0x80000), %g1
a00d9184:  9a 13 40 01  or  %o5, %g1, %o5
a00d9188:  15 00 00 38  sethi  %hi(0xe000), %o2
a00d918c:  94 2b 40 0a  andn  %o5, %o2, %o2
a00d9190:  03 00 00 10  sethi  %hi(0x4000), %g1
a00d9194:  94 12 80 01  or  %o2, %g1, %o2
a00d9198:  03 00 00 06  sethi  %hi(0x1800), %g1
a00d919c:  82 2a 80 01  andn  %o2, %g1, %g1
a00d91a0:  99 33 60 10  srl  %o5, 0x10, %o4
a00d91a4:  82 10 69 00  or  %g1, 0x900, %g1
a00d91a8:  c2 27 bf d0  st  %g1, [ %fp + -48 ]
a00d91ac:  96 10 00 0c  mov  %o4, %o3
a00d91b0:  96 0a e0 10  and  %o3, 0x10, %o3
a00d91b4:  82 10 20 49  mov  0x49, %g1
a00d91b8:  98 0b 20 20  and  %o4, 0x20, %o4
a00d91bc:  9b 33 60 10  srl  %o5, 0x10, %o5
a00d91c0:  c2 2f bf c9  stb  %g1, [ %fp + -55 ]
a00d91c4:  98 13 00 0b  or  %o4, %o3, %o4
a00d91c8:  9a 0b 60 08  and  %o5, 8, %o5
a00d91cc:  c2 0f bf e9  ldub  [ %fp + -23 ], %g1
a00d91d0:  98 13 00 0d  or  %o4, %o5, %o4
a00d91d4:  c2 2f bf d3  stb  %g1, [ %fp + -45 ]
a00d91d8:  17 33 c0 63  sethi  %hi(0xcf018c00), %o3
a00d91dc:  98 13 3f 80  or  %o4, -128, %o4
a00d91e0:  d8 2f bf c8  stb  %o4, [ %fp + -56 ]
a00d91e4:  9a 12 e2 10  or  %o3, 0x210, %o5
a00d91e8:  82 10 20 1f  mov  0x1f, %g1
a00d91ec:  c2 23 40 00  st  %g1, [ %o5 ]
a00d91f0:  9a 12 e2 14  or  %o3, 0x214, %o5
a00d91f4:  82 10 20 80  mov  0x80, %g1
a00d91f8:  c2 23 40 00  st  %g1, [ %o5 ]
a00d91fc:  c2 03 40 00  ld  [ %o5 ], %g1
a00d9200:  80 88 60 80  btst  0x80, %g1
a00d9204:  12 bf ff fe  bne  0xa00d91fc
a00d9208:  82 12 e2 00  or  %o3, 0x200, %g1
a00d920c:  c0 20 40 00  clr  [ %g1 ]
a00d9210:  82 10 20 14  mov  0x14, %g1
a00d9214:  9a 12 e2 24  or  %o3, 0x224, %o5
a00d9218:  c2 23 40 00  st  %g1, [ %o5 ]
a00d921c:  82 12 e2 28  or  %o3, 0x228, %g1
a00d9220:  c0 20 40 00  clr  [ %g1 ]
a00d9224:  a4 10 20 00  clr  %l2
a00d9228:  9a 0c a0 ff  and  %l2, 0xff, %o5
a00d922c:  80 a3 60 00  cmp  %o5, 0
a00d9230:  12 80 00 0b  bne  0xa00d925c
a00d9234:  80 a3 60 01  cmp  %o5, 1
a00d9238:  c2 0f bf ea  ldub  [ %fp + -22 ], %g1
a00d923c:  e0 0f bf c8  ldub  [ %fp + -56 ], %l0
a00d9240:  a0 14 00 01  or  %l0, %g1, %l0
a00d9244:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00d9248:  92 04 62 8c  add  %l1, 0x28c, %o1
a00d924c:  c2 0f bf e9  ldub  [ %fp + -23 ], %g1
a00d9250:  93 2a 60 10  sll  %o1, 0x10, %o1
a00d9254:  10 80 00 0c  b  0xa00d9284
a00d9258:  a0 14 00 01  or  %l0, %g1, %l0
a00d925c:  18 80 00 17  bgu  0xa00d92b8
a00d9260:  80 a3 60 04  cmp  %o5, 4
a00d9264:  82 07 bf f8  add  %fp, -8, %g1
a00d9268:  82 00 40 0d  add  %g1, %o5, %g1
a00d926c:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00d9270:  92 04 62 8c  add  %l1, 0x28c, %o1
a00d9274:  da 08 7f f2  ldub  [ %g1 + -14 ], %o5
a00d9278:  e0 08 7f d0  ldub  [ %g1 + -48 ], %l0
a00d927c:  93 2a 60 10  sll  %o1, 0x10, %o1
a00d9280:  a0 14 00 0d  or  %l0, %o5, %l0
a00d9284:  93 32 60 10  srl  %o1, 0x10, %o1
a00d9288:  40 3b 76 4c  call  0xa0fb6bb8
a00d928c:  90 10 20 00  clr  %o0
a00d9290:  92 04 62 80  add  %l1, 0x280, %o1
a00d9294:  a0 14 00 08  or  %l0, %o0, %l0
a00d9298:  93 2a 60 10  sll  %o1, 0x10, %o1
a00d929c:  93 32 60 10  srl  %o1, 0x10, %o1
a00d92a0:  40 3b 76 46  call  0xa0fb6bb8
a00d92a4:  90 10 20 00  clr  %o0
a00d92a8:  92 10 22 df  mov  0x2df, %o1
a00d92ac:  92 22 40 11  sub  %o1, %l1, %o1
a00d92b0:  10 80 00 1e  b  0xa00d9328
a00d92b4:  a0 14 00 08  or  %l0, %o0, %l0
a00d92b8:  18 80 00 0e  bgu  0xa00d92f0
a00d92bc:  80 a3 60 06  cmp  %o5, 6
a00d92c0:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00d92c4:  92 04 62 8c  add  %l1, 0x28c, %o1
a00d92c8:  93 2a 60 10  sll  %o1, 0x10, %o1
a00d92cc:  a0 07 bf f8  add  %fp, -8, %l0
a00d92d0:  a0 04 00 0d  add  %l0, %o5, %l0
a00d92d4:  93 32 60 10  srl  %o1, 0x10, %o1
a00d92d8:  40 3b 76 38  call  0xa0fb6bb8
a00d92dc:  90 10 20 00  clr  %o0
a00d92e0:  c2 0c 3f f2  ldub  [ %l0 + -14 ], %g1
a00d92e4:  92 04 62 80  add  %l1, 0x280, %o1
a00d92e8:  10 bf ff ec  b  0xa00d9298
a00d92ec:  a0 12 00 01  or  %o0, %g1, %l0
a00d92f0:  18 80 00 19  bgu  0xa00d9354
a00d92f4:  80 a3 60 07  cmp  %o5, 7
a00d92f8:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00d92fc:  92 04 62 8c  add  %l1, 0x28c, %o1
a00d9300:  93 2a 60 10  sll  %o1, 0x10, %o1
a00d9304:  a0 07 bf f8  add  %fp, -8, %l0
a00d9308:  a0 04 00 0d  add  %l0, %o5, %l0
a00d930c:  93 32 60 10  srl  %o1, 0x10, %o1
a00d9310:  40 3b 76 2a  call  0xa0fb6bb8
a00d9314:  90 10 20 00  clr  %o0
a00d9318:  92 10 22 df  mov  0x2df, %o1
a00d931c:  c2 0c 3f f2  ldub  [ %l0 + -14 ], %g1
a00d9320:  92 22 40 11  sub  %o1, %l1, %o1
a00d9324:  a0 12 00 01  or  %o0, %g1, %l0
a00d9328:  93 2a 60 10  sll  %o1, 0x10, %o1
a00d932c:  93 32 60 10  srl  %o1, 0x10, %o1
a00d9330:  40 3b 76 22  call  0xa0fb6bb8
a00d9334:  90 10 20 00  clr  %o0
a00d9338:  a0 14 00 08  or  %l0, %o0, %l0
a00d933c:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00d9340:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00d9344:  82 10 62 04  or  %g1, 0x204, %g1
a00d9348:  e0 20 40 00  st  %l0, [ %g1 ]
a00d934c:  10 80 00 1b  b  0xa00d93b8
a00d9350:  a4 04 a0 01  inc  %l2
a00d9354:  18 80 00 16  bgu  0xa00d93ac
a00d9358:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00d935c:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00d9360:  92 04 22 8c  add  %l0, 0x28c, %o1
a00d9364:  93 2a 60 10  sll  %o1, 0x10, %o1
a00d9368:  93 32 60 10  srl  %o1, 0x10, %o1
a00d936c:  40 3b 76 13  call  0xa0fb6bb8
a00d9370:  90 10 20 00  clr  %o0
a00d9374:  92 10 22 df  mov  0x2df, %o1
a00d9378:  92 22 40 10  sub  %o1, %l0, %o1
a00d937c:  a2 10 00 08  mov  %o0, %l1
a00d9380:  93 2a 60 10  sll  %o1, 0x10, %o1
a00d9384:  93 32 60 10  srl  %o1, 0x10, %o1
a00d9388:  40 3b 76 0c  call  0xa0fb6bb8
a00d938c:  90 10 20 00  clr  %o0
a00d9390:  90 12 00 11  or  %o0, %l1, %o0
a00d9394:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00d9398:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d939c:  82 10 62 04  or  %g1, 0x204, %g1
a00d93a0:  d0 20 40 00  st  %o0, [ %g1 ]
a00d93a4:  10 80 00 05  b  0xa00d93b8
a00d93a8:  a4 04 a0 01  inc  %l2
a00d93ac:  82 10 62 04  or  %g1, 0x204, %g1
a00d93b0:  c0 20 40 00  clr  [ %g1 ]
a00d93b4:  a4 04 a0 01  inc  %l2
a00d93b8:  82 0c a0 ff  and  %l2, 0xff, %g1
a00d93bc:  80 a0 60 13  cmp  %g1, 0x13
a00d93c0:  08 bf ff 9b  bleu  0xa00d922c
a00d93c4:  9a 0c a0 ff  and  %l2, 0xff, %o5
a00d93c8:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a00d93cc:  98 13 62 04  or  %o5, 0x204, %o4	! 0xcf018e04
a00d93d0:  82 10 20 80  mov  0x80, %g1
a00d93d4:  c2 23 00 00  st  %g1, [ %o4 ]
a00d93d8:  98 13 62 14  or  %o5, 0x214, %o4
a00d93dc:  82 10 20 01  mov  1, %g1
a00d93e0:  c2 23 00 00  st  %g1, [ %o4 ]
a00d93e4:  96 10 00 0d  mov  %o5, %o3
a00d93e8:  c2 03 00 00  ld  [ %o4 ], %g1
a00d93ec:  80 88 60 01  btst  1, %g1
a00d93f0:  12 bf ff fe  bne  0xa00d93e8
a00d93f4:  9a 12 e2 00  or  %o3, 0x200, %o5
a00d93f8:  82 10 20 22  mov  0x22, %g1
a00d93fc:  c2 23 40 00  st  %g1, [ %o5 ]
a00d9400:  9a 12 e2 08  or  %o3, 0x208, %o5
a00d9404:  82 10 20 80  mov  0x80, %g1
a00d9408:  c2 23 40 00  st  %g1, [ %o5 ]
a00d940c:  c2 03 40 00  ld  [ %o5 ], %g1
a00d9410:  80 88 60 80  btst  0x80, %g1
a00d9414:  12 bf ff fe  bne  0xa00d940c
a00d9418:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00d941c:  94 10 62 04  or  %g1, 0x204, %o2	! 0xcf018e04
a00d9420:  a4 10 20 00  clr  %l2
a00d9424:  96 07 bf f8  add  %fp, -8, %o3
a00d9428:  82 0c a0 ff  and  %l2, 0xff, %g1
a00d942c:  a4 04 a0 01  inc  %l2
a00d9430:  82 02 c0 01  add  %o3, %g1, %g1
a00d9434:  da 02 80 00  ld  [ %o2 ], %o5
a00d9438:  98 0c a0 ff  and  %l2, 0xff, %o4
a00d943c:  80 a3 20 13  cmp  %o4, 0x13
a00d9440:  08 bf ff fa  bleu  0xa00d9428
a00d9444:  da 28 7f dc  stb  %o5, [ %g1 + -36 ]
a00d9448:  7f ff fa 17  call  0xa00d7ca4
a00d944c:  01 00 00 00  nop
a00d9450:  90 07 bf d0  add  %fp, -48, %o0
a00d9454:  92 10 20 02  mov  2, %o1
a00d9458:  94 10 20 01  mov  1, %o2
a00d945c:  96 10 20 38  mov  0x38, %o3
a00d9460:  7f ff f9 2f  call  0xa00d791c
a00d9464:  98 10 20 18  mov  0x18, %o4
a00d9468:  01 00 00 00  nop
a00d946c:  81 c7 e0 08  ret
a00d9470:  81 e8 00 00  restore
