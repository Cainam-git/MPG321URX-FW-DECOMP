# leon2m FUN_a010f064 0xa010f064-0xa010f50c (1192 bytes)
a010f064:  9d e3 bf 98  save  %sp, -104, %sp
a010f068:  83 2f 20 10  sll  %i4, 0x10, %g1
a010f06c:  b5 2e a0 10  sll  %i2, 0x10, %i2
a010f070:  b9 30 60 11  srl  %g1, 0x11, %i4
a010f074:  b5 36 a0 11  srl  %i2, 0x11, %i2
a010f078:  b7 2e e0 10  sll  %i3, 0x10, %i3
a010f07c:  83 2f 60 10  sll  %i5, 0x10, %g1
a010f080:  b7 36 e0 10  srl  %i3, 0x10, %i3
a010f084:  b5 2e a0 10  sll  %i2, 0x10, %i2
a010f088:  bb 30 60 10  srl  %g1, 0x10, %i5
a010f08c:  b9 2f 20 10  sll  %i4, 0x10, %i4
a010f090:  9e 0e 20 ff  and  %i0, 0xff, %o7
a010f094:  b4 16 80 1b  or  %i2, %i3, %i2
a010f098:  b6 17 00 1d  or  %i4, %i5, %i3
a010f09c:  80 a3 e0 02  cmp  %o7, 2
a010f0a0:  08 80 00 03  bleu  0xa010f0ac
a010f0a4:  82 10 00 18  mov  %i0, %g1
a010f0a8:  82 10 20 00  clr  %g1
a010f0ac:  b8 08 60 ff  and  %g1, 0xff, %i4
a010f0b0:  83 2f 20 02  sll  %i4, 2, %g1
a010f0b4:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010f0b8:  b8 13 62 f0  or  %o5, 0x2f0, %i4	! 0x19aef0
a010f0bc:  fa 07 00 01  ld  [ %i4 + %g1 ], %i5
a010f0c0:  80 8e 60 ff  btst  0xff, %i1
a010f0c4:  d8 07 40 00  ld  [ %i5 ], %o4
a010f0c8:  12 80 00 64  bne  0xa010f258
a010f0cc:  80 a3 e0 02  cmp  %o7, 2
a010f0d0:  18 80 00 e6  bgu  0xa010f468
a010f0d4:  b2 10 00 1c  mov  %i4, %i1
a010f0d8:  bb 2b e0 02  sll  %o7, 2, %i5
a010f0dc:  f2 07 00 1d  ld  [ %i4 + %i5 ], %i1
a010f0e0:  82 0e 20 ff  and  %i0, 0xff, %g1
a010f0e4:  f4 26 60 08  st  %i2, [ %i1 + 8 ]
a010f0e8:  80 a0 60 02  cmp  %g1, 2
a010f0ec:  08 80 00 eb  bleu  0xa010f498
a010f0f0:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010f0f4:  b8 10 20 00  clr  %i4
a010f0f8:  b2 16 22 e4  or  %i0, 0x2e4, %i1
a010f0fc:  83 2f 20 02  sll  %i4, 2, %g1
a010f100:  fa 06 40 01  ld  [ %i1 + %g1 ], %i5
a010f104:  b8 07 20 01  inc  %i4
a010f108:  f4 27 60 08  st  %i2, [ %i5 + 8 ]
a010f10c:  80 a7 20 02  cmp  %i4, 2
a010f110:  08 bf ff fc  bleu  0xa010f100
a010f114:  83 2f 20 02  sll  %i4, 2, %g1
a010f118:  80 a3 e0 02  cmp  %o7, 2
a010f11c:  08 80 00 e7  bleu  0xa010f4b8
a010f120:  82 13 62 f0  or  %o5, 0x2f0, %g1
a010f124:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010f128:  b4 10 62 f0  or  %g1, 0x2f0, %i2	! 0x19aef0
a010f12c:  b8 10 20 00  clr  %i4
a010f130:  bb 2f 20 02  sll  %i4, 2, %i5
a010f134:  f2 06 80 1d  ld  [ %i2 + %i5 ], %i1
a010f138:  b8 07 20 01  inc  %i4
a010f13c:  f6 26 60 0c  st  %i3, [ %i1 + 0xc ]
a010f140:  80 a7 20 02  cmp  %i4, 2
a010f144:  08 bf ff fc  bleu  0xa010f134
a010f148:  bb 2f 20 02  sll  %i4, 2, %i5
a010f14c:  80 a3 e0 02  cmp  %o7, 2
a010f150:  08 80 00 e1  bleu  0xa010f4d4
a010f154:  b2 16 22 e4  or  %i0, 0x2e4, %i1
a010f158:  33 00 06 6b  sethi  %hi(0x19ac00), %i1
a010f15c:  b4 16 62 e4  or  %i1, 0x2e4, %i2	! 0x19aee4
a010f160:  b8 10 20 00  clr  %i4
a010f164:  83 2f 20 02  sll  %i4, 2, %g1
a010f168:  fa 06 80 01  ld  [ %i2 + %g1 ], %i5
a010f16c:  b8 07 20 01  inc  %i4
a010f170:  f6 27 60 0c  st  %i3, [ %i5 + 0xc ]
a010f174:  80 a7 20 02  cmp  %i4, 2
a010f178:  08 bf ff fc  bleu  0xa010f168
a010f17c:  83 2f 20 02  sll  %i4, 2, %g1
a010f180:  80 a3 e0 02  cmp  %o7, 2
a010f184:  08 80 00 da  bleu  0xa010f4ec
a010f188:  b6 13 20 01  or  %o4, 1, %i3
a010f18c:  3b 00 06 6b  sethi  %hi(0x19ac00), %i5
a010f190:  b4 17 62 f0  or  %i5, 0x2f0, %i2	! 0x19aef0
a010f194:  b8 10 20 00  clr  %i4
a010f198:  83 2f 20 02  sll  %i4, 2, %g1
a010f19c:  f2 06 80 01  ld  [ %i2 + %g1 ], %i1
a010f1a0:  b8 07 20 01  inc  %i4
a010f1a4:  f6 26 40 00  st  %i3, [ %i1 ]
a010f1a8:  80 a7 20 02  cmp  %i4, 2
a010f1ac:  08 bf ff fc  bleu  0xa010f19c
a010f1b0:  83 2f 20 02  sll  %i4, 2, %g1
a010f1b4:  80 a3 e0 02  cmp  %o7, 2
a010f1b8:  08 80 00 a7  bleu  0xa010f454
a010f1bc:  b2 16 22 e4  or  %i0, 0x2e4, %i1
a010f1c0:  33 00 06 6b  sethi  %hi(0x19ac00), %i1
a010f1c4:  b4 16 62 e4  or  %i1, 0x2e4, %i2	! 0x19aee4
a010f1c8:  b8 10 20 00  clr  %i4
a010f1cc:  83 2f 20 02  sll  %i4, 2, %g1
a010f1d0:  fa 06 80 01  ld  [ %i2 + %g1 ], %i5
a010f1d4:  b8 07 20 01  inc  %i4
a010f1d8:  f6 27 40 00  st  %i3, [ %i5 ]
a010f1dc:  80 a7 20 02  cmp  %i4, 2
a010f1e0:  08 bf ff fc  bleu  0xa010f1d0
a010f1e4:  83 2f 20 02  sll  %i4, 2, %g1
a010f1e8:  3b 00 01 40  sethi  %hi(0x50000), %i5
a010f1ec:  80 a3 e0 02  cmp  %o7, 2
a010f1f0:  08 80 00 64  bleu  0xa010f380
a010f1f4:  b6 17 60 05  or  %i5, 5, %i3
a010f1f8:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010f1fc:  b4 10 62 f0  or  %g1, 0x2f0, %i2	! 0x19aef0
a010f200:  b8 10 20 00  clr  %i4
a010f204:  bb 2f 20 02  sll  %i4, 2, %i5
a010f208:  f2 06 80 1d  ld  [ %i2 + %i5 ], %i1
a010f20c:  b8 07 20 01  inc  %i4
a010f210:  f6 26 60 18  st  %i3, [ %i1 + 0x18 ]
a010f214:  80 a7 20 02  cmp  %i4, 2
a010f218:  08 bf ff fc  bleu  0xa010f208
a010f21c:  bb 2f 20 02  sll  %i4, 2, %i5
a010f220:  80 a3 e0 02  cmp  %o7, 2
a010f224:  08 80 00 5f  bleu  0xa010f3a0
a010f228:  82 16 22 e4  or  %i0, 0x2e4, %g1
a010f22c:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010f230:  b4 16 22 e4  or  %i0, 0x2e4, %i2	! 0x19aee4
a010f234:  b8 10 20 00  clr  %i4
a010f238:  bb 2f 20 02  sll  %i4, 2, %i5
a010f23c:  f2 06 80 1d  ld  [ %i2 + %i5 ], %i1
a010f240:  b8 07 20 01  inc  %i4
a010f244:  f6 26 60 18  st  %i3, [ %i1 + 0x18 ]
a010f248:  80 a7 20 02  cmp  %i4, 2
a010f24c:  08 bf ff fc  bleu  0xa010f23c
a010f250:  bb 2f 20 02  sll  %i4, 2, %i5
a010f254:  30 80 00 ac  b,a   0xa010f504
a010f258:  18 80 00 56  bgu  0xa010f3b0
a010f25c:  b2 10 00 1c  mov  %i4, %i1
a010f260:  bb 2b e0 02  sll  %o7, 2, %i5
a010f264:  f2 07 00 1d  ld  [ %i4 + %i5 ], %i1
a010f268:  82 0e 20 ff  and  %i0, 0xff, %g1
a010f26c:  f4 26 60 10  st  %i2, [ %i1 + 0x10 ]
a010f270:  80 a0 60 02  cmp  %g1, 2
a010f274:  08 80 00 5b  bleu  0xa010f3e0
a010f278:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010f27c:  b8 10 20 00  clr  %i4
a010f280:  b2 16 22 e4  or  %i0, 0x2e4, %i1
a010f284:  83 2f 20 02  sll  %i4, 2, %g1
a010f288:  fa 06 40 01  ld  [ %i1 + %g1 ], %i5
a010f28c:  b8 07 20 01  inc  %i4
a010f290:  f4 27 60 10  st  %i2, [ %i5 + 0x10 ]
a010f294:  80 a7 20 02  cmp  %i4, 2
a010f298:  08 bf ff fc  bleu  0xa010f288
a010f29c:  83 2f 20 02  sll  %i4, 2, %g1
a010f2a0:  80 a3 e0 02  cmp  %o7, 2
a010f2a4:  08 80 00 57  bleu  0xa010f400
a010f2a8:  82 13 62 f0  or  %o5, 0x2f0, %g1
a010f2ac:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010f2b0:  b4 10 62 f0  or  %g1, 0x2f0, %i2	! 0x19aef0
a010f2b4:  b8 10 20 00  clr  %i4
a010f2b8:  bb 2f 20 02  sll  %i4, 2, %i5
a010f2bc:  f2 06 80 1d  ld  [ %i2 + %i5 ], %i1
a010f2c0:  b8 07 20 01  inc  %i4
a010f2c4:  f6 26 60 14  st  %i3, [ %i1 + 0x14 ]
a010f2c8:  80 a7 20 02  cmp  %i4, 2
a010f2cc:  08 bf ff fc  bleu  0xa010f2bc
a010f2d0:  bb 2f 20 02  sll  %i4, 2, %i5
a010f2d4:  80 a3 e0 02  cmp  %o7, 2
a010f2d8:  08 80 00 51  bleu  0xa010f41c
a010f2dc:  b2 16 22 e4  or  %i0, 0x2e4, %i1
a010f2e0:  33 00 06 6b  sethi  %hi(0x19ac00), %i1
a010f2e4:  b4 16 62 e4  or  %i1, 0x2e4, %i2	! 0x19aee4
a010f2e8:  b8 10 20 00  clr  %i4
a010f2ec:  83 2f 20 02  sll  %i4, 2, %g1
a010f2f0:  fa 06 80 01  ld  [ %i2 + %g1 ], %i5
a010f2f4:  b8 07 20 01  inc  %i4
a010f2f8:  f6 27 60 14  st  %i3, [ %i5 + 0x14 ]
a010f2fc:  80 a7 20 02  cmp  %i4, 2
a010f300:  08 bf ff fc  bleu  0xa010f2f0
a010f304:  83 2f 20 02  sll  %i4, 2, %g1
a010f308:  80 a3 e0 02  cmp  %o7, 2
a010f30c:  08 80 00 4a  bleu  0xa010f434
a010f310:  b6 13 20 10  or  %o4, 0x10, %i3
a010f314:  3b 00 06 6b  sethi  %hi(0x19ac00), %i5
a010f318:  b4 17 62 f0  or  %i5, 0x2f0, %i2	! 0x19aef0
a010f31c:  b8 10 20 00  clr  %i4
a010f320:  83 2f 20 02  sll  %i4, 2, %g1
a010f324:  f2 06 80 01  ld  [ %i2 + %g1 ], %i1
a010f328:  b8 07 20 01  inc  %i4
a010f32c:  f6 26 40 00  st  %i3, [ %i1 ]
a010f330:  80 a7 20 02  cmp  %i4, 2
a010f334:  08 bf ff fc  bleu  0xa010f324
a010f338:  83 2f 20 02  sll  %i4, 2, %g1
a010f33c:  80 a3 e0 02  cmp  %o7, 2
a010f340:  08 80 00 45  bleu  0xa010f454
a010f344:  b2 16 22 e4  or  %i0, 0x2e4, %i1
a010f348:  33 00 06 6b  sethi  %hi(0x19ac00), %i1
a010f34c:  b4 16 62 e4  or  %i1, 0x2e4, %i2	! 0x19aee4
a010f350:  b8 10 20 00  clr  %i4
a010f354:  83 2f 20 02  sll  %i4, 2, %g1
a010f358:  fa 06 80 01  ld  [ %i2 + %g1 ], %i5
a010f35c:  b8 07 20 01  inc  %i4
a010f360:  f6 27 40 00  st  %i3, [ %i5 ]
a010f364:  80 a7 20 02  cmp  %i4, 2
a010f368:  08 bf ff fc  bleu  0xa010f358
a010f36c:  83 2f 20 02  sll  %i4, 2, %g1
a010f370:  3b 00 01 40  sethi  %hi(0x50000), %i5
a010f374:  80 a3 e0 02  cmp  %o7, 2
a010f378:  18 bf ff a0  bgu  0xa010f1f8
a010f37c:  b6 17 60 05  or  %i5, 5, %i3
a010f380:  82 13 62 f0  or  %o5, 0x2f0, %g1
a010f384:  b9 2b e0 02  sll  %o7, 2, %i4
a010f388:  f4 00 40 1c  ld  [ %g1 + %i4 ], %i2
a010f38c:  f6 26 a0 18  st  %i3, [ %i2 + 0x18 ]
a010f390:  80 a3 e0 02  cmp  %o7, 2
a010f394:  38 bf ff a7  bgu,a   0xa010f230
a010f398:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010f39c:  82 16 22 e4  or  %i0, 0x2e4, %g1	! 0x19aee4
a010f3a0:  b9 2b e0 02  sll  %o7, 2, %i4
a010f3a4:  f4 00 40 1c  ld  [ %g1 + %i4 ], %i2
a010f3a8:  f6 26 a0 18  st  %i3, [ %i2 + 0x18 ]
a010f3ac:  30 80 00 56  b,a   0xa010f504
a010f3b0:  b8 10 20 00  clr  %i4
a010f3b4:  83 2f 20 02  sll  %i4, 2, %g1
a010f3b8:  fa 06 40 01  ld  [ %i1 + %g1 ], %i5
a010f3bc:  b8 07 20 01  inc  %i4
a010f3c0:  f4 27 60 10  st  %i2, [ %i5 + 0x10 ]
a010f3c4:  80 a7 20 02  cmp  %i4, 2
a010f3c8:  08 bf ff fc  bleu  0xa010f3b8
a010f3cc:  83 2f 20 02  sll  %i4, 2, %g1
a010f3d0:  82 0e 20 ff  and  %i0, 0xff, %g1
a010f3d4:  80 a0 60 02  cmp  %g1, 2
a010f3d8:  18 bf ff a9  bgu  0xa010f27c
a010f3dc:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010f3e0:  b3 28 60 02  sll  %g1, 2, %i1
a010f3e4:  ba 16 22 e4  or  %i0, 0x2e4, %i5
a010f3e8:  f8 07 40 19  ld  [ %i5 + %i1 ], %i4
a010f3ec:  f4 27 20 10  st  %i2, [ %i4 + 0x10 ]
a010f3f0:  80 a3 e0 02  cmp  %o7, 2
a010f3f4:  18 bf ff af  bgu  0xa010f2b0
a010f3f8:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010f3fc:  82 13 62 f0  or  %o5, 0x2f0, %g1
a010f400:  b9 2b e0 02  sll  %o7, 2, %i4
a010f404:  f4 00 40 1c  ld  [ %g1 + %i4 ], %i2
a010f408:  f6 26 a0 14  st  %i3, [ %i2 + 0x14 ]
a010f40c:  80 a3 e0 02  cmp  %o7, 2
a010f410:  18 bf ff b5  bgu  0xa010f2e4
a010f414:  33 00 06 6b  sethi  %hi(0x19ac00), %i1
a010f418:  b2 16 22 e4  or  %i0, 0x2e4, %i1
a010f41c:  b9 2b e0 02  sll  %o7, 2, %i4
a010f420:  f4 06 40 1c  ld  [ %i1 + %i4 ], %i2
a010f424:  f6 26 a0 14  st  %i3, [ %i2 + 0x14 ]
a010f428:  80 a3 e0 02  cmp  %o7, 2
a010f42c:  18 bf ff ba  bgu  0xa010f314
a010f430:  b6 13 20 10  or  %o4, 0x10, %i3
a010f434:  ba 13 62 f0  or  %o5, 0x2f0, %i5
a010f438:  b9 2b e0 02  sll  %o7, 2, %i4
a010f43c:  f4 07 40 1c  ld  [ %i5 + %i4 ], %i2
a010f440:  f6 26 80 00  st  %i3, [ %i2 ]
a010f444:  80 a3 e0 02  cmp  %o7, 2
a010f448:  18 bf ff c1  bgu  0xa010f34c
a010f44c:  33 00 06 6b  sethi  %hi(0x19ac00), %i1
a010f450:  b2 16 22 e4  or  %i0, 0x2e4, %i1
a010f454:  b9 2b e0 02  sll  %o7, 2, %i4
a010f458:  f4 06 40 1c  ld  [ %i1 + %i4 ], %i2
a010f45c:  f6 26 80 00  st  %i3, [ %i2 ]
a010f460:  10 bf ff 63  b  0xa010f1ec
a010f464:  3b 00 01 40  sethi  %hi(0x50000), %i5
a010f468:  b8 10 20 00  clr  %i4
a010f46c:  83 2f 20 02  sll  %i4, 2, %g1
a010f470:  fa 06 40 01  ld  [ %i1 + %g1 ], %i5
a010f474:  b8 07 20 01  inc  %i4
a010f478:  f4 27 60 08  st  %i2, [ %i5 + 8 ]
a010f47c:  80 a7 20 02  cmp  %i4, 2
a010f480:  08 bf ff fc  bleu  0xa010f470
a010f484:  83 2f 20 02  sll  %i4, 2, %g1
a010f488:  82 0e 20 ff  and  %i0, 0xff, %g1
a010f48c:  80 a0 60 02  cmp  %g1, 2
a010f490:  18 bf ff 19  bgu  0xa010f0f4
a010f494:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010f498:  b3 28 60 02  sll  %g1, 2, %i1
a010f49c:  ba 16 22 e4  or  %i0, 0x2e4, %i5
a010f4a0:  f8 07 40 19  ld  [ %i5 + %i1 ], %i4
a010f4a4:  f4 27 20 08  st  %i2, [ %i4 + 8 ]
a010f4a8:  80 a3 e0 02  cmp  %o7, 2
a010f4ac:  18 bf ff 1f  bgu  0xa010f128
a010f4b0:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010f4b4:  82 13 62 f0  or  %o5, 0x2f0, %g1
a010f4b8:  b9 2b e0 02  sll  %o7, 2, %i4
a010f4bc:  f4 00 40 1c  ld  [ %g1 + %i4 ], %i2
a010f4c0:  f6 26 a0 0c  st  %i3, [ %i2 + 0xc ]
a010f4c4:  80 a3 e0 02  cmp  %o7, 2
a010f4c8:  18 bf ff 25  bgu  0xa010f15c
a010f4cc:  33 00 06 6b  sethi  %hi(0x19ac00), %i1
a010f4d0:  b2 16 22 e4  or  %i0, 0x2e4, %i1
a010f4d4:  b9 2b e0 02  sll  %o7, 2, %i4
a010f4d8:  f4 06 40 1c  ld  [ %i1 + %i4 ], %i2
a010f4dc:  f6 26 a0 0c  st  %i3, [ %i2 + 0xc ]
a010f4e0:  80 a3 e0 02  cmp  %o7, 2
a010f4e4:  18 bf ff 2a  bgu  0xa010f18c
a010f4e8:  b6 13 20 01  or  %o4, 1, %i3
a010f4ec:  ba 13 62 f0  or  %o5, 0x2f0, %i5
a010f4f0:  b9 2b e0 02  sll  %o7, 2, %i4
a010f4f4:  f4 07 40 1c  ld  [ %i5 + %i4 ], %i2
a010f4f8:  f6 26 80 00  st  %i3, [ %i2 ]
a010f4fc:  10 bf ff 2f  b  0xa010f1b8
a010f500:  80 a3 e0 02  cmp  %o7, 2
a010f504:  81 c7 e0 08  ret
a010f508:  81 e8 00 00  restore
