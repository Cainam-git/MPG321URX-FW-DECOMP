# leon2m FUN_a009d234 0xa009d234-0xa009d4e8 (692 bytes)
a009d234:  9d e3 bf 98  save  %sp, -104, %sp
a009d238:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009d23c:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0	! 0xa802afec
a009d240:  1b 09 24 92  sethi  %hi(0x24924800), %o5
a009d244:  92 02 3f 6e  add  %o0, -146, %o1
a009d248:  82 13 61 25  or  %o5, 0x125, %g1
a009d24c:  80 52 40 01  umul  %o1, %g1, %g0
a009d250:  9f 40 00 00  rd  %y, %o7
a009d254:  a4 22 40 0f  sub  %o1, %o7, %l2
a009d258:  a1 34 a0 01  srl  %l2, 1, %l0
a009d25c:  98 03 c0 10  add  %o7, %l0, %o4
a009d260:  97 33 20 02  srl  %o4, 2, %o3
a009d264:  95 2a e0 03  sll  %o3, 3, %o2
a009d268:  9a 22 80 0b  sub  %o2, %o3, %o5
a009d26c:  90 22 40 0d  sub  %o1, %o5, %o0
a009d270:  40 00 30 53  call  0xa00a93bc
a009d274:  90 0a 20 ff  and  %o0, 0xff, %o0
a009d278:  03 23 4f 72  sethi  %hi(0x8d3dc800), %g1
a009d27c:  a0 10 63 09  or  %g1, 0x309, %l0	! 0x8d3dcb09
a009d280:  a4 10 20 00  clr  %l2
a009d284:  d0 14 63 ee  lduh  [ %l1 + 0x3ee ], %o0
a009d288:  9e 02 3f 8a  add  %o0, -118, %o7
a009d28c:  80 5b c0 10  smul  %o7, %l0, %g0
a009d290:  9b 40 00 00  rd  %y, %o5
a009d294:  82 03 40 0f  add  %o5, %o7, %g1
a009d298:  97 38 60 04  sra  %g1, 4, %o3
a009d29c:  99 3b e0 1f  sra  %o7, 0x1f, %o4
a009d2a0:  9a 22 c0 0c  sub  %o3, %o4, %o5
a009d2a4:  95 2b 60 03  sll  %o5, 3, %o2
a009d2a8:  92 22 80 0d  sub  %o2, %o5, %o1
a009d2ac:  83 2a 60 02  sll  %o1, 2, %g1
a009d2b0:  98 00 40 0d  add  %g1, %o5, %o4
a009d2b4:  94 23 c0 0c  sub  %o7, %o4, %o2
a009d2b8:  96 02 a0 92  add  %o2, 0x92, %o3
a009d2bc:  d6 24 63 ec  st  %o3, [ %l1 + 0x3ec ]
a009d2c0:  40 00 36 9c  call  0xa00aad30
a009d2c4:  90 0a a0 ff  and  %o2, 0xff, %o0
a009d2c8:  92 0a 20 ff  and  %o0, 0xff, %o1
a009d2cc:  80 a2 60 01  cmp  %o1, 1
a009d2d0:  32 bf ff ee  bne,a   0xa009d288
a009d2d4:  d0 14 63 ee  lduh  [ %l1 + 0x3ee ], %o0
a009d2d8:  d8 04 63 ec  ld  [ %l1 + 0x3ec ], %o4
a009d2dc:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009d2e0:  9e 14 22 90  or  %l0, 0x290, %o7	! 0xa802d290
a009d2e4:  92 03 20 6e  add  %o4, 0x6e, %o1
a009d2e8:  80 a3 20 98  cmp  %o4, 0x98
a009d2ec:  02 80 00 60  be  0xa009d46c
a009d2f0:  d2 2b e0 08  stb  %o1, [ %o7 + 8 ]
a009d2f4:  80 a3 20 9f  cmp  %o4, 0x9f
a009d2f8:  02 80 00 64  be  0xa009d488
a009d2fc:  01 00 00 00  nop
a009d300:  80 a3 20 a6  cmp  %o4, 0xa6
a009d304:  02 80 00 65  be  0xa009d498
a009d308:  01 00 00 00  nop
a009d30c:  80 a3 20 ad  cmp  %o4, 0xad
a009d310:  02 80 00 66  be  0xa009d4a8
a009d314:  01 00 00 00  nop
a009d318:  80 a3 20 ae  cmp  %o4, 0xae
a009d31c:  02 80 00 6f  be  0xa009d4d8
a009d320:  01 00 00 00  nop
a009d324:  80 8c a0 ff  btst  0xff, %l2
a009d328:  12 80 00 33  bne  0xa009d3f4
a009d32c:  25 2a 00 97  sethi  %hi(0xa8025c00), %l2
a009d330:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a009d334:  21 09 24 92  sethi  %hi(0x24924800), %l0
a009d338:  94 02 3f 6e  add  %o0, -146, %o2
a009d33c:  a0 14 21 25  or  %l0, 0x125, %l0
a009d340:  80 52 80 10  umul  %o2, %l0, %g0
a009d344:  97 40 00 00  rd  %y, %o3
a009d348:  98 22 80 0b  sub  %o2, %o3, %o4
a009d34c:  9b 33 20 01  srl  %o4, 1, %o5
a009d350:  92 02 c0 0d  add  %o3, %o5, %o1
a009d354:  83 32 60 02  srl  %o1, 2, %g1
a009d358:  9f 28 60 03  sll  %g1, 3, %o7
a009d35c:  98 23 c0 01  sub  %o7, %g1, %o4
a009d360:  96 22 80 0c  sub  %o2, %o4, %o3
a009d364:  90 0a e0 ff  and  %o3, 0xff, %o0
a009d368:  40 00 30 ba  call  0xa00a9650
a009d36c:  92 10 20 01  mov  1, %o1
a009d370:  40 00 40 3c  call  0xa00ad460
a009d374:  01 00 00 00  nop
a009d378:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a009d37c:  d4 0c a0 56  ldub  [ %l2 + 0x56 ], %o2
a009d380:  96 02 3f 6e  add  %o0, -146, %o3
a009d384:  80 52 80 10  umul  %o2, %l0, %g0
a009d388:  93 40 00 00  rd  %y, %o1
a009d38c:  80 52 c0 10  umul  %o3, %l0, %g0
a009d390:  9f 40 00 00  rd  %y, %o7
a009d394:  a4 22 80 09  sub  %o2, %o1, %l2
a009d398:  a3 34 a0 01  srl  %l2, 1, %l1
a009d39c:  9a 22 c0 0f  sub  %o3, %o7, %o5
a009d3a0:  98 02 40 11  add  %o1, %l1, %o4
a009d3a4:  83 33 60 01  srl  %o5, 1, %g1
a009d3a8:  90 03 c0 01  add  %o7, %g1, %o0
a009d3ac:  99 33 20 02  srl  %o4, 2, %o4
a009d3b0:  a5 32 20 02  srl  %o0, 2, %l2
a009d3b4:  a2 0b 20 ff  and  %o4, 0xff, %l1
a009d3b8:  80 a4 80 11  cmp  %l2, %l1
a009d3bc:  02 80 00 04  be  0xa009d3cc
a009d3c0:  80 a2 c0 0a  cmp  %o3, %o2
a009d3c4:  40 00 6d 3d  call  0xa00b88b8
a009d3c8:  81 e8 00 00  restore
a009d3cc:  02 80 00 3b  be  0xa009d4b8
a009d3d0:  97 2b 20 03  sll  %o4, 3, %o3
a009d3d4:  92 22 c0 0c  sub  %o3, %o4, %o1
a009d3d8:  82 22 80 09  sub  %o2, %o1, %g1
a009d3dc:  92 08 60 ff  and  %g1, 0xff, %o1
a009d3e0:  90 10 20 01  mov  1, %o0
a009d3e4:  40 00 2b 56  call  0xa00a813c
a009d3e8:  94 10 20 01  mov  1, %o2
a009d3ec:  40 00 6d 33  call  0xa00b88b8
a009d3f0:  81 e8 00 00  restore
a009d3f4:  15 09 24 92  sethi  %hi(0x24924800), %o2
a009d3f8:  82 12 a1 25  or  %o2, 0x125, %g1	! 0x24924925
a009d3fc:  9e 14 22 90  or  %l0, 0x290, %o7
a009d400:  d0 0b e0 08  ldub  [ %o7 + 8 ], %o0
a009d404:  d4 0c a0 56  ldub  [ %l2 + 0x56 ], %o2
a009d408:  80 52 80 01  umul  %o2, %g1, %g0
a009d40c:  9f 40 00 00  rd  %y, %o7
a009d410:  80 52 00 01  umul  %o0, %g1, %g0
a009d414:  93 40 00 00  rd  %y, %o1
a009d418:  98 22 00 09  sub  %o0, %o1, %o4
a009d41c:  96 22 80 0f  sub  %o2, %o7, %o3
a009d420:  a1 33 20 01  srl  %o4, 1, %l0
a009d424:  9b 32 e0 01  srl  %o3, 1, %o5
a009d428:  90 02 40 10  add  %o1, %l0, %o0
a009d42c:  96 03 c0 0d  add  %o7, %o5, %o3
a009d430:  83 32 20 02  srl  %o0, 2, %g1
a009d434:  97 32 e0 02  srl  %o3, 2, %o3
a009d438:  98 08 60 ff  and  %g1, 0xff, %o4
a009d43c:  a0 0a e0 ff  and  %o3, 0xff, %l0
a009d440:  80 a3 00 10  cmp  %o4, %l0
a009d444:  32 bf ff bc  bne,a   0xa009d334
a009d448:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a009d44c:  a1 2a e0 03  sll  %o3, 3, %l0
a009d450:  92 24 00 0b  sub  %l0, %o3, %o1
a009d454:  9a 22 80 09  sub  %o2, %o1, %o5
a009d458:  90 0b 60 ff  and  %o5, 0xff, %o0
a009d45c:  40 00 30 7d  call  0xa00a9650
a009d460:  92 10 20 00  clr  %o1
a009d464:  10 bf ff b4  b  0xa009d334
a009d468:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a009d46c:  40 00 2e 07  call  0xa00a8c88
a009d470:  01 00 00 00  nop
a009d474:  90 10 20 00  clr  %o0	! 0x0
a009d478:  40 00 2c d5  call  0xa00a87cc
a009d47c:  a4 10 20 01  mov  1, %l2
a009d480:  10 bf ff aa  b  0xa009d328
a009d484:  80 8c a0 ff  btst  0xff, %l2
a009d488:  40 00 2e 00  call  0xa00a8c88
a009d48c:  01 00 00 00  nop
a009d490:  10 bf ff fa  b  0xa009d478
a009d494:  90 10 20 01  mov  1, %o0	! 0x1
a009d498:  40 00 2d fc  call  0xa00a8c88
a009d49c:  01 00 00 00  nop
a009d4a0:  10 bf ff f6  b  0xa009d478
a009d4a4:  90 10 20 02  mov  2, %o0	! 0x2
a009d4a8:  40 00 2d f8  call  0xa00a8c88
a009d4ac:  01 00 00 00  nop
a009d4b0:  10 bf ff f2  b  0xa009d478
a009d4b4:  90 10 20 03  mov  3, %o0	! 0x3
a009d4b8:  9f 2b 20 03  sll  %o4, 3, %o7
a009d4bc:  a4 23 c0 0c  sub  %o7, %o4, %l2
a009d4c0:  a2 22 80 12  sub  %o2, %l2, %l1
a009d4c4:  92 0c 60 ff  and  %l1, 0xff, %o1
a009d4c8:  90 10 20 01  mov  1, %o0
a009d4cc:  40 00 2b 1c  call  0xa00a813c
a009d4d0:  94 10 20 00  clr  %o2
a009d4d4:  30 bf ff c6  b,a   0xa009d3ec
a009d4d8:  40 00 2d ec  call  0xa00a8c88
a009d4dc:  01 00 00 00  nop
a009d4e0:  10 bf ff e6  b  0xa009d478
a009d4e4:  90 10 20 04  mov  4, %o0	! 0x4
