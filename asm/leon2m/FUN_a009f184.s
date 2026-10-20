# leon2m FUN_a009f184 0xa009f184-0xa009f42c (680 bytes)
a009f184:  9d e3 bf 98  save  %sp, -104, %sp
a009f188:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a009f18c:  98 14 a2 90  or  %l2, 0x290, %o4	! 0xa802d290
a009f190:  c2 0b 21 ee  ldub  [ %o4 + 0x1ee ], %g1
a009f194:  80 a0 60 01  cmp  %g1, 1
a009f198:  02 80 00 61  be  0xa009f31c
a009f19c:  29 2a 00 b3  sethi  %hi(0xa802cc00), %l4
a009f1a0:  a2 14 a2 90  or  %l2, 0x290, %l1
a009f1a4:  a0 15 23 f4  or  %l4, 0x3f4, %l0
a009f1a8:  d4 0c 61 e2  ldub  [ %l1 + 0x1e2 ], %o2
a009f1ac:  da 14 20 10  lduh  [ %l0 + 0x10 ], %o5
a009f1b0:  80 a2 80 0d  cmp  %o2, %o5
a009f1b4:  22 80 00 39  be,a   0xa009f298
a009f1b8:  d6 0c 61 e6  ldub  [ %l1 + 0x1e6 ], %o3
a009f1bc:  80 a3 60 00  cmp  %o5, 0
a009f1c0:  02 80 00 39  be  0xa009f2a4
a009f1c4:  98 14 a2 90  or  %l2, 0x290, %o4
a009f1c8:  da 14 20 04  lduh  [ %l0 + 4 ], %o5
a009f1cc:  27 3f ff e0  sethi  %hi(0xffff8000), %l3
a009f1d0:  9e 0b 40 13  and  %o5, %l3, %o7
a009f1d4:  99 2b e0 10  sll  %o7, 0x10, %o4
a009f1d8:  80 a3 20 00  cmp  %o4, 0
a009f1dc:  12 80 00 70  bne  0xa009f39c
a009f1e0:  aa 13 64 00  or  %o5, 0x400, %l5
a009f1e4:  2b 2a 00 ab  sethi  %hi(0xa802ac00), %l5
a009f1e8:  40 00 57 a6  call  0xa00b5080
a009f1ec:  c0 25 63 ec  clr  [ %l5 + 0x3ec ]	! 0xa802afec
a009f1f0:  40 00 ee 39  call  0xa00daad4
a009f1f4:  01 00 00 00  nop
a009f1f8:  82 0a 20 ff  and  %o0, 0xff, %g1
a009f1fc:  80 a0 60 01  cmp  %g1, 1
a009f200:  02 80 00 5f  be  0xa009f37c
a009f204:  17 2a 00 97  sethi  %hi(0xa8025c00), %o3
a009f208:  d4 14 20 0e  lduh  [ %l0 + 0xe ], %o2
a009f20c:  d2 0c 61 e2  ldub  [ %l1 + 0x1e2 ], %o1
a009f210:  90 14 c0 0a  or  %l3, %o2, %o0
a009f214:  e6 14 20 10  lduh  [ %l0 + 0x10 ], %l3
a009f218:  9a 0a 60 ff  and  %o1, 0xff, %o5
a009f21c:  d0 34 20 0e  sth  %o0, [ %l0 + 0xe ]
a009f220:  80 a3 40 13  cmp  %o5, %l3
a009f224:  02 80 00 64  be  0xa009f3b4
a009f228:  c0 2a e0 56  clrb  [ %o3 + 0x56 ]
a009f22c:  9a 14 a2 90  or  %l2, 0x290, %o5
a009f230:  d2 0b 61 e2  ldub  [ %o5 + 0x1e2 ], %o1
a009f234:  80 a2 60 02  cmp  %o1, 2
a009f238:  18 80 00 71  bgu  0xa009f3fc
a009f23c:  98 15 23 f4  or  %l4, 0x3f4, %o4
a009f240:  d0 0b 61 ee  ldub  [ %o5 + 0x1ee ], %o0
a009f244:  a6 10 20 01  mov  1, %l3
a009f248:  80 a2 20 00  cmp  %o0, 0
a009f24c:  02 80 00 42  be  0xa009f354
a009f250:  e6 2b 20 3f  stb  %l3, [ %o4 + 0x3f ]
a009f254:  e2 13 20 18  lduh  [ %o4 + 0x18 ], %l1
a009f258:  21 3f ff e0  sethi  %hi(0xffff8000), %l0
a009f25c:  82 2c 40 10  andn  %l1, %l0, %g1
a009f260:  c2 33 20 18  sth  %g1, [ %o4 + 0x18 ]
a009f264:  96 14 a2 90  or  %l2, 0x290, %o3
a009f268:  d2 0a e1 e2  ldub  [ %o3 + 0x1e2 ], %o1
a009f26c:  90 10 20 00  clr  %o0
a009f270:  40 00 49 24  call  0xa00b1700
a009f274:  25 2a 00 97  sethi  %hi(0xa8025c00), %l2
a009f278:  92 10 21 0a  mov  0x10a, %o1
a009f27c:  c0 2c a0 55  clrb  [ %l2 + 0x55 ]
a009f280:  d2 25 63 ec  st  %o1, [ %l5 + 0x3ec ]
a009f284:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a009f288:  e0 0b 60 8e  ldub  [ %o5 + 0x8e ], %l0	! 0xa802b08e
a009f28c:  82 14 20 02  or  %l0, 2, %g1
a009f290:  10 80 00 65  b  0xa009f424
a009f294:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a009f298:  80 a2 e0 01  cmp  %o3, 1
a009f29c:  02 bf ff c8  be  0xa009f1bc
a009f2a0:  98 14 a2 90  or  %l2, 0x290, %o4
a009f2a4:  ea 0b 21 e4  ldub  [ %o4 + 0x1e4 ], %l5
a009f2a8:  80 a5 60 00  cmp  %l5, 0
a009f2ac:  02 80 00 5e  be  0xa009f424
a009f2b0:  98 15 23 f4  or  %l4, 0x3f4, %o4
a009f2b4:  d6 13 20 04  lduh  [ %o4 + 4 ], %o3
a009f2b8:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a009f2bc:  9e 0a c0 01  and  %o3, %g1, %o7
a009f2c0:  a9 2b e0 10  sll  %o7, 0x10, %l4
a009f2c4:  80 a5 20 00  cmp  %l4, 0
a009f2c8:  12 80 00 27  bne  0xa009f364
a009f2cc:  90 12 e4 00  or  %o3, 0x400, %o0
a009f2d0:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a009f2d4:  40 00 57 6b  call  0xa00b5080
a009f2d8:  c0 24 23 ec  clr  [ %l0 + 0x3ec ]	! 0xa802afec
a009f2dc:  40 00 ed fe  call  0xa00daad4
a009f2e0:  01 00 00 00  nop
a009f2e4:  a6 0a 20 ff  and  %o0, 0xff, %l3
a009f2e8:  80 a4 e0 01  cmp  %l3, 1
a009f2ec:  02 80 00 25  be  0xa009f380
a009f2f0:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a009f2f4:  90 10 20 00  clr  %o0
a009f2f8:  40 00 4a 2b  call  0xa00b1ba4
a009f2fc:  92 10 20 04  mov  4, %o1
a009f300:  9a 10 21 0a  mov  0x10a, %o5
a009f304:  da 24 23 ec  st  %o5, [ %l0 + 0x3ec ]
a009f308:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a009f30c:  e0 0b 60 8e  ldub  [ %o5 + 0x8e ], %l0	! 0xa802b08e
a009f310:  82 14 20 02  or  %l0, 2, %g1
a009f314:  10 80 00 44  b  0xa009f424
a009f318:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a009f31c:  9a 15 23 f4  or  %l4, 0x3f4, %o5
a009f320:  d6 13 60 10  lduh  [ %o5 + 0x10 ], %o3
a009f324:  d0 0b 21 e2  ldub  [ %o4 + 0x1e2 ], %o0
a009f328:  80 a2 00 0b  cmp  %o0, %o3
a009f32c:  02 bf ff 9d  be  0xa009f1a0
a009f330:  80 a2 e0 03  cmp  %o3, 3
a009f334:  18 bf ff 9c  bgu  0xa009f1a4
a009f338:  a2 14 a2 90  or  %l2, 0x290, %l1
a009f33c:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a009f340:  d2 0b 60 8e  ldub  [ %o5 + 0x8e ], %o1	! 0xa802b08e
a009f344:  82 12 60 02  or  %o1, 2, %g1
a009f348:  d6 2b 21 e2  stb  %o3, [ %o4 + 0x1e2 ]
a009f34c:  10 80 00 36  b  0xa009f424
a009f350:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a009f354:  d4 13 20 18  lduh  [ %o4 + 0x18 ], %o2
a009f358:  1b 3f ff e0  sethi  %hi(0xffff8000), %o5
a009f35c:  10 bf ff c1  b  0xa009f260
a009f360:  82 12 80 0d  or  %o2, %o5, %g1
a009f364:  d0 33 20 04  sth  %o0, [ %o4 + 4 ]
a009f368:  90 10 20 04  mov  4, %o0
a009f36c:  7f ff 85 50  call  0xa00808ac
a009f370:  92 10 20 00  clr  %o1
a009f374:  10 bf ff d8  b  0xa009f2d4
a009f378:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a009f37c:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a009f380:  c0 2a a0 56  clrb  [ %o2 + 0x56 ]	! 0xa8025c56
a009f384:  40 00 ed 3b  call  0xa00da870
a009f388:  90 10 20 00  clr  %o0
a009f38c:  40 00 ed 96  call  0xa00da9e4
a009f390:  90 0a 20 ff  and  %o0, 0xff, %o0
a009f394:  10 bf ff de  b  0xa009f30c
a009f398:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a009f39c:  ea 34 20 04  sth  %l5, [ %l0 + 4 ]
a009f3a0:  90 10 20 04  mov  4, %o0
a009f3a4:  7f ff 85 42  call  0xa00808ac
a009f3a8:  92 10 20 00  clr  %o1
a009f3ac:  10 bf ff 8f  b  0xa009f1e8
a009f3b0:  2b 2a 00 ab  sethi  %hi(0xa802ac00), %l5
a009f3b4:  e0 0c 61 e6  ldub  [ %l1 + 0x1e6 ], %l0
a009f3b8:  80 a4 20 01  cmp  %l0, 1
a009f3bc:  12 bf ff 9d  bne  0xa009f230
a009f3c0:  9a 14 a2 90  or  %l2, 0x290, %o5
a009f3c4:  80 a2 60 00  cmp  %o1, 0
a009f3c8:  22 bf ff 9b  be,a   0xa009f234
a009f3cc:  d2 0b 61 e2  ldub  [ %o5 + 0x1e2 ], %o1
a009f3d0:  e4 0c 61 e4  ldub  [ %l1 + 0x1e4 ], %l2
a009f3d4:  80 a4 a0 00  cmp  %l2, 0
a009f3d8:  32 80 00 02  bne,a   0xa009f3e0
a009f3dc:  c0 2c 61 e4  clrb  [ %l1 + 0x1e4 ]
a009f3e0:  a2 02 7f ff  add  %o1, -1, %l1
a009f3e4:  92 0c 60 ff  and  %l1, 0xff, %o1
a009f3e8:  40 00 49 ef  call  0xa00b1ba4
a009f3ec:  d0 0a e0 56  ldub  [ %o3 + 0x56 ], %o0
a009f3f0:  92 10 21 0a  mov  0x10a, %o1
a009f3f4:  10 bf ff a4  b  0xa009f284
a009f3f8:  d2 25 63 ec  st  %o1, [ %l5 + 0x3ec ]
a009f3fc:  96 15 23 f4  or  %l4, 0x3f4, %o3
a009f400:  c2 12 e0 18  lduh  [ %o3 + 0x18 ], %g1
a009f404:  1f 3f ff e0  sethi  %hi(0xffff8000), %o7
a009f408:  98 28 40 0f  andn  %g1, %o7, %o4
a009f40c:  a8 10 20 02  mov  2, %l4
a009f410:  d8 32 e0 18  sth  %o4, [ %o3 + 0x18 ]
a009f414:  e8 2a e0 3f  stb  %l4, [ %o3 + 0x3f ]
a009f418:  90 10 20 00  clr  %o0
a009f41c:  10 bf ff 95  b  0xa009f270
a009f420:  92 10 20 03  mov  3, %o1
a009f424:  81 c7 e0 08  ret
a009f428:  81 e8 00 00  restore
