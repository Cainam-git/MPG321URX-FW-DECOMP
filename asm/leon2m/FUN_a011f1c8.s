# leon2m FUN_a011f1c8 0xa011f1c8-0xa011f364 (412 bytes)
a011f1c8:  80 8a a0 ff  btst  0xff, %o2
a011f1cc:  02 80 00 12  be  0xa011f214
a011f1d0:  17 33 c0 45  sethi  %hi(0xcf011400), %o3
a011f1d4:  9a 12 e0 28  or  %o3, 0x28, %o5	! 0xcf011428
a011f1d8:  d4 03 40 00  ld  [ %o5 ], %o2
a011f1dc:  82 12 a0 03  or  %o2, 3, %g1
a011f1e0:  c2 23 40 00  st  %g1, [ %o5 ]
a011f1e4:  80 a2 20 02  cmp  %o0, 2
a011f1e8:  02 80 00 2c  be  0xa011f298
a011f1ec:  80 a2 20 01  cmp  %o0, 1
a011f1f0:  08 80 00 51  bleu  0xa011f334
a011f1f4:  19 00 06 8b  sethi  %hi(0x1a2c00), %o4
a011f1f8:  90 0a 60 ff  and  %o1, 0xff, %o0
a011f1fc:  92 10 20 03  mov  3, %o1
a011f200:  94 10 20 80  mov  0x80, %o2
a011f204:  96 10 20 01  mov  1, %o3
a011f208:  82 13 c0 00  mov  %o7, %g1
a011f20c:  7f ff 4a 54  call  0xa00f1b5c
a011f210:  9e 10 40 00  mov  %g1, %o7
a011f214:  9a 12 e0 28  or  %o3, 0x28, %o5
a011f218:  d4 03 40 00  ld  [ %o5 ], %o2
a011f21c:  82 12 a0 03  or  %o2, 3, %g1
a011f220:  c2 23 40 00  st  %g1, [ %o5 ]
a011f224:  80 a2 20 02  cmp  %o0, 2
a011f228:  02 80 00 30  be  0xa011f2e8
a011f22c:  80 a2 20 01  cmp  %o0, 1
a011f230:  08 80 00 0f  bleu  0xa011f26c
a011f234:  17 00 06 8b  sethi  %hi(0x1a2c00), %o3
a011f238:  15 33 c0 80  sethi  %hi(0xcf020000), %o2
a011f23c:  90 12 a1 14  or  %o2, 0x114, %o0	! 0xcf020114
a011f240:  d8 02 00 00  ld  [ %o0 ], %o4
a011f244:  9a 0b 20 07  and  %o4, 7, %o5
a011f248:  80 a3 60 05  cmp  %o5, 5
a011f24c:  02 bf ff eb  be  0xa011f1f8
a011f250:  90 0a 60 ff  and  %o1, 0xff, %o0
a011f254:  92 10 20 03  mov  3, %o1
a011f258:  94 10 20 80  mov  0x80, %o2
a011f25c:  96 10 20 00  clr  %o3
a011f260:  82 13 c0 00  mov  %o7, %g1
a011f264:  7f ff 4a 3e  call  0xa00f1b5c
a011f268:  9e 10 40 00  mov  %g1, %o7
a011f26c:  94 02 00 08  add  %o0, %o0, %o2
a011f270:  82 12 e3 b0  or  %o3, 0x3b0, %g1
a011f274:  d0 10 40 0a  lduh  [ %g1 + %o2 ], %o0
a011f278:  9b 2a 20 02  sll  %o0, 2, %o5
a011f27c:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011f280:  90 13 40 0c  or  %o5, %o4, %o0
a011f284:  d6 02 00 00  ld  [ %o0 ], %o3
a011f288:  94 0a e0 fe  and  %o3, 0xfe, %o2
a011f28c:  d4 22 00 00  st  %o2, [ %o0 ]
a011f290:  10 bf ff eb  b  0xa011f23c
a011f294:  15 33 c0 80  sethi  %hi(0xcf020000), %o2
a011f298:  19 00 06 8b  sethi  %hi(0x1a2c00), %o4
a011f29c:  90 13 23 b0  or  %o4, 0x3b0, %o0	! 0x1a2fb0
a011f2a0:  96 10 20 00  clr  %o3
a011f2a4:  98 10 20 00  clr  %o4
a011f2a8:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a011f2ac:  82 03 00 0c  add  %o4, %o4, %g1
a011f2b0:  d8 12 00 01  lduh  [ %o0 + %g1 ], %o4
a011f2b4:  9b 2b 20 02  sll  %o4, 2, %o5
a011f2b8:  9a 13 40 0a  or  %o5, %o2, %o5
a011f2bc:  c2 03 40 00  ld  [ %o5 ], %g1
a011f2c0:  98 10 60 01  or  %g1, 1, %o4
a011f2c4:  82 0b 20 ff  and  %o4, 0xff, %g1
a011f2c8:  96 02 e0 01  inc  %o3
a011f2cc:  98 0a e0 ff  and  %o3, 0xff, %o4
a011f2d0:  c2 23 40 00  st  %g1, [ %o5 ]
a011f2d4:  80 a3 20 01  cmp  %o4, 1
a011f2d8:  08 bf ff f6  bleu  0xa011f2b0
a011f2dc:  82 03 00 0c  add  %o4, %o4, %g1
a011f2e0:  10 bf ff c7  b  0xa011f1fc
a011f2e4:  90 0a 60 ff  and  %o1, 0xff, %o0
a011f2e8:  19 00 06 8b  sethi  %hi(0x1a2c00), %o4
a011f2ec:  90 13 23 b0  or  %o4, 0x3b0, %o0	! 0x1a2fb0
a011f2f0:  96 10 20 00  clr  %o3
a011f2f4:  98 10 20 00  clr  %o4
a011f2f8:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a011f2fc:  82 03 00 0c  add  %o4, %o4, %g1
a011f300:  d8 12 00 01  lduh  [ %o0 + %g1 ], %o4
a011f304:  9b 2b 20 02  sll  %o4, 2, %o5
a011f308:  9a 13 40 0a  or  %o5, %o2, %o5
a011f30c:  d8 03 40 00  ld  [ %o5 ], %o4
a011f310:  82 0b 20 fe  and  %o4, 0xfe, %g1
a011f314:  96 02 e0 01  inc  %o3
a011f318:  98 0a e0 ff  and  %o3, 0xff, %o4
a011f31c:  c2 23 40 00  st  %g1, [ %o5 ]
a011f320:  80 a3 20 01  cmp  %o4, 1
a011f324:  08 bf ff f7  bleu  0xa011f300
a011f328:  82 03 00 0c  add  %o4, %o4, %g1
a011f32c:  10 bf ff c4  b  0xa011f23c
a011f330:  15 33 c0 80  sethi  %hi(0xcf020000), %o2
a011f334:  96 13 23 b0  or  %o4, 0x3b0, %o3
a011f338:  94 02 00 08  add  %o0, %o0, %o2
a011f33c:  d0 12 c0 0a  lduh  [ %o3 + %o2 ], %o0
a011f340:  9b 2a 20 02  sll  %o0, 2, %o5
a011f344:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a011f348:  90 13 40 01  or  %o5, %g1, %o0
a011f34c:  d8 02 00 00  ld  [ %o0 ], %o4
a011f350:  96 13 20 01  or  %o4, 1, %o3
a011f354:  94 0a e0 ff  and  %o3, 0xff, %o2
a011f358:  d4 22 00 00  st  %o2, [ %o0 ]
a011f35c:  10 bf ff a8  b  0xa011f1fc
a011f360:  90 0a 60 ff  and  %o1, 0xff, %o0
