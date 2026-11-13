# leon2m FUN_a00a31a4 0xa00a31a4-0xa00a3838 (1684 bytes)
a00a31a4:  9d e3 bf 68  save  %sp, -152, %sp
a00a31a8:  2b 2a 00 ab  sethi  %hi(0xa802ac00), %l5
a00a31ac:  f6 2d 63 f4  stb  %i3, [ %l5 + 0x3f4 ]	! 0xa802aff4
a00a31b0:  d0 0f 00 00  ldub  [ %i4 ], %o0
a00a31b4:  82 02 20 01  add  %o0, 1, %g1
a00a31b8:  a8 08 60 ff  and  %g1, 0xff, %l4
a00a31bc:  f0 2f bf f7  stb  %i0, [ %fp + -9 ]
a00a31c0:  f2 37 bf ee  sth  %i1, [ %fp + -18 ]
a00a31c4:  f4 37 bf e6  sth  %i2, [ %fp + -26 ]
a00a31c8:  a4 10 00 1d  mov  %i5, %l2
a00a31cc:  80 a5 20 01  cmp  %l4, 1
a00a31d0:  f6 2f bf df  stb  %i3, [ %fp + -33 ]
a00a31d4:  fa 2f bf de  stb  %i5, [ %fp + -34 ]
a00a31d8:  a2 10 3f f0  mov  -16, %l1
a00a31dc:  a6 10 20 00  clr  %l3
a00a31e0:  08 80 00 2d  bleu  0xa00a3294
a00a31e4:  a0 10 20 01  mov  1, %l0
a00a31e8:  92 10 20 01  mov  1, %o1
a00a31ec:  c2 0a 40 1c  ldub  [ %o1 + %i4 ], %g1
a00a31f0:  80 a0 60 f0  cmp  %g1, 0xf0
a00a31f4:  02 80 00 22  be  0xa00a327c
a00a31f8:  80 a0 60 f2  cmp  %g1, 0xf2
a00a31fc:  02 80 00 81  be  0xa00a3400
a00a3200:  80 a0 60 f1  cmp  %g1, 0xf1
a00a3204:  02 80 00 85  be  0xa00a3418
a00a3208:  80 a0 60 f4  cmp  %g1, 0xf4
a00a320c:  02 80 00 87  be  0xa00a3428
a00a3210:  80 a0 60 f3  cmp  %g1, 0xf3
a00a3214:  02 80 00 89  be  0xa00a3438
a00a3218:  80 a0 60 f5  cmp  %g1, 0xf5
a00a321c:  02 80 00 89  be  0xa00a3440
a00a3220:  80 a0 60 f6  cmp  %g1, 0xf6
a00a3224:  02 80 00 c7  be  0xa00a3540
a00a3228:  80 a0 60 f7  cmp  %g1, 0xf7
a00a322c:  02 80 00 c9  be  0xa00a3550
a00a3230:  80 a0 60 f8  cmp  %g1, 0xf8
a00a3234:  02 80 00 cd  be  0xa00a3568
a00a3238:  80 a0 60 f9  cmp  %g1, 0xf9
a00a323c:  22 80 00 11  be,a   0xa00a3280
a00a3240:  a2 10 3f f9  mov  -7, %l1
a00a3244:  d2 0a 40 1c  ldub  [ %o1 + %i4 ], %o1
a00a3248:  80 a2 60 fa  cmp  %o1, 0xfa
a00a324c:  02 80 00 de  be  0xa00a35c4
a00a3250:  80 a2 60 fb  cmp  %o1, 0xfb
a00a3254:  02 80 00 e4  be  0xa00a35e4
a00a3258:  80 a2 60 fc  cmp  %o1, 0xfc
a00a325c:  02 80 00 e6  be  0xa00a35f4
a00a3260:  80 a2 60 fd  cmp  %o1, 0xfd
a00a3264:  02 80 00 da  be  0xa00a35cc
a00a3268:  80 a2 60 fe  cmp  %o1, 0xfe
a00a326c:  12 80 00 e4  bne  0xa00a35fc
a00a3270:  01 00 00 00  nop
a00a3274:  10 80 00 03  b  0xa00a3280
a00a3278:  a2 10 3f fe  mov  -2, %l1	! 0xfffffffe
a00a327c:  a2 10 3f f0  mov  -16, %l1
a00a3280:  a0 04 20 01  inc  %l0
a00a3284:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a3288:  80 a2 40 14  cmp  %o1, %l4
a00a328c:  2a bf ff d9  bcs,a   0xa00a31f0
a00a3290:  c2 0a 40 1c  ldub  [ %o1 + %i4 ], %g1
a00a3294:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00a3298:  ba 0c a0 ff  and  %l2, 0xff, %i5
a00a329c:  e6 32 a0 88  sth  %l3, [ %o2 + 0x88 ]
a00a32a0:  40 02 8e 45  call  0xa0146bb4
a00a32a4:  90 10 00 1d  mov  %i5, %o0
a00a32a8:  80 8a 20 ff  btst  0xff, %o0
a00a32ac:  12 80 00 69  bne  0xa00a3450
a00a32b0:  01 00 00 00  nop
a00a32b4:  c0 2f bf cf  clrb  [ %fp + -49 ]
a00a32b8:  40 02 8c 1b  call  0xa0146324
a00a32bc:  90 10 00 1d  mov  %i5, %o0
a00a32c0:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00a32c4:  b2 10 00 08  mov  %o0, %i1
a00a32c8:  80 a4 60 00  cmp  %l1, 0
a00a32cc:  02 80 00 0b  be  0xa00a32f8
a00a32d0:  98 10 20 00  clr  %o4
a00a32d4:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00a32d8:  96 13 63 f8  or  %o5, 0x3f8, %o3	! 0xa802aff8
a00a32dc:  9a 10 20 00  clr  %o5
a00a32e0:  ab 2b 60 02  sll  %o5, 2, %l5
a00a32e4:  98 03 20 01  inc  %o4
a00a32e8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00a32ec:  80 a3 40 11  cmp  %o5, %l1
a00a32f0:  0a bf ff fc  bcs  0xa00a32e0
a00a32f4:  c0 22 c0 15  clr  [ %o3 + %l5 ]
a00a32f8:  40 02 8e 3c  call  0xa0146be8
a00a32fc:  90 10 00 1d  mov  %i5, %o0
a00a3300:  80 a5 20 01  cmp  %l4, 1
a00a3304:  ac 10 3f f0  mov  -16, %l6
a00a3308:  a4 10 20 01  mov  1, %l2
a00a330c:  08 80 00 30  bleu  0xa00a33cc
a00a3310:  e6 0f bf cf  ldub  [ %fp + -49 ], %l3
a00a3314:  2f 2a 00 ab  sethi  %hi(0xa802ac00), %l7
a00a3318:  b4 15 e3 f8  or  %l7, 0x3f8, %i2	! 0xa802aff8
a00a331c:  9a 10 20 01  mov  1, %o5
a00a3320:  c2 0b 40 1c  ldub  [ %o5 + %i4 ], %g1
a00a3324:  80 a0 60 f0  cmp  %g1, 0xf0
a00a3328:  02 80 00 23  be  0xa00a33b4
a00a332c:  80 a0 60 f2  cmp  %g1, 0xf2
a00a3330:  02 80 00 36  be  0xa00a3408
a00a3334:  80 a0 60 f1  cmp  %g1, 0xf1
a00a3338:  02 80 00 36  be  0xa00a3410
a00a333c:  80 a0 60 f4  cmp  %g1, 0xf4
a00a3340:  02 80 00 38  be  0xa00a3420
a00a3344:  80 a0 60 f3  cmp  %g1, 0xf3
a00a3348:  02 80 00 3a  be  0xa00a3430
a00a334c:  80 a0 60 f5  cmp  %g1, 0xf5
a00a3350:  02 80 00 3e  be  0xa00a3448
a00a3354:  80 a0 60 f6  cmp  %g1, 0xf6
a00a3358:  02 80 00 7c  be  0xa00a3548
a00a335c:  80 a0 60 f7  cmp  %g1, 0xf7
a00a3360:  02 80 00 7e  be  0xa00a3558
a00a3364:  80 a0 60 f8  cmp  %g1, 0xf8
a00a3368:  02 80 00 7e  be  0xa00a3560
a00a336c:  80 a0 60 f9  cmp  %g1, 0xf9
a00a3370:  22 80 00 12  be,a   0xa00a33b8
a00a3374:  ac 10 3f f9  mov  -7, %l6
a00a3378:  e0 0b 40 1c  ldub  [ %o5 + %i4 ], %l0
a00a337c:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a3380:  80 a2 60 fa  cmp  %o1, 0xfa
a00a3384:  02 80 00 8e  be  0xa00a35bc
a00a3388:  80 a2 60 fb  cmp  %o1, 0xfb
a00a338c:  02 80 00 94  be  0xa00a35dc
a00a3390:  80 a2 60 fc  cmp  %o1, 0xfc
a00a3394:  02 80 00 96  be  0xa00a35ec
a00a3398:  80 a2 60 fd  cmp  %o1, 0xfd
a00a339c:  02 80 00 8e  be  0xa00a35d4
a00a33a0:  80 a2 60 fe  cmp  %o1, 0xfe
a00a33a4:  12 80 00 9b  bne  0xa00a3610
a00a33a8:  b0 0d a0 ff  and  %l6, 0xff, %i0
a00a33ac:  10 80 00 03  b  0xa00a33b8
a00a33b0:  ac 10 3f fe  mov  -2, %l6
a00a33b4:  ac 10 3f f0  mov  -16, %l6
a00a33b8:  a4 04 a0 01  inc  %l2
a00a33bc:  9a 0c a0 ff  and  %l2, 0xff, %o5
a00a33c0:  80 a3 40 14  cmp  %o5, %l4
a00a33c4:  2a bf ff d8  bcs,a   0xa00a3324
a00a33c8:  c2 0b 40 1c  ldub  [ %o5 + %i4 ], %g1
a00a33cc:  80 a4 e0 00  cmp  %l3, 0
a00a33d0:  12 80 00 4d  bne  0xa00a3504
a00a33d4:  ec 17 bf e6  lduh  [ %fp + -26 ], %l6
a00a33d8:  f2 17 bf ee  lduh  [ %fp + -18 ], %i1
a00a33dc:  b9 2d a0 10  sll  %l6, 0x10, %i4
a00a33e0:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00a33e4:  b5 37 20 10  srl  %i4, 0x10, %i2
a00a33e8:  f0 0f bf f7  ldub  [ %fp + -9 ], %i0
a00a33ec:  b3 37 60 10  srl  %i5, 0x10, %i1
a00a33f0:  f6 0f bf df  ldub  [ %fp + -33 ], %i3
a00a33f4:  f8 0f bf de  ldub  [ %fp + -34 ], %i4
a00a33f8:  40 02 8e 07  call  0xa0146c14
a00a33fc:  81 e8 00 00  restore
a00a3400:  10 bf ff a0  b  0xa00a3280
a00a3404:  a2 10 3f f2  mov  -14, %l1
a00a3408:  10 bf ff ec  b  0xa00a33b8
a00a340c:  ac 10 3f f2  mov  -14, %l6
a00a3410:  10 bf ff ea  b  0xa00a33b8
a00a3414:  ac 10 3f f1  mov  -15, %l6
a00a3418:  10 bf ff 9a  b  0xa00a3280
a00a341c:  a2 10 3f f1  mov  -15, %l1
a00a3420:  10 bf ff e6  b  0xa00a33b8
a00a3424:  ac 10 3f f4  mov  -12, %l6
a00a3428:  10 bf ff 96  b  0xa00a3280
a00a342c:  a2 10 3f f4  mov  -12, %l1
a00a3430:  10 bf ff e2  b  0xa00a33b8
a00a3434:  ac 10 3f f3  mov  -13, %l6
a00a3438:  10 bf ff 92  b  0xa00a3280
a00a343c:  a2 10 3f f3  mov  -13, %l1
a00a3440:  10 bf ff 90  b  0xa00a3280
a00a3444:  a2 10 3f f5  mov  -11, %l1
a00a3448:  10 bf ff dc  b  0xa00a33b8
a00a344c:  ac 10 3f f5  mov  -11, %l6
a00a3450:  40 02 8d d9  call  0xa0146bb4
a00a3454:  90 10 00 1d  mov  %i5, %o0
a00a3458:  96 0a 20 ff  and  %o0, 0xff, %o3
a00a345c:  80 a2 e0 01  cmp  %o3, 1
a00a3460:  02 80 00 44  be  0xa00a3570
a00a3464:  01 00 00 00  nop
a00a3468:  40 02 8d d3  call  0xa0146bb4
a00a346c:  90 10 00 1d  mov  %i5, %o0
a00a3470:  b2 0a 20 ff  and  %o0, 0xff, %i1
a00a3474:  80 a6 60 02  cmp  %i1, 2
a00a3478:  12 bf ff 90  bne  0xa00a32b8
a00a347c:  01 00 00 00  nop
a00a3480:  40 02 8e 69  call  0xa0146e24
a00a3484:  e2 0d 63 f4  ldub  [ %l5 + 0x3f4 ], %l1
a00a3488:  98 0a 20 ff  and  %o0, 0xff, %o4
a00a348c:  a0 5c 40 0c  smul  %l1, %o4, %l0
a00a3490:  96 24 00 13  sub  %l0, %l3, %o3
a00a3494:  95 2a e0 10  sll  %o3, 0x10, %o2
a00a3498:  40 02 8e 63  call  0xa0146e24
a00a349c:  b5 32 a0 10  srl  %o2, 0x10, %i2
a00a34a0:  92 0a 20 ff  and  %o0, 0xff, %o1
a00a34a4:  83 3e a0 1f  sra  %i2, 0x1f, %g1
a00a34a8:  81 80 60 00  mov  %g1, %y
a00a34ac:  01 00 00 00  nop
a00a34b0:  01 00 00 00  nop
a00a34b4:  01 00 00 00  nop
a00a34b8:  a6 7e 80 09  sdiv  %i2, %o1, %l3
a00a34bc:  40 02 8e 5a  call  0xa0146e24
a00a34c0:  01 00 00 00  nop
a00a34c4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a34c8:  9b 3e a0 1f  sra  %i2, 0x1f, %o5
a00a34cc:  81 83 60 00  mov  %o5, %y
a00a34d0:  01 00 00 00  nop
a00a34d4:  01 00 00 00  nop
a00a34d8:  01 00 00 00  nop
a00a34dc:  82 7e 80 08  sdiv  %i2, %o0, %g1
a00a34e0:  b6 58 40 08  smul  %g1, %o0, %i3
a00a34e4:  a0 26 80 1b  sub  %i2, %i3, %l0
a00a34e8:  80 8c e0 01  btst  1, %l3
a00a34ec:  12 80 00 b9  bne  0xa00a37d0
a00a34f0:  82 10 00 10  mov  %l0, %g1
a00a34f4:  a4 08 60 ff  and  %g1, 0xff, %l2
a00a34f8:  9f 34 a0 01  srl  %l2, 1, %o7
a00a34fc:  10 bf ff 6f  b  0xa00a32b8
a00a3500:  de 2f bf cf  stb  %o7, [ %fp + -49 ]
a00a3504:  29 2a 00 ab  sethi  %hi(0xa802ac00), %l4
a00a3508:  92 10 00 1d  mov  %i5, %o1
a00a350c:  40 02 8d bd  call  0xa0146c00
a00a3510:  90 15 23 f8  or  %l4, 0x3f8, %o0
a00a3514:  ec 17 bf e6  lduh  [ %fp + -26 ], %l6
a00a3518:  f2 17 bf ee  lduh  [ %fp + -18 ], %i1
a00a351c:  b9 2d a0 10  sll  %l6, 0x10, %i4
a00a3520:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00a3524:  b5 37 20 10  srl  %i4, 0x10, %i2
a00a3528:  f0 0f bf f7  ldub  [ %fp + -9 ], %i0
a00a352c:  b3 37 60 10  srl  %i5, 0x10, %i1
a00a3530:  f6 0f bf df  ldub  [ %fp + -33 ], %i3
a00a3534:  f8 0f bf de  ldub  [ %fp + -34 ], %i4
a00a3538:  40 02 8d b7  call  0xa0146c14
a00a353c:  81 e8 00 00  restore
a00a3540:  10 bf ff 50  b  0xa00a3280
a00a3544:  a2 10 3f f6  mov  -10, %l1
a00a3548:  10 bf ff 9c  b  0xa00a33b8
a00a354c:  ac 10 3f f6  mov  -10, %l6
a00a3550:  10 bf ff 4c  b  0xa00a3280
a00a3554:  a2 10 3f f7  mov  -9, %l1
a00a3558:  10 bf ff 98  b  0xa00a33b8
a00a355c:  ac 10 3f f7  mov  -9, %l6
a00a3560:  10 bf ff 96  b  0xa00a33b8
a00a3564:  ac 10 3f f8  mov  -8, %l6
a00a3568:  10 bf ff 46  b  0xa00a3280
a00a356c:  a2 10 3f f8  mov  -8, %l1
a00a3570:  40 02 8e 2d  call  0xa0146e24
a00a3574:  ee 0d 63 f4  ldub  [ %l5 + 0x3f4 ], %l7
a00a3578:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00a357c:  ac 5d c0 18  smul  %l7, %i0, %l6
a00a3580:  aa 25 80 13  sub  %l6, %l3, %l5
a00a3584:  9b 2d 60 10  sll  %l5, 0x10, %o5
a00a3588:  40 02 8e 27  call  0xa0146e24
a00a358c:  a3 33 60 10  srl  %o5, 0x10, %l1
a00a3590:  a4 0a 20 ff  and  %o0, 0xff, %l2
a00a3594:  9b 3c 60 1f  sra  %l1, 0x1f, %o5
a00a3598:  81 83 60 00  mov  %o5, %y
a00a359c:  01 00 00 00  nop
a00a35a0:  01 00 00 00  nop
a00a35a4:  01 00 00 00  nop
a00a35a8:  9e 7c 40 12  sdiv  %l1, %l2, %o7
a00a35ac:  98 5b c0 12  smul  %o7, %l2, %o4
a00a35b0:  a0 24 40 0c  sub  %l1, %o4, %l0
a00a35b4:  10 bf ff 41  b  0xa00a32b8
a00a35b8:  e0 2f bf cf  stb  %l0, [ %fp + -49 ]
a00a35bc:  10 bf ff 7f  b  0xa00a33b8
a00a35c0:  ac 10 3f fa  mov  -6, %l6
a00a35c4:  10 bf ff 2f  b  0xa00a3280
a00a35c8:  a2 10 3f fa  mov  -6, %l1
a00a35cc:  10 bf ff 2d  b  0xa00a3280
a00a35d0:  a2 10 3f fd  mov  -3, %l1
a00a35d4:  10 bf ff 79  b  0xa00a33b8
a00a35d8:  ac 10 3f fd  mov  -3, %l6
a00a35dc:  10 bf ff 77  b  0xa00a33b8
a00a35e0:  ac 10 3f fb  mov  -5, %l6
a00a35e4:  10 bf ff 27  b  0xa00a3280
a00a35e8:  a2 10 3f fb  mov  -5, %l1
a00a35ec:  10 bf ff 73  b  0xa00a33b8
a00a35f0:  ac 10 3f fc  mov  -4, %l6
a00a35f4:  10 bf ff 23  b  0xa00a3280
a00a35f8:  a2 10 3f fc  mov  -4, %l1
a00a35fc:  7f ff fe 8a  call  0xa00a3024
a00a3600:  90 0c 60 ff  and  %l1, 0xff, %o0
a00a3604:  92 0a 20 ff  and  %o0, 0xff, %o1
a00a3608:  10 bf ff 1e  b  0xa00a3280
a00a360c:  a6 04 c0 09  add  %l3, %o1, %l3
a00a3610:  f0 27 bf d8  st  %i0, [ %fp + -40 ]
a00a3614:  7f ff fe 84  call  0xa00a3024
a00a3618:  90 10 00 18  mov  %i0, %o0
a00a361c:  b6 10 00 08  mov  %o0, %i3
a00a3620:  90 0c 20 ff  and  %l0, 0xff, %o0
a00a3624:  82 0e 60 ff  and  %i1, 0xff, %g1
a00a3628:  80 a4 e0 00  cmp  %l3, 0
a00a362c:  12 80 00 51  bne  0xa00a3770
a00a3630:  b0 5a 00 01  smul  %o0, %g1, %i0
a00a3634:  80 a4 c0 11  cmp  %l3, %l1
a00a3638:  1a 80 00 10  bcc  0xa00a3678
a00a363c:  82 10 20 00  clr  %g1
a00a3640:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a00a3644:  aa 12 63 f8  or  %o1, 0x3f8, %l5	! 0xa802aff8
a00a3648:  98 0c e0 ff  and  %l3, 0xff, %o4
a00a364c:  96 03 00 18  add  %o4, %i0, %o3
a00a3650:  95 2a e0 10  sll  %o3, 0x10, %o2
a00a3654:  a1 28 60 02  sll  %g1, 2, %l0
a00a3658:  93 32 a0 10  srl  %o2, 0x10, %o1
a00a365c:  7f ff fe 24  call  0xa00a2eec
a00a3660:  d0 07 bf d8  ld  [ %fp + -40 ], %o0
a00a3664:  a6 04 e0 01  inc  %l3
a00a3668:  82 0c e0 ff  and  %l3, 0xff, %g1
a00a366c:  80 a0 40 11  cmp  %g1, %l1
a00a3670:  0a bf ff f6  bcs  0xa00a3648
a00a3674:  d0 25 40 10  st  %o0, [ %l5 + %l0 ]
a00a3678:  da 0f bf cf  ldub  [ %fp + -49 ], %o5
a00a367c:  a6 0e e0 ff  and  %i3, 0xff, %l3
a00a3680:  aa 03 40 1b  add  %o5, %i3, %l5
a00a3684:  e6 27 bf d4  st  %l3, [ %fp + -44 ]
a00a3688:  ea 2f bf cf  stb  %l5, [ %fp + -49 ]
a00a368c:  10 80 00 0f  b  0xa00a36c8
a00a3690:  a6 0d 60 ff  and  %l5, 0xff, %l3
a00a3694:  40 02 8d e4  call  0xa0146e24
a00a3698:  01 00 00 00  nop
a00a369c:  ae 0a 20 ff  and  %o0, 0xff, %l7
a00a36a0:  80 a5 c0 13  cmp  %l7, %l3
a00a36a4:  0a 80 00 15  bcs  0xa00a36f8
a00a36a8:  19 2a 00 ab  sethi  %hi(0xa802ac00), %o4
a00a36ac:  40 02 8d de  call  0xa0146e24
a00a36b0:  01 00 00 00  nop
a00a36b4:  aa 0a 20 ff  and  %o0, 0xff, %l5
a00a36b8:  82 05 7f ff  add  %l5, -1, %g1
a00a36bc:  80 a4 c0 01  cmp  %l3, %g1
a00a36c0:  24 bf ff 3f  ble,a   0xa00a33bc
a00a36c4:  a4 04 a0 01  inc  %l2
a00a36c8:  40 02 8d d7  call  0xa0146e24
a00a36cc:  01 00 00 00  nop
a00a36d0:  b6 0a 20 ff  and  %o0, 0xff, %i3
a00a36d4:  80 a6 c0 13  cmp  %i3, %l3
a00a36d8:  12 bf ff ef  bne  0xa00a3694
a00a36dc:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a00a36e0:  90 12 a3 f8  or  %o2, 0x3f8, %o0	! 0xa802aff8
a00a36e4:  40 02 8d 47  call  0xa0146c00
a00a36e8:  92 10 00 1d  mov  %i5, %o1
a00a36ec:  c0 2f bf cf  clrb  [ %fp + -49 ]
a00a36f0:  10 bf ff ef  b  0xa00a36ac
a00a36f4:  a6 10 20 00  clr  %l3
a00a36f8:  90 13 23 f8  or  %o4, 0x3f8, %o0
a00a36fc:  40 02 8d 41  call  0xa0146c00
a00a3700:  92 10 00 1d  mov  %i5, %o1
a00a3704:  40 02 8d c8  call  0xa0146e24
a00a3708:  aa 10 20 00  clr  %l5
a00a370c:  d6 0f bf cf  ldub  [ %fp + -49 ], %o3
a00a3710:  a0 22 c0 08  sub  %o3, %o0, %l0
a00a3714:  e0 2f bf cf  stb  %l0, [ %fp + -49 ]
a00a3718:  80 a4 60 00  cmp  %l1, 0
a00a371c:  02 bf ff e4  be  0xa00a36ac
a00a3720:  a6 0c 20 ff  and  %l0, 0xff, %l3
a00a3724:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a00a3728:  de 07 bf d4  ld  [ %fp + -44 ], %o7
a00a372c:  82 10 20 00  clr  %g1
a00a3730:  b6 12 23 f8  or  %o0, 0x3f8, %i3
a00a3734:  ae 23 c0 13  sub  %o7, %l3, %l7
a00a3738:  96 0d 60 ff  and  %l5, 0xff, %o3
a00a373c:  94 02 c0 18  add  %o3, %i0, %o2
a00a3740:  9b 2a a0 10  sll  %o2, 0x10, %o5
a00a3744:  a1 28 60 02  sll  %g1, 2, %l0
a00a3748:  93 33 60 10  srl  %o5, 0x10, %o1
a00a374c:  7f ff fd e8  call  0xa00a2eec
a00a3750:  d0 07 bf d8  ld  [ %fp + -40 ], %o0
a00a3754:  aa 05 60 01  inc  %l5
a00a3758:  93 2a 00 17  sll  %o0, %l7, %o1
a00a375c:  82 0d 60 ff  and  %l5, 0xff, %g1
a00a3760:  80 a0 40 11  cmp  %g1, %l1
a00a3764:  0a bf ff f5  bcs  0xa00a3738
a00a3768:  d2 26 c0 10  st  %o1, [ %i3 + %l0 ]
a00a376c:  30 bf ff d0  b,a   0xa00a36ac
a00a3770:  80 a4 e0 0f  cmp  %l3, 0xf
a00a3774:  18 80 00 1b  bgu  0xa00a37e0
a00a3778:  80 a4 60 00  cmp  %l1, 0
a00a377c:  02 bf ff bf  be  0xa00a3678
a00a3780:  aa 10 20 00  clr  %l5
a00a3784:  9a 10 20 00  clr  %o5
a00a3788:  ae 10 00 1a  mov  %i2, %l7
a00a378c:  94 0d 60 ff  and  %l5, 0xff, %o2
a00a3790:  92 02 80 18  add  %o2, %i0, %o1
a00a3794:  91 2a 60 10  sll  %o1, 0x10, %o0
a00a3798:  93 32 20 10  srl  %o0, 0x10, %o1
a00a379c:  a1 2b 60 02  sll  %o5, 2, %l0
a00a37a0:  7f ff fd d3  call  0xa00a2eec
a00a37a4:  d0 07 bf d8  ld  [ %fp + -40 ], %o0
a00a37a8:  da 05 c0 10  ld  [ %l7 + %l0 ], %o5
a00a37ac:  83 32 00 13  srl  %o0, %l3, %g1
a00a37b0:  9e 13 40 01  or  %o5, %g1, %o7
a00a37b4:  aa 05 60 01  inc  %l5
a00a37b8:  9a 0d 60 ff  and  %l5, 0xff, %o5
a00a37bc:  80 a3 40 11  cmp  %o5, %l1
a00a37c0:  0a bf ff f3  bcs  0xa00a378c
a00a37c4:  de 25 c0 10  st  %o7, [ %l7 + %l0 ]
a00a37c8:  10 bf ff ad  b  0xa00a367c
a00a37cc:  da 0f bf cf  ldub  [ %fp + -49 ], %o5
a00a37d0:  40 02 8d 95  call  0xa0146e24
a00a37d4:  01 00 00 00  nop
a00a37d8:  10 bf ff 47  b  0xa00a34f4
a00a37dc:  82 04 00 08  add  %l0, %o0, %g1
a00a37e0:  02 bf ff a6  be  0xa00a3678
a00a37e4:  aa 10 20 00  clr  %l5
a00a37e8:  9a 10 20 00  clr  %o5
a00a37ec:  2f 2a 00 ab  sethi  %hi(0xa802ac00), %l7
a00a37f0:  ae 15 e3 f8  or  %l7, 0x3f8, %l7	! 0xa802aff8
a00a37f4:  92 0d 60 ff  and  %l5, 0xff, %o1
a00a37f8:  90 02 40 18  add  %o1, %i0, %o0
a00a37fc:  83 2a 20 10  sll  %o0, 0x10, %g1
a00a3800:  a1 2b 60 02  sll  %o5, 2, %l0
a00a3804:  93 30 60 10  srl  %g1, 0x10, %o1
a00a3808:  7f ff fd b9  call  0xa00a2eec
a00a380c:  d0 07 bf d8  ld  [ %fp + -40 ], %o0
a00a3810:  d8 05 c0 10  ld  [ %l7 + %l0 ], %o4
a00a3814:  9f 32 00 13  srl  %o0, %l3, %o7
a00a3818:  aa 05 60 01  inc  %l5
a00a381c:  96 13 00 0f  or  %o4, %o7, %o3
a00a3820:  9a 0d 60 ff  and  %l5, 0xff, %o5
a00a3824:  80 a3 40 11  cmp  %o5, %l1
a00a3828:  0a bf ff f3  bcs  0xa00a37f4
a00a382c:  d6 25 c0 10  st  %o3, [ %l7 + %l0 ]
a00a3830:  10 bf ff 93  b  0xa00a367c
a00a3834:  da 0f bf cf  ldub  [ %fp + -49 ], %o5
