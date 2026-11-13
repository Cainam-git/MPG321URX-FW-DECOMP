# leon2s FUN_a00c32f4 0xa00c32f4-0xa00c3ab0 (416 bytes)
a00c32f4:  9d e3 bf 98  save  %sp, -104, %sp
a00c32f8:  ac 10 20 00  clr  %l6
a00c32fc:  aa 10 20 00  clr  %l5
a00c3300:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00c3304:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c3308:  82 10 61 c8  or  %g1, 0x1c8, %g1	! 0xa807d5c8
a00c330c:  9b 2c 20 04  sll  %l0, 4, %o5
a00c3310:  a4 03 40 01  add  %o5, %g1, %l2
a00c3314:  c2 0c a0 04  ldub  [ %l2 + 4 ], %g1
a00c3318:  80 88 60 01  btst  1, %g1
a00c331c:  02 80 00 04  be  0xa00c332c
a00c3320:  80 88 60 02  btst  2, %g1
a00c3324:  10 80 00 08  b  0xa00c3344
a00c3328:  ac 10 20 00  clr  %l6
a00c332c:  02 80 00 04  be  0xa00c333c
a00c3330:  80 88 60 04  btst  4, %g1
a00c3334:  10 80 00 04  b  0xa00c3344
a00c3338:  ac 10 20 01  mov  1, %l6
a00c333c:  32 80 00 02  bne,a   0xa00c3344
a00c3340:  ac 10 20 02  mov  2, %l6
a00c3344:  1b 01 c0 00  sethi  %hi(0x7000000), %o5
a00c3348:  c2 04 80 00  ld  [ %l2 ], %g1
a00c334c:  82 08 40 0d  and  %g1, %o5, %g1
a00c3350:  1b 01 40 00  sethi  %hi(0x5000000), %o5
a00c3354:  80 a0 40 0d  cmp  %g1, %o5
a00c3358:  12 80 01 d4  bne  0xa00c3aa8
a00c335c:  90 10 00 10  mov  %l0, %o0
a00c3360:  40 3b cc 87  call  0xa0fb657c
a00c3364:  92 10 23 19  mov  0x319, %o1
a00c3368:  80 8a 20 10  btst  0x10, %o0
a00c336c:  02 80 00 1a  be  0xa00c33d4
a00c3370:  90 10 00 10  mov  %l0, %o0
a00c3374:  40 3b cc 82  call  0xa0fb657c
a00c3378:  92 10 23 1f  mov  0x31f, %o1
a00c337c:  80 8a 20 80  btst  0x80, %o0
a00c3380:  02 80 00 07  be  0xa00c339c
a00c3384:  90 10 00 10  mov  %l0, %o0
a00c3388:  92 10 23 1f  mov  0x31f, %o1
a00c338c:  94 10 20 80  mov  0x80, %o2
a00c3390:  40 3b cd 0a  call  0xa0fb67b8
a00c3394:  96 10 20 00  clr  %o3
a00c3398:  90 10 00 10  mov  %l0, %o0
a00c339c:  40 3b cc 78  call  0xa0fb657c
a00c33a0:  92 10 20 71  mov  0x71, %o1
a00c33a4:  80 8a 20 02  btst  2, %o0
a00c33a8:  02 80 00 07  be  0xa00c33c4
a00c33ac:  90 10 00 10  mov  %l0, %o0
a00c33b0:  92 10 23 05  mov  0x305, %o1
a00c33b4:  94 10 20 04  mov  4, %o2
a00c33b8:  40 3b cd 00  call  0xa0fb67b8
a00c33bc:  96 10 20 01  mov  1, %o3
a00c33c0:  90 10 00 10  mov  %l0, %o0
a00c33c4:  92 10 23 19  mov  0x319, %o1
a00c33c8:  40 3b cc 7f  call  0xa0fb65c4
a00c33cc:  94 10 20 10  mov  0x10, %o2
a00c33d0:  90 10 00 10  mov  %l0, %o0
a00c33d4:  40 3b cc 6a  call  0xa0fb657c
a00c33d8:  92 10 23 19  mov  0x319, %o1
a00c33dc:  80 8a 20 02  btst  2, %o0
a00c33e0:  02 80 00 10  be  0xa00c3420
a00c33e4:  90 10 00 10  mov  %l0, %o0
a00c33e8:  40 3b cc 65  call  0xa0fb657c
a00c33ec:  92 10 23 1f  mov  0x31f, %o1
a00c33f0:  80 8a 20 80  btst  0x80, %o0
a00c33f4:  12 80 00 06  bne  0xa00c340c
a00c33f8:  90 10 00 10  mov  %l0, %o0
a00c33fc:  92 10 23 1f  mov  0x31f, %o1
a00c3400:  94 10 20 80  mov  0x80, %o2
a00c3404:  40 3b cc ed  call  0xa0fb67b8
a00c3408:  96 10 20 01  mov  1, %o3
a00c340c:  90 10 00 10  mov  %l0, %o0
a00c3410:  92 10 23 19  mov  0x319, %o1
a00c3414:  40 3b cc 6c  call  0xa0fb65c4
a00c3418:  94 10 20 02  mov  2, %o2
a00c341c:  90 10 00 10  mov  %l0, %o0
a00c3420:  40 3b cc 57  call  0xa0fb657c
a00c3424:  92 10 23 18  mov  0x318, %o1
a00c3428:  80 8a 20 01  btst  1, %o0
a00c342c:  22 80 00 09  be,a   0xa00c3450
a00c3430:  c2 0c a0 0d  ldub  [ %l2 + 0xd ], %g1
a00c3434:  c0 2c a0 0d  clrb  [ %l2 + 0xd ]
a00c3438:  c0 2c a0 0c  clrb  [ %l2 + 0xc ]
a00c343c:  90 10 00 10  mov  %l0, %o0
a00c3440:  92 10 23 05  mov  0x305, %o1
a00c3444:  40 3b cc 60  call  0xa0fb65c4
a00c3448:  94 10 20 03  mov  3, %o2
a00c344c:  c2 0c a0 0d  ldub  [ %l2 + 0xd ], %g1
a00c3450:  80 a0 60 0d  cmp  %g1, 0xd
a00c3454:  18 80 01 8e  bgu  0xa00c3a8c
a00c3458:  1b 27 c6 cc  sethi  %hi(0x9f1b3000), %o5
a00c345c:  83 28 60 02  sll  %g1, 2, %g1
a00c3460:  9a 13 62 bc  or  %o5, 0x2bc, %o5
a00c3464:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00c3468:  81 c0 40 00  jmp  %g1
a00c346c:  01 00 00 00  nop
a00c3470:  90 10 00 10  mov  %l0, %o0
a00c3474:  40 3b cc 42  call  0xa0fb657c
a00c3478:  92 10 23 18  mov  0x318, %o1
a00c347c:  80 8a 20 01  btst  1, %o0
a00c3480:  02 80 01 83  be  0xa00c3a8c
a00c3484:  29 2a 01 e1  sethi  %hi(0xa8078400), %l4
a00c3488:  7f ff fb 71  call  0xa00c224c
a00c348c:  90 15 22 20  or  %l4, 0x220, %o0	! 0xa8078620
a00c3490:  90 10 00 10  mov  %l0, %o0
a00c3494:  92 10 23 10  mov  0x310, %o1
a00c3498:  40 3b cc 4b  call  0xa0fb65c4
a00c349c:  94 10 20 2d  mov  0x2d, %o2
a00c34a0:  a6 10 20 00  clr  %l3
a00c34a4:  a2 10 20 00  clr  %l1
a00c34a8:  83 2c 60 10  sll  %l1, 0x10, %g1
a00c34ac:  83 30 60 10  srl  %g1, 0x10, %g1
a00c34b0:  9a 15 22 20  or  %l4, 0x220, %o5
a00c34b4:  d4 0b 40 01  ldub  [ %o5 + %g1 ], %o2
a00c34b8:  90 10 00 10  mov  %l0, %o0
a00c34bc:  40 3b cc 42  call  0xa0fb65c4
a00c34c0:  92 10 23 12  mov  0x312, %o1
a00c34c4:  9a 04 60 01  add  %l1, 1, %o5
a00c34c8:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c34cc:  83 30 60 10  srl  %g1, 0x10, %g1
a00c34d0:  80 a0 60 07  cmp  %g1, 7
a00c34d4:  08 bf ff f5  bleu  0xa00c34a8
a00c34d8:  a2 10 00 0d  mov  %o5, %l1
a00c34dc:  90 10 00 10  mov  %l0, %o0
a00c34e0:  92 10 23 03  mov  0x303, %o1
a00c34e4:  40 3b cc 38  call  0xa0fb65c4
a00c34e8:  94 10 20 00  clr  %o2
a00c34ec:  90 10 00 10  mov  %l0, %o0
a00c34f0:  92 10 23 04  mov  0x304, %o1
a00c34f4:  40 3b cc 34  call  0xa0fb65c4
a00c34f8:  94 10 20 00  clr  %o2
a00c34fc:  90 10 00 10  mov  %l0, %o0
a00c3500:  92 10 23 19  mov  0x319, %o1
a00c3504:  40 3b cc 30  call  0xa0fb65c4
a00c3508:  94 10 20 60  mov  0x60, %o2
a00c350c:  10 80 00 03  b  0xa00c3518
a00c3510:  90 10 00 10  mov  %l0, %o0
a00c3514:  90 10 00 10  mov  %l0, %o0
a00c3518:  40 3b cc 19  call  0xa0fb657c
a00c351c:  92 10 23 19  mov  0x319, %o1
a00c3520:  80 8a 20 40  btst  0x40, %o0
a00c3524:  12 80 00 06  bne  0xa00c353c
a00c3528:  83 2c e0 10  sll  %l3, 0x10, %g1
a00c352c:  83 30 60 10  srl  %g1, 0x10, %g1
a00c3530:  80 a0 6b b7  cmp  %g1, 0xbb7
a00c3534:  28 bf ff f8  bleu,a   0xa00c3514
a00c3538:  a6 04 e0 01  inc  %l3
a00c353c:  90 10 00 10  mov  %l0, %o0
a00c3540:  92 10 23 1f  mov  0x31f, %o1
a00c3544:  94 10 20 80  mov  0x80, %o2
a00c3548:  40 3b cc 9c  call  0xa0fb67b8
a00c354c:  96 10 20 01  mov  1, %o3
a00c3550:  90 10 00 10  mov  %l0, %o0
a00c3554:  92 10 23 08  mov  0x308, %o1
a00c3558:  94 10 20 02  mov  2, %o2
a00c355c:  40 3b cc 97  call  0xa0fb67b8
a00c3560:  96 10 20 01  mov  1, %o3
a00c3564:  90 10 00 10  mov  %l0, %o0
a00c3568:  92 10 23 18  mov  0x318, %o1
a00c356c:  40 3b cc 16  call  0xa0fb65c4
a00c3570:  94 10 20 ff  mov  0xff, %o2
a00c3574:  da 0c a0 04  ldub  [ %l2 + 4 ], %o5
a00c3578:  82 10 20 02  mov  2, %g1
a00c357c:  80 a3 60 00  cmp  %o5, 0
a00c3580:  02 80 00 17  be  0xa00c35dc
a00c3584:  c2 2c a0 0d  stb  %g1, [ %l2 + 0xd ]
a00c3588:  a0 0d a0 ff  and  %l6, 0xff, %l0
a00c358c:  80 a4 20 02  cmp  %l0, 2
a00c3590:  02 80 00 0e  be  0xa00c35c8
a00c3594:  90 10 00 10  mov  %l0, %o0
a00c3598:  92 10 20 04  mov  4, %o1
a00c359c:  94 10 20 10  mov  0x10, %o2
a00c35a0:  40 00 10 48  call  0xa00c76c0
a00c35a4:  96 10 20 00  clr  %o3
a00c35a8:  90 10 00 10  mov  %l0, %o0
a00c35ac:  92 10 20 00  clr  %o1
a00c35b0:  94 10 20 0f  mov  0xf, %o2
a00c35b4:  96 10 20 01  mov  1, %o3
a00c35b8:  40 3b d2 c5  call  0xa0fb80cc
a00c35bc:  98 10 20 00  clr  %o4
a00c35c0:  10 80 00 08  b  0xa00c35e0
a00c35c4:  da 04 80 00  ld  [ %l2 ], %o5
a00c35c8:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a00c35cc:  9a 13 61 00  or  %o5, 0x100, %o5	! 0xcf018d00
a00c35d0:  c2 03 40 00  ld  [ %o5 ], %g1
a00c35d4:  82 08 7f fd  and  %g1, -3, %g1
a00c35d8:  c2 23 40 00  st  %g1, [ %o5 ]
a00c35dc:  da 04 80 00  ld  [ %l2 ], %o5
a00c35e0:  03 00 20 00  sethi  %hi(0x800000), %g1
a00c35e4:  82 2b 40 01  andn  %o5, %g1, %g1
a00c35e8:  10 80 01 29  b  0xa00c3a8c
a00c35ec:  c2 24 80 00  st  %g1, [ %l2 ]
a00c35f0:  90 10 00 10  mov  %l0, %o0
a00c35f4:  40 3b cb e2  call  0xa0fb657c
a00c35f8:  92 10 23 18  mov  0x318, %o1
a00c35fc:  80 8a 20 02  btst  2, %o0
a00c3600:  02 80 00 0d  be  0xa00c3634
a00c3604:  90 10 00 10  mov  %l0, %o0
a00c3608:  92 10 23 18  mov  0x318, %o1
a00c360c:  40 3b cb ee  call  0xa0fb65c4
a00c3610:  94 10 20 02  mov  2, %o2
a00c3614:  c2 04 80 00  ld  [ %l2 ], %g1
a00c3618:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a00c361c:  9a 28 40 0d  andn  %g1, %o5, %o5
a00c3620:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00c3624:  82 2b 40 01  andn  %o5, %g1, %g1
a00c3628:  c2 24 80 00  st  %g1, [ %l2 ]
a00c362c:  10 80 00 b2  b  0xa00c38f4
a00c3630:  82 10 20 03  mov  3, %g1
a00c3634:  40 3b cb d2  call  0xa0fb657c
a00c3638:  92 10 23 18  mov  0x318, %o1
a00c363c:  80 8a 20 04  btst  4, %o0
a00c3640:  02 80 01 13  be  0xa00c3a8c
a00c3644:  90 10 00 10  mov  %l0, %o0
a00c3648:  92 10 23 18  mov  0x318, %o1
a00c364c:  40 3b cb de  call  0xa0fb65c4
a00c3650:  94 10 20 04  mov  4, %o2
a00c3654:  10 80 00 a8  b  0xa00c38f4
a00c3658:  82 10 20 04  mov  4, %g1
a00c365c:  c2 04 80 00  ld  [ %l2 ], %g1
a00c3660:  80 a0 60 00  cmp  %g1, 0
a00c3664:  06 80 00 17  bl  0xa00c36c0
a00c3668:  1b 30 00 00  sethi  %hi(0xc0000000), %o5
a00c366c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c3670:  c2 08 61 c6  ldub  [ %g1 + 0x1c6 ], %g1	! 0xa807d5c6
a00c3674:  80 a0 60 ff  cmp  %g1, 0xff
a00c3678:  02 80 00 04  be  0xa00c3688
a00c367c:  80 a0 40 10  cmp  %g1, %l0
a00c3680:  32 80 00 0b  bne,a   0xa00c36ac
a00c3684:  da 04 80 00  ld  [ %l2 ], %o5
a00c3688:  7f ff fc 34  call  0xa00c2758
a00c368c:  90 0d 60 ff  and  %l5, 0xff, %o0
a00c3690:  c2 04 80 00  ld  [ %l2 ], %g1
a00c3694:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a00c3698:  9a 28 40 0d  andn  %g1, %o5, %o5
a00c369c:  91 2a 20 1f  sll  %o0, 0x1f, %o0
a00c36a0:  9a 13 40 08  or  %o5, %o0, %o5
a00c36a4:  da 24 80 00  st  %o5, [ %l2 ]
a00c36a8:  da 04 80 00  ld  [ %l2 ], %o5
a00c36ac:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00c36b0:  82 2b 40 01  andn  %o5, %g1, %g1
a00c36b4:  c2 24 80 00  st  %g1, [ %l2 ]
a00c36b8:  1b 30 00 00  sethi  %hi(0xc0000000), %o5
a00c36bc:  c2 04 80 00  ld  [ %l2 ], %g1
a00c36c0:  82 08 40 0d  and  %g1, %o5, %g1
a00c36c4:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a00c36c8:  80 a0 40 0d  cmp  %g1, %o5
a00c36cc:  32 80 00 17  bne,a   0xa00c3728
a00c36d0:  da 04 80 00  ld  [ %l2 ], %o5
a00c36d4:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00c36d8:  90 10 00 10  mov  %l0, %o0
a00c36dc:  40 3b cb a8  call  0xa0fb657c
a00c36e0:  92 10 23 18  mov  0x318, %o1
a00c36e4:  80 8a 20 08  btst  8, %o0
a00c36e8:  22 80 00 10  be,a   0xa00c3728
a00c36ec:  da 04 80 00  ld  [ %l2 ], %o5
a00c36f0:  90 10 00 10  mov  %l0, %o0
a00c36f4:  92 10 23 18  mov  0x318, %o1
a00c36f8:  40 3b cb b3  call  0xa0fb65c4
a00c36fc:  94 10 20 08  mov  8, %o2
a00c3700:  90 10 00 10  mov  %l0, %o0
a00c3704:  92 10 23 08  mov  0x308, %o1
a00c3708:  94 10 20 04  mov  4, %o2
a00c370c:  40 3b cc 2b  call  0xa0fb67b8
a00c3710:  96 10 20 01  mov  1, %o3
a00c3714:  c2 04 80 00  ld  [ %l2 ], %g1
a00c3718:  1b 10 00 00  sethi  %hi(0x40000000), %o5
a00c371c:  82 10 40 0d  or  %g1, %o5, %g1
a00c3720:  c2 24 80 00  st  %g1, [ %l2 ]
a00c3724:  da 04 80 00  ld  [ %l2 ], %o5
a00c3728:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00c372c:  80 8b 40 01  btst  %o5, %g1
a00c3730:  02 80 00 d7  be  0xa00c3a8c
a00c3734:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00c3738:  90 10 00 10  mov  %l0, %o0
a00c373c:  40 3b cb 90  call  0xa0fb657c
a00c3740:  92 10 23 0a  mov  0x30a, %o1
a00c3744:  80 8a 20 70  btst  0x70, %o0
a00c3748:  12 80 00 d1  bne  0xa00c3a8c
a00c374c:  90 10 00 10  mov  %l0, %o0
a00c3750:  92 10 23 18  mov  0x318, %o1
a00c3754:  40 3b cb 9c  call  0xa0fb65c4
a00c3758:  94 10 20 10  mov  0x10, %o2
a00c375c:  90 10 00 10  mov  %l0, %o0
a00c3760:  92 10 23 08  mov  0x308, %o1
a00c3764:  10 80 00 0e  b  0xa00c379c
a00c3768:  94 10 20 08  mov  8, %o2
a00c376c:  90 10 00 10  mov  %l0, %o0
a00c3770:  40 3b cb 83  call  0xa0fb657c
a00c3774:  92 10 23 18  mov  0x318, %o1
a00c3778:  80 8a 20 08  btst  8, %o0
a00c377c:  02 80 00 c4  be  0xa00c3a8c
a00c3780:  90 10 00 10  mov  %l0, %o0
a00c3784:  92 10 23 18  mov  0x318, %o1
a00c3788:  40 3b cb 8f  call  0xa0fb65c4
a00c378c:  94 10 20 08  mov  8, %o2
a00c3790:  90 10 00 10  mov  %l0, %o0
a00c3794:  92 10 23 08  mov  0x308, %o1
a00c3798:  94 10 20 04  mov  4, %o2
a00c379c:  40 3b cc 07  call  0xa0fb67b8
a00c37a0:  96 10 20 01  mov  1, %o3
a00c37a4:  10 80 00 54  b  0xa00c38f4
a00c37a8:  82 10 20 05  mov  5, %g1
a00c37ac:  90 10 00 10  mov  %l0, %o0
a00c37b0:  40 3b cb 73  call  0xa0fb657c
a00c37b4:  92 10 23 18  mov  0x318, %o1
a00c37b8:  80 8a 20 80  btst  0x80, %o0
a00c37bc:  02 80 00 b4  be  0xa00c3a8c
a00c37c0:  90 10 00 10  mov  %l0, %o0
a00c37c4:  92 10 23 18  mov  0x318, %o1
a00c37c8:  40 3b cb 7f  call  0xa0fb65c4
a00c37cc:  94 10 20 80  mov  0x80, %o2
a00c37d0:  10 80 00 49  b  0xa00c38f4
a00c37d4:  82 10 20 08  mov  8, %g1
a00c37d8:  90 10 00 10  mov  %l0, %o0
a00c37dc:  40 3b cb 68  call  0xa0fb657c
a00c37e0:  92 10 23 19  mov  0x319, %o1
a00c37e4:  80 8a 20 01  btst  1, %o0
a00c37e8:  02 80 00 a9  be  0xa00c3a8c
a00c37ec:  90 10 00 10  mov  %l0, %o0
a00c37f0:  92 10 23 19  mov  0x319, %o1
a00c37f4:  40 3b cb 74  call  0xa0fb65c4
a00c37f8:  94 10 20 01  mov  1, %o2
a00c37fc:  c2 04 80 00  ld  [ %l2 ], %g1
a00c3800:  1b 00 07 c0  sethi  %hi(0x1f0000), %o5
a00c3804:  9a 28 40 0d  andn  %g1, %o5, %o5
a00c3808:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c380c:  d8 08 60 58  ldub  [ %g1 + 0x58 ], %o4	! 0xa8078c58
a00c3810:  03 00 00 40  sethi  %hi(0x10000), %g1
a00c3814:  9a 13 40 01  or  %o5, %g1, %o5
a00c3818:  99 3b 00 10  sra  %o4, %l0, %o4
a00c381c:  80 8b 20 01  btst  1, %o4
a00c3820:  02 80 00 05  be  0xa00c3834
a00c3824:  da 24 80 00  st  %o5, [ %l2 ]
a00c3828:  82 10 20 09  mov  9, %g1
a00c382c:  10 80 00 96  b  0xa00c3a84
a00c3830:  c2 2c a0 0d  stb  %g1, [ %l2 + 0xd ]
a00c3834:  82 10 20 0d  mov  0xd, %g1
a00c3838:  11 27 c6 dd  sethi  %hi(0x9f1b7400), %o0
a00c383c:  c2 2c a0 0d  stb  %g1, [ %l2 + 0xd ]
a00c3840:  92 10 00 10  mov  %l0, %o1
a00c3844:  40 3a fe 00  call  0xa0f83044
a00c3848:  90 12 21 98  or  %o0, 0x198, %o0
a00c384c:  30 80 00 90  b,a   0xa00c3a8c
a00c3850:  a2 0d a0 ff  and  %l6, 0xff, %l1
a00c3854:  80 a4 60 02  cmp  %l1, 2
a00c3858:  02 80 00 0d  be  0xa00c388c
a00c385c:  90 10 00 11  mov  %l1, %o0
a00c3860:  92 10 20 04  mov  4, %o1
a00c3864:  94 10 20 10  mov  0x10, %o2
a00c3868:  40 00 0f 96  call  0xa00c76c0
a00c386c:  96 10 20 00  clr  %o3
a00c3870:  90 10 00 11  mov  %l1, %o0
a00c3874:  92 10 20 0f  mov  0xf, %o1
a00c3878:  94 10 20 01  mov  1, %o2
a00c387c:  40 00 0f 91  call  0xa00c76c0
a00c3880:  96 10 20 00  clr  %o3
a00c3884:  10 80 00 08  b  0xa00c38a4
a00c3888:  da 04 80 00  ld  [ %l2 ], %o5
a00c388c:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a00c3890:  9a 13 61 00  or  %o5, 0x100, %o5	! 0xcf018d00
a00c3894:  c2 03 40 00  ld  [ %o5 ], %g1
a00c3898:  82 08 7f fd  and  %g1, -3, %g1
a00c389c:  c2 23 40 00  st  %g1, [ %o5 ]
a00c38a0:  da 04 80 00  ld  [ %l2 ], %o5
a00c38a4:  03 00 10 00  sethi  %hi(0x400000), %g1
a00c38a8:  80 8b 40 01  btst  %o5, %g1
a00c38ac:  02 80 00 12  be  0xa00c38f4
a00c38b0:  82 10 20 0a  mov  0xa, %g1
a00c38b4:  90 10 00 10  mov  %l0, %o0
a00c38b8:  92 10 23 08  mov  0x308, %o1
a00c38bc:  94 10 20 20  mov  0x20, %o2
a00c38c0:  40 3b cb be  call  0xa0fb67b8
a00c38c4:  96 10 20 00  clr  %o3
a00c38c8:  90 10 00 10  mov  %l0, %o0
a00c38cc:  92 10 23 08  mov  0x308, %o1
a00c38d0:  94 10 20 20  mov  0x20, %o2
a00c38d4:  40 3b cb b9  call  0xa0fb67b8
a00c38d8:  96 10 20 01  mov  1, %o3
a00c38dc:  90 10 00 10  mov  %l0, %o0
a00c38e0:  92 10 23 08  mov  0x308, %o1
a00c38e4:  94 10 20 20  mov  0x20, %o2
a00c38e8:  40 3b cb b4  call  0xa0fb67b8
a00c38ec:  96 10 20 00  clr  %o3
a00c38f0:  82 10 20 0a  mov  0xa, %g1
a00c38f4:  10 80 00 66  b  0xa00c3a8c
a00c38f8:  c2 2c a0 0d  stb  %g1, [ %l2 + 0xd ]
a00c38fc:  7f ff fd 3a  call  0xa00c2de4
a00c3900:  90 10 00 10  mov  %l0, %o0
a00c3904:  80 8a 20 ff  btst  0xff, %o0
a00c3908:  12 80 00 07  bne  0xa00c3924
a00c390c:  90 10 00 10  mov  %l0, %o0
a00c3910:  40 3b cb 1b  call  0xa0fb657c
a00c3914:  92 10 23 03  mov  0x303, %o1
a00c3918:  80 8a 20 08  btst  8, %o0
a00c391c:  02 80 00 07  be  0xa00c3938
a00c3920:  90 10 00 10  mov  %l0, %o0
a00c3924:  92 10 23 03  mov  0x303, %o1
a00c3928:  94 10 20 08  mov  8, %o2
a00c392c:  40 3b cb a3  call  0xa0fb67b8
a00c3930:  96 10 20 01  mov  1, %o3
a00c3934:  30 80 00 56  b,a   0xa00c3a8c
a00c3938:  40 3b cb 11  call  0xa0fb657c
a00c393c:  92 10 23 1a  mov  0x31a, %o1
a00c3940:  80 8a 20 01  btst  1, %o0
a00c3944:  02 80 00 14  be  0xa00c3994
a00c3948:  90 10 00 10  mov  %l0, %o0
a00c394c:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c3950:  c2 08 60 b0  ldub  [ %g1 + 0xb0 ], %g1	! 0xa8078cb0
a00c3954:  80 a0 60 00  cmp  %g1, 0
a00c3958:  12 80 00 0f  bne  0xa00c3994
a00c395c:  92 10 23 1a  mov  0x31a, %o1
a00c3960:  40 3b cb 19  call  0xa0fb65c4
a00c3964:  94 10 20 01  mov  1, %o2
a00c3968:  90 10 00 10  mov  %l0, %o0
a00c396c:  92 10 23 03  mov  0x303, %o1
a00c3970:  94 10 20 04  mov  4, %o2
a00c3974:  40 3b cb 91  call  0xa0fb67b8
a00c3978:  96 10 20 01  mov  1, %o3
a00c397c:  90 10 00 10  mov  %l0, %o0
a00c3980:  92 10 23 08  mov  0x308, %o1
a00c3984:  94 10 20 40  mov  0x40, %o2
a00c3988:  40 3b cb 8c  call  0xa0fb67b8
a00c398c:  96 10 20 01  mov  1, %o3
a00c3990:  90 10 00 10  mov  %l0, %o0
a00c3994:  40 3b ca fa  call  0xa0fb657c
a00c3998:  92 10 23 1a  mov  0x31a, %o1
a00c399c:  80 8a 20 02  btst  2, %o0
a00c39a0:  02 80 00 0b  be  0xa00c39cc
a00c39a4:  90 10 00 10  mov  %l0, %o0
a00c39a8:  92 10 23 1a  mov  0x31a, %o1
a00c39ac:  40 3b cb 06  call  0xa0fb65c4
a00c39b0:  94 10 20 02  mov  2, %o2
a00c39b4:  90 10 00 10  mov  %l0, %o0
a00c39b8:  92 10 23 03  mov  0x303, %o1
a00c39bc:  94 10 20 04  mov  4, %o2
a00c39c0:  40 3b cb 7e  call  0xa0fb67b8
a00c39c4:  96 10 20 00  clr  %o3
a00c39c8:  90 10 00 10  mov  %l0, %o0
a00c39cc:  40 3b ca ec  call  0xa0fb657c
a00c39d0:  92 10 23 1a  mov  0x31a, %o1
a00c39d4:  80 8a 20 04  btst  4, %o0
a00c39d8:  02 80 00 06  be  0xa00c39f0
a00c39dc:  90 10 00 10  mov  %l0, %o0
a00c39e0:  92 10 23 1a  mov  0x31a, %o1
a00c39e4:  40 3b ca f8  call  0xa0fb65c4
a00c39e8:  94 10 20 04  mov  4, %o2
a00c39ec:  90 10 00 10  mov  %l0, %o0
a00c39f0:  40 3b ca e3  call  0xa0fb657c
a00c39f4:  92 10 23 1a  mov  0x31a, %o1
a00c39f8:  80 8a 20 40  btst  0x40, %o0
a00c39fc:  02 80 00 09  be  0xa00c3a20
a00c3a00:  92 10 23 1a  mov  0x31a, %o1
a00c3a04:  90 10 00 10  mov  %l0, %o0
a00c3a08:  40 3b ca ef  call  0xa0fb65c4
a00c3a0c:  94 10 20 40  mov  0x40, %o2
a00c3a10:  9a 10 20 01  mov  1, %o5
a00c3a14:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c3a18:  da 28 60 b0  stb  %o5, [ %g1 + 0xb0 ]	! 0xa8078cb0
a00c3a1c:  92 10 23 1a  mov  0x31a, %o1
a00c3a20:  40 3b ca d7  call  0xa0fb657c
a00c3a24:  90 10 00 10  mov  %l0, %o0
a00c3a28:  90 10 00 10  mov  %l0, %o0
a00c3a2c:  40 3b ca d4  call  0xa0fb657c
a00c3a30:  92 10 23 1a  mov  0x31a, %o1
a00c3a34:  80 8a 20 20  btst  0x20, %o0
a00c3a38:  02 80 00 0b  be  0xa00c3a64
a00c3a3c:  90 10 00 10  mov  %l0, %o0
a00c3a40:  92 10 23 1a  mov  0x31a, %o1
a00c3a44:  40 3b ca e0  call  0xa0fb65c4
a00c3a48:  94 10 20 38  mov  0x38, %o2
a00c3a4c:  90 10 00 10  mov  %l0, %o0
a00c3a50:  92 10 23 08  mov  0x308, %o1
a00c3a54:  94 10 20 80  mov  0x80, %o2
a00c3a58:  40 3b cb 58  call  0xa0fb67b8
a00c3a5c:  96 10 20 01  mov  1, %o3
a00c3a60:  90 10 00 10  mov  %l0, %o0
a00c3a64:  40 3b ca c6  call  0xa0fb657c
a00c3a68:  92 10 23 19  mov  0x319, %o1
a00c3a6c:  80 8a 20 80  btst  0x80, %o0
a00c3a70:  02 80 00 07  be  0xa00c3a8c
a00c3a74:  90 10 00 10  mov  %l0, %o0
a00c3a78:  92 10 23 19  mov  0x319, %o1
a00c3a7c:  40 3b ca d2  call  0xa0fb65c4
a00c3a80:  94 10 20 80  mov  0x80, %o2
a00c3a84:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c3a88:  c0 28 60 b0  clrb  [ %g1 + 0xb0 ]	! 0xa8078cb0
a00c3a8c:  7f ff fd ae  call  0xa00c3144
a00c3a90:  90 0d 60 ff  and  %l5, 0xff, %o0
a00c3a94:  aa 05 60 01  inc  %l5
a00c3a98:  82 0d 60 ff  and  %l5, 0xff, %g1
a00c3a9c:  80 a0 60 01  cmp  %g1, 1
a00c3aa0:  08 bf fe 19  bleu  0xa00c3304
a00c3aa4:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00c3aa8:  81 c7 e0 08  ret
a00c3aac:  81 e8 00 00  restore
