# leon2m FUN_a010d244 0xa010d244-0xa010d530 (748 bytes)
a010d244:  9d e3 bf 98  save  %sp, -104, %sp
a010d248:  9e 0e 20 ff  and  %i0, 0xff, %o7
a010d24c:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010d250:  9a 10 00 1a  mov  %i2, %o5
a010d254:  96 10 00 1b  mov  %i3, %o3
a010d258:  80 a3 e0 01  cmp  %o7, 1
a010d25c:  02 80 00 06  be  0xa010d274
a010d260:  82 10 63 c4  or  %g1, 0x3c4, %g1
a010d264:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a010d268:  80 a3 e0 02  cmp  %o7, 2
a010d26c:  02 80 00 ac  be  0xa010d51c
a010d270:  82 16 a3 44  or  %i2, 0x344, %g1
a010d274:  d6 28 60 3a  stb  %o3, [ %g1 + 0x3a ]
a010d278:  f2 28 60 38  stb  %i1, [ %g1 + 0x38 ]
a010d27c:  da 28 60 39  stb  %o5, [ %g1 + 0x39 ]
a010d280:  80 a3 e0 02  cmp  %o7, 2
a010d284:  08 80 00 03  bleu  0xa010d290
a010d288:  82 10 00 18  mov  %i0, %g1
a010d28c:  82 10 20 00  clr  %g1
a010d290:  ba 0e 60 ff  and  %i1, 0xff, %i5
a010d294:  b4 08 60 ff  and  %g1, 0xff, %i2
a010d298:  b7 2f 60 0a  sll  %i5, 0xa, %i3
a010d29c:  83 2e a0 02  sll  %i2, 2, %g1
a010d2a0:  19 00 06 6b  sethi  %hi(0x19ac00), %o4
a010d2a4:  b8 26 c0 1d  sub  %i3, %i5, %i4
a010d2a8:  33 14 7a e1  sethi  %hi(0x51eb8400), %i1
a010d2ac:  b4 13 22 d8  or  %o4, 0x2d8, %i2
a010d2b0:  b8 07 20 32  add  %i4, 0x32, %i4
a010d2b4:  ba 16 61 1f  or  %i1, 0x11f, %i5
a010d2b8:  f6 06 80 01  ld  [ %i2 + %g1 ], %i3
a010d2bc:  80 57 00 1d  umul  %i4, %i5, %g0
a010d2c0:  b3 40 00 00  rd  %y, %i1
a010d2c4:  c2 06 e0 f4  ld  [ %i3 + 0xf4 ], %g1
a010d2c8:  ba 08 7c 00  and  %g1, -1024, %i5
a010d2cc:  b9 36 60 05  srl  %i1, 5, %i4
a010d2d0:  80 a3 e0 02  cmp  %o7, 2
a010d2d4:  08 80 00 5e  bleu  0xa010d44c
a010d2d8:  b2 17 40 1c  or  %i5, %i4, %i1
a010d2dc:  b6 10 00 1a  mov  %i2, %i3
a010d2e0:  b8 10 20 00  clr  %i4
a010d2e4:  83 2f 20 02  sll  %i4, 2, %g1
a010d2e8:  f4 06 c0 01  ld  [ %i3 + %g1 ], %i2
a010d2ec:  b8 07 20 01  inc  %i4
a010d2f0:  f2 26 a0 f4  st  %i1, [ %i2 + 0xf4 ]
a010d2f4:  80 a7 20 02  cmp  %i4, 2
a010d2f8:  28 bf ff fc  bleu,a   0xa010d2e8
a010d2fc:  83 2f 20 02  sll  %i4, 2, %g1
a010d300:  80 a3 e0 02  cmp  %o7, 2
a010d304:  18 80 00 58  bgu  0xa010d464
a010d308:  15 00 06 6b  sethi  %hi(0x19ac00), %o2
a010d30c:  82 12 a2 cc  or  %o2, 0x2cc, %g1	! 0x19aecc
a010d310:  b7 2b e0 02  sll  %o7, 2, %i3
a010d314:  f8 00 40 1b  ld  [ %g1 + %i3 ], %i4
a010d318:  f2 27 20 f4  st  %i1, [ %i4 + 0xf4 ]
a010d31c:  80 a3 e0 02  cmp  %o7, 2
a010d320:  08 80 00 03  bleu  0xa010d32c
a010d324:  82 10 00 18  mov  %i0, %g1
a010d328:  82 10 20 00  clr  %g1
a010d32c:  ba 0b 60 ff  and  %o5, 0xff, %i5
a010d330:  b2 08 60 ff  and  %g1, 0xff, %i1
a010d334:  b7 2f 60 0a  sll  %i5, 0xa, %i3
a010d338:  83 2e 60 02  sll  %i1, 2, %g1
a010d33c:  b8 26 c0 1d  sub  %i3, %i5, %i4
a010d340:  35 14 7a e1  sethi  %hi(0x51eb8400), %i2
a010d344:  b2 13 22 d8  or  %o4, 0x2d8, %i1
a010d348:  b8 07 20 32  add  %i4, 0x32, %i4
a010d34c:  ba 16 a1 1f  or  %i2, 0x11f, %i5
a010d350:  f6 06 40 01  ld  [ %i1 + %g1 ], %i3
a010d354:  80 57 00 1d  umul  %i4, %i5, %g0
a010d358:  b5 40 00 00  rd  %y, %i2
a010d35c:  c2 06 e0 f8  ld  [ %i3 + 0xf8 ], %g1
a010d360:  ba 08 7c 00  and  %g1, -1024, %i5
a010d364:  b9 36 a0 05  srl  %i2, 5, %i4
a010d368:  80 a3 e0 02  cmp  %o7, 2
a010d36c:  08 80 00 49  bleu  0xa010d490
a010d370:  b4 17 40 1c  or  %i5, %i4, %i2
a010d374:  b6 10 00 19  mov  %i1, %i3
a010d378:  b8 10 20 00  clr  %i4
a010d37c:  83 2f 20 02  sll  %i4, 2, %g1
a010d380:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010d384:  b8 07 20 01  inc  %i4
a010d388:  f4 26 60 f8  st  %i2, [ %i1 + 0xf8 ]
a010d38c:  80 a7 20 02  cmp  %i4, 2
a010d390:  28 bf ff fc  bleu,a   0xa010d380
a010d394:  83 2f 20 02  sll  %i4, 2, %g1
a010d398:  80 a3 e0 02  cmp  %o7, 2
a010d39c:  18 80 00 44  bgu  0xa010d4ac
a010d3a0:  3b 00 06 6b  sethi  %hi(0x19ac00), %i5
a010d3a4:  ba 12 a2 cc  or  %o2, 0x2cc, %i5
a010d3a8:  b7 2b e0 02  sll  %o7, 2, %i3
a010d3ac:  f8 07 40 1b  ld  [ %i5 + %i3 ], %i4
a010d3b0:  f4 27 20 f8  st  %i2, [ %i4 + 0xf8 ]
a010d3b4:  80 a3 e0 02  cmp  %o7, 2
a010d3b8:  38 80 00 02  bgu,a   0xa010d3c0
a010d3bc:  b0 10 20 00  clr  %i0
a010d3c0:  b8 0a e0 ff  and  %o3, 0xff, %i4
a010d3c4:  b6 0e 20 ff  and  %i0, 0xff, %i3
a010d3c8:  b5 2f 20 0a  sll  %i4, 0xa, %i2
a010d3cc:  b0 26 80 1c  sub  %i2, %i4, %i0
a010d3d0:  bb 2e e0 02  sll  %i3, 2, %i5
a010d3d4:  03 14 7a e1  sethi  %hi(0x51eb8400), %g1
a010d3d8:  b4 13 22 d8  or  %o4, 0x2d8, %i2
a010d3dc:  b2 10 61 1f  or  %g1, 0x11f, %i1
a010d3e0:  f6 06 80 1d  ld  [ %i2 + %i5 ], %i3
a010d3e4:  b8 06 20 32  add  %i0, 0x32, %i4
a010d3e8:  80 57 00 19  umul  %i4, %i1, %g0
a010d3ec:  b1 40 00 00  rd  %y, %i0
a010d3f0:  fa 06 e0 fc  ld  [ %i3 + 0xfc ], %i5
a010d3f4:  82 0f 7c 00  and  %i5, -1024, %g1
a010d3f8:  b3 36 20 05  srl  %i0, 5, %i1
a010d3fc:  80 a3 e0 02  cmp  %o7, 2
a010d400:  08 80 00 36  bleu  0xa010d4d8
a010d404:  b0 10 40 19  or  %g1, %i1, %i0
a010d408:  b6 10 00 1a  mov  %i2, %i3
a010d40c:  b8 10 20 00  clr  %i4
a010d410:  83 2f 20 02  sll  %i4, 2, %g1
a010d414:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010d418:  b8 07 20 01  inc  %i4
a010d41c:  f0 26 60 fc  st  %i0, [ %i1 + 0xfc ]
a010d420:  80 a7 20 02  cmp  %i4, 2
a010d424:  28 bf ff fc  bleu,a   0xa010d414
a010d428:  83 2f 20 02  sll  %i4, 2, %g1
a010d42c:  80 a3 e0 02  cmp  %o7, 2
a010d430:  18 80 00 31  bgu  0xa010d4f4
a010d434:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a010d438:  b6 12 a2 cc  or  %o2, 0x2cc, %i3
a010d43c:  bb 2b e0 02  sll  %o7, 2, %i5
a010d440:  f8 06 c0 1d  ld  [ %i3 + %i5 ], %i4
a010d444:  f0 27 20 fc  st  %i0, [ %i4 + 0xfc ]
a010d448:  30 80 00 38  b,a   0xa010d528
a010d44c:  b7 2b e0 02  sll  %o7, 2, %i3
a010d450:  f8 06 80 1b  ld  [ %i2 + %i3 ], %i4
a010d454:  f2 27 20 f4  st  %i1, [ %i4 + 0xf4 ]
a010d458:  80 a3 e0 02  cmp  %o7, 2
a010d45c:  08 bf ff ac  bleu  0xa010d30c
a010d460:  15 00 06 6b  sethi  %hi(0x19ac00), %o2
a010d464:  b8 10 20 00  clr  %i4
a010d468:  b6 12 a2 cc  or  %o2, 0x2cc, %i3
a010d46c:  b5 2f 20 02  sll  %i4, 2, %i2
a010d470:  fa 06 c0 1a  ld  [ %i3 + %i2 ], %i5
a010d474:  b8 07 20 01  inc  %i4
a010d478:  f2 27 60 f4  st  %i1, [ %i5 + 0xf4 ]
a010d47c:  80 a7 20 02  cmp  %i4, 2
a010d480:  08 bf ff fc  bleu  0xa010d470
a010d484:  b5 2f 20 02  sll  %i4, 2, %i2
a010d488:  10 bf ff a6  b  0xa010d320
a010d48c:  80 a3 e0 02  cmp  %o7, 2
a010d490:  b7 2b e0 02  sll  %o7, 2, %i3
a010d494:  f8 06 40 1b  ld  [ %i1 + %i3 ], %i4
a010d498:  f4 27 20 f8  st  %i2, [ %i4 + 0xf8 ]
a010d49c:  80 a3 e0 02  cmp  %o7, 2
a010d4a0:  08 bf ff c2  bleu  0xa010d3a8
a010d4a4:  ba 12 a2 cc  or  %o2, 0x2cc, %i5
a010d4a8:  3b 00 06 6b  sethi  %hi(0x19ac00), %i5
a010d4ac:  b6 17 62 cc  or  %i5, 0x2cc, %i3	! 0x19aecc
a010d4b0:  b8 10 20 00  clr  %i4
a010d4b4:  83 2f 20 02  sll  %i4, 2, %g1
a010d4b8:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010d4bc:  b8 07 20 01  inc  %i4
a010d4c0:  f4 26 60 f8  st  %i2, [ %i1 + 0xf8 ]
a010d4c4:  80 a7 20 02  cmp  %i4, 2
a010d4c8:  08 bf ff fc  bleu  0xa010d4b8
a010d4cc:  83 2f 20 02  sll  %i4, 2, %g1
a010d4d0:  10 bf ff ba  b  0xa010d3b8
a010d4d4:  80 a3 e0 02  cmp  %o7, 2
a010d4d8:  b7 2b e0 02  sll  %o7, 2, %i3
a010d4dc:  fa 06 80 1b  ld  [ %i2 + %i3 ], %i5
a010d4e0:  f0 27 60 fc  st  %i0, [ %i5 + 0xfc ]
a010d4e4:  80 a3 e0 02  cmp  %o7, 2
a010d4e8:  08 bf ff d5  bleu  0xa010d43c
a010d4ec:  b6 12 a2 cc  or  %o2, 0x2cc, %i3
a010d4f0:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a010d4f4:  b6 16 a2 cc  or  %i2, 0x2cc, %i3	! 0x19aecc
a010d4f8:  b8 10 20 00  clr  %i4
a010d4fc:  83 2f 20 02  sll  %i4, 2, %g1
a010d500:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010d504:  b8 07 20 01  inc  %i4
a010d508:  f0 26 60 fc  st  %i0, [ %i1 + 0xfc ]
a010d50c:  80 a7 20 02  cmp  %i4, 2
a010d510:  08 bf ff fc  bleu  0xa010d500
a010d514:  83 2f 20 02  sll  %i4, 2, %g1
a010d518:  30 80 00 04  b,a   0xa010d528
a010d51c:  37 2a 00 b5  sethi  %hi(0xa802d400), %i3
a010d520:  10 bf ff 55  b  0xa010d274
a010d524:  82 16 e3 84  or  %i3, 0x384, %g1	! 0xa802d784
a010d528:  81 c7 e0 08  ret
a010d52c:  81 e8 00 00  restore
