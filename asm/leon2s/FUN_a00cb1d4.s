# leon2s FUN_a00cb1d4 0xa00cb1d4-0xa00cb3e8 (532 bytes)
a00cb1d4:  9d e3 bf 88  save  %sp, -120, %sp
a00cb1d8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cb1dc:  82 06 00 18  add  %i0, %i0, %g1
a00cb1e0:  82 00 40 18  add  %g1, %i0, %g1
a00cb1e4:  a1 28 60 03  sll  %g1, 3, %l0
a00cb1e8:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00cb1ec:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00cb1f0:  a2 13 63 b0  or  %o5, 0x3b0, %l1
a00cb1f4:  a6 10 63 ff  or  %g1, 0x3ff, %l3
a00cb1f8:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cb1fc:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cb200:  82 08 40 13  and  %g1, %l3, %g1
a00cb204:  82 10 40 0d  or  %g1, %o5, %g1
a00cb208:  25 2a 01 f4  sethi  %hi(0xa807d000), %l2
a00cb20c:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cb210:  90 10 00 18  mov  %i0, %o0
a00cb214:  7f ff f9 61  call  0xa00c9798
a00cb218:  92 14 a2 50  or  %l2, 0x250, %o1
a00cb21c:  80 8a 20 ff  btst  0xff, %o0
a00cb220:  32 80 00 22  bne,a   0xa00cb2a8
a00cb224:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cb228:  82 14 a2 50  or  %l2, 0x250, %g1
a00cb22c:  d8 08 60 01  ldub  [ %g1 + 1 ], %o4
a00cb230:  82 0b 20 03  and  %o4, 3, %g1
a00cb234:  83 28 60 08  sll  %g1, 8, %g1
a00cb238:  da 0c a2 50  ldub  [ %l2 + 0x250 ], %o5
a00cb23c:  80 8b 20 0c  btst  0xc, %o4
a00cb240:  12 80 00 19  bne  0xa00cb2a4
a00cb244:  82 00 40 0d  add  %g1, %o5, %g1
a00cb248:  83 28 60 10  sll  %g1, 0x10, %g1
a00cb24c:  80 a0 60 00  cmp  %g1, 0
a00cb250:  12 80 00 05  bne  0xa00cb264
a00cb254:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cb258:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cb25c:  10 80 00 14  b  0xa00cb2ac
a00cb260:  82 10 40 0d  or  %g1, %o5, %g1
a00cb264:  90 10 00 18  mov  %i0, %o0
a00cb268:  92 10 20 74  mov  0x74, %o1
a00cb26c:  94 10 20 80  mov  0x80, %o2
a00cb270:  7f ff f3 76  call  0xa00c8048
a00cb274:  96 10 20 11  mov  0x11, %o3
a00cb278:  80 8a 20 ff  btst  0xff, %o0
a00cb27c:  32 80 00 0b  bne,a   0xa00cb2a8
a00cb280:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cb284:  29 2a 01 f3  sethi  %hi(0xa807cc00), %l4
a00cb288:  90 10 00 18  mov  %i0, %o0
a00cb28c:  92 15 22 50  or  %l4, 0x250, %o1
a00cb290:  7f ff f3 da  call  0xa00c81f8
a00cb294:  94 10 20 11  mov  0x11, %o2
a00cb298:  80 8a 20 ff  btst  0xff, %o0
a00cb29c:  02 80 00 06  be  0xa00cb2b4
a00cb2a0:  90 10 00 18  mov  %i0, %o0
a00cb2a4:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cb2a8:  82 08 40 13  and  %g1, %l3, %g1
a00cb2ac:  10 80 00 4d  b  0xa00cb3e0
a00cb2b0:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cb2b4:  92 10 20 01  mov  1, %o1
a00cb2b8:  7f ff f5 4c  call  0xa00c87e8
a00cb2bc:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cb2c0:  a2 10 20 00  clr  %l1
a00cb2c4:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00cb2c8:  90 10 00 18  mov  %i0, %o0
a00cb2cc:  7f ff f1 29  call  0xa00c7770
a00cb2d0:  92 10 20 01  mov  1, %o1
a00cb2d4:  a4 07 bf f8  add  %fp, -8, %l2
a00cb2d8:  a2 04 60 01  inc  %l1
a00cb2dc:  a0 04 80 10  add  %l2, %l0, %l0
a00cb2e0:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cb2e4:  80 a0 60 07  cmp  %g1, 7
a00cb2e8:  08 bf ff f7  bleu  0xa00cb2c4
a00cb2ec:  d0 2c 3f f0  stb  %o0, [ %l0 + -16 ]
a00cb2f0:  90 10 00 18  mov  %i0, %o0
a00cb2f4:  92 10 20 03  mov  3, %o1
a00cb2f8:  7f ff f5 3c  call  0xa00c87e8
a00cb2fc:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cb300:  a2 10 20 08  mov  8, %l1
a00cb304:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00cb308:  90 10 00 18  mov  %i0, %o0
a00cb30c:  7f ff f1 19  call  0xa00c7770
a00cb310:  92 10 20 01  mov  1, %o1
a00cb314:  a2 04 60 01  inc  %l1
a00cb318:  a0 04 80 10  add  %l2, %l0, %l0
a00cb31c:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cb320:  80 a0 60 0f  cmp  %g1, 0xf
a00cb324:  08 bf ff f8  bleu  0xa00cb304
a00cb328:  d0 2c 3f f0  stb  %o0, [ %l0 + -16 ]
a00cb32c:  90 10 00 18  mov  %i0, %o0
a00cb330:  92 10 20 05  mov  5, %o1
a00cb334:  7f ff f5 2d  call  0xa00c87e8
a00cb338:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cb33c:  a2 10 20 00  clr  %l1
a00cb340:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cb344:  9a 15 22 50  or  %l4, 0x250, %o5
a00cb348:  82 00 40 0d  add  %g1, %o5, %g1
a00cb34c:  d4 08 60 01  ldub  [ %g1 + 1 ], %o2
a00cb350:  90 10 00 18  mov  %i0, %o0
a00cb354:  7f ff f0 c0  call  0xa00c7654
a00cb358:  92 10 20 01  mov  1, %o1
a00cb35c:  a2 04 60 01  inc  %l1
a00cb360:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cb364:  80 a0 60 0f  cmp  %g1, 0xf
a00cb368:  08 bf ff f8  bleu  0xa00cb348
a00cb36c:  9a 15 22 50  or  %l4, 0x250, %o5
a00cb370:  a2 10 20 00  clr  %l1
a00cb374:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cb378:  82 04 80 01  add  %l2, %g1, %g1
a00cb37c:  d4 08 7f f0  ldub  [ %g1 + -16 ], %o2
a00cb380:  90 10 00 18  mov  %i0, %o0
a00cb384:  7f ff f0 b4  call  0xa00c7654
a00cb388:  92 10 20 01  mov  1, %o1
a00cb38c:  a2 04 60 01  inc  %l1
a00cb390:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cb394:  80 a0 60 0f  cmp  %g1, 0xf
a00cb398:  08 bf ff f9  bleu  0xa00cb37c
a00cb39c:  82 04 80 01  add  %l2, %g1, %g1
a00cb3a0:  83 2e 20 02  sll  %i0, 2, %g1
a00cb3a4:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a00cb3a8:  82 00 40 18  add  %g1, %i0, %g1
a00cb3ac:  9a 13 62 38  or  %o5, 0x238, %o5
a00cb3b0:  96 00 40 0d  add  %g1, %o5, %o3
a00cb3b4:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a00cb3b8:  9a 13 61 a8  or  %o5, 0x1a8, %o5	! 0xa807cda8
a00cb3bc:  90 00 40 0d  add  %g1, %o5, %o0
a00cb3c0:  a2 10 20 00  clr  %l1
a00cb3c4:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cb3c8:  a2 04 60 01  inc  %l1
a00cb3cc:  da 0a c0 01  ldub  [ %o3 + %g1 ], %o5
a00cb3d0:  98 0c 60 ff  and  %l1, 0xff, %o4
a00cb3d4:  80 a3 20 04  cmp  %o4, 4
a00cb3d8:  08 bf ff fb  bleu  0xa00cb3c4
a00cb3dc:  da 2a 00 01  stb  %o5, [ %o0 + %g1 ]
a00cb3e0:  81 c7 e0 08  ret
a00cb3e4:  81 e8 00 00  restore
