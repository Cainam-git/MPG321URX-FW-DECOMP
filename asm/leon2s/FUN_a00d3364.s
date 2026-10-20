# leon2s FUN_a00d3364 0xa00d3364-0xa00d3670 (780 bytes)
a00d3364:  9d e3 bf 90  save  %sp, -112, %sp
a00d3368:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00d336c:  92 10 61 48  or  %g1, 0x148, %o1	! 0xa807d548
a00d3370:  c2 02 60 04  ld  [ %o1 + 4 ], %g1
a00d3374:  80 a0 60 02  cmp  %g1, 2
a00d3378:  12 80 00 65  bne  0xa00d350c
a00d337c:  a2 10 20 00  clr  %l1
a00d3380:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3384:  c2 08 60 31  ldub  [ %g1 + 0x31 ], %g1	! 0xa8078c31
a00d3388:  80 a0 60 01  cmp  %g1, 1
a00d338c:  12 80 00 0e  bne  0xa00d33c4
a00d3390:  11 2a 01 de  sethi  %hi(0xa8077800), %o0
a00d3394:  e0 12 60 1c  lduh  [ %o1 + 0x1c ], %l0
a00d3398:  d0 12 21 dc  lduh  [ %o0 + 0x1dc ], %o0
a00d339c:  80 a4 00 08  cmp  %l0, %o0
a00d33a0:  18 80 00 04  bgu  0xa00d33b0
a00d33a4:  15 2a 01 de  sethi  %hi(0xa8077800), %o2
a00d33a8:  10 80 00 08  b  0xa00d33c8
a00d33ac:  a0 10 00 08  mov  %o0, %l0
a00d33b0:  94 12 a2 08  or  %o2, 0x208, %o2
a00d33b4:  40 3a 7d fe  call  0xa0f72bac
a00d33b8:  92 10 00 10  mov  %l0, %o1
a00d33bc:  10 80 00 06  b  0xa00d33d4
a00d33c0:  80 a4 20 00  cmp  %l0, 0
a00d33c4:  e0 12 21 dc  lduh  [ %o0 + 0x1dc ], %l0
a00d33c8:  7f ff fc a1  call  0xa00d264c
a00d33cc:  01 00 00 00  nop
a00d33d0:  80 a4 20 00  cmp  %l0, 0
a00d33d4:  12 80 00 06  bne  0xa00d33ec
a00d33d8:  80 a4 23 e8  cmp  %l0, 0x3e8
a00d33dc:  9a 10 20 07  mov  7, %o5
a00d33e0:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d33e4:  10 80 00 16  b  0xa00d343c
a00d33e8:  da 28 60 39  stb  %o5, [ %g1 + 0x39 ]	! 0xa8078c39
a00d33ec:  08 80 00 06  bleu  0xa00d3404
a00d33f0:  9a 10 20 03  mov  3, %o5
a00d33f4:  80 a4 25 dc  cmp  %l0, 0x5dc
a00d33f8:  18 80 00 06  bgu  0xa00d3410
a00d33fc:  80 a4 27 d0  cmp  %l0, 0x7d0
a00d3400:  9a 10 20 04  mov  4, %o5
a00d3404:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3408:  10 80 00 09  b  0xa00d342c
a00d340c:  da 28 60 39  stb  %o5, [ %g1 + 0x39 ]	! 0xa8078c39
a00d3410:  08 bf ff fd  bleu  0xa00d3404
a00d3414:  9a 10 20 05  mov  5, %o5
a00d3418:  80 a4 2f a0  cmp  %l0, 0xfa0
a00d341c:  18 80 00 06  bgu  0xa00d3434
a00d3420:  1b 2a 01 e3  sethi  %hi(0xa8078c00), %o5
a00d3424:  82 10 20 06  mov  6, %g1
a00d3428:  c2 2b 60 39  stb  %g1, [ %o5 + 0x39 ]
a00d342c:  10 80 00 05  b  0xa00d3440
a00d3430:  a2 10 20 02  mov  2, %l1
a00d3434:  82 10 20 07  mov  7, %g1
a00d3438:  c2 2b 60 39  stb  %g1, [ %o5 + 0x39 ]
a00d343c:  a2 10 20 00  clr  %l1
a00d3440:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00d3444:  e0 30 61 44  sth  %l0, [ %g1 + 0x144 ]	! 0xa807d544
a00d3448:  80 a4 20 00  cmp  %l0, 0
a00d344c:  02 80 00 08  be  0xa00d346c
a00d3450:  9a 10 20 01  mov  1, %o5
a00d3454:  03 00 00 09  sethi  %hi(0x2400), %g1
a00d3458:  82 10 63 10  or  %g1, 0x310, %g1	! 0x2710
a00d345c:  80 a4 00 01  cmp  %l0, %g1
a00d3460:  08 80 00 03  bleu  0xa00d346c
a00d3464:  9a 10 00 10  mov  %l0, %o5
a00d3468:  9a 10 00 01  mov  %g1, %o5
a00d346c:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3470:  c2 08 60 39  ldub  [ %g1 + 0x39 ], %g1	! 0xa8078c39
a00d3474:  80 a0 60 03  cmp  %g1, 3
a00d3478:  12 80 00 04  bne  0xa00d3488
a00d347c:  80 a0 60 04  cmp  %g1, 4
a00d3480:  10 80 00 09  b  0xa00d34a4
a00d3484:  03 00 00 fa  sethi  %hi(0x3e800), %g1
a00d3488:  12 80 00 04  bne  0xa00d3498
a00d348c:  80 a0 60 05  cmp  %g1, 5
a00d3490:  10 80 00 05  b  0xa00d34a4
a00d3494:  03 00 01 77  sethi  %hi(0x5dc00), %g1
a00d3498:  12 80 00 0b  bne  0xa00d34c4
a00d349c:  80 a0 60 06  cmp  %g1, 6
a00d34a0:  03 00 01 f4  sethi  %hi(0x7d000), %g1
a00d34a4:  81 80 00 00  mov  %g0, %y
a00d34a8:  01 00 00 00  nop
a00d34ac:  01 00 00 00  nop
a00d34b0:  01 00 00 00  nop
a00d34b4:  82 70 40 0d  udiv  %g1, %o5, %g1
a00d34b8:  1b 2a 01 e0  sethi  %hi(0xa8078000), %o5
a00d34bc:  10 80 00 0e  b  0xa00d34f4
a00d34c0:  c2 33 63 dc  sth  %g1, [ %o5 + 0x3dc ]	! 0xa80783dc
a00d34c4:  12 80 00 04  bne  0xa00d34d4
a00d34c8:  19 2a 01 e0  sethi  %hi(0xa8078000), %o4
a00d34cc:  10 80 00 03  b  0xa00d34d8
a00d34d0:  03 00 03 e8  sethi  %hi(0xfa000), %g1
a00d34d4:  03 00 09 c4  sethi  %hi(0x271000), %g1
a00d34d8:  81 80 00 00  mov  %g0, %y
a00d34dc:  01 00 00 00  nop
a00d34e0:  01 00 00 00  nop
a00d34e4:  01 00 00 00  nop
a00d34e8:  82 70 40 0d  udiv  %g1, %o5, %g1
a00d34ec:  c2 33 23 dc  sth  %g1, [ %o4 + 0x3dc ]
a00d34f0:  1b 2a 01 e0  sethi  %hi(0xa8078000), %o5
a00d34f4:  c2 13 63 dc  lduh  [ %o5 + 0x3dc ], %g1	! 0xa80783dc
a00d34f8:  80 a0 6f ff  cmp  %g1, 0xfff
a00d34fc:  38 80 00 02  bgu,a   0xa00d3504
a00d3500:  82 10 2f ff  mov  0xfff, %g1
a00d3504:  10 80 00 0c  b  0xa00d3534
a00d3508:  c2 33 63 dc  sth  %g1, [ %o5 + 0x3dc ]
a00d350c:  80 a0 60 03  cmp  %g1, 3
a00d3510:  12 80 00 09  bne  0xa00d3534
a00d3514:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3518:  c2 08 60 30  ldub  [ %g1 + 0x30 ], %g1	! 0xa8078c30
a00d351c:  80 88 60 01  btst  1, %g1
a00d3520:  02 80 00 05  be  0xa00d3534
a00d3524:  01 00 00 00  nop
a00d3528:  7f ff ff 34  call  0xa00d31f8
a00d352c:  b0 10 20 01  mov  1, %i0	! 0x1
a00d3530:  30 80 00 4d  b,a   0xa00d3664
a00d3534:  40 3a 7e 82  call  0xa0f72f3c
a00d3538:  90 10 20 01  mov  1, %o0
a00d353c:  80 8a 20 ff  btst  0xff, %o0
a00d3540:  02 80 00 49  be  0xa00d3664
a00d3544:  b0 10 20 00  clr  %i0
a00d3548:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d354c:  7f ff fe 75  call  0xa00d2f20
a00d3550:  d0 08 60 39  ldub  [ %g1 + 0x39 ], %o0	! 0xa8078c39
a00d3554:  40 3a 7d 90  call  0xa0f72b94
a00d3558:  01 00 00 00  nop
a00d355c:  40 3a 7e 78  call  0xa0f72f3c
a00d3560:  90 10 20 00  clr  %o0	! 0x0
a00d3564:  80 8a 20 ff  btst  0xff, %o0
a00d3568:  02 80 00 3f  be  0xa00d3664
a00d356c:  98 10 20 00  clr  %o4
a00d3570:  92 10 20 00  clr  %o1
a00d3574:  94 10 20 00  clr  %o2
a00d3578:  96 10 20 00  clr  %o3
a00d357c:  7f ff fe e6  call  0xa00d3114
a00d3580:  90 10 20 00  clr  %o0
a00d3584:  40 3a 7d 84  call  0xa0f72b94
a00d3588:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a00d358c:  03 2a 01 e0  sethi  %hi(0xa8078000), %g1
a00d3590:  7f ff fb 7a  call  0xa00d2378
a00d3594:  d0 10 63 dc  lduh  [ %g1 + 0x3dc ], %o0	! 0xa80783dc
a00d3598:  40 3a 77 e4  call  0xa0f71528
a00d359c:  90 14 23 6c  or  %l0, 0x36c, %o0
a00d35a0:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d35a4:  94 10 20 1e  mov  0x1e, %o2
a00d35a8:  96 10 20 00  clr  %o3
a00d35ac:  90 07 bf f4  add  %fp, -12, %o0
a00d35b0:  40 3a 77 c2  call  0xa0f714b8
a00d35b4:  92 10 20 1f  mov  0x1f, %o1
a00d35b8:  90 14 23 6c  or  %l0, 0x36c, %o0
a00d35bc:  40 3a 77 de  call  0xa0f71534
a00d35c0:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d35c4:  94 10 20 1e  mov  0x1e, %o2
a00d35c8:  96 10 20 03  mov  3, %o3
a00d35cc:  90 07 bf f4  add  %fp, -12, %o0
a00d35d0:  40 3a 77 ba  call  0xa0f714b8
a00d35d4:  92 10 20 1f  mov  0x1f, %o1
a00d35d8:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d35dc:  40 3a 77 d6  call  0xa0f71534
a00d35e0:  90 14 23 6c  or  %l0, 0x36c, %o0
a00d35e4:  40 3a 77 d1  call  0xa0f71528
a00d35e8:  90 14 23 dc  or  %l0, 0x3dc, %o0
a00d35ec:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d35f0:  96 0c 60 02  and  %l1, 2, %o3
a00d35f4:  94 10 20 18  mov  0x18, %o2
a00d35f8:  90 07 bf f4  add  %fp, -12, %o0
a00d35fc:  40 3a 77 af  call  0xa0f714b8
a00d3600:  92 10 20 19  mov  0x19, %o1
a00d3604:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d3608:  40 3a 77 cb  call  0xa0f71534
a00d360c:  90 14 23 dc  or  %l0, 0x3dc, %o0
a00d3610:  40 3a 77 c6  call  0xa0f71528
a00d3614:  90 14 23 dc  or  %l0, 0x3dc, %o0
a00d3618:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d361c:  94 10 20 1e  mov  0x1e, %o2
a00d3620:  96 10 20 00  clr  %o3
a00d3624:  90 07 bf f4  add  %fp, -12, %o0
a00d3628:  40 3a 77 a4  call  0xa0f714b8
a00d362c:  92 10 20 1f  mov  0x1f, %o1
a00d3630:  90 14 23 dc  or  %l0, 0x3dc, %o0
a00d3634:  40 3a 77 c0  call  0xa0f71534
a00d3638:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d363c:  94 10 20 1e  mov  0x1e, %o2
a00d3640:  96 10 20 03  mov  3, %o3
a00d3644:  90 07 bf f4  add  %fp, -12, %o0
a00d3648:  40 3a 77 9c  call  0xa0f714b8
a00d364c:  92 10 20 1f  mov  0x1f, %o1
a00d3650:  90 14 23 dc  or  %l0, 0x3dc, %o0
a00d3654:  40 3a 77 b8  call  0xa0f71534
a00d3658:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d365c:  7f ff fd cc  call  0xa00d2d8c
a00d3660:  b0 10 20 01  mov  1, %i0
a00d3664:  01 00 00 00  nop
a00d3668:  81 c7 e0 08  ret
a00d366c:  81 e8 00 00  restore
