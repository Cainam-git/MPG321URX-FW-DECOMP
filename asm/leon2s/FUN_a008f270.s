# leon2s FUN_a008f270 0xa008f270-0xa008f450 (480 bytes)
a008f270:  9d e3 bf 98  save  %sp, -104, %sp
a008f274:  11 28 01 a3  sethi  %hi(0xa0068c00), %o0
a008f278:  90 12 21 e8  or  %o0, 0x1e8, %o0	! 0xa0068de8
a008f27c:  7f ff 8f 72  call  0xa0073044
a008f280:  92 10 00 19  mov  %i1, %o1
a008f284:  80 a6 60 94  cmp  %i1, 0x94
a008f288:  a2 10 20 00  clr  %l1
a008f28c:  a0 10 20 00  clr  %l0
a008f290:  a4 10 20 00  clr  %l2
a008f294:  a6 10 20 00  clr  %l3
a008f298:  a8 10 20 00  clr  %l4
a008f29c:  04 80 00 07  ble  0xa008f2b8
a008f2a0:  82 10 20 00  clr  %g1
a008f2a4:  82 06 7f 6b  add  %i1, -149, %g1
a008f2a8:  80 a0 60 bf  cmp  %g1, 0xbf
a008f2ac:  08 80 00 03  bleu  0xa008f2b8
a008f2b0:  82 10 20 01  mov  1, %g1
a008f2b4:  82 10 20 02  mov  2, %g1
a008f2b8:  82 08 60 ff  and  %g1, 0xff, %g1
a008f2bc:  80 a0 60 01  cmp  %g1, 1
a008f2c0:  02 80 00 13  be  0xa008f30c
a008f2c4:  11 28 01 a3  sethi  %hi(0xa0068c00), %o0
a008f2c8:  14 80 00 07  bg  0xa008f2e4
a008f2cc:  80 a0 60 02  cmp  %g1, 2
a008f2d0:  80 a0 60 00  cmp  %g1, 0
a008f2d4:  02 80 00 08  be  0xa008f2f4
a008f2d8:  11 28 01 a3  sethi  %hi(0xa0068c00), %o0
a008f2dc:  10 80 00 1c  b  0xa008f34c
a008f2e0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008f2e4:  02 80 00 12  be  0xa008f32c
a008f2e8:  11 28 01 a3  sethi  %hi(0xa0068c00), %o0
a008f2ec:  10 80 00 18  b  0xa008f34c
a008f2f0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008f2f4:  7f ff 90 74  call  0xa00734c4
a008f2f8:  90 12 22 38  or  %o0, 0x238, %o0
a008f2fc:  a2 10 20 00  clr  %l1
a008f300:  a0 10 20 00  clr  %l0
a008f304:  10 80 00 07  b  0xa008f320
a008f308:  a4 10 20 00  clr  %l2
a008f30c:  7f ff 90 6e  call  0xa00734c4
a008f310:  90 12 22 08  or  %o0, 0x208, %o0
a008f314:  a2 10 20 06  mov  6, %l1
a008f318:  a0 10 20 01  mov  1, %l0
a008f31c:  a4 10 20 11  mov  0x11, %l2
a008f320:  a6 10 20 00  clr  %l3
a008f324:  10 80 00 09  b  0xa008f348
a008f328:  a8 10 20 00  clr  %l4
a008f32c:  7f ff 90 66  call  0xa00734c4
a008f330:  90 12 22 60  or  %o0, 0x260, %o0
a008f334:  a2 10 20 1b  mov  0x1b, %l1
a008f338:  a0 10 20 02  mov  2, %l0
a008f33c:  a4 10 20 22  mov  0x22, %l2
a008f340:  a6 10 20 03  mov  3, %l3
a008f344:  a8 10 20 01  mov  1, %l4
a008f348:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008f34c:  96 10 20 80  mov  0x80, %o3
a008f350:  98 10 20 00  clr  %o4
a008f354:  94 10 20 7d  mov  0x7d, %o2
a008f358:  90 10 00 18  mov  %i0, %o0
a008f35c:  40 00 63 5c  call  0xa00a80cc
a008f360:  92 10 20 01  mov  1, %o1
a008f364:  90 10 00 18  mov  %i0, %o0
a008f368:  7f ff fb 4c  call  0xa008e098
a008f36c:  92 0c 60 1f  and  %l1, 0x1f, %o1
a008f370:  a0 0c 20 ff  and  %l0, 0xff, %l0
a008f374:  90 10 00 18  mov  %i0, %o0
a008f378:  92 10 00 10  mov  %l0, %o1
a008f37c:  7f ff fb 5d  call  0xa008e0f0
a008f380:  94 10 20 00  clr  %o2
a008f384:  90 10 00 18  mov  %i0, %o0
a008f388:  7f ff fb 9e  call  0xa008e200
a008f38c:  92 0c a0 33  and  %l2, 0x33, %o1
a008f390:  80 a4 20 02  cmp  %l0, 2
a008f394:  32 80 00 09  bne,a   0xa008f3b8
a008f398:  92 10 00 10  mov  %l0, %o1
a008f39c:  90 10 00 18  mov  %i0, %o0
a008f3a0:  92 10 20 01  mov  1, %o1
a008f3a4:  94 10 20 9b  mov  0x9b, %o2
a008f3a8:  96 10 20 70  mov  0x70, %o3
a008f3ac:  40 00 63 76  call  0xa00a8184
a008f3b0:  98 10 20 10  mov  0x10, %o4
a008f3b4:  92 10 00 10  mov  %l0, %o1
a008f3b8:  94 10 20 00  clr  %o2
a008f3bc:  7f ff fb c1  call  0xa008e2c0
a008f3c0:  90 10 00 18  mov  %i0, %o0
a008f3c4:  90 10 00 18  mov  %i0, %o0
a008f3c8:  7f ff fb fe  call  0xa008e3c0
a008f3cc:  92 10 20 00  clr  %o1
a008f3d0:  a0 0c e0 ff  and  %l3, 0xff, %l0
a008f3d4:  90 10 00 18  mov  %i0, %o0
a008f3d8:  92 10 20 20  mov  0x20, %o1
a008f3dc:  40 00 0a 46  call  0xa0091cf4
a008f3e0:  94 10 00 10  mov  %l0, %o2
a008f3e4:  80 a4 20 03  cmp  %l0, 3
a008f3e8:  12 80 00 17  bne  0xa008f444
a008f3ec:  b2 0d 20 01  and  %l4, 1, %i1
a008f3f0:  90 10 00 18  mov  %i0, %o0
a008f3f4:  92 10 20 01  mov  1, %o1
a008f3f8:  94 10 20 31  mov  0x31, %o2
a008f3fc:  40 00 63 16  call  0xa00a8054
a008f400:  96 10 20 00  clr  %o3
a008f404:  90 10 00 18  mov  %i0, %o0
a008f408:  92 10 20 01  mov  1, %o1
a008f40c:  94 10 20 32  mov  0x32, %o2
a008f410:  40 00 63 11  call  0xa00a8054
a008f414:  96 10 20 00  clr  %o3
a008f418:  90 10 00 18  mov  %i0, %o0
a008f41c:  92 10 20 01  mov  1, %o1
a008f420:  94 10 20 33  mov  0x33, %o2
a008f424:  40 00 63 0c  call  0xa00a8054
a008f428:  96 10 20 32  mov  0x32, %o3
a008f42c:  90 10 00 18  mov  %i0, %o0
a008f430:  92 10 20 01  mov  1, %o1
a008f434:  94 10 20 34  mov  0x34, %o2
a008f438:  40 00 63 07  call  0xa00a8054
a008f43c:  96 10 20 00  clr  %o3
a008f440:  b2 0d 20 01  and  %l4, 1, %i1
a008f444:  7f ff fc 10  call  0xa008e484
a008f448:  81 e8 00 00  restore
a008f44c:  01 00 00 00  nop
