# leon2m FUN_a011a1b0 0xa011a1b0-0xa011a378 (40 bytes)
a011a1b0:  80 a2 20 07  cmp  %o0, 7
a011a1b4:  18 80 00 6f  bgu  0xa011a370
a011a1b8:  83 2a 20 02  sll  %o0, 2, %g1
a011a1bc:  11 00 02 e4  sethi  %hi(0xb9000), %o0
a011a1c0:  9a 12 21 5c  or  %o0, 0x15c, %o5	! 0xb915c
a011a1c4:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a011a1c8:  81 c3 00 00  jmp  %o4
a011a1cc:  01 00 00 00  nop
a011a1d0:  98 0a 60 ff  and  %o1, 0xff, %o4
a011a1d4:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a011a1d8:  90 03 00 0c  add  %o4, %o4, %o0
a011a1dc:  92 10 62 a8  or  %g1, 0x2a8, %o1
a011a1e0:  da 12 40 08  lduh  [ %o1 + %o0 ], %o5
a011a1e4:  9a 03 60 80  add  %o5, 0x80, %o5
a011a1e8:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a011a1ec:  9b 2b 60 02  sll  %o5, 2, %o5
a011a1f0:  9a 13 40 09  or  %o5, %o1, %o5
a011a1f4:  d0 03 40 00  ld  [ %o5 ], %o0
a011a1f8:  82 12 20 10  or  %o0, 0x10, %g1
a011a1fc:  92 08 60 ff  and  %g1, 0xff, %o1
a011a200:  d2 23 40 00  st  %o1, [ %o5 ]
a011a204:  30 80 00 5b  b,a   0xa011a370
a011a208:  98 0a 60 ff  and  %o1, 0xff, %o4
a011a20c:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a011a210:  92 03 00 0c  add  %o4, %o4, %o1
a011a214:  90 10 62 a8  or  %g1, 0x2a8, %o0
a011a218:  da 12 00 09  lduh  [ %o0 + %o1 ], %o5
a011a21c:  82 03 60 a5  add  %o5, 0xa5, %g1
a011a220:  91 28 60 02  sll  %g1, 2, %o0
a011a224:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011a228:  9a 12 00 0c  or  %o0, %o4, %o5
a011a22c:  d2 03 40 00  ld  [ %o5 ], %o1
a011a230:  82 12 7f 80  or  %o1, -128, %g1
a011a234:  92 08 60 ff  and  %g1, 0xff, %o1
a011a238:  d2 23 40 00  st  %o1, [ %o5 ]
a011a23c:  30 80 00 4d  b,a   0xa011a370
a011a240:  98 0a 60 ff  and  %o1, 0xff, %o4
a011a244:  1b 2a 00 9e  sethi  %hi(0xa8027800), %o5
a011a248:  92 03 00 0c  add  %o4, %o4, %o1
a011a24c:  82 13 62 a8  or  %o5, 0x2a8, %g1
a011a250:  d0 10 40 09  lduh  [ %g1 + %o1 ], %o0
a011a254:  9a 02 20 80  add  %o0, 0x80, %o5
a011a258:  83 2b 60 02  sll  %o5, 2, %g1
a011a25c:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011a260:  9a 10 40 0c  or  %g1, %o4, %o5
a011a264:  d2 03 40 00  ld  [ %o5 ], %o1
a011a268:  82 12 60 02  or  %o1, 2, %g1
a011a26c:  92 08 60 ff  and  %g1, 0xff, %o1
a011a270:  d2 23 40 00  st  %o1, [ %o5 ]
a011a274:  30 80 00 3f  b,a   0xa011a370
a011a278:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011a27c:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a011a280:  92 10 62 a8  or  %g1, 0x2a8, %o1	! 0xa8027aa8
a011a284:  98 03 40 0d  add  %o5, %o5, %o4
a011a288:  d0 12 40 0c  lduh  [ %o1 + %o4 ], %o0
a011a28c:  9a 02 20 80  add  %o0, 0x80, %o5
a011a290:  93 2b 60 02  sll  %o5, 2, %o1
a011a294:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a011a298:  9a 12 40 01  or  %o1, %g1, %o5
a011a29c:  d0 03 40 00  ld  [ %o5 ], %o0
a011a2a0:  82 12 20 04  or  %o0, 4, %g1
a011a2a4:  92 08 60 ff  and  %g1, 0xff, %o1
a011a2a8:  d2 23 40 00  st  %o1, [ %o5 ]
a011a2ac:  30 80 00 31  b,a   0xa011a370
a011a2b0:  98 0a 60 ff  and  %o1, 0xff, %o4
a011a2b4:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a011a2b8:  90 03 00 0c  add  %o4, %o4, %o0
a011a2bc:  92 10 62 a8  or  %g1, 0x2a8, %o1
a011a2c0:  da 12 40 08  lduh  [ %o1 + %o0 ], %o5
a011a2c4:  82 03 60 80  add  %o5, 0x80, %g1
a011a2c8:  93 28 60 02  sll  %g1, 2, %o1
a011a2cc:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011a2d0:  9a 12 40 0c  or  %o1, %o4, %o5
a011a2d4:  d0 03 40 00  ld  [ %o5 ], %o0
a011a2d8:  82 12 20 08  or  %o0, 8, %g1
a011a2dc:  92 08 60 ff  and  %g1, 0xff, %o1
a011a2e0:  d2 23 40 00  st  %o1, [ %o5 ]
a011a2e4:  30 80 00 23  b,a   0xa011a370
a011a2e8:  98 0a 60 ff  and  %o1, 0xff, %o4
a011a2ec:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a011a2f0:  90 03 00 0c  add  %o4, %o4, %o0
a011a2f4:  92 10 62 a8  or  %g1, 0x2a8, %o1
a011a2f8:  da 12 40 08  lduh  [ %o1 + %o0 ], %o5
a011a2fc:  10 bf ff bb  b  0xa011a1e8
a011a300:  9a 03 60 a5  add  %o5, 0xa5, %o5
a011a304:  98 0a 60 ff  and  %o1, 0xff, %o4
a011a308:  1b 2a 00 9e  sethi  %hi(0xa8027800), %o5
a011a30c:  90 03 00 0c  add  %o4, %o4, %o0
a011a310:  82 13 62 a8  or  %o5, 0x2a8, %g1
a011a314:  d2 10 40 08  lduh  [ %g1 + %o0 ], %o1
a011a318:  9a 02 60 a5  add  %o1, 0xa5, %o5
a011a31c:  91 2b 60 02  sll  %o5, 2, %o0
a011a320:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011a324:  9a 12 00 0c  or  %o0, %o4, %o5
a011a328:  c2 03 40 00  ld  [ %o5 ], %g1
a011a32c:  82 10 60 20  or  %g1, 0x20, %g1
a011a330:  92 08 60 ff  and  %g1, 0xff, %o1
a011a334:  d2 23 40 00  st  %o1, [ %o5 ]
a011a338:  30 80 00 0e  b,a   0xa011a370
a011a33c:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011a340:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a011a344:  90 10 62 a8  or  %g1, 0x2a8, %o0	! 0xa8027aa8
a011a348:  98 03 40 0d  add  %o5, %o5, %o4
a011a34c:  d2 12 00 0c  lduh  [ %o0 + %o4 ], %o1
a011a350:  9a 02 60 a5  add  %o1, 0xa5, %o5
a011a354:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a011a358:  91 2b 60 02  sll  %o5, 2, %o0
a011a35c:  9a 12 00 01  or  %o0, %g1, %o5
a011a360:  d2 03 40 00  ld  [ %o5 ], %o1
a011a364:  82 12 60 40  or  %o1, 0x40, %g1
a011a368:  92 08 60 ff  and  %g1, 0xff, %o1
a011a36c:  d2 23 40 00  st  %o1, [ %o5 ]
a011a370:  81 c3 e0 08  retl
a011a374:  01 00 00 00  nop
