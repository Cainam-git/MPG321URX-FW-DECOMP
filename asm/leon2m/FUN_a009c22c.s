# leon2m FUN_a009c22c 0xa009c22c-0xa009c4a4 (632 bytes)  [FUN_a009c49c = unreachable ret/restore tail, merged]
a009c22c:  9d e3 bf 98  save  %sp, -104, %sp
a009c230:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009c234:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5	! 0xa802afec
a009c238:  33 09 24 92  sethi  %hi(0x24924800), %i1
a009c23c:  92 03 7f a4  add  %o5, -92, %o1
a009c240:  b0 16 61 25  or  %i1, 0x125, %i0
a009c244:  80 52 40 18  umul  %o1, %i0, %g0
a009c248:  99 40 00 00  rd  %y, %o4
a009c24c:  a0 22 40 0c  sub  %o1, %o4, %l0
a009c250:  9f 34 20 01  srl  %l0, 1, %o7
a009c254:  96 03 00 0f  add  %o4, %o7, %o3
a009c258:  9b 32 e0 02  srl  %o3, 2, %o5
a009c25c:  95 2b 60 03  sll  %o5, 3, %o2
a009c260:  82 22 80 0d  sub  %o2, %o5, %g1
a009c264:  90 22 40 01  sub  %o1, %g1, %o0
a009c268:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c26c:  40 00 34 54  call  0xa00a93bc
a009c270:  b0 10 00 0d  mov  %o5, %i0
a009c274:  e0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %l0
a009c278:  94 04 3f a5  add  %l0, -91, %o2
a009c27c:  9f 3a a0 1f  sra  %o2, 0x1f, %o7
a009c280:  99 33 e0 1d  srl  %o7, 0x1d, %o4
a009c284:  96 02 80 0c  add  %o2, %o4, %o3
a009c288:  82 0a ff f8  and  %o3, -8, %g1
a009c28c:  90 22 80 01  sub  %o2, %g1, %o0
a009c290:  92 02 20 5c  add  %o0, 0x5c, %o1
a009c294:  d2 26 a3 ec  st  %o1, [ %i2 + 0x3ec ]
a009c298:  40 00 3a a6  call  0xa00aad30
a009c29c:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c2a0:  a0 0a 20 ff  and  %o0, 0xff, %l0
a009c2a4:  80 a4 20 01  cmp  %l0, 1
a009c2a8:  32 bf ff f4  bne,a   0xa009c278
a009c2ac:  e0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %l0
a009c2b0:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009c2b4:  96 06 7f a4  add  %i1, -92, %o3
a009c2b8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a009c2bc:  b2 12 a2 90  or  %o2, 0x290, %i1	! 0xa802d290
a009c2c0:  90 0a e0 ff  and  %o3, 0xff, %o0
a009c2c4:  40 00 6a 31  call  0xa00b6b88
a009c2c8:  92 10 20 01  mov  1, %o1
a009c2cc:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009c2d0:  13 09 24 92  sethi  %hi(0x24924800), %o1
a009c2d4:  98 03 7f a4  add  %o5, -92, %o4
a009c2d8:  96 10 00 08  mov  %o0, %o3
a009c2dc:  9e 12 61 25  or  %o1, 0x125, %o7
a009c2e0:  80 53 00 0f  umul  %o4, %o7, %g0
a009c2e4:  91 40 00 00  rd  %y, %o0
a009c2e8:  82 23 00 08  sub  %o4, %o0, %g1
a009c2ec:  95 30 60 01  srl  %g1, 1, %o2
a009c2f0:  9a 02 00 0a  add  %o0, %o2, %o5
a009c2f4:  92 0e 20 ff  and  %i0, 0xff, %o1
a009c2f8:  91 33 60 02  srl  %o5, 2, %o0
a009c2fc:  80 a2 40 08  cmp  %o1, %o0
a009c300:  02 80 00 05  be  0xa009c314
a009c304:  d6 2e 61 81  stb  %o3, [ %i1 + 0x181 ]
a009c308:  40 00 6a 39  call  0xa00b6bec
a009c30c:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c310:  d6 0e 61 81  ldub  [ %i1 + 0x181 ], %o3
a009c314:  90 02 ff fc  add  %o3, -4, %o0
a009c318:  b0 0a 20 ff  and  %o0, 0xff, %i0
a009c31c:  80 a6 20 02  cmp  %i0, 2
a009c320:  18 80 00 34  bgu  0xa009c3f0
a009c324:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a009c328:  c2 0e 60 11  ldub  [ %i1 + 0x11 ], %g1
a009c32c:  80 a0 60 01  cmp  %g1, 1
a009c330:  32 80 00 02  bne,a   0xa009c338
a009c334:  e0 2e 60 11  stb  %l0, [ %i1 + 0x11 ]
a009c338:  40 00 fd 00  call  0xa00db738
a009c33c:  01 00 00 00  nop
a009c340:  90 10 20 02  mov  2, %o0	! 0x2
a009c344:  40 00 3a 5c  call  0xa00aacb4
a009c348:  92 10 20 01  mov  1, %o1
a009c34c:  f0 06 a3 ec  ld  [ %i2 + 0x3ec ], %i0
a009c350:  94 06 3f a4  add  %i0, -92, %o2
a009c354:  17 09 24 92  sethi  %hi(0x24924800), %o3
a009c358:  b0 12 e1 25  or  %o3, 0x125, %i0	! 0x24924925
a009c35c:  80 52 80 18  umul  %o2, %i0, %g0
a009c360:  a1 40 00 00  rd  %y, %l0
a009c364:  9a 22 80 10  sub  %o2, %l0, %o5
a009c368:  93 33 60 01  srl  %o5, 1, %o1
a009c36c:  9e 04 00 09  add  %l0, %o1, %o7
a009c370:  83 33 e0 02  srl  %o7, 2, %g1
a009c374:  b3 28 60 03  sll  %g1, 3, %i1
a009c378:  98 26 40 01  sub  %i1, %g1, %o4
a009c37c:  96 22 80 0c  sub  %o2, %o4, %o3
a009c380:  90 0a e0 ff  and  %o3, 0xff, %o0
a009c384:  40 00 34 b3  call  0xa00a9650
a009c388:  92 10 20 01  mov  1, %o1
a009c38c:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009c390:  92 03 7f a4  add  %o5, -92, %o1
a009c394:  80 52 40 18  umul  %o1, %i0, %g0
a009c398:  b3 40 00 00  rd  %y, %i1
a009c39c:  a0 22 40 19  sub  %o1, %i1, %l0
a009c3a0:  9f 34 20 01  srl  %l0, 1, %o7
a009c3a4:  98 06 40 0f  add  %i1, %o7, %o4
a009c3a8:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a009c3ac:  a1 33 20 02  srl  %o4, 2, %l0
a009c3b0:  92 10 20 00  clr  %o1
a009c3b4:  40 00 69 f5  call  0xa00b6b88
a009c3b8:  d0 0e 60 56  ldub  [ %i1 + 0x56 ], %o0
a009c3bc:  82 0a 20 ff  and  %o0, 0xff, %g1
a009c3c0:  80 50 40 18  umul  %g1, %i0, %g0
a009c3c4:  97 40 00 00  rd  %y, %o3
a009c3c8:  90 20 40 0b  sub  %g1, %o3, %o0
a009c3cc:  95 32 20 01  srl  %o0, 1, %o2
a009c3d0:  9a 02 c0 0a  add  %o3, %o2, %o5
a009c3d4:  93 33 60 02  srl  %o5, 2, %o1
a009c3d8:  9e 0a 60 ff  and  %o1, 0xff, %o7
a009c3dc:  80 a4 00 0f  cmp  %l0, %o7
a009c3e0:  12 80 00 2e  bne  0xa009c498
a009c3e4:  d0 06 a3 ec  ld  [ %i2 + 0x3ec ], %o0
a009c3e8:  10 80 00 05  b  0xa009c3fc
a009c3ec:  a0 02 3f a4  add  %o0, -92, %l0
a009c3f0:  e0 0b 20 54  ldub  [ %o4 + 0x54 ], %l0
a009c3f4:  10 bf ff d1  b  0xa009c338
a009c3f8:  e0 2e 60 11  stb  %l0, [ %i1 + 0x11 ]
a009c3fc:  d0 0e 60 56  ldub  [ %i1 + 0x56 ], %o0
a009c400:  40 00 69 e2  call  0xa00b6b88
a009c404:  92 10 20 00  clr  %o1
a009c408:  b4 0a 20 ff  and  %o0, 0xff, %i2
a009c40c:  80 a4 00 1a  cmp  %l0, %i2
a009c410:  02 80 00 12  be  0xa009c458
a009c414:  d0 0e 60 56  ldub  [ %i1 + 0x56 ], %o0
a009c418:  40 00 69 dc  call  0xa00b6b88
a009c41c:  92 10 20 00  clr  %o1
a009c420:  a0 0a 20 ff  and  %o0, 0xff, %l0
a009c424:  80 54 00 18  umul  %l0, %i0, %g0
a009c428:  83 40 00 00  rd  %y, %g1
a009c42c:  96 24 00 01  sub  %l0, %g1, %o3
a009c430:  93 32 e0 01  srl  %o3, 1, %o1
a009c434:  9e 00 40 09  add  %g1, %o1, %o7
a009c438:  b3 33 e0 02  srl  %o7, 2, %i1
a009c43c:  99 2e 60 03  sll  %i1, 3, %o4
a009c440:  94 23 00 19  sub  %o4, %i1, %o2
a009c444:  b4 24 00 0a  sub  %l0, %o2, %i2
a009c448:  b2 0e a0 ff  and  %i2, 0xff, %i1
a009c44c:  b0 10 20 01  mov  1, %i0
a009c450:  40 00 2f 3b  call  0xa00a813c
a009c454:  95 e8 20 01  restore  %g0, 1, %o2
a009c458:  40 00 69 cc  call  0xa00b6b88
a009c45c:  92 10 20 00  clr  %o1
a009c460:  98 0a 20 ff  and  %o0, 0xff, %o4
a009c464:  80 53 00 18  umul  %o4, %i0, %g0
a009c468:  97 40 00 00  rd  %y, %o3
a009c46c:  b0 23 00 0b  sub  %o4, %o3, %i0
a009c470:  9b 36 20 01  srl  %i0, 1, %o5
a009c474:  92 02 c0 0d  add  %o3, %o5, %o1
a009c478:  83 32 60 02  srl  %o1, 2, %g1
a009c47c:  9f 28 60 03  sll  %g1, 3, %o7
a009c480:  b2 23 c0 01  sub  %o7, %g1, %i1
a009c484:  94 23 00 19  sub  %o4, %i1, %o2
a009c488:  b2 0a a0 ff  and  %o2, 0xff, %i1
a009c48c:  b0 10 20 01  mov  1, %i0
a009c490:  40 00 2f 2b  call  0xa00a813c
a009c494:  95 e8 20 00  restore  %g0, 0, %o2
a009c498:  01 00 00 00  nop
a009c49c:  81 c7 e0 08  ret
a009c4a0:  81 e8 00 00  restore
