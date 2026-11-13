# leon2s FUN_a00d8300 0xa00d8300-0xa00d84f4 (500 bytes)
a00d8300:  9d e3 bf 80  save  %sp, -128, %sp
a00d8304:  92 10 20 00  clr  %o1
a00d8308:  c0 37 bf e8  clrh  [ %fp + -24 ]
a00d830c:  90 07 bf e8  add  %fp, -24, %o0
a00d8310:  94 10 20 01  mov  1, %o2
a00d8314:  7f ff fc 28  call  0xa00d73b4
a00d8318:  96 10 20 12  mov  0x12, %o3
a00d831c:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a00d8320:  19 1f c0 00  sethi  %hi(0x7f000000), %o4
a00d8324:  98 28 40 0c  andn  %g1, %o4, %o4
a00d8328:  03 04 00 00  sethi  %hi(0x10000000), %g1
a00d832c:  98 13 00 01  or  %o4, %g1, %o4
a00d8330:  03 00 3c 00  sethi  %hi(0xf00000), %g1
a00d8334:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a00d8338:  9a 0b 40 01  and  %o5, %g1, %o5
a00d833c:  92 2b 00 01  andn  %o4, %g1, %o1
a00d8340:  92 12 40 0d  or  %o1, %o5, %o1
a00d8344:  83 32 60 10  srl  %o1, 0x10, %g1
a00d8348:  82 08 60 f0  and  %g1, 0xf0, %g1
a00d834c:  80 a0 60 10  cmp  %g1, 0x10
a00d8350:  d2 27 bf e0  st  %o1, [ %fp + -32 ]
a00d8354:  12 80 00 10  bne  0xa00d8394
a00d8358:  a0 10 20 00  clr  %l0
a00d835c:  90 10 20 00  clr  %o0
a00d8360:  92 10 20 90  mov  0x90, %o1
a00d8364:  94 10 20 01  mov  1, %o2
a00d8368:  96 10 20 01  mov  1, %o3
a00d836c:  40 3a f8 25  call  0xa0f96400
a00d8370:  98 07 bf f0  add  %fp, -16, %o4
a00d8374:  80 8a 20 ff  btst  0xff, %o0
a00d8378:  32 80 00 05  bne,a   0xa00d838c
a00d837c:  d8 0f bf f0  ldub  [ %fp + -16 ], %o4
a00d8380:  c0 2f bf f0  clrb  [ %fp + -16 ]
a00d8384:  c0 2f bf f1  clrb  [ %fp + -15 ]
a00d8388:  d8 0f bf f0  ldub  [ %fp + -16 ], %o4
a00d838c:  10 80 00 1a  b  0xa00d83f4
a00d8390:  da 0f bf f1  ldub  [ %fp + -15 ], %o5
a00d8394:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d8398:  da 08 60 32  ldub  [ %g1 + 0x32 ], %o5	! 0xa8078832
a00d839c:  15 28 02 ce  sethi  %hi(0xa00b3800), %o2
a00d83a0:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d83a4:  94 12 a0 3c  or  %o2, 0x3c, %o2
a00d83a8:  9b 2b 60 02  sll  %o5, 2, %o5
a00d83ac:  82 10 60 a4  or  %g1, 0xa4, %g1
a00d83b0:  d6 00 40 0d  ld  [ %g1 + %o5 ], %o3
a00d83b4:  d8 12 a0 5a  lduh  [ %o2 + 0x5a ], %o4
a00d83b8:  99 2b 20 02  sll  %o4, 2, %o4
a00d83bc:  da 12 a0 5c  lduh  [ %o2 + 0x5c ], %o5
a00d83c0:  d8 02 c0 0c  ld  [ %o3 + %o4 ], %o4
a00d83c4:  9b 2b 60 02  sll  %o5, 2, %o5
a00d83c8:  c2 12 a0 58  lduh  [ %o2 + 0x58 ], %g1
a00d83cc:  da 02 c0 0d  ld  [ %o3 + %o5 ], %o5
a00d83d0:  83 28 60 02  sll  %g1, 2, %g1
a00d83d4:  c2 02 c0 01  ld  [ %o3 + %g1 ], %g1
a00d83d8:  80 88 60 01  btst  1, %g1
a00d83dc:  02 80 00 04  be  0xa00d83ec
a00d83e0:  03 00 00 40  sethi  %hi(0x10000), %g1
a00d83e4:  10 80 00 03  b  0xa00d83f0
a00d83e8:  82 12 40 01  or  %o1, %g1, %g1
a00d83ec:  82 2a 40 01  andn  %o1, %g1, %g1
a00d83f0:  c2 27 bf e0  st  %g1, [ %fp + -32 ]
a00d83f4:  98 0b 20 ff  and  %o4, 0xff, %o4
a00d83f8:  80 a3 20 06  cmp  %o4, 6
a00d83fc:  12 80 00 04  bne  0xa00d840c
a00d8400:  80 a3 20 0a  cmp  %o4, 0xa
a00d8404:  10 80 00 14  b  0xa00d8454
a00d8408:  a0 10 20 00  clr  %l0
a00d840c:  12 80 00 04  bne  0xa00d841c
a00d8410:  80 a3 20 14  cmp  %o4, 0x14
a00d8414:  10 80 00 10  b  0xa00d8454
a00d8418:  a0 10 20 03  mov  3, %l0
a00d841c:  12 80 00 04  bne  0xa00d842c
a00d8420:  80 a3 20 1e  cmp  %o4, 0x1e
a00d8424:  10 80 00 0c  b  0xa00d8454
a00d8428:  a0 10 20 06  mov  6, %l0
a00d842c:  12 80 00 04  bne  0xa00d843c
a00d8430:  80 a3 20 01  cmp  %o4, 1
a00d8434:  10 80 00 08  b  0xa00d8454
a00d8438:  a0 10 20 09  mov  9, %l0
a00d843c:  12 80 00 04  bne  0xa00d844c
a00d8440:  80 a3 20 04  cmp  %o4, 4
a00d8444:  10 80 00 04  b  0xa00d8454
a00d8448:  a0 10 20 0c  mov  0xc, %l0
a00d844c:  22 80 00 02  be,a   0xa00d8454
a00d8450:  a0 10 20 0f  mov  0xf, %l0
a00d8454:  9a 0b 60 0f  and  %o5, 0xf, %o5
a00d8458:  80 a3 60 02  cmp  %o5, 2
a00d845c:  12 80 00 04  bne  0xa00d846c
a00d8460:  80 a3 60 04  cmp  %o5, 4
a00d8464:  10 80 00 04  b  0xa00d8474
a00d8468:  a0 04 20 01  inc  %l0
a00d846c:  22 80 00 02  be,a   0xa00d8474
a00d8470:  a0 04 20 02  add  %l0, 2, %l0
a00d8474:  c2 17 bf e0  lduh  [ %fp + -32 ], %g1
a00d8478:  82 08 60 f0  and  %g1, 0xf0, %g1
a00d847c:  80 a0 60 80  cmp  %g1, 0x80
a00d8480:  12 80 00 0e  bne  0xa00d84b8
a00d8484:  82 0c 20 ff  and  %l0, 0xff, %g1
a00d8488:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00d848c:  c2 10 63 f8  lduh  [ %g1 + 0x3f8 ], %g1	! 0xa80787f8
a00d8490:  80 a0 60 00  cmp  %g1, 0
a00d8494:  02 80 00 09  be  0xa00d84b8
a00d8498:  82 0c 20 ff  and  %l0, 0xff, %g1
a00d849c:  1b 2a 01 d8  sethi  %hi(0xa8076000), %o5
a00d84a0:  82 00 40 01  add  %g1, %g1, %g1
a00d84a4:  9a 13 60 c8  or  %o5, 0xc8, %o5
a00d84a8:  c2 13 40 01  lduh  [ %o5 + %g1 ], %g1
a00d84ac:  c2 37 bf e2  sth  %g1, [ %fp + -30 ]
a00d84b0:  10 80 00 08  b  0xa00d84d0
a00d84b4:  c0 37 bf e4  clrh  [ %fp + -28 ]
a00d84b8:  1b 2a 01 d8  sethi  %hi(0xa8076000), %o5
a00d84bc:  82 00 40 01  add  %g1, %g1, %g1
a00d84c0:  9a 13 60 c8  or  %o5, 0xc8, %o5
a00d84c4:  c2 13 40 01  lduh  [ %o5 + %g1 ], %g1
a00d84c8:  c2 37 bf e4  sth  %g1, [ %fp + -28 ]
a00d84cc:  c2 37 bf e2  sth  %g1, [ %fp + -30 ]
a00d84d0:  90 07 bf e0  add  %fp, -32, %o0
a00d84d4:  92 10 20 02  mov  2, %o1
a00d84d8:  94 10 20 01  mov  1, %o2
a00d84dc:  96 10 20 02  mov  2, %o3
a00d84e0:  7f ff fd 0f  call  0xa00d791c
a00d84e4:  98 10 20 06  mov  6, %o4
a00d84e8:  01 00 00 00  nop
a00d84ec:  81 c7 e0 08  ret
a00d84f0:  81 e8 00 00  restore
