# leon2m FUN_a00c3380 0xa00c3380-0xa00c35d0 (592 bytes)
a00c3380:  9d e3 bf 98  save  %sp, -104, %sp
a00c3384:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c3388:  80 a4 20 02  cmp  %l0, 2
a00c338c:  02 80 00 55  be  0xa00c34e0
a00c3390:  80 a4 20 03  cmp  %l0, 3
a00c3394:  02 80 00 70  be  0xa00c3554
a00c3398:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c339c:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c33a0:  94 08 60 ff  and  %g1, 0xff, %o2
a00c33a4:  96 02 bf d0  add  %o2, -48, %o3
a00c33a8:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00c33ac:  80 a3 60 0c  cmp  %o5, 0xc
a00c33b0:  18 80 00 86  bgu  0xa00c35c8
a00c33b4:  b0 10 20 ff  mov  0xff, %i0
a00c33b8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c33bc:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00c33c0:  b0 12 22 90  or  %o0, 0x290, %i0
a00c33c4:  d8 10 63 f8  lduh  [ %g1 + 0x3f8 ], %o4
a00c33c8:  1f 00 00 18  sethi  %hi(0x6000), %o7
a00c33cc:  80 8b c0 0c  btst  %o7, %o4
a00c33d0:  02 80 00 47  be  0xa00c34ec
a00c33d4:  d6 2e 21 7b  stb  %o3, [ %i0 + 0x17b ]
a00c33d8:  80 a4 20 02  cmp  %l0, 2
a00c33dc:  02 80 00 24  be  0xa00c346c
a00c33e0:  80 a4 20 03  cmp  %l0, 3
a00c33e4:  02 80 00 5f  be  0xa00c3560
a00c33e8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c33ec:  94 13 20 78  or  %o4, 0x78, %o2	! 0xa802d078
a00c33f0:  96 10 20 30  mov  0x30, %o3
a00c33f4:  9e 10 20 35  mov  0x35, %o7
a00c33f8:  b0 10 20 36  mov  0x36, %i0
a00c33fc:  9a 10 20 2b  mov  0x2b, %o5
a00c3400:  92 10 20 0d  mov  0xd, %o1
a00c3404:  de 2b 20 78  stb  %o7, [ %o4 + 0x78 ]
a00c3408:  f0 2a a0 01  stb  %i0, [ %o2 + 1 ]
a00c340c:  d6 2a a0 03  stb  %o3, [ %o2 + 3 ]
a00c3410:  da 2a a0 04  stb  %o5, [ %o2 + 4 ]
a00c3414:  d2 2a a0 05  stb  %o1, [ %o2 + 5 ]
a00c3418:  80 a4 20 02  cmp  %l0, 2
a00c341c:  02 80 00 21  be  0xa00c34a0
a00c3420:  d6 2a a0 02  stb  %o3, [ %o2 + 2 ]
a00c3424:  80 a4 20 03  cmp  %l0, 3
a00c3428:  02 80 00 5b  be  0xa00c3594
a00c342c:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00c3430:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c3434:  9a 16 20 d0  or  %i0, 0xd0, %o5	! 0xa802d0d0
a00c3438:  c0 2b 20 9c  clrb  [ %o4 + 0x9c ]
a00c343c:  c0 2e 20 d0  clrb  [ %i0 + 0xd0 ]
a00c3440:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00c3444:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00c3448:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00c344c:  80 a4 20 02  cmp  %l0, 2
a00c3450:  02 80 00 1d  be  0xa00c34c4
a00c3454:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00c3458:  80 a4 20 03  cmp  %l0, 3
a00c345c:  12 80 00 1d  bne  0xa00c34d0
a00c3460:  90 10 00 10  mov  %l0, %o0
a00c3464:  10 80 00 56  b  0xa00c35bc
a00c3468:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c346c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c3470:  a0 12 61 28  or  %o1, 0x128, %l0	! 0xa802d128
a00c3474:  9e 10 20 30  mov  0x30, %o7
a00c3478:  9a 10 20 35  mov  0x35, %o5
a00c347c:  96 10 20 0d  mov  0xd, %o3
a00c3480:  90 10 20 36  mov  0x36, %o0
a00c3484:  82 10 20 2b  mov  0x2b, %g1
a00c3488:  da 2a 61 28  stb  %o5, [ %o1 + 0x128 ]
a00c348c:  d6 2c 20 05  stb  %o3, [ %l0 + 5 ]
a00c3490:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00c3494:  de 2c 20 03  stb  %o7, [ %l0 + 3 ]
a00c3498:  c2 2c 20 04  stb  %g1, [ %l0 + 4 ]
a00c349c:  de 2c 20 02  stb  %o7, [ %l0 + 2 ]
a00c34a0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c34a4:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c34a8:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00c34ac:  c0 2a 20 9a  clrb  [ %o0 + 0x9a ]	! 0xa802b09a
a00c34b0:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c34b4:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c34b8:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c34bc:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c34c0:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c34c4:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c34c8:  94 13 e1 28  or  %o7, 0x128, %o2	! 0xa802d128
a00c34cc:  90 10 20 02  mov  2, %o0
a00c34d0:  40 02 14 c6  call  0xa01487e8
a00c34d4:  92 10 20 06  mov  6, %o1
a00c34d8:  10 80 00 3c  b  0xa00c35c8
a00c34dc:  b0 10 20 00  clr  %i0
a00c34e0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c34e4:  10 bf ff af  b  0xa00c33a0
a00c34e8:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c34ec:  7f ff 36 bb  call  0xa0090fd8
a00c34f0:  01 00 00 00  nop
a00c34f4:  7f ff 36 ae  call  0xa0090fac
a00c34f8:  01 00 00 00  nop
a00c34fc:  d6 0e 21 90  ldub  [ %i0 + 0x190 ], %o3
a00c3500:  80 a2 e0 00  cmp  %o3, 0
a00c3504:  12 bf ff b6  bne  0xa00c33dc
a00c3508:  80 a4 20 02  cmp  %l0, 2
a00c350c:  da 06 20 a8  ld  [ %i0 + 0xa8 ], %o5
a00c3510:  13 00 00 04  sethi  %hi(0x1000), %o1
a00c3514:  80 8b 40 09  btst  %o5, %o1
a00c3518:  12 bf ff b1  bne  0xa00c33dc
a00c351c:  80 a4 20 02  cmp  %l0, 2
a00c3520:  d4 0e 21 a0  ldub  [ %i0 + 0x1a0 ], %o2
a00c3524:  80 a2 a0 00  cmp  %o2, 0
a00c3528:  12 bf ff ad  bne  0xa00c33dc
a00c352c:  80 a4 20 02  cmp  %l0, 2
a00c3530:  d8 06 20 ac  ld  [ %i0 + 0xac ], %o4
a00c3534:  31 00 10 00  sethi  %hi(0x400000), %i0
a00c3538:  80 8b 00 18  btst  %o4, %i0
a00c353c:  32 bf ff a8  bne,a   0xa00c33dc
a00c3540:  80 a4 20 02  cmp  %l0, 2
a00c3544:  7f ff 36 a5  call  0xa0090fd8
a00c3548:  01 00 00 00  nop
a00c354c:  10 bf ff a4  b  0xa00c33dc
a00c3550:  80 a4 20 02  cmp  %l0, 2
a00c3554:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c3558:  10 bf ff 92  b  0xa00c33a0
a00c355c:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c3560:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c3564:  b0 12 21 08  or  %o0, 0x108, %i0	! 0xa802d108
a00c3568:  94 10 20 30  mov  0x30, %o2
a00c356c:  82 10 20 35  mov  0x35, %g1
a00c3570:  9e 10 20 0d  mov  0xd, %o7
a00c3574:  a0 10 20 36  mov  0x36, %l0
a00c3578:  98 10 20 2b  mov  0x2b, %o4
a00c357c:  c2 2a 21 08  stb  %g1, [ %o0 + 0x108 ]
a00c3580:  de 2e 20 05  stb  %o7, [ %i0 + 5 ]
a00c3584:  e0 2e 20 01  stb  %l0, [ %i0 + 1 ]
a00c3588:  d4 2e 20 03  stb  %o2, [ %i0 + 3 ]
a00c358c:  d8 2e 20 04  stb  %o4, [ %i0 + 4 ]
a00c3590:  d4 2e 20 02  stb  %o2, [ %i0 + 2 ]
a00c3594:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c3598:  96 12 60 98  or  %o1, 0x98, %o3	! 0xa802d098
a00c359c:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c35a0:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c35a4:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]
a00c35a8:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00c35ac:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00c35b0:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00c35b4:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00c35b8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c35bc:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c35c0:  10 bf ff c4  b  0xa00c34d0
a00c35c4:  90 10 20 03  mov  3, %o0
a00c35c8:  81 c7 e0 08  ret
a00c35cc:  81 e8 00 00  restore
