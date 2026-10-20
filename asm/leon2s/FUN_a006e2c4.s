# leon2s FUN_a006e2c4 0xa006e2c4-0xa006e430 (364 bytes)
a006e2c4:  9d e3 bf 98  save  %sp, -104, %sp
a006e2c8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a006e2cc:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a006e2d0:  9a 14 63 e0  or  %l1, 0x3e0, %o5	! 0xa807d7e0
a006e2d4:  82 5e 61 90  smul  %i1, 0x190, %g1
a006e2d8:  a0 00 40 0d  add  %g1, %o5, %l0
a006e2dc:  c2 0c 20 19  ldub  [ %l0 + 0x19 ], %g1
a006e2e0:  c2 2e 20 12  stb  %g1, [ %i0 + 0x12 ]
a006e2e4:  90 10 00 18  mov  %i0, %o0
a006e2e8:  94 10 00 10  mov  %l0, %o2
a006e2ec:  7f ff ff 7e  call  0xa006e0e4
a006e2f0:  92 10 00 19  mov  %i1, %o1
a006e2f4:  c2 0c 20 2d  ldub  [ %l0 + 0x2d ], %g1
a006e2f8:  80 a0 60 01  cmp  %g1, 1
a006e2fc:  12 80 00 04  bne  0xa006e30c
a006e300:  90 10 00 19  mov  %i1, %o0
a006e304:  10 80 00 16  b  0xa006e35c
a006e308:  c2 14 20 1a  lduh  [ %l0 + 0x1a ], %g1
a006e30c:  40 00 cf 5d  call  0xa00a2080
a006e310:  01 00 00 00  nop
a006e314:  c2 14 20 1a  lduh  [ %l0 + 0x1a ], %g1
a006e318:  80 8a 20 ff  btst  0xff, %o0
a006e31c:  02 80 00 10  be  0xa006e35c
a006e320:  9a 00 40 01  add  %g1, %g1, %o5
a006e324:  da 36 20 02  sth  %o5, [ %i0 + 2 ]
a006e328:  c2 14 20 1e  lduh  [ %l0 + 0x1e ], %g1
a006e32c:  82 00 40 01  add  %g1, %g1, %g1
a006e330:  c2 36 20 06  sth  %g1, [ %i0 + 6 ]
a006e334:  1b 33 33 33  sethi  %hi(0xcccccc00), %o5
a006e338:  c2 14 20 32  lduh  [ %l0 + 0x32 ], %g1
a006e33c:  9a 13 60 cd  or  %o5, 0xcd, %o5
a006e340:  80 50 40 0d  umul  %g1, %o5, %g0
a006e344:  83 40 00 00  rd  %y, %g1
a006e348:  83 28 60 0d  sll  %g1, 0xd, %g1
a006e34c:  83 30 60 10  srl  %g1, 0x10, %g1
a006e350:  82 00 40 01  add  %g1, %g1, %g1
a006e354:  10 80 00 0c  b  0xa006e384
a006e358:  c2 36 20 0a  sth  %g1, [ %i0 + 0xa ]
a006e35c:  c2 36 20 02  sth  %g1, [ %i0 + 2 ]
a006e360:  c2 14 20 1e  lduh  [ %l0 + 0x1e ], %g1
a006e364:  c2 36 20 06  sth  %g1, [ %i0 + 6 ]
a006e368:  03 33 33 33  sethi  %hi(0xcccccc00), %g1
a006e36c:  da 14 20 32  lduh  [ %l0 + 0x32 ], %o5
a006e370:  82 10 60 cd  or  %g1, 0xcd, %g1
a006e374:  80 53 40 01  umul  %o5, %g1, %g0
a006e378:  9b 40 00 00  rd  %y, %o5
a006e37c:  9b 33 60 03  srl  %o5, 3, %o5
a006e380:  da 36 20 0a  sth  %o5, [ %i0 + 0xa ]
a006e384:  9a 14 63 e0  or  %l1, 0x3e0, %o5
a006e388:  82 5e 61 90  smul  %i1, 0x190, %g1
a006e38c:  82 00 40 0d  add  %g1, %o5, %g1
a006e390:  da 10 60 1c  lduh  [ %g1 + 0x1c ], %o5
a006e394:  da 36 20 04  sth  %o5, [ %i0 + 4 ]
a006e398:  c2 10 60 20  lduh  [ %g1 + 0x20 ], %g1
a006e39c:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006e3a0:  c2 36 20 08  sth  %g1, [ %i0 + 8 ]
a006e3a4:  d2 16 20 02  lduh  [ %i0 + 2 ], %o1
a006e3a8:  40 00 13 27  call  0xa0073044
a006e3ac:  90 12 20 a8  or  %o0, 0xa8, %o0
a006e3b0:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006e3b4:  d2 16 20 04  lduh  [ %i0 + 4 ], %o1
a006e3b8:  40 00 13 23  call  0xa0073044
a006e3bc:  90 12 20 c0  or  %o0, 0xc0, %o0
a006e3c0:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006e3c4:  d2 16 20 06  lduh  [ %i0 + 6 ], %o1
a006e3c8:  40 00 13 1f  call  0xa0073044
a006e3cc:  90 12 20 d8  or  %o0, 0xd8, %o0
a006e3d0:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006e3d4:  d2 16 20 08  lduh  [ %i0 + 8 ], %o1
a006e3d8:  40 00 13 1b  call  0xa0073044
a006e3dc:  90 12 20 f0  or  %o0, 0xf0, %o0
a006e3e0:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006e3e4:  d2 16 20 0a  lduh  [ %i0 + 0xa ], %o1
a006e3e8:  40 00 13 17  call  0xa0073044
a006e3ec:  90 12 21 08  or  %o0, 0x108, %o0
a006e3f0:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006e3f4:  d2 0e 20 0c  ldub  [ %i0 + 0xc ], %o1
a006e3f8:  40 00 13 13  call  0xa0073044
a006e3fc:  90 12 21 18  or  %o0, 0x118, %o0
a006e400:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006e404:  d2 0e 20 12  ldub  [ %i0 + 0x12 ], %o1
a006e408:  40 00 13 0f  call  0xa0073044
a006e40c:  90 12 21 30  or  %o0, 0x130, %o0
a006e410:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006e414:  90 12 21 48  or  %o0, 0x148, %o0	! 0xa0065d48
a006e418:  40 00 13 0b  call  0xa0073044
a006e41c:  d2 0e 20 0d  ldub  [ %i0 + 0xd ], %o1
a006e420:  82 10 20 01  mov  1, %g1
a006e424:  c2 2e 20 0f  stb  %g1, [ %i0 + 0xf ]
a006e428:  81 c7 e0 08  ret
a006e42c:  81 e8 00 00  restore
