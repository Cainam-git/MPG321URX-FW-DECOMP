# leon2s FUN_a00a33f4 0xa00a33f4-0xa00a3578 (388 bytes)
a00a33f4:  9d e3 bf 98  save  %sp, -104, %sp
a00a33f8:  c2 0e 60 80  ldub  [ %i1 + 0x80 ], %g1
a00a33fc:  b4 10 00 19  mov  %i1, %i2
a00a3400:  80 a0 60 02  cmp  %g1, 2
a00a3404:  9a 10 00 18  mov  %i0, %o5
a00a3408:  90 10 20 00  clr  %o0
a00a340c:  12 80 00 03  bne  0xa00a3418
a00a3410:  ba 10 20 00  clr  %i5
a00a3414:  ba 10 20 01  mov  1, %i5
a00a3418:  c2 0e a1 00  ldub  [ %i2 + 0x100 ], %g1
a00a341c:  80 a0 60 02  cmp  %g1, 2
a00a3420:  22 80 00 02  be,a   0xa00a3428
a00a3424:  ba 10 20 02  mov  2, %i5
a00a3428:  c2 0e a1 80  ldub  [ %i2 + 0x180 ], %g1
a00a342c:  80 a0 60 02  cmp  %g1, 2
a00a3430:  22 80 00 02  be,a   0xa00a3438
a00a3434:  ba 10 20 03  mov  3, %i5
a00a3438:  82 0f 60 ff  and  %i5, 0xff, %g1
a00a343c:  80 a0 60 00  cmp  %g1, 0
a00a3440:  02 80 00 4c  be  0xa00a3570
a00a3444:  bb 28 60 07  sll  %g1, 7, %i5
a00a3448:  b8 07 60 7c  add  %i5, 0x7c, %i4
a00a344c:  80 a7 40 1c  cmp  %i5, %i4
a00a3450:  1a 80 00 48  bcc  0xa00a3570
a00a3454:  b6 10 00 1d  mov  %i5, %i3
a00a3458:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a345c:  98 10 61 e0  or  %g1, 0x1e0, %o4	! 0xa80791e0
a00a3460:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3464:  96 10 61 b8  or  %g1, 0x1b8, %o3	! 0xa80791b8
a00a3468:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a346c:  94 10 61 c8  or  %g1, 0x1c8, %o2	! 0xa80791c8
a00a3470:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3474:  92 10 61 c0  or  %g1, 0x1c0, %o1	! 0xa80791c0
a00a3478:  9e 10 00 1c  mov  %i4, %o7
a00a347c:  b2 06 e0 01  add  %i3, 1, %i1
a00a3480:  83 2e 60 10  sll  %i1, 0x10, %g1
a00a3484:  bb 2e e0 10  sll  %i3, 0x10, %i5
a00a3488:  bb 37 60 10  srl  %i5, 0x10, %i5
a00a348c:  b1 30 60 10  srl  %g1, 0x10, %i0
a00a3490:  c2 0e 80 1d  ldub  [ %i2 + %i5 ], %g1
a00a3494:  80 a0 60 d8  cmp  %g1, 0xd8
a00a3498:  12 80 00 33  bne  0xa00a3564
a00a349c:  b8 06 80 1d  add  %i2, %i5, %i4
a00a34a0:  c2 0f 20 01  ldub  [ %i4 + 1 ], %g1
a00a34a4:  80 a0 60 5d  cmp  %g1, 0x5d
a00a34a8:  12 80 00 30  bne  0xa00a3568
a00a34ac:  80 a6 00 0f  cmp  %i0, %o7
a00a34b0:  c2 0f 20 02  ldub  [ %i4 + 2 ], %g1
a00a34b4:  80 a0 60 c4  cmp  %g1, 0xc4
a00a34b8:  12 80 00 2c  bne  0xa00a3568
a00a34bc:  80 a6 00 0f  cmp  %i0, %o7
a00a34c0:  fa 0f 20 03  ldub  [ %i4 + 3 ], %i5
a00a34c4:  80 a7 60 01  cmp  %i5, 1
a00a34c8:  12 80 00 28  bne  0xa00a3568
a00a34cc:  80 a6 00 0f  cmp  %i0, %o7
a00a34d0:  c2 0f 3f ff  ldub  [ %i4 + -1 ], %g1
a00a34d4:  80 a0 60 6d  cmp  %g1, 0x6d
a00a34d8:  22 80 00 02  be,a   0xa00a34e0
a00a34dc:  90 10 20 01  mov  1, %o0
a00a34e0:  82 06 e0 04  add  %i3, 4, %g1
a00a34e4:  b2 08 60 ff  and  %g1, 0xff, %i1
a00a34e8:  82 06 80 19  add  %i2, %i1, %g1
a00a34ec:  c2 48 60 01  ldsb  [ %g1 + 1 ], %g1
a00a34f0:  80 a0 60 00  cmp  %g1, 0
a00a34f4:  b8 0a 20 ff  and  %o0, 0xff, %i4
a00a34f8:  16 80 00 04  bge  0xa00a3508
a00a34fc:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a3500:  10 80 00 03  b  0xa00a350c
a00a3504:  fa 2b 00 01  stb  %i5, [ %o4 + %g1 ]
a00a3508:  c0 2b 00 01  clrb  [ %o4 + %g1 ]
a00a350c:  b2 06 80 19  add  %i2, %i1, %i1
a00a3510:  fa 0e 60 02  ldub  [ %i1 + 2 ], %i5
a00a3514:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3518:  b0 0b 60 ff  and  %o5, 0xff, %i0
a00a351c:  bb 37 60 04  srl  %i5, 4, %i5
a00a3520:  82 10 61 d8  or  %g1, 0x1d8, %g1
a00a3524:  80 a7 20 00  cmp  %i4, 0
a00a3528:  02 80 00 0b  be  0xa00a3554
a00a352c:  fa 28 40 18  stb  %i5, [ %g1 + %i0 ]
a00a3530:  c2 0e 60 06  ldub  [ %i1 + 6 ], %g1
a00a3534:  c2 2a c0 18  stb  %g1, [ %o3 + %i0 ]
a00a3538:  c2 0e 60 07  ldub  [ %i1 + 7 ], %g1
a00a353c:  83 30 60 04  srl  %g1, 4, %g1
a00a3540:  c2 2a 80 18  stb  %g1, [ %o2 + %i0 ]
a00a3544:  c2 0e 60 07  ldub  [ %i1 + 7 ], %g1
a00a3548:  82 08 60 0f  and  %g1, 0xf, %g1
a00a354c:  10 80 00 09  b  0xa00a3570
a00a3550:  c2 2a 40 18  stb  %g1, [ %o1 + %i0 ]
a00a3554:  c0 2a 40 18  clrb  [ %o1 + %i0 ]
a00a3558:  c0 2a c0 18  clrb  [ %o3 + %i0 ]
a00a355c:  10 80 00 05  b  0xa00a3570
a00a3560:  c0 2a 80 18  clrb  [ %o2 + %i0 ]
a00a3564:  80 a6 00 0f  cmp  %i0, %o7
a00a3568:  0a bf ff c5  bcs  0xa00a347c
a00a356c:  b6 10 00 19  mov  %i1, %i3
a00a3570:  81 c7 e0 08  ret
a00a3574:  81 e8 00 00  restore
