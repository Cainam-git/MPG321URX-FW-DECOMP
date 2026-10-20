# leon2m FUN_a00f72cc 0xa00f72cc-0xa00f7434 (360 bytes)
a00f72cc:  9d e3 bf 98  save  %sp, -104, %sp
a00f72d0:  03 33 c0 3a  sethi  %hi(0xcf00e800), %g1
a00f72d4:  a0 10 61 84  or  %g1, 0x184, %l0	! 0xcf00e984
a00f72d8:  da 04 00 00  ld  [ %l0 ], %o5
a00f72dc:  67 fe 5b f2  call  0x4008e2a4
a00f72e0:  a6 10 00 0d  mov  %o5, %l3
a00f72e4:  80 8e 20 ff  btst  0xff, %i0
a00f72e8:  02 80 00 05  be  0xa00f72fc
a00f72ec:  01 00 00 00  nop
a00f72f0:  d0 04 00 00  ld  [ %l0 ], %o0
a00f72f4:  10 80 00 04  b  0xa00f7304
a00f72f8:  82 12 20 40  or  %o0, 0x40, %g1
a00f72fc:  d2 04 00 00  ld  [ %l0 ], %o1
a00f7300:  82 0a 7f bf  and  %o1, -65, %g1
a00f7304:  17 33 c0 3a  sethi  %hi(0xcf00e800), %o3
a00f7308:  c2 24 00 00  st  %g1, [ %l0 ]
a00f730c:  94 12 e1 84  or  %o3, 0x184, %o2
a00f7310:  e4 02 80 00  ld  [ %o2 ], %l2
a00f7314:  a2 0c a0 f1  and  %l2, 0xf1, %l1
a00f7318:  e2 22 80 00  st  %l1, [ %o2 ]
a00f731c:  a4 12 e1 8c  or  %o3, 0x18c, %l2
a00f7320:  e0 04 80 00  ld  [ %l2 ], %l0
a00f7324:  a2 12 e1 90  or  %o3, 0x190, %l1
a00f7328:  d8 04 40 00  ld  [ %l1 ], %o4
a00f732c:  83 2b 20 08  sll  %o4, 8, %g1
a00f7330:  9e 14 00 01  or  %l0, %g1, %o7
a00f7334:  de 36 40 00  sth  %o7, [ %i1 ]
a00f7338:  a0 12 e1 94  or  %o3, 0x194, %l0
a00f733c:  d0 04 00 00  ld  [ %l0 ], %o0
a00f7340:  9e 12 e1 98  or  %o3, 0x198, %o7
a00f7344:  da 03 c0 00  ld  [ %o7 ], %o5
a00f7348:  b1 2b 60 08  sll  %o5, 8, %i0
a00f734c:  92 12 00 18  or  %o0, %i0, %o1
a00f7350:  d2 36 60 02  sth  %o1, [ %i1 + 2 ]
a00f7354:  90 12 e1 9c  or  %o3, 0x19c, %o0
a00f7358:  da 02 00 00  ld  [ %o0 ], %o5
a00f735c:  92 12 e1 a0  or  %o3, 0x1a0, %o1
a00f7360:  d8 02 40 00  ld  [ %o1 ], %o4
a00f7364:  83 2b 20 08  sll  %o4, 8, %g1
a00f7368:  b0 13 40 01  or  %o5, %g1, %i0
a00f736c:  f0 36 60 04  sth  %i0, [ %i1 + 4 ]
a00f7370:  b0 12 e1 a4  or  %o3, 0x1a4, %i0
a00f7374:  d8 06 00 00  ld  [ %i0 ], %o4
a00f7378:  d8 36 60 06  sth  %o4, [ %i1 + 6 ]
a00f737c:  da 02 80 00  ld  [ %o2 ], %o5
a00f7380:  82 0b 60 f1  and  %o5, 0xf1, %g1
a00f7384:  98 10 60 02  or  %g1, 2, %o4
a00f7388:  d8 22 80 00  st  %o4, [ %o2 ]
a00f738c:  d8 04 80 00  ld  [ %l2 ], %o4
a00f7390:  da 04 40 00  ld  [ %l1 ], %o5
a00f7394:  83 2b 60 08  sll  %o5, 8, %g1
a00f7398:  9a 13 00 01  or  %o4, %g1, %o5
a00f739c:  da 36 60 08  sth  %o5, [ %i1 + 8 ]
a00f73a0:  da 04 00 00  ld  [ %l0 ], %o5
a00f73a4:  d8 03 c0 00  ld  [ %o7 ], %o4
a00f73a8:  83 2b 20 08  sll  %o4, 8, %g1
a00f73ac:  98 13 40 01  or  %o5, %g1, %o4
a00f73b0:  d8 36 60 0a  sth  %o4, [ %i1 + 0xa ]
a00f73b4:  d8 02 00 00  ld  [ %o0 ], %o4
a00f73b8:  da 02 40 00  ld  [ %o1 ], %o5
a00f73bc:  83 2b 60 08  sll  %o5, 8, %g1
a00f73c0:  9a 13 00 01  or  %o4, %g1, %o5
a00f73c4:  da 36 60 0c  sth  %o5, [ %i1 + 0xc ]
a00f73c8:  c2 06 00 00  ld  [ %i0 ], %g1
a00f73cc:  c2 36 60 0e  sth  %g1, [ %i1 + 0xe ]
a00f73d0:  d8 02 80 00  ld  [ %o2 ], %o4
a00f73d4:  9a 0b 20 f1  and  %o4, 0xf1, %o5
a00f73d8:  82 13 60 04  or  %o5, 4, %g1
a00f73dc:  c2 22 80 00  st  %g1, [ %o2 ]
a00f73e0:  da 04 80 00  ld  [ %l2 ], %o5
a00f73e4:  d8 04 40 00  ld  [ %l1 ], %o4
a00f73e8:  a5 2b 20 08  sll  %o4, 8, %l2
a00f73ec:  a2 13 40 12  or  %o5, %l2, %l1
a00f73f0:  e2 36 60 10  sth  %l1, [ %i1 + 0x10 ]
a00f73f4:  d8 04 00 00  ld  [ %l0 ], %o4
a00f73f8:  e0 03 c0 00  ld  [ %o7 ], %l0
a00f73fc:  83 2c 20 08  sll  %l0, 8, %g1
a00f7400:  9a 13 00 01  or  %o4, %g1, %o5
a00f7404:  da 36 60 12  sth  %o5, [ %i1 + 0x12 ]
a00f7408:  e0 02 00 00  ld  [ %o0 ], %l0
a00f740c:  e4 02 40 00  ld  [ %o1 ], %l2
a00f7410:  a3 2c a0 08  sll  %l2, 8, %l1
a00f7414:  9e 14 00 11  or  %l0, %l1, %o7
a00f7418:  de 36 60 14  sth  %o7, [ %i1 + 0x14 ]
a00f741c:  d8 06 00 00  ld  [ %i0 ], %o4
a00f7420:  d8 36 60 16  sth  %o4, [ %i1 + 0x16 ]
a00f7424:  96 0c e0 ff  and  %l3, 0xff, %o3
a00f7428:  d6 22 80 00  st  %o3, [ %o2 ]
a00f742c:  81 c7 e0 08  ret
a00f7430:  81 e8 00 00  restore
