# leon2m FUN_a011e4c8 0xa011e4c8-0xa011e5fc (132 bytes)
a011e4c8:  90 0a 20 ff  and  %o0, 0xff, %o0
a011e4cc:  82 02 3f f0  add  %o0, -16, %g1
a011e4d0:  80 a0 60 08  cmp  %g1, 8
a011e4d4:  38 80 00 08  bgu,a   0xa011e4f4
a011e4d8:  11 33 c0 59  sethi  %hi(0xcf016400), %o0
a011e4dc:  17 00 02 f5  sethi  %hi(0xbd400), %o3
a011e4e0:  83 28 60 02  sll  %g1, 2, %g1
a011e4e4:  9a 12 e2 0c  or  %o3, 0x20c, %o5
a011e4e8:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a011e4ec:  81 c3 00 00  jmp  %o4
a011e4f0:  01 00 00 00  nop
a011e4f4:  96 0a 60 ff  and  %o1, 0xff, %o3
a011e4f8:  9a 12 20 50  or  %o0, 0x50, %o5
a011e4fc:  d6 23 40 00  st  %o3, [ %o5 ]
a011e500:  82 12 20 54  or  %o0, 0x54, %g1
a011e504:  d6 20 40 00  st  %o3, [ %g1 ]
a011e508:  98 12 20 58  or  %o0, 0x58, %o4
a011e50c:  d6 23 00 00  st  %o3, [ %o4 ]
a011e510:  92 12 20 5c  or  %o0, 0x5c, %o1
a011e514:  d6 22 40 00  st  %o3, [ %o1 ]
a011e518:  9a 12 20 60  or  %o0, 0x60, %o5
a011e51c:  d6 23 40 00  st  %o3, [ %o5 ]
a011e520:  82 12 20 64  or  %o0, 0x64, %g1
a011e524:  d6 20 40 00  st  %o3, [ %g1 ]
a011e528:  98 12 20 68  or  %o0, 0x68, %o4
a011e52c:  d6 23 00 00  st  %o3, [ %o4 ]
a011e530:  92 12 20 6c  or  %o0, 0x6c, %o1
a011e534:  d6 22 40 00  st  %o3, [ %o1 ]
a011e538:  9a 12 20 7c  or  %o0, 0x7c, %o5
a011e53c:  d6 23 40 00  st  %o3, [ %o5 ]
a011e540:  30 80 00 2d  b,a   0xa011e5f4
a011e544:  03 33 c0 59  sethi  %hi(0xcf016400), %g1
a011e548:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011e54c:  82 10 60 7c  or  %g1, 0x7c, %g1
a011e550:  da 20 40 00  st  %o5, [ %g1 ]
a011e554:  30 80 00 28  b,a   0xa011e5f4
a011e558:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011e55c:  13 33 c0 59  sethi  %hi(0xcf016400), %o1
a011e560:  82 12 60 50  or  %o1, 0x50, %g1	! 0xcf016450
a011e564:  da 20 40 00  st  %o5, [ %g1 ]
a011e568:  30 80 00 23  b,a   0xa011e5f4
a011e56c:  11 33 c0 59  sethi  %hi(0xcf016400), %o0
a011e570:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011e574:  82 12 20 54  or  %o0, 0x54, %g1
a011e578:  da 20 40 00  st  %o5, [ %g1 ]
a011e57c:  30 80 00 1e  b,a   0xa011e5f4
a011e580:  19 33 c0 59  sethi  %hi(0xcf016400), %o4
a011e584:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011e588:  82 13 20 58  or  %o4, 0x58, %g1
a011e58c:  da 20 40 00  st  %o5, [ %g1 ]
a011e590:  30 80 00 19  b,a   0xa011e5f4
a011e594:  03 33 c0 59  sethi  %hi(0xcf016400), %g1
a011e598:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011e59c:  82 10 60 5c  or  %g1, 0x5c, %g1
a011e5a0:  da 20 40 00  st  %o5, [ %g1 ]
a011e5a4:  30 80 00 14  b,a   0xa011e5f4
a011e5a8:  17 33 c0 59  sethi  %hi(0xcf016400), %o3
a011e5ac:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011e5b0:  82 12 e0 60  or  %o3, 0x60, %g1
a011e5b4:  da 20 40 00  st  %o5, [ %g1 ]
a011e5b8:  30 80 00 0f  b,a   0xa011e5f4
a011e5bc:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011e5c0:  13 33 c0 59  sethi  %hi(0xcf016400), %o1
a011e5c4:  82 12 60 64  or  %o1, 0x64, %g1	! 0xcf016464
a011e5c8:  da 20 40 00  st  %o5, [ %g1 ]
a011e5cc:  30 80 00 0a  b,a   0xa011e5f4
a011e5d0:  11 33 c0 59  sethi  %hi(0xcf016400), %o0
a011e5d4:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011e5d8:  82 12 20 68  or  %o0, 0x68, %g1
a011e5dc:  da 20 40 00  st  %o5, [ %g1 ]
a011e5e0:  30 80 00 05  b,a   0xa011e5f4
a011e5e4:  19 33 c0 59  sethi  %hi(0xcf016400), %o4
a011e5e8:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011e5ec:  82 13 20 6c  or  %o4, 0x6c, %g1
a011e5f0:  da 20 40 00  st  %o5, [ %g1 ]
a011e5f4:  81 c3 e0 08  retl
a011e5f8:  01 00 00 00  nop
