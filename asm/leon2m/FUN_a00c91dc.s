# leon2m FUN_a00c91dc 0xa00c91dc-0xa00c93e0 (516 bytes)
a00c91dc:  9d e3 bf 98  save  %sp, -104, %sp
a00c91e0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c91e4:  80 a4 20 02  cmp  %l0, 2
a00c91e8:  02 80 00 5c  be  0xa00c9358
a00c91ec:  80 a4 20 03  cmp  %l0, 3
a00c91f0:  02 80 00 5d  be  0xa00c9364
a00c91f4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c91f8:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c91fc:  96 08 60 ff  and  %g1, 0xff, %o3
a00c9200:  94 02 ff d0  add  %o3, -48, %o2
a00c9204:  96 0a a0 ff  and  %o2, 0xff, %o3
a00c9208:  80 a2 e0 04  cmp  %o3, 4
a00c920c:  18 80 00 73  bgu  0xa00c93d8
a00c9210:  b0 10 20 ff  mov  0xff, %i0
a00c9214:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c9218:  98 13 e2 90  or  %o7, 0x290, %o4	! 0xa802d290
a00c921c:  da 0b 20 1f  ldub  [ %o4 + 0x1f ], %o5
a00c9220:  80 a3 60 00  cmp  %o5, 0
a00c9224:  02 80 00 6d  be  0xa00c93d8
a00c9228:  94 0a e0 0f  and  %o3, 0xf, %o2
a00c922c:  d2 03 20 30  ld  [ %o4 + 0x30 ], %o1
a00c9230:  91 2a a0 04  sll  %o2, 4, %o0
a00c9234:  82 0a 7f 0f  and  %o1, -241, %g1
a00c9238:  b0 10 40 08  or  %g1, %o0, %i0
a00c923c:  f0 23 20 30  st  %i0, [ %o4 + 0x30 ]
a00c9240:  40 00 3a 0c  call  0xa00d7a70
a00c9244:  90 10 20 01  mov  1, %o0
a00c9248:  7f ff bd a1  call  0xa00b88cc
a00c924c:  01 00 00 00  nop
a00c9250:  80 a4 20 02  cmp  %l0, 2
a00c9254:  02 80 00 24  be  0xa00c92e4
a00c9258:  80 a4 20 03  cmp  %l0, 3
a00c925c:  02 80 00 45  be  0xa00c9370
a00c9260:  9e 10 20 30  mov  0x30, %o7
a00c9264:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c9268:  94 12 60 78  or  %o1, 0x78, %o2	! 0xa802d078
a00c926c:  98 10 20 35  mov  0x35, %o4
a00c9270:  90 10 20 36  mov  0x36, %o0
a00c9274:  82 10 20 2b  mov  0x2b, %g1
a00c9278:  b0 10 20 0d  mov  0xd, %i0
a00c927c:  d8 2a 60 78  stb  %o4, [ %o1 + 0x78 ]
a00c9280:  d0 2a a0 01  stb  %o0, [ %o2 + 1 ]
a00c9284:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00c9288:  c2 2a a0 04  stb  %g1, [ %o2 + 4 ]
a00c928c:  f0 2a a0 05  stb  %i0, [ %o2 + 5 ]
a00c9290:  80 a4 20 02  cmp  %l0, 2
a00c9294:  02 80 00 21  be  0xa00c9318
a00c9298:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00c929c:  80 a4 20 03  cmp  %l0, 3
a00c92a0:  02 80 00 41  be  0xa00c93a4
a00c92a4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c92a8:  90 12 60 d0  or  %o1, 0xd0, %o0	! 0xa802d0d0
a00c92ac:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c92b0:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]	! 0xa802b09c
a00c92b4:  c0 2a 60 d0  clrb  [ %o1 + 0xd0 ]
a00c92b8:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c92bc:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c92c0:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c92c4:  80 a4 20 02  cmp  %l0, 2
a00c92c8:  02 80 00 1d  be  0xa00c933c
a00c92cc:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c92d0:  80 a4 20 03  cmp  %l0, 3
a00c92d4:  12 80 00 1d  bne  0xa00c9348
a00c92d8:  90 10 00 10  mov  %l0, %o0
a00c92dc:  10 80 00 3c  b  0xa00c93cc
a00c92e0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c92e4:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c92e8:  98 16 21 28  or  %i0, 0x128, %o4	! 0xa802d128
a00c92ec:  a0 10 20 30  mov  0x30, %l0
a00c92f0:  82 10 20 35  mov  0x35, %g1
a00c92f4:  9e 10 20 0d  mov  0xd, %o7
a00c92f8:  9a 10 20 36  mov  0x36, %o5
a00c92fc:  96 10 20 2b  mov  0x2b, %o3
a00c9300:  c2 2e 21 28  stb  %g1, [ %i0 + 0x128 ]
a00c9304:  de 2b 20 05  stb  %o7, [ %o4 + 5 ]
a00c9308:  da 2b 20 01  stb  %o5, [ %o4 + 1 ]
a00c930c:  e0 2b 20 03  stb  %l0, [ %o4 + 3 ]
a00c9310:  d6 2b 20 04  stb  %o3, [ %o4 + 4 ]
a00c9314:  e0 2b 20 02  stb  %l0, [ %o4 + 2 ]
a00c9318:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c931c:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c9320:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c9324:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00c9328:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c932c:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c9330:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c9334:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c9338:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c933c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c9340:  94 13 21 28  or  %o4, 0x128, %o2	! 0xa802d128
a00c9344:  90 10 20 02  mov  2, %o0
a00c9348:  40 01 fd 28  call  0xa01487e8
a00c934c:  92 10 20 06  mov  6, %o1
a00c9350:  10 80 00 22  b  0xa00c93d8
a00c9354:  b0 10 20 00  clr  %i0
a00c9358:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c935c:  10 bf ff a8  b  0xa00c91fc
a00c9360:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c9364:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9368:  10 bf ff a5  b  0xa00c91fc
a00c936c:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c9370:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c9374:  90 12 e1 08  or  %o3, 0x108, %o0	! 0xa802d108
a00c9378:  92 10 20 30  mov  0x30, %o1
a00c937c:  9a 10 20 35  mov  0x35, %o5
a00c9380:  a0 10 20 0d  mov  0xd, %l0
a00c9384:  98 10 20 36  mov  0x36, %o4
a00c9388:  94 10 20 2b  mov  0x2b, %o2
a00c938c:  da 2a e1 08  stb  %o5, [ %o3 + 0x108 ]
a00c9390:  e0 2a 20 05  stb  %l0, [ %o0 + 5 ]
a00c9394:  d8 2a 20 01  stb  %o4, [ %o0 + 1 ]
a00c9398:  d2 2a 20 03  stb  %o1, [ %o0 + 3 ]
a00c939c:  d4 2a 20 04  stb  %o2, [ %o0 + 4 ]
a00c93a0:  d2 2a 20 02  stb  %o1, [ %o0 + 2 ]
a00c93a4:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c93a8:  9a 13 e0 98  or  %o7, 0x98, %o5	! 0xa802d098
a00c93ac:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00c93b0:  c0 2e 20 98  clrb  [ %i0 + 0x98 ]	! 0xa802b098
a00c93b4:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]
a00c93b8:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00c93bc:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00c93c0:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00c93c4:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00c93c8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c93cc:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c93d0:  10 bf ff de  b  0xa00c9348
a00c93d4:  90 10 20 03  mov  3, %o0
a00c93d8:  81 c7 e0 08  ret
a00c93dc:  81 e8 00 00  restore
