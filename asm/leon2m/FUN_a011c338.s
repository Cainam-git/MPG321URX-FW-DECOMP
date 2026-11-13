# leon2m FUN_a011c338 0xa011c338-0xa011c4cc (404 bytes)
a011c338:  9d e3 bf 98  save  %sp, -104, %sp
a011c33c:  9a 0f 60 ff  and  %i5, 0xff, %o5
a011c340:  3b 2a 00 b2  sethi  %hi(0xa802c800), %i5
a011c344:  9e 03 40 0d  add  %o5, %o5, %o7
a011c348:  82 17 61 ca  or  %i5, 0x1ca, %g1
a011c34c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a011c350:  fa 10 40 0f  lduh  [ %g1 + %o7 ], %i5
a011c354:  b4 5e 80 1d  smul  %i2, %i5, %i2
a011c358:  80 a6 20 01  cmp  %i0, 1
a011c35c:  b2 06 40 1a  add  %i1, %i2, %i1
a011c360:  02 80 00 3b  be  0xa011c44c
a011c364:  b0 10 00 1c  mov  %i4, %i0
a011c368:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011c36c:  ba 10 20 40  mov  0x40, %i5
a011c370:  80 a3 60 00  cmp  %o5, 0
a011c374:  12 80 00 32  bne  0xa011c43c
a011c378:  82 10 63 80  or  %g1, 0x380, %g1
a011c37c:  fa 20 40 00  st  %i5, [ %g1 ]
a011c380:  82 10 20 9f  mov  0x9f, %g1
a011c384:  01 00 00 00  nop
a011c388:  82 80 7f ff  addcc  %g1, -1, %g1
a011c38c:  1c bf ff fe  bpos  0xa011c384
a011c390:  80 a3 60 00  cmp  %o5, 0
a011c394:  b3 2e 60 10  sll  %i1, 0x10, %i1
a011c398:  12 80 00 3e  bne  0xa011c490
a011c39c:  bb 36 60 10  srl  %i1, 0x10, %i5
a011c3a0:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011c3a4:  b4 0f 60 ff  and  %i5, 0xff, %i2
a011c3a8:  82 17 23 84  or  %i4, 0x384, %g1
a011c3ac:  f4 20 40 00  st  %i2, [ %g1 ]
a011c3b0:  b4 17 23 88  or  %i4, 0x388, %i2
a011c3b4:  bb 36 60 18  srl  %i1, 0x18, %i5
a011c3b8:  fa 26 80 00  st  %i5, [ %i2 ]
a011c3bc:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a011c3c0:  b2 10 63 cc  or  %g1, 0x3cc, %i1	! 0xcf00bfcc
a011c3c4:  c0 26 40 00  clr  [ %i1 ]
a011c3c8:  82 10 20 9f  mov  0x9f, %g1
a011c3cc:  01 00 00 00  nop
a011c3d0:  82 80 7f ff  addcc  %g1, -1, %g1
a011c3d4:  1c bf ff fe  bpos  0xa011c3cc
a011c3d8:  01 00 00 00  nop
a011c3dc:  b6 0e e0 ff  and  %i3, 0xff, %i3
a011c3e0:  80 a6 e0 00  cmp  %i3, 0
a011c3e4:  02 80 00 38  be  0xa011c4c4
a011c3e8:  b8 10 20 00  clr  %i4
a011c3ec:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011c3f0:  b2 10 63 a0  or  %g1, 0x3a0, %i1	! 0xcf0117a0
a011c3f4:  ba 10 20 00  clr  %i5
a011c3f8:  b4 10 63 8c  or  %g1, 0x38c, %i2
a011c3fc:  80 a3 60 00  cmp  %o5, 0
a011c400:  12 80 00 2d  bne  0xa011c4b4
a011c404:  c2 0f 40 18  ldub  [ %i5 + %i0 ], %g1
a011c408:  ba 08 60 ff  and  %g1, 0xff, %i5
a011c40c:  fa 26 80 00  st  %i5, [ %i2 ]
a011c410:  82 10 20 9f  mov  0x9f, %g1
a011c414:  01 00 00 00  nop
a011c418:  82 80 7f ff  addcc  %g1, -1, %g1
a011c41c:  1c bf ff fe  bpos  0xa011c414
a011c420:  01 00 00 00  nop
a011c424:  b8 07 20 01  inc  %i4
a011c428:  ba 0f 20 ff  and  %i4, 0xff, %i5
a011c42c:  80 a7 40 1b  cmp  %i5, %i3
a011c430:  0a bf ff f4  bcs  0xa011c400
a011c434:  80 a3 60 00  cmp  %o5, 0
a011c438:  30 80 00 23  b,a   0xa011c4c4
a011c43c:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011c440:  ba 10 20 40  mov  0x40, %i5
a011c444:  10 bf ff ce  b  0xa011c37c
a011c448:  82 17 23 94  or  %i4, 0x394, %g1
a011c44c:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011c450:  ba 10 20 90  mov  0x90, %i5
a011c454:  80 a3 60 00  cmp  %o5, 0
a011c458:  02 80 00 05  be  0xa011c46c
a011c45c:  82 17 23 80  or  %i4, 0x380, %g1
a011c460:  35 33 c0 45  sethi  %hi(0xcf011400), %i2
a011c464:  ba 10 20 90  mov  0x90, %i5
a011c468:  82 16 a3 94  or  %i2, 0x394, %g1
a011c46c:  fa 20 40 00  st  %i5, [ %g1 ]
a011c470:  82 10 20 9f  mov  0x9f, %g1
a011c474:  01 00 00 00  nop
a011c478:  82 80 7f ff  addcc  %g1, -1, %g1
a011c47c:  1c bf ff fe  bpos  0xa011c474
a011c480:  80 a3 60 00  cmp  %o5, 0
a011c484:  b3 2e 60 10  sll  %i1, 0x10, %i1
a011c488:  02 bf ff c6  be  0xa011c3a0
a011c48c:  bb 36 60 10  srl  %i1, 0x10, %i5
a011c490:  35 33 c0 45  sethi  %hi(0xcf011400), %i2
a011c494:  b8 0f 60 ff  and  %i5, 0xff, %i4
a011c498:  82 16 a3 98  or  %i2, 0x398, %g1
a011c49c:  f8 20 40 00  st  %i4, [ %g1 ]
a011c4a0:  b8 16 a3 9c  or  %i2, 0x39c, %i4
a011c4a4:  bb 36 60 18  srl  %i1, 0x18, %i5
a011c4a8:  fa 27 00 00  st  %i5, [ %i4 ]
a011c4ac:  10 bf ff c5  b  0xa011c3c0
a011c4b0:  03 33 c0 30  sethi  %hi(0xcf00c000), %g1
a011c4b4:  82 08 60 ff  and  %g1, 0xff, %g1
a011c4b8:  c2 26 40 00  st  %g1, [ %i1 ]
a011c4bc:  10 bf ff d6  b  0xa011c414
a011c4c0:  82 10 20 9f  mov  0x9f, %g1
a011c4c4:  81 c7 e0 08  ret
a011c4c8:  81 e8 00 00  restore
