# leon2m FUN_a014e320 0xa014e320-0xa014e478 (344 bytes)
a014e320:  9d e3 bf 90  save  %sp, -112, %sp
a014e324:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014e328:  a4 10 63 d0  or  %g1, 0x3d0, %l2	! 0xa802e3d0
a014e32c:  7f ff 83 82  call  0xa012f134
a014e330:  d0 0c a0 18  ldub  [ %l2 + 0x18 ], %o0
a014e334:  a2 10 00 12  mov  %l2, %l1
a014e338:  92 10 20 02  mov  2, %o1
a014e33c:  80 8a 20 ff  btst  0xff, %o0
a014e340:  12 80 00 10  bne  0xa014e380
a014e344:  94 07 bf f0  add  %fp, -16, %o2
a014e348:  7f ff 83 7b  call  0xa012f134
a014e34c:  d0 0c 60 18  ldub  [ %l1 + 0x18 ], %o0
a014e350:  92 10 20 10  mov  0x10, %o1
a014e354:  80 8a 20 ff  btst  0xff, %o0
a014e358:  12 80 00 20  bne  0xa014e3d8
a014e35c:  94 07 bf f0  add  %fp, -16, %o2
a014e360:  7f ff 83 75  call  0xa012f134
a014e364:  d0 0c a0 18  ldub  [ %l2 + 0x18 ], %o0
a014e368:  92 10 20 80  mov  0x80, %o1
a014e36c:  80 8a 20 ff  btst  0xff, %o0
a014e370:  02 80 00 40  be  0xa014e470
a014e374:  94 07 bf f0  add  %fp, -16, %o2
a014e378:  10 80 00 2f  b  0xa014e434
a014e37c:  d6 0c a0 18  ldub  [ %l2 + 0x18 ], %o3
a014e380:  de 0c a0 18  ldub  [ %l2 + 0x18 ], %o7
a014e384:  19 00 00 40  sethi  %hi(0x10000), %o4
a014e388:  9a 0b e0 0f  and  %o7, 0xf, %o5
a014e38c:  97 2b 00 0d  sll  %o4, %o5, %o3
a014e390:  7f ff 80 70  call  0xa012e550
a014e394:  91 32 e0 10  srl  %o3, 0x10, %o0
a014e398:  80 8a 20 ff  btst  0xff, %o0
a014e39c:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014e3a0:  02 bf ff ea  be  0xa014e348
a014e3a4:  98 12 21 f0  or  %o0, 0x1f0, %o4	! 0xa802e1f0
a014e3a8:  d4 0f bf f0  ldub  [ %fp + -16 ], %o2
a014e3ac:  d2 0f bf f1  ldub  [ %fp + -15 ], %o1
a014e3b0:  e0 0f bf f2  ldub  [ %fp + -14 ], %l0
a014e3b4:  d4 2b 20 06  stb  %o2, [ %o4 + 6 ]
a014e3b8:  d2 2b 20 07  stb  %o1, [ %o4 + 7 ]
a014e3bc:  e0 2b 20 08  stb  %l0, [ %o4 + 8 ]
a014e3c0:  7f ff 83 5d  call  0xa012f134
a014e3c4:  d0 0c 60 18  ldub  [ %l1 + 0x18 ], %o0
a014e3c8:  92 10 20 10  mov  0x10, %o1
a014e3cc:  80 8a 20 ff  btst  0xff, %o0
a014e3d0:  02 bf ff e4  be  0xa014e360
a014e3d4:  94 07 bf f0  add  %fp, -16, %o2
a014e3d8:  d8 0c 60 18  ldub  [ %l1 + 0x18 ], %o4
a014e3dc:  82 0b 20 0f  and  %o4, 0xf, %g1
a014e3e0:  17 00 00 40  sethi  %hi(0x10000), %o3
a014e3e4:  91 2a c0 01  sll  %o3, %g1, %o0
a014e3e8:  7f ff 80 5a  call  0xa012e550
a014e3ec:  91 32 20 10  srl  %o0, 0x10, %o0
a014e3f0:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a014e3f4:  80 8a 20 ff  btst  0xff, %o0
a014e3f8:  02 bf ff da  be  0xa014e360
a014e3fc:  98 14 61 f0  or  %l1, 0x1f0, %o4
a014e400:  d2 0f bf f2  ldub  [ %fp + -14 ], %o1
a014e404:  de 0f bf f0  ldub  [ %fp + -16 ], %o7
a014e408:  da 0f bf f1  ldub  [ %fp + -15 ], %o5
a014e40c:  d2 2b 20 0b  stb  %o1, [ %o4 + 0xb ]
a014e410:  de 2b 20 09  stb  %o7, [ %o4 + 9 ]
a014e414:  da 2b 20 0a  stb  %o5, [ %o4 + 0xa ]
a014e418:  7f ff 83 47  call  0xa012f134
a014e41c:  d0 0c a0 18  ldub  [ %l2 + 0x18 ], %o0
a014e420:  92 10 20 80  mov  0x80, %o1
a014e424:  80 8a 20 ff  btst  0xff, %o0
a014e428:  02 80 00 12  be  0xa014e470
a014e42c:  94 07 bf f0  add  %fp, -16, %o2
a014e430:  d6 0c a0 18  ldub  [ %l2 + 0x18 ], %o3
a014e434:  90 0a e0 0f  and  %o3, 0xf, %o0
a014e438:  23 00 00 40  sethi  %hi(0x10000), %l1
a014e43c:  a1 2c 40 08  sll  %l1, %o0, %l0
a014e440:  7f ff 80 44  call  0xa012e550
a014e444:  91 34 20 10  srl  %l0, 0x10, %o0
a014e448:  25 2a 00 b8  sethi  %hi(0xa802e000), %l2
a014e44c:  80 8a 20 ff  btst  0xff, %o0
a014e450:  02 80 00 08  be  0xa014e470
a014e454:  98 14 a1 f0  or  %l2, 0x1f0, %o4
a014e458:  da 0f bf f2  ldub  [ %fp + -14 ], %o5
a014e45c:  c2 0f bf f0  ldub  [ %fp + -16 ], %g1
a014e460:  d4 0f bf f1  ldub  [ %fp + -15 ], %o2
a014e464:  da 2b 20 14  stb  %o5, [ %o4 + 0x14 ]
a014e468:  c2 2b 20 12  stb  %g1, [ %o4 + 0x12 ]
a014e46c:  d4 2b 20 13  stb  %o2, [ %o4 + 0x13 ]
a014e470:  81 c7 e0 08  ret
a014e474:  81 e8 00 00  restore
