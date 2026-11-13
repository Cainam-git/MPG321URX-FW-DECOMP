# leon2s FUN_a00a8508 0xa00a8508-0xa00a8694 (396 bytes)
a00a8508:  9d e3 bf 90  save  %sp, -112, %sp
a00a850c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a8510:  98 10 20 00  clr  %o4
a00a8514:  9a 10 20 00  clr  %o5
a00a8518:  80 a6 60 01  cmp  %i1, 1
a00a851c:  02 80 00 29  be  0xa00a85c0
a00a8520:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a00a8524:  80 a6 60 01  cmp  %i1, 1
a00a8528:  14 80 00 07  bg  0xa00a8544
a00a852c:  80 a6 60 02  cmp  %i1, 2
a00a8530:  80 a6 60 00  cmp  %i1, 0
a00a8534:  22 80 00 07  be,a   0xa00a8550
a00a8538:  c2 0e a0 02  ldub  [ %i2 + 2 ], %g1
a00a853c:  10 80 00 51  b  0xa00a8680
a00a8540:  11 28 01 b0  sethi  %hi(0xa006c000), %o0
a00a8544:  02 80 00 37  be  0xa00a8620
a00a8548:  11 28 01 b0  sethi  %hi(0xa006c000), %o0
a00a854c:  30 80 00 4d  b,a   0xa00a8680
a00a8550:  da 0e a0 01  ldub  [ %i2 + 1 ], %o5
a00a8554:  83 28 60 08  sll  %g1, 8, %g1
a00a8558:  9a 13 40 01  or  %o5, %g1, %o5
a00a855c:  d8 0e a0 03  ldub  [ %i2 + 3 ], %o4
a00a8560:  96 0e 20 ff  and  %i0, 0xff, %o3
a00a8564:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a8568:  d4 0e 80 00  ldub  [ %i2 ], %o2
a00a856c:  99 2b 20 10  sll  %o4, 0x10, %o4
a00a8570:  82 10 63 00  or  %g1, 0x300, %g1
a00a8574:  96 5a e0 34  smul  %o3, 0x34, %o3
a00a8578:  9a 13 40 0c  or  %o5, %o4, %o5
a00a857c:  96 02 c0 01  add  %o3, %g1, %o3
a00a8580:  95 2a a0 18  sll  %o2, 0x18, %o2
a00a8584:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a00a8588:  d4 27 bf f0  st  %o2, [ %fp + -16 ]
a00a858c:  d8 02 e0 30  ld  [ %o3 + 0x30 ], %o4
a00a8590:  da 03 20 a8  ld  [ %o4 + 0xa8 ], %o5
a00a8594:  03 38 00 00  sethi  %hi(0xe0000000), %g1
a00a8598:  82 2b 40 01  andn  %o5, %g1, %g1
a00a859c:  9a 10 40 0a  or  %g1, %o2, %o5
a00a85a0:  da 23 20 a8  st  %o5, [ %o4 + 0xa8 ]
a00a85a4:  da 03 20 ac  ld  [ %o4 + 0xac ], %o5
a00a85a8:  03 3f f0 00  sethi  %hi(0xffc00000), %g1
a00a85ac:  82 0b 40 01  and  %o5, %g1, %g1
a00a85b0:  da 07 bf f4  ld  [ %fp + -12 ], %o5
a00a85b4:  9a 10 40 0d  or  %g1, %o5, %o5
a00a85b8:  da 23 20 ac  st  %o5, [ %o4 + 0xac ]
a00a85bc:  30 80 00 33  b,a   0xa00a8688
a00a85c0:  c2 0e a0 01  ldub  [ %i2 + 1 ], %g1
a00a85c4:  83 28 60 08  sll  %g1, 8, %g1
a00a85c8:  d8 0e 80 00  ldub  [ %i2 ], %o4
a00a85cc:  da 0e a0 02  ldub  [ %i2 + 2 ], %o5
a00a85d0:  98 13 00 01  or  %o4, %g1, %o4
a00a85d4:  c2 0e a0 03  ldub  [ %i2 + 3 ], %g1
a00a85d8:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00a85dc:  98 13 00 0d  or  %o4, %o5, %o4
a00a85e0:  83 28 60 18  sll  %g1, 0x18, %g1
a00a85e4:  98 13 00 01  or  %o4, %g1, %o4
a00a85e8:  96 0e 20 ff  and  %i0, 0xff, %o3
a00a85ec:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a85f0:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a85f4:  96 5a e0 34  smul  %o3, 0x34, %o3
a00a85f8:  96 02 c0 01  add  %o3, %g1, %o3
a00a85fc:  d8 27 bf f0  st  %o4, [ %fp + -16 ]
a00a8600:  da 02 e0 30  ld  [ %o3 + 0x30 ], %o5
a00a8604:  03 0f ff ff  sethi  %hi(0x3ffffc00), %g1
a00a8608:  d4 03 60 e8  ld  [ %o5 + 0xe8 ], %o2
a00a860c:  82 10 63 e0  or  %g1, 0x3e0, %g1
a00a8610:  82 2a 80 01  andn  %o2, %g1, %g1
a00a8614:  94 10 40 0c  or  %g1, %o4, %o2
a00a8618:  d4 23 60 e8  st  %o2, [ %o5 + 0xe8 ]
a00a861c:  30 80 00 1b  b,a   0xa00a8688
a00a8620:  c2 0e a0 01  ldub  [ %i2 + 1 ], %g1
a00a8624:  83 28 60 08  sll  %g1, 8, %g1
a00a8628:  d8 0e 80 00  ldub  [ %i2 ], %o4
a00a862c:  da 0e a0 02  ldub  [ %i2 + 2 ], %o5
a00a8630:  98 13 00 01  or  %o4, %g1, %o4
a00a8634:  c2 0e a0 03  ldub  [ %i2 + 3 ], %g1
a00a8638:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00a863c:  98 13 00 0d  or  %o4, %o5, %o4
a00a8640:  83 28 60 18  sll  %g1, 0x18, %g1
a00a8644:  98 13 00 01  or  %o4, %g1, %o4
a00a8648:  96 0e 20 ff  and  %i0, 0xff, %o3
a00a864c:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a8650:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a8654:  96 5a e0 34  smul  %o3, 0x34, %o3
a00a8658:  96 02 c0 01  add  %o3, %g1, %o3
a00a865c:  d8 27 bf f0  st  %o4, [ %fp + -16 ]
a00a8660:  da 02 e0 30  ld  [ %o3 + 0x30 ], %o5
a00a8664:  03 0f ff ff  sethi  %hi(0x3ffffc00), %g1
a00a8668:  d4 03 60 ec  ld  [ %o5 + 0xec ], %o2
a00a866c:  82 10 63 e0  or  %g1, 0x3e0, %g1
a00a8670:  82 2a 80 01  andn  %o2, %g1, %g1
a00a8674:  94 10 40 0c  or  %g1, %o4, %o2
a00a8678:  d4 23 60 ec  st  %o2, [ %o5 + 0xec ]
a00a867c:  30 80 00 03  b,a   0xa00a8688
a00a8680:  7f ff 2a 71  call  0xa0073044
a00a8684:  90 12 21 80  or  %o0, 0x180, %o0
a00a8688:  01 00 00 00  nop
a00a868c:  81 c7 e0 08  ret
a00a8690:  81 e8 00 00  restore
